# leon2s FUN_a00c2de4 0xa00c2de4-0xa00c2f58 (372 bytes)
a00c2de4:  9d e3 bf 98  save  %sp, -104, %sp
a00c2de8:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a00c2dec:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c2df0:  a8 10 61 c8  or  %g1, 0x1c8, %l4
a00c2df4:  40 3b fc 9c  call  0xa0fc2064
a00c2df8:  a7 2e 20 04  sll  %i0, 4, %l3
a00c2dfc:  a4 04 c0 14  add  %l3, %l4, %l2
a00c2e00:  c2 04 a0 08  ld  [ %l2 + 8 ], %g1
a00c2e04:  90 22 00 01  sub  %o0, %g1, %o0
a00c2e08:  80 a2 20 64  cmp  %o0, 0x64
a00c2e0c:  08 80 00 50  bleu  0xa00c2f4c
a00c2e10:  aa 10 20 00  clr  %l5
a00c2e14:  94 10 20 01  mov  1, %o2
a00c2e18:  90 10 00 18  mov  %i0, %o0
a00c2e1c:  40 3b cd ea  call  0xa0fb65c4
a00c2e20:  92 10 20 bb  mov  0xbb, %o1
a00c2e24:  92 10 20 ca  mov  0xca, %o1
a00c2e28:  40 3b cd d5  call  0xa0fb657c
a00c2e2c:  90 10 00 18  mov  %i0, %o0
a00c2e30:  a2 0a 20 ff  and  %o0, 0xff, %l1
a00c2e34:  92 10 20 c9  mov  0xc9, %o1
a00c2e38:  40 3b cd d1  call  0xa0fb657c
a00c2e3c:  90 10 00 18  mov  %i0, %o0
a00c2e40:  90 0a 20 ff  and  %o0, 0xff, %o0
a00c2e44:  a3 2c 60 08  sll  %l1, 8, %l1
a00c2e48:  a2 04 40 08  add  %l1, %o0, %l1
a00c2e4c:  92 10 20 ce  mov  0xce, %o1
a00c2e50:  40 3b cd cb  call  0xa0fb657c
a00c2e54:  90 10 00 18  mov  %i0, %o0
a00c2e58:  a0 0a 20 ff  and  %o0, 0xff, %l0
a00c2e5c:  90 10 00 18  mov  %i0, %o0
a00c2e60:  40 3b cd c7  call  0xa0fb657c
a00c2e64:  92 10 20 cd  mov  0xcd, %o1
a00c2e68:  a1 2c 20 08  sll  %l0, 8, %l0
a00c2e6c:  90 0a 20 ff  and  %o0, 0xff, %o0
a00c2e70:  a3 2c 60 10  sll  %l1, 0x10, %l1
a00c2e74:  a0 04 00 08  add  %l0, %o0, %l0
a00c2e78:  a3 34 60 10  srl  %l1, 0x10, %l1
a00c2e7c:  80 a4 60 10  cmp  %l1, 0x10
a00c2e80:  a1 2c 20 10  sll  %l0, 0x10, %l0
a00c2e84:  82 60 20 00  subx  %g0, 0, %g1
a00c2e88:  a1 34 20 10  srl  %l0, 0x10, %l0
a00c2e8c:  82 08 60 01  and  %g1, 1, %g1
a00c2e90:  80 a4 20 05  cmp  %l0, 5
a00c2e94:  18 80 00 03  bgu  0xa00c2ea0
a00c2e98:  9a 10 20 01  mov  1, %o5
a00c2e9c:  9a 10 20 00  clr  %o5
a00c2ea0:  80 88 40 0d  btst  %g1, %o5
a00c2ea4:  02 80 00 22  be  0xa00c2f2c
a00c2ea8:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00c2eac:  da 04 c0 14  ld  [ %l3 + %l4 ], %o5
a00c2eb0:  03 00 07 c0  sethi  %hi(0x1f0000), %g1
a00c2eb4:  80 8b 40 01  btst  %o5, %g1
a00c2eb8:  12 80 00 1d  bne  0xa00c2f2c
a00c2ebc:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00c2ec0:  1b 2a 01 e3  sethi  %hi(0xa8078c00), %o5
a00c2ec4:  98 13 60 80  or  %o5, 0x80, %o4	! 0xa8078c80
a00c2ec8:  c2 0b 00 18  ldub  [ %o4 + %i0 ], %g1
a00c2ecc:  80 a0 60 04  cmp  %g1, 4
a00c2ed0:  08 80 00 06  bleu  0xa00c2ee8
a00c2ed4:  82 00 60 01  inc  %g1
a00c2ed8:  c0 2b 00 18  clrb  [ %o4 + %i0 ]
a00c2edc:  aa 10 20 01  mov  1, %l5
a00c2ee0:  c2 0b 00 18  ldub  [ %o4 + %i0 ], %g1
a00c2ee4:  82 00 60 01  inc  %g1
a00c2ee8:  80 a4 24 00  cmp  %l0, 0x400
a00c2eec:  18 80 00 0b  bgu  0xa00c2f18
a00c2ef0:  c2 2b 00 18  stb  %g1, [ %o4 + %i0 ]
a00c2ef4:  80 a4 23 00  cmp  %l0, 0x300
a00c2ef8:  18 80 00 03  bgu  0xa00c2f04
a00c2efc:  98 10 20 01  mov  1, %o4
a00c2f00:  98 10 20 00  clr  %o4
a00c2f04:  80 a4 60 08  cmp  %l1, 8
a00c2f08:  82 40 20 00  addx  %g0, 0, %g1
a00c2f0c:  80 8b 00 01  btst  %o4, %g1
a00c2f10:  22 80 00 0a  be,a   0xa00c2f38
a00c2f14:  da 04 80 00  ld  [ %l2 ], %o5
a00c2f18:  9a 13 60 80  or  %o5, 0x80, %o5
a00c2f1c:  c2 0b 40 18  ldub  [ %o5 + %i0 ], %g1
a00c2f20:  82 00 60 01  inc  %g1
a00c2f24:  10 80 00 04  b  0xa00c2f34
a00c2f28:  c2 2b 40 18  stb  %g1, [ %o5 + %i0 ]
a00c2f2c:  82 10 60 80  or  %g1, 0x80, %g1
a00c2f30:  c0 28 40 18  clrb  [ %g1 + %i0 ]
a00c2f34:  da 04 80 00  ld  [ %l2 ], %o5
a00c2f38:  03 00 07 c0  sethi  %hi(0x1f0000), %g1
a00c2f3c:  82 2b 40 01  andn  %o5, %g1, %g1
a00c2f40:  40 3b fc 49  call  0xa0fc2064
a00c2f44:  c2 24 80 00  st  %g1, [ %l2 ]
a00c2f48:  d0 24 a0 08  st  %o0, [ %l2 + 8 ]
a00c2f4c:  b0 0d 60 01  and  %l5, 1, %i0
a00c2f50:  81 c7 e0 08  ret
a00c2f54:  81 e8 00 00  restore
