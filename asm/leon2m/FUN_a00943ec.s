# leon2m FUN_a00943ec 0xa00943ec-0xa0094438 (76 bytes)
a00943ec:  9d e3 bf 98  save  %sp, -104, %sp
a00943f0:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00943f4:  98 12 a2 90  or  %o2, 0x290, %o4	! 0xa802d290
a00943f8:  d2 0b 21 3f  ldub  [ %o4 + 0x13f ], %o1
a00943fc:  11 2a 00 97  sethi  %hi(0xa8025c00), %o0
a0094400:  96 10 21 08  mov  0x108, %o3
a0094404:  03 2a 00 ab  sethi  %hi(0xa802ac00), %g1
a0094408:  9a 10 20 01  mov  1, %o5
a009440c:  d2 2a 20 55  stb  %o1, [ %o0 + 0x55 ]
a0094410:  d6 20 63 ec  st  %o3, [ %g1 + 0x3ec ]
a0094414:  40 00 83 1b  call  0xa00b5080
a0094418:  da 2b 21 a3  stb  %o5, [ %o4 + 0x1a3 ]
a009441c:  67 ff e7 a2  call  0x4008e2a4
a0094420:  b0 10 20 01  mov  1, %i0
a0094424:  67 ff e7 a0  call  0x4008e2a4
a0094428:  b2 10 20 01  mov  1, %i1
a009442c:  40 00 49 db  call  0xa00a6b98
a0094430:  95 e8 20 00  restore  %g0, 0, %o2
a0094434:  01 00 00 00  nop
