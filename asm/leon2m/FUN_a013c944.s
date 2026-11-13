# leon2m FUN_a013c944 0xa013c944-0xa013cd4c (1032 bytes)  [FUN_a013cd44 = unreachable ret/restore tail, merged]
a013c944:  9d e3 bf 98  save  %sp, -104, %sp
a013c948:  13 2a 00 b7  sethi  %hi(0xa802dc00), %o1
a013c94c:  96 12 63 30  or  %o1, 0x330, %o3	! 0xa802df30
a013c950:  15 03 ff ff  sethi  %hi(0xffffc00), %o2
a013c954:  f4 02 63 30  ld  [ %o1 + 0x330 ], %i2
a013c958:  f6 02 e0 70  ld  [ %o3 + 0x70 ], %i3
a013c95c:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a013c960:  33 00 40 00  sethi  %hi(0x1000000), %i1
a013c964:  ba 0e 80 0a  and  %i2, %o2, %i5
a013c968:  b0 16 c0 19  or  %i3, %i1, %i0
a013c96c:  03 14 00 00  sethi  %hi(0x50000000), %g1
a013c970:  39 10 00 00  sethi  %hi(0x40000000), %i4
a013c974:  19 3c 3f ff  sethi  %hi(0xf0fffc00), %o4
a013c978:  b4 17 40 01  or  %i5, %g1, %i2
a013c97c:  b6 16 00 1c  or  %i0, %i4, %i3
a013c980:  98 13 23 ff  or  %o4, 0x3ff, %o4
a013c984:  b2 0e 80 0c  and  %i2, %o4, %i1
a013c988:  03 01 40 00  sethi  %hi(0x5000000), %g1
a013c98c:  39 00 04 00  sethi  %hi(0x100000), %i4
a013c990:  31 3f c3 ff  sethi  %hi(0xff0ffc00), %i0
a013c994:  1b 3f ff 7f  sethi  %hi(0xfffdfc00), %o5
a013c998:  ba 16 40 01  or  %i1, %g1, %i5
a013c99c:  b4 16 c0 1c  or  %i3, %i4, %i2
a013c9a0:  b0 16 23 ff  or  %i0, 0x3ff, %i0
a013c9a4:  9a 13 63 ff  or  %o5, 0x3ff, %o5
a013c9a8:  1f 3f ff bf  sethi  %hi(0xfffefc00), %o7
a013c9ac:  82 0f 40 18  and  %i5, %i0, %g1
a013c9b0:  b8 0e 80 0d  and  %i2, %o5, %i4
a013c9b4:  9e 13 e3 ff  or  %o7, 0x3ff, %o7
a013c9b8:  ba 08 7f 01  and  %g1, -255, %i5
a013c9bc:  b6 0f 00 0f  and  %i4, %o7, %i3
a013c9c0:  33 3f ff c3  sethi  %hi(0xffff0c00), %i1
a013c9c4:  35 00 00 cc  sethi  %hi(0x33000), %i2
a013c9c8:  b4 2e c0 1a  andn  %i3, %i2, %i2
a013c9cc:  b2 16 63 ff  or  %i1, 0x3ff, %i1
a013c9d0:  03 3f fc 3f  sethi  %hi(0xfff0fc00), %g1
a013c9d4:  b8 10 63 ff  or  %g1, 0x3ff, %i4	! 0xfff0ffff
a013c9d8:  b6 0f 40 19  and  %i5, %i1, %i3
a013c9dc:  ba 0e c0 1c  and  %i3, %i4, %i5
a013c9e0:  03 00 00 04  sethi  %hi(0x1000), %g1
a013c9e4:  fa 22 63 30  st  %i5, [ %o1 + 0x330 ]
a013c9e8:  b6 16 80 01  or  %i2, %g1, %i3
a013c9ec:  b8 10 21 f4  mov  0x1f4, %i4
a013c9f0:  a6 10 00 0a  mov  %o2, %l3
a013c9f4:  a2 10 00 0c  mov  %o4, %l1
a013c9f8:  35 3f bf ff  sethi  %hi(0xfefffc00), %i2
a013c9fc:  3b 00 06 95  sethi  %hi(0x1a5400), %i5
a013ca00:  90 10 00 18  mov  %i0, %o0
a013ca04:  03 3f fb ff  sethi  %hi(0xffeffc00), %g1
a013ca08:  f8 32 e0 74  sth  %i4, [ %o3 + 0x74 ]
a013ca0c:  f6 22 e0 70  st  %i3, [ %o3 + 0x70 ]
a013ca10:  a4 16 a3 ff  or  %i2, 0x3ff, %l2
a013ca14:  94 17 63 c0  or  %i5, 0x3c0, %o2
a013ca18:  98 10 00 19  mov  %i1, %o4
a013ca1c:  a0 10 63 ff  or  %g1, 0x3ff, %l0
a013ca20:  b0 10 20 01  mov  1, %i0
a013ca24:  10 80 00 26  b  0xa013cabc
a013ca28:  92 10 20 01  mov  1, %o1
a013ca2c:  c2 26 a0 70  st  %g1, [ %i2 + 0x70 ]
a013ca30:  f8 02 c0 1b  ld  [ %o3 + %i3 ], %i4
a013ca34:  ba 0f 3f f1  and  %i4, -15, %i5
a013ca38:  b2 17 60 04  or  %i5, 4, %i1
a013ca3c:  80 a2 60 02  cmp  %o1, 2
a013ca40:  02 80 00 48  be  0xa013cb60
a013ca44:  f2 22 c0 1b  st  %i1, [ %o3 + %i3 ]
a013ca48:  80 a2 60 03  cmp  %o1, 3
a013ca4c:  22 80 00 ac  be,a   0xa013ccfc
a013ca50:  c2 0a a0 03  ldub  [ %o2 + 3 ], %g1
a013ca54:  b7 2a 60 04  sll  %o1, 4, %i3
a013ca58:  b8 26 c0 09  sub  %i3, %o1, %i4
a013ca5c:  b7 2f 20 03  sll  %i4, 3, %i3
a013ca60:  c2 0a 80 09  ldub  [ %o2 + %o1 ], %g1
a013ca64:  b2 08 60 0f  and  %g1, 0xf, %i1
a013ca68:  f4 02 c0 1b  ld  [ %o3 + %i3 ], %i2
a013ca6c:  82 0e 80 0c  and  %i2, %o4, %g1
a013ca70:  bb 2e 60 0c  sll  %i1, 0xc, %i5
a013ca74:  b2 10 40 1d  or  %g1, %i5, %i1
a013ca78:  b4 0e 7f 0f  and  %i1, -241, %i2
a013ca7c:  82 16 a0 10  or  %i2, 0x10, %g1
a013ca80:  c2 22 c0 1b  st  %g1, [ %o3 + %i3 ]
a013ca84:  b5 2a 60 04  sll  %o1, 4, %i2
a013ca88:  b8 26 80 09  sub  %i2, %o1, %i4
a013ca8c:  b9 2f 20 03  sll  %i4, 3, %i4
a013ca90:  f6 02 c0 1c  ld  [ %o3 + %i4 ], %i3
a013ca94:  b2 0a 60 0f  and  %o1, 0xf, %i1
a013ca98:  03 00 03 c0  sethi  %hi(0xf0000), %g1
a013ca9c:  b4 2e c0 01  andn  %i3, %g1, %i2
a013caa0:  bb 2e 60 10  sll  %i1, 0x10, %i5
a013caa4:  b0 06 20 01  inc  %i0
a013caa8:  b6 16 80 1d  or  %i2, %i5, %i3
a013caac:  92 0e 20 ff  and  %i0, 0xff, %o1
a013cab0:  80 a2 60 03  cmp  %o1, 3
a013cab4:  18 80 00 42  bgu  0xa013cbbc
a013cab8:  f6 22 c0 1c  st  %i3, [ %o3 + %i4 ]
a013cabc:  b7 2a 60 04  sll  %o1, 4, %i3
a013cac0:  82 26 c0 09  sub  %i3, %o1, %g1
a013cac4:  b7 28 60 03  sll  %g1, 3, %i3
a013cac8:  f8 02 c0 1b  ld  [ %o3 + %i3 ], %i4
a013cacc:  b2 0f 00 13  and  %i4, %l3, %i1
a013cad0:  b4 0e 40 11  and  %i1, %l1, %i2
a013cad4:  f4 22 c0 1b  st  %i2, [ %o3 + %i3 ]
a013cad8:  b4 06 c0 0b  add  %i3, %o3, %i2
a013cadc:  fa 06 a0 70  ld  [ %i2 + 0x70 ], %i5
a013cae0:  82 0f 40 12  and  %i5, %l2, %g1
a013cae4:  c2 26 a0 70  st  %g1, [ %i2 + 0x70 ]
a013cae8:  f8 02 c0 1b  ld  [ %o3 + %i3 ], %i4
a013caec:  b2 0f 00 08  and  %i4, %o0, %i1
a013caf0:  f2 22 c0 1b  st  %i1, [ %o3 + %i3 ]
a013caf4:  c2 06 a0 70  ld  [ %i2 + 0x70 ], %g1
a013caf8:  3b 00 20 00  sethi  %hi(0x800000), %i5
a013cafc:  b8 10 40 1d  or  %g1, %i5, %i4
a013cb00:  b2 0f 00 10  and  %i4, %l0, %i1
a013cb04:  ba 0e 40 0d  and  %i1, %o5, %i5
a013cb08:  82 0f 40 0f  and  %i5, %o7, %g1
a013cb0c:  39 00 04 cc  sethi  %hi(0x133000), %i4
a013cb10:  b8 28 40 1c  andn  %g1, %i4, %i4
a013cb14:  ba 10 21 f4  mov  0x1f4, %i5
a013cb18:  03 00 00 04  sethi  %hi(0x1000), %g1
a013cb1c:  fa 36 a0 74  sth  %i5, [ %i2 + 0x74 ]
a013cb20:  b8 17 00 01  or  %i4, %g1, %i4
a013cb24:  3b 10 04 c0  sethi  %hi(0x40130000), %i5
a013cb28:  b2 02 e0 78  add  %o3, 0x78, %i1
a013cb2c:  80 a2 60 01  cmp  %o1, 1
a013cb30:  12 bf ff bf  bne  0xa013ca2c
a013cb34:  82 2f 00 1d  andn  %i4, %i5, %g1
a013cb38:  f8 26 a0 70  st  %i4, [ %i2 + 0x70 ]
a013cb3c:  f4 02 e0 78  ld  [ %o3 + 0x78 ], %i2
a013cb40:  f6 06 60 70  ld  [ %i1 + 0x70 ], %i3
a013cb44:  03 10 00 00  sethi  %hi(0x40000000), %g1
a013cb48:  b8 0e bf f1  and  %i2, -15, %i4
a013cb4c:  ba 16 c0 01  or  %i3, %g1, %i5
a013cb50:  b4 17 20 02  or  %i4, 2, %i2
a013cb54:  fa 26 60 70  st  %i5, [ %i1 + 0x70 ]
a013cb58:  10 bf ff bf  b  0xa013ca54
a013cb5c:  f4 22 e0 78  st  %i2, [ %o3 + 0x78 ]
a013cb60:  f4 0a a0 02  ldub  [ %o2 + 2 ], %i2
a013cb64:  f6 02 e0 f0  ld  [ %o3 + 0xf0 ], %i3
a013cb68:  ba 0e a0 0f  and  %i2, 0xf, %i5
a013cb6c:  b9 2f 60 0c  sll  %i5, 0xc, %i4
a013cb70:  82 0e c0 0c  and  %i3, %o4, %g1
a013cb74:  b2 10 40 1c  or  %g1, %i4, %i1
a013cb78:  b4 0e 7f 0f  and  %i1, -241, %i2
a013cb7c:  ba 16 a0 40  or  %i2, 0x40, %i5
a013cb80:  b5 2a 60 04  sll  %o1, 4, %i2
a013cb84:  b8 26 80 09  sub  %i2, %o1, %i4
a013cb88:  fa 22 e0 f0  st  %i5, [ %o3 + 0xf0 ]
a013cb8c:  b9 2f 20 03  sll  %i4, 3, %i4
a013cb90:  f6 02 c0 1c  ld  [ %o3 + %i4 ], %i3
a013cb94:  b2 0a 60 0f  and  %o1, 0xf, %i1
a013cb98:  03 00 03 c0  sethi  %hi(0xf0000), %g1
a013cb9c:  b4 2e c0 01  andn  %i3, %g1, %i2
a013cba0:  bb 2e 60 10  sll  %i1, 0x10, %i5
a013cba4:  b0 06 20 01  inc  %i0
a013cba8:  b6 16 80 1d  or  %i2, %i5, %i3
a013cbac:  92 0e 20 ff  and  %i0, 0xff, %o1
a013cbb0:  80 a2 60 03  cmp  %o1, 3
a013cbb4:  08 bf ff c2  bleu  0xa013cabc
a013cbb8:  f6 22 c0 1c  st  %i3, [ %o3 + %i4 ]
a013cbbc:  03 2a 00 b7  sethi  %hi(0xa802dc00), %g1
a013cbc0:  33 1f ff ff  sethi  %hi(0x7ffffc00), %i1
a013cbc4:  3b 37 ff ff  sethi  %hi(0xdffffc00), %i5
a013cbc8:  31 3b ff ff  sethi  %hi(0xeffffc00), %i0
a013cbcc:  96 10 63 30  or  %g1, 0x330, %o3
a013cbd0:  aa 16 63 ff  or  %i1, 0x3ff, %l5
a013cbd4:  a8 17 63 ff  or  %i5, 0x3ff, %l4
a013cbd8:  a6 16 23 ff  or  %i0, 0x3ff, %l3
a013cbdc:  35 3d ff ff  sethi  %hi(0xf7fffc00), %i2
a013cbe0:  39 3e ff ff  sethi  %hi(0xfbfffc00), %i4
a013cbe4:  37 2a 00 b8  sethi  %hi(0xa802e000), %i3
a013cbe8:  03 3f 7f ff  sethi  %hi(0xfdfffc00), %g1
a013cbec:  33 3f ff cf  sethi  %hi(0xffff3c00), %i1
a013cbf0:  3b 3f fb ff  sethi  %hi(0xffeffc00), %i5
a013cbf4:  31 3f ef ff  sethi  %hi(0xffbffc00), %i0
a013cbf8:  a4 16 a3 ff  or  %i2, 0x3ff, %l2
a013cbfc:  a2 17 23 ff  or  %i4, 0x3ff, %l1
a013cc00:  9a 16 e3 78  or  %i3, 0x378, %o5
a013cc04:  a0 10 63 ff  or  %g1, 0x3ff, %l0
a013cc08:  90 16 63 ff  or  %i1, 0x3ff, %o0
a013cc0c:  92 17 63 ff  or  %i5, 0x3ff, %o1
a013cc10:  94 16 23 ff  or  %i0, 0x3ff, %o2
a013cc14:  98 10 20 00  clr  %o4
a013cc18:  10 80 00 30  b  0xa013ccd8
a013cc1c:  9e 10 20 00  clr  %o7
a013cc20:  f0 02 c0 00  ld  [ %o3 ], %i0
a013cc24:  b4 16 20 01  or  %i0, 1, %i2
a013cc28:  f4 22 c0 00  st  %i2, [ %o3 ]
a013cc2c:  b5 2b e0 04  sll  %o7, 4, %i2
a013cc30:  b0 26 80 0f  sub  %i2, %o7, %i0
a013cc34:  bb 2e 20 03  sll  %i0, 3, %i5
a013cc38:  ba 07 40 0b  add  %i5, %o3, %i5
a013cc3c:  f2 07 60 70  ld  [ %i5 + 0x70 ], %i1
a013cc40:  b8 0e 40 15  and  %i1, %l5, %i4
a013cc44:  82 0f 00 14  and  %i4, %l4, %g1
a013cc48:  b6 08 40 13  and  %g1, %l3, %i3
a013cc4c:  b4 0e c0 12  and  %i3, %l2, %i2
a013cc50:  b0 0e 80 11  and  %i2, %l1, %i0
a013cc54:  b2 0e 00 10  and  %i0, %l0, %i1
a013cc58:  82 0e 40 08  and  %i1, %o0, %g1
a013cc5c:  f4 07 60 68  ld  [ %i5 + 0x68 ], %i2
a013cc60:  39 00 01 00  sethi  %hi(0x40000), %i4
a013cc64:  37 00 20 00  sethi  %hi(0x800000), %i3
a013cc68:  82 10 40 1c  or  %g1, %i4, %g1
a013cc6c:  b4 16 80 1b  or  %i2, %i3, %i2
a013cc70:  f0 13 60 26  lduh  [ %o5 + 0x26 ], %i0
a013cc74:  f8 13 60 30  lduh  [ %o5 + 0x30 ], %i4
a013cc78:  f2 13 60 28  lduh  [ %o5 + 0x28 ], %i1
a013cc7c:  f6 13 60 32  lduh  [ %o5 + 0x32 ], %i3
a013cc80:  b2 06 40 18  add  %i1, %i0, %i1
a013cc84:  b6 06 c0 1c  add  %i3, %i4, %i3
a013cc88:  98 03 20 01  inc  %o4
a013cc8c:  f8 13 60 08  lduh  [ %o5 + 8 ], %i4
a013cc90:  f0 13 60 0a  lduh  [ %o5 + 0xa ], %i0
a013cc94:  b4 0e 80 09  and  %i2, %o1, %i2
a013cc98:  82 08 40 0a  and  %g1, %o2, %g1
a013cc9c:  9e 0b 20 ff  and  %o4, 0xff, %o7
a013cca0:  c2 27 60 70  st  %g1, [ %i5 + 0x70 ]
a013cca4:  f8 37 60 4a  sth  %i4, [ %i5 + 0x4a ]
a013cca8:  f0 37 60 52  sth  %i0, [ %i5 + 0x52 ]
a013ccac:  f2 37 60 4e  sth  %i1, [ %i5 + 0x4e ]
a013ccb0:  f6 37 60 58  sth  %i3, [ %i5 + 0x58 ]
a013ccb4:  f4 27 60 68  st  %i2, [ %i5 + 0x68 ]
a013ccb8:  f8 37 60 4c  sth  %i4, [ %i5 + 0x4c ]
a013ccbc:  f0 37 60 54  sth  %i0, [ %i5 + 0x54 ]
a013ccc0:  f2 37 60 50  sth  %i1, [ %i5 + 0x50 ]
a013ccc4:  f6 37 60 56  sth  %i3, [ %i5 + 0x56 ]
a013ccc8:  c0 37 60 5a  clrh  [ %i5 + 0x5a ]
a013cccc:  80 a3 e0 03  cmp  %o7, 3
a013ccd0:  18 80 00 14  bgu  0xa013cd20
a013ccd4:  c0 37 60 5c  clrh  [ %i5 + 0x5c ]
a013ccd8:  b9 2b e0 04  sll  %o7, 4, %i4
a013ccdc:  b6 27 00 0f  sub  %i4, %o7, %i3
a013cce0:  80 a3 e0 00  cmp  %o7, 0
a013cce4:  02 bf ff cf  be  0xa013cc20
a013cce8:  bb 2e e0 03  sll  %i3, 3, %i5
a013ccec:  c2 02 c0 1d  ld  [ %o3 + %i5 ], %g1
a013ccf0:  b2 08 7f fe  and  %g1, -2, %i1
a013ccf4:  10 bf ff ce  b  0xa013cc2c
a013ccf8:  f2 22 c0 1d  st  %i1, [ %o3 + %i5 ]
a013ccfc:  b2 08 60 0f  and  %g1, 0xf, %i1
a013cd00:  f4 02 e1 68  ld  [ %o3 + 0x168 ], %i2
a013cd04:  bb 2e 60 0c  sll  %i1, 0xc, %i5
a013cd08:  b6 0e 80 0c  and  %i2, %o4, %i3
a013cd0c:  b8 16 c0 1d  or  %i3, %i5, %i4
a013cd10:  82 0f 3f 0f  and  %i4, -241, %g1
a013cd14:  b2 10 60 40  or  %g1, 0x40, %i1
a013cd18:  10 bf ff 5b  b  0xa013ca84
a013cd1c:  f2 22 e1 68  st  %i1, [ %o3 + 0x168 ]
a013cd20:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a013cd24:  f8 00 63 d0  ld  [ %g1 + 0x3d0 ], %i4	! 0xa802e3d0
a013cd28:  37 00 08 00  sethi  %hi(0x200000), %i3
a013cd2c:  80 8f 00 1b  btst  %i4, %i3
a013cd30:  02 80 00 04  be  0xa013cd40
a013cd34:  b0 10 20 03  mov  3, %i0
a013cd38:  7f ff cd 6a  call  0xa01302e0
a013cd3c:  93 e8 20 01  restore  %g0, 1, %o1
a013cd40:  01 00 00 00  nop
a013cd44:  81 c7 e0 08  ret
a013cd48:  81 e8 00 00  restore
