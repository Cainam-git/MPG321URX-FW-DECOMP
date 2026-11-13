# leon2s FUN_a00a4880 0xa00a4880-0xa00a4e68 (1512 bytes)
a00a4880:  9d e3 bf 90  save  %sp, -112, %sp
a00a4884:  25 2a 01 e1  sethi  %hi(0xa8078400), %l2
a00a4888:  c2 0c a3 48  ldub  [ %l2 + 0x348 ], %g1	! 0xa8078748
a00a488c:  80 a0 60 01  cmp  %g1, 1
a00a4890:  12 80 00 07  bne  0xa00a48ac
a00a4894:  2b 2a 01 f7  sethi  %hi(0xa807dc00), %l5
a00a4898:  9a 0e 20 ff  and  %i0, 0xff, %o5
a00a489c:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00a48a0:  9b 2b 60 03  sll  %o5, 3, %o5
a00a48a4:  82 10 60 10  or  %g1, 0x10, %g1
a00a48a8:  c0 20 40 0d  clr  [ %g1 + %o5 ]
a00a48ac:  a2 0e 20 ff  and  %i0, 0xff, %l1
a00a48b0:  9a 15 60 10  or  %l5, 0x10, %o5
a00a48b4:  83 2c 60 03  sll  %l1, 3, %g1
a00a48b8:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a00a48bc:  80 a0 60 04  cmp  %g1, 4
a00a48c0:  18 80 01 68  bgu  0xa00a4e60
a00a48c4:  1b 28 02 92  sethi  %hi(0xa00a4800), %o5
a00a48c8:  83 28 60 02  sll  %g1, 2, %g1
a00a48cc:  9a 13 60 6c  or  %o5, 0x6c, %o5
a00a48d0:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a00a48d4:  81 c0 40 00  jmp  %g1
a00a48d8:  21 2a 01 e4  sethi  %hi(0xa8079000), %l0
a00a48dc:  40 00 06 2d  call  0xa00a6190
a00a48e0:  d0 0c 22 28  ldub  [ %l0 + 0x228 ], %o0	! 0xa8079228
a00a48e4:  80 8a 20 ff  btst  0xff, %o0
a00a48e8:  02 80 00 0b  be  0xa00a4914
a00a48ec:  d0 0c 22 28  ldub  [ %l0 + 0x228 ], %o0
a00a48f0:  40 00 06 4b  call  0xa00a621c
a00a48f4:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a48f8:  80 8a 20 ff  btst  0xff, %o0
a00a48fc:  12 80 01 59  bne  0xa00a4e60
a00a4900:  98 15 60 10  or  %l5, 0x10, %o4
a00a4904:  9b 2c 60 03  sll  %l1, 3, %o5
a00a4908:  82 10 20 01  mov  1, %g1
a00a490c:  10 80 00 1c  b  0xa00a497c
a00a4910:  c2 23 00 0d  st  %g1, [ %o4 + %o5 ]
a00a4914:  40 00 06 30  call  0xa00a61d4
a00a4918:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a491c:  80 8a 20 ff  btst  0xff, %o0
a00a4920:  02 80 00 99  be  0xa00a4b84
a00a4924:  9a 15 60 10  or  %l5, 0x10, %o5
a00a4928:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a492c:  c2 08 62 28  ldub  [ %g1 + 0x228 ], %g1	! 0xa8079228
a00a4930:  80 a0 60 71  cmp  %g1, 0x71
a00a4934:  02 80 00 05  be  0xa00a4948
a00a4938:  90 10 20 00  clr  %o0
a00a493c:  80 a0 60 81  cmp  %g1, 0x81
a00a4940:  12 80 00 07  bne  0xa00a495c
a00a4944:  90 10 20 01  mov  1, %o0
a00a4948:  40 00 2d 5c  call  0xa00afeb8
a00a494c:  92 10 20 01  mov  1, %o1
a00a4950:  9a 10 20 01  mov  1, %o5
a00a4954:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a4958:  da 20 62 30  st  %o5, [ %g1 + 0x230 ]	! 0xa8079230
a00a495c:  40 00 35 c2  call  0xa00b2064
a00a4960:  01 00 00 00  nop
a00a4964:  82 10 20 04  mov  4, %g1	! 0x4
a00a4968:  98 15 60 10  or  %l5, 0x10, %o4
a00a496c:  9b 2c 60 03  sll  %l1, 3, %o5
a00a4970:  c2 23 00 0d  st  %g1, [ %o4 + %o5 ]
a00a4974:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a4978:  d0 20 62 2c  st  %o0, [ %g1 + 0x22c ]	! 0xa807922c
a00a497c:  10 80 01 39  b  0xa00a4e60
a00a4980:  c0 2c a3 48  clrb  [ %l2 + 0x348 ]
a00a4984:  40 00 06 03  call  0xa00a6190
a00a4988:  d0 0c 22 28  ldub  [ %l0 + 0x228 ], %o0
a00a498c:  80 8a 20 ff  btst  0xff, %o0
a00a4990:  02 80 00 7d  be  0xa00a4b84
a00a4994:  9a 15 60 10  or  %l5, 0x10, %o5
a00a4998:  40 00 06 21  call  0xa00a621c
a00a499c:  d0 0c 22 28  ldub  [ %l0 + 0x228 ], %o0
a00a49a0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a49a4:  80 a2 20 01  cmp  %o0, 1
a00a49a8:  12 80 00 05  bne  0xa00a49bc
a00a49ac:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a49b0:  9a 15 60 10  or  %l5, 0x10, %o5
a00a49b4:  83 2c 60 03  sll  %l1, 3, %g1
a00a49b8:  c0 23 40 01  clr  [ %o5 + %g1 ]
a00a49bc:  82 06 00 18  add  %i0, %i0, %g1
a00a49c0:  82 00 40 18  add  %g1, %i0, %g1
a00a49c4:  1b 2a 01 f7  sethi  %hi(0xa807dc00), %o5
a00a49c8:  83 28 60 02  sll  %g1, 2, %g1
a00a49cc:  9a 13 60 04  or  %o5, 4, %o5
a00a49d0:  82 00 40 0d  add  %g1, %o5, %g1
a00a49d4:  c2 00 60 04  ld  [ %g1 + 4 ], %g1
a00a49d8:  c2 00 40 00  ld  [ %g1 ], %g1
a00a49dc:  80 a0 60 00  cmp  %g1, 0
a00a49e0:  12 80 00 08  bne  0xa00a4a00
a00a49e4:  01 00 00 00  nop
a00a49e8:  40 00 05 b1  call  0xa00a60ac
a00a49ec:  90 10 00 18  mov  %i0, %o0
a00a49f0:  99 2e 20 03  sll  %i0, 3, %o4
a00a49f4:  80 a2 20 00  cmp  %o0, 0
a00a49f8:  02 80 00 18  be  0xa00a4a58
a00a49fc:  9a 10 20 01  mov  1, %o5
a00a4a00:  40 00 05 b6  call  0xa00a60d8
a00a4a04:  90 10 00 18  mov  %i0, %o0
a00a4a08:  40 00 05 c2  call  0xa00a6110
a00a4a0c:  90 10 00 18  mov  %i0, %o0
a00a4a10:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a4a14:  82 10 62 88  or  %g1, 0x288, %g1	! 0xa8079288
a00a4a18:  40 00 35 93  call  0xa00b2064
a00a4a1c:  d0 28 40 18  stb  %o0, [ %g1 + %i0 ]
a00a4a20:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a4a24:  99 2e 20 02  sll  %i0, 2, %o4
a00a4a28:  82 10 62 34  or  %g1, 0x234, %g1
a00a4a2c:  d0 20 40 0c  st  %o0, [ %g1 + %o4 ]
a00a4a30:  9a 03 00 18  add  %o4, %i0, %o5
a00a4a34:  11 2a 01 e4  sethi  %hi(0xa8079000), %o0
a00a4a38:  9b 2b 60 04  sll  %o5, 4, %o5
a00a4a3c:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a4a40:  90 12 22 38  or  %o0, 0x238, %o0
a00a4a44:  90 03 40 08  add  %o5, %o0, %o0
a00a4a48:  40 00 06 58  call  0xa00a63a8
a00a4a4c:  d2 08 62 28  ldub  [ %g1 + 0x228 ], %o1
a00a4a50:  99 2e 20 03  sll  %i0, 3, %o4
a00a4a54:  9a 10 20 02  mov  2, %o5
a00a4a58:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00a4a5c:  82 10 60 10  or  %g1, 0x10, %g1	! 0xa807dc10
a00a4a60:  10 80 01 00  b  0xa00a4e60
a00a4a64:  da 20 40 0c  st  %o5, [ %g1 + %o4 ]
a00a4a68:  40 00 05 ca  call  0xa00a6190
a00a4a6c:  d0 0c 22 28  ldub  [ %l0 + 0x228 ], %o0
a00a4a70:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a4a74:  80 a2 20 01  cmp  %o0, 1
a00a4a78:  12 80 00 43  bne  0xa00a4b84
a00a4a7c:  9a 15 60 10  or  %l5, 0x10, %o5
a00a4a80:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a4a84:  40 00 05 e6  call  0xa00a621c
a00a4a88:  d0 08 62 28  ldub  [ %g1 + 0x228 ], %o0	! 0xa8079228
a00a4a8c:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a4a90:  80 a2 20 01  cmp  %o0, 1
a00a4a94:  02 80 00 3c  be  0xa00a4b84
a00a4a98:  9a 15 60 10  or  %l5, 0x10, %o5
a00a4a9c:  40 00 35 72  call  0xa00b2064
a00a4aa0:  01 00 00 00  nop
a00a4aa4:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a4aa8:  9b 2c 60 02  sll  %l1, 2, %o5
a00a4aac:  82 10 62 34  or  %g1, 0x234, %g1
a00a4ab0:  c2 00 40 0d  ld  [ %g1 + %o5 ], %g1
a00a4ab4:  90 22 00 01  sub  %o0, %g1, %o0
a00a4ab8:  80 a2 20 28  cmp  %o0, 0x28
a00a4abc:  08 80 00 e9  bleu  0xa00a4e60
a00a4ac0:  82 03 40 11  add  %o5, %l1, %g1
a00a4ac4:  13 2a 01 e4  sethi  %hi(0xa8079000), %o1
a00a4ac8:  83 28 60 04  sll  %g1, 4, %g1
a00a4acc:  92 12 62 38  or  %o1, 0x238, %o1
a00a4ad0:  92 00 40 09  add  %g1, %o1, %o1
a00a4ad4:  94 10 20 00  clr  %o2
a00a4ad8:  90 10 00 11  mov  %l1, %o0
a00a4adc:  40 00 02 35  call  0xa00a53b0
a00a4ae0:  21 33 c0 b7  sethi  %hi(0xcf02dc00), %l0
a00a4ae4:  a0 14 20 10  or  %l0, 0x10, %l0	! 0xcf02dc10
a00a4ae8:  c2 04 00 00  ld  [ %l0 ], %g1
a00a4aec:  82 10 60 01  or  %g1, 1, %g1
a00a4af0:  c2 24 00 00  st  %g1, [ %l0 ]
a00a4af4:  40 00 32 c6  call  0xa00b160c
a00a4af8:  90 10 20 64  mov  0x64, %o0
a00a4afc:  c2 04 00 00  ld  [ %l0 ], %g1
a00a4b00:  82 08 7f fe  and  %g1, -2, %g1
a00a4b04:  c2 24 00 00  st  %g1, [ %l0 ]
a00a4b08:  94 15 60 10  or  %l5, 0x10, %o2
a00a4b0c:  97 2c 60 03  sll  %l1, 3, %o3
a00a4b10:  98 02 c0 0a  add  %o3, %o2, %o4
a00a4b14:  82 10 20 03  mov  3, %g1
a00a4b18:  c2 2b 20 04  stb  %g1, [ %o4 + 4 ]
a00a4b1c:  9a 04 40 11  add  %l1, %l1, %o5
a00a4b20:  9a 03 40 11  add  %o5, %l1, %o5
a00a4b24:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00a4b28:  9b 2b 60 02  sll  %o5, 2, %o5
a00a4b2c:  82 10 60 04  or  %g1, 4, %g1
a00a4b30:  d8 00 40 0d  ld  [ %g1 + %o5 ], %o4
a00a4b34:  c2 03 20 b4  ld  [ %o4 + 0xb4 ], %g1
a00a4b38:  82 10 60 02  or  %g1, 2, %g1
a00a4b3c:  9a 10 20 03  mov  3, %o5
a00a4b40:  da 22 80 0b  st  %o5, [ %o2 + %o3 ]
a00a4b44:  c2 23 20 b4  st  %g1, [ %o4 + 0xb4 ]
a00a4b48:  30 80 00 c6  b,a   0xa00a4e60
a00a4b4c:  40 00 05 91  call  0xa00a6190
a00a4b50:  d0 0c 22 28  ldub  [ %l0 + 0x228 ], %o0
a00a4b54:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a4b58:  80 a2 20 01  cmp  %o0, 1
a00a4b5c:  12 80 00 0a  bne  0xa00a4b84
a00a4b60:  9a 15 60 10  or  %l5, 0x10, %o5
a00a4b64:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a4b68:  40 00 05 ad  call  0xa00a621c
a00a4b6c:  d0 08 62 28  ldub  [ %g1 + 0x228 ], %o0	! 0xa8079228
a00a4b70:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a4b74:  80 a2 20 01  cmp  %o0, 1
a00a4b78:  12 80 00 06  bne  0xa00a4b90
a00a4b7c:  a4 15 60 10  or  %l5, 0x10, %l2
a00a4b80:  9a 15 60 10  or  %l5, 0x10, %o5
a00a4b84:  83 2c 60 03  sll  %l1, 3, %g1
a00a4b88:  10 80 00 b6  b  0xa00a4e60
a00a4b8c:  c0 23 40 01  clr  [ %o5 + %g1 ]
a00a4b90:  a1 2c 60 03  sll  %l1, 3, %l0
a00a4b94:  98 04 00 12  add  %l0, %l2, %o4
a00a4b98:  c2 0b 20 04  ldub  [ %o4 + 4 ], %g1
a00a4b9c:  80 a0 60 00  cmp  %g1, 0
a00a4ba0:  02 80 00 16  be  0xa00a4bf8
a00a4ba4:  82 00 7f ff  add  %g1, -1, %g1
a00a4ba8:  c2 2b 20 04  stb  %g1, [ %o4 + 4 ]
a00a4bac:  9a 04 40 11  add  %l1, %l1, %o5
a00a4bb0:  9a 03 40 11  add  %o5, %l1, %o5
a00a4bb4:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00a4bb8:  9b 2b 60 02  sll  %o5, 2, %o5
a00a4bbc:  82 10 60 04  or  %g1, 4, %g1
a00a4bc0:  c2 00 40 0d  ld  [ %g1 + %o5 ], %g1
a00a4bc4:  c2 00 60 b4  ld  [ %g1 + 0xb4 ], %g1
a00a4bc8:  80 88 60 04  btst  4, %g1
a00a4bcc:  12 80 00 a5  bne  0xa00a4e60
a00a4bd0:  82 04 00 11  add  %l0, %l1, %g1
a00a4bd4:  13 2a 01 f6  sethi  %hi(0xa807d800), %o1
a00a4bd8:  83 28 60 04  sll  %g1, 4, %g1
a00a4bdc:  92 12 63 b4  or  %o1, 0x3b4, %o1
a00a4be0:  92 00 40 09  add  %g1, %o1, %o1
a00a4be4:  40 00 04 6a  call  0xa00a5d8c
a00a4be8:  90 10 00 11  mov  %l1, %o0
a00a4bec:  82 10 20 04  mov  4, %g1
a00a4bf0:  10 80 00 9c  b  0xa00a4e60
a00a4bf4:  c2 24 80 10  st  %g1, [ %l2 + %l0 ]
a00a4bf8:  92 06 20 41  add  %i0, 0x41, %o1
a00a4bfc:  93 2a 60 18  sll  %o1, 0x18, %o1
a00a4c00:  11 28 01 b0  sethi  %hi(0xa006c000), %o0
a00a4c04:  c0 24 80 10  clr  [ %l2 + %l0 ]
a00a4c08:  93 3a 60 18  sra  %o1, 0x18, %o1
a00a4c0c:  7f ff 39 0e  call  0xa0073044
a00a4c10:  90 12 20 50  or  %o0, 0x50, %o0
a00a4c14:  30 80 00 93  b,a   0xa00a4e60
a00a4c18:  40 00 05 6f  call  0xa00a61d4
a00a4c1c:  d0 0c 22 28  ldub  [ %l0 + 0x228 ], %o0
a00a4c20:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a4c24:  80 a2 20 01  cmp  %o0, 1
a00a4c28:  12 80 00 72  bne  0xa00a4df0
a00a4c2c:  27 2a 01 e4  sethi  %hi(0xa8079000), %l3
a00a4c30:  40 00 35 0d  call  0xa00b2064
a00a4c34:  01 00 00 00  nop
a00a4c38:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a4c3c:  c2 00 62 2c  ld  [ %g1 + 0x22c ], %g1	! 0xa807922c
a00a4c40:  90 22 00 01  sub  %o0, %g1, %o0
a00a4c44:  80 a2 20 14  cmp  %o0, 0x14
a00a4c48:  08 80 00 1d  bleu  0xa00a4cbc
a00a4c4c:  82 04 40 11  add  %l1, %l1, %g1
a00a4c50:  1b 2a 01 e4  sethi  %hi(0xa8079000), %o5
a00a4c54:  c2 03 62 30  ld  [ %o5 + 0x230 ], %g1	! 0xa8079230
a00a4c58:  80 a0 60 01  cmp  %g1, 1
a00a4c5c:  12 80 00 06  bne  0xa00a4c74
a00a4c60:  01 00 00 00  nop
a00a4c64:  40 00 27 eb  call  0xa00aec10
a00a4c68:  c0 23 62 30  clr  [ %o5 + 0x230 ]
a00a4c6c:  10 80 00 14  b  0xa00a4cbc
a00a4c70:  82 04 40 11  add  %l1, %l1, %g1
a00a4c74:  40 00 27 ee  call  0xa00aec2c
a00a4c78:  01 00 00 00  nop
a00a4c7c:  80 8a 20 ff  btst  0xff, %o0
a00a4c80:  02 80 00 0f  be  0xa00a4cbc
a00a4c84:  82 04 40 11  add  %l1, %l1, %g1
a00a4c88:  c2 0c e2 28  ldub  [ %l3 + 0x228 ], %g1
a00a4c8c:  92 10 20 00  clr  %o1
a00a4c90:  80 a0 60 71  cmp  %g1, 0x71
a00a4c94:  02 80 00 07  be  0xa00a4cb0
a00a4c98:  90 10 20 00  clr  %o0
a00a4c9c:  80 a0 60 81  cmp  %g1, 0x81
a00a4ca0:  12 80 00 07  bne  0xa00a4cbc
a00a4ca4:  82 04 40 11  add  %l1, %l1, %g1
a00a4ca8:  90 10 20 01  mov  1, %o0
a00a4cac:  92 10 20 00  clr  %o1
a00a4cb0:  40 00 2c 82  call  0xa00afeb8
a00a4cb4:  01 00 00 00  nop
a00a4cb8:  82 04 40 11  add  %l1, %l1, %g1
a00a4cbc:  82 00 40 11  add  %g1, %l1, %g1
a00a4cc0:  29 2a 01 f7  sethi  %hi(0xa807dc00), %l4
a00a4cc4:  a1 28 60 02  sll  %g1, 2, %l0
a00a4cc8:  a4 15 20 04  or  %l4, 4, %l2
a00a4ccc:  c2 04 80 10  ld  [ %l2 + %l0 ], %g1
a00a4cd0:  c2 00 60 c0  ld  [ %g1 + 0xc0 ], %g1
a00a4cd4:  83 30 60 0c  srl  %g1, 0xc, %g1
a00a4cd8:  80 88 60 01  btst  1, %g1
a00a4cdc:  12 80 00 24  bne  0xa00a4d6c
a00a4ce0:  c2 0c e2 28  ldub  [ %l3 + 0x228 ], %g1
a00a4ce4:  80 a0 60 71  cmp  %g1, 0x71
a00a4ce8:  12 80 00 10  bne  0xa00a4d28
a00a4cec:  80 a0 60 81  cmp  %g1, 0x81
a00a4cf0:  40 00 27 5d  call  0xa00aea64
a00a4cf4:  90 10 20 00  clr  %o0
a00a4cf8:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a4cfc:  80 a2 20 01  cmp  %o0, 1
a00a4d00:  12 80 00 09  bne  0xa00a4d24
a00a4d04:  c2 0c e2 28  ldub  [ %l3 + 0x228 ], %g1
a00a4d08:  c2 04 80 10  ld  [ %l2 + %l0 ], %g1
a00a4d0c:  da 00 60 c0  ld  [ %g1 + 0xc0 ], %o5
a00a4d10:  19 00 00 04  sethi  %hi(0x1000), %o4
a00a4d14:  9a 13 40 0c  or  %o5, %o4, %o5
a00a4d18:  da 20 60 c0  st  %o5, [ %g1 + 0xc0 ]
a00a4d1c:  10 80 00 47  b  0xa00a4e38
a00a4d20:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a4d24:  80 a0 60 81  cmp  %g1, 0x81
a00a4d28:  32 80 00 44  bne,a   0xa00a4e38
a00a4d2c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a4d30:  40 00 27 4d  call  0xa00aea64
a00a4d34:  90 10 20 01  mov  1, %o0
a00a4d38:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a4d3c:  80 a2 20 01  cmp  %o0, 1
a00a4d40:  32 80 00 3e  bne,a   0xa00a4e38
a00a4d44:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a4d48:  82 04 40 11  add  %l1, %l1, %g1
a00a4d4c:  82 00 40 11  add  %g1, %l1, %g1
a00a4d50:  9a 15 20 04  or  %l4, 4, %o5
a00a4d54:  83 28 60 02  sll  %g1, 2, %g1
a00a4d58:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a00a4d5c:  c2 03 20 c0  ld  [ %o4 + 0xc0 ], %g1
a00a4d60:  1b 00 00 04  sethi  %hi(0x1000), %o5
a00a4d64:  10 80 00 20  b  0xa00a4de4
a00a4d68:  82 10 40 0d  or  %g1, %o5, %g1
a00a4d6c:  80 a0 60 71  cmp  %g1, 0x71
a00a4d70:  12 80 00 0b  bne  0xa00a4d9c
a00a4d74:  c2 0c e2 28  ldub  [ %l3 + 0x228 ], %g1
a00a4d78:  40 00 27 3b  call  0xa00aea64
a00a4d7c:  90 10 20 00  clr  %o0
a00a4d80:  80 8a 20 ff  btst  0xff, %o0
a00a4d84:  12 80 00 06  bne  0xa00a4d9c
a00a4d88:  c2 0c e2 28  ldub  [ %l3 + 0x228 ], %g1
a00a4d8c:  03 00 00 04  sethi  %hi(0x1000), %g1
a00a4d90:  c2 27 bf f4  st  %g1, [ %fp + -12 ]
a00a4d94:  10 80 00 11  b  0xa00a4dd8
a00a4d98:  d8 04 80 10  ld  [ %l2 + %l0 ], %o4
a00a4d9c:  80 a0 60 81  cmp  %g1, 0x81
a00a4da0:  32 80 00 26  bne,a   0xa00a4e38
a00a4da4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a4da8:  40 00 27 2f  call  0xa00aea64
a00a4dac:  90 10 20 01  mov  1, %o0
a00a4db0:  80 8a 20 ff  btst  0xff, %o0
a00a4db4:  32 80 00 21  bne,a   0xa00a4e38
a00a4db8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a4dbc:  1b 00 00 04  sethi  %hi(0x1000), %o5
a00a4dc0:  82 04 40 11  add  %l1, %l1, %g1
a00a4dc4:  82 00 40 11  add  %g1, %l1, %g1
a00a4dc8:  da 27 bf f4  st  %o5, [ %fp + -12 ]
a00a4dcc:  9a 15 20 04  or  %l4, 4, %o5
a00a4dd0:  83 28 60 02  sll  %g1, 2, %g1
a00a4dd4:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a00a4dd8:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a00a4ddc:  da 03 20 c0  ld  [ %o4 + 0xc0 ], %o5
a00a4de0:  82 2b 40 01  andn  %o5, %g1, %g1
a00a4de4:  c2 23 20 c0  st  %g1, [ %o4 + 0xc0 ]
a00a4de8:  10 80 00 14  b  0xa00a4e38
a00a4dec:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a4df0:  82 04 40 11  add  %l1, %l1, %g1
a00a4df4:  82 00 40 11  add  %g1, %l1, %g1
a00a4df8:  1b 2a 01 f7  sethi  %hi(0xa807dc00), %o5
a00a4dfc:  83 28 60 02  sll  %g1, 2, %g1
a00a4e00:  9a 13 60 04  or  %o5, 4, %o5
a00a4e04:  d0 03 40 01  ld  [ %o5 + %g1 ], %o0
a00a4e08:  c2 02 20 c0  ld  [ %o0 + 0xc0 ], %g1
a00a4e0c:  83 30 60 0c  srl  %g1, 0xc, %g1
a00a4e10:  80 88 60 01  btst  1, %g1
a00a4e14:  22 80 00 09  be,a   0xa00a4e38
a00a4e18:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a4e1c:  03 00 00 04  sethi  %hi(0x1000), %g1
a00a4e20:  c2 27 bf f4  st  %g1, [ %fp + -12 ]
a00a4e24:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a00a4e28:  da 02 20 c0  ld  [ %o0 + 0xc0 ], %o5
a00a4e2c:  82 2b 40 01  andn  %o5, %g1, %g1
a00a4e30:  c2 22 20 c0  st  %g1, [ %o0 + 0xc0 ]
a00a4e34:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a4e38:  7f ff fe 6a  call  0xa00a47e0
a00a4e3c:  90 10 00 18  mov  %i0, %o0
a00a4e40:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a4e44:  80 a2 20 01  cmp  %o0, 1
a00a4e48:  12 80 00 06  bne  0xa00a4e60
a00a4e4c:  82 15 60 10  or  %l5, 0x10, %g1
a00a4e50:  9b 2e 20 03  sll  %i0, 3, %o5
a00a4e54:  98 03 40 01  add  %o5, %g1, %o4
a00a4e58:  c0 20 40 0d  clr  [ %g1 + %o5 ]
a00a4e5c:  c0 2b 20 05  clrb  [ %o4 + 5 ]
a00a4e60:  81 c7 e0 08  ret
a00a4e64:  81 e8 00 00  restore
