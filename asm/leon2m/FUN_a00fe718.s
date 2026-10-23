# leon2m FUN_a00fe718 0xa00fe718-0xa00fe7d8 (192 bytes)
a00fe718:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a00fe71c:  94 10 62 dc  or  %g1, 0x2dc, %o2	! 0xcf0116dc
a00fe720:  da 02 80 00  ld  [ %o2 ], %o5
a00fe724:  98 0b 60 3f  and  %o5, 0x3f, %o4
a00fe728:  90 0a 20 ff  and  %o0, 0xff, %o0
a00fe72c:  80 a2 20 01  cmp  %o0, 1
a00fe730:  02 80 00 0b  be  0xa00fe75c
a00fe734:  96 10 00 0c  mov  %o4, %o3
a00fe738:  80 a2 20 01  cmp  %o0, 1
a00fe73c:  04 80 00 18  ble  0xa00fe79c
a00fe740:  80 a2 20 02  cmp  %o0, 2
a00fe744:  02 80 00 0e  be  0xa00fe77c
a00fe748:  80 a2 20 03  cmp  %o0, 3
a00fe74c:  12 80 00 21  bne  0xa00fe7d0
a00fe750:  11 33 c0 b7  sethi  %hi(0xcf02dc00), %o0
a00fe754:  10 80 00 1c  b  0xa00fe7c4
a00fe758:  94 12 20 04  or  %o0, 4, %o2	! 0xcf02dc04
a00fe75c:  03 33 c0 b7  sethi  %hi(0xcf02dc00), %g1
a00fe760:  96 10 60 04  or  %g1, 4, %o3	! 0xcf02dc04
a00fe764:  da 02 c0 00  ld  [ %o3 ], %o5
a00fe768:  90 13 60 20  or  %o5, 0x20, %o0
a00fe76c:  d0 22 c0 00  st  %o0, [ %o3 ]
a00fe770:  98 13 20 80  or  %o4, 0x80, %o4
a00fe774:  d8 22 80 00  st  %o4, [ %o2 ]
a00fe778:  30 80 00 16  b,a   0xa00fe7d0
a00fe77c:  03 33 c0 b7  sethi  %hi(0xcf02dc00), %g1
a00fe780:  96 10 60 04  or  %g1, 4, %o3	! 0xcf02dc04
a00fe784:  da 02 c0 00  ld  [ %o3 ], %o5
a00fe788:  90 13 60 20  or  %o5, 0x20, %o0
a00fe78c:  d0 22 c0 00  st  %o0, [ %o3 ]
a00fe790:  98 13 20 c0  or  %o4, 0xc0, %o4
a00fe794:  d8 22 80 00  st  %o4, [ %o2 ]
a00fe798:  30 80 00 0e  b,a   0xa00fe7d0
a00fe79c:  80 a2 20 00  cmp  %o0, 0
a00fe7a0:  12 80 00 0c  bne  0xa00fe7d0
a00fe7a4:  03 33 c0 b7  sethi  %hi(0xcf02dc00), %g1
a00fe7a8:  90 10 60 04  or  %g1, 4, %o0	! 0xcf02dc04
a00fe7ac:  da 02 00 00  ld  [ %o0 ], %o5
a00fe7b0:  98 13 60 20  or  %o5, 0x20, %o4
a00fe7b4:  d8 22 00 00  st  %o4, [ %o0 ]
a00fe7b8:  98 0a e0 ff  and  %o3, 0xff, %o4
a00fe7bc:  d8 22 80 00  st  %o4, [ %o2 ]
a00fe7c0:  30 80 00 04  b,a   0xa00fe7d0
a00fe7c4:  d6 02 80 00  ld  [ %o2 ], %o3
a00fe7c8:  98 0a ff df  and  %o3, -33, %o4
a00fe7cc:  d8 22 80 00  st  %o4, [ %o2 ]
a00fe7d0:  81 c3 e0 08  retl
a00fe7d4:  01 00 00 00  nop
