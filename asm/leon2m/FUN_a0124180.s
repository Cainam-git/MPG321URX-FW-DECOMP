# leon2m FUN_a0124180 0xa0124180-0xa01241fc (124 bytes)
a0124180:  9d e3 bf 90  save  %sp, -112, %sp
a0124184:  31 00 06 8c  sethi  %hi(0x1a3000), %i0
a0124188:  d8 1e 20 d0  ldd  [ %i0 + 0xd0 ], %o4	! 0x1a30d0
a012418c:  39 2a 00 b8  sethi  %hi(0xa802e000), %i4
a0124190:  82 16 20 d0  or  %i0, 0xd0, %g1
a0124194:  d8 3f 23 78  std  %o4, [ %i4 + 0x378 ]
a0124198:  d8 18 60 50  ldd  [ %g1 + 0x50 ], %o4
a012419c:  d8 3f bf f0  std  %o4, [ %fp + -16 ]
a01241a0:  ba 17 23 78  or  %i4, 0x378, %i5
a01241a4:  d8 18 60 18  ldd  [ %g1 + 0x18 ], %o4
a01241a8:  d8 3f 60 18  std  %o4, [ %i5 + 0x18 ]
a01241ac:  d8 1f bf f0  ldd  [ %fp + -16 ], %o4
a01241b0:  f4 18 60 08  ldd  [ %g1 + 8 ], %i2
a01241b4:  f0 18 60 10  ldd  [ %g1 + 0x10 ], %i0
a01241b8:  d4 18 60 20  ldd  [ %g1 + 0x20 ], %o2
a01241bc:  d0 18 60 28  ldd  [ %g1 + 0x28 ], %o0
a01241c0:  e0 18 60 30  ldd  [ %g1 + 0x30 ], %l0
a01241c4:  e4 18 60 38  ldd  [ %g1 + 0x38 ], %l2
a01241c8:  e8 18 60 40  ldd  [ %g1 + 0x40 ], %l4
a01241cc:  ec 18 60 48  ldd  [ %g1 + 0x48 ], %l6
a01241d0:  d8 3f 60 50  std  %o4, [ %i5 + 0x50 ]
a01241d4:  f4 3f 60 08  std  %i2, [ %i5 + 8 ]
a01241d8:  f0 3f 60 10  std  %i0, [ %i5 + 0x10 ]
a01241dc:  d4 3f 60 20  std  %o2, [ %i5 + 0x20 ]
a01241e0:  d0 3f 60 28  std  %o0, [ %i5 + 0x28 ]
a01241e4:  e0 3f 60 30  std  %l0, [ %i5 + 0x30 ]
a01241e8:  e4 3f 60 38  std  %l2, [ %i5 + 0x38 ]
a01241ec:  e8 3f 60 40  std  %l4, [ %i5 + 0x40 ]
a01241f0:  ec 3f 60 48  std  %l6, [ %i5 + 0x48 ]
a01241f4:  81 c7 e0 08  ret
a01241f8:  81 e8 00 00  restore
