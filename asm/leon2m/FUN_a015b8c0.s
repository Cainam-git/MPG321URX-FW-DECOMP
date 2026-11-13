# leon2m FUN_a015b8c0 0xa015b8c0-0xa015bb44 (644 bytes)
a015b8c0:  9d e3 bf 98  save  %sp, -104, %sp
a015b8c4:  80 a6 60 00  cmp  %i1, 0
a015b8c8:  02 80 00 9d  be  0xa015bb3c
a015b8cc:  a4 10 00 18  mov  %i0, %l2
a015b8d0:  40 00 04 e1  call  0xa015cc54
a015b8d4:  90 10 00 18  mov  %i0, %o0
a015b8d8:  a0 06 7f f8  add  %i1, -8, %l0
a015b8dc:  d6 04 20 04  ld  [ %l0 + 4 ], %o3
a015b8e0:  90 0a ff fe  and  %o3, -2, %o0
a015b8e4:  19 2a 00 aa  sethi  %hi(0xa802a800), %o4
a015b8e8:  94 04 00 08  add  %l0, %o0, %o2
a015b8ec:  a2 13 22 b8  or  %o4, 0x2b8, %l1
a015b8f0:  da 02 a0 04  ld  [ %o2 + 4 ], %o5
a015b8f4:  c2 04 60 08  ld  [ %l1 + 8 ], %g1
a015b8f8:  80 a0 40 0a  cmp  %g1, %o2
a015b8fc:  02 80 00 44  be  0xa015ba0c
a015b900:  9e 0b 7f fc  and  %o5, -4, %o7
a015b904:  80 8a e0 01  btst  1, %o3
a015b908:  de 22 a0 04  st  %o7, [ %o2 + 4 ]
a015b90c:  12 80 00 0c  bne  0xa015b93c
a015b910:  b0 10 20 00  clr  %i0
a015b914:  f2 06 7f f8  ld  [ %i1 + -8 ], %i1
a015b918:  a0 24 00 19  sub  %l0, %i1, %l0
a015b91c:  82 04 60 08  add  %l1, 8, %g1
a015b920:  da 04 20 08  ld  [ %l0 + 8 ], %o5
a015b924:  80 a3 40 01  cmp  %o5, %g1
a015b928:  02 80 00 7d  be  0xa015bb1c
a015b92c:  90 02 00 19  add  %o0, %i1, %o0
a015b930:  d2 04 20 0c  ld  [ %l0 + 0xc ], %o1
a015b934:  da 22 60 08  st  %o5, [ %o1 + 8 ]
a015b938:  d2 23 60 0c  st  %o1, [ %o5 + 0xc ]
a015b93c:  82 02 80 0f  add  %o2, %o7, %g1
a015b940:  da 00 60 04  ld  [ %g1 + 4 ], %o5
a015b944:  80 8b 60 01  btst  1, %o5
a015b948:  12 80 00 0a  bne  0xa015b970
a015b94c:  82 12 20 01  or  %o0, 1, %g1
a015b950:  80 a6 20 00  cmp  %i0, 0
a015b954:  02 80 00 22  be  0xa015b9dc
a015b958:  90 02 00 0f  add  %o0, %o7, %o0
a015b95c:  da 02 a0 08  ld  [ %o2 + 8 ], %o5
a015b960:  d2 02 a0 0c  ld  [ %o2 + 0xc ], %o1
a015b964:  da 22 60 08  st  %o5, [ %o1 + 8 ]
a015b968:  d2 23 60 0c  st  %o1, [ %o5 + 0xc ]
a015b96c:  82 12 20 01  or  %o0, 1, %g1
a015b970:  c2 24 20 04  st  %g1, [ %l0 + 4 ]
a015b974:  80 a6 20 00  cmp  %i0, 0
a015b978:  02 80 00 05  be  0xa015b98c
a015b97c:  d0 24 00 08  st  %o0, [ %l0 + %o0 ]
a015b980:  b0 10 00 12  mov  %l2, %i0
a015b984:  40 00 04 ba  call  0xa015cc6c
a015b988:  81 e8 00 00  restore
a015b98c:  80 a2 21 ff  cmp  %o0, 0x1ff
a015b990:  18 80 00 36  bgu  0xa015ba68
a015b994:  97 32 20 09  srl  %o0, 9, %o3
a015b998:  9b 32 20 03  srl  %o0, 3, %o5
a015b99c:  98 13 22 b8  or  %o4, 0x2b8, %o4
a015b9a0:  83 2b 60 03  sll  %o5, 3, %g1
a015b9a4:  92 00 40 0c  add  %g1, %o4, %o1
a015b9a8:  9b 33 60 02  srl  %o5, 2, %o5
a015b9ac:  82 10 20 01  mov  1, %g1
a015b9b0:  83 28 40 0d  sll  %g1, %o5, %g1
a015b9b4:  d6 02 60 08  ld  [ %o1 + 8 ], %o3
a015b9b8:  da 03 20 04  ld  [ %o4 + 4 ], %o5
a015b9bc:  9a 13 40 01  or  %o5, %g1, %o5
a015b9c0:  d2 24 20 0c  st  %o1, [ %l0 + 0xc ]
a015b9c4:  d6 24 20 08  st  %o3, [ %l0 + 8 ]
a015b9c8:  e0 22 e0 0c  st  %l0, [ %o3 + 0xc ]
a015b9cc:  da 23 20 04  st  %o5, [ %o4 + 4 ]
a015b9d0:  e0 22 60 08  st  %l0, [ %o1 + 8 ]
a015b9d4:  10 bf ff ec  b  0xa015b984
a015b9d8:  b0 10 00 12  mov  %l2, %i0
a015b9dc:  03 2a 00 aa  sethi  %hi(0xa802a800), %g1
a015b9e0:  da 02 a0 08  ld  [ %o2 + 8 ], %o5
a015b9e4:  82 10 62 c0  or  %g1, 0x2c0, %g1
a015b9e8:  80 a3 40 01  cmp  %o5, %g1
a015b9ec:  32 bf ff de  bne,a   0xa015b964
a015b9f0:  d2 02 a0 0c  ld  [ %o2 + 0xc ], %o1
a015b9f4:  e0 23 60 0c  st  %l0, [ %o5 + 0xc ]
a015b9f8:  e0 23 60 08  st  %l0, [ %o5 + 8 ]
a015b9fc:  da 24 20 08  st  %o5, [ %l0 + 8 ]
a015ba00:  da 24 20 0c  st  %o5, [ %l0 + 0xc ]
a015ba04:  10 bf ff da  b  0xa015b96c
a015ba08:  b0 10 20 01  mov  1, %i0
a015ba0c:  80 8a e0 01  btst  1, %o3
a015ba10:  12 80 00 09  bne  0xa015ba34
a015ba14:  90 02 00 0f  add  %o0, %o7, %o0
a015ba18:  f2 06 7f f8  ld  [ %i1 + -8 ], %i1
a015ba1c:  a0 24 00 19  sub  %l0, %i1, %l0
a015ba20:  d2 04 20 0c  ld  [ %l0 + 0xc ], %o1
a015ba24:  d6 04 20 08  ld  [ %l0 + 8 ], %o3
a015ba28:  d6 22 60 08  st  %o3, [ %o1 + 8 ]
a015ba2c:  90 02 00 19  add  %o0, %i1, %o0
a015ba30:  d2 22 e0 0c  st  %o1, [ %o3 + 0xc ]
a015ba34:  03 2a 00 aa  sethi  %hi(0xa802a800), %g1
a015ba38:  da 00 62 b4  ld  [ %g1 + 0x2b4 ], %o5	! 0xa802aab4
a015ba3c:  98 12 20 01  or  %o0, 1, %o4
a015ba40:  e0 24 60 08  st  %l0, [ %l1 + 8 ]
a015ba44:  80 a2 00 0d  cmp  %o0, %o5
a015ba48:  0a bf ff cf  bcs  0xa015b984
a015ba4c:  d8 24 20 04  st  %o4, [ %l0 + 4 ]
a015ba50:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a015ba54:  d2 00 63 d0  ld  [ %g1 + 0x3d0 ], %o1	! 0xa802cfd0
a015ba58:  7f ff ff 5b  call  0xa015b7c4
a015ba5c:  90 10 00 12  mov  %l2, %o0
a015ba60:  40 00 04 83  call  0xa015cc6c
a015ba64:  81 e8 00 00  restore
a015ba68:  80 a2 e0 00  cmp  %o3, 0
a015ba6c:  02 80 00 16  be  0xa015bac4
a015ba70:  9b 32 20 03  srl  %o0, 3, %o5
a015ba74:  83 32 20 06  srl  %o0, 6, %g1
a015ba78:  80 a2 e0 04  cmp  %o3, 4
a015ba7c:  08 80 00 12  bleu  0xa015bac4
a015ba80:  9a 00 60 38  add  %g1, 0x38, %o5
a015ba84:  80 a2 e0 14  cmp  %o3, 0x14
a015ba88:  08 80 00 0f  bleu  0xa015bac4
a015ba8c:  9a 02 e0 5b  add  %o3, 0x5b, %o5
a015ba90:  83 32 20 0c  srl  %o0, 0xc, %g1
a015ba94:  80 a2 e0 54  cmp  %o3, 0x54
a015ba98:  08 80 00 0b  bleu  0xa015bac4
a015ba9c:  9a 00 60 6e  add  %g1, 0x6e, %o5
a015baa0:  83 32 20 0f  srl  %o0, 0xf, %g1
a015baa4:  80 a2 e1 54  cmp  %o3, 0x154
a015baa8:  08 80 00 07  bleu  0xa015bac4
a015baac:  9a 00 60 77  add  %g1, 0x77, %o5
a015bab0:  83 32 20 12  srl  %o0, 0x12, %g1
a015bab4:  80 a2 e5 54  cmp  %o3, 0x554
a015bab8:  08 80 00 03  bleu  0xa015bac4
a015babc:  9a 00 60 7c  add  %g1, 0x7c, %o5
a015bac0:  9a 10 20 7e  mov  0x7e, %o5
a015bac4:  94 13 22 b8  or  %o4, 0x2b8, %o2
a015bac8:  83 2b 60 03  sll  %o5, 3, %g1
a015bacc:  92 00 40 0a  add  %g1, %o2, %o1
a015bad0:  d6 02 60 08  ld  [ %o1 + 8 ], %o3
a015bad4:  80 a2 c0 09  cmp  %o3, %o1
a015bad8:  02 80 00 13  be  0xa015bb24
a015badc:  99 33 60 02  srl  %o5, 2, %o4
a015bae0:  c2 02 e0 04  ld  [ %o3 + 4 ], %g1
a015bae4:  82 08 7f fc  and  %g1, -4, %g1
a015bae8:  80 a0 40 08  cmp  %g1, %o0
a015baec:  28 80 00 07  bleu,a   0xa015bb08
a015baf0:  d2 02 e0 0c  ld  [ %o3 + 0xc ], %o1
a015baf4:  d6 02 e0 08  ld  [ %o3 + 8 ], %o3
a015baf8:  80 a2 c0 09  cmp  %o3, %o1
a015bafc:  32 bf ff fa  bne,a   0xa015bae4
a015bb00:  c2 02 e0 04  ld  [ %o3 + 4 ], %g1
a015bb04:  d2 02 e0 0c  ld  [ %o3 + 0xc ], %o1
a015bb08:  d2 24 20 0c  st  %o1, [ %l0 + 0xc ]
a015bb0c:  d6 24 20 08  st  %o3, [ %l0 + 8 ]
a015bb10:  e0 22 e0 0c  st  %l0, [ %o3 + 0xc ]
a015bb14:  10 bf ff b0  b  0xa015b9d4
a015bb18:  e0 22 60 08  st  %l0, [ %o1 + 8 ]
a015bb1c:  10 bf ff 88  b  0xa015b93c
a015bb20:  b0 10 20 01  mov  1, %i0
a015bb24:  9a 10 20 01  mov  1, %o5
a015bb28:  c2 02 a0 04  ld  [ %o2 + 4 ], %g1
a015bb2c:  9b 2b 40 0c  sll  %o5, %o4, %o5
a015bb30:  82 10 40 0d  or  %g1, %o5, %g1
a015bb34:  10 bf ff f5  b  0xa015bb08
a015bb38:  c2 22 a0 04  st  %g1, [ %o2 + 4 ]
a015bb3c:  81 c7 e0 08  ret
a015bb40:  81 e8 00 00  restore
