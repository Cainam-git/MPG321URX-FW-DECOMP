# leon2m FUN_a014a0d8 0xa014a0d8-0xa014a11c (68 bytes)
a014a0d8:  9d e3 bf 98  save  %sp, -104, %sp
a014a0dc:  21 2a 00 b8  sethi  %hi(0xa802e000), %l0
a014a0e0:  da 04 23 d0  ld  [ %l0 + 0x3d0 ], %o5	! 0xa802e3d0
a014a0e4:  92 0e 20 01  and  %i0, 1, %o1
a014a0e8:  15 00 40 00  sethi  %hi(0x1000000), %o2
a014a0ec:  90 2b 40 0a  andn  %o5, %o2, %o0
a014a0f0:  b1 2a 60 18  sll  %o1, 0x18, %i0
a014a0f4:  82 12 00 18  or  %o0, %i0, %g1
a014a0f8:  c2 24 23 d0  st  %g1, [ %l0 + 0x3d0 ]
a014a0fc:  90 10 20 10  mov  0x10, %o0
a014a100:  40 00 1e 69  call  0xa0151aa4
a014a104:  92 10 20 01  mov  1, %o1
a014a108:  f2 0c 23 d0  ldub  [ %l0 + 0x3d0 ], %i1
a014a10c:  b2 0e 60 01  and  %i1, 1, %i1
a014a110:  7f ff 84 86  call  0xa012b328
a014a114:  91 e8 20 00  restore  %g0, 0, %o0
a014a118:  01 00 00 00  nop
