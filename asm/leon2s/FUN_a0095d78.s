# leon2s FUN_a0095d78 0xa0095d78-0xa0095e08 (144 bytes)
a0095d78:  9d e3 bf 98  save  %sp, -104, %sp
a0095d7c:  b2 0e 20 ff  and  %i0, 0xff, %i1
a0095d80:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a0095d84:  a0 10 60 50  or  %g1, 0x50, %l0	! 0xa8078c50
a0095d88:  7f ff ff eb  call  0xa0095d34
a0095d8c:  90 10 00 19  mov  %i1, %o0
a0095d90:  9a 0a 20 ff  and  %o0, 0xff, %o5
a0095d94:  c2 0c 00 19  ldub  [ %l0 + %i1 ], %g1
a0095d98:  90 10 00 19  mov  %i1, %o0
a0095d9c:  80 a0 40 0d  cmp  %g1, %o5
a0095da0:  02 80 00 18  be  0xa0095e00
a0095da4:  23 2a 01 e3  sethi  %hi(0xa8078c00), %l1
a0095da8:  7f ff ff e3  call  0xa0095d34
a0095dac:  b0 10 00 19  mov  %i1, %i0
a0095db0:  82 10 00 08  mov  %o0, %g1
a0095db4:  90 10 00 19  mov  %i1, %o0
a0095db8:  92 10 20 00  clr  %o1
a0095dbc:  80 88 60 ff  btst  0xff, %g1
a0095dc0:  02 80 00 0c  be  0xa0095df0
a0095dc4:  c2 2c 00 19  stb  %g1, [ %l0 + %i1 ]
a0095dc8:  7f ff ff b7  call  0xa0095ca4
a0095dcc:  01 00 00 00  nop
a0095dd0:  9a 14 60 48  or  %l1, 0x48, %o5
a0095dd4:  82 10 20 01  mov  1, %g1
a0095dd8:  99 2e 60 09  sll  %i1, 9, %o4
a0095ddc:  c2 2b 40 19  stb  %g1, [ %o5 + %i1 ]
a0095de0:  33 27 c6 c0  sethi  %hi(0x9f1b0000), %i1
a0095de4:  b2 16 62 00  or  %i1, 0x200, %i1	! 0x9f1b0200
a0095de8:  40 00 35 83  call  0xa00a33f4
a0095dec:  93 eb 00 19  restore  %o4, %i1, %o1
a0095df0:  7f c4 8b 0b  call  0x9f1b8a1c
a0095df4:  90 10 00 19  mov  %i1, %o0
a0095df8:  82 14 60 48  or  %l1, 0x48, %g1
a0095dfc:  c0 28 40 19  clrb  [ %g1 + %i1 ]
a0095e00:  81 c7 e0 08  ret
a0095e04:  81 e8 00 00  restore
