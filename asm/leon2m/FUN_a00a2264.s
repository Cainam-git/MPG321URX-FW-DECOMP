# leon2m FUN_a00a2264 0xa00a2264-0xa00a231c (184 bytes)
a00a2264:  9d e3 bf 98  save  %sp, -104, %sp
a00a2268:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00a226c:  1b 2a 00 97  sethi  %hi(0xa8025c00), %o5
a00a2270:  a0 10 62 90  or  %g1, 0x290, %l0
a00a2274:  de 0b 60 55  ldub  [ %o5 + 0x55 ], %o7
a00a2278:  98 10 20 02  mov  2, %o4
a00a227c:  23 2a 00 97  sethi  %hi(0xa8025c00), %l1
a00a2280:  de 2c 21 e9  stb  %o7, [ %l0 + 0x1e9 ]
a00a2284:  d8 2c 60 56  stb  %o4, [ %l1 + 0x56 ]
a00a2288:  40 00 1c 4d  call  0xa00a93bc
a00a228c:  90 10 20 00  clr  %o0
a00a2290:  40 00 1a 7e  call  0xa00a8c88
a00a2294:  01 00 00 00  nop
a00a2298:  96 10 20 c0  mov  0xc0, %o3	! 0xc0
a00a229c:  15 2a 00 ab  sethi  %hi(0xa802ac00), %o2
a00a22a0:  d6 22 a3 ec  st  %o3, [ %o2 + 0x3ec ]	! 0xa802afec
a00a22a4:  40 00 29 1d  call  0xa00ac718
a00a22a8:  90 10 20 38  mov  0x38, %o0
a00a22ac:  d0 0c 60 56  ldub  [ %l1 + 0x56 ], %o0
a00a22b0:  40 00 1c e8  call  0xa00a9650
a00a22b4:  92 10 20 01  mov  1, %o1
a00a22b8:  92 10 3f ff  mov  -1, %o1
a00a22bc:  40 00 24 80  call  0xa00ab4bc
a00a22c0:  d2 2c 21 89  stb  %o1, [ %l0 + 0x189 ]
a00a22c4:  90 10 20 01  mov  1, %o0
a00a22c8:  40 00 1c 68  call  0xa00a9468
a00a22cc:  92 10 20 02  mov  2, %o1
a00a22d0:  90 10 20 02  mov  2, %o0
a00a22d4:  40 00 1c 65  call  0xa00a9468
a00a22d8:  92 10 20 05  mov  5, %o1
a00a22dc:  92 10 20 00  clr  %o1
a00a22e0:  40 00 1c 62  call  0xa00a9468
a00a22e4:  90 10 20 00  clr  %o0
a00a22e8:  40 00 44 59  call  0xa00b344c
a00a22ec:  90 10 20 07  mov  7, %o0
a00a22f0:  90 10 20 00  clr  %o0
a00a22f4:  40 00 44 78  call  0xa00b34d4
a00a22f8:  92 10 20 01  mov  1, %o1
a00a22fc:  40 00 e2 41  call  0xa00dac00
a00a2300:  01 00 00 00  nop
a00a2304:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00a2308:  d0 0b 60 8e  ldub  [ %o5 + 0x8e ], %o0	! 0xa802b08e
a00a230c:  82 12 20 02  or  %o0, 2, %g1
a00a2310:  c2 2b 60 8e  stb  %g1, [ %o5 + 0x8e ]
a00a2314:  81 c7 e0 08  ret
a00a2318:  81 e8 00 00  restore
