# leon2m FUN_a00cbe9c 0xa00cbe9c-0xa00cc140 (676 bytes)
a00cbe9c:  9d e3 bf 98  save  %sp, -104, %sp
a00cbea0:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00cbea4:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00cbea8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00cbeac:  94 12 20 40  or  %o0, 0x40, %o2
a00cbeb0:  92 13 60 98  or  %o5, 0x98, %o1
a00cbeb4:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00cbeb8:  90 10 60 d0  or  %g1, 0xd0, %o0	! 0xa802d0d0
a00cbebc:  9a 10 20 00  clr  %o5
a00cbec0:  96 10 20 06  mov  6, %o3
a00cbec4:  80 a6 20 02  cmp  %i0, 2
a00cbec8:  02 80 00 39  be  0xa00cbfac
a00cbecc:  98 10 20 06  mov  6, %o4
a00cbed0:  80 a6 20 03  cmp  %i0, 3
a00cbed4:  22 80 00 6e  be,a   0xa00cc08c
a00cbed8:  d4 0a 40 0c  ldub  [ %o1 + %o4 ], %o2
a00cbedc:  d2 0a 00 0c  ldub  [ %o0 + %o4 ], %o1
a00cbee0:  96 02 e0 01  inc  %o3
a00cbee4:  98 0a e0 ff  and  %o3, 0xff, %o4
a00cbee8:  80 a3 20 11  cmp  %o4, 0x11
a00cbeec:  08 bf ff fc  bleu  0xa00cbedc
a00cbef0:  9a 02 40 0d  add  %o1, %o5, %o5
a00cbef4:  80 a6 20 02  cmp  %i0, 2
a00cbef8:  02 80 00 3b  be  0xa00cbfe4
a00cbefc:  80 a6 20 03  cmp  %i0, 3
a00cbf00:  02 80 00 7d  be  0xa00cc0f4
a00cbf04:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00cbf08:  c2 0b 20 e2  ldub  [ %o4 + 0xe2 ], %g1	! 0xa802d0e2
a00cbf0c:  9a 0b 60 ff  and  %o5, 0xff, %o5
a00cbf10:  9e 08 60 ff  and  %g1, 0xff, %o7
a00cbf14:  80 a3 40 0f  cmp  %o5, %o7
a00cbf18:  02 80 00 3b  be  0xa00cc004
a00cbf1c:  80 a6 20 02  cmp  %i0, 2
a00cbf20:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00cbf24:  98 12 20 78  or  %o0, 0x78, %o4	! 0xa802d078
a00cbf28:  94 10 20 30  mov  0x30, %o2
a00cbf2c:  82 10 20 35  mov  0x35, %g1
a00cbf30:  9a 10 20 0d  mov  0xd, %o5
a00cbf34:  9e 10 20 36  mov  0x36, %o7
a00cbf38:  96 10 3f ee  mov  -18, %o3
a00cbf3c:  c2 2a 20 78  stb  %g1, [ %o0 + 0x78 ]
a00cbf40:  da 2b 20 05  stb  %o5, [ %o4 + 5 ]
a00cbf44:  de 2b 20 01  stb  %o7, [ %o4 + 1 ]
a00cbf48:  d4 2b 20 03  stb  %o2, [ %o4 + 3 ]
a00cbf4c:  d6 2b 20 04  stb  %o3, [ %o4 + 4 ]
a00cbf50:  80 a6 20 02  cmp  %i0, 2
a00cbf54:  02 80 00 40  be  0xa00cc054
a00cbf58:  d4 2b 20 02  stb  %o2, [ %o4 + 2 ]
a00cbf5c:  80 a6 20 03  cmp  %i0, 3
a00cbf60:  02 80 00 58  be  0xa00cc0c0
a00cbf64:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00cbf68:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00cbf6c:  9a 12 20 d0  or  %o0, 0xd0, %o5	! 0xa802d0d0
a00cbf70:  c0 28 60 9c  clrb  [ %g1 + 0x9c ]
a00cbf74:  c0 2a 20 d0  clrb  [ %o0 + 0xd0 ]
a00cbf78:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00cbf7c:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00cbf80:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00cbf84:  80 a6 20 02  cmp  %i0, 2
a00cbf88:  02 80 00 3c  be  0xa00cc078
a00cbf8c:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00cbf90:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00cbf94:  90 10 00 18  mov  %i0, %o0
a00cbf98:  80 a6 20 03  cmp  %i0, 3
a00cbf9c:  12 80 00 65  bne  0xa00cc130
a00cbfa0:  94 12 60 78  or  %o1, 0x78, %o2
a00cbfa4:  10 80 00 51  b  0xa00cc0e8
a00cbfa8:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00cbfac:  de 0a 80 0c  ldub  [ %o2 + %o4 ], %o7
a00cbfb0:  96 02 e0 01  inc  %o3
a00cbfb4:  98 0a e0 ff  and  %o3, 0xff, %o4
a00cbfb8:  80 a3 20 11  cmp  %o4, 0x11
a00cbfbc:  18 bf ff ce  bgu  0xa00cbef4
a00cbfc0:  9a 03 c0 0d  add  %o7, %o5, %o5
a00cbfc4:  de 0a 80 0c  ldub  [ %o2 + %o4 ], %o7
a00cbfc8:  96 02 e0 01  inc  %o3
a00cbfcc:  98 0a e0 ff  and  %o3, 0xff, %o4
a00cbfd0:  80 a3 20 11  cmp  %o4, 0x11
a00cbfd4:  08 bf ff f6  bleu  0xa00cbfac
a00cbfd8:  9a 03 c0 0d  add  %o7, %o5, %o5
a00cbfdc:  10 bf ff c7  b  0xa00cbef8
a00cbfe0:  80 a6 20 02  cmp  %i0, 2
a00cbfe4:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00cbfe8:  c2 0a a0 52  ldub  [ %o2 + 0x52 ], %g1	! 0xa802d052
a00cbfec:  9a 0b 60 ff  and  %o5, 0xff, %o5
a00cbff0:  9e 08 60 ff  and  %g1, 0xff, %o7
a00cbff4:  80 a3 40 0f  cmp  %o5, %o7
a00cbff8:  12 bf ff cb  bne  0xa00cbf24
a00cbffc:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00cc000:  80 a6 20 02  cmp  %i0, 2
a00cc004:  02 80 00 45  be  0xa00cc118
a00cc008:  80 a6 20 03  cmp  %i0, 3
a00cc00c:  02 80 00 3d  be  0xa00cc100
a00cc010:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00cc014:  9a 10 20 35  mov  0x35, %o5
a00cc018:  98 13 e0 78  or  %o7, 0x78, %o4
a00cc01c:  94 10 20 30  mov  0x30, %o2
a00cc020:  da 2b e0 78  stb  %o5, [ %o7 + 0x78 ]
a00cc024:  92 10 20 0d  mov  0xd, %o1
a00cc028:  82 10 20 36  mov  0x36, %g1
a00cc02c:  90 10 20 2b  mov  0x2b, %o0
a00cc030:  d2 2b 20 05  stb  %o1, [ %o4 + 5 ]
a00cc034:  c2 2b 20 01  stb  %g1, [ %o4 + 1 ]
a00cc038:  d4 2b 20 03  stb  %o2, [ %o4 + 3 ]
a00cc03c:  d0 2b 20 04  stb  %o0, [ %o4 + 4 ]
a00cc040:  7f fe da f3  call  0xa0082c0c
a00cc044:  d4 2b 20 02  stb  %o2, [ %o4 + 2 ]
a00cc048:  80 a6 20 02  cmp  %i0, 2
a00cc04c:  12 bf ff c5  bne  0xa00cbf60
a00cc050:  80 a6 20 03  cmp  %i0, 3
a00cc054:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00cc058:  b0 12 60 40  or  %o1, 0x40, %i0	! 0xa802d040
a00cc05c:  19 2a 00 ac  sethi  %hi(0xa802b000), %o4
a00cc060:  c0 2b 20 9a  clrb  [ %o4 + 0x9a ]	! 0xa802b09a
a00cc064:  c0 2a 60 40  clrb  [ %o1 + 0x40 ]
a00cc068:  c0 2e 20 19  clrb  [ %i0 + 0x19 ]
a00cc06c:  c0 2e 20 01  clrb  [ %i0 + 1 ]
a00cc070:  c0 2e 20 07  clrb  [ %i0 + 7 ]
a00cc074:  c0 2e 20 0a  clrb  [ %i0 + 0xa ]
a00cc078:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00cc07c:  94 16 21 28  or  %i0, 0x128, %o2	! 0xa802d128
a00cc080:  10 80 00 2c  b  0xa00cc130
a00cc084:  90 10 20 02  mov  2, %o0
a00cc088:  d4 0a 40 0c  ldub  [ %o1 + %o4 ], %o2
a00cc08c:  96 02 e0 01  inc  %o3
a00cc090:  98 0a e0 ff  and  %o3, 0xff, %o4
a00cc094:  80 a3 20 11  cmp  %o4, 0x11
a00cc098:  18 bf ff 97  bgu  0xa00cbef4
a00cc09c:  9a 02 80 0d  add  %o2, %o5, %o5
a00cc0a0:  d4 0a 40 0c  ldub  [ %o1 + %o4 ], %o2
a00cc0a4:  96 02 e0 01  inc  %o3
a00cc0a8:  98 0a e0 ff  and  %o3, 0xff, %o4
a00cc0ac:  80 a3 20 11  cmp  %o4, 0x11
a00cc0b0:  08 bf ff f6  bleu  0xa00cc088
a00cc0b4:  9a 02 80 0d  add  %o2, %o5, %o5
a00cc0b8:  10 bf ff 90  b  0xa00cbef8
a00cc0bc:  80 a6 20 02  cmp  %i0, 2
a00cc0c0:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00cc0c4:  94 12 e0 98  or  %o3, 0x98, %o2	! 0xa802d098
a00cc0c8:  1f 2a 00 ac  sethi  %hi(0xa802b000), %o7
a00cc0cc:  c0 2b e0 98  clrb  [ %o7 + 0x98 ]	! 0xa802b098
a00cc0d0:  c0 2a e0 98  clrb  [ %o3 + 0x98 ]
a00cc0d4:  c0 2a a0 19  clrb  [ %o2 + 0x19 ]
a00cc0d8:  c0 2a a0 01  clrb  [ %o2 + 1 ]
a00cc0dc:  c0 2a a0 07  clrb  [ %o2 + 7 ]
a00cc0e0:  c0 2a a0 0a  clrb  [ %o2 + 0xa ]
a00cc0e4:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00cc0e8:  94 13 21 08  or  %o4, 0x108, %o2	! 0xa802d108
a00cc0ec:  10 80 00 11  b  0xa00cc130
a00cc0f0:  90 10 20 03  mov  3, %o0
a00cc0f4:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00cc0f8:  10 bf ff 85  b  0xa00cbf0c
a00cc0fc:  c2 0a e0 aa  ldub  [ %o3 + 0xaa ], %g1	! 0xa802d0aa
a00cc100:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00cc104:  96 10 20 35  mov  0x35, %o3
a00cc108:  98 12 61 08  or  %o1, 0x108, %o4
a00cc10c:  94 10 20 30  mov  0x30, %o2
a00cc110:  10 bf ff c5  b  0xa00cc024
a00cc114:  d6 2a 61 08  stb  %o3, [ %o1 + 0x108 ]
a00cc118:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00cc11c:  82 10 20 35  mov  0x35, %g1
a00cc120:  98 12 21 28  or  %o0, 0x128, %o4
a00cc124:  94 10 20 30  mov  0x30, %o2
a00cc128:  10 bf ff bf  b  0xa00cc024
a00cc12c:  c2 2a 21 28  stb  %g1, [ %o0 + 0x128 ]
a00cc130:  40 01 f1 ae  call  0xa01487e8
a00cc134:  92 10 20 06  mov  6, %o1
a00cc138:  81 c7 e0 08  ret
a00cc13c:  91 e8 20 00  restore  %g0, 0, %o0
