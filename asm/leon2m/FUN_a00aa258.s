# leon2m FUN_a00aa258 0xa00aa258-0xa00aa33c (228 bytes)
a00aa258:  9d e3 bf 90  save  %sp, -112, %sp
a00aa25c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00aa260:  82 06 00 18  add  %i0, %i0, %g1
a00aa264:  80 a6 20 01  cmp  %i0, 1
a00aa268:  02 80 00 08  be  0xa00aa288
a00aa26c:  96 00 60 06  add  %g1, 6, %o3
a00aa270:  90 10 20 01  mov  1, %o0
a00aa274:  7f ff fc 7d  call  0xa00a9468
a00aa278:  92 10 20 02  mov  2, %o1
a00aa27c:  b0 10 20 00  clr  %i0
a00aa280:  40 00 24 95  call  0xa00b34d4
a00aa284:  93 e8 20 01  restore  %g0, 1, %o1
a00aa288:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00aa28c:  da 02 23 ac  ld  [ %o0 + 0x3ac ], %o5	! 0xa802d3ac
a00aa290:  80 8b 60 10  btst  0x10, %o5
a00aa294:  12 80 00 03  bne  0xa00aa2a0
a00aa298:  9a 10 20 01  mov  1, %o5
a00aa29c:  9a 10 20 00  clr  %o5
a00aa2a0:  92 0e 60 ff  and  %i1, 0xff, %o1
a00aa2a4:  80 a2 60 01  cmp  %o1, 1
a00aa2a8:  02 80 00 1f  be  0xa00aa324
a00aa2ac:  b0 0b 60 ff  and  %o5, 0xff, %i0
a00aa2b0:  80 a0 00 18  cmp  %g0, %i0
a00aa2b4:  82 40 3f ff  addx  %g0, -1, %g1
a00aa2b8:  b2 08 7e 00  and  %g1, -512, %i1
a00aa2bc:  82 06 67 92  add  %i1, 0x792, %g1
a00aa2c0:  9f 28 60 10  sll  %g1, 0x10, %o7
a00aa2c4:  95 33 e0 10  srl  %o7, 0x10, %o2
a00aa2c8:  98 1a a7 42  xor  %o2, 0x742, %o4
a00aa2cc:  80 a0 00 0c  cmp  %g0, %o4
a00aa2d0:  90 60 3f ff  subx  %g0, -1, %o0
a00aa2d4:  92 1a a7 92  xor  %o2, 0x792, %o1
a00aa2d8:  80 a0 00 09  cmp  %g0, %o1
a00aa2dc:  9a 60 3f ff  subx  %g0, -1, %o5
a00aa2e0:  80 92 00 0d  orcc  %o0, %o5, %g0
a00aa2e4:  12 80 00 03  bne  0xa00aa2f0
a00aa2e8:  82 10 20 37  mov  0x37, %g1
a00aa2ec:  82 10 20 34  mov  0x34, %g1
a00aa2f0:  98 0a e0 fe  and  %o3, 0xfe, %o4
a00aa2f4:  c2 23 a0 5c  st  %g1, [ %sp + 0x5c ]
a00aa2f8:  90 10 20 01  mov  1, %o0
a00aa2fc:  92 10 20 01  mov  1, %o1
a00aa300:  96 10 20 22  mov  0x22, %o3
a00aa304:  40 00 23 f8  call  0xa00b32e4
a00aa308:  9a 10 20 03  mov  3, %o5
a00aa30c:  90 10 20 01  mov  1, %o0
a00aa310:  7f ff fc 56  call  0xa00a9468
a00aa314:  92 10 20 03  mov  3, %o1
a00aa318:  b0 10 20 00  clr  %i0
a00aa31c:  40 00 24 6e  call  0xa00b34d4
a00aa320:  93 e8 20 02  restore  %g0, 2, %o1
a00aa324:  9e 0b 60 ff  and  %o5, 0xff, %o7
a00aa328:  80 a0 00 0f  cmp  %g0, %o7
a00aa32c:  98 40 3f ff  addx  %g0, -1, %o4
a00aa330:  94 0b 3e 00  and  %o4, -512, %o2
a00aa334:  10 bf ff e3  b  0xa00aa2c0
a00aa338:  82 02 a7 42  add  %o2, 0x742, %g1
