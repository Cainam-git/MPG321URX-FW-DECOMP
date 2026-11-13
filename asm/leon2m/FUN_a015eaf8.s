# leon2m FUN_a015eaf8 0xa015eaf8-0xa015eb2c (52 bytes)
a015eaf8:  9d e3 bf 98  save  %sp, -104, %sp
a015eafc:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a015eb00:  c2 00 63 d4  ld  [ %g1 + 0x3d4 ], %g1	! 0xa802cfd4
a015eb04:  90 10 00 18  mov  %i0, %o0
a015eb08:  92 10 00 19  mov  %i1, %o1
a015eb0c:  80 a0 60 00  cmp  %g1, 0
a015eb10:  02 80 00 05  be  0xa015eb24
a015eb14:  b0 10 20 00  clr  %i0
a015eb18:  9f c0 40 00  call  %g1
a015eb1c:  01 00 00 00  nop
a015eb20:  b0 10 00 08  mov  %o0, %i0
a015eb24:  81 c7 e0 08  ret
a015eb28:  81 e8 00 00  restore
