# leon2m FUN_a01377a4 0xa01377a4-0xa01377e8 (68 bytes)
a01377a4:  9d e3 bf 90  save  %sp, -112, %sp
a01377a8:  90 10 20 01  mov  1, %o0
a01377ac:  92 10 20 0c  mov  0xc, %o1
a01377b0:  94 07 bf f4  add  %fp, -12, %o2
a01377b4:  c0 27 bf f4  clr  [ %fp + -12 ]
a01377b8:  67 fd 53 46  call  0x4008c4d0
a01377bc:  96 10 20 01  mov  1, %o3
a01377c0:  15 00 00 3f  sethi  %hi(0xfc00), %o2
a01377c4:  d2 07 bf f4  ld  [ %fp + -12 ], %o1
a01377c8:  9a 12 a3 00  or  %o2, 0x300, %o5
a01377cc:  90 0a 40 0d  and  %o1, %o5, %o0
a01377d0:  83 32 20 08  srl  %o0, 8, %g1
a01377d4:  b0 0e 00 01  and  %i0, %g1, %i0
a01377d8:  80 a0 00 18  cmp  %g0, %i0
a01377dc:  b0 40 20 00  addx  %g0, 0, %i0
a01377e0:  81 c7 e0 08  ret
a01377e4:  81 e8 00 00  restore
