# leon2s FUN_a00d8b90 0xa00d8b90-0xa00d8d20 (400 bytes)
a00d8b90:  9d e3 be 80  save  %sp, -384, %sp
a00d8b94:  a6 07 be e8  add  %fp, -280, %l3
a00d8b98:  92 10 20 00  clr  %o1
a00d8b9c:  94 10 21 0c  mov  0x10c, %o2
a00d8ba0:  40 3b a2 83  call  0xa0fc15ac
a00d8ba4:  90 10 00 13  mov  %l3, %o0
a00d8ba8:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a00d8bac:  aa 10 60 a4  or  %g1, 0xa4, %l5	! 0xa80760a4
a00d8bb0:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a00d8bb4:  a8 10 60 3c  or  %g1, 0x3c, %l4	! 0xa00b383c
a00d8bb8:  90 10 00 13  mov  %l3, %o0
a00d8bbc:  92 10 20 00  clr  %o1
a00d8bc0:  94 10 20 01  mov  1, %o2
a00d8bc4:  7f ff f9 fc  call  0xa00d73b4
a00d8bc8:  96 10 20 18  mov  0x18, %o3
a00d8bcc:  c2 07 be e0  ld  [ %fp + -288 ], %g1
a00d8bd0:  19 1f c0 00  sethi  %hi(0x7f000000), %o4
a00d8bd4:  98 28 40 0c  andn  %g1, %o4, %o4
a00d8bd8:  1b 08 40 00  sethi  %hi(0x21000000), %o5
a00d8bdc:  c2 07 be e8  ld  [ %fp + -280 ], %g1
a00d8be0:  98 13 00 0d  or  %o4, %o5, %o4
a00d8be4:  83 30 60 14  srl  %g1, 0x14, %g1
a00d8be8:  82 08 60 0f  and  %g1, 0xf, %g1
a00d8bec:  1b 00 03 c0  sethi  %hi(0xf0000), %o5
a00d8bf0:  83 28 60 10  sll  %g1, 0x10, %g1
a00d8bf4:  9a 2b 00 0d  andn  %o4, %o5, %o5
a00d8bf8:  9a 13 40 01  or  %o5, %g1, %o5
a00d8bfc:  83 33 60 10  srl  %o5, 0x10, %g1
a00d8c00:  82 08 60 0f  and  %g1, 0xf, %g1
a00d8c04:  80 a0 60 01  cmp  %g1, 1
a00d8c08:  da 27 be e0  st  %o5, [ %fp + -288 ]
a00d8c0c:  25 2a 01 e2  sethi  %hi(0xa8078800), %l2
a00d8c10:  e2 0f be f0  ldub  [ %fp + -272 ], %l1
a00d8c14:  12 80 00 21  bne  0xa00d8c98
a00d8c18:  b0 10 20 00  clr  %i0
a00d8c1c:  9b 2c 60 10  sll  %l1, 0x10, %o5
a00d8c20:  80 a3 60 00  cmp  %o5, 0
a00d8c24:  02 80 00 36  be  0xa00d8cfc
a00d8c28:  83 33 60 10  srl  %o5, 0x10, %g1
a00d8c2c:  80 a0 60 10  cmp  %g1, 0x10
a00d8c30:  08 80 00 05  bleu  0xa00d8c44
a00d8c34:  a0 10 00 11  mov  %l1, %l0
a00d8c38:  a0 10 20 10  mov  0x10, %l0
a00d8c3c:  10 80 00 03  b  0xa00d8c48
a00d8c40:  a2 04 7f f0  add  %l1, -16, %l1
a00d8c44:  a2 10 20 00  clr  %l1
a00d8c48:  99 2e 20 10  sll  %i0, 0x10, %o4
a00d8c4c:  99 33 20 10  srl  %o4, 0x10, %o4
a00d8c50:  98 04 c0 0c  add  %l3, %o4, %o4
a00d8c54:  97 2c 20 18  sll  %l0, 0x18, %o3
a00d8c58:  97 3a e0 18  sra  %o3, 0x18, %o3
a00d8c5c:  98 03 20 09  add  %o4, 9, %o4
a00d8c60:  90 10 20 00  clr  %o0
a00d8c64:  92 10 20 80  mov  0x80, %o1
a00d8c68:  40 3a f5 db  call  0xa0f963d4
a00d8c6c:  d4 07 be ec  ld  [ %fp + -276 ], %o2
a00d8c70:  82 0c 20 ff  and  %l0, 0xff, %g1
a00d8c74:  9b 2c 60 10  sll  %l1, 0x10, %o5
a00d8c78:  80 8a 20 ff  btst  0xff, %o0
a00d8c7c:  12 bf ff e9  bne  0xa00d8c20
a00d8c80:  b0 06 00 01  add  %i0, %g1, %i0
a00d8c84:  11 27 c7 32  sethi  %hi(0x9f1cc800), %o0
a00d8c88:  40 3a aa 0f  call  0xa0f834c4
a00d8c8c:  90 12 21 f0  or  %o0, 0x1f0, %o0	! 0x9f1cc9f0
a00d8c90:  10 80 00 22  b  0xa00d8d18
a00d8c94:  b0 10 20 00  clr  %i0
a00d8c98:  c2 07 be ec  ld  [ %fp + -276 ], %g1
a00d8c9c:  80 a0 61 60  cmp  %g1, 0x160
a00d8ca0:  12 80 00 0e  bne  0xa00d8cd8
a00d8ca4:  80 a0 61 07  cmp  %g1, 0x107
a00d8ca8:  c2 0c a0 32  ldub  [ %l2 + 0x32 ], %g1
a00d8cac:  83 28 60 02  sll  %g1, 2, %g1
a00d8cb0:  e2 05 40 01  ld  [ %l5 + %g1 ], %l1
a00d8cb4:  7f ff fb d1  call  0xa00d7bf8
a00d8cb8:  e0 15 20 82  lduh  [ %l4 + 0x82 ], %l0
a00d8cbc:  a1 2c 20 02  sll  %l0, 2, %l0
a00d8cc0:  c2 0f be f1  ldub  [ %fp + -271 ], %g1
a00d8cc4:  c2 24 40 10  st  %g1, [ %l1 + %l0 ]
a00d8cc8:  7f ff fb f7  call  0xa00d7ca4
a00d8ccc:  01 00 00 00  nop
a00d8cd0:  c2 07 be ec  ld  [ %fp + -276 ], %g1
a00d8cd4:  80 a0 61 07  cmp  %g1, 0x107
a00d8cd8:  12 80 00 0a  bne  0xa00d8d00
a00d8cdc:  90 07 be e0  add  %fp, -288, %o0
a00d8ce0:  c2 0c a0 32  ldub  [ %l2 + 0x32 ], %g1
a00d8ce4:  83 28 60 02  sll  %g1, 2, %g1
a00d8ce8:  d8 05 40 01  ld  [ %l5 + %g1 ], %o4
a00d8cec:  da 15 20 68  lduh  [ %l4 + 0x68 ], %o5
a00d8cf0:  9b 2b 60 02  sll  %o5, 2, %o5
a00d8cf4:  c2 0f be f1  ldub  [ %fp + -271 ], %g1
a00d8cf8:  c2 23 00 0d  st  %g1, [ %o4 + %o5 ]
a00d8cfc:  90 07 be e0  add  %fp, -288, %o0
a00d8d00:  92 10 20 02  mov  2, %o1
a00d8d04:  94 10 20 01  mov  1, %o2
a00d8d08:  96 10 20 08  mov  8, %o3
a00d8d0c:  7f ff fb 04  call  0xa00d791c
a00d8d10:  98 10 20 02  mov  2, %o4
a00d8d14:  b0 10 20 01  mov  1, %i0
a00d8d18:  81 c7 e0 08  ret
a00d8d1c:  81 e8 00 00  restore
