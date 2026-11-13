# leon2s FUN_a0074ef4 0xa0074ef4-0xa0074f60 (108 bytes)  [FUN_a0074f58 = unreachable ret/restore tail, merged]
a0074ef4:  9d e3 bf 98  save  %sp, -104, %sp
a0074ef8:  b8 0e a0 ff  and  %i2, 0xff, %i4
a0074efc:  3b 28 02 ce  sethi  %hi(0xa00b3800), %i5
a0074f00:  ba 17 62 64  or  %i5, 0x264, %i5	! 0xa00b3a64
a0074f04:  b9 2f 20 02  sll  %i4, 2, %i4
a0074f08:  82 07 00 1d  add  %i4, %i5, %g1
a0074f0c:  c2 10 60 02  lduh  [ %g1 + 2 ], %g1
a0074f10:  83 28 60 10  sll  %g1, 0x10, %g1
a0074f14:  f6 0f 40 1c  ldub  [ %i5 + %i4 ], %i3
a0074f18:  b2 0e 60 ff  and  %i1, 0xff, %i1
a0074f1c:  35 3f c0 00  sethi  %hi(0xff000000), %i2
a0074f20:  83 30 60 08  srl  %g1, 8, %g1
a0074f24:  b6 0e e0 0f  and  %i3, 0xf, %i3
a0074f28:  9e 06 40 19  add  %i1, %i1, %o7
a0074f2c:  b4 16 a0 f0  or  %i2, 0xf0, %i2
a0074f30:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0074f34:  80 a6 60 02  cmp  %i1, 2
a0074f38:  18 80 00 07  bgu  0xa0074f54
a0074f3c:  b6 16 c0 01  or  %i3, %g1, %i3
a0074f40:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a0074f44:  82 10 63 78  or  %g1, 0x378, %g1	! 0xa00b3b78
a0074f48:  f2 10 40 0f  lduh  [ %g1 + %o7 ], %i1
a0074f4c:  40 00 c9 4f  call  0xa00a7488
a0074f50:  81 e8 00 00  restore
a0074f54:  01 00 00 00  nop
a0074f58:  81 c7 e0 08  ret
a0074f5c:  81 e8 00 00  restore
