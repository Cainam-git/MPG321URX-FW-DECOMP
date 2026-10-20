# leon2m FUN_a015e9d8 0xa015e9d8-0xa015ea08 (48 bytes)
a015e9d8:  9d e3 bf 98  save  %sp, -104, %sp
a015e9dc:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a015e9e0:  c2 00 63 ec  ld  [ %g1 + 0x3ec ], %g1	! 0xa802cfec
a015e9e4:  90 10 00 18  mov  %i0, %o0
a015e9e8:  80 a0 60 00  cmp  %g1, 0
a015e9ec:  02 80 00 05  be  0xa015ea00
a015e9f0:  b0 10 20 00  clr  %i0
a015e9f4:  9f c0 40 00  call  %g1
a015e9f8:  01 00 00 00  nop
a015e9fc:  b0 10 00 08  mov  %o0, %i0
a015ea00:  81 c7 e0 08  ret
a015ea04:  81 e8 00 00  restore
