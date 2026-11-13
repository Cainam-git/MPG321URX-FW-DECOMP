# leon2s FUN_a00cc9f8 0xa00cc9f8-0xa00cca38 (64 bytes)
a00cc9f8:  9d e3 bf 90  save  %sp, -112, %sp
a00cc9fc:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00cca00:  92 07 bf f0  add  %fp, -16, %o1
a00cca04:  7f ff f3 65  call  0xa00c9798
a00cca08:  90 10 00 18  mov  %i0, %o0
a00cca0c:  90 10 00 18  mov  %i0, %o0
a00cca10:  c2 0f bf f1  ldub  [ %fp + -15 ], %g1
a00cca14:  92 10 20 00  clr  %o1
a00cca18:  80 88 60 08  btst  8, %g1
a00cca1c:  02 80 00 04  be  0xa00cca2c
a00cca20:  b0 10 20 00  clr  %i0
a00cca24:  7f ff ec 0a  call  0xa00c7a4c
a00cca28:  b0 10 20 01  mov  1, %i0
a00cca2c:  b0 0e 20 01  and  %i0, 1, %i0
a00cca30:  81 c7 e0 08  ret
a00cca34:  81 e8 00 00  restore
