# leon2m FUN_a012d4f8 0xa012d4f8-0xa012d554 (92 bytes)
a012d4f8:  9d e3 bf 98  save  %sp, -104, %sp
a012d4fc:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a012d500:  90 12 a1 a0  or  %o2, 0x1a0, %o0	! 0xa802e1a0
a012d504:  d2 02 20 34  ld  [ %o0 + 0x34 ], %o1
a012d508:  da 0a 20 37  ldub  [ %o0 + 0x37 ], %o5
a012d50c:  83 32 60 08  srl  %o1, 8, %g1
a012d510:  94 10 20 01  mov  1, %o2
a012d514:  96 07 a0 44  add  %fp, 0x44, %o3
a012d518:  98 10 20 01  mov  1, %o4
a012d51c:  f0 2f a0 44  stb  %i0, [ %fp + 0x44 ]
a012d520:  80 a3 60 01  cmp  %o5, 1
a012d524:  08 80 00 03  bleu  0xa012d530
a012d528:  92 10 21 20  mov  0x120, %o1
a012d52c:  92 10 22 40  mov  0x240, %o1
a012d530:  92 0a 63 60  and  %o1, 0x360, %o1
a012d534:  b0 00 40 09  add  %g1, %o1, %i0
a012d538:  9f 2e 20 10  sll  %i0, 0x10, %o7
a012d53c:  93 33 e0 10  srl  %o7, 0x10, %o1
a012d540:  40 00 4e 4d  call  0xa0140e74
a012d544:  d0 0a 20 34  ldub  [ %o0 + 0x34 ], %o0
a012d548:  01 00 00 00  nop
a012d54c:  81 c7 e0 08  ret
a012d550:  81 e8 00 00  restore
