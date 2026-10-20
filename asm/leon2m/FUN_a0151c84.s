# leon2m FUN_a0151c84 0xa0151c84-0xa0151db4 (96 bytes)
a0151c84:  9d e3 bf 98  save  %sp, -104, %sp
a0151c88:  7f ff 49 5d  call  0xa01241fc
a0151c8c:  b0 10 20 00  clr  %i0
a0151c90:  d2 0a 20 06  ldub  [ %o0 + 6 ], %o1
a0151c94:  82 0a 60 ff  and  %o1, 0xff, %g1
a0151c98:  82 00 7f f0  add  %g1, -16, %g1
a0151c9c:  80 a0 60 32  cmp  %g1, 0x32
a0151ca0:  38 80 00 3c  bgu,a   0xa0151d90
a0151ca4:  c2 02 00 00  ld  [ %o0 ], %g1
a0151ca8:  17 00 03 c4  sethi  %hi(0xf1000), %o3
a0151cac:  95 28 60 02  sll  %g1, 2, %o2
a0151cb0:  9a 12 e0 08  or  %o3, 8, %o5
a0151cb4:  d8 03 40 0a  ld  [ %o5 + %o2 ], %o4
a0151cb8:  81 c3 00 00  jmp  %o4
a0151cbc:  01 00 00 00  nop
a0151cc0:  de 02 00 00  ld  [ %o0 ], %o7
a0151cc4:  1b 00 03 80  sethi  %hi(0xe0000), %o5
a0151cc8:  96 0b c0 0d  and  %o7, %o5, %o3
a0151ccc:  80 a0 00 0b  cmp  %g0, %o3
a0151cd0:  94 10 20 06  mov  6, %o2
a0151cd4:  10 80 00 2e  b  0xa0151d8c
a0151cd8:  b0 62 a0 00  subx  %o2, 0, %i0
a0151cdc:  d6 02 00 00  ld  [ %o0 ], %o3
a0151ce0:  1f 00 03 80  sethi  %hi(0xe0000), %o7
a0151ce4:  82 0a c0 0f  and  %o3, %o7, %g1
a0151ce8:  15 00 01 00  sethi  %hi(0x40000), %o2
a0151cec:  80 a0 40 0a  cmp  %g1, %o2
a0151cf0:  02 80 00 27  be  0xa0151d8c
a0151cf4:  b0 10 20 0d  mov  0xd, %i0
a0151cf8:  80 a0 00 01  cmp  %g0, %g1
a0151cfc:  82 10 20 0c  mov  0xc, %g1
a0151d00:  10 80 00 23  b  0xa0151d8c
a0151d04:  b0 60 60 00  subx  %g1, 0, %i0
a0151d08:  10 80 00 21  b  0xa0151d8c
a0151d0c:  b0 10 20 01  mov  1, %i0
a0151d10:  d4 02 00 00  ld  [ %o0 ], %o2
a0151d14:  1b 00 03 80  sethi  %hi(0xe0000), %o5
a0151d18:  82 0a 80 0d  and  %o2, %o5, %g1
a0151d1c:  19 00 00 80  sethi  %hi(0x20000), %o4
a0151d20:  b0 18 40 0c  xor  %g1, %o4, %i0
a0151d24:  80 a0 00 18  cmp  %g0, %i0
a0151d28:  9e 40 20 00  addx  %g0, 0, %o7
a0151d2c:  10 80 00 18  b  0xa0151d8c
a0151d30:  b0 03 e0 03  add  %o7, 3, %i0
a0151d34:  10 80 00 16  b  0xa0151d8c
a0151d38:  b0 10 20 05  mov  5, %i0
a0151d3c:  c2 02 00 00  ld  [ %o0 ], %g1
a0151d40:  19 00 03 80  sethi  %hi(0xe0000), %o4
a0151d44:  b0 08 40 0c  and  %g1, %o4, %i0
a0151d48:  80 a0 00 18  cmp  %g0, %i0
a0151d4c:  9e 60 20 00  subx  %g0, 0, %o7
a0151d50:  96 0b ff f7  and  %o7, -9, %o3
a0151d54:  10 80 00 0f  b  0xa0151d90
a0151d58:  b0 02 e0 11  add  %o3, 0x11, %i0
a0151d5c:  10 80 00 0c  b  0xa0151d8c
a0151d60:  b0 10 20 0e  mov  0xe, %i0
a0151d64:  c2 02 00 00  ld  [ %o0 ], %g1
a0151d68:  19 00 03 80  sethi  %hi(0xe0000), %o4
a0151d6c:  31 00 01 00  sethi  %hi(0x40000), %i0
a0151d70:  82 08 40 0c  and  %g1, %o4, %g1
a0151d74:  80 a0 40 18  cmp  %g1, %i0
a0151d78:  02 80 00 05  be  0xa0151d8c
a0151d7c:  b0 10 20 0a  mov  0xa, %i0
a0151d80:  80 a0 00 01  cmp  %g0, %g1
a0151d84:  82 10 20 09  mov  9, %g1
a0151d88:  b0 60 60 00  subx  %g1, 0, %i0
a0151d8c:  c2 02 00 00  ld  [ %o0 ], %g1
a0151d90:  9b 30 60 11  srl  %g1, 0x11, %o5
a0151d94:  11 00 06 9d  sethi  %hi(0x1a7400), %o0
a0151d98:  90 12 20 f0  or  %o0, 0xf0, %o0	! 0x1a74f0
a0151d9c:  92 0a 60 ff  and  %o1, 0xff, %o1
a0151da0:  94 0b 60 07  and  %o5, 7, %o2
a0151da4:  7f fe 34 f3  call  0xa00df170
a0151da8:  96 10 00 18  mov  %i0, %o3
a0151dac:  81 c7 e0 08  ret
a0151db0:  81 e8 00 00  restore
