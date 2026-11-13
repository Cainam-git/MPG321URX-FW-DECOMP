# leon2m FUN_a015eac8 0xa015eac8-0xa015eaf8 (48 bytes)
a015eac8:  9d e3 bf 98  save  %sp, -104, %sp
a015eacc:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a015ead0:  c2 00 63 d8  ld  [ %g1 + 0x3d8 ], %g1	! 0xa802cfd8
a015ead4:  90 10 00 18  mov  %i0, %o0
a015ead8:  80 a0 60 00  cmp  %g1, 0
a015eadc:  02 80 00 05  be  0xa015eaf0
a015eae0:  b0 10 20 00  clr  %i0
a015eae4:  9f c0 40 00  call  %g1
a015eae8:  01 00 00 00  nop
a015eaec:  b0 10 00 08  mov  %o0, %i0
a015eaf0:  81 c7 e0 08  ret
a015eaf4:  81 e8 00 00  restore
