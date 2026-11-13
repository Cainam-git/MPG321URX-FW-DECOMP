# leon2m FUN_a00e0514 0xa00e0514-0xa00e05d8 (196 bytes)
a00e0514:  9d e3 bf 88  save  %sp, -120, %sp
a00e0518:  83 36 60 08  srl  %i1, 8, %g1
a00e051c:  a0 08 60 0f  and  %g1, 0xf, %l0
a00e0520:  80 a6 20 02  cmp  %i0, 2
a00e0524:  14 80 00 1f  bg  0xa00e05a0
a00e0528:  a2 0e 60 ff  and  %i1, 0xff, %l1
a00e052c:  03 2a 00 97  sethi  %hi(0xa8025c00), %g1
a00e0530:  1f 33 c0 8a  sethi  %hi(0xcf022800), %o7
a00e0534:  a8 10 61 10  or  %g1, 0x110, %l4
a00e0538:  9b 2e 20 02  sll  %i0, 2, %o5
a00e053c:  de 27 bf e8  st  %o7, [ %fp + -24 ]
a00e0540:  15 2a 00 ad  sethi  %hi(0xa802b400), %o2
a00e0544:  13 00 06 65  sethi  %hi(0x199400), %o1
a00e0548:  25 33 c0 8b  sethi  %hi(0xcf022c00), %l2
a00e054c:  27 33 c0 8c  sethi  %hi(0xcf023000), %l3
a00e0550:  98 07 80 0d  add  %fp, %o5, %o4
a00e0554:  e4 27 bf ec  st  %l2, [ %fp + -20 ]
a00e0558:  e6 27 bf f0  st  %l3, [ %fp + -16 ]
a00e055c:  de 02 a1 50  ld  [ %o2 + 0x150 ], %o7
a00e0560:  90 12 60 50  or  %o1, 0x50, %o0
a00e0564:  d6 0d 00 18  ldub  [ %l4 + %i0 ], %o3
a00e0568:  92 10 00 18  mov  %i0, %o1
a00e056c:  94 10 00 19  mov  %i1, %o2
a00e0570:  80 a2 c0 10  cmp  %o3, %l0
a00e0574:  c2 03 3f e8  ld  [ %o4 + -24 ], %g1
a00e0578:  02 80 00 04  be  0xa00e0588
a00e057c:  9b 2c 60 02  sll  %l1, 2, %o5
a00e0580:  e0 20 63 f8  st  %l0, [ %g1 + 0x3f8 ]
a00e0584:  e0 2d 00 18  stb  %l0, [ %l4 + %i0 ]
a00e0588:  e0 00 40 0d  ld  [ %g1 + %o5 ], %l0
a00e058c:  b0 0c 00 1a  and  %l0, %i2, %i0
a00e0590:  80 a3 e0 00  cmp  %o7, 0
a00e0594:  02 80 00 0f  be  0xa00e05d0
a00e0598:  96 10 00 18  mov  %i0, %o3
a00e059c:  30 80 00 0b  b,a   0xa00e05c8
a00e05a0:  7f ff fc 9b  call  0xa00df80c
a00e05a4:  01 00 00 00  nop
a00e05a8:  40 00 01 8c  call  0xa00e0bd8
a00e05ac:  01 00 00 00  nop
a00e05b0:  11 00 06 65  sethi  %hi(0x199400), %o0
a00e05b4:  92 10 00 18  mov  %i0, %o1
a00e05b8:  7f ff fa ee  call  0xa00df170
a00e05bc:  90 12 20 78  or  %o0, 0x78, %o0
a00e05c0:  10 bf ff dc  b  0xa00e0530
a00e05c4:  03 2a 00 97  sethi  %hi(0xa8025c00), %g1
a00e05c8:  7f ff fa ea  call  0xa00df170
a00e05cc:  01 00 00 00  nop
a00e05d0:  81 c7 e0 08  ret
a00e05d4:  81 e8 00 00  restore
