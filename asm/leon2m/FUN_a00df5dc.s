# leon2m FUN_a00df5dc 0xa00df5dc-0xa00df648 (108 bytes)
a00df5dc:  80 a2 60 01  cmp  %o1, 1
a00df5e0:  02 80 00 07  be  0xa00df5fc
a00df5e4:  17 30 03 40  sethi  %hi(0xc00d0000), %o3
a00df5e8:  9a 10 20 02  mov  2, %o5
a00df5ec:  92 12 e2 f4  or  %o3, 0x2f4, %o1
a00df5f0:  da 22 40 00  st  %o5, [ %o1 ]
a00df5f4:  10 80 00 06  b  0xa00df60c
a00df5f8:  95 2a 20 02  sll  %o0, 2, %o2
a00df5fc:  15 30 03 40  sethi  %hi(0xc00d0000), %o2
a00df600:  82 12 a2 f4  or  %o2, 0x2f4, %g1	! 0xc00d02f4
a00df604:  d2 20 40 00  st  %o1, [ %g1 ]
a00df608:  95 2a 20 02  sll  %o0, 2, %o2
a00df60c:  11 33 c0 00  sethi  %hi(0xcf000000), %o0
a00df610:  d6 02 80 08  ld  [ %o2 + %o0 ], %o3
a00df614:  9a 12 20 04  or  %o0, 4, %o5
a00df618:  d2 02 80 0d  ld  [ %o2 + %o5 ], %o1
a00df61c:  82 12 20 08  or  %o0, 8, %g1
a00df620:  d0 02 80 01  ld  [ %o2 + %g1 ], %o0
a00df624:  99 2a 60 08  sll  %o1, 8, %o4
a00df628:  92 12 c0 0c  or  %o3, %o4, %o1
a00df62c:  9b 2a 20 10  sll  %o0, 0x10, %o5
a00df630:  94 12 40 0d  or  %o1, %o5, %o2
a00df634:  82 02 80 0a  add  %o2, %o2, %g1
a00df638:  98 00 40 0a  add  %g1, %o2, %o4
a00df63c:  91 2b 20 02  sll  %o4, 2, %o0
a00df640:  81 c3 e0 08  retl
a00df644:  91 32 20 11  srl  %o0, 0x11, %o0
