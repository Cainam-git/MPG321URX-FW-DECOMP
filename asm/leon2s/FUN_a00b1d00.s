# leon2s FUN_a00b1d00 0xa00b1d00-0xa00b1e2c (300 bytes)
a00b1d00:  9d e3 bf 98  save  %sp, -104, %sp
a00b1d04:  80 a6 20 08  cmp  %i0, 8
a00b1d08:  18 80 00 0a  bgu  0xa00b1d30
a00b1d0c:  a0 10 00 18  mov  %i0, %l0
a00b1d10:  1b 28 02 c7  sethi  %hi(0xa00b1c00), %o5
a00b1d14:  83 2e 20 02  sll  %i0, 2, %g1
a00b1d18:  9a 13 60 dc  or  %o5, 0xdc, %o5
a00b1d1c:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a00b1d20:  81 c0 40 00  jmp  %g1
a00b1d24:  01 00 00 00  nop
a00b1d28:  10 80 00 03  b  0xa00b1d34
a00b1d2c:  94 10 20 00  clr  %o2	! 0x0
a00b1d30:  94 10 3f d0  mov  -48, %o2
a00b1d34:  b0 0c 20 ff  and  %l0, 0xff, %i0
a00b1d38:  94 0a a0 d0  and  %o2, 0xd0, %o2
a00b1d3c:  90 10 00 18  mov  %i0, %o0
a00b1d40:  7f ff d9 7b  call  0xa00a832c
a00b1d44:  92 10 20 00  clr  %o1
a00b1d48:  90 10 00 18  mov  %i0, %o0
a00b1d4c:  92 10 20 01  mov  1, %o1
a00b1d50:  7f ff d9 77  call  0xa00a832c
a00b1d54:  94 10 20 ea  mov  0xea, %o2
a00b1d58:  80 a4 20 08  cmp  %l0, 8
a00b1d5c:  32 80 00 0c  bne,a   0xa00b1d8c
a00b1d60:  94 0e 60 ff  and  %i1, 0xff, %o2
a00b1d64:  1b 33 c0 51  sethi  %hi(0xcf014400), %o5
a00b1d68:  9a 13 60 ac  or  %o5, 0xac, %o5	! 0xcf0144ac
a00b1d6c:  c2 03 40 00  ld  [ %o5 ], %g1
a00b1d70:  82 10 60 80  or  %g1, 0x80, %g1
a00b1d74:  c2 23 40 00  st  %g1, [ %o5 ]
a00b1d78:  90 10 20 08  mov  8, %o0
a00b1d7c:  92 10 20 01  mov  1, %o1
a00b1d80:  7f ff d9 6b  call  0xa00a832c
a00b1d84:  94 10 20 aa  mov  0xaa, %o2
a00b1d88:  94 0e 60 ff  and  %i1, 0xff, %o2
a00b1d8c:  90 10 00 18  mov  %i0, %o0
a00b1d90:  7f ff d9 67  call  0xa00a832c
a00b1d94:  92 10 20 04  mov  4, %o1
a00b1d98:  95 36 60 08  srl  %i1, 8, %o2
a00b1d9c:  94 0a a0 ff  and  %o2, 0xff, %o2
a00b1da0:  90 10 00 18  mov  %i0, %o0
a00b1da4:  7f ff d9 62  call  0xa00a832c
a00b1da8:  92 10 20 05  mov  5, %o1
a00b1dac:  95 36 60 10  srl  %i1, 0x10, %o2
a00b1db0:  94 0a a0 ff  and  %o2, 0xff, %o2
a00b1db4:  90 10 00 18  mov  %i0, %o0
a00b1db8:  7f ff d9 5d  call  0xa00a832c
a00b1dbc:  92 10 20 06  mov  6, %o1
a00b1dc0:  94 0e a0 ff  and  %i2, 0xff, %o2
a00b1dc4:  90 10 00 18  mov  %i0, %o0
a00b1dc8:  7f ff d9 59  call  0xa00a832c
a00b1dcc:  92 10 20 08  mov  8, %o1
a00b1dd0:  95 36 a0 08  srl  %i2, 8, %o2
a00b1dd4:  94 0a a0 ff  and  %o2, 0xff, %o2
a00b1dd8:  90 10 00 18  mov  %i0, %o0
a00b1ddc:  7f ff d9 54  call  0xa00a832c
a00b1de0:  92 10 20 09  mov  9, %o1
a00b1de4:  95 36 a0 10  srl  %i2, 0x10, %o2
a00b1de8:  94 0a a0 ff  and  %o2, 0xff, %o2
a00b1dec:  90 10 00 18  mov  %i0, %o0
a00b1df0:  7f ff d9 4f  call  0xa00a832c
a00b1df4:  92 10 20 0a  mov  0xa, %o1
a00b1df8:  90 10 00 18  mov  %i0, %o0
a00b1dfc:  92 10 20 03  mov  3, %o1
a00b1e00:  7f ff d9 4b  call  0xa00a832c
a00b1e04:  94 10 20 03  mov  3, %o2
a00b1e08:  90 10 00 18  mov  %i0, %o0
a00b1e0c:  92 10 20 03  mov  3, %o1
a00b1e10:  7f ff d9 47  call  0xa00a832c
a00b1e14:  94 10 20 07  mov  7, %o2
a00b1e18:  7f ff fe 5f  call  0xa00b1794
a00b1e1c:  90 10 20 01  mov  1, %o0
a00b1e20:  b2 10 20 03  mov  3, %i1
a00b1e24:  7f ff d9 42  call  0xa00a832c
a00b1e28:  95 e8 20 03  restore  %g0, 3, %o2
