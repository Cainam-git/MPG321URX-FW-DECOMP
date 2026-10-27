# leon2m FUN_a01492f0 0xa01492f0-0xa014931c (44 bytes)
a01492f0:  9d e3 bf 98  save  %sp, -104, %sp
a01492f4:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a01492f8:  a0 10 63 d0  or  %g1, 0x3d0, %l0	! 0xa802e3d0
a01492fc:  f0 2c 20 06  stb  %i0, [ %l0 + 6 ]
a0149300:  90 0e 20 ff  and  %i0, 0xff, %o0
a0149304:  7f ff 41 71  call  0xa01198c8
a0149308:  92 10 20 00  clr  %o1
a014930c:  f0 0c 20 06  ldub  [ %l0 + 6 ], %i0
a0149310:  7f ff 41 6e  call  0xa01198c8
a0149314:  93 e8 20 01  restore  %g0, 1, %o1
a0149318:  01 00 00 00  nop
