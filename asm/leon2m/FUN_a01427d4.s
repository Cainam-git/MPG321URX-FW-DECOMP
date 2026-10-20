# leon2m FUN_a01427d4 0xa01427d4-0xa014285c (136 bytes)
a01427d4:  1b 3f ff fb  sethi  %hi(0xffffec00), %o5
a01427d8:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a01427dc:  90 13 63 ff  or  %o5, 0x3ff, %o0
a01427e0:  94 10 62 24  or  %g1, 0x224, %o2
a01427e4:  96 10 20 00  clr  %o3
a01427e8:  9a 10 20 00  clr  %o5
a01427ec:  92 10 20 01  mov  1, %o1
a01427f0:  82 5b 60 2a  smul  %o5, 0x2a, %g1
a01427f4:  9a 00 40 0a  add  %g1, %o2, %o5
a01427f8:  d6 2b 60 0b  stb  %o3, [ %o5 + 0xb ]
a01427fc:  d2 2b 60 02  stb  %o1, [ %o5 + 2 ]
a0142800:  d2 2b 60 09  stb  %o1, [ %o5 + 9 ]
a0142804:  d8 12 80 01  lduh  [ %o2 + %g1 ], %o4
a0142808:  9a 0a 00 0c  and  %o0, %o4, %o5
a014280c:  98 0b 7f ef  and  %o5, -17, %o4
a0142810:  96 02 e0 01  inc  %o3
a0142814:  9a 0a e0 ff  and  %o3, 0xff, %o5
a0142818:  80 a3 60 07  cmp  %o5, 7
a014281c:  08 bf ff f5  bleu  0xa01427f0
a0142820:  d8 32 80 01  sth  %o4, [ %o2 + %g1 ]
a0142824:  11 2a 00 b8  sethi  %hi(0xa802e000), %o0
a0142828:  94 12 22 24  or  %o0, 0x224, %o2	! 0xa802e224
a014282c:  98 10 20 00  clr  %o4
a0142830:  9a 10 20 00  clr  %o5
a0142834:  96 10 20 02  mov  2, %o3
a0142838:  82 5b 60 2a  smul  %o5, 0x2a, %g1
a014283c:  98 03 20 01  inc  %o4
a0142840:  92 00 40 0a  add  %g1, %o2, %o1
a0142844:  9a 0b 20 ff  and  %o4, 0xff, %o5
a0142848:  80 a3 60 03  cmp  %o5, 3
a014284c:  08 bf ff fb  bleu  0xa0142838
a0142850:  d6 2a 60 02  stb  %o3, [ %o1 + 2 ]
a0142854:  81 c3 e0 08  retl
a0142858:  01 00 00 00  nop
