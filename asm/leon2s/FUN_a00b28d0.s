# leon2s FUN_a00b28d0 0xa00b28d0-0xa00b34a8 (3032 bytes)
a00b28d0:  9d e3 bf 90  save  %sp, -112, %sp
a00b28d4:  7f ff 00 e6  call  0xa0072c6c
a00b28d8:  90 07 bf f7  add  %fp, -9, %o0
a00b28dc:  80 a2 20 00  cmp  %o0, 0
a00b28e0:  02 80 02 f0  be  0xa00b34a0
a00b28e4:  2b 2a 01 f7  sethi  %hi(0xa807dc00), %l5
a00b28e8:  c2 0d 62 c4  ldub  [ %l5 + 0x2c4 ], %g1	! 0xa807dec4
a00b28ec:  80 a0 60 00  cmp  %g1, 0
a00b28f0:  02 80 00 f7  be  0xa00b2ccc
a00b28f4:  d6 0f bf f7  ldub  [ %fp + -9 ], %o3
a00b28f8:  83 2a e0 18  sll  %o3, 0x18, %g1
a00b28fc:  83 38 60 18  sra  %g1, 0x18, %g1
a00b2900:  80 a0 60 1c  cmp  %g1, 0x1c
a00b2904:  22 80 02 e6  be,a   0xa00b349c
a00b2908:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00b290c:  14 80 00 07  bg  0xa00b2928
a00b2910:  80 a0 60 5e  cmp  %g1, 0x5e
a00b2914:  80 a0 60 0d  cmp  %g1, 0xd
a00b2918:  02 80 00 08  be  0xa00b2938
a00b291c:  15 2a 01 f7  sethi  %hi(0xa807dc00), %o2
a00b2920:  10 80 00 e3  b  0xa00b2cac
a00b2924:  d8 02 a2 ac  ld  [ %o2 + 0x2ac ], %o4	! 0xa807deac
a00b2928:  12 80 00 e0  bne  0xa00b2ca8
a00b292c:  15 2a 01 f7  sethi  %hi(0xa807dc00), %o2
a00b2930:  10 80 02 db  b  0xa00b349c
a00b2934:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00b2938:  2d 2a 01 f7  sethi  %hi(0xa807dc00), %l6
a00b293c:  c2 05 a2 ac  ld  [ %l6 + 0x2ac ], %g1	! 0xa807deac
a00b2940:  80 a0 60 01  cmp  %g1, 1
a00b2944:  24 80 00 d7  ble,a   0xa00b2ca0
a00b2948:  c0 25 a2 ac  clr  [ %l6 + 0x2ac ]
a00b294c:  9e 08 60 ff  and  %g1, 0xff, %o7
a00b2950:  23 2a 01 f7  sethi  %hi(0xa807dc00), %l1
a00b2954:  96 10 20 01  mov  1, %o3
a00b2958:  80 a2 c0 0f  cmp  %o3, %o7
a00b295c:  d0 0c 62 f0  ldub  [ %l1 + 0x2f0 ], %o0
a00b2960:  94 10 20 00  clr  %o2
a00b2964:  a0 10 20 00  clr  %l0
a00b2968:  1a 80 00 3a  bcc  0xa00b2a50
a00b296c:  92 10 20 00  clr  %o1
a00b2970:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00b2974:  a4 10 62 d0  or  %g1, 0x2d0, %l2	! 0xa807ded0
a00b2978:  82 14 62 f0  or  %l1, 0x2f0, %g1
a00b297c:  da 08 40 0b  ldub  [ %g1 + %o3 ], %o5
a00b2980:  82 03 7f 9f  add  %o5, -97, %g1
a00b2984:  82 08 60 ff  and  %g1, 0xff, %g1
a00b2988:  80 a0 60 05  cmp  %g1, 5
a00b298c:  18 80 00 04  bgu  0xa00b299c
a00b2990:  82 03 7f bf  add  %o5, -65, %g1
a00b2994:  10 80 00 1b  b  0xa00b2a00
a00b2998:  9a 03 7f a9  add  %o5, -87, %o5
a00b299c:  82 08 60 ff  and  %g1, 0xff, %g1
a00b29a0:  80 a0 60 05  cmp  %g1, 5
a00b29a4:  18 80 00 04  bgu  0xa00b29b4
a00b29a8:  98 03 7f d0  add  %o5, -48, %o4
a00b29ac:  10 80 00 15  b  0xa00b2a00
a00b29b0:  9a 03 7f c9  add  %o5, -55, %o5
a00b29b4:  82 0b 20 ff  and  %o4, 0xff, %g1
a00b29b8:  80 a0 60 09  cmp  %g1, 9
a00b29bc:  18 80 00 04  bgu  0xa00b29cc
a00b29c0:  82 0b 60 ff  and  %o5, 0xff, %g1
a00b29c4:  10 80 00 0f  b  0xa00b2a00
a00b29c8:  9a 10 00 0c  mov  %o4, %o5
a00b29cc:  9a 18 60 20  xor  %g1, 0x20, %o5
a00b29d0:  80 a0 00 0d  cmp  %g0, %o5
a00b29d4:  9a 60 3f ff  subx  %g0, -1, %o5
a00b29d8:  82 18 60 2c  xor  %g1, 0x2c, %g1
a00b29dc:  80 a0 00 01  cmp  %g0, %g1
a00b29e0:  82 60 3f ff  subx  %g0, -1, %g1
a00b29e4:  80 93 40 01  orcc  %o5, %g1, %g0
a00b29e8:  02 80 00 14  be  0xa00b2a38
a00b29ec:  80 8a a0 ff  btst  0xff, %o2
a00b29f0:  32 80 00 18  bne,a   0xa00b2a50
a00b29f4:  90 10 3f ff  mov  -1, %o0
a00b29f8:  10 80 00 12  b  0xa00b2a40
a00b29fc:  a0 10 20 00  clr  %l0
a00b2a00:  80 8a a0 ff  btst  0xff, %o2
a00b2a04:  12 80 00 05  bne  0xa00b2a18
a00b2a08:  80 a2 60 1f  cmp  %o1, 0x1f
a00b2a0c:  a0 10 00 0d  mov  %o5, %l0
a00b2a10:  10 80 00 0c  b  0xa00b2a40
a00b2a14:  94 10 20 01  mov  1, %o2
a00b2a18:  18 80 00 08  bgu  0xa00b2a38
a00b2a1c:  94 10 20 00  clr  %o2
a00b2a20:  82 0c 20 ff  and  %l0, 0xff, %g1
a00b2a24:  83 28 60 04  sll  %g1, 4, %g1
a00b2a28:  82 00 40 0d  add  %g1, %o5, %g1
a00b2a2c:  c2 2a 40 12  stb  %g1, [ %o1 + %l2 ]
a00b2a30:  10 80 00 04  b  0xa00b2a40
a00b2a34:  92 02 60 01  inc  %o1
a00b2a38:  10 80 00 06  b  0xa00b2a50
a00b2a3c:  90 10 3f ff  mov  -1, %o0
a00b2a40:  96 02 e0 01  inc  %o3
a00b2a44:  80 a2 c0 0f  cmp  %o3, %o7
a00b2a48:  0a bf ff cd  bcs  0xa00b297c
a00b2a4c:  82 14 62 f0  or  %l1, 0x2f0, %g1
a00b2a50:  80 a2 60 20  cmp  %o1, 0x20
a00b2a54:  82 40 20 00  addx  %g0, 0, %g1
a00b2a58:  80 88 40 0a  btst  %g1, %o2
a00b2a5c:  32 80 00 02  bne,a   0xa00b2a64
a00b2a60:  90 10 3f ff  mov  -1, %o0
a00b2a64:  98 0a 20 ff  and  %o0, 0xff, %o4
a00b2a68:  80 a3 20 57  cmp  %o4, 0x57
a00b2a6c:  a6 10 20 00  clr  %l3
a00b2a70:  a2 10 20 00  clr  %l1
a00b2a74:  02 80 00 10  be  0xa00b2ab4
a00b2a78:  a4 10 20 00  clr  %l2
a00b2a7c:  80 a3 20 57  cmp  %o4, 0x57
a00b2a80:  14 80 00 06  bg  0xa00b2a98
a00b2a84:  80 a3 20 75  cmp  %o4, 0x75
a00b2a88:  80 a3 20 52  cmp  %o4, 0x52
a00b2a8c:  02 80 00 0a  be  0xa00b2ab4
a00b2a90:  80 a3 20 55  cmp  %o4, 0x55
a00b2a94:  30 80 00 06  b,a   0xa00b2aac
a00b2a98:  02 80 00 07  be  0xa00b2ab4
a00b2a9c:  80 a3 20 75  cmp  %o4, 0x75
a00b2aa0:  34 80 00 03  bg,a   0xa00b2aac
a00b2aa4:  80 a3 20 77  cmp  %o4, 0x77
a00b2aa8:  80 a3 20 72  cmp  %o4, 0x72
a00b2aac:  12 80 00 0c  bne  0xa00b2adc
a00b2ab0:  80 a3 20 57  cmp  %o4, 0x57
a00b2ab4:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00b2ab8:  94 10 62 d0  or  %g1, 0x2d0, %o2	! 0xa807ded0
a00b2abc:  96 10 20 00  clr  %o3
a00b2ac0:  da 0a 80 0b  ldub  [ %o2 + %o3 ], %o5
a00b2ac4:  83 2c e0 08  sll  %l3, 8, %g1
a00b2ac8:  96 02 e0 01  inc  %o3
a00b2acc:  80 a2 e0 03  cmp  %o3, 3
a00b2ad0:  08 bf ff fc  bleu  0xa00b2ac0
a00b2ad4:  a6 00 40 0d  add  %g1, %o5, %l3
a00b2ad8:  80 a3 20 57  cmp  %o4, 0x57
a00b2adc:  02 80 00 4d  be  0xa00b2c10
a00b2ae0:  82 10 20 00  clr  %g1
a00b2ae4:  80 a3 20 57  cmp  %o4, 0x57
a00b2ae8:  14 80 00 08  bg  0xa00b2b08
a00b2aec:  80 a3 20 75  cmp  %o4, 0x75
a00b2af0:  80 a3 20 52  cmp  %o4, 0x52
a00b2af4:  02 80 00 10  be  0xa00b2b34
a00b2af8:  80 a3 20 55  cmp  %o4, 0x55
a00b2afc:  02 80 00 26  be  0xa00b2b94
a00b2b00:  80 88 60 ff  btst  0xff, %g1
a00b2b04:  30 80 00 5c  b,a   0xa00b2c74
a00b2b08:  02 80 00 23  be  0xa00b2b94
a00b2b0c:  80 a3 20 75  cmp  %o4, 0x75
a00b2b10:  14 80 00 06  bg  0xa00b2b28
a00b2b14:  80 a3 20 77  cmp  %o4, 0x77
a00b2b18:  80 a3 20 72  cmp  %o4, 0x72
a00b2b1c:  02 80 00 06  be  0xa00b2b34
a00b2b20:  80 88 60 ff  btst  0xff, %g1
a00b2b24:  30 80 00 54  b,a   0xa00b2c74
a00b2b28:  02 80 00 3a  be  0xa00b2c10
a00b2b2c:  80 88 60 ff  btst  0xff, %g1
a00b2b30:  30 80 00 51  b,a   0xa00b2c74
a00b2b34:  80 a2 60 04  cmp  %o1, 4
a00b2b38:  12 80 00 4f  bne  0xa00b2c74
a00b2b3c:  80 88 60 ff  btst  0xff, %g1
a00b2b40:  7f ff fd ef  call  0xa00b22fc
a00b2b44:  90 10 00 13  mov  %l3, %o0
a00b2b48:  1b 2a 01 f7  sethi  %hi(0xa807dc00), %o5
a00b2b4c:  a2 10 00 08  mov  %o0, %l1
a00b2b50:  82 10 3f 83  mov  -125, %g1
a00b2b54:  c2 2b 62 d0  stb  %g1, [ %o5 + 0x2d0 ]
a00b2b58:  90 13 62 d0  or  %o5, 0x2d0, %o0
a00b2b5c:  96 10 20 01  mov  1, %o3
a00b2b60:  98 10 20 1c  mov  0x1c, %o4
a00b2b64:  83 34 40 0c  srl  %l1, %o4, %g1
a00b2b68:  82 08 60 0f  and  %g1, 0xf, %g1
a00b2b6c:  82 00 7f 90  add  %g1, -112, %g1
a00b2b70:  c2 2a 00 0b  stb  %g1, [ %o0 + %o3 ]
a00b2b74:  96 02 e0 01  inc  %o3
a00b2b78:  80 a2 e0 08  cmp  %o3, 8
a00b2b7c:  08 bf ff fa  bleu  0xa00b2b64
a00b2b80:  98 03 3f fc  add  %o4, -4, %o4
a00b2b84:  82 10 3f 8f  mov  -113, %g1
a00b2b88:  c2 2a 20 09  stb  %g1, [ %o0 + 9 ]
a00b2b8c:  10 80 00 36  b  0xa00b2c64
a00b2b90:  c0 2a 20 0a  clrb  [ %o0 + 0xa ]
a00b2b94:  80 a2 60 0c  cmp  %o1, 0xc
a00b2b98:  12 80 00 37  bne  0xa00b2c74
a00b2b9c:  80 88 60 ff  btst  0xff, %g1
a00b2ba0:  29 2a 01 f7  sethi  %hi(0xa807dc00), %l4
a00b2ba4:  96 10 20 04  mov  4, %o3
a00b2ba8:  98 15 22 d0  or  %l4, 0x2d0, %o4
a00b2bac:  da 0b 00 0b  ldub  [ %o4 + %o3 ], %o5
a00b2bb0:  83 2c 60 08  sll  %l1, 8, %g1
a00b2bb4:  96 02 e0 01  inc  %o3
a00b2bb8:  80 a2 e0 07  cmp  %o3, 7
a00b2bbc:  08 bf ff fc  bleu  0xa00b2bac
a00b2bc0:  a2 00 40 0d  add  %g1, %o5, %l1
a00b2bc4:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00b2bc8:  a0 10 62 d0  or  %g1, 0x2d0, %l0	! 0xa807ded0
a00b2bcc:  96 10 20 08  mov  8, %o3
a00b2bd0:  da 0c 00 0b  ldub  [ %l0 + %o3 ], %o5
a00b2bd4:  83 2c a0 08  sll  %l2, 8, %g1
a00b2bd8:  96 02 e0 01  inc  %o3
a00b2bdc:  80 a2 e0 0b  cmp  %o3, 0xb
a00b2be0:  08 bf ff fc  bleu  0xa00b2bd0
a00b2be4:  a4 00 40 0d  add  %g1, %o5, %l2
a00b2be8:  7f ff fd c5  call  0xa00b22fc
a00b2bec:  90 10 00 13  mov  %l3, %o0
a00b2bf0:  92 2a 00 12  andn  %o0, %l2, %o1
a00b2bf4:  a2 0c 40 12  and  %l1, %l2, %l1
a00b2bf8:  92 12 40 11  or  %o1, %l1, %o1
a00b2bfc:  7f ff fd c2  call  0xa00b2304
a00b2c00:  90 10 00 13  mov  %l3, %o0
a00b2c04:  82 10 3f 83  mov  -125, %g1
a00b2c08:  10 80 00 13  b  0xa00b2c54
a00b2c0c:  c2 2d 22 d0  stb  %g1, [ %l4 + 0x2d0 ]
a00b2c10:  80 a2 60 08  cmp  %o1, 8
a00b2c14:  12 80 00 18  bne  0xa00b2c74
a00b2c18:  80 88 60 ff  btst  0xff, %g1
a00b2c1c:  25 2a 01 f7  sethi  %hi(0xa807dc00), %l2
a00b2c20:  96 10 20 04  mov  4, %o3
a00b2c24:  a0 14 a2 d0  or  %l2, 0x2d0, %l0
a00b2c28:  da 0c 00 0b  ldub  [ %l0 + %o3 ], %o5
a00b2c2c:  83 2c 60 08  sll  %l1, 8, %g1
a00b2c30:  96 02 e0 01  inc  %o3
a00b2c34:  80 a2 e0 07  cmp  %o3, 7
a00b2c38:  08 bf ff fc  bleu  0xa00b2c28
a00b2c3c:  a2 00 40 0d  add  %g1, %o5, %l1
a00b2c40:  90 10 00 13  mov  %l3, %o0
a00b2c44:  7f ff fd b0  call  0xa00b2304
a00b2c48:  92 10 00 11  mov  %l1, %o1
a00b2c4c:  82 10 3f 83  mov  -125, %g1
a00b2c50:  c2 2c a2 d0  stb  %g1, [ %l2 + 0x2d0 ]
a00b2c54:  82 10 3f 8f  mov  -113, %g1
a00b2c58:  c2 2c 20 01  stb  %g1, [ %l0 + 1 ]
a00b2c5c:  c0 2c 20 02  clrb  [ %l0 + 2 ]
a00b2c60:  90 10 00 10  mov  %l0, %o0
a00b2c64:  7f fe b9 87  call  0xa0061280
a00b2c68:  01 00 00 00  nop
a00b2c6c:  82 10 20 01  mov  1, %g1	! 0x1
a00b2c70:  80 88 60 ff  btst  0xff, %g1
a00b2c74:  32 80 00 0b  bne,a   0xa00b2ca0
a00b2c78:  c0 25 a2 ac  clr  [ %l6 + 0x2ac ]
a00b2c7c:  1b 2a 01 f7  sethi  %hi(0xa807dc00), %o5
a00b2c80:  82 10 3f 82  mov  -126, %g1
a00b2c84:  c2 2b 62 d0  stb  %g1, [ %o5 + 0x2d0 ]
a00b2c88:  90 13 62 d0  or  %o5, 0x2d0, %o0
a00b2c8c:  82 10 3f 8f  mov  -113, %g1
a00b2c90:  c2 2a 20 01  stb  %g1, [ %o0 + 1 ]
a00b2c94:  7f fe b9 7b  call  0xa0061280
a00b2c98:  c0 2a 20 02  clrb  [ %o0 + 2 ]
a00b2c9c:  c0 25 a2 ac  clr  [ %l6 + 0x2ac ]
a00b2ca0:  10 80 02 00  b  0xa00b34a0
a00b2ca4:  c0 2d 62 c4  clrb  [ %l5 + 0x2c4 ]
a00b2ca8:  d8 02 a2 ac  ld  [ %o2 + 0x2ac ], %o4
a00b2cac:  80 a3 20 fd  cmp  %o4, 0xfd
a00b2cb0:  14 80 01 fc  bg  0xa00b34a0
a00b2cb4:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00b2cb8:  9a 03 20 01  add  %o4, 1, %o5
a00b2cbc:  82 10 62 f0  or  %g1, 0x2f0, %g1
a00b2cc0:  d6 28 40 0c  stb  %o3, [ %g1 + %o4 ]
a00b2cc4:  10 80 01 f7  b  0xa00b34a0
a00b2cc8:  da 22 a2 ac  st  %o5, [ %o2 + 0x2ac ]
a00b2ccc:  83 2a e0 18  sll  %o3, 0x18, %g1
a00b2cd0:  83 38 60 18  sra  %g1, 0x18, %g1
a00b2cd4:  80 a0 60 0d  cmp  %g1, 0xd
a00b2cd8:  02 80 00 17  be  0xa00b2d34
a00b2cdc:  a0 10 20 00  clr  %l0
a00b2ce0:  80 a0 60 0d  cmp  %g1, 0xd
a00b2ce4:  14 80 00 07  bg  0xa00b2d00
a00b2ce8:  80 a0 60 1b  cmp  %g1, 0x1b
a00b2cec:  80 a0 60 08  cmp  %g1, 8
a00b2cf0:  02 80 00 08  be  0xa00b2d10
a00b2cf4:  19 2a 01 f7  sethi  %hi(0xa807dc00), %o4
a00b2cf8:  10 80 00 19  b  0xa00b2d5c
a00b2cfc:  c2 03 22 ac  ld  [ %o4 + 0x2ac ], %g1	! 0xa807deac
a00b2d00:  02 80 00 0f  be  0xa00b2d3c
a00b2d04:  19 2a 01 f7  sethi  %hi(0xa807dc00), %o4
a00b2d08:  10 80 00 15  b  0xa00b2d5c
a00b2d0c:  c2 03 22 ac  ld  [ %o4 + 0x2ac ], %g1	! 0xa807deac
a00b2d10:  1b 2a 01 f7  sethi  %hi(0xa807dc00), %o5
a00b2d14:  c2 03 62 ac  ld  [ %o5 + 0x2ac ], %g1	! 0xa807deac
a00b2d18:  80 a0 60 00  cmp  %g1, 0
a00b2d1c:  04 80 00 27  ble  0xa00b2db8
a00b2d20:  82 00 7f ff  add  %g1, -1, %g1
a00b2d24:  11 28 01 b1  sethi  %hi(0xa006c400), %o0
a00b2d28:  c2 23 62 ac  st  %g1, [ %o5 + 0x2ac ]
a00b2d2c:  10 80 00 08  b  0xa00b2d4c
a00b2d30:  90 12 22 b8  or  %o0, 0x2b8, %o0
a00b2d34:  10 80 00 21  b  0xa00b2db8
a00b2d38:  a0 10 20 01  mov  1, %l0
a00b2d3c:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00b2d40:  11 28 01 b1  sethi  %hi(0xa006c400), %o0
a00b2d44:  c0 20 62 ac  clr  [ %g1 + 0x2ac ]
a00b2d48:  90 12 22 c0  or  %o0, 0x2c0, %o0
a00b2d4c:  7f fe b9 4d  call  0xa0061280
a00b2d50:  01 00 00 00  nop
a00b2d54:  10 80 00 1a  b  0xa00b2dbc
a00b2d58:  80 8c 20 ff  btst  0xff, %l0
a00b2d5c:  80 a0 60 00  cmp  %g1, 0
a00b2d60:  12 80 00 0b  bne  0xa00b2d8c
a00b2d64:  da 03 22 ac  ld  [ %o4 + 0x2ac ], %o5
a00b2d68:  83 2a e0 18  sll  %o3, 0x18, %g1
a00b2d6c:  83 38 60 18  sra  %g1, 0x18, %g1
a00b2d70:  80 a0 60 5e  cmp  %g1, 0x5e
a00b2d74:  12 80 00 07  bne  0xa00b2d90
a00b2d78:  80 a3 60 fd  cmp  %o5, 0xfd
a00b2d7c:  82 10 20 01  mov  1, %g1
a00b2d80:  c2 2d 62 c4  stb  %g1, [ %l5 + 0x2c4 ]
a00b2d84:  10 80 00 0d  b  0xa00b2db8
a00b2d88:  c0 23 22 ac  clr  [ %o4 + 0x2ac ]
a00b2d8c:  80 a3 60 fd  cmp  %o5, 0xfd
a00b2d90:  14 80 00 0b  bg  0xa00b2dbc
a00b2d94:  80 8c 20 ff  btst  0xff, %l0
a00b2d98:  d0 0f bf f7  ldub  [ %fp + -9 ], %o0
a00b2d9c:  82 03 60 01  add  %o5, 1, %g1
a00b2da0:  c2 23 22 ac  st  %g1, [ %o4 + 0x2ac ]
a00b2da4:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00b2da8:  82 10 62 f0  or  %g1, 0x2f0, %g1	! 0xa807def0
a00b2dac:  d0 28 40 0d  stb  %o0, [ %g1 + %o5 ]
a00b2db0:  7f fe b9 1f  call  0xa006122c
a00b2db4:  90 0a 20 ff  and  %o0, 0xff, %o0
a00b2db8:  80 8c 20 ff  btst  0xff, %l0
a00b2dbc:  02 80 01 b9  be  0xa00b34a0
a00b2dc0:  29 28 01 a3  sethi  %hi(0xa0068c00), %l4
a00b2dc4:  7f fe b9 2f  call  0xa0061280
a00b2dc8:  90 15 23 00  or  %l4, 0x300, %o0	! 0xa0068f00
a00b2dcc:  19 2a 01 f7  sethi  %hi(0xa807dc00), %o4
a00b2dd0:  da 03 22 ac  ld  [ %o4 + 0x2ac ], %o5	! 0xa807deac
a00b2dd4:  80 a3 60 ff  cmp  %o5, 0xff
a00b2dd8:  14 80 00 06  bg  0xa00b2df0
a00b2ddc:  80 a3 60 00  cmp  %o5, 0
a00b2de0:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00b2de4:  82 10 62 f0  or  %g1, 0x2f0, %g1	! 0xa807def0
a00b2de8:  10 80 00 09  b  0xa00b2e0c
a00b2dec:  c0 28 40 0d  clrb  [ %g1 + %o5 ]
a00b2df0:  02 80 00 06  be  0xa00b2e08
a00b2df4:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00b2df8:  82 10 62 f0  or  %g1, 0x2f0, %g1	! 0xa807def0
a00b2dfc:  82 03 40 01  add  %o5, %g1, %g1
a00b2e00:  10 80 00 03  b  0xa00b2e0c
a00b2e04:  c0 28 7f ff  clrb  [ %g1 + -1 ]
a00b2e08:  c0 28 62 f0  clrb  [ %g1 + 0x2f0 ]
a00b2e0c:  27 2a 01 f7  sethi  %hi(0xa807dc00), %l3
a00b2e10:  c2 0c e2 a8  ldub  [ %l3 + 0x2a8 ], %g1	! 0xa807dea8
a00b2e14:  80 a0 60 00  cmp  %g1, 0
a00b2e18:  12 80 00 9f  bne  0xa00b3094
a00b2e1c:  c2 03 22 ac  ld  [ %o4 + 0x2ac ], %g1
a00b2e20:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00b2e24:  da 08 62 f0  ldub  [ %g1 + 0x2f0 ], %o5	! 0xa807def0
a00b2e28:  80 a3 60 2a  cmp  %o5, 0x2a
a00b2e2c:  12 80 00 05  bne  0xa00b2e40
a00b2e30:  92 10 62 f0  or  %g1, 0x2f0, %o1
a00b2e34:  11 28 02 d3  sethi  %hi(0xa00b4c00), %o0
a00b2e38:  10 80 00 07  b  0xa00b2e54
a00b2e3c:  90 12 22 30  or  %o0, 0x230, %o0	! 0xa00b4e30
a00b2e40:  80 a3 60 7b  cmp  %o5, 0x7b
a00b2e44:  12 80 00 0c  bne  0xa00b2e74
a00b2e48:  a2 10 00 09  mov  %o1, %l1
a00b2e4c:  11 28 02 d3  sethi  %hi(0xa00b4c00), %o0
a00b2e50:  90 12 22 20  or  %o0, 0x220, %o0	! 0xa00b4e20
a00b2e54:  7f ff f9 c5  call  0xa00b1568
a00b2e58:  01 00 00 00  nop
a00b2e5c:  80 a2 20 00  cmp  %o0, 0
a00b2e60:  12 80 01 8f  bne  0xa00b349c
a00b2e64:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00b2e68:  82 10 20 01  mov  1, %g1
a00b2e6c:  10 80 01 8b  b  0xa00b3498
a00b2e70:  c2 2c e2 a8  stb  %g1, [ %l3 + 0x2a8 ]
a00b2e74:  7f ff f9 b1  call  0xa00b1538
a00b2e78:  90 10 00 09  mov  %o1, %o0
a00b2e7c:  2b 2a 01 f7  sethi  %hi(0xa807dc00), %l5
a00b2e80:  13 2a 01 f7  sethi  %hi(0xa807dc00), %o1
a00b2e84:  80 a2 20 00  cmp  %o0, 0
a00b2e88:  9e 15 62 b0  or  %l5, 0x2b0, %o7
a00b2e8c:  02 80 00 7d  be  0xa00b3080
a00b2e90:  a4 12 63 f0  or  %o1, 0x3f0, %l2
a00b2e94:  96 10 20 00  clr  %o3
a00b2e98:  80 a2 c0 08  cmp  %o3, %o0
a00b2e9c:  98 10 3f ff  mov  -1, %o4
a00b2ea0:  16 80 00 35  bge  0xa00b2f74
a00b2ea4:  a0 10 20 00  clr  %l0
a00b2ea8:  d4 0c 40 0b  ldub  [ %l1 + %o3 ], %o2
a00b2eac:  82 0a a0 ff  and  %o2, 0xff, %g1
a00b2eb0:  80 a0 60 20  cmp  %g1, 0x20
a00b2eb4:  22 80 00 0b  be,a   0xa00b2ee0
a00b2eb8:  80 a4 20 00  cmp  %l0, 0
a00b2ebc:  14 80 00 06  bg  0xa00b2ed4
a00b2ec0:  80 a0 60 2c  cmp  %g1, 0x2c
a00b2ec4:  80 a0 60 00  cmp  %g1, 0
a00b2ec8:  22 80 00 06  be,a   0xa00b2ee0
a00b2ecc:  80 a4 20 00  cmp  %l0, 0
a00b2ed0:  80 a0 60 09  cmp  %g1, 9
a00b2ed4:  12 80 00 0e  bne  0xa00b2f0c
a00b2ed8:  9a 04 20 01  add  %l0, 1, %o5
a00b2edc:  80 a4 20 00  cmp  %l0, 0
a00b2ee0:  22 80 00 17  be,a   0xa00b2f3c
a00b2ee4:  96 02 e0 01  inc  %o3
a00b2ee8:  c2 0b c0 00  ldub  [ %o7 ], %g1
a00b2eec:  82 00 60 01  inc  %g1
a00b2ef0:  9a 08 60 ff  and  %g1, 0xff, %o5
a00b2ef4:  80 a3 60 04  cmp  %o5, 4
a00b2ef8:  c2 2b c0 00  stb  %g1, [ %o7 ]
a00b2efc:  08 80 00 0f  bleu  0xa00b2f38
a00b2f00:  a0 10 20 00  clr  %l0
a00b2f04:  10 80 00 06  b  0xa00b2f1c
a00b2f08:  98 10 20 01  mov  1, %o4
a00b2f0c:  80 a3 60 1f  cmp  %o5, 0x1f
a00b2f10:  24 80 00 05  ble,a   0xa00b2f24
a00b2f14:  c2 0b c0 00  ldub  [ %o7 ], %g1
a00b2f18:  98 10 20 01  mov  1, %o4
a00b2f1c:  10 80 00 07  b  0xa00b2f38
a00b2f20:  96 10 00 08  mov  %o0, %o3
a00b2f24:  83 28 60 05  sll  %g1, 5, %g1
a00b2f28:  82 00 40 10  add  %g1, %l0, %g1
a00b2f2c:  d4 28 40 12  stb  %o2, [ %g1 + %l2 ]
a00b2f30:  a0 10 00 0d  mov  %o5, %l0
a00b2f34:  98 10 20 00  clr  %o4
a00b2f38:  96 02 e0 01  inc  %o3
a00b2f3c:  80 a2 c0 08  cmp  %o3, %o0
a00b2f40:  26 bf ff db  bl,a   0xa00b2eac
a00b2f44:  d4 0c 40 0b  ldub  [ %l1 + %o3 ], %o2
a00b2f48:  80 a3 20 00  cmp  %o4, 0
a00b2f4c:  12 80 00 06  bne  0xa00b2f64
a00b2f50:  82 1b 20 01  xor  %o4, 1, %g1
a00b2f54:  c2 0b c0 00  ldub  [ %o7 ], %g1
a00b2f58:  82 00 60 01  inc  %g1
a00b2f5c:  10 80 00 07  b  0xa00b2f78
a00b2f60:  c2 2b c0 00  stb  %g1, [ %o7 ]
a00b2f64:  80 a0 00 01  cmp  %g0, %g1
a00b2f68:  82 40 20 00  addx  %g0, 0, %g1
a00b2f6c:  82 20 00 01  neg  %g1
a00b2f70:  98 0b 00 01  and  %o4, %g1, %o4
a00b2f74:  80 a3 20 00  cmp  %o4, 0
a00b2f78:  12 80 00 43  bne  0xa00b3084
a00b2f7c:  11 28 01 b1  sethi  %hi(0xa006c400), %o0
a00b2f80:  a6 12 63 f0  or  %o1, 0x3f0, %l3
a00b2f84:  a4 10 20 00  clr  %l2
a00b2f88:  a0 10 20 00  clr  %l0
a00b2f8c:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00b2f90:  82 10 62 3c  or  %g1, 0x23c, %g1	! 0xa00b4e3c
a00b2f94:  a2 04 00 01  add  %l0, %g1, %l1
a00b2f98:  90 10 00 11  mov  %l1, %o0
a00b2f9c:  7f ff f9 73  call  0xa00b1568
a00b2fa0:  92 10 00 13  mov  %l3, %o1
a00b2fa4:  a4 04 a0 01  inc  %l2
a00b2fa8:  80 a2 20 00  cmp  %o0, 0
a00b2fac:  12 80 00 20  bne  0xa00b302c
a00b2fb0:  a0 04 20 24  add  %l0, 0x24, %l0
a00b2fb4:  7f fe b8 b3  call  0xa0061280
a00b2fb8:  90 15 23 00  or  %l4, 0x300, %o0
a00b2fbc:  e8 04 60 20  ld  [ %l1 + 0x20 ], %l4
a00b2fc0:  80 a5 20 00  cmp  %l4, 0
a00b2fc4:  22 80 00 1e  be,a   0xa00b303c
a00b2fc8:  11 28 01 b1  sethi  %hi(0xa006c400), %o0
a00b2fcc:  7f ff fd 8b  call  0xa00b25f8
a00b2fd0:  90 04 e0 20  add  %l3, 0x20, %o0
a00b2fd4:  a4 10 00 08  mov  %o0, %l2
a00b2fd8:  7f ff fd 88  call  0xa00b25f8
a00b2fdc:  90 04 e0 40  add  %l3, 0x40, %o0
a00b2fe0:  a2 10 00 08  mov  %o0, %l1
a00b2fe4:  7f ff fd 85  call  0xa00b25f8
a00b2fe8:  90 04 e0 60  add  %l3, 0x60, %o0
a00b2fec:  a0 10 00 08  mov  %o0, %l0
a00b2ff0:  7f ff fd 82  call  0xa00b25f8
a00b2ff4:  90 04 e0 80  add  %l3, 0x80, %o0
a00b2ff8:  96 10 00 08  mov  %o0, %o3
a00b2ffc:  92 10 00 11  mov  %l1, %o1
a00b3000:  94 10 00 10  mov  %l0, %o2
a00b3004:  9f c5 00 00  call  %l4
a00b3008:  90 10 00 12  mov  %l2, %o0
a00b300c:  11 28 01 a3  sethi  %hi(0xa0068c00), %o0
a00b3010:  7f fe b8 9c  call  0xa0061280
a00b3014:  90 12 23 00  or  %o0, 0x300, %o0	! 0xa0068f00
a00b3018:  7f fe b8 9a  call  0xa0061280
a00b301c:  90 10 00 13  mov  %l3, %o0
a00b3020:  11 28 01 b1  sethi  %hi(0xa006c400), %o0
a00b3024:  10 80 00 07  b  0xa00b3040
a00b3028:  90 12 22 f0  or  %o0, 0x2f0, %o0	! 0xa006c6f0
a00b302c:  80 a4 a0 08  cmp  %l2, 8
a00b3030:  06 bf ff d8  bl  0xa00b2f90
a00b3034:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00b3038:  11 28 01 b1  sethi  %hi(0xa006c400), %o0
a00b303c:  90 12 22 d8  or  %o0, 0x2d8, %o0	! 0xa006c6d8
a00b3040:  7f fe b8 90  call  0xa0061280
a00b3044:  01 00 00 00  nop
a00b3048:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00b304c:  82 10 63 f0  or  %g1, 0x3f0, %g1	! 0xa807dff0
a00b3050:  98 10 20 00  clr  %o4
a00b3054:  9a 10 20 00  clr  %o5
a00b3058:  c0 28 40 0d  clrb  [ %g1 + %o5 ]
a00b305c:  9a 03 60 01  inc  %o5
a00b3060:  80 a3 60 1f  cmp  %o5, 0x1f
a00b3064:  24 bf ff fe  ble,a   0xa00b305c
a00b3068:  c0 28 40 0d  clrb  [ %g1 + %o5 ]
a00b306c:  98 03 20 01  inc  %o4
a00b3070:  80 a3 20 04  cmp  %o4, 4
a00b3074:  04 bf ff f8  ble  0xa00b3054
a00b3078:  82 00 60 20  add  %g1, 0x20, %g1
a00b307c:  c0 2d 62 b0  clrb  [ %l5 + 0x2b0 ]
a00b3080:  11 28 01 b1  sethi  %hi(0xa006c400), %o0
a00b3084:  7f fe b8 7f  call  0xa0061280
a00b3088:  90 12 22 d0  or  %o0, 0x2d0, %o0	! 0xa006c6d0
a00b308c:  10 80 01 04  b  0xa00b349c
a00b3090:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00b3094:  80 a0 60 02  cmp  %g1, 2
a00b3098:  04 80 01 01  ble  0xa00b349c
a00b309c:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00b30a0:  21 2a 01 f7  sethi  %hi(0xa807dc00), %l0
a00b30a4:  a2 14 22 f0  or  %l0, 0x2f0, %l1	! 0xa807def0
a00b30a8:  90 04 60 03  add  %l1, 3, %o0
a00b30ac:  7f ff fd b9  call  0xa00b2790
a00b30b0:  92 10 20 04  mov  4, %o1
a00b30b4:  c2 4c 22 f0  ldsb  [ %l0 + 0x2f0 ], %g1
a00b30b8:  80 a0 60 2a  cmp  %g1, 0x2a
a00b30bc:  12 80 00 0f  bne  0xa00b30f8
a00b30c0:  a4 10 00 08  mov  %o0, %l2
a00b30c4:  c2 4c 60 01  ldsb  [ %l1 + 1 ], %g1
a00b30c8:  80 a0 60 71  cmp  %g1, 0x71
a00b30cc:  32 80 00 0c  bne,a   0xa00b30fc
a00b30d0:  c2 4c 40 00  ldsb  [ %l1 ], %g1
a00b30d4:  c2 4c 60 02  ldsb  [ %l1 + 2 ], %g1
a00b30d8:  80 a0 60 74  cmp  %g1, 0x74
a00b30dc:  32 80 00 08  bne,a   0xa00b30fc
a00b30e0:  c2 4c 40 00  ldsb  [ %l1 ], %g1
a00b30e4:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a00b30e8:  82 10 63 ff  or  %g1, 0x3ff, %g1	! 0xffff
a00b30ec:  1b 2a 01 f7  sethi  %hi(0xa807dc00), %o5
a00b30f0:  10 80 00 73  b  0xa00b32bc
a00b30f4:  c2 23 62 b4  st  %g1, [ %o5 + 0x2b4 ]	! 0xa807deb4
a00b30f8:  c2 4c 40 00  ldsb  [ %l1 ], %g1
a00b30fc:  80 a0 60 2a  cmp  %g1, 0x2a
a00b3100:  12 80 00 e6  bne  0xa00b3498
a00b3104:  da 0c 40 00  ldub  [ %l1 ], %o5
a00b3108:  c2 4c 60 01  ldsb  [ %l1 + 1 ], %g1
a00b310c:  80 a0 60 52  cmp  %g1, 0x52
a00b3110:  12 80 00 13  bne  0xa00b315c
a00b3114:  83 2b 60 18  sll  %o5, 0x18, %g1
a00b3118:  c2 4c 60 02  ldsb  [ %l1 + 2 ], %g1
a00b311c:  80 a0 60 44  cmp  %g1, 0x44
a00b3120:  12 80 00 0f  bne  0xa00b315c
a00b3124:  83 2b 60 18  sll  %o5, 0x18, %g1
a00b3128:  90 10 00 12  mov  %l2, %o0
a00b312c:  7f ff fd d8  call  0xa00b288c
a00b3130:  92 10 20 00  clr  %o1
a00b3134:  90 0a 20 ff  and  %o0, 0xff, %o0
a00b3138:  c2 4c 60 07  ldsb  [ %l1 + 7 ], %g1
a00b313c:  80 a2 00 01  cmp  %o0, %g1
a00b3140:  12 80 00 51  bne  0xa00b3284
a00b3144:  19 2a 01 f7  sethi  %hi(0xa807dc00), %o4
a00b3148:  82 13 22 b4  or  %o4, 0x2b4, %g1	! 0xa807deb4
a00b314c:  e4 20 60 04  st  %l2, [ %g1 + 4 ]
a00b3150:  82 10 20 01  mov  1, %g1
a00b3154:  10 80 00 5a  b  0xa00b32bc
a00b3158:  c2 23 22 b4  st  %g1, [ %o4 + 0x2b4 ]
a00b315c:  83 38 60 18  sra  %g1, 0x18, %g1
a00b3160:  80 a0 60 2a  cmp  %g1, 0x2a
a00b3164:  12 80 00 ce  bne  0xa00b349c
a00b3168:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00b316c:  c2 4c 60 01  ldsb  [ %l1 + 1 ], %g1
a00b3170:  80 a0 60 57  cmp  %g1, 0x57
a00b3174:  12 80 00 12  bne  0xa00b31bc
a00b3178:  83 2b 60 18  sll  %o5, 0x18, %g1
a00b317c:  c2 4c 60 02  ldsb  [ %l1 + 2 ], %g1
a00b3180:  80 a0 60 44  cmp  %g1, 0x44
a00b3184:  12 80 00 0e  bne  0xa00b31bc
a00b3188:  83 2b 60 18  sll  %o5, 0x18, %g1
a00b318c:  90 04 60 07  add  %l1, 7, %o0
a00b3190:  7f ff fd 80  call  0xa00b2790
a00b3194:  92 10 20 08  mov  8, %o1
a00b3198:  19 2a 01 f7  sethi  %hi(0xa807dc00), %o4
a00b319c:  c2 0c 60 0f  ldub  [ %l1 + 0xf ], %g1
a00b31a0:  9a 13 22 b4  or  %o4, 0x2b4, %o5
a00b31a4:  c2 2b 60 0c  stb  %g1, [ %o5 + 0xc ]
a00b31a8:  82 10 20 02  mov  2, %g1
a00b31ac:  c2 23 22 b4  st  %g1, [ %o4 + 0x2b4 ]
a00b31b0:  e4 23 60 04  st  %l2, [ %o5 + 4 ]
a00b31b4:  10 80 00 42  b  0xa00b32bc
a00b31b8:  d0 23 60 08  st  %o0, [ %o5 + 8 ]
a00b31bc:  83 38 60 18  sra  %g1, 0x18, %g1
a00b31c0:  80 a0 60 2a  cmp  %g1, 0x2a
a00b31c4:  12 80 00 b6  bne  0xa00b349c
a00b31c8:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00b31cc:  c2 4c 60 01  ldsb  [ %l1 + 1 ], %g1
a00b31d0:  80 a0 60 52  cmp  %g1, 0x52
a00b31d4:  12 80 00 08  bne  0xa00b31f4
a00b31d8:  83 2b 60 18  sll  %o5, 0x18, %g1
a00b31dc:  c2 4c 60 02  ldsb  [ %l1 + 2 ], %g1
a00b31e0:  80 a0 60 42  cmp  %g1, 0x42
a00b31e4:  12 80 00 04  bne  0xa00b31f4
a00b31e8:  83 2b 60 18  sll  %o5, 0x18, %g1
a00b31ec:  10 80 00 0f  b  0xa00b3228
a00b31f0:  9a 10 20 03  mov  3, %o5
a00b31f4:  83 38 60 18  sra  %g1, 0x18, %g1
a00b31f8:  80 a0 60 2a  cmp  %g1, 0x2a
a00b31fc:  12 80 00 a8  bne  0xa00b349c
a00b3200:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00b3204:  c2 4c 60 01  ldsb  [ %l1 + 1 ], %g1
a00b3208:  80 a0 60 57  cmp  %g1, 0x57
a00b320c:  12 80 00 0a  bne  0xa00b3234
a00b3210:  83 2b 60 18  sll  %o5, 0x18, %g1
a00b3214:  c2 4c 60 02  ldsb  [ %l1 + 2 ], %g1
a00b3218:  80 a0 60 42  cmp  %g1, 0x42
a00b321c:  12 80 00 06  bne  0xa00b3234
a00b3220:  83 2b 60 18  sll  %o5, 0x18, %g1
a00b3224:  9a 10 20 04  mov  4, %o5
a00b3228:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00b322c:  10 80 00 25  b  0xa00b32c0
a00b3230:  da 20 62 b4  st  %o5, [ %g1 + 0x2b4 ]	! 0xa807deb4
a00b3234:  83 38 60 18  sra  %g1, 0x18, %g1
a00b3238:  80 a0 60 2a  cmp  %g1, 0x2a
a00b323c:  12 80 00 98  bne  0xa00b349c
a00b3240:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00b3244:  c2 4c 60 01  ldsb  [ %l1 + 1 ], %g1
a00b3248:  80 a0 60 43  cmp  %g1, 0x43
a00b324c:  12 80 00 94  bne  0xa00b349c
a00b3250:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00b3254:  c2 4c 60 02  ldsb  [ %l1 + 2 ], %g1
a00b3258:  80 a0 60 42  cmp  %g1, 0x42
a00b325c:  12 80 00 90  bne  0xa00b349c
a00b3260:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00b3264:  90 10 00 12  mov  %l2, %o0
a00b3268:  7f ff fd 89  call  0xa00b288c
a00b326c:  92 10 20 00  clr  %o1
a00b3270:  90 0a 20 ff  and  %o0, 0xff, %o0
a00b3274:  c2 4c 60 07  ldsb  [ %l1 + 7 ], %g1
a00b3278:  80 a2 00 01  cmp  %o0, %g1
a00b327c:  02 80 00 04  be  0xa00b328c
a00b3280:  19 2a 01 f7  sethi  %hi(0xa807dc00), %o4
a00b3284:  10 80 00 0e  b  0xa00b32bc
a00b3288:  c0 23 22 b4  clr  [ %o4 + 0x2b4 ]	! 0xa807deb4
a00b328c:  9a 10 20 05  mov  5, %o5
a00b3290:  da 23 22 b4  st  %o5, [ %o4 + 0x2b4 ]
a00b3294:  9a 03 6f fb  add  %o5, 0xffb, %o5
a00b3298:  82 13 22 b4  or  %o4, 0x2b4, %g1
a00b329c:  80 a4 80 0d  cmp  %l2, %o5
a00b32a0:  e4 20 60 04  st  %l2, [ %g1 + 4 ]
a00b32a4:  12 80 00 05  bne  0xa00b32b8
a00b32a8:  1b 2a 01 f8  sethi  %hi(0xa807e000), %o5
a00b32ac:  82 10 20 01  mov  1, %g1
a00b32b0:  10 80 00 03  b  0xa00b32bc
a00b32b4:  c2 2b 60 b0  stb  %g1, [ %o5 + 0xb0 ]
a00b32b8:  c0 2b 60 b0  clrb  [ %o5 + 0xb0 ]
a00b32bc:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00b32c0:  da 00 62 b4  ld  [ %g1 + 0x2b4 ], %o5	! 0xa807deb4
a00b32c4:  80 a3 60 02  cmp  %o5, 2
a00b32c8:  a4 10 20 00  clr  %l2
a00b32cc:  02 80 00 31  be  0xa00b3390
a00b32d0:  a0 10 62 b4  or  %g1, 0x2b4, %l0
a00b32d4:  80 a3 60 02  cmp  %o5, 2
a00b32d8:  18 80 00 06  bgu  0xa00b32f0
a00b32dc:  80 a3 60 05  cmp  %o5, 5
a00b32e0:  80 a3 60 01  cmp  %o5, 1
a00b32e4:  02 80 00 0b  be  0xa00b3310
a00b32e8:  80 a4 a0 00  cmp  %l2, 0
a00b32ec:  30 80 00 69  b,a   0xa00b3490
a00b32f0:  02 80 00 46  be  0xa00b3408
a00b32f4:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a00b32f8:  82 10 63 ff  or  %g1, 0x3ff, %g1	! 0xffff
a00b32fc:  80 a3 40 01  cmp  %o5, %g1
a00b3300:  22 80 00 63  be,a   0xa00b348c
a00b3304:  a4 10 20 01  mov  1, %l2
a00b3308:  10 80 00 62  b  0xa00b3490
a00b330c:  80 a4 a0 00  cmp  %l2, 0
a00b3310:  d0 04 20 04  ld  [ %l0 + 4 ], %o0
a00b3314:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00b3318:  c2 00 62 c8  ld  [ %g1 + 0x2c8 ], %g1	! 0xa807dec8
a00b331c:  90 0a 3f fc  and  %o0, -4, %o0
a00b3320:  7f ff fb f7  call  0xa00b22fc
a00b3324:  90 00 40 08  add  %g1, %o0, %o0
a00b3328:  a0 10 00 08  mov  %o0, %l0
a00b332c:  7f ff fd 58  call  0xa00b288c
a00b3330:  92 10 20 00  clr  %o1
a00b3334:  a2 10 00 08  mov  %o0, %l1
a00b3338:  11 2a 01 f8  sethi  %hi(0xa807e000), %o0
a00b333c:  90 12 20 91  or  %o0, 0x91, %o0	! 0xa807e091
a00b3340:  7f ff fd 37  call  0xa00b281c
a00b3344:  92 10 00 10  mov  %l0, %o1
a00b3348:  03 2a 01 f8  sethi  %hi(0xa807e000), %g1
a00b334c:  9a 10 20 23  mov  0x23, %o5
a00b3350:  90 10 60 90  or  %g1, 0x90, %o0
a00b3354:  da 28 60 90  stb  %o5, [ %g1 + 0x90 ]
a00b3358:  82 10 20 20  mov  0x20, %g1
a00b335c:  c2 2a 20 0a  stb  %g1, [ %o0 + 0xa ]
a00b3360:  82 10 20 4f  mov  0x4f, %g1
a00b3364:  c2 2a 20 0b  stb  %g1, [ %o0 + 0xb ]
a00b3368:  82 10 20 4b  mov  0x4b, %g1
a00b336c:  c2 2a 20 0c  stb  %g1, [ %o0 + 0xc ]
a00b3370:  82 10 20 21  mov  0x21, %g1
a00b3374:  c2 2a 20 0d  stb  %g1, [ %o0 + 0xd ]
a00b3378:  82 10 20 0a  mov  0xa, %g1
a00b337c:  e2 2a 20 09  stb  %l1, [ %o0 + 9 ]
a00b3380:  da 2a 20 0e  stb  %o5, [ %o0 + 0xe ]
a00b3384:  c2 2a 20 0f  stb  %g1, [ %o0 + 0xf ]
a00b3388:  10 80 00 3f  b  0xa00b3484
a00b338c:  c0 2a 20 10  clrb  [ %o0 + 0x10 ]
a00b3390:  d0 04 20 04  ld  [ %l0 + 4 ], %o0
a00b3394:  7f ff fd 3e  call  0xa00b288c
a00b3398:  d2 04 20 08  ld  [ %l0 + 8 ], %o1
a00b339c:  90 0a 20 ff  and  %o0, 0xff, %o0
a00b33a0:  c2 4c 20 0c  ldsb  [ %l0 + 0xc ], %g1
a00b33a4:  80 a2 00 01  cmp  %o0, %g1
a00b33a8:  12 80 00 3a  bne  0xa00b3490
a00b33ac:  80 a4 a0 00  cmp  %l2, 0
a00b33b0:  d0 04 20 04  ld  [ %l0 + 4 ], %o0
a00b33b4:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00b33b8:  c2 00 62 c8  ld  [ %g1 + 0x2c8 ], %g1	! 0xa807dec8
a00b33bc:  90 0a 3f fc  and  %o0, -4, %o0
a00b33c0:  90 00 40 08  add  %g1, %o0, %o0
a00b33c4:  7f ff fb d0  call  0xa00b2304
a00b33c8:  d2 04 20 08  ld  [ %l0 + 8 ], %o1
a00b33cc:  03 2a 01 f8  sethi  %hi(0xa807e000), %g1
a00b33d0:  9a 10 20 23  mov  0x23, %o5
a00b33d4:  90 10 60 90  or  %g1, 0x90, %o0
a00b33d8:  da 28 60 90  stb  %o5, [ %g1 + 0x90 ]
a00b33dc:  82 10 20 4f  mov  0x4f, %g1
a00b33e0:  c2 2a 20 01  stb  %g1, [ %o0 + 1 ]
a00b33e4:  82 10 20 4b  mov  0x4b, %g1
a00b33e8:  c2 2a 20 02  stb  %g1, [ %o0 + 2 ]
a00b33ec:  82 10 20 21  mov  0x21, %g1
a00b33f0:  c2 2a 20 03  stb  %g1, [ %o0 + 3 ]
a00b33f4:  82 10 20 0a  mov  0xa, %g1
a00b33f8:  da 2a 20 04  stb  %o5, [ %o0 + 4 ]
a00b33fc:  c2 2a 20 05  stb  %g1, [ %o0 + 5 ]
a00b3400:  10 80 00 21  b  0xa00b3484
a00b3404:  c0 2a 20 06  clrb  [ %o0 + 6 ]
a00b3408:  d2 04 20 04  ld  [ %l0 + 4 ], %o1
a00b340c:  9b 2a 60 10  sll  %o1, 0x10, %o5
a00b3410:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00b3414:  11 2a 01 f8  sethi  %hi(0xa807e000), %o0
a00b3418:  da 20 62 c8  st  %o5, [ %g1 + 0x2c8 ]
a00b341c:  7f ff fd 00  call  0xa00b281c
a00b3420:  90 12 20 a0  or  %o0, 0xa0, %o0
a00b3424:  03 2a 01 f8  sethi  %hi(0xa807e000), %g1
a00b3428:  92 10 20 23  mov  0x23, %o1
a00b342c:  90 10 60 90  or  %g1, 0x90, %o0
a00b3430:  d2 28 60 90  stb  %o1, [ %g1 + 0x90 ]
a00b3434:  82 10 20 20  mov  0x20, %g1
a00b3438:  c2 2a 20 05  stb  %g1, [ %o0 + 5 ]
a00b343c:  82 10 20 4f  mov  0x4f, %g1
a00b3440:  c2 2a 20 06  stb  %g1, [ %o0 + 6 ]
a00b3444:  82 10 20 4b  mov  0x4b, %g1
a00b3448:  c2 2a 20 07  stb  %g1, [ %o0 + 7 ]
a00b344c:  82 10 20 21  mov  0x21, %g1
a00b3450:  c2 2a 20 08  stb  %g1, [ %o0 + 8 ]
a00b3454:  da 0a 20 14  ldub  [ %o0 + 0x14 ], %o5
a00b3458:  d8 0a 20 15  ldub  [ %o0 + 0x15 ], %o4
a00b345c:  d6 0a 20 16  ldub  [ %o0 + 0x16 ], %o3
a00b3460:  d4 0a 20 17  ldub  [ %o0 + 0x17 ], %o2
a00b3464:  82 10 20 0a  mov  0xa, %g1
a00b3468:  da 2a 20 01  stb  %o5, [ %o0 + 1 ]
a00b346c:  d8 2a 20 02  stb  %o4, [ %o0 + 2 ]
a00b3470:  d6 2a 20 03  stb  %o3, [ %o0 + 3 ]
a00b3474:  d4 2a 20 04  stb  %o2, [ %o0 + 4 ]
a00b3478:  d2 2a 20 09  stb  %o1, [ %o0 + 9 ]
a00b347c:  c2 2a 20 0a  stb  %g1, [ %o0 + 0xa ]
a00b3480:  c0 2a 20 0b  clrb  [ %o0 + 0xb ]
a00b3484:  7f fe b7 7f  call  0xa0061280
a00b3488:  01 00 00 00  nop
a00b348c:  80 a4 a0 00  cmp  %l2, 0
a00b3490:  32 80 00 02  bne,a   0xa00b3498
a00b3494:  c0 2c e2 a8  clrb  [ %l3 + 0x2a8 ]
a00b3498:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00b349c:  c0 20 62 ac  clr  [ %g1 + 0x2ac ]	! 0xa807deac
a00b34a0:  81 c7 e0 08  ret
a00b34a4:  81 e8 00 00  restore
