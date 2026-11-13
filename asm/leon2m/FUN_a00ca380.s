# leon2m FUN_a00ca380 0xa00ca380-0xa00ca410 (144 bytes)
a00ca380:  9d e3 bf 98  save  %sp, -104, %sp
a00ca384:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00ca388:  80 a6 20 02  cmp  %i0, 2
a00ca38c:  02 80 00 19  be  0xa00ca3f0
a00ca390:  80 a6 20 03  cmp  %i0, 3
a00ca394:  02 80 00 1a  be  0xa00ca3fc
a00ca398:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00ca39c:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00ca3a0:  94 08 60 ff  and  %g1, 0xff, %o2
a00ca3a4:  98 02 bf d0  add  %o2, -48, %o4
a00ca3a8:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00ca3ac:  80 a3 60 02  cmp  %o5, 2
a00ca3b0:  18 80 00 16  bgu  0xa00ca408
a00ca3b4:  82 10 20 ff  mov  0xff, %g1
a00ca3b8:  17 2a 00 b5  sethi  %hi(0xa802d400), %o3
a00ca3bc:  40 00 41 d3  call  0xa00dab08
a00ca3c0:  d8 2a e0 6d  stb  %o4, [ %o3 + 0x6d ]	! 0xa802d46d
a00ca3c4:  7f ff b9 42  call  0xa00b88cc
a00ca3c8:  01 00 00 00  nop
a00ca3cc:  7f ff c1 a8  call  0xa00baa6c
a00ca3d0:  90 10 00 18  mov  %i0, %o0
a00ca3d4:  7f ff c1 5f  call  0xa00ba950
a00ca3d8:  90 10 00 18  mov  %i0, %o0
a00ca3dc:  90 10 00 18  mov  %i0, %o0
a00ca3e0:  7f ff c1 e8  call  0xa00bab80
a00ca3e4:  92 10 20 06  mov  6, %o1
a00ca3e8:  10 80 00 08  b  0xa00ca408
a00ca3ec:  82 10 20 00  clr  %g1
a00ca3f0:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00ca3f4:  10 bf ff eb  b  0xa00ca3a0
a00ca3f8:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00ca3fc:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00ca400:  10 bf ff e8  b  0xa00ca3a0
a00ca404:  c2 0a 20 a1  ldub  [ %o0 + 0xa1 ], %g1	! 0xa802d0a1
a00ca408:  81 c7 e0 08  ret
a00ca40c:  91 e8 00 01  restore  %g0, %g1, %o0
