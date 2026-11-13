# leon2m FUN_a00a4e08 0xa00a4e08-0xa00a4f68 (352 bytes)
a00a4e08:  9d e3 bf 98  save  %sp, -104, %sp
a00a4e0c:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00a4e10:  98 12 22 90  or  %o0, 0x290, %o4	! 0xa802d290
a00a4e14:  da 03 20 ac  ld  [ %o4 + 0xac ], %o5
a00a4e18:  03 00 10 00  sethi  %hi(0x400000), %g1
a00a4e1c:  80 8b 40 01  btst  %o5, %g1
a00a4e20:  22 80 00 4d  be,a   0xa00a4f54
a00a4e24:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00a4e28:  17 00 10 00  sethi  %hi(0x400000), %o3
a00a4e2c:  94 2b 40 0b  andn  %o5, %o3, %o2
a00a4e30:  a3 32 a0 16  srl  %o2, 0x16, %l1
a00a4e34:  d4 23 20 ac  st  %o2, [ %o4 + 0xac ]
a00a4e38:  a0 0c 60 01  and  %l1, 1, %l0
a00a4e3c:  90 10 20 05  mov  5, %o0
a00a4e40:  92 10 20 08  mov  8, %o1
a00a4e44:  94 10 20 04  mov  4, %o2
a00a4e48:  96 10 27 92  mov  0x792, %o3
a00a4e4c:  98 10 20 00  clr  %o4
a00a4e50:  40 02 87 0c  call  0xa0146a80
a00a4e54:  a2 0c 20 ff  and  %l0, 0xff, %l1
a00a4e58:  80 a4 60 00  cmp  %l1, 0
a00a4e5c:  02 80 00 22  be  0xa00a4ee4
a00a4e60:  a0 10 20 00  clr  %l0
a00a4e64:  9a 0c 20 ff  and  %l0, 0xff, %o5
a00a4e68:  96 03 60 09  add  %o5, 9, %o3
a00a4e6c:  95 2a e0 10  sll  %o3, 0x10, %o2
a00a4e70:  93 32 a0 10  srl  %o2, 0x10, %o1
a00a4e74:  98 04 20 1e  add  %l0, 0x1e, %o4
a00a4e78:  98 0b 20 ff  and  %o4, 0xff, %o4
a00a4e7c:  90 10 20 00  clr  %o0
a00a4e80:  94 10 20 08  mov  8, %o2
a00a4e84:  96 10 20 01  mov  1, %o3
a00a4e88:  40 02 87 26  call  0xa0146b20
a00a4e8c:  9a 10 20 00  clr  %o5
a00a4e90:  a0 04 20 01  inc  %l0
a00a4e94:  92 0c 20 ff  and  %l0, 0xff, %o1
a00a4e98:  80 a2 60 03  cmp  %o1, 3
a00a4e9c:  08 bf ff f3  bleu  0xa00a4e68
a00a4ea0:  9a 0c 20 ff  and  %l0, 0xff, %o5
a00a4ea4:  80 a4 60 00  cmp  %l1, 0
a00a4ea8:  12 80 00 21  bne  0xa00a4f2c
a00a4eac:  90 10 20 03  mov  3, %o0
a00a4eb0:  92 10 20 08  mov  8, %o1
a00a4eb4:  94 10 20 05  mov  5, %o2
a00a4eb8:  96 10 27 92  mov  0x792, %o3
a00a4ebc:  40 02 86 f1  call  0xa0146a80
a00a4ec0:  98 10 20 00  clr  %o4
a00a4ec4:  90 10 20 0e  mov  0xe, %o0
a00a4ec8:  92 10 20 08  mov  8, %o1
a00a4ecc:  94 10 20 05  mov  5, %o2
a00a4ed0:  96 10 29 92  mov  0x992, %o3
a00a4ed4:  40 02 86 eb  call  0xa0146a80
a00a4ed8:  98 10 20 00  clr  %o4
a00a4edc:  10 80 00 1e  b  0xa00a4f54
a00a4ee0:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00a4ee4:  98 0c 20 ff  and  %l0, 0xff, %o4
a00a4ee8:  92 03 20 09  add  %o4, 9, %o1
a00a4eec:  91 2a 60 10  sll  %o1, 0x10, %o0
a00a4ef0:  82 04 20 22  add  %l0, 0x22, %g1
a00a4ef4:  93 32 20 10  srl  %o0, 0x10, %o1
a00a4ef8:  98 08 60 ff  and  %g1, 0xff, %o4
a00a4efc:  90 10 20 00  clr  %o0
a00a4f00:  94 10 20 08  mov  8, %o2
a00a4f04:  96 10 20 01  mov  1, %o3
a00a4f08:  40 02 87 06  call  0xa0146b20
a00a4f0c:  9a 10 20 00  clr  %o5
a00a4f10:  a0 04 20 01  inc  %l0
a00a4f14:  9e 0c 20 ff  and  %l0, 0xff, %o7
a00a4f18:  80 a3 e0 03  cmp  %o7, 3
a00a4f1c:  08 bf ff f3  bleu  0xa00a4ee8
a00a4f20:  98 0c 20 ff  and  %l0, 0xff, %o4
a00a4f24:  10 bf ff e1  b  0xa00a4ea8
a00a4f28:  80 a4 60 00  cmp  %l1, 0
a00a4f2c:  92 10 20 08  mov  8, %o1
a00a4f30:  94 10 20 05  mov  5, %o2
a00a4f34:  96 10 29 92  mov  0x992, %o3
a00a4f38:  40 02 86 d2  call  0xa0146a80
a00a4f3c:  98 10 20 00  clr  %o4
a00a4f40:  90 10 20 0e  mov  0xe, %o0
a00a4f44:  92 10 20 08  mov  8, %o1
a00a4f48:  94 10 20 05  mov  5, %o2
a00a4f4c:  10 bf ff e2  b  0xa00a4ed4
a00a4f50:  96 10 27 92  mov  0x792, %o3
a00a4f54:  c2 0b 60 8e  ldub  [ %o5 + 0x8e ], %g1
a00a4f58:  9e 10 60 02  or  %g1, 2, %o7
a00a4f5c:  de 2b 60 8e  stb  %o7, [ %o5 + 0x8e ]
a00a4f60:  81 c7 e0 08  ret
a00a4f64:  81 e8 00 00  restore
