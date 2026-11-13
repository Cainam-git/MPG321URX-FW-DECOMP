# leon2s FUN_a00a2bec 0xa00a2bec-0xa00a2c18 (44 bytes)
a00a2bec:  9d e3 bf 98  save  %sp, -104, %sp
a00a2bf0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a2bf4:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a00a2bf8:  b0 5e 20 34  smul  %i0, 0x34, %i0
a00a2bfc:  82 10 63 00  or  %g1, 0x300, %g1
a00a2c00:  d2 00 40 18  ld  [ %g1 + %i0 ], %o1
a00a2c04:  92 02 60 08  add  %o1, 8, %o1
a00a2c08:  40 00 11 f3  call  0xa00a73d4
a00a2c0c:  90 10 20 02  mov  2, %o0
a00a2c10:  81 c7 e0 08  ret
a00a2c14:  91 e8 20 00  restore  %g0, 0, %o0
