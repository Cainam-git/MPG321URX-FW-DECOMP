# leon2m FUN_a0150df8 0xa0150df8-0xa0150f44 (332 bytes)
a0150df8:  9d e3 bf 98  save  %sp, -104, %sp
a0150dfc:  7f ff 12 12  call  0xa0115644
a0150e00:  90 10 20 01  mov  1, %o0
a0150e04:  7f ff 09 5e  call  0xa011337c
a0150e08:  90 10 20 03  mov  3, %o0
a0150e0c:  67 fc f5 98  call  0x4008e46c
a0150e10:  90 10 20 18  mov  0x18, %o0
a0150e14:  b0 02 20 30  add  %o0, 0x30, %i0
a0150e18:  11 2a 00 b3  sethi  %hi(0xa802cc00), %o0
a0150e1c:  1b 2a 00 b3  sethi  %hi(0xa802cc00), %o5
a0150e20:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a0150e24:  a8 12 22 90  or  %o0, 0x290, %l4
a0150e28:  a6 13 61 90  or  %o5, 0x190, %l3
a0150e2c:  a4 10 60 90  or  %g1, 0x90, %l2
a0150e30:  a0 10 20 00  clr  %l0
a0150e34:  a2 10 20 00  clr  %l1
a0150e38:  9f 2c 20 10  sll  %l0, 0x10, %o7
a0150e3c:  99 33 e0 10  srl  %o7, 0x10, %o4
a0150e40:  96 03 00 12  add  %o4, %l2, %o3
a0150e44:  90 10 00 18  mov  %i0, %o0
a0150e48:  92 03 00 14  add  %o4, %l4, %o1
a0150e4c:  7f ff 0a df  call  0xa01139c8
a0150e50:  94 03 00 13  add  %o4, %l3, %o2
a0150e54:  92 04 60 01  add  %l1, 1, %o1
a0150e58:  97 2a 60 10  sll  %o1, 0x10, %o3
a0150e5c:  95 32 e0 10  srl  %o3, 0x10, %o2
a0150e60:  80 a2 a0 0f  cmp  %o2, 0xf
a0150e64:  b0 06 20 78  add  %i0, 0x78, %i0
a0150e68:  a0 04 20 10  add  %l0, 0x10, %l0
a0150e6c:  08 bf ff f3  bleu  0xa0150e38
a0150e70:  a2 10 00 09  mov  %o1, %l1
a0150e74:  7f ff 09 42  call  0xa011337c
a0150e78:  91 e8 20 10  restore  %g0, 0x10, %o0
a0150e7c:  01 00 00 00  nop
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
