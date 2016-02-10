	.file	"datatype_data.c"
	.version	"01.01"
gcc2_compiled.:
.globl INITIAL_INDEX
.section	.rodata
.LC0:
	.string	"0"
.data
	.align 4
	.type	 INITIAL_INDEX,@object
	.size	 INITIAL_INDEX,4
INITIAL_INDEX:
	.long .LC0
.globl INITIAL_RANGE
.section	.rodata
.LC1:
	.string	"0 0"
.data
	.align 4
	.type	 INITIAL_RANGE,@object
	.size	 INITIAL_RANGE,4
INITIAL_RANGE:
	.long .LC1
.globl START_RANGE
	.align 4
	.type	 START_RANGE,@object
	.size	 START_RANGE,4
START_RANGE:
	.long .LC1
.globl INITIAL_SIZE
	.align 4
	.type	 INITIAL_SIZE,@object
	.size	 INITIAL_SIZE,4
INITIAL_SIZE:
	.long .LC0
.globl INITIAL_STRING
.section	.rodata
.LC2:
	.string	"           "
.data
	.align 4
	.type	 INITIAL_STRING,@object
	.size	 INITIAL_STRING,4
INITIAL_STRING:
	.long .LC2
.globl INITIAL_DEBUG4VAR
	.align 32
	.type	 INITIAL_DEBUG4VAR,@object
	.size	 INITIAL_DEBUG4VAR,100
INITIAL_DEBUG4VAR:
	.string	"0"
	.zero	48
	.string	"0"
	.zero	48
.globl INITIAL_UNSIGNEDINT
	.align 4
	.type	 INITIAL_UNSIGNEDINT,@object
	.size	 INITIAL_UNSIGNEDINT,4
INITIAL_UNSIGNEDINT:
	.long 0
.globl INITIAL_UNSIGNEDLL
	.align 4
	.type	 INITIAL_UNSIGNEDLL,@object
	.size	 INITIAL_UNSIGNEDLL,8
INITIAL_UNSIGNEDLL:
	.long 0
	.long 0
.globl INITIAL_FLOAT
	.align 4
	.type	 INITIAL_FLOAT,@object
	.size	 INITIAL_FLOAT,4
INITIAL_FLOAT:
	.long 0x0
.text
	.align 4
.globl _text_to_StrlSampleIndex
	.type	 _text_to_StrlSampleIndex,@function
_text_to_StrlSampleIndex:
	pushl %ebp
	movl %esp,%ebp
	subl $8,%esp
	addl $-8,%esp
	movl 8(%ebp),%eax
	pushl %eax
	movl 12(%ebp),%eax
	pushl %eax
	call strcpy
	addl $16,%esp
.L2:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe1:
	.size	 _text_to_StrlSampleIndex,.Lfe1-_text_to_StrlSampleIndex
	.local	buf.6
	.comm	buf.6,80,32
	.align 4
.globl _StrlSampleIndex_to_text
	.type	 _StrlSampleIndex_to_text,@function
_StrlSampleIndex_to_text:
	pushl %ebp
	movl %esp,%ebp
	subl $8,%esp
	addl $-8,%esp
	movl 8(%ebp),%eax
	pushl %eax
	pushl $buf.6
	call strcpy
	addl $16,%esp
	movl $buf.6,%eax
	jmp .L3
	.p2align 4,,7
.L3:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe2:
	.size	 _StrlSampleIndex_to_text,.Lfe2-_StrlSampleIndex_to_text
	.align 4
.globl _text_to_StrlSampleSize
	.type	 _text_to_StrlSampleSize,@function
_text_to_StrlSampleSize:
	pushl %ebp
	movl %esp,%ebp
	subl $8,%esp
	addl $-8,%esp
	movl 8(%ebp),%eax
	pushl %eax
	movl 12(%ebp),%eax
	pushl %eax
	call strcpy
	addl $16,%esp
.L4:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe3:
	.size	 _text_to_StrlSampleSize,.Lfe3-_text_to_StrlSampleSize
	.local	buf.13
	.comm	buf.13,80,32
	.align 4
.globl _StrlSampleSize_to_text
	.type	 _StrlSampleSize_to_text,@function
_StrlSampleSize_to_text:
	pushl %ebp
	movl %esp,%ebp
	subl $8,%esp
	addl $-8,%esp
	movl 8(%ebp),%eax
	pushl %eax
	pushl $buf.13
	call strcpy
	addl $16,%esp
	movl $buf.13,%eax
	jmp .L5
	.p2align 4,,7
.L5:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe4:
	.size	 _StrlSampleSize_to_text,.Lfe4-_StrlSampleSize_to_text
	.align 4
.globl _text_to_StrlSampleRange
	.type	 _text_to_StrlSampleRange,@function
_text_to_StrlSampleRange:
	pushl %ebp
	movl %esp,%ebp
	subl $8,%esp
	addl $-8,%esp
	movl 8(%ebp),%eax
	pushl %eax
	movl 12(%ebp),%eax
	pushl %eax
	call strcpy
	addl $16,%esp
.L6:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe5:
	.size	 _text_to_StrlSampleRange,.Lfe5-_text_to_StrlSampleRange
	.local	buf.20
	.comm	buf.20,80,32
	.align 4
.globl _StrlSampleRange_to_text
	.type	 _StrlSampleRange_to_text,@function
_StrlSampleRange_to_text:
	pushl %ebp
	movl %esp,%ebp
	subl $8,%esp
	addl $-8,%esp
	movl 8(%ebp),%eax
	pushl %eax
	pushl $buf.20
	call strcpy
	addl $16,%esp
	movl $buf.20,%eax
	jmp .L7
	.p2align 4,,7
.L7:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe6:
	.size	 _StrlSampleRange_to_text,.Lfe6-_StrlSampleRange_to_text
.section	.rodata
.LC3:
	.string	"%lld %lu"
.text
	.align 4
.globl _check_StrlSampleRange
	.type	 _check_StrlSampleRange,@function
_check_StrlSampleRange:
	pushl %ebp
	movl %esp,%ebp
	subl $24,%esp
	leal -12(%ebp),%eax
	pushl %eax
	leal -8(%ebp),%eax
	pushl %eax
	pushl $.LC3
	movl 8(%ebp),%eax
	pushl %eax
	call sscanf
	addl $16,%esp
	movl %eax,%eax
	cmpl $2,%eax
	sete %al
	movzbl %al,%edx
	movl %edx,%eax
	jmp .L8
	.p2align 4,,7
.L8:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe7:
	.size	 _check_StrlSampleRange,.Lfe7-_check_StrlSampleRange
	.align 4
.globl _text_to_StrlString
	.type	 _text_to_StrlString,@function
_text_to_StrlString:
	pushl %ebp
	movl %esp,%ebp
	subl $8,%esp
	addl $-8,%esp
	movl 8(%ebp),%eax
	pushl %eax
	movl 12(%ebp),%eax
	pushl %eax
	call strcpy
	addl $16,%esp
.L9:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe8:
	.size	 _text_to_StrlString,.Lfe8-_text_to_StrlString
	.local	buf.30
	.comm	buf.30,80,32
	.align 4
.globl _StrlString_to_text
	.type	 _StrlString_to_text,@function
_StrlString_to_text:
	pushl %ebp
	movl %esp,%ebp
	subl $8,%esp
	addl $-8,%esp
	movl 8(%ebp),%eax
	pushl %eax
	pushl $buf.30
	call strcpy
	addl $16,%esp
	movl $buf.30,%eax
	jmp .L10
	.p2align 4,,7
.L10:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe9:
	.size	 _StrlString_to_text,.Lfe9-_StrlString_to_text
	.local	buf.34
	.comm	buf.34,80,32
.section	.rodata
.LC4:
	.string	"%s"
.text
	.align 4
.globl _check_StrlString
	.type	 _check_StrlString,@function
_check_StrlString:
	pushl %ebp
	movl %esp,%ebp
	subl $8,%esp
	addl $-4,%esp
	pushl $buf.34
	pushl $.LC4
	movl 8(%ebp),%eax
	pushl %eax
	call sscanf
	addl $16,%esp
	movl %eax,%eax
	cmpl $1,%eax
	sete %al
	movzbl %al,%edx
	movl %edx,%eax
	jmp .L11
	.p2align 4,,7
.L11:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe10:
	.size	 _check_StrlString,.Lfe10-_check_StrlString
.section	.rodata
.LC5:
	.string	"%s %s"
.text
	.align 4
.globl _text_to_Debug4Var
	.type	 _text_to_Debug4Var,@function
_text_to_Debug4Var:
	pushl %ebp
	movl %esp,%ebp
	subl $8,%esp
	movl 8(%ebp),%eax
	addl $50,%eax
	pushl %eax
	movl 8(%ebp),%eax
	pushl %eax
	pushl $.LC5
	movl 12(%ebp),%eax
	pushl %eax
	call sscanf
	addl $16,%esp
