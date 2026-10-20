# leon2s FUN_a0086df4 0xa0086df4-0xa0086e58 (100 bytes)
a0086df4:  9d e3 bf 90  save  %sp, -112, %sp
a0086df8:  90 0e 20 ff  and  %i0, 0xff, %o0
a0086dfc:  9a 02 00 08  add  %o0, %o0, %o5
a0086e00:  9a 03 40 08  add  %o5, %o0, %o5
a0086e04:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a0086e08:  9a 03 40 0d  add  %o5, %o5, %o5
a0086e0c:  82 10 61 2e  or  %g1, 0x12e, %g1
a0086e10:  c2 08 40 0d  ldub  [ %g1 + %o5 ], %g1
a0086e14:  f2 2f bf f1  stb  %i1, [ %fp + -15 ]
a0086e18:  92 10 20 80  mov  0x80, %o1
a0086e1c:  94 10 21 00  mov  0x100, %o2
a0086e20:  96 10 20 01  mov  1, %o3
a0086e24:  98 07 bf f0  add  %fp, -16, %o4
a0086e28:  80 88 60 10  btst  0x10, %g1
a0086e2c:  f4 2f bf f0  stb  %i2, [ %fp + -16 ]
a0086e30:  02 80 00 03  be  0xa0086e3c
a0086e34:  b2 16 7f 80  or  %i1, -128, %i1
a0086e38:  f2 2f bf f1  stb  %i1, [ %fp + -15 ]
a0086e3c:  7f ff fd 66  call  0xa00863d4
a0086e40:  01 00 00 00  nop
a0086e44:  90 0a 20 ff  and  %o0, 0xff, %o0
a0086e48:  80 a0 00 08  cmp  %g0, %o0
a0086e4c:  b0 40 20 00  addx  %g0, 0, %i0
a0086e50:  81 c7 e0 08  ret
a0086e54:  81 e8 00 00  restore
