# leon2m FUN_a00b7ae4 0xa00b7ae4-0xa00b7b8c (168 bytes)
a00b7ae4:  9d e3 bf 98  save  %sp, -104, %sp
a00b7ae8:  90 10 21 11  mov  0x111, %o0
a00b7aec:  40 02 3c 19  call  0xa0146b50
a00b7af0:  92 10 20 00  clr  %o1
a00b7af4:  90 10 20 00  clr  %o0
a00b7af8:  40 02 3c 1d  call  0xa0146b6c
a00b7afc:  92 10 20 00  clr  %o1
a00b7b00:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00b7b04:  a0 10 62 90  or  %g1, 0x290, %l0	! 0xa802d290
a00b7b08:  b2 10 20 00  clr  %i1
a00b7b0c:  b4 10 20 00  clr  %i2
a00b7b10:  31 00 06 35  sethi  %hi(0x18d400), %i0
a00b7b14:  83 2e a0 03  sll  %i2, 3, %g1
a00b7b18:  9e 20 40 1a  sub  %g1, %i2, %o7
a00b7b1c:  9b 2b e0 02  sll  %o7, 2, %o5
a00b7b20:  96 03 40 1a  add  %o5, %i2, %o3
a00b7b24:  d8 0c 20 08  ldub  [ %l0 + 8 ], %o4
a00b7b28:  90 02 c0 0c  add  %o3, %o4, %o0
a00b7b2c:  93 2a 20 10  sll  %o0, 0x10, %o1
a00b7b30:  93 32 60 10  srl  %o1, 0x10, %o1
a00b7b34:  7f ff af 44  call  0xa00a3844
a00b7b38:  90 16 21 78  or  %i0, 0x178, %o0
a00b7b3c:  98 10 00 08  mov  %o0, %o4
a00b7b40:  94 06 80 1a  add  %i2, %i2, %o2
a00b7b44:  94 02 a0 06  add  %o2, 6, %o2
a00b7b48:  90 10 20 00  clr  %o0
a00b7b4c:  92 10 20 2a  mov  0x2a, %o1
a00b7b50:  96 10 20 01  mov  1, %o3
a00b7b54:  9a 10 20 00  clr  %o5
a00b7b58:  7f ff ad 93  call  0xa00a31a4
a00b7b5c:  b2 06 60 01  inc  %i1
a00b7b60:  b4 0e 60 ff  and  %i1, 0xff, %i2
a00b7b64:  80 a6 a0 03  cmp  %i2, 3
a00b7b68:  08 bf ff ec  bleu  0xa00b7b18
a00b7b6c:  83 2e a0 03  sll  %i2, 3, %g1
a00b7b70:  f0 0c 20 4a  ldub  [ %l0 + 0x4a ], %i0
a00b7b74:  b2 06 20 02  add  %i0, 2, %i1
a00b7b78:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00b7b7c:  b0 10 20 01  mov  1, %i0
a00b7b80:  7f ff c1 6f  call  0xa00a813c
a00b7b84:  95 e8 20 01  restore  %g0, 1, %o2
a00b7b88:  01 00 00 00  nop
