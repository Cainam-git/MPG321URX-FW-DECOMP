# leon2s FUN_a009faf0 0xa009faf0-0xa009fcb8 (456 bytes)
a009faf0:  9d e3 bf 98  save  %sp, -104, %sp
a009faf4:  a0 0e 20 ff  and  %i0, 0xff, %l0
a009faf8:  11 2a 01 f6  sethi  %hi(0xa807d800), %o0
a009fafc:  9a 12 23 00  or  %o0, 0x300, %o5	! 0xa807db00
a009fb00:  82 5c 20 34  smul  %l0, 0x34, %g1
a009fb04:  92 00 40 0d  add  %g1, %o5, %o1
a009fb08:  c2 02 60 04  ld  [ %o1 + 4 ], %g1
a009fb0c:  d6 00 60 80  ld  [ %g1 + 0x80 ], %o3
a009fb10:  9b 32 e0 10  srl  %o3, 0x10, %o5
a009fb14:  82 0a e0 ff  and  %o3, 0xff, %g1
a009fb18:  80 a0 60 84  cmp  %g1, 0x84
a009fb1c:  d6 2e 60 1c  stb  %o3, [ %i1 + 0x1c ]
a009fb20:  12 80 00 39  bne  0xa009fc04
a009fb24:  da 2e 60 1e  stb  %o5, [ %i1 + 0x1e ]
a009fb28:  80 8b 60 ff  btst  0xff, %o5
a009fb2c:  22 80 00 37  be,a   0xa009fc08
a009fb30:  90 10 00 19  mov  %i1, %o0
a009fb34:  83 32 e0 18  srl  %o3, 0x18, %g1
a009fb38:  c2 2e 60 1f  stb  %g1, [ %i1 + 0x1f ]
a009fb3c:  c2 02 60 04  ld  [ %o1 + 4 ], %g1
a009fb40:  f0 00 60 84  ld  [ %g1 + 0x84 ], %i0
a009fb44:  82 0e 20 f0  and  %i0, 0xf0, %g1
a009fb48:  95 30 60 04  srl  %g1, 4, %o2
a009fb4c:  97 32 e0 08  srl  %o3, 8, %o3
a009fb50:  83 36 20 08  srl  %i0, 8, %g1
a009fb54:  9b 36 20 10  srl  %i0, 0x10, %o5
a009fb58:  99 36 20 18  srl  %i0, 0x18, %o4
a009fb5c:  c2 2e 60 21  stb  %g1, [ %i1 + 0x21 ]
a009fb60:  da 2e 60 22  stb  %o5, [ %i1 + 0x22 ]
a009fb64:  d8 2e 60 23  stb  %o4, [ %i1 + 0x23 ]
a009fb68:  d6 2e 60 1d  stb  %o3, [ %i1 + 0x1d ]
a009fb6c:  f0 2e 60 20  stb  %i0, [ %i1 + 0x20 ]
a009fb70:  80 a2 a0 0e  cmp  %o2, 0xe
a009fb74:  08 80 00 03  bleu  0xa009fb80
a009fb78:  d6 2e 40 00  stb  %o3, [ %i1 ]
a009fb7c:  94 10 20 0f  mov  0xf, %o2
a009fb80:  82 0a a0 ff  and  %o2, 0xff, %g1
a009fb84:  1b 28 02 d1  sethi  %hi(0xa00b4400), %o5
a009fb88:  9a 13 63 50  or  %o5, 0x350, %o5	! 0xa00b4750
a009fb8c:  83 28 60 03  sll  %g1, 3, %g1
a009fb90:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a009fb94:  9a 0e 20 07  and  %i0, 7, %o5
a009fb98:  80 a3 60 07  cmp  %o5, 7
a009fb9c:  08 80 00 03  bleu  0xa009fba8
a009fba0:  c2 26 60 04  st  %g1, [ %i1 + 4 ]
a009fba4:  9a 10 20 08  mov  8, %o5
a009fba8:  9a 0b 60 ff  and  %o5, 0xff, %o5
a009fbac:  03 28 02 d1  sethi  %hi(0xa00b4400), %g1
a009fbb0:  9b 2b 60 03  sll  %o5, 3, %o5
a009fbb4:  99 36 20 0a  srl  %i0, 0xa, %o4
a009fbb8:  82 10 63 08  or  %g1, 0x308, %g1
a009fbbc:  c2 00 40 0d  ld  [ %g1 + %o5 ], %g1
a009fbc0:  98 0b 20 07  and  %o4, 7, %o4
a009fbc4:  80 a3 20 07  cmp  %o4, 7
a009fbc8:  08 80 00 03  bleu  0xa009fbd4
a009fbcc:  c2 26 60 08  st  %g1, [ %i1 + 8 ]
a009fbd0:  98 10 20 08  mov  8, %o4
a009fbd4:  9a 0b 20 ff  and  %o4, 0xff, %o5
a009fbd8:  03 28 02 d1  sethi  %hi(0xa00b4400), %g1
a009fbdc:  9b 2b 60 03  sll  %o5, 3, %o5
a009fbe0:  98 0e 23 00  and  %i0, 0x300, %o4
a009fbe4:  82 10 62 c0  or  %g1, 0x2c0, %g1
a009fbe8:  c2 00 40 0d  ld  [ %g1 + %o5 ], %g1
a009fbec:  9f 33 20 08  srl  %o4, 8, %o7
a009fbf0:  80 a3 e0 03  cmp  %o7, 3
a009fbf4:  08 80 00 0a  bleu  0xa009fc1c
a009fbf8:  c2 26 60 0c  st  %g1, [ %i1 + 0xc ]
a009fbfc:  10 80 00 08  b  0xa009fc1c
a009fc00:  9e 10 20 04  mov  4, %o7
a009fc04:  90 10 00 19  mov  %i1, %o0
a009fc08:  92 10 20 00  clr  %o1
a009fc0c:  40 00 46 68  call  0xa00b15ac
a009fc10:  94 10 20 30  mov  0x30, %o2
a009fc14:  10 80 00 27  b  0xa009fcb0
a009fc18:  b0 10 20 01  mov  1, %i0
a009fc1c:  83 36 20 18  srl  %i0, 0x18, %g1
a009fc20:  c2 2e 60 14  stb  %g1, [ %i1 + 0x14 ]
a009fc24:  c2 02 60 04  ld  [ %o1 + 4 ], %g1
a009fc28:  f0 00 60 88  ld  [ %g1 + 0x88 ], %i0
a009fc2c:  82 0e 20 78  and  %i0, 0x78, %g1
a009fc30:  83 30 60 03  srl  %g1, 3, %g1
a009fc34:  97 36 20 08  srl  %i0, 8, %o3
a009fc38:  95 36 20 10  srl  %i0, 0x10, %o2
a009fc3c:  93 36 20 18  srl  %i0, 0x18, %o1
a009fc40:  90 12 23 00  or  %o0, 0x300, %o0
a009fc44:  98 5c 20 34  smul  %l0, 0x34, %o4
a009fc48:  d6 2e 60 25  stb  %o3, [ %i1 + 0x25 ]
a009fc4c:  d4 2e 60 26  stb  %o2, [ %i1 + 0x26 ]
a009fc50:  d2 2e 60 27  stb  %o1, [ %i1 + 0x27 ]
a009fc54:  c2 2e 60 15  stb  %g1, [ %i1 + 0x15 ]
a009fc58:  98 03 00 08  add  %o4, %o0, %o4
a009fc5c:  f0 2e 60 24  stb  %i0, [ %i1 + 0x24 ]
a009fc60:  c2 03 20 04  ld  [ %o4 + 4 ], %g1
a009fc64:  9a 0e 20 80  and  %i0, 0x80, %o5
a009fc68:  f0 00 60 8c  ld  [ %g1 + 0x8c ], %i0
a009fc6c:  98 0b e0 ff  and  %o7, 0xff, %o4
a009fc70:  03 28 02 d1  sethi  %hi(0xa00b4400), %g1
a009fc74:  82 10 62 98  or  %g1, 0x298, %g1	! 0xa00b4698
a009fc78:  99 2b 20 03  sll  %o4, 3, %o4
a009fc7c:  d8 00 40 0c  ld  [ %g1 + %o4 ], %o4
a009fc80:  9b 33 60 07  srl  %o5, 7, %o5
a009fc84:  9a 0b 60 ff  and  %o5, 0xff, %o5
a009fc88:  03 28 02 d1  sethi  %hi(0xa00b4400), %g1
a009fc8c:  82 10 62 80  or  %g1, 0x280, %g1	! 0xa00b4680
a009fc90:  9b 2b 60 03  sll  %o5, 3, %o5
a009fc94:  da 00 40 0d  ld  [ %g1 + %o5 ], %o5
a009fc98:  83 36 20 08  srl  %i0, 8, %g1
a009fc9c:  f0 2e 60 28  stb  %i0, [ %i1 + 0x28 ]
a009fca0:  c2 2e 60 29  stb  %g1, [ %i1 + 0x29 ]
a009fca4:  d8 26 60 10  st  %o4, [ %i1 + 0x10 ]
a009fca8:  da 26 60 18  st  %o5, [ %i1 + 0x18 ]
a009fcac:  b0 10 20 00  clr  %i0
a009fcb0:  81 c7 e0 08  ret
a009fcb4:  81 e8 00 00  restore
