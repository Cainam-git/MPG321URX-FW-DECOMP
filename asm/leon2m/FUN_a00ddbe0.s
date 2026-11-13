# leon2m FUN_a00ddbe0 0xa00ddbe0-0xa00ddc50 (112 bytes)
a00ddbe0:  82 0a 20 ff  and  %o0, 0xff, %g1
a00ddbe4:  80 a0 60 08  cmp  %g1, 8
a00ddbe8:  18 80 00 17  bgu  0xa00ddc44
a00ddbec:  90 10 20 00  clr  %o0
a00ddbf0:  19 00 01 f6  sethi  %hi(0x7d800), %o4
a00ddbf4:  83 28 60 02  sll  %g1, 2, %g1
a00ddbf8:  9a 13 20 e0  or  %o4, 0xe0, %o5
a00ddbfc:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a00ddc00:  81 c3 00 00  jmp  %o4
a00ddc04:  01 00 00 00  nop
a00ddc08:  10 80 00 0f  b  0xa00ddc44
a00ddc0c:  90 10 30 83  mov  -3965, %o0	! 0xfffff083
a00ddc10:  10 80 00 0d  b  0xa00ddc44
a00ddc14:  90 10 30 84  mov  -3964, %o0
a00ddc18:  10 80 00 0b  b  0xa00ddc44
a00ddc1c:  90 10 30 0c  mov  -4084, %o0
a00ddc20:  10 80 00 09  b  0xa00ddc44
a00ddc24:  90 10 30 0d  mov  -4083, %o0
a00ddc28:  10 80 00 07  b  0xa00ddc44
a00ddc2c:  90 10 30 0e  mov  -4082, %o0
a00ddc30:  10 80 00 05  b  0xa00ddc44
a00ddc34:  90 10 30 0f  mov  -4081, %o0
a00ddc38:  10 80 00 03  b  0xa00ddc44
a00ddc3c:  90 10 30 81  mov  -3967, %o0
a00ddc40:  90 10 30 82  mov  -3966, %o0
a00ddc44:  91 2a 20 10  sll  %o0, 0x10, %o0
a00ddc48:  81 c3 e0 08  retl
a00ddc4c:  91 32 20 10  srl  %o0, 0x10, %o0
