# leon2m FUN_a00f62ac 0xa00f62ac-0xa00f6340 (148 bytes)
a00f62ac:  9d e3 bf 98  save  %sp, -104, %sp
a00f62b0:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00f62b4:  92 10 20 36  mov  0x36, %o1
a00f62b8:  7f ff ed f6  call  0xa00f1a90
a00f62bc:  90 10 00 10  mov  %l0, %o0
a00f62c0:  80 8a 20 02  btst  2, %o0
a00f62c4:  92 10 20 9d  mov  0x9d, %o1
a00f62c8:  90 10 00 10  mov  %l0, %o0
a00f62cc:  12 80 00 1b  bne  0xa00f6338
a00f62d0:  b0 10 20 00  clr  %i0
a00f62d4:  7f ff ed ef  call  0xa00f1a90
a00f62d8:  01 00 00 00  nop
a00f62dc:  92 0a 20 ff  and  %o0, 0xff, %o1
a00f62e0:  80 a0 00 09  cmp  %g0, %o1
a00f62e4:  82 40 20 00  addx  %g0, 0, %g1
a00f62e8:  92 10 20 04  mov  4, %o1
a00f62ec:  b0 10 00 01  mov  %g1, %i0
a00f62f0:  7f ff ed e8  call  0xa00f1a90
a00f62f4:  90 10 00 10  mov  %l0, %o0
a00f62f8:  90 0a 20 0f  and  %o0, 0xf, %o0
a00f62fc:  80 a2 20 01  cmp  %o0, 1
a00f6300:  90 10 00 10  mov  %l0, %o0
a00f6304:  92 10 20 36  mov  0x36, %o1
a00f6308:  04 80 00 05  ble  0xa00f631c
a00f630c:  94 10 20 2e  mov  0x2e, %o2
a00f6310:  7f ff ed f1  call  0xa00f1ad4
a00f6314:  b0 10 20 01  mov  1, %i0
a00f6318:  30 80 00 08  b,a   0xa00f6338
a00f631c:  80 a6 20 00  cmp  %i0, 0
a00f6320:  12 bf ff fc  bne  0xa00f6310
a00f6324:  01 00 00 00  nop
a00f6328:  90 10 00 10  mov  %l0, %o0
a00f632c:  92 10 20 36  mov  0x36, %o1
a00f6330:  10 bf ff f8  b  0xa00f6310
a00f6334:  94 10 20 6e  mov  0x6e, %o2
a00f6338:  81 c7 e0 08  ret
a00f633c:  81 e8 00 00  restore
