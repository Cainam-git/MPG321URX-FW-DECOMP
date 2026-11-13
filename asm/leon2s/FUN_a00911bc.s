# leon2s FUN_a00911bc 0xa00911bc-0xa0091204 (72 bytes)
a00911bc:  9d e3 bf 98  save  %sp, -104, %sp
a00911c0:  b0 0e 20 01  and  %i0, 1, %i0
a00911c4:  7f ff 8f 67  call  0xa0074f60
a00911c8:  90 10 00 18  mov  %i0, %o0
a00911cc:  82 06 00 18  add  %i0, %i0, %g1
a00911d0:  82 00 40 18  add  %g1, %i0, %g1
a00911d4:  1b 2a 01 f3  sethi  %hi(0xa807cc00), %o5
a00911d8:  83 28 60 03  sll  %g1, 3, %g1
a00911dc:  9a 13 60 64  or  %o5, 0x64, %o5
a00911e0:  82 00 40 0d  add  %g1, %o5, %g1
a00911e4:  c2 08 60 04  ldub  [ %g1 + 4 ], %g1
a00911e8:  80 a0 60 00  cmp  %g1, 0
a00911ec:  32 80 00 02  bne,a   0xa00911f4
a00911f0:  91 2a 20 02  sll  %o0, 2, %o0
a00911f4:  b1 2a 20 10  sll  %o0, 0x10, %i0
a00911f8:  b1 36 20 10  srl  %i0, 0x10, %i0
a00911fc:  81 c7 e0 08  ret
a0091200:  81 e8 00 00  restore
