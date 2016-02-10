;; *  Char(Real)/Complex Vector Dot Product (for FIR Filter) using MMX
;; *  ccvdp_mmx(d_ptr, taps_ptr, out_ptr, n)
;; *  
;; *  input values:
;; *    d_ptr = pointer to input data (signed bytes) 64-bit aligned
;; *    taps_ptr = pointer to precomputed packed taps coefficient table
;; *              (format: quadword [Dr2  Dr1  Di2  Di1]) 16-bit signed each
;; *              Must be 64 bit aligned (and aligned w/ data)
;; *              Note the interleved and backwards order!
;; *    out_ptr = pointer to packed output data (one value)
;; *              (format: Dr  Di, each 32 bits)
;; *    n = number of Taps (and data points that will be used)
;; *        WARNING: will round up to next multiple of 8!!!

BITS 32

SEGMENT .text

GLOBAL  _ccvdp_mmx:function
_ccvdp_mmx:

;d_ptr      EQU     [esp+8]
;taps_ptr   EQU     [esp+12]
;out_ptr    EQU     [esp+16]
;n          EQU     [esp+20]

	push ebx
	
        mov     eax, [esp+8] ;d_ptr       ; src1 pointer (1 clock AGI delay)
        mov     ebx, [esp+12] ;taps_ptr    ; src2 pointer

        mov     ecx, [esp+20] ;n          ; number of Taps
        mov     edx, [esp+16] ;out_ptr    ; pointer to the result

        pxor    mm4, mm4        ; prepare for early use (SW pipelining)
        pxor    mm5, mm5        ; prepare for early use (SW pipelining)

        pxor    mm7, mm7        ; initialize accumulator


;;Each iteration does 8 taps (13 cycles if I did it right)
ALIGN 16
cvdp16:
	punpcklbw mm0, [eax]    ; Unpack the first (low-order) 4 bytes
	paddd mm7,mm4           ; Accumulate (from prev iter)

        movq    mm2, [ebx]      ; first 2 taps
	psraw	mm0, 8          ; Sign-extend first 4 data elements (DCBA)

        movq    mm3, [ebx+8]    ; second 2 taps
	paddd mm7,mm5           ; Accumulate (from prev iter)

	movq    mm1, mm0        ; Get ready to duplicate first 4 words
	punpckldq mm0, mm0      ; Duplicate 1st 2 words (B A B A)

	punpcklbw mm4, [eax+4]  ; Unpack the second (high-order) 4 bytes
	pmaddwd mm0, mm2        ; Multiply and accum 1st 2 vals

	punpckhdq mm1, mm1      ; Duplicate 2nd 2 words (D C D C)
	psraw	mm4, 8          ; Sign-extend second 4 data elements

        movq    mm2, [ebx+16]   ; 3rd 2 taps
	pmaddwd mm1, mm3        ; Multiply and accum 2nd 2 vals

	paddd mm7,mm0           ; Accumulate
	movq    mm5, mm4        ; Get ready to duplicate first 4 words

        movq    mm3, [ebx+24]   ; 4th 2 taps
	punpckldq mm4, mm4      ; Duplicate 3rd 2 words 

	pmaddwd mm4, mm2        ; Multiply and accum 3rd 2 vals
	punpckhdq mm5, mm5      ; Duplicate 4th 2 words

	pmaddwd mm5, mm3        ; Multiply and accum 4th 2 vals
	paddd mm7,mm1           ; Accumulate 

        add     eax, 8          ; increment data index by 8 bytes
        add     ebx, 32         ; increment taps index

        sub     ecx, 8          ; (NOTE: could elim. prev. pair, but AGI)
        jg      cvdp16

	paddd mm7,mm4           ; Accumulate (from prev iter)
                                ; V-pipe empty

	paddd mm7,mm5           ; Accumulate (from prev iter)
                                ; V-pipe empty (data dependency)

                                ; One cycle stall - Op-Store dependency
        movq    [edx],mm7       ; store result
                                ; V-pipe empty (integer inst. does not pair w/ MM memory reference)

        emms

	pop ebx

        ret

GLOBAL  _query_mmx:function
_query_mmx:
	push ebx
	mov eax, 1
	cpuid
	test edx, 00800000h
	jnz mmx_found
	mov eax, 0
	pop ebx
	ret
mmx_found:
	mov eax, 1
	pop ebx
	ret

END
