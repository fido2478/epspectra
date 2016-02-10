SEGMENT .text	
GLOBAL _vradd_mmx:function
_vradd_mmx:
	;; /* input pointer 1 = [esp+8]  ?
	;; input pointer 2 = [esp+12]    ?
	;; number of elements to add = [esp+16]  ?
	;; output pointer  = [esp+20]    ?
	;; HOPEFULLY 4 cycles...
	;; Initialization */
	push ebx
	mov eax, [esp+8]
	mov ebx, [esp+12]
	mov ecx, [esp+16]
	mov edx, [esp+20]	
	
	pxor mm0, mm0
	pxor mm1, mm1
	
beginning:	
	movq mm0, [eax]
	movq mm1, [ebx]
	paddb mm1, mm0
	add eax, 8
	add ebx, 8
	movq [edx], mm1
	add edx, 8
	sub ecx, 8
	jg beginning
	emms			 
	pop ebx
	ret
END	











