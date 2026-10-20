# leon2m FUN_a0098f28 0xa0098f28-0xa009901c (244 bytes)
a0098f28:  9d e3 bf 98  save  %sp, -104, %sp
a0098f2c:  25 2a 00 ab  sethi  %hi(0xa802ac00), %l2
a0098f30:  d6 04 a3 ec  ld  [ %l2 + 0x3ec ], %o3	! 0xa802afec
a0098f34:  92 02 e0 4f  add  %o3, 0x4f, %o1
a0098f38:  40 00 41 21  call  0xa00a93bc
a0098f3c:  90 0a 60 ff  and  %o1, 0xff, %o0
a0098f40:  15 2a 00 97  sethi  %hi(0xa8025c00), %o2
a0098f44:  d2 0a a0 56  ldub  [ %o2 + 0x56 ], %o1	! 0xa8025c56
a0098f48:  90 10 20 01  mov  1, %o0
a0098f4c:  40 00 3c 7c  call  0xa00a813c
a0098f50:  94 10 20 00  clr  %o2
a0098f54:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a0098f58:  da 04 a3 ec  ld  [ %l2 + 0x3ec ], %o5
a0098f5c:  a0 12 22 90  or  %o0, 0x290, %l0
a0098f60:  82 0b 60 01  and  %o5, 1, %g1
a0098f64:  a2 10 00 10  mov  %l0, %l1
a0098f68:  90 10 20 00  clr  %o0
a0098f6c:  92 10 20 00  clr  %o1
a0098f70:  80 a3 60 b1  cmp  %o5, 0xb1
a0098f74:  02 80 00 11  be  0xa0098fb8
a0098f78:  99 28 60 05  sll  %g1, 5, %o4
a0098f7c:  e2 04 20 a8  ld  [ %l0 + 0xa8 ], %l1
a0098f80:  9a 14 60 40  or  %l1, 0x40, %o5
a0098f84:  9e 0b 7f df  and  %o5, -33, %o7
a0098f88:  94 13 c0 0c  or  %o7, %o4, %o2
a0098f8c:  97 32 a0 05  srl  %o2, 5, %o3
a0098f90:  92 0a e0 01  and  %o3, 1, %o1
a0098f94:  90 02 60 01  add  %o1, 1, %o0
a0098f98:  92 10 20 00  clr  %o1
a0098f9c:  40 00 41 ad  call  0xa00a9650
a0098fa0:  d4 24 20 a8  st  %o2, [ %l0 + 0xa8 ]
a0098fa4:  d0 04 20 a8  ld  [ %l0 + 0xa8 ], %o0
a0098fa8:  83 32 20 05  srl  %o0, 5, %g1
a0098fac:  a2 08 60 01  and  %g1, 1, %l1
a0098fb0:  10 80 00 09  b  0xa0098fd4
a0098fb4:  92 04 60 01  add  %l1, 1, %o1
a0098fb8:  da 04 20 a8  ld  [ %l0 + 0xa8 ], %o5
a0098fbc:  a0 0b 7f bf  and  %o5, -65, %l0
a0098fc0:  40 00 41 a4  call  0xa00a9650
a0098fc4:  e0 24 60 a8  st  %l0, [ %l1 + 0xa8 ]
a0098fc8:  de 04 60 a8  ld  [ %l1 + 0xa8 ], %o7
a0098fcc:  99 33 e0 06  srl  %o7, 6, %o4
a0098fd0:  92 0b 20 01  and  %o4, 1, %o1
a0098fd4:  90 10 20 01  mov  1, %o0
a0098fd8:  40 00 3c 59  call  0xa00a813c
a0098fdc:  94 10 20 01  mov  1, %o2
a0098fe0:  40 01 02 66  call  0xa00d9978
a0098fe4:  01 00 00 00  nop
a0098fe8:  40 01 02 70  call  0xa00d99a8
a0098fec:  01 00 00 00  nop
a0098ff0:  82 10 20 2d  mov  0x2d, %g1	! 0x2d
a0098ff4:  c2 24 a3 ec  st  %g1, [ %l2 + 0x3ec ]
a0098ff8:  90 10 20 03  mov  3, %o0
a0098ffc:  40 00 40 04  call  0xa00a900c
a0099000:  92 10 20 01  mov  1, %o1
a0099004:  25 2a 00 ac  sethi  %hi(0xa802b000), %l2
a0099008:  e0 0c a0 8e  ldub  [ %l2 + 0x8e ], %l0	! 0xa802b08e
a009900c:  98 14 20 02  or  %l0, 2, %o4
a0099010:  d8 2c a0 8e  stb  %o4, [ %l2 + 0x8e ]
a0099014:  81 c7 e0 08  ret
a0099018:  81 e8 00 00  restore
