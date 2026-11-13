# leon2m FUN_a015b738 0xa015b738-0xa015b75c (36 bytes)
a015b738:  9d e3 bf 98  save  %sp, -104, %sp
a015b73c:  c2 16 20 0c  lduh  [ %i0 + 0xc ], %g1
a015b740:  80 88 62 00  btst  0x200, %g1
a015b744:  12 80 00 04  bne  0xa015b754
a015b748:  90 06 20 58  add  %i0, 0x58, %o0
a015b74c:  40 00 0c af  call  0xa015ea08
a015b750:  01 00 00 00  nop
a015b754:  81 c7 e0 08  ret
a015b758:  91 e8 20 00  restore  %g0, 0, %o0
