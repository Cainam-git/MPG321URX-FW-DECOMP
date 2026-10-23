# leon2m FUN_a0141b10 0xa0141b10-0xa0141b60 (80 bytes)
a0141b10:  11 2a 00 b8  sethi  %hi(0xa802e000), %o0
a0141b14:  92 12 21 16  or  %o0, 0x116, %o1	! 0xa802e116
a0141b18:  c2 12 60 36  lduh  [ %o1 + 0x36 ], %g1
a0141b1c:  d8 12 21 16  lduh  [ %o0 + 0x116 ], %o4
a0141b20:  9a 08 6f ff  and  %g1, 0xfff, %o5
a0141b24:  03 00 00 08  sethi  %hi(0x2000), %g1
a0141b28:  d6 12 60 12  lduh  [ %o1 + 0x12 ], %o3
a0141b2c:  d4 12 60 24  lduh  [ %o1 + 0x24 ], %o2
a0141b30:  98 0b 2f ff  and  %o4, 0xfff, %o4
a0141b34:  96 0a ef ff  and  %o3, 0xfff, %o3
a0141b38:  94 0a af ff  and  %o2, 0xfff, %o2
a0141b3c:  98 13 00 01  or  %o4, %g1, %o4
a0141b40:  d8 32 21 16  sth  %o4, [ %o0 + 0x116 ]
a0141b44:  9a 13 40 01  or  %o5, %g1, %o5
a0141b48:  96 12 c0 01  or  %o3, %g1, %o3
a0141b4c:  94 12 80 01  or  %o2, %g1, %o2
a0141b50:  da 32 60 36  sth  %o5, [ %o1 + 0x36 ]
a0141b54:  d6 32 60 12  sth  %o3, [ %o1 + 0x12 ]
a0141b58:  81 c3 e0 08  retl
a0141b5c:  d4 32 60 24  sth  %o2, [ %o1 + 0x24 ]
