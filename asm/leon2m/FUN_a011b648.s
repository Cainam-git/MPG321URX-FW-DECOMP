# leon2m FUN_a011b648 0xa011b648-0xa011bac0 (1144 bytes)
a011b648:  9d e3 bf 98  save  %sp, -104, %sp
a011b64c:  98 0f 20 ff  and  %i4, 0xff, %o4
a011b650:  03 2a 00 b2  sethi  %hi(0xa802c800), %g1
a011b654:  9a 03 00 0c  add  %o4, %o4, %o5
a011b658:  b8 10 61 ca  or  %g1, 0x1ca, %i4
a011b65c:  17 2a 00 b2  sethi  %hi(0xa802c800), %o3
a011b660:  fa 17 00 0d  lduh  [ %i4 + %o5 ], %i5
a011b664:  82 12 e1 a0  or  %o3, 0x1a0, %g1
a011b668:  de 08 40 0c  ldub  [ %g1 + %o4 ], %o7
a011b66c:  39 2a 00 b2  sethi  %hi(0xa802c800), %i4
a011b670:  b4 5e 80 1d  smul  %i2, %i5, %i2
a011b674:  82 17 21 a2  or  %i4, 0x1a2, %g1
a011b678:  fa 10 40 0d  lduh  [ %g1 + %o5 ], %i5
a011b67c:  b2 06 40 1a  add  %i1, %i2, %i1
a011b680:  9a 27 40 0f  sub  %i5, %o7, %o5
a011b684:  80 a3 20 00  cmp  %o4, 0
a011b688:  12 80 00 61  bne  0xa011b80c
a011b68c:  b4 10 00 1b  mov  %i3, %i2
a011b690:  b6 0e 20 ff  and  %i0, 0xff, %i3
a011b694:  80 a6 e0 01  cmp  %i3, 1
a011b698:  02 80 00 d0  be  0xa011b9d8
a011b69c:  31 33 c0 45  sethi  %hi(0xcf011400), %i0
a011b6a0:  82 16 23 80  or  %i0, 0x380, %g1	! 0xcf011780
a011b6a4:  b6 10 20 40  mov  0x40, %i3
a011b6a8:  f6 20 40 00  st  %i3, [ %g1 ]
a011b6ac:  82 10 20 9f  mov  0x9f, %g1
a011b6b0:  01 00 00 00  nop
a011b6b4:  82 80 7f ff  addcc  %g1, -1, %g1
a011b6b8:  1c bf ff fe  bpos  0xa011b6b0
a011b6bc:  b7 2e 60 10  sll  %i1, 0x10, %i3
a011b6c0:  31 33 c0 45  sethi  %hi(0xcf011400), %i0
a011b6c4:  b9 36 e0 10  srl  %i3, 0x10, %i4
a011b6c8:  ba 0f 20 ff  and  %i4, 0xff, %i5
a011b6cc:  b2 16 23 84  or  %i0, 0x384, %i1
a011b6d0:  fa 26 40 00  st  %i5, [ %i1 ]
a011b6d4:  83 36 e0 18  srl  %i3, 0x18, %g1
a011b6d8:  b8 16 23 88  or  %i0, 0x388, %i4
a011b6dc:  3b 33 c0 2f  sethi  %hi(0xcf00bc00), %i5
a011b6e0:  c2 27 00 00  st  %g1, [ %i4 ]
a011b6e4:  b2 17 63 cc  or  %i5, 0x3cc, %i1
a011b6e8:  c0 26 40 00  clr  [ %i1 ]
a011b6ec:  82 10 20 9f  mov  0x9f, %g1
a011b6f0:  01 00 00 00  nop
a011b6f4:  82 80 7f ff  addcc  %g1, -1, %g1
a011b6f8:  1c bf ff fe  bpos  0xa011b6f0
a011b6fc:  9e 10 20 00  clr  %o7
a011b700:  03 2a 00 b2  sethi  %hi(0xa802c800), %g1
a011b704:  fa 08 61 ab  ldub  [ %g1 + 0x1ab ], %i5	! 0xa802c9ab
a011b708:  82 97 60 00  orcc  %i5, 0, %g1
a011b70c:  02 80 00 08  be  0xa011b72c
a011b710:  b2 0e a0 ff  and  %i2, 0xff, %i1
a011b714:  80 a0 60 01  cmp  %g1, 1
a011b718:  02 80 00 da  be  0xa011ba80
a011b71c:  82 0f 60 ff  and  %i5, 0xff, %g1
a011b720:  80 a0 60 02  cmp  %g1, 2
a011b724:  02 80 00 de  be  0xa011ba9c
a011b728:  f0 0a e1 a0  ldub  [ %o3 + 0x1a0 ], %i0
a011b72c:  b8 0b e0 ff  and  %o7, 0xff, %i4
a011b730:  80 a7 20 00  cmp  %i4, 0
a011b734:  02 80 00 0f  be  0xa011b770
a011b738:  ba 10 20 00  clr  %i5
a011b73c:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a011b740:  b6 10 63 8c  or  %g1, 0x38c, %i3	! 0xcf01178c
a011b744:  c0 26 c0 00  clr  [ %i3 ]
a011b748:  82 10 20 9f  mov  0x9f, %g1
a011b74c:  01 00 00 00  nop
a011b750:  82 80 7f ff  addcc  %g1, -1, %g1
a011b754:  1c bf ff fe  bpos  0xa011b74c
a011b758:  01 00 00 00  nop
a011b75c:  ba 07 60 01  inc  %i5
a011b760:  b4 0f 60 ff  and  %i5, 0xff, %i2
a011b764:  80 a6 80 1c  cmp  %i2, %i4
a011b768:  0a bf ff f7  bcs  0xa011b744
a011b76c:  01 00 00 00  nop
a011b770:  f4 0a e1 a0  ldub  [ %o3 + 0x1a0 ], %i2
a011b774:  80 a6 a0 00  cmp  %i2, 0
a011b778:  02 80 00 12  be  0xa011b7c0
a011b77c:  b8 10 20 00  clr  %i4
a011b780:  3b 33 c0 45  sethi  %hi(0xcf011400), %i5
a011b784:  b6 10 00 0d  mov  %o5, %i3
a011b788:  b0 17 63 8c  or  %i5, 0x38c, %i0
a011b78c:  ba 07 00 1b  add  %i4, %i3, %i5
a011b790:  82 0f 60 ff  and  %i5, 0xff, %g1
a011b794:  c2 26 00 00  st  %g1, [ %i0 ]
a011b798:  82 10 20 9f  mov  0x9f, %g1
a011b79c:  01 00 00 00  nop
a011b7a0:  82 80 7f ff  addcc  %g1, -1, %g1
a011b7a4:  1c bf ff fe  bpos  0xa011b79c
a011b7a8:  ba 0e a0 ff  and  %i2, 0xff, %i5
a011b7ac:  b8 07 20 01  inc  %i4
a011b7b0:  82 0f 20 ff  and  %i4, 0xff, %g1
a011b7b4:  80 a7 40 01  cmp  %i5, %g1
a011b7b8:  18 bf ff f6  bgu  0xa011b790
a011b7bc:  ba 07 00 1b  add  %i4, %i3, %i5
a011b7c0:  f0 0a e1 a0  ldub  [ %o3 + 0x1a0 ], %i0
a011b7c4:  b8 06 00 0f  add  %i0, %o7, %i4
a011b7c8:  b6 0f 20 ff  and  %i4, 0xff, %i3
a011b7cc:  80 a6 c0 19  cmp  %i3, %i1
a011b7d0:  1a 80 00 ba  bcc  0xa011bab8
a011b7d4:  35 33 c0 45  sethi  %hi(0xcf011400), %i2
a011b7d8:  ba 16 a3 8c  or  %i2, 0x38c, %i5	! 0xcf01178c
a011b7dc:  c0 27 40 00  clr  [ %i5 ]
a011b7e0:  82 10 20 9f  mov  0x9f, %g1
a011b7e4:  01 00 00 00  nop
a011b7e8:  82 80 7f ff  addcc  %g1, -1, %g1
a011b7ec:  1c bf ff fe  bpos  0xa011b7e4
a011b7f0:  01 00 00 00  nop
a011b7f4:  b8 07 20 01  inc  %i4
a011b7f8:  82 0f 20 ff  and  %i4, 0xff, %g1
a011b7fc:  80 a0 40 19  cmp  %g1, %i1
a011b800:  0a bf ff f7  bcs  0xa011b7dc
a011b804:  01 00 00 00  nop
a011b808:  30 80 00 ac  b,a   0xa011bab8
a011b80c:  b8 0e 20 ff  and  %i0, 0xff, %i4
a011b810:  80 a7 20 01  cmp  %i4, 1
a011b814:  02 80 00 7c  be  0xa011ba04
a011b818:  37 33 c0 45  sethi  %hi(0xcf011400), %i3
a011b81c:  82 16 e3 94  or  %i3, 0x394, %g1	! 0xcf011794
a011b820:  b8 10 20 40  mov  0x40, %i4
a011b824:  f8 20 40 00  st  %i4, [ %g1 ]
a011b828:  82 10 20 9f  mov  0x9f, %g1
a011b82c:  01 00 00 00  nop
a011b830:  82 80 7f ff  addcc  %g1, -1, %g1
a011b834:  1c bf ff fe  bpos  0xa011b82c
a011b838:  80 a3 20 00  cmp  %o4, 0
a011b83c:  b3 2e 60 10  sll  %i1, 0x10, %i1
a011b840:  12 80 00 7d  bne  0xa011ba34
a011b844:  bb 36 60 10  srl  %i1, 0x10, %i5
a011b848:  39 33 c0 45  sethi  %hi(0xcf011400), %i4
a011b84c:  b6 0f 60 ff  and  %i5, 0xff, %i3
a011b850:  82 17 23 84  or  %i4, 0x384, %g1
a011b854:  f6 20 40 00  st  %i3, [ %g1 ]
a011b858:  b0 17 23 88  or  %i4, 0x388, %i0
a011b85c:  bb 36 60 18  srl  %i1, 0x18, %i5
a011b860:  fa 26 00 00  st  %i5, [ %i0 ]
a011b864:  03 33 c0 2f  sethi  %hi(0xcf00bc00), %g1
a011b868:  b2 10 63 cc  or  %g1, 0x3cc, %i1	! 0xcf00bfcc
a011b86c:  c0 26 40 00  clr  [ %i1 ]
a011b870:  82 10 20 9f  mov  0x9f, %g1
a011b874:  01 00 00 00  nop
a011b878:  82 80 7f ff  addcc  %g1, -1, %g1
a011b87c:  1c bf ff fe  bpos  0xa011b874
a011b880:  b9 2b 20 02  sll  %o4, 2, %i4
a011b884:  03 2a 00 b2  sethi  %hi(0xa802c800), %g1
a011b888:  ba 10 61 a8  or  %g1, 0x1a8, %i5	! 0xa802c9a8
a011b88c:  f0 07 40 1c  ld  [ %i5 + %i4 ], %i0
a011b890:  b8 0e 20 ff  and  %i0, 0xff, %i4
a011b894:  82 97 20 00  orcc  %i4, 0, %g1
a011b898:  94 10 20 00  clr  %o2
a011b89c:  02 80 00 08  be  0xa011b8bc
a011b8a0:  b2 0e a0 ff  and  %i2, 0xff, %i1
a011b8a4:  80 a0 60 01  cmp  %g1, 1
a011b8a8:  02 80 00 79  be  0xa011ba8c
a011b8ac:  b8 0f 20 ff  and  %i4, 0xff, %i4
a011b8b0:  80 a7 20 02  cmp  %i4, 2
a011b8b4:  02 80 00 7d  be  0xa011baa8
a011b8b8:  ba 12 e1 a0  or  %o3, 0x1a0, %i5
a011b8bc:  b8 0a a0 ff  and  %o2, 0xff, %i4
a011b8c0:  80 a7 20 00  cmp  %i4, 0
a011b8c4:  02 80 00 13  be  0xa011b910
a011b8c8:  ba 10 20 00  clr  %i5
a011b8cc:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a011b8d0:  b4 10 63 a0  or  %g1, 0x3a0, %i2	! 0xcf0117a0
a011b8d4:  b6 10 63 8c  or  %g1, 0x38c, %i3
a011b8d8:  80 a3 20 00  cmp  %o4, 0
a011b8dc:  12 80 00 5f  bne  0xa011ba58
a011b8e0:  01 00 00 00  nop
a011b8e4:  c0 26 c0 00  clr  [ %i3 ]
a011b8e8:  82 10 20 9f  mov  0x9f, %g1
a011b8ec:  01 00 00 00  nop
a011b8f0:  82 80 7f ff  addcc  %g1, -1, %g1
a011b8f4:  1c bf ff fe  bpos  0xa011b8ec
a011b8f8:  01 00 00 00  nop
a011b8fc:  ba 07 60 01  inc  %i5
a011b900:  b0 0f 60 ff  and  %i5, 0xff, %i0
a011b904:  80 a6 00 1c  cmp  %i0, %i4
a011b908:  0a bf ff f5  bcs  0xa011b8dc
a011b90c:  80 a3 20 00  cmp  %o4, 0
a011b910:  b4 12 e1 a0  or  %o3, 0x1a0, %i2
a011b914:  f6 0e 80 0c  ldub  [ %i2 + %o4 ], %i3
a011b918:  80 a6 e0 00  cmp  %i3, 0
a011b91c:  08 80 00 18  bleu  0xa011b97c
a011b920:  b6 10 20 00  clr  %i3
a011b924:  39 33 c0 45  sethi  %hi(0xcf011400), %i4
a011b928:  b4 10 00 0d  mov  %o5, %i2
a011b92c:  9e 17 23 a0  or  %i4, 0x3a0, %o7
a011b930:  b0 17 23 8c  or  %i4, 0x38c, %i0
a011b934:  80 a3 20 00  cmp  %o4, 0
a011b938:  12 80 00 4b  bne  0xa011ba64
a011b93c:  82 06 c0 1a  add  %i3, %i2, %g1
a011b940:  ba 08 60 ff  and  %g1, 0xff, %i5
a011b944:  fa 26 00 00  st  %i5, [ %i0 ]
a011b948:  82 10 20 9f  mov  0x9f, %g1
a011b94c:  01 00 00 00  nop
a011b950:  82 80 7f ff  addcc  %g1, -1, %g1
a011b954:  1c bf ff fe  bpos  0xa011b94c
a011b958:  01 00 00 00  nop
a011b95c:  b6 06 e0 01  inc  %i3
a011b960:  82 12 e1 a0  or  %o3, 0x1a0, %g1
a011b964:  f8 08 40 0c  ldub  [ %g1 + %o4 ], %i4
a011b968:  ba 0e e0 ff  and  %i3, 0xff, %i5
a011b96c:  80 a7 00 1d  cmp  %i4, %i5
a011b970:  18 bf ff f2  bgu  0xa011b938
a011b974:  80 a3 20 00  cmp  %o4, 0
a011b978:  b4 12 e1 a0  or  %o3, 0x1a0, %i2
a011b97c:  f6 0e 80 0c  ldub  [ %i2 + %o4 ], %i3
a011b980:  ba 06 c0 0a  add  %i3, %o2, %i5
a011b984:  b0 0f 60 ff  and  %i5, 0xff, %i0
a011b988:  80 a6 00 19  cmp  %i0, %i1
a011b98c:  1a 80 00 4b  bcc  0xa011bab8
a011b990:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a011b994:  b6 10 63 a0  or  %g1, 0x3a0, %i3	! 0xcf0117a0
a011b998:  b8 10 63 8c  or  %g1, 0x38c, %i4
a011b99c:  80 a3 20 00  cmp  %o4, 0
a011b9a0:  12 80 00 35  bne  0xa011ba74
a011b9a4:  01 00 00 00  nop
a011b9a8:  c0 27 00 00  clr  [ %i4 ]
a011b9ac:  82 10 20 9f  mov  0x9f, %g1
a011b9b0:  01 00 00 00  nop
a011b9b4:  82 80 7f ff  addcc  %g1, -1, %g1
a011b9b8:  1c bf ff fe  bpos  0xa011b9b0
a011b9bc:  01 00 00 00  nop
a011b9c0:  ba 07 60 01  inc  %i5
a011b9c4:  b0 0f 60 ff  and  %i5, 0xff, %i0
a011b9c8:  80 a6 00 19  cmp  %i0, %i1
a011b9cc:  0a bf ff f5  bcs  0xa011b9a0
a011b9d0:  80 a3 20 00  cmp  %o4, 0
a011b9d4:  30 80 00 39  b,a   0xa011bab8
a011b9d8:  39 33 c0 45  sethi  %hi(0xcf011400), %i4
a011b9dc:  ba 10 20 90  mov  0x90, %i5
a011b9e0:  b0 17 23 80  or  %i4, 0x380, %i0
a011b9e4:  fa 26 00 00  st  %i5, [ %i0 ]
a011b9e8:  82 10 20 9f  mov  0x9f, %g1
a011b9ec:  01 00 00 00  nop
a011b9f0:  82 80 7f ff  addcc  %g1, -1, %g1
a011b9f4:  1c bf ff fe  bpos  0xa011b9ec
a011b9f8:  b7 2e 60 10  sll  %i1, 0x10, %i3
a011b9fc:  10 bf ff 32  b  0xa011b6c4
a011ba00:  31 33 c0 45  sethi  %hi(0xcf011400), %i0
a011ba04:  31 33 c0 45  sethi  %hi(0xcf011400), %i0
a011ba08:  ba 10 20 90  mov  0x90, %i5
a011ba0c:  b6 16 23 94  or  %i0, 0x394, %i3
a011ba10:  fa 26 c0 00  st  %i5, [ %i3 ]
a011ba14:  82 10 20 9f  mov  0x9f, %g1
a011ba18:  01 00 00 00  nop
a011ba1c:  82 80 7f ff  addcc  %g1, -1, %g1
a011ba20:  1c bf ff fe  bpos  0xa011ba18
a011ba24:  80 a3 20 00  cmp  %o4, 0
a011ba28:  b3 2e 60 10  sll  %i1, 0x10, %i1
a011ba2c:  02 bf ff 87  be  0xa011b848
a011ba30:  bb 36 60 10  srl  %i1, 0x10, %i5
a011ba34:  39 33 c0 45  sethi  %hi(0xcf011400), %i4
a011ba38:  b6 0f 60 ff  and  %i5, 0xff, %i3
a011ba3c:  82 17 23 98  or  %i4, 0x398, %g1
a011ba40:  f6 20 40 00  st  %i3, [ %g1 ]
a011ba44:  b0 17 23 9c  or  %i4, 0x39c, %i0
a011ba48:  bb 36 60 18  srl  %i1, 0x18, %i5
a011ba4c:  fa 26 00 00  st  %i5, [ %i0 ]
a011ba50:  10 bf ff 86  b  0xa011b868
a011ba54:  03 33 c0 30  sethi  %hi(0xcf00c000), %g1
a011ba58:  c0 26 80 00  clr  [ %i2 ]
a011ba5c:  10 bf ff a4  b  0xa011b8ec
a011ba60:  82 10 20 9f  mov  0x9f, %g1
a011ba64:  82 08 60 ff  and  %g1, 0xff, %g1
a011ba68:  c2 23 c0 00  st  %g1, [ %o7 ]
a011ba6c:  10 bf ff b8  b  0xa011b94c
a011ba70:  82 10 20 9f  mov  0x9f, %g1
a011ba74:  c0 26 c0 00  clr  [ %i3 ]
a011ba78:  10 bf ff ce  b  0xa011b9b0
a011ba7c:  82 10 20 9f  mov  0x9f, %g1
a011ba80:  f6 0a e1 a0  ldub  [ %o3 + 0x1a0 ], %i3
a011ba84:  10 bf ff 2a  b  0xa011b72c
a011ba88:  9e 26 80 1b  sub  %i2, %i3, %o7
a011ba8c:  b0 12 e1 a0  or  %o3, 0x1a0, %i0
a011ba90:  f6 0e 00 0c  ldub  [ %i0 + %o4 ], %i3
a011ba94:  10 bf ff 8a  b  0xa011b8bc
a011ba98:  94 26 80 1b  sub  %i2, %i3, %o2
a011ba9c:  b4 26 40 18  sub  %i1, %i0, %i2
a011baa0:  10 bf ff 23  b  0xa011b72c
a011baa4:  9f 36 a0 01  srl  %i2, 1, %o7
a011baa8:  f8 0f 40 0c  ldub  [ %i5 + %o4 ], %i4
a011baac:  b4 26 40 1c  sub  %i1, %i4, %i2
a011bab0:  10 bf ff 83  b  0xa011b8bc
a011bab4:  95 36 a0 01  srl  %i2, 1, %o2
a011bab8:  81 c7 e0 08  ret
a011babc:  81 e8 00 00  restore
