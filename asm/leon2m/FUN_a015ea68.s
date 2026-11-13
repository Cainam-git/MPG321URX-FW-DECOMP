# leon2m FUN_a015ea68 0xa015ea68-0xa015ea98 (48 bytes)
a015ea68:  9d e3 bf 98  save  %sp, -104, %sp
a015ea6c:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a015ea70:  c2 00 63 e0  ld  [ %g1 + 0x3e0 ], %g1	! 0xa802cfe0
a015ea74:  90 10 00 18  mov  %i0, %o0
a015ea78:  80 a0 60 00  cmp  %g1, 0
a015ea7c:  02 80 00 05  be  0xa015ea90
a015ea80:  b0 10 20 00  clr  %i0
a015ea84:  9f c0 40 00  call  %g1
a015ea88:  01 00 00 00  nop
a015ea8c:  b0 10 00 08  mov  %o0, %i0
a015ea90:  81 c7 e0 08  ret
a015ea94:  81 e8 00 00  restore
