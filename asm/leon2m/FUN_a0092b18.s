# leon2m FUN_a0092b18 0xa0092b18-0xa0092bb4 (156 bytes)
a0092b18:  9d e3 bf 98  save  %sp, -104, %sp
a0092b1c:  33 2a 00 ab  sethi  %hi(0xa802ac00), %i1
a0092b20:  d2 06 63 ec  ld  [ %i1 + 0x3ec ], %o1	! 0xa802afec
a0092b24:  90 02 7f fe  add  %o1, -2, %o0
a0092b28:  90 0a 20 ff  and  %o0, 0xff, %o0
a0092b2c:  40 00 85 86  call  0xa00b4144
a0092b30:  92 10 20 02  mov  2, %o1
a0092b34:  82 10 20 2a  mov  0x2a, %g1
a0092b38:  1b 19 99 99  sethi  %hi(0x66666400), %o5
a0092b3c:  c2 26 63 ec  st  %g1, [ %i1 + 0x3ec ]
a0092b40:  b0 13 62 67  or  %o5, 0x267, %i0
a0092b44:  10 80 00 0e  b  0xa0092b7c
a0092b48:  a0 10 00 19  mov  %i1, %l0
a0092b4c:  90 03 3f d7  add  %o4, -41, %o0
a0092b50:  80 5a 00 18  smul  %o0, %i0, %g0
a0092b54:  83 40 00 00  rd  %y, %g1
a0092b58:  9b 38 60 02  sra  %g1, 2, %o5
a0092b5c:  97 3a 20 1f  sra  %o0, 0x1f, %o3
a0092b60:  9e 23 40 0b  sub  %o5, %o3, %o7
a0092b64:  95 2b e0 02  sll  %o7, 2, %o2
a0092b68:  92 02 80 0f  add  %o2, %o7, %o1
a0092b6c:  82 02 40 09  add  %o1, %o1, %g1
a0092b70:  9a 22 00 01  sub  %o0, %g1, %o5
a0092b74:  9e 03 60 2a  add  %o5, 0x2a, %o7
a0092b78:  de 26 63 ec  st  %o7, [ %i1 + 0x3ec ]
a0092b7c:  d8 06 63 ec  ld  [ %i1 + 0x3ec ], %o4
a0092b80:  96 03 3f d6  add  %o4, -42, %o3
a0092b84:  40 00 5e 67  call  0xa00aa520
a0092b88:  90 0a e0 ff  and  %o3, 0xff, %o0
a0092b8c:  94 0a 20 ff  and  %o0, 0xff, %o2
a0092b90:  80 a2 a0 01  cmp  %o2, 1
a0092b94:  12 bf ff ee  bne  0xa0092b4c
a0092b98:  d8 16 63 ee  lduh  [ %i1 + 0x3ee ], %o4
a0092b9c:  f2 04 23 ec  ld  [ %l0 + 0x3ec ], %i1
a0092ba0:  b0 06 7f d6  add  %i1, -42, %i0
a0092ba4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0092ba8:  40 00 59 19  call  0xa00a900c
a0092bac:  93 e8 20 01  restore  %g0, 1, %o1
a0092bb0:  01 00 00 00  nop
