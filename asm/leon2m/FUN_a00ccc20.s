# leon2m FUN_a00ccc20 0xa00ccc20-0xa00cce80 (608 bytes)
a00ccc20:  9d e3 bf 98  save  %sp, -104, %sp
a00ccc24:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00ccc28:  9a 14 62 90  or  %l1, 0x290, %o5	! 0xa802d290
a00ccc2c:  c2 0b 60 11  ldub  [ %o5 + 0x11 ], %g1
a00ccc30:  80 a0 60 03  cmp  %g1, 3
a00ccc34:  02 80 00 04  be  0xa00ccc44
a00ccc38:  90 10 20 03  mov  3, %o0
a00ccc3c:  40 00 32 ca  call  0xa00d9764
a00ccc40:  d0 2b 60 11  stb  %o0, [ %o5 + 0x11 ]
a00ccc44:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00ccc48:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00ccc4c:  80 a4 20 02  cmp  %l0, 2
a00ccc50:  02 80 00 08  be  0xa00ccc70
a00ccc54:  82 12 60 40  or  %o1, 0x40, %g1
a00ccc58:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00ccc5c:  80 a4 20 03  cmp  %l0, 3
a00ccc60:  02 80 00 04  be  0xa00ccc70
a00ccc64:  82 12 a0 98  or  %o2, 0x98, %g1
a00ccc68:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00ccc6c:  82 12 e0 d0  or  %o3, 0xd0, %g1	! 0xa802d0d0
a00ccc70:  de 08 60 07  ldub  [ %g1 + 7 ], %o7
a00ccc74:  94 03 ff d0  add  %o7, -48, %o2
a00ccc78:  9a 0a a0 ff  and  %o2, 0xff, %o5
a00ccc7c:  80 a3 60 01  cmp  %o5, 1
a00ccc80:  d6 08 60 09  ldub  [ %g1 + 9 ], %o3
a00ccc84:  d8 08 60 08  ldub  [ %g1 + 8 ], %o4
a00ccc88:  18 80 00 07  bgu  0xa00ccca4
a00ccc8c:  9a 10 20 ff  mov  0xff, %o5
a00ccc90:  98 03 3f d0  add  %o4, -48, %o4
a00ccc94:  b0 0b 20 ff  and  %o4, 0xff, %i0
a00ccc98:  80 a6 20 09  cmp  %i0, 9
a00ccc9c:  28 80 00 31  bleu,a   0xa00ccd60
a00ccca0:  96 02 ff d0  add  %o3, -48, %o3
a00ccca4:  80 a3 60 ff  cmp  %o5, 0xff
a00ccca8:  02 80 00 74  be  0xa00cce78
a00cccac:  b0 10 20 ff  mov  0xff, %i0
a00cccb0:  80 a3 60 64  cmp  %o5, 0x64
a00cccb4:  18 80 00 71  bgu  0xa00cce78
a00cccb8:  96 14 62 90  or  %l1, 0x290, %o3
a00cccbc:  40 00 32 9c  call  0xa00d972c
a00cccc0:  da 2a e0 14  stb  %o5, [ %o3 + 0x14 ]
a00cccc4:  7f ff af 02  call  0xa00b88cc
a00cccc8:  01 00 00 00  nop
a00ccccc:  80 a4 20 02  cmp  %l0, 2
a00cccd0:  02 80 00 33  be  0xa00ccd9c
a00cccd4:  80 a4 20 03  cmp  %l0, 3
a00cccd8:  02 80 00 4e  be  0xa00cce10
a00cccdc:  9e 10 20 30  mov  0x30, %o7
a00ccce0:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00ccce4:  94 12 20 78  or  %o0, 0x78, %o2	! 0xa802d078
a00ccce8:  82 10 20 35  mov  0x35, %g1
a00cccec:  b0 10 20 36  mov  0x36, %i0
a00cccf0:  9a 10 20 2b  mov  0x2b, %o5
a00cccf4:  98 10 20 0d  mov  0xd, %o4
a00cccf8:  c2 2a 20 78  stb  %g1, [ %o0 + 0x78 ]
a00cccfc:  f0 2a a0 01  stb  %i0, [ %o2 + 1 ]
a00ccd00:  de 2a a0 03  stb  %o7, [ %o2 + 3 ]
a00ccd04:  da 2a a0 04  stb  %o5, [ %o2 + 4 ]
a00ccd08:  d8 2a a0 05  stb  %o4, [ %o2 + 5 ]
a00ccd0c:  80 a4 20 02  cmp  %l0, 2
a00ccd10:  02 80 00 30  be  0xa00ccdd0
a00ccd14:  de 2a a0 02  stb  %o7, [ %o2 + 2 ]
a00ccd18:  80 a4 20 03  cmp  %l0, 3
a00ccd1c:  02 80 00 4a  be  0xa00cce44
a00ccd20:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00ccd24:  9a 13 20 d0  or  %o4, 0xd0, %o5	! 0xa802d0d0
a00ccd28:  31 2a 00 ac  sethi  %hi(0xa802b000), %i0
a00ccd2c:  c0 2e 20 9c  clrb  [ %i0 + 0x9c ]	! 0xa802b09c
a00ccd30:  c0 2b 20 d0  clrb  [ %o4 + 0xd0 ]
a00ccd34:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00ccd38:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00ccd3c:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00ccd40:  80 a4 20 02  cmp  %l0, 2
a00ccd44:  02 80 00 2c  be  0xa00ccdf4
a00ccd48:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00ccd4c:  80 a4 20 03  cmp  %l0, 3
a00ccd50:  12 80 00 2c  bne  0xa00cce00
a00ccd54:  90 10 00 10  mov  %l0, %o0
a00ccd58:  10 80 00 45  b  0xa00cce6c
a00ccd5c:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00ccd60:  82 0a e0 ff  and  %o3, 0xff, %g1
a00ccd64:  80 a0 60 09  cmp  %g1, 9
a00ccd68:  18 bf ff d0  bgu  0xa00ccca8
a00ccd6c:  80 a3 60 ff  cmp  %o5, 0xff
a00ccd70:  90 0b 20 ff  and  %o4, 0xff, %o0
a00ccd74:  83 2a 20 02  sll  %o0, 2, %g1
a00ccd78:  9e 00 40 08  add  %g1, %o0, %o7
a00ccd7c:  b0 0a a0 ff  and  %o2, 0xff, %i0
a00ccd80:  9a 03 c0 0f  add  %o7, %o7, %o5
a00ccd84:  94 5e 20 64  smul  %i0, 0x64, %o2
a00ccd88:  92 02 80 0d  add  %o2, %o5, %o1
a00ccd8c:  98 0a e0 ff  and  %o3, 0xff, %o4
a00ccd90:  90 02 40 0c  add  %o1, %o4, %o0
a00ccd94:  10 bf ff c4  b  0xa00ccca4
a00ccd98:  9a 0a 20 ff  and  %o0, 0xff, %o5
a00ccd9c:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00ccda0:  a0 13 61 28  or  %o5, 0x128, %l0	! 0xa802d128
a00ccda4:  a2 10 20 30  mov  0x30, %l1
a00ccda8:  9e 10 20 35  mov  0x35, %o7
a00ccdac:  94 10 20 0d  mov  0xd, %o2
a00ccdb0:  98 10 20 36  mov  0x36, %o4
a00ccdb4:  92 10 20 2b  mov  0x2b, %o1
a00ccdb8:  de 2b 61 28  stb  %o7, [ %o5 + 0x128 ]
a00ccdbc:  d4 2c 20 05  stb  %o2, [ %l0 + 5 ]
a00ccdc0:  d8 2c 20 01  stb  %o4, [ %l0 + 1 ]
a00ccdc4:  e2 2c 20 03  stb  %l1, [ %l0 + 3 ]
a00ccdc8:  d2 2c 20 04  stb  %o1, [ %l0 + 4 ]
a00ccdcc:  e2 2c 20 02  stb  %l1, [ %l0 + 2 ]
a00ccdd0:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00ccdd4:  94 12 e0 40  or  %o3, 0x40, %o2	! 0xa802d040
a00ccdd8:  21 2a 00 ac  sethi  %hi(0xa802b000), %l0
a00ccddc:  c0 2c 20 9a  clrb  [ %l0 + 0x9a ]	! 0xa802b09a
a00ccde0:  c0 2a e0 40  clrb  [ %o3 + 0x40 ]
a00ccde4:  c0 2a a0 19  clrb  [ %o2 + 0x19 ]
a00ccde8:  c0 2a a0 01  clrb  [ %o2 + 1 ]
a00ccdec:  c0 2a a0 07  clrb  [ %o2 + 7 ]
a00ccdf0:  c0 2a a0 0a  clrb  [ %o2 + 0xa ]
a00ccdf4:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00ccdf8:  94 12 21 28  or  %o0, 0x128, %o2	! 0xa802d128
a00ccdfc:  90 10 20 02  mov  2, %o0
a00cce00:  40 01 ee 7a  call  0xa01487e8
a00cce04:  92 10 20 06  mov  6, %o1
a00cce08:  10 80 00 1c  b  0xa00cce78
a00cce0c:  b0 10 20 00  clr  %i0
a00cce10:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00cce14:  b0 14 61 08  or  %l1, 0x108, %i0	! 0xa802d108
a00cce18:  90 10 20 30  mov  0x30, %o0
a00cce1c:  92 10 20 35  mov  0x35, %o1
a00cce20:  a0 10 20 0d  mov  0xd, %l0
a00cce24:  96 10 20 36  mov  0x36, %o3
a00cce28:  82 10 20 2b  mov  0x2b, %g1
a00cce2c:  d2 2c 61 08  stb  %o1, [ %l1 + 0x108 ]
a00cce30:  e0 2e 20 05  stb  %l0, [ %i0 + 5 ]
a00cce34:  d6 2e 20 01  stb  %o3, [ %i0 + 1 ]
a00cce38:  d0 2e 20 03  stb  %o0, [ %i0 + 3 ]
a00cce3c:  c2 2e 20 04  stb  %g1, [ %i0 + 4 ]
a00cce40:  d0 2e 20 02  stb  %o0, [ %i0 + 2 ]
a00cce44:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00cce48:  a2 12 60 98  or  %o1, 0x98, %l1	! 0xa802d098
a00cce4c:  1f 2a 00 ac  sethi  %hi(0xa802b000), %o7
a00cce50:  c0 2b e0 98  clrb  [ %o7 + 0x98 ]	! 0xa802b098
a00cce54:  c0 2a 60 98  clrb  [ %o1 + 0x98 ]
a00cce58:  c0 2c 60 19  clrb  [ %l1 + 0x19 ]
a00cce5c:  c0 2c 60 01  clrb  [ %l1 + 1 ]
a00cce60:  c0 2c 60 07  clrb  [ %l1 + 7 ]
a00cce64:  c0 2c 60 0a  clrb  [ %l1 + 0xa ]
a00cce68:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00cce6c:  94 10 61 08  or  %g1, 0x108, %o2	! 0xa802d108
a00cce70:  10 bf ff e4  b  0xa00cce00
a00cce74:  90 10 20 03  mov  3, %o0
a00cce78:  81 c7 e0 08  ret
a00cce7c:  81 e8 00 00  restore
