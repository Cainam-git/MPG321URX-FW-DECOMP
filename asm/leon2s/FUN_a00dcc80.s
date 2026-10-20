# leon2s FUN_a00dcc80 0xa00dcc80-0xa00dccd8 (88 bytes)
a00dcc80:  9d e3 bf 98  save  %sp, -104, %sp
a00dcc84:  03 2a 01 e5  sethi  %hi(0xa8079400), %g1
a00dcc88:  e0 08 61 3d  ldub  [ %g1 + 0x13d ], %l0	! 0xa807953d
a00dcc8c:  7f ff ff f1  call  0xa00dcc50
a00dcc90:  90 10 00 10  mov  %l0, %o0
a00dcc94:  31 27 c7 3b  sethi  %hi(0x9f1cec00), %i0
a00dcc98:  80 a4 20 00  cmp  %l0, 0
a00dcc9c:  02 80 00 0c  be  0xa00dcccc
a00dcca0:  b0 16 20 38  or  %i0, 0x38, %i0
a00dcca4:  31 27 c7 3b  sethi  %hi(0x9f1cec00), %i0
a00dcca8:  80 a4 20 02  cmp  %l0, 2
a00dccac:  02 80 00 08  be  0xa00dcccc
a00dccb0:  b0 16 20 50  or  %i0, 0x50, %i0
a00dccb4:  31 27 c7 3b  sethi  %hi(0x9f1cec00), %i0
a00dccb8:  80 a4 20 03  cmp  %l0, 3
a00dccbc:  02 80 00 04  be  0xa00dcccc
a00dccc0:  b0 16 20 68  or  %i0, 0x68, %i0
a00dccc4:  31 27 c7 3b  sethi  %hi(0x9f1cec00), %i0
a00dccc8:  b0 16 20 80  or  %i0, 0x80, %i0	! 0x9f1cec80
a00dcccc:  40 3a 99 fe  call  0xa0f834c4
a00dccd0:  81 e8 00 00  restore
a00dccd4:  01 00 00 00  nop
