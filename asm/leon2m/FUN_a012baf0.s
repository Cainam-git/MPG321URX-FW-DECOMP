# leon2m FUN_a012baf0 0xa012baf0-0xa012bb14 (36 bytes)
a012baf0:  90 0a 20 ff  and  %o0, 0xff, %o0
a012baf4:  9b 2a 20 03  sll  %o0, 3, %o5
a012baf8:  82 03 40 08  add  %o5, %o0, %g1
a012bafc:  1b 2a 00 b6  sethi  %hi(0xa802d800), %o5
a012bb00:  91 28 60 02  sll  %g1, 2, %o0
a012bb04:  9a 13 60 dc  or  %o5, 0xdc, %o5
a012bb08:  82 02 00 0d  add  %o0, %o5, %g1
a012bb0c:  81 c3 e0 08  retl
a012bb10:  c0 30 60 1c  clrh  [ %g1 + 0x1c ]
