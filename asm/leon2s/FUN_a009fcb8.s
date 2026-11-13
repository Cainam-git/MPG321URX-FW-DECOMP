# leon2s FUN_a009fcb8 0xa009fcb8-0xa009fe2c (372 bytes)
a009fcb8:  9d e3 bf 98  save  %sp, -104, %sp
a009fcbc:  b0 0e 20 ff  and  %i0, 0xff, %i0
a009fcc0:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a009fcc4:  82 10 63 00  or  %g1, 0x300, %g1	! 0xa807db00
a009fcc8:  b0 5e 20 34  smul  %i0, 0x34, %i0
a009fccc:  b0 06 00 01  add  %i0, %g1, %i0
a009fcd0:  d6 06 20 04  ld  [ %i0 + 4 ], %o3
a009fcd4:  d8 02 e0 60  ld  [ %o3 + 0x60 ], %o4
a009fcd8:  82 0b 20 ff  and  %o4, 0xff, %g1
a009fcdc:  92 10 20 00  clr  %o1
a009fce0:  94 10 20 24  mov  0x24, %o2
a009fce4:  9b 33 20 10  srl  %o4, 0x10, %o5
a009fce8:  80 a0 60 83  cmp  %g1, 0x83
a009fcec:  12 80 00 4a  bne  0xa009fe14
a009fcf0:  90 10 00 19  mov  %i1, %o0
a009fcf4:  80 8b 60 ff  btst  0xff, %o5
a009fcf8:  02 80 00 47  be  0xa009fe14
a009fcfc:  01 00 00 00  nop
a009fd00:  da 02 e0 64  ld  [ %o3 + 0x64 ], %o5
a009fd04:  03 3f c0 00  sethi  %hi(0xff000000), %g1
a009fd08:  82 2b 40 01  andn  %o5, %g1, %g1
a009fd0c:  99 33 20 08  srl  %o4, 8, %o4
a009fd10:  80 a0 60 1a  cmp  %g1, 0x1a
a009fd14:  02 80 00 40  be  0xa009fe14
a009fd18:  9a 0b 20 ff  and  %o4, 0xff, %o5
a009fd1c:  80 a3 60 01  cmp  %o5, 1
a009fd20:  12 80 00 40  bne  0xa009fe20
a009fd24:  d8 2e 40 00  stb  %o4, [ %i1 ]
a009fd28:  c2 06 20 04  ld  [ %i0 + 4 ], %g1
a009fd2c:  d6 00 60 64  ld  [ %g1 + 0x64 ], %o3
a009fd30:  99 32 e0 18  srl  %o3, 0x18, %o4
a009fd34:  83 32 e0 08  srl  %o3, 8, %g1
a009fd38:  9b 32 e0 10  srl  %o3, 0x10, %o5
a009fd3c:  da 2e 60 03  stb  %o5, [ %i1 + 3 ]
a009fd40:  d8 2e 60 04  stb  %o4, [ %i1 + 4 ]
a009fd44:  c2 2e 60 02  stb  %g1, [ %i1 + 2 ]
a009fd48:  d6 2e 60 01  stb  %o3, [ %i1 + 1 ]
a009fd4c:  c2 06 20 04  ld  [ %i0 + 4 ], %g1
a009fd50:  d6 00 60 68  ld  [ %g1 + 0x68 ], %o3
a009fd54:  99 32 e0 18  srl  %o3, 0x18, %o4
a009fd58:  83 32 e0 08  srl  %o3, 8, %g1
a009fd5c:  9b 32 e0 10  srl  %o3, 0x10, %o5
a009fd60:  da 2e 60 07  stb  %o5, [ %i1 + 7 ]
a009fd64:  d8 2e 60 08  stb  %o4, [ %i1 + 8 ]
a009fd68:  c2 2e 60 06  stb  %g1, [ %i1 + 6 ]
a009fd6c:  d6 2e 60 05  stb  %o3, [ %i1 + 5 ]
a009fd70:  c2 06 20 04  ld  [ %i0 + 4 ], %g1
a009fd74:  d6 00 60 6c  ld  [ %g1 + 0x6c ], %o3
a009fd78:  99 32 e0 18  srl  %o3, 0x18, %o4
a009fd7c:  83 32 e0 08  srl  %o3, 8, %g1
a009fd80:  9b 32 e0 10  srl  %o3, 0x10, %o5
a009fd84:  da 2e 60 0b  stb  %o5, [ %i1 + 0xb ]
a009fd88:  d8 2e 60 0c  stb  %o4, [ %i1 + 0xc ]
a009fd8c:  c2 2e 60 0a  stb  %g1, [ %i1 + 0xa ]
a009fd90:  d6 2e 60 09  stb  %o3, [ %i1 + 9 ]
a009fd94:  c2 06 20 04  ld  [ %i0 + 4 ], %g1
a009fd98:  d6 00 60 70  ld  [ %g1 + 0x70 ], %o3
a009fd9c:  99 32 e0 18  srl  %o3, 0x18, %o4
a009fda0:  83 32 e0 08  srl  %o3, 8, %g1
a009fda4:  9b 32 e0 10  srl  %o3, 0x10, %o5
a009fda8:  da 2e 60 0f  stb  %o5, [ %i1 + 0xf ]
a009fdac:  d8 2e 60 10  stb  %o4, [ %i1 + 0x10 ]
a009fdb0:  c2 2e 60 0e  stb  %g1, [ %i1 + 0xe ]
a009fdb4:  d6 2e 60 0d  stb  %o3, [ %i1 + 0xd ]
a009fdb8:  c2 06 20 04  ld  [ %i0 + 4 ], %g1
a009fdbc:  d6 00 60 74  ld  [ %g1 + 0x74 ], %o3
a009fdc0:  83 32 e0 08  srl  %o3, 8, %g1
a009fdc4:  c2 2e 60 12  stb  %g1, [ %i1 + 0x12 ]
a009fdc8:  9b 32 e0 10  srl  %o3, 0x10, %o5
a009fdcc:  83 32 e0 18  srl  %o3, 0x18, %g1
a009fdd0:  da 2e 60 13  stb  %o5, [ %i1 + 0x13 ]
a009fdd4:  d6 2e 60 11  stb  %o3, [ %i1 + 0x11 ]
a009fdd8:  c2 2e 60 14  stb  %g1, [ %i1 + 0x14 ]
a009fddc:  c2 06 20 04  ld  [ %i0 + 4 ], %g1
a009fde0:  d6 00 60 78  ld  [ %g1 + 0x78 ], %o3
a009fde4:  83 32 e0 08  srl  %o3, 8, %g1
a009fde8:  c2 2e 60 16  stb  %g1, [ %i1 + 0x16 ]
a009fdec:  9b 32 e0 10  srl  %o3, 0x10, %o5
a009fdf0:  da 2e 60 17  stb  %o5, [ %i1 + 0x17 ]
a009fdf4:  99 32 e0 18  srl  %o3, 0x18, %o4
a009fdf8:  d8 2e 60 18  stb  %o4, [ %i1 + 0x18 ]
a009fdfc:  d6 2e 60 15  stb  %o3, [ %i1 + 0x15 ]
a009fe00:  c2 06 20 04  ld  [ %i0 + 4 ], %g1
a009fe04:  c2 00 60 7c  ld  [ %g1 + 0x7c ], %g1
a009fe08:  82 08 60 ff  and  %g1, 0xff, %g1
a009fe0c:  10 80 00 05  b  0xa009fe20
a009fe10:  c2 26 60 1c  st  %g1, [ %i1 + 0x1c ]
a009fe14:  40 00 45 e6  call  0xa00b15ac
a009fe18:  b0 10 20 01  mov  1, %i0
a009fe1c:  30 80 00 02  b,a   0xa009fe24
a009fe20:  b0 10 20 00  clr  %i0
a009fe24:  81 c7 e0 08  ret
a009fe28:  81 e8 00 00  restore
