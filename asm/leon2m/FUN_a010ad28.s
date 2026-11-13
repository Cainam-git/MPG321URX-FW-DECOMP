# leon2m FUN_a010ad28 0xa010ad28-0xa010adb8 (144 bytes)
a010ad28:  03 33 c0 47  sethi  %hi(0xcf011c00), %g1
a010ad2c:  90 0a 20 ff  and  %o0, 0xff, %o0
a010ad30:  92 0a 60 3f  and  %o1, 0x3f, %o1
a010ad34:  98 10 61 d4  or  %g1, 0x1d4, %o4
a010ad38:  80 a2 20 02  cmp  %o0, 2
a010ad3c:  02 80 00 0a  be  0xa010ad64
a010ad40:  9a 0a 60 ff  and  %o1, 0xff, %o5
a010ad44:  80 a2 20 02  cmp  %o0, 2
a010ad48:  04 80 00 0c  ble  0xa010ad78
a010ad4c:  98 10 61 cc  or  %g1, 0x1cc, %o4
a010ad50:  03 33 c0 47  sethi  %hi(0xcf011c00), %g1
a010ad54:  96 10 61 d8  or  %g1, 0x1d8, %o3	! 0xcf011dd8
a010ad58:  80 a2 20 03  cmp  %o0, 3
a010ad5c:  02 80 00 11  be  0xa010ada0
a010ad60:  92 0a 60 ff  and  %o1, 0xff, %o1
a010ad64:  d6 03 00 00  ld  [ %o4 ], %o3
a010ad68:  90 0a e0 80  and  %o3, 0x80, %o0
a010ad6c:  92 12 00 0d  or  %o0, %o5, %o1
a010ad70:  d2 23 00 00  st  %o1, [ %o4 ]
a010ad74:  30 80 00 0f  b,a   0xa010adb0
a010ad78:  80 a2 20 01  cmp  %o0, 1
a010ad7c:  12 bf ff fa  bne  0xa010ad64
a010ad80:  03 33 c0 47  sethi  %hi(0xcf011c00), %g1
a010ad84:  90 10 61 d0  or  %g1, 0x1d0, %o0	! 0xcf011dd0
a010ad88:  da 02 00 00  ld  [ %o0 ], %o5
a010ad8c:  96 0b 60 80  and  %o5, 0x80, %o3
a010ad90:  98 0a 60 ff  and  %o1, 0xff, %o4
a010ad94:  9a 12 c0 0c  or  %o3, %o4, %o5
a010ad98:  da 22 00 00  st  %o5, [ %o0 ]
a010ad9c:  30 80 00 05  b,a   0xa010adb0
a010ada0:  c2 02 c0 00  ld  [ %o3 ], %g1
a010ada4:  9a 08 60 80  and  %g1, 0x80, %o5
a010ada8:  98 13 40 09  or  %o5, %o1, %o4
a010adac:  d8 22 c0 00  st  %o4, [ %o3 ]
a010adb0:  81 c3 e0 08  retl
a010adb4:  01 00 00 00  nop
