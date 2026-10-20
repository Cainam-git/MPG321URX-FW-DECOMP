# leon2m FUN_a013143c 0xa013143c-0xa0131510 (212 bytes)
a013143c:  9d e3 bf 98  save  %sp, -104, %sp
a0131440:  90 0e 60 ff  and  %i1, 0xff, %o0
a0131444:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a0131448:  b2 5a 20 2a  smul  %o0, 0x2a, %i1
a013144c:  a0 10 62 24  or  %g1, 0x224, %l0
a0131450:  80 8e 20 ff  btst  0xff, %i0
a0131454:  12 80 00 04  bne  0xa0131464
a0131458:  b2 06 40 10  add  %i1, %l0, %i1
a013145c:  10 80 00 2a  b  0xa0131504
a0131460:  82 10 3f ff  mov  -1, %g1
a0131464:  7f ff 30 ef  call  0xa00fd820
a0131468:  d0 0e 60 0b  ldub  [ %i1 + 0xb ], %o0
a013146c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0131470:  80 a2 20 b1  cmp  %o0, 0xb1
a0131474:  02 80 00 13  be  0xa01314c0
a0131478:  13 2a 00 a9  sethi  %hi(0xa802a400), %o1
a013147c:  21 00 06 94  sethi  %hi(0x1a5000), %l0
a0131480:  98 14 22 38  or  %l0, 0x238, %o4	! 0x1a5238
a0131484:  9a 10 20 00  clr  %o5
a0131488:  82 10 20 00  clr  %g1
a013148c:  d6 0b 00 01  ldub  [ %o4 + %g1 ], %o3
a0131490:  80 a2 00 0b  cmp  %o0, %o3
a0131494:  02 80 00 09  be  0xa01314b8
a0131498:  82 10 00 0d  mov  %o5, %g1
a013149c:  9a 03 60 01  inc  %o5
a01314a0:  82 0b 60 ff  and  %o5, 0xff, %g1
a01314a4:  80 a0 60 03  cmp  %g1, 3
a01314a8:  28 bf ff fa  bleu,a   0xa0131490
a01314ac:  d6 0b 00 01  ldub  [ %o4 + %g1 ], %o3
a01314b0:  10 80 00 15  b  0xa0131504
a01314b4:  c2 0e 60 0c  ldub  [ %i1 + 0xc ], %g1
a01314b8:  10 80 00 13  b  0xa0131504
a01314bc:  da 2e 60 0c  stb  %o5, [ %i1 + 0xc ]
a01314c0:  da 0a 60 4c  ldub  [ %o1 + 0x4c ], %o5
a01314c4:  80 a3 60 ff  cmp  %o5, 0xff
a01314c8:  02 80 00 0d  be  0xa01314fc
a01314cc:  82 10 3f ff  mov  -1, %g1
a01314d0:  95 2b 60 04  sll  %o5, 4, %o2
a01314d4:  92 22 80 0d  sub  %o2, %o5, %o1
a01314d8:  11 2a 00 b7  sethi  %hi(0xa802dc00), %o0
a01314dc:  82 12 23 30  or  %o0, 0x330, %g1	! 0xa802df30
a01314e0:  b1 2a 60 03  sll  %o1, 3, %i0
a01314e4:  de 00 40 18  ld  [ %g1 + %i0 ], %o7
a01314e8:  9b 33 e0 0c  srl  %o7, 0xc, %o5
a01314ec:  98 0b 60 0f  and  %o5, 0xf, %o4
a01314f0:  96 5b 20 2a  smul  %o4, 0x2a, %o3
a01314f4:  94 02 c0 10  add  %o3, %l0, %o2
a01314f8:  c2 0a a0 0a  ldub  [ %o2 + 0xa ], %g1
a01314fc:  10 bf ff e0  b  0xa013147c
a0131500:  90 08 60 ff  and  %g1, 0xff, %o0
a0131504:  c2 2e 60 0d  stb  %g1, [ %i1 + 0xd ]
a0131508:  81 c7 e0 08  ret
a013150c:  81 e8 00 00  restore
