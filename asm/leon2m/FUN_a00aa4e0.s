# leon2m FUN_a00aa4e0 0xa00aa4e0-0xa00aa520 (64 bytes)
a00aa4e0:  9d e3 bf 98  save  %sp, -104, %sp
a00aa4e4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00aa4e8:  80 a6 20 05  cmp  %i0, 5
a00aa4ec:  12 80 00 0b  bne  0xa00aa518
a00aa4f0:  b0 10 20 01  mov  1, %i0
a00aa4f4:  40 00 b6 15  call  0xa00d7d48
a00aa4f8:  b0 10 20 00  clr  %i0
a00aa4fc:  80 a2 20 00  cmp  %o0, 0
a00aa500:  12 80 00 06  bne  0xa00aa518
a00aa504:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a00aa508:  da 00 60 84  ld  [ %g1 + 0x84 ], %o5	! 0xa802d484
a00aa50c:  80 a3 60 00  cmp  %o5, 0
a00aa510:  36 80 00 02  bge,a   0xa00aa518
a00aa514:  b0 10 20 01  mov  1, %i0
a00aa518:  81 c7 e0 08  ret
a00aa51c:  81 e8 00 00  restore
