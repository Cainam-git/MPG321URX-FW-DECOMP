# leon2s FUN_a0091db4 0xa0091db4-0xa0091e70 (188 bytes)
a0091db4:  9d e3 bf 88  save  %sp, -120, %sp
a0091db8:  83 2e a0 10  sll  %i2, 0x10, %g1
a0091dbc:  83 30 60 14  srl  %g1, 0x14, %g1
a0091dc0:  80 a0 60 00  cmp  %g1, 0
a0091dc4:  02 80 00 29  be  0xa0091e68
a0091dc8:  a4 10 20 00  clr  %l2
a0091dcc:  a2 0e 20 ff  and  %i0, 0xff, %l1
a0091dd0:  7f c4 97 64  call  0x9f1b7b60
a0091dd4:  90 10 00 11  mov  %l1, %o0
a0091dd8:  90 10 00 11  mov  %l1, %o0
a0091ddc:  7f c4 97 6d  call  0x9f1b7b90
a0091de0:  a1 2c a0 10  sll  %l2, 0x10, %l0
a0091de4:  a1 34 20 0c  srl  %l0, 0xc, %l0
a0091de8:  94 04 00 1b  add  %l0, %i3, %o2
a0091dec:  95 2a a0 10  sll  %o2, 0x10, %o2
a0091df0:  96 10 20 10  mov  0x10, %o3
a0091df4:  95 32 a0 10  srl  %o2, 0x10, %o2
a0091df8:  92 10 20 a0  mov  0xa0, %o1
a0091dfc:  7f c4 98 93  call  0x9f1b8048
a0091e00:  90 10 00 11  mov  %l1, %o0
a0091e04:  94 10 20 10  mov  0x10, %o2
a0091e08:  90 10 00 11  mov  %l1, %o0
a0091e0c:  7f c4 98 fb  call  0x9f1b81f8
a0091e10:  92 07 bf e8  add  %fp, -24, %o1
a0091e14:  a0 04 00 19  add  %l0, %i1, %l0
a0091e18:  96 10 20 00  clr  %o3
a0091e1c:  94 07 bf f8  add  %fp, -8, %o2
a0091e20:  99 2a e0 10  sll  %o3, 0x10, %o4
a0091e24:  99 33 20 10  srl  %o4, 0x10, %o4
a0091e28:  96 02 e0 01  inc  %o3
a0091e2c:  9b 2a e0 10  sll  %o3, 0x10, %o5
a0091e30:  82 02 80 0c  add  %o2, %o4, %g1
a0091e34:  c2 08 7f f0  ldub  [ %g1 + -16 ], %g1
a0091e38:  9b 33 60 10  srl  %o5, 0x10, %o5
a0091e3c:  80 a3 60 0f  cmp  %o5, 0xf
a0091e40:  08 bf ff f8  bleu  0xa0091e20
a0091e44:  c2 2c 00 0c  stb  %g1, [ %l0 + %o4 ]
a0091e48:  98 04 a0 01  add  %l2, 1, %o4
a0091e4c:  9b 2b 20 10  sll  %o4, 0x10, %o5
a0091e50:  83 2e a0 10  sll  %i2, 0x10, %g1
a0091e54:  9b 33 60 10  srl  %o5, 0x10, %o5
a0091e58:  83 30 60 14  srl  %g1, 0x14, %g1
a0091e5c:  80 a3 40 01  cmp  %o5, %g1
a0091e60:  0a bf ff db  bcs  0xa0091dcc
a0091e64:  a4 10 00 0c  mov  %o4, %l2
a0091e68:  81 c7 e0 08  ret
a0091e6c:  81 e8 00 00  restore
