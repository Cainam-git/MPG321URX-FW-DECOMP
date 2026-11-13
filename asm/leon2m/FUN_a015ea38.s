# leon2m FUN_a015ea38 0xa015ea38-0xa015ea68 (48 bytes)
a015ea38:  9d e3 bf 98  save  %sp, -104, %sp
a015ea3c:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a015ea40:  c2 00 63 e8  ld  [ %g1 + 0x3e8 ], %g1	! 0xa802cfe8
a015ea44:  90 10 00 18  mov  %i0, %o0
a015ea48:  80 a0 60 00  cmp  %g1, 0
a015ea4c:  02 80 00 05  be  0xa015ea60
a015ea50:  b0 10 20 00  clr  %i0
a015ea54:  9f c0 40 00  call  %g1
a015ea58:  01 00 00 00  nop
a015ea5c:  b0 10 00 08  mov  %o0, %i0
a015ea60:  81 c7 e0 08  ret
a015ea64:  81 e8 00 00  restore
