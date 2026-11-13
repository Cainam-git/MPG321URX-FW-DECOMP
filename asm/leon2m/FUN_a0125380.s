# leon2m FUN_a0125380 0xa0125380-0xa01253bc (60 bytes)
a0125380:  19 2a 00 b6  sethi  %hi(0xa802d800), %o4
a0125384:  9a 0a 20 ff  and  %o0, 0xff, %o5
a0125388:  82 13 20 80  or  %o4, 0x80, %g1
a012538c:  d8 08 40 0d  ldub  [ %g1 + %o5 ], %o4
a0125390:  11 00 06 90  sethi  %hi(0x1a4000), %o0
a0125394:  82 12 22 a8  or  %o0, 0x2a8, %g1	! 0x1a42a8
a0125398:  9a 5b 20 16  smul  %o4, 0x16, %o5
a012539c:  9a 03 40 01  add  %o5, %g1, %o5
a01253a0:  80 a3 20 ff  cmp  %o4, 0xff
a01253a4:  02 80 00 03  be  0xa01253b0
a01253a8:  90 10 3f ff  mov  -1, %o0
a01253ac:  d0 13 60 06  lduh  [ %o5 + 6 ], %o0
a01253b0:  91 2a 20 10  sll  %o0, 0x10, %o0
a01253b4:  81 c3 e0 08  retl
a01253b8:  91 32 20 10  srl  %o0, 0x10, %o0
