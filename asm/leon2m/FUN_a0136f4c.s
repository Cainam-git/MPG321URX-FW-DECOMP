# leon2m FUN_a0136f4c 0xa0136f4c-0xa0136fc4 (120 bytes)
a0136f4c:  9d e3 bf 90  save  %sp, -112, %sp
a0136f50:  03 2a 00 a9  sethi  %hi(0xa802a400), %g1
a0136f54:  b1 2e 20 10  sll  %i0, 0x10, %i0
a0136f58:  da 08 60 57  ldub  [ %g1 + 0x57 ], %o5
a0136f5c:  b1 36 20 10  srl  %i0, 0x10, %i0
a0136f60:  9b 2b 60 10  sll  %o5, 0x10, %o5
a0136f64:  90 10 20 01  mov  1, %o0
a0136f68:  92 10 20 08  mov  8, %o1
a0136f6c:  94 07 bf f4  add  %fp, -12, %o2
a0136f70:  96 10 20 01  mov  1, %o3
a0136f74:  80 8e 20 01  btst  1, %i0
a0136f78:  02 80 00 03  be  0xa0136f84
a0136f7c:  82 10 20 00  clr  %g1
a0136f80:  82 10 20 04  mov  4, %g1
a0136f84:  80 8e 20 02  btst  2, %i0
a0136f88:  32 80 00 02  bne,a   0xa0136f90
a0136f8c:  82 10 60 08  or  %g1, 8, %g1
a0136f90:  80 8e 20 04  btst  4, %i0
a0136f94:  32 80 00 02  bne,a   0xa0136f9c
a0136f98:  82 10 60 10  or  %g1, 0x10, %g1
a0136f9c:  80 8e 20 08  btst  8, %i0
a0136fa0:  32 80 00 02  bne,a   0xa0136fa8
a0136fa4:  82 10 60 20  or  %g1, 0x20, %g1
a0136fa8:  9f 28 60 18  sll  %g1, 0x18, %o7
a0136fac:  98 13 40 0f  or  %o5, %o7, %o4
a0136fb0:  67 fd 55 92  call  0x4008c5f8
a0136fb4:  d8 27 bf f4  st  %o4, [ %fp + -12 ]
a0136fb8:  01 00 00 00  nop
a0136fbc:  81 c7 e0 08  ret
a0136fc0:  81 e8 00 00  restore
