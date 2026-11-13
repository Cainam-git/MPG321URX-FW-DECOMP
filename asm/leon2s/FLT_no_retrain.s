# leon2s FLT_no_retrain 0xa009c9b4-0xa009cb34 (384 bytes)
a009c9b4:  9d e3 bf 98  save  %sp, -104, %sp
a009c9b8:  a2 10 20 00  clr  %l1
a009c9bc:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a009c9c0:  b0 0c 60 ff  and  %l1, 0xff, %i0
a009c9c4:  82 10 61 10  or  %g1, 0x110, %g1
a009c9c8:  c2 08 40 18  ldub  [ %g1 + %i0 ], %g1
a009c9cc:  80 a0 60 00  cmp  %g1, 0
a009c9d0:  22 80 00 4d  be,a   0xa009cb04
a009c9d4:  a2 04 60 01  inc  %l1
a009c9d8:  15 00 00 07  sethi  %hi(0x1c00), %o2
a009c9dc:  94 12 a3 0c  or  %o2, 0x30c, %o2	! 0x1f0c
a009c9e0:  90 10 20 14  mov  0x14, %o0
a009c9e4:  40 00 2a a1  call  0xa00a7468
a009c9e8:  92 10 20 00  clr  %o1
a009c9ec:  80 a2 20 00  cmp  %o0, 0
a009c9f0:  32 80 00 33  bne,a   0xa009cabc
a009c9f4:  b0 0c 60 ff  and  %l1, 0xff, %i0
a009c9f8:  21 2a 01 f6  sethi  %hi(0xa807d800), %l0
a009c9fc:  82 14 23 00  or  %l0, 0x300, %g1	! 0xa807db00
a009ca00:  9a 5e 20 34  smul  %i0, 0x34, %o5
a009ca04:  9a 03 40 01  add  %o5, %g1, %o5
a009ca08:  d2 03 60 18  ld  [ %o5 + 0x18 ], %o1
a009ca0c:  92 02 60 90  add  %o1, 0x90, %o1
a009ca10:  40 00 2a 7e  call  0xa00a7408
a009ca14:  90 10 20 11  mov  0x11, %o0
a009ca18:  80 a2 20 00  cmp  %o0, 0
a009ca1c:  02 80 00 18  be  0xa009ca7c
a009ca20:  82 06 00 18  add  %i0, %i0, %g1
a009ca24:  82 00 40 18  add  %g1, %i0, %g1
a009ca28:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a009ca2c:  83 28 60 03  sll  %g1, 3, %g1
a009ca30:  9a 13 62 50  or  %o5, 0x250, %o5
a009ca34:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a009ca38:  80 a0 60 01  cmp  %g1, 1
a009ca3c:  08 80 00 10  bleu  0xa009ca7c
a009ca40:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a009ca44:  82 5e 20 b0  smul  %i0, 0xb0, %g1
a009ca48:  9a 13 62 80  or  %o5, 0x280, %o5
a009ca4c:  9a 00 40 0d  add  %g1, %o5, %o5
a009ca50:  c2 0b 60 35  ldub  [ %o5 + 0x35 ], %g1
a009ca54:  80 a0 60 00  cmp  %g1, 0
a009ca58:  32 80 00 2b  bne,a   0xa009cb04
a009ca5c:  a2 04 60 01  inc  %l1
a009ca60:  82 10 20 01  mov  1, %g1
a009ca64:  11 28 01 a9  sethi  %hi(0xa006a400), %o0
a009ca68:  c2 2b 60 35  stb  %g1, [ %o5 + 0x35 ]
a009ca6c:  7f ff 5a 96  call  0xa00734c4
a009ca70:  90 12 23 78  or  %o0, 0x378, %o0
a009ca74:  10 80 00 24  b  0xa009cb04
a009ca78:  a2 04 60 01  inc  %l1
a009ca7c:  82 14 23 00  or  %l0, 0x300, %g1
a009ca80:  9a 5e 20 34  smul  %i0, 0x34, %o5
a009ca84:  9a 03 40 01  add  %o5, %g1, %o5
a009ca88:  d2 03 60 18  ld  [ %o5 + 0x18 ], %o1
a009ca8c:  92 02 60 90  add  %o1, 0x90, %o1
a009ca90:  40 00 2a 5e  call  0xa00a7408
a009ca94:  90 10 20 11  mov  0x11, %o0
a009ca98:  80 a2 20 00  cmp  %o0, 0
a009ca9c:  32 80 00 08  bne,a   0xa009cabc
a009caa0:  b0 0c 60 ff  and  %l1, 0xff, %i0
a009caa4:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a009caa8:  9a 5e 20 b0  smul  %i0, 0xb0, %o5
a009caac:  82 10 62 80  or  %g1, 0x280, %g1
a009cab0:  9a 03 40 01  add  %o5, %g1, %o5
a009cab4:  c0 2b 60 35  clrb  [ %o5 + 0x35 ]
a009cab8:  b0 0c 60 ff  and  %l1, 0xff, %i0
a009cabc:  7f ff ff 7d  call  0xa009c8b0
a009cac0:  90 10 00 18  mov  %i0, %o0
a009cac4:  9a 06 00 18  add  %i0, %i0, %o5
a009cac8:  9a 03 40 18  add  %o5, %i0, %o5
a009cacc:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a009cad0:  82 10 62 50  or  %g1, 0x250, %g1	! 0xa807d650
a009cad4:  9b 2b 60 03  sll  %o5, 3, %o5
a009cad8:  da 00 40 0d  ld  [ %g1 + %o5 ], %o5
a009cadc:  03 28 02 d0  sethi  %hi(0xa00b4000), %g1
a009cae0:  9b 2b 60 02  sll  %o5, 2, %o5
a009cae4:  82 10 62 58  or  %g1, 0x258, %g1
a009cae8:  c2 00 40 0d  ld  [ %g1 + %o5 ], %g1
a009caec:  9f c0 40 00  call  %g1
a009caf0:  90 10 00 18  mov  %i0, %o0
a009caf4:  80 8a 20 ff  btst  0xff, %o0
a009caf8:  12 bf ff f4  bne  0xa009cac8
a009cafc:  9a 06 00 18  add  %i0, %i0, %o5
a009cb00:  a2 04 60 01  inc  %l1
a009cb04:  82 0c 60 ff  and  %l1, 0xff, %g1
a009cb08:  80 a0 60 01  cmp  %g1, 1
a009cb0c:  08 bf ff ad  bleu  0xa009c9c0
a009cb10:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a009cb14:  31 2a 01 e4  sethi  %hi(0xa8079000), %i0
a009cb18:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009cb1c:  b0 16 20 f4  or  %i0, 0xf4, %i0
a009cb20:  c2 08 62 31  ldub  [ %g1 + 0x231 ], %g1
a009cb24:  c2 26 20 04  st  %g1, [ %i0 + 4 ]
a009cb28:  40 00 55 9b  call  0xa00b2194
a009cb2c:  81 e8 00 00  restore
a009cb30:  01 00 00 00  nop
