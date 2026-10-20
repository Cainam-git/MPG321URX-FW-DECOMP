# leon2m FUN_a00844f8 0xa00844f8-0xa008453c (68 bytes)
a00844f8:  9d e3 bf 98  save  %sp, -104, %sp
a00844fc:  40 02 ff e4  call  0xa014448c
a0084500:  90 10 20 01  mov  1, %o0
a0084504:  90 0a 20 ff  and  %o0, 0xff, %o0
a0084508:  80 a2 20 0d  cmp  %o0, 0xd
a008450c:  12 80 00 09  bne  0xa0084530
a0084510:  b0 10 20 00  clr  %i0
a0084514:  13 2a 00 90  sethi  %hi(0xa8024000), %o1
a0084518:  1b 2a 00 90  sethi  %hi(0xa8024000), %o5
a008451c:  d8 12 60 06  lduh  [ %o1 + 6 ], %o4
a0084520:  c2 13 60 04  lduh  [ %o5 + 4 ], %g1
a0084524:  80 a3 00 01  cmp  %o4, %g1
a0084528:  28 80 00 02  bleu,a   0xa0084530
a008452c:  b0 10 20 01  mov  1, %i0
a0084530:  b0 0e 20 01  and  %i0, 1, %i0
a0084534:  81 c7 e0 08  ret
a0084538:  81 e8 00 00  restore
