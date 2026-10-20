# leon2s FUN_a008facc 0xa008facc-0xa008fb5c (144 bytes)
a008facc:  9d e3 bf 98  save  %sp, -104, %sp
a008fad0:  a2 0e 20 ff  and  %i0, 0xff, %l1
a008fad4:  92 10 21 34  mov  0x134, %o1
a008fad8:  40 00 5a a9  call  0xa00a657c
a008fadc:  90 10 00 11  mov  %l1, %o0
a008fae0:  80 8a 20 02  btst  2, %o0
a008fae4:  92 10 21 48  mov  0x148, %o1
a008fae8:  b0 10 00 11  mov  %l1, %i0
a008faec:  b2 10 20 08  mov  8, %i1
a008faf0:  b4 10 20 f0  mov  0xf0, %i2
a008faf4:  b6 10 20 00  clr  %i3
a008faf8:  02 80 00 16  be  0xa008fb50
a008fafc:  90 10 00 11  mov  %l1, %o0
a008fb00:  40 00 5a 9f  call  0xa00a657c
a008fb04:  01 00 00 00  nop
a008fb08:  a0 0a 20 0f  and  %o0, 0xf, %l0
a008fb0c:  92 10 20 08  mov  8, %o1
a008fb10:  40 00 5a 9b  call  0xa00a657c
a008fb14:  90 10 00 11  mov  %l1, %o0
a008fb18:  90 0a 20 0f  and  %o0, 0xf, %o0
a008fb1c:  a0 0c 20 ff  and  %l0, 0xff, %l0
a008fb20:  80 a4 20 01  cmp  %l0, 1
a008fb24:  12 80 00 04  bne  0xa008fb34
a008fb28:  b4 10 00 08  mov  %o0, %i2
a008fb2c:  10 80 00 05  b  0xa008fb40
a008fb30:  b4 12 20 50  or  %o0, 0x50, %i2
a008fb34:  80 a4 20 03  cmp  %l0, 3
a008fb38:  22 80 00 02  be,a   0xa008fb40
a008fb3c:  b4 12 3f f0  or  %o0, -16, %i2
a008fb40:  b0 10 00 11  mov  %l1, %i0
a008fb44:  b4 0e a0 ff  and  %i2, 0xff, %i2
a008fb48:  40 00 5a 9f  call  0xa00a65c4
a008fb4c:  93 e8 20 08  restore  %g0, 8, %o1
a008fb50:  40 00 5b 1a  call  0xa00a67b8
a008fb54:  81 e8 00 00  restore
a008fb58:  01 00 00 00  nop
