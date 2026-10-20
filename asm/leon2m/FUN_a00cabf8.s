# leon2m FUN_a00cabf8 0xa00cabf8-0xa00cadd4 (476 bytes)
a00cabf8:  9d e3 bf 98  save  %sp, -104, %sp
a00cabfc:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00cac00:  80 a4 20 02  cmp  %l0, 2
a00cac04:  02 80 00 52  be  0xa00cad4c
a00cac08:  80 a4 20 03  cmp  %l0, 3
a00cac0c:  02 80 00 53  be  0xa00cad58
a00cac10:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00cac14:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00cac18:  94 08 60 ff  and  %g1, 0xff, %o2
a00cac1c:  98 02 bf d0  add  %o2, -48, %o4
a00cac20:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00cac24:  80 a3 60 06  cmp  %o5, 6
a00cac28:  18 80 00 69  bgu  0xa00cadcc
a00cac2c:  b0 10 20 ff  mov  0xff, %i0
a00cac30:  17 2a 00 b5  sethi  %hi(0xa802d400), %o3
a00cac34:  40 00 3f bb  call  0xa00dab20
a00cac38:  d8 2a e0 6f  stb  %o4, [ %o3 + 0x6f ]	! 0xa802d46f
a00cac3c:  7f ff b7 24  call  0xa00b88cc
a00cac40:  01 00 00 00  nop
a00cac44:  80 a4 20 02  cmp  %l0, 2
a00cac48:  02 80 00 24  be  0xa00cacd8
a00cac4c:  80 a4 20 03  cmp  %l0, 3
a00cac50:  02 80 00 45  be  0xa00cad64
a00cac54:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00cac58:  94 13 60 78  or  %o5, 0x78, %o2	! 0xa802d078
a00cac5c:  90 10 20 30  mov  0x30, %o0
a00cac60:  96 10 20 35  mov  0x35, %o3
a00cac64:  98 10 20 36  mov  0x36, %o4
a00cac68:  92 10 20 2b  mov  0x2b, %o1
a00cac6c:  82 10 20 0d  mov  0xd, %g1
a00cac70:  d6 2b 60 78  stb  %o3, [ %o5 + 0x78 ]
a00cac74:  d8 2a a0 01  stb  %o4, [ %o2 + 1 ]
a00cac78:  d0 2a a0 03  stb  %o0, [ %o2 + 3 ]
a00cac7c:  d2 2a a0 04  stb  %o1, [ %o2 + 4 ]
a00cac80:  c2 2a a0 05  stb  %g1, [ %o2 + 5 ]
a00cac84:  80 a4 20 02  cmp  %l0, 2
a00cac88:  02 80 00 21  be  0xa00cad0c
a00cac8c:  d0 2a a0 02  stb  %o0, [ %o2 + 2 ]
a00cac90:  80 a4 20 03  cmp  %l0, 3
a00cac94:  02 80 00 41  be  0xa00cad98
a00cac98:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00cac9c:  92 13 20 d0  or  %o4, 0xd0, %o1	! 0xa802d0d0
a00caca0:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00caca4:  c0 2b 60 9c  clrb  [ %o5 + 0x9c ]	! 0xa802b09c
a00caca8:  c0 2b 20 d0  clrb  [ %o4 + 0xd0 ]
a00cacac:  c0 2a 60 19  clrb  [ %o1 + 0x19 ]
a00cacb0:  c0 2a 60 01  clrb  [ %o1 + 1 ]
a00cacb4:  c0 2a 60 07  clrb  [ %o1 + 7 ]
a00cacb8:  80 a4 20 02  cmp  %l0, 2
a00cacbc:  02 80 00 1d  be  0xa00cad30
a00cacc0:  c0 2a 60 0a  clrb  [ %o1 + 0xa ]
a00cacc4:  80 a4 20 03  cmp  %l0, 3
a00cacc8:  12 80 00 1d  bne  0xa00cad3c
a00caccc:  90 10 00 10  mov  %l0, %o0
a00cacd0:  10 80 00 3c  b  0xa00cadc0
a00cacd4:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00cacd8:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00cacdc:  98 12 21 28  or  %o0, 0x128, %o4	! 0xa802d128
a00cace0:  9e 10 20 30  mov  0x30, %o7
a00cace4:  92 10 20 35  mov  0x35, %o1
a00cace8:  82 10 20 0d  mov  0xd, %g1
a00cacec:  b0 10 20 36  mov  0x36, %i0
a00cacf0:  a0 10 20 2b  mov  0x2b, %l0
a00cacf4:  d2 2a 21 28  stb  %o1, [ %o0 + 0x128 ]
a00cacf8:  c2 2b 20 05  stb  %g1, [ %o4 + 5 ]
a00cacfc:  f0 2b 20 01  stb  %i0, [ %o4 + 1 ]
a00cad00:  de 2b 20 03  stb  %o7, [ %o4 + 3 ]
a00cad04:  e0 2b 20 04  stb  %l0, [ %o4 + 4 ]
a00cad08:  de 2b 20 02  stb  %o7, [ %o4 + 2 ]
a00cad0c:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00cad10:  94 13 e0 40  or  %o7, 0x40, %o2	! 0xa802d040
a00cad14:  21 2a 00 ac  sethi  %hi(0xa802b000), %l0
a00cad18:  c0 2c 20 9a  clrb  [ %l0 + 0x9a ]	! 0xa802b09a
a00cad1c:  c0 2b e0 40  clrb  [ %o7 + 0x40 ]
a00cad20:  c0 2a a0 19  clrb  [ %o2 + 0x19 ]
a00cad24:  c0 2a a0 01  clrb  [ %o2 + 1 ]
a00cad28:  c0 2a a0 07  clrb  [ %o2 + 7 ]
a00cad2c:  c0 2a a0 0a  clrb  [ %o2 + 0xa ]
a00cad30:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00cad34:  94 12 e1 28  or  %o3, 0x128, %o2	! 0xa802d128
a00cad38:  90 10 20 02  mov  2, %o0
a00cad3c:  40 01 f6 ab  call  0xa01487e8
a00cad40:  92 10 20 06  mov  6, %o1
a00cad44:  10 80 00 22  b  0xa00cadcc
a00cad48:  b0 10 20 00  clr  %i0
a00cad4c:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00cad50:  10 bf ff b2  b  0xa00cac18
a00cad54:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00cad58:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00cad5c:  10 bf ff af  b  0xa00cac18
a00cad60:  c2 0a 20 a1  ldub  [ %o0 + 0xa1 ], %g1	! 0xa802d0a1
a00cad64:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00cad68:  98 14 21 08  or  %l0, 0x108, %o4	! 0xa802d108
a00cad6c:  94 10 20 30  mov  0x30, %o2
a00cad70:  b0 10 20 35  mov  0x35, %i0
a00cad74:  9e 10 20 0d  mov  0xd, %o7
a00cad78:  96 10 20 36  mov  0x36, %o3
a00cad7c:  9a 10 20 2b  mov  0x2b, %o5
a00cad80:  f0 2c 21 08  stb  %i0, [ %l0 + 0x108 ]
a00cad84:  de 2b 20 05  stb  %o7, [ %o4 + 5 ]
a00cad88:  d6 2b 20 01  stb  %o3, [ %o4 + 1 ]
a00cad8c:  d4 2b 20 03  stb  %o2, [ %o4 + 3 ]
a00cad90:  da 2b 20 04  stb  %o5, [ %o4 + 4 ]
a00cad94:  d4 2b 20 02  stb  %o2, [ %o4 + 2 ]
a00cad98:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00cad9c:  b0 12 20 98  or  %o0, 0x98, %i0	! 0xa802d098
a00cada0:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00cada4:  c0 28 60 98  clrb  [ %g1 + 0x98 ]	! 0xa802b098
a00cada8:  c0 2a 20 98  clrb  [ %o0 + 0x98 ]
a00cadac:  c0 2e 20 19  clrb  [ %i0 + 0x19 ]
a00cadb0:  c0 2e 20 01  clrb  [ %i0 + 1 ]
a00cadb4:  c0 2e 20 07  clrb  [ %i0 + 7 ]
a00cadb8:  c0 2e 20 0a  clrb  [ %i0 + 0xa ]
a00cadbc:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00cadc0:  94 12 a1 08  or  %o2, 0x108, %o2	! 0xa802d108
a00cadc4:  10 bf ff de  b  0xa00cad3c
a00cadc8:  90 10 20 03  mov  3, %o0
a00cadcc:  81 c7 e0 08  ret
a00cadd0:  81 e8 00 00  restore
