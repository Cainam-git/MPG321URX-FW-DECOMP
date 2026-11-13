# leon2m FUN_a00837e4 0xa00837e4-0xa008380c (40 bytes)
a00837e4:  1b 2a 00 b5  sethi  %hi(0xa802d400), %o5
a00837e8:  c2 0b 60 34  ldub  [ %o5 + 0x34 ], %g1	! 0xa802d434
a00837ec:  90 00 7f fc  add  %g1, -4, %o0
a00837f0:  82 0a 20 ff  and  %o0, 0xff, %g1
a00837f4:  80 a0 60 02  cmp  %g1, 2
a00837f8:  18 80 00 03  bgu  0xa0083804
a00837fc:  90 10 20 00  clr  %o0
a0083800:  90 10 20 01  mov  1, %o0
a0083804:  81 c3 e0 08  retl
a0083808:  90 0a 20 01  and  %o0, 1, %o0
