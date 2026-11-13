# leon2m FUN_a013ffb0 0xa013ffb0-0xa0140034 (132 bytes)
a013ffb0:  13 00 06 96  sethi  %hi(0x1a5800), %o1
a013ffb4:  96 12 62 16  or  %o1, 0x216, %o3	! 0x1a5a16
a013ffb8:  1b 00 00 3f  sethi  %hi(0xfc00), %o5
a013ffbc:  c2 12 e0 02  lduh  [ %o3 + 2 ], %g1
a013ffc0:  9a 13 63 ff  or  %o5, 0x3ff, %o5
a013ffc4:  80 a0 40 0d  cmp  %g1, %o5
a013ffc8:  82 10 00 08  mov  %o0, %g1
a013ffcc:  98 10 20 00  clr  %o4
a013ffd0:  02 80 00 17  be  0xa014002c
a013ffd4:  90 10 20 00  clr  %o0
a013ffd8:  83 28 60 10  sll  %g1, 0x10, %g1
a013ffdc:  94 10 00 0b  mov  %o3, %o2
a013ffe0:  97 30 60 10  srl  %g1, 0x10, %o3
a013ffe4:  92 10 00 0d  mov  %o5, %o1
a013ffe8:  9b 2a 20 03  sll  %o0, 3, %o5
a013ffec:  82 03 40 08  add  %o5, %o0, %g1
a013fff0:  9b 28 60 02  sll  %g1, 2, %o5
a013fff4:  82 03 40 0a  add  %o5, %o2, %g1
a013fff8:  da 10 60 22  lduh  [ %g1 + 0x22 ], %o5
a013fffc:  80 a3 40 0b  cmp  %o5, %o3
a0140000:  02 80 00 0b  be  0xa014002c
a0140004:  98 03 20 01  inc  %o4
a0140008:  90 0b 20 ff  and  %o4, 0xff, %o0
a014000c:  9b 2a 20 03  sll  %o0, 3, %o5
a0140010:  82 03 40 08  add  %o5, %o0, %g1
a0140014:  9b 28 60 02  sll  %g1, 2, %o5
a0140018:  82 03 40 0a  add  %o5, %o2, %g1
a014001c:  da 10 60 02  lduh  [ %g1 + 2 ], %o5
a0140020:  80 a3 40 09  cmp  %o5, %o1
a0140024:  12 bf ff f2  bne  0xa013ffec
a0140028:  9b 2a 20 03  sll  %o0, 3, %o5
a014002c:  81 c3 e0 08  retl
a0140030:  01 00 00 00  nop
