# leon2m FUN_a00cfacc 0xa00cfacc-0xa00d0e48 (4516 bytes)
a00cfacc:  9d e3 bf 98  save  %sp, -104, %sp
a00cfad0:  d6 0e 20 04  ldub  [ %i0 + 4 ], %o3
a00cfad4:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00cfad8:  80 a3 60 04  cmp  %o5, 4
a00cfadc:  02 80 00 2d  be  0xa00cfb90
a00cfae0:  a4 10 20 00  clr  %l2
a00cfae4:  80 a3 60 14  cmp  %o5, 0x14
a00cfae8:  02 80 00 91  be  0xa00cfd2c
a00cfaec:  80 a3 60 1f  cmp  %o5, 0x1f
a00cfaf0:  22 80 00 29  be,a   0xa00cfb94
a00cfaf4:  a4 10 20 01  mov  1, %l2
a00cfaf8:  80 a3 60 60  cmp  %o5, 0x60
a00cfafc:  02 80 00 25  be  0xa00cfb90
a00cfb00:  80 a3 60 cc  cmp  %o5, 0xcc
a00cfb04:  02 80 00 23  be  0xa00cfb90
a00cfb08:  80 a3 60 e1  cmp  %o5, 0xe1
a00cfb0c:  22 80 00 ed  be,a   0xa00cfec0
a00cfb10:  d0 0e 20 05  ldub  [ %i0 + 5 ], %o0
a00cfb14:  80 a2 e0 e1  cmp  %o3, 0xe1
a00cfb18:  22 80 01 16  be,a   0xa00cff70
a00cfb1c:  d4 0e 20 05  ldub  [ %i0 + 5 ], %o2
a00cfb20:  80 a2 e0 08  cmp  %o3, 8
a00cfb24:  22 80 01 22  be,a   0xa00cffac
a00cfb28:  e0 0e 20 05  ldub  [ %i0 + 5 ], %l0
a00cfb2c:  82 0a e0 ff  and  %o3, 0xff, %g1
a00cfb30:  80 a0 60 10  cmp  %g1, 0x10
a00cfb34:  02 80 01 27  be  0xa00cffd0
a00cfb38:  80 a0 60 e1  cmp  %g1, 0xe1
a00cfb3c:  12 80 00 17  bne  0xa00cfb98
a00cfb40:  82 0a e0 ff  and  %o3, 0xff, %g1
a00cfb44:  e8 0e 20 05  ldub  [ %i0 + 5 ], %l4
a00cfb48:  80 a5 20 a4  cmp  %l4, 0xa4
a00cfb4c:  12 80 00 14  bne  0xa00cfb9c
a00cfb50:  80 a0 60 60  cmp  %g1, 0x60
a00cfb54:  d8 0e 20 06  ldub  [ %i0 + 6 ], %o4
a00cfb58:  94 03 3f de  add  %o4, -34, %o2
a00cfb5c:  92 0a a0 ff  and  %o2, 0xff, %o1
a00cfb60:  80 a2 60 02  cmp  %o1, 2
a00cfb64:  90 60 20 00  subx  %g0, 0, %o0
a00cfb68:  82 1b 20 20  xor  %o4, 0x20, %g1
a00cfb6c:  80 a0 00 01  cmp  %g0, %g1
a00cfb70:  ac 0a 20 01  and  %o0, 1, %l6
a00cfb74:  aa 60 3f ff  subx  %g0, -1, %l5
a00cfb78:  80 95 80 15  orcc  %l6, %l5, %g0
a00cfb7c:  32 80 00 06  bne,a   0xa00cfb94
a00cfb80:  a4 10 20 01  mov  1, %l2
a00cfb84:  80 a3 20 21  cmp  %o4, 0x21
a00cfb88:  12 80 00 04  bne  0xa00cfb98
a00cfb8c:  82 0a e0 ff  and  %o3, 0xff, %g1
a00cfb90:  a4 10 20 01  mov  1, %l2
a00cfb94:  82 0a e0 ff  and  %o3, 0xff, %g1
a00cfb98:  80 a0 60 60  cmp  %g1, 0x60
a00cfb9c:  02 80 00 50  be  0xa00cfcdc
a00cfba0:  80 a0 60 60  cmp  %g1, 0x60
a00cfba4:  14 80 00 1e  bg  0xa00cfc1c
a00cfba8:  80 a0 60 d6  cmp  %g1, 0xd6
a00cfbac:  80 a0 60 14  cmp  %g1, 0x14
a00cfbb0:  22 80 00 e1  be,a   0xa00cff34
a00cfbb4:  c2 0e 20 07  ldub  [ %i0 + 7 ], %g1
a00cfbb8:  04 80 00 a3  ble  0xa00cfe44
a00cfbbc:  80 a0 60 08  cmp  %g1, 8
a00cfbc0:  80 a0 60 18  cmp  %g1, 0x18
a00cfbc4:  02 80 02 5d  be  0xa00d0538
a00cfbc8:  92 10 20 00  clr  %o1
a00cfbcc:  14 80 01 07  bg  0xa00cffe8
a00cfbd0:  80 a0 60 1a  cmp  %g1, 0x1a
a00cfbd4:  80 a0 60 16  cmp  %g1, 0x16
a00cfbd8:  32 80 00 29  bne,a   0xa00cfc7c
a00cfbdc:  80 8c a0 ff  btst  0xff, %l2
a00cfbe0:  92 10 20 00  clr  %o1
a00cfbe4:  40 01 d8 c1  call  0xa0145ee8
a00cfbe8:  90 10 20 00  clr  %o0
a00cfbec:  40 01 d8 f0  call  0xa0145fac
a00cfbf0:  90 10 20 01  mov  1, %o0
a00cfbf4:  da 0e 20 07  ldub  [ %i0 + 7 ], %o5
a00cfbf8:  92 10 00 0d  mov  %o5, %o1
a00cfbfc:  90 02 60 01  add  %o1, 1, %o0
a00cfc00:  a9 2a 20 10  sll  %o0, 0x10, %l4
a00cfc04:  2d 2a 00 ac  sethi  %hi(0xa802b000), %l6
a00cfc08:  da 2d a0 a2  stb  %o5, [ %l6 + 0xa2 ]	! 0xa802b0a2
a00cfc0c:  40 01 ae 08  call  0xa013b42c
a00cfc10:  91 35 20 10  srl  %l4, 0x10, %o0
a00cfc14:  10 80 00 1a  b  0xa00cfc7c
a00cfc18:  80 8c a0 ff  btst  0xff, %l2
a00cfc1c:  02 80 00 b6  be  0xa00cfef4
a00cfc20:  80 a0 60 d6  cmp  %g1, 0xd6
a00cfc24:  14 80 00 48  bg  0xa00cfd44
a00cfc28:  80 a0 60 e2  cmp  %g1, 0xe2
a00cfc2c:  80 a0 60 6e  cmp  %g1, 0x6e
a00cfc30:  02 80 02 39  be  0xa00d0514
a00cfc34:  92 10 20 00  clr  %o1
a00cfc38:  14 80 01 02  bg  0xa00d0040
a00cfc3c:  80 a0 60 70  cmp  %g1, 0x70
a00cfc40:  80 a0 60 6c  cmp  %g1, 0x6c
a00cfc44:  12 80 00 0e  bne  0xa00cfc7c
a00cfc48:  80 8c a0 ff  btst  0xff, %l2
a00cfc4c:  92 10 20 00  clr  %o1
a00cfc50:  40 01 d8 a6  call  0xa0145ee8
a00cfc54:  90 10 20 00  clr  %o0
a00cfc58:  40 01 d8 d5  call  0xa0145fac
a00cfc5c:  90 10 20 01  mov  1, %o0
a00cfc60:  c2 0e 20 07  ldub  [ %i0 + 7 ], %g1
a00cfc64:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00cfc68:  40 00 12 8a  call  0xa00d4690
a00cfc6c:  c2 2c 22 a5  stb  %g1, [ %l0 + 0x2a5 ]	! 0xa802d2a5
a00cfc70:  7f fe e8 a8  call  0xa0089f10
a00cfc74:  01 00 00 00  nop
a00cfc78:  80 8c a0 ff  btst  0xff, %l2
a00cfc7c:  02 80 04 71  be  0xa00d0e40
a00cfc80:  90 10 20 00  clr  %o0
a00cfc84:  a0 10 20 04  mov  4, %l0
a00cfc88:  82 10 20 04  mov  4, %g1
a00cfc8c:  a5 2a 20 10  sll  %o0, 0x10, %l2
a00cfc90:  d0 08 40 18  ldub  [ %g1 + %i0 ], %o0
a00cfc94:  7f ff fb 77  call  0xa00cea70
a00cfc98:  93 34 a0 10  srl  %l2, 0x10, %o1
a00cfc9c:  a0 04 20 01  inc  %l0
a00cfca0:  82 0c 20 ff  and  %l0, 0xff, %g1
a00cfca4:  80 a0 60 07  cmp  %g1, 7
a00cfca8:  28 bf ff fa  bleu,a   0xa00cfc90
a00cfcac:  a5 2a 20 10  sll  %o0, 0x10, %l2
a00cfcb0:  b1 32 20 08  srl  %o0, 8, %i0
a00cfcb4:  d0 2e 60 04  stb  %o0, [ %i1 + 4 ]
a00cfcb8:  90 10 20 6e  mov  0x6e, %o0
a00cfcbc:  94 10 3f 83  mov  -125, %o2
a00cfcc0:  82 10 20 02  mov  2, %g1
a00cfcc4:  f0 2e 60 03  stb  %i0, [ %i1 + 3 ]
a00cfcc8:  d0 2e 40 00  stb  %o0, [ %i1 ]
a00cfccc:  d4 2e 60 01  stb  %o2, [ %i1 + 1 ]
a00cfcd0:  c2 2e 60 02  stb  %g1, [ %i1 + 2 ]
a00cfcd4:  7f fe e8 a3  call  0xa0089f60
a00cfcd8:  91 e8 20 50  restore  %g0, 0x50, %o0
a00cfcdc:  c2 0e 20 05  ldub  [ %i0 + 5 ], %g1
a00cfce0:  80 a0 60 03  cmp  %g1, 3
a00cfce4:  02 80 00 81  be  0xa00cfee8
a00cfce8:  9a 10 20 02  mov  2, %o5
a00cfcec:  80 a0 60 11  cmp  %g1, 0x11
a00cfcf0:  02 80 00 7e  be  0xa00cfee8
a00cfcf4:  9a 10 20 04  mov  4, %o5
a00cfcf8:  80 a0 60 12  cmp  %g1, 0x12
a00cfcfc:  02 80 00 7b  be  0xa00cfee8
a00cfd00:  9a 10 20 06  mov  6, %o5
a00cfd04:  80 a0 60 0f  cmp  %g1, 0xf
a00cfd08:  02 80 00 78  be  0xa00cfee8
a00cfd0c:  9a 10 20 0b  mov  0xb, %o5
a00cfd10:  80 a0 60 10  cmp  %g1, 0x10
a00cfd14:  02 80 00 74  be  0xa00cfee4
a00cfd18:  80 a0 60 01  cmp  %g1, 1
a00cfd1c:  12 bf ff d5  bne  0xa00cfc70
a00cfd20:  27 2a 00 b4  sethi  %hi(0xa802d000), %l3
a00cfd24:  10 bf ff d3  b  0xa00cfc70
a00cfd28:  c0 2c e2 ae  clrb  [ %l3 + 0x2ae ]	! 0xa802d2ae
a00cfd2c:  c2 0e 20 07  ldub  [ %i0 + 7 ], %g1
a00cfd30:  80 a0 60 00  cmp  %g1, 0
a00cfd34:  12 bf ff 72  bne  0xa00cfafc
a00cfd38:  80 a3 60 60  cmp  %o5, 0x60
a00cfd3c:  10 bf ff 96  b  0xa00cfb94
a00cfd40:  a4 10 20 01  mov  1, %l2
a00cfd44:  02 80 01 b3  be  0xa00d0410
a00cfd48:  80 a0 60 e2  cmp  %g1, 0xe2
a00cfd4c:  14 80 00 ca  bg  0xa00d0074
a00cfd50:  80 a0 60 e7  cmp  %g1, 0xe7
a00cfd54:  80 a0 60 e1  cmp  %g1, 0xe1
a00cfd58:  12 bf ff c9  bne  0xa00cfc7c
a00cfd5c:  80 8c a0 ff  btst  0xff, %l2
a00cfd60:  da 0e 20 05  ldub  [ %i0 + 5 ], %o5
a00cfd64:  80 a3 60 a0  cmp  %o5, 0xa0
a00cfd68:  22 80 02 6d  be,a   0xa00d071c
a00cfd6c:  c2 0e 20 06  ldub  [ %i0 + 6 ], %g1
a00cfd70:  80 a3 60 a1  cmp  %o5, 0xa1
a00cfd74:  22 80 02 82  be,a   0xa00d077c
a00cfd78:  e2 0e 20 06  ldub  [ %i0 + 6 ], %l1
a00cfd7c:  80 a3 60 a2  cmp  %o5, 0xa2
a00cfd80:  22 80 02 b0  be,a   0xa00d0840
a00cfd84:  de 0e 20 06  ldub  [ %i0 + 6 ], %o7
a00cfd88:  80 a3 60 a3  cmp  %o5, 0xa3
a00cfd8c:  22 80 02 96  be,a   0xa00d07e4
a00cfd90:  d8 0e 20 06  ldub  [ %i0 + 6 ], %o4
a00cfd94:  80 a3 60 a5  cmp  %o5, 0xa5
a00cfd98:  22 80 02 86  be,a   0xa00d07b0
a00cfd9c:  ec 0e 20 06  ldub  [ %i0 + 6 ], %l6
a00cfda0:  82 0b 60 ff  and  %o5, 0xff, %g1
a00cfda4:  80 a0 60 ed  cmp  %g1, 0xed
a00cfda8:  02 80 03 1f  be  0xa00d0a24
a00cfdac:  80 a0 60 a7  cmp  %g1, 0xa7
a00cfdb0:  22 80 03 23  be,a   0xa00d0a3c
a00cfdb4:  de 0e 20 06  ldub  [ %i0 + 6 ], %o7
a00cfdb8:  80 a3 60 a7  cmp  %o5, 0xa7
a00cfdbc:  12 bf ff b0  bne  0xa00cfc7c
a00cfdc0:  80 8c a0 ff  btst  0xff, %l2
a00cfdc4:  e2 0e 20 06  ldub  [ %i0 + 6 ], %l1
a00cfdc8:  80 a4 60 03  cmp  %l1, 3
a00cfdcc:  02 80 03 58  be  0xa00d0b2c
a00cfdd0:  80 a3 60 a7  cmp  %o5, 0xa7
a00cfdd4:  12 bf ff aa  bne  0xa00cfc7c
a00cfdd8:  80 8c a0 ff  btst  0xff, %l2
a00cfddc:  da 0e 20 06  ldub  [ %i0 + 6 ], %o5
a00cfde0:  80 a3 60 13  cmp  %o5, 0x13
a00cfde4:  12 bf ff a6  bne  0xa00cfc7c
a00cfde8:  80 8c a0 ff  btst  0xff, %l2
a00cfdec:  d0 0e 20 07  ldub  [ %i0 + 7 ], %o0
a00cfdf0:  80 a2 20 01  cmp  %o0, 1
a00cfdf4:  02 80 03 c7  be  0xa00d0d10
a00cfdf8:  90 10 23 6f  mov  0x36f, %o0
a00cfdfc:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00cfe00:  a6 14 22 90  or  %l0, 0x290, %l3	! 0xa802d290
a00cfe04:  c2 04 e1 d4  ld  [ %l3 + 0x1d4 ], %g1
a00cfe08:  92 08 7f bf  and  %g1, -65, %o1
a00cfe0c:  9a 10 20 46  mov  0x46, %o5
a00cfe10:  d2 24 e1 d4  st  %o1, [ %l3 + 0x1d4 ]
a00cfe14:  d0 34 e1 da  sth  %o0, [ %l3 + 0x1da ]
a00cfe18:  40 00 23 af  call  0xa00d8cd4
a00cfe1c:  da 2c e0 09  stb  %o5, [ %l3 + 9 ]
a00cfe20:  40 00 12 de  call  0xa00d4998
a00cfe24:  01 00 00 00  nop
a00cfe28:  92 10 00 13  mov  %l3, %o1
a00cfe2c:  94 10 20 00  clr  %o2
a00cfe30:  96 10 21 fc  mov  0x1fc, %o3
a00cfe34:  40 01 ec 27  call  0xa014aed0
a00cfe38:  90 10 20 30  mov  0x30, %o0
a00cfe3c:  10 bf ff 90  b  0xa00cfc7c
a00cfe40:  80 8c a0 ff  btst  0xff, %l2
a00cfe44:  02 80 01 54  be  0xa00d0394
a00cfe48:  80 a0 60 08  cmp  %g1, 8
a00cfe4c:  14 80 00 d5  bg  0xa00d01a0
a00cfe50:  80 a0 60 10  cmp  %g1, 0x10
a00cfe54:  80 a0 60 04  cmp  %g1, 4
a00cfe58:  12 bf ff 89  bne  0xa00cfc7c
a00cfe5c:  80 8c a0 ff  btst  0xff, %l2
a00cfe60:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00cfe64:  a2 13 e2 90  or  %o7, 0x290, %l1	! 0xa802d290
a00cfe68:  1b 00 00 15  sethi  %hi(0x5400), %o5
a00cfe6c:  a6 13 61 aa  or  %o5, 0x1aa, %l3	! 0x55aa
a00cfe70:  d8 14 61 f6  lduh  [ %l1 + 0x1f6 ], %o4
a00cfe74:  96 1b 00 13  xor  %o4, %l3, %o3
a00cfe78:  80 a0 00 0b  cmp  %g0, %o3
a00cfe7c:  40 00 31 58  call  0xa00dc3dc
a00cfe80:  a0 60 3f ff  subx  %g0, -1, %l0
a00cfe84:  7f fe e8 23  call  0xa0089f10
a00cfe88:  01 00 00 00  nop
a00cfe8c:  80 a4 20 00  cmp  %l0, 0
a00cfe90:  02 bf ff 78  be  0xa00cfc70
a00cfe94:  01 00 00 00  nop
a00cfe98:  e8 14 61 f6  lduh  [ %l1 + 0x1f6 ], %l4
a00cfe9c:  80 a5 00 13  cmp  %l4, %l3
a00cfea0:  02 bf ff 74  be  0xa00cfc70
a00cfea4:  01 00 00 00  nop
a00cfea8:  40 01 53 02  call  0xa0124ab0
a00cfeac:  01 00 00 00  nop
a00cfeb0:  40 01 53 12  call  0xa0124af8
a00cfeb4:  01 00 00 00  nop
a00cfeb8:  10 bf ff 71  b  0xa00cfc7c
a00cfebc:  80 8c a0 ff  btst  0xff, %l2
a00cfec0:  80 a2 20 a0  cmp  %o0, 0xa0
a00cfec4:  12 bf ff 15  bne  0xa00cfb18
a00cfec8:  80 a2 e0 e1  cmp  %o3, 0xe1
a00cfecc:  d2 0e 20 06  ldub  [ %i0 + 6 ], %o1
a00cfed0:  80 a2 60 00  cmp  %o1, 0
a00cfed4:  22 bf ff 30  be,a   0xa00cfb94
a00cfed8:  a4 10 20 01  mov  1, %l2
a00cfedc:  10 bf ff 0f  b  0xa00cfb18
a00cfee0:  80 a2 e0 e1  cmp  %o3, 0xe1
a00cfee4:  9a 10 20 0d  mov  0xd, %o5
a00cfee8:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00cfeec:  10 bf ff 61  b  0xa00cfc70
a00cfef0:  da 2a 62 ae  stb  %o5, [ %o1 + 0x2ae ]	! 0xa802d2ae
a00cfef4:  c2 0e 20 05  ldub  [ %i0 + 5 ], %g1
a00cfef8:  80 a0 60 01  cmp  %g1, 1
a00cfefc:  02 80 01 9d  be  0xa00d0570
a00cff00:  80 a0 60 00  cmp  %g1, 0
a00cff04:  02 80 01 75  be  0xa00d04d8
a00cff08:  80 a0 60 05  cmp  %g1, 5
a00cff0c:  12 bf ff 59  bne  0xa00cfc70
a00cff10:  01 00 00 00  nop
a00cff14:  40 01 b3 d6  call  0xa013ce6c
a00cff18:  90 10 20 00  clr  %o0	! 0x0
a00cff1c:  80 8a 20 ff  btst  0xff, %o0
a00cff20:  02 bf ff 54  be  0xa00cfc70
a00cff24:  01 00 00 00  nop
a00cff28:  67 fe fe 6c  call  0x4008f8d8
a00cff2c:  01 00 00 00  nop
a00cff30:  30 bf ff 50  b,a   0xa00cfc70
a00cff34:  80 a0 60 01  cmp  %g1, 1
a00cff38:  02 80 01 4f  be  0xa00d0474
a00cff3c:  80 a0 60 00  cmp  %g1, 0
a00cff40:  12 bf ff 4f  bne  0xa00cfc7c
a00cff44:  80 8c a0 ff  btst  0xff, %l2
a00cff48:  c2 0e 20 05  ldub  [ %i0 + 5 ], %g1
a00cff4c:  80 a0 60 0b  cmp  %g1, 0xb
a00cff50:  38 bf ff 4b  bgu,a   0xa00cfc7c
a00cff54:  80 8c a0 ff  btst  0xff, %l2
a00cff58:  17 00 01 bb  sethi  %hi(0x6ec00), %o3
a00cff5c:  95 28 60 02  sll  %g1, 2, %o2
a00cff60:  a0 12 e0 0c  or  %o3, 0xc, %l0
a00cff64:  e6 04 00 0a  ld  [ %l0 + %o2 ], %l3
a00cff68:  81 c4 c0 00  jmp  %l3
a00cff6c:  01 00 00 00  nop
a00cff70:  80 a2 a0 a2  cmp  %o2, 0xa2
a00cff74:  02 80 00 9d  be  0xa00d01e8
a00cff78:  80 a2 e0 e1  cmp  %o3, 0xe1
a00cff7c:  12 bf fe ea  bne  0xa00cfb24
a00cff80:  80 a2 e0 08  cmp  %o3, 8
a00cff84:  da 0e 20 05  ldub  [ %i0 + 5 ], %o5
a00cff88:  80 a3 60 a5  cmp  %o5, 0xa5
a00cff8c:  12 bf fe e6  bne  0xa00cfb24
a00cff90:  80 a2 e0 08  cmp  %o3, 8
a00cff94:  de 0e 20 06  ldub  [ %i0 + 6 ], %o7
a00cff98:  80 a3 e0 00  cmp  %o7, 0
a00cff9c:  22 bf fe fe  be,a   0xa00cfb94
a00cffa0:  a4 10 20 01  mov  1, %l2
a00cffa4:  10 bf fe e0  b  0xa00cfb24
a00cffa8:  80 a2 e0 08  cmp  %o3, 8
a00cffac:  80 a4 20 01  cmp  %l0, 1
a00cffb0:  12 bf fe e0  bne  0xa00cfb30
a00cffb4:  82 0a e0 ff  and  %o3, 0xff, %g1
a00cffb8:  e2 0e 20 06  ldub  [ %i0 + 6 ], %l1
a00cffbc:  80 a4 60 00  cmp  %l1, 0
a00cffc0:  22 bf fe f6  be,a   0xa00cfb98
a00cffc4:  a4 10 20 01  mov  1, %l2
a00cffc8:  10 bf fe db  b  0xa00cfb34
a00cffcc:  80 a0 60 10  cmp  %g1, 0x10
a00cffd0:  e6 0e 20 05  ldub  [ %i0 + 5 ], %l3
a00cffd4:  80 a4 e0 0e  cmp  %l3, 0xe
a00cffd8:  12 bf fe f0  bne  0xa00cfb98
a00cffdc:  82 0a e0 ff  and  %o3, 0xff, %g1
a00cffe0:  10 bf fe ee  b  0xa00cfb98
a00cffe4:  a4 10 20 01  mov  1, %l2
a00cffe8:  02 80 00 86  be  0xa00d0200
a00cffec:  92 10 20 00  clr  %o1
a00cfff0:  80 a0 60 1e  cmp  %g1, 0x1e
a00cfff4:  12 bf ff 22  bne  0xa00cfc7c
a00cfff8:  80 8c a0 ff  btst  0xff, %l2
a00cfffc:  40 01 cb a4  call  0xa0142e8c
a00d0000:  90 10 20 00  clr  %o0
a00d0004:  ac 0a 20 ff  and  %o0, 0xff, %l6
a00d0008:  80 a5 a0 05  cmp  %l6, 5
a00d000c:  02 bf ff 1c  be  0xa00cfc7c
a00d0010:  80 8c a0 ff  btst  0xff, %l2
a00d0014:  40 01 dd c2  call  0xa014771c
a00d0018:  90 10 20 00  clr  %o0
a00d001c:  11 2a 00 b7  sethi  %hi(0xa802dc00), %o0
a00d0020:  da 0a 23 6a  ldub  [ %o0 + 0x36a ], %o5	! 0xa802df6a
a00d0024:  80 a3 60 00  cmp  %o5, 0
a00d0028:  22 bf ff 15  be,a   0xa00cfc7c
a00d002c:  80 8c a0 ff  btst  0xff, %l2
a00d0030:  7f fe e7 c7  call  0xa0089f4c
a00d0034:  01 00 00 00  nop
a00d0038:  10 bf ff 11  b  0xa00cfc7c
a00d003c:  80 8c a0 ff  btst  0xff, %l2
a00d0040:  02 80 00 7e  be  0xa00d0238
a00d0044:  80 a0 60 cc  cmp  %g1, 0xcc
a00d0048:  12 bf ff 0d  bne  0xa00cfc7c
a00d004c:  80 8c a0 ff  btst  0xff, %l2
a00d0050:  c2 0e 20 07  ldub  [ %i0 + 7 ], %g1
a00d0054:  80 a0 60 25  cmp  %g1, 0x25
a00d0058:  18 bf ff 06  bgu  0xa00cfc70
a00d005c:  2d 00 01 ba  sethi  %hi(0x6e800), %l6
a00d0060:  99 28 60 02  sll  %g1, 2, %o4
a00d0064:  a8 15 a3 74  or  %l6, 0x374, %l4
a00d0068:  de 05 00 0c  ld  [ %l4 + %o4 ], %o7
a00d006c:  81 c3 c0 00  jmp  %o7
a00d0070:  01 00 00 00  nop
a00d0074:  02 80 01 8e  be  0xa00d06ac
a00d0078:  90 10 20 00  clr  %o0	! 0x0
a00d007c:  80 a0 60 ef  cmp  %g1, 0xef
a00d0080:  12 bf fe ff  bne  0xa00cfc7c
a00d0084:  80 8c a0 ff  btst  0xff, %l2
a00d0088:  a0 10 20 02  mov  2, %l0
a00d008c:  29 2a 00 ac  sethi  %hi(0xa802b000), %l4
a00d0090:  23 2a 00 ac  sethi  %hi(0xa802b000), %l1
a00d0094:  e0 2c 60 a3  stb  %l0, [ %l1 + 0xa3 ]	! 0xa802b0a3
a00d0098:  e0 2d 20 a4  stb  %l0, [ %l4 + 0xa4 ]
a00d009c:  27 2a 00 b4  sethi  %hi(0xa802d000), %l3
a00d00a0:  c2 0e 20 05  ldub  [ %i0 + 5 ], %g1
a00d00a4:  80 a0 60 13  cmp  %g1, 0x13
a00d00a8:  c2 2c e2 50  stb  %g1, [ %l3 + 0x250 ]
a00d00ac:  02 80 02 7b  be  0xa00d0a98
a00d00b0:  9a 14 e2 50  or  %l3, 0x250, %o5
a00d00b4:  ea 0e 20 07  ldub  [ %i0 + 7 ], %l5
a00d00b8:  a0 0d 60 ff  and  %l5, 0xff, %l0
a00d00bc:  80 a4 20 00  cmp  %l0, 0
a00d00c0:  12 80 00 03  bne  0xa00d00cc
a00d00c4:  ec 0e 20 06  ldub  [ %i0 + 6 ], %l6
a00d00c8:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00d00cc:  94 10 00 0d  mov  %o5, %o2
a00d00d0:  96 10 20 00  clr  %o3
a00d00d4:  82 10 20 00  clr  %g1
a00d00d8:  98 00 40 18  add  %g1, %i0, %o4
a00d00dc:  de 0b 20 08  ldub  [ %o4 + 8 ], %o7
a00d00e0:  d2 0a a0 01  ldub  [ %o2 + 1 ], %o1
a00d00e4:  96 02 e0 01  inc  %o3
a00d00e8:  90 02 40 0f  add  %o1, %o7, %o0
a00d00ec:  82 0a e0 ff  and  %o3, 0xff, %g1
a00d00f0:  80 a0 60 20  cmp  %g1, 0x20
a00d00f4:  0a bf ff f9  bcs  0xa00d00d8
a00d00f8:  d0 2a a0 01  stb  %o0, [ %o2 + 1 ]
a00d00fc:  9a 10 20 6e  mov  0x6e, %o5
a00d0100:  94 10 3f 88  mov  -120, %o2
a00d0104:  96 10 20 20  mov  0x20, %o3
a00d0108:  da 2e 40 00  stb  %o5, [ %i1 ]
a00d010c:  d4 2e 60 01  stb  %o2, [ %i1 + 1 ]
a00d0110:  d6 2e 60 04  stb  %o3, [ %i1 + 4 ]
a00d0114:  ec 2e 60 02  stb  %l6, [ %i1 + 2 ]
a00d0118:  ea 2e 60 03  stb  %l5, [ %i1 + 3 ]
a00d011c:  7f fe e7 91  call  0xa0089f60
a00d0120:  90 10 20 50  mov  0x50, %o0
a00d0124:  80 a4 20 5f  cmp  %l0, 0x5f
a00d0128:  c2 0e 20 26  ldub  [ %i0 + 0x26 ], %g1
a00d012c:  08 80 01 6e  bleu  0xa00d06e4
a00d0130:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00d0134:  80 a4 20 60  cmp  %l0, 0x60
a00d0138:  02 80 02 4e  be  0xa00d0a70
a00d013c:  82 08 60 ff  and  %g1, 0xff, %g1
a00d0140:  c2 0c e2 50  ldub  [ %l3 + 0x250 ], %g1
a00d0144:  80 a0 60 42  cmp  %g1, 0x42
a00d0148:  02 80 01 e9  be  0xa00d08ec
a00d014c:  96 14 e2 50  or  %l3, 0x250, %o3
a00d0150:  d8 0c e2 50  ldub  [ %l3 + 0x250 ], %o4
a00d0154:  80 a3 20 43  cmp  %o4, 0x43
a00d0158:  02 80 01 c5  be  0xa00d086c
a00d015c:  96 14 e2 50  or  %l3, 0x250, %o3
a00d0160:  98 14 e2 50  or  %l3, 0x250, %o4
a00d0164:  a6 04 20 20  add  %l0, 0x20, %l3
a00d0168:  e0 13 20 02  lduh  [ %o4 + 2 ], %l0
a00d016c:  80 a4 c0 10  cmp  %l3, %l0
a00d0170:  06 bf fe c3  bl  0xa00cfc7c
a00d0174:  80 8c a0 ff  btst  0xff, %l2
a00d0178:  d6 0b 20 01  ldub  [ %o4 + 1 ], %o3
a00d017c:  80 a2 e0 00  cmp  %o3, 0
a00d0180:  12 80 02 1d  bne  0xa00d09f4
a00d0184:  d8 0c 60 a3  ldub  [ %l1 + 0xa3 ], %o4
a00d0188:  82 03 3f ff  add  %o4, -1, %g1
a00d018c:  80 88 60 ff  btst  0xff, %g1
a00d0190:  22 80 00 02  be,a   0xa00d0198
a00d0194:  c2 0d 20 a4  ldub  [ %l4 + 0xa4 ], %g1
a00d0198:  10 bf fe b8  b  0xa00cfc78
a00d019c:  c2 2c 60 a3  stb  %g1, [ %l1 + 0xa3 ]
a00d01a0:  02 80 00 fd  be  0xa00d0594
a00d01a4:  80 a0 60 12  cmp  %g1, 0x12
a00d01a8:  12 bf fe b5  bne  0xa00cfc7c
a00d01ac:  80 8c a0 ff  btst  0xff, %l2
a00d01b0:  90 10 20 00  clr  %o0
a00d01b4:  40 01 d7 4d  call  0xa0145ee8
a00d01b8:  92 10 20 00  clr  %o1
a00d01bc:  40 01 d7 7c  call  0xa0145fac
a00d01c0:  90 10 20 01  mov  1, %o0
a00d01c4:  da 0e 20 05  ldub  [ %i0 + 5 ], %o5
a00d01c8:  2d 2a 00 b4  sethi  %hi(0xa802d000), %l6
a00d01cc:  80 a3 60 64  cmp  %o5, 0x64
a00d01d0:  08 80 01 e8  bleu  0xa00d0970
a00d01d4:  98 15 a2 90  or  %l6, 0x290, %o4
a00d01d8:  82 10 20 64  mov  0x64, %g1
a00d01dc:  40 00 1f 01  call  0xa00d7de0
a00d01e0:  c2 2b 20 0a  stb  %g1, [ %o4 + 0xa ]
a00d01e4:  30 bf fe a3  b,a   0xa00cfc70
a00d01e8:  d8 0e 20 06  ldub  [ %i0 + 6 ], %o4
a00d01ec:  80 a3 20 00  cmp  %o4, 0
a00d01f0:  22 bf fe 69  be,a   0xa00cfb94
a00d01f4:  a4 10 20 01  mov  1, %l2
a00d01f8:  10 bf ff 61  b  0xa00cff7c
a00d01fc:  80 a2 e0 e1  cmp  %o3, 0xe1
a00d0200:  40 01 d7 3a  call  0xa0145ee8
a00d0204:  90 10 20 00  clr  %o0
a00d0208:  40 01 d7 69  call  0xa0145fac
a00d020c:  90 10 20 01  mov  1, %o0
a00d0210:  de 0e 20 07  ldub  [ %i0 + 7 ], %o7
a00d0214:  a8 10 00 0f  mov  %o7, %l4
a00d0218:  98 05 20 01  add  %l4, 1, %o4
a00d021c:  95 2b 20 10  sll  %o4, 0x10, %o2
a00d0220:  2b 2a 00 ac  sethi  %hi(0xa802b000), %l5
a00d0224:  de 2d 60 a0  stb  %o7, [ %l5 + 0xa0 ]	! 0xa802b0a0
a00d0228:  40 01 ac 91  call  0xa013b46c
a00d022c:  91 32 a0 10  srl  %o2, 0x10, %o0
a00d0230:  10 bf fe 93  b  0xa00cfc7c
a00d0234:  80 8c a0 ff  btst  0xff, %l2
a00d0238:  92 10 20 00  clr  %o1
a00d023c:  40 01 d7 2b  call  0xa0145ee8
a00d0240:  90 10 20 00  clr  %o0
a00d0244:  40 01 d7 5a  call  0xa0145fac
a00d0248:  90 10 20 01  mov  1, %o0
a00d024c:  ea 0e 20 07  ldub  [ %i0 + 7 ], %l5
a00d0250:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00d0254:  40 00 11 29  call  0xa00d46f8
a00d0258:  ea 2a a2 a7  stb  %l5, [ %o2 + 0x2a7 ]	! 0xa802d2a7
a00d025c:  30 bf fe 85  b,a   0xa00cfc70
a00d0260:  19 2a 00 ac  sethi  %hi(0xa802b000), %o4
a00d0264:  1f 2a 00 ac  sethi  %hi(0xa802b000), %o7
a00d0268:  2b 2a 00 ac  sethi  %hi(0xa802b000), %l5
a00d026c:  d4 0b 20 a2  ldub  [ %o4 + 0xa2 ], %o2
a00d0270:  d6 0b e0 a1  ldub  [ %o7 + 0xa1 ], %o3
a00d0274:  e2 0d 60 a0  ldub  [ %l5 + 0xa0 ], %l1
a00d0278:  a0 5a a0 64  smul  %o2, 0x64, %l0
a00d027c:  a6 5a e0 64  smul  %o3, 0x64, %l3
a00d0280:  92 5c 60 64  smul  %l1, 0x64, %o1
a00d0284:  03 20 20 20  sethi  %hi(0x80808000), %g1
a00d0288:  ac 10 60 81  or  %g1, 0x81, %l6	! 0x80808081
a00d028c:  9a 02 60 7f  add  %o1, 0x7f, %o5
a00d0290:  90 04 20 7f  add  %l0, 0x7f, %o0
a00d0294:  a8 04 e0 7f  add  %l3, 0x7f, %l4
a00d0298:  80 53 40 16  umul  %o5, %l6, %g0
a00d029c:  a3 40 00 00  rd  %y, %l1
a00d02a0:  80 52 00 16  umul  %o0, %l6, %g0
a00d02a4:  9f 40 00 00  rd  %y, %o7
a00d02a8:  80 55 00 16  umul  %l4, %l6, %g0
a00d02ac:  ab 40 00 00  rd  %y, %l5
a00d02b0:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00d02b4:  98 13 22 90  or  %o4, 0x290, %o4	! 0xa802d290
a00d02b8:  95 33 e0 07  srl  %o7, 7, %o2
a00d02bc:  97 35 60 07  srl  %l5, 7, %o3
a00d02c0:  9b 34 60 07  srl  %l1, 7, %o5
a00d02c4:  da 2b 20 14  stb  %o5, [ %o4 + 0x14 ]
a00d02c8:  d4 2b 20 12  stb  %o2, [ %o4 + 0x12 ]
a00d02cc:  d6 2b 20 13  stb  %o3, [ %o4 + 0x13 ]
a00d02d0:  40 01 d4 24  call  0xa0145360
a00d02d4:  90 10 20 00  clr  %o0
a00d02d8:  10 bf fe 69  b  0xa00cfc7c
a00d02dc:  80 8c a0 ff  btst  0xff, %l2
a00d02e0:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a00d02e4:  17 2a 00 ac  sethi  %hi(0xa802b000), %o3
a00d02e8:  98 12 a1 f0  or  %o2, 0x1f0, %o4
a00d02ec:  d4 0a e0 a2  ldub  [ %o3 + 0xa2 ], %o2
a00d02f0:  21 2a 00 ac  sethi  %hi(0xa802b000), %l0
a00d02f4:  27 2a 00 ac  sethi  %hi(0xa802b000), %l3
a00d02f8:  d6 0c 20 a1  ldub  [ %l0 + 0xa1 ], %o3
a00d02fc:  10 bf ff f2  b  0xa00d02c4
a00d0300:  da 0c e0 a0  ldub  [ %l3 + 0xa0 ], %o5
a00d0304:  13 2a 00 b8  sethi  %hi(0xa802e000), %o1
a00d0308:  11 2a 00 ac  sethi  %hi(0xa802b000), %o0
a00d030c:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00d0310:  2d 2a 00 ac  sethi  %hi(0xa802b000), %l6
a00d0314:  aa 12 61 f0  or  %o1, 0x1f0, %l5
a00d0318:  e8 0a 20 a2  ldub  [ %o0 + 0xa2 ], %l4
a00d031c:  de 08 60 a1  ldub  [ %g1 + 0xa1 ], %o7
a00d0320:  da 0d a0 a0  ldub  [ %l6 + 0xa0 ], %o5
a00d0324:  da 2d 60 0b  stb  %o5, [ %l5 + 0xb ]
a00d0328:  e8 2d 60 09  stb  %l4, [ %l5 + 9 ]
a00d032c:  10 bf ff e9  b  0xa00d02d0
a00d0330:  de 2d 60 0a  stb  %o7, [ %l5 + 0xa ]
a00d0334:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a00d0338:  23 2a 00 ac  sethi  %hi(0xa802b000), %l1
a00d033c:  17 2a 00 ac  sethi  %hi(0xa802b000), %o3
a00d0340:  21 2a 00 ac  sethi  %hi(0xa802b000), %l0
a00d0344:  90 13 21 f0  or  %o4, 0x1f0, %o0
a00d0348:  e6 0c 60 a2  ldub  [ %l1 + 0xa2 ], %l3
a00d034c:  d2 0a e0 a1  ldub  [ %o3 + 0xa1 ], %o1
a00d0350:  d4 0c 20 a0  ldub  [ %l0 + 0xa0 ], %o2
a00d0354:  d4 2a 20 08  stb  %o2, [ %o0 + 8 ]
a00d0358:  e6 2a 20 06  stb  %l3, [ %o0 + 6 ]
a00d035c:  10 bf ff dd  b  0xa00d02d0
a00d0360:  d2 2a 20 07  stb  %o1, [ %o0 + 7 ]
a00d0364:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a00d0368:  2d 2a 00 ac  sethi  %hi(0xa802b000), %l6
a00d036c:  29 2a 00 ac  sethi  %hi(0xa802b000), %l4
a00d0370:  1f 2a 00 ac  sethi  %hi(0xa802b000), %o7
a00d0374:  98 10 61 f0  or  %g1, 0x1f0, %o4
a00d0378:  ea 0d a0 a2  ldub  [ %l6 + 0xa2 ], %l5
a00d037c:  e2 0d 20 a1  ldub  [ %l4 + 0xa1 ], %l1
a00d0380:  da 0b e0 a0  ldub  [ %o7 + 0xa0 ], %o5
a00d0384:  da 2b 20 23  stb  %o5, [ %o4 + 0x23 ]
a00d0388:  ea 2b 20 21  stb  %l5, [ %o4 + 0x21 ]
a00d038c:  10 bf ff d1  b  0xa00d02d0
a00d0390:  e2 2b 20 22  stb  %l1, [ %o4 + 0x22 ]
a00d0394:  e2 0e 20 05  ldub  [ %i0 + 5 ], %l1
a00d0398:  80 a4 60 01  cmp  %l1, 1
a00d039c:  02 80 00 04  be  0xa00d03ac
a00d03a0:  2b 2a 00 b4  sethi  %hi(0xa802d000), %l5
a00d03a4:  10 bf fe a2  b  0xa00cfe2c
a00d03a8:  92 15 62 90  or  %l5, 0x290, %o1	! 0xa802d290
a00d03ac:  e6 0e 20 06  ldub  [ %i0 + 6 ], %l3
a00d03b0:  80 a4 e0 00  cmp  %l3, 0
a00d03b4:  12 bf fe 9e  bne  0xa00cfe2c
a00d03b8:  92 15 62 90  or  %l5, 0x290, %o1
a00d03bc:  ec 0e 20 07  ldub  [ %i0 + 7 ], %l6
a00d03c0:  80 a5 a0 00  cmp  %l6, 0
a00d03c4:  12 bf fe 9a  bne  0xa00cfe2c
a00d03c8:  a2 15 62 90  or  %l5, 0x290, %l1
a00d03cc:  13 00 00 15  sethi  %hi(0x5400), %o1
a00d03d0:  a6 12 61 aa  or  %o1, 0x1aa, %l3	! 0x55aa
a00d03d4:  c2 14 61 f6  lduh  [ %l1 + 0x1f6 ], %g1
a00d03d8:  90 18 40 13  xor  %g1, %l3, %o0
a00d03dc:  80 a0 00 08  cmp  %g0, %o0
a00d03e0:  a0 60 3f ff  subx  %g0, -1, %l0
a00d03e4:  40 00 2f fe  call  0xa00dc3dc
a00d03e8:  e8 0c 61 d5  ldub  [ %l1 + 0x1d5 ], %l4
a00d03ec:  80 a4 20 00  cmp  %l0, 0
a00d03f0:  12 80 02 1d  bne  0xa00d0c64
a00d03f4:  17 3f ff ee  sethi  %hi(0xffffb800), %o3
a00d03f8:  94 12 e3 99  or  %o3, 0x399, %o2	! 0xffffbb99
a00d03fc:  98 15 62 90  or  %l5, 0x290, %o4
a00d0400:  d4 34 61 f6  sth  %o2, [ %l1 + 0x1f6 ]
a00d0404:  e8 2b 21 d5  stb  %l4, [ %o4 + 0x1d5 ]
a00d0408:  10 bf fe 89  b  0xa00cfe2c
a00d040c:  92 15 62 90  or  %l5, 0x290, %o1
a00d0410:  c2 0e 20 05  ldub  [ %i0 + 5 ], %g1
a00d0414:  80 a0 60 01  cmp  %g1, 1
a00d0418:  22 80 00 ae  be,a   0xa00d06d0
a00d041c:  d6 0e 60 07  ldub  [ %i1 + 7 ], %o3
a00d0420:  80 a0 60 02  cmp  %g1, 2
a00d0424:  22 80 00 b3  be,a   0xa00d06f0
a00d0428:  ea 0e 60 07  ldub  [ %i1 + 7 ], %l5
a00d042c:  80 a0 60 03  cmp  %g1, 3
a00d0430:  22 80 00 b5  be,a   0xa00d0704
a00d0434:  d8 0e 60 07  ldub  [ %i1 + 7 ], %o4
a00d0438:  80 a0 60 04  cmp  %g1, 4
a00d043c:  22 80 00 cb  be,a   0xa00d0768
a00d0440:  ec 0e 60 07  ldub  [ %i1 + 7 ], %l6
a00d0444:  80 a0 60 05  cmp  %g1, 5
a00d0448:  22 80 00 c3  be,a   0xa00d0754
a00d044c:  da 0e 60 07  ldub  [ %i1 + 7 ], %o5
a00d0450:  80 a0 60 06  cmp  %g1, 6
a00d0454:  32 bf fe 0a  bne,a   0xa00cfc7c
a00d0458:  80 8c a0 ff  btst  0xff, %l2
a00d045c:  d2 0e 60 07  ldub  [ %i1 + 7 ], %o1
a00d0460:  11 2a 00 b8  sethi  %hi(0xa802e000), %o0
a00d0464:  7f fe e6 b5  call  0xa0089f38
a00d0468:  d2 2a 21 f5  stb  %o1, [ %o0 + 0x1f5 ]	! 0xa802e1f5
a00d046c:  10 bf fe 04  b  0xa00cfc7c
a00d0470:  80 8c a0 ff  btst  0xff, %l2
a00d0474:  c2 0e 20 05  ldub  [ %i0 + 5 ], %g1
a00d0478:  80 a0 60 06  cmp  %g1, 6
a00d047c:  02 80 00 8a  be  0xa00d06a4
a00d0480:  9a 10 20 00  clr  %o5
a00d0484:  80 a0 60 06  cmp  %g1, 6
a00d0488:  14 80 00 81  bg  0xa00d068c
a00d048c:  80 a0 60 08  cmp  %g1, 8
a00d0490:  80 a0 60 05  cmp  %g1, 5
a00d0494:  22 80 00 02  be,a   0xa00d049c
a00d0498:  9a 10 20 01  mov  1, %o5
a00d049c:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00d04a0:  a2 12 62 90  or  %o1, 0x290, %l1	! 0xa802d290
a00d04a4:  a0 0b 60 ff  and  %o5, 0xff, %l0
a00d04a8:  d0 0c 60 11  ldub  [ %l1 + 0x11 ], %o0
a00d04ac:  80 a2 00 10  cmp  %o0, %l0
a00d04b0:  02 bf fd f2  be  0xa00cfc78
a00d04b4:  92 10 20 00  clr  %o1
a00d04b8:  40 01 d6 8c  call  0xa0145ee8
a00d04bc:  90 10 20 00  clr  %o0
a00d04c0:  40 01 d6 bb  call  0xa0145fac
a00d04c4:  90 10 20 01  mov  1, %o0
a00d04c8:  40 00 24 a7  call  0xa00d9764
a00d04cc:  e0 2c 60 11  stb  %l0, [ %l1 + 0x11 ]
a00d04d0:  10 bf fd eb  b  0xa00cfc7c
a00d04d4:  80 8c a0 ff  btst  0xff, %l2
a00d04d8:  40 01 b2 65  call  0xa013ce6c
a00d04dc:  90 10 20 00  clr  %o0
a00d04e0:  a6 0a 20 ff  and  %o0, 0xff, %l3
a00d04e4:  80 a4 e0 01  cmp  %l3, 1
a00d04e8:  02 bf fd e2  be  0xa00cfc70
a00d04ec:  01 00 00 00  nop
a00d04f0:  40 01 b2 5f  call  0xa013ce6c
a00d04f4:  90 10 20 01  mov  1, %o0	! 0x1
a00d04f8:  a0 0a 20 ff  and  %o0, 0xff, %l0
a00d04fc:  80 a4 20 01  cmp  %l0, 1
a00d0500:  02 bf fd dc  be  0xa00cfc70
a00d0504:  01 00 00 00  nop
a00d0508:  40 01 cc bd  call  0xa01437fc
a00d050c:  01 00 00 00  nop
a00d0510:  30 bf fd d8  b,a   0xa00cfc70
a00d0514:  40 01 d6 75  call  0xa0145ee8
a00d0518:  90 10 20 00  clr  %o0
a00d051c:  40 01 d6 a4  call  0xa0145fac
a00d0520:  90 10 20 01  mov  1, %o0
a00d0524:  d6 0e 20 07  ldub  [ %i0 + 7 ], %o3
a00d0528:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00d052c:  40 00 10 66  call  0xa00d46c4
a00d0530:  d6 2c 62 a6  stb  %o3, [ %l1 + 0x2a6 ]	! 0xa802d2a6
a00d0534:  30 bf fd cf  b,a   0xa00cfc70
a00d0538:  40 01 d6 6c  call  0xa0145ee8
a00d053c:  90 10 20 00  clr  %o0
a00d0540:  40 01 d6 9b  call  0xa0145fac
a00d0544:  90 10 20 01  mov  1, %o0
a00d0548:  c2 0e 20 07  ldub  [ %i0 + 7 ], %g1
a00d054c:  96 10 00 01  mov  %g1, %o3
a00d0550:  a2 02 e0 01  add  %o3, 1, %l1
a00d0554:  a7 2c 60 10  sll  %l1, 0x10, %l3
a00d0558:  21 2a 00 ac  sethi  %hi(0xa802b000), %l0
a00d055c:  c2 2c 20 a1  stb  %g1, [ %l0 + 0xa1 ]	! 0xa802b0a1
a00d0560:  40 01 ab bb  call  0xa013b44c
a00d0564:  91 34 e0 10  srl  %l3, 0x10, %o0
a00d0568:  10 bf fd c5  b  0xa00cfc7c
a00d056c:  80 8c a0 ff  btst  0xff, %l2
a00d0570:  40 01 b2 3f  call  0xa013ce6c
a00d0574:  90 10 20 00  clr  %o0
a00d0578:  92 0a 20 ff  and  %o0, 0xff, %o1
a00d057c:  80 a2 60 04  cmp  %o1, 4
a00d0580:  02 bf fd bc  be  0xa00cfc70
a00d0584:  01 00 00 00  nop
a00d0588:  40 01 cc 9b  call  0xa01437f4
a00d058c:  01 00 00 00  nop
a00d0590:  30 bf fd b8  b,a   0xa00cfc70
a00d0594:  ea 0e 20 05  ldub  [ %i0 + 5 ], %l5
a00d0598:  80 a5 60 0e  cmp  %l5, 0xe
a00d059c:  12 bf fd b8  bne  0xa00cfc7c
a00d05a0:  80 8c a0 ff  btst  0xff, %l2
a00d05a4:  e0 0e 20 07  ldub  [ %i0 + 7 ], %l0
a00d05a8:  d4 0e 20 08  ldub  [ %i0 + 8 ], %o2
a00d05ac:  a7 2c 20 08  sll  %l0, 8, %l3
a00d05b0:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00d05b4:  92 14 c0 0a  or  %l3, %o2, %o1
a00d05b8:  a0 14 62 90  or  %l1, 0x290, %l0
a00d05bc:  e6 14 21 da  lduh  [ %l0 + 0x1da ], %l3
a00d05c0:  d2 34 21 da  sth  %o1, [ %l0 + 0x1da ]
a00d05c4:  92 10 20 01  mov  1, %o1
a00d05c8:  40 01 d4 26  call  0xa0145660
a00d05cc:  90 10 20 00  clr  %o0
a00d05d0:  03 33 33 33  sethi  %hi(0xcccccc00), %g1
a00d05d4:  91 2a 20 10  sll  %o0, 0x10, %o0
a00d05d8:  ac 10 60 cd  or  %g1, 0xcd, %l6
a00d05dc:  a9 32 20 10  srl  %o0, 0x10, %l4
a00d05e0:  80 55 00 16  umul  %l4, %l6, %g0
a00d05e4:  9f 40 00 00  rd  %y, %o7
a00d05e8:  9b 2b e0 0d  sll  %o7, 0xd, %o5
a00d05ec:  7f fe db 9b  call  0xa0087458
a00d05f0:  91 33 60 10  srl  %o5, 0x10, %o0
a00d05f4:  c2 14 21 da  lduh  [ %l0 + 0x1da ], %g1
a00d05f8:  80 a0 63 ff  cmp  %g1, 0x3ff
a00d05fc:  08 80 01 96  bleu  0xa00d0c54
a00d0600:  80 a0 60 7d  cmp  %g1, 0x7d
a00d0604:  82 10 23 ff  mov  0x3ff, %g1
a00d0608:  c2 34 21 da  sth  %g1, [ %l0 + 0x1da ]
a00d060c:  40 00 21 b2  call  0xa00d8cd4
a00d0610:  01 00 00 00  nop
a00d0614:  d6 0e 20 06  ldub  [ %i0 + 6 ], %o3
a00d0618:  80 a2 e0 01  cmp  %o3, 1
a00d061c:  02 80 01 de  be  0xa00d0d94
a00d0620:  98 14 62 90  or  %l1, 0x290, %o4
a00d0624:  e6 33 21 da  sth  %l3, [ %o4 + 0x1da ]
a00d0628:  90 10 20 00  clr  %o0
a00d062c:  a0 10 20 04  mov  4, %l0
a00d0630:  82 10 20 04  mov  4, %g1
a00d0634:  a3 2a 20 10  sll  %o0, 0x10, %l1
a00d0638:  d0 08 40 18  ldub  [ %g1 + %i0 ], %o0
a00d063c:  7f ff f9 0d  call  0xa00cea70
a00d0640:  93 34 60 10  srl  %l1, 0x10, %o1
a00d0644:  a0 04 20 01  inc  %l0
a00d0648:  82 0c 20 ff  and  %l0, 0xff, %g1
a00d064c:  80 a0 60 07  cmp  %g1, 7
a00d0650:  28 bf ff fa  bleu,a   0xa00d0638
a00d0654:  a3 2a 20 10  sll  %o0, 0x10, %l1
a00d0658:  ab 32 20 08  srl  %o0, 8, %l5
a00d065c:  a8 10 20 6e  mov  0x6e, %l4
a00d0660:  9e 10 3f 83  mov  -125, %o7
a00d0664:  9a 10 20 02  mov  2, %o5
a00d0668:  e8 2e 40 00  stb  %l4, [ %i1 ]
a00d066c:  de 2e 60 01  stb  %o7, [ %i1 + 1 ]
a00d0670:  da 2e 60 02  stb  %o5, [ %i1 + 2 ]
a00d0674:  ea 2e 60 03  stb  %l5, [ %i1 + 3 ]
a00d0678:  d0 2e 60 04  stb  %o0, [ %i1 + 4 ]
a00d067c:  7f fe e6 39  call  0xa0089f60
a00d0680:  90 10 20 50  mov  0x50, %o0
a00d0684:  10 bf fd 7e  b  0xa00cfc7c
a00d0688:  80 8c a0 ff  btst  0xff, %l2
a00d068c:  02 80 00 47  be  0xa00d07a8
a00d0690:  80 a0 60 0b  cmp  %g1, 0xb
a00d0694:  22 bf ff 82  be,a   0xa00d049c
a00d0698:  9a 10 20 17  mov  0x17, %o5
a00d069c:  10 bf ff 81  b  0xa00d04a0
a00d06a0:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00d06a4:  10 bf ff 7e  b  0xa00d049c
a00d06a8:  9a 10 20 04  mov  4, %o5
a00d06ac:  d2 0e 20 05  ldub  [ %i0 + 5 ], %o1
a00d06b0:  d4 0e 20 06  ldub  [ %i0 + 6 ], %o2
a00d06b4:  d6 0e 20 07  ldub  [ %i0 + 7 ], %o3
a00d06b8:  40 01 d6 4c  call  0xa0145fe8
a00d06bc:  98 10 20 00  clr  %o4
a00d06c0:  40 00 d9 3a  call  0xa0106ba8
a00d06c4:  90 10 20 00  clr  %o0
a00d06c8:  10 bf fd 6d  b  0xa00cfc7c
a00d06cc:  80 8c a0 ff  btst  0xff, %l2
a00d06d0:  23 2a 00 b8  sethi  %hi(0xa802e000), %l1
a00d06d4:  7f fe e6 19  call  0xa0089f38
a00d06d8:  d6 2c 61 f0  stb  %o3, [ %l1 + 0x1f0 ]	! 0xa802e1f0
a00d06dc:  10 bf fd 68  b  0xa00cfc7c
a00d06e0:  80 8c a0 ff  btst  0xff, %l2
a00d06e4:  82 10 20 80  mov  0x80, %g1
a00d06e8:  10 bf fe 96  b  0xa00d0140
a00d06ec:  c2 33 62 52  sth  %g1, [ %o5 + 0x252 ]
a00d06f0:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a00d06f4:  7f fe e6 11  call  0xa0089f38
a00d06f8:  ea 2a a1 f1  stb  %l5, [ %o2 + 0x1f1 ]	! 0xa802e1f1
a00d06fc:  10 bf fd 60  b  0xa00cfc7c
a00d0700:  80 8c a0 ff  btst  0xff, %l2
a00d0704:  1f 2a 00 b8  sethi  %hi(0xa802e000), %o7
a00d0708:  d8 2b e1 f2  stb  %o4, [ %o7 + 0x1f2 ]	! 0xa802e1f2
a00d070c:  7f fe e6 0b  call  0xa0089f38
a00d0710:  01 00 00 00  nop
a00d0714:  10 bf fd 5a  b  0xa00cfc7c
a00d0718:  80 8c a0 ff  btst  0xff, %l2
a00d071c:  80 a0 60 00  cmp  %g1, 0
a00d0720:  12 bf fd 95  bne  0xa00cfd74
a00d0724:  80 a3 60 a1  cmp  %o5, 0xa1
a00d0728:  c2 0e 20 07  ldub  [ %i0 + 7 ], %g1
a00d072c:  80 a0 60 01  cmp  %g1, 1
a00d0730:  02 80 01 6e  be  0xa00d0ce8
a00d0734:  01 00 00 00  nop
a00d0738:  80 a0 60 00  cmp  %g1, 0
a00d073c:  32 bf fd 50  bne,a   0xa00cfc7c
a00d0740:  80 8c a0 ff  btst  0xff, %l2
a00d0744:  7f ff f8 c0  call  0xa00cea44
a00d0748:  01 00 00 00  nop
a00d074c:  10 bf fd 4c  b  0xa00cfc7c
a00d0750:  80 8c a0 ff  btst  0xff, %l2
a00d0754:  27 2a 00 b8  sethi  %hi(0xa802e000), %l3
a00d0758:  7f fe e5 f8  call  0xa0089f38
a00d075c:  da 2c e1 f4  stb  %o5, [ %l3 + 0x1f4 ]	! 0xa802e1f4
a00d0760:  10 bf fd 47  b  0xa00cfc7c
a00d0764:  80 8c a0 ff  btst  0xff, %l2
a00d0768:  29 2a 00 b8  sethi  %hi(0xa802e000), %l4
a00d076c:  7f fe e5 f3  call  0xa0089f38
a00d0770:  ec 2d 21 f3  stb  %l6, [ %l4 + 0x1f3 ]	! 0xa802e1f3
a00d0774:  10 bf fd 42  b  0xa00cfc7c
a00d0778:  80 8c a0 ff  btst  0xff, %l2
a00d077c:  80 a4 60 00  cmp  %l1, 0
a00d0780:  12 bf fd 80  bne  0xa00cfd80
a00d0784:  80 a3 60 a2  cmp  %o5, 0xa2
a00d0788:  2b 2a 00 b4  sethi  %hi(0xa802d000), %l5
a00d078c:  d4 05 62 90  ld  [ %l5 + 0x290 ], %o2	! 0xa802d290
a00d0790:  17 00 00 10  sethi  %hi(0x4000), %o3
a00d0794:  80 8a 80 0b  btst  %o2, %o3
a00d0798:  02 bf fd 39  be  0xa00cfc7c
a00d079c:  80 8c a0 ff  btst  0xff, %l2
a00d07a0:  10 80 00 00  b  0xa00d07a0
a00d07a4:  01 00 00 00  nop
a00d07a8:  10 bf ff 3d  b  0xa00d049c
a00d07ac:  9a 10 20 07  mov  7, %o5	! 0x7
a00d07b0:  80 a5 a0 00  cmp  %l6, 0
a00d07b4:  12 bf fd 7c  bne  0xa00cfda4
a00d07b8:  82 0b 60 ff  and  %o5, 0xff, %g1
a00d07bc:  da 0e 20 07  ldub  [ %i0 + 7 ], %o5
a00d07c0:  80 a3 60 01  cmp  %o5, 1
a00d07c4:  02 80 01 33  be  0xa00d0c90
a00d07c8:  15 3f ff ee  sethi  %hi(0xffffb800), %o2
a00d07cc:  96 12 a3 99  or  %o2, 0x399, %o3	! 0xffffbb99
a00d07d0:  23 2a 00 b5  sethi  %hi(0xa802d400), %l1
a00d07d4:  d6 34 60 86  sth  %o3, [ %l1 + 0x86 ]	! 0xa802d486
a00d07d8:  7f fe e5 d3  call  0xa0089f24
a00d07dc:  01 00 00 00  nop
a00d07e0:  30 bf fd 24  b,a   0xa00cfc70
a00d07e4:  80 a3 20 00  cmp  %o4, 0
a00d07e8:  12 bf fd 6c  bne  0xa00cfd98
a00d07ec:  80 a3 60 a5  cmp  %o5, 0xa5
a00d07f0:  e8 0e 20 07  ldub  [ %i0 + 7 ], %l4
a00d07f4:  80 a5 20 00  cmp  %l4, 0
a00d07f8:  32 bf fd 68  bne,a   0xa00cfd98
a00d07fc:  80 a3 60 a5  cmp  %o5, 0xa5
a00d0800:  90 10 20 08  mov  8, %o0
a00d0804:  40 01 d5 16  call  0xa0145c5c
a00d0808:  92 10 20 00  clr  %o1
a00d080c:  90 10 20 09  mov  9, %o0
a00d0810:  40 01 d5 13  call  0xa0145c5c
a00d0814:  92 10 20 00  clr  %o1
a00d0818:  90 10 20 06  mov  6, %o0
a00d081c:  40 01 d5 10  call  0xa0145c5c
a00d0820:  92 10 20 00  clr  %o1
a00d0824:  90 10 20 07  mov  7, %o0
a00d0828:  40 01 d5 0d  call  0xa0145c5c
a00d082c:  92 10 20 00  clr  %o1
a00d0830:  7f fe e5 bd  call  0xa0089f24
a00d0834:  01 00 00 00  nop
a00d0838:  10 bf fd 11  b  0xa00cfc7c
a00d083c:  80 8c a0 ff  btst  0xff, %l2
a00d0840:  80 a3 e0 00  cmp  %o7, 0
a00d0844:  12 80 00 d2  bne  0xa00d0b8c
a00d0848:  80 a3 60 a2  cmp  %o5, 0xa2
a00d084c:  da 0e 20 07  ldub  [ %i0 + 7 ], %o5
a00d0850:  80 a3 60 00  cmp  %o5, 0
a00d0854:  02 80 00 cb  be  0xa00d0b80
a00d0858:  29 2a 00 b5  sethi  %hi(0xa802d400), %l4
a00d085c:  19 2a 00 b5  sethi  %hi(0xa802d400), %o4
a00d0860:  7f fe e5 b1  call  0xa0089f24
a00d0864:  da 2b 20 65  stb  %o5, [ %o4 + 0x65 ]	! 0xa802d465
a00d0868:  30 bf fd 02  b,a   0xa00cfc70
a00d086c:  92 0d a0 ff  and  %l6, 0xff, %o1
a00d0870:  90 0d 60 ff  and  %l5, 0xff, %o0
a00d0874:  99 2a 60 08  sll  %o1, 8, %o4
a00d0878:  94 03 00 08  add  %o4, %o0, %o2
a00d087c:  82 02 a0 20  add  %o2, 0x20, %g1
a00d0880:  9b 28 60 10  sll  %g1, 0x10, %o5
a00d0884:  ec 12 e0 02  lduh  [ %o3 + 2 ], %l6
a00d0888:  ab 33 60 10  srl  %o5, 0x10, %l5
a00d088c:  80 a5 80 15  cmp  %l6, %l5
a00d0890:  18 80 00 4a  bgu  0xa00d09b8
a00d0894:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00d0898:  9e 12 a1 48  or  %o2, 0x148, %o7	! 0xa802d148
a00d089c:  96 03 00 0f  add  %o4, %o7, %o3
a00d08a0:  92 02 c0 10  add  %o3, %l0, %o1
a00d08a4:  96 10 20 00  clr  %o3
a00d08a8:  98 10 20 00  clr  %o4
a00d08ac:  ac 03 00 18  add  %o4, %i0, %l6
a00d08b0:  ea 0d a0 08  ldub  [ %l6 + 8 ], %l5
a00d08b4:  ea 2a 40 0c  stb  %l5, [ %o1 + %o4 ]
a00d08b8:  96 02 e0 01  inc  %o3
a00d08bc:  98 0a e0 ff  and  %o3, 0xff, %o4
a00d08c0:  80 a3 20 1f  cmp  %o4, 0x1f
a00d08c4:  28 bf ff fb  bleu,a   0xa00d08b0
a00d08c8:  ac 03 00 18  add  %o4, %i0, %l6
a00d08cc:  94 12 a1 48  or  %o2, 0x148, %o2
a00d08d0:  90 10 20 ff  mov  0xff, %o0
a00d08d4:  92 10 20 01  mov  1, %o1
a00d08d8:  96 10 21 00  mov  0x100, %o3
a00d08dc:  40 01 ea 69  call  0xa014b280
a00d08e0:  98 10 20 01  mov  1, %o4
a00d08e4:  10 bf fe 20  b  0xa00d0164
a00d08e8:  98 14 e2 50  or  %l3, 0x250, %o4
a00d08ec:  90 0d a0 ff  and  %l6, 0xff, %o0
a00d08f0:  99 2a 20 08  sll  %o0, 8, %o4
a00d08f4:  82 0d 60 ff  and  %l5, 0xff, %g1
a00d08f8:  9a 03 00 01  add  %o4, %g1, %o5
a00d08fc:  94 03 60 20  add  %o5, 0x20, %o2
a00d0900:  9f 2a a0 10  sll  %o2, 0x10, %o7
a00d0904:  d2 12 e0 02  lduh  [ %o3 + 2 ], %o1
a00d0908:  91 33 e0 10  srl  %o7, 0x10, %o0
a00d090c:  80 a2 40 08  cmp  %o1, %o0
a00d0910:  18 80 00 1b  bgu  0xa00d097c
a00d0914:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00d0918:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00d091c:  92 12 a1 48  or  %o2, 0x148, %o1	! 0xa802d148
a00d0920:  96 03 00 09  add  %o4, %o1, %o3
a00d0924:  92 02 c0 10  add  %o3, %l0, %o1
a00d0928:  96 10 20 00  clr  %o3
a00d092c:  98 10 20 00  clr  %o4
a00d0930:  9a 03 00 18  add  %o4, %i0, %o5
a00d0934:  de 0b 60 08  ldub  [ %o5 + 8 ], %o7
a00d0938:  de 2a 40 0c  stb  %o7, [ %o1 + %o4 ]
a00d093c:  96 02 e0 01  inc  %o3
a00d0940:  98 0a e0 ff  and  %o3, 0xff, %o4
a00d0944:  80 a3 20 1f  cmp  %o4, 0x1f
a00d0948:  28 bf ff fb  bleu,a   0xa00d0934
a00d094c:  9a 03 00 18  add  %o4, %i0, %o5
a00d0950:  94 12 a1 48  or  %o2, 0x148, %o2
a00d0954:  90 10 20 ff  mov  0xff, %o0
a00d0958:  92 10 20 01  mov  1, %o1
a00d095c:  96 10 21 00  mov  0x100, %o3
a00d0960:  40 01 ea 48  call  0xa014b280
a00d0964:  98 10 20 01  mov  1, %o4
a00d0968:  10 bf fd fb  b  0xa00d0154
a00d096c:  d8 0c e2 50  ldub  [ %l3 + 0x250 ], %o4
a00d0970:  40 00 1d 1c  call  0xa00d7de0
a00d0974:  da 2b 20 0a  stb  %o5, [ %o4 + 0xa ]
a00d0978:  30 bf fc be  b,a   0xa00cfc70
a00d097c:  94 12 21 48  or  %o0, 0x148, %o2
a00d0980:  82 03 00 0a  add  %o4, %o2, %g1
a00d0984:  94 00 40 10  add  %g1, %l0, %o2
a00d0988:  96 10 20 00  clr  %o3
a00d098c:  98 10 20 00  clr  %o4
a00d0990:  9e 03 00 18  add  %o4, %i0, %o7
a00d0994:  d2 0b e0 08  ldub  [ %o7 + 8 ], %o1
a00d0998:  d2 2a 80 0c  stb  %o1, [ %o2 + %o4 ]
a00d099c:  96 02 e0 01  inc  %o3
a00d09a0:  98 0a e0 ff  and  %o3, 0xff, %o4
a00d09a4:  80 a3 20 1f  cmp  %o4, 0x1f
a00d09a8:  08 bf ff fb  bleu  0xa00d0994
a00d09ac:  9e 03 00 18  add  %o4, %i0, %o7
a00d09b0:  10 bf fd e9  b  0xa00d0154
a00d09b4:  d8 0c e2 50  ldub  [ %l3 + 0x250 ], %o4
a00d09b8:  82 12 a1 48  or  %o2, 0x148, %g1
a00d09bc:  9a 03 00 01  add  %o4, %g1, %o5
a00d09c0:  94 03 40 10  add  %o5, %l0, %o2
a00d09c4:  96 10 20 00  clr  %o3
a00d09c8:  98 10 20 00  clr  %o4
a00d09cc:  92 03 00 18  add  %o4, %i0, %o1
a00d09d0:  d0 0a 60 08  ldub  [ %o1 + 8 ], %o0
a00d09d4:  d0 2a 80 0c  stb  %o0, [ %o2 + %o4 ]
a00d09d8:  96 02 e0 01  inc  %o3
a00d09dc:  98 0a e0 ff  and  %o3, 0xff, %o4
a00d09e0:  80 a3 20 1f  cmp  %o4, 0x1f
a00d09e4:  08 bf ff fb  bleu  0xa00d09d0
a00d09e8:  92 03 00 18  add  %o4, %i0, %o1
a00d09ec:  10 bf fd de  b  0xa00d0164
a00d09f0:  98 14 e2 50  or  %l3, 0x250, %o4
a00d09f4:  9a 10 20 6e  mov  0x6e, %o5
a00d09f8:  ac 10 3f 83  mov  -125, %l6
a00d09fc:  da 2e 40 00  stb  %o5, [ %i1 ]
a00d0a00:  ec 2e 60 01  stb  %l6, [ %i1 + 1 ]
a00d0a04:  ea 0e 20 06  ldub  [ %i0 + 6 ], %l5
a00d0a08:  ea 2e 60 02  stb  %l5, [ %i1 + 2 ]
a00d0a0c:  de 0e 20 07  ldub  [ %i0 + 7 ], %o7
a00d0a10:  de 2e 60 03  stb  %o7, [ %i1 + 3 ]
a00d0a14:  e8 0e 20 01  ldub  [ %i0 + 1 ], %l4
a00d0a18:  a2 05 20 7a  add  %l4, 0x7a, %l1
a00d0a1c:  10 bf ff 18  b  0xa00d067c
a00d0a20:  e2 2e 60 04  stb  %l1, [ %i1 + 4 ]
a00d0a24:  ea 0e 20 06  ldub  [ %i0 + 6 ], %l5
a00d0a28:  80 a5 60 05  cmp  %l5, 5
a00d0a2c:  32 bf fc e4  bne,a   0xa00cfdbc
a00d0a30:  80 a3 60 a7  cmp  %o5, 0xa7
a00d0a34:  10 bf fc 92  b  0xa00cfc7c
a00d0a38:  80 8c a0 ff  btst  0xff, %l2
a00d0a3c:  80 a3 e0 06  cmp  %o7, 6
a00d0a40:  12 bf fc df  bne  0xa00cfdbc
a00d0a44:  80 a3 60 a7  cmp  %o5, 0xa7
a00d0a48:  d8 0e 20 07  ldub  [ %i0 + 7 ], %o4
a00d0a4c:  80 a3 20 01  cmp  %o4, 1
a00d0a50:  02 80 00 89  be  0xa00d0c74
a00d0a54:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00d0a58:  c2 02 62 90  ld  [ %o1 + 0x290 ], %g1	! 0xa802d290
a00d0a5c:  21 00 00 04  sethi  %hi(0x1000), %l0
a00d0a60:  a6 28 40 10  andn  %g1, %l0, %l3
a00d0a64:  7f fe e5 30  call  0xa0089f24
a00d0a68:  e6 22 62 90  st  %l3, [ %o1 + 0x290 ]
a00d0a6c:  30 bf fc 81  b,a   0xa00cfc70
a00d0a70:  80 a0 60 00  cmp  %g1, 0
a00d0a74:  22 bf ff 1d  be,a   0xa00d06e8
a00d0a78:  82 10 20 80  mov  0x80, %g1
a00d0a7c:  80 a0 60 01  cmp  %g1, 1
a00d0a80:  02 80 00 90  be  0xa00d0cc0
a00d0a84:  80 a0 60 02  cmp  %g1, 2
a00d0a88:  02 80 00 8b  be  0xa00d0cb4
a00d0a8c:  82 10 22 00  mov  0x200, %g1
a00d0a90:  10 bf fd ac  b  0xa00d0140
a00d0a94:  c2 33 62 52  sth  %g1, [ %o5 + 0x252 ]
a00d0a98:  ec 0e 20 01  ldub  [ %i0 + 1 ], %l6
a00d0a9c:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00d0aa0:  d4 0e 20 07  ldub  [ %i0 + 7 ], %o2
a00d0aa4:  ea 0e 20 06  ldub  [ %i0 + 6 ], %l5
a00d0aa8:  a0 14 62 74  or  %l1, 0x274, %l0
a00d0aac:  a8 05 a0 7a  add  %l6, 0x7a, %l4
a00d0ab0:  e8 2c 20 02  stb  %l4, [ %l0 + 2 ]
a00d0ab4:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00d0ab8:  98 10 20 6e  mov  0x6e, %o4
a00d0abc:  9e 10 3f 88  mov  -120, %o7
a00d0ac0:  d4 2e 60 03  stb  %o2, [ %i1 + 3 ]
a00d0ac4:  d8 2e 40 00  stb  %o4, [ %i1 ]
a00d0ac8:  de 2e 60 01  stb  %o7, [ %i1 + 1 ]
a00d0acc:  ea 2e 60 02  stb  %l5, [ %i1 + 2 ]
a00d0ad0:  d6 0c 20 02  ldub  [ %l0 + 2 ], %o3
a00d0ad4:  d6 2e 60 04  stb  %o3, [ %i1 + 4 ]
a00d0ad8:  7f fe e5 22  call  0xa0089f60
a00d0adc:  90 10 20 50  mov  0x50, %o0
a00d0ae0:  c2 0c 20 02  ldub  [ %l0 + 2 ], %g1
a00d0ae4:  80 a0 60 00  cmp  %g1, 0
a00d0ae8:  08 80 00 0d  bleu  0xa00d0b1c
a00d0aec:  94 10 20 00  clr  %o2
a00d0af0:  90 10 00 10  mov  %l0, %o0
a00d0af4:  92 10 00 01  mov  %g1, %o1
a00d0af8:  96 10 20 00  clr  %o3
a00d0afc:  82 02 c0 18  add  %o3, %i0, %g1
a00d0b00:  a6 02 c0 08  add  %o3, %o0, %l3
a00d0b04:  94 02 a0 01  inc  %o2
a00d0b08:  da 08 60 08  ldub  [ %g1 + 8 ], %o5
a00d0b0c:  96 0a a0 ff  and  %o2, 0xff, %o3
a00d0b10:  80 a2 40 0b  cmp  %o1, %o3
a00d0b14:  18 bf ff fa  bgu  0xa00d0afc
a00d0b18:  da 2c e0 03  stb  %o5, [ %l3 + 3 ]
a00d0b1c:  92 14 62 74  or  %l1, 0x274, %o1
a00d0b20:  94 10 22 e0  mov  0x2e0, %o2
a00d0b24:  10 bf fc c4  b  0xa00cfe34
a00d0b28:  96 10 20 1c  mov  0x1c, %o3
a00d0b2c:  c2 0e 20 07  ldub  [ %i0 + 7 ], %g1
a00d0b30:  80 a0 60 00  cmp  %g1, 0
a00d0b34:  12 80 00 66  bne  0xa00d0ccc
a00d0b38:  80 a0 60 01  cmp  %g1, 1
a00d0b3c:  2b 2a 00 b4  sethi  %hi(0xa802d000), %l5
a00d0b40:  82 15 62 90  or  %l5, 0x290, %g1	! 0xa802d290
a00d0b44:  d4 00 61 1c  ld  [ %g1 + 0x11c ], %o2
a00d0b48:  17 20 00 00  sethi  %hi(0x80000000), %o3
a00d0b4c:  9a 2a 80 0b  andn  %o2, %o3, %o5
a00d0b50:  da 20 61 1c  st  %o5, [ %g1 + 0x11c ]
a00d0b54:  40 01 b0 c6  call  0xa013ce6c
a00d0b58:  90 10 20 00  clr  %o0
a00d0b5c:  ac 0a 20 ff  and  %o0, 0xff, %l6
a00d0b60:  80 a5 a0 0c  cmp  %l6, 0xc
a00d0b64:  12 bf ff 1d  bne  0xa00d07d8
a00d0b68:  01 00 00 00  nop
a00d0b6c:  40 00 21 24  call  0xa00d8ffc
a00d0b70:  01 00 00 00  nop
a00d0b74:  7f fe e4 ec  call  0xa0089f24
a00d0b78:  01 00 00 00  nop
a00d0b7c:  30 bf fc 3d  b,a   0xa00cfc70
a00d0b80:  7f fe e4 e9  call  0xa0089f24
a00d0b84:  c0 2d 20 65  clrb  [ %l4 + 0x65 ]
a00d0b88:  30 bf fc 3a  b,a   0xa00cfc70
a00d0b8c:  12 bf fc 80  bne  0xa00cfd8c
a00d0b90:  80 a3 60 a3  cmp  %o5, 0xa3
a00d0b94:  ec 0e 20 06  ldub  [ %i0 + 6 ], %l6
a00d0b98:  80 a5 a0 01  cmp  %l6, 1
a00d0b9c:  12 bf fc 7c  bne  0xa00cfd8c
a00d0ba0:  80 a3 60 a3  cmp  %o5, 0xa3
a00d0ba4:  1b 2a 00 97  sethi  %hi(0xa8025c00), %o5
a00d0ba8:  94 13 60 58  or  %o5, 0x58, %o2	! 0xa8025c58
a00d0bac:  96 10 20 00  clr  %o3
a00d0bb0:  98 10 20 00  clr  %o4
a00d0bb4:  82 10 20 00  clr  %g1
a00d0bb8:  a7 28 60 02  sll  %g1, 2, %l3
a00d0bbc:  92 04 c0 0a  add  %l3, %o2, %o1
a00d0bc0:  d0 12 60 02  lduh  [ %o1 + 2 ], %o0
a00d0bc4:  98 03 20 01  inc  %o4
a00d0bc8:  9a 12 c0 08  or  %o3, %o0, %o5
a00d0bcc:  82 0b 20 ff  and  %o4, 0xff, %g1
a00d0bd0:  80 a0 60 02  cmp  %g1, 2
a00d0bd4:  08 bf ff f9  bleu  0xa00d0bb8
a00d0bd8:  96 10 00 0d  mov  %o5, %o3
a00d0bdc:  a1 2b 60 10  sll  %o5, 0x10, %l0
a00d0be0:  a3 34 20 10  srl  %l0, 0x10, %l1
a00d0be4:  c2 0e 20 07  ldub  [ %i0 + 7 ], %g1
a00d0be8:  80 a0 60 01  cmp  %g1, 1
a00d0bec:  02 80 00 71  be  0xa00d0db0
a00d0bf0:  a6 10 00 11  mov  %l1, %l3
a00d0bf4:  80 a0 60 00  cmp  %g1, 0
a00d0bf8:  32 bf fc 21  bne,a   0xa00cfc7c
a00d0bfc:  80 8c a0 ff  btst  0xff, %l2
a00d0c00:  90 10 20 fe  mov  0xfe, %o0
a00d0c04:  40 01 ea 2c  call  0xa014b4b4
a00d0c08:  92 10 20 01  mov  1, %o1
a00d0c0c:  21 2a 00 ac  sethi  %hi(0xa802b000), %l0
a00d0c10:  c0 2c 20 9d  clrb  [ %l0 + 0x9d ]	! 0xa802b09d
a00d0c14:  90 10 20 fe  mov  0xfe, %o0
a00d0c18:  40 01 ea 27  call  0xa014b4b4
a00d0c1c:  92 10 20 01  mov  1, %o1
a00d0c20:  97 34 60 08  srl  %l1, 8, %o3
a00d0c24:  9e 10 20 6e  mov  0x6e, %o7
a00d0c28:  aa 10 3f 84  mov  -124, %l5
a00d0c2c:  94 10 20 02  mov  2, %o2
a00d0c30:  de 2e 40 00  stb  %o7, [ %i1 ]
a00d0c34:  ea 2e 60 01  stb  %l5, [ %i1 + 1 ]
a00d0c38:  d4 2e 60 02  stb  %o2, [ %i1 + 2 ]
a00d0c3c:  d6 2e 60 03  stb  %o3, [ %i1 + 3 ]
a00d0c40:  e2 0c 20 9d  ldub  [ %l0 + 0x9d ], %l1
a00d0c44:  82 04 40 11  add  %l1, %l1, %g1
a00d0c48:  c2 2e 60 04  stb  %g1, [ %i1 + 4 ]
a00d0c4c:  10 bf fe 8c  b  0xa00d067c
a00d0c50:  e6 2e 60 05  stb  %l3, [ %i1 + 5 ]
a00d0c54:  18 bf fe 6e  bgu  0xa00d060c
a00d0c58:  82 10 20 7e  mov  0x7e, %g1
a00d0c5c:  10 bf fe 6c  b  0xa00d060c
a00d0c60:  c2 34 21 da  sth  %g1, [ %l0 + 0x1da ]
a00d0c64:  98 15 62 90  or  %l5, 0x290, %o4
a00d0c68:  e6 34 61 f6  sth  %l3, [ %l1 + 0x1f6 ]
a00d0c6c:  10 bf fd e7  b  0xa00d0408
a00d0c70:  e8 2b 21 d5  stb  %l4, [ %o4 + 0x1d5 ]
a00d0c74:  29 2a 00 b4  sethi  %hi(0xa802d000), %l4
a00d0c78:  da 05 22 90  ld  [ %l4 + 0x290 ], %o5	! 0xa802d290
a00d0c7c:  11 00 00 04  sethi  %hi(0x1000), %o0
a00d0c80:  ac 13 40 08  or  %o5, %o0, %l6
a00d0c84:  7f fe e4 a8  call  0xa0089f24
a00d0c88:  ec 25 22 90  st  %l6, [ %l4 + 0x290 ]
a00d0c8c:  30 bf fb f9  b,a   0xa00cfc70
a00d0c90:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00d0c94:  27 00 00 15  sethi  %hi(0x5400), %l3
a00d0c98:  90 10 62 90  or  %g1, 0x290, %o0
a00d0c9c:  a0 10 20 64  mov  0x64, %l0
a00d0ca0:  92 14 e1 aa  or  %l3, 0x1aa, %o1
a00d0ca4:  e0 2a 20 10  stb  %l0, [ %o0 + 0x10 ]
a00d0ca8:  7f fe e4 9f  call  0xa0089f24
a00d0cac:  d2 32 21 f6  sth  %o1, [ %o0 + 0x1f6 ]
a00d0cb0:  30 bf fb f0  b,a   0xa00cfc70
a00d0cb4:  82 10 21 80  mov  0x180, %g1
a00d0cb8:  10 bf fd 22  b  0xa00d0140
a00d0cbc:  c2 33 62 52  sth  %g1, [ %o5 + 0x252 ]
a00d0cc0:  82 10 21 00  mov  0x100, %g1
a00d0cc4:  10 bf fd 1f  b  0xa00d0140
a00d0cc8:  c2 33 62 52  sth  %g1, [ %o5 + 0x252 ]
a00d0ccc:  12 bf ff a2  bne  0xa00d0b54
a00d0cd0:  29 2a 00 b4  sethi  %hi(0xa802d000), %l4
a00d0cd4:  82 15 22 90  or  %l4, 0x290, %g1	! 0xa802d290
a00d0cd8:  de 00 61 1c  ld  [ %g1 + 0x11c ], %o7
a00d0cdc:  19 20 00 00  sethi  %hi(0x80000000), %o4
a00d0ce0:  10 bf ff 9c  b  0xa00d0b50
a00d0ce4:  9a 13 c0 0c  or  %o7, %o4, %o5
a00d0ce8:  7f ff f7 4c  call  0xa00cea18
a00d0cec:  01 00 00 00  nop
a00d0cf0:  10 bf fb e3  b  0xa00cfc7c
a00d0cf4:  80 8c a0 ff  btst  0xff, %l2
a00d0cf8:  9a 10 20 0b  mov  0xb, %o5
a00d0cfc:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00d0d00:  10 bf fb dc  b  0xa00cfc70
a00d0d04:  da 2a 22 98  stb  %o5, [ %o0 + 0x298 ]	! 0xa802d298
a00d0d08:  10 bf ff fd  b  0xa00d0cfc
a00d0d0c:  9a 10 20 0d  mov  0xd, %o5
a00d0d10:  2d 2a 00 b4  sethi  %hi(0xa802d000), %l6
a00d0d14:  aa 15 a2 90  or  %l6, 0x290, %l5	! 0xa802d290
a00d0d18:  e8 05 61 d4  ld  [ %l5 + 0x1d4 ], %l4
a00d0d1c:  98 15 20 40  or  %l4, 0x40, %o4
a00d0d20:  de 0d 61 d8  ldub  [ %l5 + 0x1d8 ], %o7
a00d0d24:  d8 25 61 d4  st  %o4, [ %l5 + 0x1d4 ]
a00d0d28:  de 2d 60 09  stb  %o7, [ %l5 + 9 ]
a00d0d2c:  40 00 1f ea  call  0xa00d8cd4
a00d0d30:  a6 10 20 03  mov  3, %l3
a00d0d34:  40 00 0f 19  call  0xa00d4998
a00d0d38:  a2 10 20 02  mov  2, %l1
a00d0d3c:  92 10 00 15  mov  %l5, %o1
a00d0d40:  94 10 20 00  clr  %o2
a00d0d44:  96 10 21 fc  mov  0x1fc, %o3
a00d0d48:  40 01 e8 62  call  0xa014aed0
a00d0d4c:  90 10 20 30  mov  0x30, %o0
a00d0d50:  92 10 3f ff  mov  -1, %o1
a00d0d54:  94 10 20 6e  mov  0x6e, %o2
a00d0d58:  96 10 3f 87  mov  -121, %o3
a00d0d5c:  82 10 23 6f  mov  0x36f, %g1
a00d0d60:  a0 10 3f 96  mov  -106, %l0
a00d0d64:  d4 2e 40 00  stb  %o2, [ %i1 ]
a00d0d68:  d6 2e 60 01  stb  %o3, [ %i1 + 1 ]
a00d0d6c:  e2 2e 60 02  stb  %l1, [ %i1 + 2 ]
a00d0d70:  c2 2e 60 04  stb  %g1, [ %i1 + 4 ]
a00d0d74:  e6 2e 60 05  stb  %l3, [ %i1 + 5 ]
a00d0d78:  e0 2e 60 07  stb  %l0, [ %i1 + 7 ]
a00d0d7c:  d2 2e 60 08  stb  %o1, [ %i1 + 8 ]
a00d0d80:  e6 2e 60 03  stb  %l3, [ %i1 + 3 ]
a00d0d84:  10 bf fe 3e  b  0xa00d067c
a00d0d88:  d2 2e 60 06  stb  %o1, [ %i1 + 6 ]
a00d0d8c:  10 bf ff dc  b  0xa00d0cfc
a00d0d90:  9a 10 20 10  mov  0x10, %o5
a00d0d94:  92 14 62 90  or  %l1, 0x290, %o1
a00d0d98:  94 10 20 00  clr  %o2
a00d0d9c:  96 10 21 fc  mov  0x1fc, %o3
a00d0da0:  40 01 e8 4c  call  0xa014aed0
a00d0da4:  90 10 20 30  mov  0x30, %o0
a00d0da8:  10 bf fe 21  b  0xa00d062c
a00d0dac:  90 10 20 00  clr  %o0
a00d0db0:  21 2a 00 ac  sethi  %hi(0xa802b000), %l0
a00d0db4:  10 bf ff 98  b  0xa00d0c14
a00d0db8:  c2 2c 20 9d  stb  %g1, [ %l0 + 0x9d ]	! 0xa802b09d
a00d0dbc:  10 bf ff d0  b  0xa00d0cfc
a00d0dc0:  9a 10 20 11  mov  0x11, %o5
a00d0dc4:  10 bf ff ce  b  0xa00d0cfc
a00d0dc8:  9a 10 20 15  mov  0x15, %o5
a00d0dcc:  10 bf ff cc  b  0xa00d0cfc
a00d0dd0:  9a 10 20 1a  mov  0x1a, %o5
a00d0dd4:  10 bf ff ca  b  0xa00d0cfc
a00d0dd8:  9a 10 20 13  mov  0x13, %o5
a00d0ddc:  10 bf ff c8  b  0xa00d0cfc
a00d0de0:  9a 10 20 0a  mov  0xa, %o5
a00d0de4:  10 bf ff c6  b  0xa00d0cfc
a00d0de8:  9a 10 20 0e  mov  0xe, %o5
a00d0dec:  10 bf ff c4  b  0xa00d0cfc
a00d0df0:  9a 10 20 05  mov  5, %o5
a00d0df4:  10 bf ff c2  b  0xa00d0cfc
a00d0df8:  9a 10 20 08  mov  8, %o5
a00d0dfc:  10 bf ff c0  b  0xa00d0cfc
a00d0e00:  9a 10 20 09  mov  9, %o5
a00d0e04:  10 bf ff be  b  0xa00d0cfc
a00d0e08:  9a 10 20 06  mov  6, %o5
a00d0e0c:  10 bf ff bc  b  0xa00d0cfc
a00d0e10:  9a 10 20 07  mov  7, %o5
a00d0e14:  10 bf ff ba  b  0xa00d0cfc
a00d0e18:  9a 10 20 04  mov  4, %o5
a00d0e1c:  10 bf ff b8  b  0xa00d0cfc
a00d0e20:  9a 10 20 03  mov  3, %o5
a00d0e24:  10 bf ff b6  b  0xa00d0cfc
a00d0e28:  9a 10 20 02  mov  2, %o5
a00d0e2c:  10 bf ff b4  b  0xa00d0cfc
a00d0e30:  9a 10 20 01  mov  1, %o5
a00d0e34:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00d0e38:  10 bf fb 8e  b  0xa00cfc70
a00d0e3c:  c0 2b 62 98  clrb  [ %o5 + 0x298 ]	! 0xa802d298
a00d0e40:  81 c7 e0 08  ret
a00d0e44:  81 e8 00 00  restore