.L12:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe11:
	.size	 _text_to_Debug4Var,.Lfe11-_text_to_Debug4Var
	.local	buf.41
	.comm	buf.41,80,32
	.align 4
.globl _Debug4Var_to_text
	.type	 _Debug4Var_to_text,@function
_Debug4Var_to_text:
	pushl %ebp
	movl %esp,%ebp
	subl $8,%esp
	leal 58(%ebp),%eax
	pushl %eax
	leal 8(%ebp),%eax
	pushl %eax
	pushl $.LC5
	pushl $buf.41
	call sprintf
	addl $16,%esp
	movl $buf.41,%eax
	jmp .L13
	.p2align 4,,7
.L13:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe12:
	.size	 _Debug4Var_to_text,.Lfe12-_Debug4Var_to_text
	.align 4
.globl _check4Var_Debug
	.type	 _check4Var_Debug,@function
_check4Var_Debug:
	pushl %ebp
	movl %esp,%ebp
	subl $24,%esp
	movl -8(%ebp),%eax
	pushl %eax
	movl -4(%ebp),%eax
	pushl %eax
	pushl $.LC5
	movl 8(%ebp),%eax
	pushl %eax
	call sscanf
	addl $16,%esp
	movl %eax,%eax
	cmpl $2,%eax
	sete %al
	movzbl %al,%edx
	movl %edx,%eax
	jmp .L14
	.p2align 4,,7
.L14:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe13:
	.size	 _check4Var_Debug,.Lfe13-_check4Var_Debug
.section	.rodata
.LC6:
	.string	"%lld"
.text
	.align 4
.globl _text_to_VrSampleIndex
	.type	 _text_to_VrSampleIndex,@function
_text_to_VrSampleIndex:
	pushl %ebp
	movl %esp,%ebp
	subl $8,%esp
	addl $-4,%esp
	movl 8(%ebp),%eax
	pushl %eax
	pushl $.LC6
	movl 12(%ebp),%eax
	pushl %eax
	call sscanf
	addl $16,%esp
.L15:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe14:
	.size	 _text_to_VrSampleIndex,.Lfe14-_text_to_VrSampleIndex
	.local	buf.51
	.comm	buf.51,80,32
	.align 4
.globl _VrSampleIndex_to_text
	.type	 _VrSampleIndex_to_text,@function
_VrSampleIndex_to_text:
	pushl %ebp
	movl %esp,%ebp
	subl $8,%esp
	movl 8(%ebp),%eax
	movl 12(%ebp),%edx
	pushl %edx
	pushl %eax
	pushl $.LC6
	pushl $buf.51
	call sprintf
	addl $16,%esp
	movl $buf.51,%eax
	jmp .L16
	.p2align 4,,7
.L16:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe15:
	.size	 _VrSampleIndex_to_text,.Lfe15-_VrSampleIndex_to_text
	.align 4
.globl _check_VrSampleIndex
	.type	 _check_VrSampleIndex,@function
_check_VrSampleIndex:
	pushl %ebp
	movl %esp,%ebp
	subl $24,%esp
	addl $-4,%esp
	leal -4(%ebp),%eax
	pushl %eax
	pushl $.LC6
	movl 8(%ebp),%eax
	pushl %eax
	call sscanf
	addl $16,%esp
	movl %eax,%eax
	cmpl $1,%eax
	sete %al
	movzbl %al,%edx
	movl %edx,%eax
	jmp .L17
	.p2align 4,,7
.L17:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe16:
	.size	 _check_VrSampleIndex,.Lfe16-_check_VrSampleIndex
	.align 4
.globl _text_to_VrSampleRange
	.type	 _text_to_VrSampleRange,@function
_text_to_VrSampleRange:
	pushl %ebp
	movl %esp,%ebp
	subl $8,%esp
	movl 8(%ebp),%eax
	addl $8,%eax
	pushl %eax
	movl 8(%ebp),%eax
	pushl %eax
	pushl $.LC3
	movl 12(%ebp),%eax
	pushl %eax
	call sscanf
	addl $16,%esp
.L18:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe17:
	.size	 _text_to_VrSampleRange,.Lfe17-_text_to_VrSampleRange
	.local	buf.61
	.comm	buf.61,80,32
	.align 4
.globl _VrSampleRange_to_text
	.type	 _VrSampleRange_to_text,@function
_VrSampleRange_to_text:
	pushl %ebp
	movl %esp,%ebp
	subl $8,%esp
	addl $-12,%esp
	movl 16(%ebp),%eax
	pushl %eax
	movl 8(%ebp),%eax
	movl 12(%ebp),%edx
	pushl %edx
	pushl %eax
	pushl $.LC3
	pushl $buf.61
	call sprintf
	addl $32,%esp
	movl $buf.61,%eax
	jmp .L19
	.p2align 4,,7
.L19:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe18:
	.size	 _VrSampleRange_to_text,.Lfe18-_VrSampleRange_to_text
	.align 4
.globl _check_VrSampleRange
	.type	 _check_VrSampleRange,@function
_check_VrSampleRange:
	pushl %ebp
	movl %esp,%ebp
	subl $24,%esp
	leal -8(%ebp),%eax
	pushl %eax
	leal -4(%ebp),%eax
	pushl %eax
	pushl $.LC3
	movl 8(%ebp),%eax
	pushl %eax
	call sscanf
	addl $16,%esp
	movl %eax,%eax
	cmpl $2,%eax
	sete %al
	movzbl %al,%edx
	movl %edx,%eax
	jmp .L20
	.p2align 4,,7
.L20:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe19:
	.size	 _check_VrSampleRange,.Lfe19-_check_VrSampleRange
	.align 4
.globl _text_to_UnsignedLL
	.type	 _text_to_UnsignedLL,@function
_text_to_UnsignedLL:
	pushl %ebp
	movl %esp,%ebp
	subl $8,%esp
	addl $-4,%esp
	movl 8(%ebp),%eax
	pushl %eax
	pushl $.LC6
	movl 12(%ebp),%eax
	pushl %eax
	call sscanf
	addl $16,%esp
.L21:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe20:
	.size	 _text_to_UnsignedLL,.Lfe20-_text_to_UnsignedLL
	.local	buf.71
	.comm	buf.71,21,1
	.align 4
.globl _UnsignedLL_to_text
	.type	 _UnsignedLL_to_text,@function
_UnsignedLL_to_text:
	pushl %ebp
	movl %esp,%ebp
	subl $8,%esp
	movl 8(%ebp),%eax
	movl 12(%ebp),%edx
	pushl %edx
	pushl %eax
	pushl $.LC6
	pushl $buf.71
	call sprintf
	addl $16,%esp
	movl $buf.71,%eax
	jmp .L22
	.p2align 4,,7
.L22:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe21:
	.size	 _UnsignedLL_to_text,.Lfe21-_UnsignedLL_to_text
	.align 4
.globl _check_UnsignedLL
	.type	 _check_UnsignedLL,@function
_check_UnsignedLL:
	pushl %ebp
	movl %esp,%ebp
	subl $24,%esp
	addl $-4,%esp
	leal -8(%ebp),%eax
	pushl %eax
	pushl $.LC6
	movl 8(%ebp),%eax
	pushl %eax
	call sscanf
	addl $16,%esp
	movl %eax,%eax
	cmpl $1,%eax
	sete %al
	movzbl %al,%edx
	movl %edx,%eax
	jmp .L23
	.p2align 4,,7
.L23:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe22:
	.size	 _check_UnsignedLL,.Lfe22-_check_UnsignedLL
.section	.rodata
.LC7:
	.string	"%lu"
.text
	.align 4
.globl _text_to_UnsignedLong
	.type	 _text_to_UnsignedLong,@function
_text_to_UnsignedLong:
	pushl %ebp
	movl %esp,%ebp
	subl $8,%esp
	addl $-4,%esp
	movl 8(%ebp),%eax
	pushl %eax
	pushl $.LC7
	movl 12(%ebp),%eax
	pushl %eax
	call sscanf
	addl $16,%esp
.L24:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe23:
	.size	 _text_to_UnsignedLong,.Lfe23-_text_to_UnsignedLong
	.local	buf.81
	.comm	buf.81,21,1
	.align 4
.globl _UnsignedLong_to_text
	.type	 _UnsignedLong_to_text,@function
_UnsignedLong_to_text:
	pushl %ebp
	movl %esp,%ebp
	subl $8,%esp
	addl $-4,%esp
	movl 8(%ebp),%eax
	pushl %eax
	pushl $.LC7
	pushl $buf.81
	call sprintf
	addl $16,%esp
	movl $buf.81,%eax
	jmp .L25
	.p2align 4,,7
.L25:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe24:
	.size	 _UnsignedLong_to_text,.Lfe24-_UnsignedLong_to_text
	.align 4
.globl _check_UnsignedLong
	.type	 _check_UnsignedLong,@function
