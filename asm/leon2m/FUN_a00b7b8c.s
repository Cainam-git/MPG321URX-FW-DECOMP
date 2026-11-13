# leon2m FUN_a00b7b8c 0xa00b7b8c-0xa00b7d14 (392 bytes)
a00b7b8c:  9d e3 bf 98  save  %sp, -104, %sp
a00b7b90:  90 10 21 11  mov  0x111, %o0
a00b7b94:  40 02 3b ef  call  0xa0146b50
a00b7b98:  92 10 20 00  clr  %o1
a00b7b9c:  90 10 20 00  clr  %o0
a00b7ba0:  40 02 3b f3  call  0xa0146b6c
a00b7ba4:  92 10 20 00  clr  %o1
a00b7ba8:  90 10 20 2d  mov  0x2d, %o0
a00b7bac:  92 10 20 14  mov  0x14, %o1
a00b7bb0:  94 10 20 02  mov  2, %o2
a00b7bb4:  96 10 26 92  mov  0x692, %o3
a00b7bb8:  40 02 3b b2  call  0xa0146a80
a00b7bbc:  98 10 20 00  clr  %o4
a00b7bc0:  80 8e 20 ff  btst  0xff, %i0
a00b7bc4:  32 80 00 23  bne,a   0xa00b7c50
a00b7bc8:  a0 10 20 07  mov  7, %l0
a00b7bcc:  a0 10 20 00  clr  %l0
a00b7bd0:  b0 10 20 00  clr  %i0
a00b7bd4:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a00b7bd8:  23 00 06 4d  sethi  %hi(0x193400), %l1
a00b7bdc:  95 2e 20 03  sll  %i0, 3, %o2
a00b7be0:  9e 22 80 18  sub  %o2, %i0, %o7
a00b7be4:  99 2b e0 02  sll  %o7, 2, %o4
a00b7be8:  9a 14 a2 90  or  %l2, 0x290, %o5
a00b7bec:  96 03 00 18  add  %o4, %i0, %o3
a00b7bf0:  c2 0b 60 08  ldub  [ %o5 + 8 ], %g1
a00b7bf4:  90 02 c0 01  add  %o3, %g1, %o0
a00b7bf8:  93 2a 20 10  sll  %o0, 0x10, %o1
a00b7bfc:  93 32 60 10  srl  %o1, 0x10, %o1
a00b7c00:  7f ff af 11  call  0xa00a3844
a00b7c04:  90 14 61 bc  or  %l1, 0x1bc, %o0
a00b7c08:  98 10 00 08  mov  %o0, %o4
a00b7c0c:  94 06 00 18  add  %i0, %i0, %o2
a00b7c10:  94 02 a0 06  add  %o2, 6, %o2
a00b7c14:  90 10 20 00  clr  %o0
a00b7c18:  92 10 20 2a  mov  0x2a, %o1
a00b7c1c:  96 10 20 01  mov  1, %o3
a00b7c20:  9a 10 20 00  clr  %o5
a00b7c24:  7f ff ad 60  call  0xa00a31a4
a00b7c28:  a0 04 20 01  inc  %l0
a00b7c2c:  b0 0c 20 ff  and  %l0, 0xff, %i0
a00b7c30:  80 a6 20 06  cmp  %i0, 6
a00b7c34:  08 bf ff eb  bleu  0xa00b7be0
a00b7c38:  95 2e 20 03  sll  %i0, 3, %o2
a00b7c3c:  90 10 27 92  mov  0x792, %o0
a00b7c40:  40 02 3b 9c  call  0xa0146ab0
a00b7c44:  92 10 20 00  clr  %o1
a00b7c48:  10 80 00 21  b  0xa00b7ccc
a00b7c4c:  b0 10 20 00  clr  %i0
a00b7c50:  b0 10 20 07  mov  7, %i0
a00b7c54:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a00b7c58:  23 00 06 4d  sethi  %hi(0x193400), %l1
a00b7c5c:  91 2e 20 03  sll  %i0, 3, %o0
a00b7c60:  92 22 00 18  sub  %o0, %i0, %o1
a00b7c64:  95 2a 60 02  sll  %o1, 2, %o2
a00b7c68:  9e 14 a2 90  or  %l2, 0x290, %o7
a00b7c6c:  98 02 80 18  add  %o2, %i0, %o4
a00b7c70:  c2 0b e0 08  ldub  [ %o7 + 8 ], %g1
a00b7c74:  9a 03 00 01  add  %o4, %g1, %o5
a00b7c78:  97 2b 60 10  sll  %o5, 0x10, %o3
a00b7c7c:  93 32 e0 10  srl  %o3, 0x10, %o1
a00b7c80:  7f ff ae f1  call  0xa00a3844
a00b7c84:  90 14 61 bc  or  %l1, 0x1bc, %o0
a00b7c88:  98 10 00 08  mov  %o0, %o4
a00b7c8c:  90 06 00 18  add  %i0, %i0, %o0
a00b7c90:  92 02 3f f8  add  %o0, -8, %o1
a00b7c94:  b1 2a 60 10  sll  %o1, 0x10, %i0
a00b7c98:  95 36 20 10  srl  %i0, 0x10, %o2
a00b7c9c:  90 10 20 00  clr  %o0
a00b7ca0:  92 10 20 2a  mov  0x2a, %o1
a00b7ca4:  96 10 20 01  mov  1, %o3
a00b7ca8:  9a 10 20 00  clr  %o5
a00b7cac:  7f ff ad 3e  call  0xa00a31a4
a00b7cb0:  a0 04 20 01  inc  %l0
a00b7cb4:  b0 0c 20 ff  and  %l0, 0xff, %i0
a00b7cb8:  80 a6 20 0b  cmp  %i0, 0xb
a00b7cbc:  28 bf ff e9  bleu,a   0xa00b7c60
a00b7cc0:  91 2e 20 03  sll  %i0, 3, %o0
a00b7cc4:  10 bf ff df  b  0xa00b7c40
a00b7cc8:  90 10 27 92  mov  0x792, %o0
a00b7ccc:  9a 0e 20 ff  and  %i0, 0xff, %o5
a00b7cd0:  96 03 60 2d  add  %o5, 0x2d, %o3
a00b7cd4:  a5 2a e0 10  sll  %o3, 0x10, %l2
a00b7cd8:  a2 06 20 28  add  %i0, 0x28, %l1
a00b7cdc:  93 34 a0 10  srl  %l2, 0x10, %o1
a00b7ce0:  98 0c 60 ff  and  %l1, 0xff, %o4
a00b7ce4:  90 10 20 01  mov  1, %o0
a00b7ce8:  94 10 20 15  mov  0x15, %o2
a00b7cec:  96 10 20 01  mov  1, %o3
a00b7cf0:  9a 10 20 00  clr  %o5
a00b7cf4:  40 02 3b 8b  call  0xa0146b20
a00b7cf8:  b0 06 20 01  inc  %i0
a00b7cfc:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00b7d00:  80 a4 20 02  cmp  %l0, 2
a00b7d04:  0a bf ff f3  bcs  0xa00b7cd0
a00b7d08:  9a 0e 20 ff  and  %i0, 0xff, %o5
a00b7d0c:  81 c7 e0 08  ret
a00b7d10:  81 e8 00 00  restore
