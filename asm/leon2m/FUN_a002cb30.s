# leon2m FUN_a002cb30 0xa002cb30-0xa002cd38 (520 bytes)
a002cb30:  94 0a a0 ff  and  %o2, 0xff, %o2
a002cb34:  80 a2 a0 01  cmp  %o2, 1
a002cb38:  02 80 00 11  be  0xa002cb7c
a002cb3c:  82 0a 20 ff  and  %o0, 0xff, %g1
a002cb40:  80 a0 60 11  cmp  %g1, 0x11
a002cb44:  18 80 00 7b  bgu  0xa002cd30
a002cb48:  11 28 00 b1  sethi  %hi(0xa002c400), %o0
a002cb4c:  99 28 60 02  sll  %g1, 2, %o4
a002cb50:  9a 12 23 dc  or  %o0, 0x3dc, %o5
a002cb54:  d4 03 40 0c  ld  [ %o5 + %o4 ], %o2
a002cb58:  81 c2 80 00  jmp  %o2
a002cb5c:  01 00 00 00  nop
a002cb60:  03 33 c0 f0  sethi  %hi(0xcf03c000), %g1
a002cb64:  82 10 60 4c  or  %g1, 0x4c, %g1	! 0xcf03c04c
a002cb68:  90 0a 60 ff  and  %o1, 0xff, %o0
a002cb6c:  d2 00 40 00  ld  [ %g1 ], %o1
a002cb70:  9a 12 40 08  or  %o1, %o0, %o5
a002cb74:  da 20 40 00  st  %o5, [ %g1 ]
a002cb78:  30 80 00 6e  b,a   0xa002cd30
a002cb7c:  80 a0 60 11  cmp  %g1, 0x11
a002cb80:  18 80 00 6c  bgu  0xa002cd30
a002cb84:  11 28 00 b1  sethi  %hi(0xa002c400), %o0
a002cb88:  83 28 60 02  sll  %g1, 2, %g1
a002cb8c:  9a 12 23 94  or  %o0, 0x394, %o5
a002cb90:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a002cb94:  81 c3 00 00  jmp  %o4
a002cb98:  01 00 00 00  nop
a002cb9c:  03 33 c0 f3  sethi  %hi(0xcf03cc00), %g1
a002cba0:  82 10 60 4c  or  %g1, 0x4c, %g1	! 0xcf03cc4c
a002cba4:  9a 0a 60 ff  and  %o1, 0xff, %o5
a002cba8:  d2 00 40 00  ld  [ %g1 ], %o1
a002cbac:  9a 2a 40 0d  andn  %o1, %o5, %o5
a002cbb0:  da 20 40 00  st  %o5, [ %g1 ]
a002cbb4:  30 80 00 5f  b,a   0xa002cd30
a002cbb8:  03 33 c0 f0  sethi  %hi(0xcf03c000), %g1
a002cbbc:  10 bf ff fa  b  0xa002cba4
a002cbc0:  82 10 60 14  or  %g1, 0x14, %g1	! 0xcf03c014
a002cbc4:  15 33 c0 f0  sethi  %hi(0xcf03c000), %o2
a002cbc8:  10 bf ff f7  b  0xa002cba4
a002cbcc:  82 12 a0 18  or  %o2, 0x18, %g1	! 0xcf03c018
a002cbd0:  19 33 c0 f0  sethi  %hi(0xcf03c000), %o4
a002cbd4:  10 bf ff f4  b  0xa002cba4
a002cbd8:  82 13 20 1c  or  %o4, 0x1c, %g1	! 0xcf03c01c
a002cbdc:  1b 33 c0 f0  sethi  %hi(0xcf03c000), %o5
a002cbe0:  10 bf ff f1  b  0xa002cba4
a002cbe4:  82 13 60 20  or  %o5, 0x20, %g1	! 0xcf03c020
a002cbe8:  11 33 c0 f0  sethi  %hi(0xcf03c000), %o0
a002cbec:  10 bf ff ee  b  0xa002cba4
a002cbf0:  82 12 20 24  or  %o0, 0x24, %g1	! 0xcf03c024
a002cbf4:  03 33 c0 f0  sethi  %hi(0xcf03c000), %g1
a002cbf8:  10 bf ff eb  b  0xa002cba4
a002cbfc:  82 10 60 44  or  %g1, 0x44, %g1	! 0xcf03c044
a002cc00:  10 bf ff e8  b  0xa002cba0
a002cc04:  03 33 c0 f0  sethi  %hi(0xcf03c000), %g1
a002cc08:  03 33 c0 f1  sethi  %hi(0xcf03c400), %g1
a002cc0c:  10 bf ff e6  b  0xa002cba4
a002cc10:  82 10 60 54  or  %g1, 0x54, %g1	! 0xcf03c454
a002cc14:  15 33 c0 f1  sethi  %hi(0xcf03c400), %o2
a002cc18:  10 bf ff e3  b  0xa002cba4
a002cc1c:  82 12 a0 5c  or  %o2, 0x5c, %g1	! 0xcf03c45c
a002cc20:  19 33 c0 f1  sethi  %hi(0xcf03c400), %o4
a002cc24:  10 bf ff e0  b  0xa002cba4
a002cc28:  82 13 20 64  or  %o4, 0x64, %g1	! 0xcf03c464
a002cc2c:  1b 33 c0 f1  sethi  %hi(0xcf03c400), %o5
a002cc30:  10 bf ff dd  b  0xa002cba4
a002cc34:  82 13 60 6c  or  %o5, 0x6c, %g1	! 0xcf03c46c
a002cc38:  11 33 c0 f1  sethi  %hi(0xcf03c400), %o0
a002cc3c:  10 bf ff da  b  0xa002cba4
a002cc40:  82 12 20 74  or  %o0, 0x74, %g1	! 0xcf03c474
a002cc44:  03 33 c0 f1  sethi  %hi(0xcf03c400), %g1
a002cc48:  10 bf ff d7  b  0xa002cba4
a002cc4c:  82 10 60 7c  or  %g1, 0x7c, %g1	! 0xcf03c47c
a002cc50:  15 33 c0 f3  sethi  %hi(0xcf03cc00), %o2
a002cc54:  10 bf ff d4  b  0xa002cba4
a002cc58:  82 12 a0 40  or  %o2, 0x40, %g1	! 0xcf03cc40
a002cc5c:  03 33 c0 f3  sethi  %hi(0xcf03cc00), %g1
a002cc60:  10 bf ff d1  b  0xa002cba4
a002cc64:  82 10 60 44  or  %g1, 0x44, %g1	! 0xcf03cc44
a002cc68:  19 33 c0 f3  sethi  %hi(0xcf03cc00), %o4
a002cc6c:  10 bf ff ce  b  0xa002cba4
a002cc70:  82 13 20 48  or  %o4, 0x48, %g1	! 0xcf03cc48
a002cc74:  10 bf ff bc  b  0xa002cb64
a002cc78:  03 33 c0 f3  sethi  %hi(0xcf03cc00), %g1
a002cc7c:  03 33 c0 f3  sethi  %hi(0xcf03cc00), %g1
a002cc80:  10 bf ff ba  b  0xa002cb68
a002cc84:  82 10 60 48  or  %g1, 0x48, %g1	! 0xcf03cc48
a002cc88:  03 33 c0 f3  sethi  %hi(0xcf03cc00), %g1
a002cc8c:  10 bf ff b7  b  0xa002cb68
a002cc90:  82 10 60 44  or  %g1, 0x44, %g1	! 0xcf03cc44
a002cc94:  11 33 c0 f3  sethi  %hi(0xcf03cc00), %o0
a002cc98:  10 bf ff b4  b  0xa002cb68
a002cc9c:  82 12 20 40  or  %o0, 0x40, %g1	! 0xcf03cc40
a002cca0:  19 33 c0 f1  sethi  %hi(0xcf03c400), %o4
a002cca4:  10 bf ff b1  b  0xa002cb68
a002cca8:  82 13 20 7c  or  %o4, 0x7c, %g1	! 0xcf03c47c
a002ccac:  15 33 c0 f1  sethi  %hi(0xcf03c400), %o2
a002ccb0:  10 bf ff ae  b  0xa002cb68
a002ccb4:  82 12 a0 74  or  %o2, 0x74, %g1	! 0xcf03c474
a002ccb8:  1b 33 c0 f1  sethi  %hi(0xcf03c400), %o5
a002ccbc:  10 bf ff ab  b  0xa002cb68
a002ccc0:  82 13 60 6c  or  %o5, 0x6c, %g1	! 0xcf03c46c
a002ccc4:  03 33 c0 f1  sethi  %hi(0xcf03c400), %g1
a002ccc8:  10 bf ff a8  b  0xa002cb68
a002cccc:  82 10 60 64  or  %g1, 0x64, %g1	! 0xcf03c464
a002ccd0:  11 33 c0 f1  sethi  %hi(0xcf03c400), %o0
a002ccd4:  10 bf ff a5  b  0xa002cb68
a002ccd8:  82 12 20 5c  or  %o0, 0x5c, %g1	! 0xcf03c45c
a002ccdc:  19 33 c0 f1  sethi  %hi(0xcf03c400), %o4
a002cce0:  10 bf ff a2  b  0xa002cb68
a002cce4:  82 13 20 54  or  %o4, 0x54, %g1	! 0xcf03c454
a002cce8:  03 33 c0 f0  sethi  %hi(0xcf03c000), %g1
a002ccec:  10 bf ff 9f  b  0xa002cb68
a002ccf0:  82 10 60 44  or  %g1, 0x44, %g1	! 0xcf03c044
a002ccf4:  15 33 c0 f0  sethi  %hi(0xcf03c000), %o2
a002ccf8:  10 bf ff 9c  b  0xa002cb68
a002ccfc:  82 12 a0 24  or  %o2, 0x24, %g1	! 0xcf03c024
a002cd00:  1b 33 c0 f0  sethi  %hi(0xcf03c000), %o5
a002cd04:  10 bf ff 99  b  0xa002cb68
a002cd08:  82 13 60 20  or  %o5, 0x20, %g1	! 0xcf03c020
a002cd0c:  03 33 c0 f0  sethi  %hi(0xcf03c000), %g1
a002cd10:  10 bf ff 96  b  0xa002cb68
a002cd14:  82 10 60 1c  or  %g1, 0x1c, %g1	! 0xcf03c01c
a002cd18:  19 33 c0 f0  sethi  %hi(0xcf03c000), %o4
a002cd1c:  10 bf ff 93  b  0xa002cb68
a002cd20:  82 13 20 18  or  %o4, 0x18, %g1	! 0xcf03c018
a002cd24:  15 33 c0 f0  sethi  %hi(0xcf03c000), %o2
a002cd28:  10 bf ff 90  b  0xa002cb68
a002cd2c:  82 12 a0 14  or  %o2, 0x14, %g1	! 0xcf03c014
a002cd30:  81 c3 e0 08  retl
a002cd34:  01 00 00 00  nop
