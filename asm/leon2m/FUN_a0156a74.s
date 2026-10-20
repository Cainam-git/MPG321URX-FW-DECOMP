# leon2m FUN_a0156a74 0xa0156a74-0xa0156d1c (680 bytes)
a0156a74:  80 92 40 08  orcc  %o1, %o0, %g0
a0156a78:  16 80 00 08  bge  0xa0156a98
a0156a7c:  86 1a 40 08  xor  %o1, %o0, %g3
a0156a80:  80 92 40 00  tst  %o1
a0156a84:  16 80 00 04  bge  0xa0156a94
a0156a88:  80 92 00 00  tst  %o0
a0156a8c:  16 80 00 03  bge  0xa0156a98
a0156a90:  92 20 00 09  neg  %o1
a0156a94:  90 20 00 08  neg  %o0
a0156a98:  9a 92 40 00  orcc  %o1, %g0, %o5
a0156a9c:  12 80 00 05  bne  0xa0156ab0
a0156aa0:  96 10 00 08  mov  %o0, %o3
a0156aa4:  91 d0 20 02  ta  2
a0156aa8:  81 c3 e0 08  retl
a0156aac:  90 10 00 00  mov  %g0, %o0
a0156ab0:  80 a2 c0 0d  cmp  %o3, %o5
a0156ab4:  0a 80 00 95  bcs  0xa0156d08
a0156ab8:  94 10 00 00  mov  %g0, %o2
a0156abc:  03 02 00 00  sethi  %hi(0x8000000), %g1
a0156ac0:  80 a2 c0 01  cmp  %o3, %g1
a0156ac4:  0a 80 00 28  bcs  0xa0156b64
a0156ac8:  98 10 00 00  mov  %g0, %o4
a0156acc:  80 a3 40 01  cmp  %o5, %g1
a0156ad0:  1a 80 00 0d  bcc  0xa0156b04
a0156ad4:  84 10 20 01  mov  1, %g2
a0156ad8:  9b 2b 60 04  sll  %o5, 4, %o5
a0156adc:  10 bf ff fc  b  0xa0156acc
a0156ae0:  98 03 20 01  inc  %o4
a0156ae4:  9a 83 40 0d  addcc  %o5, %o5, %o5
a0156ae8:  1a 80 00 07  bcc  0xa0156b04
a0156aec:  84 00 a0 01  inc  %g2
a0156af0:  83 28 60 04  sll  %g1, 4, %g1
a0156af4:  9b 33 60 01  srl  %o5, 1, %o5
a0156af8:  9a 03 40 01  add  %o5, %g1, %o5
a0156afc:  10 80 00 07  b  0xa0156b18
a0156b00:  84 20 a0 01  dec  %g2
a0156b04:  80 a3 40 0b  cmp  %o5, %o3
a0156b08:  0a bf ff f7  bcs  0xa0156ae4
a0156b0c:  01 00 00 00  nop
a0156b10:  02 80 00 02  be  0xa0156b18
a0156b14:  01 00 00 00  nop
a0156b18:  84 a0 a0 01  deccc  %g2
a0156b1c:  06 80 00 76  bl  0xa0156cf4
a0156b20:  01 00 00 00  nop
a0156b24:  96 22 c0 0d  sub  %o3, %o5, %o3
a0156b28:  94 10 20 01  mov  1, %o2
a0156b2c:  10 80 00 0a  b  0xa0156b54
a0156b30:  01 00 00 00  nop
a0156b34:  95 2a a0 01  sll  %o2, 1, %o2
a0156b38:  06 80 00 05  bl  0xa0156b4c
a0156b3c:  9b 33 60 01  srl  %o5, 1, %o5
a0156b40:  96 22 c0 0d  sub  %o3, %o5, %o3
a0156b44:  10 80 00 04  b  0xa0156b54
a0156b48:  94 02 a0 01  inc  %o2
a0156b4c:  96 02 c0 0d  add  %o3, %o5, %o3
a0156b50:  94 22 a0 01  dec  %o2
a0156b54:  84 a0 a0 01  deccc  %g2
a0156b58:  16 bf ff f7  bge  0xa0156b34
a0156b5c:  80 92 c0 00  tst  %o3
a0156b60:  30 80 00 65  b,a   0xa0156cf4
a0156b64:  9b 2b 60 04  sll  %o5, 4, %o5
a0156b68:  80 a3 40 0b  cmp  %o5, %o3
a0156b6c:  08 bf ff fe  bleu  0xa0156b64
a0156b70:  98 83 20 01  inccc  %o4
a0156b74:  02 80 00 65  be  0xa0156d08
a0156b78:  98 23 20 01  dec  %o4
a0156b7c:  80 92 c0 00  tst  %o3
a0156b80:  95 2a a0 04  sll  %o2, 4, %o2
a0156b84:  06 80 00 2f  bl  0xa0156c40
a0156b88:  9b 33 60 01  srl  %o5, 1, %o5
a0156b8c:  96 a2 c0 0d  subcc  %o3, %o5, %o3
a0156b90:  06 80 00 17  bl  0xa0156bec
a0156b94:  9b 33 60 01  srl  %o5, 1, %o5
a0156b98:  96 a2 c0 0d  subcc  %o3, %o5, %o3
a0156b9c:  06 80 00 0b  bl  0xa0156bc8
a0156ba0:  9b 33 60 01  srl  %o5, 1, %o5
a0156ba4:  96 a2 c0 0d  subcc  %o3, %o5, %o3
a0156ba8:  06 80 00 05  bl  0xa0156bbc
a0156bac:  9b 33 60 01  srl  %o5, 1, %o5
a0156bb0:  96 a2 c0 0d  subcc  %o3, %o5, %o3
a0156bb4:  10 80 00 50  b  0xa0156cf4
a0156bb8:  94 02 a0 0f  add  %o2, 0xf, %o2
a0156bbc:  96 82 c0 0d  addcc  %o3, %o5, %o3
a0156bc0:  10 80 00 4d  b  0xa0156cf4
a0156bc4:  94 02 a0 0d  add  %o2, 0xd, %o2
a0156bc8:  96 82 c0 0d  addcc  %o3, %o5, %o3
a0156bcc:  06 80 00 05  bl  0xa0156be0
a0156bd0:  9b 33 60 01  srl  %o5, 1, %o5
a0156bd4:  96 a2 c0 0d  subcc  %o3, %o5, %o3
a0156bd8:  10 80 00 47  b  0xa0156cf4
a0156bdc:  94 02 a0 0b  add  %o2, 0xb, %o2
a0156be0:  96 82 c0 0d  addcc  %o3, %o5, %o3
a0156be4:  10 80 00 44  b  0xa0156cf4
a0156be8:  94 02 a0 09  add  %o2, 9, %o2
a0156bec:  96 82 c0 0d  addcc  %o3, %o5, %o3
a0156bf0:  06 80 00 0b  bl  0xa0156c1c
a0156bf4:  9b 33 60 01  srl  %o5, 1, %o5
a0156bf8:  96 a2 c0 0d  subcc  %o3, %o5, %o3
a0156bfc:  06 80 00 05  bl  0xa0156c10
a0156c00:  9b 33 60 01  srl  %o5, 1, %o5
a0156c04:  96 a2 c0 0d  subcc  %o3, %o5, %o3
a0156c08:  10 80 00 3b  b  0xa0156cf4
a0156c0c:  94 02 a0 07  add  %o2, 7, %o2
a0156c10:  96 82 c0 0d  addcc  %o3, %o5, %o3
a0156c14:  10 80 00 38  b  0xa0156cf4
a0156c18:  94 02 a0 05  add  %o2, 5, %o2
a0156c1c:  96 82 c0 0d  addcc  %o3, %o5, %o3
a0156c20:  06 80 00 05  bl  0xa0156c34
a0156c24:  9b 33 60 01  srl  %o5, 1, %o5
a0156c28:  96 a2 c0 0d  subcc  %o3, %o5, %o3
a0156c2c:  10 80 00 32  b  0xa0156cf4
a0156c30:  94 02 a0 03  add  %o2, 3, %o2
a0156c34:  96 82 c0 0d  addcc  %o3, %o5, %o3
a0156c38:  10 80 00 2f  b  0xa0156cf4
a0156c3c:  94 02 a0 01  inc  %o2
a0156c40:  96 82 c0 0d  addcc  %o3, %o5, %o3
a0156c44:  06 80 00 17  bl  0xa0156ca0
a0156c48:  9b 33 60 01  srl  %o5, 1, %o5
a0156c4c:  96 a2 c0 0d  subcc  %o3, %o5, %o3
a0156c50:  06 80 00 0b  bl  0xa0156c7c
a0156c54:  9b 33 60 01  srl  %o5, 1, %o5
a0156c58:  96 a2 c0 0d  subcc  %o3, %o5, %o3
a0156c5c:  06 80 00 05  bl  0xa0156c70
a0156c60:  9b 33 60 01  srl  %o5, 1, %o5
a0156c64:  96 a2 c0 0d  subcc  %o3, %o5, %o3
a0156c68:  10 80 00 23  b  0xa0156cf4
a0156c6c:  94 02 bf ff  add  %o2, -1, %o2
a0156c70:  96 82 c0 0d  addcc  %o3, %o5, %o3
a0156c74:  10 80 00 20  b  0xa0156cf4
a0156c78:  94 02 bf fd  add  %o2, -3, %o2
a0156c7c:  96 82 c0 0d  addcc  %o3, %o5, %o3
a0156c80:  06 80 00 05  bl  0xa0156c94
a0156c84:  9b 33 60 01  srl  %o5, 1, %o5
a0156c88:  96 a2 c0 0d  subcc  %o3, %o5, %o3
a0156c8c:  10 80 00 1a  b  0xa0156cf4
a0156c90:  94 02 bf fb  add  %o2, -5, %o2
a0156c94:  96 82 c0 0d  addcc  %o3, %o5, %o3
a0156c98:  10 80 00 17  b  0xa0156cf4
a0156c9c:  94 02 bf f9  add  %o2, -7, %o2
a0156ca0:  96 82 c0 0d  addcc  %o3, %o5, %o3
a0156ca4:  06 80 00 0b  bl  0xa0156cd0
a0156ca8:  9b 33 60 01  srl  %o5, 1, %o5
a0156cac:  96 a2 c0 0d  subcc  %o3, %o5, %o3
a0156cb0:  06 80 00 05  bl  0xa0156cc4
a0156cb4:  9b 33 60 01  srl  %o5, 1, %o5
a0156cb8:  96 a2 c0 0d  subcc  %o3, %o5, %o3
a0156cbc:  10 80 00 0e  b  0xa0156cf4
a0156cc0:  94 02 bf f7  add  %o2, -9, %o2
a0156cc4:  96 82 c0 0d  addcc  %o3, %o5, %o3
a0156cc8:  10 80 00 0b  b  0xa0156cf4
a0156ccc:  94 02 bf f5  add  %o2, -11, %o2
a0156cd0:  96 82 c0 0d  addcc  %o3, %o5, %o3
a0156cd4:  06 80 00 05  bl  0xa0156ce8
a0156cd8:  9b 33 60 01  srl  %o5, 1, %o5
a0156cdc:  96 a2 c0 0d  subcc  %o3, %o5, %o3
a0156ce0:  10 80 00 05  b  0xa0156cf4
a0156ce4:  94 02 bf f3  add  %o2, -13, %o2
a0156ce8:  96 82 c0 0d  addcc  %o3, %o5, %o3
a0156cec:  10 80 00 02  b  0xa0156cf4
a0156cf0:  94 02 bf f1  add  %o2, -15, %o2
a0156cf4:  98 a3 20 01  deccc  %o4
a0156cf8:  16 bf ff a2  bge  0xa0156b80
a0156cfc:  80 92 c0 00  tst  %o3
a0156d00:  26 80 00 02  bl,a   0xa0156d08
a0156d04:  94 22 a0 01  dec  %o2
a0156d08:  80 90 c0 00  tst  %g3
a0156d0c:  26 80 00 02  bl,a   0xa0156d14
a0156d10:  94 20 00 0a  neg  %o2
a0156d14:  81 c3 e0 08  retl
a0156d18:  90 10 00 0a  mov  %o2, %o0
