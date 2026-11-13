# leon2m FUN_a0146fdc 0xa0146fdc-0xa014705c (128 bytes)
a0146fdc:  90 0a 20 ff  and  %o0, 0xff, %o0
a0146fe0:  80 a2 20 01  cmp  %o0, 1
a0146fe4:  02 80 00 15  be  0xa0147038
a0146fe8:  9a 10 20 04  mov  4, %o5
a0146fec:  80 a2 20 01  cmp  %o0, 1
a0146ff0:  04 80 00 16  ble  0xa0147048
a0146ff4:  80 a2 20 02  cmp  %o0, 2
a0146ff8:  02 80 00 12  be  0xa0147040
a0146ffc:  80 a2 20 03  cmp  %o0, 3
a0147000:  22 80 00 02  be,a   0xa0147008
a0147004:  9a 10 20 03  mov  3, %o5
a0147008:  82 0a 60 ff  and  %o1, 0xff, %g1
a014700c:  80 a0 60 01  cmp  %g1, 1
a0147010:  02 80 00 06  be  0xa0147028
a0147014:  01 00 00 00  nop
a0147018:  90 0b 60 07  and  %o5, 7, %o0
a014701c:  82 13 c0 00  mov  %o7, %g1
a0147020:  7f fe bd ec  call  0xa00f67d0
a0147024:  9e 10 40 00  mov  %g1, %o7
a0147028:  90 0b 60 07  and  %o5, 7, %o0
a014702c:  82 13 c0 00  mov  %o7, %g1
a0147030:  7f fe be 1a  call  0xa00f6898
a0147034:  9e 10 40 00  mov  %g1, %o7
a0147038:  10 bf ff f4  b  0xa0147008
a014703c:  9a 10 20 01  mov  1, %o5
a0147040:  10 bf ff f2  b  0xa0147008
a0147044:  9a 10 20 02  mov  2, %o5
a0147048:  80 a2 20 00  cmp  %o0, 0
a014704c:  22 bf ff ef  be,a   0xa0147008
a0147050:  9a 10 20 00  clr  %o5
a0147054:  10 bf ff ee  b  0xa014700c
a0147058:  82 0a 60 ff  and  %o1, 0xff, %g1
