# leon2m FUN_a002d148 0xa002d148-0xa002d174 (44 bytes)
a002d148:  9d e3 bf 98  save  %sp, -104, %sp
a002d14c:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a002d150:  c2 00 60 dc  ld  [ %g1 + 0xdc ], %g1	! 0xa802b0dc
a002d154:  80 a0 60 00  cmp  %g1, 0
a002d158:  02 80 00 04  be  0xa002d168
a002d15c:  90 10 20 03  mov  3, %o0
a002d160:  9f c0 40 00  call  %g1
a002d164:  01 00 00 00  nop
a002d168:  01 00 00 00  nop
a002d16c:  81 c7 e0 08  ret
a002d170:  81 e8 00 00  restore
