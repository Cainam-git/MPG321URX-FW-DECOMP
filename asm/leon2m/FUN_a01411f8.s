# leon2m FUN_a01411f8 0xa01411f8-0xa014122c (52 bytes)
a01411f8:  9d e3 bf 98  save  %sp, -104, %sp
a01411fc:  7f ff 5f a8  call  0xa011909c
a0141200:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0141204:  98 0a 20 ff  and  %o0, 0xff, %o4
a0141208:  97 2e 20 04  sll  %i0, 4, %o3
a014120c:  94 02 c0 0c  add  %o3, %o4, %o2
a0141210:  13 00 06 8d  sethi  %hi(0x1a3400), %o1
a0141214:  90 02 80 0a  add  %o2, %o2, %o0
a0141218:  82 12 62 48  or  %o1, 0x248, %g1
a014121c:  b0 02 00 01  add  %o0, %g1, %i0
a0141220:  f0 0e 20 01  ldub  [ %i0 + 1 ], %i0
a0141224:  81 c7 e0 08  ret
a0141228:  81 e8 00 00  restore
