# leon2m FUN_a00e2288 0xa00e2288-0xa00e2340 (184 bytes)
a00e2288:  9d e3 bf 98  save  %sp, -104, %sp
a00e228c:  92 10 20 00  clr  %o1
a00e2290:  94 10 20 10  mov  0x10, %o2
a00e2294:  7f ff f8 a0  call  0xa00e0514
a00e2298:  90 10 00 18  mov  %i0, %o0
a00e229c:  a0 10 00 08  mov  %o0, %l0
a00e22a0:  80 a6 60 04  cmp  %i1, 4
a00e22a4:  b6 10 20 3f  mov  0x3f, %i3
a00e22a8:  02 80 00 22  be  0xa00e2330
a00e22ac:  a2 10 20 00  clr  %l1
a00e22b0:  80 a6 60 03  cmp  %i1, 3
a00e22b4:  22 80 00 02  be,a   0xa00e22bc
a00e22b8:  b6 10 20 1f  mov  0x1f, %i3
a00e22bc:  92 10 20 d5  mov  0xd5, %o1
a00e22c0:  94 10 00 1b  mov  %i3, %o2
a00e22c4:  7f ff f8 94  call  0xa00e0514
a00e22c8:  90 10 00 18  mov  %i0, %o0
a00e22cc:  96 02 00 1a  add  %o0, %i2, %o3
a00e22d0:  94 10 00 1b  mov  %i3, %o2
a00e22d4:  90 10 00 18  mov  %i0, %o0
a00e22d8:  7f ff f8 c0  call  0xa00e05d8
a00e22dc:  92 10 20 d5  mov  0xd5, %o1
a00e22e0:  90 10 00 18  mov  %i0, %o0
a00e22e4:  92 10 20 d5  mov  0xd5, %o1
a00e22e8:  94 10 20 1f  mov  0x1f, %o2
a00e22ec:  b4 10 00 11  mov  %l1, %i2
a00e22f0:  80 a4 20 00  cmp  %l0, 0
a00e22f4:  02 80 00 0b  be  0xa00e2320
a00e22f8:  b2 10 20 d6  mov  0xd6, %i1
a00e22fc:  80 a4 20 10  cmp  %l0, 0x10
a00e2300:  02 80 00 0e  be  0xa00e2338
a00e2304:  01 00 00 00  nop
a00e2308:  7f ff f5 41  call  0xa00df80c
a00e230c:  31 00 06 65  sethi  %hi(0x199400), %i0
a00e2310:  7f ff fa 2c  call  0xa00e0bc0
a00e2314:  b0 16 22 b8  or  %i0, 0x2b8, %i0	! 0x1996b8
a00e2318:  7f ff f3 96  call  0xa00df170
a00e231c:  81 e8 00 00  restore
a00e2320:  7f ff f8 7d  call  0xa00e0514
a00e2324:  01 00 00 00  nop
a00e2328:  7f ff f8 ac  call  0xa00e05d8
a00e232c:  97 ea 20 10  restore  %o0, 0x10, %o3
a00e2330:  10 bf ff e3  b  0xa00e22bc
a00e2334:  a2 10 20 1f  mov  0x1f, %l1
a00e2338:  81 c7 e0 08  ret
a00e233c:  81 e8 00 00  restore
