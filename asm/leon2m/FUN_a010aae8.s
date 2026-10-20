# leon2m FUN_a010aae8 0xa010aae8-0xa010abd4 (236 bytes)
a010aae8:  9d e3 bf 98  save  %sp, -104, %sp
a010aaec:  b0 0e 20 ff  and  %i0, 0xff, %i0
a010aaf0:  80 a6 20 01  cmp  %i0, 1
a010aaf4:  02 80 00 0b  be  0xa010ab20
a010aaf8:  9e 10 00 1b  mov  %i3, %o7
a010aafc:  80 a6 20 01  cmp  %i0, 1
a010ab00:  04 80 00 1e  ble  0xa010ab78
a010ab04:  80 a6 20 02  cmp  %i0, 2
a010ab08:  02 80 00 11  be  0xa010ab4c
a010ab0c:  80 a6 20 03  cmp  %i0, 3
a010ab10:  12 80 00 2f  bne  0xa010abcc
a010ab14:  31 33 c0 47  sethi  %hi(0xcf011c00), %i0
a010ab18:  10 80 00 25  b  0xa010abac
a010ab1c:  b8 0e 60 ff  and  %i1, 0xff, %i4
a010ab20:  3b 33 c0 47  sethi  %hi(0xcf011c00), %i5
a010ab24:  b0 0e 60 ff  and  %i1, 0xff, %i0
a010ab28:  b6 17 63 d0  or  %i5, 0x3d0, %i3
a010ab2c:  f0 26 c0 00  st  %i0, [ %i3 ]
a010ab30:  82 0e a0 ff  and  %i2, 0xff, %g1
a010ab34:  b2 17 63 d4  or  %i5, 0x3d4, %i1
a010ab38:  c2 26 40 00  st  %g1, [ %i1 ]
a010ab3c:  ba 17 63 d8  or  %i5, 0x3d8, %i5
a010ab40:  b4 0b e0 ff  and  %o7, 0xff, %i2
a010ab44:  f4 27 40 00  st  %i2, [ %i5 ]
a010ab48:  30 80 00 21  b,a   0xa010abcc
a010ab4c:  3b 33 c0 47  sethi  %hi(0xcf011c00), %i5
a010ab50:  82 0e 60 ff  and  %i1, 0xff, %g1
a010ab54:  b2 17 63 dc  or  %i5, 0x3dc, %i1
a010ab58:  b8 0e a0 ff  and  %i2, 0xff, %i4
a010ab5c:  b4 17 63 e0  or  %i5, 0x3e0, %i2
a010ab60:  c2 26 40 00  st  %g1, [ %i1 ]
a010ab64:  f8 26 80 00  st  %i4, [ %i2 ]
a010ab68:  ba 17 63 e4  or  %i5, 0x3e4, %i5
a010ab6c:  b4 0b e0 ff  and  %o7, 0xff, %i2
a010ab70:  f4 27 40 00  st  %i2, [ %i5 ]
a010ab74:  30 80 00 16  b,a   0xa010abcc
a010ab78:  80 a6 20 00  cmp  %i0, 0
a010ab7c:  12 80 00 14  bne  0xa010abcc
a010ab80:  3b 33 c0 47  sethi  %hi(0xcf011c00), %i5
a010ab84:  b0 17 63 c4  or  %i5, 0x3c4, %i0	! 0xcf011fc4
a010ab88:  b8 0e 60 ff  and  %i1, 0xff, %i4
a010ab8c:  f8 26 00 00  st  %i4, [ %i0 ]
a010ab90:  b6 0e a0 ff  and  %i2, 0xff, %i3
a010ab94:  82 17 63 c8  or  %i5, 0x3c8, %g1
a010ab98:  f6 20 40 00  st  %i3, [ %g1 ]
a010ab9c:  ba 17 63 cc  or  %i5, 0x3cc, %i5
a010aba0:  b4 0b e0 ff  and  %o7, 0xff, %i2
a010aba4:  f4 27 40 00  st  %i2, [ %i5 ]
a010aba8:  30 80 00 09  b,a   0xa010abcc
a010abac:  b2 16 23 e8  or  %i0, 0x3e8, %i1
a010abb0:  f8 26 40 00  st  %i4, [ %i1 ]
a010abb4:  b6 0e a0 ff  and  %i2, 0xff, %i3
a010abb8:  ba 16 23 ec  or  %i0, 0x3ec, %i5
a010abbc:  f6 27 40 00  st  %i3, [ %i5 ]
a010abc0:  ba 16 23 f0  or  %i0, 0x3f0, %i5
a010abc4:  b4 0b e0 ff  and  %o7, 0xff, %i2
a010abc8:  f4 27 40 00  st  %i2, [ %i5 ]
a010abcc:  81 c7 e0 08  ret
a010abd0:  81 e8 00 00  restore