_check_UnsignedLong:
	pushl %ebp
	movl %esp,%ebp
	subl $24,%esp
	addl $-4,%esp
	leal -4(%ebp),%eax
	pushl %eax
	pushl $.LC7
	movl 8(%ebp),%eax
	pushl %eax
	call sscanf
	addl $16,%esp
	movl %eax,%eax
	cmpl $1,%eax
	sete %al
	movzbl %al,%edx
	movl %edx,%eax
	jmp .L26
	.p2align 4,,7
.L26:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe25:
	.size	 _check_UnsignedLong,.Lfe25-_check_UnsignedLong
.section	.rodata
.LC8:
	.string	"%u"
.text
	.align 4
.globl _text_to_UnsignedInt
	.type	 _text_to_UnsignedInt,@function
_text_to_UnsignedInt:
	pushl %ebp
	movl %esp,%ebp
	subl $8,%esp
	addl $-4,%esp
	movl 8(%ebp),%eax
	pushl %eax
	pushl $.LC8
	movl 12(%ebp),%eax
	pushl %eax
	call sscanf
	addl $16,%esp
.L27:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe26:
	.size	 _text_to_UnsignedInt,.Lfe26-_text_to_UnsignedInt
	.local	buf.91
	.comm	buf.91,10,1
	.align 4
.globl _UnsignedInt_to_text
	.type	 _UnsignedInt_to_text,@function
_UnsignedInt_to_text:
	pushl %ebp
	movl %esp,%ebp
	subl $8,%esp
	addl $-4,%esp
	movl 8(%ebp),%eax
	pushl %eax
	pushl $.LC8
	pushl $buf.91
	call sprintf
	addl $16,%esp
	movl $buf.91,%eax
	jmp .L28
	.p2align 4,,7
.L28:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe27:
	.size	 _UnsignedInt_to_text,.Lfe27-_UnsignedInt_to_text
	.align 4
.globl _check_UnsignedInt
	.type	 _check_UnsignedInt,@function
_check_UnsignedInt:
	pushl %ebp
	movl %esp,%ebp
	subl $24,%esp
	addl $-4,%esp
	leal -4(%ebp),%eax
	pushl %eax
	pushl $.LC8
	movl 8(%ebp),%eax
	pushl %eax
	call sscanf
	addl $16,%esp
	movl %eax,%eax
	cmpl $1,%eax
	sete %al
	movzbl %al,%edx
	movl %edx,%eax
	jmp .L29
	.p2align 4,,7
.L29:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe28:
	.size	 _check_UnsignedInt,.Lfe28-_check_UnsignedInt
.section	.rodata
.LC9:
	.string	"%f"
.text
	.align 4
.globl _text_to_Float_Type
	.type	 _text_to_Float_Type,@function
_text_to_Float_Type:
	pushl %ebp
	movl %esp,%ebp
	subl $8,%esp
	addl $-4,%esp
	movl 8(%ebp),%eax
	pushl %eax
	pushl $.LC9
	movl 12(%ebp),%eax
	pushl %eax
	call sscanf
	addl $16,%esp
.L30:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe29:
	.size	 _text_to_Float_Type,.Lfe29-_text_to_Float_Type
	.local	buf.101
	.comm	buf.101,10,1
	.align 4
.globl _Float_Type_to_text
	.type	 _Float_Type_to_text,@function
_Float_Type_to_text:
	pushl %ebp
	movl %esp,%ebp
	subl $24,%esp
	fldl 8(%ebp)
	fstps -4(%ebp)
	flds -4(%ebp)
	fstps -8(%ebp)
	flds -8(%ebp)
	subl $8,%esp
	fstpl (%esp)
	pushl $.LC9
	pushl $buf.101
	call sprintf
	addl $16,%esp
	movl $buf.101,%eax
	jmp .L31
	.p2align 4,,7
.L31:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe30:
	.size	 _Float_Type_to_text,.Lfe30-_Float_Type_to_text
	.align 4
.globl _check_Float_Type
	.type	 _check_Float_Type,@function
_check_Float_Type:
	pushl %ebp
	movl %esp,%ebp
	subl $24,%esp
	addl $-4,%esp
	leal -4(%ebp),%eax
	pushl %eax
	pushl $.LC9
	movl 8(%ebp),%eax
	pushl %eax
	call sscanf
	addl $16,%esp
	movl %eax,%eax
	cmpl $1,%eax
	sete %al
	movzbl %al,%edx
	movl %edx,%eax
	jmp .L32
	.p2align 4,,7
.L32:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe31:
	.size	 _check_Float_Type,.Lfe31-_check_Float_Type
.section	.rodata
.LC10:
	.string	"%d"
.text
	.align 4
.globl d2str
	.type	 d2str,@function
d2str:
	pushl %ebp
	movl %esp,%ebp
	subl $24,%esp
	addl $-12,%esp
	pushl $10
	call malloc
	addl $16,%esp
	movl %eax,%eax
	movl %eax,-4(%ebp)
	addl $-4,%esp
	movl 8(%ebp),%eax
	pushl %eax
	pushl $.LC10
	movl -4(%ebp),%eax
	pushl %eax
	call sprintf
	addl $16,%esp
	movl -4(%ebp),%edx
	movl %edx,%eax
	jmp .L33
	.p2align 4,,7
.L33:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe32:
	.size	 d2str,.Lfe32-d2str
	.align 4
.globl ud2str
	.type	 ud2str,@function
ud2str:
	pushl %ebp
	movl %esp,%ebp
	subl $24,%esp
	addl $-12,%esp
	pushl $10
	call malloc
	addl $16,%esp
	movl %eax,%eax
	movl %eax,-4(%ebp)
	addl $-4,%esp
	movl 8(%ebp),%eax
	pushl %eax
	pushl $.LC8
	movl -4(%ebp),%eax
	pushl %eax
	call sprintf
	addl $16,%esp
	movl -4(%ebp),%edx
	movl %edx,%eax
	jmp .L34
	.p2align 4,,7
.L34:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe33:
	.size	 ud2str,.Lfe33-ud2str
	.align 4
.globl lld2str
	.type	 lld2str,@function
lld2str:
	pushl %ebp
	movl %esp,%ebp
	subl $24,%esp
	addl $-12,%esp
	pushl $20
	call malloc
	addl $16,%esp
	movl %eax,%eax
	movl %eax,-4(%ebp)
	movl 8(%ebp),%eax
	movl 12(%ebp),%edx
	pushl %edx
	pushl %eax
	pushl $.LC6
	movl -4(%ebp),%eax
	pushl %eax
	call sprintf
	addl $16,%esp
	movl -4(%ebp),%edx
	movl %edx,%eax
	jmp .L35
	.p2align 4,,7
.L35:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe34:
	.size	 lld2str,.Lfe34-lld2str
	.align 4
.globl str2lld
	.type	 str2lld,@function
str2lld:
	pushl %ebp
	movl %esp,%ebp
	subl $20,%esp
	pushl %ebx
	addl $-4,%esp
	leal -8(%ebp),%eax
	pushl %eax
	pushl $.LC6
	movl 8(%ebp),%eax
	pushl %eax
	call sscanf
	addl $16,%esp
	movl -8(%ebp),%ecx
	movl -4(%ebp),%ebx
	movl %ecx,%eax
	movl %ebx,%edx
	jmp .L36
	.p2align 4,,7
.L36:
	movl -24(%ebp),%ebx
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe35:
	.size	 str2lld,.Lfe35-str2lld
	.align 4
.globl uld2str
	.type	 uld2str,@function
uld2str:
	pushl %ebp
	movl %esp,%ebp
	subl $24,%esp
	addl $-12,%esp
	pushl $20
	call malloc
	addl $16,%esp
	movl %eax,%eax
	movl %eax,-4(%ebp)
	addl $-4,%esp
	movl 8(%ebp),%eax
	pushl %eax
	pushl $.LC7
	movl -4(%ebp),%eax
	pushl %eax
	call sprintf
	addl $16,%esp
	movl -4(%ebp),%edx
	movl %edx,%eax
	jmp .L37
	.p2align 4,,7
.L37:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe36:
	.size	 uld2str,.Lfe36-uld2str
	.align 4
.globl str2uld
	.type	 str2uld,@function
str2uld:
	pushl %ebp
	movl %esp,%ebp
	subl $24,%esp
	addl $-4,%esp
	leal -4(%ebp),%eax
	pushl %eax
	pushl $.LC7
	movl 8(%ebp),%eax
	pushl %eax
	call sscanf
	addl $16,%esp
	movl -4(%ebp),%edx
	movl %edx,%eax
	jmp .L38
	.p2align 4,,7
.L38:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe37:
	.size	 str2uld,.Lfe37-str2uld
	.align 4
.globl SRange2str
	.type	 SRange2str,@function
SRange2str:
	pushl %ebp
	movl %esp,%ebp
	subl $24,%esp
	addl $-12,%esp
	pushl $40
	call malloc
	addl $16,%esp
	movl %eax,%eax
	movl %eax,-4(%ebp)
	addl $-12,%esp
	movl 16(%ebp),%eax
	pushl %eax
	movl 8(%ebp),%eax
	movl 12(%ebp),%edx
	pushl %edx
	pushl %eax
	pushl $.LC3
	movl -4(%ebp),%eax
	pushl %eax
	call sprintf
	addl $32,%esp
	movl -4(%ebp),%edx
	movl %edx,%eax
	jmp .L39
	.p2align 4,,7
