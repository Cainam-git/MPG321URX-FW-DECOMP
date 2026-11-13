# leon2m FUN_a00e0c88 0xa00e0c88-0xa00e0ca8 (32 bytes)
a00e0c88:  03 2a 00 ad  sethi  %hi(0xa802b400), %g1
a00e0c8c:  da 00 61 48  ld  [ %g1 + 0x148 ], %o5	! 0xa802b548
a00e0c90:  80 a3 60 00  cmp  %o5, 0
a00e0c94:  12 80 00 03  bne  0xa00e0ca0
a00e0c98:  1b 2a 00 ad  sethi  %hi(0xa802b400), %o5
a00e0c9c:  d0 23 61 54  st  %o0, [ %o5 + 0x154 ]	! 0xa802b554
a00e0ca0:  81 c3 e0 08  retl
a00e0ca4:  01 00 00 00  nop
