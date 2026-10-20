# leon2m FUN_a0141d50 0xa0141d50-0xa0141e0c (188 bytes)
a0141d50:  90 0a 20 ff  and  %o0, 0xff, %o0
a0141d54:  80 a2 20 61  cmp  %o0, 0x61
a0141d58:  02 80 00 15  be  0xa0141dac
a0141d5c:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a0141d60:  14 80 00 07  bg  0xa0141d7c
a0141d64:  80 a2 20 71  cmp  %o0, 0x71
a0141d68:  80 a2 20 51  cmp  %o0, 0x51
a0141d6c:  12 80 00 26  bne  0xa0141e04
a0141d70:  82 0a 60 ff  and  %o1, 0xff, %g1
a0141d74:  10 80 00 1f  b  0xa0141df0
a0141d78:  11 2a 00 b8  sethi  %hi(0xa802e000), %o0
a0141d7c:  02 80 00 14  be  0xa0141dcc
a0141d80:  80 a2 20 81  cmp  %o0, 0x81
a0141d84:  12 80 00 20  bne  0xa0141e04
a0141d88:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a0141d8c:  82 0a 60 ff  and  %o1, 0xff, %g1
a0141d90:  90 13 21 16  or  %o4, 0x116, %o0
a0141d94:  d2 12 20 36  lduh  [ %o0 + 0x36 ], %o1
a0141d98:  9b 28 60 0c  sll  %g1, 0xc, %o5
a0141d9c:  82 0a 6f ff  and  %o1, 0xfff, %g1
a0141da0:  92 10 40 0d  or  %g1, %o5, %o1
a0141da4:  10 80 00 18  b  0xa0141e04
a0141da8:  d2 32 20 36  sth  %o1, [ %o0 + 0x36 ]
a0141dac:  82 0a 60 ff  and  %o1, 0xff, %g1
a0141db0:  90 13 21 16  or  %o4, 0x116, %o0
a0141db4:  d2 12 20 12  lduh  [ %o0 + 0x12 ], %o1
a0141db8:  9b 28 60 0c  sll  %g1, 0xc, %o5
a0141dbc:  82 0a 6f ff  and  %o1, 0xfff, %g1
a0141dc0:  92 10 40 0d  or  %g1, %o5, %o1
a0141dc4:  10 80 00 10  b  0xa0141e04
a0141dc8:  d2 32 20 12  sth  %o1, [ %o0 + 0x12 ]
a0141dcc:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a0141dd0:  82 0a 60 ff  and  %o1, 0xff, %g1
a0141dd4:  98 13 21 16  or  %o4, 0x116, %o4
a0141dd8:  d2 13 20 24  lduh  [ %o4 + 0x24 ], %o1
a0141ddc:  9b 28 60 0c  sll  %g1, 0xc, %o5
a0141de0:  90 0a 6f ff  and  %o1, 0xfff, %o0
a0141de4:  82 12 00 0d  or  %o0, %o5, %g1
a0141de8:  10 80 00 07  b  0xa0141e04
a0141dec:  c2 33 20 24  sth  %g1, [ %o4 + 0x24 ]
a0141df0:  d8 12 21 16  lduh  [ %o0 + 0x116 ], %o4
a0141df4:  9b 28 60 0c  sll  %g1, 0xc, %o5
a0141df8:  82 0b 2f ff  and  %o4, 0xfff, %g1
a0141dfc:  92 10 40 0d  or  %g1, %o5, %o1
a0141e00:  d2 32 21 16  sth  %o1, [ %o0 + 0x116 ]
a0141e04:  81 c3 e0 08  retl
a0141e08:  01 00 00 00  nop
