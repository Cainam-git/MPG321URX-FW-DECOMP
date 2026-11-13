# leon2m FUN_a00cbbb0 0xa00cbbb0-0xa00cbe2c (636 bytes)
a00cbbb0:  9d e3 bf 98  save  %sp, -104, %sp
a00cbbb4:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00cbbb8:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00cbbbc:  80 a4 20 02  cmp  %l0, 2
a00cbbc0:  02 80 00 08  be  0xa00cbbe0
a00cbbc4:  82 10 60 40  or  %g1, 0x40, %g1
a00cbbc8:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00cbbcc:  80 a4 20 03  cmp  %l0, 3
a00cbbd0:  02 80 00 04  be  0xa00cbbe0
a00cbbd4:  82 12 20 98  or  %o0, 0x98, %g1
a00cbbd8:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00cbbdc:  82 12 60 d0  or  %o1, 0xd0, %g1	! 0xa802d0d0
a00cbbe0:  de 08 60 07  ldub  [ %g1 + 7 ], %o7
a00cbbe4:  94 03 ff d0  add  %o7, -48, %o2
a00cbbe8:  9a 0a a0 ff  and  %o2, 0xff, %o5
a00cbbec:  80 a3 60 01  cmp  %o5, 1
a00cbbf0:  d6 08 60 09  ldub  [ %g1 + 9 ], %o3
a00cbbf4:  d8 08 60 08  ldub  [ %g1 + 8 ], %o4
a00cbbf8:  18 80 00 07  bgu  0xa00cbc14
a00cbbfc:  9a 10 20 ff  mov  0xff, %o5
a00cbc00:  98 03 3f d0  add  %o4, -48, %o4
a00cbc04:  b0 0b 20 ff  and  %o4, 0xff, %i0
a00cbc08:  80 a6 20 09  cmp  %i0, 9
a00cbc0c:  08 80 00 3b  bleu  0xa00cbcf8
a00cbc10:  96 02 ff d0  add  %o3, -48, %o3
a00cbc14:  94 03 7f ec  add  %o5, -20, %o2
a00cbc18:  96 0a a0 ff  and  %o2, 0xff, %o3
a00cbc1c:  80 a2 e0 50  cmp  %o3, 0x50
a00cbc20:  18 80 00 81  bgu  0xa00cbe24
a00cbc24:  b0 10 20 ff  mov  0xff, %i0
a00cbc28:  82 0b 60 ff  and  %o5, 0xff, %g1
a00cbc2c:  15 19 99 99  sethi  %hi(0x66666400), %o2
a00cbc30:  b0 00 7f ec  add  %g1, -20, %i0
a00cbc34:  96 12 a2 67  or  %o2, 0x267, %o3
a00cbc38:  80 5e 00 0b  smul  %i0, %o3, %g0
a00cbc3c:  91 40 00 00  rd  %y, %o0
a00cbc40:  9b 3a 20 03  sra  %o0, 3, %o5
a00cbc44:  9f 3e 20 1f  sra  %i0, 0x1f, %o7
a00cbc48:  98 23 40 0f  sub  %o5, %o7, %o4
a00cbc4c:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00cbc50:  d8 2a 63 3c  stb  %o4, [ %o1 + 0x33c ]	! 0xa802d33c
a00cbc54:  40 00 3a c0  call  0xa00da754
a00cbc58:  90 0b 20 ff  and  %o4, 0xff, %o0
a00cbc5c:  7f ff b3 1c  call  0xa00b88cc
a00cbc60:  01 00 00 00  nop
a00cbc64:  80 a4 20 02  cmp  %l0, 2
a00cbc68:  02 80 00 38  be  0xa00cbd48
a00cbc6c:  80 a4 20 03  cmp  %l0, 3
a00cbc70:  02 80 00 53  be  0xa00cbdbc
a00cbc74:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00cbc78:  94 13 20 78  or  %o4, 0x78, %o2	! 0xa802d078
a00cbc7c:  9e 10 20 30  mov  0x30, %o7
a00cbc80:  82 10 20 35  mov  0x35, %g1
a00cbc84:  96 10 20 36  mov  0x36, %o3
a00cbc88:  90 10 20 2b  mov  0x2b, %o0
a00cbc8c:  b0 10 20 0d  mov  0xd, %i0
a00cbc90:  c2 2b 20 78  stb  %g1, [ %o4 + 0x78 ]
a00cbc94:  d6 2a a0 01  stb  %o3, [ %o2 + 1 ]
a00cbc98:  de 2a a0 03  stb  %o7, [ %o2 + 3 ]
a00cbc9c:  d0 2a a0 04  stb  %o0, [ %o2 + 4 ]
a00cbca0:  f0 2a a0 05  stb  %i0, [ %o2 + 5 ]
a00cbca4:  80 a4 20 02  cmp  %l0, 2
a00cbca8:  02 80 00 35  be  0xa00cbd7c
a00cbcac:  de 2a a0 02  stb  %o7, [ %o2 + 2 ]
a00cbcb0:  80 a4 20 03  cmp  %l0, 3
a00cbcb4:  02 80 00 4f  be  0xa00cbdf0
a00cbcb8:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00cbcbc:  90 12 e0 d0  or  %o3, 0xd0, %o0	! 0xa802d0d0
a00cbcc0:  19 2a 00 ac  sethi  %hi(0xa802b000), %o4
a00cbcc4:  c0 2b 20 9c  clrb  [ %o4 + 0x9c ]	! 0xa802b09c
a00cbcc8:  c0 2a e0 d0  clrb  [ %o3 + 0xd0 ]
a00cbccc:  c0 2a 20 19  clrb  [ %o0 + 0x19 ]
a00cbcd0:  c0 2a 20 01  clrb  [ %o0 + 1 ]
a00cbcd4:  c0 2a 20 07  clrb  [ %o0 + 7 ]
a00cbcd8:  80 a4 20 02  cmp  %l0, 2
a00cbcdc:  02 80 00 31  be  0xa00cbda0
a00cbce0:  c0 2a 20 0a  clrb  [ %o0 + 0xa ]
a00cbce4:  80 a4 20 03  cmp  %l0, 3
a00cbce8:  12 80 00 31  bne  0xa00cbdac
a00cbcec:  90 10 00 10  mov  %l0, %o0
a00cbcf0:  10 80 00 4a  b  0xa00cbe18
a00cbcf4:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00cbcf8:  82 0a e0 ff  and  %o3, 0xff, %g1
a00cbcfc:  80 a0 60 09  cmp  %g1, 9
a00cbd00:  38 bf ff c6  bgu,a   0xa00cbc18
a00cbd04:  94 03 7f ec  add  %o5, -20, %o2
a00cbd08:  90 0b 20 ff  and  %o4, 0xff, %o0
a00cbd0c:  83 2a 20 02  sll  %o0, 2, %g1
a00cbd10:  b0 0a a0 ff  and  %o2, 0xff, %i0
a00cbd14:  9e 00 40 08  add  %g1, %o0, %o7
a00cbd18:  92 5e 20 64  smul  %i0, 0x64, %o1
a00cbd1c:  9a 03 c0 0f  add  %o7, %o7, %o5
a00cbd20:  90 02 40 0d  add  %o1, %o5, %o0
a00cbd24:  98 0a e0 ff  and  %o3, 0xff, %o4
a00cbd28:  94 02 00 0c  add  %o0, %o4, %o2
a00cbd2c:  9a 0a a0 ff  and  %o2, 0xff, %o5
a00cbd30:  94 03 7f ec  add  %o5, -20, %o2
a00cbd34:  96 0a a0 ff  and  %o2, 0xff, %o3
a00cbd38:  80 a2 e0 50  cmp  %o3, 0x50
a00cbd3c:  08 bf ff bb  bleu  0xa00cbc28
a00cbd40:  b0 10 20 ff  mov  0xff, %i0
a00cbd44:  30 80 00 38  b,a   0xa00cbe24
a00cbd48:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00cbd4c:  a0 16 21 28  or  %i0, 0x128, %l0	! 0xa802d128
a00cbd50:  98 10 20 30  mov  0x30, %o4
a00cbd54:  90 10 20 35  mov  0x35, %o0
a00cbd58:  9e 10 20 0d  mov  0xd, %o7
a00cbd5c:  9a 10 20 36  mov  0x36, %o5
a00cbd60:  92 10 20 2b  mov  0x2b, %o1
a00cbd64:  d0 2e 21 28  stb  %o0, [ %i0 + 0x128 ]
a00cbd68:  de 2c 20 05  stb  %o7, [ %l0 + 5 ]
a00cbd6c:  da 2c 20 01  stb  %o5, [ %l0 + 1 ]
a00cbd70:  d8 2c 20 03  stb  %o4, [ %l0 + 3 ]
a00cbd74:  d2 2c 20 04  stb  %o1, [ %l0 + 4 ]
a00cbd78:  d8 2c 20 02  stb  %o4, [ %l0 + 2 ]
a00cbd7c:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00cbd80:  a0 12 a0 40  or  %o2, 0x40, %l0	! 0xa802d040
a00cbd84:  13 2a 00 ac  sethi  %hi(0xa802b000), %o1
a00cbd88:  c0 2a 60 9a  clrb  [ %o1 + 0x9a ]	! 0xa802b09a
a00cbd8c:  c0 2a a0 40  clrb  [ %o2 + 0x40 ]
a00cbd90:  c0 2c 20 19  clrb  [ %l0 + 0x19 ]
a00cbd94:  c0 2c 20 01  clrb  [ %l0 + 1 ]
a00cbd98:  c0 2c 20 07  clrb  [ %l0 + 7 ]
a00cbd9c:  c0 2c 20 0a  clrb  [ %l0 + 0xa ]
a00cbda0:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00cbda4:  94 10 61 28  or  %g1, 0x128, %o2	! 0xa802d128
a00cbda8:  90 10 20 02  mov  2, %o0
a00cbdac:  40 01 f2 8f  call  0xa01487e8
a00cbdb0:  92 10 20 06  mov  6, %o1
a00cbdb4:  10 80 00 1c  b  0xa00cbe24
a00cbdb8:  b0 10 20 00  clr  %i0
a00cbdbc:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00cbdc0:  a0 12 61 08  or  %o1, 0x108, %l0	! 0xa802d108
a00cbdc4:  94 10 20 30  mov  0x30, %o2
a00cbdc8:  9a 10 20 35  mov  0x35, %o5
a00cbdcc:  98 10 20 0d  mov  0xd, %o4
a00cbdd0:  82 10 20 36  mov  0x36, %g1
a00cbdd4:  96 10 20 2b  mov  0x2b, %o3
a00cbdd8:  da 2a 61 08  stb  %o5, [ %o1 + 0x108 ]
a00cbddc:  d8 2c 20 05  stb  %o4, [ %l0 + 5 ]
a00cbde0:  c2 2c 20 01  stb  %g1, [ %l0 + 1 ]
a00cbde4:  d4 2c 20 03  stb  %o2, [ %l0 + 3 ]
a00cbde8:  d6 2c 20 04  stb  %o3, [ %l0 + 4 ]
a00cbdec:  d4 2c 20 02  stb  %o2, [ %l0 + 2 ]
a00cbdf0:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00cbdf4:  9a 13 e0 98  or  %o7, 0x98, %o5	! 0xa802d098
a00cbdf8:  31 2a 00 ac  sethi  %hi(0xa802b000), %i0
a00cbdfc:  c0 2e 20 98  clrb  [ %i0 + 0x98 ]	! 0xa802b098
a00cbe00:  c0 2b e0 98  clrb  [ %o7 + 0x98 ]
a00cbe04:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00cbe08:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00cbe0c:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00cbe10:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00cbe14:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00cbe18:  94 14 21 08  or  %l0, 0x108, %o2	! 0xa802d108
a00cbe1c:  10 bf ff e4  b  0xa00cbdac
a00cbe20:  90 10 20 03  mov  3, %o0
a00cbe24:  81 c7 e0 08  ret
a00cbe28:  81 e8 00 00  restore
