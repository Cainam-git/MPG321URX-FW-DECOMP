# leon2m FUN_a002fae0 0xa002fae0-0xa002fb44 (100 bytes)
a002fae0:  9d e3 bf 98  save  %sp, -104, %sp
a002fae4:  03 2a 00 b7  sethi  %hi(0xa802dc00), %g1
a002fae8:  a4 10 63 30  or  %g1, 0x330, %l2	! 0xa802df30
a002faec:  a2 10 20 00  clr  %l1
a002faf0:  9a 10 20 00  clr  %o5
a002faf4:  95 2b 60 04  sll  %o5, 4, %o2
a002faf8:  90 22 80 0d  sub  %o2, %o5, %o0
a002fafc:  7f ff f1 c2  call  0xa002c204
a002fb00:  a1 2a 20 03  sll  %o0, 3, %l0
a002fb04:  92 04 00 12  add  %l0, %l2, %o1
a002fb08:  da 0a 60 76  ldub  [ %o1 + 0x76 ], %o5
a002fb0c:  a2 04 60 01  inc  %l1
a002fb10:  80 8a 00 0d  btst  %o0, %o5
a002fb14:  02 80 00 06  be  0xa002fb2c
a002fb18:  92 10 20 01  mov  1, %o1
a002fb1c:  d8 04 80 10  ld  [ %l2 + %l0 ], %o4
a002fb20:  97 33 20 0c  srl  %o4, 0xc, %o3
a002fb24:  7f ff fa 28  call  0xa002e3c4
a002fb28:  90 0a e0 0f  and  %o3, 0xf, %o0
a002fb2c:  9a 0c 60 ff  and  %l1, 0xff, %o5
a002fb30:  80 a3 60 03  cmp  %o5, 3
a002fb34:  08 bf ff f1  bleu  0xa002faf8
a002fb38:  95 2b 60 04  sll  %o5, 4, %o2
a002fb3c:  81 c7 e0 08  ret
a002fb40:  81 e8 00 00  restore
