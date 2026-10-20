# leon2m FUN_a0092fd4 0xa0092fd4-0xa0093144 (368 bytes)
a0092fd4:  9d e3 bf 98  save  %sp, -104, %sp
a0092fd8:  33 2a 00 ab  sethi  %hi(0xa802ac00), %i1
a0092fdc:  c2 06 63 ec  ld  [ %i1 + 0x3ec ], %g1	! 0xa802afec
a0092fe0:  b0 00 7f cc  add  %g1, -52, %i0
a0092fe4:  40 00 57 c1  call  0xa00a8ee8
a0092fe8:  90 0e 20 ff  and  %i0, 0xff, %o0
a0092fec:  de 06 63 ec  ld  [ %i1 + 0x3ec ], %o7
a0092ff0:  19 09 24 92  sethi  %hi(0x24924800), %o4
a0092ff4:  94 03 ff cc  add  %o7, -52, %o2
a0092ff8:  96 13 21 25  or  %o4, 0x125, %o3
a0092ffc:  80 52 80 0b  umul  %o2, %o3, %g0
a0093000:  91 40 00 00  rd  %y, %o0
a0093004:  92 22 80 08  sub  %o2, %o0, %o1
a0093008:  9b 32 60 01  srl  %o1, 1, %o5
a009300c:  82 02 00 0d  add  %o0, %o5, %g1
a0093010:  b1 30 60 02  srl  %g1, 2, %i0
a0093014:  c2 16 63 ee  lduh  [ %i1 + 0x3ee ], %g1
a0093018:  92 00 7f d3  add  %g1, -45, %o1
a009301c:  9f 3a 60 1f  sra  %o1, 0x1f, %o7
a0093020:  99 33 e0 1d  srl  %o7, 0x1d, %o4
a0093024:  96 02 40 0c  add  %o1, %o4, %o3
a0093028:  94 0a ff f8  and  %o3, -8, %o2
a009302c:  90 22 40 0a  sub  %o1, %o2, %o0
a0093030:  9a 02 20 34  add  %o0, 0x34, %o5
a0093034:  da 26 63 ec  st  %o5, [ %i1 + 0x3ec ]
a0093038:  40 00 5d 3a  call  0xa00aa520
a009303c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0093040:  90 0a 20 ff  and  %o0, 0xff, %o0
a0093044:  80 a2 20 01  cmp  %o0, 1
a0093048:  12 bf ff f4  bne  0xa0093018
a009304c:  c2 16 63 ee  lduh  [ %i1 + 0x3ee ], %g1
a0093050:  c2 06 63 ec  ld  [ %i1 + 0x3ec ], %g1
a0093054:  13 09 24 92  sethi  %hi(0x24924800), %o1
a0093058:  b2 12 61 25  or  %o1, 0x125, %i1	! 0x24924925
a009305c:  9e 00 7f cc  add  %g1, -52, %o7
a0093060:  80 53 c0 19  umul  %o7, %i1, %g0
a0093064:  95 40 00 00  rd  %y, %o2
a0093068:  98 23 c0 0a  sub  %o7, %o2, %o4
a009306c:  97 33 20 01  srl  %o4, 1, %o3
a0093070:  9a 02 80 0b  add  %o2, %o3, %o5
a0093074:  b3 33 60 02  srl  %o5, 2, %i1
a0093078:  92 0e 20 ff  and  %i0, 0xff, %o1
a009307c:  80 a2 40 19  cmp  %o1, %i1
a0093080:  02 80 00 05  be  0xa0093094
a0093084:  33 2a 00 ab  sethi  %hi(0xa802ac00), %i1
a0093088:  90 22 00 18  sub  %o0, %i0, %o0
a009308c:  40 00 5d ec  call  0xa00aa83c
a0093090:  90 0a 20 ff  and  %o0, 0xff, %o0
a0093094:  d6 06 63 ec  ld  [ %i1 + 0x3ec ], %o3
a0093098:  94 02 ff cc  add  %o3, -52, %o2
a009309c:  90 0a a0 ff  and  %o2, 0xff, %o0
a00930a0:  40 00 57 db  call  0xa00a900c
a00930a4:  92 10 20 01  mov  1, %o1
a00930a8:  da 06 63 ec  ld  [ %i1 + 0x3ec ], %o5
a00930ac:  b0 03 7f cc  add  %o5, -52, %i0
a00930b0:  92 0e 20 ff  and  %i0, 0xff, %o1
a00930b4:  40 00 70 e6  call  0xa00af44c
a00930b8:  90 10 20 34  mov  0x34, %o0
a00930bc:  c2 06 63 ec  ld  [ %i1 + 0x3ec ], %g1
a00930c0:  80 a0 60 35  cmp  %g1, 0x35
a00930c4:  02 80 00 19  be  0xa0093128
a00930c8:  80 a0 60 3b  cmp  %g1, 0x3b
a00930cc:  02 80 00 11  be  0xa0093110
a00930d0:  9e 10 3f ff  mov  -1, %o7
a00930d4:  19 2a 00 b5  sethi  %hi(0xa802d400), %o4
a00930d8:  de 2b 20 19  stb  %o7, [ %o4 + 0x19 ]	! 0xa802d419
a00930dc:  40 00 60 f8  call  0xa00ab4bc
a00930e0:  b0 10 20 00  clr  %i0
a00930e4:  90 10 20 01  mov  1, %o0
a00930e8:  40 00 58 e0  call  0xa00a9468
a00930ec:  92 10 20 02  mov  2, %o1
a00930f0:  90 10 20 02  mov  2, %o0
a00930f4:  40 00 58 dd  call  0xa00a9468
a00930f8:  92 10 20 05  mov  5, %o1
a00930fc:  90 10 20 00  clr  %o0
a0093100:  40 00 58 da  call  0xa00a9468
a0093104:  92 10 20 00  clr  %o1
a0093108:  40 00 80 f3  call  0xa00b34d4
a009310c:  93 e8 20 01  restore  %g0, 1, %o1
a0093110:  90 10 20 00  clr  %o0
a0093114:  40 00 80 f0  call  0xa00b34d4
a0093118:  92 10 20 04  mov  4, %o1
a009311c:  b0 10 20 01  mov  1, %i0
a0093120:  40 00 58 d2  call  0xa00a9468
a0093124:  93 e8 20 06  restore  %g0, 6, %o1
a0093128:  90 10 20 01  mov  1, %o0
a009312c:  40 00 58 cf  call  0xa00a9468
a0093130:  92 10 20 03  mov  3, %o1
a0093134:  b0 10 20 00  clr  %i0
a0093138:  40 00 80 e7  call  0xa00b34d4
a009313c:  93 e8 20 04  restore  %g0, 4, %o1
a0093140:  01 00 00 00  nop
