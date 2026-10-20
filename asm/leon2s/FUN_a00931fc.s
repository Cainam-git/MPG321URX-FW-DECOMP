# leon2s FUN_a00931fc 0xa00931fc-0xa009332c (304 bytes)
a00931fc:  9d e3 bf 98  save  %sp, -104, %sp
a0093200:  b4 10 00 18  mov  %i0, %i2
a0093204:  b8 10 20 00  clr  %i4
a0093208:  a0 0f 20 ff  and  %i4, 0xff, %l0
a009320c:  92 04 21 2a  add  %l0, 0x12a, %o1
a0093210:  93 2a 60 10  sll  %o1, 0x10, %o1
a0093214:  23 2a 01 f5  sethi  %hi(0xa807d400), %l1
a0093218:  b6 0e a0 ff  and  %i2, 0xff, %i3
a009321c:  c2 04 61 b8  ld  [ %l1 + 0x1b8 ], %g1
a0093220:  93 32 60 10  srl  %o1, 0x10, %o1
a0093224:  9f c0 40 00  call  %g1
a0093228:  90 10 00 1b  mov  %i3, %o0
a009322c:  a0 04 21 1e  add  %l0, 0x11e, %l0
a0093230:  96 0a 20 ff  and  %o0, 0xff, %o3
a0093234:  a1 2c 20 10  sll  %l0, 0x10, %l0
a0093238:  b0 0e 60 ff  and  %i1, 0xff, %i0
a009323c:  95 34 20 10  srl  %l0, 0x10, %o2
a0093240:  90 10 00 18  mov  %i0, %o0
a0093244:  40 00 53 84  call  0xa00a8054
a0093248:  92 10 20 00  clr  %o1
a009324c:  b8 07 20 01  inc  %i4
a0093250:  82 0f 20 ff  and  %i4, 0xff, %g1
a0093254:  80 a0 60 02  cmp  %g1, 2
a0093258:  08 bf ff ed  bleu  0xa009320c
a009325c:  a0 0f 20 ff  and  %i4, 0xff, %l0
a0093260:  b8 10 20 00  clr  %i4
a0093264:  a0 0f 20 ff  and  %i4, 0xff, %l0
a0093268:  92 04 21 30  add  %l0, 0x130, %o1
a009326c:  93 2a 60 10  sll  %o1, 0x10, %o1
a0093270:  c2 04 61 b8  ld  [ %l1 + 0x1b8 ], %g1
a0093274:  93 32 60 10  srl  %o1, 0x10, %o1
a0093278:  9f c0 40 00  call  %g1
a009327c:  90 10 00 1b  mov  %i3, %o0
a0093280:  a0 04 21 21  add  %l0, 0x121, %l0
a0093284:  96 0a 20 ff  and  %o0, 0xff, %o3
a0093288:  a1 2c 20 10  sll  %l0, 0x10, %l0
a009328c:  95 34 20 10  srl  %l0, 0x10, %o2
a0093290:  90 10 00 18  mov  %i0, %o0
a0093294:  40 00 53 70  call  0xa00a8054
a0093298:  92 10 20 00  clr  %o1
a009329c:  b8 07 20 01  inc  %i4
a00932a0:  82 0f 20 ff  and  %i4, 0xff, %g1
a00932a4:  80 a0 60 01  cmp  %g1, 1
a00932a8:  08 bf ff f0  bleu  0xa0093268
a00932ac:  a0 0f 20 ff  and  %i4, 0xff, %l0
a00932b0:  90 10 00 18  mov  %i0, %o0
a00932b4:  92 10 20 00  clr  %o1
a00932b8:  94 10 21 3e  mov  0x13e, %o2
a00932bc:  96 10 20 30  mov  0x30, %o3
a00932c0:  40 00 53 83  call  0xa00a80cc
a00932c4:  98 10 20 00  clr  %o4
a00932c8:  b8 10 20 00  clr  %i4
a00932cc:  a0 0f 20 ff  and  %i4, 0xff, %l0
a00932d0:  a0 04 21 80  add  %l0, 0x180, %l0
a00932d4:  a1 2c 20 10  sll  %l0, 0x10, %l0
a00932d8:  a1 34 20 10  srl  %l0, 0x10, %l0
a00932dc:  c2 04 61 b8  ld  [ %l1 + 0x1b8 ], %g1
a00932e0:  92 10 00 10  mov  %l0, %o1
a00932e4:  9f c0 40 00  call  %g1
a00932e8:  90 10 00 1b  mov  %i3, %o0
a00932ec:  96 0a 20 ff  and  %o0, 0xff, %o3
a00932f0:  94 10 00 10  mov  %l0, %o2
a00932f4:  90 10 00 18  mov  %i0, %o0
a00932f8:  40 00 53 57  call  0xa00a8054
a00932fc:  92 10 20 00  clr  %o1
a0093300:  b8 07 20 01  inc  %i4
a0093304:  82 0f 20 ff  and  %i4, 0xff, %g1
a0093308:  80 a0 60 08  cmp  %g1, 8
a009330c:  28 bf ff f1  bleu,a   0xa00932d0
a0093310:  a0 0f 20 ff  and  %i4, 0xff, %l0
a0093314:  b2 10 20 00  clr  %i1
a0093318:  b4 10 21 3e  mov  0x13e, %i2
a009331c:  b6 10 20 30  mov  0x30, %i3
a0093320:  40 00 53 6b  call  0xa00a80cc
a0093324:  99 e8 20 01  restore  %g0, 1, %o4
a0093328:  01 00 00 00  nop
