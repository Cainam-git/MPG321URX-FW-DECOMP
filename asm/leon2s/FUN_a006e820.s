# leon2s FUN_a006e820 0xa006e820-0xa006e990 (368 bytes)
a006e820:  9d e3 bf 98  save  %sp, -104, %sp
a006e824:  c2 0e 00 00  ldub  [ %i0 ], %g1
a006e828:  80 a0 60 02  cmp  %g1, 2
a006e82c:  38 80 00 11  bgu,a   0xa006e870
a006e830:  c2 0e 20 0d  ldub  [ %i0 + 0xd ], %g1
a006e834:  32 80 00 0d  bne,a   0xa006e868
a006e838:  c2 0e 20 0d  ldub  [ %i0 + 0xd ], %g1
a006e83c:  40 00 fa 90  call  0xa00ad27c
a006e840:  90 0e 60 ff  and  %i1, 0xff, %o0
a006e844:  90 0a 20 ff  and  %o0, 0xff, %o0
a006e848:  80 a2 20 01  cmp  %o0, 1
a006e84c:  12 80 00 04  bne  0xa006e85c
a006e850:  c2 0e 20 0d  ldub  [ %i0 + 0xd ], %g1
a006e854:  10 80 00 03  b  0xa006e860
a006e858:  82 10 60 01  or  %g1, 1, %g1
a006e85c:  82 08 7f fe  and  %g1, -2, %g1
a006e860:  c2 2e 20 0d  stb  %g1, [ %i0 + 0xd ]
a006e864:  c2 0e 20 0d  ldub  [ %i0 + 0xd ], %g1
a006e868:  10 80 00 47  b  0xa006e984
a006e86c:  82 08 60 01  and  %g1, 1, %g1
a006e870:  82 10 60 01  or  %g1, 1, %g1
a006e874:  b2 0e 60 ff  and  %i1, 0xff, %i1
a006e878:  c2 2e 20 0d  stb  %g1, [ %i0 + 0xd ]
a006e87c:  40 00 fb c2  call  0xa00ad784
a006e880:  90 10 00 19  mov  %i1, %o0
a006e884:  80 8a 20 ff  btst  0xff, %o0
a006e888:  02 80 00 04  be  0xa006e898
a006e88c:  c2 0e 20 0d  ldub  [ %i0 + 0xd ], %g1
a006e890:  10 80 00 03  b  0xa006e89c
a006e894:  82 10 60 02  or  %g1, 2, %g1
a006e898:  82 08 7f fd  and  %g1, -3, %g1
a006e89c:  c2 2e 20 0d  stb  %g1, [ %i0 + 0xd ]
a006e8a0:  40 00 fa a0  call  0xa00ad320
a006e8a4:  90 10 00 19  mov  %i1, %o0
a006e8a8:  80 8a 20 ff  btst  0xff, %o0
a006e8ac:  02 80 00 04  be  0xa006e8bc
a006e8b0:  c2 0e 20 0d  ldub  [ %i0 + 0xd ], %g1
a006e8b4:  10 80 00 03  b  0xa006e8c0
a006e8b8:  82 10 60 04  or  %g1, 4, %g1
a006e8bc:  82 08 7f fb  and  %g1, -5, %g1
a006e8c0:  c2 2e 20 0d  stb  %g1, [ %i0 + 0xd ]
a006e8c4:  40 01 03 18  call  0xa00af524
a006e8c8:  90 10 00 19  mov  %i1, %o0
a006e8cc:  90 0a 20 ff  and  %o0, 0xff, %o0
a006e8d0:  80 8a 20 01  btst  1, %o0
a006e8d4:  02 80 00 04  be  0xa006e8e4
a006e8d8:  c2 0e 20 0d  ldub  [ %i0 + 0xd ], %g1
a006e8dc:  10 80 00 03  b  0xa006e8e8
a006e8e0:  82 10 60 08  or  %g1, 8, %g1
a006e8e4:  82 08 7f f7  and  %g1, -9, %g1
a006e8e8:  c2 2e 20 0d  stb  %g1, [ %i0 + 0xd ]
a006e8ec:  80 8a 20 02  btst  2, %o0
a006e8f0:  02 80 00 04  be  0xa006e900
a006e8f4:  c2 0e 20 0d  ldub  [ %i0 + 0xd ], %g1
a006e8f8:  10 80 00 03  b  0xa006e904
a006e8fc:  82 10 60 10  or  %g1, 0x10, %g1
a006e900:  82 08 7f ef  and  %g1, -17, %g1
a006e904:  c2 2e 20 0d  stb  %g1, [ %i0 + 0xd ]
a006e908:  90 10 00 18  mov  %i0, %o0
a006e90c:  40 01 03 61  call  0xa00af690
a006e910:  92 10 00 19  mov  %i1, %o1
a006e914:  80 8a 20 ff  btst  0xff, %o0
a006e918:  02 80 00 04  be  0xa006e928
a006e91c:  c2 16 20 12  lduh  [ %i0 + 0x12 ], %g1
a006e920:  10 80 00 03  b  0xa006e92c
a006e924:  82 10 60 40  or  %g1, 0x40, %g1
a006e928:  82 08 7f bf  and  %g1, -65, %g1
a006e92c:  c2 36 20 12  sth  %g1, [ %i0 + 0x12 ]
a006e930:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a006e934:  c2 08 60 35  ldub  [ %g1 + 0x35 ], %g1	! 0xa8078c35
a006e938:  9a 06 60 04  add  %i1, 4, %o5
a006e93c:  83 38 40 0d  sra  %g1, %o5, %g1
a006e940:  80 88 60 01  btst  1, %g1
a006e944:  02 80 00 04  be  0xa006e954
a006e948:  c2 0e 20 0d  ldub  [ %i0 + 0xd ], %g1
a006e94c:  10 80 00 03  b  0xa006e958
a006e950:  82 10 60 40  or  %g1, 0x40, %g1
a006e954:  82 08 7f bf  and  %g1, -65, %g1
a006e958:  c2 2e 20 0d  stb  %g1, [ %i0 + 0xd ]
a006e95c:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a006e960:  c2 08 60 5b  ldub  [ %g1 + 0x5b ], %g1	! 0xa8078c5b
a006e964:  9a 06 60 04  add  %i1, 4, %o5
a006e968:  83 38 40 0d  sra  %g1, %o5, %g1
a006e96c:  80 88 60 01  btst  1, %g1
a006e970:  02 80 00 04  be  0xa006e980
a006e974:  c2 0e 20 0d  ldub  [ %i0 + 0xd ], %g1
a006e978:  10 80 00 03  b  0xa006e984
a006e97c:  82 10 60 20  or  %g1, 0x20, %g1
a006e980:  82 08 7f df  and  %g1, -33, %g1
a006e984:  c2 2e 20 0d  stb  %g1, [ %i0 + 0xd ]
a006e988:  81 c7 e0 08  ret
a006e98c:  81 e8 00 00  restore
