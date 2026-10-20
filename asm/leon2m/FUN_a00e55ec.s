# leon2m FUN_a00e55ec 0xa00e55ec-0xa00e57b4 (456 bytes)
a00e55ec:  9d e3 bf 98  save  %sp, -104, %sp
a00e55f0:  80 a6 a0 08  cmp  %i2, 8
a00e55f4:  04 80 00 3d  ble  0xa00e56e8
a00e55f8:  80 a6 bf f8  cmp  %i2, -8
a00e55fc:  90 10 00 18  mov  %i0, %o0
a00e5600:  92 10 00 19  mov  %i1, %o1
a00e5604:  7f ff ff fa  call  0xa00e55ec
a00e5608:  94 10 20 08  mov  8, %o2
a00e560c:  80 a2 20 00  cmp  %o0, 0
a00e5610:  12 80 00 67  bne  0xa00e57ac
a00e5614:  b4 06 bf f8  add  %i2, -8, %i2
a00e5618:  80 a6 a0 08  cmp  %i2, 8
a00e561c:  14 bf ff f9  bg  0xa00e5600
a00e5620:  90 10 00 18  mov  %i0, %o0
a00e5624:  80 a6 a0 00  cmp  %i2, 0
a00e5628:  02 80 00 61  be  0xa00e57ac
a00e562c:  90 10 20 00  clr  %o0
a00e5630:  80 a6 7f ff  cmp  %i1, -1
a00e5634:  02 80 00 4a  be  0xa00e575c
a00e5638:  9b 2e 60 02  sll  %i1, 2, %o5
a00e563c:  27 2a 00 99  sethi  %hi(0xa8026400), %l3
a00e5640:  90 14 e2 88  or  %l3, 0x288, %o0	! 0xa8026688
a00e5644:  25 2a 00 99  sethi  %hi(0xa8026400), %l2
a00e5648:  23 2a 00 99  sethi  %hi(0xa8026400), %l1
a00e564c:  98 14 a2 98  or  %l2, 0x298, %o4
a00e5650:  82 14 62 78  or  %l1, 0x278, %g1
a00e5654:  d4 02 00 0d  ld  [ %o0 + %o5 ], %o2
a00e5658:  d6 00 40 0d  ld  [ %g1 + %o5 ], %o3
a00e565c:  d2 03 00 0d  ld  [ %o4 + %o5 ], %o1
a00e5660:  90 10 00 18  mov  %i0, %o0
a00e5664:  7f ff ec 3c  call  0xa00e0754
a00e5668:  01 00 00 00  nop
a00e566c:  9a 02 3f fb  add  %o0, -5, %o5
a00e5670:  80 a3 60 07  cmp  %o5, 7
a00e5674:  08 80 00 26  bleu  0xa00e570c
a00e5678:  a0 10 00 08  mov  %o0, %l0
a00e567c:  80 a6 a0 00  cmp  %i2, 0
a00e5680:  04 80 00 44  ble  0xa00e5790
a00e5684:  9a 02 20 03  add  %o0, 3, %o5
a00e5688:  9e 0b 60 0f  and  %o5, 0xf, %o7
a00e568c:  96 10 20 07  mov  7, %o3
a00e5690:  82 22 c0 0f  sub  %o3, %o7, %g1
a00e5694:  90 10 00 18  mov  %i0, %o0
a00e5698:  92 10 00 19  mov  %i1, %o1
a00e569c:  80 a0 40 1a  cmp  %g1, %i2
a00e56a0:  0a 80 00 29  bcs  0xa00e5744
a00e56a4:  94 10 20 01  mov  1, %o2
a00e56a8:  80 a6 7f ff  cmp  %i1, -1
a00e56ac:  02 80 00 34  be  0xa00e577c
a00e56b0:  b4 04 00 1a  add  %l0, %i2, %i2
a00e56b4:  a1 2e 60 02  sll  %i1, 2, %l0
a00e56b8:  b2 14 a2 98  or  %l2, 0x298, %i1
a00e56bc:  a4 14 e2 88  or  %l3, 0x288, %l2
a00e56c0:  a6 14 62 78  or  %l1, 0x278, %l3
a00e56c4:  d6 04 c0 10  ld  [ %l3 + %l0 ], %o3
a00e56c8:  90 10 00 18  mov  %i0, %o0
a00e56cc:  d2 06 40 10  ld  [ %i1 + %l0 ], %o1
a00e56d0:  d4 04 80 10  ld  [ %l2 + %l0 ], %o2
a00e56d4:  7f ff ec 28  call  0xa00e0774
a00e56d8:  98 10 00 1a  mov  %i2, %o4
a00e56dc:  10 80 00 34  b  0xa00e57ac
a00e56e0:  90 10 20 00  clr  %o0
a00e56e4:  80 a6 bf f8  cmp  %i2, -8
a00e56e8:  16 bf ff cf  bge  0xa00e5624
a00e56ec:  90 10 00 18  mov  %i0, %o0
a00e56f0:  92 10 00 19  mov  %i1, %o1
a00e56f4:  7f ff ff be  call  0xa00e55ec
a00e56f8:  94 10 3f f8  mov  -8, %o2
a00e56fc:  80 a2 20 00  cmp  %o0, 0
a00e5700:  02 bf ff f9  be  0xa00e56e4
a00e5704:  b4 06 a0 08  add  %i2, 8, %i2
a00e5708:  30 80 00 29  b,a   0xa00e57ac
a00e570c:  92 10 20 0c  mov  0xc, %o1
a00e5710:  80 a6 a0 00  cmp  %i2, 0
a00e5714:  14 bf ff e0  bg  0xa00e5694
a00e5718:  82 22 40 08  sub  %o1, %o0, %g1
a00e571c:  80 a6 a0 00  cmp  %i2, 0
a00e5720:  16 bf ff e3  bge  0xa00e56ac
a00e5724:  80 a6 7f ff  cmp  %i1, -1
a00e5728:  94 20 00 1a  neg  %i2, %o2
a00e572c:  80 a3 40 0a  cmp  %o5, %o2
a00e5730:  1a bf ff df  bcc  0xa00e56ac
a00e5734:  80 a6 7f ff  cmp  %i1, -1
a00e5738:  90 10 00 18  mov  %i0, %o0
a00e573c:  92 10 00 19  mov  %i1, %o1
a00e5740:  94 10 3f ff  mov  -1, %o2
a00e5744:  7f ff ff 39  call  0xa00e5428
a00e5748:  01 00 00 00  nop
a00e574c:  80 a2 20 00  cmp  %o0, 0
a00e5750:  12 80 00 17  bne  0xa00e57ac
a00e5754:  80 a6 7f ff  cmp  %i1, -1
a00e5758:  30 bf ff d5  b,a   0xa00e56ac
a00e575c:  25 2a 00 99  sethi  %hi(0xa8026400), %l2
a00e5760:  27 2a 00 99  sethi  %hi(0xa8026400), %l3
a00e5764:  23 2a 00 99  sethi  %hi(0xa8026400), %l1
a00e5768:  90 10 00 18  mov  %i0, %o0
a00e576c:  92 14 a2 98  or  %l2, 0x298, %o1
a00e5770:  94 14 e2 88  or  %l3, 0x288, %o2
a00e5774:  10 bf ff bc  b  0xa00e5664
a00e5778:  96 14 62 78  or  %l1, 0x278, %o3
a00e577c:  90 10 00 18  mov  %i0, %o0
a00e5780:  92 14 a2 98  or  %l2, 0x298, %o1
a00e5784:  94 14 e2 88  or  %l3, 0x288, %o2
a00e5788:  10 bf ff d3  b  0xa00e56d4
a00e578c:  96 14 62 78  or  %l1, 0x278, %o3
a00e5790:  36 bf ff c7  bge,a   0xa00e56ac
a00e5794:  80 a6 7f ff  cmp  %i1, -1
a00e5798:  82 02 20 03  add  %o0, 3, %g1
a00e579c:  98 08 60 0f  and  %g1, 0xf, %o4
a00e57a0:  90 20 00 1a  neg  %i2, %o0
a00e57a4:  10 bf ff e3  b  0xa00e5730
a00e57a8:  80 a3 00 08  cmp  %o4, %o0
a00e57ac:  81 c7 e0 08  ret
a00e57b0:  91 e8 00 08  restore  %g0, %o0, %o0
