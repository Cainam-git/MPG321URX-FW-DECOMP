# leon2m FUN_a00920f4 0xa00920f4-0xa0092188 (148 bytes)
a00920f4:  9d e3 bf 98  save  %sp, -104, %sp
a00920f8:  33 2a 00 ab  sethi  %hi(0xa802ac00), %i1
a00920fc:  d2 06 63 ec  ld  [ %i1 + 0x3ec ], %o1	! 0xa802afec
a0092100:  90 02 7f e8  add  %o1, -24, %o0
a0092104:  40 00 5b 79  call  0xa00a8ee8
a0092108:  90 0a 20 ff  and  %o0, 0xff, %o0
a009210c:  03 0a aa aa  sethi  %hi(0x2aaaa800), %g1
a0092110:  b0 10 62 ab  or  %g1, 0x2ab, %i0	! 0x2aaaaaab
a0092114:  d0 16 63 ee  lduh  [ %i1 + 0x3ee ], %o0
a0092118:  9e 02 3f ed  add  %o0, -19, %o7
a009211c:  80 5b c0 18  smul  %o7, %i0, %g0
a0092120:  97 40 00 00  rd  %y, %o3
a0092124:  9b 3b e0 1f  sra  %o7, 0x1f, %o5
a0092128:  94 22 c0 0d  sub  %o3, %o5, %o2
a009212c:  92 02 80 0a  add  %o2, %o2, %o1
a0092130:  82 02 40 0a  add  %o1, %o2, %g1
a0092134:  98 00 40 01  add  %g1, %g1, %o4
a0092138:  96 23 c0 0c  sub  %o7, %o4, %o3
a009213c:  9a 02 e0 18  add  %o3, 0x18, %o5
a0092140:  da 26 63 ec  st  %o5, [ %i1 + 0x3ec ]
a0092144:  40 00 60 f7  call  0xa00aa520
a0092148:  90 0a e0 ff  and  %o3, 0xff, %o0
a009214c:  94 0a 20 ff  and  %o0, 0xff, %o2
a0092150:  80 a2 a0 01  cmp  %o2, 1
a0092154:  12 bf ff f1  bne  0xa0092118
a0092158:  d0 16 63 ee  lduh  [ %i1 + 0x3ee ], %o0
a009215c:  d8 06 63 ec  ld  [ %i1 + 0x3ec ], %o4
a0092160:  9e 03 3f e8  add  %o4, -24, %o7
a0092164:  90 0b e0 ff  and  %o7, 0xff, %o0
a0092168:  40 00 5b a9  call  0xa00a900c
a009216c:  92 10 20 01  mov  1, %o1
a0092170:  f0 06 63 ec  ld  [ %i1 + 0x3ec ], %i0
a0092174:  b2 06 3f e8  add  %i0, -24, %i1
a0092178:  b2 0e 60 ff  and  %i1, 0xff, %i1
a009217c:  40 00 74 b4  call  0xa00af44c
a0092180:  91 e8 20 18  restore  %g0, 0x18, %o0
a0092184:  01 00 00 00  nop
