# leon2m FUN_a00adaf4 0xa00adaf4-0xa00adc98 (420 bytes)
a00adaf4:  9d e3 bf 90  save  %sp, -112, %sp
a00adaf8:  67 ff 81 eb  call  0x4008e2a4
a00adafc:  a4 10 20 04  mov  4, %l2
a00adb00:  b2 10 20 04  mov  4, %i1
a00adb04:  b4 10 20 04  mov  4, %i2
a00adb08:  94 10 00 1a  mov  %i2, %o2
a00adb0c:  90 10 20 00  clr  %o0
a00adb10:  92 10 20 03  mov  3, %o1
a00adb14:  96 10 20 10  mov  0x10, %o3
a00adb18:  98 10 20 00  clr  %o4
a00adb1c:  40 02 64 01  call  0xa0146b20
a00adb20:  9a 10 20 00  clr  %o5
a00adb24:  92 10 00 1a  mov  %i2, %o1
a00adb28:  90 10 20 03  mov  3, %o0
a00adb2c:  94 10 20 10  mov  0x10, %o2
a00adb30:  96 10 27 92  mov  0x792, %o3
a00adb34:  98 10 20 00  clr  %o4
a00adb38:  40 02 63 d2  call  0xa0146a80
a00adb3c:  b2 06 60 01  inc  %i1
a00adb40:  b4 0e 60 ff  and  %i1, 0xff, %i2
a00adb44:  80 a6 a0 0b  cmp  %i2, 0xb
a00adb48:  08 bf ff f1  bleu  0xa00adb0c
a00adb4c:  94 10 00 1a  mov  %i2, %o2
a00adb50:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00adb54:  9a 14 62 90  or  %l1, 0x290, %o5	! 0xa802d290
a00adb58:  d0 0b 61 90  ldub  [ %o5 + 0x190 ], %o0
a00adb5c:  83 32 20 02  srl  %o0, 2, %g1
a00adb60:  80 a0 60 00  cmp  %g1, 0
a00adb64:  12 80 00 04  bne  0xa00adb74
a00adb68:  a0 10 20 06  mov  6, %l0
a00adb6c:  a0 10 20 00  clr  %l0
a00adb70:  a4 10 20 06  mov  6, %l2
a00adb74:  b0 0c 20 ff  and  %l0, 0xff, %i0
a00adb78:  80 a6 20 00  cmp  %i0, 0
a00adb7c:  02 80 00 34  be  0xa00adc4c
a00adb80:  90 10 20 02  mov  2, %o0
a00adb84:  80 a6 20 0c  cmp  %i0, 0xc
a00adb88:  18 80 00 1e  bgu  0xa00adc00
a00adb8c:  b4 10 00 10  mov  %l0, %i2
a00adb90:  80 a0 00 18  cmp  %g0, %i0
a00adb94:  9e 10 00 18  mov  %i0, %o7
a00adb98:  b2 60 3f ff  subx  %g0, -1, %i1
a00adb9c:  82 03 c0 0f  add  %o7, %o7, %g1
a00adba0:  92 00 60 11  add  %g1, 0x11, %o1
a00adba4:  b0 26 80 10  sub  %i2, %l0, %i0
a00adba8:  98 06 00 12  add  %i0, %l2, %o4
a00adbac:  82 0a 60 ff  and  %o1, 0xff, %g1
a00adbb0:  80 a3 e0 05  cmp  %o7, 5
a00adbb4:  98 0b 20 ff  and  %o4, 0xff, %o4
a00adbb8:  90 10 20 01  mov  1, %o0
a00adbbc:  92 10 20 01  mov  1, %o1
a00adbc0:  94 10 27 96  mov  0x796, %o2
a00adbc4:  96 10 20 0a  mov  0xa, %o3
a00adbc8:  9a 10 20 02  mov  2, %o5
a00adbcc:  b4 06 a0 01  inc  %i2
a00adbd0:  18 80 00 03  bgu  0xa00adbdc
a00adbd4:  9e 10 20 01  mov  1, %o7
a00adbd8:  9e 10 20 00  clr  %o7
a00adbdc:  80 8e 40 0f  btst  %i1, %o7
a00adbe0:  32 80 00 09  bne,a   0xa00adc04
a00adbe4:  b2 14 62 90  or  %l1, 0x290, %i1
a00adbe8:  40 00 15 bf  call  0xa00b32e4
a00adbec:  c2 23 a0 5c  st  %g1, [ %sp + 0x5c ]
a00adbf0:  9e 0e a0 ff  and  %i2, 0xff, %o7
a00adbf4:  80 a3 e0 0c  cmp  %o7, 0xc
a00adbf8:  08 bf ff ea  bleu  0xa00adba0
a00adbfc:  82 03 c0 0f  add  %o7, %o7, %g1
a00adc00:  b2 14 62 90  or  %l1, 0x290, %i1
a00adc04:  21 2a 00 97  sethi  %hi(0xa8025c00), %l0
a00adc08:  e4 0e 61 90  ldub  [ %i1 + 0x190 ], %l2
a00adc0c:  d0 0c 20 56  ldub  [ %l0 + 0x56 ], %o0
a00adc10:  9f 34 a0 02  srl  %l2, 2, %o7
a00adc14:  a3 32 20 02  srl  %o0, 2, %l1
a00adc18:  80 a4 40 0f  cmp  %l1, %o7
a00adc1c:  02 80 00 05  be  0xa00adc30
a00adc20:  b2 10 20 00  clr  %i1
a00adc24:  b0 10 20 04  mov  4, %i0
a00adc28:  40 02 64 06  call  0xa0146c40
a00adc2c:  95 e8 20 00  restore  %g0, 0, %o2
a00adc30:  90 0a 20 03  and  %o0, 3, %o0
a00adc34:  7f ff ff 0e  call  0xa00ad86c
a00adc38:  92 10 20 00  clr  %o1
a00adc3c:  f4 0c 20 56  ldub  [ %l0 + 0x56 ], %i2
a00adc40:  b0 0e a0 03  and  %i2, 3, %i0
a00adc44:  40 00 16 74  call  0xa00b3614
a00adc48:  93 e8 20 01  restore  %g0, 1, %o1
a00adc4c:  40 02 63 c8  call  0xa0146b6c
a00adc50:  92 10 20 00  clr  %o1
a00adc54:  90 10 20 6f  mov  0x6f, %o0
a00adc58:  40 02 63 be  call  0xa0146b50
a00adc5c:  92 10 20 00  clr  %o1
a00adc60:  96 14 62 90  or  %l1, 0x290, %o3
a00adc64:  15 00 06 3e  sethi  %hi(0x18f800), %o2
a00adc68:  d2 0a e0 08  ldub  [ %o3 + 8 ], %o1
a00adc6c:  7f ff d6 f6  call  0xa00a3844
a00adc70:  90 12 a1 84  or  %o2, 0x184, %o0
a00adc74:  98 10 00 08  mov  %o0, %o4
a00adc78:  90 10 20 00  clr  %o0
a00adc7c:  92 10 20 06  mov  6, %o1
a00adc80:  94 10 20 05  mov  5, %o2
a00adc84:  96 10 20 0a  mov  0xa, %o3
a00adc88:  7f ff d5 47  call  0xa00a31a4
a00adc8c:  9a 10 20 00  clr  %o5
a00adc90:  10 bf ff be  b  0xa00adb88
a00adc94:  80 a6 20 0c  cmp  %i0, 0xc
