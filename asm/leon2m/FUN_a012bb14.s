# leon2m FUN_a012bb14 0xa012bb14-0xa012bb38 (36 bytes)
a012bb14:  90 0a 20 ff  and  %o0, 0xff, %o0
a012bb18:  9b 2a 20 03  sll  %o0, 3, %o5
a012bb1c:  82 03 40 08  add  %o5, %o0, %g1
a012bb20:  1b 2a 00 b6  sethi  %hi(0xa802d800), %o5
a012bb24:  91 28 60 02  sll  %g1, 2, %o0
a012bb28:  9a 13 60 dc  or  %o5, 0xdc, %o5
a012bb2c:  82 02 00 0d  add  %o0, %o5, %g1
a012bb30:  81 c3 e0 08  retl
a012bb34:  d2 20 60 14  st  %o1, [ %g1 + 0x14 ]
