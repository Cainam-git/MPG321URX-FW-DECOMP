# leon2m FUN_a0097d3c 0xa0097d3c-0xa0097dec (176 bytes)  [FUN_a0097de4 = unreachable ret/restore tail, merged]
a0097d3c:  9d e3 bf 98  save  %sp, -104, %sp
a0097d40:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a0097d44:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a0097d48:  da 03 63 ec  ld  [ %o5 + 0x3ec ], %o5
a0097d4c:  80 a3 60 7f  cmp  %o5, 0x7f
a0097d50:  02 80 00 08  be  0xa0097d70
a0097d54:  98 10 62 90  or  %g1, 0x290, %o4
a0097d58:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a0097d5c:  80 a3 60 80  cmp  %o5, 0x80
a0097d60:  12 80 00 20  bne  0xa0097de0
a0097d64:  98 12 22 90  or  %o0, 0x290, %o4
a0097d68:  10 80 00 10  b  0xa0097da8
a0097d6c:  d4 0b 20 2f  ldub  [ %o4 + 0x2f ], %o2
a0097d70:  d2 0b 20 2f  ldub  [ %o4 + 0x2f ], %o1
a0097d74:  80 a2 60 00  cmp  %o1, 0
a0097d78:  02 80 00 1a  be  0xa0097de0
a0097d7c:  90 10 20 00  clr  %o0
a0097d80:  40 01 05 1f  call  0xa00d91fc
a0097d84:  c0 2b 20 2f  clrb  [ %o4 + 0x2f ]
a0097d88:  90 10 20 00  clr  %o0
a0097d8c:  40 02 c1 37  call  0xa0148268
a0097d90:  92 10 20 01  mov  1, %o1
a0097d94:  90 10 20 01  mov  1, %o0
a0097d98:  40 02 c1 34  call  0xa0148268
a0097d9c:  92 10 20 01  mov  1, %o1
a0097da0:  40 01 09 2d  call  0xa00da254
a0097da4:  81 e8 00 00  restore
a0097da8:  80 a2 a0 01  cmp  %o2, 1
a0097dac:  02 80 00 0d  be  0xa0097de0
a0097db0:  90 10 20 00  clr  %o0
a0097db4:  96 10 20 01  mov  1, %o3
a0097db8:  40 01 05 11  call  0xa00d91fc
a0097dbc:  d6 2b 20 2f  stb  %o3, [ %o4 + 0x2f ]
a0097dc0:  90 10 20 00  clr  %o0
a0097dc4:  40 02 c1 29  call  0xa0148268
a0097dc8:  92 10 20 01  mov  1, %o1
a0097dcc:  90 10 20 01  mov  1, %o0
a0097dd0:  40 02 c1 26  call  0xa0148268
a0097dd4:  92 10 20 01  mov  1, %o1
a0097dd8:  40 01 09 1f  call  0xa00da254
a0097ddc:  81 e8 00 00  restore
a0097de0:  01 00 00 00  nop
a0097de4:  81 c7 e0 08  ret
a0097de8:  81 e8 00 00  restore
