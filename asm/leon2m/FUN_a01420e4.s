# leon2m FUN_a01420e4 0xa01420e4-0xa0142110 (44 bytes)
a01420e4:  90 0a 20 ff  and  %o0, 0xff, %o0
a01420e8:  9b 2a 20 03  sll  %o0, 3, %o5
a01420ec:  82 03 40 08  add  %o5, %o0, %g1
a01420f0:  1b 2a 00 b8  sethi  %hi(0xa802e000), %o5
a01420f4:  90 00 40 01  add  %g1, %g1, %o0
a01420f8:  9a 13 61 16  or  %o5, 0x116, %o5
a01420fc:  82 02 00 0d  add  %o0, %o5, %g1
a0142100:  da 10 60 02  lduh  [ %g1 + 2 ], %o5
a0142104:  91 33 60 06  srl  %o5, 6, %o0
a0142108:  81 c3 e0 08  retl
a014210c:  90 0a 20 01  and  %o0, 1, %o0
