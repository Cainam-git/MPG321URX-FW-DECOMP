# leon2m FUN_a0141c48 0xa0141c48-0xa0141c98 (80 bytes)
a0141c48:  11 2a 00 b8  sethi  %hi(0xa802e000), %o0
a0141c4c:  92 12 21 16  or  %o0, 0x116, %o1	! 0xa802e116
a0141c50:  c2 12 60 36  lduh  [ %o1 + 0x36 ], %g1
a0141c54:  d8 12 21 16  lduh  [ %o0 + 0x116 ], %o4
a0141c58:  9a 08 6f ff  and  %g1, 0xfff, %o5
a0141c5c:  03 00 00 18  sethi  %hi(0x6000), %g1
a0141c60:  d6 12 60 12  lduh  [ %o1 + 0x12 ], %o3
a0141c64:  d4 12 60 24  lduh  [ %o1 + 0x24 ], %o2
a0141c68:  98 0b 2f ff  and  %o4, 0xfff, %o4
a0141c6c:  96 0a ef ff  and  %o3, 0xfff, %o3
a0141c70:  94 0a af ff  and  %o2, 0xfff, %o2
a0141c74:  98 13 00 01  or  %o4, %g1, %o4
a0141c78:  d8 32 21 16  sth  %o4, [ %o0 + 0x116 ]
a0141c7c:  9a 13 40 01  or  %o5, %g1, %o5
a0141c80:  96 12 c0 01  or  %o3, %g1, %o3
a0141c84:  94 12 80 01  or  %o2, %g1, %o2
a0141c88:  da 32 60 36  sth  %o5, [ %o1 + 0x36 ]
a0141c8c:  d6 32 60 12  sth  %o3, [ %o1 + 0x12 ]
a0141c90:  81 c3 e0 08  retl
a0141c94:  d4 32 60 24  sth  %o2, [ %o1 + 0x24 ]
