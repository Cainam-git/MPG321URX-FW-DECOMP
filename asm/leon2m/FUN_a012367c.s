# leon2m FUN_a012367c 0xa012367c-0xa01236e8 (108 bytes)
a012367c:  19 33 c0 f1  sethi  %hi(0xcf03c400), %o4
a0123680:  96 13 22 70  or  %o4, 0x270, %o3	! 0xcf03c670
a0123684:  83 32 20 18  srl  %o0, 0x18, %g1
a0123688:  c2 22 c0 00  st  %g1, [ %o3 ]
a012368c:  9b 32 20 10  srl  %o0, 0x10, %o5
a0123690:  96 13 22 74  or  %o4, 0x274, %o3
a0123694:  9a 0b 60 ff  and  %o5, 0xff, %o5
a0123698:  da 22 c0 00  st  %o5, [ %o3 ]
a012369c:  83 32 20 08  srl  %o0, 8, %g1
a01236a0:  96 08 60 ff  and  %g1, 0xff, %o3
a01236a4:  9a 13 22 78  or  %o4, 0x278, %o5
a01236a8:  d6 23 40 00  st  %o3, [ %o5 ]
a01236ac:  82 0a 20 ff  and  %o0, 0xff, %g1
a01236b0:  96 13 22 7c  or  %o4, 0x27c, %o3
a01236b4:  c2 22 c0 00  st  %g1, [ %o3 ]
a01236b8:  9a 13 22 64  or  %o4, 0x264, %o5
a01236bc:  90 10 20 ff  mov  0xff, %o0
a01236c0:  d0 23 40 00  st  %o0, [ %o5 ]
a01236c4:  98 13 22 60  or  %o4, 0x260, %o4
a01236c8:  82 10 20 31  mov  0x31, %g1
a01236cc:  c2 23 00 00  st  %g1, [ %o4 ]
a01236d0:  d0 03 00 00  ld  [ %o4 ], %o0
a01236d4:  80 a2 20 31  cmp  %o0, 0x31
a01236d8:  02 bf ff fe  be  0xa01236d0
a01236dc:  01 00 00 00  nop
a01236e0:  81 c3 e0 08  retl
a01236e4:  01 00 00 00  nop
