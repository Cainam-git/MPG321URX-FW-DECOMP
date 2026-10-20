# leon2s FUN_a008fb7c 0xa008fb7c-0xa008fdc8 (588 bytes)
a008fb7c:  9d e3 bf 98  save  %sp, -104, %sp
a008fb80:  b0 0e 20 ff  and  %i0, 0xff, %i0
a008fb84:  80 a6 20 00  cmp  %i0, 0
a008fb88:  a2 10 20 08  mov  8, %l1
a008fb8c:  02 80 00 07  be  0xa008fba8
a008fb90:  a0 10 20 00  clr  %l0
a008fb94:  80 a6 20 01  cmp  %i0, 1
a008fb98:  02 80 00 04  be  0xa008fba8
a008fb9c:  a0 10 20 01  mov  1, %l0
a008fba0:  10 80 00 88  b  0xa008fdc0
a008fba4:  b0 10 20 08  mov  8, %i0
a008fba8:  90 10 00 18  mov  %i0, %o0
a008fbac:  40 00 5a 74  call  0xa00a657c
a008fbb0:  92 10 20 45  mov  0x45, %o1
a008fbb4:  90 0a 20 07  and  %o0, 7, %o0
a008fbb8:  80 a2 20 04  cmp  %o0, 4
a008fbbc:  12 80 00 0f  bne  0xa008fbf8
a008fbc0:  80 a6 20 00  cmp  %i0, 0
a008fbc4:  02 80 00 06  be  0xa008fbdc
a008fbc8:  1b 33 c0 3c  sethi  %hi(0xcf00f000), %o5
a008fbcc:  80 a6 20 01  cmp  %i0, 1
a008fbd0:  02 80 00 07  be  0xa008fbec
a008fbd4:  9a 13 62 24  or  %o5, 0x224, %o5
a008fbd8:  30 80 00 15  b,a   0xa008fc2c
a008fbdc:  9a 13 62 24  or  %o5, 0x224, %o5
a008fbe0:  c2 03 40 00  ld  [ %o5 ], %g1
a008fbe4:  10 80 00 11  b  0xa008fc28
a008fbe8:  82 10 60 11  or  %g1, 0x11, %g1
a008fbec:  c2 03 40 00  ld  [ %o5 ], %g1
a008fbf0:  10 80 00 0e  b  0xa008fc28
a008fbf4:  82 10 60 22  or  %g1, 0x22, %g1
a008fbf8:  02 80 00 06  be  0xa008fc10
a008fbfc:  1b 33 c0 3c  sethi  %hi(0xcf00f000), %o5
a008fc00:  80 a6 20 01  cmp  %i0, 1
a008fc04:  02 80 00 07  be  0xa008fc20
a008fc08:  9a 13 62 24  or  %o5, 0x224, %o5
a008fc0c:  30 80 00 08  b,a   0xa008fc2c
a008fc10:  9a 13 62 24  or  %o5, 0x224, %o5
a008fc14:  c2 03 40 00  ld  [ %o5 ], %g1
a008fc18:  10 80 00 04  b  0xa008fc28
a008fc1c:  82 08 7f fe  and  %g1, -2, %g1
a008fc20:  c2 03 40 00  ld  [ %o5 ], %g1
a008fc24:  82 08 7f fd  and  %g1, -3, %g1
a008fc28:  c2 23 40 00  st  %g1, [ %o5 ]
a008fc2c:  7f ff ff cc  call  0xa008fb5c
a008fc30:  90 10 00 18  mov  %i0, %o0
a008fc34:  90 0a 20 ff  and  %o0, 0xff, %o0
a008fc38:  80 a2 20 03  cmp  %o0, 3
a008fc3c:  12 80 00 12  bne  0xa008fc84
a008fc40:  80 a6 20 00  cmp  %i0, 0
a008fc44:  02 80 00 07  be  0xa008fc60
a008fc48:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a008fc4c:  80 a6 20 01  cmp  %i0, 1
a008fc50:  02 80 00 08  be  0xa008fc70
a008fc54:  9a 13 62 40  or  %o5, 0x240, %o5
a008fc58:  10 80 00 20  b  0xa008fcd8
a008fc5c:  90 10 00 18  mov  %i0, %o0
a008fc60:  9a 13 62 40  or  %o5, 0x240, %o5
a008fc64:  c2 03 40 00  ld  [ %o5 ], %g1
a008fc68:  10 80 00 04  b  0xa008fc78
a008fc6c:  82 10 60 10  or  %g1, 0x10, %g1
a008fc70:  c2 03 40 00  ld  [ %o5 ], %g1
a008fc74:  82 10 60 20  or  %g1, 0x20, %g1
a008fc78:  c2 23 40 00  st  %g1, [ %o5 ]
a008fc7c:  10 80 00 17  b  0xa008fcd8
a008fc80:  90 10 00 18  mov  %i0, %o0
a008fc84:  02 80 00 06  be  0xa008fc9c
a008fc88:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a008fc8c:  80 a6 20 01  cmp  %i0, 1
a008fc90:  02 80 00 0a  be  0xa008fcb8
a008fc94:  90 10 00 18  mov  %i0, %o0
a008fc98:  30 80 00 10  b,a   0xa008fcd8
a008fc9c:  82 10 62 40  or  %g1, 0x240, %g1
a008fca0:  da 00 40 00  ld  [ %g1 ], %o5
a008fca4:  9a 0b 7f ef  and  %o5, -17, %o5
a008fca8:  da 20 40 00  st  %o5, [ %g1 ]
a008fcac:  da 00 40 00  ld  [ %g1 ], %o5
a008fcb0:  10 80 00 08  b  0xa008fcd0
a008fcb4:  9a 0b 7f fe  and  %o5, -2, %o5
a008fcb8:  82 10 62 40  or  %g1, 0x240, %g1
a008fcbc:  da 00 40 00  ld  [ %g1 ], %o5
a008fcc0:  9a 0b 7f df  and  %o5, -33, %o5
a008fcc4:  da 20 40 00  st  %o5, [ %g1 ]
a008fcc8:  da 00 40 00  ld  [ %g1 ], %o5
a008fccc:  9a 0b 7f fd  and  %o5, -3, %o5
a008fcd0:  da 20 40 00  st  %o5, [ %g1 ]
a008fcd4:  90 10 00 18  mov  %i0, %o0
a008fcd8:  40 00 5a 29  call  0xa00a657c
a008fcdc:  92 10 20 45  mov  0x45, %o1
a008fce0:  90 0a 20 07  and  %o0, 7, %o0
a008fce4:  80 a2 20 05  cmp  %o0, 5
a008fce8:  22 80 00 16  be,a   0xa008fd40
a008fcec:  13 00 00 07  sethi  %hi(0x1c00), %o1
a008fcf0:  14 80 00 07  bg  0xa008fd0c
a008fcf4:  80 a2 20 06  cmp  %o0, 6
a008fcf8:  80 a2 20 04  cmp  %o0, 4
a008fcfc:  02 80 00 0a  be  0xa008fd24
a008fd00:  13 00 00 07  sethi  %hi(0x1c00), %o1
a008fd04:  10 80 00 25  b  0xa008fd98
a008fd08:  90 0c 20 ff  and  %l0, 0xff, %o0
a008fd0c:  02 80 00 14  be  0xa008fd5c
a008fd10:  80 a2 20 07  cmp  %o0, 7
a008fd14:  02 80 00 1a  be  0xa008fd7c
a008fd18:  13 00 00 07  sethi  %hi(0x1c00), %o1
a008fd1c:  10 80 00 1f  b  0xa008fd98
a008fd20:  90 0c 20 ff  and  %l0, 0xff, %o0
a008fd24:  90 0c 20 ff  and  %l0, 0xff, %o0
a008fd28:  92 12 63 08  or  %o1, 0x308, %o1
a008fd2c:  94 10 3f f8  mov  -8, %o2
a008fd30:  40 00 5d d6  call  0xa00a7488
a008fd34:  96 10 20 04  mov  4, %o3
a008fd38:  10 80 00 1c  b  0xa008fda8
a008fd3c:  a2 10 20 08  mov  8, %l1
a008fd40:  90 0c 20 ff  and  %l0, 0xff, %o0
a008fd44:  92 12 63 08  or  %o1, 0x308, %o1
a008fd48:  94 10 3f f8  mov  -8, %o2
a008fd4c:  40 00 5d cf  call  0xa00a7488
a008fd50:  96 10 20 05  mov  5, %o3
a008fd54:  10 80 00 15  b  0xa008fda8
a008fd58:  a2 10 20 0a  mov  0xa, %l1
a008fd5c:  13 00 00 07  sethi  %hi(0x1c00), %o1
a008fd60:  90 0c 20 ff  and  %l0, 0xff, %o0
a008fd64:  92 12 63 08  or  %o1, 0x308, %o1
a008fd68:  94 10 3f f8  mov  -8, %o2
a008fd6c:  40 00 5d c7  call  0xa00a7488
a008fd70:  96 10 20 06  mov  6, %o3
a008fd74:  10 80 00 0d  b  0xa008fda8
a008fd78:  a2 10 20 0c  mov  0xc, %l1
a008fd7c:  90 0c 20 ff  and  %l0, 0xff, %o0
a008fd80:  92 12 63 08  or  %o1, 0x308, %o1
a008fd84:  94 10 3f f8  mov  -8, %o2
a008fd88:  40 00 5d c0  call  0xa00a7488
a008fd8c:  96 10 20 07  mov  7, %o3
a008fd90:  10 80 00 06  b  0xa008fda8
a008fd94:  a2 10 20 10  mov  0x10, %l1
a008fd98:  92 12 63 08  or  %o1, 0x308, %o1
a008fd9c:  94 10 3f f8  mov  -8, %o2
a008fda0:  40 00 5d ba  call  0xa00a7488
a008fda4:  96 10 20 04  mov  4, %o3
a008fda8:  90 10 00 18  mov  %i0, %o0
a008fdac:  92 10 20 d9  mov  0xd9, %o1
a008fdb0:  94 10 20 02  mov  2, %o2
a008fdb4:  40 00 5a 81  call  0xa00a67b8
a008fdb8:  96 10 20 00  clr  %o3
a008fdbc:  b0 0c 60 ff  and  %l1, 0xff, %i0
a008fdc0:  81 c7 e0 08  ret
a008fdc4:  81 e8 00 00  restore
