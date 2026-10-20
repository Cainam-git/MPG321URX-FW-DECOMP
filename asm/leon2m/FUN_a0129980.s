# leon2m FUN_a0129980 0xa0129980-0xa0129a10 (144 bytes)
a0129980:  9d e3 bf 98  save  %sp, -104, %sp
a0129984:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a0129988:  aa 10 61 16  or  %g1, 0x116, %l5	! 0xa802e116
a012998c:  a4 10 20 00  clr  %l2
a0129990:  a2 10 20 00  clr  %l1
a0129994:  27 2a 00 b2  sethi  %hi(0xa802c800), %l3
a0129998:  10 80 00 06  b  0xa01299b0
a012999c:  a8 10 20 01  mov  1, %l4
a01299a0:  9f 2d 00 11  sll  %l4, %l1, %o7
a01299a4:  da 14 e2 00  lduh  [ %l3 + 0x200 ], %o5
a01299a8:  10 80 00 13  b  0xa01299f4
a01299ac:  82 2b 40 0f  andn  %o5, %o7, %g1
a01299b0:  95 2c 60 03  sll  %l1, 3, %o2
a01299b4:  92 02 80 11  add  %o2, %l1, %o1
a01299b8:  90 02 40 09  add  %o1, %o1, %o0
a01299bc:  a0 02 00 15  add  %o0, %l5, %l0
a01299c0:  7f ff ec d9  call  0xa0124d24
a01299c4:  d0 0c 20 10  ldub  [ %l0 + 0x10 ], %o0
a01299c8:  80 8a 20 ff  btst  0xff, %o0
a01299cc:  02 bf ff f6  be  0xa01299a4
a01299d0:  9f 2d 00 11  sll  %l4, %l1, %o7
a01299d4:  7f ff ed db  call  0xa0125140
a01299d8:  d0 0c 20 10  ldub  [ %l0 + 0x10 ], %o0
a01299dc:  96 0a 20 ff  and  %o0, 0xff, %o3
a01299e0:  80 a2 e0 ff  cmp  %o3, 0xff
a01299e4:  02 bf ff ef  be  0xa01299a0
a01299e8:  9b 2d 00 11  sll  %l4, %l1, %o5
a01299ec:  d8 14 e2 00  lduh  [ %l3 + 0x200 ], %o4
a01299f0:  82 13 40 0c  or  %o5, %o4, %g1
a01299f4:  a4 04 a0 01  inc  %l2
a01299f8:  a2 0c a0 ff  and  %l2, 0xff, %l1
a01299fc:  80 a4 60 06  cmp  %l1, 6
a0129a00:  08 bf ff ec  bleu  0xa01299b0
a0129a04:  c2 34 e2 00  sth  %g1, [ %l3 + 0x200 ]
a0129a08:  81 c7 e0 08  ret
a0129a0c:  81 e8 00 00  restore
