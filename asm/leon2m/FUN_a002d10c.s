# leon2m FUN_a002d10c 0xa002d10c-0xa002d138 (44 bytes)
a002d10c:  9d e3 bf 98  save  %sp, -104, %sp
a002d110:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a002d114:  c2 00 60 d4  ld  [ %g1 + 0xd4 ], %g1	! 0xa802b0d4
a002d118:  80 a0 60 00  cmp  %g1, 0
a002d11c:  02 80 00 04  be  0xa002d12c
a002d120:  90 10 20 01  mov  1, %o0
a002d124:  9f c0 40 00  call  %g1
a002d128:  01 00 00 00  nop
a002d12c:  01 00 00 00  nop
a002d130:  81 c7 e0 08  ret
a002d134:  81 e8 00 00  restore
