# leon2m FUN_a012cf64 0xa012cf64-0xa012cfac (72 bytes)
a012cf64:  03 00 06 94  sethi  %hi(0x1a5000), %g1
a012cf68:  94 10 61 68  or  %g1, 0x168, %o2	! 0x1a5168
a012cf6c:  90 0a 20 ff  and  %o0, 0xff, %o0
a012cf70:  96 10 20 00  clr  %o3
a012cf74:  98 10 20 00  clr  %o4
a012cf78:  83 2b 20 02  sll  %o4, 2, %g1
a012cf7c:  da 12 80 01  lduh  [ %o2 + %g1 ], %o5
a012cf80:  80 a2 00 0d  cmp  %o0, %o5
a012cf84:  02 80 00 06  be  0xa012cf9c
a012cf88:  96 02 e0 01  inc  %o3
a012cf8c:  98 0a e0 ff  and  %o3, 0xff, %o4
a012cf90:  80 a3 20 0b  cmp  %o4, 0xb
a012cf94:  08 bf ff fa  bleu  0xa012cf7c
a012cf98:  83 2b 20 02  sll  %o4, 2, %g1
a012cf9c:  91 2b 20 02  sll  %o4, 2, %o0
a012cfa0:  96 02 00 0a  add  %o0, %o2, %o3
a012cfa4:  81 c3 e0 08  retl
a012cfa8:  d0 12 e0 02  lduh  [ %o3 + 2 ], %o0
