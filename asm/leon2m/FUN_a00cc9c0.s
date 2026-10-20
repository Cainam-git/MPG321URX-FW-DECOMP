# leon2m FUN_a00cc9c0 0xa00cc9c0-0xa00ccc20 (608 bytes)
a00cc9c0:  9d e3 bf 98  save  %sp, -104, %sp
a00cc9c4:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00cc9c8:  9a 14 62 90  or  %l1, 0x290, %o5	! 0xa802d290
a00cc9cc:  c2 0b 60 11  ldub  [ %o5 + 0x11 ], %g1
a00cc9d0:  80 a0 60 03  cmp  %g1, 3
a00cc9d4:  02 80 00 04  be  0xa00cc9e4
a00cc9d8:  90 10 20 03  mov  3, %o0
a00cc9dc:  40 00 33 62  call  0xa00d9764
a00cc9e0:  d0 2b 60 11  stb  %o0, [ %o5 + 0x11 ]
a00cc9e4:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00cc9e8:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00cc9ec:  80 a4 20 02  cmp  %l0, 2
a00cc9f0:  02 80 00 08  be  0xa00cca10
a00cc9f4:  82 12 60 40  or  %o1, 0x40, %g1
a00cc9f8:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00cc9fc:  80 a4 20 03  cmp  %l0, 3
a00cca00:  02 80 00 04  be  0xa00cca10
a00cca04:  82 12 a0 98  or  %o2, 0x98, %g1
a00cca08:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00cca0c:  82 12 e0 d0  or  %o3, 0xd0, %g1	! 0xa802d0d0
a00cca10:  de 08 60 07  ldub  [ %g1 + 7 ], %o7
a00cca14:  94 03 ff d0  add  %o7, -48, %o2
a00cca18:  9a 0a a0 ff  and  %o2, 0xff, %o5
a00cca1c:  80 a3 60 01  cmp  %o5, 1
a00cca20:  d6 08 60 09  ldub  [ %g1 + 9 ], %o3
a00cca24:  d8 08 60 08  ldub  [ %g1 + 8 ], %o4
a00cca28:  18 80 00 07  bgu  0xa00cca44
a00cca2c:  9a 10 20 ff  mov  0xff, %o5
a00cca30:  98 03 3f d0  add  %o4, -48, %o4
a00cca34:  b0 0b 20 ff  and  %o4, 0xff, %i0
a00cca38:  80 a6 20 09  cmp  %i0, 9
a00cca3c:  28 80 00 31  bleu,a   0xa00ccb00
a00cca40:  96 02 ff d0  add  %o3, -48, %o3
a00cca44:  80 a3 60 ff  cmp  %o5, 0xff
a00cca48:  02 80 00 74  be  0xa00ccc18
a00cca4c:  b0 10 20 ff  mov  0xff, %i0
a00cca50:  80 a3 60 64  cmp  %o5, 0x64
a00cca54:  18 80 00 71  bgu  0xa00ccc18
a00cca58:  96 14 62 90  or  %l1, 0x290, %o3
a00cca5c:  40 00 1e f4  call  0xa00d462c
a00cca60:  da 2a e0 13  stb  %o5, [ %o3 + 0x13 ]
a00cca64:  7f ff af 9a  call  0xa00b88cc
a00cca68:  01 00 00 00  nop
a00cca6c:  80 a4 20 02  cmp  %l0, 2
a00cca70:  02 80 00 33  be  0xa00ccb3c
a00cca74:  80 a4 20 03  cmp  %l0, 3
a00cca78:  02 80 00 4e  be  0xa00ccbb0
a00cca7c:  9e 10 20 30  mov  0x30, %o7
a00cca80:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00cca84:  94 12 20 78  or  %o0, 0x78, %o2	! 0xa802d078
a00cca88:  82 10 20 35  mov  0x35, %g1
a00cca8c:  b0 10 20 36  mov  0x36, %i0
a00cca90:  9a 10 20 2b  mov  0x2b, %o5
a00cca94:  98 10 20 0d  mov  0xd, %o4
a00cca98:  c2 2a 20 78  stb  %g1, [ %o0 + 0x78 ]
a00cca9c:  f0 2a a0 01  stb  %i0, [ %o2 + 1 ]
a00ccaa0:  de 2a a0 03  stb  %o7, [ %o2 + 3 ]
a00ccaa4:  da 2a a0 04  stb  %o5, [ %o2 + 4 ]
a00ccaa8:  d8 2a a0 05  stb  %o4, [ %o2 + 5 ]
a00ccaac:  80 a4 20 02  cmp  %l0, 2
a00ccab0:  02 80 00 30  be  0xa00ccb70
a00ccab4:  de 2a a0 02  stb  %o7, [ %o2 + 2 ]
a00ccab8:  80 a4 20 03  cmp  %l0, 3
a00ccabc:  02 80 00 4a  be  0xa00ccbe4
a00ccac0:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00ccac4:  9a 13 20 d0  or  %o4, 0xd0, %o5	! 0xa802d0d0
a00ccac8:  31 2a 00 ac  sethi  %hi(0xa802b000), %i0
a00ccacc:  c0 2e 20 9c  clrb  [ %i0 + 0x9c ]	! 0xa802b09c
a00ccad0:  c0 2b 20 d0  clrb  [ %o4 + 0xd0 ]
a00ccad4:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00ccad8:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00ccadc:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00ccae0:  80 a4 20 02  cmp  %l0, 2
a00ccae4:  02 80 00 2c  be  0xa00ccb94
a00ccae8:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00ccaec:  80 a4 20 03  cmp  %l0, 3
a00ccaf0:  12 80 00 2c  bne  0xa00ccba0
a00ccaf4:  90 10 00 10  mov  %l0, %o0
a00ccaf8:  10 80 00 45  b  0xa00ccc0c
a00ccafc:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00ccb00:  82 0a e0 ff  and  %o3, 0xff, %g1
a00ccb04:  80 a0 60 09  cmp  %g1, 9
a00ccb08:  18 bf ff d0  bgu  0xa00cca48
a00ccb0c:  80 a3 60 ff  cmp  %o5, 0xff
a00ccb10:  90 0b 20 ff  and  %o4, 0xff, %o0
a00ccb14:  83 2a 20 02  sll  %o0, 2, %g1
a00ccb18:  9e 00 40 08  add  %g1, %o0, %o7
a00ccb1c:  b0 0a a0 ff  and  %o2, 0xff, %i0
a00ccb20:  9a 03 c0 0f  add  %o7, %o7, %o5
a00ccb24:  94 5e 20 64  smul  %i0, 0x64, %o2
a00ccb28:  92 02 80 0d  add  %o2, %o5, %o1
a00ccb2c:  98 0a e0 ff  and  %o3, 0xff, %o4
a00ccb30:  90 02 40 0c  add  %o1, %o4, %o0
a00ccb34:  10 bf ff c4  b  0xa00cca44
a00ccb38:  9a 0a 20 ff  and  %o0, 0xff, %o5
a00ccb3c:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00ccb40:  a0 13 61 28  or  %o5, 0x128, %l0	! 0xa802d128
a00ccb44:  a2 10 20 30  mov  0x30, %l1
a00ccb48:  9e 10 20 35  mov  0x35, %o7
a00ccb4c:  94 10 20 0d  mov  0xd, %o2
a00ccb50:  98 10 20 36  mov  0x36, %o4
a00ccb54:  92 10 20 2b  mov  0x2b, %o1
a00ccb58:  de 2b 61 28  stb  %o7, [ %o5 + 0x128 ]
a00ccb5c:  d4 2c 20 05  stb  %o2, [ %l0 + 5 ]
a00ccb60:  d8 2c 20 01  stb  %o4, [ %l0 + 1 ]
a00ccb64:  e2 2c 20 03  stb  %l1, [ %l0 + 3 ]
a00ccb68:  d2 2c 20 04  stb  %o1, [ %l0 + 4 ]
a00ccb6c:  e2 2c 20 02  stb  %l1, [ %l0 + 2 ]
a00ccb70:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00ccb74:  94 12 e0 40  or  %o3, 0x40, %o2	! 0xa802d040
a00ccb78:  21 2a 00 ac  sethi  %hi(0xa802b000), %l0
a00ccb7c:  c0 2c 20 9a  clrb  [ %l0 + 0x9a ]	! 0xa802b09a
a00ccb80:  c0 2a e0 40  clrb  [ %o3 + 0x40 ]
a00ccb84:  c0 2a a0 19  clrb  [ %o2 + 0x19 ]
a00ccb88:  c0 2a a0 01  clrb  [ %o2 + 1 ]
a00ccb8c:  c0 2a a0 07  clrb  [ %o2 + 7 ]
a00ccb90:  c0 2a a0 0a  clrb  [ %o2 + 0xa ]
a00ccb94:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00ccb98:  94 12 21 28  or  %o0, 0x128, %o2	! 0xa802d128
a00ccb9c:  90 10 20 02  mov  2, %o0
a00ccba0:  40 01 ef 12  call  0xa01487e8
a00ccba4:  92 10 20 06  mov  6, %o1
a00ccba8:  10 80 00 1c  b  0xa00ccc18
a00ccbac:  b0 10 20 00  clr  %i0
a00ccbb0:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00ccbb4:  b0 14 61 08  or  %l1, 0x108, %i0	! 0xa802d108
a00ccbb8:  90 10 20 30  mov  0x30, %o0
a00ccbbc:  92 10 20 35  mov  0x35, %o1
a00ccbc0:  a0 10 20 0d  mov  0xd, %l0
a00ccbc4:  96 10 20 36  mov  0x36, %o3
a00ccbc8:  82 10 20 2b  mov  0x2b, %g1
a00ccbcc:  d2 2c 61 08  stb  %o1, [ %l1 + 0x108 ]
a00ccbd0:  e0 2e 20 05  stb  %l0, [ %i0 + 5 ]
a00ccbd4:  d6 2e 20 01  stb  %o3, [ %i0 + 1 ]
a00ccbd8:  d0 2e 20 03  stb  %o0, [ %i0 + 3 ]
a00ccbdc:  c2 2e 20 04  stb  %g1, [ %i0 + 4 ]
a00ccbe0:  d0 2e 20 02  stb  %o0, [ %i0 + 2 ]
a00ccbe4:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00ccbe8:  a2 12 60 98  or  %o1, 0x98, %l1	! 0xa802d098
a00ccbec:  1f 2a 00 ac  sethi  %hi(0xa802b000), %o7
a00ccbf0:  c0 2b e0 98  clrb  [ %o7 + 0x98 ]	! 0xa802b098
a00ccbf4:  c0 2a 60 98  clrb  [ %o1 + 0x98 ]
a00ccbf8:  c0 2c 60 19  clrb  [ %l1 + 0x19 ]
a00ccbfc:  c0 2c 60 01  clrb  [ %l1 + 1 ]
a00ccc00:  c0 2c 60 07  clrb  [ %l1 + 7 ]
a00ccc04:  c0 2c 60 0a  clrb  [ %l1 + 0xa ]
a00ccc08:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00ccc0c:  94 10 61 08  or  %g1, 0x108, %o2	! 0xa802d108
a00ccc10:  10 bf ff e4  b  0xa00ccba0
a00ccc14:  90 10 20 03  mov  3, %o0
a00ccc18:  81 c7 e0 08  ret
a00ccc1c:  81 e8 00 00  restore
