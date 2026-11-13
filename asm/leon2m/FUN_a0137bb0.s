# leon2m FUN_a0137bb0 0xa0137bb0-0xa0137be8 (56 bytes)
a0137bb0:  9d e3 bf 90  save  %sp, -112, %sp
a0137bb4:  90 10 20 87  mov  0x87, %o0
a0137bb8:  92 10 20 04  mov  4, %o1
a0137bbc:  94 07 bf f0  add  %fp, -16, %o2
a0137bc0:  96 10 20 00  clr  %o3
a0137bc4:  7f ff fd 46  call  0xa01370dc
a0137bc8:  c0 27 bf f0  clr  [ %fp + -16 ]
a0137bcc:  7f ff fd de  call  0xa0137344
a0137bd0:  90 10 20 01  mov  1, %o0
a0137bd4:  03 2a 00 b2  sethi  %hi(0xa802c800), %g1
a0137bd8:  f0 08 63 a3  ldub  [ %g1 + 0x3a3 ], %i0	! 0xa802cba3
a0137bdc:  b0 0e 20 01  and  %i0, 1, %i0
a0137be0:  81 c7 e0 08  ret
a0137be4:  81 e8 00 00  restore
