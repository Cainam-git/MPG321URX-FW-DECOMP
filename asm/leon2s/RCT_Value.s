# leon2s RCT_Value 0xa0075858-0xa0075ffc (1956 bytes)
a0075858:  9d e3 bf 90  save  %sp, -112, %sp
a007585c:  3b 2a 01 e1  sethi  %hi(0xa8078400), %i5
a0075860:  c2 07 62 34  ld  [ %i5 + 0x234 ], %g1	! 0xa8078634
a0075864:  80 88 60 02  btst  2, %g1
a0075868:  02 80 00 18  be  0xa00758c8
a007586c:  a4 10 00 18  mov  %i0, %l2
a0075870:  98 0e 20 ff  and  %i0, 0xff, %o4
a0075874:  17 2a 01 ea  sethi  %hi(0xa807a800), %o3
a0075878:  96 12 e1 f0  or  %o3, 0x1f0, %o3	! 0xa807a9f0
a007587c:  82 5b 28 98  smul  %o4, 0x898, %g1
a0075880:  82 00 40 0b  add  %g1, %o3, %g1
a0075884:  94 0e 60 ff  and  %i1, 0xff, %o2
a0075888:  82 00 40 0a  add  %g1, %o2, %g1
a007588c:  da 08 68 90  ldub  [ %g1 + 0x890 ], %o5
a0075890:  82 03 40 0d  add  %o5, %o5, %g1
a0075894:  82 00 40 0d  add  %g1, %o5, %g1
a0075898:  98 5b 24 4c  smul  %o4, 0x44c, %o4
a007589c:  82 00 40 0c  add  %g1, %o4, %g1
a00758a0:  82 00 40 0a  add  %g1, %o2, %g1
a00758a4:  92 06 20 41  add  %i0, 0x41, %o1
a00758a8:  82 00 40 01  add  %g1, %g1, %g1
a00758ac:  82 00 40 0b  add  %g1, %o3, %g1
a00758b0:  93 2a 60 18  sll  %o1, 0x18, %o1
a00758b4:  11 28 01 9a  sethi  %hi(0xa0066800), %o0
a00758b8:  90 12 23 a8  or  %o0, 0x3a8, %o0	! 0xa0066ba8
a00758bc:  93 3a 60 18  sra  %o1, 0x18, %o1
a00758c0:  7f ff f5 e1  call  0xa0073044
a00758c4:  d6 10 68 60  lduh  [ %g1 + 0x860 ], %o3
a00758c8:  92 0c a0 ff  and  %l2, 0xff, %o1
a00758cc:  15 2a 01 ea  sethi  %hi(0xa807a800), %o2
a00758d0:  98 12 a1 f0  or  %o2, 0x1f0, %o4	! 0xa807a9f0
a00758d4:  82 5a 68 98  smul  %o1, 0x898, %g1
a00758d8:  82 00 40 0c  add  %g1, %o4, %g1
a00758dc:  90 0e 60 ff  and  %i1, 0xff, %o0
a00758e0:  82 00 40 08  add  %g1, %o0, %g1
a00758e4:  da 08 68 90  ldub  [ %g1 + 0x890 ], %o5
a00758e8:  82 03 40 0d  add  %o5, %o5, %g1
a00758ec:  82 00 40 0d  add  %g1, %o5, %g1
a00758f0:  9a 5a 64 4c  smul  %o1, 0x44c, %o5
a00758f4:  82 00 40 0d  add  %g1, %o5, %g1
a00758f8:  82 00 40 08  add  %g1, %o0, %g1
a00758fc:  82 00 40 01  add  %g1, %g1, %g1
a0075900:  82 00 40 0c  add  %g1, %o4, %g1
a0075904:  c2 10 68 60  lduh  [ %g1 + 0x860 ], %g1
a0075908:  80 a0 60 00  cmp  %g1, 0
a007590c:  9e 10 00 0a  mov  %o2, %o7
a0075910:  19 2a 01 f3  sethi  %hi(0xa807cc00), %o4
a0075914:  12 80 00 1b  bne  0xa0075980
a0075918:  82 02 40 09  add  %o1, %o1, %g1
a007591c:  82 00 40 09  add  %g1, %o1, %g1
a0075920:  9a 13 20 c4  or  %o4, 0xc4, %o5
a0075924:  83 28 60 02  sll  %g1, 2, %g1
a0075928:  82 00 40 0d  add  %g1, %o5, %g1
a007592c:  c2 08 60 08  ldub  [ %g1 + 8 ], %g1
a0075930:  80 a0 60 00  cmp  %g1, 0
a0075934:  12 80 00 09  bne  0xa0075958
a0075938:  b8 10 20 ff  mov  0xff, %i4
a007593c:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a0075940:  82 10 61 88  or  %g1, 0x188, %g1	! 0xa8078988
a0075944:  c2 08 40 09  ldub  [ %g1 + %o1 ], %g1
a0075948:  80 a0 60 01  cmp  %g1, 1
a007594c:  02 80 00 03  be  0xa0075958
a0075950:  b8 10 20 00  clr  %i4
a0075954:  b8 10 20 ff  mov  0xff, %i4
a0075958:  98 12 a1 f0  or  %o2, 0x1f0, %o4
a007595c:  9a 5a 68 98  smul  %o1, 0x898, %o5
a0075960:  82 03 40 0c  add  %o5, %o4, %g1
a0075964:  82 00 40 08  add  %g1, %o0, %g1
a0075968:  c2 08 68 90  ldub  [ %g1 + 0x890 ], %g1
a007596c:  82 58 60 54  smul  %g1, 0x54, %g1
a0075970:  9a 03 40 01  add  %o5, %g1, %o5
a0075974:  98 03 24 70  add  %o4, 0x470, %o4
a0075978:  10 80 00 24  b  0xa0075a08
a007597c:  aa 03 40 0c  add  %o5, %o4, %l5
a0075980:  82 00 40 09  add  %g1, %o1, %g1
a0075984:  83 28 60 02  sll  %g1, 2, %g1
a0075988:  9a 13 20 c4  or  %o4, 0xc4, %o5
a007598c:  82 00 40 0d  add  %g1, %o5, %g1
a0075990:  c2 08 60 08  ldub  [ %g1 + 8 ], %g1
a0075994:  80 a0 60 00  cmp  %g1, 0
a0075998:  12 80 00 09  bne  0xa00759bc
a007599c:  b8 10 2f ff  mov  0xfff, %i4
a00759a0:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00759a4:  82 10 61 88  or  %g1, 0x188, %g1	! 0xa8078988
a00759a8:  c2 08 40 09  ldub  [ %g1 + %o1 ], %g1
a00759ac:  80 a0 60 01  cmp  %g1, 1
a00759b0:  02 80 00 03  be  0xa00759bc
a00759b4:  b8 10 20 ff  mov  0xff, %i4
a00759b8:  b8 10 2f ff  mov  0xfff, %i4
a00759bc:  82 02 40 09  add  %o1, %o1, %g1
a00759c0:  94 12 a1 f0  or  %o2, 0x1f0, %o2
a00759c4:  96 5a 68 98  smul  %o1, 0x898, %o3
a00759c8:  82 00 40 09  add  %g1, %o1, %g1
a00759cc:  9a 02 c0 0a  add  %o3, %o2, %o5
a00759d0:  98 13 20 c4  or  %o4, 0xc4, %o4
a00759d4:  83 28 60 02  sll  %g1, 2, %g1
a00759d8:  9a 03 40 08  add  %o5, %o0, %o5
a00759dc:  82 00 40 0c  add  %g1, %o4, %g1
a00759e0:  c2 08 60 08  ldub  [ %g1 + 8 ], %g1
a00759e4:  da 0b 68 90  ldub  [ %o5 + 0x890 ], %o5
a00759e8:  9a 5b 60 54  smul  %o5, 0x54, %o5
a00759ec:  80 a0 60 00  cmp  %g1, 0
a00759f0:  96 02 c0 0d  add  %o3, %o5, %o3
a00759f4:  94 02 a6 68  add  %o2, 0x668, %o2
a00759f8:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a00759fc:  aa 02 c0 0a  add  %o3, %o2, %l5
a0075a00:  12 80 00 04  bne  0xa0075a10
a0075a04:  ac 10 63 80  or  %g1, 0x380, %l6
a0075a08:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a0075a0c:  ac 10 63 88  or  %g1, 0x388, %l6	! 0xa00b3b88
a0075a10:  94 13 e1 f0  or  %o7, 0x1f0, %o2
a0075a14:  96 5a 68 98  smul  %o1, 0x898, %o3
a0075a18:  82 02 c0 0a  add  %o3, %o2, %g1
a0075a1c:  82 00 40 08  add  %g1, %o0, %g1
a0075a20:  9a 02 40 09  add  %o1, %o1, %o5
a0075a24:  c2 08 68 90  ldub  [ %g1 + 0x890 ], %g1
a0075a28:  9a 03 40 09  add  %o5, %o1, %o5
a0075a2c:  21 2a 01 f3  sethi  %hi(0xa807cc00), %l0
a0075a30:  82 58 60 54  smul  %g1, 0x54, %g1
a0075a34:  98 14 20 c4  or  %l0, 0xc4, %o4
a0075a38:  96 02 c0 01  add  %o3, %g1, %o3
a0075a3c:  9b 2b 60 02  sll  %o5, 2, %o5
a0075a40:  94 02 a6 68  add  %o2, 0x668, %o2
a0075a44:  9a 03 40 0c  add  %o5, %o4, %o5
a0075a48:  94 02 c0 0a  add  %o3, %o2, %o2
a0075a4c:  d8 0b 60 08  ldub  [ %o5 + 8 ], %o4
a0075a50:  37 2a 01 ea  sethi  %hi(0xa807a800), %i3
a0075a54:  96 10 20 01  mov  1, %o3
a0075a58:  a2 10 20 01  mov  1, %l1
a0075a5c:  9e 10 20 00  clr  %o7
a0075a60:  10 80 00 08  b  0xa0075a80
a0075a64:  b0 10 20 00  clr  %i0
a0075a68:  80 a0 60 00  cmp  %g1, 0
a0075a6c:  32 80 00 04  bne,a   0xa0075a7c
a0075a70:  96 10 20 00  clr  %o3
a0075a74:  a2 10 20 00  clr  %l1
a0075a78:  9e 03 e0 01  inc  %o7
a0075a7c:  b0 06 20 01  inc  %i0
a0075a80:  9a 0e 20 ff  and  %i0, 0xff, %o5
a0075a84:  82 03 40 0d  add  %o5, %o5, %g1
a0075a88:  82 00 40 0d  add  %g1, %o5, %g1
a0075a8c:  82 00 40 08  add  %g1, %o0, %g1
a0075a90:  80 a3 20 00  cmp  %o4, 0
a0075a94:  02 80 00 04  be  0xa0075aa4
a0075a98:  83 28 60 02  sll  %g1, 2, %g1
a0075a9c:  10 80 00 03  b  0xa0075aa8
a0075aa0:  80 a3 60 04  cmp  %o5, 4
a0075aa4:  80 a3 60 06  cmp  %o5, 6
a0075aa8:  28 bf ff f0  bleu,a   0xa0075a68
a0075aac:  c2 05 40 01  ld  [ %l5 + %g1 ], %g1
a0075ab0:  82 02 40 09  add  %o1, %o1, %g1
a0075ab4:  82 00 40 09  add  %g1, %o1, %g1
a0075ab8:  9a 14 20 c4  or  %l0, 0xc4, %o5
a0075abc:  83 28 60 02  sll  %g1, 2, %g1
a0075ac0:  82 00 40 0d  add  %g1, %o5, %g1
a0075ac4:  c2 08 60 08  ldub  [ %g1 + 8 ], %g1
a0075ac8:  80 a0 60 00  cmp  %g1, 0
a0075acc:  12 80 00 41  bne  0xa0075bd0
a0075ad0:  80 8a e0 ff  btst  0xff, %o3
a0075ad4:  27 2a 01 e2  sethi  %hi(0xa8078800), %l3
a0075ad8:  9a 14 e1 88  or  %l3, 0x188, %o5	! 0xa8078988
a0075adc:  c2 0b 40 09  ldub  [ %o5 + %o1 ], %g1
a0075ae0:  80 a0 60 00  cmp  %g1, 0
a0075ae4:  12 80 00 3b  bne  0xa0075bd0
a0075ae8:  80 8a e0 ff  btst  0xff, %o3
a0075aec:  82 0c 60 ff  and  %l1, 0xff, %g1
a0075af0:  80 a0 60 01  cmp  %g1, 1
a0075af4:  02 80 00 22  be  0xa0075b7c
a0075af8:  98 10 20 01  mov  1, %o4
a0075afc:  b0 10 20 00  clr  %i0
a0075b00:  a0 10 20 00  clr  %l0
a0075b04:  10 80 00 05  b  0xa0075b18
a0075b08:  90 0e 60 ff  and  %i1, 0xff, %o0
a0075b0c:  80 a0 00 01  cmp  %g0, %g1
a0075b10:  82 60 20 00  subx  %g0, 0, %g1
a0075b14:  98 08 40 0c  and  %g1, %o4, %o4
a0075b18:  9a 0e 20 ff  and  %i0, 0xff, %o5
a0075b1c:  82 03 40 0d  add  %o5, %o5, %g1
a0075b20:  82 00 40 0d  add  %g1, %o5, %g1
a0075b24:  82 00 40 08  add  %g1, %o0, %g1
a0075b28:  80 a4 20 00  cmp  %l0, 0
a0075b2c:  83 28 60 02  sll  %g1, 2, %g1
a0075b30:  02 80 00 04  be  0xa0075b40
a0075b34:  b0 06 20 01  inc  %i0
a0075b38:  10 80 00 03  b  0xa0075b44
a0075b3c:  80 a3 60 04  cmp  %o5, 4
a0075b40:  80 a3 60 06  cmp  %o5, 6
a0075b44:  28 bf ff f2  bleu,a   0xa0075b0c
a0075b48:  c2 02 80 01  ld  [ %o2 + %g1 ], %g1
a0075b4c:  82 0b 20 ff  and  %o4, 0xff, %g1
a0075b50:  82 18 60 01  xor  %g1, 1, %g1
a0075b54:  80 a0 00 01  cmp  %g0, %g1
a0075b58:  9a 60 3f ff  subx  %g0, -1, %o5
a0075b5c:  82 0b e0 ff  and  %o7, 0xff, %g1
a0075b60:  80 a0 60 03  cmp  %g1, 3
a0075b64:  82 60 20 00  subx  %g0, 0, %g1
a0075b68:  80 88 40 0d  btst  %g1, %o5
a0075b6c:  02 80 00 06  be  0xa0075b84
a0075b70:  1b 2a 01 e2  sethi  %hi(0xa8078800), %o5
a0075b74:  9a 14 e1 88  or  %l3, 0x188, %o5
a0075b78:  82 10 20 01  mov  1, %g1
a0075b7c:  c2 2b 40 09  stb  %g1, [ %o5 + %o1 ]
a0075b80:  1b 2a 01 e2  sethi  %hi(0xa8078800), %o5
a0075b84:  82 0c a0 ff  and  %l2, 0xff, %g1
a0075b88:  9a 13 61 88  or  %o5, 0x188, %o5
a0075b8c:  c2 0b 40 01  ldub  [ %o5 + %g1 ], %g1
a0075b90:  80 a0 60 01  cmp  %g1, 1
a0075b94:  12 80 00 0f  bne  0xa0075bd0
a0075b98:  80 8a e0 ff  btst  0xff, %o3
a0075b9c:  c2 07 62 34  ld  [ %i5 + 0x234 ], %g1
a0075ba0:  80 88 60 02  btst  2, %g1
a0075ba4:  22 80 01 14  be,a   0xa0075ff4
a0075ba8:  b0 10 20 00  clr  %i0
a0075bac:  92 04 a0 41  add  %l2, 0x41, %o1
a0075bb0:  93 2a 60 18  sll  %o1, 0x18, %o1
a0075bb4:  11 28 01 9a  sethi  %hi(0xa0066800), %o0
a0075bb8:  90 12 23 f0  or  %o0, 0x3f0, %o0	! 0xa0066bf0
a0075bbc:  93 3a 60 18  sra  %o1, 0x18, %o1
a0075bc0:  7f ff f5 21  call  0xa0073044
a0075bc4:  94 0e 60 ff  and  %i1, 0xff, %o2
a0075bc8:  10 80 01 0b  b  0xa0075ff4
a0075bcc:  b0 10 20 00  clr  %i0
a0075bd0:  02 80 00 26  be  0xa0075c68
a0075bd4:  80 8c 60 ff  btst  0xff, %l1
a0075bd8:  c2 07 62 34  ld  [ %i5 + 0x234 ], %g1
a0075bdc:  80 88 60 02  btst  2, %g1
a0075be0:  02 80 00 0a  be  0xa0075c08
a0075be4:  92 0c a0 ff  and  %l2, 0xff, %o1
a0075be8:  92 04 a0 41  add  %l2, 0x41, %o1
a0075bec:  93 2a 60 18  sll  %o1, 0x18, %o1
a0075bf0:  11 28 01 9b  sethi  %hi(0xa0066c00), %o0
a0075bf4:  90 12 20 30  or  %o0, 0x30, %o0	! 0xa0066c30
a0075bf8:  93 3a 60 18  sra  %o1, 0x18, %o1
a0075bfc:  7f ff f5 12  call  0xa0073044
a0075c00:  94 0e 60 ff  and  %i1, 0xff, %o2
a0075c04:  92 0c a0 ff  and  %l2, 0xff, %o1
a0075c08:  82 02 40 09  add  %o1, %o1, %g1
a0075c0c:  82 00 40 09  add  %g1, %o1, %g1
a0075c10:  1b 2a 01 f3  sethi  %hi(0xa807cc00), %o5
a0075c14:  9a 13 60 c4  or  %o5, 0xc4, %o5	! 0xa807ccc4
a0075c18:  83 28 60 02  sll  %g1, 2, %g1
a0075c1c:  82 00 40 0d  add  %g1, %o5, %g1
a0075c20:  c2 08 60 08  ldub  [ %g1 + 8 ], %g1
a0075c24:  80 a0 60 00  cmp  %g1, 0
a0075c28:  d6 0d 80 00  ldub  [ %l6 ], %o3
a0075c2c:  12 80 00 03  bne  0xa0075c38
a0075c30:  9a 05 a0 04  add  %l6, 4, %o5
a0075c34:  9a 05 a0 06  add  %l6, 6, %o5
a0075c38:  d8 0b 40 00  ldub  [ %o5 ], %o4
a0075c3c:  94 0e 60 ff  and  %i1, 0xff, %o2
a0075c40:  82 5a 62 26  smul  %o1, 0x226, %g1
a0075c44:  98 02 c0 0c  add  %o3, %o4, %o4
a0075c48:  82 00 40 0a  add  %g1, %o2, %g1
a0075c4c:  96 16 e1 f0  or  %i3, 0x1f0, %o3
a0075c50:  83 28 60 02  sll  %g1, 2, %g1
a0075c54:  9a 5a 68 98  smul  %o1, 0x898, %o5
a0075c58:  9a 03 40 0b  add  %o5, %o3, %o5
a0075c5c:  82 00 40 0b  add  %g1, %o3, %g1
a0075c60:  10 80 00 4a  b  0xa0075d88
a0075c64:  99 3b 20 01  sra  %o4, 1, %o4
a0075c68:  a8 10 20 00  clr  %l4
a0075c6c:  ae 10 20 00  clr  %l7
a0075c70:  02 80 00 65  be  0xa0075e04
a0075c74:  b0 10 20 00  clr  %i0
a0075c78:  a2 0e 60 ff  and  %i1, 0xff, %l1
a0075c7c:  83 2c 60 02  sll  %l1, 2, %g1
a0075c80:  e0 05 40 01  ld  [ %l5 + %g1 ], %l0
a0075c84:  10 80 00 0e  b  0xa0075cbc
a0075c88:  a6 10 20 01  mov  1, %l3
a0075c8c:  f0 05 40 0c  ld  [ %l5 + %o4 ], %i0
a0075c90:  80 88 60 02  btst  2, %g1
a0075c94:  02 80 00 04  be  0xa0075ca4
a0075c98:  98 10 00 18  mov  %i0, %o4
a0075c9c:  7f ff f4 ea  call  0xa0073044
a0075ca0:  e0 23 a0 5c  st  %l0, [ %sp + 0x5c ]
a0075ca4:  80 a6 00 10  cmp  %i0, %l0
a0075ca8:  3a 80 00 05  bcc,a   0xa0075cbc
a0075cac:  a6 04 e0 01  inc  %l3
a0075cb0:  a0 10 00 18  mov  %i0, %l0
a0075cb4:  a8 10 00 13  mov  %l3, %l4
a0075cb8:  a6 04 e0 01  inc  %l3
a0075cbc:  b0 0c a0 ff  and  %l2, 0xff, %i0
a0075cc0:  9a 06 00 18  add  %i0, %i0, %o5
a0075cc4:  9a 03 40 18  add  %o5, %i0, %o5
a0075cc8:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a0075ccc:  82 10 60 c4  or  %g1, 0xc4, %g1	! 0xa807ccc4
a0075cd0:  9b 2b 60 02  sll  %o5, 2, %o5
a0075cd4:  9a 03 40 01  add  %o5, %g1, %o5
a0075cd8:  c2 0b 60 08  ldub  [ %o5 + 8 ], %g1
a0075cdc:  9e 0c e0 ff  and  %l3, 0xff, %o7
a0075ce0:  80 a0 60 00  cmp  %g1, 0
a0075ce4:  82 03 c0 0f  add  %o7, %o7, %g1
a0075ce8:  92 04 a0 41  add  %l2, 0x41, %o1
a0075cec:  82 00 40 0f  add  %g1, %o7, %g1
a0075cf0:  93 2a 60 18  sll  %o1, 0x18, %o1
a0075cf4:  11 28 01 9b  sethi  %hi(0xa0066c00), %o0
a0075cf8:  82 00 40 11  add  %g1, %l1, %g1
a0075cfc:  90 12 20 70  or  %o0, 0x70, %o0
a0075d00:  93 3a 60 18  sra  %o1, 0x18, %o1
a0075d04:  99 28 60 02  sll  %g1, 2, %o4
a0075d08:  96 10 00 0f  mov  %o7, %o3
a0075d0c:  9a 0d 20 ff  and  %l4, 0xff, %o5
a0075d10:  02 80 00 04  be  0xa0075d20
a0075d14:  94 10 00 11  mov  %l1, %o2
a0075d18:  10 80 00 03  b  0xa0075d24
a0075d1c:  80 a3 e0 04  cmp  %o7, 4
a0075d20:  80 a3 e0 06  cmp  %o7, 6
a0075d24:  08 bf ff da  bleu  0xa0075c8c
a0075d28:  c2 07 62 34  ld  [ %i5 + 0x234 ], %g1
a0075d2c:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a0075d30:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a0075d34:  80 88 60 02  btst  2, %g1
a0075d38:  02 80 00 0b  be  0xa0075d64
a0075d3c:  94 0e 60 ff  and  %i1, 0xff, %o2
a0075d40:  92 04 a0 41  add  %l2, 0x41, %o1
a0075d44:  96 0d 20 ff  and  %l4, 0xff, %o3
a0075d48:  93 2a 60 18  sll  %o1, 0x18, %o1
a0075d4c:  11 28 01 9b  sethi  %hi(0xa0066c00), %o0
a0075d50:  90 12 20 d0  or  %o0, 0xd0, %o0	! 0xa0066cd0
a0075d54:  93 3a 60 18  sra  %o1, 0x18, %o1
a0075d58:  7f ff f4 bb  call  0xa0073044
a0075d5c:  d8 0d 80 0b  ldub  [ %l6 + %o3 ], %o4
a0075d60:  94 0e 60 ff  and  %i1, 0xff, %o2
a0075d64:  82 5e 22 26  smul  %i0, 0x226, %g1
a0075d68:  82 00 40 0a  add  %g1, %o2, %g1
a0075d6c:  96 16 e1 f0  or  %i3, 0x1f0, %o3
a0075d70:  98 0d 20 ff  and  %l4, 0xff, %o4
a0075d74:  83 28 60 02  sll  %g1, 2, %g1
a0075d78:  9a 5e 28 98  smul  %i0, 0x898, %o5
a0075d7c:  d8 0d 80 0c  ldub  [ %l6 + %o4 ], %o4
a0075d80:  9a 03 40 0b  add  %o5, %o3, %o5
a0075d84:  82 00 40 0b  add  %g1, %o3, %g1
a0075d88:  f8 30 68 86  sth  %i4, [ %g1 + 0x886 ]
a0075d8c:  d8 28 68 84  stb  %o4, [ %g1 + 0x884 ]
a0075d90:  9a 03 40 0a  add  %o5, %o2, %o5
a0075d94:  82 10 20 01  mov  1, %g1
a0075d98:  10 80 00 96  b  0xa0075ff0
a0075d9c:  c2 2b 60 34  stb  %g1, [ %o5 + 0x34 ]
a0075da0:  80 88 60 02  btst  2, %g1
a0075da4:  02 80 00 0e  be  0xa0075ddc
a0075da8:  9a 0e 20 ff  and  %i0, 0xff, %o5
a0075dac:  da 0c 28 90  ldub  [ %l0 + 0x890 ], %o5
a0075db0:  83 2b 60 02  sll  %o5, 2, %g1
a0075db4:  82 00 40 0d  add  %g1, %o5, %g1
a0075db8:  83 28 60 02  sll  %g1, 2, %g1
a0075dbc:  82 00 40 0d  add  %g1, %o5, %g1
a0075dc0:  82 03 00 01  add  %o4, %g1, %g1
a0075dc4:  82 00 40 0f  add  %g1, %o7, %g1
a0075dc8:  83 28 60 02  sll  %g1, 2, %g1
a0075dcc:  82 00 40 11  add  %g1, %l1, %g1
a0075dd0:  7f ff f4 9d  call  0xa0073044
a0075dd4:  d8 00 66 68  ld  [ %g1 + 0x668 ], %o4
a0075dd8:  9a 0e 20 ff  and  %i0, 0xff, %o5
a0075ddc:  82 03 40 0d  add  %o5, %o5, %g1
a0075de0:  82 00 40 0d  add  %g1, %o5, %g1
a0075de4:  9a 0e 60 ff  and  %i1, 0xff, %o5
a0075de8:  82 00 40 0d  add  %g1, %o5, %g1
a0075dec:  83 28 60 02  sll  %g1, 2, %g1
a0075df0:  c2 05 40 01  ld  [ %l5 + %g1 ], %g1
a0075df4:  80 a0 60 0f  cmp  %g1, 0xf
a0075df8:  28 80 00 23  bleu,a   0xa0075e84
a0075dfc:  a8 10 00 18  mov  %i0, %l4
a0075e00:  b0 06 20 01  inc  %i0
a0075e04:  9a 0c a0 ff  and  %l2, 0xff, %o5
a0075e08:  82 5b 68 98  smul  %o5, 0x898, %g1
a0075e0c:  a2 16 e1 f0  or  %i3, 0x1f0, %l1
a0075e10:  9e 0e 60 ff  and  %i1, 0xff, %o7
a0075e14:  82 00 40 11  add  %g1, %l1, %g1
a0075e18:  a0 00 40 0f  add  %g1, %o7, %l0
a0075e1c:  82 03 40 0d  add  %o5, %o5, %g1
a0075e20:  98 5b 62 26  smul  %o5, 0x226, %o4
a0075e24:  82 00 40 0d  add  %g1, %o5, %g1
a0075e28:  27 2a 01 f3  sethi  %hi(0xa807cc00), %l3
a0075e2c:  9a 14 e0 c4  or  %l3, 0xc4, %o5	! 0xa807ccc4
a0075e30:  83 28 60 02  sll  %g1, 2, %g1
a0075e34:  82 00 40 0d  add  %g1, %o5, %g1
a0075e38:  c2 08 60 08  ldub  [ %g1 + 8 ], %g1
a0075e3c:  9a 0e 20 ff  and  %i0, 0xff, %o5
a0075e40:  80 a0 60 00  cmp  %g1, 0
a0075e44:  92 04 a0 41  add  %l2, 0x41, %o1
a0075e48:  82 03 40 0d  add  %o5, %o5, %g1
a0075e4c:  93 2a 60 18  sll  %o1, 0x18, %o1
a0075e50:  11 28 01 9b  sethi  %hi(0xa0066c00), %o0
a0075e54:  82 00 40 0d  add  %g1, %o5, %g1
a0075e58:  90 12 21 10  or  %o0, 0x110, %o0
a0075e5c:  93 3a 60 18  sra  %o1, 0x18, %o1
a0075e60:  94 10 00 0f  mov  %o7, %o2
a0075e64:  98 03 00 01  add  %o4, %g1, %o4
a0075e68:  02 80 00 04  be  0xa0075e78
a0075e6c:  96 10 00 0d  mov  %o5, %o3
a0075e70:  10 80 00 03  b  0xa0075e7c
a0075e74:  80 a3 60 04  cmp  %o5, 4
a0075e78:  80 a3 60 06  cmp  %o5, 6
a0075e7c:  08 bf ff c9  bleu  0xa0075da0
a0075e80:  c2 07 62 34  ld  [ %i5 + 0x234 ], %g1
a0075e84:  a0 0c a0 ff  and  %l2, 0xff, %l0
a0075e88:  82 04 00 10  add  %l0, %l0, %g1
a0075e8c:  82 00 40 10  add  %g1, %l0, %g1
a0075e90:  9a 14 e0 c4  or  %l3, 0xc4, %o5
a0075e94:  83 28 60 02  sll  %g1, 2, %g1
a0075e98:  82 00 40 0d  add  %g1, %o5, %g1
a0075e9c:  c2 08 60 08  ldub  [ %g1 + 8 ], %g1
a0075ea0:  80 a0 60 00  cmp  %g1, 0
a0075ea4:  12 80 00 03  bne  0xa0075eb0
a0075ea8:  b0 10 20 04  mov  4, %i0
a0075eac:  b0 10 20 06  mov  6, %i0
a0075eb0:  80 8e 20 ff  btst  0xff, %i0
a0075eb4:  02 80 00 2d  be  0xa0075f68
a0075eb8:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a0075ebc:  a6 10 61 f0  or  %g1, 0x1f0, %l3	! 0xa807a9f0
a0075ec0:  82 5c 28 98  smul  %l0, 0x898, %g1
a0075ec4:  82 00 40 13  add  %g1, %l3, %g1
a0075ec8:  98 0e 60 ff  and  %i1, 0xff, %o4
a0075ecc:  96 0e 20 ff  and  %i0, 0xff, %o3
a0075ed0:  9e 00 40 0c  add  %g1, %o4, %o7
a0075ed4:  82 02 c0 0b  add  %o3, %o3, %g1
a0075ed8:  82 00 40 0b  add  %g1, %o3, %g1
a0075edc:  9a 5c 22 26  smul  %l0, 0x226, %o5
a0075ee0:  a2 03 40 01  add  %o5, %g1, %l1
a0075ee4:  92 04 a0 41  add  %l2, 0x41, %o1
a0075ee8:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a0075eec:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a0075ef0:  93 2a 60 18  sll  %o1, 0x18, %o1
a0075ef4:  11 28 01 9b  sethi  %hi(0xa0066c00), %o0
a0075ef8:  80 88 60 02  btst  2, %g1
a0075efc:  90 12 21 48  or  %o0, 0x148, %o0
a0075f00:  93 3a 60 18  sra  %o1, 0x18, %o1
a0075f04:  02 80 00 0d  be  0xa0075f38
a0075f08:  94 10 00 0c  mov  %o4, %o2
a0075f0c:  da 0b e8 90  ldub  [ %o7 + 0x890 ], %o5
a0075f10:  83 2b 60 02  sll  %o5, 2, %g1
a0075f14:  82 00 40 0d  add  %g1, %o5, %g1
a0075f18:  83 28 60 02  sll  %g1, 2, %g1
a0075f1c:  82 00 40 0d  add  %g1, %o5, %g1
a0075f20:  82 04 40 01  add  %l1, %g1, %g1
a0075f24:  82 00 40 0c  add  %g1, %o4, %g1
a0075f28:  83 28 60 02  sll  %g1, 2, %g1
a0075f2c:  82 00 40 13  add  %g1, %l3, %g1
a0075f30:  7f ff f4 45  call  0xa0073044
a0075f34:  d8 00 66 68  ld  [ %g1 + 0x668 ], %o4
a0075f38:  9a 0e 20 ff  and  %i0, 0xff, %o5
a0075f3c:  82 03 40 0d  add  %o5, %o5, %g1
a0075f40:  82 00 40 0d  add  %g1, %o5, %g1
a0075f44:  9a 0e 60 ff  and  %i1, 0xff, %o5
a0075f48:  82 00 40 0d  add  %g1, %o5, %g1
a0075f4c:  83 28 60 02  sll  %g1, 2, %g1
a0075f50:  c2 05 40 01  ld  [ %l5 + %g1 ], %g1
a0075f54:  80 a0 60 0f  cmp  %g1, 0xf
a0075f58:  28 80 00 04  bleu,a   0xa0075f68
a0075f5c:  ae 10 00 18  mov  %i0, %l7
a0075f60:  10 bf ff d4  b  0xa0075eb0
a0075f64:  b0 06 3f ff  add  %i0, -1, %i0
a0075f68:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a0075f6c:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a0075f70:  80 88 60 02  btst  2, %g1
a0075f74:  02 80 00 0b  be  0xa0075fa0
a0075f78:  96 0d 20 ff  and  %l4, 0xff, %o3
a0075f7c:  92 04 a0 41  add  %l2, 0x41, %o1
a0075f80:  93 2a 60 18  sll  %o1, 0x18, %o1
a0075f84:  11 28 01 9b  sethi  %hi(0xa0066c00), %o0
a0075f88:  90 12 21 80  or  %o0, 0x180, %o0	! 0xa0066d80
a0075f8c:  93 3a 60 18  sra  %o1, 0x18, %o1
a0075f90:  94 0e 60 ff  and  %i1, 0xff, %o2
a0075f94:  7f ff f4 2c  call  0xa0073044
a0075f98:  98 0d e0 ff  and  %l7, 0xff, %o4
a0075f9c:  96 0d 20 ff  and  %l4, 0xff, %o3
a0075fa0:  9a 0d e0 ff  and  %l7, 0xff, %o5
a0075fa4:  da 0d 80 0d  ldub  [ %l6 + %o5 ], %o5
a0075fa8:  d6 0d 80 0b  ldub  [ %l6 + %o3 ], %o3
a0075fac:  98 0c a0 ff  and  %l2, 0xff, %o4
a0075fb0:  94 0e 60 ff  and  %i1, 0xff, %o2
a0075fb4:  82 5b 22 26  smul  %o4, 0x226, %g1
a0075fb8:  96 02 c0 0d  add  %o3, %o5, %o3
a0075fbc:  82 00 40 0a  add  %g1, %o2, %g1
a0075fc0:  1b 2a 01 ea  sethi  %hi(0xa807a800), %o5
a0075fc4:  9a 13 61 f0  or  %o5, 0x1f0, %o5	! 0xa807a9f0
a0075fc8:  83 28 60 02  sll  %g1, 2, %g1
a0075fcc:  82 00 40 0d  add  %g1, %o5, %g1
a0075fd0:  98 5b 28 98  smul  %o4, 0x898, %o4
a0075fd4:  97 3a e0 01  sra  %o3, 1, %o3
a0075fd8:  f8 30 68 86  sth  %i4, [ %g1 + 0x886 ]
a0075fdc:  d6 28 68 84  stb  %o3, [ %g1 + 0x884 ]
a0075fe0:  98 03 00 0d  add  %o4, %o5, %o4
a0075fe4:  98 03 00 0a  add  %o4, %o2, %o4
a0075fe8:  82 10 20 01  mov  1, %g1
a0075fec:  c2 2b 20 34  stb  %g1, [ %o4 + 0x34 ]
a0075ff0:  b0 10 20 01  mov  1, %i0
a0075ff4:  81 c7 e0 08  ret
a0075ff8:  81 e8 00 00  restore
