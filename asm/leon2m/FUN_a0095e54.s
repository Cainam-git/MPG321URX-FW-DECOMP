# leon2m FUN_a0095e54 0xa0095e54-0xa0095fb0 (348 bytes)
a0095e54:  9d e3 bf 98  save  %sp, -104, %sp
a0095e58:  27 2a 00 b4  sethi  %hi(0xa802d000), %l3
a0095e5c:  9a 14 e2 90  or  %l3, 0x290, %o5	! 0xa802d290
a0095e60:  d6 0b 61 81  ldub  [ %o5 + 0x181 ], %o3
a0095e64:  13 2a 00 97  sethi  %hi(0xa8025c00), %o1
a0095e68:  94 02 ff fc  add  %o3, -4, %o2
a0095e6c:  d0 0a 60 56  ldub  [ %o1 + 0x56 ], %o0
a0095e70:  82 0a a0 ff  and  %o2, 0xff, %g1
a0095e74:  92 10 20 00  clr  %o1
a0095e78:  80 a0 60 02  cmp  %g1, 2
a0095e7c:  08 80 00 06  bleu  0xa0095e94
a0095e80:  25 2a 00 ab  sethi  %hi(0xa802ac00), %l2
a0095e84:  d8 03 61 1c  ld  [ %o5 + 0x11c ], %o4
a0095e88:  80 8b 20 10  btst  0x10, %o4
a0095e8c:  02 80 00 06  be  0xa0095ea4
a0095e90:  01 00 00 00  nop
a0095e94:  de 0b 61 78  ldub  [ %o5 + 0x178 ], %o7
a0095e98:  80 a3 e0 01  cmp  %o7, 1
a0095e9c:  22 80 00 02  be,a   0xa0095ea4
a0095ea0:  c0 2b 61 78  clrb  [ %o5 + 0x178 ]
a0095ea4:  40 00 83 39  call  0xa00b6b88
a0095ea8:  23 09 24 92  sethi  %hi(0x24924800), %l1
a0095eac:  9e 0a 20 ff  and  %o0, 0xff, %o7
a0095eb0:  a2 14 61 25  or  %l1, 0x125, %l1
a0095eb4:  80 53 c0 11  umul  %o7, %l1, %g0
a0095eb8:  97 40 00 00  rd  %y, %o3
a0095ebc:  a0 23 c0 0b  sub  %o7, %o3, %l0
a0095ec0:  91 34 20 01  srl  %l0, 1, %o0
a0095ec4:  92 02 c0 08  add  %o3, %o0, %o1
a0095ec8:  83 32 60 02  srl  %o1, 2, %g1
a0095ecc:  95 28 60 03  sll  %g1, 3, %o2
a0095ed0:  9a 22 80 01  sub  %o2, %g1, %o5
a0095ed4:  98 23 c0 0d  sub  %o7, %o5, %o4
a0095ed8:  a0 0b 20 ff  and  %o4, 0xff, %l0
a0095edc:  40 00 4d 38  call  0xa00a93bc
a0095ee0:  90 10 00 10  mov  %l0, %o0
a0095ee4:  92 10 00 10  mov  %l0, %o1
a0095ee8:  94 10 20 00  clr  %o2
a0095eec:  40 00 48 94  call  0xa00a813c
a0095ef0:  90 10 20 01  mov  1, %o0
a0095ef4:  d0 04 a3 ec  ld  [ %l2 + 0x3ec ], %o0
a0095ef8:  98 02 3f a4  add  %o0, -92, %o4
a0095efc:  80 53 00 11  umul  %o4, %l1, %g0
a0095f00:  95 40 00 00  rd  %y, %o2
a0095f04:  96 23 00 0a  sub  %o4, %o2, %o3
a0095f08:  93 32 e0 01  srl  %o3, 1, %o1
a0095f0c:  82 02 80 09  add  %o2, %o1, %g1
a0095f10:  a1 30 60 02  srl  %g1, 2, %l0
a0095f14:  9b 2c 20 03  sll  %l0, 3, %o5
a0095f18:  9e 23 40 10  sub  %o5, %l0, %o7
a0095f1c:  96 23 00 0f  sub  %o4, %o7, %o3
a0095f20:  90 0a e0 ff  and  %o3, 0xff, %o0
a0095f24:  40 00 4d cb  call  0xa00a9650
a0095f28:  92 10 20 00  clr  %o1
a0095f2c:  d2 04 a3 ec  ld  [ %l2 + 0x3ec ], %o1
a0095f30:  96 02 7f a4  add  %o1, -92, %o3
a0095f34:  80 52 c0 11  umul  %o3, %l1, %g0
a0095f38:  a1 40 00 00  rd  %y, %l0
a0095f3c:  94 22 c0 10  sub  %o3, %l0, %o2
a0095f40:  83 32 a0 01  srl  %o2, 1, %g1
a0095f44:  90 04 00 01  add  %l0, %g1, %o0
a0095f48:  9b 32 20 02  srl  %o0, 2, %o5
a0095f4c:  9f 2b 60 03  sll  %o5, 3, %o7
a0095f50:  98 23 c0 0d  sub  %o7, %o5, %o4
a0095f54:  94 22 c0 0c  sub  %o3, %o4, %o2
a0095f58:  92 0a a0 ff  and  %o2, 0xff, %o1
a0095f5c:  94 10 20 01  mov  1, %o2
a0095f60:  40 00 48 77  call  0xa00a813c
a0095f64:  90 10 20 01  mov  1, %o0
a0095f68:  82 10 20 15  mov  0x15, %g1
a0095f6c:  c2 24 a3 ec  st  %g1, [ %l2 + 0x3ec ]
a0095f70:  90 10 20 00  clr  %o0
a0095f74:  40 00 4c 26  call  0xa00a900c
a0095f78:  92 10 20 01  mov  1, %o1
a0095f7c:  a2 14 e2 90  or  %l3, 0x290, %l1
a0095f80:  e6 04 60 a8  ld  [ %l1 + 0xa8 ], %l3
a0095f84:  a4 14 e8 00  or  %l3, 0x800, %l2
a0095f88:  40 00 83 74  call  0xa00b6d58
a0095f8c:  e4 24 60 a8  st  %l2, [ %l1 + 0xa8 ]
a0095f90:  40 00 5b 2c  call  0xa00acc40
a0095f94:  01 00 00 00  nop
a0095f98:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a0095f9c:  e0 0b 60 8e  ldub  [ %o5 + 0x8e ], %l0	! 0xa802b08e
a0095fa0:  90 14 20 02  or  %l0, 2, %o0
a0095fa4:  d0 2b 60 8e  stb  %o0, [ %o5 + 0x8e ]
a0095fa8:  81 c7 e0 08  ret
a0095fac:  81 e8 00 00  restore