.L39:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe38:
	.size	 SRange2str,.Lfe38-SRange2str
	.align 4
.globl str2SRange
	.type	 str2SRange,@function
str2SRange:
	pushl %ebp
	movl %esp,%ebp
	subl $20,%esp
	pushl %ebx
	movl 8(%ebp),%ebx
	leal -12(%ebp),%eax
	leal 8(%eax),%edx
	pushl %edx
	leal -12(%ebp),%eax
	pushl %eax
	pushl $.LC3
	movl 12(%ebp),%eax
	pushl %eax
	call sscanf
	addl $16,%esp
	movl -12(%ebp),%eax
	movl %eax,(%ebx)
	movl -8(%ebp),%eax
	movl %eax,4(%ebx)
	movl -4(%ebp),%eax
	movl %eax,8(%ebx)
	jmp .L40
.L40:
	movl %ebx,%eax
	movl -24(%ebp),%ebx
	movl %ebp,%esp
	popl %ebp
	ret $4
.Lfe39:
	.size	 str2SRange,.Lfe39-str2SRange
.section	.rodata
.LC11:
	.string	"1844674000000000000"
.text
	.align 4
.globl setMaxlld
	.type	 setMaxlld,@function
setMaxlld:
	pushl %ebp
	movl %esp,%ebp
	subl $8,%esp
	addl $-8,%esp
	pushl $.LC11
	movl 8(%ebp),%eax
	pushl %eax
	call strcpy
	addl $16,%esp
.L41:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe40:
	.size	 setMaxlld,.Lfe40-setMaxlld
	.align 4
.globl GETMARKEDWP
	.type	 GETMARKEDWP,@function
GETMARKEDWP:
	pushl %ebp
	movl %esp,%ebp
	subl $8,%esp
	addl $-8,%esp
	addl $-12,%esp
	movl 8(%ebp),%eax
	pushl %eax
	call InterGetMarkedWP
	addl $16,%esp
	movl %eax,%eax
	movl %edx,%edx
	pushl %edx
	pushl %eax
	call lld2str
	addl $16,%esp
	movl %eax,%edx
	movl %edx,%eax
	jmp .L42
	.p2align 4,,7
.L42:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe41:
	.size	 GETMARKEDWP,.Lfe41-GETMARKEDWP
	.align 4
.globl GETMARKEDWPNEW
	.type	 GETMARKEDWPNEW,@function
GETMARKEDWPNEW:
	pushl %ebp
	movl %esp,%ebp
	subl $24,%esp
	addl $-12,%esp
	movl 12(%ebp),%eax
	pushl %eax
	call InterGetMarkedWP
	addl $16,%esp
	movl %eax,%eax
	movl %edx,%edx
	movl %eax,-8(%ebp)
	movl %edx,-4(%ebp)
	movl -8(%ebp),%eax
	movl -4(%ebp),%edx
	pushl %edx
	pushl %eax
	pushl $.LC6
	leal 8(%ebp),%eax
	pushl %eax
	call sprintf
	addl $16,%esp
.L43:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe42:
	.size	 GETMARKEDWPNEW,.Lfe42-GETMARKEDWPNEW
	.align 4
.globl GETMARKEDWPVR
	.type	 GETMARKEDWPVR,@function
GETMARKEDWPVR:
	pushl %ebp
	movl %esp,%ebp
	subl $8,%esp
	addl $-12,%esp
	movl 12(%ebp),%eax
	pushl %eax
	call InterGetMarkedWP
	addl $16,%esp
	movl %eax,%eax
	movl %edx,%edx
	movl 8(%ebp),%ecx
	movl %eax,(%ecx)
	movl %edx,4(%ecx)
.L44:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe43:
	.size	 GETMARKEDWPVR,.Lfe43-GETMARKEDWPVR
	.align 4
.globl GET_MYMARKEDINDEX
	.type	 GET_MYMARKEDINDEX,@function
GET_MYMARKEDINDEX:
	pushl %ebp
	movl %esp,%ebp
	subl $8,%esp
	addl $-8,%esp
	addl $-12,%esp
	movl 8(%ebp),%eax
	pushl %eax
	call InterGetMymarkedIndex
	addl $16,%esp
	movl %eax,%eax
	movl %edx,%edx
	pushl %edx
	pushl %eax
	call lld2str
	addl $16,%esp
	movl %eax,%edx
	movl %edx,%eax
	jmp .L45
	.p2align 4,,7
.L45:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe44:
	.size	 GET_MYMARKEDINDEX,.Lfe44-GET_MYMARKEDINDEX
	.align 4
.globl GET_MYMARKEDINDEXNEW
	.type	 GET_MYMARKEDINDEXNEW,@function
GET_MYMARKEDINDEXNEW:
	pushl %ebp
	movl %esp,%ebp
	subl $24,%esp
	addl $-12,%esp
	movl 12(%ebp),%eax
	pushl %eax
	call InterGetMymarkedIndex
	addl $16,%esp
	movl %eax,%eax
	movl %edx,%edx
	movl %eax,-8(%ebp)
	movl %edx,-4(%ebp)
	movl -8(%ebp),%eax
	movl -4(%ebp),%edx
	pushl %edx
	pushl %eax
	pushl $.LC6
	leal 8(%ebp),%eax
	pushl %eax
	call sprintf
	addl $16,%esp
.L46:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe45:
	.size	 GET_MYMARKEDINDEXNEW,.Lfe45-GET_MYMARKEDINDEXNEW
	.align 4
.globl GET_MYMARKEDINDEXVR
	.type	 GET_MYMARKEDINDEXVR,@function
GET_MYMARKEDINDEXVR:
	pushl %ebp
	movl %esp,%ebp
	subl $8,%esp
	addl $-12,%esp
	movl 12(%ebp),%eax
	pushl %eax
	call InterGetMymarkedIndex
	addl $16,%esp
	movl %eax,%eax
	movl %edx,%edx
	movl 8(%ebp),%ecx
	movl %eax,(%ecx)
	movl %edx,4(%ecx)
.L47:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe46:
	.size	 GET_MYMARKEDINDEXVR,.Lfe46-GET_MYMARKEDINDEXVR
	.align 4
.globl GET_MYMARKEDSIZE
	.type	 GET_MYMARKEDSIZE,@function
GET_MYMARKEDSIZE:
	pushl %ebp
	movl %esp,%ebp
	subl $8,%esp
	addl $-8,%esp
	addl $-12,%esp
	movl 8(%ebp),%eax
	pushl %eax
	call InterGetMymarkedSize
	addl $16,%esp
	movl %eax,%eax
	movl %eax,%edx
	xorl %ecx,%ecx
	pushl %ecx
	pushl %edx
	call lld2str
	addl $16,%esp
	movl %eax,%edx
	movl %edx,%eax
	jmp .L48
	.p2align 4,,7
.L48:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe47:
	.size	 GET_MYMARKEDSIZE,.Lfe47-GET_MYMARKEDSIZE
	.align 4
.globl GET_MYMARKEDSIZENEW
	.type	 GET_MYMARKEDSIZENEW,@function
GET_MYMARKEDSIZENEW:
	pushl %ebp
	movl %esp,%ebp
	subl $24,%esp
	addl $-12,%esp
	movl 12(%ebp),%eax
	pushl %eax
	call InterGetMymarkedSize
	addl $16,%esp
	movl %eax,%eax
	movl %eax,-4(%ebp)
	addl $-4,%esp
	movl -4(%ebp),%eax
	pushl %eax
	pushl $.LC6
	leal 8(%ebp),%eax
	pushl %eax
	call sprintf
	addl $16,%esp
.L49:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe48:
	.size	 GET_MYMARKEDSIZENEW,.Lfe48-GET_MYMARKEDSIZENEW
	.align 4
.globl GET_MYMARKEDDATA
	.type	 GET_MYMARKEDDATA,@function
GET_MYMARKEDDATA:
	pushl %ebp
	movl %esp,%ebp
	subl $104,%esp
	leal -92(%ebp),%eax
	addl $-8,%esp
	movl 8(%ebp),%edx
	pushl %edx
	pushl %eax
	call InterGetMymarkedData
	addl $12,%esp
	addl $-12,%esp
	movl -84(%ebp),%eax
	pushl %eax
	movl -92(%ebp),%eax
	movl -88(%ebp),%edx
	pushl %edx
	pushl %eax
	pushl $.LC3
	leal -80(%ebp),%eax
	pushl %eax
	call sprintf
	addl $32,%esp
	leal -80(%ebp),%edx
	movl %edx,%eax
	jmp .L50
	.p2align 4,,7
.L50:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe49:
	.size	 GET_MYMARKEDDATA,.Lfe49-GET_MYMARKEDDATA
	.align 4
