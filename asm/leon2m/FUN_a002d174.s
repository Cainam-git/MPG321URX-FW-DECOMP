# leon2m FUN_a002d174 0xa002d174-0xa002d1a0 (44 bytes)
a002d174:  9d e3 bf 98  save  %sp, -104, %sp
a002d178:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a002d17c:  c2 00 60 e0  ld  [ %g1 + 0xe0 ], %g1	! 0xa802b0e0
a002d180:  80 a0 60 00  cmp  %g1, 0
a002d184:  02 80 00 04  be  0xa002d194
a002d188:  90 10 20 04  mov  4, %o0
a002d18c:  9f c0 40 00  call  %g1
a002d190:  01 00 00 00  nop
a002d194:  01 00 00 00  nop
a002d198:  81 c7 e0 08  ret
a002d19c:  81 e8 00 00  restore
