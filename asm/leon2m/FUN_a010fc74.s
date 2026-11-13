# leon2m FUN_a010fc74 0xa010fc74-0xa010fda4 (304 bytes)
a010fc74:  90 0a 20 ff  and  %o0, 0xff, %o0
a010fc78:  80 a2 20 01  cmp  %o0, 1
a010fc7c:  02 80 00 18  be  0xa010fcdc
a010fc80:  03 34 00 c0  sethi  %hi(0xd0030000), %g1
a010fc84:  04 80 00 39  ble  0xa010fd68
a010fc88:  80 a2 20 02  cmp  %o0, 2
a010fc8c:  02 80 00 1d  be  0xa010fd00
a010fc90:  82 10 60 04  or  %g1, 4, %g1
a010fc94:  80 a2 20 01  cmp  %o0, 1
a010fc98:  02 80 00 08  be  0xa010fcb8
a010fc9c:  80 a2 20 01  cmp  %o0, 1
a010fca0:  04 80 00 27  ble  0xa010fd3c
a010fca4:  80 a2 20 02  cmp  %o0, 2
a010fca8:  12 80 00 3d  bne  0xa010fd9c
a010fcac:  03 34 00 e0  sethi  %hi(0xd0038000), %g1
a010fcb0:  10 80 00 1c  b  0xa010fd20
a010fcb4:  82 10 60 04  or  %g1, 4, %g1	! 0xd0038004
a010fcb8:  03 34 00 e0  sethi  %hi(0xd0038000), %g1
a010fcbc:  82 10 60 04  or  %g1, 4, %g1	! 0xd0038004
a010fcc0:  d8 00 40 00  ld  [ %g1 ], %o4
a010fcc4:  9a 13 22 00  or  %o4, 0x200, %o5
a010fcc8:  da 20 40 00  st  %o5, [ %g1 ]
a010fccc:  d0 00 40 00  ld  [ %g1 ], %o0
a010fcd0:  98 0a 3f fb  and  %o0, -5, %o4
a010fcd4:  d8 20 40 00  st  %o4, [ %g1 ]
a010fcd8:  30 80 00 31  b,a   0xa010fd9c
a010fcdc:  82 10 60 04  or  %g1, 4, %g1
a010fce0:  da 00 40 00  ld  [ %g1 ], %o5
a010fce4:  98 13 62 00  or  %o5, 0x200, %o4
a010fce8:  d8 20 40 00  st  %o4, [ %g1 ]
a010fcec:  da 00 40 00  ld  [ %g1 ], %o5
a010fcf0:  98 0b 7f fb  and  %o5, -5, %o4
a010fcf4:  d8 20 40 00  st  %o4, [ %g1 ]
a010fcf8:  10 bf ff e8  b  0xa010fc98
a010fcfc:  80 a2 20 01  cmp  %o0, 1
a010fd00:  d8 00 40 00  ld  [ %g1 ], %o4
a010fd04:  9a 13 24 00  or  %o4, 0x400, %o5
a010fd08:  da 20 40 00  st  %o5, [ %g1 ]
a010fd0c:  d8 00 40 00  ld  [ %g1 ], %o4
a010fd10:  98 0b 3f f7  and  %o4, -9, %o4
a010fd14:  d8 20 40 00  st  %o4, [ %g1 ]
a010fd18:  10 bf ff e0  b  0xa010fc98
a010fd1c:  80 a2 20 01  cmp  %o0, 1
a010fd20:  d8 00 40 00  ld  [ %g1 ], %o4
a010fd24:  9a 13 24 00  or  %o4, 0x400, %o5
a010fd28:  da 20 40 00  st  %o5, [ %g1 ]
a010fd2c:  d0 00 40 00  ld  [ %g1 ], %o0
a010fd30:  98 0a 3f f7  and  %o0, -9, %o4
a010fd34:  d8 20 40 00  st  %o4, [ %g1 ]
a010fd38:  30 80 00 19  b,a   0xa010fd9c
a010fd3c:  80 a2 20 00  cmp  %o0, 0
a010fd40:  12 80 00 17  bne  0xa010fd9c
a010fd44:  03 34 00 e0  sethi  %hi(0xd0038000), %g1
a010fd48:  82 10 60 04  or  %g1, 4, %g1	! 0xd0038004
a010fd4c:  d8 00 40 00  ld  [ %g1 ], %o4
a010fd50:  9a 13 21 00  or  %o4, 0x100, %o5
a010fd54:  da 20 40 00  st  %o5, [ %g1 ]
a010fd58:  d0 00 40 00  ld  [ %g1 ], %o0
a010fd5c:  98 0a 3f fd  and  %o0, -3, %o4
a010fd60:  d8 20 40 00  st  %o4, [ %g1 ]
a010fd64:  30 80 00 0e  b,a   0xa010fd9c
a010fd68:  80 a2 20 00  cmp  %o0, 0
a010fd6c:  32 bf ff cb  bne,a   0xa010fc98
a010fd70:  80 a2 20 01  cmp  %o0, 1
a010fd74:  03 34 00 c0  sethi  %hi(0xd0030000), %g1
a010fd78:  82 10 60 04  or  %g1, 4, %g1	! 0xd0030004
a010fd7c:  d8 00 40 00  ld  [ %g1 ], %o4
a010fd80:  9a 13 21 00  or  %o4, 0x100, %o5
a010fd84:  da 20 40 00  st  %o5, [ %g1 ]
a010fd88:  d8 00 40 00  ld  [ %g1 ], %o4
a010fd8c:  98 0b 3f fd  and  %o4, -3, %o4
a010fd90:  d8 20 40 00  st  %o4, [ %g1 ]
a010fd94:  10 bf ff c1  b  0xa010fc98
a010fd98:  80 a2 20 01  cmp  %o0, 1
a010fd9c:  81 c3 e0 08  retl
a010fda0:  01 00 00 00  nop