.globl GET_MYMARKEDDATANEW
	.type	 GET_MYMARKEDDATANEW,@function
GET_MYMARKEDDATANEW:
	pushl %ebp
	movl %esp,%ebp
	subl $24,%esp
	leal -12(%ebp),%eax
	addl $-8,%esp
	movl 12(%ebp),%edx
	pushl %edx
	pushl %eax
	call InterGetMymarkedData
	addl $12,%esp
	addl $-12,%esp
	movl -4(%ebp),%eax
	pushl %eax
	movl -12(%ebp),%eax
	movl -8(%ebp),%edx
	pushl %edx
	pushl %eax
	pushl $.LC3
	leal 8(%ebp),%eax
	pushl %eax
	call sprintf
	addl $32,%esp
.L51:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe50:
	.size	 GET_MYMARKEDDATANEW,.Lfe50-GET_MYMARKEDDATANEW
	.align 4
.globl GET_MYMARKEDDATAVR
	.type	 GET_MYMARKEDDATAVR,@function
GET_MYMARKEDDATAVR:
	pushl %ebp
	movl %esp,%ebp
	subl $24,%esp
	leal -12(%ebp),%eax
	addl $-8,%esp
	movl 12(%ebp),%edx
	pushl %edx
	pushl %eax
	call InterGetMymarkedData
	addl $12,%esp
	movl 8(%ebp),%eax
	movl -12(%ebp),%edx
	movl %edx,(%eax)
	movl -8(%ebp),%edx
	movl %edx,4(%eax)
	movl -4(%ebp),%edx
	movl %edx,8(%eax)
.L52:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe51:
	.size	 GET_MYMARKEDDATAVR,.Lfe51-GET_MYMARKEDDATAVR
	.align 4
.globl SET_MARKEDWP
	.type	 SET_MARKEDWP,@function
SET_MARKEDWP:
	pushl %ebp
	movl %esp,%ebp
	subl $8,%esp
	addl $-4,%esp
	addl $-12,%esp
	movl 12(%ebp),%eax
	pushl %eax
	call str2lld
	addl $16,%esp
	movl %eax,%eax
	movl %edx,%edx
	pushl %edx
	pushl %eax
	movl 8(%ebp),%eax
	pushl %eax
	call InterSet_MarkedWP
	addl $16,%esp
.L53:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe52:
	.size	 SET_MARKEDWP,.Lfe52-SET_MARKEDWP
	.align 4
.globl SET_MARKEDWPVR
	.type	 SET_MARKEDWPVR,@function
SET_MARKEDWPVR:
	pushl %ebp
	movl %esp,%ebp
	subl $8,%esp
	addl $-4,%esp
	movl 12(%ebp),%eax
	movl 16(%ebp),%edx
	pushl %edx
	pushl %eax
	movl 8(%ebp),%eax
	pushl %eax
	call InterSet_MarkedWP
	addl $16,%esp
.L54:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe53:
	.size	 SET_MARKEDWPVR,.Lfe53-SET_MARKEDWPVR
	.align 4
.globl GETWP
	.type	 GETWP,@function
GETWP:
	pushl %ebp
	movl %esp,%ebp
	subl $8,%esp
	addl $-8,%esp
	addl $-12,%esp
	movl 8(%ebp),%eax
	pushl %eax
	call InterGetWP
	addl $16,%esp
	movl %eax,%eax
	movl %edx,%edx
	pushl %edx
	pushl %eax
	call lld2str
	addl $16,%esp
	movl %eax,%edx
	movl %edx,%eax
	jmp .L55
	.p2align 4,,7
.L55:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe54:
	.size	 GETWP,.Lfe54-GETWP
	.align 4
.globl GETWPNEW
	.type	 GETWPNEW,@function
GETWPNEW:
	pushl %ebp
	movl %esp,%ebp
	subl $24,%esp
	addl $-12,%esp
	movl 12(%ebp),%eax
	pushl %eax
	call InterGetWP
	addl $16,%esp
	movl %eax,%eax
	movl %edx,%edx
	movl %eax,-8(%ebp)
	movl %edx,-4(%ebp)
	movl -8(%ebp),%eax
	movl -4(%ebp),%edx
	pushl %edx
	pushl %eax
	pushl $.LC6
	leal 8(%ebp),%eax
	pushl %eax
	call sprintf
	addl $16,%esp
.L56:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe55:
	.size	 GETWPNEW,.Lfe55-GETWPNEW
	.align 4
.globl GETWPVR
	.type	 GETWPVR,@function
GETWPVR:
	pushl %ebp
	movl %esp,%ebp
	subl $8,%esp
	addl $-12,%esp
	movl 12(%ebp),%eax
	pushl %eax
	call InterGetWP
	addl $16,%esp
	movl %eax,%eax
	movl %edx,%edx
	movl 8(%ebp),%ecx
	movl %eax,(%ecx)
	movl %edx,4(%ecx)
.L57:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe56:
	.size	 GETWPVR,.Lfe56-GETWPVR
	.align 4
.globl CMPSAMPLEINDEX
	.type	 CMPSAMPLEINDEX,@function
CMPSAMPLEINDEX:
	pushl %ebp
	movl %esp,%ebp
	subl $16,%esp
	pushl %esi
	pushl %ebx
	addl $-12,%esp
	movl 8(%ebp),%eax
	pushl %eax
	call str2lld
	addl $16,%esp
	movl %eax,%ebx
	movl %edx,%esi
	addl $-12,%esp
	movl 12(%ebp),%eax
	pushl %eax
	call str2lld
	addl $16,%esp
	movl %eax,-8(%ebp)
	movl %edx,-4(%ebp)
	movl %ebx,%edx
	subl -8(%ebp),%edx
	movl %edx,%eax
	jmp .L58
	.p2align 4,,7
.L58:
	leal -24(%ebp),%esp
	popl %ebx
	popl %esi
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe57:
	.size	 CMPSAMPLEINDEX,.Lfe57-CMPSAMPLEINDEX
	.align 4
.globl CMPSAMPLESIZE
	.type	 CMPSAMPLESIZE,@function
CMPSAMPLESIZE:
	pushl %ebp
	movl %esp,%ebp
	subl $20,%esp
	pushl %ebx
	addl $-12,%esp
	movl 8(%ebp),%eax
	pushl %eax
	call str2uld
	addl $16,%esp
	movl %eax,%ebx
	addl $-12,%esp
	movl 12(%ebp),%eax
	pushl %eax
	call str2uld
	addl $16,%esp
	movl %eax,%eax
	movl %ebx,%edx
	subl %eax,%edx
	movl %edx,%eax
	jmp .L59
	.p2align 4,,7
.L59:
	movl -24(%ebp),%ebx
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe58:
	.size	 CMPSAMPLESIZE,.Lfe58-CMPSAMPLESIZE
	.align 4
.globl CMPSAMPLEINDEXVR
	.type	 CMPSAMPLEINDEXVR,@function
CMPSAMPLEINDEXVR:
	pushl %ebp
	movl %esp,%ebp
	movl 8(%ebp),%edx
	subl 16(%ebp),%edx
	movl %edx,%eax
	jmp .L60
	.p2align 4,,7
.L60:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe59:
	.size	 CMPSAMPLEINDEXVR,.Lfe59-CMPSAMPLEINDEXVR
	.align 4
.globl GET_NUMBERINPUTS
	.type	 GET_NUMBERINPUTS,@function
GET_NUMBERINPUTS:
	pushl %ebp
	movl %esp,%ebp
	subl $8,%esp
	addl $-12,%esp
	movl 8(%ebp),%eax
	pushl %eax
	call InterGetNumberInputs
	addl $16,%esp
	movl %eax,%edx
	movl %edx,%eax
	jmp .L61
	.p2align 4,,7
.L61:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe60:
	.size	 GET_NUMBERINPUTS,.Lfe60-GET_NUMBERINPUTS
	.align 4
.globl DEBUG_INDEX
	.type	 DEBUG_INDEX,@function
DEBUG_INDEX:
	pushl %ebp
	movl %esp,%ebp
	subl $108,%esp
	pushl %edi
	pushl %esi
	pushl %ebx
	movl 8(%ebp),%ebx
	addl $-8,%esp
	movl 12(%ebp),%eax
	pushl %eax
	leal -100(%ebp),%eax
	pushl %eax
	call strcpy
	addl $16,%esp
	addl $-8,%esp
	movl 16(%ebp),%eax
	pushl %eax
	leal -100(%ebp),%eax
	leal 50(%eax),%edx
	pushl %edx
	call strcpy
	addl $16,%esp
	movl %ebx,%edi
	leal -100(%ebp),%esi
	cld
	movl $25,%ecx
	rep
	movsl
	jmp .L62
.L62:
	movl %ebx,%eax
	leal -120(%ebp),%esp
	popl %ebx
	popl %esi
	popl %edi
	movl %ebp,%esp
	popl %ebp
	ret $4
.Lfe61:
	.size	 DEBUG_INDEX,.Lfe61-DEBUG_INDEX
	.align 4
