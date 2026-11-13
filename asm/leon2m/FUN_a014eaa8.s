# leon2m FUN_a014eaa8 0xa014eaa8-0xa014ead0 (40 bytes)
a014eaa8:  1b 2a 00 b3  sethi  %hi(0xa802cc00), %o5
a014eaac:  d8 13 60 82  lduh  [ %o5 + 0x82 ], %o4	! 0xa802cc82
a014eab0:  90 0a 20 ff  and  %o0, 0xff, %o0
a014eab4:  83 2b 20 10  sll  %o4, 0x10, %g1
a014eab8:  91 2a 20 0c  sll  %o0, 0xc, %o0
a014eabc:  83 30 60 14  srl  %g1, 0x14, %g1
a014eac0:  82 10 40 08  or  %g1, %o0, %g1
a014eac4:  c2 33 60 82  sth  %g1, [ %o5 + 0x82 ]
a014eac8:  81 c3 e0 08  retl
a014eacc:  90 0b 20 0f  and  %o4, 0xf, %o0
