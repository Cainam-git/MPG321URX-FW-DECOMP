# leon2m FUN_a00e0cb8 0xa00e0cb8-0xa00e0cd8 (32 bytes)
a00e0cb8:  03 2a 00 ad  sethi  %hi(0xa802b400), %g1
a00e0cbc:  da 00 61 3c  ld  [ %g1 + 0x13c ], %o5	! 0xa802b53c
a00e0cc0:  80 a3 60 00  cmp  %o5, 0
a00e0cc4:  12 80 00 03  bne  0xa00e0cd0
a00e0cc8:  1b 2a 00 ad  sethi  %hi(0xa802b400), %o5
a00e0ccc:  d0 23 61 50  st  %o0, [ %o5 + 0x150 ]	! 0xa802b550
a00e0cd0:  81 c3 e0 08  retl
a00e0cd4:  01 00 00 00  nop
