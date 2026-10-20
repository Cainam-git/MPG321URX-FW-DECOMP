# leon2m FUN_a0148eb4 0xa0148eb4-0xa0148ef4 (64 bytes)
a0148eb4:  9d e3 bf 98  save  %sp, -104, %sp
a0148eb8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0148ebc:  17 00 06 9b  sethi  %hi(0x1a6c00), %o3
a0148ec0:  92 10 00 18  mov  %i0, %o1
a0148ec4:  7f fe 58 ab  call  0xa00df170
a0148ec8:  90 12 e3 78  or  %o3, 0x378, %o0
a0148ecc:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a0148ed0:  da 03 23 d0  ld  [ %o4 + 0x3d0 ], %o5	! 0xa802e3d0
a0148ed4:  92 0e 20 01  and  %i0, 1, %o1
a0148ed8:  15 01 00 00  sethi  %hi(0x4000000), %o2
a0148edc:  90 2b 40 0a  andn  %o5, %o2, %o0
a0148ee0:  b1 2a 60 1a  sll  %o1, 0x1a, %i0
a0148ee4:  82 12 00 18  or  %o0, %i0, %g1
a0148ee8:  c2 23 23 d0  st  %g1, [ %o4 + 0x3d0 ]
a0148eec:  81 c7 e0 08  ret
a0148ef0:  81 e8 00 00  restore
