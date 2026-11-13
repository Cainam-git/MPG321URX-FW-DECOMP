# leon2m FUN_a002c86c 0xa002c86c-0xa002cb30 (708 bytes)
a002c86c:  80 8a a0 01  btst  1, %o2
a002c870:  12 80 00 14  bne  0xa002c8c0
a002c874:  82 0a 20 ff  and  %o0, 0xff, %g1
a002c878:  80 a0 60 11  cmp  %g1, 0x11
a002c87c:  18 80 00 ab  bgu  0xa002cb28
a002c880:  15 28 00 b1  sethi  %hi(0xa002c400), %o2
a002c884:  83 28 60 02  sll  %g1, 2, %g1
a002c888:  9a 12 a3 4c  or  %o2, 0x34c, %o5
a002c88c:  d6 03 40 01  ld  [ %o5 + %g1 ], %o3
a002c890:  81 c2 c0 00  jmp  %o3
a002c894:  01 00 00 00  nop
a002c898:  03 33 c0 f0  sethi  %hi(0xcf03c000), %g1
a002c89c:  96 10 60 48  or  %g1, 0x48, %o3	! 0xcf03c048
a002c8a0:  82 10 60 4c  or  %g1, 0x4c, %g1
a002c8a4:  d0 02 c0 00  ld  [ %o3 ], %o0
a002c8a8:  d8 00 40 00  ld  [ %g1 ], %o4
a002c8ac:  9a 12 00 0c  or  %o0, %o4, %o5
a002c8b0:  94 0a 60 ff  and  %o1, 0xff, %o2
a002c8b4:  92 13 40 0a  or  %o5, %o2, %o1
a002c8b8:  d2 22 c0 00  st  %o1, [ %o3 ]
a002c8bc:  30 80 00 9b  b,a   0xa002cb28
a002c8c0:  80 a0 60 11  cmp  %g1, 0x11
a002c8c4:  18 80 00 99  bgu  0xa002cb28
a002c8c8:  11 28 00 b1  sethi  %hi(0xa002c400), %o0
a002c8cc:  83 28 60 02  sll  %g1, 2, %g1
a002c8d0:  9a 12 23 04  or  %o0, 0x304, %o5
a002c8d4:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a002c8d8:  81 c3 00 00  jmp  %o4
a002c8dc:  01 00 00 00  nop
a002c8e0:  03 33 c0 f3  sethi  %hi(0xcf03cc00), %g1
a002c8e4:  96 10 60 0c  or  %g1, 0xc, %o3	! 0xcf03cc0c
a002c8e8:  82 10 60 4c  or  %g1, 0x4c, %g1
a002c8ec:  da 02 c0 00  ld  [ %o3 ], %o5
a002c8f0:  d8 00 40 00  ld  [ %g1 ], %o4
a002c8f4:  90 13 40 0c  or  %o5, %o4, %o0
a002c8f8:  94 0a 60 ff  and  %o1, 0xff, %o2
a002c8fc:  82 2a 00 0a  andn  %o0, %o2, %g1
a002c900:  c2 22 c0 00  st  %g1, [ %o3 ]
a002c904:  30 80 00 89  b,a   0xa002cb28
a002c908:  17 33 c0 f0  sethi  %hi(0xcf03c000), %o3
a002c90c:  d8 02 c0 00  ld  [ %o3 ], %o4
a002c910:  82 12 e0 14  or  %o3, 0x14, %g1
a002c914:  da 00 40 00  ld  [ %g1 ], %o5
a002c918:  98 13 00 0d  or  %o4, %o5, %o4
a002c91c:  90 0a 60 ff  and  %o1, 0xff, %o0
a002c920:  82 2b 00 08  andn  %o4, %o0, %g1
a002c924:  c2 22 c0 00  st  %g1, [ %o3 ]
a002c928:  30 80 00 80  b,a   0xa002cb28
a002c92c:  11 33 c0 f0  sethi  %hi(0xcf03c000), %o0
a002c930:  96 12 20 04  or  %o0, 4, %o3	! 0xcf03c004
a002c934:  10 bf ff ee  b  0xa002c8ec
a002c938:  82 12 20 18  or  %o0, 0x18, %g1
a002c93c:  19 33 c0 f0  sethi  %hi(0xcf03c000), %o4
a002c940:  96 13 20 08  or  %o4, 8, %o3	! 0xcf03c008
a002c944:  10 bf ff ea  b  0xa002c8ec
a002c948:  82 13 20 1c  or  %o4, 0x1c, %g1
a002c94c:  03 33 c0 f0  sethi  %hi(0xcf03c000), %g1
a002c950:  96 10 60 0c  or  %g1, 0xc, %o3	! 0xcf03c00c
a002c954:  10 bf ff e6  b  0xa002c8ec
a002c958:  82 10 60 20  or  %g1, 0x20, %g1
a002c95c:  1b 33 c0 f0  sethi  %hi(0xcf03c000), %o5
a002c960:  96 13 60 10  or  %o5, 0x10, %o3	! 0xcf03c010
a002c964:  10 bf ff e2  b  0xa002c8ec
a002c968:  82 13 60 24  or  %o5, 0x24, %g1
a002c96c:  03 33 c0 f0  sethi  %hi(0xcf03c000), %g1
a002c970:  96 10 60 40  or  %g1, 0x40, %o3	! 0xcf03c040
a002c974:  10 bf ff de  b  0xa002c8ec
a002c978:  82 10 60 44  or  %g1, 0x44, %g1
a002c97c:  03 33 c0 f0  sethi  %hi(0xcf03c000), %g1
a002c980:  10 bf ff da  b  0xa002c8e8
a002c984:  96 10 60 48  or  %g1, 0x48, %o3	! 0xcf03c048
a002c988:  15 33 c0 f1  sethi  %hi(0xcf03c400), %o2
a002c98c:  96 12 a0 50  or  %o2, 0x50, %o3	! 0xcf03c450
a002c990:  10 bf ff d7  b  0xa002c8ec
a002c994:  82 12 a0 54  or  %o2, 0x54, %g1
a002c998:  11 33 c0 f1  sethi  %hi(0xcf03c400), %o0
a002c99c:  96 12 20 58  or  %o0, 0x58, %o3	! 0xcf03c458
a002c9a0:  10 bf ff d3  b  0xa002c8ec
a002c9a4:  82 12 20 5c  or  %o0, 0x5c, %g1
a002c9a8:  19 33 c0 f1  sethi  %hi(0xcf03c400), %o4
a002c9ac:  96 13 20 60  or  %o4, 0x60, %o3	! 0xcf03c460
a002c9b0:  10 bf ff cf  b  0xa002c8ec
a002c9b4:  82 13 20 64  or  %o4, 0x64, %g1
a002c9b8:  03 33 c0 f1  sethi  %hi(0xcf03c400), %g1
a002c9bc:  96 10 60 68  or  %g1, 0x68, %o3	! 0xcf03c468
a002c9c0:  10 bf ff cb  b  0xa002c8ec
a002c9c4:  82 10 60 6c  or  %g1, 0x6c, %g1
a002c9c8:  1b 33 c0 f1  sethi  %hi(0xcf03c400), %o5
a002c9cc:  96 13 60 70  or  %o5, 0x70, %o3	! 0xcf03c470
a002c9d0:  10 bf ff c7  b  0xa002c8ec
a002c9d4:  82 13 60 74  or  %o5, 0x74, %g1
a002c9d8:  15 33 c0 f1  sethi  %hi(0xcf03c400), %o2
a002c9dc:  96 12 a0 78  or  %o2, 0x78, %o3	! 0xcf03c478
a002c9e0:  10 bf ff c3  b  0xa002c8ec
a002c9e4:  82 12 a0 7c  or  %o2, 0x7c, %g1
a002c9e8:  17 33 c0 f3  sethi  %hi(0xcf03cc00), %o3
a002c9ec:  d8 02 c0 00  ld  [ %o3 ], %o4
a002c9f0:  10 bf ff c9  b  0xa002c914
a002c9f4:  82 12 e0 40  or  %o3, 0x40, %g1
a002c9f8:  03 33 c0 f3  sethi  %hi(0xcf03cc00), %g1
a002c9fc:  96 10 60 04  or  %g1, 4, %o3	! 0xcf03cc04
a002ca00:  10 bf ff bb  b  0xa002c8ec
a002ca04:  82 10 60 44  or  %g1, 0x44, %g1
a002ca08:  03 33 c0 f3  sethi  %hi(0xcf03cc00), %g1
a002ca0c:  96 10 60 08  or  %g1, 8, %o3	! 0xcf03cc08
a002ca10:  10 bf ff b7  b  0xa002c8ec
a002ca14:  82 10 60 48  or  %g1, 0x48, %g1
a002ca18:  03 33 c0 f3  sethi  %hi(0xcf03cc00), %g1
a002ca1c:  10 bf ff a1  b  0xa002c8a0
a002ca20:  96 10 60 0c  or  %g1, 0xc, %o3	! 0xcf03cc0c
a002ca24:  03 33 c0 f3  sethi  %hi(0xcf03cc00), %g1
a002ca28:  96 10 60 08  or  %g1, 8, %o3	! 0xcf03cc08
a002ca2c:  10 bf ff 9e  b  0xa002c8a4
a002ca30:  82 10 60 48  or  %g1, 0x48, %g1
a002ca34:  03 33 c0 f3  sethi  %hi(0xcf03cc00), %g1
a002ca38:  96 10 60 04  or  %g1, 4, %o3	! 0xcf03cc04
a002ca3c:  10 bf ff 9a  b  0xa002c8a4
a002ca40:  82 10 60 44  or  %g1, 0x44, %g1
a002ca44:  17 33 c0 f3  sethi  %hi(0xcf03cc00), %o3
a002ca48:  c2 02 c0 00  ld  [ %o3 ], %g1
a002ca4c:  9a 12 e0 40  or  %o3, 0x40, %o5
a002ca50:  d0 03 40 00  ld  [ %o5 ], %o0
a002ca54:  94 10 40 08  or  %g1, %o0, %o2
a002ca58:  98 0a 60 ff  and  %o1, 0xff, %o4
a002ca5c:  82 12 80 0c  or  %o2, %o4, %g1
a002ca60:  c2 22 c0 00  st  %g1, [ %o3 ]
a002ca64:  30 80 00 31  b,a   0xa002cb28
a002ca68:  11 33 c0 f1  sethi  %hi(0xcf03c400), %o0
a002ca6c:  96 12 20 78  or  %o0, 0x78, %o3	! 0xcf03c478
a002ca70:  10 bf ff 8d  b  0xa002c8a4
a002ca74:  82 12 20 7c  or  %o0, 0x7c, %g1
a002ca78:  1b 33 c0 f1  sethi  %hi(0xcf03c400), %o5
a002ca7c:  96 13 60 70  or  %o5, 0x70, %o3	! 0xcf03c470
a002ca80:  10 bf ff 89  b  0xa002c8a4
a002ca84:  82 13 60 74  or  %o5, 0x74, %g1
a002ca88:  03 33 c0 f1  sethi  %hi(0xcf03c400), %g1
a002ca8c:  96 10 60 68  or  %g1, 0x68, %o3	! 0xcf03c468
a002ca90:  10 bf ff 85  b  0xa002c8a4
a002ca94:  82 10 60 6c  or  %g1, 0x6c, %g1
a002ca98:  19 33 c0 f1  sethi  %hi(0xcf03c400), %o4
a002ca9c:  96 13 20 60  or  %o4, 0x60, %o3	! 0xcf03c460
a002caa0:  10 bf ff 81  b  0xa002c8a4
a002caa4:  82 13 20 64  or  %o4, 0x64, %g1
a002caa8:  15 33 c0 f1  sethi  %hi(0xcf03c400), %o2
a002caac:  96 12 a0 58  or  %o2, 0x58, %o3	! 0xcf03c458
a002cab0:  10 bf ff 7d  b  0xa002c8a4
a002cab4:  82 12 a0 5c  or  %o2, 0x5c, %g1
a002cab8:  11 33 c0 f1  sethi  %hi(0xcf03c400), %o0
a002cabc:  96 12 20 50  or  %o0, 0x50, %o3	! 0xcf03c450
a002cac0:  10 bf ff 79  b  0xa002c8a4
a002cac4:  82 12 20 54  or  %o0, 0x54, %g1
a002cac8:  03 33 c0 f0  sethi  %hi(0xcf03c000), %g1
a002cacc:  96 10 60 40  or  %g1, 0x40, %o3	! 0xcf03c040
a002cad0:  10 bf ff 75  b  0xa002c8a4
a002cad4:  82 10 60 44  or  %g1, 0x44, %g1
a002cad8:  1b 33 c0 f0  sethi  %hi(0xcf03c000), %o5
a002cadc:  96 13 60 10  or  %o5, 0x10, %o3	! 0xcf03c010
a002cae0:  10 bf ff 71  b  0xa002c8a4
a002cae4:  82 13 60 24  or  %o5, 0x24, %g1
a002cae8:  03 33 c0 f0  sethi  %hi(0xcf03c000), %g1
a002caec:  96 10 60 0c  or  %g1, 0xc, %o3	! 0xcf03c00c
a002caf0:  10 bf ff 6d  b  0xa002c8a4
a002caf4:  82 10 60 20  or  %g1, 0x20, %g1
a002caf8:  19 33 c0 f0  sethi  %hi(0xcf03c000), %o4
a002cafc:  96 13 20 08  or  %o4, 8, %o3	! 0xcf03c008
a002cb00:  10 bf ff 69  b  0xa002c8a4
a002cb04:  82 13 20 1c  or  %o4, 0x1c, %g1
a002cb08:  15 33 c0 f0  sethi  %hi(0xcf03c000), %o2
a002cb0c:  96 12 a0 04  or  %o2, 4, %o3	! 0xcf03c004
a002cb10:  10 bf ff 65  b  0xa002c8a4
a002cb14:  82 12 a0 18  or  %o2, 0x18, %g1
a002cb18:  17 33 c0 f0  sethi  %hi(0xcf03c000), %o3
a002cb1c:  c2 02 c0 00  ld  [ %o3 ], %g1
a002cb20:  10 bf ff cc  b  0xa002ca50
a002cb24:  9a 12 e0 14  or  %o3, 0x14, %o5
a002cb28:  81 c3 e0 08  retl
a002cb2c:  01 00 00 00  nop
