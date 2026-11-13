# leon2s CONV2HDMITX_UpdatePacket 0xa00a9870-0xa00a9c4c (988 bytes)
a00a9870:  9d e3 bf 58  save  %sp, -168, %sp
a00a9874:  a4 07 bf d8  add  %fp, -40, %l2
a00a9878:  92 10 20 00  clr  %o1
a00a987c:  94 10 20 1f  mov  0x1f, %o2
a00a9880:  40 00 1f 4b  call  0xa00b15ac
a00a9884:  90 10 00 12  mov  %l2, %o0
a00a9888:  a6 07 bf c8  add  %fp, -56, %l3
a00a988c:  92 10 20 00  clr  %o1
a00a9890:  94 10 20 0e  mov  0xe, %o2
a00a9894:  40 00 1f 46  call  0xa00b15ac
a00a9898:  90 10 00 13  mov  %l3, %o0
a00a989c:  ac 07 bf b8  add  %fp, -72, %l6
a00a98a0:  90 10 00 16  mov  %l6, %o0
a00a98a4:  92 10 20 00  clr  %o1
a00a98a8:  40 00 1f 41  call  0xa00b15ac
a00a98ac:  94 10 20 0e  mov  0xe, %o2
a00a98b0:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00a98b4:  80 a6 60 71  cmp  %i1, 0x71
a00a98b8:  02 80 00 07  be  0xa00a98d4
a00a98bc:  aa 10 20 00  clr  %l5
a00a98c0:  80 a6 60 81  cmp  %i1, 0x81
a00a98c4:  12 80 00 05  bne  0xa00a98d8
a00a98c8:  80 a6 60 51  cmp  %i1, 0x51
a00a98cc:  10 80 00 22  b  0xa00a9954
a00a98d0:  aa 10 20 01  mov  1, %l5
a00a98d4:  80 a6 60 51  cmp  %i1, 0x51
a00a98d8:  02 80 00 14  be  0xa00a9928
a00a98dc:  80 a6 60 51  cmp  %i1, 0x51
a00a98e0:  14 80 00 06  bg  0xa00a98f8
a00a98e4:  80 a6 60 71  cmp  %i1, 0x71
a00a98e8:  80 a6 60 31  cmp  %i1, 0x31
a00a98ec:  02 80 00 0f  be  0xa00a9928
a00a98f0:  80 a6 60 41  cmp  %i1, 0x41
a00a98f4:  30 80 00 06  b,a   0xa00a990c
a00a98f8:  02 80 00 17  be  0xa00a9954
a00a98fc:  80 a6 60 71  cmp  %i1, 0x71
a00a9900:  14 80 00 06  bg  0xa00a9918
a00a9904:  80 a6 60 81  cmp  %i1, 0x81
a00a9908:  80 a6 60 61  cmp  %i1, 0x61
a00a990c:  02 80 00 07  be  0xa00a9928
a00a9910:  11 28 01 b1  sethi  %hi(0xa006c400), %o0
a00a9914:  30 80 00 c9  b,a   0xa00a9c38
a00a9918:  02 80 00 10  be  0xa00a9958
a00a991c:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00a9920:  10 80 00 c6  b  0xa00a9c38
a00a9924:  11 28 01 b1  sethi  %hi(0xa006c400), %o0
a00a9928:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00a992c:  90 10 00 10  mov  %l0, %o0
a00a9930:  7f ff a5 cc  call  0xa0093060
a00a9934:  92 10 20 00  clr  %o1
a00a9938:  90 10 00 10  mov  %l0, %o0
a00a993c:  7f ff a3 33  call  0xa0092608
a00a9940:  92 10 20 00  clr  %o1
a00a9944:  90 10 00 10  mov  %l0, %o0
a00a9948:  7f ff a3 71  call  0xa009270c
a00a994c:  92 10 20 00  clr  %o1
a00a9950:  30 80 00 bc  b,a   0xa00a9c40
a00a9954:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00a9958:  82 04 00 10  add  %l0, %l0, %g1
a00a995c:  82 00 40 10  add  %g1, %l0, %g1
a00a9960:  29 2a 01 e4  sethi  %hi(0xa8079000), %l4
a00a9964:  9a 15 22 90  or  %l4, 0x290, %o5	! 0xa8079290
a00a9968:  a2 0d 60 ff  and  %l5, 0xff, %l1
a00a996c:  83 28 60 02  sll  %g1, 2, %g1
a00a9970:  b2 00 40 0d  add  %g1, %o5, %i1
a00a9974:  40 00 1a 65  call  0xa00b0308
a00a9978:  90 10 00 11  mov  %l1, %o0
a00a997c:  c2 0e 60 0d  ldub  [ %i1 + 0xd ], %g1
a00a9980:  90 12 00 01  or  %o0, %g1, %o0
a00a9984:  d0 2e 60 0d  stb  %o0, [ %i1 + 0xd ]
a00a9988:  40 00 1a 67  call  0xa00b0324
a00a998c:  90 10 00 11  mov  %l1, %o0
a00a9990:  d0 2e 60 0c  stb  %o0, [ %i1 + 0xc ]
a00a9994:  40 00 1a 6b  call  0xa00b0340
a00a9998:  90 10 00 11  mov  %l1, %o0
a00a999c:  d0 2e 60 0e  stb  %o0, [ %i1 + 0xe ]
a00a99a0:  40 00 1a 3f  call  0xa00b029c
a00a99a4:  90 10 00 11  mov  %l1, %o0
a00a99a8:  c2 0e 60 07  ldub  [ %i1 + 7 ], %g1
a00a99ac:  90 12 00 01  or  %o0, %g1, %o0
a00a99b0:  d0 2e 60 07  stb  %o0, [ %i1 + 7 ]
a00a99b4:  40 00 1a 41  call  0xa00b02b8
a00a99b8:  90 10 00 11  mov  %l1, %o0
a00a99bc:  d0 2e 60 06  stb  %o0, [ %i1 + 6 ]
a00a99c0:  40 00 1a 45  call  0xa00b02d4
a00a99c4:  90 10 00 11  mov  %l1, %o0
a00a99c8:  d0 2e 60 08  stb  %o0, [ %i1 + 8 ]
a00a99cc:  40 00 1a 1f  call  0xa00b0248
a00a99d0:  90 10 00 11  mov  %l1, %o0
a00a99d4:  c2 0e 60 10  ldub  [ %i1 + 0x10 ], %g1
a00a99d8:  90 12 00 01  or  %o0, %g1, %o0
a00a99dc:  d0 2e 60 10  stb  %o0, [ %i1 + 0x10 ]
a00a99e0:  40 00 1a 21  call  0xa00b0264
a00a99e4:  90 10 00 11  mov  %l1, %o0
a00a99e8:  d0 2e 60 0f  stb  %o0, [ %i1 + 0xf ]
a00a99ec:  40 00 1a 25  call  0xa00b0280
a00a99f0:  90 10 00 11  mov  %l1, %o0
a00a99f4:  c2 0e 60 08  ldub  [ %i1 + 8 ], %g1
a00a99f8:  80 a0 60 00  cmp  %g1, 0
a00a99fc:  12 80 00 13  bne  0xa00a9a48
a00a9a00:  d0 2e 60 11  stb  %o0, [ %i1 + 0x11 ]
a00a9a04:  c2 0e 60 06  ldub  [ %i1 + 6 ], %g1
a00a9a08:  80 a0 60 01  cmp  %g1, 1
a00a9a0c:  12 80 00 10  bne  0xa00a9a4c
a00a9a10:  82 04 00 10  add  %l0, %l0, %g1
a00a9a14:  c2 0e 60 07  ldub  [ %i1 + 7 ], %g1
a00a9a18:  80 a0 60 01  cmp  %g1, 1
a00a9a1c:  12 80 00 0c  bne  0xa00a9a4c
a00a9a20:  82 04 00 10  add  %l0, %l0, %g1
a00a9a24:  40 00 1a 33  call  0xa00b02f0
a00a9a28:  90 10 00 11  mov  %l1, %o0
a00a9a2c:  7f ff fd 26  call  0xa00a8ec4
a00a9a30:  92 10 00 12  mov  %l2, %o1
a00a9a34:  90 10 00 10  mov  %l0, %o0
a00a9a38:  7f ff a3 2a  call  0xa00926e0
a00a9a3c:  92 10 00 12  mov  %l2, %o1
a00a9a40:  10 80 00 13  b  0xa00a9a8c
a00a9a44:  c0 2e 60 07  clrb  [ %i1 + 7 ]
a00a9a48:  82 04 00 10  add  %l0, %l0, %g1
a00a9a4c:  82 00 40 10  add  %g1, %l0, %g1
a00a9a50:  83 28 60 02  sll  %g1, 2, %g1
a00a9a54:  9a 15 22 90  or  %l4, 0x290, %o5
a00a9a58:  b2 00 40 0d  add  %g1, %o5, %i1
a00a9a5c:  c2 0e 60 08  ldub  [ %i1 + 8 ], %g1
a00a9a60:  80 a0 60 00  cmp  %g1, 0
a00a9a64:  32 80 00 0b  bne,a   0xa00a9a90
a00a9a68:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00a9a6c:  c2 0e 60 06  ldub  [ %i1 + 6 ], %g1
a00a9a70:  80 a0 60 00  cmp  %g1, 0
a00a9a74:  32 80 00 07  bne,a   0xa00a9a90
a00a9a78:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00a9a7c:  90 10 00 10  mov  %l0, %o0
a00a9a80:  7f ff a2 e2  call  0xa0092608
a00a9a84:  92 10 20 00  clr  %o1
a00a9a88:  c0 2e 60 07  clrb  [ %i1 + 7 ]
a00a9a8c:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00a9a90:  82 04 00 10  add  %l0, %l0, %g1
a00a9a94:  82 00 40 10  add  %g1, %l0, %g1
a00a9a98:  19 2a 01 e4  sethi  %hi(0xa8079000), %o4
a00a9a9c:  83 28 60 02  sll  %g1, 2, %g1
a00a9aa0:  9a 13 22 90  or  %o4, 0x290, %o5
a00a9aa4:  b2 00 40 0d  add  %g1, %o5, %i1
a00a9aa8:  c2 0e 60 0e  ldub  [ %i1 + 0xe ], %g1
a00a9aac:  80 a0 60 00  cmp  %g1, 0
a00a9ab0:  12 80 00 13  bne  0xa00a9afc
a00a9ab4:  82 04 00 10  add  %l0, %l0, %g1
a00a9ab8:  c2 0e 60 0c  ldub  [ %i1 + 0xc ], %g1
a00a9abc:  80 a0 60 01  cmp  %g1, 1
a00a9ac0:  12 80 00 0f  bne  0xa00a9afc
a00a9ac4:  82 04 00 10  add  %l0, %l0, %g1
a00a9ac8:  c2 0e 60 0d  ldub  [ %i1 + 0xd ], %g1
a00a9acc:  80 a0 60 01  cmp  %g1, 1
a00a9ad0:  12 80 00 0b  bne  0xa00a9afc
a00a9ad4:  82 04 00 10  add  %l0, %l0, %g1
a00a9ad8:  40 00 1a 21  call  0xa00b035c
a00a9adc:  90 10 00 11  mov  %l1, %o0
a00a9ae0:  7f ff fd 12  call  0xa00a8f28
a00a9ae4:  92 10 00 13  mov  %l3, %o1
a00a9ae8:  90 10 00 10  mov  %l0, %o0
a00a9aec:  7f ff a5 93  call  0xa0093138
a00a9af0:  92 10 00 13  mov  %l3, %o1
a00a9af4:  10 80 00 23  b  0xa00a9b80
a00a9af8:  c0 2e 60 0d  clrb  [ %i1 + 0xd ]
a00a9afc:  82 00 40 10  add  %g1, %l0, %g1
a00a9b00:  83 28 60 02  sll  %g1, 2, %g1
a00a9b04:  9a 13 22 90  or  %o4, 0x290, %o5
a00a9b08:  b2 00 40 0d  add  %g1, %o5, %i1
a00a9b0c:  c2 0e 60 0e  ldub  [ %i1 + 0xe ], %g1
a00a9b10:  80 a0 60 00  cmp  %g1, 0
a00a9b14:  12 80 00 0b  bne  0xa00a9b40
a00a9b18:  82 04 00 10  add  %l0, %l0, %g1
a00a9b1c:  c2 0e 60 0c  ldub  [ %i1 + 0xc ], %g1
a00a9b20:  80 a0 60 00  cmp  %g1, 0
a00a9b24:  12 80 00 07  bne  0xa00a9b40
a00a9b28:  82 04 00 10  add  %l0, %l0, %g1
a00a9b2c:  90 10 00 10  mov  %l0, %o0
a00a9b30:  7f ff a5 4c  call  0xa0093060
a00a9b34:  92 10 20 00  clr  %o1
a00a9b38:  10 80 00 12  b  0xa00a9b80
a00a9b3c:  c0 2e 60 0d  clrb  [ %i1 + 0xd ]
a00a9b40:  82 00 40 10  add  %g1, %l0, %g1
a00a9b44:  83 28 60 02  sll  %g1, 2, %g1
a00a9b48:  9a 13 22 90  or  %o4, 0x290, %o5
a00a9b4c:  b2 00 40 0d  add  %g1, %o5, %i1
a00a9b50:  c2 0e 60 11  ldub  [ %i1 + 0x11 ], %g1
a00a9b54:  80 a0 60 00  cmp  %g1, 0
a00a9b58:  32 80 00 0b  bne,a   0xa00a9b84
a00a9b5c:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00a9b60:  c2 0e 60 0f  ldub  [ %i1 + 0xf ], %g1
a00a9b64:  80 a0 60 00  cmp  %g1, 0
a00a9b68:  32 80 00 07  bne,a   0xa00a9b84
a00a9b6c:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00a9b70:  90 10 00 10  mov  %l0, %o0
a00a9b74:  7f ff a2 e6  call  0xa009270c
a00a9b78:  92 10 20 00  clr  %o1
a00a9b7c:  c0 2e 60 10  clrb  [ %i1 + 0x10 ]
a00a9b80:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00a9b84:  82 04 00 10  add  %l0, %l0, %g1
a00a9b88:  82 00 40 10  add  %g1, %l0, %g1
a00a9b8c:  19 2a 01 e4  sethi  %hi(0xa8079000), %o4
a00a9b90:  83 28 60 02  sll  %g1, 2, %g1
a00a9b94:  9a 13 22 90  or  %o4, 0x290, %o5
a00a9b98:  b2 00 40 0d  add  %g1, %o5, %i1
a00a9b9c:  c2 0e 60 0b  ldub  [ %i1 + 0xb ], %g1
a00a9ba0:  80 a0 60 00  cmp  %g1, 0
a00a9ba4:  12 80 00 0f  bne  0xa00a9be0
a00a9ba8:  82 04 00 10  add  %l0, %l0, %g1
a00a9bac:  c2 0e 60 09  ldub  [ %i1 + 9 ], %g1
a00a9bb0:  80 a0 60 01  cmp  %g1, 1
a00a9bb4:  12 80 00 0b  bne  0xa00a9be0
a00a9bb8:  82 04 00 10  add  %l0, %l0, %g1
a00a9bbc:  c2 0e 60 0a  ldub  [ %i1 + 0xa ], %g1
a00a9bc0:  80 a0 60 01  cmp  %g1, 1
a00a9bc4:  12 80 00 07  bne  0xa00a9be0
a00a9bc8:  82 04 00 10  add  %l0, %l0, %g1
a00a9bcc:  90 10 00 10  mov  %l0, %o0
a00a9bd0:  7f ff a3 30  call  0xa0092890
a00a9bd4:  92 10 20 00  clr  %o1
a00a9bd8:  10 80 00 1a  b  0xa00a9c40
a00a9bdc:  c0 2e 60 0a  clrb  [ %i1 + 0xa ]
a00a9be0:  82 00 40 10  add  %g1, %l0, %g1
a00a9be4:  83 28 60 02  sll  %g1, 2, %g1
a00a9be8:  9a 13 22 90  or  %o4, 0x290, %o5
a00a9bec:  b2 00 40 0d  add  %g1, %o5, %i1
a00a9bf0:  c2 0e 60 0b  ldub  [ %i1 + 0xb ], %g1
a00a9bf4:  80 a0 60 00  cmp  %g1, 0
a00a9bf8:  12 80 00 12  bne  0xa00a9c40
a00a9bfc:  01 00 00 00  nop
a00a9c00:  c2 0e 60 09  ldub  [ %i1 + 9 ], %g1
a00a9c04:  80 a0 60 00  cmp  %g1, 0
a00a9c08:  12 80 00 0e  bne  0xa00a9c40
a00a9c0c:  01 00 00 00  nop
a00a9c10:  40 00 1a 1f  call  0xa00b048c
a00a9c14:  90 0d 60 01  and  %l5, 1, %o0
a00a9c18:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a9c1c:  7f ff fd d9  call  0xa00a9380
a00a9c20:  92 10 00 16  mov  %l6, %o1
a00a9c24:  90 10 00 10  mov  %l0, %o0
a00a9c28:  7f ff a5 03  call  0xa0093034
a00a9c2c:  92 10 00 16  mov  %l6, %o1
a00a9c30:  10 80 00 04  b  0xa00a9c40
a00a9c34:  c0 2e 60 0a  clrb  [ %i1 + 0xa ]
a00a9c38:  7f ff 26 23  call  0xa00734c4
a00a9c3c:  90 12 20 10  or  %o0, 0x10, %o0
a00a9c40:  01 00 00 00  nop
a00a9c44:  81 c7 e0 08  ret
a00a9c48:  81 e8 00 00  restore
