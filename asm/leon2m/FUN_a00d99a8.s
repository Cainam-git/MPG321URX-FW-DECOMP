# leon2m FUN_a00d99a8 0xa00d99a8-0xa00d99f8 (80 bytes)
a00d99a8:  9d e3 bf 98  save  %sp, -104, %sp
a00d99ac:  40 01 37 e0  call  0xa012792c
a00d99b0:  01 00 00 00  nop
a00d99b4:  80 8a 20 ff  btst  0xff, %o0
a00d99b8:  02 80 00 04  be  0xa00d99c8
a00d99bc:  01 00 00 00  nop
a00d99c0:  40 01 30 9d  call  0xa0125c34
a00d99c4:  81 e8 00 00  restore
a00d99c8:  40 01 37 df  call  0xa0127944
a00d99cc:  01 00 00 00  nop
a00d99d0:  80 8a 20 ff  btst  0xff, %o0
a00d99d4:  12 bf ff fb  bne  0xa00d99c0
a00d99d8:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00d99dc:  da 00 63 38  ld  [ %g1 + 0x338 ], %o5	! 0xa802d338
a00d99e0:  80 8b 60 20  btst  0x20, %o5
a00d99e4:  12 bf ff f7  bne  0xa00d99c0
a00d99e8:  01 00 00 00  nop
a00d99ec:  40 01 30 94  call  0xa0125c3c
a00d99f0:  81 e8 00 00  restore
a00d99f4:  01 00 00 00  nop
