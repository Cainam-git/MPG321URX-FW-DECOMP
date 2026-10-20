# leon2m FUN_a00f643c 0xa00f643c-0xa00f6508 (204 bytes)
a00f643c:  17 33 c0 3b  sethi  %hi(0xcf00ec00), %o3
a00f6440:  9a 12 e3 30  or  %o3, 0x330, %o5	! 0xcf00ef30
a00f6444:  d8 03 40 00  ld  [ %o5 ], %o4
a00f6448:  94 0b 3f fd  and  %o4, -3, %o2
a00f644c:  d4 23 40 00  st  %o2, [ %o5 ]
a00f6450:  98 12 e3 34  or  %o3, 0x334, %o4
a00f6454:  82 10 20 01  mov  1, %g1
a00f6458:  c2 23 00 00  st  %g1, [ %o4 ]
a00f645c:  94 12 e3 3c  or  %o3, 0x33c, %o2
a00f6460:  98 10 20 00  clr  %o4
a00f6464:  9a 10 20 00  clr  %o5
a00f6468:  80 a2 20 00  cmp  %o0, 0
a00f646c:  02 80 00 12  be  0xa00f64b4
a00f6470:  96 12 e3 38  or  %o3, 0x338, %o3
a00f6474:  c2 02 00 00  ld  [ %o0 ], %g1
a00f6478:  83 30 40 0d  srl  %g1, %o5, %g1
a00f647c:  80 88 60 01  btst  1, %g1
a00f6480:  22 80 00 07  be,a   0xa00f649c
a00f6484:  98 03 20 01  inc  %o4
a00f6488:  da 22 c0 00  st  %o5, [ %o3 ]
a00f648c:  82 02 00 0d  add  %o0, %o5, %g1
a00f6490:  da 08 60 04  ldub  [ %g1 + 4 ], %o5
a00f6494:  da 22 80 00  st  %o5, [ %o2 ]
a00f6498:  98 03 20 01  inc  %o4
a00f649c:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00f64a0:  80 a3 60 17  cmp  %o5, 0x17
a00f64a4:  28 bf ff f5  bleu,a   0xa00f6478
a00f64a8:  c2 02 00 00  ld  [ %o0 ], %g1
a00f64ac:  10 80 00 11  b  0xa00f64f0
a00f64b0:  19 33 c0 3b  sethi  %hi(0xcf00ec00), %o4
a00f64b4:  da 22 c0 00  st  %o5, [ %o3 ]
a00f64b8:  98 03 20 01  inc  %o4
a00f64bc:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00f64c0:  c0 22 80 00  clr  [ %o2 ]
a00f64c4:  80 a3 60 17  cmp  %o5, 0x17
a00f64c8:  38 80 00 0a  bgu,a   0xa00f64f0
a00f64cc:  19 33 c0 3b  sethi  %hi(0xcf00ec00), %o4
a00f64d0:  da 22 c0 00  st  %o5, [ %o3 ]
a00f64d4:  98 03 20 01  inc  %o4
a00f64d8:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00f64dc:  c0 22 80 00  clr  [ %o2 ]
a00f64e0:  80 a3 60 17  cmp  %o5, 0x17
a00f64e4:  08 bf ff f4  bleu  0xa00f64b4
a00f64e8:  01 00 00 00  nop
a00f64ec:  19 33 c0 3b  sethi  %hi(0xcf00ec00), %o4
a00f64f0:  90 13 23 30  or  %o4, 0x330, %o0	! 0xcf00ef30
a00f64f4:  d4 02 00 00  ld  [ %o0 ], %o2
a00f64f8:  96 12 a0 02  or  %o2, 2, %o3
a00f64fc:  d6 22 00 00  st  %o3, [ %o0 ]
a00f6500:  81 c3 e0 08  retl
a00f6504:  01 00 00 00  nop
