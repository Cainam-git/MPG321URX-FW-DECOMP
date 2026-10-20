# leon2m FUN_a014fb84 0xa014fb84-0xa014fbf0 (108 bytes)
a014fb84:  9d e3 bf 98  save  %sp, -104, %sp
a014fb88:  b0 0e 20 ff  and  %i0, 0xff, %i0
a014fb8c:  35 2a 00 a9  sethi  %hi(0xa802a400), %i2
a014fb90:  92 10 20 01  mov  1, %o1
a014fb94:  b2 10 20 ff  mov  0xff, %i1
a014fb98:  80 a6 20 01  cmp  %i0, 1
a014fb9c:  02 80 00 06  be  0xa014fbb4
a014fba0:  b6 10 20 00  clr  %i3
a014fba4:  13 2a 00 a9  sethi  %hi(0xa802a400), %o1
a014fba8:  f0 0a 60 9a  ldub  [ %o1 + 0x9a ], %i0	! 0xa802a49a
a014fbac:  7f ff 39 67  call  0xa011e148
a014fbb0:  81 e8 00 00  restore
a014fbb4:  7f ff 39 1d  call  0xa011e028
a014fbb8:  d0 0e a0 9a  ldub  [ %i2 + 0x9a ], %o0
a014fbbc:  d0 0e a0 9a  ldub  [ %i2 + 0x9a ], %o0
a014fbc0:  7f ff 39 98  call  0xa011e220
a014fbc4:  92 10 20 01  mov  1, %o1
a014fbc8:  11 2a 00 a9  sethi  %hi(0xa802a400), %o0
a014fbcc:  d2 12 20 9e  lduh  [ %o0 + 0x9e ], %o1	! 0xa802a49e
a014fbd0:  7f ff 38 73  call  0xa011dd9c
a014fbd4:  d0 0e a0 9a  ldub  [ %i2 + 0x9a ], %o0
a014fbd8:  f0 0e a0 9a  ldub  [ %i2 + 0x9a ], %i0
a014fbdc:  03 2a 00 a9  sethi  %hi(0xa802a400), %g1
a014fbe0:  f4 10 60 a0  lduh  [ %g1 + 0xa0 ], %i2	! 0xa802a4a0
a014fbe4:  7f ff 36 d9  call  0xa011d748
a014fbe8:  81 e8 00 00  restore
a014fbec:  01 00 00 00  nop