.globl DEBUG_RANGE
	.type	 DEBUG_RANGE,@function
DEBUG_RANGE:
	pushl %ebp
	movl %esp,%ebp
	subl $108,%esp
	pushl %edi
	pushl %esi
	pushl %ebx
	movl 8(%ebp),%ebx
	addl $-8,%esp
	movl 12(%ebp),%eax
	pushl %eax
	leal -100(%ebp),%eax
	pushl %eax
	call strcpy
	addl $16,%esp
	addl $-8,%esp
	movl 16(%ebp),%eax
	pushl %eax
	leal -100(%ebp),%eax
	leal 50(%eax),%edx
	pushl %edx
	call strcpy
	addl $16,%esp
	movl %ebx,%edi
	leal -100(%ebp),%esi
	cld
	movl $25,%ecx
	rep
	movsl
	jmp .L63
.L63:
	movl %ebx,%eax
	leal -120(%ebp),%esp
	popl %ebx
	popl %esi
	popl %edi
	movl %ebp,%esp
	popl %ebp
	ret $4
.Lfe62:
	.size	 DEBUG_RANGE,.Lfe62-DEBUG_RANGE
	.align 4
.globl DEBUG_INT
	.type	 DEBUG_INT,@function
DEBUG_INT:
	pushl %ebp
	movl %esp,%ebp
	movl 8(%ebp),%eax
.L64:
	movl %eax,%eax
	movl %ebp,%esp
	popl %ebp
	ret $4
.Lfe63:
	.size	 DEBUG_INT,.Lfe63-DEBUG_INT
	.align 4
.globl DEBUG_UNINT
	.type	 DEBUG_UNINT,@function
DEBUG_UNINT:
	pushl %ebp
	movl %esp,%ebp
	movl 8(%ebp),%eax
.L65:
	movl %eax,%eax
	movl %ebp,%esp
	popl %ebp
	ret $4
.Lfe64:
	.size	 DEBUG_UNINT,.Lfe64-DEBUG_UNINT
	.align 4
.globl GET_OUTPUTSIZE
	.type	 GET_OUTPUTSIZE,@function
GET_OUTPUTSIZE:
	pushl %ebp
	movl %esp,%ebp
	subl $8,%esp
	addl $-12,%esp
	movl 8(%ebp),%eax
	pushl %eax
	call InterGetOutputSize
	addl $16,%esp
	movl %eax,%edx
	movl %edx,%eax
	jmp .L66
	.p2align 4,,7
.L66:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe65:
	.size	 GET_OUTPUTSIZE,.Lfe65-GET_OUTPUTSIZE
	.align 4
.globl CHECKSAMPLESIZE
	.type	 CHECKSAMPLESIZE,@function
CHECKSAMPLESIZE:
	pushl %ebp
	movl %esp,%ebp
	subl $40,%esp
	leal -12(%ebp),%eax
	leal 8(%eax),%edx
	pushl %edx
	leal -12(%ebp),%eax
	pushl %eax
	pushl $.LC3
	movl 8(%ebp),%eax
	pushl %eax
	call sscanf
	addl $16,%esp
	leal -24(%ebp),%eax
	leal 8(%eax),%edx
	pushl %edx
	leal -24(%ebp),%eax
	pushl %eax
	pushl $.LC3
	movl 12(%ebp),%eax
	pushl %eax
	call sscanf
	addl $16,%esp
	movl -4(%ebp),%eax
	xorl %edx,%edx
	addl %eax,-12(%ebp)
	adcl %edx,-8(%ebp)
	movl -16(%ebp),%eax
	movl %eax,%edx
	leal (%edx,%edx),%eax
	movl %eax,-16(%ebp)
	movl -16(%ebp),%eax
	xorl %edx,%edx
	addl %eax,-24(%ebp)
	adcl %edx,-20(%ebp)
	movl -12(%ebp),%edx
	subl -24(%ebp),%edx
	movl %edx,%eax
	jmp .L67
	.p2align 4,,7
.L67:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe66:
	.size	 CHECKSAMPLESIZE,.Lfe66-CHECKSAMPLESIZE
	.align 4
.globl UPDATESAMPLE
	.type	 UPDATESAMPLE,@function
UPDATESAMPLE:
	pushl %ebp
	movl %esp,%ebp
	subl $24,%esp
	leal -12(%ebp),%eax
	leal 8(%eax),%edx
	pushl %edx
	leal -12(%ebp),%eax
	pushl %eax
	pushl $.LC3
	movl 8(%ebp),%eax
	pushl %eax
	call sscanf
	addl $16,%esp
	movl -4(%ebp),%eax
	xorl %edx,%edx
	addl %eax,-12(%ebp)
	adcl %edx,-8(%ebp)
	addl $-12,%esp
	movl -4(%ebp),%eax
	pushl %eax
	movl -12(%ebp),%eax
	movl -8(%ebp),%edx
	pushl %edx
	pushl %eax
	pushl $.LC3
	movl -16(%ebp),%eax
	pushl %eax
	call sprintf
	addl $32,%esp
	movl -16(%ebp),%edx
	movl %edx,%eax
	jmp .L68
	.p2align 4,,7
.L68:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe67:
	.size	 UPDATESAMPLE,.Lfe67-UPDATESAMPLE
	.align 4
.globl UPDATESAMPLENEW
	.type	 UPDATESAMPLENEW,@function
UPDATESAMPLENEW:
	pushl %ebp
	movl %esp,%ebp
	subl $24,%esp
	leal -12(%ebp),%eax
	leal 8(%eax),%edx
	pushl %edx
	leal -12(%ebp),%eax
	pushl %eax
	pushl $.LC3
	leal 8(%ebp),%eax
	pushl %eax
	call sscanf
	addl $16,%esp
	movl -4(%ebp),%eax
	xorl %edx,%edx
	addl %eax,-12(%ebp)
	adcl %edx,-8(%ebp)
	addl $-12,%esp
	movl -4(%ebp),%eax
	pushl %eax
	movl -12(%ebp),%eax
	movl -8(%ebp),%edx
	pushl %edx
	pushl %eax
	pushl $.LC3
	leal 8(%ebp),%eax
	pushl %eax
	call sprintf
	addl $32,%esp
.L69:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe68:
	.size	 UPDATESAMPLENEW,.Lfe68-UPDATESAMPLENEW
	.align 4
.globl COMP_FOR_MAINSINK
	.type	 COMP_FOR_MAINSINK,@function
COMP_FOR_MAINSINK:
	pushl %ebp
	movl %esp,%ebp
	subl $24,%esp
	leal -12(%ebp),%eax
	leal 8(%eax),%edx
	pushl %edx
	leal -12(%ebp),%eax
	pushl %eax
	pushl $.LC3
	movl 8(%ebp),%eax
	pushl %eax
	call sscanf
	addl $16,%esp
	movl -4(%ebp),%eax
	xorl %edx,%edx
	addl %eax,-12(%ebp)
	adcl %edx,-8(%ebp)
	addl $-12,%esp
	movl 12(%ebp),%eax
	pushl %eax
	call InterComputeForMainSink
	addl $16,%esp
	movl %eax,%edx
	movl %edx,%eax
	jmp .L70
	.p2align 4,,7
.L70:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe69:
	.size	 COMP_FOR_MAINSINK,.Lfe69-COMP_FOR_MAINSINK
	.align 4
.globl INSIDE_COMP_FIT
	.type	 INSIDE_COMP_FIT,@function
INSIDE_COMP_FIT:
	pushl %ebp
	movl %esp,%ebp
	subl $60,%esp
	pushl %edi
	pushl %esi
	pushl %ebx
	leal -12(%ebp),%eax
	leal 8(%eax),%edx
	pushl %edx
	leal -12(%ebp),%eax
	pushl %eax
	pushl $.LC3
	movl 8(%ebp),%eax
	pushl %eax
	call sscanf
	addl $16,%esp
	leal -24(%ebp),%eax
	leal 8(%eax),%edx
	pushl %edx
	leal -24(%ebp),%eax
	pushl %eax
	pushl $.LC3
	movl 12(%ebp),%eax
	pushl %eax
	call sscanf
	addl $16,%esp
	.p2align 4,,7
.L72:
	addl $-12,%esp
	movl 16(%ebp),%eax
	pushl %eax
	call InterComputeForMainSink
	addl $16,%esp
	movl -16(%ebp),%eax
	movl %eax,%edx
	leal (%edx,%edx),%eax
	movl %eax,%ecx
	xorl %ebx,%ebx
	movl %ecx,%eax
	movl %ebx,%edx
	addl -24(%ebp),%eax
	adcl -20(%ebp),%edx
	movl -4(%ebp),%esi
	xorl %edi,%edi
	movl %esi,%ecx
	movl %edi,%ebx
	addl -12(%ebp),%ecx
	adcl -8(%ebp),%ebx
	cmpl %ebx,%edx
	ja .L75
	cmpl %ebx,%edx
	jne .L76
	cmpl %ecx,%eax
	ja .L75
	cmpl %ecx,%eax
	jne .L76
	jmp .L76
	.p2align 4,,7
