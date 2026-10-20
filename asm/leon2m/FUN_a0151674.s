# leon2m FUN_a0151674 0xa0151674-0xa01516b0 (60 bytes)
a0151674:  9d e3 bf 98  save  %sp, -104, %sp
a0151678:  7f ff 4a e1  call  0xa01241fc
a015167c:  01 00 00 00  nop
a0151680:  d2 02 00 00  ld  [ %o0 ], %o1
a0151684:  1b 00 1c 00  sethi  %hi(0x700000), %o5
a0151688:  82 0a 40 0d  and  %o1, %o5, %g1
a015168c:  19 00 04 00  sethi  %hi(0x100000), %o4
a0151690:  80 a0 40 0c  cmp  %g1, %o4
a0151694:  12 80 00 04  bne  0xa01516a4
a0151698:  01 00 00 00  nop
a015169c:  7f ff 45 9c  call  0xa0122d0c
a01516a0:  81 e8 00 00  restore
a01516a4:  01 00 00 00  nop
a01516a8:  81 c7 e0 08  ret
a01516ac:  81 e8 00 00  restore
