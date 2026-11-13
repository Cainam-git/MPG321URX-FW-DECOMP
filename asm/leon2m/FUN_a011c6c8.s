# leon2m FUN_a011c6c8 0xa011c6c8-0xa011c77c (180 bytes)
a011c6c8:  92 0a 60 ff  and  %o1, 0xff, %o1
a011c6cc:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a011c6d0:  9a 10 20 90  mov  0x90, %o5
a011c6d4:  80 a2 60 00  cmp  %o1, 0
a011c6d8:  02 80 00 05  be  0xa011c6ec
a011c6dc:  82 10 63 80  or  %g1, 0x380, %g1
a011c6e0:  19 33 c0 45  sethi  %hi(0xcf011400), %o4
a011c6e4:  9a 10 20 90  mov  0x90, %o5
a011c6e8:  82 13 23 94  or  %o4, 0x394, %g1
a011c6ec:  da 20 40 00  st  %o5, [ %g1 ]
a011c6f0:  82 10 20 9f  mov  0x9f, %g1
a011c6f4:  01 00 00 00  nop
a011c6f8:  82 80 7f ff  addcc  %g1, -1, %g1
a011c6fc:  1c bf ff fe  bpos  0xa011c6f4
a011c700:  80 a2 60 00  cmp  %o1, 0
a011c704:  91 2a 20 10  sll  %o0, 0x10, %o0
a011c708:  12 80 00 0e  bne  0xa011c740
a011c70c:  9b 32 20 10  srl  %o0, 0x10, %o5
a011c710:  19 33 c0 45  sethi  %hi(0xcf011400), %o4
a011c714:  92 0b 60 ff  and  %o5, 0xff, %o1
a011c718:  82 13 23 84  or  %o4, 0x384, %g1
a011c71c:  d2 20 40 00  st  %o1, [ %g1 ]
a011c720:  92 13 23 88  or  %o4, 0x388, %o1
a011c724:  9b 32 20 18  srl  %o0, 0x18, %o5
a011c728:  da 22 40 00  st  %o5, [ %o1 ]
a011c72c:  03 33 c0 2f  sethi  %hi(0xcf00bc00), %g1
a011c730:  90 10 63 cc  or  %g1, 0x3cc, %o0	! 0xcf00bfcc
a011c734:  c0 22 00 00  clr  [ %o0 ]
a011c738:  10 80 00 0b  b  0xa011c764
a011c73c:  82 10 20 9f  mov  0x9f, %g1
a011c740:  13 33 c0 45  sethi  %hi(0xcf011400), %o1
a011c744:  98 0b 60 ff  and  %o5, 0xff, %o4
a011c748:  82 12 63 98  or  %o1, 0x398, %g1
a011c74c:  d8 20 40 00  st  %o4, [ %g1 ]
a011c750:  98 12 63 9c  or  %o1, 0x39c, %o4
a011c754:  9b 32 20 18  srl  %o0, 0x18, %o5
a011c758:  da 23 00 00  st  %o5, [ %o4 ]
a011c75c:  10 bf ff f5  b  0xa011c730
a011c760:  03 33 c0 30  sethi  %hi(0xcf00c000), %g1
a011c764:  01 00 00 00  nop
a011c768:  82 80 7f ff  addcc  %g1, -1, %g1
a011c76c:  1c bf ff fe  bpos  0xa011c764
a011c770:  01 00 00 00  nop
a011c774:  81 c3 e0 08  retl
a011c778:  01 00 00 00  nop
