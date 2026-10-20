# leon2m FUN_a011e794 0xa011e794-0xa011e8fc (360 bytes)
a011e794:  92 0a 60 ff  and  %o1, 0xff, %o1
a011e798:  80 a2 60 01  cmp  %o1, 1
a011e79c:  02 80 00 2f  be  0xa011e858
a011e7a0:  1b 33 c0 59  sethi  %hi(0xcf016400), %o5
a011e7a4:  90 0a 20 ff  and  %o0, 0xff, %o0
a011e7a8:  80 a2 20 10  cmp  %o0, 0x10
a011e7ac:  02 80 00 25  be  0xa011e840
a011e7b0:  82 13 60 80  or  %o5, 0x80, %g1
a011e7b4:  03 33 c0 59  sethi  %hi(0xcf016400), %g1
a011e7b8:  80 a2 20 11  cmp  %o0, 0x11
a011e7bc:  02 80 00 18  be  0xa011e81c
a011e7c0:  82 10 60 80  or  %g1, 0x80, %g1
a011e7c4:  80 a2 20 12  cmp  %o0, 0x12
a011e7c8:  02 80 00 1c  be  0xa011e838
a011e7cc:  80 a2 20 13  cmp  %o0, 0x13
a011e7d0:  03 33 c0 59  sethi  %hi(0xcf016400), %g1
a011e7d4:  02 80 00 12  be  0xa011e81c
a011e7d8:  82 10 60 84  or  %g1, 0x84, %g1	! 0xcf016484
a011e7dc:  19 33 c0 59  sethi  %hi(0xcf016400), %o4
a011e7e0:  80 a2 20 14  cmp  %o0, 0x14
a011e7e4:  02 80 00 17  be  0xa011e840
a011e7e8:  82 13 20 88  or  %o4, 0x88, %g1
a011e7ec:  13 33 c0 59  sethi  %hi(0xcf016400), %o1
a011e7f0:  80 a2 20 15  cmp  %o0, 0x15
a011e7f4:  02 80 00 0a  be  0xa011e81c
a011e7f8:  82 12 60 88  or  %o1, 0x88, %g1
a011e7fc:  1b 33 c0 59  sethi  %hi(0xcf016400), %o5
a011e800:  80 a2 20 16  cmp  %o0, 0x16
a011e804:  02 80 00 0f  be  0xa011e840
a011e808:  82 13 60 8c  or  %o5, 0x8c, %g1
a011e80c:  80 a2 20 17  cmp  %o0, 0x17
a011e810:  12 80 00 39  bne  0xa011e8f4
a011e814:  11 33 c0 59  sethi  %hi(0xcf016400), %o0
a011e818:  82 12 20 8c  or  %o0, 0x8c, %g1	! 0xcf01648c
a011e81c:  da 00 40 00  ld  [ %g1 ], %o5
a011e820:  92 13 60 04  or  %o5, 4, %o1
a011e824:  d2 20 40 00  st  %o1, [ %g1 ]
a011e828:  d8 00 40 00  ld  [ %g1 ], %o4
a011e82c:  98 0b 3f f7  and  %o4, -9, %o4
a011e830:  d8 20 40 00  st  %o4, [ %g1 ]
a011e834:  30 80 00 30  b,a   0xa011e8f4
a011e838:  19 33 c0 59  sethi  %hi(0xcf016400), %o4
a011e83c:  82 13 20 84  or  %o4, 0x84, %g1	! 0xcf016484
a011e840:  da 00 40 00  ld  [ %g1 ], %o5
a011e844:  92 13 60 40  or  %o5, 0x40, %o1
a011e848:  d2 20 40 00  st  %o1, [ %g1 ]
a011e84c:  d0 00 40 00  ld  [ %g1 ], %o0
a011e850:  10 bf ff f8  b  0xa011e830
a011e854:  98 0a 3f 7f  and  %o0, -129, %o4
a011e858:  90 0a 20 ff  and  %o0, 0xff, %o0
a011e85c:  80 a2 20 10  cmp  %o0, 0x10
a011e860:  02 80 00 22  be  0xa011e8e8
a011e864:  9a 13 60 80  or  %o5, 0x80, %o5
a011e868:  03 33 c0 59  sethi  %hi(0xcf016400), %g1
a011e86c:  80 a2 20 11  cmp  %o0, 0x11
a011e870:  02 80 00 18  be  0xa011e8d0
a011e874:  9a 10 60 80  or  %g1, 0x80, %o5
a011e878:  80 a2 20 12  cmp  %o0, 0x12
a011e87c:  02 80 00 19  be  0xa011e8e0
a011e880:  13 33 c0 59  sethi  %hi(0xcf016400), %o1
a011e884:  80 a2 20 13  cmp  %o0, 0x13
a011e888:  02 80 00 12  be  0xa011e8d0
a011e88c:  9a 12 60 84  or  %o1, 0x84, %o5
a011e890:  1b 33 c0 59  sethi  %hi(0xcf016400), %o5
a011e894:  80 a2 20 14  cmp  %o0, 0x14
a011e898:  02 80 00 14  be  0xa011e8e8
a011e89c:  9a 13 60 88  or  %o5, 0x88, %o5
a011e8a0:  03 33 c0 59  sethi  %hi(0xcf016400), %g1
a011e8a4:  80 a2 20 15  cmp  %o0, 0x15
a011e8a8:  02 80 00 0a  be  0xa011e8d0
a011e8ac:  9a 10 60 88  or  %g1, 0x88, %o5
a011e8b0:  19 33 c0 59  sethi  %hi(0xcf016400), %o4
a011e8b4:  80 a2 20 16  cmp  %o0, 0x16
a011e8b8:  02 80 00 0c  be  0xa011e8e8
a011e8bc:  9a 13 20 8c  or  %o4, 0x8c, %o5
a011e8c0:  80 a2 20 17  cmp  %o0, 0x17
a011e8c4:  12 80 00 0c  bne  0xa011e8f4
a011e8c8:  11 33 c0 59  sethi  %hi(0xcf016400), %o0
a011e8cc:  9a 12 20 8c  or  %o0, 0x8c, %o5	! 0xcf01648c
a011e8d0:  d2 03 40 00  ld  [ %o5 ], %o1
a011e8d4:  82 0a 7f f3  and  %o1, -13, %g1
a011e8d8:  c2 23 40 00  st  %g1, [ %o5 ]
a011e8dc:  30 80 00 06  b,a   0xa011e8f4
a011e8e0:  11 33 c0 59  sethi  %hi(0xcf016400), %o0
a011e8e4:  9a 12 20 84  or  %o0, 0x84, %o5	! 0xcf016484
a011e8e8:  d8 03 40 00  ld  [ %o5 ], %o4
a011e8ec:  82 0b 3f 3f  and  %o4, -193, %g1
a011e8f0:  c2 23 40 00  st  %g1, [ %o5 ]
a011e8f4:  81 c3 e0 08  retl
a011e8f8:  01 00 00 00  nop
