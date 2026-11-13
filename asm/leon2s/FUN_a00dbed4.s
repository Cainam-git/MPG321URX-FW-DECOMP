# leon2s FUN_a00dbed4 0xa00dbed4-0xa00dbf24 (80 bytes)
a00dbed4:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00dbed8:  d8 08 63 fe  ldub  [ %g1 + 0x3fe ], %o4	! 0xa80787fe
a00dbedc:  17 2a 01 e1  sethi  %hi(0xa8078400), %o3
a00dbee0:  da 0a e3 ff  ldub  [ %o3 + 0x3ff ], %o5	! 0xa80787ff
a00dbee4:  82 0b 20 ff  and  %o4, 0xff, %g1
a00dbee8:  80 a3 40 01  cmp  %o5, %g1
a00dbeec:  02 80 00 0b  be  0xa00dbf18
a00dbef0:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00dbef4:  c2 08 60 3f  ldub  [ %g1 + 0x3f ], %g1	! 0xa807883f
a00dbef8:  80 a0 60 00  cmp  %g1, 0
a00dbefc:  12 80 00 04  bne  0xa00dbf0c
a00dbf00:  01 00 00 00  nop
a00dbf04:  10 80 00 05  b  0xa00dbf18
a00dbf08:  d8 2a e3 ff  stb  %o4, [ %o3 + 0x3ff ]
a00dbf0c:  82 13 c0 00  mov  %o7, %g1
a00dbf10:  7f ff fd 8b  call  0xa00db53c
a00dbf14:  9e 10 40 00  mov  %g1, %o7
a00dbf18:  01 00 00 00  nop
a00dbf1c:  81 c3 e0 08  retl
a00dbf20:  01 00 00 00  nop
