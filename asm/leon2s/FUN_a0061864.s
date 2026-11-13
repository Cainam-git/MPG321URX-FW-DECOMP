# leon2s FUN_a0061864 0xa0061864-0xa00618c0 (92 bytes)
a0061864:  9d e3 bf 98  save  %sp, -104, %sp
a0061868:  b3 36 60 02  srl  %i1, 2, %i1
a006186c:  80 a6 60 00  cmp  %i1, 0
a0061870:  02 80 00 12  be  0xa00618b8
a0061874:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a0061878:  9e 10 63 00  or  %g1, 0x300, %o7	! 0xff00
a006187c:  35 00 3f c0  sethi  %hi(0xff0000), %i2
a0061880:  f6 06 00 00  ld  [ %i0 ], %i3
a0061884:  ba 0e c0 1a  and  %i3, %i2, %i5
a0061888:  b9 36 e0 18  srl  %i3, 0x18, %i4
a006188c:  82 0e c0 0f  and  %i3, %o7, %g1
a0061890:  bb 37 60 08  srl  %i5, 8, %i5
a0061894:  83 28 60 08  sll  %g1, 8, %g1
a0061898:  b8 17 00 1d  or  %i4, %i5, %i4
a006189c:  b8 17 00 01  or  %i4, %g1, %i4
a00618a0:  83 2e e0 18  sll  %i3, 0x18, %g1
a00618a4:  b6 17 00 01  or  %i4, %g1, %i3
a00618a8:  f6 26 00 00  st  %i3, [ %i0 ]
a00618ac:  b2 86 7f ff  addcc  %i1, -1, %i1
a00618b0:  12 bf ff f4  bne  0xa0061880
a00618b4:  b0 06 20 04  add  %i0, 4, %i0
a00618b8:  81 c7 e0 08  ret
a00618bc:  81 e8 00 00  restore
