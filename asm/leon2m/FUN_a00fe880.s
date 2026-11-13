# leon2m FUN_a00fe880 0xa00fe880-0xa010031c (44 bytes)
a00fe880:  82 0a 20 ff  and  %o0, 0xff, %g1
a00fe884:  80 a0 60 11  cmp  %g1, 0x11
a00fe888:  18 80 06 a3  bgu  0xa0100314
a00fe88c:  11 00 02 75  sethi  %hi(0x9d400), %o0
a00fe890:  83 28 60 02  sll  %g1, 2, %g1
a00fe894:  9a 12 21 10  or  %o0, 0x110, %o5
a00fe898:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a00fe89c:  81 c3 00 00  jmp  %o4
a00fe8a0:  01 00 00 00  nop
a00fe8a4:  82 0a 60 ff  and  %o1, 0xff, %g1
a00fe8a8:  80 a0 60 01  cmp  %g1, 1
a00fe8ac:  02 80 01 23  be  0xa00fed38
a00fe8b0:  80 a0 60 02  cmp  %g1, 2
a00fe8b4:  02 80 01 ab  be  0xa00fef60
a00fe8b8:  80 a0 60 04  cmp  %g1, 4
a00fe8bc:  02 80 01 ff  be  0xa00ff0b8
a00fe8c0:  80 a0 60 08  cmp  %g1, 8
a00fe8c4:  02 80 02 73  be  0xa00ff290
a00fe8c8:  80 a0 60 10  cmp  %g1, 0x10
a00fe8cc:  02 80 03 0b  be  0xa00ff4f8
a00fe8d0:  80 a0 60 20  cmp  %g1, 0x20
a00fe8d4:  02 80 03 d8  be  0xa00ff834
a00fe8d8:  80 a0 60 40  cmp  %g1, 0x40
a00fe8dc:  02 80 04 a0  be  0xa00ffb5c
a00fe8e0:  80 a0 60 80  cmp  %g1, 0x80
a00fe8e4:  12 80 06 8c  bne  0xa0100314
a00fe8e8:  80 a2 a0 05  cmp  %o2, 5
a00fe8ec:  02 80 06 2c  be  0xa010019c
a00fe8f0:  80 a2 a0 0f  cmp  %o2, 0xf
a00fe8f4:  02 80 06 7c  be  0xa01002e4
a00fe8f8:  80 a2 a0 06  cmp  %o2, 6
a00fe8fc:  02 80 06 81  be  0xa0100300
a00fe900:  19 33 c0 45  sethi  %hi(0xcf011400), %o4
a00fe904:  90 13 22 b0  or  %o4, 0x2b0, %o0	! 0xcf0116b0
a00fe908:  d2 02 00 00  ld  [ %o0 ], %o1
a00fe90c:  82 0a 7f fc  and  %o1, -4, %g1
a00fe910:  c2 22 00 00  st  %g1, [ %o0 ]
a00fe914:  30 80 06 80  b,a   0xa0100314
a00fe918:  82 0a 60 ff  and  %o1, 0xff, %g1
a00fe91c:  80 a0 60 01  cmp  %g1, 1
a00fe920:  02 80 01 66  be  0xa00feeb8
a00fe924:  80 a0 60 02  cmp  %g1, 2
a00fe928:  02 80 01 86  be  0xa00fef40
a00fe92c:  80 a0 60 04  cmp  %g1, 4
a00fe930:  02 80 02 1a  be  0xa00ff198
a00fe934:  80 a0 60 08  cmp  %g1, 8
a00fe938:  02 80 02 4e  be  0xa00ff270
a00fe93c:  80 a0 60 10  cmp  %g1, 0x10
a00fe940:  12 80 06 75  bne  0xa0100314
a00fe944:  80 a2 a0 0b  cmp  %o2, 0xb
a00fe948:  02 80 05 56  be  0xa00ffea0
a00fe94c:  19 33 c0 45  sethi  %hi(0xcf011400), %o4
a00fe950:  9a 13 21 3c  or  %o4, 0x13c, %o5	! 0xcf01153c
a00fe954:  d2 03 40 00  ld  [ %o5 ], %o1
a00fe958:  82 0a 7f 3f  and  %o1, -193, %g1
a00fe95c:  c2 23 40 00  st  %g1, [ %o5 ]
a00fe960:  30 80 06 6d  b,a   0xa0100314
a00fe964:  82 0a 60 ff  and  %o1, 0xff, %g1
a00fe968:  80 a0 60 04  cmp  %g1, 4
a00fe96c:  02 80 01 35  be  0xa00fee40
a00fe970:  80 a0 60 08  cmp  %g1, 8
a00fe974:  02 80 01 c7  be  0xa00ff090
a00fe978:  80 a0 60 10  cmp  %g1, 0x10
a00fe97c:  02 80 02 19  be  0xa00ff1e0
a00fe980:  80 a0 60 20  cmp  %g1, 0x20
a00fe984:  02 80 02 27  be  0xa00ff220
a00fe988:  80 a0 60 40  cmp  %g1, 0x40
a00fe98c:  02 80 03 1b  be  0xa00ff5f8
a00fe990:  80 a0 60 80  cmp  %g1, 0x80
a00fe994:  12 80 06 60  bne  0xa0100314
a00fe998:  80 a2 a0 05  cmp  %o2, 5
a00fe99c:  02 80 05 9b  be  0xa0100008
a00fe9a0:  15 33 c0 45  sethi  %hi(0xcf011400), %o2
a00fe9a4:  9a 12 a1 30  or  %o2, 0x130, %o5	! 0xcf011530
a00fe9a8:  d8 03 40 00  ld  [ %o5 ], %o4
a00fe9ac:  92 0b 3f fc  and  %o4, -4, %o1
a00fe9b0:  d2 23 40 00  st  %o1, [ %o5 ]
a00fe9b4:  30 80 06 58  b,a   0xa0100314
a00fe9b8:  82 0a 60 ff  and  %o1, 0xff, %g1
a00fe9bc:  80 a0 60 01  cmp  %g1, 1
a00fe9c0:  02 80 01 2a  be  0xa00fee68
a00fe9c4:  80 a0 60 02  cmp  %g1, 2
a00fe9c8:  02 80 01 7a  be  0xa00fefb0
a00fe9cc:  80 a0 60 04  cmp  %g1, 4
a00fe9d0:  02 80 01 ca  be  0xa00ff0f8
a00fe9d4:  80 a0 60 08  cmp  %g1, 8
a00fe9d8:  02 80 02 52  be  0xa00ff320
a00fe9dc:  80 a0 60 10  cmp  %g1, 0x10
a00fe9e0:  02 80 02 ea  be  0xa00ff588
a00fe9e4:  80 a0 60 20  cmp  %g1, 0x20
a00fe9e8:  02 80 03 b7  be  0xa00ff8c4
a00fe9ec:  80 a0 60 40  cmp  %g1, 0x40
a00fe9f0:  02 80 04 79  be  0xa00ffbd4
a00fe9f4:  80 a0 60 80  cmp  %g1, 0x80
a00fe9f8:  12 80 06 47  bne  0xa0100314
a00fe9fc:  80 a2 a0 06  cmp  %o2, 6
a00fea00:  02 80 05 f5  be  0xa01001d4
a00fea04:  15 33 c0 45  sethi  %hi(0xcf011400), %o2
a00fea08:  90 12 a1 28  or  %o2, 0x128, %o0	! 0xcf011528
a00fea0c:  d8 02 00 00  ld  [ %o0 ], %o4
a00fea10:  92 0b 3f fc  and  %o4, -4, %o1
a00fea14:  d2 22 00 00  st  %o1, [ %o0 ]
a00fea18:  30 80 06 3f  b,a   0xa0100314
a00fea1c:  82 0a 60 ff  and  %o1, 0xff, %g1
a00fea20:  80 a0 60 01  cmp  %g1, 1
a00fea24:  02 80 00 e9  be  0xa00fedc8
a00fea28:  80 a0 60 02  cmp  %g1, 2
a00fea2c:  02 80 01 7f  be  0xa00ff028
a00fea30:  80 a0 60 04  cmp  %g1, 4
a00fea34:  02 80 01 a9  be  0xa00ff0d8
a00fea38:  80 a0 60 08  cmp  %g1, 8
a00fea3c:  02 80 02 1d  be  0xa00ff2b0
a00fea40:  80 a0 60 10  cmp  %g1, 0x10
a00fea44:  02 80 02 e3  be  0xa00ff5d0
a00fea48:  80 a0 60 20  cmp  %g1, 0x20
a00fea4c:  02 80 03 82  be  0xa00ff854
a00fea50:  80 a0 60 40  cmp  %g1, 0x40
a00fea54:  02 80 04 38  be  0xa00ffb34
a00fea58:  80 a0 60 80  cmp  %g1, 0x80
a00fea5c:  12 80 06 2e  bne  0xa0100314
a00fea60:  80 a2 a0 0b  cmp  %o2, 0xb
a00fea64:  02 80 05 c7  be  0xa0100180
a00fea68:  80 a2 a0 08  cmp  %o2, 8
a00fea6c:  02 80 06 0c  be  0xa010029c
a00fea70:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00fea74:  94 13 61 54  or  %o5, 0x154, %o2	! 0xcf011554
a00fea78:  d0 02 80 00  ld  [ %o2 ], %o0
a00fea7c:  82 0a 3f fc  and  %o0, -4, %g1
a00fea80:  c2 22 80 00  st  %g1, [ %o2 ]
a00fea84:  30 80 06 24  b,a   0xa0100314
a00fea88:  82 0a 60 ff  and  %o1, 0xff, %g1
a00fea8c:  80 a0 60 01  cmp  %g1, 1
a00fea90:  02 80 00 c2  be  0xa00fed98
a00fea94:  80 a0 60 02  cmp  %g1, 2
a00fea98:  02 80 01 58  be  0xa00feff8
a00fea9c:  80 a0 60 04  cmp  %g1, 4
a00feaa0:  02 80 01 b4  be  0xa00ff170
a00feaa4:  80 a0 60 08  cmp  %g1, 8
a00feaa8:  02 80 02 14  be  0xa00ff2f8
a00feaac:  80 a0 60 10  cmp  %g1, 0x10
a00feab0:  02 80 02 be  be  0xa00ff5a8
a00feab4:  80 a0 60 20  cmp  %g1, 0x20
a00feab8:  02 80 03 79  be  0xa00ff89c
a00feabc:  80 a0 60 40  cmp  %g1, 0x40
a00feac0:  02 80 04 33  be  0xa00ffb8c
a00feac4:  80 a0 60 80  cmp  %g1, 0x80
a00feac8:  12 80 06 13  bne  0xa0100314
a00feacc:  80 a2 a0 0a  cmp  %o2, 0xa
a00fead0:  02 80 05 ba  be  0xa01001b8
a00fead4:  80 a2 a0 08  cmp  %o2, 8
a00fead8:  02 80 05 eb  be  0xa0100284
a00feadc:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00feae0:  98 13 60 e8  or  %o5, 0xe8, %o4	! 0xcf0114e8
a00feae4:  d0 03 00 00  ld  [ %o4 ], %o0
a00feae8:  94 0a 3f fc  and  %o0, -4, %o2
a00feaec:  d4 23 00 00  st  %o2, [ %o4 ]
a00feaf0:  30 80 06 09  b,a   0xa0100314
a00feaf4:  82 0a 60 ff  and  %o1, 0xff, %g1
a00feaf8:  80 a0 60 01  cmp  %g1, 1
a00feafc:  02 80 00 e5  be  0xa00fee90
a00feb00:  80 a0 60 02  cmp  %g1, 2
a00feb04:  02 80 01 05  be  0xa00fef18
a00feb08:  80 a0 60 04  cmp  %g1, 4
a00feb0c:  02 80 01 ab  be  0xa00ff1b8
a00feb10:  80 a0 60 08  cmp  %g1, 8
a00feb14:  02 80 02 0d  be  0xa00ff348
a00feb18:  80 a0 60 10  cmp  %g1, 0x10
a00feb1c:  02 80 02 87  be  0xa00ff538
a00feb20:  80 a0 60 20  cmp  %g1, 0x20
a00feb24:  12 80 05 fc  bne  0xa0100314
a00feb28:  80 a2 a0 06  cmp  %o2, 6
a00feb2c:  02 80 05 25  be  0xa00fffc0
a00feb30:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00feb34:  94 13 61 20  or  %o5, 0x120, %o2	! 0xcf011520
a00feb38:  c2 02 80 00  ld  [ %o2 ], %g1
a00feb3c:  90 08 7f cf  and  %g1, -49, %o0
a00feb40:  d0 22 80 00  st  %o0, [ %o2 ]
a00feb44:  30 80 05 f4  b,a   0xa0100314
a00feb48:  82 0a 60 ff  and  %o1, 0xff, %g1
a00feb4c:  80 a0 60 02  cmp  %g1, 2
a00feb50:  02 80 00 b4  be  0xa00fee20
a00feb54:  80 a0 60 04  cmp  %g1, 4
a00feb58:  02 80 01 46  be  0xa00ff070
a00feb5c:  80 a0 60 08  cmp  %g1, 8
a00feb60:  12 80 05 ed  bne  0xa0100314
a00feb64:  80 a2 a0 05  cmp  %o2, 5
a00feb68:  02 80 03 6b  be  0xa00ff914
a00feb6c:  11 33 c0 45  sethi  %hi(0xcf011400), %o0
a00feb70:  98 12 20 d4  or  %o0, 0xd4, %o4	! 0xcf0114d4
a00feb74:  d4 03 00 00  ld  [ %o4 ], %o2
a00feb78:  82 0a bf fc  and  %o2, -4, %g1
a00feb7c:  c2 23 00 00  st  %g1, [ %o4 ]
a00feb80:  30 80 05 e5  b,a   0xa0100314
a00feb84:  98 0a 60 ff  and  %o1, 0xff, %o4
a00feb88:  80 a3 20 80  cmp  %o4, 0x80
a00feb8c:  12 80 05 e2  bne  0xa0100314
a00feb90:  80 a2 a0 02  cmp  %o2, 2
a00feb94:  02 80 02 1a  be  0xa00ff3fc
a00feb98:  80 a2 a0 03  cmp  %o2, 3
a00feb9c:  02 80 02 f1  be  0xa00ff760
a00feba0:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00feba4:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a00feba8:  98 10 60 d0  or  %g1, 0xd0, %o4	! 0xcf0114d0
a00febac:  d0 03 00 00  ld  [ %o4 ], %o0
a00febb0:  94 0a 3f fc  and  %o0, -4, %o2
a00febb4:  d4 23 00 00  st  %o2, [ %o4 ]
a00febb8:  30 80 05 d7  b,a   0xa0100314
a00febbc:  82 0a 60 ff  and  %o1, 0xff, %g1
a00febc0:  80 a0 60 01  cmp  %g1, 1
a00febc4:  02 80 00 6d  be  0xa00fed78
a00febc8:  80 a0 60 02  cmp  %g1, 2
a00febcc:  02 80 01 03  be  0xa00fefd8
a00febd0:  80 a0 60 04  cmp  %g1, 4
a00febd4:  02 80 01 5f  be  0xa00ff150
a00febd8:  80 a0 60 08  cmp  %g1, 8
a00febdc:  02 80 01 bf  be  0xa00ff2d8
a00febe0:  80 a0 60 10  cmp  %g1, 0x10
a00febe4:  02 80 02 4d  be  0xa00ff518
a00febe8:  80 a0 60 20  cmp  %g1, 0x20
a00febec:  02 80 03 24  be  0xa00ff87c
a00febf0:  80 a0 60 40  cmp  %g1, 0x40
a00febf4:  02 80 03 f0  be  0xa00ffbb4
a00febf8:  80 a0 60 80  cmp  %g1, 0x80
a00febfc:  12 80 05 c6  bne  0xa0100314
a00fec00:  80 a2 a0 06  cmp  %o2, 6
a00fec04:  02 80 05 99  be  0xa0100268
a00fec08:  13 33 c0 45  sethi  %hi(0xcf011400), %o1
a00fec0c:  94 12 60 e0  or  %o1, 0xe0, %o2	! 0xcf0114e0
a00fec10:  d0 02 80 00  ld  [ %o2 ], %o0
a00fec14:  82 0a 3f fc  and  %o0, -4, %g1
a00fec18:  c2 22 80 00  st  %g1, [ %o2 ]
a00fec1c:  30 80 05 be  b,a   0xa0100314
a00fec20:  82 0a 60 ff  and  %o1, 0xff, %g1
a00fec24:  80 a0 60 01  cmp  %g1, 1
a00fec28:  02 80 00 ac  be  0xa00feed8
a00fec2c:  80 a0 60 02  cmp  %g1, 2
a00fec30:  12 80 05 b9  bne  0xa0100314
a00fec34:  80 a2 a0 09  cmp  %o2, 9
a00fec38:  02 80 02 f8  be  0xa00ff818
a00fec3c:  13 33 c0 45  sethi  %hi(0xcf011400), %o1
a00fec40:  94 12 60 d8  or  %o1, 0xd8, %o2	! 0xcf0114d8
a00fec44:  d0 02 80 00  ld  [ %o2 ], %o0
a00fec48:  82 0a 3f cf  and  %o0, -49, %g1
a00fec4c:  c2 22 80 00  st  %g1, [ %o2 ]
a00fec50:  30 80 05 b1  b,a   0xa0100314
a00fec54:  82 0a 60 ff  and  %o1, 0xff, %g1
a00fec58:  80 a0 60 01  cmp  %g1, 1
a00fec5c:  02 80 00 65  be  0xa00fedf0
a00fec60:  80 a0 60 02  cmp  %g1, 2
a00fec64:  02 80 00 c7  be  0xa00fef80
a00fec68:  80 a0 60 04  cmp  %g1, 4
a00fec6c:  02 80 01 2d  be  0xa00ff120
a00fec70:  80 a0 60 08  cmp  %g1, 8
a00fec74:  02 80 01 73  be  0xa00ff240
a00fec78:  80 a0 60 10  cmp  %g1, 0x10
a00fec7c:  02 80 02 37  be  0xa00ff558
a00fec80:  80 a0 60 20  cmp  %g1, 0x20
a00fec84:  02 80 03 18  be  0xa00ff8e4
a00fec88:  80 a0 60 40  cmp  %g1, 0x40
a00fec8c:  02 80 03 a0  be  0xa00ffb0c
a00fec90:  80 a0 60 80  cmp  %g1, 0x80
a00fec94:  12 80 05 a0  bne  0xa0100314
a00fec98:  80 a2 a0 0c  cmp  %o2, 0xc
a00fec9c:  02 80 05 5a  be  0xa0100204
a00feca0:  80 a2 a0 06  cmp  %o2, 6
a00feca4:  02 80 05 8a  be  0xa01002cc
a00feca8:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00fecac:  90 13 61 18  or  %o5, 0x118, %o0	! 0xcf011518
a00fecb0:  d2 02 00 00  ld  [ %o0 ], %o1
a00fecb4:  82 0a 7f fc  and  %o1, -4, %g1
a00fecb8:  c2 22 00 00  st  %g1, [ %o0 ]
a00fecbc:  30 80 05 96  b,a   0xa0100314
a00fecc0:  82 0a 60 ff  and  %o1, 0xff, %g1
a00fecc4:  80 a0 60 01  cmp  %g1, 1
a00fecc8:  02 80 00 8c  be  0xa00feef8
a00feccc:  80 a0 60 02  cmp  %g1, 2
a00fecd0:  02 80 00 e0  be  0xa00ff050
a00fecd4:  80 a0 60 04  cmp  %g1, 4
a00fecd8:  02 80 01 4a  be  0xa00ff200
a00fecdc:  80 a0 60 08  cmp  %g1, 8
a00fece0:  12 80 05 8d  bne  0xa0100314
a00fece4:  80 a2 a0 01  cmp  %o2, 1
a00fece8:  02 80 04 20  be  0xa00ffd68
a00fecec:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00fecf0:  90 13 60 cc  or  %o5, 0xcc, %o0	! 0xcf0114cc
a00fecf4:  d2 02 00 00  ld  [ %o0 ], %o1
a00fecf8:  82 0a 7f fc  and  %o1, -4, %g1
a00fecfc:  c2 22 00 00  st  %g1, [ %o0 ]
a00fed00:  30 80 05 85  b,a   0xa0100314
a00fed04:  82 0a 60 ff  and  %o1, 0xff, %g1
a00fed08:  80 a0 60 04  cmp  %g1, 4
a00fed0c:  02 80 00 13  be  0xa00fed58
a00fed10:  80 a0 60 08  cmp  %g1, 8
a00fed14:  12 80 05 80  bne  0xa0100314
a00fed18:  80 a2 a0 10  cmp  %o2, 0x10
a00fed1c:  02 80 02 46  be  0xa00ff634
a00fed20:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00fed24:  98 13 61 40  or  %o5, 0x140, %o4	! 0xcf011540
a00fed28:  d0 03 00 00  ld  [ %o4 ], %o0
a00fed2c:  82 0a 3f cf  and  %o0, -49, %g1
a00fed30:  c2 23 00 00  st  %g1, [ %o4 ]
a00fed34:  30 80 05 78  b,a   0xa0100314
a00fed38:  80 a2 a0 12  cmp  %o2, 0x12
a00fed3c:  02 80 01 94  be  0xa00ff38c
a00fed40:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a00fed44:  98 10 62 ac  or  %g1, 0x2ac, %o4	! 0xcf0116ac
a00fed48:  d0 03 00 00  ld  [ %o4 ], %o0
a00fed4c:  94 0a 3f 3f  and  %o0, -193, %o2
a00fed50:  d4 23 00 00  st  %o2, [ %o4 ]
a00fed54:  30 80 05 70  b,a   0xa0100314
a00fed58:  80 a2 a0 10  cmp  %o2, 0x10
a00fed5c:  02 80 01 9a  be  0xa00ff3c4
a00fed60:  19 33 c0 45  sethi  %hi(0xcf011400), %o4
a00fed64:  90 13 21 40  or  %o4, 0x140, %o0	! 0xcf011540
a00fed68:  d4 02 00 00  ld  [ %o0 ], %o2
a00fed6c:  92 0a bf 3f  and  %o2, -193, %o1
a00fed70:  d2 22 00 00  st  %o1, [ %o0 ]
a00fed74:  30 80 05 68  b,a   0xa0100314
a00fed78:  80 a2 a0 06  cmp  %o2, 6
a00fed7c:  02 80 01 ca  be  0xa00ff4a4
a00fed80:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a00fed84:  92 10 60 dc  or  %g1, 0xdc, %o1	! 0xcf0114dc
a00fed88:  d4 02 40 00  ld  [ %o1 ], %o2
a00fed8c:  98 0a bf 3f  and  %o2, -193, %o4
a00fed90:  d8 22 40 00  st  %o4, [ %o1 ]
a00fed94:  30 80 05 60  b,a   0xa0100314
a00fed98:  80 a2 a0 0a  cmp  %o2, 0xa
a00fed9c:  02 80 01 91  be  0xa00ff3e0
a00feda0:  80 a2 a0 07  cmp  %o2, 7
a00feda4:  02 80 02 68  be  0xa00ff744
a00feda8:  80 a2 a0 08  cmp  %o2, 8
a00fedac:  02 80 03 23  be  0xa00ffa38
a00fedb0:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00fedb4:  90 13 60 e4  or  %o5, 0xe4, %o0	! 0xcf0114e4
a00fedb8:  d2 02 00 00  ld  [ %o0 ], %o1
a00fedbc:  82 0a 7f 3f  and  %o1, -193, %g1
a00fedc0:  c2 22 00 00  st  %g1, [ %o0 ]
a00fedc4:  30 80 05 54  b,a   0xa0100314
a00fedc8:  80 a2 a0 05  cmp  %o2, 5
a00fedcc:  02 80 01 bd  be  0xa00ff4c0
a00fedd0:  80 a2 a0 08  cmp  %o2, 8
a00fedd4:  02 80 02 69  be  0xa00ff778
a00fedd8:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00feddc:  94 13 61 50  or  %o5, 0x150, %o2	! 0xcf011550
a00fede0:  d2 02 80 00  ld  [ %o2 ], %o1
a00fede4:  90 0a 7f 3f  and  %o1, -193, %o0
a00fede8:  d0 22 80 00  st  %o0, [ %o2 ]
a00fedec:  30 80 05 4a  b,a   0xa0100314
a00fedf0:  80 a2 a0 0a  cmp  %o2, 0xa
a00fedf4:  02 80 01 8a  be  0xa00ff41c
a00fedf8:  80 a2 a0 05  cmp  %o2, 5
a00fedfc:  02 80 02 37  be  0xa00ff6d8
a00fee00:  80 a2 a0 06  cmp  %o2, 6
a00fee04:  02 80 03 00  be  0xa00ffa04
a00fee08:  13 33 c0 45  sethi  %hi(0xcf011400), %o1
a00fee0c:  94 12 61 4c  or  %o1, 0x14c, %o2	! 0xcf01154c
a00fee10:  d0 02 80 00  ld  [ %o2 ], %o0
a00fee14:  82 0a 3f 3f  and  %o0, -193, %g1
a00fee18:  c2 22 80 00  st  %g1, [ %o2 ]
a00fee1c:  30 80 05 3e  b,a   0xa0100314
a00fee20:  80 a2 a0 04  cmp  %o2, 4
a00fee24:  02 80 01 99  be  0xa00ff488
a00fee28:  15 33 c0 45  sethi  %hi(0xcf011400), %o2
a00fee2c:  92 12 a0 d4  or  %o2, 0xd4, %o1	! 0xcf0114d4
a00fee30:  d8 02 40 00  ld  [ %o1 ], %o4
a00fee34:  82 0b 3f cf  and  %o4, -49, %g1
a00fee38:  c2 22 40 00  st  %g1, [ %o1 ]
a00fee3c:  30 80 05 36  b,a   0xa0100314
a00fee40:  80 a2 a0 05  cmp  %o2, 5
a00fee44:  02 80 01 84  be  0xa00ff454
a00fee48:  80 a2 a0 0f  cmp  %o2, 0xf
a00fee4c:  02 80 02 6c  be  0xa00ff7fc
a00fee50:  11 33 c0 45  sethi  %hi(0xcf011400), %o0
a00fee54:  98 12 21 2c  or  %o0, 0x12c, %o4	! 0xcf01152c
a00fee58:  c2 03 00 00  ld  [ %o4 ], %g1
a00fee5c:  94 08 7f f3  and  %g1, -13, %o2
a00fee60:  d4 23 00 00  st  %o2, [ %o4 ]
a00fee64:  30 80 05 2c  b,a   0xa0100314
a00fee68:  80 a2 a0 0e  cmp  %o2, 0xe
a00fee6c:  02 80 01 9c  be  0xa00ff4dc
a00fee70:  80 a2 a0 06  cmp  %o2, 6
a00fee74:  02 80 02 47  be  0xa00ff790
a00fee78:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00fee7c:  90 13 61 24  or  %o5, 0x124, %o0	! 0xcf011524
a00fee80:  d2 02 00 00  ld  [ %o0 ], %o1
a00fee84:  82 0a 7f 3f  and  %o1, -193, %g1
a00fee88:  c2 22 00 00  st  %g1, [ %o0 ]
a00fee8c:  30 80 05 22  b,a   0xa0100314
a00fee90:  80 a2 a0 0b  cmp  %o2, 0xb
a00fee94:  02 80 01 69  be  0xa00ff438
a00fee98:  80 a2 a0 06  cmp  %o2, 6
a00fee9c:  02 80 02 16  be  0xa00ff6f4
a00feea0:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00feea4:  92 13 61 1c  or  %o5, 0x11c, %o1	! 0xcf01151c
a00feea8:  d8 02 40 00  ld  [ %o1 ], %o4
a00feeac:  82 0b 3f 3f  and  %o4, -193, %g1
a00feeb0:  c2 22 40 00  st  %g1, [ %o1 ]
a00feeb4:  30 80 05 18  b,a   0xa0100314
a00feeb8:  80 a2 a0 0b  cmp  %o2, 0xb
a00feebc:  02 80 01 6d  be  0xa00ff470
a00feec0:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a00feec4:  98 10 61 38  or  %g1, 0x138, %o4	! 0xcf011538
a00feec8:  d0 03 00 00  ld  [ %o4 ], %o0
a00feecc:  94 0a 3f 3f  and  %o0, -193, %o2
a00feed0:  d4 23 00 00  st  %o2, [ %o4 ]
a00feed4:  30 80 05 10  b,a   0xa0100314
a00feed8:  80 a2 a0 09  cmp  %o2, 9
a00feedc:  02 80 01 25  be  0xa00ff370
a00feee0:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a00feee4:  90 10 60 d8  or  %g1, 0xd8, %o0	! 0xcf0114d8
a00feee8:  d8 02 00 00  ld  [ %o0 ], %o4
a00feeec:  92 0b 3f 3f  and  %o4, -193, %o1
a00feef0:  d2 22 00 00  st  %o1, [ %o0 ]
a00feef4:  30 80 05 08  b,a   0xa0100314
a00feef8:  80 a2 a0 01  cmp  %o2, 1
a00feefc:  02 80 01 2b  be  0xa00ff3a8
a00fef00:  19 33 c0 45  sethi  %hi(0xcf011400), %o4
a00fef04:  9a 13 20 cc  or  %o4, 0xcc, %o5	! 0xcf0114cc
a00fef08:  d4 03 40 00  ld  [ %o5 ], %o2
a00fef0c:  92 0a bf 3f  and  %o2, -193, %o1
a00fef10:  d2 23 40 00  st  %o1, [ %o5 ]
a00fef14:  30 80 05 00  b,a   0xa0100314
a00fef18:  80 a2 a0 0b  cmp  %o2, 0xb
a00fef1c:  02 80 01 bf  be  0xa00ff618
a00fef20:  80 a2 a0 06  cmp  %o2, 6
a00fef24:  02 80 02 96  be  0xa00ff97c
a00fef28:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00fef2c:  98 13 61 1c  or  %o5, 0x11c, %o4	! 0xcf01151c
a00fef30:  d4 03 00 00  ld  [ %o4 ], %o2
a00fef34:  82 0a bf cf  and  %o2, -49, %g1
a00fef38:  c2 23 00 00  st  %g1, [ %o4 ]
a00fef3c:  30 80 04 f6  b,a   0xa0100314
a00fef40:  80 a2 a0 0b  cmp  %o2, 0xb
a00fef44:  02 80 01 d8  be  0xa00ff6a4
a00fef48:  19 33 c0 45  sethi  %hi(0xcf011400), %o4
a00fef4c:  90 13 21 38  or  %o4, 0x138, %o0	! 0xcf011538
a00fef50:  d2 02 00 00  ld  [ %o0 ], %o1
a00fef54:  82 0a 7f cf  and  %o1, -49, %g1
a00fef58:  c2 22 00 00  st  %g1, [ %o0 ]
a00fef5c:  30 80 04 ee  b,a   0xa0100314
a00fef60:  80 a2 a0 12  cmp  %o2, 0x12
a00fef64:  02 80 01 c2  be  0xa00ff66c
a00fef68:  15 33 c0 45  sethi  %hi(0xcf011400), %o2
a00fef6c:  92 12 a2 ac  or  %o2, 0x2ac, %o1	! 0xcf0116ac
a00fef70:  d8 02 40 00  ld  [ %o1 ], %o4
a00fef74:  82 0b 3f cf  and  %o4, -49, %g1
a00fef78:  c2 22 40 00  st  %g1, [ %o1 ]
a00fef7c:  30 80 04 e6  b,a   0xa0100314
a00fef80:  80 a2 a0 0a  cmp  %o2, 0xa
a00fef84:  02 80 01 c1  be  0xa00ff688
a00fef88:  80 a2 a0 05  cmp  %o2, 5
a00fef8c:  02 80 02 89  be  0xa00ff9b0
a00fef90:  80 a2 a0 06  cmp  %o2, 6
a00fef94:  02 80 03 1e  be  0xa00ffc0c
a00fef98:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00fef9c:  90 13 61 4c  or  %o5, 0x14c, %o0	! 0xcf01154c
a00fefa0:  d2 02 00 00  ld  [ %o0 ], %o1
a00fefa4:  82 0a 7f cf  and  %o1, -49, %g1
a00fefa8:  c2 22 00 00  st  %g1, [ %o0 ]
a00fefac:  30 80 04 da  b,a   0xa0100314
a00fefb0:  80 a2 a0 0e  cmp  %o2, 0xe
a00fefb4:  02 80 01 dd  be  0xa00ff728
a00fefb8:  80 a2 a0 06  cmp  %o2, 6
a00fefbc:  02 80 02 b3  be  0xa00ffa88
a00fefc0:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00fefc4:  92 13 61 24  or  %o5, 0x124, %o1	! 0xcf011524
a00fefc8:  d8 02 40 00  ld  [ %o1 ], %o4
a00fefcc:  82 0b 3f cf  and  %o4, -49, %g1
a00fefd0:  c2 22 40 00  st  %g1, [ %o1 ]
a00fefd4:  30 80 04 d0  b,a   0xa0100314
a00fefd8:  80 a2 a0 06  cmp  %o2, 6
a00fefdc:  02 80 02 01  be  0xa00ff7e0
a00fefe0:  19 33 c0 45  sethi  %hi(0xcf011400), %o4
a00fefe4:  90 13 20 dc  or  %o4, 0xdc, %o0	! 0xcf0114dc
a00fefe8:  d2 02 00 00  ld  [ %o0 ], %o1
a00fefec:  82 0a 7f cf  and  %o1, -49, %g1
a00feff0:  c2 22 00 00  st  %g1, [ %o0 ]
a00feff4:  30 80 04 c8  b,a   0xa0100314
a00feff8:  80 a2 a0 0a  cmp  %o2, 0xa
a00feffc:  02 80 01 c4  be  0xa00ff70c
a00ff000:  80 a2 a0 07  cmp  %o2, 7
a00ff004:  02 80 02 86  be  0xa00ffa1c
a00ff008:  80 a2 a0 08  cmp  %o2, 8
a00ff00c:  02 80 03 06  be  0xa00ffc24
a00ff010:  19 33 c0 45  sethi  %hi(0xcf011400), %o4
a00ff014:  90 13 20 e4  or  %o4, 0xe4, %o0	! 0xcf0114e4
a00ff018:  d2 02 00 00  ld  [ %o0 ], %o1
a00ff01c:  82 0a 7f cf  and  %o1, -49, %g1
a00ff020:  c2 22 00 00  st  %g1, [ %o0 ]
a00ff024:  30 80 04 bc  b,a   0xa0100314
a00ff028:  80 a2 a0 05  cmp  %o2, 5
a00ff02c:  02 80 01 df  be  0xa00ff7a8
a00ff030:  80 a2 a0 08  cmp  %o2, 8
a00ff034:  02 80 02 9b  be  0xa00ffaa0
a00ff038:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00ff03c:  90 13 61 50  or  %o5, 0x150, %o0	! 0xcf011550
a00ff040:  d8 02 00 00  ld  [ %o0 ], %o4
a00ff044:  92 0b 3f cf  and  %o4, -49, %o1
a00ff048:  d2 22 00 00  st  %o1, [ %o0 ]
a00ff04c:  30 80 04 b2  b,a   0xa0100314
a00ff050:  80 a2 a0 01  cmp  %o2, 1
a00ff054:  02 80 01 9a  be  0xa00ff6bc
a00ff058:  13 33 c0 45  sethi  %hi(0xcf011400), %o1
a00ff05c:  98 12 60 cc  or  %o1, 0xcc, %o4	! 0xcf0114cc
a00ff060:  c2 03 00 00  ld  [ %o4 ], %g1
a00ff064:  90 08 7f cf  and  %g1, -49, %o0
a00ff068:  d0 23 00 00  st  %o0, [ %o4 ]
a00ff06c:  30 80 04 aa  b,a   0xa0100314
a00ff070:  80 a2 a0 05  cmp  %o2, 5
a00ff074:  02 80 01 d4  be  0xa00ff7c4
a00ff078:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a00ff07c:  94 10 60 d4  or  %g1, 0xd4, %o2	! 0xcf0114d4
a00ff080:  d2 02 80 00  ld  [ %o2 ], %o1
a00ff084:  90 0a 7f f3  and  %o1, -13, %o0
a00ff088:  d0 22 80 00  st  %o0, [ %o2 ]
a00ff08c:  30 80 04 a2  b,a   0xa0100314
a00ff090:  80 a2 a0 05  cmp  %o2, 5
a00ff094:  02 80 01 6f  be  0xa00ff650
a00ff098:  80 a2 a0 0f  cmp  %o2, 0xf
a00ff09c:  02 80 02 53  be  0xa00ff9e8
a00ff0a0:  19 33 c0 45  sethi  %hi(0xcf011400), %o4
a00ff0a4:  9a 13 21 2c  or  %o4, 0x12c, %o5	! 0xcf01152c
a00ff0a8:  d2 03 40 00  ld  [ %o5 ], %o1
a00ff0ac:  90 0a 7f fc  and  %o1, -4, %o0
a00ff0b0:  d0 23 40 00  st  %o0, [ %o5 ]
a00ff0b4:  30 80 04 98  b,a   0xa0100314
a00ff0b8:  80 a2 a0 12  cmp  %o2, 0x12
a00ff0bc:  02 80 02 44  be  0xa00ff9cc
a00ff0c0:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a00ff0c4:  94 10 62 ac  or  %g1, 0x2ac, %o2	! 0xcf0116ac
a00ff0c8:  d2 02 80 00  ld  [ %o2 ], %o1
a00ff0cc:  90 0a 7f f3  and  %o1, -13, %o0
a00ff0d0:  d0 22 80 00  st  %o0, [ %o2 ]
a00ff0d4:  30 80 04 90  b,a   0xa0100314
a00ff0d8:  80 a2 a0 08  cmp  %o2, 8
a00ff0dc:  02 80 02 1c  be  0xa00ff94c
a00ff0e0:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00ff0e4:  98 13 61 50  or  %o5, 0x150, %o4	! 0xcf011550
a00ff0e8:  c2 03 00 00  ld  [ %o4 ], %g1
a00ff0ec:  94 08 7f f3  and  %g1, -13, %o2
a00ff0f0:  d4 23 00 00  st  %o2, [ %o4 ]
a00ff0f4:  30 80 04 88  b,a   0xa0100314
a00ff0f8:  80 a2 a0 0e  cmp  %o2, 0xe
a00ff0fc:  02 80 02 7d  be  0xa00ffaf0
a00ff100:  80 a2 a0 06  cmp  %o2, 6
a00ff104:  02 80 02 bc  be  0xa00ffbf4
a00ff108:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00ff10c:  98 13 61 24  or  %o5, 0x124, %o4	! 0xcf011524
a00ff110:  d4 03 00 00  ld  [ %o4 ], %o2
a00ff114:  82 0a bf f3  and  %o2, -13, %g1
a00ff118:  c2 23 00 00  st  %g1, [ %o4 ]
a00ff11c:  30 80 04 7e  b,a   0xa0100314
a00ff120:  80 a2 a0 0a  cmp  %o2, 0xa
a00ff124:  02 80 02 52  be  0xa00ffa6c
a00ff128:  80 a2 a0 05  cmp  %o2, 5
a00ff12c:  02 80 02 fa  be  0xa00ffd14
a00ff130:  80 a2 a0 06  cmp  %o2, 6
a00ff134:  02 80 03 68  be  0xa00ffed4
a00ff138:  19 33 c0 45  sethi  %hi(0xcf011400), %o4
a00ff13c:  90 13 21 4c  or  %o4, 0x14c, %o0	! 0xcf01154c
a00ff140:  d2 02 00 00  ld  [ %o0 ], %o1
a00ff144:  82 0a 7f f3  and  %o1, -13, %g1
a00ff148:  c2 22 00 00  st  %g1, [ %o0 ]
a00ff14c:  30 80 04 72  b,a   0xa0100314
a00ff150:  80 a2 a0 06  cmp  %o2, 6
a00ff154:  02 80 02 3f  be  0xa00ffa50
a00ff158:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a00ff15c:  98 10 60 dc  or  %g1, 0xdc, %o4	! 0xcf0114dc
a00ff160:  d0 03 00 00  ld  [ %o4 ], %o0
a00ff164:  94 0a 3f f3  and  %o0, -13, %o2
a00ff168:  d4 23 00 00  st  %o2, [ %o4 ]
a00ff16c:  30 80 04 6a  b,a   0xa0100314
a00ff170:  80 a2 a0 0a  cmp  %o2, 0xa
a00ff174:  02 80 02 08  be  0xa00ff994
a00ff178:  80 a2 a0 08  cmp  %o2, 8
a00ff17c:  02 80 02 c4  be  0xa00ffc8c
a00ff180:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00ff184:  92 13 60 e4  or  %o5, 0xe4, %o1	! 0xcf0114e4
a00ff188:  d4 02 40 00  ld  [ %o1 ], %o2
a00ff18c:  98 0a bf f3  and  %o2, -13, %o4
a00ff190:  d8 22 40 00  st  %o4, [ %o1 ]
a00ff194:  30 80 04 60  b,a   0xa0100314
a00ff198:  80 a2 a0 0b  cmp  %o2, 0xb
a00ff19c:  02 80 01 f2  be  0xa00ff964
a00ff1a0:  11 33 c0 45  sethi  %hi(0xcf011400), %o0
a00ff1a4:  92 12 21 38  or  %o0, 0x138, %o1	! 0xcf011538
a00ff1a8:  d4 02 40 00  ld  [ %o1 ], %o2
a00ff1ac:  98 0a bf f3  and  %o2, -13, %o4
a00ff1b0:  d8 22 40 00  st  %o4, [ %o1 ]
a00ff1b4:  30 80 04 58  b,a   0xa0100314
a00ff1b8:  80 a2 a0 0b  cmp  %o2, 0xb
a00ff1bc:  02 80 02 46  be  0xa00ffad4
a00ff1c0:  80 a2 a0 06  cmp  %o2, 6
a00ff1c4:  02 80 02 f0  be  0xa00ffd84
a00ff1c8:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00ff1cc:  94 13 61 1c  or  %o5, 0x11c, %o2	! 0xcf01151c
a00ff1d0:  d0 02 80 00  ld  [ %o2 ], %o0
a00ff1d4:  82 0a 3f f3  and  %o0, -13, %g1
a00ff1d8:  c2 22 80 00  st  %g1, [ %o2 ]
a00ff1dc:  30 80 04 4e  b,a   0xa0100314
a00ff1e0:  80 a2 a0 05  cmp  %o2, 5
a00ff1e4:  02 80 02 35  be  0xa00ffab8
a00ff1e8:  11 33 c0 45  sethi  %hi(0xcf011400), %o0
a00ff1ec:  98 12 21 30  or  %o0, 0x130, %o4	! 0xcf011530
a00ff1f0:  c2 03 00 00  ld  [ %o4 ], %g1
a00ff1f4:  94 08 7f 3f  and  %g1, -193, %o2
a00ff1f8:  d4 23 00 00  st  %o2, [ %o4 ]
a00ff1fc:  30 80 04 46  b,a   0xa0100314
a00ff200:  80 a2 a0 01  cmp  %o2, 1
a00ff204:  02 80 01 cb  be  0xa00ff930
a00ff208:  11 33 c0 45  sethi  %hi(0xcf011400), %o0
a00ff20c:  92 12 20 cc  or  %o0, 0xcc, %o1	! 0xcf0114cc
a00ff210:  d8 02 40 00  ld  [ %o1 ], %o4
a00ff214:  94 0b 3f f3  and  %o4, -13, %o2
a00ff218:  d4 22 40 00  st  %o2, [ %o1 ]
a00ff21c:  30 80 04 3e  b,a   0xa0100314
a00ff220:  80 a2 a0 05  cmp  %o2, 5
a00ff224:  02 80 02 a7  be  0xa00ffcc0
a00ff228:  15 33 c0 45  sethi  %hi(0xcf011400), %o2
a00ff22c:  90 12 a1 30  or  %o2, 0x130, %o0	! 0xcf011530
a00ff230:  d8 02 00 00  ld  [ %o0 ], %o4
a00ff234:  92 0b 3f cf  and  %o4, -49, %o1
a00ff238:  d2 22 00 00  st  %o1, [ %o0 ]
a00ff23c:  30 80 04 36  b,a   0xa0100314
a00ff240:  80 a2 a0 0a  cmp  %o2, 0xa
a00ff244:  02 80 02 a6  be  0xa00ffcdc
a00ff248:  80 a2 a0 05  cmp  %o2, 5
a00ff24c:  02 80 02 f4  be  0xa00ffe1c
a00ff250:  80 a2 a0 06  cmp  %o2, 6
a00ff254:  02 80 03 67  be  0xa00ffff0
a00ff258:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00ff25c:  92 13 61 4c  or  %o5, 0x14c, %o1	! 0xcf01154c
a00ff260:  d8 02 40 00  ld  [ %o1 ], %o4
a00ff264:  82 0b 3f fc  and  %o4, -4, %g1
a00ff268:  c2 22 40 00  st  %g1, [ %o1 ]
a00ff26c:  30 80 04 2a  b,a   0xa0100314
a00ff270:  80 a2 a0 0b  cmp  %o2, 0xb
a00ff274:  02 80 02 80  be  0xa00ffc74
a00ff278:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00ff27c:  94 13 61 38  or  %o5, 0x138, %o2	! 0xcf011538
a00ff280:  c2 02 80 00  ld  [ %o2 ], %g1
a00ff284:  90 08 7f fc  and  %g1, -4, %o0
a00ff288:  d0 22 80 00  st  %o0, [ %o2 ]
a00ff28c:  30 80 04 22  b,a   0xa0100314
a00ff290:  80 a2 a0 12  cmp  %o2, 0x12
a00ff294:  02 80 02 71  be  0xa00ffc58
a00ff298:  11 33 c0 45  sethi  %hi(0xcf011400), %o0
a00ff29c:  98 12 22 ac  or  %o0, 0x2ac, %o4	! 0xcf0116ac
a00ff2a0:  d4 03 00 00  ld  [ %o4 ], %o2
a00ff2a4:  82 0a bf fc  and  %o2, -4, %g1
a00ff2a8:  c2 23 00 00  st  %g1, [ %o4 ]
a00ff2ac:  30 80 04 1a  b,a   0xa0100314
a00ff2b0:  80 a2 a0 0b  cmp  %o2, 0xb
a00ff2b4:  02 80 02 9f  be  0xa00ffd30
a00ff2b8:  80 a2 a0 08  cmp  %o2, 8
a00ff2bc:  02 80 02 cc  be  0xa00ffdec
a00ff2c0:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00ff2c4:  94 13 61 50  or  %o5, 0x150, %o2	! 0xcf011550
a00ff2c8:  d0 02 80 00  ld  [ %o2 ], %o0
a00ff2cc:  82 0a 3f fc  and  %o0, -4, %g1
a00ff2d0:  c2 22 80 00  st  %g1, [ %o2 ]
a00ff2d4:  30 80 04 10  b,a   0xa0100314
a00ff2d8:  80 a2 a0 06  cmp  %o2, 6
a00ff2dc:  02 80 02 87  be  0xa00ffcf8
a00ff2e0:  15 33 c0 45  sethi  %hi(0xcf011400), %o2
a00ff2e4:  92 12 a0 dc  or  %o2, 0xdc, %o1	! 0xcf0114dc
a00ff2e8:  d8 02 40 00  ld  [ %o1 ], %o4
a00ff2ec:  82 0b 3f fc  and  %o4, -4, %g1
a00ff2f0:  c2 22 40 00  st  %g1, [ %o1 ]
a00ff2f4:  30 80 04 08  b,a   0xa0100314
a00ff2f8:  80 a2 a0 0a  cmp  %o2, 0xa
a00ff2fc:  02 80 02 50  be  0xa00ffc3c
a00ff300:  80 a2 a0 08  cmp  %o2, 8
a00ff304:  02 80 02 e1  be  0xa00ffe88
a00ff308:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00ff30c:  98 13 60 e4  or  %o5, 0xe4, %o4	! 0xcf0114e4
a00ff310:  d0 03 00 00  ld  [ %o4 ], %o0
a00ff314:  94 0a 3f fc  and  %o0, -4, %o2
a00ff318:  d4 23 00 00  st  %o2, [ %o4 ]
a00ff31c:  30 80 03 fe  b,a   0xa0100314
a00ff320:  80 a2 a0 0e  cmp  %o2, 0xe
a00ff324:  02 80 02 8a  be  0xa00ffd4c
a00ff328:  80 a2 a0 06  cmp  %o2, 6
a00ff32c:  02 80 02 b6  be  0xa00ffe04
a00ff330:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00ff334:  94 13 61 24  or  %o5, 0x124, %o2	! 0xcf011524
a00ff338:  d0 02 80 00  ld  [ %o2 ], %o0
a00ff33c:  82 0a 3f fc  and  %o0, -4, %g1
a00ff340:  c2 22 80 00  st  %g1, [ %o2 ]
a00ff344:  30 80 03 f4  b,a   0xa0100314
a00ff348:  80 a2 a0 0b  cmp  %o2, 0xb
a00ff34c:  02 80 02 56  be  0xa00ffca4
a00ff350:  80 a2 a0 06  cmp  %o2, 6
a00ff354:  02 80 02 c0  be  0xa00ffe54
a00ff358:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00ff35c:  90 13 61 1c  or  %o5, 0x11c, %o0	! 0xcf01151c
a00ff360:  d2 02 00 00  ld  [ %o0 ], %o1
a00ff364:  82 0a 7f fc  and  %o1, -4, %g1
a00ff368:  c2 22 00 00  st  %g1, [ %o0 ]
a00ff36c:  30 80 03 ea  b,a   0xa0100314
a00ff370:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00ff374:  92 13 60 d8  or  %o5, 0xd8, %o1	! 0xcf0114d8
a00ff378:  d4 02 40 00  ld  [ %o1 ], %o2
a00ff37c:  82 0a bf 3f  and  %o2, -193, %g1
a00ff380:  98 10 60 40  or  %g1, 0x40, %o4
a00ff384:  d8 22 40 00  st  %o4, [ %o1 ]
a00ff388:  30 80 03 e3  b,a   0xa0100314
a00ff38c:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00ff390:  94 13 62 ac  or  %o5, 0x2ac, %o2	! 0xcf0116ac
a00ff394:  d2 02 80 00  ld  [ %o2 ], %o1
a00ff398:  82 0a 7f 3f  and  %o1, -193, %g1
a00ff39c:  90 10 60 40  or  %g1, 0x40, %o0
a00ff3a0:  d0 22 80 00  st  %o0, [ %o2 ]
a00ff3a4:  30 80 03 dc  b,a   0xa0100314
a00ff3a8:  11 33 c0 45  sethi  %hi(0xcf011400), %o0
a00ff3ac:  92 12 20 cc  or  %o0, 0xcc, %o1	! 0xcf0114cc
a00ff3b0:  c2 02 40 00  ld  [ %o1 ], %g1
a00ff3b4:  98 08 7f 3f  and  %g1, -193, %o4
a00ff3b8:  94 13 20 40  or  %o4, 0x40, %o2
a00ff3bc:  d4 22 40 00  st  %o2, [ %o1 ]
a00ff3c0:  30 80 03 d5  b,a   0xa0100314
a00ff3c4:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00ff3c8:  92 13 61 40  or  %o5, 0x140, %o1	! 0xcf011540
a00ff3cc:  c2 02 40 00  ld  [ %o1 ], %g1
a00ff3d0:  98 08 7f 3f  and  %g1, -193, %o4
a00ff3d4:  94 13 20 40  or  %o4, 0x40, %o2
a00ff3d8:  d4 22 40 00  st  %o2, [ %o1 ]
a00ff3dc:  30 80 03 ce  b,a   0xa0100314
a00ff3e0:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00ff3e4:  98 13 60 e4  or  %o5, 0xe4, %o4	! 0xcf0114e4
a00ff3e8:  d0 03 00 00  ld  [ %o4 ], %o0
a00ff3ec:  82 0a 3f 3f  and  %o0, -193, %g1
a00ff3f0:  94 10 60 40  or  %g1, 0x40, %o2
a00ff3f4:  d4 23 00 00  st  %o2, [ %o4 ]
a00ff3f8:  30 80 03 c7  b,a   0xa0100314
a00ff3fc:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a00ff400:  9a 10 60 d0  or  %g1, 0xd0, %o5	! 0xcf0114d0
a00ff404:  d0 03 40 00  ld  [ %o5 ], %o0
a00ff408:  94 0a 3f fc  and  %o0, -4, %o2
a00ff40c:  82 12 a0 01  or  %o2, 1, %g1
a00ff410:  c2 23 40 00  st  %g1, [ %o5 ]
a00ff414:  10 bf fd e5  b  0xa00feba8
a00ff418:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a00ff41c:  11 33 c0 45  sethi  %hi(0xcf011400), %o0
a00ff420:  92 12 21 4c  or  %o0, 0x14c, %o1	! 0xcf01154c
a00ff424:  c2 02 40 00  ld  [ %o1 ], %g1
a00ff428:  94 08 7f 3f  and  %g1, -193, %o2
a00ff42c:  98 12 a0 40  or  %o2, 0x40, %o4
a00ff430:  d8 22 40 00  st  %o4, [ %o1 ]
a00ff434:  30 80 03 b8  b,a   0xa0100314
a00ff438:  13 33 c0 45  sethi  %hi(0xcf011400), %o1
a00ff43c:  98 12 61 1c  or  %o1, 0x11c, %o4	! 0xcf01151c
a00ff440:  c2 03 00 00  ld  [ %o4 ], %g1
a00ff444:  90 08 7f 3f  and  %g1, -193, %o0
a00ff448:  94 12 20 40  or  %o0, 0x40, %o2
a00ff44c:  d4 23 00 00  st  %o2, [ %o4 ]
a00ff450:  30 80 03 b1  b,a   0xa0100314
a00ff454:  19 33 c0 45  sethi  %hi(0xcf011400), %o4
a00ff458:  9a 13 21 2c  or  %o4, 0x12c, %o5	! 0xcf01152c
a00ff45c:  d2 03 40 00  ld  [ %o5 ], %o1
a00ff460:  90 0a 7f f3  and  %o1, -13, %o0
a00ff464:  82 12 20 04  or  %o0, 4, %g1
a00ff468:  c2 23 40 00  st  %g1, [ %o5 ]
a00ff46c:  30 80 03 aa  b,a   0xa0100314
a00ff470:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00ff474:  90 13 61 38  or  %o5, 0x138, %o0	! 0xcf011538
a00ff478:  d2 02 00 00  ld  [ %o0 ], %o1
a00ff47c:  82 12 60 c0  or  %o1, 0xc0, %g1
a00ff480:  c2 22 00 00  st  %g1, [ %o0 ]
a00ff484:  30 80 03 a4  b,a   0xa0100314
a00ff488:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00ff48c:  92 13 60 d4  or  %o5, 0xd4, %o1	! 0xcf0114d4
a00ff490:  d0 02 40 00  ld  [ %o1 ], %o0
a00ff494:  94 0a 3f cf  and  %o0, -49, %o2
a00ff498:  98 12 a0 10  or  %o2, 0x10, %o4
a00ff49c:  d8 22 40 00  st  %o4, [ %o1 ]
a00ff4a0:  30 80 03 9d  b,a   0xa0100314
a00ff4a4:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00ff4a8:  98 13 60 dc  or  %o5, 0xdc, %o4	! 0xcf0114dc
a00ff4ac:  d0 03 00 00  ld  [ %o4 ], %o0
a00ff4b0:  82 0a 3f 3f  and  %o0, -193, %g1
a00ff4b4:  94 10 60 40  or  %g1, 0x40, %o2
a00ff4b8:  d4 23 00 00  st  %o2, [ %o4 ]
a00ff4bc:  30 80 03 96  b,a   0xa0100314
a00ff4c0:  11 33 c0 45  sethi  %hi(0xcf011400), %o0
a00ff4c4:  92 12 21 50  or  %o0, 0x150, %o1	! 0xcf011550
a00ff4c8:  d4 02 40 00  ld  [ %o1 ], %o2
a00ff4cc:  98 0a bf 3f  and  %o2, -193, %o4
a00ff4d0:  82 13 20 40  or  %o4, 0x40, %g1
a00ff4d4:  c2 22 40 00  st  %g1, [ %o1 ]
a00ff4d8:  30 80 03 8f  b,a   0xa0100314
a00ff4dc:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a00ff4e0:  92 10 61 24  or  %g1, 0x124, %o1	! 0xcf011524
a00ff4e4:  d0 02 40 00  ld  [ %o1 ], %o0
a00ff4e8:  94 0a 3f 3f  and  %o0, -193, %o2
a00ff4ec:  98 12 a0 40  or  %o2, 0x40, %o4
a00ff4f0:  d8 22 40 00  st  %o4, [ %o1 ]
a00ff4f4:  30 80 03 88  b,a   0xa0100314
a00ff4f8:  80 a2 a0 12  cmp  %o2, 0x12
a00ff4fc:  02 80 02 5c  be  0xa00ffe6c
a00ff500:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a00ff504:  90 10 62 b0  or  %g1, 0x2b0, %o0	! 0xcf0116b0
a00ff508:  d8 02 00 00  ld  [ %o0 ], %o4
a00ff50c:  92 0b 3f 3f  and  %o4, -193, %o1
a00ff510:  d2 22 00 00  st  %o1, [ %o0 ]
a00ff514:  30 80 03 80  b,a   0xa0100314
a00ff518:  80 a2 a0 06  cmp  %o2, 6
a00ff51c:  02 80 02 67  be  0xa00ffeb8
a00ff520:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a00ff524:  94 10 60 e0  or  %g1, 0xe0, %o2	! 0xcf0114e0
a00ff528:  d2 02 80 00  ld  [ %o2 ], %o1
a00ff52c:  90 0a 7f 3f  and  %o1, -193, %o0
a00ff530:  d0 22 80 00  st  %o0, [ %o2 ]
a00ff534:  30 80 03 78  b,a   0xa0100314
a00ff538:  80 a2 a0 06  cmp  %o2, 6
a00ff53c:  02 80 02 1f  be  0xa00ffdb8
a00ff540:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00ff544:  92 13 61 20  or  %o5, 0x120, %o1	! 0xcf011520
a00ff548:  d4 02 40 00  ld  [ %o1 ], %o2
a00ff54c:  98 0a bf 3f  and  %o2, -193, %o4
a00ff550:  d8 22 40 00  st  %o4, [ %o1 ]
a00ff554:  30 80 03 70  b,a   0xa0100314
a00ff558:  80 a2 a0 0c  cmp  %o2, 0xc
a00ff55c:  02 80 02 6a  be  0xa00fff04
a00ff560:  80 a2 a0 0d  cmp  %o2, 0xd
a00ff564:  02 80 02 6f  be  0xa00fff20
a00ff568:  80 a2 a0 06  cmp  %o2, 6
a00ff56c:  02 80 02 f1  be  0xa0100130
a00ff570:  15 33 c0 45  sethi  %hi(0xcf011400), %o2
a00ff574:  92 12 a1 18  or  %o2, 0x118, %o1	! 0xcf011518
a00ff578:  d8 02 40 00  ld  [ %o1 ], %o4
a00ff57c:  82 0b 3f 3f  and  %o4, -193, %g1
a00ff580:  c2 22 40 00  st  %g1, [ %o1 ]
a00ff584:  30 80 03 64  b,a   0xa0100314
a00ff588:  80 a2 a0 06  cmp  %o2, 6
a00ff58c:  02 80 02 58  be  0xa00ffeec
a00ff590:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00ff594:  90 13 61 28  or  %o5, 0x128, %o0	! 0xcf011528
a00ff598:  d8 02 00 00  ld  [ %o0 ], %o4
a00ff59c:  92 0b 3f 3f  and  %o4, -193, %o1
a00ff5a0:  d2 22 00 00  st  %o1, [ %o0 ]
a00ff5a4:  30 80 03 5c  b,a   0xa0100314
a00ff5a8:  80 a2 a0 0a  cmp  %o2, 0xa
a00ff5ac:  02 80 02 09  be  0xa00ffdd0
a00ff5b0:  80 a2 a0 08  cmp  %o2, 8
a00ff5b4:  02 80 02 89  be  0xa00fffd8
a00ff5b8:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00ff5bc:  94 13 60 e8  or  %o5, 0xe8, %o2	! 0xcf0114e8
a00ff5c0:  d2 02 80 00  ld  [ %o2 ], %o1
a00ff5c4:  90 0a 7f 3f  and  %o1, -193, %o0
a00ff5c8:  d0 22 80 00  st  %o0, [ %o2 ]
a00ff5cc:  30 80 03 52  b,a   0xa0100314
a00ff5d0:  80 a2 a0 0b  cmp  %o2, 0xb
a00ff5d4:  02 80 01 f2  be  0xa00ffd9c
a00ff5d8:  80 a2 a0 08  cmp  %o2, 8
a00ff5dc:  02 80 02 66  be  0xa00fff74
a00ff5e0:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00ff5e4:  90 13 61 54  or  %o5, 0x154, %o0	! 0xcf011554
a00ff5e8:  d2 02 00 00  ld  [ %o0 ], %o1
a00ff5ec:  82 0a 7f 3f  and  %o1, -193, %g1
a00ff5f0:  c2 22 00 00  st  %g1, [ %o0 ]
a00ff5f4:  30 80 03 48  b,a   0xa0100314
a00ff5f8:  80 a2 a0 05  cmp  %o2, 5
a00ff5fc:  02 80 02 0f  be  0xa00ffe38
a00ff600:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00ff604:  94 13 61 30  or  %o5, 0x130, %o2	! 0xcf011530
a00ff608:  d0 02 80 00  ld  [ %o2 ], %o0
a00ff60c:  82 0a 3f f3  and  %o0, -13, %g1
a00ff610:  c2 22 80 00  st  %g1, [ %o2 ]
a00ff614:  30 80 03 40  b,a   0xa0100314
a00ff618:  19 33 c0 45  sethi  %hi(0xcf011400), %o4
a00ff61c:  94 13 21 1c  or  %o4, 0x11c, %o2	! 0xcf01151c
a00ff620:  c2 02 80 00  ld  [ %o2 ], %g1
a00ff624:  92 08 7f cf  and  %g1, -49, %o1
a00ff628:  90 12 60 10  or  %o1, 0x10, %o0
a00ff62c:  d0 22 80 00  st  %o0, [ %o2 ]
a00ff630:  30 80 03 39  b,a   0xa0100314
a00ff634:  15 33 c0 45  sethi  %hi(0xcf011400), %o2
a00ff638:  9a 12 a1 40  or  %o2, 0x140, %o5	! 0xcf011540
a00ff63c:  d2 03 40 00  ld  [ %o5 ], %o1
a00ff640:  90 0a 7f cf  and  %o1, -49, %o0
a00ff644:  82 12 20 10  or  %o0, 0x10, %g1
a00ff648:  c2 23 40 00  st  %g1, [ %o5 ]
a00ff64c:  30 80 03 32  b,a   0xa0100314
a00ff650:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00ff654:  92 13 61 2c  or  %o5, 0x12c, %o1	! 0xcf01152c
a00ff658:  c2 02 40 00  ld  [ %o1 ], %g1
a00ff65c:  94 08 7f fc  and  %g1, -4, %o2
a00ff660:  98 12 a0 01  or  %o2, 1, %o4
a00ff664:  d8 22 40 00  st  %o4, [ %o1 ]
a00ff668:  30 80 03 2b  b,a   0xa0100314
a00ff66c:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00ff670:  92 13 62 ac  or  %o5, 0x2ac, %o1	! 0xcf0116ac
a00ff674:  d0 02 40 00  ld  [ %o1 ], %o0
a00ff678:  94 0a 3f cf  and  %o0, -49, %o2
a00ff67c:  98 12 a0 10  or  %o2, 0x10, %o4
a00ff680:  d8 22 40 00  st  %o4, [ %o1 ]
a00ff684:  30 80 03 24  b,a   0xa0100314
a00ff688:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00ff68c:  98 13 61 4c  or  %o5, 0x14c, %o4	! 0xcf01154c
a00ff690:  d0 03 00 00  ld  [ %o4 ], %o0
a00ff694:  82 0a 3f cf  and  %o0, -49, %g1
a00ff698:  94 10 60 10  or  %g1, 0x10, %o2
a00ff69c:  d4 23 00 00  st  %o2, [ %o4 ]
a00ff6a0:  30 80 03 1d  b,a   0xa0100314
a00ff6a4:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00ff6a8:  92 13 61 38  or  %o5, 0x138, %o1	! 0xcf011538
a00ff6ac:  d4 02 40 00  ld  [ %o1 ], %o2
a00ff6b0:  98 12 a0 30  or  %o2, 0x30, %o4
a00ff6b4:  d8 22 40 00  st  %o4, [ %o1 ]
a00ff6b8:  30 80 03 17  b,a   0xa0100314
a00ff6bc:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00ff6c0:  90 13 60 cc  or  %o5, 0xcc, %o0	! 0xcf0114cc
a00ff6c4:  d4 02 00 00  ld  [ %o0 ], %o2
a00ff6c8:  92 0a bf cf  and  %o2, -49, %o1
a00ff6cc:  82 12 60 10  or  %o1, 0x10, %g1
a00ff6d0:  c2 22 00 00  st  %g1, [ %o0 ]
a00ff6d4:  30 80 03 10  b,a   0xa0100314
a00ff6d8:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a00ff6dc:  9a 10 61 4c  or  %g1, 0x14c, %o5	! 0xcf01154c
a00ff6e0:  d4 03 40 00  ld  [ %o5 ], %o2
a00ff6e4:  98 0a bf 3f  and  %o2, -193, %o4
a00ff6e8:  92 13 20 80  or  %o4, 0x80, %o1
a00ff6ec:  d2 23 40 00  st  %o1, [ %o5 ]
a00ff6f0:  30 80 03 09  b,a   0xa0100314
a00ff6f4:  11 33 c0 45  sethi  %hi(0xcf011400), %o0
a00ff6f8:  9a 12 21 1c  or  %o0, 0x11c, %o5	! 0xcf01151c
a00ff6fc:  d4 03 40 00  ld  [ %o5 ], %o2
a00ff700:  98 12 a0 c0  or  %o2, 0xc0, %o4
a00ff704:  d8 23 40 00  st  %o4, [ %o5 ]
a00ff708:  30 80 03 03  b,a   0xa0100314
a00ff70c:  13 33 c0 45  sethi  %hi(0xcf011400), %o1
a00ff710:  98 12 60 e4  or  %o1, 0xe4, %o4	! 0xcf0114e4
a00ff714:  c2 03 00 00  ld  [ %o4 ], %g1
a00ff718:  90 08 7f cf  and  %g1, -49, %o0
a00ff71c:  94 12 20 10  or  %o0, 0x10, %o2
a00ff720:  d4 23 00 00  st  %o2, [ %o4 ]
a00ff724:  30 80 02 fc  b,a   0xa0100314
a00ff728:  13 33 c0 45  sethi  %hi(0xcf011400), %o1
a00ff72c:  98 12 61 24  or  %o1, 0x124, %o4	! 0xcf011524
a00ff730:  c2 03 00 00  ld  [ %o4 ], %g1
a00ff734:  90 08 7f cf  and  %g1, -49, %o0
a00ff738:  94 12 20 10  or  %o0, 0x10, %o2
a00ff73c:  d4 23 00 00  st  %o2, [ %o4 ]
a00ff740:  30 80 02 f5  b,a   0xa0100314
a00ff744:  11 33 c0 45  sethi  %hi(0xcf011400), %o0
a00ff748:  92 12 20 e4  or  %o0, 0xe4, %o1	! 0xcf0114e4
a00ff74c:  c2 02 40 00  ld  [ %o1 ], %g1
a00ff750:  94 08 7f 3f  and  %g1, -193, %o2
a00ff754:  98 12 a0 80  or  %o2, 0x80, %o4
a00ff758:  d8 22 40 00  st  %o4, [ %o1 ]
a00ff75c:  30 80 02 ee  b,a   0xa0100314
a00ff760:  9a 13 60 d0  or  %o5, 0xd0, %o5
a00ff764:  d2 03 40 00  ld  [ %o5 ], %o1
a00ff768:  82 12 60 03  or  %o1, 3, %g1
a00ff76c:  c2 23 40 00  st  %g1, [ %o5 ]
a00ff770:  10 bf fd 0e  b  0xa00feba8
a00ff774:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a00ff778:  19 33 c0 45  sethi  %hi(0xcf011400), %o4
a00ff77c:  9a 13 21 50  or  %o4, 0x150, %o5	! 0xcf011550
a00ff780:  c2 03 40 00  ld  [ %o5 ], %g1
a00ff784:  92 10 60 c0  or  %g1, 0xc0, %o1
a00ff788:  d2 23 40 00  st  %o1, [ %o5 ]
a00ff78c:  30 80 02 e2  b,a   0xa0100314
a00ff790:  15 33 c0 45  sethi  %hi(0xcf011400), %o2
a00ff794:  9a 12 a1 24  or  %o2, 0x124, %o5	! 0xcf011524
a00ff798:  d8 03 40 00  ld  [ %o5 ], %o4
a00ff79c:  92 13 20 c0  or  %o4, 0xc0, %o1
a00ff7a0:  d2 23 40 00  st  %o1, [ %o5 ]
a00ff7a4:  30 80 02 dc  b,a   0xa0100314
a00ff7a8:  13 33 c0 45  sethi  %hi(0xcf011400), %o1
a00ff7ac:  98 12 61 50  or  %o1, 0x150, %o4	! 0xcf011550
a00ff7b0:  d0 03 00 00  ld  [ %o4 ], %o0
a00ff7b4:  94 0a 3f cf  and  %o0, -49, %o2
a00ff7b8:  82 12 a0 10  or  %o2, 0x10, %g1
a00ff7bc:  c2 23 00 00  st  %g1, [ %o4 ]
a00ff7c0:  30 80 02 d5  b,a   0xa0100314
a00ff7c4:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00ff7c8:  90 13 60 d4  or  %o5, 0xd4, %o0	! 0xcf0114d4
a00ff7cc:  d8 02 00 00  ld  [ %o0 ], %o4
a00ff7d0:  82 0b 3f f3  and  %o4, -13, %g1
a00ff7d4:  92 10 60 04  or  %g1, 4, %o1
a00ff7d8:  d2 22 00 00  st  %o1, [ %o0 ]
a00ff7dc:  30 80 02 ce  b,a   0xa0100314
a00ff7e0:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00ff7e4:  90 13 60 dc  or  %o5, 0xdc, %o0	! 0xcf0114dc
a00ff7e8:  d4 02 00 00  ld  [ %o0 ], %o2
a00ff7ec:  98 0a bf cf  and  %o2, -49, %o4
a00ff7f0:  92 13 20 10  or  %o4, 0x10, %o1
a00ff7f4:  d2 22 00 00  st  %o1, [ %o0 ]
a00ff7f8:  30 80 02 c7  b,a   0xa0100314
a00ff7fc:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00ff800:  94 13 61 2c  or  %o5, 0x12c, %o2	! 0xcf01152c
a00ff804:  d2 02 80 00  ld  [ %o2 ], %o1
a00ff808:  90 0a 7f f3  and  %o1, -13, %o0
a00ff80c:  82 12 20 08  or  %o0, 8, %g1
a00ff810:  c2 22 80 00  st  %g1, [ %o2 ]
a00ff814:  30 80 02 c0  b,a   0xa0100314
a00ff818:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00ff81c:  94 13 60 d8  or  %o5, 0xd8, %o2	! 0xcf0114d8
a00ff820:  d8 02 80 00  ld  [ %o2 ], %o4
a00ff824:  92 0b 3f cf  and  %o4, -49, %o1
a00ff828:  90 12 60 10  or  %o1, 0x10, %o0
a00ff82c:  d0 22 80 00  st  %o0, [ %o2 ]
a00ff830:  30 80 02 b9  b,a   0xa0100314
a00ff834:  80 a2 a0 12  cmp  %o2, 0x12
a00ff838:  02 80 01 db  be  0xa00fffa4
a00ff83c:  13 33 c0 45  sethi  %hi(0xcf011400), %o1
a00ff840:  94 12 62 b0  or  %o1, 0x2b0, %o2	! 0xcf0116b0
a00ff844:  d0 02 80 00  ld  [ %o2 ], %o0
a00ff848:  82 0a 3f cf  and  %o0, -49, %g1
a00ff84c:  c2 22 80 00  st  %g1, [ %o2 ]
a00ff850:  30 80 02 b1  b,a   0xa0100314
a00ff854:  80 a2 a0 0b  cmp  %o2, 0xb
a00ff858:  02 80 01 fa  be  0xa0100040
a00ff85c:  80 a2 a0 08  cmp  %o2, 8
a00ff860:  02 80 01 ff  be  0xa010005c
a00ff864:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00ff868:  92 13 61 54  or  %o5, 0x154, %o1	! 0xcf011554
a00ff86c:  d8 02 40 00  ld  [ %o1 ], %o4
a00ff870:  82 0b 3f cf  and  %o4, -49, %g1
a00ff874:  c2 22 40 00  st  %g1, [ %o1 ]
a00ff878:  30 80 02 a7  b,a   0xa0100314
a00ff87c:  80 a2 a0 06  cmp  %o2, 6
a00ff880:  02 80 01 b6  be  0xa00fff58
a00ff884:  11 33 c0 45  sethi  %hi(0xcf011400), %o0
a00ff888:  98 12 20 e0  or  %o0, 0xe0, %o4	! 0xcf0114e0
a00ff88c:  d4 03 00 00  ld  [ %o4 ], %o2
a00ff890:  82 0a bf cf  and  %o2, -49, %g1
a00ff894:  c2 23 00 00  st  %g1, [ %o4 ]
a00ff898:  30 80 02 9f  b,a   0xa0100314
a00ff89c:  80 a2 a0 0a  cmp  %o2, 0xa
a00ff8a0:  02 80 01 a7  be  0xa00fff3c
a00ff8a4:  80 a2 a0 08  cmp  %o2, 8
a00ff8a8:  02 80 02 1c  be  0xa0100118
a00ff8ac:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00ff8b0:  90 13 60 e8  or  %o5, 0xe8, %o0	! 0xcf0114e8
a00ff8b4:  d8 02 00 00  ld  [ %o0 ], %o4
a00ff8b8:  92 0b 3f cf  and  %o4, -49, %o1
a00ff8bc:  d2 22 00 00  st  %o1, [ %o0 ]
a00ff8c0:  30 80 02 95  b,a   0xa0100314
a00ff8c4:  80 a2 a0 06  cmp  %o2, 6
a00ff8c8:  02 80 01 b1  be  0xa00fff8c
a00ff8cc:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00ff8d0:  98 13 61 28  or  %o5, 0x128, %o4	! 0xcf011528
a00ff8d4:  c2 03 00 00  ld  [ %o4 ], %g1
a00ff8d8:  94 08 7f cf  and  %g1, -49, %o2
a00ff8dc:  d4 23 00 00  st  %o2, [ %o4 ]
a00ff8e0:  30 80 02 8d  b,a   0xa0100314
a00ff8e4:  80 a2 a0 0c  cmp  %o2, 0xc
a00ff8e8:  02 80 01 cf  be  0xa0100024
a00ff8ec:  80 a2 a0 0d  cmp  %o2, 0xd
a00ff8f0:  02 80 01 f6  be  0xa01000c8
a00ff8f4:  80 a2 a0 06  cmp  %o2, 6
a00ff8f8:  02 80 02 3d  be  0xa01001ec
a00ff8fc:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00ff900:  98 13 61 18  or  %o5, 0x118, %o4	! 0xcf011518
a00ff904:  d4 03 00 00  ld  [ %o4 ], %o2
a00ff908:  82 0a bf cf  and  %o2, -49, %g1
a00ff90c:  c2 23 00 00  st  %g1, [ %o4 ]
a00ff910:  30 80 02 81  b,a   0xa0100314
a00ff914:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00ff918:  98 13 60 d4  or  %o5, 0xd4, %o4	! 0xcf0114d4
a00ff91c:  d2 03 00 00  ld  [ %o4 ], %o1
a00ff920:  90 0a 7f fc  and  %o1, -4, %o0
a00ff924:  94 12 20 01  or  %o0, 1, %o2
a00ff928:  d4 23 00 00  st  %o2, [ %o4 ]
a00ff92c:  30 80 02 7a  b,a   0xa0100314
a00ff930:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00ff934:  94 13 60 cc  or  %o5, 0xcc, %o2	! 0xcf0114cc
a00ff938:  c2 02 80 00  ld  [ %o2 ], %g1
a00ff93c:  90 08 7f f3  and  %g1, -13, %o0
a00ff940:  98 12 20 04  or  %o0, 4, %o4
a00ff944:  d8 22 80 00  st  %o4, [ %o2 ]
a00ff948:  30 80 02 73  b,a   0xa0100314
a00ff94c:  13 33 c0 45  sethi  %hi(0xcf011400), %o1
a00ff950:  94 12 61 50  or  %o1, 0x150, %o2	! 0xcf011550
a00ff954:  d0 02 80 00  ld  [ %o2 ], %o0
a00ff958:  82 12 20 0c  or  %o0, 0xc, %g1
a00ff95c:  c2 22 80 00  st  %g1, [ %o2 ]
a00ff960:  30 80 02 6d  b,a   0xa0100314
a00ff964:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00ff968:  94 13 61 38  or  %o5, 0x138, %o2	! 0xcf011538
a00ff96c:  c2 02 80 00  ld  [ %o2 ], %g1
a00ff970:  90 10 60 0c  or  %g1, 0xc, %o0
a00ff974:  d0 22 80 00  st  %o0, [ %o2 ]
a00ff978:  30 80 02 67  b,a   0xa0100314
a00ff97c:  13 33 c0 45  sethi  %hi(0xcf011400), %o1
a00ff980:  9a 12 61 1c  or  %o1, 0x11c, %o5	! 0xcf01151c
a00ff984:  d0 03 40 00  ld  [ %o5 ], %o0
a00ff988:  94 12 20 30  or  %o0, 0x30, %o2
a00ff98c:  d4 23 40 00  st  %o2, [ %o5 ]
a00ff990:  30 80 02 61  b,a   0xa0100314
a00ff994:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00ff998:  94 13 60 e4  or  %o5, 0xe4, %o2	! 0xcf0114e4
a00ff99c:  d2 02 80 00  ld  [ %o2 ], %o1
a00ff9a0:  82 0a 7f f3  and  %o1, -13, %g1
a00ff9a4:  90 10 60 04  or  %g1, 4, %o0
a00ff9a8:  d0 22 80 00  st  %o0, [ %o2 ]
a00ff9ac:  30 80 02 5a  b,a   0xa0100314
a00ff9b0:  11 33 c0 45  sethi  %hi(0xcf011400), %o0
a00ff9b4:  92 12 21 4c  or  %o0, 0x14c, %o1	! 0xcf01154c
a00ff9b8:  c2 02 40 00  ld  [ %o1 ], %g1
a00ff9bc:  94 08 7f cf  and  %g1, -49, %o2
a00ff9c0:  98 12 a0 20  or  %o2, 0x20, %o4
a00ff9c4:  d8 22 40 00  st  %o4, [ %o1 ]
a00ff9c8:  30 80 02 53  b,a   0xa0100314
a00ff9cc:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00ff9d0:  90 13 62 ac  or  %o5, 0x2ac, %o0	! 0xcf0116ac
a00ff9d4:  d8 02 00 00  ld  [ %o0 ], %o4
a00ff9d8:  82 0b 3f f3  and  %o4, -13, %g1
a00ff9dc:  92 10 60 04  or  %g1, 4, %o1
a00ff9e0:  d2 22 00 00  st  %o1, [ %o0 ]
a00ff9e4:  30 80 02 4c  b,a   0xa0100314
a00ff9e8:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a00ff9ec:  90 10 61 2c  or  %g1, 0x12c, %o0	! 0xcf01152c
a00ff9f0:  d4 02 00 00  ld  [ %o0 ], %o2
a00ff9f4:  98 0a bf fc  and  %o2, -4, %o4
a00ff9f8:  92 13 20 02  or  %o4, 2, %o1
a00ff9fc:  d2 22 00 00  st  %o1, [ %o0 ]
a00ffa00:  30 80 02 45  b,a   0xa0100314
a00ffa04:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00ffa08:  90 13 61 4c  or  %o5, 0x14c, %o0	! 0xcf01154c
a00ffa0c:  d8 02 00 00  ld  [ %o0 ], %o4
a00ffa10:  92 13 20 c0  or  %o4, 0xc0, %o1
a00ffa14:  d2 22 00 00  st  %o1, [ %o0 ]
a00ffa18:  30 80 02 3f  b,a   0xa0100314
a00ffa1c:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a00ffa20:  9a 10 60 e4  or  %g1, 0xe4, %o5	! 0xcf0114e4
a00ffa24:  d0 03 40 00  ld  [ %o5 ], %o0
a00ffa28:  94 0a 3f cf  and  %o0, -49, %o2
a00ffa2c:  98 12 a0 20  or  %o2, 0x20, %o4
a00ffa30:  d8 23 40 00  st  %o4, [ %o5 ]
a00ffa34:  30 80 02 38  b,a   0xa0100314
a00ffa38:  15 33 c0 45  sethi  %hi(0xcf011400), %o2
a00ffa3c:  9a 12 a0 e4  or  %o2, 0xe4, %o5	! 0xcf0114e4
a00ffa40:  d8 03 40 00  ld  [ %o5 ], %o4
a00ffa44:  92 13 20 c0  or  %o4, 0xc0, %o1
a00ffa48:  d2 23 40 00  st  %o1, [ %o5 ]
a00ffa4c:  30 80 02 32  b,a   0xa0100314
a00ffa50:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00ffa54:  94 13 60 dc  or  %o5, 0xdc, %o2	! 0xcf0114dc
a00ffa58:  d2 02 80 00  ld  [ %o2 ], %o1
a00ffa5c:  82 0a 7f f3  and  %o1, -13, %g1
a00ffa60:  90 10 60 04  or  %g1, 4, %o0
a00ffa64:  d0 22 80 00  st  %o0, [ %o2 ]
a00ffa68:  30 80 02 2b  b,a   0xa0100314
a00ffa6c:  13 33 c0 45  sethi  %hi(0xcf011400), %o1
a00ffa70:  98 12 61 4c  or  %o1, 0x14c, %o4	! 0xcf01154c
a00ffa74:  c2 03 00 00  ld  [ %o4 ], %g1
a00ffa78:  90 08 7f f3  and  %g1, -13, %o0
a00ffa7c:  94 12 20 04  or  %o0, 4, %o2
a00ffa80:  d4 23 00 00  st  %o2, [ %o4 ]
a00ffa84:  30 80 02 24  b,a   0xa0100314
a00ffa88:  11 33 c0 45  sethi  %hi(0xcf011400), %o0
a00ffa8c:  9a 12 21 24  or  %o0, 0x124, %o5	! 0xcf011524
a00ffa90:  d4 03 40 00  ld  [ %o5 ], %o2
a00ffa94:  98 12 a0 30  or  %o2, 0x30, %o4
a00ffa98:  d8 23 40 00  st  %o4, [ %o5 ]
a00ffa9c:  30 80 02 1e  b,a   0xa0100314
a00ffaa0:  15 33 c0 45  sethi  %hi(0xcf011400), %o2
a00ffaa4:  9a 12 a1 50  or  %o2, 0x150, %o5	! 0xcf011550
a00ffaa8:  c2 03 40 00  ld  [ %o5 ], %g1
a00ffaac:  98 10 60 30  or  %g1, 0x30, %o4
a00ffab0:  d8 23 40 00  st  %o4, [ %o5 ]
a00ffab4:  30 80 02 18  b,a   0xa0100314
a00ffab8:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00ffabc:  94 13 61 30  or  %o5, 0x130, %o2	! 0xcf011530
a00ffac0:  d2 02 80 00  ld  [ %o2 ], %o1
a00ffac4:  90 0a 7f 3f  and  %o1, -193, %o0
a00ffac8:  82 12 20 40  or  %o0, 0x40, %g1
a00ffacc:  c2 22 80 00  st  %g1, [ %o2 ]
a00ffad0:  30 80 02 11  b,a   0xa0100314
a00ffad4:  15 33 c0 45  sethi  %hi(0xcf011400), %o2
a00ffad8:  90 12 a1 1c  or  %o2, 0x11c, %o0	! 0xcf01151c
a00ffadc:  c2 02 00 00  ld  [ %o0 ], %g1
a00ffae0:  98 08 7f f3  and  %g1, -13, %o4
a00ffae4:  92 13 20 04  or  %o4, 4, %o1
a00ffae8:  d2 22 00 00  st  %o1, [ %o0 ]
a00ffaec:  30 80 02 0a  b,a   0xa0100314
a00ffaf0:  19 33 c0 45  sethi  %hi(0xcf011400), %o4
a00ffaf4:  94 13 21 24  or  %o4, 0x124, %o2	! 0xcf011524
a00ffaf8:  c2 02 80 00  ld  [ %o2 ], %g1
a00ffafc:  92 08 7f f3  and  %g1, -13, %o1
a00ffb00:  90 12 60 04  or  %o1, 4, %o0
a00ffb04:  d0 22 80 00  st  %o0, [ %o2 ]
a00ffb08:  30 80 02 03  b,a   0xa0100314
a00ffb0c:  80 a2 a0 0c  cmp  %o2, 0xc
a00ffb10:  02 80 01 7b  be  0xa01000fc
a00ffb14:  80 a2 a0 06  cmp  %o2, 6
a00ffb18:  02 80 01 c2  be  0xa0100220
a00ffb1c:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00ffb20:  94 13 61 18  or  %o5, 0x118, %o2	! 0xcf011518
a00ffb24:  d0 02 80 00  ld  [ %o2 ], %o0
a00ffb28:  82 0a 3f f3  and  %o0, -13, %g1
a00ffb2c:  c2 22 80 00  st  %g1, [ %o2 ]
a00ffb30:  30 80 01 f9  b,a   0xa0100314
a00ffb34:  80 a2 a0 0b  cmp  %o2, 0xb
a00ffb38:  02 80 01 56  be  0xa0100090
a00ffb3c:  80 a2 a0 08  cmp  %o2, 8
a00ffb40:  02 80 01 c4  be  0xa0100250
a00ffb44:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00ffb48:  98 13 61 54  or  %o5, 0x154, %o4	! 0xcf011554
a00ffb4c:  d4 03 00 00  ld  [ %o4 ], %o2
a00ffb50:  82 0a bf f3  and  %o2, -13, %g1
a00ffb54:  c2 23 00 00  st  %g1, [ %o4 ]
a00ffb58:  30 80 01 ef  b,a   0xa0100314
a00ffb5c:  80 a2 a0 05  cmp  %o2, 5
a00ffb60:  02 80 01 7a  be  0xa0100148
a00ffb64:  80 a2 a0 0f  cmp  %o2, 0xf
a00ffb68:  02 80 01 7f  be  0xa0100164
a00ffb6c:  80 a2 a0 06  cmp  %o2, 6
a00ffb70:  02 80 01 d1  be  0xa01002b4
a00ffb74:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00ffb78:  90 13 62 b0  or  %o5, 0x2b0, %o0	! 0xcf0116b0
a00ffb7c:  d2 02 00 00  ld  [ %o0 ], %o1
a00ffb80:  82 0a 7f f3  and  %o1, -13, %g1
a00ffb84:  c2 22 00 00  st  %g1, [ %o0 ]
a00ffb88:  30 80 01 e3  b,a   0xa0100314
a00ffb8c:  80 a2 a0 0a  cmp  %o2, 0xa
a00ffb90:  02 80 01 39  be  0xa0100074
a00ffb94:  80 a2 a0 08  cmp  %o2, 8
a00ffb98:  02 80 01 a8  be  0xa0100238
a00ffb9c:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00ffba0:  92 13 60 e8  or  %o5, 0xe8, %o1	! 0xcf0114e8
a00ffba4:  d4 02 40 00  ld  [ %o1 ], %o2
a00ffba8:  98 0a bf f3  and  %o2, -13, %o4
a00ffbac:  d8 22 40 00  st  %o4, [ %o1 ]
a00ffbb0:  30 80 01 d9  b,a   0xa0100314
a00ffbb4:  80 a2 a0 06  cmp  %o2, 6
a00ffbb8:  02 80 01 3d  be  0xa01000ac
a00ffbbc:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a00ffbc0:  90 10 60 e0  or  %g1, 0xe0, %o0	! 0xcf0114e0
a00ffbc4:  d8 02 00 00  ld  [ %o0 ], %o4
a00ffbc8:  92 0b 3f f3  and  %o4, -13, %o1
a00ffbcc:  d2 22 00 00  st  %o1, [ %o0 ]
a00ffbd0:  30 80 01 d1  b,a   0xa0100314
a00ffbd4:  80 a2 a0 06  cmp  %o2, 6
a00ffbd8:  02 80 01 43  be  0xa01000e4
a00ffbdc:  13 33 c0 45  sethi  %hi(0xcf011400), %o1
a00ffbe0:  9a 12 61 28  or  %o1, 0x128, %o5	! 0xcf011528
a00ffbe4:  d0 03 40 00  ld  [ %o5 ], %o0
a00ffbe8:  82 0a 3f f3  and  %o0, -13, %g1
a00ffbec:  c2 23 40 00  st  %g1, [ %o5 ]
a00ffbf0:  30 80 01 c9  b,a   0xa0100314
a00ffbf4:  13 33 c0 45  sethi  %hi(0xcf011400), %o1
a00ffbf8:  9a 12 61 24  or  %o1, 0x124, %o5	! 0xcf011524
a00ffbfc:  d0 03 40 00  ld  [ %o5 ], %o0
a00ffc00:  94 12 20 0c  or  %o0, 0xc, %o2
a00ffc04:  d4 23 40 00  st  %o2, [ %o5 ]
a00ffc08:  30 80 01 c3  b,a   0xa0100314
a00ffc0c:  15 33 c0 45  sethi  %hi(0xcf011400), %o2
a00ffc10:  9a 12 a1 4c  or  %o2, 0x14c, %o5	! 0xcf01154c
a00ffc14:  d8 03 40 00  ld  [ %o5 ], %o4
a00ffc18:  92 13 20 30  or  %o4, 0x30, %o1
a00ffc1c:  d2 23 40 00  st  %o1, [ %o5 ]
a00ffc20:  30 80 01 bd  b,a   0xa0100314
a00ffc24:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00ffc28:  92 13 60 e4  or  %o5, 0xe4, %o1	! 0xcf0114e4
a00ffc2c:  d4 02 40 00  ld  [ %o1 ], %o2
a00ffc30:  98 12 a0 30  or  %o2, 0x30, %o4
a00ffc34:  d8 22 40 00  st  %o4, [ %o1 ]
a00ffc38:  30 80 01 b7  b,a   0xa0100314
a00ffc3c:  15 33 c0 45  sethi  %hi(0xcf011400), %o2
a00ffc40:  90 12 a0 e4  or  %o2, 0xe4, %o0	! 0xcf0114e4
a00ffc44:  d8 02 00 00  ld  [ %o0 ], %o4
a00ffc48:  92 0b 3f fc  and  %o4, -4, %o1
a00ffc4c:  82 12 60 01  or  %o1, 1, %g1
a00ffc50:  c2 22 00 00  st  %g1, [ %o0 ]
a00ffc54:  30 80 01 b0  b,a   0xa0100314
a00ffc58:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00ffc5c:  98 13 62 ac  or  %o5, 0x2ac, %o4	! 0xcf0116ac
a00ffc60:  d2 03 00 00  ld  [ %o4 ], %o1
a00ffc64:  90 0a 7f fc  and  %o1, -4, %o0
a00ffc68:  94 12 20 01  or  %o0, 1, %o2
a00ffc6c:  d4 23 00 00  st  %o2, [ %o4 ]
a00ffc70:  30 80 01 a9  b,a   0xa0100314
a00ffc74:  19 33 c0 45  sethi  %hi(0xcf011400), %o4
a00ffc78:  9a 13 21 38  or  %o4, 0x138, %o5	! 0xcf011538
a00ffc7c:  d2 03 40 00  ld  [ %o5 ], %o1
a00ffc80:  82 12 60 03  or  %o1, 3, %g1
a00ffc84:  c2 23 40 00  st  %g1, [ %o5 ]
a00ffc88:  30 80 01 a3  b,a   0xa0100314
a00ffc8c:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a00ffc90:  98 10 60 e4  or  %g1, 0xe4, %o4	! 0xcf0114e4
a00ffc94:  d0 03 00 00  ld  [ %o4 ], %o0
a00ffc98:  94 12 20 0c  or  %o0, 0xc, %o2
a00ffc9c:  d4 23 00 00  st  %o2, [ %o4 ]
a00ffca0:  30 80 01 9d  b,a   0xa0100314
a00ffca4:  11 33 c0 45  sethi  %hi(0xcf011400), %o0
a00ffca8:  92 12 21 1c  or  %o0, 0x11c, %o1	! 0xcf01151c
a00ffcac:  c2 02 40 00  ld  [ %o1 ], %g1
a00ffcb0:  94 08 7f fc  and  %g1, -4, %o2
a00ffcb4:  98 12 a0 01  or  %o2, 1, %o4
a00ffcb8:  d8 22 40 00  st  %o4, [ %o1 ]
a00ffcbc:  30 80 01 96  b,a   0xa0100314
a00ffcc0:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00ffcc4:  92 13 61 30  or  %o5, 0x130, %o1	! 0xcf011530
a00ffcc8:  c2 02 40 00  ld  [ %o1 ], %g1
a00ffccc:  94 08 7f cf  and  %g1, -49, %o2
a00ffcd0:  98 12 a0 10  or  %o2, 0x10, %o4
a00ffcd4:  d8 22 40 00  st  %o4, [ %o1 ]
a00ffcd8:  30 80 01 8f  b,a   0xa0100314
a00ffcdc:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00ffce0:  94 13 61 4c  or  %o5, 0x14c, %o2	! 0xcf01154c
a00ffce4:  d2 02 80 00  ld  [ %o2 ], %o1
a00ffce8:  82 0a 7f fc  and  %o1, -4, %g1
a00ffcec:  90 10 60 01  or  %g1, 1, %o0
a00ffcf0:  d0 22 80 00  st  %o0, [ %o2 ]
a00ffcf4:  30 80 01 88  b,a   0xa0100314
a00ffcf8:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00ffcfc:  92 13 60 dc  or  %o5, 0xdc, %o1	! 0xcf0114dc
a00ffd00:  d0 02 40 00  ld  [ %o1 ], %o0
a00ffd04:  94 0a 3f fc  and  %o0, -4, %o2
a00ffd08:  98 12 a0 01  or  %o2, 1, %o4
a00ffd0c:  d8 22 40 00  st  %o4, [ %o1 ]
a00ffd10:  30 80 01 81  b,a   0xa0100314
a00ffd14:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a00ffd18:  9a 10 61 4c  or  %g1, 0x14c, %o5	! 0xcf01154c
a00ffd1c:  d0 03 40 00  ld  [ %o5 ], %o0
a00ffd20:  94 0a 3f f3  and  %o0, -13, %o2
a00ffd24:  98 12 a0 08  or  %o2, 8, %o4
a00ffd28:  d8 23 40 00  st  %o4, [ %o5 ]
a00ffd2c:  30 80 01 7a  b,a   0xa0100314
a00ffd30:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a00ffd34:  90 10 61 50  or  %g1, 0x150, %o0	! 0xcf011550
a00ffd38:  d4 02 00 00  ld  [ %o0 ], %o2
a00ffd3c:  98 0a bf fc  and  %o2, -4, %o4
a00ffd40:  92 13 20 01  or  %o4, 1, %o1
a00ffd44:  d2 22 00 00  st  %o1, [ %o0 ]
a00ffd48:  30 80 01 73  b,a   0xa0100314
a00ffd4c:  15 33 c0 45  sethi  %hi(0xcf011400), %o2
a00ffd50:  90 12 a1 24  or  %o2, 0x124, %o0	! 0xcf011524
a00ffd54:  c2 02 00 00  ld  [ %o0 ], %g1
a00ffd58:  98 08 7f fc  and  %g1, -4, %o4
a00ffd5c:  92 13 20 01  or  %o4, 1, %o1
a00ffd60:  d2 22 00 00  st  %o1, [ %o0 ]
a00ffd64:  30 80 01 6c  b,a   0xa0100314
a00ffd68:  19 33 c0 45  sethi  %hi(0xcf011400), %o4
a00ffd6c:  9a 13 20 cc  or  %o4, 0xcc, %o5	! 0xcf0114cc
a00ffd70:  d4 03 40 00  ld  [ %o5 ], %o2
a00ffd74:  92 0a bf fc  and  %o2, -4, %o1
a00ffd78:  82 12 60 01  or  %o1, 1, %g1
a00ffd7c:  c2 23 40 00  st  %g1, [ %o5 ]
a00ffd80:  30 80 01 65  b,a   0xa0100314
a00ffd84:  19 33 c0 45  sethi  %hi(0xcf011400), %o4
a00ffd88:  9a 13 21 1c  or  %o4, 0x11c, %o5	! 0xcf01151c
a00ffd8c:  d2 03 40 00  ld  [ %o5 ], %o1
a00ffd90:  90 12 60 0c  or  %o1, 0xc, %o0
a00ffd94:  d0 23 40 00  st  %o0, [ %o5 ]
a00ffd98:  30 80 01 5f  b,a   0xa0100314
a00ffd9c:  11 33 c0 45  sethi  %hi(0xcf011400), %o0
a00ffda0:  92 12 21 54  or  %o0, 0x154, %o1	! 0xcf011554
a00ffda4:  c2 02 40 00  ld  [ %o1 ], %g1
a00ffda8:  94 08 7f 3f  and  %g1, -193, %o2
a00ffdac:  98 12 a0 40  or  %o2, 0x40, %o4
a00ffdb0:  d8 22 40 00  st  %o4, [ %o1 ]
a00ffdb4:  30 80 01 58  b,a   0xa0100314
a00ffdb8:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a00ffdbc:  98 10 61 20  or  %g1, 0x120, %o4	! 0xcf011520
a00ffdc0:  d0 03 00 00  ld  [ %o4 ], %o0
a00ffdc4:  94 12 20 c0  or  %o0, 0xc0, %o2
a00ffdc8:  d4 23 00 00  st  %o2, [ %o4 ]
a00ffdcc:  30 80 01 52  b,a   0xa0100314
a00ffdd0:  11 33 c0 45  sethi  %hi(0xcf011400), %o0
a00ffdd4:  92 12 20 e8  or  %o0, 0xe8, %o1	! 0xcf0114e8
a00ffdd8:  d4 02 40 00  ld  [ %o1 ], %o2
a00ffddc:  98 0a bf 3f  and  %o2, -193, %o4
a00ffde0:  82 13 20 40  or  %o4, 0x40, %g1
a00ffde4:  c2 22 40 00  st  %g1, [ %o1 ]
a00ffde8:  30 80 01 4b  b,a   0xa0100314
a00ffdec:  19 33 c0 45  sethi  %hi(0xcf011400), %o4
a00ffdf0:  9a 13 21 50  or  %o4, 0x150, %o5	! 0xcf011550
a00ffdf4:  d2 03 40 00  ld  [ %o5 ], %o1
a00ffdf8:  90 12 60 03  or  %o1, 3, %o0
a00ffdfc:  d0 23 40 00  st  %o0, [ %o5 ]
a00ffe00:  30 80 01 45  b,a   0xa0100314
a00ffe04:  19 33 c0 45  sethi  %hi(0xcf011400), %o4
a00ffe08:  9a 13 21 24  or  %o4, 0x124, %o5	! 0xcf011524
a00ffe0c:  d2 03 40 00  ld  [ %o5 ], %o1
a00ffe10:  90 12 60 03  or  %o1, 3, %o0
a00ffe14:  d0 23 40 00  st  %o0, [ %o5 ]
a00ffe18:  30 80 01 3f  b,a   0xa0100314
a00ffe1c:  13 33 c0 45  sethi  %hi(0xcf011400), %o1
a00ffe20:  98 12 61 4c  or  %o1, 0x14c, %o4	! 0xcf01154c
a00ffe24:  c2 03 00 00  ld  [ %o4 ], %g1
a00ffe28:  90 08 7f fc  and  %g1, -4, %o0
a00ffe2c:  94 12 20 02  or  %o0, 2, %o2
a00ffe30:  d4 23 00 00  st  %o2, [ %o4 ]
a00ffe34:  30 80 01 38  b,a   0xa0100314
a00ffe38:  19 33 c0 45  sethi  %hi(0xcf011400), %o4
a00ffe3c:  9a 13 21 30  or  %o4, 0x130, %o5	! 0xcf011530
a00ffe40:  d2 03 40 00  ld  [ %o5 ], %o1
a00ffe44:  90 0a 7f f3  and  %o1, -13, %o0
a00ffe48:  82 12 20 04  or  %o0, 4, %g1
a00ffe4c:  c2 23 40 00  st  %g1, [ %o5 ]
a00ffe50:  30 80 01 31  b,a   0xa0100314
a00ffe54:  15 33 c0 45  sethi  %hi(0xcf011400), %o2
a00ffe58:  9a 12 a1 1c  or  %o2, 0x11c, %o5	! 0xcf01151c
a00ffe5c:  d8 03 40 00  ld  [ %o5 ], %o4
a00ffe60:  92 13 20 03  or  %o4, 3, %o1
a00ffe64:  d2 23 40 00  st  %o1, [ %o5 ]
a00ffe68:  30 80 01 2b  b,a   0xa0100314
a00ffe6c:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00ffe70:  92 13 62 b0  or  %o5, 0x2b0, %o1	! 0xcf0116b0
a00ffe74:  d4 02 40 00  ld  [ %o1 ], %o2
a00ffe78:  82 0a bf 3f  and  %o2, -193, %g1
a00ffe7c:  98 10 60 40  or  %g1, 0x40, %o4
a00ffe80:  d8 22 40 00  st  %o4, [ %o1 ]
a00ffe84:  30 80 01 24  b,a   0xa0100314
a00ffe88:  13 33 c0 45  sethi  %hi(0xcf011400), %o1
a00ffe8c:  9a 12 60 e4  or  %o1, 0xe4, %o5	! 0xcf0114e4
a00ffe90:  c2 03 40 00  ld  [ %o5 ], %g1
a00ffe94:  90 10 60 03  or  %g1, 3, %o0
a00ffe98:  d0 23 40 00  st  %o0, [ %o5 ]
a00ffe9c:  30 80 01 1e  b,a   0xa0100314
a00ffea0:  11 33 c0 45  sethi  %hi(0xcf011400), %o0
a00ffea4:  92 12 21 3c  or  %o0, 0x13c, %o1	! 0xcf01153c
a00ffea8:  d4 02 40 00  ld  [ %o1 ], %o2
a00ffeac:  98 12 a0 c0  or  %o2, 0xc0, %o4
a00ffeb0:  d8 22 40 00  st  %o4, [ %o1 ]
a00ffeb4:  30 80 01 18  b,a   0xa0100314
a00ffeb8:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00ffebc:  90 13 60 e0  or  %o5, 0xe0, %o0	! 0xcf0114e0
a00ffec0:  d8 02 00 00  ld  [ %o0 ], %o4
a00ffec4:  82 0b 3f 3f  and  %o4, -193, %g1
a00ffec8:  92 10 60 40  or  %g1, 0x40, %o1
a00ffecc:  d2 22 00 00  st  %o1, [ %o0 ]
a00ffed0:  30 80 01 11  b,a   0xa0100314
a00ffed4:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00ffed8:  92 13 61 4c  or  %o5, 0x14c, %o1	! 0xcf01154c
a00ffedc:  d4 02 40 00  ld  [ %o1 ], %o2
a00ffee0:  98 12 a0 0c  or  %o2, 0xc, %o4
a00ffee4:  d8 22 40 00  st  %o4, [ %o1 ]
a00ffee8:  30 80 01 0b  b,a   0xa0100314
a00ffeec:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a00ffef0:  92 10 61 28  or  %g1, 0x128, %o1	! 0xcf011528
a00ffef4:  d4 02 40 00  ld  [ %o1 ], %o2
a00ffef8:  98 12 a0 c0  or  %o2, 0xc0, %o4
a00ffefc:  d8 22 40 00  st  %o4, [ %o1 ]
a00fff00:  30 80 01 05  b,a   0xa0100314
a00fff04:  19 33 c0 45  sethi  %hi(0xcf011400), %o4
a00fff08:  94 13 21 18  or  %o4, 0x118, %o2	! 0xcf011518
a00fff0c:  c2 02 80 00  ld  [ %o2 ], %g1
a00fff10:  92 08 7f 3f  and  %g1, -193, %o1
a00fff14:  90 12 60 40  or  %o1, 0x40, %o0
a00fff18:  d0 22 80 00  st  %o0, [ %o2 ]
a00fff1c:  30 80 00 fe  b,a   0xa0100314
a00fff20:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a00fff24:  9a 10 61 18  or  %g1, 0x118, %o5	! 0xcf011518
a00fff28:  d2 03 40 00  ld  [ %o5 ], %o1
a00fff2c:  90 0a 7f 3f  and  %o1, -193, %o0
a00fff30:  94 12 20 80  or  %o0, 0x80, %o2
a00fff34:  d4 23 40 00  st  %o2, [ %o5 ]
a00fff38:  30 80 00 f7  b,a   0xa0100314
a00fff3c:  13 33 c0 45  sethi  %hi(0xcf011400), %o1
a00fff40:  98 12 60 e8  or  %o1, 0xe8, %o4	! 0xcf0114e8
a00fff44:  d0 03 00 00  ld  [ %o4 ], %o0
a00fff48:  94 0a 3f cf  and  %o0, -49, %o2
a00fff4c:  82 12 a0 10  or  %o2, 0x10, %g1
a00fff50:  c2 23 00 00  st  %g1, [ %o4 ]
a00fff54:  30 80 00 f0  b,a   0xa0100314
a00fff58:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00fff5c:  98 13 60 e0  or  %o5, 0xe0, %o4	! 0xcf0114e0
a00fff60:  d2 03 00 00  ld  [ %o4 ], %o1
a00fff64:  90 0a 7f cf  and  %o1, -49, %o0
a00fff68:  94 12 20 10  or  %o0, 0x10, %o2
a00fff6c:  d4 23 00 00  st  %o2, [ %o4 ]
a00fff70:  30 80 00 e9  b,a   0xa0100314
a00fff74:  15 33 c0 45  sethi  %hi(0xcf011400), %o2
a00fff78:  9a 12 a1 54  or  %o2, 0x154, %o5	! 0xcf011554
a00fff7c:  d8 03 40 00  ld  [ %o5 ], %o4
a00fff80:  92 13 20 c0  or  %o4, 0xc0, %o1
a00fff84:  d2 23 40 00  st  %o1, [ %o5 ]
a00fff88:  30 80 00 e3  b,a   0xa0100314
a00fff8c:  13 33 c0 45  sethi  %hi(0xcf011400), %o1
a00fff90:  94 12 61 28  or  %o1, 0x128, %o2	! 0xcf011528
a00fff94:  d0 02 80 00  ld  [ %o2 ], %o0
a00fff98:  82 12 20 30  or  %o0, 0x30, %g1
a00fff9c:  c2 22 80 00  st  %g1, [ %o2 ]
a00fffa0:  30 80 00 dd  b,a   0xa0100314
a00fffa4:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00fffa8:  94 13 62 b0  or  %o5, 0x2b0, %o2	! 0xcf0116b0
a00fffac:  d8 02 80 00  ld  [ %o2 ], %o4
a00fffb0:  92 0b 3f cf  and  %o4, -49, %o1
a00fffb4:  90 12 60 10  or  %o1, 0x10, %o0
a00fffb8:  d0 22 80 00  st  %o0, [ %o2 ]
a00fffbc:  30 80 00 d6  b,a   0xa0100314
a00fffc0:  19 33 c0 45  sethi  %hi(0xcf011400), %o4
a00fffc4:  90 13 21 20  or  %o4, 0x120, %o0	! 0xcf011520
a00fffc8:  d2 02 00 00  ld  [ %o0 ], %o1
a00fffcc:  82 12 60 30  or  %o1, 0x30, %g1
a00fffd0:  c2 22 00 00  st  %g1, [ %o0 ]
a00fffd4:  30 80 00 d0  b,a   0xa0100314
a00fffd8:  19 33 c0 45  sethi  %hi(0xcf011400), %o4
a00fffdc:  9a 13 20 e8  or  %o4, 0xe8, %o5	! 0xcf0114e8
a00fffe0:  c2 03 40 00  ld  [ %o5 ], %g1
a00fffe4:  92 10 60 c0  or  %g1, 0xc0, %o1
a00fffe8:  d2 23 40 00  st  %o1, [ %o5 ]
a00fffec:  30 80 00 ca  b,a   0xa0100314
a00ffff0:  11 33 c0 45  sethi  %hi(0xcf011400), %o0
a00ffff4:  9a 12 21 4c  or  %o0, 0x14c, %o5	! 0xcf01154c
a00ffff8:  d4 03 40 00  ld  [ %o5 ], %o2
a00ffffc:  98 12 a0 03  or  %o2, 3, %o4
a0100000:  d8 23 40 00  st  %o4, [ %o5 ]
a0100004:  30 80 00 c4  b,a   0xa0100314
a0100008:  11 33 c0 45  sethi  %hi(0xcf011400), %o0
a010000c:  92 12 21 30  or  %o0, 0x130, %o1	! 0xcf011530
a0100010:  c2 02 40 00  ld  [ %o1 ], %g1
a0100014:  94 08 7f fc  and  %g1, -4, %o2
a0100018:  98 12 a0 01  or  %o2, 1, %o4
a010001c:  d8 22 40 00  st  %o4, [ %o1 ]
a0100020:  30 80 00 bd  b,a   0xa0100314
a0100024:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a0100028:  90 13 61 18  or  %o5, 0x118, %o0	! 0xcf011518
a010002c:  d8 02 00 00  ld  [ %o0 ], %o4
a0100030:  82 0b 3f cf  and  %o4, -49, %g1
a0100034:  92 10 60 10  or  %g1, 0x10, %o1
a0100038:  d2 22 00 00  st  %o1, [ %o0 ]
a010003c:  30 80 00 b6  b,a   0xa0100314
a0100040:  13 33 c0 45  sethi  %hi(0xcf011400), %o1
a0100044:  98 12 61 54  or  %o1, 0x154, %o4	! 0xcf011554
a0100048:  c2 03 00 00  ld  [ %o4 ], %g1
a010004c:  90 08 7f cf  and  %g1, -49, %o0
a0100050:  94 12 20 10  or  %o0, 0x10, %o2
a0100054:  d4 23 00 00  st  %o2, [ %o4 ]
a0100058:  30 80 00 af  b,a   0xa0100314
a010005c:  11 33 c0 45  sethi  %hi(0xcf011400), %o0
a0100060:  9a 12 21 54  or  %o0, 0x154, %o5	! 0xcf011554
a0100064:  d4 03 40 00  ld  [ %o5 ], %o2
a0100068:  98 12 a0 30  or  %o2, 0x30, %o4
a010006c:  d8 23 40 00  st  %o4, [ %o5 ]
a0100070:  30 80 00 a9  b,a   0xa0100314
a0100074:  19 33 c0 45  sethi  %hi(0xcf011400), %o4
a0100078:  94 13 20 e8  or  %o4, 0xe8, %o2	! 0xcf0114e8
a010007c:  d2 02 80 00  ld  [ %o2 ], %o1
a0100080:  90 0a 7f f3  and  %o1, -13, %o0
a0100084:  82 12 20 04  or  %o0, 4, %g1
a0100088:  c2 22 80 00  st  %g1, [ %o2 ]
a010008c:  30 80 00 a2  b,a   0xa0100314
a0100090:  19 33 c0 45  sethi  %hi(0xcf011400), %o4
a0100094:  94 13 21 54  or  %o4, 0x154, %o2	! 0xcf011554
a0100098:  c2 02 80 00  ld  [ %o2 ], %g1
a010009c:  92 08 7f f3  and  %g1, -13, %o1
a01000a0:  90 12 60 04  or  %o1, 4, %o0
a01000a4:  d0 22 80 00  st  %o0, [ %o2 ]
a01000a8:  30 80 00 9b  b,a   0xa0100314
a01000ac:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a01000b0:  92 13 60 e0  or  %o5, 0xe0, %o1	! 0xcf0114e0
a01000b4:  d4 02 40 00  ld  [ %o1 ], %o2
a01000b8:  82 0a bf f3  and  %o2, -13, %g1
a01000bc:  98 10 60 04  or  %g1, 4, %o4
a01000c0:  d8 22 40 00  st  %o4, [ %o1 ]
a01000c4:  30 80 00 94  b,a   0xa0100314
a01000c8:  19 33 c0 45  sethi  %hi(0xcf011400), %o4
a01000cc:  94 13 21 18  or  %o4, 0x118, %o2	! 0xcf011518
a01000d0:  c2 02 80 00  ld  [ %o2 ], %g1
a01000d4:  92 08 7f cf  and  %g1, -49, %o1
a01000d8:  90 12 60 20  or  %o1, 0x20, %o0
a01000dc:  d0 22 80 00  st  %o0, [ %o2 ]
a01000e0:  30 80 00 8d  b,a   0xa0100314
a01000e4:  15 33 c0 45  sethi  %hi(0xcf011400), %o2
a01000e8:  90 12 a1 28  or  %o2, 0x128, %o0	! 0xcf011528
a01000ec:  d8 02 00 00  ld  [ %o0 ], %o4
a01000f0:  92 13 20 0c  or  %o4, 0xc, %o1
a01000f4:  d2 22 00 00  st  %o1, [ %o0 ]
a01000f8:  30 80 00 87  b,a   0xa0100314
a01000fc:  15 33 c0 45  sethi  %hi(0xcf011400), %o2
a0100100:  90 12 a1 18  or  %o2, 0x118, %o0	! 0xcf011518
a0100104:  c2 02 00 00  ld  [ %o0 ], %g1
a0100108:  98 08 7f f3  and  %g1, -13, %o4
a010010c:  92 13 20 04  or  %o4, 4, %o1
a0100110:  d2 22 00 00  st  %o1, [ %o0 ]
a0100114:  30 80 00 80  b,a   0xa0100314
a0100118:  15 33 c0 45  sethi  %hi(0xcf011400), %o2
a010011c:  9a 12 a0 e8  or  %o2, 0xe8, %o5	! 0xcf0114e8
a0100120:  c2 03 40 00  ld  [ %o5 ], %g1
a0100124:  98 10 60 30  or  %g1, 0x30, %o4
a0100128:  d8 23 40 00  st  %o4, [ %o5 ]
a010012c:  30 80 00 7a  b,a   0xa0100314
a0100130:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a0100134:  98 13 61 18  or  %o5, 0x118, %o4	! 0xcf011518
a0100138:  d0 03 00 00  ld  [ %o4 ], %o0
a010013c:  94 12 20 c0  or  %o0, 0xc0, %o2
a0100140:  d4 23 00 00  st  %o2, [ %o4 ]
a0100144:  30 80 00 74  b,a   0xa0100314
a0100148:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a010014c:  98 13 62 b0  or  %o5, 0x2b0, %o4	! 0xcf0116b0
a0100150:  d0 03 00 00  ld  [ %o4 ], %o0
a0100154:  82 0a 3f f3  and  %o0, -13, %g1
a0100158:  94 10 60 04  or  %g1, 4, %o2
a010015c:  d4 23 00 00  st  %o2, [ %o4 ]
a0100160:  30 80 00 6d  b,a   0xa0100314
a0100164:  11 33 c0 45  sethi  %hi(0xcf011400), %o0
a0100168:  92 12 22 b0  or  %o0, 0x2b0, %o1	! 0xcf0116b0
a010016c:  c2 02 40 00  ld  [ %o1 ], %g1
a0100170:  94 08 7f f3  and  %g1, -13, %o2
a0100174:  98 12 a0 08  or  %o2, 8, %o4
a0100178:  d8 22 40 00  st  %o4, [ %o1 ]
a010017c:  30 80 00 66  b,a   0xa0100314
a0100180:  15 33 c0 45  sethi  %hi(0xcf011400), %o2
a0100184:  90 12 a1 54  or  %o2, 0x154, %o0	! 0xcf011554
a0100188:  c2 02 00 00  ld  [ %o0 ], %g1
a010018c:  98 08 7f fc  and  %g1, -4, %o4
a0100190:  92 13 20 01  or  %o4, 1, %o1
a0100194:  d2 22 00 00  st  %o1, [ %o0 ]
a0100198:  30 80 00 5f  b,a   0xa0100314
a010019c:  13 33 c0 45  sethi  %hi(0xcf011400), %o1
a01001a0:  98 12 62 b0  or  %o1, 0x2b0, %o4	! 0xcf0116b0
a01001a4:  c2 03 00 00  ld  [ %o4 ], %g1
a01001a8:  90 08 7f fc  and  %g1, -4, %o0
a01001ac:  94 12 20 01  or  %o0, 1, %o2
a01001b0:  d4 23 00 00  st  %o2, [ %o4 ]
a01001b4:  30 80 00 58  b,a   0xa0100314
a01001b8:  15 33 c0 45  sethi  %hi(0xcf011400), %o2
a01001bc:  90 12 a0 e8  or  %o2, 0xe8, %o0	! 0xcf0114e8
a01001c0:  d8 02 00 00  ld  [ %o0 ], %o4
a01001c4:  92 0b 3f fc  and  %o4, -4, %o1
a01001c8:  82 12 60 01  or  %o1, 1, %g1
a01001cc:  c2 22 00 00  st  %g1, [ %o0 ]
a01001d0:  30 80 00 51  b,a   0xa0100314
a01001d4:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a01001d8:  98 13 61 28  or  %o5, 0x128, %o4	! 0xcf011528
a01001dc:  c2 03 00 00  ld  [ %o4 ], %g1
a01001e0:  94 10 60 03  or  %g1, 3, %o2
a01001e4:  d4 23 00 00  st  %o2, [ %o4 ]
a01001e8:  30 80 00 4b  b,a   0xa0100314
a01001ec:  13 33 c0 45  sethi  %hi(0xcf011400), %o1
a01001f0:  9a 12 61 18  or  %o1, 0x118, %o5	! 0xcf011518
a01001f4:  d0 03 40 00  ld  [ %o5 ], %o0
a01001f8:  94 12 20 30  or  %o0, 0x30, %o2
a01001fc:  d4 23 40 00  st  %o2, [ %o5 ]
a0100200:  30 80 00 45  b,a   0xa0100314
a0100204:  11 33 c0 45  sethi  %hi(0xcf011400), %o0
a0100208:  92 12 21 18  or  %o0, 0x118, %o1	! 0xcf011518
a010020c:  c2 02 40 00  ld  [ %o1 ], %g1
a0100210:  94 08 7f fc  and  %g1, -4, %o2
a0100214:  98 12 a0 01  or  %o2, 1, %o4
a0100218:  d8 22 40 00  st  %o4, [ %o1 ]
a010021c:  30 80 00 3e  b,a   0xa0100314
a0100220:  19 33 c0 45  sethi  %hi(0xcf011400), %o4
a0100224:  9a 13 21 18  or  %o4, 0x118, %o5	! 0xcf011518
a0100228:  d2 03 40 00  ld  [ %o5 ], %o1
a010022c:  90 12 60 0c  or  %o1, 0xc, %o0
a0100230:  d0 23 40 00  st  %o0, [ %o5 ]
a0100234:  30 80 00 38  b,a   0xa0100314
a0100238:  11 33 c0 45  sethi  %hi(0xcf011400), %o0
a010023c:  9a 12 20 e8  or  %o0, 0xe8, %o5	! 0xcf0114e8
a0100240:  c2 03 40 00  ld  [ %o5 ], %g1
a0100244:  94 10 60 0c  or  %g1, 0xc, %o2
a0100248:  d4 23 40 00  st  %o2, [ %o5 ]
a010024c:  30 80 00 32  b,a   0xa0100314
a0100250:  13 33 c0 45  sethi  %hi(0xcf011400), %o1
a0100254:  9a 12 61 54  or  %o1, 0x154, %o5	! 0xcf011554
a0100258:  d0 03 40 00  ld  [ %o5 ], %o0
a010025c:  94 12 20 0c  or  %o0, 0xc, %o2
a0100260:  d4 23 40 00  st  %o2, [ %o5 ]
a0100264:  30 80 00 2c  b,a   0xa0100314
a0100268:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a010026c:  94 13 60 e0  or  %o5, 0xe0, %o2	! 0xcf0114e0
a0100270:  d8 02 80 00  ld  [ %o2 ], %o4
a0100274:  92 0b 3f fc  and  %o4, -4, %o1
a0100278:  90 12 60 01  or  %o1, 1, %o0
a010027c:  d0 22 80 00  st  %o0, [ %o2 ]
a0100280:  30 80 00 25  b,a   0xa0100314
a0100284:  13 33 c0 45  sethi  %hi(0xcf011400), %o1
a0100288:  9a 12 60 e8  or  %o1, 0xe8, %o5	! 0xcf0114e8
a010028c:  c2 03 40 00  ld  [ %o5 ], %g1
a0100290:  90 10 60 03  or  %g1, 3, %o0
a0100294:  d0 23 40 00  st  %o0, [ %o5 ]
a0100298:  30 80 00 1f  b,a   0xa0100314
a010029c:  19 33 c0 45  sethi  %hi(0xcf011400), %o4
a01002a0:  9a 13 21 54  or  %o4, 0x154, %o5	! 0xcf011554
a01002a4:  d2 03 40 00  ld  [ %o5 ], %o1
a01002a8:  90 12 60 03  or  %o1, 3, %o0
a01002ac:  d0 23 40 00  st  %o0, [ %o5 ]
a01002b0:  30 80 00 19  b,a   0xa0100314
a01002b4:  15 33 c0 45  sethi  %hi(0xcf011400), %o2
a01002b8:  9a 12 a2 b0  or  %o2, 0x2b0, %o5	! 0xcf0116b0
a01002bc:  d8 03 40 00  ld  [ %o5 ], %o4
a01002c0:  92 13 20 0c  or  %o4, 0xc, %o1
a01002c4:  d2 23 40 00  st  %o1, [ %o5 ]
a01002c8:  30 80 00 13  b,a   0xa0100314
a01002cc:  15 33 c0 45  sethi  %hi(0xcf011400), %o2
a01002d0:  9a 12 a1 18  or  %o2, 0x118, %o5	! 0xcf011518
a01002d4:  d8 03 40 00  ld  [ %o5 ], %o4
a01002d8:  92 13 20 03  or  %o4, 3, %o1
a01002dc:  d2 23 40 00  st  %o1, [ %o5 ]
a01002e0:  30 80 00 0d  b,a   0xa0100314
a01002e4:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a01002e8:  9a 10 62 b0  or  %g1, 0x2b0, %o5	! 0xcf0116b0
a01002ec:  d0 03 40 00  ld  [ %o5 ], %o0
a01002f0:  94 0a 3f fc  and  %o0, -4, %o2
a01002f4:  98 12 a0 02  or  %o2, 2, %o4
a01002f8:  d8 23 40 00  st  %o4, [ %o5 ]
a01002fc:  30 80 00 06  b,a   0xa0100314
a0100300:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a0100304:  92 13 62 b0  or  %o5, 0x2b0, %o1	! 0xcf0116b0
a0100308:  d4 02 40 00  ld  [ %o1 ], %o2
a010030c:  98 12 a0 03  or  %o2, 3, %o4
a0100310:  d8 22 40 00  st  %o4, [ %o1 ]
a0100314:  81 c3 e0 08  retl
a0100318:  01 00 00 00  nop
