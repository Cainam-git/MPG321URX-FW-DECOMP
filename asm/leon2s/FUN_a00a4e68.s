# leon2s FUN_a00a4e68 0xa00a4e68-0xa00a4ec4 (92 bytes)
a00a4e68:  9d e3 bf 98  save  %sp, -104, %sp
a00a4e6c:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00a4e70:  b0 10 60 04  or  %g1, 4, %i0	! 0xa807dc04
a00a4e74:  b2 10 20 00  clr  %i1
a00a4e78:  19 30 04 00  sethi  %hi(0xc0100000), %o4
a00a4e7c:  1b 30 04 01  sethi  %hi(0xc0100400), %o5
a00a4e80:  1f 30 04 02  sethi  %hi(0xc0100800), %o7
a00a4e84:  82 0e 60 ff  and  %i1, 0xff, %g1
a00a4e88:  ba 00 40 01  add  %g1, %g1, %i5
a00a4e8c:  ba 07 40 01  add  %i5, %g1, %i5
a00a4e90:  bb 2f 60 02  sll  %i5, 2, %i5
a00a4e94:  b8 00 40 0f  add  %g1, %o7, %i4
a00a4e98:  b6 00 40 0c  add  %g1, %o4, %i3
a00a4e9c:  b4 07 40 18  add  %i5, %i0, %i2
a00a4ea0:  82 00 40 0d  add  %g1, %o5, %g1
a00a4ea4:  b2 06 60 01  inc  %i1
a00a4ea8:  f8 26 a0 08  st  %i4, [ %i2 + 8 ]
a00a4eac:  f6 26 00 1d  st  %i3, [ %i0 + %i5 ]
a00a4eb0:  80 8e 60 ff  btst  0xff, %i1
a00a4eb4:  02 bf ff f4  be  0xa00a4e84
a00a4eb8:  c2 26 a0 04  st  %g1, [ %i2 + 4 ]
a00a4ebc:  81 c7 e0 08  ret
a00a4ec0:  81 e8 00 00  restore
