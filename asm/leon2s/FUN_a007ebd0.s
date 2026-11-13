# leon2s FUN_a007ebd0 0xa007ebd0-0xa007ec30 (96 bytes)
a007ebd0:  9d e3 bf 98  save  %sp, -104, %sp
a007ebd4:  a0 0e 20 ff  and  %i0, 0xff, %l0
a007ebd8:  90 10 00 10  mov  %l0, %o0
a007ebdc:  7f ff d2 51  call  0xa0073520
a007ebe0:  b0 10 00 10  mov  %l0, %i0
a007ebe4:  a0 1c 20 02  xor  %l0, 2, %l0
a007ebe8:  b2 10 21 36  mov  0x136, %i1
a007ebec:  b4 10 20 01  mov  1, %i2
a007ebf0:  80 8a 20 ff  btst  0xff, %o0
a007ebf4:  02 80 00 0c  be  0xa007ec24
a007ebf8:  b6 10 20 00  clr  %i3
a007ebfc:  80 a0 00 10  cmp  %g0, %l0
a007ec00:  82 40 20 00  addx  %g0, 0, %g1
a007ec04:  1b 2a 01 f6  sethi  %hi(0xa807d800), %o5
a007ec08:  82 58 60 34  smul  %g1, 0x34, %g1
a007ec0c:  9a 13 63 00  or  %o5, 0x300, %o5
a007ec10:  82 00 40 0d  add  %g1, %o5, %g1
a007ec14:  f2 00 60 04  ld  [ %g1 + 4 ], %i1
a007ec18:  b2 06 60 34  add  %i1, 0x34, %i1
a007ec1c:  40 00 a1 e4  call  0xa00a73ac
a007ec20:  91 e8 20 10  restore  %g0, 0x10, %o0
a007ec24:  40 00 9e e5  call  0xa00a67b8
a007ec28:  81 e8 00 00  restore
a007ec2c:  01 00 00 00  nop
