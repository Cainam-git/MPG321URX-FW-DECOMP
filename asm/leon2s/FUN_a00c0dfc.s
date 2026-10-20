# leon2s FUN_a00c0dfc 0xa00c0dfc-0xa00c0ecc (208 bytes)
a00c0dfc:  9d e3 bf 98  save  %sp, -104, %sp
a00c0e00:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c0e04:  90 10 00 18  mov  %i0, %o0
a00c0e08:  92 10 20 40  mov  0x40, %o1
a00c0e0c:  94 10 20 08  mov  8, %o2
a00c0e10:  40 3b d7 24  call  0xa0fb6aa0
a00c0e14:  96 10 20 01  mov  1, %o3
a00c0e18:  a2 10 20 00  clr  %l1
a00c0e1c:  92 04 60 1a  add  %l1, 0x1a, %o1
a00c0e20:  83 2c 60 10  sll  %l1, 0x10, %g1
a00c0e24:  83 30 60 10  srl  %g1, 0x10, %g1
a00c0e28:  93 2a 60 10  sll  %o1, 0x10, %o1
a00c0e2c:  d4 0e 40 01  ldub  [ %i1 + %g1 ], %o2
a00c0e30:  93 32 60 10  srl  %o1, 0x10, %o1
a00c0e34:  40 3b d6 f2  call  0xa0fb69fc
a00c0e38:  90 10 00 18  mov  %i0, %o0
a00c0e3c:  9a 04 60 01  add  %l1, 1, %o5
a00c0e40:  83 2b 60 10  sll  %o5, 0x10, %g1
a00c0e44:  83 30 60 10  srl  %g1, 0x10, %g1
a00c0e48:  80 a0 60 04  cmp  %g1, 4
a00c0e4c:  08 bf ff f4  bleu  0xa00c0e1c
a00c0e50:  a2 10 00 0d  mov  %o5, %l1
a00c0e54:  92 10 20 a0  mov  0xa0, %o1
a00c0e58:  40 3b d6 d7  call  0xa0fb69b4
a00c0e5c:  90 10 00 18  mov  %i0, %o0
a00c0e60:  90 10 00 18  mov  %i0, %o0
a00c0e64:  92 10 20 a0  mov  0xa0, %o1
a00c0e68:  40 3b d6 e5  call  0xa0fb69fc
a00c0e6c:  94 10 20 e0  mov  0xe0, %o2
a00c0e70:  a2 10 20 00  clr  %l1
a00c0e74:  94 0c 60 ff  and  %l1, 0xff, %o2
a00c0e78:  90 10 00 18  mov  %i0, %o0
a00c0e7c:  40 3b d6 e0  call  0xa0fb69fc
a00c0e80:  92 10 20 a1  mov  0xa1, %o1
a00c0e84:  a1 2c 60 10  sll  %l1, 0x10, %l0
a00c0e88:  95 34 20 18  srl  %l0, 0x18, %o2
a00c0e8c:  90 10 00 18  mov  %i0, %o0
a00c0e90:  40 3b d6 db  call  0xa0fb69fc
a00c0e94:  92 10 20 a2  mov  0xa2, %o1
a00c0e98:  a1 34 20 10  srl  %l0, 0x10, %l0
a00c0e9c:  90 10 00 18  mov  %i0, %o0
a00c0ea0:  d4 0e 80 10  ldub  [ %i2 + %l0 ], %o2
a00c0ea4:  40 3b d6 d6  call  0xa0fb69fc
a00c0ea8:  92 10 20 a3  mov  0xa3, %o1
a00c0eac:  9a 04 60 01  add  %l1, 1, %o5
a00c0eb0:  83 2b 60 10  sll  %o5, 0x10, %g1
a00c0eb4:  83 30 60 10  srl  %g1, 0x10, %g1
a00c0eb8:  80 a0 61 19  cmp  %g1, 0x119
a00c0ebc:  08 bf ff ee  bleu  0xa00c0e74
a00c0ec0:  a2 10 00 0d  mov  %o5, %l1
a00c0ec4:  81 c7 e0 08  ret
a00c0ec8:  81 e8 00 00  restore
