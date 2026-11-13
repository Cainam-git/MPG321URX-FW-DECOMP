# leon2m FUN_a0134684 0xa0134684-0xa01346ac (40 bytes)
a0134684:  19 2a 00 b2  sethi  %hi(0xa802c800), %o4
a0134688:  c2 0b 23 8d  ldub  [ %o4 + 0x38d ], %g1	! 0xa802cb8d
a013468c:  82 00 60 01  inc  %g1
a0134690:  9a 08 60 ff  and  %g1, 0xff, %o5
a0134694:  80 a3 60 03  cmp  %o5, 3
a0134698:  28 80 00 03  bleu,a   0xa01346a4
a013469c:  c2 2b 23 8d  stb  %g1, [ %o4 + 0x38d ]
a01346a0:  c0 2b 23 8d  clrb  [ %o4 + 0x38d ]
a01346a4:  81 c3 e0 08  retl
a01346a8:  01 00 00 00  nop
