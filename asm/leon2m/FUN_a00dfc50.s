# leon2m FUN_a00dfc50 0xa00dfc50-0xa00dff94 (380 bytes)
a00dfc50:  9d e3 bf 98  save  %sp, -104, %sp
a00dfc54:  80 a6 20 02  cmp  %i0, 2
a00dfc58:  08 80 00 0e  bleu  0xa00dfc90
a00dfc5c:  a2 10 20 00  clr  %l1
a00dfc60:  17 2a 00 ad  sethi  %hi(0xa802b400), %o3
a00dfc64:  da 02 e1 30  ld  [ %o3 + 0x130 ], %o5	! 0xa802b530
a00dfc68:  03 00 06 64  sethi  %hi(0x199000), %g1
a00dfc6c:  80 a3 60 0c  cmp  %o5, 0xc
a00dfc70:  18 80 00 1c  bgu  0xa00dfce0
a00dfc74:  92 10 62 88  or  %g1, 0x288, %o1
a00dfc78:  91 2b 60 02  sll  %o5, 2, %o0
a00dfc7c:  13 00 01 fd  sethi  %hi(0x7f400), %o1
a00dfc80:  9a 12 63 d0  or  %o1, 0x3d0, %o5	! 0x7f7d0
a00dfc84:  d8 03 40 08  ld  [ %o5 + %o0 ], %o4
a00dfc88:  81 c3 00 00  jmp  %o4
a00dfc8c:  01 00 00 00  nop
a00dfc90:  b0 1e 60 02  xor  %i1, 2, %i0
a00dfc94:  80 a0 00 18  cmp  %g0, %i0
a00dfc98:  a0 60 3f ff  subx  %g0, -1, %l0
a00dfc9c:  80 a4 20 00  cmp  %l0, 0
a00dfca0:  32 80 00 31  bne,a   0xa00dfd64
a00dfca4:  a0 06 bf fd  add  %i2, -3, %l0
a00dfca8:  17 2a 00 ad  sethi  %hi(0xa802b400), %o3
a00dfcac:  da 02 e1 30  ld  [ %o3 + 0x130 ], %o5	! 0xa802b530
a00dfcb0:  19 00 06 64  sethi  %hi(0x199000), %o4
a00dfcb4:  80 a3 60 0c  cmp  %o5, 0xc
a00dfcb8:  18 80 00 1a  bgu  0xa00dfd20
a00dfcbc:  92 13 22 88  or  %o4, 0x288, %o1
a00dfcc0:  91 2b 60 02  sll  %o5, 2, %o0
a00dfcc4:  15 00 01 fd  sethi  %hi(0x7f400), %o2
a00dfcc8:  9a 12 a3 9c  or  %o2, 0x39c, %o5	! 0x7f79c
a00dfccc:  d2 03 40 08  ld  [ %o5 + %o0 ], %o1
a00dfcd0:  81 c2 40 00  jmp  %o1
a00dfcd4:  01 00 00 00  nop
a00dfcd8:  21 00 06 64  sethi  %hi(0x199000), %l0
a00dfcdc:  92 14 22 90  or  %l0, 0x290, %o1	! 0x199290
a00dfce0:  03 00 06 64  sethi  %hi(0x199000), %g1
a00dfce4:  b4 12 e1 30  or  %o3, 0x130, %i2
a00dfce8:  d6 06 a0 08  ld  [ %i2 + 8 ], %o3
a00dfcec:  90 10 62 98  or  %g1, 0x298, %o0
a00dfcf0:  7f ff fd 20  call  0xa00df170
a00dfcf4:  d4 06 a0 04  ld  [ %i2 + 4 ], %o2
a00dfcf8:  40 00 03 b8  call  0xa00e0bd8
a00dfcfc:  01 00 00 00  nop
a00dfd00:  17 00 06 64  sethi  %hi(0x199000), %o3
a00dfd04:  90 12 e3 28  or  %o3, 0x328, %o0	! 0x199328
a00dfd08:  92 10 00 18  mov  %i0, %o1
a00dfd0c:  7f ff fd 19  call  0xa00df170
a00dfd10:  b0 10 00 11  mov  %l1, %i0
a00dfd14:  30 80 00 9e  b,a   0xa00dff8c
a00dfd18:  11 00 06 64  sethi  %hi(0x199000), %o0
a00dfd1c:  92 12 22 90  or  %o0, 0x290, %o1	! 0x199290
a00dfd20:  15 00 06 64  sethi  %hi(0x199000), %o2
a00dfd24:  9e 12 e1 30  or  %o3, 0x130, %o7
a00dfd28:  90 12 a2 98  or  %o2, 0x298, %o0
a00dfd2c:  d6 03 e0 08  ld  [ %o7 + 8 ], %o3
a00dfd30:  d4 03 e0 04  ld  [ %o7 + 4 ], %o2
a00dfd34:  7f ff fd 0f  call  0xa00df170
a00dfd38:  01 00 00 00  nop
a00dfd3c:  40 00 03 a7  call  0xa00e0bd8
a00dfd40:  01 00 00 00  nop
a00dfd44:  17 00 06 64  sethi  %hi(0x199000), %o3
a00dfd48:  90 12 e3 40  or  %o3, 0x340, %o0	! 0x199340
a00dfd4c:  7f ff fd 09  call  0xa00df170
a00dfd50:  92 10 00 19  mov  %i1, %o1
a00dfd54:  80 a4 20 00  cmp  %l0, 0
a00dfd58:  02 80 00 8d  be  0xa00dff8c
a00dfd5c:  b0 10 00 11  mov  %l1, %i0
a00dfd60:  a0 06 bf fd  add  %i2, -3, %l0
a00dfd64:  80 a4 20 01  cmp  %l0, 1
a00dfd68:  28 80 00 88  bleu,a   0xa00dff88
a00dfd6c:  a2 10 20 01  mov  1, %l1
a00dfd70:  17 2a 00 ad  sethi  %hi(0xa802b400), %o3
a00dfd74:  da 02 e1 30  ld  [ %o3 + 0x130 ], %o5	! 0xa802b530
a00dfd78:  33 00 06 64  sethi  %hi(0x199000), %i1
a00dfd7c:  80 a3 60 0c  cmp  %o5, 0xc
a00dfd80:  18 80 00 0a  bgu  0xa00dfda8
a00dfd84:  92 16 62 88  or  %i1, 0x288, %o1
a00dfd88:  19 00 01 fd  sethi  %hi(0x7f400), %o4
a00dfd8c:  83 2b 60 02  sll  %o5, 2, %g1
a00dfd90:  b0 13 23 68  or  %o4, 0x368, %i0
a00dfd94:  d2 06 00 01  ld  [ %i0 + %g1 ], %o1
a00dfd98:  81 c2 40 00  jmp  %o1
a00dfd9c:  01 00 00 00  nop
a00dfda0:  1f 00 06 64  sethi  %hi(0x199000), %o7
a00dfda4:  92 13 e2 90  or  %o7, 0x290, %o1	! 0x199290
a00dfda8:  a0 12 e1 30  or  %o3, 0x130, %l0
a00dfdac:  33 00 06 64  sethi  %hi(0x199000), %i1
a00dfdb0:  d6 04 20 08  ld  [ %l0 + 8 ], %o3
a00dfdb4:  d4 04 20 04  ld  [ %l0 + 4 ], %o2
a00dfdb8:  7f ff fc ee  call  0xa00df170
a00dfdbc:  90 16 62 98  or  %i1, 0x298, %o0
a00dfdc0:  40 00 03 86  call  0xa00e0bd8
a00dfdc4:  01 00 00 00  nop
a00dfdc8:  17 00 06 64  sethi  %hi(0x199000), %o3
a00dfdcc:  90 12 e3 60  or  %o3, 0x360, %o0	! 0x199360
a00dfdd0:  10 bf ff cf  b  0xa00dfd0c
a00dfdd4:  92 10 00 1a  mov  %i2, %o1
a00dfdd8:  33 00 06 64  sethi  %hi(0x199000), %i1
a00dfddc:  10 bf ff c1  b  0xa00dfce0
a00dfde0:  92 16 62 b0  or  %i1, 0x2b0, %o1	! 0x1992b0
a00dfde4:  15 00 06 64  sethi  %hi(0x199000), %o2
a00dfde8:  10 bf ff be  b  0xa00dfce0
a00dfdec:  92 12 a3 20  or  %o2, 0x320, %o1	! 0x199320
a00dfdf0:  1f 00 06 64  sethi  %hi(0x199000), %o7
a00dfdf4:  10 bf ff bb  b  0xa00dfce0
a00dfdf8:  92 13 e3 10  or  %o7, 0x310, %o1	! 0x199310
a00dfdfc:  21 00 06 64  sethi  %hi(0x199000), %l0
a00dfe00:  10 bf ff b8  b  0xa00dfce0
a00dfe04:  92 14 23 08  or  %l0, 0x308, %o1	! 0x199308
a00dfe08:  33 00 06 64  sethi  %hi(0x199000), %i1
a00dfe0c:  10 bf ff b5  b  0xa00dfce0
a00dfe10:  92 16 63 00  or  %i1, 0x300, %o1	! 0x199300
a00dfe14:  35 00 06 64  sethi  %hi(0x199000), %i2
a00dfe18:  10 bf ff b2  b  0xa00dfce0
a00dfe1c:  92 16 a2 f8  or  %i2, 0x2f8, %o1	! 0x1992f8
a00dfe20:  03 00 06 64  sethi  %hi(0x199000), %g1
a00dfe24:  10 bf ff af  b  0xa00dfce0
a00dfe28:  92 10 62 f0  or  %g1, 0x2f0, %o1	! 0x1992f0
a00dfe2c:  19 00 06 64  sethi  %hi(0x199000), %o4
a00dfe30:  10 bf ff ac  b  0xa00dfce0
a00dfe34:  92 13 22 e8  or  %o4, 0x2e8, %o1	! 0x1992e8
a00dfe38:  11 00 06 64  sethi  %hi(0x199000), %o0
a00dfe3c:  10 bf ff a9  b  0xa00dfce0
a00dfe40:  92 12 22 d8  or  %o0, 0x2d8, %o1	! 0x1992d8
a00dfe44:  1b 00 06 64  sethi  %hi(0x199000), %o5
a00dfe48:  10 bf ff a6  b  0xa00dfce0
a00dfe4c:  92 13 62 d0  or  %o5, 0x2d0, %o1	! 0x1992d0
a00dfe50:  15 00 06 64  sethi  %hi(0x199000), %o2
a00dfe54:  10 bf ff a3  b  0xa00dfce0
a00dfe58:  92 12 a2 c8  or  %o2, 0x2c8, %o1	! 0x1992c8
a00dfe5c:  1f 00 06 64  sethi  %hi(0x199000), %o7
a00dfe60:  10 bf ff a0  b  0xa00dfce0
a00dfe64:  92 13 e2 b8  or  %o7, 0x2b8, %o1	! 0x1992b8
a00dfe68:  1b 00 06 64  sethi  %hi(0x199000), %o5
a00dfe6c:  10 bf ff ad  b  0xa00dfd20
a00dfe70:  92 13 62 b0  or  %o5, 0x2b0, %o1	! 0x1992b0
a00dfe74:  19 00 06 64  sethi  %hi(0x199000), %o4
a00dfe78:  10 bf ff aa  b  0xa00dfd20
a00dfe7c:  92 13 22 b8  or  %o4, 0x2b8, %o1	! 0x1992b8
a00dfe80:  31 00 06 64  sethi  %hi(0x199000), %i0
a00dfe84:  10 bf ff a7  b  0xa00dfd20
a00dfe88:  92 16 22 c8  or  %i0, 0x2c8, %o1	! 0x1992c8
a00dfe8c:  03 00 06 64  sethi  %hi(0x199000), %g1
a00dfe90:  10 bf ff a4  b  0xa00dfd20
a00dfe94:  92 10 62 d0  or  %g1, 0x2d0, %o1	! 0x1992d0
a00dfe98:  1f 00 06 64  sethi  %hi(0x199000), %o7
a00dfe9c:  10 bf ff a1  b  0xa00dfd20
a00dfea0:  92 13 e2 d8  or  %o7, 0x2d8, %o1	! 0x1992d8
a00dfea4:  15 00 06 64  sethi  %hi(0x199000), %o2
a00dfea8:  10 bf ff 9e  b  0xa00dfd20
a00dfeac:  92 12 a2 e8  or  %o2, 0x2e8, %o1	! 0x1992e8
a00dfeb0:  1b 00 06 64  sethi  %hi(0x199000), %o5
a00dfeb4:  10 bf ff 9b  b  0xa00dfd20
a00dfeb8:  92 13 62 f0  or  %o5, 0x2f0, %o1	! 0x1992f0
a00dfebc:  11 00 06 64  sethi  %hi(0x199000), %o0
a00dfec0:  10 bf ff 98  b  0xa00dfd20
a00dfec4:  92 12 22 f8  or  %o0, 0x2f8, %o1	! 0x1992f8
a00dfec8:  19 00 06 64  sethi  %hi(0x199000), %o4
a00dfecc:  10 bf ff 95  b  0xa00dfd20
a00dfed0:  92 13 23 00  or  %o4, 0x300, %o1	! 0x199300
a00dfed4:  31 00 06 64  sethi  %hi(0x199000), %i0
a00dfed8:  10 bf ff 92  b  0xa00dfd20
a00dfedc:  92 16 23 08  or  %i0, 0x308, %o1	! 0x199308
a00dfee0:  03 00 06 64  sethi  %hi(0x199000), %g1
a00dfee4:  10 bf ff 8f  b  0xa00dfd20
a00dfee8:  92 10 63 10  or  %g1, 0x310, %o1	! 0x199310
a00dfeec:  1f 00 06 64  sethi  %hi(0x199000), %o7
a00dfef0:  10 bf ff 8c  b  0xa00dfd20
a00dfef4:  92 13 e3 20  or  %o7, 0x320, %o1	! 0x199320
a00dfef8:  15 00 06 64  sethi  %hi(0x199000), %o2
a00dfefc:  10 bf ff ab  b  0xa00dfda8
a00dff00:  92 12 a2 b0  or  %o2, 0x2b0, %o1	! 0x1992b0
a00dff04:  15 00 06 64  sethi  %hi(0x199000), %o2
a00dff08:  10 bf ff a8  b  0xa00dfda8
a00dff0c:  92 12 a3 00  or  %o2, 0x300, %o1	! 0x199300
a00dff10:  1f 00 06 64  sethi  %hi(0x199000), %o7
a00dff14:  10 bf ff a5  b  0xa00dfda8
a00dff18:  92 13 e3 08  or  %o7, 0x308, %o1	! 0x199308
a00dff1c:  1b 00 06 64  sethi  %hi(0x199000), %o5
a00dff20:  10 bf ff a2  b  0xa00dfda8
a00dff24:  92 13 63 10  or  %o5, 0x310, %o1	! 0x199310
a00dff28:  11 00 06 64  sethi  %hi(0x199000), %o0
a00dff2c:  10 bf ff 9f  b  0xa00dfda8
a00dff30:  92 12 23 20  or  %o0, 0x320, %o1	! 0x199320
a00dff34:  1b 00 06 64  sethi  %hi(0x199000), %o5
a00dff38:  10 bf ff 9c  b  0xa00dfda8
a00dff3c:  92 13 62 b8  or  %o5, 0x2b8, %o1	! 0x1992b8
a00dff40:  11 00 06 64  sethi  %hi(0x199000), %o0
a00dff44:  10 bf ff 99  b  0xa00dfda8
a00dff48:  92 12 22 c8  or  %o0, 0x2c8, %o1	! 0x1992c8
a00dff4c:  19 00 06 64  sethi  %hi(0x199000), %o4
a00dff50:  10 bf ff 96  b  0xa00dfda8
a00dff54:  92 13 22 d0  or  %o4, 0x2d0, %o1	! 0x1992d0
a00dff58:  31 00 06 64  sethi  %hi(0x199000), %i0
a00dff5c:  10 bf ff 93  b  0xa00dfda8
a00dff60:  92 16 22 d8  or  %i0, 0x2d8, %o1	! 0x1992d8
a00dff64:  03 00 06 64  sethi  %hi(0x199000), %g1
a00dff68:  10 bf ff 90  b  0xa00dfda8
a00dff6c:  92 10 62 e8  or  %g1, 0x2e8, %o1	! 0x1992e8
a00dff70:  33 00 06 64  sethi  %hi(0x199000), %i1
a00dff74:  10 bf ff 8d  b  0xa00dfda8
a00dff78:  92 16 62 f0  or  %i1, 0x2f0, %o1	! 0x1992f0
a00dff7c:  21 00 06 64  sethi  %hi(0x199000), %l0
a00dff80:  10 bf ff 8a  b  0xa00dfda8
a00dff84:  92 14 22 f8  or  %l0, 0x2f8, %o1	! 0x1992f8
a00dff88:  b0 10 00 11  mov  %l1, %i0
a00dff8c:  81 c7 e0 08  ret
a00dff90:  81 e8 00 00  restore
