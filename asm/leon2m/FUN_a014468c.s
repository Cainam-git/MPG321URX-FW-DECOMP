# leon2m FUN_a014468c 0xa014468c-0xa01446e0 (84 bytes)
a014468c:  03 00 06 9b  sethi  %hi(0x1a6c00), %g1
a0144690:  96 0a 20 ff  and  %o0, 0xff, %o3
a0144694:  94 10 61 a3  or  %g1, 0x1a3, %o2
a0144698:  98 10 20 00  clr  %o4
a014469c:  9a 10 20 00  clr  %o5
a01446a0:  90 03 40 0d  add  %o5, %o5, %o0
a01446a4:  82 02 00 0d  add  %o0, %o5, %g1
a01446a8:  90 00 40 0a  add  %g1, %o2, %o0
a01446ac:  98 03 20 01  inc  %o4
a01446b0:  c2 0a 20 02  ldub  [ %o0 + 2 ], %g1
a01446b4:  80 a0 40 0b  cmp  %g1, %o3
a01446b8:  02 80 00 07  be  0xa01446d4
a01446bc:  9a 0b 20 ff  and  %o4, 0xff, %o5
a01446c0:  80 a3 60 04  cmp  %o5, 4
a01446c4:  28 bf ff f8  bleu,a   0xa01446a4
a01446c8:  90 03 40 0d  add  %o5, %o5, %o0
a01446cc:  10 80 00 03  b  0xa01446d8
a01446d0:  90 10 20 ff  mov  0xff, %o0
a01446d4:  d0 0a 20 01  ldub  [ %o0 + 1 ], %o0
a01446d8:  81 c3 e0 08  retl
a01446dc:  01 00 00 00  nop
