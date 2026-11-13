# leon2m FUN_a011ce80 0xa011ce80-0xa011cf88 (108 bytes)
a011ce80:  9d e3 bf 98  save  %sp, -104, %sp
a011ce84:  9e 10 00 1a  mov  %i2, %o7
a011ce88:  80 a6 20 04  cmp  %i0, 4
a011ce8c:  ba 10 20 00  clr  %i5
a011ce90:  18 80 00 0f  bgu  0xa011cecc
a011ce94:  b4 10 20 00  clr  %i2
a011ce98:  83 2e 20 02  sll  %i0, 2, %g1
a011ce9c:  31 00 02 f3  sethi  %hi(0xbcc00), %i0
a011cea0:  ba 16 22 6c  or  %i0, 0x26c, %i5	! 0xbce6c
a011cea4:  f8 07 40 01  ld  [ %i5 + %g1 ], %i4
a011cea8:  81 c7 00 00  jmp  %i4
a011ceac:  01 00 00 00  nop
a011ceb0:  ba 10 00 19  mov  %i1, %i5
a011ceb4:  b2 0e 60 ff  and  %i1, 0xff, %i1
a011ceb8:  80 a6 60 10  cmp  %i1, 0x10
a011cebc:  38 80 00 02  bgu,a   0xa011cec4
a011cec0:  ba 10 20 10  mov  0x10, %i5
a011cec4:  37 27 c6 c1  sethi  %hi(0x9f1b0400), %i3
a011cec8:  b4 16 e2 20  or  %i3, 0x220, %i2	! 0x9f1b0620
a011cecc:  b6 0f 60 ff  and  %i5, 0xff, %i3
a011ced0:  80 a6 e0 00  cmp  %i3, 0
a011ced4:  02 80 00 2b  be  0xa011cf80
a011ced8:  b8 10 20 00  clr  %i4
a011cedc:  ba 10 20 00  clr  %i5
a011cee0:  c2 0f 40 1a  ldub  [ %i5 + %i2 ], %g1
a011cee4:  c2 2f 40 0f  stb  %g1, [ %i5 + %o7 ]
a011cee8:  b8 07 20 01  inc  %i4
a011ceec:  ba 0f 20 ff  and  %i4, 0xff, %i5
a011cef0:  80 a7 40 1b  cmp  %i5, %i3
a011cef4:  2a bf ff fc  bcs,a   0xa011cee4
a011cef8:  c2 0f 40 1a  ldub  [ %i5 + %i2 ], %g1
a011cefc:  30 80 00 21  b,a   0xa011cf80
a011cf00:  b4 0e 60 ff  and  %i1, 0xff, %i2
a011cf04:  80 a6 a0 28  cmp  %i2, 0x28
a011cf08:  08 80 00 03  bleu  0xa011cf14
a011cf0c:  ba 10 00 19  mov  %i1, %i5
a011cf10:  ba 10 20 28  mov  0x28, %i5
a011cf14:  39 27 c6 c1  sethi  %hi(0x9f1b0400), %i4
a011cf18:  10 bf ff ed  b  0xa011cecc
a011cf1c:  b4 17 22 30  or  %i4, 0x230, %i2	! 0x9f1b0630
a011cf20:  ba 10 00 19  mov  %i1, %i5
a011cf24:  b2 0e 60 ff  and  %i1, 0xff, %i1
a011cf28:  80 a6 60 08  cmp  %i1, 8
a011cf2c:  38 80 00 02  bgu,a   0xa011cf34
a011cf30:  ba 10 20 08  mov  8, %i5
a011cf34:  37 27 c6 c1  sethi  %hi(0x9f1b0400), %i3
a011cf38:  10 bf ff e5  b  0xa011cecc
a011cf3c:  b4 16 e2 00  or  %i3, 0x200, %i2	! 0x9f1b0600
a011cf40:  82 0e 60 ff  and  %i1, 0xff, %g1
a011cf44:  80 a0 60 10  cmp  %g1, 0x10
a011cf48:  08 80 00 03  bleu  0xa011cf54
a011cf4c:  ba 10 00 19  mov  %i1, %i5
a011cf50:  ba 10 20 10  mov  0x10, %i5
a011cf54:  31 27 c6 c1  sethi  %hi(0x9f1b0400), %i0
a011cf58:  10 bf ff dd  b  0xa011cecc
a011cf5c:  b4 16 22 10  or  %i0, 0x210, %i2	! 0x9f1b0610
a011cf60:  b4 0e 60 ff  and  %i1, 0xff, %i2
a011cf64:  80 a6 a0 08  cmp  %i2, 8
a011cf68:  08 80 00 03  bleu  0xa011cf74
a011cf6c:  ba 10 00 19  mov  %i1, %i5
a011cf70:  ba 10 20 08  mov  8, %i5
a011cf74:  39 27 c6 c1  sethi  %hi(0x9f1b0400), %i4
a011cf78:  10 bf ff d5  b  0xa011cecc
a011cf7c:  b4 17 22 08  or  %i4, 0x208, %i2	! 0x9f1b0608
a011cf80:  81 c7 e0 08  ret
a011cf84:  81 e8 00 00  restore
