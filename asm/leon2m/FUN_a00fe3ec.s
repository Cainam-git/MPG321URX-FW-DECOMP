# leon2m FUN_a00fe3ec 0xa00fe3ec-0xa00fe444 (88 bytes)
a00fe3ec:  9d e3 bf 98  save  %sp, -104, %sp
a00fe3f0:  40 00 7a e6  call  0xa011cf88
a00fe3f4:  01 00 00 00  nop
a00fe3f8:  90 0a 20 ff  and  %o0, 0xff, %o0
a00fe3fc:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a00fe400:  80 a2 20 81  cmp  %o0, 0x81
a00fe404:  18 80 00 04  bgu  0xa00fe414
a00fe408:  82 10 62 e0  or  %g1, 0x2e0, %g1
a00fe40c:  13 33 c0 45  sethi  %hi(0xcf011400), %o1
a00fe410:  82 12 62 d4  or  %o1, 0x2d4, %g1	! 0xcf0116d4
a00fe414:  da 00 40 00  ld  [ %g1 ], %o5
a00fe418:  94 0b 60 28  and  %o5, 0x28, %o2
a00fe41c:  9a 1a a0 08  xor  %o2, 8, %o5
a00fe420:  80 a2 a0 20  cmp  %o2, 0x20
a00fe424:  02 80 00 05  be  0xa00fe438
a00fe428:  82 10 20 03  mov  3, %g1
a00fe42c:  80 a0 00 0d  cmp  %g0, %o5
a00fe430:  98 10 20 02  mov  2, %o4
a00fe434:  82 63 20 00  subx  %o4, 0, %g1
a00fe438:  b0 08 60 ff  and  %g1, 0xff, %i0
a00fe43c:  81 c7 e0 08  ret
a00fe440:  81 e8 00 00  restore
