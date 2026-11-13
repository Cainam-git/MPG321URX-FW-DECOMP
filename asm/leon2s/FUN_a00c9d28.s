# leon2s FUN_a00c9d28 0xa00c9d28-0xa00c9de8 (192 bytes)
a00c9d28:  9d e3 bf 98  save  %sp, -104, %sp
a00c9d2c:  b4 0e a0 ff  and  %i2, 0xff, %i2
a00c9d30:  95 2e a0 04  sll  %i2, 4, %o2
a00c9d34:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c9d38:  94 02 80 1a  add  %o2, %i2, %o2
a00c9d3c:  94 0a a0 ff  and  %o2, 0xff, %o2
a00c9d40:  90 10 00 18  mov  %i0, %o0
a00c9d44:  40 3b b8 67  call  0xa0fb7ee0
a00c9d48:  92 10 20 04  mov  4, %o1
a00c9d4c:  90 10 00 18  mov  %i0, %o0
a00c9d50:  92 10 20 05  mov  5, %o1
a00c9d54:  40 3b b8 63  call  0xa0fb7ee0
a00c9d58:  94 10 20 80  mov  0x80, %o2
a00c9d5c:  90 10 00 18  mov  %i0, %o0
a00c9d60:  92 10 20 05  mov  5, %o1
a00c9d64:  40 3b b8 5f  call  0xa0fb7ee0
a00c9d68:  94 10 20 00  clr  %o2
a00c9d6c:  90 10 00 18  mov  %i0, %o0
a00c9d70:  40 3b b8 8c  call  0xa0fb7fa0
a00c9d74:  92 10 20 07  mov  7, %o1
a00c9d78:  83 2e e0 10  sll  %i3, 0x10, %g1
a00c9d7c:  83 30 60 14  srl  %g1, 0x14, %g1
a00c9d80:  80 a0 60 00  cmp  %g1, 0
a00c9d84:  02 80 00 17  be  0xa00c9de0
a00c9d88:  b4 10 20 00  clr  %i2
a00c9d8c:  a1 2e a0 10  sll  %i2, 0x10, %l0
a00c9d90:  a3 2e e0 10  sll  %i3, 0x10, %l1
a00c9d94:  a3 34 60 14  srl  %l1, 0x14, %l1
a00c9d98:  a1 34 20 10  srl  %l0, 0x10, %l0
a00c9d9c:  a0 24 40 10  sub  %l1, %l0, %l0
a00c9da0:  92 10 20 06  mov  6, %o1
a00c9da4:  90 10 00 18  mov  %i0, %o0
a00c9da8:  40 3b b8 7e  call  0xa0fb7fa0
a00c9dac:  a0 04 00 10  add  %l0, %l0, %l0
a00c9db0:  a0 04 00 19  add  %l0, %i1, %l0
a00c9db4:  d0 2c 3f ff  stb  %o0, [ %l0 + -1 ]
a00c9db8:  90 10 00 18  mov  %i0, %o0
a00c9dbc:  40 3b b8 79  call  0xa0fb7fa0
a00c9dc0:  92 10 20 07  mov  7, %o1
a00c9dc4:  9a 06 a0 01  add  %i2, 1, %o5
a00c9dc8:  83 2b 60 10  sll  %o5, 0x10, %g1
a00c9dcc:  83 30 60 10  srl  %g1, 0x10, %g1
a00c9dd0:  d0 2c 3f fe  stb  %o0, [ %l0 + -2 ]
a00c9dd4:  80 a0 40 11  cmp  %g1, %l1
a00c9dd8:  0a bf ff ed  bcs  0xa00c9d8c
a00c9ddc:  b4 10 00 0d  mov  %o5, %i2
a00c9de0:  81 c7 e0 08  ret
a00c9de4:  81 e8 00 00  restore
