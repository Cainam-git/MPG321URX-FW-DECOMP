# leon2m FUN_a014ead0 0xa014ead0-0xa014eb14 (68 bytes)
a014ead0:  96 0a 20 ff  and  %o0, 0xff, %o3
a014ead4:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a014ead8:  d8 10 60 80  lduh  [ %g1 + 0x80 ], %o4	! 0xa802cc80
a014eadc:  9a 10 20 00  clr  %o5
a014eae0:  90 10 20 00  clr  %o0
a014eae4:  83 2a 20 02  sll  %o0, 2, %g1
a014eae8:  83 3b 00 01  sra  %o4, %g1, %g1
a014eaec:  82 08 60 0f  and  %g1, 0xf, %g1
a014eaf0:  80 a0 40 0b  cmp  %g1, %o3
a014eaf4:  02 80 00 06  be  0xa014eb0c
a014eaf8:  9a 03 60 01  inc  %o5
a014eafc:  90 0b 60 ff  and  %o5, 0xff, %o0
a014eb00:  80 a2 20 03  cmp  %o0, 3
a014eb04:  08 bf ff f9  bleu  0xa014eae8
a014eb08:  83 2a 20 02  sll  %o0, 2, %g1
a014eb0c:  81 c3 e0 08  retl
a014eb10:  01 00 00 00  nop
