# leon2m FUN_a011c77c 0xa011c77c-0xa011c830 (180 bytes)
a011c77c:  92 0a 60 ff  and  %o1, 0xff, %o1
a011c780:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a011c784:  9a 10 20 80  mov  0x80, %o5
a011c788:  80 a2 60 00  cmp  %o1, 0
a011c78c:  02 80 00 05  be  0xa011c7a0
a011c790:  82 10 63 80  or  %g1, 0x380, %g1
a011c794:  19 33 c0 45  sethi  %hi(0xcf011400), %o4
a011c798:  9a 10 20 80  mov  0x80, %o5
a011c79c:  82 13 23 94  or  %o4, 0x394, %g1
a011c7a0:  da 20 40 00  st  %o5, [ %g1 ]
a011c7a4:  82 10 20 9f  mov  0x9f, %g1
a011c7a8:  01 00 00 00  nop
a011c7ac:  82 80 7f ff  addcc  %g1, -1, %g1
a011c7b0:  1c bf ff fe  bpos  0xa011c7a8
a011c7b4:  80 a2 60 00  cmp  %o1, 0
a011c7b8:  91 2a 20 10  sll  %o0, 0x10, %o0
a011c7bc:  12 80 00 0e  bne  0xa011c7f4
a011c7c0:  9b 32 20 10  srl  %o0, 0x10, %o5
a011c7c4:  19 33 c0 45  sethi  %hi(0xcf011400), %o4
a011c7c8:  92 0b 60 ff  and  %o5, 0xff, %o1
a011c7cc:  82 13 23 84  or  %o4, 0x384, %g1
a011c7d0:  d2 20 40 00  st  %o1, [ %g1 ]
a011c7d4:  92 13 23 88  or  %o4, 0x388, %o1
a011c7d8:  9b 32 20 18  srl  %o0, 0x18, %o5
a011c7dc:  da 22 40 00  st  %o5, [ %o1 ]
a011c7e0:  03 33 c0 2f  sethi  %hi(0xcf00bc00), %g1
a011c7e4:  90 10 63 cc  or  %g1, 0x3cc, %o0	! 0xcf00bfcc
a011c7e8:  c0 22 00 00  clr  [ %o0 ]
a011c7ec:  10 80 00 0b  b  0xa011c818
a011c7f0:  82 10 20 9f  mov  0x9f, %g1
a011c7f4:  13 33 c0 45  sethi  %hi(0xcf011400), %o1
a011c7f8:  98 0b 60 ff  and  %o5, 0xff, %o4
a011c7fc:  82 12 63 98  or  %o1, 0x398, %g1
a011c800:  d8 20 40 00  st  %o4, [ %g1 ]
a011c804:  98 12 63 9c  or  %o1, 0x39c, %o4
a011c808:  9b 32 20 18  srl  %o0, 0x18, %o5
a011c80c:  da 23 00 00  st  %o5, [ %o4 ]
a011c810:  10 bf ff f5  b  0xa011c7e4
a011c814:  03 33 c0 30  sethi  %hi(0xcf00c000), %g1
a011c818:  01 00 00 00  nop
a011c81c:  82 80 7f ff  addcc  %g1, -1, %g1
a011c820:  1c bf ff fe  bpos  0xa011c818
a011c824:  01 00 00 00  nop
a011c828:  81 c3 e0 08  retl
a011c82c:  01 00 00 00  nop
