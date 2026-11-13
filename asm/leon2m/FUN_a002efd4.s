# leon2m FUN_a002efd4 0xa002efd4-0xa002f010 (60 bytes)
a002efd4:  9d e3 bf 98  save  %sp, -104, %sp
a002efd8:  15 33 c0 1b  sethi  %hi(0xcf006c00), %o2
a002efdc:  96 12 a3 30  or  %o2, 0x330, %o3	! 0xcf006f30
a002efe0:  92 12 a3 34  or  %o2, 0x334, %o1
a002efe4:  c0 22 c0 00  clr  [ %o3 ]
a002efe8:  c0 22 40 00  clr  [ %o1 ]
a002efec:  90 10 20 01  mov  1, %o0
a002eff0:  7f ff fc f5  call  0xa002e3c4
a002eff4:  92 10 20 01  mov  1, %o1
a002eff8:  1b 2a 00 b2  sethi  %hi(0xa802c800), %o5
a002effc:  d0 03 61 e4  ld  [ %o5 + 0x1e4 ], %o0	! 0xa802c9e4
a002f000:  82 12 20 02  or  %o0, 2, %g1
a002f004:  c2 23 61 e4  st  %g1, [ %o5 + 0x1e4 ]
a002f008:  81 c7 e0 08  ret
a002f00c:  81 e8 00 00  restore
