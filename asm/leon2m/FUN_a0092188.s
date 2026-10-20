# leon2m FUN_a0092188 0xa0092188-0xa009221c (148 bytes)
a0092188:  9d e3 bf 98  save  %sp, -104, %sp
a009218c:  33 2a 00 ab  sethi  %hi(0xa802ac00), %i1
a0092190:  d2 06 63 ec  ld  [ %i1 + 0x3ec ], %o1	! 0xa802afec
a0092194:  90 02 7f e8  add  %o1, -24, %o0
a0092198:  40 00 5b 54  call  0xa00a8ee8
a009219c:  90 0a 20 ff  and  %o0, 0xff, %o0
a00921a0:  03 0a aa aa  sethi  %hi(0x2aaaa800), %g1
a00921a4:  b0 10 62 ab  or  %g1, 0x2ab, %i0	! 0x2aaaaaab
a00921a8:  d0 16 63 ee  lduh  [ %i1 + 0x3ee ], %o0
a00921ac:  9e 02 3f e9  add  %o0, -23, %o7
a00921b0:  80 5b c0 18  smul  %o7, %i0, %g0
a00921b4:  97 40 00 00  rd  %y, %o3
a00921b8:  9b 3b e0 1f  sra  %o7, 0x1f, %o5
a00921bc:  94 22 c0 0d  sub  %o3, %o5, %o2
a00921c0:  92 02 80 0a  add  %o2, %o2, %o1
a00921c4:  82 02 40 0a  add  %o1, %o2, %g1
a00921c8:  98 00 40 01  add  %g1, %g1, %o4
a00921cc:  96 23 c0 0c  sub  %o7, %o4, %o3
a00921d0:  9a 02 e0 18  add  %o3, 0x18, %o5
a00921d4:  da 26 63 ec  st  %o5, [ %i1 + 0x3ec ]
a00921d8:  40 00 60 d2  call  0xa00aa520
a00921dc:  90 0a e0 ff  and  %o3, 0xff, %o0
a00921e0:  94 0a 20 ff  and  %o0, 0xff, %o2
a00921e4:  80 a2 a0 01  cmp  %o2, 1
a00921e8:  12 bf ff f1  bne  0xa00921ac
a00921ec:  d0 16 63 ee  lduh  [ %i1 + 0x3ee ], %o0
a00921f0:  d8 06 63 ec  ld  [ %i1 + 0x3ec ], %o4
a00921f4:  9e 03 3f e8  add  %o4, -24, %o7
a00921f8:  90 0b e0 ff  and  %o7, 0xff, %o0
a00921fc:  40 00 5b 84  call  0xa00a900c
a0092200:  92 10 20 01  mov  1, %o1
a0092204:  f0 06 63 ec  ld  [ %i1 + 0x3ec ], %i0
a0092208:  b2 06 3f e8  add  %i0, -24, %i1
a009220c:  b2 0e 60 ff  and  %i1, 0xff, %i1
a0092210:  40 00 74 8f  call  0xa00af44c
a0092214:  91 e8 20 18  restore  %g0, 0x18, %o0
a0092218:  01 00 00 00  nop
