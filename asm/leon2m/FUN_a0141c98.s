# leon2m FUN_a0141c98 0xa0141c98-0xa0141ce0 (72 bytes)
a0141c98:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a0141c9c:  94 10 61 16  or  %g1, 0x116, %o2	! 0xa802e116
a0141ca0:  96 10 20 00  clr  %o3
a0141ca4:  98 10 20 00  clr  %o4
a0141ca8:  13 00 00 04  sethi  %hi(0x1000), %o1
a0141cac:  83 2b 20 03  sll  %o4, 3, %g1
a0141cb0:  9a 00 40 0c  add  %g1, %o4, %o5
a0141cb4:  9a 03 40 0d  add  %o5, %o5, %o5
a0141cb8:  c2 12 80 0d  lduh  [ %o2 + %o5 ], %g1
a0141cbc:  98 08 6f ff  and  %g1, 0xfff, %o4
a0141cc0:  82 13 00 09  or  %o4, %o1, %g1
a0141cc4:  96 02 e0 01  inc  %o3
a0141cc8:  98 0a e0 ff  and  %o3, 0xff, %o4
a0141ccc:  80 a3 20 06  cmp  %o4, 6
a0141cd0:  08 bf ff f7  bleu  0xa0141cac
a0141cd4:  c2 32 80 0d  sth  %g1, [ %o2 + %o5 ]
a0141cd8:  81 c3 e0 08  retl
a0141cdc:  01 00 00 00  nop
