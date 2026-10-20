# leon2m FUN_a0100e6c 0xa0100e6c-0xa0101028 (444 bytes)
a0100e6c:  9d e3 bf 98  save  %sp, -104, %sp
a0100e70:  03 2a 00 9e  sethi  %hi(0xa8027800), %g1
a0100e74:  d6 00 62 78  ld  [ %g1 + 0x278 ], %o3	! 0xa8027a78
a0100e78:  80 a2 e0 01  cmp  %o3, 1
a0100e7c:  02 80 00 08  be  0xa0100e9c
a0100e80:  80 a2 e0 02  cmp  %o3, 2
a0100e84:  02 80 00 22  be  0xa0100f0c
a0100e88:  19 2a 00 9e  sethi  %hi(0xa8027800), %o4
a0100e8c:  f6 0b 22 74  ldub  [ %o4 + 0x274 ], %i3	! 0xa8027a74
a0100e90:  33 2a 00 9e  sethi  %hi(0xa8027800), %i1
a0100e94:  10 80 00 63  b  0xa0101020
a0100e98:  f6 2e 62 75  stb  %i3, [ %i1 + 0x275 ]	! 0xa8027a75
a0100e9c:  b4 0e a0 ff  and  %i2, 0xff, %i2
a0100ea0:  92 1e a0 31  xor  %i2, 0x31, %o1
a0100ea4:  80 a0 00 09  cmp  %g0, %o1
a0100ea8:  98 60 3f ff  subx  %g0, -1, %o4
a0100eac:  90 1e a0 41  xor  %i2, 0x41, %o0
a0100eb0:  80 a0 00 08  cmp  %g0, %o0
a0100eb4:  9a 60 3f ff  subx  %g0, -1, %o5
a0100eb8:  80 93 00 0d  orcc  %o4, %o5, %g0
a0100ebc:  12 80 00 19  bne  0xa0100f20
a0100ec0:  1b 2a 00 9e  sethi  %hi(0xa8027800), %o5
a0100ec4:  9a 1e a0 51  xor  %i2, 0x51, %o5
a0100ec8:  80 a0 00 0d  cmp  %g0, %o5
a0100ecc:  9e 60 3f ff  subx  %g0, -1, %o7
a0100ed0:  82 1e a0 61  xor  %i2, 0x61, %g1
a0100ed4:  80 a0 00 01  cmp  %g0, %g1
a0100ed8:  94 60 3f ff  subx  %g0, -1, %o2
a0100edc:  80 93 c0 0a  orcc  %o7, %o2, %g0
a0100ee0:  32 80 00 10  bne,a   0xa0100f20
a0100ee4:  1b 2a 00 9e  sethi  %hi(0xa8027800), %o5
a0100ee8:  80 a6 a0 21  cmp  %i2, 0x21
a0100eec:  02 80 00 0f  be  0xa0100f28
a0100ef0:  80 a6 a0 71  cmp  %i2, 0x71
a0100ef4:  02 80 00 0a  be  0xa0100f1c
a0100ef8:  80 a6 a0 81  cmp  %i2, 0x81
a0100efc:  02 80 00 08  be  0xa0100f1c
a0100f00:  15 2a 00 9e  sethi  %hi(0xa8027800), %o2
a0100f04:  10 80 00 47  b  0xa0101020
a0100f08:  d6 2a a2 75  stb  %o3, [ %o2 + 0x275 ]	! 0xa8027a75
a0100f0c:  9a 10 20 01  mov  1, %o5
a0100f10:  03 2a 00 9e  sethi  %hi(0xa8027800), %g1
a0100f14:  10 80 00 43  b  0xa0101020
a0100f18:  da 28 62 75  stb  %o5, [ %g1 + 0x275 ]	! 0xa8027a75
a0100f1c:  1b 2a 00 9e  sethi  %hi(0xa8027800), %o5
a0100f20:  10 80 00 40  b  0xa0101020
a0100f24:  f6 2b 62 75  stb  %i3, [ %o5 + 0x275 ]	! 0xa8027a75
a0100f28:  b2 0e 60 ff  and  %i1, 0xff, %i1
a0100f2c:  7f ff df aa  call  0xa00f8dd4
a0100f30:  90 10 00 19  mov  %i1, %o0
a0100f34:  b4 10 00 08  mov  %o0, %i2
a0100f38:  7f ff df ae  call  0xa00f8df0
a0100f3c:  90 10 00 19  mov  %i1, %o0
a0100f40:  b7 2e a0 10  sll  %i2, 0x10, %i3
a0100f44:  95 36 e0 10  srl  %i3, 0x10, %o2
a0100f48:  96 1a a7 80  xor  %o2, 0x780, %o3
a0100f4c:  80 a0 00 0b  cmp  %g0, %o3
a0100f50:  b5 2a 20 10  sll  %o0, 0x10, %i2
a0100f54:  97 36 a0 10  srl  %i2, 0x10, %o3
a0100f58:  98 60 3f ff  subx  %g0, -1, %o4
a0100f5c:  92 1a e4 38  xor  %o3, 0x438, %o1
a0100f60:  80 a0 00 09  cmp  %g0, %o1
a0100f64:  90 60 3f ff  subx  %g0, -1, %o0
a0100f68:  80 8b 00 08  btst  %o4, %o0
a0100f6c:  12 80 00 0c  bne  0xa0100f9c
a0100f70:  82 1a a5 00  xor  %o2, 0x500, %g1
a0100f74:  80 a0 00 01  cmp  %g0, %g1
a0100f78:  9a 60 3f ff  subx  %g0, -1, %o5
a0100f7c:  94 1a e2 d0  xor  %o3, 0x2d0, %o2
a0100f80:  80 a0 00 0a  cmp  %g0, %o2
a0100f84:  9e 60 3f ff  subx  %g0, -1, %o7
a0100f88:  90 10 00 19  mov  %i1, %o0
a0100f8c:  92 10 20 01  mov  1, %o1
a0100f90:  80 8b 40 0f  btst  %o5, %o7
a0100f94:  02 80 00 05  be  0xa0100fa8
a0100f98:  94 10 20 01  mov  1, %o2
a0100f9c:  90 10 00 19  mov  %i1, %o0
a0100fa0:  92 10 20 01  mov  1, %o1
a0100fa4:  94 10 20 24  mov  0x24, %o2
a0100fa8:  7f ff c2 cb  call  0xa00f1ad4
a0100fac:  01 00 00 00  nop
a0100fb0:  67 fe 30 7c  call  0x4008d1a0
a0100fb4:  90 10 20 14  mov  0x14, %o0	! 0x14
a0100fb8:  97 36 e0 10  srl  %i3, 0x10, %o3
a0100fbc:  90 1a e7 80  xor  %o3, 0x780, %o0
a0100fc0:  80 a0 00 08  cmp  %g0, %o0
a0100fc4:  91 36 a0 10  srl  %i2, 0x10, %o0
a0100fc8:  b6 60 3f ff  subx  %g0, -1, %i3
a0100fcc:  98 1a 24 38  xor  %o0, 0x438, %o4
a0100fd0:  80 a0 00 0c  cmp  %g0, %o4
a0100fd4:  b2 60 3f ff  subx  %g0, -1, %i1
a0100fd8:  80 8e c0 19  btst  %i3, %i1
a0100fdc:  12 80 00 0c  bne  0xa010100c
a0100fe0:  9a 10 20 09  mov  9, %o5
a0100fe4:  9e 1a e5 00  xor  %o3, 0x500, %o7
a0100fe8:  80 a0 00 0f  cmp  %g0, %o7
a0100fec:  96 60 3f ff  subx  %g0, -1, %o3
a0100ff0:  b4 1a 22 d0  xor  %o0, 0x2d0, %i2
a0100ff4:  80 a0 00 1a  cmp  %g0, %i2
a0100ff8:  92 60 3f ff  subx  %g0, -1, %o1
a0100ffc:  80 8a c0 09  btst  %o3, %o1
a0101000:  02 80 00 06  be  0xa0101018
a0101004:  9a 10 20 03  mov  3, %o5
a0101008:  9a 10 20 09  mov  9, %o5
a010100c:  03 2a 00 9e  sethi  %hi(0xa8027800), %g1
a0101010:  10 80 00 04  b  0xa0101020
a0101014:  da 28 62 75  stb  %o5, [ %g1 + 0x275 ]	! 0xa8027a75
a0101018:  03 2a 00 9e  sethi  %hi(0xa8027800), %g1
a010101c:  da 28 62 75  stb  %o5, [ %g1 + 0x275 ]	! 0xa8027a75
a0101020:  81 c7 e0 08  ret
a0101024:  81 e8 00 00  restore
