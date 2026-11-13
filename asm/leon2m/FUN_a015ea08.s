# leon2m FUN_a015ea08 0xa015ea08-0xa015ea38 (48 bytes)
a015ea08:  9d e3 bf 98  save  %sp, -104, %sp
a015ea0c:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a015ea10:  c2 00 63 e4  ld  [ %g1 + 0x3e4 ], %g1	! 0xa802cfe4
a015ea14:  90 10 00 18  mov  %i0, %o0
a015ea18:  80 a0 60 00  cmp  %g1, 0
a015ea1c:  02 80 00 05  be  0xa015ea30
a015ea20:  b0 10 20 00  clr  %i0
a015ea24:  9f c0 40 00  call  %g1
a015ea28:  01 00 00 00  nop
a015ea2c:  b0 10 00 08  mov  %o0, %i0
a015ea30:  81 c7 e0 08  ret
a015ea34:  81 e8 00 00  restore
