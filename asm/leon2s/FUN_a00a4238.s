# leon2s FUN_a00a4238 0xa00a4238-0xa00a4370 (312 bytes)
a00a4238:  9d e3 bf 98  save  %sp, -104, %sp
a00a423c:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a00a4240:  a6 10 63 6c  or  %g1, 0x36c, %l3	! 0xa807db6c
a00a4244:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a4248:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00a424c:  a1 2e 20 02  sll  %i0, 2, %l0
a00a4250:  a2 10 63 3c  or  %g1, 0x33c, %l1
a00a4254:  11 28 01 af  sethi  %hi(0xa006bc00), %o0
a00a4258:  da 04 c0 10  ld  [ %l3 + %l0 ], %o5
a00a425c:  c2 04 40 10  ld  [ %l1 + %l0 ], %g1
a00a4260:  90 12 22 78  or  %o0, 0x278, %o0
a00a4264:  92 10 00 18  mov  %i0, %o1
a00a4268:  80 a3 40 01  cmp  %o5, %g1
a00a426c:  29 2a 01 e4  sethi  %hi(0xa8079000), %l4
a00a4270:  02 80 00 06  be  0xa00a4288
a00a4274:  2b 28 01 af  sethi  %hi(0xa006bc00), %l5
a00a4278:  7f ff 3b 73  call  0xa0073044
a00a427c:  01 00 00 00  nop
a00a4280:  c2 04 c0 10  ld  [ %l3 + %l0 ], %g1
a00a4284:  c2 24 40 10  st  %g1, [ %l1 + %l0 ]
a00a4288:  7f ff b5 d6  call  0xa00919e0
a00a428c:  90 10 00 18  mov  %i0, %o0
a00a4290:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a4294:  a4 10 61 fc  or  %g1, 0x1fc, %l2	! 0xa80791fc
a00a4298:  c2 04 80 10  ld  [ %l2 + %l0 ], %g1
a00a429c:  9a 00 7f ff  add  %g1, -1, %o5
a00a42a0:  90 10 00 18  mov  %i0, %o0
a00a42a4:  80 a0 60 00  cmp  %g1, 0
a00a42a8:  02 80 00 07  be  0xa00a42c4
a00a42ac:  92 0b 60 ff  and  %o5, 0xff, %o1
a00a42b0:  7f ff b5 9a  call  0xa0091918
a00a42b4:  da 24 80 10  st  %o5, [ %l2 + %l0 ]
a00a42b8:  7f ff b6 2f  call  0xa0091b74
a00a42bc:  90 10 00 18  mov  %i0, %o0
a00a42c0:  c2 04 80 10  ld  [ %l2 + %l0 ], %g1
a00a42c4:  a2 08 60 ff  and  %g1, 0xff, %l1
a00a42c8:  90 10 00 18  mov  %i0, %o0
a00a42cc:  9a 15 21 f0  or  %l4, 0x1f0, %o5
a00a42d0:  92 10 20 31  mov  0x31, %o1
a00a42d4:  80 a0 60 00  cmp  %g1, 0
a00a42d8:  12 80 00 18  bne  0xa00a4338
a00a42dc:  94 10 00 11  mov  %l1, %o2
a00a42e0:  7f ff b5 aa  call  0xa0091988
a00a42e4:  01 00 00 00  nop
a00a42e8:  7f ff b6 23  call  0xa0091b74
a00a42ec:  90 10 00 18  mov  %i0, %o0
a00a42f0:  82 10 20 06  mov  6, %g1
a00a42f4:  c2 24 c0 10  st  %g1, [ %l3 + %l0 ]
a00a42f8:  7f ff b5 f3  call  0xa0091ac4
a00a42fc:  90 10 00 18  mov  %i0, %o0
a00a4300:  11 28 01 af  sethi  %hi(0xa006bc00), %o0
a00a4304:  7f ff 3c 70  call  0xa00734c4
a00a4308:  90 12 22 e8  or  %o0, 0x2e8, %o0	! 0xa006bee8
a00a430c:  e0 04 80 10  ld  [ %l2 + %l0 ], %l0
a00a4310:  a0 0c 20 ff  and  %l0, 0xff, %l0
a00a4314:  82 15 21 f0  or  %l4, 0x1f0, %g1
a00a4318:  90 10 00 18  mov  %i0, %o0
a00a431c:  94 10 00 10  mov  %l0, %o2
a00a4320:  c0 28 40 18  clrb  [ %g1 + %i0 ]
a00a4324:  7f ff b6 74  call  0xa0091cf4
a00a4328:  92 10 20 31  mov  0x31, %o1
a00a432c:  90 15 62 c0  or  %l5, 0x2c0, %o0
a00a4330:  10 80 00 0c  b  0xa00a4360
a00a4334:  94 10 00 10  mov  %l0, %o2
a00a4338:  82 10 20 03  mov  3, %g1
a00a433c:  c2 24 c0 10  st  %g1, [ %l3 + %l0 ]
a00a4340:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a4344:  82 10 61 e8  or  %g1, 0x1e8, %g1	! 0xa80791e8
a00a4348:  90 10 00 18  mov  %i0, %o0
a00a434c:  c0 28 40 18  clrb  [ %g1 + %i0 ]
a00a4350:  7f ff b6 69  call  0xa0091cf4
a00a4354:  c0 2b 40 18  clrb  [ %o5 + %i0 ]
a00a4358:  90 15 62 c0  or  %l5, 0x2c0, %o0
a00a435c:  94 10 00 11  mov  %l1, %o2
a00a4360:  7f ff 3b 39  call  0xa0073044
a00a4364:  92 10 20 31  mov  0x31, %o1
a00a4368:  81 c7 e0 08  ret
a00a436c:  91 e8 20 00  restore  %g0, 0, %o0
