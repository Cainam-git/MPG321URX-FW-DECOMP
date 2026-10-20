# leon2m FUN_a00b6bec 0xa00b6bec-0xa00b6d58 (364 bytes)
a00b6bec:  9d e3 bf 98  save  %sp, -104, %sp
a00b6bf0:  7f ff c8 26  call  0xa00a8c88
a00b6bf4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00b6bf8:  90 10 21 11  mov  0x111, %o0
a00b6bfc:  40 02 3f d5  call  0xa0146b50
a00b6c00:  92 10 20 00  clr  %o1
a00b6c04:  90 10 20 00  clr  %o0
a00b6c08:  40 02 3f d9  call  0xa0146b6c
a00b6c0c:  92 10 20 00  clr  %o1
a00b6c10:  80 a0 00 18  cmp  %g0, %i0
a00b6c14:  92 60 20 00  subx  %g0, 0, %o1
a00b6c18:  90 0a 7f fa  and  %o1, -6, %o0
a00b6c1c:  82 02 20 07  add  %o0, 7, %g1
a00b6c20:  a4 08 60 ff  and  %g1, 0xff, %l2
a00b6c24:  80 a4 a0 00  cmp  %l2, 0
a00b6c28:  02 80 00 36  be  0xa00b6d00
a00b6c2c:  a2 10 20 00  clr  %l1
a00b6c30:  95 2e 20 03  sll  %i0, 3, %o2
a00b6c34:  b0 22 80 18  sub  %o2, %i0, %i0
a00b6c38:  a0 10 20 00  clr  %l0
a00b6c3c:  29 2a 00 b4  sethi  %hi(0xa802d000), %l4
a00b6c40:  10 80 00 1c  b  0xa00b6cb0
a00b6c44:  27 00 06 54  sethi  %hi(0x195000), %l3
a00b6c48:  02 80 00 20  be  0xa00b6cc8
a00b6c4c:  01 00 00 00  nop
a00b6c50:  96 04 00 18  add  %l0, %i0, %o3
a00b6c54:  99 2a e0 03  sll  %o3, 3, %o4
a00b6c58:  9a 23 00 0b  sub  %o4, %o3, %o5
a00b6c5c:  93 2b 60 02  sll  %o5, 2, %o1
a00b6c60:  94 15 22 90  or  %l4, 0x290, %o2
a00b6c64:  90 02 40 0b  add  %o1, %o3, %o0
a00b6c68:  c2 0a a0 08  ldub  [ %o2 + 8 ], %g1
a00b6c6c:  9e 02 00 01  add  %o0, %g1, %o7
a00b6c70:  99 2b e0 10  sll  %o7, 0x10, %o4
a00b6c74:  93 33 20 10  srl  %o4, 0x10, %o1
a00b6c78:  7f ff b2 f3  call  0xa00a3844
a00b6c7c:  90 14 e1 dc  or  %l3, 0x1dc, %o0
a00b6c80:  9a 04 00 10  add  %l0, %l0, %o5
a00b6c84:  98 10 00 08  mov  %o0, %o4
a00b6c88:  94 03 60 06  add  %o5, 6, %o2
a00b6c8c:  90 10 20 00  clr  %o0
a00b6c90:  92 10 20 2a  mov  0x2a, %o1
a00b6c94:  96 10 20 01  mov  1, %o3
a00b6c98:  7f ff b1 43  call  0xa00a31a4
a00b6c9c:  9a 10 20 00  clr  %o5
a00b6ca0:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00b6ca4:  80 a4 00 12  cmp  %l0, %l2
a00b6ca8:  1a 80 00 17  bcc  0xa00b6d04
a00b6cac:  90 10 27 92  mov  0x792, %o0
a00b6cb0:  80 a4 20 05  cmp  %l0, 5
a00b6cb4:  02 80 00 05  be  0xa00b6cc8
a00b6cb8:  a2 04 60 01  inc  %l1
a00b6cbc:  80 a4 20 06  cmp  %l0, 6
a00b6cc0:  12 bf ff e2  bne  0xa00b6c48
a00b6cc4:  80 a4 20 07  cmp  %l0, 7
a00b6cc8:  40 00 84 20  call  0xa00d7d48
a00b6ccc:  01 00 00 00  nop
a00b6cd0:  96 04 00 10  add  %l0, %l0, %o3
a00b6cd4:  80 a2 20 00  cmp  %o0, 0
a00b6cd8:  92 02 e0 06  add  %o3, 6, %o1
a00b6cdc:  94 10 20 0b  mov  0xb, %o2
a00b6ce0:  96 10 22 96  mov  0x296, %o3
a00b6ce4:  98 10 20 00  clr  %o4
a00b6ce8:  02 bf ff da  be  0xa00b6c50
a00b6cec:  90 10 20 2a  mov  0x2a, %o0
a00b6cf0:  40 02 3f 64  call  0xa0146a80
a00b6cf4:  01 00 00 00  nop
a00b6cf8:  10 bf ff d7  b  0xa00b6c54
a00b6cfc:  96 04 00 18  add  %l0, %i0, %o3
a00b6d00:  90 10 27 92  mov  0x792, %o0
a00b6d04:  40 02 3f 6b  call  0xa0146ab0
a00b6d08:  92 10 20 00  clr  %o1
a00b6d0c:  b0 10 20 00  clr  %i0
a00b6d10:  a8 0e 20 ff  and  %i0, 0xff, %l4
a00b6d14:  a6 05 20 2f  add  %l4, 0x2f, %l3
a00b6d18:  a2 06 20 28  add  %i0, 0x28, %l1
a00b6d1c:  a5 2c e0 10  sll  %l3, 0x10, %l2
a00b6d20:  93 34 a0 10  srl  %l2, 0x10, %o1
a00b6d24:  98 0c 60 ff  and  %l1, 0xff, %o4
a00b6d28:  90 10 20 01  mov  1, %o0
a00b6d2c:  94 10 20 1c  mov  0x1c, %o2
a00b6d30:  96 10 20 01  mov  1, %o3
a00b6d34:  9a 10 20 00  clr  %o5
a00b6d38:  40 02 3f 7a  call  0xa0146b20
a00b6d3c:  b0 06 20 01  inc  %i0
a00b6d40:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00b6d44:  80 a4 20 03  cmp  %l0, 3
a00b6d48:  0a bf ff f3  bcs  0xa00b6d14
a00b6d4c:  a8 0e 20 ff  and  %i0, 0xff, %l4
a00b6d50:  81 c7 e0 08  ret
a00b6d54:  81 e8 00 00  restore
