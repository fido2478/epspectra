SEGMENT .text	
GLOBAL _vradd4_mmx:function
_vradd_mmx:
	;; /* input pointer 1 = [esp+8]  
	;; input pointer 2 = [esp+12]    
	;; input pointer 3 = [esp+16]
	;; input pointer 4 = [esp+20]
	;; number of elements to add = [esp+24]  
	;; output pointer  = [esp+28]    
	;; 
	;; HOPEFULLY 4 cycles...
	;; Initialization */
	push ebx
	push esi
	push edi
	mov eax, [esp+8]
	mov ebx, [esp+12]
	mov esi, [esp+24]
	mov edi, [esp+28]	
	mov ecx, [esp+16]
	mov edx, [esp+20]
	;; Result:
	;; EAX:	 Input Array 1
	;; EBX:	 Input Array 2
	;; ECX:	 Input Array 3
	;; EDX:	 Input Array 4
	;; ESI:	 Number of elements to add
	;; EDI:	 Output pointer
	
beginning:	
	movq mm0, [eax]
	movq mm1, [ebx]
	movq mm2, [ecx]
	movq mm3, [edx]
	paddb mm1, mm0
	paddb mm3, mm2
	paddb mm1, mm3
	add eax, 8
	add ebx, 8
	movq [edi], mm1	
	add ecx, 8
	add edx, 8
	add edi, 8
	sub esi, 8
	jg beginning
	emms	
	pop edi		 
	pop esi
	pop ebx

	ret
END	
