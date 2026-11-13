# leon2m FUN_a0093144 0xa0093144-0xa00932a8 (356 bytes)
a0093144:  9d e3 bf 98  save  %sp, -104, %sp
a0093148:  33 2a 00 ab  sethi  %hi(0xa802ac00), %i1
a009314c:  c2 06 63 ec  ld  [ %i1 + 0x3ec ], %g1	! 0xa802afec
a0093150:  b0 00 7f cc  add  %g1, -52, %i0
a0093154:  40 00 57 65  call  0xa00a8ee8
a0093158:  90 0e 20 ff  and  %i0, 0xff, %o0
a009315c:  de 06 63 ec  ld  [ %i1 + 0x3ec ], %o7
a0093160:  19 09 24 92  sethi  %hi(0x24924800), %o4
a0093164:  94 03 ff cc  add  %o7, -52, %o2
a0093168:  96 13 21 25  or  %o4, 0x125, %o3
a009316c:  80 52 80 0b  umul  %o2, %o3, %g0
a0093170:  91 40 00 00  rd  %y, %o0
a0093174:  92 22 80 08  sub  %o2, %o0, %o1
a0093178:  9b 32 60 01  srl  %o1, 1, %o5
a009317c:  82 02 00 0d  add  %o0, %o5, %g1
a0093180:  b1 30 60 02  srl  %g1, 2, %i0
a0093184:  c2 16 63 ee  lduh  [ %i1 + 0x3ee ], %g1
a0093188:  92 00 7f cd  add  %g1, -51, %o1
a009318c:  9f 3a 60 1f  sra  %o1, 0x1f, %o7
a0093190:  99 33 e0 1d  srl  %o7, 0x1d, %o4
a0093194:  96 02 40 0c  add  %o1, %o4, %o3
a0093198:  94 0a ff f8  and  %o3, -8, %o2
a009319c:  90 22 40 0a  sub  %o1, %o2, %o0
a00931a0:  9a 02 20 34  add  %o0, 0x34, %o5
a00931a4:  da 26 63 ec  st  %o5, [ %i1 + 0x3ec ]
a00931a8:  40 00 5c de  call  0xa00aa520
a00931ac:  90 0a 20 ff  and  %o0, 0xff, %o0
a00931b0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00931b4:  80 a2 20 01  cmp  %o0, 1
a00931b8:  12 bf ff f4  bne  0xa0093188
a00931bc:  c2 16 63 ee  lduh  [ %i1 + 0x3ee ], %g1
a00931c0:  c2 06 63 ec  ld  [ %i1 + 0x3ec ], %g1
a00931c4:  13 09 24 92  sethi  %hi(0x24924800), %o1
a00931c8:  b2 12 61 25  or  %o1, 0x125, %i1	! 0x24924925
a00931cc:  9e 00 7f cc  add  %g1, -52, %o7
a00931d0:  80 53 c0 19  umul  %o7, %i1, %g0
a00931d4:  95 40 00 00  rd  %y, %o2
a00931d8:  98 23 c0 0a  sub  %o7, %o2, %o4
a00931dc:  97 33 20 01  srl  %o4, 1, %o3
a00931e0:  9a 02 80 0b  add  %o2, %o3, %o5
a00931e4:  b3 33 60 02  srl  %o5, 2, %i1
a00931e8:  92 0e 20 ff  and  %i0, 0xff, %o1
a00931ec:  80 a2 40 19  cmp  %o1, %i1
a00931f0:  02 80 00 05  be  0xa0093204
a00931f4:  33 2a 00 ab  sethi  %hi(0xa802ac00), %i1
a00931f8:  90 22 00 18  sub  %o0, %i0, %o0
a00931fc:  40 00 5d 90  call  0xa00aa83c
a0093200:  90 0a 20 ff  and  %o0, 0xff, %o0
a0093204:  d6 06 63 ec  ld  [ %i1 + 0x3ec ], %o3
a0093208:  94 02 ff cc  add  %o3, -52, %o2
a009320c:  90 0a a0 ff  and  %o2, 0xff, %o0
a0093210:  40 00 57 7f  call  0xa00a900c
a0093214:  92 10 20 01  mov  1, %o1
a0093218:  da 06 63 ec  ld  [ %i1 + 0x3ec ], %o5
a009321c:  b0 03 7f cc  add  %o5, -52, %i0
a0093220:  92 0e 20 ff  and  %i0, 0xff, %o1
a0093224:  40 00 70 8a  call  0xa00af44c
a0093228:  90 10 20 34  mov  0x34, %o0
a009322c:  c2 06 63 ec  ld  [ %i1 + 0x3ec ], %g1
a0093230:  80 a0 60 35  cmp  %g1, 0x35
a0093234:  02 80 00 16  be  0xa009328c
a0093238:  80 a0 60 3b  cmp  %g1, 0x3b
a009323c:  02 80 00 11  be  0xa0093280
a0093240:  9e 10 3f ff  mov  -1, %o7
a0093244:  19 2a 00 b5  sethi  %hi(0xa802d400), %o4
a0093248:  de 2b 20 19  stb  %o7, [ %o4 + 0x19 ]	! 0xa802d419
a009324c:  40 00 60 9c  call  0xa00ab4bc
a0093250:  b0 10 20 00  clr  %i0
a0093254:  90 10 20 01  mov  1, %o0
a0093258:  40 00 58 84  call  0xa00a9468
a009325c:  92 10 20 02  mov  2, %o1
a0093260:  90 10 20 02  mov  2, %o0
a0093264:  40 00 58 81  call  0xa00a9468
a0093268:  92 10 20 05  mov  5, %o1
a009326c:  90 10 20 00  clr  %o0
a0093270:  40 00 58 7e  call  0xa00a9468
a0093274:  92 10 20 00  clr  %o1
a0093278:  40 00 80 97  call  0xa00b34d4
a009327c:  93 e8 20 01  restore  %g0, 1, %o1
a0093280:  b0 10 20 01  mov  1, %i0
a0093284:  40 00 58 79  call  0xa00a9468
a0093288:  93 e8 20 06  restore  %g0, 6, %o1
a009328c:  90 10 20 01  mov  1, %o0
a0093290:  40 00 58 76  call  0xa00a9468
a0093294:  92 10 20 03  mov  3, %o1
a0093298:  b0 10 20 00  clr  %i0
a009329c:  40 00 80 8e  call  0xa00b34d4
a00932a0:  93 e8 20 04  restore  %g0, 4, %o1
a00932a4:  01 00 00 00  nop
