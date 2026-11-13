# leon2s FUN_a0090dec 0xa0090dec-0xa0090e4c (96 bytes)
a0090dec:  9d e3 bf 98  save  %sp, -104, %sp
a0090df0:  90 0e 20 ff  and  %i0, 0xff, %o0
a0090df4:  40 00 55 e2  call  0xa00a657c
a0090df8:  92 10 20 45  mov  0x45, %o1
a0090dfc:  82 0a 20 07  and  %o0, 7, %g1
a0090e00:  80 a0 60 07  cmp  %g1, 7
a0090e04:  38 80 00 0f  bgu,a   0xa0090e40
a0090e08:  b0 10 20 08  mov  8, %i0
a0090e0c:  1b 28 02 43  sethi  %hi(0xa0090c00), %o5
a0090e10:  83 28 60 02  sll  %g1, 2, %g1
a0090e14:  9a 13 61 cc  or  %o5, 0x1cc, %o5
a0090e18:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a0090e1c:  81 c0 40 00  jmp  %g1
a0090e20:  01 00 00 00  nop
a0090e24:  10 80 00 07  b  0xa0090e40
a0090e28:  b0 10 20 0a  mov  0xa, %i0	! 0xa
a0090e2c:  10 80 00 05  b  0xa0090e40
a0090e30:  b0 10 20 0c  mov  0xc, %i0
a0090e34:  10 80 00 03  b  0xa0090e40
a0090e38:  b0 10 20 10  mov  0x10, %i0
a0090e3c:  b0 10 20 08  mov  8, %i0
a0090e40:  b0 0e 20 1e  and  %i0, 0x1e, %i0
a0090e44:  81 c7 e0 08  ret
a0090e48:  81 e8 00 00  restore
