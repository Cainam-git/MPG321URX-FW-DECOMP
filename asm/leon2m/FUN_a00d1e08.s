# leon2m FUN_a00d1e08 0xa00d1e08-0xa00d1e3c (52 bytes)
a00d1e08:  c2 0a 20 07  ldub  [ %o0 + 7 ], %g1
a00d1e0c:  80 a0 60 01  cmp  %g1, 1
a00d1e10:  02 80 00 07  be  0xa00d1e2c
a00d1e14:  80 a0 60 00  cmp  %g1, 0
a00d1e18:  12 80 00 07  bne  0xa00d1e34
a00d1e1c:  9a 10 20 01  mov  1, %o5
a00d1e20:  11 2a 00 ac  sethi  %hi(0xa802b000), %o0
a00d1e24:  10 80 00 04  b  0xa00d1e34
a00d1e28:  da 2a 20 9d  stb  %o5, [ %o0 + 0x9d ]	! 0xa802b09d
a00d1e2c:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00d1e30:  c0 28 60 9d  clrb  [ %g1 + 0x9d ]	! 0xa802b09d
a00d1e34:  81 c3 e0 08  retl
a00d1e38:  90 10 20 e0  mov  0xe0, %o0