.L76:
	movl -16(%ebp),%eax
	xorl %edx,%edx
	addl %eax,-24(%ebp)
	adcl %edx,-20(%ebp)
	jmp .L77
	.p2align 4,,7
.L75:
	jmp .L73
	.p2align 4,,7
.L77:
	movl 16(%ebp),%eax
	pushl %eax
	movl -16(%ebp),%eax
	pushl %eax
	movl -20(%ebp),%eax
	pushl %eax
	movl -24(%ebp),%eax
	pushl %eax
	call InterFitRangeForMainSink
	addl $16,%esp
	movl %eax,%eax
	movl %eax,-28(%ebp)
	movl -28(%ebp),%eax
	movl (%eax),%edx
	movl 4(%eax),%ecx
	movl %edx,-24(%ebp)
	movl %ecx,-20(%ebp)
	movl -28(%ebp),%eax
	movl 8(%eax),%edx
	movl %edx,-16(%ebp)
.L74:
	jmp .L72
	.p2align 4,,7
.L73:
	addl $-12,%esp
	movl -16(%ebp),%eax
	pushl %eax
	movl -24(%ebp),%eax
	movl -20(%ebp),%edx
	pushl %edx
	pushl %eax
	pushl $.LC3
	movl -32(%ebp),%eax
	pushl %eax
	call sprintf
	addl $32,%esp
	movl -32(%ebp),%edx
	movl %edx,%eax
	jmp .L71
	.p2align 4,,7
.L71:
	leal -72(%ebp),%esp
	popl %ebx
	popl %esi
	popl %edi
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe70:
	.size	 INSIDE_COMP_FIT,.Lfe70-INSIDE_COMP_FIT
	.align 4
.globl CONNECT_MODULES
	.type	 CONNECT_MODULES,@function
CONNECT_MODULES:
	pushl %ebp
	movl %esp,%ebp
	subl $8,%esp
	movl 20(%ebp),%eax
	pushl %eax
	movl 16(%ebp),%eax
	pushl %eax
	movl 12(%ebp),%eax
	pushl %eax
	movl 8(%ebp),%eax
	pushl %eax
	call InterConnectModules
	addl $16,%esp
.L78:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe71:
	.size	 CONNECT_MODULES,.Lfe71-CONNECT_MODULES
	.align 4
.globl INITIAL_SINK
	.type	 INITIAL_SINK,@function
INITIAL_SINK:
	pushl %ebp
	movl %esp,%ebp
	subl $8,%esp
	addl $-12,%esp
	movl 8(%ebp),%eax
	pushl %eax
	call InterInitializeSink
	addl $16,%esp
.L79:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe72:
	.size	 INITIAL_SINK,.Lfe72-INITIAL_SINK
	.align 4
.globl GET_FREQUENCY
	.type	 GET_FREQUENCY,@function
GET_FREQUENCY:
	pushl %ebp
	movl %esp,%ebp
	subl $24,%esp
	addl $-12,%esp
	movl 8(%ebp),%eax
	pushl %eax
	call InterGetFrequency
	addl $16,%esp
	fstps -4(%ebp)
	flds -4(%ebp)
	jmp .L80
	.p2align 4,,7
.L80:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe73:
	.size	 GET_FREQUENCY,.Lfe73-GET_FREQUENCY
	.align 4
.globl NEWGETWP
	.type	 NEWGETWP,@function
NEWGETWP:
	pushl %ebp
	movl %esp,%ebp
	subl $20,%esp
	pushl %ebx
	addl $-12,%esp
	movl 8(%ebp),%eax
	pushl %eax
	call InterGetWP
	addl $16,%esp
	movl %eax,%ecx
	movl %edx,%ebx
	movl %ecx,%edx
	movl %edx,%eax
	jmp .L81
	.p2align 4,,7
.L81:
	movl -24(%ebp),%ebx
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe74:
	.size	 NEWGETWP,.Lfe74-NEWGETWP
	.align 4
.globl GET_TIMESTAMP
	.type	 GET_TIMESTAMP,@function
GET_TIMESTAMP:
	pushl %ebp
	movl %esp,%ebp
	subl $20,%esp
	pushl %ebx
	addl $-8,%esp
	pushl $0
	leal -8(%ebp),%eax
	pushl %eax
	call gettimeofday
	addl $16,%esp
	imull $1000000,-8(%ebp),%eax
	movl %eax,%edx
	addl -4(%ebp),%edx
	movl %edx,%ecx
	movl %edx,%ebx
	sarl $31,%ebx
	movl %ecx,%eax
	movl %ebx,%edx
	jmp .L82
	.p2align 4,,7
.L82:
	movl -24(%ebp),%ebx
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe75:
	.size	 GET_TIMESTAMP,.Lfe75-GET_TIMESTAMP
.globl __cmpdi2
.section	.rodata
	.align 16
.LC12:
	.long 0x0,0x80000000,0x403f
	.align 8
.LC13:
	.long 0x0,0x412e8480
.text
	.align 4
.globl ELAPSE_TIME
	.type	 ELAPSE_TIME,@function
ELAPSE_TIME:
	pushl %ebp
	movl %esp,%ebp
	subl $56,%esp
	addl $-8,%esp
	pushl $0
	leal -8(%ebp),%eax
	pushl %eax
	call gettimeofday
	addl $16,%esp
	imull $1000000,-8(%ebp),%eax
	movl %eax,%edx
	addl -4(%ebp),%edx
	movl %edx,-16(%ebp)
	movl %edx,%eax
	sarl $31,%eax
	movl %eax,-12(%ebp)
	movl -16(%ebp),%eax
	movl -12(%ebp),%edx
	subl 8(%ebp),%eax
	sbbl 12(%ebp),%edx
	movl %eax,-24(%ebp)
	movl %edx,-20(%ebp)
	fildll -24(%ebp)
	fstpt -48(%ebp)
	pushl $0
	pushl $0
	pushl %edx
	pushl %eax
	call __cmpdi2
	addl $16,%esp
	movl %eax,%eax
	cmpl $1,%eax
	jge .L85
	fldt .LC12
	fldt -48(%ebp)
	faddp %st,%st(1)
	fstpt -48(%ebp)
.L85:
	fldt -48(%ebp)
	fstpl -32(%ebp)
	fldl -32(%ebp)
	fldl 16(%ebp)
	fldl .LC13
	fmulp %st,%st(1)
	fcompp
	fnstsw %ax
	andb $69,%ah
	decb %ah
	cmpb $64,%ah
	jae .L84
	movl $1,%eax
	jmp .L83
	jmp .L86
	.p2align 4,,7
.L84:
	xorl %eax,%eax
	jmp .L83
	.p2align 4,,7
.L86:
.L83:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe76:
	.size	 ELAPSE_TIME,.Lfe76-ELAPSE_TIME
.globl __fixunssfdi
	.align 4
.globl ALAMEACHSEC
	.type	 ALAMEACHSEC,@function
ALAMEACHSEC:
	pushl %ebp
	movl %esp,%ebp
	subl $16,%esp
	pushl %esi
	pushl %ebx
	addl $-12,%esp
	addl $-12,%esp
	flds 8(%ebp)
	subl $4,%esp
	fstps (%esp)
	call __fixunssfdi
	addl $16,%esp
	movl %eax,%ecx
	movl %edx,%ebx
	movl $1000000,%esi
	movl %ecx,%eax
	mull %esi
	movl %eax,-8(%ebp)
	movl %edx,-4(%ebp)
	imull $0,%ecx,%esi
	addl %esi,-4(%ebp)
	imull $1000000,%ebx,%ecx
	addl %ecx,-4(%ebp)
	movl -8(%ebp),%eax
	movl -4(%ebp),%edx
	movl %eax,-8(%ebp)
	movl %edx,-4(%ebp)
	movl -8(%ebp),%edx
	pushl %edx
	call usleep
	addl $16,%esp
	movl $1,%eax
	jmp .L87
	.p2align 4,,7
.L87:
	leal -24(%ebp),%esp
	popl %ebx
	popl %esi
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe77:
	.size	 ALAMEACHSEC,.Lfe77-ALAMEACHSEC
.globl __fixunsdfdi
.section	.rodata
	.align 16
.LC14:
	.long 0x0,0x80000000,0x403f
.text
	.align 4
.globl EVAL_TS_TM
	.type	 EVAL_TS_TM,@function
