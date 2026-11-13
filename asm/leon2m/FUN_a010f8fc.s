# leon2m FUN_a010f8fc 0xa010f8fc-0xa010fc74 (888 bytes)
a010f8fc:  90 0a 20 ff  and  %o0, 0xff, %o0
a010f900:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a010f904:  80 a2 20 01  cmp  %o0, 1
a010f908:  02 80 00 06  be  0xa010f920
a010f90c:  96 10 63 c4  or  %g1, 0x3c4, %o3
a010f910:  19 2a 00 b5  sethi  %hi(0xa802d400), %o4
a010f914:  80 a2 20 02  cmp  %o0, 2
a010f918:  02 80 00 4a  be  0xa010fa40
a010f91c:  96 13 23 44  or  %o4, 0x344, %o3
a010f920:  1b 2a 00 b5  sethi  %hi(0xa802d400), %o5
a010f924:  d8 03 62 a4  ld  [ %o5 + 0x2a4 ], %o4	! 0xa802d6a4
a010f928:  c2 13 20 08  lduh  [ %o4 + 8 ], %g1
a010f92c:  99 30 60 01  srl  %g1, 1, %o4
a010f930:  da 12 e0 14  lduh  [ %o3 + 0x14 ], %o5
a010f934:  80 a3 40 0c  cmp  %o5, %o4
a010f938:  2a 80 00 13  bcs,a   0xa010f984
a010f93c:  c2 12 e0 16  lduh  [ %o3 + 0x16 ], %g1
a010f940:  80 a2 20 01  cmp  %o0, 1
a010f944:  22 80 00 42  be,a   0xa010fa4c
a010f948:  03 34 00 c0  sethi  %hi(0xd0030000), %g1
a010f94c:  04 80 00 79  ble  0xa010fb30
a010f950:  80 a2 20 02  cmp  %o0, 2
a010f954:  02 80 00 51  be  0xa010fa98
a010f958:  03 34 00 c0  sethi  %hi(0xd0030000), %g1
a010f95c:  80 a2 20 01  cmp  %o0, 1
a010f960:  02 80 00 46  be  0xa010fa78
a010f964:  03 34 00 e0  sethi  %hi(0xd0038000), %g1
a010f968:  80 a2 20 01  cmp  %o0, 1
a010f96c:  04 80 00 66  ble  0xa010fb04
a010f970:  80 a2 20 02  cmp  %o0, 2
a010f974:  12 80 00 be  bne  0xa010fc6c
a010f978:  1b 34 00 e0  sethi  %hi(0xd0038000), %o5
a010f97c:  10 80 00 14  b  0xa010f9cc
a010f980:  82 13 60 04  or  %o5, 4, %g1	! 0xd0038004
a010f984:  96 03 40 01  add  %o5, %g1, %o3
a010f988:  80 a2 c0 0c  cmp  %o3, %o4
a010f98c:  04 80 00 17  ble  0xa010f9e8
a010f990:  80 a2 20 01  cmp  %o0, 1
a010f994:  22 80 00 53  be,a   0xa010fae0
a010f998:  03 34 00 c0  sethi  %hi(0xd0030000), %g1
a010f99c:  04 80 00 8c  ble  0xa010fbcc
a010f9a0:  80 a2 20 02  cmp  %o0, 2
a010f9a4:  02 80 00 79  be  0xa010fb88
a010f9a8:  03 34 00 c0  sethi  %hi(0xd0030000), %g1
a010f9ac:  80 a2 20 01  cmp  %o0, 1
a010f9b0:  02 80 00 31  be  0xa010fa74
a010f9b4:  80 a2 20 01  cmp  %o0, 1
a010f9b8:  04 80 00 aa  ble  0xa010fc60
a010f9bc:  80 a2 20 02  cmp  %o0, 2
a010f9c0:  12 80 00 ab  bne  0xa010fc6c
a010f9c4:  1b 34 00 e0  sethi  %hi(0xd0038000), %o5
a010f9c8:  82 13 60 04  or  %o5, 4, %g1	! 0xd0038004
a010f9cc:  d8 00 40 00  ld  [ %g1 ], %o4
a010f9d0:  90 13 20 08  or  %o4, 8, %o0
a010f9d4:  d0 20 40 00  st  %o0, [ %g1 ]
a010f9d8:  d6 00 40 00  ld  [ %g1 ], %o3
a010f9dc:  98 0a fb ff  and  %o3, -1025, %o4
a010f9e0:  d8 20 40 00  st  %o4, [ %g1 ]
a010f9e4:  30 80 00 a2  b,a   0xa010fc6c
a010f9e8:  02 80 00 35  be  0xa010fabc
a010f9ec:  03 34 00 c0  sethi  %hi(0xd0030000), %g1
a010f9f0:  80 a2 20 01  cmp  %o0, 1
a010f9f4:  04 80 00 8e  ble  0xa010fc2c
a010f9f8:  80 a2 20 02  cmp  %o0, 2
a010f9fc:  02 80 00 6c  be  0xa010fbac
a010fa00:  82 10 60 04  or  %g1, 4, %g1
a010fa04:  80 a2 20 01  cmp  %o0, 1
a010fa08:  02 80 00 57  be  0xa010fb64
a010fa0c:  80 a2 20 01  cmp  %o0, 1
a010fa10:  04 80 00 7c  ble  0xa010fc00
a010fa14:  80 a2 20 02  cmp  %o0, 2
a010fa18:  12 80 00 95  bne  0xa010fc6c
a010fa1c:  19 34 00 e0  sethi  %hi(0xd0038000), %o4
a010fa20:  82 13 20 04  or  %o4, 4, %g1	! 0xd0038004
a010fa24:  d6 00 40 00  ld  [ %g1 ], %o3
a010fa28:  90 12 e4 00  or  %o3, 0x400, %o0
a010fa2c:  d0 20 40 00  st  %o0, [ %g1 ]
a010fa30:  da 00 40 00  ld  [ %g1 ], %o5
a010fa34:  98 0b 7f f7  and  %o5, -9, %o4
a010fa38:  d8 20 40 00  st  %o4, [ %g1 ]
a010fa3c:  30 80 00 8c  b,a   0xa010fc6c
a010fa40:  1b 2a 00 b5  sethi  %hi(0xa802d400), %o5
a010fa44:  10 bf ff b7  b  0xa010f920
a010fa48:  96 13 63 84  or  %o5, 0x384, %o3	! 0xa802d784
a010fa4c:  82 10 60 04  or  %g1, 4, %g1
a010fa50:  da 00 40 00  ld  [ %g1 ], %o5
a010fa54:  98 13 62 00  or  %o5, 0x200, %o4
a010fa58:  d8 20 40 00  st  %o4, [ %g1 ]
a010fa5c:  d6 00 40 00  ld  [ %g1 ], %o3
a010fa60:  98 0a ff fb  and  %o3, -5, %o4
a010fa64:  d8 20 40 00  st  %o4, [ %g1 ]
a010fa68:  80 a2 20 01  cmp  %o0, 1
a010fa6c:  12 bf ff c0  bne  0xa010f96c
a010fa70:  80 a2 20 01  cmp  %o0, 1
a010fa74:  03 34 00 e0  sethi  %hi(0xd0038000), %g1
a010fa78:  82 10 60 04  or  %g1, 4, %g1	! 0xd0038004
a010fa7c:  da 00 40 00  ld  [ %g1 ], %o5
a010fa80:  98 13 60 04  or  %o5, 4, %o4
a010fa84:  d8 20 40 00  st  %o4, [ %g1 ]
a010fa88:  d0 00 40 00  ld  [ %g1 ], %o0
a010fa8c:  98 0a 3d ff  and  %o0, -513, %o4
a010fa90:  d8 20 40 00  st  %o4, [ %g1 ]
a010fa94:  30 80 00 76  b,a   0xa010fc6c
a010fa98:  82 10 60 04  or  %g1, 4, %g1
a010fa9c:  da 00 40 00  ld  [ %g1 ], %o5
a010faa0:  98 13 64 00  or  %o5, 0x400, %o4
a010faa4:  d8 20 40 00  st  %o4, [ %g1 ]
a010faa8:  d6 00 40 00  ld  [ %g1 ], %o3
a010faac:  98 0a ff f7  and  %o3, -9, %o4
a010fab0:  d8 20 40 00  st  %o4, [ %g1 ]
a010fab4:  10 bf ff ee  b  0xa010fa6c
a010fab8:  80 a2 20 01  cmp  %o0, 1
a010fabc:  82 10 60 04  or  %g1, 4, %g1
a010fac0:  da 00 40 00  ld  [ %g1 ], %o5
a010fac4:  98 13 60 04  or  %o5, 4, %o4
a010fac8:  d8 20 40 00  st  %o4, [ %g1 ]
a010facc:  d6 00 40 00  ld  [ %g1 ], %o3
a010fad0:  98 0a fd ff  and  %o3, -513, %o4
a010fad4:  d8 20 40 00  st  %o4, [ %g1 ]
a010fad8:  10 bf ff cc  b  0xa010fa08
a010fadc:  80 a2 20 01  cmp  %o0, 1
a010fae0:  82 10 60 04  or  %g1, 4, %g1
a010fae4:  d6 00 40 00  ld  [ %g1 ], %o3
a010fae8:  9a 12 e0 04  or  %o3, 4, %o5
a010faec:  da 20 40 00  st  %o5, [ %g1 ]
a010faf0:  d8 00 40 00  ld  [ %g1 ], %o4
a010faf4:  98 0b 3d ff  and  %o4, -513, %o4
a010faf8:  d8 20 40 00  st  %o4, [ %g1 ]
a010fafc:  10 bf ff ad  b  0xa010f9b0
a010fb00:  80 a2 20 01  cmp  %o0, 1
a010fb04:  80 a2 20 00  cmp  %o0, 0
a010fb08:  12 80 00 59  bne  0xa010fc6c
a010fb0c:  17 34 00 e0  sethi  %hi(0xd0038000), %o3
a010fb10:  82 12 e0 04  or  %o3, 4, %g1	! 0xd0038004
a010fb14:  da 00 40 00  ld  [ %g1 ], %o5
a010fb18:  98 13 60 02  or  %o5, 2, %o4
a010fb1c:  d8 20 40 00  st  %o4, [ %g1 ]
a010fb20:  d0 00 40 00  ld  [ %g1 ], %o0
a010fb24:  98 0a 3e ff  and  %o0, -257, %o4
a010fb28:  d8 20 40 00  st  %o4, [ %g1 ]
a010fb2c:  30 80 00 50  b,a   0xa010fc6c
a010fb30:  80 a2 20 00  cmp  %o0, 0
a010fb34:  32 bf ff 8b  bne,a   0xa010f960
a010fb38:  80 a2 20 01  cmp  %o0, 1
a010fb3c:  03 34 00 c0  sethi  %hi(0xd0030000), %g1
a010fb40:  82 10 60 04  or  %g1, 4, %g1	! 0xd0030004
a010fb44:  da 00 40 00  ld  [ %g1 ], %o5
a010fb48:  98 13 61 00  or  %o5, 0x100, %o4
a010fb4c:  d8 20 40 00  st  %o4, [ %g1 ]
a010fb50:  d6 00 40 00  ld  [ %g1 ], %o3
a010fb54:  98 0a ff fd  and  %o3, -3, %o4
a010fb58:  d8 20 40 00  st  %o4, [ %g1 ]
a010fb5c:  10 bf ff c4  b  0xa010fa6c
a010fb60:  80 a2 20 01  cmp  %o0, 1
a010fb64:  03 34 00 e0  sethi  %hi(0xd0038000), %g1
a010fb68:  82 10 60 04  or  %g1, 4, %g1	! 0xd0038004
a010fb6c:  d8 00 40 00  ld  [ %g1 ], %o4
a010fb70:  96 13 22 00  or  %o4, 0x200, %o3
a010fb74:  d6 20 40 00  st  %o3, [ %g1 ]
a010fb78:  d0 00 40 00  ld  [ %g1 ], %o0
a010fb7c:  98 0a 3f fb  and  %o0, -5, %o4
a010fb80:  d8 20 40 00  st  %o4, [ %g1 ]
a010fb84:  30 80 00 3a  b,a   0xa010fc6c
a010fb88:  82 10 60 04  or  %g1, 4, %g1
a010fb8c:  d6 00 40 00  ld  [ %g1 ], %o3
a010fb90:  9a 12 e0 08  or  %o3, 8, %o5
a010fb94:  da 20 40 00  st  %o5, [ %g1 ]
a010fb98:  d8 00 40 00  ld  [ %g1 ], %o4
a010fb9c:  98 0b 3b ff  and  %o4, -1025, %o4
a010fba0:  d8 20 40 00  st  %o4, [ %g1 ]
a010fba4:  10 bf ff 83  b  0xa010f9b0
a010fba8:  80 a2 20 01  cmp  %o0, 1
a010fbac:  da 00 40 00  ld  [ %g1 ], %o5
a010fbb0:  98 13 60 08  or  %o5, 8, %o4
a010fbb4:  d8 20 40 00  st  %o4, [ %g1 ]
a010fbb8:  d6 00 40 00  ld  [ %g1 ], %o3
a010fbbc:  98 0a fb ff  and  %o3, -1025, %o4
a010fbc0:  d8 20 40 00  st  %o4, [ %g1 ]
a010fbc4:  10 bf ff 91  b  0xa010fa08
a010fbc8:  80 a2 20 01  cmp  %o0, 1
a010fbcc:  80 a2 20 00  cmp  %o0, 0
a010fbd0:  32 bf ff 78  bne,a   0xa010f9b0
a010fbd4:  80 a2 20 01  cmp  %o0, 1
a010fbd8:  03 34 00 c0  sethi  %hi(0xd0030000), %g1
a010fbdc:  82 10 60 04  or  %g1, 4, %g1	! 0xd0030004
a010fbe0:  d6 00 40 00  ld  [ %g1 ], %o3
a010fbe4:  9a 12 e0 02  or  %o3, 2, %o5
a010fbe8:  da 20 40 00  st  %o5, [ %g1 ]
a010fbec:  d8 00 40 00  ld  [ %g1 ], %o4
a010fbf0:  98 0b 3e ff  and  %o4, -257, %o4
a010fbf4:  d8 20 40 00  st  %o4, [ %g1 ]
a010fbf8:  10 bf ff 6e  b  0xa010f9b0
a010fbfc:  80 a2 20 01  cmp  %o0, 1
a010fc00:  80 a2 20 00  cmp  %o0, 0
a010fc04:  12 80 00 1a  bne  0xa010fc6c
a010fc08:  1b 34 00 e0  sethi  %hi(0xd0038000), %o5
a010fc0c:  82 13 60 04  or  %o5, 4, %g1	! 0xd0038004
a010fc10:  d8 00 40 00  ld  [ %g1 ], %o4
a010fc14:  96 13 21 00  or  %o4, 0x100, %o3
a010fc18:  d6 20 40 00  st  %o3, [ %g1 ]
a010fc1c:  d0 00 40 00  ld  [ %g1 ], %o0
a010fc20:  98 0a 3f fd  and  %o0, -3, %o4
a010fc24:  d8 20 40 00  st  %o4, [ %g1 ]
a010fc28:  30 80 00 11  b,a   0xa010fc6c
a010fc2c:  80 a2 20 00  cmp  %o0, 0
a010fc30:  32 bf ff 76  bne,a   0xa010fa08
a010fc34:  80 a2 20 01  cmp  %o0, 1
a010fc38:  03 34 00 c0  sethi  %hi(0xd0030000), %g1
a010fc3c:  82 10 60 04  or  %g1, 4, %g1	! 0xd0030004
a010fc40:  da 00 40 00  ld  [ %g1 ], %o5
a010fc44:  98 13 60 02  or  %o5, 2, %o4
a010fc48:  d8 20 40 00  st  %o4, [ %g1 ]
a010fc4c:  d6 00 40 00  ld  [ %g1 ], %o3
a010fc50:  98 0a fe ff  and  %o3, -257, %o4
a010fc54:  d8 20 40 00  st  %o4, [ %g1 ]
a010fc58:  10 bf ff 6c  b  0xa010fa08
a010fc5c:  80 a2 20 01  cmp  %o0, 1
a010fc60:  80 a2 20 00  cmp  %o0, 0
a010fc64:  02 bf ff ab  be  0xa010fb10
a010fc68:  17 34 00 e0  sethi  %hi(0xd0038000), %o3
a010fc6c:  81 c3 e0 08  retl
a010fc70:  01 00 00 00  nop
