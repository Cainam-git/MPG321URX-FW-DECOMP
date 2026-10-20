# leon2s FUN_a009c434 0xa009c434-0xa009c468 (52 bytes)
a009c434:  9d e3 bf 98  save  %sp, -104, %sp
a009c438:  b0 0e 20 ff  and  %i0, 0xff, %i0
a009c43c:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a009c440:  82 10 63 00  or  %g1, 0x300, %g1	! 0xa807db00
a009c444:  b0 5e 20 34  smul  %i0, 0x34, %i0
a009c448:  b0 06 00 01  add  %i0, %g1, %i0
a009c44c:  d2 06 20 04  ld  [ %i0 + 4 ], %o1
a009c450:  40 00 2b ee  call  0xa00a7408
a009c454:  90 10 20 01  mov  1, %o0
a009c458:  80 a0 00 08  cmp  %g0, %o0
a009c45c:  b0 40 20 00  addx  %g0, 0, %i0
a009c460:  81 c7 e0 08  ret
a009c464:  81 e8 00 00  restore
