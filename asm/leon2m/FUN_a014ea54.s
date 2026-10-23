# leon2m FUN_a014ea54 0xa014ea54-0xa014eaa8 (84 bytes)
a014ea54:  13 2a 00 b3  sethi  %hi(0xa802cc00), %o1
a014ea58:  94 0a 20 ff  and  %o0, 0xff, %o2
a014ea5c:  98 10 20 00  clr  %o4
a014ea60:  9a 10 20 00  clr  %o5
a014ea64:  d6 12 60 82  lduh  [ %o1 + 0x82 ], %o3
a014ea68:  83 2a e0 10  sll  %o3, 0x10, %g1
a014ea6c:  91 2b 60 02  sll  %o5, 2, %o0
a014ea70:  83 30 60 10  srl  %g1, 0x10, %g1
a014ea74:  98 03 20 01  inc  %o4
a014ea78:  83 38 40 08  sra  %g1, %o0, %g1
a014ea7c:  80 88 60 0f  btst  0xf, %g1
a014ea80:  02 80 00 06  be  0xa014ea98
a014ea84:  9a 0b 20 ff  and  %o4, 0xff, %o5
a014ea88:  80 a3 60 03  cmp  %o5, 3
a014ea8c:  08 bf ff f8  bleu  0xa014ea6c
a014ea90:  83 2a e0 10  sll  %o3, 0x10, %g1
a014ea94:  30 80 00 03  b,a   0xa014eaa0
a014ea98:  99 2a 80 08  sll  %o2, %o0, %o4
a014ea9c:  96 13 00 0b  or  %o4, %o3, %o3
a014eaa0:  81 c3 e0 08  retl
a014eaa4:  d6 32 60 82  sth  %o3, [ %o1 + 0x82 ]
