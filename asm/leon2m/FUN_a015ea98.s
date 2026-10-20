# leon2m FUN_a015ea98 0xa015ea98-0xa015eac8 (48 bytes)
a015ea98:  9d e3 bf 98  save  %sp, -104, %sp
a015ea9c:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a015eaa0:  c2 00 63 dc  ld  [ %g1 + 0x3dc ], %g1	! 0xa802cfdc
a015eaa4:  90 10 00 18  mov  %i0, %o0
a015eaa8:  80 a0 60 00  cmp  %g1, 0
a015eaac:  02 80 00 05  be  0xa015eac0
a015eab0:  b0 10 20 00  clr  %i0
a015eab4:  9f c0 40 00  call  %g1
a015eab8:  01 00 00 00  nop
a015eabc:  b0 10 00 08  mov  %o0, %i0
a015eac0:  81 c7 e0 08  ret
a015eac4:  81 e8 00 00  restore
