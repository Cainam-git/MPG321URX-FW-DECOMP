# leon2m FUN_a00dcec4 0xa00dcec4-0xa00dd250 (908 bytes)
a00dcec4:  9d e3 bf 90  save  %sp, -112, %sp
a00dcec8:  40 00 07 f7  call  0xa00deea4
a00dcecc:  90 07 bf f7  add  %fp, -9, %o0
a00dced0:  80 a2 20 00  cmp  %o0, 0
a00dced4:  02 80 00 dd  be  0xa00dd248
a00dced8:  c2 4f bf f7  ldsb  [ %fp + -9 ], %g1
a00dcedc:  80 a0 60 0d  cmp  %g1, 0xd
a00dcee0:  a0 10 20 00  clr  %l0
a00dcee4:  02 80 00 86  be  0xa00dd0fc
a00dcee8:  d6 0f bf f7  ldub  [ %fp + -9 ], %o3
a00dceec:  80 a0 60 0d  cmp  %g1, 0xd
a00dcef0:  04 80 00 76  ble  0xa00dd0c8
a00dcef4:  80 a0 60 08  cmp  %g1, 8
a00dcef8:  80 a0 60 1b  cmp  %g1, 0x1b
a00dcefc:  02 80 00 ab  be  0xa00dd1a8
a00dcf00:  15 2a 00 b5  sethi  %hi(0xa802d400), %o2
a00dcf04:  d8 02 a0 90  ld  [ %o2 + 0x90 ], %o4	! 0xa802d490
a00dcf08:  80 a3 20 00  cmp  %o4, 0
a00dcf0c:  12 80 00 07  bne  0xa00dcf28
a00dcf10:  80 a3 20 fd  cmp  %o4, 0xfd
a00dcf14:  9f 2a e0 18  sll  %o3, 0x18, %o7
a00dcf18:  9b 3b e0 18  sra  %o7, 0x18, %o5
a00dcf1c:  80 a3 60 5e  cmp  %o5, 0x5e
a00dcf20:  02 80 00 9d  be  0xa00dd194
a00dcf24:  80 a3 20 fd  cmp  %o4, 0xfd
a00dcf28:  04 80 00 7d  ble  0xa00dd11c
a00dcf2c:  29 2a 00 b5  sethi  %hi(0xa802d400), %l4
a00dcf30:  80 8c 20 ff  btst  0xff, %l0
a00dcf34:  02 80 00 c5  be  0xa00dd248
a00dcf38:  2f 00 06 63  sethi  %hi(0x198c00), %l7
a00dcf3c:  40 00 08 01  call  0xa00def40
a00dcf40:  90 15 e3 48  or  %l7, 0x348, %o0	! 0x198f48
a00dcf44:  37 2a 00 b5  sethi  %hi(0xa802d400), %i3
a00dcf48:  da 06 e0 90  ld  [ %i3 + 0x90 ], %o5	! 0xa802d490
a00dcf4c:  80 a3 60 ff  cmp  %o5, 0xff
a00dcf50:  14 80 00 6d  bg  0xa00dd104
a00dcf54:  80 a3 60 00  cmp  %o5, 0
a00dcf58:  11 2a 00 b5  sethi  %hi(0xa802d400), %o0
a00dcf5c:  a0 12 20 98  or  %o0, 0x98, %l0	! 0xa802d498
a00dcf60:  c0 2c 00 0d  clrb  [ %l0 + %o5 ]
a00dcf64:  aa 12 20 98  or  %o0, 0x98, %l5
a00dcf68:  40 00 02 35  call  0xa00dd83c
a00dcf6c:  90 10 00 15  mov  %l5, %o0
a00dcf70:  39 2a 00 b5  sethi  %hi(0xa802d400), %i4
a00dcf74:  3b 2a 00 b5  sethi  %hi(0xa802d400), %i5
a00dcf78:  a2 10 00 08  mov  %o0, %l1
a00dcf7c:  80 a2 20 00  cmp  %o0, 0
a00dcf80:  a8 17 20 94  or  %i4, 0x94, %l4
a00dcf84:  02 80 00 4c  be  0xa00dd0b4
a00dcf88:  ac 17 61 98  or  %i5, 0x198, %l6
a00dcf8c:  a0 10 20 00  clr  %l0
a00dcf90:  80 a4 00 08  cmp  %l0, %o0
a00dcf94:  a4 10 3f ff  mov  -1, %l2
a00dcf98:  16 80 00 22  bge  0xa00dd020
a00dcf9c:  a6 10 20 00  clr  %l3
a00dcfa0:  d8 0d 40 10  ldub  [ %l5 + %l0 ], %o4
a00dcfa4:  82 0b 20 ff  and  %o4, 0xff, %g1
a00dcfa8:  80 a0 60 20  cmp  %g1, 0x20
a00dcfac:  22 80 00 68  be,a   0xa00dd14c
a00dcfb0:  80 a4 e0 00  cmp  %l3, 0
a00dcfb4:  14 80 00 06  bg  0xa00dcfcc
a00dcfb8:  80 a0 60 2c  cmp  %g1, 0x2c
a00dcfbc:  80 a0 60 00  cmp  %g1, 0
a00dcfc0:  02 80 00 63  be  0xa00dd14c
a00dcfc4:  80 a4 e0 00  cmp  %l3, 0
a00dcfc8:  80 a0 60 09  cmp  %g1, 9
a00dcfcc:  02 80 00 5f  be  0xa00dd148
a00dcfd0:  9a 04 e0 01  add  %l3, 1, %o5
a00dcfd4:  80 a3 60 1f  cmp  %o5, 0x1f
a00dcfd8:  34 80 00 6d  bg,a   0xa00dd18c
a00dcfdc:  19 00 06 62  sethi  %hi(0x198800), %o4
a00dcfe0:  e4 0d 00 00  ldub  [ %l4 ], %l2
a00dcfe4:  97 2c a0 05  sll  %l2, 5, %o3
a00dcfe8:  9e 02 c0 13  add  %o3, %l3, %o7
a00dcfec:  d8 2b c0 16  stb  %o4, [ %o7 + %l6 ]
a00dcff0:  a6 10 00 0d  mov  %o5, %l3
a00dcff4:  a4 10 20 00  clr  %l2
a00dcff8:  a0 04 20 01  inc  %l0
a00dcffc:  80 a4 00 11  cmp  %l0, %l1
a00dd000:  26 bf ff e9  bl,a   0xa00dcfa4
a00dd004:  d8 0d 40 10  ldub  [ %l5 + %l0 ], %o4
a00dd008:  80 a4 a0 00  cmp  %l2, 0
a00dd00c:  32 80 00 6d  bne,a   0xa00dd1c0
a00dd010:  aa 1c a0 01  xor  %l2, 1, %l5
a00dd014:  e2 0d 00 00  ldub  [ %l4 ], %l1
a00dd018:  9a 04 60 01  add  %l1, 1, %o5
a00dd01c:  da 2d 00 00  stb  %o5, [ %l4 ]
a00dd020:  80 a4 a0 00  cmp  %l2, 0
a00dd024:  32 80 00 25  bne,a   0xa00dd0b8
a00dd028:  39 00 06 62  sethi  %hi(0x198800), %i4
a00dd02c:  a8 17 61 98  or  %i5, 0x198, %l4
a00dd030:  a2 10 20 00  clr  %l1
a00dd034:  27 00 06 63  sethi  %hi(0x198c00), %l3
a00dd038:  a0 10 20 00  clr  %l0
a00dd03c:  ba 14 e0 90  or  %l3, 0x90, %i5
a00dd040:  a4 04 00 1d  add  %l0, %i5, %l2
a00dd044:  90 10 00 12  mov  %l2, %o0
a00dd048:  40 00 02 08  call  0xa00dd868
a00dd04c:  92 10 00 14  mov  %l4, %o1
a00dd050:  a2 04 60 01  inc  %l1
a00dd054:  80 a2 20 00  cmp  %o0, 0
a00dd058:  02 80 00 5f  be  0xa00dd1d4
a00dd05c:  a0 04 20 24  add  %l0, 0x24, %l0
a00dd060:  80 a4 60 0c  cmp  %l1, 0xc
a00dd064:  06 bf ff f7  bl  0xa00dd040
a00dd068:  ba 14 e0 90  or  %l3, 0x90, %i5
a00dd06c:  11 00 06 62  sethi  %hi(0x198800), %o0
a00dd070:  90 12 23 10  or  %o0, 0x310, %o0	! 0x198b10
a00dd074:  40 00 07 b3  call  0xa00def40
a00dd078:  01 00 00 00  nop
a00dd07c:  13 2a 00 b5  sethi  %hi(0xa802d400), %o1
a00dd080:  82 12 61 98  or  %o1, 0x198, %g1	! 0xa802d598
a00dd084:  98 10 20 00  clr  %o4
a00dd088:  9a 10 20 00  clr  %o5
a00dd08c:  c0 28 40 0d  clrb  [ %g1 + %o5 ]
a00dd090:  9a 03 60 01  inc  %o5
a00dd094:  80 a3 60 1f  cmp  %o5, 0x1f
a00dd098:  24 bf ff fe  ble,a   0xa00dd090
a00dd09c:  c0 28 40 0d  clrb  [ %g1 + %o5 ]
a00dd0a0:  98 03 20 01  inc  %o4
a00dd0a4:  80 a3 20 04  cmp  %o4, 4
a00dd0a8:  04 bf ff f8  ble  0xa00dd088
a00dd0ac:  82 00 60 20  add  %g1, 0x20, %g1
a00dd0b0:  c0 2f 20 94  clrb  [ %i4 + 0x94 ]
a00dd0b4:  39 00 06 62  sethi  %hi(0x198800), %i4
a00dd0b8:  40 00 07 a2  call  0xa00def40
a00dd0bc:  90 17 23 08  or  %i4, 0x308, %o0	! 0x198b08
a00dd0c0:  10 80 00 62  b  0xa00dd248
a00dd0c4:  c0 26 e0 90  clr  [ %i3 + 0x90 ]
a00dd0c8:  12 bf ff 8f  bne  0xa00dcf04
a00dd0cc:  15 2a 00 b5  sethi  %hi(0xa802d400), %o2
a00dd0d0:  1b 2a 00 b5  sethi  %hi(0xa802d400), %o5
a00dd0d4:  c2 03 60 90  ld  [ %o5 + 0x90 ], %g1	! 0xa802d490
a00dd0d8:  80 a0 60 00  cmp  %g1, 0
a00dd0dc:  04 bf ff 95  ble  0xa00dcf30
a00dd0e0:  82 00 7f ff  add  %g1, -1, %g1
a00dd0e4:  11 00 06 62  sethi  %hi(0x198800), %o0
a00dd0e8:  c2 23 60 90  st  %g1, [ %o5 + 0x90 ]
a00dd0ec:  40 00 07 95  call  0xa00def40
a00dd0f0:  90 12 23 28  or  %o0, 0x328, %o0
a00dd0f4:  10 bf ff 90  b  0xa00dcf34
a00dd0f8:  80 8c 20 ff  btst  0xff, %l0
a00dd0fc:  10 bf ff 8d  b  0xa00dcf30
a00dd100:  a0 10 20 01  mov  1, %l0
a00dd104:  02 80 00 0f  be  0xa00dd140
a00dd108:  11 2a 00 b5  sethi  %hi(0xa802d400), %o0
a00dd10c:  b8 12 20 98  or  %o0, 0x98, %i4	! 0xa802d498
a00dd110:  ac 03 40 1c  add  %o5, %i4, %l6
a00dd114:  10 bf ff 94  b  0xa00dcf64
a00dd118:  c0 2d bf ff  clrb  [ %l6 + -1 ]
a00dd11c:  aa 03 20 01  add  %o4, 1, %l5
a00dd120:  a5 2a e0 18  sll  %o3, 0x18, %l2
a00dd124:  a6 15 20 98  or  %l4, 0x98, %l3
a00dd128:  ea 22 a0 90  st  %l5, [ %o2 + 0x90 ]
a00dd12c:  d6 2c c0 0c  stb  %o3, [ %l3 + %o4 ]
a00dd130:  40 00 07 70  call  0xa00deef0
a00dd134:  91 3c a0 18  sra  %l2, 0x18, %o0
a00dd138:  10 bf ff 7f  b  0xa00dcf34
a00dd13c:  80 8c 20 ff  btst  0xff, %l0
a00dd140:  10 bf ff 89  b  0xa00dcf64
a00dd144:  c0 2a 20 98  clrb  [ %o0 + 0x98 ]
a00dd148:  80 a4 e0 00  cmp  %l3, 0
a00dd14c:  22 bf ff ac  be,a   0xa00dcffc
a00dd150:  a0 04 20 01  inc  %l0
a00dd154:  c2 0d 00 00  ldub  [ %l4 ], %g1
a00dd158:  90 00 60 01  add  %g1, 1, %o0
a00dd15c:  92 0a 20 ff  and  %o0, 0xff, %o1
a00dd160:  80 a2 60 04  cmp  %o1, 4
a00dd164:  d0 2d 00 00  stb  %o0, [ %l4 ]
a00dd168:  08 bf ff a4  bleu  0xa00dcff8
a00dd16c:  a6 10 20 00  clr  %l3
a00dd170:  15 00 06 62  sethi  %hi(0x198800), %o2
a00dd174:  90 12 a3 30  or  %o2, 0x330, %o0	! 0x198b30
a00dd178:  a4 10 20 01  mov  1, %l2
a00dd17c:  40 00 07 fd  call  0xa00df170
a00dd180:  a0 10 00 11  mov  %l1, %l0
a00dd184:  10 bf ff 9e  b  0xa00dcffc
a00dd188:  a0 04 20 01  inc  %l0
a00dd18c:  10 bf ff fb  b  0xa00dd178
a00dd190:  90 13 22 f0  or  %o4, 0x2f0, %o0
a00dd194:  a2 10 20 01  mov  1, %l1
a00dd198:  17 2a 00 b5  sethi  %hi(0xa802d400), %o3
a00dd19c:  e2 2a e0 95  stb  %l1, [ %o3 + 0x95 ]	! 0xa802d495
a00dd1a0:  10 bf ff 64  b  0xa00dcf30
a00dd1a4:  c0 22 a0 90  clr  [ %o2 + 0x90 ]
a00dd1a8:  13 00 06 62  sethi  %hi(0x198800), %o1
a00dd1ac:  c0 22 a0 90  clr  [ %o2 + 0x90 ]
a00dd1b0:  40 00 07 64  call  0xa00def40
a00dd1b4:  90 12 63 48  or  %o1, 0x348, %o0
a00dd1b8:  10 bf ff 5f  b  0xa00dcf34
a00dd1bc:  80 8c 20 ff  btst  0xff, %l0
a00dd1c0:  80 a0 00 15  cmp  %g0, %l5
a00dd1c4:  a8 40 20 00  addx  %g0, 0, %l4
a00dd1c8:  a6 20 00 14  neg  %l4, %l3
a00dd1cc:  10 bf ff 95  b  0xa00dd020
a00dd1d0:  a4 0c 80 13  and  %l2, %l3, %l2
a00dd1d4:  40 00 07 5b  call  0xa00def40
a00dd1d8:  90 15 e3 48  or  %l7, 0x348, %o0
a00dd1dc:  e6 04 a0 20  ld  [ %l2 + 0x20 ], %l3
a00dd1e0:  80 a4 e0 00  cmp  %l3, 0
a00dd1e4:  22 bf ff a3  be,a   0xa00dd070
a00dd1e8:  11 00 06 62  sethi  %hi(0x198800), %o0
a00dd1ec:  7f ff fe d3  call  0xa00dcd38
a00dd1f0:  90 05 20 20  add  %l4, 0x20, %o0
a00dd1f4:  a0 10 00 08  mov  %o0, %l0
a00dd1f8:  7f ff fe d0  call  0xa00dcd38
a00dd1fc:  90 05 20 40  add  %l4, 0x40, %o0
a00dd200:  a4 10 00 08  mov  %o0, %l2
a00dd204:  7f ff fe cd  call  0xa00dcd38
a00dd208:  90 05 20 60  add  %l4, 0x60, %o0
a00dd20c:  ac 10 00 08  mov  %o0, %l6
a00dd210:  7f ff fe ca  call  0xa00dcd38
a00dd214:  90 05 20 80  add  %l4, 0x80, %o0
a00dd218:  96 10 00 08  mov  %o0, %o3
a00dd21c:  92 10 00 12  mov  %l2, %o1
a00dd220:  94 10 00 16  mov  %l6, %o2
a00dd224:  9f c4 c0 00  call  %l3
a00dd228:  90 10 00 10  mov  %l0, %o0
a00dd22c:  40 00 07 45  call  0xa00def40
a00dd230:  90 15 e3 48  or  %l7, 0x348, %o0
a00dd234:  40 00 07 43  call  0xa00def40
a00dd238:  90 10 00 14  mov  %l4, %o0
a00dd23c:  2f 00 06 62  sethi  %hi(0x198800), %l7
a00dd240:  10 bf ff 8d  b  0xa00dd074
a00dd244:  90 15 e3 58  or  %l7, 0x358, %o0	! 0x198b58
a00dd248:  81 c7 e0 08  ret
a00dd24c:  81 e8 00 00  restore
