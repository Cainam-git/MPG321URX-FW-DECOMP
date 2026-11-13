# leon2m FUN_a0142110 0xa0142110-0xa0142140 (48 bytes)
a0142110:  90 0a 20 ff  and  %o0, 0xff, %o0
a0142114:  9b 2a 20 03  sll  %o0, 3, %o5
a0142118:  98 03 40 08  add  %o5, %o0, %o4
a014211c:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a0142120:  9a 10 61 16  or  %g1, 0x116, %o5	! 0xa802e116
a0142124:  98 03 00 0c  add  %o4, %o4, %o4
a0142128:  d0 13 40 0c  lduh  [ %o5 + %o4 ], %o0
a014212c:  83 32 20 0c  srl  %o0, 0xc, %g1
a0142130:  9a 18 60 05  xor  %g1, 5, %o5
a0142134:  80 a0 00 0d  cmp  %g0, %o5
a0142138:  81 c3 e0 08  retl
a014213c:  90 60 3f ff  subx  %g0, -1, %o0
