# leon2m FUN_a01095bc 0xa01095bc-0xa0109654 (152 bytes)
a01095bc:  9d e3 bf 98  save  %sp, -104, %sp
a01095c0:  11 00 06 6b  sethi  %hi(0x19ac00), %o0
a01095c4:  80 8e 20 ff  btst  0xff, %i0
a01095c8:  02 80 00 13  be  0xa0109614
a01095cc:  90 12 20 10  or  %o0, 0x10, %o0
a01095d0:  7f ff 56 e8  call  0xa00df170
a01095d4:  01 00 00 00  nop
a01095d8:  19 33 c0 45  sethi  %hi(0xcf011400), %o4
a01095dc:  9e 13 22 d4  or  %o4, 0x2d4, %o7	! 0xcf0116d4
a01095e0:  d0 03 c0 00  ld  [ %o7 ], %o0
a01095e4:  19 33 c0 46  sethi  %hi(0xcf011800), %o4
a01095e8:  b0 12 20 01  or  %o0, 1, %i0
a01095ec:  f0 23 c0 00  st  %i0, [ %o7 ]
a01095f0:  96 13 22 80  or  %o4, 0x280, %o3
a01095f4:  d4 02 c0 00  ld  [ %o3 ], %o2
a01095f8:  92 12 a0 01  or  %o2, 1, %o1
a01095fc:  d2 22 c0 00  st  %o1, [ %o3 ]
a0109600:  c2 03 00 00  ld  [ %o4 ], %g1
a0109604:  9a 08 7f fe  and  %g1, -2, %o5
a0109608:  da 23 00 00  st  %o5, [ %o4 ]
a010960c:  10 80 00 0d  b  0xa0109640
a0109610:  98 13 22 00  or  %o4, 0x200, %o4
a0109614:  1f 00 06 6b  sethi  %hi(0x19ac00), %o7
a0109618:  90 13 e0 30  or  %o7, 0x30, %o0	! 0x19ac30
a010961c:  7f ff 56 d5  call  0xa00df170
a0109620:  01 00 00 00  nop
a0109624:  15 33 c0 45  sethi  %hi(0xcf011400), %o2
a0109628:  96 12 a2 d4  or  %o2, 0x2d4, %o3	! 0xcf0116d4
a010962c:  d2 02 c0 00  ld  [ %o3 ], %o1
a0109630:  82 0a 7f fe  and  %o1, -2, %g1
a0109634:  1b 33 c0 46  sethi  %hi(0xcf011800), %o5
a0109638:  c2 22 c0 00  st  %g1, [ %o3 ]
a010963c:  98 13 62 80  or  %o5, 0x280, %o4
a0109640:  d0 03 00 00  ld  [ %o4 ], %o0
a0109644:  b0 0a 3f fe  and  %o0, -2, %i0
a0109648:  f0 23 00 00  st  %i0, [ %o4 ]
a010964c:  81 c7 e0 08  ret
a0109650:  81 e8 00 00  restore
