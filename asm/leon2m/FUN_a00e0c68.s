# leon2m FUN_a00e0c68 0xa00e0c68-0xa00e0c88 (32 bytes)
a00e0c68:  03 2a 00 ad  sethi  %hi(0xa802b400), %g1
a00e0c6c:  da 00 61 4c  ld  [ %g1 + 0x14c ], %o5	! 0xa802b54c
a00e0c70:  80 a3 60 00  cmp  %o5, 0
a00e0c74:  12 80 00 03  bne  0xa00e0c80
a00e0c78:  1b 2a 00 97  sethi  %hi(0xa8025c00), %o5
a00e0c7c:  d0 23 61 08  st  %o0, [ %o5 + 0x108 ]	! 0xa8025d08
a00e0c80:  81 c3 e0 08  retl
a00e0c84:  01 00 00 00  nop
