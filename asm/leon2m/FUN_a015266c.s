# leon2m FUN_a015266c 0xa015266c-0xa0152a20 (948 bytes)
a015266c:  9d e3 bf 98  save  %sp, -104, %sp
a0152670:  11 2a 00 b8  sethi  %hi(0xa802e000), %o0
a0152674:  d8 02 23 d0  ld  [ %o0 + 0x3d0 ], %o4	! 0xa802e3d0
a0152678:  1b 20 00 00  sethi  %hi(0x80000000), %o5
a015267c:  92 2b 00 0d  andn  %o4, %o5, %o1
a0152680:  17 08 00 00  sethi  %hi(0x20000000), %o3
a0152684:  94 2a 40 0b  andn  %o1, %o3, %o2
a0152688:  03 00 80 00  sethi  %hi(0x2000000), %g1
a015268c:  a0 12 80 01  or  %o2, %g1, %l0
a0152690:  1f 00 40 00  sethi  %hi(0x1000000), %o7
a0152694:  98 2c 00 0f  andn  %l0, %o7, %o4
a0152698:  1b 00 20 00  sethi  %hi(0x800000), %o5
a015269c:  92 2b 00 0d  andn  %o4, %o5, %o1
a01526a0:  9a 12 23 d0  or  %o0, 0x3d0, %o5
a01526a4:  17 04 00 00  sethi  %hi(0x10000000), %o3
a01526a8:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a01526ac:  94 2a 40 0b  andn  %o1, %o3, %o2
a01526b0:  03 02 00 00  sethi  %hi(0x8000000), %g1
a01526b4:  d8 03 60 04  ld  [ %o5 + 4 ], %o4
a01526b8:  a0 12 80 01  or  %o2, %g1, %l0
a01526bc:  1f 01 00 00  sethi  %hi(0x4000000), %o7
a01526c0:  13 3c 00 00  sethi  %hi(0xf0000000), %o1
a01526c4:  96 2b 00 09  andn  %o4, %o1, %o3
a01526c8:  94 2c 00 0f  andn  %l0, %o7, %o2
a01526cc:  03 00 10 00  sethi  %hi(0x400000), %g1
a01526d0:  d6 23 60 04  st  %o3, [ %o5 + 4 ]
a01526d4:  a0 2a 80 01  andn  %o2, %g1, %l0
a01526d8:  1f 10 00 00  sethi  %hi(0x40000000), %o7
a01526dc:  c0 2b 60 06  clrb  [ %o5 + 6 ]
a01526e0:  92 2c 00 0f  andn  %l0, %o7, %o1
a01526e4:  19 00 08 00  sethi  %hi(0x200000), %o4
a01526e8:  d4 03 60 04  ld  [ %o5 + 4 ], %o2
a01526ec:  96 12 40 0c  or  %o1, %o4, %o3
a01526f0:  03 00 02 00  sethi  %hi(0x80000), %g1
a01526f4:  21 00 3c 00  sethi  %hi(0xf00000), %l0
a01526f8:  9e 2a c0 01  andn  %o3, %g1, %o7
a01526fc:  98 2a 80 10  andn  %o2, %l0, %o4
a0152700:  13 03 c0 00  sethi  %hi(0xf000000), %o1
a0152704:  de 22 23 d0  st  %o7, [ %o0 + 0x3d0 ]
a0152708:  96 2b 00 09  andn  %o4, %o1, %o3
a015270c:  9e 10 3f 80  mov  -128, %o7
a0152710:  a0 10 20 32  mov  0x32, %l0
a0152714:  92 10 20 01  mov  1, %o1
a0152718:  82 10 20 64  mov  0x64, %g1
a015271c:  d6 23 60 04  st  %o3, [ %o5 + 4 ]
a0152720:  de 2b 60 17  stb  %o7, [ %o5 + 0x17 ]
a0152724:  d2 2b 60 2e  stb  %o1, [ %o5 + 0x2e ]
a0152728:  d2 2b 60 2f  stb  %o1, [ %o5 + 0x2f ]
a015272c:  de 2b 60 0a  stb  %o7, [ %o5 + 0xa ]
a0152730:  de 2b 60 12  stb  %o7, [ %o5 + 0x12 ]
a0152734:  de 2b 60 13  stb  %o7, [ %o5 + 0x13 ]
a0152738:  de 2b 60 14  stb  %o7, [ %o5 + 0x14 ]
a015273c:  de 2b 60 15  stb  %o7, [ %o5 + 0x15 ]
a0152740:  de 2b 60 16  stb  %o7, [ %o5 + 0x16 ]
a0152744:  c2 2b 60 08  stb  %g1, [ %o5 + 8 ]
a0152748:  e0 2b 60 0f  stb  %l0, [ %o5 + 0xf ]
a015274c:  e0 2b 60 09  stb  %l0, [ %o5 + 9 ]
a0152750:  e0 2b 60 0e  stb  %l0, [ %o5 + 0xe ]
a0152754:  e0 2b 60 11  stb  %l0, [ %o5 + 0x11 ]
a0152758:  e0 2b 60 0d  stb  %l0, [ %o5 + 0xd ]
a015275c:  e0 2b 60 10  stb  %l0, [ %o5 + 0x10 ]
a0152760:  e0 2b 60 0c  stb  %l0, [ %o5 + 0xc ]
a0152764:  c0 2b 60 0b  clrb  [ %o5 + 0xb ]
a0152768:  c0 2b 60 18  clrb  [ %o5 + 0x18 ]
a015276c:  c0 2b 60 1c  clrb  [ %o5 + 0x1c ]
a0152770:  c0 2b 60 1d  clrb  [ %o5 + 0x1d ]
a0152774:  c0 2b 60 03  clrb  [ %o5 + 3 ]
a0152778:  c0 2b 60 22  clrb  [ %o5 + 0x22 ]
a015277c:  c0 2b 60 23  clrb  [ %o5 + 0x23 ]
a0152780:  c0 2b 60 30  clrb  [ %o5 + 0x30 ]
a0152784:  c0 2b 60 31  clrb  [ %o5 + 0x31 ]
a0152788:  d8 02 23 d0  ld  [ %o0 + 0x3d0 ], %o4
a015278c:  15 00 01 00  sethi  %hi(0x40000), %o2
a0152790:  82 2b 00 0a  andn  %o4, %o2, %g1
a0152794:  c2 22 23 d0  st  %g1, [ %o0 + 0x3d0 ]
a0152798:  d2 2b 60 33  stb  %o1, [ %o5 + 0x33 ]
a015279c:  c0 33 60 36  clrh  [ %o5 + 0x36 ]
a01527a0:  c0 2b 60 32  clrb  [ %o5 + 0x32 ]
a01527a4:  7f fe bf b7  call  0xa0102680
a01527a8:  c0 2b 60 34  clrb  [ %o5 + 0x34 ]
a01527ac:  7f fe 30 06  call  0xa00de7c4
a01527b0:  21 2a 00 b3  sethi  %hi(0xa802cc00), %l0
a01527b4:  7f ff 98 cd  call  0xa0138ae8
a01527b8:  01 00 00 00  nop
a01527bc:  01 00 00 00  nop
a01527c0:  7f ff 83 69  call  0xa0133564
a01527c4:  01 00 00 00  nop
a01527c8:  92 0a 20 ff  and  %o0, 0xff, %o1
a01527cc:  80 a2 60 00  cmp  %o1, 0
a01527d0:  02 bf ff fb  be  0xa01527bc
a01527d4:  d0 2c 23 90  stb  %o0, [ %l0 + 0x390 ]
a01527d8:  11 00 06 9d  sethi  %hi(0x1a7400), %o0
a01527dc:  7f fe 32 65  call  0xa00df170
a01527e0:  90 12 21 58  or  %o0, 0x158, %o0	! 0x1a7558
a01527e4:  7f ff 47 19  call  0xa0124448
a01527e8:  d0 0c 23 90  ldub  [ %l0 + 0x390 ], %o0
a01527ec:  21 00 06 9d  sethi  %hi(0x1a7400), %l0
a01527f0:  7f ff 92 0b  call  0xa013701c
a01527f4:  01 00 00 00  nop
a01527f8:  80 8a 20 ff  btst  0xff, %o0
a01527fc:  12 80 00 0e  bne  0xa0152834
a0152800:  90 10 20 10  mov  0x10, %o0
a0152804:  7f fe 2b 84  call  0xa00dd614
a0152808:  01 00 00 00  nop
a015280c:  80 8a 20 ff  btst  0xff, %o0
a0152810:  02 bf ff f8  be  0xa01527f0
a0152814:  90 14 21 70  or  %l0, 0x170, %o0
a0152818:  7f fe 32 56  call  0xa00df170
a015281c:  01 00 00 00  nop
a0152820:  7f ff 91 ff  call  0xa013701c
a0152824:  01 00 00 00  nop
a0152828:  80 8a 20 ff  btst  0xff, %o0
a015282c:  02 bf ff f6  be  0xa0152804
a0152830:  90 10 20 10  mov  0x10, %o0
a0152834:  7f fe 2b 78  call  0xa00dd614
a0152838:  01 00 00 00  nop
a015283c:  80 8a 20 ff  btst  0xff, %o0
a0152840:  12 80 00 61  bne  0xa01529c4
a0152844:  1f 00 06 9d  sethi  %hi(0x1a7400), %o7
a0152848:  7f ff b6 26  call  0xa01400e0
a015284c:  21 2a 00 b3  sethi  %hi(0xa802cc00), %l0
a0152850:  7f ff be cc  call  0xa0142380
a0152854:  01 00 00 00  nop
a0152858:  40 00 05 07  call  0xa0153c74
a015285c:  01 00 00 00  nop
a0152860:  c2 04 20 3c  ld  [ %l0 + 0x3c ], %g1
a0152864:  80 a0 60 00  cmp  %g1, 0
a0152868:  12 80 00 54  bne  0xa01529b8
a015286c:  01 00 00 00  nop
a0152870:  7f ff bc bc  call  0xa0141b60
a0152874:  21 00 06 9d  sethi  %hi(0x1a7400), %l0
a0152878:  7f ff bf d7  call  0xa01427d4
a015287c:  01 00 00 00  nop
a0152880:  92 10 20 32  mov  0x32, %o1	! 0x32
a0152884:  7f ff 16 df  call  0xa0118400
a0152888:  90 10 20 1e  mov  0x1e, %o0
a015288c:  7f ff be c5  call  0xa01423a0
a0152890:  01 00 00 00  nop
a0152894:  7f fe fc 0b  call  0xa01118c0
a0152898:  90 0a 20 ff  and  %o0, 0xff, %o0
a015289c:  7f ff 01 45  call  0xa0112db0
a01528a0:  90 10 20 00  clr  %o0
a01528a4:  90 10 20 00  clr  %o0
a01528a8:  7f fe bf 90  call  0xa01026e8
a01528ac:  13 0e 4e 1c  sethi  %hi(0x39387000), %o1
a01528b0:  90 10 20 04  mov  4, %o0
a01528b4:  7f fe bf 8d  call  0xa01026e8
a01528b8:  13 0e 4e 1c  sethi  %hi(0x39387000), %o1
a01528bc:  7f ff 9f a5  call  0xa013a750
a01528c0:  01 00 00 00  nop
a01528c4:  90 10 20 00  clr  %o0	! 0x0
a01528c8:  7f ff c4 44  call  0xa01439d8
a01528cc:  92 10 20 01  mov  1, %o1
a01528d0:  7f ff 91 bd  call  0xa0136fc4
a01528d4:  01 00 00 00  nop
a01528d8:  80 8a 20 ff  btst  0xff, %o0
a01528dc:  12 80 00 0e  bne  0xa0152914
a01528e0:  90 10 20 10  mov  0x10, %o0
a01528e4:  7f fe 2b 4c  call  0xa00dd614
a01528e8:  01 00 00 00  nop
a01528ec:  80 8a 20 ff  btst  0xff, %o0
a01528f0:  02 bf ff f8  be  0xa01528d0
a01528f4:  90 14 21 98  or  %l0, 0x198, %o0
a01528f8:  7f fe 32 1e  call  0xa00df170
a01528fc:  01 00 00 00  nop
a0152900:  7f ff 91 b1  call  0xa0136fc4
a0152904:  01 00 00 00  nop
a0152908:  80 8a 20 ff  btst  0xff, %o0
a015290c:  02 bf ff f6  be  0xa01528e4
a0152910:  90 10 20 10  mov  0x10, %o0
a0152914:  7f fe 2b 40  call  0xa00dd614
a0152918:  01 00 00 00  nop
a015291c:  80 8a 20 ff  btst  0xff, %o0
a0152920:  12 80 00 2d  bne  0xa01529d4
a0152924:  15 00 06 9d  sethi  %hi(0x1a7400), %o2
a0152928:  7f ff 69 a1  call  0xa012cfac
a015292c:  01 00 00 00  nop
a0152930:  7f fe ab 0a  call  0xa00fd558
a0152934:  01 00 00 00  nop
a0152938:  7f ff bc 0b  call  0xa0141964
a015293c:  01 00 00 00  nop
a0152940:  7f ff fd d7  call  0xa015209c
a0152944:  01 00 00 00  nop
a0152948:  7f ff a7 ff  call  0xa013c944
a015294c:  01 00 00 00  nop
a0152950:  7f ff 74 ad  call  0xa012fc04
a0152954:  01 00 00 00  nop
a0152958:  7f ff 63 98  call  0xa012b7b8
a015295c:  01 00 00 00  nop
a0152960:  7f ff 46 27  call  0xa01241fc
a0152964:  01 00 00 00  nop
a0152968:  d2 02 00 00  ld  [ %o0 ], %o1
a015296c:  1b 00 1c 00  sethi  %hi(0x700000), %o5
a0152970:  82 0a 40 0d  and  %o1, %o5, %g1
a0152974:  17 00 08 00  sethi  %hi(0x200000), %o3
a0152978:  80 a0 40 0b  cmp  %g1, %o3
a015297c:  02 80 00 19  be  0xa01529e0
a0152980:  01 00 00 00  nop
a0152984:  7f ff 96 40  call  0xa0138284
a0152988:  01 00 00 00  nop
a015298c:  7f ff 96 56  call  0xa01382e4
a0152990:  01 00 00 00  nop
a0152994:  90 10 20 02  mov  2, %o0	! 0x2
a0152998:  7f ff 8b 59  call  0xa01356fc
a015299c:  92 10 20 00  clr  %o1
a01529a0:  7f ff 46 8f  call  0xa01243dc
a01529a4:  01 00 00 00  nop
a01529a8:  7f ff 65 f8  call  0xa012c188
a01529ac:  01 00 00 00  nop
a01529b0:  7f ff 5b ca  call  0xa01298d8
a01529b4:  81 e8 00 00  restore
a01529b8:  9f c0 40 00  call  %g1
a01529bc:  01 00 00 00  nop
a01529c0:  30 bf ff ac  b,a   0xa0152870
a01529c4:  90 13 e1 88  or  %o7, 0x188, %o0
a01529c8:  7f fe 31 ea  call  0xa00df170
a01529cc:  01 00 00 00  nop
a01529d0:  30 bf ff 9e  b,a   0xa0152848
a01529d4:  7f fe 31 e7  call  0xa00df170
a01529d8:  90 12 a1 b0  or  %o2, 0x1b0, %o0
a01529dc:  30 bf ff d3  b,a   0xa0152928
a01529e0:  7f ff 63 f0  call  0xa012b9a0
a01529e4:  01 00 00 00  nop
a01529e8:  7f ff 96 27  call  0xa0138284
a01529ec:  01 00 00 00  nop
a01529f0:  7f ff 96 3d  call  0xa01382e4
a01529f4:  01 00 00 00  nop
a01529f8:  90 10 20 02  mov  2, %o0	! 0x2
a01529fc:  7f ff 8b 40  call  0xa01356fc
a0152a00:  92 10 20 00  clr  %o1
a0152a04:  7f ff 46 76  call  0xa01243dc
a0152a08:  01 00 00 00  nop
a0152a0c:  7f ff 65 df  call  0xa012c188
a0152a10:  01 00 00 00  nop
a0152a14:  7f ff 5b b1  call  0xa01298d8
a0152a18:  81 e8 00 00  restore
a0152a1c:  01 00 00 00  nop
