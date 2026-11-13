# leon2m FUN_a011c8e4 0xa011c8e4-0xa011c998 (180 bytes)
a011c8e4:  92 0a 60 ff  and  %o1, 0xff, %o1
a011c8e8:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a011c8ec:  9a 10 20 40  mov  0x40, %o5
a011c8f0:  80 a2 60 00  cmp  %o1, 0
a011c8f4:  02 80 00 05  be  0xa011c908
a011c8f8:  82 10 63 80  or  %g1, 0x380, %g1
a011c8fc:  19 33 c0 45  sethi  %hi(0xcf011400), %o4
a011c900:  9a 10 20 40  mov  0x40, %o5
a011c904:  82 13 23 94  or  %o4, 0x394, %g1
a011c908:  da 20 40 00  st  %o5, [ %g1 ]
a011c90c:  82 10 20 9f  mov  0x9f, %g1
a011c910:  01 00 00 00  nop
a011c914:  82 80 7f ff  addcc  %g1, -1, %g1
a011c918:  1c bf ff fe  bpos  0xa011c910
a011c91c:  80 a2 60 00  cmp  %o1, 0
a011c920:  91 2a 20 10  sll  %o0, 0x10, %o0
a011c924:  12 80 00 0e  bne  0xa011c95c
a011c928:  9b 32 20 10  srl  %o0, 0x10, %o5
a011c92c:  19 33 c0 45  sethi  %hi(0xcf011400), %o4
a011c930:  92 0b 60 ff  and  %o5, 0xff, %o1
a011c934:  82 13 23 84  or  %o4, 0x384, %g1
a011c938:  d2 20 40 00  st  %o1, [ %g1 ]
a011c93c:  92 13 23 88  or  %o4, 0x388, %o1
a011c940:  9b 32 20 18  srl  %o0, 0x18, %o5
a011c944:  da 22 40 00  st  %o5, [ %o1 ]
a011c948:  03 33 c0 2f  sethi  %hi(0xcf00bc00), %g1
a011c94c:  90 10 63 cc  or  %g1, 0x3cc, %o0	! 0xcf00bfcc
a011c950:  c0 22 00 00  clr  [ %o0 ]
a011c954:  10 80 00 0b  b  0xa011c980
a011c958:  82 10 20 9f  mov  0x9f, %g1
a011c95c:  13 33 c0 45  sethi  %hi(0xcf011400), %o1
a011c960:  98 0b 60 ff  and  %o5, 0xff, %o4
a011c964:  82 12 63 98  or  %o1, 0x398, %g1
a011c968:  d8 20 40 00  st  %o4, [ %g1 ]
a011c96c:  98 12 63 9c  or  %o1, 0x39c, %o4
a011c970:  9b 32 20 18  srl  %o0, 0x18, %o5
a011c974:  da 23 00 00  st  %o5, [ %o4 ]
a011c978:  10 bf ff f5  b  0xa011c94c
a011c97c:  03 33 c0 30  sethi  %hi(0xcf00c000), %g1
a011c980:  01 00 00 00  nop
a011c984:  82 80 7f ff  addcc  %g1, -1, %g1
a011c988:  1c bf ff fe  bpos  0xa011c980
a011c98c:  01 00 00 00  nop
a011c990:  81 c3 e0 08  retl
a011c994:  01 00 00 00  nop