EVAL_TS_TM:
	pushl %ebp
	movl %esp,%ebp
	subl $64,%esp
	pushl %esi
	pushl %ebx
	flds 12(%ebp)
	fmull 16(%ebp)
	movl 24(%ebp),%eax
	movl 28(%ebp),%edx
	subl %edx,%eax
	movl %eax,%edx
	xorl %ecx,%ecx
	movl %edx,-24(%ebp)
	movl %ecx,-20(%ebp)
	fildll -24(%ebp)
	fcompp
	fnstsw %ax
	andb $69,%ah
	cmpb $1,%ah
	jne .L89
	flds 12(%ebp)
	fmull 16(%ebp)
	addl $-8,%esp
	subl $8,%esp
	fstpl (%esp)
	call __fixunsdfdi
	addl $16,%esp
	movl %eax,%eax
	movl %edx,%edx
	movl 24(%ebp),%ecx
	movl 28(%ebp),%ebx
	subl %ebx,%ecx
	movl %ecx,%ebx
	xorl %esi,%esi
	subl %ebx,%eax
	sbbl %esi,%edx
	movl %eax,-24(%ebp)
	movl %edx,-20(%ebp)
	fildll -24(%ebp)
	fstpt -48(%ebp)
	pushl $0
	pushl $0
	pushl %edx
	pushl %eax
	call __cmpdi2
	addl $16,%esp
	movl %eax,%eax
	cmpl $1,%eax
	jge .L90
	fldt .LC14
	fldt -48(%ebp)
	faddp %st,%st(1)
	fstpt -48(%ebp)
.L90:
	fldt -48(%ebp)
	fstps -4(%ebp)
	flds -4(%ebp)
	flds 8(%ebp)
	fdivs 12(%ebp)
	fmulp %st,%st(1)
	addl $-12,%esp
	subl $4,%esp
	fstps (%esp)
	call __fixunssfdi
	addl $16,%esp
	movl %eax,%ecx
	movl %edx,%ebx
	movl %ecx,%eax
	movl %ebx,%edx
	jmp .L88
	.p2align 4,,7
.L89:
	movl $0,%eax
	movl $0,%edx
	jmp .L88
	.p2align 4,,7
.L88:
	leal -72(%ebp),%esp
	popl %ebx
	popl %esi
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe78:
	.size	 EVAL_TS_TM,.Lfe78-EVAL_TS_TM
.globl __udivdi3
.section	.rodata
.LC16:
	.string	"missed deadline : skip\t%lld\n"
	.align 16
.LC15:
	.long 0x0,0x80000000,0x403f
.text
	.align 4
.globl EVAL_TS
	.type	 EVAL_TS,@function
EVAL_TS:
	pushl %ebp
	movl %esp,%ebp
	subl $68,%esp
	pushl %ebx
	leal -20(%ebp),%eax
	leal 8(%eax),%edx
	pushl %edx
	leal -20(%ebp),%eax
	pushl %eax
	pushl $.LC3
	movl 12(%ebp),%eax
	pushl %eax
	call sscanf
	addl $16,%esp
	movl 16(%ebp),%eax
	movl 20(%ebp),%edx
	subl 24(%ebp),%eax
	sbbl 28(%ebp),%edx
	pushl $0
	pushl $1000000
	pushl %edx
	pushl %eax
	call __udivdi3
	addl $16,%esp
	movl %eax,%eax
	movl %edx,%edx
	movl %eax,-28(%ebp)
	movl %edx,-24(%ebp)
	fildll -28(%ebp)
	fstpt -48(%ebp)
	pushl $0
	pushl $0
	pushl %edx
	pushl %eax
	call __cmpdi2
	addl $16,%esp
	movl %eax,%eax
	cmpl $1,%eax
	jge .L92
	fldt .LC15
	fldt -48(%ebp)
	faddp %st,%st(1)
	fstpt -48(%ebp)
.L92:
	fldt -48(%ebp)
	fstps -32(%ebp)
	flds -32(%ebp)
	fmuls 8(%ebp)
	addl $-12,%esp
	subl $4,%esp
	fstps (%esp)
	call __fixunssfdi
	addl $16,%esp
	movl %eax,%eax
	movl %edx,%edx
	movl %eax,-8(%ebp)
	movl %edx,-4(%ebp)
	movl -12(%ebp),%eax
	xorl %edx,%edx
	cmpl %edx,-4(%ebp)
	ja .L94
	cmpl %edx,-4(%ebp)
	jne .L93
	cmpl %eax,-8(%ebp)
	ja .L94
	cmpl %eax,-8(%ebp)
	jne .L93
	jmp .L93
	.p2align 4,,7
.L94:
	addl $-4,%esp
	movl -12(%ebp),%eax
	xorl %edx,%edx
	movl -8(%ebp),%ecx
	movl -4(%ebp),%ebx
	subl %eax,%ecx
	sbbl %edx,%ebx
	pushl %ebx
	pushl %ecx
	pushl $.LC16
	call printf
	addl $16,%esp
	movl -12(%ebp),%eax
	xorl %edx,%edx
	movl -8(%ebp),%ecx
	movl -4(%ebp),%ebx
	subl %eax,%ecx
	sbbl %edx,%ebx
	movl %ecx,%eax
	movl %ebx,%edx
	jmp .L91
	.p2align 4,,7
.L93:
	movl $0,%eax
	movl $0,%edx
	jmp .L91
	.p2align 4,,7
.L91:
	movl -72(%ebp),%ebx
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe79:
	.size	 EVAL_TS,.Lfe79-EVAL_TS
	.align 4
.globl SKIP_SAMPLEDATA
	.type	 SKIP_SAMPLEDATA,@function
SKIP_SAMPLEDATA:
	pushl %ebp
	movl %esp,%ebp
	subl $20,%esp
	pushl %ebx
	addl $-12,%esp
	movl 16(%ebp),%eax
	pushl %eax
	call str2lld
	addl $16,%esp
	movl %eax,%eax
	movl %edx,%edx
	movl %eax,%ecx
	movl %edx,%ebx
	addl 8(%ebp),%ecx
	adcl 12(%ebp),%ebx
	pushl %ebx
	pushl %ecx
	pushl $.LC6
	movl -4(%ebp),%eax
	pushl %eax
	call sprintf
	addl $16,%esp
	movl -4(%ebp),%edx
	movl %edx,%eax
	jmp .L95
	.p2align 4,,7
.L95:
	movl -24(%ebp),%ebx
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe80:
	.size	 SKIP_SAMPLEDATA,.Lfe80-SKIP_SAMPLEDATA
	.align 4
.globl CMPSMPINDEX
	.type	 CMPSMPINDEX,@function
CMPSMPINDEX:
	pushl %ebp
	movl %esp,%ebp
	subl $40,%esp
	leal -12(%ebp),%eax
	leal 8(%eax),%edx
	pushl %edx
	leal -12(%ebp),%eax
	pushl %eax
	pushl $.LC3
	movl 12(%ebp),%eax
	pushl %eax
	call sscanf
	addl $16,%esp
	leal -24(%ebp),%eax
	leal 8(%eax),%edx
	pushl %edx
	leal -24(%ebp),%eax
	pushl %eax
	pushl $.LC3
	movl 16(%ebp),%eax
	pushl %eax
	call sscanf
	addl $16,%esp
	flds 8(%ebp)
	fnstcw -26(%ebp)
	movw -26(%ebp),%dx
	orw $3072,%dx
	movw %dx,-28(%ebp)
	fldcw -28(%ebp)
	fistpl -32(%ebp)
	movl -32(%ebp),%eax
	fldcw -26(%ebp)
	movl %eax,%ecx
	imull -4(%ebp),%ecx
	movl %ecx,%eax
	xorl %edx,%edx
	cmpl -24(%ebp),%eax
	jne .L97
	cmpl -20(%ebp),%edx
	jne .L97
	movl $1,%eax
	jmp .L96
	jmp .L98
	.p2align 4,,7
.L97:
	xorl %eax,%eax
	jmp .L96
	.p2align 4,,7
.L98:
.L96:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe81:
	.size	 CMPSMPINDEX,.Lfe81-CMPSMPINDEX
	.align 4
.globl CMPULL
	.type	 CMPULL,@function
CMPULL:
	pushl %ebp
	movl %esp,%ebp
	movl 12(%ebp),%eax
	cmpl 20(%ebp),%eax
	ja .L101
	movl 12(%ebp),%eax
	cmpl 20(%ebp),%eax
	jne .L100
	movl 8(%ebp),%eax
	cmpl 16(%ebp),%eax
	ja .L101
	movl 8(%ebp),%eax
	cmpl 16(%ebp),%eax
	jne .L100
	jmp .L100
	.p2align 4,,7
.L101:
	movl $1,%eax
	jmp .L99
	jmp .L102
	.p2align 4,,7
.L100:
	xorl %eax,%eax
	jmp .L99
	.p2align 4,,7
.L102:
.L99:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe82:
	.size	 CMPULL,.Lfe82-CMPULL
	.align 4
.globl SKIPPING_DATA
	.type	 SKIPPING_DATA,@function
SKIPPING_DATA:
	pushl %ebp
	movl %esp,%ebp
	subl $8,%esp
	addl $-12,%esp
	movl 8(%ebp),%eax
	pushl %eax
	call InterSaveSkippedDataSize
	addl $16,%esp
.L103:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe83:
	.size	 SKIPPING_DATA,.Lfe83-SKIPPING_DATA
	.ident	"GCC: (GNU) 2.95.3 20010315 (release)"
