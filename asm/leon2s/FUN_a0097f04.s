# leon2s FUN_a0097f04 0xa0097f04-0xa0097ff4 (240 bytes)
a0097f04:  9d e3 bf 98  save  %sp, -104, %sp
a0097f08:  96 0e 20 ff  and  %i0, 0xff, %o3
a0097f0c:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a0097f10:  98 5a e0 34  smul  %o3, 0x34, %o4
a0097f14:  82 10 63 00  or  %g1, 0x300, %g1
a0097f18:  9a 02 c0 0b  add  %o3, %o3, %o5
a0097f1c:  92 03 00 01  add  %o4, %g1, %o1
a0097f20:  9a 03 40 0b  add  %o5, %o3, %o5
a0097f24:  19 2a 01 f5  sethi  %hi(0xa807d400), %o4
a0097f28:  94 13 22 50  or  %o4, 0x250, %o2	! 0xa807d650
a0097f2c:  9b 2b 60 03  sll  %o5, 3, %o5
a0097f30:  9a 03 40 0a  add  %o5, %o2, %o5
a0097f34:  d6 0b 60 06  ldub  [ %o5 + 6 ], %o3
a0097f38:  80 a2 e0 00  cmp  %o3, 0
a0097f3c:  02 80 00 0a  be  0xa0097f64
a0097f40:  94 10 00 0d  mov  %o5, %o2
a0097f44:  c2 02 60 04  ld  [ %o1 + 4 ], %g1
a0097f48:  c2 00 60 40  ld  [ %g1 + 0x40 ], %g1
a0097f4c:  82 08 60 ff  and  %g1, 0xff, %g1
a0097f50:  80 a0 60 82  cmp  %g1, 0x82
a0097f54:  02 80 00 04  be  0xa0097f64
a0097f58:  98 02 ff ff  add  %o3, -1, %o4
a0097f5c:  10 80 00 03  b  0xa0097f68
a0097f60:  d8 2b 60 06  stb  %o4, [ %o5 + 6 ]
a0097f64:  c0 2a a0 06  clrb  [ %o2 + 6 ]
a0097f68:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0097f6c:  92 10 20 16  mov  0x16, %o1
a0097f70:  40 00 22 12  call  0xa00a07b8
a0097f74:  90 10 00 18  mov  %i0, %o0
a0097f78:  7f ff d6 22  call  0xa008d800
a0097f7c:  01 00 00 00  nop
a0097f80:  82 0a 20 ff  and  %o0, 0xff, %g1
a0097f84:  92 10 20 08  mov  8, %o1
a0097f88:  80 a0 60 82  cmp  %g1, 0x82
a0097f8c:  08 80 00 0a  bleu  0xa0097fb4
a0097f90:  90 10 00 18  mov  %i0, %o0
a0097f94:  40 00 22 09  call  0xa00a07b8
a0097f98:  01 00 00 00  nop
a0097f9c:  90 10 00 18  mov  %i0, %o0
a0097fa0:  40 00 22 06  call  0xa00a07b8
a0097fa4:  92 10 20 0b  mov  0xb, %o1
a0097fa8:  90 10 00 18  mov  %i0, %o0
a0097fac:  40 00 22 03  call  0xa00a07b8
a0097fb0:  92 10 20 0c  mov  0xc, %o1
a0097fb4:  7f ff ff c7  call  0xa0097ed0
a0097fb8:  90 10 00 18  mov  %i0, %o0
a0097fbc:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a0097fc0:  96 10 62 50  or  %g1, 0x250, %o3	! 0xa807d650
a0097fc4:  82 06 00 18  add  %i0, %i0, %g1
a0097fc8:  9a 00 40 18  add  %g1, %i0, %o5
a0097fcc:  80 8a 20 ff  btst  0xff, %o0
a0097fd0:  12 80 00 05  bne  0xa0097fe4
a0097fd4:  9b 2b 60 03  sll  %o5, 3, %o5
a0097fd8:  82 10 20 07  mov  7, %g1
a0097fdc:  10 80 00 04  b  0xa0097fec
a0097fe0:  c2 22 c0 0d  st  %g1, [ %o3 + %o5 ]
a0097fe4:  82 10 20 07  mov  7, %g1
a0097fe8:  c2 22 c0 0d  st  %g1, [ %o3 + %o5 ]
a0097fec:  81 c7 e0 08  ret
a0097ff0:  91 e8 20 01  restore  %g0, 1, %o0
