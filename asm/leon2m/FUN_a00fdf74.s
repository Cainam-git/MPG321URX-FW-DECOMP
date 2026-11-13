# leon2m FUN_a00fdf74 0xa00fdf74-0xa00fe184 (528 bytes)
a00fdf74:  9d e3 bf 98  save  %sp, -104, %sp
a00fdf78:  13 00 06 69  sethi  %hi(0x19a400), %o1
a00fdf7c:  90 12 60 b0  or  %o1, 0xb0, %o0	! 0x19a4b0
a00fdf80:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00fdf84:  7f ff 84 7b  call  0xa00df170
a00fdf88:  92 10 00 18  mov  %i0, %o1
a00fdf8c:  40 00 7b ff  call  0xa011cf88
a00fdf90:  01 00 00 00  nop
a00fdf94:  90 0a 20 ff  and  %o0, 0xff, %o0
a00fdf98:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a00fdf9c:  80 a2 20 81  cmp  %o0, 0x81
a00fdfa0:  18 80 00 04  bgu  0xa00fdfb0
a00fdfa4:  82 10 62 e0  or  %g1, 0x2e0, %g1
a00fdfa8:  15 33 c0 45  sethi  %hi(0xcf011400), %o2
a00fdfac:  82 12 a2 d4  or  %o2, 0x2d4, %g1	! 0xcf0116d4
a00fdfb0:  da 00 40 00  ld  [ %g1 ], %o5
a00fdfb4:  9a 0b 7f af  and  %o5, -81, %o5
a00fdfb8:  80 a6 20 02  cmp  %i0, 2
a00fdfbc:  02 80 00 3c  be  0xa00fe0ac
a00fdfc0:  a0 10 00 0d  mov  %o5, %l0
a00fdfc4:  80 a6 20 02  cmp  %i0, 2
a00fdfc8:  04 80 00 1a  ble  0xa00fe030
a00fdfcc:  80 a6 20 01  cmp  %i0, 1
a00fdfd0:  80 a6 20 03  cmp  %i0, 3
a00fdfd4:  02 80 00 54  be  0xa00fe124
a00fdfd8:  13 33 c0 f2  sethi  %hi(0xcf03c800), %o1
a00fdfdc:  40 00 7b eb  call  0xa011cf88
a00fdfe0:  01 00 00 00  nop
a00fdfe4:  96 0a 20 ff  and  %o0, 0xff, %o3
a00fdfe8:  13 33 c0 45  sethi  %hi(0xcf011400), %o1
a00fdfec:  9a 0c 20 ff  and  %l0, 0xff, %o5
a00fdff0:  80 a2 e0 81  cmp  %o3, 0x81
a00fdff4:  18 80 00 0d  bgu  0xa00fe028
a00fdff8:  82 12 62 e0  or  %o1, 0x2e0, %g1
a00fdffc:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a00fe000:  de 00 62 a4  ld  [ %g1 + 0x2a4 ], %o7	! 0xa802d6a4
a00fe004:  d4 03 c0 00  ld  [ %o7 ], %o2
a00fe008:  1b 00 1c 00  sethi  %hi(0x700000), %o5
a00fe00c:  98 0a 80 0d  and  %o2, %o5, %o4
a00fe010:  31 00 04 00  sethi  %hi(0x100000), %i0
a00fe014:  80 a3 00 18  cmp  %o4, %i0
a00fe018:  02 80 00 59  be  0xa00fe17c
a00fe01c:  9a 0c 20 ff  and  %l0, 0xff, %o5
a00fe020:  21 33 c0 45  sethi  %hi(0xcf011400), %l0
a00fe024:  82 14 22 d4  or  %l0, 0x2d4, %g1	! 0xcf0116d4
a00fe028:  da 20 40 00  st  %o5, [ %g1 ]
a00fe02c:  30 80 00 54  b,a   0xa00fe17c
a00fe030:  12 bf ff eb  bne  0xa00fdfdc
a00fe034:  1f 33 c0 f2  sethi  %hi(0xcf03c800), %o7
a00fe038:  19 00 00 3f  sethi  %hi(0xfc00), %o4
a00fe03c:  a0 10 00 0d  mov  %o5, %l0
a00fe040:  96 13 e0 40  or  %o7, 0x40, %o3
a00fe044:  92 13 23 ff  or  %o4, 0x3ff, %o1
a00fe048:  94 10 3f ff  mov  -1, %o2
a00fe04c:  90 10 20 01  mov  1, %o0
a00fe050:  82 02 bf ff  add  %o2, -1, %g1
a00fe054:  95 28 60 10  sll  %g1, 0x10, %o2
a00fe058:  9b 32 a0 10  srl  %o2, 0x10, %o5
a00fe05c:  f0 02 c0 00  ld  [ %o3 ], %i0
a00fe060:  80 a6 20 02  cmp  %i0, 2
a00fe064:  02 80 00 03  be  0xa00fe070
a00fe068:  94 10 00 01  mov  %g1, %o2
a00fe06c:  d0 22 c0 00  st  %o0, [ %o3 ]
a00fe070:  d8 02 c0 00  ld  [ %o3 ], %o4
a00fe074:  80 a3 20 01  cmp  %o4, 1
a00fe078:  02 80 00 04  be  0xa00fe088
a00fe07c:  80 a3 40 09  cmp  %o5, %o1
a00fe080:  32 bf ff f5  bne,a   0xa00fe054
a00fe084:  82 02 bf ff  add  %o2, -1, %g1
a00fe088:  9a 10 20 01  mov  1, %o5
a00fe08c:  da 22 c0 00  st  %o5, [ %o3 ]
a00fe090:  13 33 c0 45  sethi  %hi(0xcf011400), %o1
a00fe094:  9a 12 62 00  or  %o1, 0x200, %o5	! 0xcf011600
a00fe098:  d0 03 40 00  ld  [ %o5 ], %o0
a00fe09c:  82 0a 3f bf  and  %o0, -65, %g1
a00fe0a0:  c2 23 40 00  st  %g1, [ %o5 ]
a00fe0a4:  c0 22 c0 00  clr  [ %o3 ]
a00fe0a8:  30 bf ff cd  b,a   0xa00fdfdc
a00fe0ac:  31 33 c0 f2  sethi  %hi(0xcf03c800), %i0
a00fe0b0:  1f 00 00 3f  sethi  %hi(0xfc00), %o7
a00fe0b4:  a0 13 60 10  or  %o5, 0x10, %l0
a00fe0b8:  96 16 20 40  or  %i0, 0x40, %o3
a00fe0bc:  92 13 e3 ff  or  %o7, 0x3ff, %o1
a00fe0c0:  94 10 3f ff  mov  -1, %o2
a00fe0c4:  90 10 20 01  mov  1, %o0
a00fe0c8:  82 02 bf ff  add  %o2, -1, %g1
a00fe0cc:  95 28 60 10  sll  %g1, 0x10, %o2
a00fe0d0:  9b 32 a0 10  srl  %o2, 0x10, %o5
a00fe0d4:  d8 02 c0 00  ld  [ %o3 ], %o4
a00fe0d8:  80 a3 20 02  cmp  %o4, 2
a00fe0dc:  02 80 00 03  be  0xa00fe0e8
a00fe0e0:  94 10 00 01  mov  %g1, %o2
a00fe0e4:  d0 22 c0 00  st  %o0, [ %o3 ]
a00fe0e8:  de 02 c0 00  ld  [ %o3 ], %o7
a00fe0ec:  80 a3 e0 01  cmp  %o7, 1
a00fe0f0:  02 80 00 04  be  0xa00fe100
a00fe0f4:  80 a3 40 09  cmp  %o5, %o1
a00fe0f8:  32 bf ff f5  bne,a   0xa00fe0cc
a00fe0fc:  82 02 bf ff  add  %o2, -1, %g1
a00fe100:  90 10 20 01  mov  1, %o0
a00fe104:  1f 33 c0 45  sethi  %hi(0xcf011400), %o7
a00fe108:  d0 22 c0 00  st  %o0, [ %o3 ]
a00fe10c:  9a 13 e2 00  or  %o7, 0x200, %o5
a00fe110:  d4 03 40 00  ld  [ %o5 ], %o2
a00fe114:  82 12 a0 40  or  %o2, 0x40, %g1
a00fe118:  c2 23 40 00  st  %g1, [ %o5 ]
a00fe11c:  c0 22 c0 00  clr  [ %o3 ]
a00fe120:  30 bf ff af  b,a   0xa00fdfdc
a00fe124:  11 00 00 3f  sethi  %hi(0xfc00), %o0
a00fe128:  96 12 60 40  or  %o1, 0x40, %o3
a00fe12c:  92 12 23 ff  or  %o0, 0x3ff, %o1
a00fe130:  a0 13 60 40  or  %o5, 0x40, %l0
a00fe134:  94 10 3f ff  mov  -1, %o2
a00fe138:  90 10 20 01  mov  1, %o0
a00fe13c:  98 02 bf ff  add  %o2, -1, %o4
a00fe140:  9b 2b 20 10  sll  %o4, 0x10, %o5
a00fe144:  f0 02 c0 00  ld  [ %o3 ], %i0
a00fe148:  9b 33 60 10  srl  %o5, 0x10, %o5
a00fe14c:  80 a6 20 02  cmp  %i0, 2
a00fe150:  02 80 00 03  be  0xa00fe15c
a00fe154:  94 10 00 0c  mov  %o4, %o2
a00fe158:  d0 22 c0 00  st  %o0, [ %o3 ]
a00fe15c:  c2 02 c0 00  ld  [ %o3 ], %g1
a00fe160:  80 a0 60 01  cmp  %g1, 1
a00fe164:  02 bf ff e7  be  0xa00fe100
a00fe168:  80 a3 40 09  cmp  %o5, %o1
a00fe16c:  12 bf ff f5  bne  0xa00fe140
a00fe170:  98 02 bf ff  add  %o2, -1, %o4
a00fe174:  10 bf ff e4  b  0xa00fe104
a00fe178:  90 10 20 01  mov  1, %o0
a00fe17c:  81 c7 e0 08  ret
a00fe180:  81 e8 00 00  restore
