# leon2s FUN_a0072970 0xa0072970-0xa0072a4c (220 bytes)
a0072970:  9d e3 bf 98  save  %sp, -104, %sp
a0072974:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0072978:  80 a6 20 00  cmp  %i0, 0
a007297c:  02 80 00 07  be  0xa0072998
a0072980:  b6 0e e0 ff  and  %i3, 0xff, %i3
a0072984:  80 a6 20 01  cmp  %i0, 1
a0072988:  02 80 00 15  be  0xa00729dc
a007298c:  01 00 00 00  nop
a0072990:  10 80 00 24  b  0xa0072a20
a0072994:  80 a6 e0 00  cmp  %i3, 0
a0072998:  80 a6 00 1b  cmp  %i0, %i3
a007299c:  1a 80 00 2a  bcc  0xa0072a44
a00729a0:  b0 10 20 00  clr  %i0
a00729a4:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00729a8:  a1 2c 20 02  sll  %l0, 2, %l0
a00729ac:  82 0e 60 ff  and  %i1, 0xff, %g1
a00729b0:  11 27 c2 80  sethi  %hi(0x9f0a0000), %o0
a00729b4:  82 00 40 10  add  %g1, %l0, %g1
a00729b8:  90 12 21 00  or  %o0, 0x100, %o0
a00729bc:  7f ff bb c1  call  0xa00618c0
a00729c0:  90 00 40 08  add  %g1, %o0, %o0
a00729c4:  b0 06 20 01  inc  %i0
a00729c8:  82 0e 20 ff  and  %i0, 0xff, %g1
a00729cc:  80 a0 40 1b  cmp  %g1, %i3
a00729d0:  0a bf ff f5  bcs  0xa00729a4
a00729d4:  d0 26 80 10  st  %o0, [ %i2 + %l0 ]
a00729d8:  30 80 00 1b  b,a   0xa0072a44
a00729dc:  80 a6 e0 00  cmp  %i3, 0
a00729e0:  02 80 00 19  be  0xa0072a44
a00729e4:  b0 10 20 00  clr  %i0
a00729e8:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00729ec:  a1 2c 20 02  sll  %l0, 2, %l0
a00729f0:  82 0e 60 ff  and  %i1, 0xff, %g1
a00729f4:  11 27 c4 c0  sethi  %hi(0x9f130000), %o0
a00729f8:  82 00 40 10  add  %g1, %l0, %g1
a00729fc:  90 12 21 00  or  %o0, 0x100, %o0
a0072a00:  7f ff bb b0  call  0xa00618c0
a0072a04:  90 00 40 08  add  %g1, %o0, %o0
a0072a08:  b0 06 20 01  inc  %i0
a0072a0c:  82 0e 20 ff  and  %i0, 0xff, %g1
a0072a10:  80 a0 40 1b  cmp  %g1, %i3
a0072a14:  0a bf ff f5  bcs  0xa00729e8
a0072a18:  d0 26 80 10  st  %o0, [ %i2 + %l0 ]
a0072a1c:  30 80 00 0a  b,a   0xa0072a44
a0072a20:  02 80 00 09  be  0xa0072a44
a0072a24:  b0 10 20 00  clr  %i0
a0072a28:  82 0e 20 ff  and  %i0, 0xff, %g1
a0072a2c:  b0 06 20 01  inc  %i0
a0072a30:  83 28 60 02  sll  %g1, 2, %g1
a0072a34:  9a 0e 20 ff  and  %i0, 0xff, %o5
a0072a38:  80 a3 40 1b  cmp  %o5, %i3
a0072a3c:  0a bf ff fb  bcs  0xa0072a28
a0072a40:  c0 26 80 01  clr  [ %i2 + %g1 ]
a0072a44:  81 c7 e0 08  ret
a0072a48:  81 e8 00 00  restore
