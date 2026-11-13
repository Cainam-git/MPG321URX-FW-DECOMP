# leon2m FUN_a00bfb28 0xa00bfb28-0xa00bfcc4 (412 bytes)
a00bfb28:  9d e3 bf 98  save  %sp, -104, %sp
a00bfb2c:  35 2a 00 b4  sethi  %hi(0xa802d000), %i2
a00bfb30:  90 10 20 35  mov  0x35, %o0
a00bfb34:  a0 16 a0 78  or  %i2, 0x78, %l0
a00bfb38:  98 10 20 30  mov  0x30, %o4
a00bfb3c:  9a 10 20 62  mov  0x62, %o5
a00bfb40:  82 10 20 5b  mov  0x5b, %g1
a00bfb44:  d0 2e a0 78  stb  %o0, [ %i2 + 0x78 ]
a00bfb48:  da 2c 20 01  stb  %o5, [ %l0 + 1 ]
a00bfb4c:  c2 2c 20 04  stb  %g1, [ %l0 + 4 ]
a00bfb50:  d8 2c 20 03  stb  %o4, [ %l0 + 3 ]
a00bfb54:  d8 2c 20 02  stb  %o4, [ %l0 + 2 ]
a00bfb58:  40 02 17 72  call  0xa0145920
a00bfb5c:  90 10 20 06  mov  6, %o0
a00bfb60:  d0 2c 20 05  stb  %o0, [ %l0 + 5 ]
a00bfb64:  40 02 17 6f  call  0xa0145920
a00bfb68:  90 10 20 07  mov  7, %o0
a00bfb6c:  d0 2c 20 06  stb  %o0, [ %l0 + 6 ]
a00bfb70:  40 02 17 6c  call  0xa0145920
a00bfb74:  90 10 20 08  mov  8, %o0
a00bfb78:  d0 2c 20 07  stb  %o0, [ %l0 + 7 ]
a00bfb7c:  40 02 17 69  call  0xa0145920
a00bfb80:  90 10 20 09  mov  9, %o0
a00bfb84:  d0 2c 20 08  stb  %o0, [ %l0 + 8 ]
a00bfb88:  40 02 17 66  call  0xa0145920
a00bfb8c:  90 10 20 0a  mov  0xa, %o0
a00bfb90:  d0 2c 20 09  stb  %o0, [ %l0 + 9 ]
a00bfb94:  40 02 17 63  call  0xa0145920
a00bfb98:  90 10 20 0b  mov  0xb, %o0
a00bfb9c:  d0 2c 20 0a  stb  %o0, [ %l0 + 0xa ]
a00bfba0:  40 02 17 60  call  0xa0145920
a00bfba4:  90 10 20 0c  mov  0xc, %o0
a00bfba8:  d0 2c 20 0b  stb  %o0, [ %l0 + 0xb ]
a00bfbac:  40 02 17 5d  call  0xa0145920
a00bfbb0:  90 10 20 0d  mov  0xd, %o0
a00bfbb4:  d0 2c 20 0c  stb  %o0, [ %l0 + 0xc ]
a00bfbb8:  40 02 17 5a  call  0xa0145920
a00bfbbc:  90 10 20 0e  mov  0xe, %o0
a00bfbc0:  d0 2c 20 0d  stb  %o0, [ %l0 + 0xd ]
a00bfbc4:  40 02 17 57  call  0xa0145920
a00bfbc8:  90 10 20 12  mov  0x12, %o0
a00bfbcc:  d0 2c 20 0e  stb  %o0, [ %l0 + 0xe ]
a00bfbd0:  40 02 17 54  call  0xa0145920
a00bfbd4:  90 10 20 13  mov  0x13, %o0
a00bfbd8:  d0 2c 20 0f  stb  %o0, [ %l0 + 0xf ]
a00bfbdc:  40 02 17 51  call  0xa0145920
a00bfbe0:  90 10 20 14  mov  0x14, %o0
a00bfbe4:  d0 2c 20 10  stb  %o0, [ %l0 + 0x10 ]
a00bfbe8:  96 10 20 00  clr  %o3
a00bfbec:  9a 10 20 05  mov  5, %o5
a00bfbf0:  82 10 20 05  mov  5, %g1
a00bfbf4:  d2 0c 00 01  ldub  [ %l0 + %g1 ], %o1
a00bfbf8:  9a 03 60 01  inc  %o5
a00bfbfc:  98 02 c0 09  add  %o3, %o1, %o4
a00bfc00:  82 0b 60 ff  and  %o5, 0xff, %g1
a00bfc04:  80 a0 60 10  cmp  %g1, 0x10
a00bfc08:  08 bf ff fb  bleu  0xa00bfbf4
a00bfc0c:  96 10 00 0c  mov  %o4, %o3
a00bfc10:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bfc14:  94 10 20 0d  mov  0xd, %o2
a00bfc18:  d4 2c 20 12  stb  %o2, [ %l0 + 0x12 ]
a00bfc1c:  80 a6 20 02  cmp  %i0, 2
a00bfc20:  02 80 00 10  be  0xa00bfc60
a00bfc24:  d8 2c 20 11  stb  %o4, [ %l0 + 0x11 ]
a00bfc28:  80 a6 20 03  cmp  %i0, 3
a00bfc2c:  02 80 00 19  be  0xa00bfc90
a00bfc30:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00bfc34:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00bfc38:  9a 13 20 d0  or  %o4, 0xd0, %o5
a00bfc3c:  c0 28 60 9c  clrb  [ %g1 + 0x9c ]
a00bfc40:  c0 2b 20 d0  clrb  [ %o4 + 0xd0 ]
a00bfc44:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00bfc48:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00bfc4c:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00bfc50:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00bfc54:  b4 16 a0 78  or  %i2, 0x78, %i2
a00bfc58:  40 02 22 e4  call  0xa01487e8
a00bfc5c:  93 e8 20 13  restore  %g0, 0x13, %o1
a00bfc60:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00bfc64:  1f 2a 00 ac  sethi  %hi(0xa802b000), %o7
a00bfc68:  9a 12 e0 40  or  %o3, 0x40, %o5
a00bfc6c:  c0 2b e0 9a  clrb  [ %o7 + 0x9a ]
a00bfc70:  c0 2a e0 40  clrb  [ %o3 + 0x40 ]
a00bfc74:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00bfc78:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00bfc7c:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00bfc80:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00bfc84:  b4 16 a0 78  or  %i2, 0x78, %i2
a00bfc88:  40 02 22 d8  call  0xa01487e8
a00bfc8c:  93 e8 20 13  restore  %g0, 0x13, %o1
a00bfc90:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00bfc94:  33 2a 00 ac  sethi  %hi(0xa802b000), %i1
a00bfc98:  c0 2e 60 98  clrb  [ %i1 + 0x98 ]	! 0xa802b098
a00bfc9c:  9a 14 20 98  or  %l0, 0x98, %o5
a00bfca0:  c0 2c 20 98  clrb  [ %l0 + 0x98 ]
a00bfca4:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00bfca8:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00bfcac:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00bfcb0:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00bfcb4:  b4 16 a0 78  or  %i2, 0x78, %i2
a00bfcb8:  40 02 22 cc  call  0xa01487e8
a00bfcbc:  93 e8 20 13  restore  %g0, 0x13, %o1
a00bfcc0:  01 00 00 00  nop
