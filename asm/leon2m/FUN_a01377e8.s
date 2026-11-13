# leon2m FUN_a01377e8 0xa01377e8-0xa013782c (68 bytes)
a01377e8:  9d e3 bf 90  save  %sp, -112, %sp
a01377ec:  90 10 20 01  mov  1, %o0
a01377f0:  92 10 20 cc  mov  0xcc, %o1
a01377f4:  94 07 bf f4  add  %fp, -12, %o2
a01377f8:  c0 27 bf f4  clr  [ %fp + -12 ]
a01377fc:  67 fd 53 35  call  0x4008c4d0
a0137800:  96 10 20 01  mov  1, %o3
a0137804:  15 00 00 3f  sethi  %hi(0xfc00), %o2
a0137808:  d2 07 bf f4  ld  [ %fp + -12 ], %o1
a013780c:  9a 12 a3 00  or  %o2, 0x300, %o5
a0137810:  90 0a 40 0d  and  %o1, %o5, %o0
a0137814:  83 32 20 08  srl  %o0, 8, %g1
a0137818:  b0 0e 00 01  and  %i0, %g1, %i0
a013781c:  80 a0 00 18  cmp  %g0, %i0
a0137820:  b0 40 20 00  addx  %g0, 0, %i0
a0137824:  81 c7 e0 08  ret
a0137828:  81 e8 00 00  restore
