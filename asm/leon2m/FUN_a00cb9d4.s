# leon2m FUN_a00cb9d4 0xa00cb9d4-0xa00cbbb0 (476 bytes)
a00cb9d4:  9d e3 bf 98  save  %sp, -104, %sp
a00cb9d8:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00cb9dc:  80 a4 20 02  cmp  %l0, 2
a00cb9e0:  02 80 00 52  be  0xa00cbb28
a00cb9e4:  80 a4 20 03  cmp  %l0, 3
a00cb9e8:  02 80 00 53  be  0xa00cbb34
a00cb9ec:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00cb9f0:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00cb9f4:  94 08 60 ff  and  %g1, 0xff, %o2
a00cb9f8:  98 02 bf d0  add  %o2, -48, %o4
a00cb9fc:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00cba00:  80 a3 60 01  cmp  %o5, 1
a00cba04:  18 80 00 69  bgu  0xa00cbba8
a00cba08:  b0 10 20 ff  mov  0xff, %i0
a00cba0c:  17 2a 00 b5  sethi  %hi(0xa802d400), %o3
a00cba10:  40 00 3c 60  call  0xa00dab90
a00cba14:  d8 2a e0 7c  stb  %o4, [ %o3 + 0x7c ]	! 0xa802d47c
a00cba18:  7f ff b3 ad  call  0xa00b88cc
a00cba1c:  01 00 00 00  nop
a00cba20:  80 a4 20 02  cmp  %l0, 2
a00cba24:  02 80 00 24  be  0xa00cbab4
a00cba28:  80 a4 20 03  cmp  %l0, 3
a00cba2c:  02 80 00 45  be  0xa00cbb40
a00cba30:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00cba34:  94 13 60 78  or  %o5, 0x78, %o2	! 0xa802d078
a00cba38:  90 10 20 30  mov  0x30, %o0
a00cba3c:  96 10 20 35  mov  0x35, %o3
a00cba40:  98 10 20 36  mov  0x36, %o4
a00cba44:  92 10 20 2b  mov  0x2b, %o1
a00cba48:  82 10 20 0d  mov  0xd, %g1
a00cba4c:  d6 2b 60 78  stb  %o3, [ %o5 + 0x78 ]
a00cba50:  d8 2a a0 01  stb  %o4, [ %o2 + 1 ]
a00cba54:  d0 2a a0 03  stb  %o0, [ %o2 + 3 ]
a00cba58:  d2 2a a0 04  stb  %o1, [ %o2 + 4 ]
a00cba5c:  c2 2a a0 05  stb  %g1, [ %o2 + 5 ]
a00cba60:  80 a4 20 02  cmp  %l0, 2
a00cba64:  02 80 00 21  be  0xa00cbae8
a00cba68:  d0 2a a0 02  stb  %o0, [ %o2 + 2 ]
a00cba6c:  80 a4 20 03  cmp  %l0, 3
a00cba70:  02 80 00 41  be  0xa00cbb74
a00cba74:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00cba78:  92 13 20 d0  or  %o4, 0xd0, %o1	! 0xa802d0d0
a00cba7c:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00cba80:  c0 2b 60 9c  clrb  [ %o5 + 0x9c ]	! 0xa802b09c
a00cba84:  c0 2b 20 d0  clrb  [ %o4 + 0xd0 ]
a00cba88:  c0 2a 60 19  clrb  [ %o1 + 0x19 ]
a00cba8c:  c0 2a 60 01  clrb  [ %o1 + 1 ]
a00cba90:  c0 2a 60 07  clrb  [ %o1 + 7 ]
a00cba94:  80 a4 20 02  cmp  %l0, 2
a00cba98:  02 80 00 1d  be  0xa00cbb0c
a00cba9c:  c0 2a 60 0a  clrb  [ %o1 + 0xa ]
a00cbaa0:  80 a4 20 03  cmp  %l0, 3
a00cbaa4:  12 80 00 1d  bne  0xa00cbb18
a00cbaa8:  90 10 00 10  mov  %l0, %o0
a00cbaac:  10 80 00 3c  b  0xa00cbb9c
a00cbab0:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00cbab4:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00cbab8:  98 12 21 28  or  %o0, 0x128, %o4	! 0xa802d128
a00cbabc:  9e 10 20 30  mov  0x30, %o7
a00cbac0:  92 10 20 35  mov  0x35, %o1
a00cbac4:  82 10 20 0d  mov  0xd, %g1
a00cbac8:  b0 10 20 36  mov  0x36, %i0
a00cbacc:  a0 10 20 2b  mov  0x2b, %l0
a00cbad0:  d2 2a 21 28  stb  %o1, [ %o0 + 0x128 ]
a00cbad4:  c2 2b 20 05  stb  %g1, [ %o4 + 5 ]
a00cbad8:  f0 2b 20 01  stb  %i0, [ %o4 + 1 ]
a00cbadc:  de 2b 20 03  stb  %o7, [ %o4 + 3 ]
a00cbae0:  e0 2b 20 04  stb  %l0, [ %o4 + 4 ]
a00cbae4:  de 2b 20 02  stb  %o7, [ %o4 + 2 ]
a00cbae8:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00cbaec:  94 13 e0 40  or  %o7, 0x40, %o2	! 0xa802d040
a00cbaf0:  21 2a 00 ac  sethi  %hi(0xa802b000), %l0
a00cbaf4:  c0 2c 20 9a  clrb  [ %l0 + 0x9a ]	! 0xa802b09a
a00cbaf8:  c0 2b e0 40  clrb  [ %o7 + 0x40 ]
a00cbafc:  c0 2a a0 19  clrb  [ %o2 + 0x19 ]
a00cbb00:  c0 2a a0 01  clrb  [ %o2 + 1 ]
a00cbb04:  c0 2a a0 07  clrb  [ %o2 + 7 ]
a00cbb08:  c0 2a a0 0a  clrb  [ %o2 + 0xa ]
a00cbb0c:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00cbb10:  94 12 e1 28  or  %o3, 0x128, %o2	! 0xa802d128
a00cbb14:  90 10 20 02  mov  2, %o0
a00cbb18:  40 01 f3 34  call  0xa01487e8
a00cbb1c:  92 10 20 06  mov  6, %o1
a00cbb20:  10 80 00 22  b  0xa00cbba8
a00cbb24:  b0 10 20 00  clr  %i0
a00cbb28:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00cbb2c:  10 bf ff b2  b  0xa00cb9f4
a00cbb30:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00cbb34:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00cbb38:  10 bf ff af  b  0xa00cb9f4
a00cbb3c:  c2 0a 20 a1  ldub  [ %o0 + 0xa1 ], %g1	! 0xa802d0a1
a00cbb40:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00cbb44:  98 14 21 08  or  %l0, 0x108, %o4	! 0xa802d108
a00cbb48:  94 10 20 30  mov  0x30, %o2
a00cbb4c:  b0 10 20 35  mov  0x35, %i0
a00cbb50:  9e 10 20 0d  mov  0xd, %o7
a00cbb54:  96 10 20 36  mov  0x36, %o3
a00cbb58:  9a 10 20 2b  mov  0x2b, %o5
a00cbb5c:  f0 2c 21 08  stb  %i0, [ %l0 + 0x108 ]
a00cbb60:  de 2b 20 05  stb  %o7, [ %o4 + 5 ]
a00cbb64:  d6 2b 20 01  stb  %o3, [ %o4 + 1 ]
a00cbb68:  d4 2b 20 03  stb  %o2, [ %o4 + 3 ]
a00cbb6c:  da 2b 20 04  stb  %o5, [ %o4 + 4 ]
a00cbb70:  d4 2b 20 02  stb  %o2, [ %o4 + 2 ]
a00cbb74:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00cbb78:  b0 12 20 98  or  %o0, 0x98, %i0	! 0xa802d098
a00cbb7c:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00cbb80:  c0 28 60 98  clrb  [ %g1 + 0x98 ]	! 0xa802b098
a00cbb84:  c0 2a 20 98  clrb  [ %o0 + 0x98 ]
a00cbb88:  c0 2e 20 19  clrb  [ %i0 + 0x19 ]
a00cbb8c:  c0 2e 20 01  clrb  [ %i0 + 1 ]
a00cbb90:  c0 2e 20 07  clrb  [ %i0 + 7 ]
a00cbb94:  c0 2e 20 0a  clrb  [ %i0 + 0xa ]
a00cbb98:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00cbb9c:  94 12 a1 08  or  %o2, 0x108, %o2	! 0xa802d108
a00cbba0:  10 bf ff de  b  0xa00cbb18
a00cbba4:  90 10 20 03  mov  3, %o0
a00cbba8:  81 c7 e0 08  ret
a00cbbac:  81 e8 00 00  restore
