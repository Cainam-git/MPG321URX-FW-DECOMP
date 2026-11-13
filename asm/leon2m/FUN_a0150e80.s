# leon2m FUN_a0150e80 0xa0150e80-0xa0150f44 (196 bytes)
a0150e80:  90 0a 20 ff  and  %o0, 0xff, %o0
a0150e84:  80 a2 20 01  cmp  %o0, 1
a0150e88:  02 80 00 17  be  0xa0150ee4
a0150e8c:  98 10 3f 80  mov  -128, %o4
a0150e90:  80 a2 20 01  cmp  %o0, 1
a0150e94:  04 80 00 23  ble  0xa0150f20
a0150e98:  80 a2 20 02  cmp  %o0, 2
a0150e9c:  02 80 00 15  be  0xa0150ef0
a0150ea0:  17 2a 00 b8  sethi  %hi(0xa802e000), %o3
a0150ea4:  96 0b 20 ff  and  %o4, 0xff, %o3
a0150ea8:  80 a2 e0 80  cmp  %o3, 0x80
a0150eac:  02 80 00 23  be  0xa0150f38
a0150eb0:  80 8b 20 80  btst  0x80, %o4
a0150eb4:  12 80 00 11  bne  0xa0150ef8
a0150eb8:  91 2a 60 10  sll  %o1, 0x10, %o0
a0150ebc:  98 0b 20 ff  and  %o4, 0xff, %o4
a0150ec0:  82 10 20 80  mov  0x80, %g1
a0150ec4:  82 20 40 0b  sub  %g1, %o3, %g1
a0150ec8:  98 03 00 09  add  %o4, %o1, %o4
a0150ecc:  9b 32 20 10  srl  %o0, 0x10, %o5
a0150ed0:  80 a3 40 01  cmp  %o5, %g1
a0150ed4:  14 80 00 19  bg  0xa0150f38
a0150ed8:  92 03 3f 80  add  %o4, -128, %o1
a0150edc:  10 80 00 17  b  0xa0150f38
a0150ee0:  92 10 20 00  clr  %o1
a0150ee4:  11 2a 00 b8  sethi  %hi(0xa802e000), %o0
a0150ee8:  10 bf ff ef  b  0xa0150ea4
a0150eec:  d8 0a 23 e3  ldub  [ %o0 + 0x3e3 ], %o4	! 0xa802e3e3
a0150ef0:  10 bf ff ed  b  0xa0150ea4
a0150ef4:  d8 0a e3 e4  ldub  [ %o3 + 0x3e4 ], %o4
a0150ef8:  82 0b 20 ff  and  %o4, 0xff, %g1
a0150efc:  9a 00 40 09  add  %g1, %o1, %o5
a0150f00:  96 03 7f 80  add  %o5, -128, %o3
a0150f04:  91 2a e0 10  sll  %o3, 0x10, %o0
a0150f08:  93 32 20 10  srl  %o0, 0x10, %o1
a0150f0c:  80 a2 60 ff  cmp  %o1, 0xff
a0150f10:  08 80 00 0a  bleu  0xa0150f38
a0150f14:  92 10 00 0b  mov  %o3, %o1
a0150f18:  10 80 00 08  b  0xa0150f38
a0150f1c:  92 10 20 ff  mov  0xff, %o1
a0150f20:  80 a2 20 00  cmp  %o0, 0
a0150f24:  12 bf ff e1  bne  0xa0150ea8
a0150f28:  96 0b 20 ff  and  %o4, 0xff, %o3
a0150f2c:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a0150f30:  10 bf ff dd  b  0xa0150ea4
a0150f34:  d8 08 63 e2  ldub  [ %g1 + 0x3e2 ], %o4	! 0xa802e3e2
a0150f38:  99 2a 60 10  sll  %o1, 0x10, %o4
a0150f3c:  81 c3 e0 08  retl
a0150f40:  91 33 20 10  srl  %o4, 0x10, %o0
