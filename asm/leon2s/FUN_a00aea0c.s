# leon2s FUN_a00aea0c 0xa00aea0c-0xa00aea3c (48 bytes)
a00aea0c:  9d e3 bf 98  save  %sp, -104, %sp
a00aea10:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00aea14:  c2 08 62 63  ldub  [ %g1 + 0x263 ], %g1	! 0xa807de63
a00aea18:  b0 10 20 01  mov  1, %i0
a00aea1c:  80 a0 60 01  cmp  %g1, 1
a00aea20:  12 80 00 04  bne  0xa00aea30
a00aea24:  90 10 20 01  mov  1, %o0
a00aea28:  7f ff fe ef  call  0xa00ae5e4
a00aea2c:  01 00 00 00  nop
a00aea30:  7f ff 5b 33  call  0xa00856fc
a00aea34:  81 e8 00 00  restore
a00aea38:  01 00 00 00  nop
