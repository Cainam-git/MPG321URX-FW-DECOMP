# leon2m FUN_a01198c8 0xa01198c8-0xa0119910 (72 bytes)
a01198c8:  82 0a 20 03  and  %o0, 3, %g1
a01198cc:  17 2a 00 b2  sethi  %hi(0xa802c800), %o3
a01198d0:  98 10 00 0b  mov  %o3, %o4
a01198d4:  80 8a 60 ff  btst  0xff, %o1
a01198d8:  9b 28 60 02  sll  %g1, 2, %o5
a01198dc:  12 80 00 07  bne  0xa01198f8
a01198e0:  91 28 60 04  sll  %g1, 4, %o0
a01198e4:  d0 0a e1 b0  ldub  [ %o3 + 0x1b0 ], %o0
a01198e8:  98 0a 3f f3  and  %o0, -13, %o4
a01198ec:  92 13 00 0d  or  %o4, %o5, %o1
a01198f0:  10 80 00 06  b  0xa0119908
a01198f4:  d2 2a e1 b0  stb  %o1, [ %o3 + 0x1b0 ]
a01198f8:  c2 0a e1 b0  ldub  [ %o3 + 0x1b0 ], %g1
a01198fc:  9a 08 7f cf  and  %g1, -49, %o5
a0119900:  96 13 40 08  or  %o5, %o0, %o3
a0119904:  d6 2b 21 b0  stb  %o3, [ %o4 + 0x1b0 ]
a0119908:  81 c3 e0 08  retl
a011990c:  01 00 00 00  nop
