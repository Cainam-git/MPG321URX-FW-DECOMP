# leon2m FUN_a0029f14 0xa0029f14-0xa002a02c (280 bytes)
a0029f14:  9d e3 bf 98  save  %sp, -104, %sp
a0029f18:  17 27 c0 00  sethi  %hi(0x9f000000), %o3
a0029f1c:  90 12 e0 90  or  %o3, 0x90, %o0	! 0x9f000090
a0029f20:  92 10 20 00  clr  %o1
a0029f24:  40 00 08 d1  call  0xa002c268
a0029f28:  94 10 20 40  mov  0x40, %o2
a0029f2c:  23 27 c0 80  sethi  %hi(0x9f020000), %l1
a0029f30:  92 10 20 40  mov  0x40, %o1
a0029f34:  94 10 20 40  mov  0x40, %o2
a0029f38:  40 00 08 cc  call  0xa002c268
a0029f3c:  90 14 60 28  or  %l1, 0x28, %o0
a0029f40:  40 00 08 c4  call  0xa002c250
a0029f44:  90 14 60 84  or  %l1, 0x84, %o0
a0029f48:  a4 10 00 08  mov  %o0, %l2
a0029f4c:  40 00 08 c1  call  0xa002c250
a0029f50:  90 14 60 4c  or  %l1, 0x4c, %o0
a0029f54:  a0 2c 80 08  andn  %l2, %o0, %l0
a0029f58:  15 00 00 3f  sethi  %hi(0xfc00), %o2
a0029f5c:  92 12 a3 ff  or  %o2, 0x3ff, %o1	! 0xffff
a0029f60:  91 32 20 10  srl  %o0, 0x10, %o0
a0029f64:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a0029f68:  a4 0a 00 09  and  %o0, %o1, %l2
a0029f6c:  a0 0c 00 09  and  %l0, %o1, %l0
a0029f70:  b0 10 61 70  or  %g1, 0x170, %i0
a0029f74:  b2 10 20 00  clr  %i1
a0029f78:  98 10 20 01  mov  1, %o4
a0029f7c:  b5 2b 00 19  sll  %o4, %i1, %i2
a0029f80:  80 8e 80 10  btst  %i2, %l0
a0029f84:  22 80 00 0f  be,a   0xa0029fc0
a0029f88:  b2 06 60 01  inc  %i1
a0029f8c:  c2 06 21 80  ld  [ %i0 + 0x180 ], %g1
a0029f90:  80 a0 60 00  cmp  %g1, 0
a0029f94:  22 80 00 0b  be,a   0xa0029fc0
a0029f98:  b2 06 60 01  inc  %i1
a0029f9c:  92 10 00 1a  mov  %i2, %o1
a0029fa0:  80 8e 80 12  btst  %i2, %l2
a0029fa4:  02 80 00 1b  be  0xa002a010
a0029fa8:  90 14 60 84  or  %l1, 0x84, %o0
a0029fac:  9f c0 40 00  call  %g1
a0029fb0:  b2 06 60 01  inc  %i1
a0029fb4:  92 10 00 1a  mov  %i2, %o1
a0029fb8:  40 00 08 a9  call  0xa002c25c
a0029fbc:  90 14 60 84  or  %l1, 0x84, %o0
a0029fc0:  b0 06 20 04  add  %i0, 4, %i0
a0029fc4:  80 a6 60 06  cmp  %i1, 6
a0029fc8:  08 bf ff ed  bleu  0xa0029f7c
a0029fcc:  98 10 20 01  mov  1, %o4
a0029fd0:  23 27 c0 80  sethi  %hi(0x9f020000), %l1
a0029fd4:  90 14 60 34  or  %l1, 0x34, %o0	! 0x9f020034
a0029fd8:  40 00 08 a1  call  0xa002c25c
a0029fdc:  92 10 20 40  mov  0x40, %o1
a0029fe0:  31 27 c0 00  sethi  %hi(0x9f000000), %i0
a0029fe4:  90 16 20 9c  or  %i0, 0x9c, %o0	! 0x9f00009c
a0029fe8:  40 00 08 9d  call  0xa002c25c
a0029fec:  92 10 20 40  mov  0x40, %o1
a0029ff0:  90 14 60 28  or  %l1, 0x28, %o0
a0029ff4:  92 10 20 00  clr  %o1
a0029ff8:  40 00 08 9c  call  0xa002c268
a0029ffc:  94 10 20 40  mov  0x40, %o2
a002a000:  b0 16 20 90  or  %i0, 0x90, %i0
a002a004:  b2 10 20 40  mov  0x40, %i1
a002a008:  40 00 08 98  call  0xa002c268
a002a00c:  95 e8 20 40  restore  %g0, 0x40, %o2
a002a010:  40 00 08 93  call  0xa002c25c
a002a014:  b2 06 60 01  inc  %i1
a002a018:  da 06 21 80  ld  [ %i0 + 0x180 ], %o5
a002a01c:  9f c3 40 00  call  %o5
a002a020:  b0 06 20 04  add  %i0, 4, %i0
a002a024:  10 bf ff e9  b  0xa0029fc8
a002a028:  80 a6 60 06  cmp  %i1, 6
