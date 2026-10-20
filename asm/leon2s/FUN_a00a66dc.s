# leon2s FUN_a00a66dc 0xa00a66dc-0xa00a67b8 (220 bytes)
a00a66dc:  9d e3 bf 98  save  %sp, -104, %sp
a00a66e0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a66e4:  80 a6 20 02  cmp  %i0, 2
a00a66e8:  18 80 00 32  bgu  0xa00a67b0
a00a66ec:  9e 10 00 1a  mov  %i2, %o7
a00a66f0:  80 a6 20 02  cmp  %i0, 2
a00a66f4:  12 80 00 1c  bne  0xa00a6764
a00a66f8:  80 a6 20 01  cmp  %i0, 1
a00a66fc:  b9 2e a0 10  sll  %i2, 0x10, %i4
a00a6700:  b6 0e a0 ff  and  %i2, 0xff, %i3
a00a6704:  83 2e 60 10  sll  %i1, 0x10, %g1
a00a6708:  3b 28 02 d3  sethi  %hi(0xa00b4c00), %i5
a00a670c:  b5 37 20 18  srl  %i4, 0x18, %i2
a00a6710:  9e 17 61 9c  or  %i5, 0x19c, %o7
a00a6714:  b3 30 60 10  srl  %g1, 0x10, %i1
a00a6718:  b0 10 20 00  clr  %i0
a00a671c:  39 33 c0 00  sethi  %hi(0xcf000000), %i4
a00a6720:  82 0e 20 ff  and  %i0, 0xff, %g1
a00a6724:  82 00 40 01  add  %g1, %g1, %g1
a00a6728:  c2 13 c0 01  lduh  [ %o7 + %g1 ], %g1
a00a672c:  82 00 40 19  add  %g1, %i1, %g1
a00a6730:  ba 00 60 01  add  %g1, 1, %i5
a00a6734:  83 28 60 02  sll  %g1, 2, %g1
a00a6738:  82 10 40 1c  or  %g1, %i4, %g1
a00a673c:  f6 20 40 00  st  %i3, [ %g1 ]
a00a6740:  bb 2f 60 02  sll  %i5, 2, %i5
a00a6744:  b0 06 20 01  inc  %i0
a00a6748:  ba 17 40 1c  or  %i5, %i4, %i5
a00a674c:  82 0e 20 ff  and  %i0, 0xff, %g1
a00a6750:  f4 27 40 00  st  %i2, [ %i5 ]
a00a6754:  80 a0 60 01  cmp  %g1, 1
a00a6758:  08 bf ff f3  bleu  0xa00a6724
a00a675c:  82 0e 20 ff  and  %i0, 0xff, %g1
a00a6760:  30 80 00 14  b,a   0xa00a67b0
a00a6764:  18 80 00 13  bgu  0xa00a67b0
a00a6768:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00a676c:  b8 06 00 18  add  %i0, %i0, %i4
a00a6770:  bb 2e 60 10  sll  %i1, 0x10, %i5
a00a6774:  82 10 61 9c  or  %g1, 0x19c, %g1
a00a6778:  c2 10 40 1c  lduh  [ %g1 + %i4 ], %g1
a00a677c:  bb 37 60 10  srl  %i5, 0x10, %i5
a00a6780:  82 00 40 1d  add  %g1, %i5, %g1
a00a6784:  b8 00 60 01  add  %g1, 1, %i4
a00a6788:  35 33 c0 00  sethi  %hi(0xcf000000), %i2
a00a678c:  83 28 60 02  sll  %g1, 2, %g1
a00a6790:  82 10 40 1a  or  %g1, %i2, %g1
a00a6794:  b6 0b e0 ff  and  %o7, 0xff, %i3
a00a6798:  b9 2f 20 02  sll  %i4, 2, %i4
a00a679c:  bb 2b e0 10  sll  %o7, 0x10, %i5
a00a67a0:  f6 20 40 00  st  %i3, [ %g1 ]
a00a67a4:  b8 17 00 1a  or  %i4, %i2, %i4
a00a67a8:  bb 37 60 18  srl  %i5, 0x18, %i5
a00a67ac:  fa 27 00 00  st  %i5, [ %i4 ]
a00a67b0:  81 c7 e0 08  ret
a00a67b4:  81 e8 00 00  restore
