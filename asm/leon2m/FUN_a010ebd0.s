# leon2m FUN_a010ebd0 0xa010ebd0-0xa010ec70 (160 bytes)
a010ebd0:  03 34 00 c1  sethi  %hi(0xd0030400), %g1
a010ebd4:  98 10 60 20  or  %g1, 0x20, %o4	! 0xd0030420
a010ebd8:  92 0a 60 ff  and  %o1, 0xff, %o1
a010ebdc:  c2 03 00 00  ld  [ %o4 ], %g1
a010ebe0:  80 a2 60 00  cmp  %o1, 0
a010ebe4:  12 80 00 0c  bne  0xa010ec14
a010ebe8:  80 a2 60 01  cmp  %o1, 1
a010ebec:  90 0a 20 ff  and  %o0, 0xff, %o0
a010ebf0:  80 a2 20 01  cmp  %o0, 1
a010ebf4:  02 80 00 11  be  0xa010ec38
a010ebf8:  1b 04 c0 80  sethi  %hi(0x13020000), %o5
a010ebfc:  04 80 00 14  ble  0xa010ec4c
a010ec00:  80 a2 20 02  cmp  %o0, 2
a010ec04:  12 80 00 19  bne  0xa010ec68
a010ec08:  1b 04 0c 80  sethi  %hi(0x10320000), %o5
a010ec0c:  10 80 00 0c  b  0xa010ec3c
a010ec10:  13 34 00 e1  sethi  %hi(0xd0038400), %o1
a010ec14:  12 80 00 15  bne  0xa010ec68
a010ec18:  90 0a 20 ff  and  %o0, 0xff, %o0
a010ec1c:  80 a2 20 01  cmp  %o0, 1
a010ec20:  02 80 00 06  be  0xa010ec38
a010ec24:  1b 00 c4 80  sethi  %hi(0x3120000), %o5
a010ec28:  04 80 00 0d  ble  0xa010ec5c
a010ec2c:  80 a2 20 02  cmp  %o0, 2
a010ec30:  12 80 00 0e  bne  0xa010ec68
a010ec34:  1b 00 4c 80  sethi  %hi(0x1320000), %o5
a010ec38:  13 34 00 e1  sethi  %hi(0xd0038400), %o1
a010ec3c:  da 23 00 00  st  %o5, [ %o4 ]
a010ec40:  90 12 60 20  or  %o1, 0x20, %o0
a010ec44:  da 22 00 00  st  %o5, [ %o0 ]
a010ec48:  30 80 00 08  b,a   0xa010ec68
a010ec4c:  80 a2 20 00  cmp  %o0, 0
a010ec50:  02 bf ff fa  be  0xa010ec38
a010ec54:  1b 04 c8 00  sethi  %hi(0x13200000), %o5
a010ec58:  30 80 00 04  b,a   0xa010ec68
a010ec5c:  80 a2 20 00  cmp  %o0, 0
a010ec60:  02 bf ff f6  be  0xa010ec38
a010ec64:  1b 00 c8 40  sethi  %hi(0x3210000), %o5
a010ec68:  81 c3 e0 08  retl
a010ec6c:  01 00 00 00  nop
