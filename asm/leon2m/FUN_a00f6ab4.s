# leon2m FUN_a00f6ab4 0xa00f6ab4-0xa00f6b34 (128 bytes)
a00f6ab4:  80 a2 20 04  cmp  %o0, 4
a00f6ab8:  18 80 00 1d  bgu  0xa00f6b2c
a00f6abc:  83 2a 20 02  sll  %o0, 2, %g1
a00f6ac0:  11 00 02 58  sethi  %hi(0x96000), %o0
a00f6ac4:  9a 12 23 a8  or  %o0, 0x3a8, %o5	! 0x963a8
a00f6ac8:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a00f6acc:  81 c3 00 00  jmp  %o4
a00f6ad0:  01 00 00 00  nop
a00f6ad4:  19 33 c0 3b  sethi  %hi(0xcf00ec00), %o4
a00f6ad8:  9a 13 22 40  or  %o4, 0x240, %o5	! 0xcf00ee40
a00f6adc:  d0 03 40 00  ld  [ %o5 ], %o0
a00f6ae0:  82 0a 3f bf  and  %o0, -65, %g1
a00f6ae4:  c2 23 40 00  st  %g1, [ %o5 ]
a00f6ae8:  30 80 00 11  b,a   0xa00f6b2c
a00f6aec:  03 33 c0 3b  sethi  %hi(0xcf00ec00), %g1
a00f6af0:  9a 10 62 40  or  %g1, 0x240, %o5	! 0xcf00ee40
a00f6af4:  c2 03 40 00  ld  [ %o5 ], %g1
a00f6af8:  82 08 7f 7f  and  %g1, -129, %g1
a00f6afc:  c2 23 40 00  st  %g1, [ %o5 ]
a00f6b00:  30 80 00 0b  b,a   0xa00f6b2c
a00f6b04:  1b 33 c0 3b  sethi  %hi(0xcf00ec00), %o5
a00f6b08:  9a 13 62 68  or  %o5, 0x268, %o5	! 0xcf00ee68
a00f6b0c:  d0 03 40 00  ld  [ %o5 ], %o0
a00f6b10:  10 bf ff f5  b  0xa00f6ae4
a00f6b14:  82 0a 3f bf  and  %o0, -65, %g1
a00f6b18:  19 33 c0 3b  sethi  %hi(0xcf00ec00), %o4
a00f6b1c:  9a 13 22 68  or  %o4, 0x268, %o5	! 0xcf00ee68
a00f6b20:  c2 03 40 00  ld  [ %o5 ], %g1
a00f6b24:  10 bf ff f6  b  0xa00f6afc
a00f6b28:  82 08 7f 7f  and  %g1, -129, %g1
a00f6b2c:  81 c3 e0 08  retl
a00f6b30:  01 00 00 00  nop
