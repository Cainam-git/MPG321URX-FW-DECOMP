# leon2m FUN_a011c830 0xa011c830-0xa011c8e4 (180 bytes)
a011c830:  92 0a 60 ff  and  %o1, 0xff, %o1
a011c834:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a011c838:  9a 10 20 70  mov  0x70, %o5
a011c83c:  80 a2 60 00  cmp  %o1, 0
a011c840:  02 80 00 05  be  0xa011c854
a011c844:  82 10 63 80  or  %g1, 0x380, %g1
a011c848:  19 33 c0 45  sethi  %hi(0xcf011400), %o4
a011c84c:  9a 10 20 70  mov  0x70, %o5
a011c850:  82 13 23 94  or  %o4, 0x394, %g1
a011c854:  da 20 40 00  st  %o5, [ %g1 ]
a011c858:  82 10 20 9f  mov  0x9f, %g1
a011c85c:  01 00 00 00  nop
a011c860:  82 80 7f ff  addcc  %g1, -1, %g1
a011c864:  1c bf ff fe  bpos  0xa011c85c
a011c868:  80 a2 60 00  cmp  %o1, 0
a011c86c:  91 2a 20 10  sll  %o0, 0x10, %o0
a011c870:  12 80 00 0e  bne  0xa011c8a8
a011c874:  9b 32 20 10  srl  %o0, 0x10, %o5
a011c878:  19 33 c0 45  sethi  %hi(0xcf011400), %o4
a011c87c:  92 0b 60 ff  and  %o5, 0xff, %o1
a011c880:  82 13 23 84  or  %o4, 0x384, %g1
a011c884:  d2 20 40 00  st  %o1, [ %g1 ]
a011c888:  92 13 23 88  or  %o4, 0x388, %o1
a011c88c:  9b 32 20 18  srl  %o0, 0x18, %o5
a011c890:  da 22 40 00  st  %o5, [ %o1 ]
a011c894:  03 33 c0 2f  sethi  %hi(0xcf00bc00), %g1
a011c898:  90 10 63 cc  or  %g1, 0x3cc, %o0	! 0xcf00bfcc
a011c89c:  c0 22 00 00  clr  [ %o0 ]
a011c8a0:  10 80 00 0b  b  0xa011c8cc
a011c8a4:  82 10 20 9f  mov  0x9f, %g1
a011c8a8:  13 33 c0 45  sethi  %hi(0xcf011400), %o1
a011c8ac:  98 0b 60 ff  and  %o5, 0xff, %o4
a011c8b0:  82 12 63 98  or  %o1, 0x398, %g1
a011c8b4:  d8 20 40 00  st  %o4, [ %g1 ]
a011c8b8:  98 12 63 9c  or  %o1, 0x39c, %o4
a011c8bc:  9b 32 20 18  srl  %o0, 0x18, %o5
a011c8c0:  da 23 00 00  st  %o5, [ %o4 ]
a011c8c4:  10 bf ff f5  b  0xa011c898
a011c8c8:  03 33 c0 30  sethi  %hi(0xcf00c000), %g1
a011c8cc:  01 00 00 00  nop
a011c8d0:  82 80 7f ff  addcc  %g1, -1, %g1
a011c8d4:  1c bf ff fe  bpos  0xa011c8cc
a011c8d8:  01 00 00 00  nop
a011c8dc:  81 c3 e0 08  retl
a011c8e0:  01 00 00 00  nop
