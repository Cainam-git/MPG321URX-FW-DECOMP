# leon2m FUN_a00acc40 0xa00acc40-0xa00acef4 (692 bytes)
a00acc40:  9d e3 bf 98  save  %sp, -104, %sp
a00acc44:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00acc48:  90 16 22 90  or  %i0, 0x290, %o0	! 0xa802d290
a00acc4c:  d6 0a 20 08  ldub  [ %o0 + 8 ], %o3
a00acc50:  80 a0 00 0b  cmp  %g0, %o3
a00acc54:  98 60 3f ff  subx  %g0, -1, %o4
a00acc58:  82 1a e0 06  xor  %o3, 6, %g1
a00acc5c:  80 a0 00 01  cmp  %g0, %g1
a00acc60:  9a 60 3f ff  subx  %g0, -1, %o5
a00acc64:  80 93 00 0d  orcc  %o4, %o5, %g0
a00acc68:  12 80 00 08  bne  0xa00acc88
a00acc6c:  92 16 22 90  or  %i0, 0x290, %o1
a00acc70:  80 a2 e0 07  cmp  %o3, 7
a00acc74:  02 80 00 05  be  0xa00acc88
a00acc78:  80 a2 e0 0a  cmp  %o3, 0xa
a00acc7c:  12 80 00 04  bne  0xa00acc8c
a00acc80:  b2 10 20 01  mov  1, %i1
a00acc84:  92 16 22 90  or  %i0, 0x290, %o1
a00acc88:  f2 0a 60 08  ldub  [ %o1 + 8 ], %i1
a00acc8c:  90 10 21 77  mov  0x177, %o0
a00acc90:  40 02 67 b0  call  0xa0146b50
a00acc94:  92 10 20 00  clr  %o1
a00acc98:  90 10 20 02  mov  2, %o0
a00acc9c:  40 02 67 b4  call  0xa0146b6c
a00acca0:  92 10 20 00  clr  %o1
a00acca4:  96 10 25 96  mov  0x596, %o3
a00acca8:  98 10 20 00  clr  %o4
a00accac:  94 10 20 06  mov  6, %o2
a00accb0:  90 10 20 22  mov  0x22, %o0
a00accb4:  40 02 67 73  call  0xa0146a80
a00accb8:  92 10 20 01  mov  1, %o1
a00accbc:  15 00 06 29  sethi  %hi(0x18a400), %o2
a00accc0:  90 12 a2 ac  or  %o2, 0x2ac, %o0	! 0x18a6ac
a00accc4:  7f ff da e0  call  0xa00a3844
a00accc8:  92 10 20 01  mov  1, %o1
a00acccc:  98 10 00 08  mov  %o0, %o4
a00accd0:  90 10 20 00  clr  %o0
a00accd4:  92 10 20 22  mov  0x22, %o1
a00accd8:  94 10 20 01  mov  1, %o2
a00accdc:  96 10 20 06  mov  6, %o3
a00acce0:  7f ff d9 31  call  0xa00a31a4
a00acce4:  9a 10 20 00  clr  %o5
a00acce8:  40 00 ac 18  call  0xa00d7d48
a00accec:  01 00 00 00  nop
a00accf0:  80 a2 20 00  cmp  %o0, 0
a00accf4:  02 80 00 55  be  0xa00ace48
a00accf8:  92 10 20 02  mov  2, %o1
a00accfc:  96 10 25 96  mov  0x596, %o3
a00acd00:  94 10 20 06  mov  6, %o2
a00acd04:  98 10 20 00  clr  %o4
a00acd08:  40 02 67 5e  call  0xa0146a80
a00acd0c:  90 10 20 22  mov  0x22, %o0
a00acd10:  9a 0e 60 ff  and  %i1, 0xff, %o5
a00acd14:  9e 03 60 1d  add  %o5, 0x1d, %o7
a00acd18:  97 2b e0 10  sll  %o7, 0x10, %o3
a00acd1c:  93 32 e0 10  srl  %o3, 0x10, %o1
a00acd20:  33 00 06 4c  sethi  %hi(0x193000), %i1
a00acd24:  7f ff da c8  call  0xa00a3844
a00acd28:  90 16 62 48  or  %i1, 0x248, %o0	! 0x193248
a00acd2c:  98 10 00 08  mov  %o0, %o4
a00acd30:  9a 10 20 00  clr  %o5
a00acd34:  90 10 20 00  clr  %o0
a00acd38:  92 10 20 22  mov  0x22, %o1
a00acd3c:  94 10 20 02  mov  2, %o2
a00acd40:  7f ff d9 19  call  0xa00a31a4
a00acd44:  96 10 20 06  mov  6, %o3
a00acd48:  90 10 20 17  mov  0x17, %o0
a00acd4c:  92 10 20 01  mov  1, %o1
a00acd50:  94 10 20 0a  mov  0xa, %o2
a00acd54:  96 10 25 96  mov  0x596, %o3
a00acd58:  40 02 67 4a  call  0xa0146a80
a00acd5c:  98 10 20 00  clr  %o4
a00acd60:  90 10 20 17  mov  0x17, %o0
a00acd64:  92 10 20 02  mov  2, %o1
a00acd68:  94 10 20 0a  mov  0xa, %o2
a00acd6c:  96 10 25 96  mov  0x596, %o3
a00acd70:  40 02 67 44  call  0xa0146a80
a00acd74:  98 10 20 00  clr  %o4
a00acd78:  90 10 20 00  clr  %o0
a00acd7c:  92 10 20 17  mov  0x17, %o1
a00acd80:  94 10 20 01  mov  1, %o2
a00acd84:  96 10 20 0a  mov  0xa, %o3
a00acd88:  98 10 20 00  clr  %o4
a00acd8c:  40 02 67 65  call  0xa0146b20
a00acd90:  9a 10 20 00  clr  %o5
a00acd94:  90 10 20 00  clr  %o0
a00acd98:  92 10 20 17  mov  0x17, %o1
a00acd9c:  94 10 20 02  mov  2, %o2
a00acda0:  96 10 20 0a  mov  0xa, %o3
a00acda4:  98 10 20 00  clr  %o4
a00acda8:  40 02 67 5e  call  0xa0146b20
a00acdac:  9a 10 20 00  clr  %o5
a00acdb0:  b2 16 22 90  or  %i0, 0x290, %i1
a00acdb4:  f0 06 60 a8  ld  [ %i1 + 0xa8 ], %i0
a00acdb8:  80 8e 28 00  btst  0x800, %i0
a00acdbc:  32 80 00 2a  bne,a   0xa00ace64
a00acdc0:  19 00 06 21  sethi  %hi(0x188400), %o4
a00acdc4:  19 00 06 23  sethi  %hi(0x188c00), %o4
a00acdc8:  d2 0e 60 08  ldub  [ %i1 + 8 ], %o1
a00acdcc:  7f ff da 9e  call  0xa00a3844
a00acdd0:  90 13 21 a0  or  %o4, 0x1a0, %o0
a00acdd4:  98 10 00 08  mov  %o0, %o4
a00acdd8:  94 10 20 01  mov  1, %o2
a00acddc:  96 10 20 0a  mov  0xa, %o3
a00acde0:  9a 10 20 00  clr  %o5
a00acde4:  90 10 20 00  clr  %o0
a00acde8:  7f ff d8 ef  call  0xa00a31a4
a00acdec:  92 10 20 17  mov  0x17, %o1
a00acdf0:  de 0e 61 82  ldub  [ %i1 + 0x182 ], %o7
a00acdf4:  b1 2b e0 03  sll  %o7, 3, %i0
a00acdf8:  9a 26 00 0f  sub  %i0, %o7, %o5
a00acdfc:  97 2b 60 02  sll  %o5, 2, %o3
a00ace00:  92 02 c0 0f  add  %o3, %o7, %o1
a00ace04:  d4 0e 60 08  ldub  [ %i1 + 8 ], %o2
a00ace08:  90 02 40 0a  add  %o1, %o2, %o0
a00ace0c:  83 2a 20 10  sll  %o0, 0x10, %g1
a00ace10:  19 00 06 57  sethi  %hi(0x195c00), %o4
a00ace14:  93 30 60 10  srl  %g1, 0x10, %o1
a00ace18:  7f ff da 8b  call  0xa00a3844
a00ace1c:  90 13 23 24  or  %o4, 0x324, %o0
a00ace20:  98 10 00 08  mov  %o0, %o4
a00ace24:  90 10 20 00  clr  %o0
a00ace28:  92 10 20 17  mov  0x17, %o1
a00ace2c:  94 10 20 02  mov  2, %o2
a00ace30:  96 10 20 0a  mov  0xa, %o3
a00ace34:  7f ff d8 dc  call  0xa00a31a4
a00ace38:  9a 10 20 00  clr  %o5
a00ace3c:  b0 10 20 00  clr  %i0
a00ace40:  40 02 67 4b  call  0xa0146b6c
a00ace44:  93 e8 20 00  restore  %g0, 0, %o1
a00ace48:  94 10 20 06  mov  6, %o2
a00ace4c:  96 10 25 96  mov  0x596, %o3
a00ace50:  98 10 20 00  clr  %o4
a00ace54:  40 02 67 0b  call  0xa0146a80
a00ace58:  90 10 20 22  mov  0x22, %o0
a00ace5c:  10 bf ff b1  b  0xa00acd20
a00ace60:  92 0e 60 ff  and  %i1, 0xff, %o1
a00ace64:  d2 0e 60 08  ldub  [ %i1 + 8 ], %o1
a00ace68:  7f ff da 77  call  0xa00a3844
a00ace6c:  90 13 22 34  or  %o4, 0x234, %o0
a00ace70:  98 10 00 08  mov  %o0, %o4
a00ace74:  94 10 20 01  mov  1, %o2
a00ace78:  96 10 20 0a  mov  0xa, %o3
a00ace7c:  9a 10 20 00  clr  %o5
a00ace80:  90 10 20 00  clr  %o0
a00ace84:  7f ff d8 c8  call  0xa00a31a4
a00ace88:  92 10 20 17  mov  0x17, %o1
a00ace8c:  92 10 20 00  clr  %o1
a00ace90:  40 00 27 3e  call  0xa00b6b88
a00ace94:  d0 0e 61 81  ldub  [ %i1 + 0x181 ], %o0
a00ace98:  9e 0a 20 ff  and  %o0, 0xff, %o7
a00ace9c:  b1 2b e0 03  sll  %o7, 3, %i0
a00acea0:  9a 26 00 0f  sub  %i0, %o7, %o5
a00acea4:  97 2b 60 02  sll  %o5, 2, %o3
a00acea8:  92 02 c0 0f  add  %o3, %o7, %o1
a00aceac:  d4 0e 60 08  ldub  [ %i1 + 8 ], %o2
a00aceb0:  90 02 40 0a  add  %o1, %o2, %o0
a00aceb4:  83 2a 20 10  sll  %o0, 0x10, %g1
a00aceb8:  33 00 06 54  sethi  %hi(0x195000), %i1
a00acebc:  93 30 60 10  srl  %g1, 0x10, %o1
a00acec0:  7f ff da 61  call  0xa00a3844
a00acec4:  90 16 61 dc  or  %i1, 0x1dc, %o0
a00acec8:  98 10 00 08  mov  %o0, %o4
a00acecc:  90 10 20 00  clr  %o0
a00aced0:  92 10 20 17  mov  0x17, %o1
a00aced4:  94 10 20 02  mov  2, %o2
a00aced8:  96 10 20 0a  mov  0xa, %o3
a00acedc:  7f ff d8 b2  call  0xa00a31a4
a00acee0:  9a 10 20 00  clr  %o5
a00acee4:  b0 10 20 00  clr  %i0
a00acee8:  40 02 67 21  call  0xa0146b6c
a00aceec:  93 e8 20 00  restore  %g0, 0, %o1
a00acef0:  01 00 00 00  nop
