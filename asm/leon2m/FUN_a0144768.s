# leon2m FUN_a0144768 0xa0144768-0xa01447bc (84 bytes)
a0144768:  03 00 06 9b  sethi  %hi(0x1a6c00), %g1
a014476c:  96 0a 20 ff  and  %o0, 0xff, %o3
a0144770:  94 10 61 a3  or  %g1, 0x1a3, %o2
a0144774:  98 10 20 00  clr  %o4
a0144778:  9a 10 20 00  clr  %o5
a014477c:  90 03 40 0d  add  %o5, %o5, %o0
a0144780:  82 02 00 0d  add  %o0, %o5, %g1
a0144784:  90 00 40 0a  add  %g1, %o2, %o0
a0144788:  98 03 20 01  inc  %o4
a014478c:  c2 0a 20 01  ldub  [ %o0 + 1 ], %g1
a0144790:  80 a0 40 0b  cmp  %g1, %o3
a0144794:  02 80 00 07  be  0xa01447b0
a0144798:  9a 0b 20 ff  and  %o4, 0xff, %o5
a014479c:  80 a3 60 04  cmp  %o5, 4
a01447a0:  28 bf ff f8  bleu,a   0xa0144780
a01447a4:  90 03 40 0d  add  %o5, %o5, %o0
a01447a8:  10 80 00 03  b  0xa01447b4
a01447ac:  90 10 20 00  clr  %o0
a01447b0:  d0 0a 20 02  ldub  [ %o0 + 2 ], %o0
a01447b4:  81 c3 e0 08  retl
a01447b8:  01 00 00 00  nop
