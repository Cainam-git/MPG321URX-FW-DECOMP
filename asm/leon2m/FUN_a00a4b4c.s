# leon2m FUN_a00a4b4c 0xa00a4b4c-0xa00a4cac (352 bytes)
a00a4b4c:  9d e3 bf 98  save  %sp, -104, %sp
a00a4b50:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00a4b54:  98 12 22 90  or  %o0, 0x290, %o4	! 0xa802d290
a00a4b58:  da 03 20 a8  ld  [ %o4 + 0xa8 ], %o5
a00a4b5c:  03 00 00 04  sethi  %hi(0x1000), %g1
a00a4b60:  80 8b 40 01  btst  %o5, %g1
a00a4b64:  22 80 00 4d  be,a   0xa00a4c98
a00a4b68:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00a4b6c:  17 00 00 04  sethi  %hi(0x1000), %o3
a00a4b70:  94 2b 40 0b  andn  %o5, %o3, %o2
a00a4b74:  a3 32 a0 0c  srl  %o2, 0xc, %l1
a00a4b78:  d4 23 20 a8  st  %o2, [ %o4 + 0xa8 ]
a00a4b7c:  a0 0c 60 01  and  %l1, 1, %l0
a00a4b80:  90 10 20 05  mov  5, %o0
a00a4b84:  92 10 20 08  mov  8, %o1
a00a4b88:  94 10 20 04  mov  4, %o2
a00a4b8c:  96 10 27 92  mov  0x792, %o3
a00a4b90:  98 10 20 00  clr  %o4
a00a4b94:  40 02 87 bb  call  0xa0146a80
a00a4b98:  a2 0c 20 ff  and  %l0, 0xff, %l1
a00a4b9c:  80 a4 60 00  cmp  %l1, 0
a00a4ba0:  02 80 00 22  be  0xa00a4c28
a00a4ba4:  a0 10 20 00  clr  %l0
a00a4ba8:  9a 0c 20 ff  and  %l0, 0xff, %o5
a00a4bac:  96 03 60 09  add  %o5, 9, %o3
a00a4bb0:  95 2a e0 10  sll  %o3, 0x10, %o2
a00a4bb4:  93 32 a0 10  srl  %o2, 0x10, %o1
a00a4bb8:  98 04 20 1e  add  %l0, 0x1e, %o4
a00a4bbc:  98 0b 20 ff  and  %o4, 0xff, %o4
a00a4bc0:  90 10 20 00  clr  %o0
a00a4bc4:  94 10 20 08  mov  8, %o2
a00a4bc8:  96 10 20 01  mov  1, %o3
a00a4bcc:  40 02 87 d5  call  0xa0146b20
a00a4bd0:  9a 10 20 00  clr  %o5
a00a4bd4:  a0 04 20 01  inc  %l0
a00a4bd8:  92 0c 20 ff  and  %l0, 0xff, %o1
a00a4bdc:  80 a2 60 03  cmp  %o1, 3
a00a4be0:  08 bf ff f3  bleu  0xa00a4bac
a00a4be4:  9a 0c 20 ff  and  %l0, 0xff, %o5
a00a4be8:  80 a4 60 00  cmp  %l1, 0
a00a4bec:  12 80 00 21  bne  0xa00a4c70
a00a4bf0:  90 10 20 03  mov  3, %o0
a00a4bf4:  92 10 20 08  mov  8, %o1
a00a4bf8:  94 10 20 05  mov  5, %o2
a00a4bfc:  96 10 27 92  mov  0x792, %o3
a00a4c00:  40 02 87 a0  call  0xa0146a80
a00a4c04:  98 10 20 00  clr  %o4
a00a4c08:  90 10 20 0e  mov  0xe, %o0
a00a4c0c:  92 10 20 08  mov  8, %o1
a00a4c10:  94 10 20 05  mov  5, %o2
a00a4c14:  96 10 29 92  mov  0x992, %o3
a00a4c18:  40 02 87 9a  call  0xa0146a80
a00a4c1c:  98 10 20 00  clr  %o4
a00a4c20:  10 80 00 1e  b  0xa00a4c98
a00a4c24:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00a4c28:  98 0c 20 ff  and  %l0, 0xff, %o4
a00a4c2c:  92 03 20 09  add  %o4, 9, %o1
a00a4c30:  91 2a 60 10  sll  %o1, 0x10, %o0
a00a4c34:  82 04 20 22  add  %l0, 0x22, %g1
a00a4c38:  93 32 20 10  srl  %o0, 0x10, %o1
a00a4c3c:  98 08 60 ff  and  %g1, 0xff, %o4
a00a4c40:  90 10 20 00  clr  %o0
a00a4c44:  94 10 20 08  mov  8, %o2
a00a4c48:  96 10 20 01  mov  1, %o3
a00a4c4c:  40 02 87 b5  call  0xa0146b20
a00a4c50:  9a 10 20 00  clr  %o5
a00a4c54:  a0 04 20 01  inc  %l0
a00a4c58:  9e 0c 20 ff  and  %l0, 0xff, %o7
a00a4c5c:  80 a3 e0 03  cmp  %o7, 3
a00a4c60:  08 bf ff f3  bleu  0xa00a4c2c
a00a4c64:  98 0c 20 ff  and  %l0, 0xff, %o4
a00a4c68:  10 bf ff e1  b  0xa00a4bec
a00a4c6c:  80 a4 60 00  cmp  %l1, 0
a00a4c70:  92 10 20 08  mov  8, %o1
a00a4c74:  94 10 20 05  mov  5, %o2
a00a4c78:  96 10 29 92  mov  0x992, %o3
a00a4c7c:  40 02 87 81  call  0xa0146a80
a00a4c80:  98 10 20 00  clr  %o4
a00a4c84:  90 10 20 0e  mov  0xe, %o0
a00a4c88:  92 10 20 08  mov  8, %o1
a00a4c8c:  94 10 20 05  mov  5, %o2
a00a4c90:  10 bf ff e2  b  0xa00a4c18
a00a4c94:  96 10 27 92  mov  0x792, %o3
a00a4c98:  c2 0b 60 8e  ldub  [ %o5 + 0x8e ], %g1
a00a4c9c:  9e 10 60 02  or  %g1, 2, %o7
a00a4ca0:  de 2b 60 8e  stb  %o7, [ %o5 + 0x8e ]
a00a4ca4:  81 c7 e0 08  ret
a00a4ca8:  81 e8 00 00  restore
