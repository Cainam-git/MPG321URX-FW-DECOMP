# leon2m FUN_a00f37d0 0xa00f37d0-0xa00f381c (76 bytes)
a00f37d0:  9d e3 bf 98  save  %sp, -104, %sp
a00f37d4:  19 2a 00 ad  sethi  %hi(0xa802b400), %o4
a00f37d8:  13 33 c0 4a  sethi  %hi(0xcf012800), %o1
a00f37dc:  da 0b 23 70  ldub  [ %o4 + 0x370 ], %o5
a00f37e0:  90 0e 20 ff  and  %i0, 0xff, %o0
a00f37e4:  82 12 60 1c  or  %o1, 0x1c, %g1
a00f37e8:  d0 20 40 00  st  %o0, [ %g1 ]
a00f37ec:  80 a3 60 00  cmp  %o5, 0
a00f37f0:  02 80 00 08  be  0xa00f3810
a00f37f4:  98 13 23 70  or  %o4, 0x370, %o4
a00f37f8:  d8 03 20 0c  ld  [ %o4 + 0xc ], %o4
a00f37fc:  80 a3 20 00  cmp  %o4, 0
a00f3800:  02 80 00 04  be  0xa00f3810
a00f3804:  01 00 00 00  nop
a00f3808:  9f c3 00 00  call  %o4
a00f380c:  01 00 00 00  nop
a00f3810:  01 00 00 00  nop
a00f3814:  81 c7 e0 08  ret
a00f3818:  81 e8 00 00  restore
