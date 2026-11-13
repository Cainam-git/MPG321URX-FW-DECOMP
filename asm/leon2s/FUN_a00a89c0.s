# leon2s FUN_a00a89c0 0xa00a89c0-0xa00a8cac (748 bytes)
a00a89c0:  9d e3 bf 98  save  %sp, -104, %sp
a00a89c4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a89c8:  a0 0e 60 ff  and  %i1, 0xff, %l0
a00a89cc:  a2 0e a0 ff  and  %i2, 0xff, %l1
a00a89d0:  90 10 00 18  mov  %i0, %o0
a00a89d4:  92 10 00 10  mov  %l0, %o1
a00a89d8:  7f ff ff b8  call  0xa00a88b8
a00a89dc:  94 10 00 11  mov  %l1, %o2
a00a89e0:  80 a6 20 01  cmp  %i0, 1
a00a89e4:  02 80 00 17  be  0xa00a8a40
a00a89e8:  a4 0a 20 01  and  %o0, 1, %l2
a00a89ec:  80 a6 20 01  cmp  %i0, 1
a00a89f0:  14 80 00 07  bg  0xa00a8a0c
a00a89f4:  80 a6 20 02  cmp  %i0, 2
a00a89f8:  80 a6 20 00  cmp  %i0, 0
a00a89fc:  22 80 00 08  be,a   0xa00a8a1c
a00a8a00:  90 10 00 11  mov  %l1, %o0
a00a8a04:  10 80 00 8f  b  0xa00a8c40
a00a8a08:  a4 10 20 00  clr  %l2
a00a8a0c:  02 80 00 36  be  0xa00a8ae4
a00a8a10:  82 1c 20 31  xor  %l0, 0x31, %g1
a00a8a14:  10 80 00 8b  b  0xa00a8c40
a00a8a18:  a4 10 20 00  clr  %l2
a00a8a1c:  92 10 20 59  mov  0x59, %o1
a00a8a20:  94 10 20 04  mov  4, %o2
a00a8a24:  7f ff fe 0f  call  0xa00a8260
a00a8a28:  96 0f 20 ff  and  %i4, 0xff, %o3
a00a8a2c:  90 10 00 11  mov  %l1, %o0
a00a8a30:  92 10 20 50  mov  0x50, %o1
a00a8a34:  94 10 20 01  mov  1, %o2
a00a8a38:  10 80 00 22  b  0xa00a8ac0
a00a8a3c:  96 0f 60 ff  and  %i5, 0xff, %o3
a00a8a40:  98 0e e0 ff  and  %i3, 0xff, %o4
a00a8a44:  90 10 20 04  mov  4, %o0
a00a8a48:  92 10 00 11  mov  %l1, %o1
a00a8a4c:  94 10 20 55  mov  0x55, %o2
a00a8a50:  7f ff f6 7c  call  0xa00a6440
a00a8a54:  96 10 20 ff  mov  0xff, %o3
a00a8a58:  99 2e e0 10  sll  %i3, 0x10, %o4
a00a8a5c:  99 33 20 18  srl  %o4, 0x18, %o4
a00a8a60:  90 10 20 04  mov  4, %o0
a00a8a64:  92 10 00 11  mov  %l1, %o1
a00a8a68:  94 10 20 56  mov  0x56, %o2
a00a8a6c:  7f ff f6 75  call  0xa00a6440
a00a8a70:  96 10 20 ff  mov  0xff, %o3
a00a8a74:  90 10 00 11  mov  %l1, %o0
a00a8a78:  92 10 20 59  mov  0x59, %o1
a00a8a7c:  94 10 20 10  mov  0x10, %o2
a00a8a80:  7f ff fd f8  call  0xa00a8260
a00a8a84:  96 0f 20 ff  and  %i4, 0xff, %o3
a00a8a88:  90 10 00 11  mov  %l1, %o0
a00a8a8c:  92 10 20 54  mov  0x54, %o1
a00a8a90:  94 10 20 07  mov  7, %o2
a00a8a94:  7f ff fd f3  call  0xa00a8260
a00a8a98:  96 0f 60 ff  and  %i5, 0xff, %o3
a00a8a9c:  90 10 00 11  mov  %l1, %o0
a00a8aa0:  92 10 20 54  mov  0x54, %o1
a00a8aa4:  94 10 20 80  mov  0x80, %o2
a00a8aa8:  7f ff fd ee  call  0xa00a8260
a00a8aac:  96 10 20 01  mov  1, %o3
a00a8ab0:  90 10 00 11  mov  %l1, %o0
a00a8ab4:  92 10 20 54  mov  0x54, %o1
a00a8ab8:  94 10 20 80  mov  0x80, %o2
a00a8abc:  96 10 20 00  clr  %o3
a00a8ac0:  7f ff fd e8  call  0xa00a8260
a00a8ac4:  01 00 00 00  nop
a00a8ac8:  82 06 7f cf  add  %i1, -49, %g1
a00a8acc:  82 08 60 ff  and  %g1, 0xff, %g1
a00a8ad0:  80 a0 60 50  cmp  %g1, 0x50
a00a8ad4:  08 80 00 5c  bleu  0xa00a8c44
a00a8ad8:  82 0f 40 1c  and  %i5, %i4, %g1
a00a8adc:  10 80 00 5a  b  0xa00a8c44
a00a8ae0:  a4 10 20 00  clr  %l2
a00a8ae4:  80 a0 00 01  cmp  %g0, %g1
a00a8ae8:  9a 60 3f ff  subx  %g0, -1, %o5
a00a8aec:  82 1c 20 41  xor  %l0, 0x41, %g1
a00a8af0:  80 a0 00 01  cmp  %g0, %g1
a00a8af4:  82 60 3f ff  subx  %g0, -1, %g1
a00a8af8:  80 93 40 01  orcc  %o5, %g1, %g0
a00a8afc:  12 80 00 0c  bne  0xa00a8b2c
a00a8b00:  83 2c 60 03  sll  %l1, 3, %g1
a00a8b04:  82 1c 20 51  xor  %l0, 0x51, %g1
a00a8b08:  80 a0 00 01  cmp  %g0, %g1
a00a8b0c:  9a 60 3f ff  subx  %g0, -1, %o5
a00a8b10:  82 1c 20 61  xor  %l0, 0x61, %g1
a00a8b14:  80 a0 00 01  cmp  %g0, %g1
a00a8b18:  82 60 3f ff  subx  %g0, -1, %g1
a00a8b1c:  80 93 40 01  orcc  %o5, %g1, %g0
a00a8b20:  02 80 00 22  be  0xa00a8ba8
a00a8b24:  82 1c 20 71  xor  %l0, 0x71, %g1
a00a8b28:  83 2c 60 03  sll  %l1, 3, %g1
a00a8b2c:  82 20 40 11  sub  %g1, %l1, %g1
a00a8b30:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a00a8b34:  83 28 60 02  sll  %g1, 2, %g1
a00a8b38:  9a 13 61 80  or  %o5, 0x180, %o5
a00a8b3c:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a00a8b40:  83 30 60 1e  srl  %g1, 0x1e, %g1
a00a8b44:  80 88 60 01  btst  1, %g1
a00a8b48:  02 80 00 07  be  0xa00a8b64
a00a8b4c:  90 10 20 04  mov  4, %o0
a00a8b50:  92 10 00 11  mov  %l1, %o1
a00a8b54:  94 10 20 57  mov  0x57, %o2
a00a8b58:  96 10 20 ff  mov  0xff, %o3
a00a8b5c:  10 80 00 06  b  0xa00a8b74
a00a8b60:  98 10 20 0a  mov  0xa, %o4
a00a8b64:  92 10 00 11  mov  %l1, %o1
a00a8b68:  94 10 20 57  mov  0x57, %o2
a00a8b6c:  96 10 20 ff  mov  0xff, %o3
a00a8b70:  98 10 20 0b  mov  0xb, %o4
a00a8b74:  7f ff f6 33  call  0xa00a6440
a00a8b78:  01 00 00 00  nop
a00a8b7c:  92 10 00 11  mov  %l1, %o1
a00a8b80:  90 10 20 04  mov  4, %o0
a00a8b84:  94 10 20 58  mov  0x58, %o2
a00a8b88:  96 10 20 1f  mov  0x1f, %o3
a00a8b8c:  7f ff f6 2d  call  0xa00a6440
a00a8b90:  98 10 20 00  clr  %o4
a00a8b94:  90 10 00 11  mov  %l1, %o0
a00a8b98:  92 10 20 59  mov  0x59, %o1
a00a8b9c:  94 10 20 02  mov  2, %o2
a00a8ba0:  10 80 00 1a  b  0xa00a8c08
a00a8ba4:  96 10 20 00  clr  %o3
a00a8ba8:  80 a0 00 01  cmp  %g0, %g1
a00a8bac:  9a 60 3f ff  subx  %g0, -1, %o5
a00a8bb0:  82 1c 20 81  xor  %l0, 0x81, %g1
a00a8bb4:  80 a0 00 01  cmp  %g0, %g1
a00a8bb8:  82 60 3f ff  subx  %g0, -1, %g1
a00a8bbc:  80 93 40 01  orcc  %o5, %g1, %g0
a00a8bc0:  22 80 00 16  be,a   0xa00a8c18
a00a8bc4:  a4 10 20 00  clr  %l2
a00a8bc8:  92 10 00 11  mov  %l1, %o1
a00a8bcc:  90 10 20 04  mov  4, %o0
a00a8bd0:  94 10 20 57  mov  0x57, %o2
a00a8bd4:  96 10 20 ff  mov  0xff, %o3
a00a8bd8:  7f ff f6 1a  call  0xa00a6440
a00a8bdc:  98 10 20 04  mov  4, %o4
a00a8be0:  92 10 00 11  mov  %l1, %o1
a00a8be4:  90 10 20 04  mov  4, %o0
a00a8be8:  94 10 20 58  mov  0x58, %o2
a00a8bec:  96 10 20 1f  mov  0x1f, %o3
a00a8bf0:  7f ff f6 14  call  0xa00a6440
a00a8bf4:  98 10 20 10  mov  0x10, %o4
a00a8bf8:  90 10 00 11  mov  %l1, %o0
a00a8bfc:  92 10 20 59  mov  0x59, %o1
a00a8c00:  94 10 20 02  mov  2, %o2
a00a8c04:  96 10 20 01  mov  1, %o3
a00a8c08:  7f ff fd 96  call  0xa00a8260
a00a8c0c:  01 00 00 00  nop
a00a8c10:  10 80 00 03  b  0xa00a8c1c
a00a8c14:  96 0f 20 ff  and  %i4, 0xff, %o3
a00a8c18:  96 0f 20 ff  and  %i4, 0xff, %o3
a00a8c1c:  97 2a e0 03  sll  %o3, 3, %o3
a00a8c20:  96 12 c0 1d  or  %o3, %i5, %o3
a00a8c24:  96 0a e0 ff  and  %o3, 0xff, %o3
a00a8c28:  90 0e a0 ff  and  %i2, 0xff, %o0
a00a8c2c:  92 10 20 59  mov  0x59, %o1
a00a8c30:  7f ff fd 8c  call  0xa00a8260
a00a8c34:  94 10 20 09  mov  9, %o2
a00a8c38:  10 80 00 03  b  0xa00a8c44
a00a8c3c:  82 0f 40 1c  and  %i5, %i4, %g1
a00a8c40:  82 0f 40 1c  and  %i5, %i4, %g1
a00a8c44:  80 88 60 ff  btst  0xff, %g1
a00a8c48:  02 80 00 13  be  0xa00a8c94
a00a8c4c:  82 0e a0 ff  and  %i2, 0xff, %g1
a00a8c50:  a2 0e a0 ff  and  %i2, 0xff, %l1
a00a8c54:  92 10 20 00  clr  %o1
a00a8c58:  94 10 20 33  mov  0x33, %o2
a00a8c5c:  7f ff fc df  call  0xa00a7fd8
a00a8c60:  90 10 00 11  mov  %l1, %o0
a00a8c64:  a1 32 20 04  srl  %o0, 4, %l0
a00a8c68:  90 10 00 11  mov  %l1, %o0
a00a8c6c:  92 10 20 00  clr  %o1
a00a8c70:  7f ff fc da  call  0xa00a7fd8
a00a8c74:  94 10 20 3f  mov  0x3f, %o2
a00a8c78:  a0 0c 20 03  and  %l0, 3, %l0
a00a8c7c:  90 1a 00 10  xor  %o0, %l0, %o0
a00a8c80:  90 0a 20 03  and  %o0, 3, %o0
a00a8c84:  80 a0 00 08  cmp  %g0, %o0
a00a8c88:  82 40 3f ff  addx  %g0, -1, %g1
a00a8c8c:  a4 08 40 12  and  %g1, %l2, %l2
a00a8c90:  82 0e a0 ff  and  %i2, 0xff, %g1
a00a8c94:  80 a0 60 02  cmp  %g1, 2
a00a8c98:  82 60 20 00  subx  %g0, 0, %g1
a00a8c9c:  a4 08 40 12  and  %g1, %l2, %l2
a00a8ca0:  b0 0c a0 ff  and  %l2, 0xff, %i0
a00a8ca4:  81 c7 e0 08  ret
a00a8ca8:  81 e8 00 00  restore
