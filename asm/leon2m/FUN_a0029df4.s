# leon2m FUN_a0029df4 0xa0029df4-0xa0029f14 (288 bytes)
a0029df4:  9d e3 bf 98  save  %sp, -104, %sp
a0029df8:  17 27 c0 00  sethi  %hi(0x9f000000), %o3
a0029dfc:  90 12 e0 90  or  %o3, 0x90, %o0	! 0x9f000090
a0029e00:  92 10 20 00  clr  %o1
a0029e04:  40 00 09 19  call  0xa002c268
a0029e08:  94 10 20 20  mov  0x20, %o2
a0029e0c:  23 27 c0 80  sethi  %hi(0x9f020000), %l1
a0029e10:  92 10 20 20  mov  0x20, %o1
a0029e14:  94 10 20 20  mov  0x20, %o2
a0029e18:  40 00 09 14  call  0xa002c268
a0029e1c:  90 14 60 28  or  %l1, 0x28, %o0
a0029e20:  40 00 09 0c  call  0xa002c250
a0029e24:  90 14 60 80  or  %l1, 0x80, %o0
a0029e28:  a4 10 00 08  mov  %o0, %l2
a0029e2c:  40 00 09 09  call  0xa002c250
a0029e30:  90 14 60 48  or  %l1, 0x48, %o0
a0029e34:  a0 2c 80 08  andn  %l2, %o0, %l0
a0029e38:  15 00 00 3f  sethi  %hi(0xfc00), %o2
a0029e3c:  92 12 a3 ff  or  %o2, 0x3ff, %o1	! 0xffff
a0029e40:  91 32 20 10  srl  %o0, 0x10, %o0
a0029e44:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a0029e48:  a4 0a 00 09  and  %o0, %o1, %l2
a0029e4c:  a0 0c 00 09  and  %l0, %o1, %l0
a0029e50:  b0 10 61 70  or  %g1, 0x170, %i0
a0029e54:  10 80 00 0a  b  0xa0029e7c
a0029e58:  b2 10 20 00  clr  %i1
a0029e5c:  9f c0 40 00  call  %g1
a0029e60:  b2 06 60 01  inc  %i1
a0029e64:  92 10 00 1a  mov  %i2, %o1
a0029e68:  40 00 08 fd  call  0xa002c25c
a0029e6c:  90 14 60 80  or  %l1, 0x80, %o0
a0029e70:  80 a6 60 0f  cmp  %i1, 0xf
a0029e74:  18 80 00 17  bgu  0xa0029ed0
a0029e78:  b0 06 20 04  add  %i0, 4, %i0
a0029e7c:  98 10 20 01  mov  1, %o4
a0029e80:  b5 2b 00 19  sll  %o4, %i1, %i2
a0029e84:  80 8e 80 10  btst  %i2, %l0
a0029e88:  22 bf ff fa  be,a   0xa0029e70
a0029e8c:  b2 06 60 01  inc  %i1
a0029e90:  c2 06 21 40  ld  [ %i0 + 0x140 ], %g1
a0029e94:  80 a0 60 00  cmp  %g1, 0
a0029e98:  22 bf ff f6  be,a   0xa0029e70
a0029e9c:  b2 06 60 01  inc  %i1
a0029ea0:  92 10 00 1a  mov  %i2, %o1
a0029ea4:  80 8e 80 12  btst  %i2, %l2
a0029ea8:  12 bf ff ed  bne  0xa0029e5c
a0029eac:  90 14 60 80  or  %l1, 0x80, %o0
a0029eb0:  40 00 08 eb  call  0xa002c25c
a0029eb4:  b2 06 60 01  inc  %i1
a0029eb8:  da 06 21 40  ld  [ %i0 + 0x140 ], %o5
a0029ebc:  9f c3 40 00  call  %o5
a0029ec0:  b0 06 20 04  add  %i0, 4, %i0
a0029ec4:  80 a6 60 0f  cmp  %i1, 0xf
a0029ec8:  08 bf ff ee  bleu  0xa0029e80
a0029ecc:  98 10 20 01  mov  1, %o4
a0029ed0:  23 27 c0 80  sethi  %hi(0x9f020000), %l1
a0029ed4:  90 14 60 34  or  %l1, 0x34, %o0	! 0x9f020034
a0029ed8:  40 00 08 e1  call  0xa002c25c
a0029edc:  92 10 20 20  mov  0x20, %o1
a0029ee0:  31 27 c0 00  sethi  %hi(0x9f000000), %i0
a0029ee4:  90 16 20 9c  or  %i0, 0x9c, %o0	! 0x9f00009c
a0029ee8:  40 00 08 dd  call  0xa002c25c
a0029eec:  92 10 20 20  mov  0x20, %o1
a0029ef0:  90 14 60 28  or  %l1, 0x28, %o0
a0029ef4:  92 10 20 00  clr  %o1
a0029ef8:  40 00 08 dc  call  0xa002c268
a0029efc:  94 10 20 20  mov  0x20, %o2
a0029f00:  b0 16 20 90  or  %i0, 0x90, %i0
a0029f04:  b2 10 20 20  mov  0x20, %i1
a0029f08:  40 00 08 d8  call  0xa002c268
a0029f0c:  95 e8 20 20  restore  %g0, 0x20, %o2
a0029f10:  01 00 00 00  nop
