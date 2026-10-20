# leon2s FUN_a00d6724 0xa00d6724-0xa00d6890 (364 bytes)
a00d6724:  96 10 20 00  clr  %o3	! 0x0
a00d6728:  82 0a e0 ff  and  %o3, 0xff, %g1
a00d672c:  96 02 e0 01  inc  %o3
a00d6730:  82 02 00 01  add  %o0, %g1, %g1
a00d6734:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00d6738:  80 a3 60 0f  cmp  %o5, 0xf
a00d673c:  08 bf ff fb  bleu  0xa00d6728
a00d6740:  c0 28 60 01  clrb  [ %g1 + 1 ]
a00d6744:  c2 0a 40 00  ldub  [ %o1 ], %g1
a00d6748:  da 0a 00 00  ldub  [ %o0 ], %o5
a00d674c:  82 08 60 f0  and  %g1, 0xf0, %g1
a00d6750:  9a 0b 60 0f  and  %o5, 0xf, %o5
a00d6754:  9a 13 40 01  or  %o5, %g1, %o5
a00d6758:  da 2a 00 00  stb  %o5, [ %o0 ]
a00d675c:  c2 0a 40 00  ldub  [ %o1 ], %g1
a00d6760:  82 08 60 0f  and  %g1, 0xf, %g1
a00d6764:  9a 0b 7f f0  and  %o5, -16, %o5
a00d6768:  9a 13 40 01  or  %o5, %g1, %o5
a00d676c:  83 33 60 04  srl  %o5, 4, %g1
a00d6770:  96 00 7f ff  add  %g1, -1, %o3
a00d6774:  83 32 e0 1f  srl  %o3, 0x1f, %g1
a00d6778:  82 02 c0 01  add  %o3, %g1, %g1
a00d677c:  83 38 60 01  sra  %g1, 1, %g1
a00d6780:  da 2a 00 00  stb  %o5, [ %o0 ]
a00d6784:  80 8a e0 01  btst  1, %o3
a00d6788:  02 80 00 03  be  0xa00d6794
a00d678c:  98 10 00 01  mov  %g1, %o4
a00d6790:  98 00 60 01  add  %g1, 1, %o4
a00d6794:  80 a2 e0 00  cmp  %o3, 0
a00d6798:  04 80 00 16  ble  0xa00d67f0
a00d679c:  96 10 20 00  clr  %o3
a00d67a0:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00d67a4:  83 33 60 01  srl  %o5, 1, %g1
a00d67a8:  80 8b 60 01  btst  1, %o5
a00d67ac:  94 02 40 01  add  %o1, %g1, %o2
a00d67b0:  96 02 e0 01  inc  %o3
a00d67b4:  12 80 00 05  bne  0xa00d67c8
a00d67b8:  9a 02 00 0d  add  %o0, %o5, %o5
a00d67bc:  c2 0a a0 01  ldub  [ %o2 + 1 ], %g1
a00d67c0:  10 80 00 04  b  0xa00d67d0
a00d67c4:  83 30 60 04  srl  %g1, 4, %g1
a00d67c8:  c2 0a a0 01  ldub  [ %o2 + 1 ], %g1
a00d67cc:  82 08 60 0f  and  %g1, 0xf, %g1
a00d67d0:  c2 2b 60 01  stb  %g1, [ %o5 + 1 ]
a00d67d4:  c2 0a 00 00  ldub  [ %o0 ], %g1
a00d67d8:  83 30 60 04  srl  %g1, 4, %g1
a00d67dc:  82 00 7f ff  add  %g1, -1, %g1
a00d67e0:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00d67e4:  80 a3 40 01  cmp  %o5, %g1
a00d67e8:  06 bf ff f0  bl  0xa00d67a8
a00d67ec:  83 33 60 01  srl  %o5, 1, %g1
a00d67f0:  98 0b 20 ff  and  %o4, 0xff, %o4
a00d67f4:  98 02 40 0c  add  %o1, %o4, %o4
a00d67f8:  da 0b 20 01  ldub  [ %o4 + 1 ], %o5
a00d67fc:  c2 0a 20 11  ldub  [ %o0 + 0x11 ], %g1
a00d6800:  9a 0b 60 80  and  %o5, 0x80, %o5
a00d6804:  82 08 60 7f  and  %g1, 0x7f, %g1
a00d6808:  82 10 40 0d  or  %g1, %o5, %g1
a00d680c:  c2 2a 20 11  stb  %g1, [ %o0 + 0x11 ]
a00d6810:  da 0b 20 01  ldub  [ %o4 + 1 ], %o5
a00d6814:  9a 0b 60 40  and  %o5, 0x40, %o5
a00d6818:  82 08 7f bf  and  %g1, -65, %g1
a00d681c:  82 10 40 0d  or  %g1, %o5, %g1
a00d6820:  c2 2a 20 11  stb  %g1, [ %o0 + 0x11 ]
a00d6824:  da 0b 20 01  ldub  [ %o4 + 1 ], %o5
a00d6828:  9a 0b 60 3f  and  %o5, 0x3f, %o5
a00d682c:  82 08 7f c0  and  %g1, -64, %g1
a00d6830:  82 10 40 0d  or  %g1, %o5, %g1
a00d6834:  c2 2a 20 11  stb  %g1, [ %o0 + 0x11 ]
a00d6838:  da 0b 20 02  ldub  [ %o4 + 2 ], %o5
a00d683c:  c2 0a 20 12  ldub  [ %o0 + 0x12 ], %g1
a00d6840:  9a 0b 60 80  and  %o5, 0x80, %o5
a00d6844:  82 08 60 7f  and  %g1, 0x7f, %g1
a00d6848:  82 10 40 0d  or  %g1, %o5, %g1
a00d684c:  c2 2a 20 12  stb  %g1, [ %o0 + 0x12 ]
a00d6850:  da 0b 20 02  ldub  [ %o4 + 2 ], %o5
a00d6854:  9a 0b 60 40  and  %o5, 0x40, %o5
a00d6858:  82 08 7f bf  and  %g1, -65, %g1
a00d685c:  82 10 40 0d  or  %g1, %o5, %g1
a00d6860:  c2 2a 20 12  stb  %g1, [ %o0 + 0x12 ]
a00d6864:  da 0b 20 02  ldub  [ %o4 + 2 ], %o5
a00d6868:  9a 0b 60 10  and  %o5, 0x10, %o5
a00d686c:  82 08 7f ef  and  %g1, -17, %g1
a00d6870:  82 10 40 0d  or  %g1, %o5, %g1
a00d6874:  c2 2a 20 12  stb  %g1, [ %o0 + 0x12 ]
a00d6878:  da 0b 20 02  ldub  [ %o4 + 2 ], %o5
a00d687c:  9a 0b 60 0f  and  %o5, 0xf, %o5
a00d6880:  82 08 7f f0  and  %g1, -16, %g1
a00d6884:  82 10 40 0d  or  %g1, %o5, %g1
a00d6888:  81 c3 e0 08  retl
a00d688c:  c2 2a 20 12  stb  %g1, [ %o0 + 0x12 ]
