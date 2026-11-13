# leon2m FUN_a0119114 0xa0119114-0xa0119148 (52 bytes)
a0119114:  9d e3 bf 98  save  %sp, -104, %sp
a0119118:  40 00 0f 9c  call  0xa011cf88
a011911c:  01 00 00 00  nop
a0119120:  03 33 c0 4b  sethi  %hi(0xcf012c00), %g1
a0119124:  90 0a 20 ff  and  %o0, 0xff, %o0
a0119128:  80 a2 20 83  cmp  %o0, 0x83
a011912c:  08 80 00 05  bleu  0xa0119140
a0119130:  9a 10 63 74  or  %g1, 0x374, %o5
a0119134:  d4 03 40 00  ld  [ %o5 ], %o2
a0119138:  92 0a bf fd  and  %o2, -3, %o1
a011913c:  d2 23 40 00  st  %o1, [ %o5 ]
a0119140:  81 c7 e0 08  ret
a0119144:  81 e8 00 00  restore
