# leon2s FUN_a0096428 0xa0096428-0xa009645c (52 bytes)
a0096428:  9d e3 bf 98  save  %sp, -104, %sp
a009642c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0096430:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a0096434:  b0 5e 20 34  smul  %i0, 0x34, %i0
a0096438:  82 10 63 00  or  %g1, 0x300, %g1
a009643c:  d2 00 40 18  ld  [ %g1 + %i0 ], %o1
a0096440:  92 02 60 70  add  %o1, 0x70, %o1
a0096444:  40 00 43 f1  call  0xa00a7408
a0096448:  90 10 20 18  mov  0x18, %o0
a009644c:  80 a0 00 08  cmp  %g0, %o0
a0096450:  b0 40 20 00  addx  %g0, 0, %i0
a0096454:  81 c7 e0 08  ret
a0096458:  81 e8 00 00  restore
