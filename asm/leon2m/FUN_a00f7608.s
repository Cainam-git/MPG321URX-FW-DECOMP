# leon2m FUN_a00f7608 0xa00f7608-0xa00f76dc (212 bytes)
a00f7608:  9d e3 bf 98  save  %sp, -104, %sp
a00f760c:  13 33 c0 3b  sethi  %hi(0xcf00ec00), %o1
a00f7610:  96 12 62 80  or  %o1, 0x280, %o3	! 0xcf00ee80
a00f7614:  1f 2a 00 ad  sethi  %hi(0xa802b400), %o7
a00f7618:  d8 02 c0 00  ld  [ %o3 ], %o4
a00f761c:  d4 0b e3 b4  ldub  [ %o7 + 0x3b4 ], %o2
a00f7620:  82 0b 20 f9  and  %o4, 0xf9, %g1
a00f7624:  90 02 80 0a  add  %o2, %o2, %o0
a00f7628:  9a 10 40 08  or  %g1, %o0, %o5
a00f762c:  da 22 c0 00  st  %o5, [ %o3 ]
a00f7630:  94 12 62 c0  or  %o1, 0x2c0, %o2
a00f7634:  e0 02 80 00  ld  [ %o2 ], %l0
a00f7638:  9e 0c 20 f3  and  %l0, 0xf3, %o7
a00f763c:  98 13 e0 68  or  %o7, 0x68, %o4
a00f7640:  96 12 62 c4  or  %o1, 0x2c4, %o3
a00f7644:  d8 22 80 00  st  %o4, [ %o2 ]
a00f7648:  d0 02 c0 00  ld  [ %o3 ], %o0
a00f764c:  82 12 20 40  or  %o0, 0x40, %g1
a00f7650:  c2 22 c0 00  st  %g1, [ %o3 ]
a00f7654:  1b 00 06 68  sethi  %hi(0x19a000), %o5
a00f7658:  80 a6 20 00  cmp  %i0, 0
a00f765c:  02 80 00 03  be  0xa00f7668
a00f7660:  96 13 63 34  or  %o5, 0x334, %o3
a00f7664:  96 10 00 18  mov  %i0, %o3
a00f7668:  f0 0a c0 00  ldub  [ %o3 ], %i0
a00f766c:  80 a6 20 00  cmp  %i0, 0
a00f7670:  08 80 00 0f  bleu  0xa00f76ac
a00f7674:  98 10 20 00  clr  %o4
a00f7678:  13 33 c0 3b  sethi  %hi(0xcf00ec00), %o1
a00f767c:  94 12 62 c8  or  %o1, 0x2c8, %o2	! 0xcf00eec8
a00f7680:  9a 10 20 00  clr  %o5
a00f7684:  90 03 40 0d  add  %o5, %o5, %o0
a00f7688:  82 02 00 0b  add  %o0, %o3, %g1
a00f768c:  da 10 60 02  lduh  [ %g1 + 2 ], %o5
a00f7690:  da 22 80 00  st  %o5, [ %o2 ]
a00f7694:  98 03 20 01  inc  %o4
a00f7698:  e0 0a c0 00  ldub  [ %o3 ], %l0
a00f769c:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00f76a0:  80 a4 00 0d  cmp  %l0, %o5
a00f76a4:  18 bf ff f9  bgu  0xa00f7688
a00f76a8:  90 03 40 0d  add  %o5, %o5, %o0
a00f76ac:  13 33 c0 3b  sethi  %hi(0xcf00ec00), %o1
a00f76b0:  b0 12 62 c4  or  %o1, 0x2c4, %i0	! 0xcf00eec4
a00f76b4:  de 06 00 00  ld  [ %i0 ], %o7
a00f76b8:  98 13 e0 80  or  %o7, 0x80, %o4
a00f76bc:  d8 26 00 00  st  %o4, [ %i0 ]
a00f76c0:  67 fe 5a f9  call  0x4008e2a4
a00f76c4:  01 00 00 00  nop
a00f76c8:  d4 06 00 00  ld  [ %i0 ], %o2
a00f76cc:  96 0a bf 7f  and  %o2, -129, %o3
a00f76d0:  d6 26 00 00  st  %o3, [ %i0 ]
a00f76d4:  81 c7 e0 08  ret
a00f76d8:  81 e8 00 00  restore
