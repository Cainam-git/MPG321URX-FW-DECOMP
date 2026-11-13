# leon2m FUN_a0154458 0xa0154458-0xa01544cc (116 bytes)
a0154458:  9d e3 bf 90  save  %sp, -112, %sp
a015445c:  31 00 00 80  sethi  %hi(0x20000), %i0
a0154460:  82 16 20 00  mov  %i0, %g1	! 0x20000
a0154464:  d8 18 61 b8  ldd  [ %g1 + 0x1b8 ], %o4
a0154468:  d8 3f bf f0  std  %o4, [ %fp + -16 ]
a015446c:  39 2a 00 b8  sethi  %hi(0xa802e000), %i4
a0154470:  f4 18 61 70  ldd  [ %g1 + 0x170 ], %i2
a0154474:  f4 3f 21 a0  std  %i2, [ %i4 + 0x1a0 ]
a0154478:  ba 17 21 a0  or  %i4, 0x1a0, %i5
a015447c:  f4 1f bf f0  ldd  [ %fp + -16 ], %i2
a0154480:  f0 18 61 78  ldd  [ %g1 + 0x178 ], %i0
a0154484:  d8 18 61 80  ldd  [ %g1 + 0x180 ], %o4
a0154488:  d4 18 61 88  ldd  [ %g1 + 0x188 ], %o2
a015448c:  d0 18 61 90  ldd  [ %g1 + 0x190 ], %o0
a0154490:  e0 18 61 98  ldd  [ %g1 + 0x198 ], %l0
a0154494:  e4 18 61 a0  ldd  [ %g1 + 0x1a0 ], %l2
a0154498:  e8 18 61 a8  ldd  [ %g1 + 0x1a8 ], %l4
a015449c:  ec 18 61 b0  ldd  [ %g1 + 0x1b0 ], %l6
a01544a0:  f4 3f 60 48  std  %i2, [ %i5 + 0x48 ]
a01544a4:  f0 3f 60 08  std  %i0, [ %i5 + 8 ]
a01544a8:  d8 3f 60 10  std  %o4, [ %i5 + 0x10 ]
a01544ac:  d4 3f 60 18  std  %o2, [ %i5 + 0x18 ]
a01544b0:  d0 3f 60 20  std  %o0, [ %i5 + 0x20 ]
a01544b4:  e0 3f 60 28  std  %l0, [ %i5 + 0x28 ]
a01544b8:  e4 3f 60 30  std  %l2, [ %i5 + 0x30 ]
a01544bc:  e8 3f 60 38  std  %l4, [ %i5 + 0x38 ]
a01544c0:  ec 3f 60 40  std  %l6, [ %i5 + 0x40 ]
a01544c4:  81 c7 e0 08  ret
a01544c8:  81 e8 00 00  restore
