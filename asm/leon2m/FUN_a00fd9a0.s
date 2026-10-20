# leon2m FUN_a00fd9a0 0xa00fd9a0-0xa00fde94 (1268 bytes)
a00fd9a0:  9d e3 be d8  save  %sp, -296, %sp
a00fd9a4:  13 00 06 69  sethi  %hi(0x19a400), %o1
a00fd9a8:  92 12 60 fb  or  %o1, 0xfb, %o1	! 0x19a4fb
a00fd9ac:  90 07 bf 38  add  %fp, -200, %o0
a00fd9b0:  40 00 fb d8  call  0xa013c910
a00fd9b4:  94 10 20 c0  mov  0xc0, %o2
a00fd9b8:  a4 0e 60 ff  and  %i1, 0xff, %l2
a00fd9bc:  80 a4 a0 71  cmp  %l2, 0x71
a00fd9c0:  02 80 00 d5  be  0xa00fdd14
a00fd9c4:  82 10 20 00  clr  %g1
a00fd9c8:  80 a4 a0 71  cmp  %l2, 0x71
a00fd9cc:  14 80 00 c6  bg  0xa00fdce4
a00fd9d0:  80 a4 a0 b1  cmp  %l2, 0xb1
a00fd9d4:  80 a4 a0 21  cmp  %l2, 0x21
a00fd9d8:  02 80 01 12  be  0xa00fde20
a00fd9dc:  a2 0e 20 ff  and  %i0, 0xff, %l1
a00fd9e0:  14 80 00 e2  bg  0xa00fdd68
a00fd9e4:  80 a4 a0 41  cmp  %l2, 0x41
a00fd9e8:  80 a4 a0 12  cmp  %l2, 0x12
a00fd9ec:  22 80 00 09  be,a   0xa00fda10
a00fd9f0:  82 10 20 01  mov  1, %g1
a00fd9f4:  04 80 00 08  ble  0xa00fda14
a00fd9f8:  a6 08 60 ff  and  %g1, 0xff, %l3
a00fd9fc:  80 a4 a0 13  cmp  %l2, 0x13
a00fda00:  12 80 00 05  bne  0xa00fda14
a00fda04:  01 00 00 00  nop
a00fda08:  82 10 20 02  mov  2, %g1	! 0x2
a00fda0c:  a2 0e 20 ff  and  %i0, 0xff, %l1
a00fda10:  a6 08 60 ff  and  %g1, 0xff, %l3
a00fda14:  9f 2c e0 04  sll  %l3, 4, %o7
a00fda18:  a8 07 bf f8  add  %fp, -8, %l4
a00fda1c:  a0 03 c0 14  add  %o7, %l4, %l0
a00fda20:  90 10 00 11  mov  %l1, %o0
a00fda24:  d4 0c 3f 40  ldub  [ %l0 + -192 ], %o2
a00fda28:  7f ff d1 6e  call  0xa00f1fe0
a00fda2c:  92 10 20 00  clr  %o1
a00fda30:  98 06 7f ef  add  %i1, -17, %o4
a00fda34:  96 0b 20 ff  and  %o4, 0xff, %o3
a00fda38:  80 a2 e0 03  cmp  %o3, 3
a00fda3c:  90 60 20 00  subx  %g0, 0, %o0
a00fda40:  94 1c a0 21  xor  %l2, 0x21, %o2
a00fda44:  80 a0 00 0a  cmp  %g0, %o2
a00fda48:  9a 0a 20 01  and  %o0, 1, %o5
a00fda4c:  82 60 3f ff  subx  %g0, -1, %g1
a00fda50:  80 93 40 01  orcc  %o5, %g1, %g0
a00fda54:  02 80 00 30  be  0xa00fdb14
a00fda58:  97 2c e0 04  sll  %l3, 4, %o3
a00fda5c:  17 33 c0 80  sethi  %hi(0xcf020000), %o3
a00fda60:  da 0c 3f 41  ldub  [ %l0 + -191 ], %o5
a00fda64:  82 12 e1 14  or  %o3, 0x114, %g1
a00fda68:  da 20 40 00  st  %o5, [ %g1 ]
a00fda6c:  d2 00 40 00  ld  [ %g1 ], %o1
a00fda70:  a0 0a 60 07  and  %o1, 7, %l0
a00fda74:  80 a4 20 05  cmp  %l0, 5
a00fda78:  02 80 00 d9  be  0xa00fdddc
a00fda7c:  98 12 e0 88  or  %o3, 0x88, %o4
a00fda80:  c0 23 00 00  clr  [ %o4 ]
a00fda84:  93 2c e0 04  sll  %l3, 4, %o1
a00fda88:  90 02 40 14  add  %o1, %l4, %o0
a00fda8c:  13 33 c0 80  sethi  %hi(0xcf020000), %o1
a00fda90:  94 12 60 cc  or  %o1, 0xcc, %o2	! 0xcf0200cc
a00fda94:  c2 0a 3f 42  ldub  [ %o0 + -190 ], %g1
a00fda98:  9e 1c a0 13  xor  %l2, 0x13, %o7
a00fda9c:  c2 22 80 00  st  %g1, [ %o2 ]
a00fdaa0:  80 a0 00 0f  cmp  %g0, %o7
a00fdaa4:  d8 02 80 00  ld  [ %o2 ], %o4
a00fdaa8:  9e 60 3f ff  subx  %g0, -1, %o7
a00fdaac:  a0 1c a0 21  xor  %l2, 0x21, %l0
a00fdab0:  80 a0 00 10  cmp  %g0, %l0
a00fdab4:  9a 13 20 01  or  %o4, 1, %o5
a00fdab8:  da 22 80 00  st  %o5, [ %o2 ]
a00fdabc:  c2 0a 3f 43  ldub  [ %o0 + -189 ], %g1
a00fdac0:  96 60 3f ff  subx  %g0, -1, %o3
a00fdac4:  a0 12 60 d0  or  %o1, 0xd0, %l0
a00fdac8:  c2 24 00 00  st  %g1, [ %l0 ]
a00fdacc:  80 93 c0 0b  orcc  %o7, %o3, %g0
a00fdad0:  02 80 00 9d  be  0xa00fdd44
a00fdad4:  98 12 61 34  or  %o1, 0x134, %o4
a00fdad8:  96 12 61 34  or  %o1, 0x134, %o3
a00fdadc:  82 10 20 d0  mov  0xd0, %g1
a00fdae0:  c2 22 c0 00  st  %g1, [ %o3 ]
a00fdae4:  a0 12 61 38  or  %o1, 0x138, %l0
a00fdae8:  9e 10 20 02  mov  2, %o7
a00fdaec:  de 24 00 00  st  %o7, [ %l0 ]
a00fdaf0:  9a 10 20 80  mov  0x80, %o5
a00fdaf4:  98 12 61 3c  or  %o1, 0x13c, %o4
a00fdaf8:  da 23 00 00  st  %o5, [ %o4 ]
a00fdafc:  94 12 61 40  or  %o1, 0x140, %o2
a00fdb00:  da 22 80 00  st  %o5, [ %o2 ]
a00fdb04:  96 12 61 44  or  %o1, 0x144, %o3
a00fdb08:  90 10 20 40  mov  0x40, %o0
a00fdb0c:  d0 22 c0 00  st  %o0, [ %o3 ]
a00fdb10:  97 2c e0 04  sll  %l3, 4, %o3
a00fdb14:  9e 02 c0 14  add  %o3, %l4, %o7
a00fdb18:  92 10 20 00  clr  %o1
a00fdb1c:  d4 0b ff 44  ldub  [ %o7 + -188 ], %o2
a00fdb20:  7f ff cf ed  call  0xa00f1ad4
a00fdb24:  90 10 00 11  mov  %l1, %o0
a00fdb28:  b0 06 3f fa  add  %i0, -6, %i0
a00fdb2c:  92 0e 20 ff  and  %i0, 0xff, %o1
a00fdb30:  80 a2 60 01  cmp  %o1, 1
a00fdb34:  38 80 00 0b  bgu,a   0xa00fdb60
a00fdb38:  91 2c e0 04  sll  %l3, 4, %o0
a00fdb3c:  80 a4 e0 03  cmp  %l3, 3
a00fdb40:  18 80 00 7d  bgu  0xa00fdd34
a00fdb44:  90 10 00 11  mov  %l1, %o0
a00fdb48:  92 10 20 00  clr  %o1
a00fdb4c:  94 10 20 80  mov  0x80, %o2
a00fdb50:  96 10 20 01  mov  1, %o3
a00fdb54:  7f ff d0 02  call  0xa00f1b5c
a00fdb58:  01 00 00 00  nop
a00fdb5c:  91 2c e0 04  sll  %l3, 4, %o0
a00fdb60:  a0 02 00 14  add  %o0, %l4, %l0
a00fdb64:  d4 0c 3f 45  ldub  [ %l0 + -187 ], %o2
a00fdb68:  90 10 00 11  mov  %l1, %o0
a00fdb6c:  7f ff cf da  call  0xa00f1ad4
a00fdb70:  92 10 20 01  mov  1, %o1
a00fdb74:  92 10 20 03  mov  3, %o1
a00fdb78:  7f ff cf c6  call  0xa00f1a90
a00fdb7c:  90 10 00 11  mov  %l1, %o0
a00fdb80:  82 0a 20 01  and  %o0, 1, %g1
a00fdb84:  e8 0c 3f 46  ldub  [ %l0 + -186 ], %l4
a00fdb88:  94 10 40 14  or  %g1, %l4, %o2
a00fdb8c:  90 10 00 11  mov  %l1, %o0
a00fdb90:  7f ff cf d1  call  0xa00f1ad4
a00fdb94:  92 10 20 03  mov  3, %o1
a00fdb98:  90 10 00 11  mov  %l1, %o0
a00fdb9c:  92 10 20 05  mov  5, %o1
a00fdba0:  7f ff cf cd  call  0xa00f1ad4
a00fdba4:  d4 0c 3f 47  ldub  [ %l0 + -185 ], %o2
a00fdba8:  a6 0e 20 ff  and  %i0, 0xff, %l3
a00fdbac:  80 a4 e0 01  cmp  %l3, 1
a00fdbb0:  08 80 00 5b  bleu  0xa00fdd1c
a00fdbb4:  90 10 00 11  mov  %l1, %o0
a00fdbb8:  92 10 20 06  mov  6, %o1
a00fdbbc:  7f ff cf c6  call  0xa00f1ad4
a00fdbc0:  d4 0c 3f 48  ldub  [ %l0 + -184 ], %o2
a00fdbc4:  90 10 00 11  mov  %l1, %o0
a00fdbc8:  92 10 20 16  mov  0x16, %o1
a00fdbcc:  7f ff cf c2  call  0xa00f1ad4
a00fdbd0:  d4 0c 3f 49  ldub  [ %l0 + -183 ], %o2
a00fdbd4:  90 10 00 11  mov  %l1, %o0
a00fdbd8:  92 10 20 54  mov  0x54, %o1
a00fdbdc:  7f ff cf be  call  0xa00f1ad4
a00fdbe0:  d4 0c 3f 4a  ldub  [ %l0 + -182 ], %o2
a00fdbe4:  90 10 00 11  mov  %l1, %o0
a00fdbe8:  92 10 20 32  mov  0x32, %o1
a00fdbec:  7f ff d1 ab  call  0xa00f2298
a00fdbf0:  d4 0c 3f 4b  ldub  [ %l0 + -181 ], %o2
a00fdbf4:  90 10 00 11  mov  %l1, %o0
a00fdbf8:  d4 0c 3f 4d  ldub  [ %l0 + -179 ], %o2
a00fdbfc:  7f ff cf b6  call  0xa00f1ad4
a00fdc00:  92 10 20 56  mov  0x56, %o1
a00fdc04:  98 1c a0 71  xor  %l2, 0x71, %o4
a00fdc08:  80 a0 00 0c  cmp  %g0, %o4
a00fdc0c:  9a 60 3f ff  subx  %g0, -1, %o5
a00fdc10:  94 1c a0 81  xor  %l2, 0x81, %o2
a00fdc14:  80 a0 00 0a  cmp  %g0, %o2
a00fdc18:  b0 60 3f ff  subx  %g0, -1, %i0
a00fdc1c:  90 10 00 11  mov  %l1, %o0
a00fdc20:  92 10 20 01  mov  1, %o1
a00fdc24:  80 93 40 18  orcc  %o5, %i0, %g0
a00fdc28:  12 80 00 05  bne  0xa00fdc3c
a00fdc2c:  94 10 20 08  mov  8, %o2
a00fdc30:  90 10 00 11  mov  %l1, %o0
a00fdc34:  92 10 20 01  mov  1, %o1
a00fdc38:  94 10 20 04  mov  4, %o2
a00fdc3c:  40 00 8b 03  call  0xa0120848
a00fdc40:  01 00 00 00  nop
a00fdc44:  96 1c a0 31  xor  %l2, 0x31, %o3
a00fdc48:  80 a0 00 0b  cmp  %g0, %o3
a00fdc4c:  92 60 3f ff  subx  %g0, -1, %o1
a00fdc50:  9e 1c a0 41  xor  %l2, 0x41, %o7
a00fdc54:  80 a0 00 0f  cmp  %g0, %o7
a00fdc58:  a0 60 3f ff  subx  %g0, -1, %l0
a00fdc5c:  80 92 40 10  orcc  %o1, %l0, %g0
a00fdc60:  12 80 00 1b  bne  0xa00fdccc
a00fdc64:  82 1c a0 61  xor  %l2, 0x61, %g1
a00fdc68:  90 1c a0 51  xor  %l2, 0x51, %o0
a00fdc6c:  80 a0 00 08  cmp  %g0, %o0
a00fdc70:  a8 60 3f ff  subx  %g0, -1, %l4
a00fdc74:  80 a0 00 01  cmp  %g0, %g1
a00fdc78:  a6 60 3f ff  subx  %g0, -1, %l3
a00fdc7c:  80 95 00 13  orcc  %l4, %l3, %g0
a00fdc80:  32 80 00 14  bne,a   0xa00fdcd0
a00fdc84:  90 10 00 11  mov  %l1, %o0
a00fdc88:  98 1c a0 71  xor  %l2, 0x71, %o4
a00fdc8c:  80 a0 00 0c  cmp  %g0, %o4
a00fdc90:  9a 60 3f ff  subx  %g0, -1, %o5
a00fdc94:  94 1c a0 81  xor  %l2, 0x81, %o2
a00fdc98:  80 a0 00 0a  cmp  %g0, %o2
a00fdc9c:  b0 60 3f ff  subx  %g0, -1, %i0
a00fdca0:  80 93 40 18  orcc  %o5, %i0, %g0
a00fdca4:  12 80 00 4b  bne  0xa00fddd0
a00fdca8:  80 a4 a0 91  cmp  %l2, 0x91
a00fdcac:  02 80 00 42  be  0xa00fddb4
a00fdcb0:  a0 06 60 1f  add  %i1, 0x1f, %l0
a00fdcb4:  b2 0c 20 ff  and  %l0, 0xff, %i1
a00fdcb8:  80 a6 60 01  cmp  %i1, 1
a00fdcbc:  08 80 00 3e  bleu  0xa00fddb4
a00fdcc0:  80 a4 a0 b1  cmp  %l2, 0xb1
a00fdcc4:  22 80 00 44  be,a   0xa00fddd4
a00fdcc8:  90 10 00 11  mov  %l1, %o0
a00fdccc:  90 10 00 11  mov  %l1, %o0
a00fdcd0:  40 00 8f b2  call  0xa0121b98
a00fdcd4:  92 10 20 00  clr  %o1
a00fdcd8:  90 10 00 11  mov  %l1, %o0
a00fdcdc:  10 80 00 63  b  0xa00fde68
a00fdce0:  92 10 20 00  clr  %o1
a00fdce4:  02 80 00 43  be  0xa00fddf0
a00fdce8:  80 a4 a0 b1  cmp  %l2, 0xb1
a00fdcec:  14 80 00 28  bg  0xa00fdd8c
a00fdcf0:  80 a4 a0 e2  cmp  %l2, 0xe2
a00fdcf4:  80 a4 a0 91  cmp  %l2, 0x91
a00fdcf8:  22 bf ff 45  be,a   0xa00fda0c
a00fdcfc:  82 10 20 08  mov  8, %g1
a00fdd00:  14 80 00 56  bg  0xa00fde58
a00fdd04:  80 a4 a0 a1  cmp  %l2, 0xa1
a00fdd08:  80 a4 a0 81  cmp  %l2, 0x81
a00fdd0c:  12 bf ff 41  bne  0xa00fda10
a00fdd10:  a2 0e 20 ff  and  %i0, 0xff, %l1
a00fdd14:  10 bf ff 3e  b  0xa00fda0c
a00fdd18:  82 10 20 06  mov  6, %g1
a00fdd1c:  92 10 20 05  mov  5, %o1
a00fdd20:  94 10 20 01  mov  1, %o2
a00fdd24:  7f ff cf 8e  call  0xa00f1b5c
a00fdd28:  96 10 20 01  mov  1, %o3
a00fdd2c:  10 bf ff a3  b  0xa00fdbb8
a00fdd30:  90 10 00 11  mov  %l1, %o0
a00fdd34:  92 10 20 00  clr  %o1
a00fdd38:  94 10 20 80  mov  0x80, %o2
a00fdd3c:  10 bf ff 86  b  0xa00fdb54
a00fdd40:  96 10 20 00  clr  %o3
a00fdd44:  a0 10 20 50  mov  0x50, %l0
a00fdd48:  e0 23 00 00  st  %l0, [ %o4 ]
a00fdd4c:  94 12 61 38  or  %o1, 0x138, %o2
a00fdd50:  9a 10 20 22  mov  0x22, %o5
a00fdd54:  da 22 80 00  st  %o5, [ %o2 ]
a00fdd58:  90 12 61 3c  or  %o1, 0x13c, %o0
a00fdd5c:  c0 22 00 00  clr  [ %o0 ]
a00fdd60:  10 bf ff 6d  b  0xa00fdb14
a00fdd64:  97 2c e0 04  sll  %l3, 4, %o3
a00fdd68:  02 80 00 07  be  0xa00fdd84
a00fdd6c:  80 a4 a0 41  cmp  %l2, 0x41
a00fdd70:  14 80 00 26  bg  0xa00fde08
a00fdd74:  80 a4 a0 51  cmp  %l2, 0x51
a00fdd78:  80 a4 a0 31  cmp  %l2, 0x31
a00fdd7c:  12 bf ff 25  bne  0xa00fda10
a00fdd80:  a2 0e 20 ff  and  %i0, 0xff, %l1
a00fdd84:  10 bf ff 22  b  0xa00fda0c
a00fdd88:  82 10 20 04  mov  4, %g1
a00fdd8c:  14 80 00 1b  bg  0xa00fddf8
a00fdd90:  80 a4 a0 e8  cmp  %l2, 0xe8
a00fdd94:  80 a4 a0 e1  cmp  %l2, 0xe1
a00fdd98:  36 bf ff 1d  bge,a   0xa00fda0c
a00fdd9c:  82 10 20 0a  mov  0xa, %g1
a00fdda0:  80 a4 a0 c1  cmp  %l2, 0xc1
a00fdda4:  12 bf ff 1b  bne  0xa00fda10
a00fdda8:  a2 0e 20 ff  and  %i0, 0xff, %l1
a00fddac:  10 bf ff 19  b  0xa00fda10
a00fddb0:  82 10 20 07  mov  7, %g1
a00fddb4:  90 10 00 11  mov  %l1, %o0
a00fddb8:  92 10 20 02  mov  2, %o1
a00fddbc:  40 00 8f 77  call  0xa0121b98
a00fddc0:  01 00 00 00  nop
a00fddc4:  90 10 00 11  mov  %l1, %o0
a00fddc8:  10 80 00 28  b  0xa00fde68
a00fddcc:  92 10 20 01  mov  1, %o1
a00fddd0:  90 10 00 11  mov  %l1, %o0
a00fddd4:  10 bf ff fa  b  0xa00fddbc
a00fddd8:  92 10 20 03  mov  3, %o1
a00fdddc:  90 12 e0 88  or  %o3, 0x88, %o0
a00fdde0:  94 10 20 a0  mov  0xa0, %o2
a00fdde4:  d4 22 00 00  st  %o2, [ %o0 ]
a00fdde8:  10 bf ff 28  b  0xa00fda88
a00fddec:  93 2c e0 04  sll  %l3, 4, %o1
a00fddf0:  10 bf ff 07  b  0xa00fda0c
a00fddf4:  82 10 20 09  mov  9, %g1
a00fddf8:  12 bf ff 06  bne  0xa00fda10
a00fddfc:  a2 0e 20 ff  and  %i0, 0xff, %l1
a00fde00:  10 bf ff 04  b  0xa00fda10
a00fde04:  82 10 20 0b  mov  0xb, %g1
a00fde08:  02 80 00 04  be  0xa00fde18
a00fde0c:  80 a4 a0 61  cmp  %l2, 0x61
a00fde10:  12 bf ff 00  bne  0xa00fda10
a00fde14:  a2 0e 20 ff  and  %i0, 0xff, %l1
a00fde18:  10 bf fe fd  b  0xa00fda0c
a00fde1c:  82 10 20 05  mov  5, %g1
a00fde20:  92 10 20 01  mov  1, %o1
a00fde24:  94 10 20 40  mov  0x40, %o2
a00fde28:  96 10 20 01  mov  1, %o3
a00fde2c:  7f ff cf 4c  call  0xa00f1b5c
a00fde30:  90 10 00 11  mov  %l1, %o0
a00fde34:  67 fe 3c db  call  0x4008d1a0
a00fde38:  90 10 20 02  mov  2, %o0
a00fde3c:  90 10 00 11  mov  %l1, %o0
a00fde40:  92 10 20 01  mov  1, %o1
a00fde44:  94 10 20 40  mov  0x40, %o2
a00fde48:  7f ff cf 45  call  0xa00f1b5c
a00fde4c:  96 10 20 00  clr  %o3
a00fde50:  10 bf fe f0  b  0xa00fda10
a00fde54:  82 10 20 03  mov  3, %g1
a00fde58:  12 bf fe ee  bne  0xa00fda10
a00fde5c:  a2 0e 20 ff  and  %i0, 0xff, %l1
a00fde60:  10 bf fe ec  b  0xa00fda10
a00fde64:  82 10 20 08  mov  8, %g1
a00fde68:  40 00 8f 3a  call  0xa0121b50
a00fde6c:  01 00 00 00  nop
a00fde70:  92 1c a0 e8  xor  %l2, 0xe8, %o1
a00fde74:  80 a0 00 09  cmp  %g0, %o1
a00fde78:  90 10 00 11  mov  %l1, %o0
a00fde7c:  94 60 3f ff  subx  %g0, -1, %o2
a00fde80:  7f ff ec af  call  0xa00f913c
a00fde84:  92 10 20 15  mov  0x15, %o1
a00fde88:  01 00 00 00  nop
a00fde8c:  81 c7 e0 08  ret
a00fde90:  81 e8 00 00  restore
