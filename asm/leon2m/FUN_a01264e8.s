# leon2m FUN_a01264e8 0xa01264e8-0xa012653c (84 bytes)
a01264e8:  9d e3 bf 90  save  %sp, -112, %sp
a01264ec:  7f ff f8 f7  call  0xa01248c8
a01264f0:  21 2a 00 b6  sethi  %hi(0xa802d800), %l0
a01264f4:  80 8a 20 ff  btst  0xff, %o0
a01264f8:  90 10 20 60  mov  0x60, %o0
a01264fc:  92 10 20 02  mov  2, %o1
a0126500:  94 10 20 5e  mov  0x5e, %o2
a0126504:  96 10 20 05  mov  5, %o3
a0126508:  02 80 00 06  be  0xa0126520
a012650c:  98 10 20 00  clr  %o4
a0126510:  82 10 20 02  mov  2, %g1
a0126514:  c2 23 a0 5c  st  %g1, [ %sp + 0x5c ]
a0126518:  40 00 85 74  call  0xa0147ae8
a012651c:  9a 14 20 88  or  %l0, 0x88, %o5
a0126520:  d2 0c 20 88  ldub  [ %l0 + 0x88 ], %o1
a0126524:  9a 14 20 88  or  %l0, 0x88, %o5
a0126528:  b1 2a 60 08  sll  %o1, 8, %i0
a012652c:  d0 0b 60 01  ldub  [ %o5 + 1 ], %o0
a0126530:  b0 12 00 18  or  %o0, %i0, %i0
a0126534:  81 c7 e0 08  ret
a0126538:  81 e8 00 00  restore
