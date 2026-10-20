# leon2s FUN_a00afdf4 0xa00afdf4-0xa00afeb8 (196 bytes)
a00afdf4:  9d e3 bf 98  save  %sp, -104, %sp
a00afdf8:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00afdfc:  7f c4 5a 0a  call  0x9f1c6624
a00afe00:  90 10 00 10  mov  %l0, %o0
a00afe04:  92 0a 20 ff  and  %o0, 0xff, %o1
a00afe08:  7f ff f7 d0  call  0xa00add48
a00afe0c:  90 10 00 10  mov  %l0, %o0
a00afe10:  82 0e 60 ff  and  %i1, 0xff, %g1
a00afe14:  a2 0a 20 ff  and  %o0, 0xff, %l1
a00afe18:  b0 10 00 10  mov  %l0, %i0
a00afe1c:  b2 10 20 03  mov  3, %i1
a00afe20:  b4 10 20 04  mov  4, %i2
a00afe24:  80 a0 60 01  cmp  %g1, 1
a00afe28:  12 80 00 04  bne  0xa00afe38
a00afe2c:  b6 10 20 00  clr  %i3
a00afe30:  7f ff ff e0  call  0xa00afdb0
a00afe34:  81 e8 00 00  restore
a00afe38:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00afe3c:  c2 08 63 14  ldub  [ %g1 + 0x314 ], %g1	! 0xa8079314
a00afe40:  b0 0a 20 ff  and  %o0, 0xff, %i0
a00afe44:  83 38 40 10  sra  %g1, %l0, %g1
a00afe48:  90 10 00 18  mov  %i0, %o0
a00afe4c:  92 10 20 01  mov  1, %o1
a00afe50:  94 10 20 20  mov  0x20, %o2
a00afe54:  80 88 60 01  btst  1, %g1
a00afe58:  12 80 00 09  bne  0xa00afe7c
a00afe5c:  96 10 20 00  clr  %o3
a00afe60:  7f ff e1 68  call  0xa00a8400
a00afe64:  01 00 00 00  nop
a00afe68:  90 10 00 18  mov  %i0, %o0
a00afe6c:  92 10 20 03  mov  3, %o1
a00afe70:  94 10 20 02  mov  2, %o2
a00afe74:  7f ff e1 63  call  0xa00a8400
a00afe78:  96 10 20 00  clr  %o3
a00afe7c:  90 10 00 11  mov  %l1, %o0
a00afe80:  92 10 20 03  mov  3, %o1
a00afe84:  94 10 20 03  mov  3, %o2
a00afe88:  7f ff e1 5e  call  0xa00a8400
a00afe8c:  96 10 20 01  mov  1, %o3
a00afe90:  90 10 00 11  mov  %l1, %o0
a00afe94:  92 10 20 03  mov  3, %o1
a00afe98:  94 10 20 04  mov  4, %o2
a00afe9c:  7f ff e1 59  call  0xa00a8400
a00afea0:  96 10 20 01  mov  1, %o3
a00afea4:  40 00 06 3c  call  0xa00b1794
a00afea8:  90 10 20 01  mov  1, %o0
a00afeac:  7f ff e1 55  call  0xa00a8400
a00afeb0:  91 e8 00 11  restore  %g0, %l1, %o0
a00afeb4:  01 00 00 00  nop
