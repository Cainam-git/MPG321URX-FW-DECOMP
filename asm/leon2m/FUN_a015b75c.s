# leon2m FUN_a015b75c 0xa015b75c-0xa015b780 (36 bytes)
a015b75c:  9d e3 bf 98  save  %sp, -104, %sp
a015b760:  c2 16 20 0c  lduh  [ %i0 + 0xc ], %g1
a015b764:  80 88 62 00  btst  0x200, %g1
a015b768:  12 80 00 04  bne  0xa015b778
a015b76c:  90 06 20 58  add  %i0, 0x58, %o0
a015b770:  40 00 0c be  call  0xa015ea68
a015b774:  01 00 00 00  nop
a015b778:  81 c7 e0 08  ret
a015b77c:  91 e8 20 00  restore  %g0, 0, %o0
