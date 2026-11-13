# leon2m FUN_a00993a8 0xa00993a8-0xa0099440 (152 bytes)
a00993a8:  9d e3 bf 98  save  %sp, -104, %sp
a00993ac:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00993b0:  a0 14 22 90  or  %l0, 0x290, %l0	! 0xa802d290
a00993b4:  d8 04 21 f4  ld  [ %l0 + 0x1f4 ], %o4
a00993b8:  91 33 20 1e  srl  %o4, 0x1e, %o0
a00993bc:  82 38 00 08  xnor  %g0, %o0, %g1
a00993c0:  9e 08 60 01  and  %g1, 1, %o7
a00993c4:  1b 10 00 00  sethi  %hi(0x40000000), %o5
a00993c8:  94 2b 00 0d  andn  %o4, %o5, %o2
a00993cc:  97 2b e0 1e  sll  %o7, 0x1e, %o3
a00993d0:  90 12 80 0b  or  %o2, %o3, %o0
a00993d4:  93 32 20 1e  srl  %o0, 0x1e, %o1
a00993d8:  d0 24 21 f4  st  %o0, [ %l0 + 0x1f4 ]
a00993dc:  92 0a 60 01  and  %o1, 1, %o1
a00993e0:  40 00 30 10  call  0xa00a5420
a00993e4:  90 10 20 01  mov  1, %o0
a00993e8:  40 02 2b f5  call  0xa01243bc
a00993ec:  90 10 20 01  mov  1, %o0
a00993f0:  da 04 21 f4  ld  [ %l0 + 0x1f4 ], %o5
a00993f4:  03 10 00 00  sethi  %hi(0x40000000), %g1
a00993f8:  80 8b 40 01  btst  %o5, %g1
a00993fc:  02 80 00 05  be  0xa0099410
a0099400:  01 00 00 00  nop
a0099404:  40 02 2d 99  call  0xa0124a68
a0099408:  01 00 00 00  nop
a009940c:  30 80 00 03  b,a   0xa0099418
a0099410:  40 02 2d a8  call  0xa0124ab0
a0099414:  01 00 00 00  nop
a0099418:  40 02 2d ca  call  0xa0124b40
a009941c:  01 00 00 00  nop
a0099420:  40 01 07 55  call  0xa00db174
a0099424:  01 00 00 00  nop
a0099428:  13 2a 00 ac  sethi  %hi(0xa802b000), %o1
a009942c:  d6 0a 60 8e  ldub  [ %o1 + 0x8e ], %o3	! 0xa802b08e
a0099430:  94 12 e0 02  or  %o3, 2, %o2
a0099434:  d4 2a 60 8e  stb  %o2, [ %o1 + 0x8e ]
a0099438:  81 c7 e0 08  ret
a009943c:  81 e8 00 00  restore
