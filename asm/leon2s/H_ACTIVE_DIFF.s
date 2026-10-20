# leon2s H_ACTIVE_DIFF 0xa009cb34-0xa009d2f8 (1988 bytes)
a009cb34:  9d e3 bf 98  save  %sp, -104, %sp
a009cb38:  a6 0e 20 ff  and  %i0, 0xff, %l3
a009cb3c:  a8 10 00 18  mov  %i0, %l4
a009cb40:  80 a4 e0 00  cmp  %l3, 0
a009cb44:  02 80 00 06  be  0xa009cb5c
a009cb48:  b8 10 20 02  mov  2, %i4
a009cb4c:  b0 10 20 00  clr  %i0
a009cb50:  80 a4 e0 01  cmp  %l3, 1
a009cb54:  12 80 01 e7  bne  0xa009d2f0
a009cb58:  b8 10 20 03  mov  3, %i4
a009cb5c:  40 00 0e 1b  call  0xa00a03c8
a009cb60:  90 10 00 13  mov  %l3, %o0
a009cb64:  80 8a 20 ff  btst  0xff, %o0
a009cb68:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a009cb6c:  02 80 00 39  be  0xa009cc50
a009cb70:  a2 5c e0 34  smul  %l3, 0x34, %l1
a009cb74:  96 10 63 00  or  %g1, 0x300, %o3
a009cb78:  82 04 40 0b  add  %l1, %o3, %g1
a009cb7c:  da 00 60 2c  ld  [ %g1 + 0x2c ], %o5
a009cb80:  d0 03 60 0c  ld  [ %o5 + 0xc ], %o0
a009cb84:  e0 03 60 10  ld  [ %o5 + 0x10 ], %l0
a009cb88:  de 03 60 0c  ld  [ %o5 + 0xc ], %o7
a009cb8c:  e4 03 60 0c  ld  [ %o5 + 0xc ], %l2
a009cb90:  d8 03 60 88  ld  [ %o5 + 0x88 ], %o4
a009cb94:  d2 03 60 88  ld  [ %o5 + 0x88 ], %o1
a009cb98:  d4 03 60 88  ld  [ %o5 + 0x88 ], %o2
a009cb9c:  c2 02 c0 11  ld  [ %o3 + %l1 ], %g1
a009cba0:  e2 03 60 84  ld  [ %o5 + 0x84 ], %l1
a009cba4:  d6 00 60 64  ld  [ %g1 + 0x64 ], %o3
a009cba8:  d6 00 60 60  ld  [ %g1 + 0x60 ], %o3
a009cbac:  d6 00 60 60  ld  [ %g1 + 0x60 ], %o3
a009cbb0:  c2 00 60 60  ld  [ %g1 + 0x60 ], %g1
a009cbb4:  d6 03 60 8c  ld  [ %o5 + 0x8c ], %o3
a009cbb8:  c2 03 60 88  ld  [ %o5 + 0x88 ], %g1
a009cbbc:  99 33 20 10  srl  %o4, 0x10, %o4
a009cbc0:  96 0a e0 ff  and  %o3, 0xff, %o3
a009cbc4:  83 30 60 18  srl  %g1, 0x18, %g1
a009cbc8:  91 32 20 18  srl  %o0, 0x18, %o0
a009cbcc:  98 0b 20 ff  and  %o4, 0xff, %o4
a009cbd0:  93 32 60 08  srl  %o1, 8, %o1
a009cbd4:  97 2a e0 08  sll  %o3, 8, %o3
a009cbd8:  96 02 c0 01  add  %o3, %g1, %o3
a009cbdc:  92 0a 60 ff  and  %o1, 0xff, %o1
a009cbe0:  91 2a 20 08  sll  %o0, 8, %o0
a009cbe4:  a0 0c 20 ff  and  %l0, 0xff, %l0
a009cbe8:  99 2b 20 08  sll  %o4, 8, %o4
a009cbec:  94 0a a0 ff  and  %o2, 0xff, %o2
a009cbf0:  90 02 00 10  add  %o0, %l0, %o0
a009cbf4:  98 03 00 09  add  %o4, %o1, %o4
a009cbf8:  9f 33 e0 08  srl  %o7, 8, %o7
a009cbfc:  95 2a a0 08  sll  %o2, 8, %o2
a009cc00:  a3 34 60 18  srl  %l1, 0x18, %l1
a009cc04:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a009cc08:  98 02 00 0c  add  %o0, %o4, %o4
a009cc0c:  82 10 63 e0  or  %g1, 0x3e0, %g1
a009cc10:  94 02 80 11  add  %o2, %l1, %o2
a009cc14:  9e 0b e0 ff  and  %o7, 0xff, %o7
a009cc18:  a5 34 a0 10  srl  %l2, 0x10, %l2
a009cc1c:  9a 5c e1 90  smul  %l3, 0x190, %o5
a009cc20:  94 02 80 0c  add  %o2, %o4, %o2
a009cc24:  9a 03 40 01  add  %o5, %g1, %o5
a009cc28:  9f 2b e0 08  sll  %o7, 8, %o7
a009cc2c:  a4 0c a0 ff  and  %l2, 0xff, %l2
a009cc30:  ae 10 00 08  mov  %o0, %l7
a009cc34:  ba 03 c0 12  add  %o7, %l2, %i5
a009cc38:  ac 02 80 0b  add  %o2, %o3, %l6
a009cc3c:  d2 0b 60 19  ldub  [ %o5 + 0x19 ], %o1
a009cc40:  7f ff fd 17  call  0xa009c09c
a009cc44:  90 10 00 13  mov  %l3, %o0
a009cc48:  10 80 00 11  b  0xa009cc8c
a009cc4c:  aa 10 00 08  mov  %o0, %l5
a009cc50:  82 10 63 00  or  %g1, 0x300, %g1
a009cc54:  d8 00 40 11  ld  [ %g1 + %l1 ], %o4
a009cc58:  d6 03 20 38  ld  [ %o4 + 0x38 ], %o3
a009cc5c:  d4 03 20 3c  ld  [ %o4 + 0x3c ], %o2
a009cc60:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a009cc64:  da 03 20 4c  ld  [ %o4 + 0x4c ], %o5
a009cc68:  82 10 60 a8  or  %g1, 0xa8, %g1
a009cc6c:  c2 08 40 13  ldub  [ %g1 + %l3 ], %g1
a009cc70:  97 32 e0 10  srl  %o3, 0x10, %o3
a009cc74:  9b 33 60 10  srl  %o5, 0x10, %o5
a009cc78:  d8 03 20 50  ld  [ %o4 + 0x50 ], %o4
a009cc7c:  af 2b 40 01  sll  %o5, %g1, %l7
a009cc80:  ad 2a c0 01  sll  %o3, %g1, %l6
a009cc84:  aa 10 00 0a  mov  %o2, %l5
a009cc88:  ba 10 00 0c  mov  %o4, %i5
a009cc8c:  21 2a 01 f5  sethi  %hi(0xa807d400), %l0
a009cc90:  9a 14 23 e0  or  %l0, 0x3e0, %o5	! 0xa807d7e0
a009cc94:  82 5c e1 90  smul  %l3, 0x190, %g1
a009cc98:  96 00 40 0d  add  %g1, %o5, %o3
a009cc9c:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a009cca0:  82 10 60 b0  or  %g1, 0xb0, %g1	! 0xa80790b0
a009cca4:  d8 0a e0 06  ldub  [ %o3 + 6 ], %o4
a009cca8:  80 a0 00 0c  cmp  %g0, %o4
a009ccac:  da 08 40 13  ldub  [ %g1 + %l3 ], %o5
a009ccb0:  82 40 20 00  addx  %g0, 0, %g1
a009ccb4:  80 a3 40 01  cmp  %o5, %g1
a009ccb8:  02 80 00 16  be  0xa009cd10
a009ccbc:  80 a3 60 01  cmp  %o5, 1
a009ccc0:  12 80 00 0c  bne  0xa009ccf0
a009ccc4:  9a 14 23 e0  or  %l0, 0x3e0, %o5
a009ccc8:  80 a3 20 00  cmp  %o4, 0
a009cccc:  12 80 00 0a  bne  0xa009ccf4
a009ccd0:  82 5c e1 90  smul  %l3, 0x190, %g1
a009ccd4:  93 2d 60 10  sll  %l5, 0x10, %o1
a009ccd8:  11 28 01 a9  sethi  %hi(0xa006a400), %o0
a009ccdc:  ea 32 e0 1c  sth  %l5, [ %o3 + 0x1c ]
a009cce0:  90 12 23 88  or  %o0, 0x388, %o0
a009cce4:  7f ff 58 d8  call  0xa0073044
a009cce8:  93 32 60 10  srl  %o1, 0x10, %o1
a009ccec:  9a 14 23 e0  or  %l0, 0x3e0, %o5
a009ccf0:  82 5c e1 90  smul  %l3, 0x190, %g1
a009ccf4:  82 00 40 0d  add  %g1, %o5, %g1
a009ccf8:  c2 08 60 06  ldub  [ %g1 + 6 ], %g1
a009ccfc:  80 a0 00 01  cmp  %g0, %g1
a009cd00:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a009cd04:  9a 40 20 00  addx  %g0, 0, %o5
a009cd08:  82 10 60 b0  or  %g1, 0xb0, %g1
a009cd0c:  da 28 40 13  stb  %o5, [ %g1 + %l3 ]
a009cd10:  19 2a 01 f5  sethi  %hi(0xa807d400), %o4
a009cd14:  a2 0d 20 ff  and  %l4, 0xff, %l1
a009cd18:  82 13 23 e0  or  %o4, 0x3e0, %g1
a009cd1c:  9a 5c 61 90  smul  %l1, 0x190, %o5
a009cd20:  9a 03 40 01  add  %o5, %g1, %o5
a009cd24:  c2 0b 60 2d  ldub  [ %o5 + 0x2d ], %g1
a009cd28:  80 a0 60 00  cmp  %g1, 0
a009cd2c:  12 80 00 10  bne  0xa009cd6c
a009cd30:  a4 10 20 00  clr  %l2
a009cd34:  c2 0b 60 06  ldub  [ %o5 + 6 ], %g1
a009cd38:  80 a0 60 00  cmp  %g1, 0
a009cd3c:  32 80 00 0d  bne,a   0xa009cd70
a009cd40:  9a 13 23 e0  or  %o4, 0x3e0, %o5
a009cd44:  83 2d 60 10  sll  %l5, 0x10, %g1
a009cd48:  83 30 60 10  srl  %g1, 0x10, %g1
a009cd4c:  da 13 60 1c  lduh  [ %o5 + 0x1c ], %o5
a009cd50:  9a 23 40 01  sub  %o5, %g1, %o5
a009cd54:  83 3b 60 1f  sra  %o5, 0x1f, %g1
a009cd58:  9a 18 40 0d  xor  %g1, %o5, %o5
a009cd5c:  9a 23 40 01  sub  %o5, %g1, %o5
a009cd60:  80 a3 60 05  cmp  %o5, 5
a009cd64:  34 80 00 33  bg,a   0xa009ce30
a009cd68:  19 33 c0 f2  sethi  %hi(0xcf03c800), %o4
a009cd6c:  9a 13 23 e0  or  %o4, 0x3e0, %o5	! 0xcf03cbe0
a009cd70:  82 5c 61 90  smul  %l1, 0x190, %g1
a009cd74:  a0 00 40 0d  add  %g1, %o5, %l0
a009cd78:  9b 2d e0 10  sll  %l7, 0x10, %o5
a009cd7c:  9b 33 60 10  srl  %o5, 0x10, %o5
a009cd80:  c2 14 20 1e  lduh  [ %l0 + 0x1e ], %g1
a009cd84:  82 20 40 0d  sub  %g1, %o5, %g1
a009cd88:  9b 38 60 1f  sra  %g1, 0x1f, %o5
a009cd8c:  82 1b 40 01  xor  %o5, %g1, %g1
a009cd90:  82 20 40 0d  sub  %g1, %o5, %g1
a009cd94:  80 a0 60 01  cmp  %g1, 1
a009cd98:  04 80 00 07  ble  0xa009cdb4
a009cd9c:  83 2f 60 10  sll  %i5, 0x10, %g1
a009cda0:  c2 0c 20 2d  ldub  [ %l0 + 0x2d ], %g1
a009cda4:  80 a0 60 00  cmp  %g1, 0
a009cda8:  02 80 00 22  be  0xa009ce30
a009cdac:  19 33 c0 f2  sethi  %hi(0xcf03c800), %o4
a009cdb0:  83 2f 60 10  sll  %i5, 0x10, %g1
a009cdb4:  83 30 60 10  srl  %g1, 0x10, %g1
a009cdb8:  da 14 20 20  lduh  [ %l0 + 0x20 ], %o5
a009cdbc:  9a 23 40 01  sub  %o5, %g1, %o5
a009cdc0:  83 3b 60 1f  sra  %o5, 0x1f, %g1
a009cdc4:  9a 18 40 0d  xor  %g1, %o5, %o5
a009cdc8:  9a 23 40 01  sub  %o5, %g1, %o5
a009cdcc:  80 a3 60 01  cmp  %o5, 1
a009cdd0:  14 80 00 18  bg  0xa009ce30
a009cdd4:  19 33 c0 f2  sethi  %hi(0xcf03c800), %o4
a009cdd8:  7f ff ec 3e  call  0xa0097ed0
a009cddc:  90 10 00 11  mov  %l1, %o0
a009cde0:  90 0a 20 ff  and  %o0, 0xff, %o0
a009cde4:  c2 0c 20 18  ldub  [ %l0 + 0x18 ], %g1
a009cde8:  80 a0 40 08  cmp  %g1, %o0
a009cdec:  12 80 00 11  bne  0xa009ce30
a009cdf0:  19 33 c0 f2  sethi  %hi(0xcf03c800), %o4
a009cdf4:  82 04 40 11  add  %l1, %l1, %g1
a009cdf8:  82 00 40 11  add  %g1, %l1, %g1
a009cdfc:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a009ce00:  83 28 60 03  sll  %g1, 3, %g1
a009ce04:  9a 13 62 50  or  %o5, 0x250, %o5
a009ce08:  82 00 40 0d  add  %g1, %o5, %g1
a009ce0c:  c2 08 60 0a  ldub  [ %g1 + 0xa ], %g1
a009ce10:  80 a0 60 01  cmp  %g1, 1
a009ce14:  02 80 00 08  be  0xa009ce34
a009ce18:  98 13 20 90  or  %o4, 0x90, %o4
a009ce1c:  c2 0c 21 8a  ldub  [ %l0 + 0x18a ], %g1
a009ce20:  80 a0 60 01  cmp  %g1, 1
a009ce24:  12 80 00 4b  bne  0xa009cf50
a009ce28:  80 8c a0 ff  btst  0xff, %l2
a009ce2c:  19 33 c0 f2  sethi  %hi(0xcf03c800), %o4
a009ce30:  98 13 20 90  or  %o4, 0x90, %o4	! 0xcf03c890
a009ce34:  a0 0d 20 ff  and  %l4, 0xff, %l0
a009ce38:  9a 10 20 04  mov  4, %o5
a009ce3c:  c2 03 00 00  ld  [ %o4 ], %g1
a009ce40:  9b 2b 40 10  sll  %o5, %l0, %o5
a009ce44:  82 10 40 0d  or  %g1, %o5, %g1
a009ce48:  c2 23 00 00  st  %g1, [ %o4 ]
a009ce4c:  40 00 52 bf  call  0xa00b1948
a009ce50:  23 2a 01 f5  sethi  %hi(0xa807d400), %l1
a009ce54:  9a 14 63 e0  or  %l1, 0x3e0, %o5	! 0xa807d7e0
a009ce58:  82 5c 21 90  smul  %l0, 0x190, %g1
a009ce5c:  98 00 40 0d  add  %g1, %o5, %o4
a009ce60:  9f 2d e0 10  sll  %l7, 0x10, %o7
a009ce64:  d2 13 20 1e  lduh  [ %o4 + 0x1e ], %o1
a009ce68:  95 33 e0 10  srl  %o7, 0x10, %o2
a009ce6c:  82 22 40 0a  sub  %o1, %o2, %g1
a009ce70:  9b 38 60 1f  sra  %g1, 0x1f, %o5
a009ce74:  82 1b 40 01  xor  %o5, %g1, %g1
a009ce78:  82 20 40 0d  sub  %g1, %o5, %g1
a009ce7c:  80 a0 60 01  cmp  %g1, 1
a009ce80:  04 80 00 33  ble  0xa009cf4c
a009ce84:  a4 10 20 01  mov  1, %l2
a009ce88:  d6 13 20 1a  lduh  [ %o4 + 0x1a ], %o3
a009ce8c:  91 2d a0 10  sll  %l6, 0x10, %o0
a009ce90:  99 32 20 10  srl  %o0, 0x10, %o4
a009ce94:  82 22 c0 0c  sub  %o3, %o4, %g1
a009ce98:  9b 38 60 1f  sra  %g1, 0x1f, %o5
a009ce9c:  82 1b 40 01  xor  %o5, %g1, %g1
a009cea0:  82 20 40 0d  sub  %g1, %o5, %g1
a009cea4:  80 a0 60 05  cmp  %g1, 5
a009cea8:  04 80 00 2a  ble  0xa009cf50
a009ceac:  80 8c a0 ff  btst  0xff, %l2
a009ceb0:  82 02 80 0a  add  %o2, %o2, %g1
a009ceb4:  80 a2 40 01  cmp  %o1, %g1
a009ceb8:  12 80 00 08  bne  0xa009ced8
a009cebc:  9a 14 63 e0  or  %l1, 0x3e0, %o5
a009cec0:  82 03 00 0c  add  %o4, %o4, %g1
a009cec4:  80 a2 c0 01  cmp  %o3, %g1
a009cec8:  12 80 00 05  bne  0xa009cedc
a009cecc:  82 5c 21 90  smul  %l0, 0x190, %g1
a009ced0:  10 80 00 0f  b  0xa009cf0c
a009ced4:  a4 10 20 00  clr  %l2
a009ced8:  82 5c 21 90  smul  %l0, 0x190, %g1
a009cedc:  98 00 40 0d  add  %g1, %o5, %o4
a009cee0:  9b 33 e0 11  srl  %o7, 0x11, %o5
a009cee4:  c2 13 20 1e  lduh  [ %o4 + 0x1e ], %g1
a009cee8:  80 a0 40 0d  cmp  %g1, %o5
a009ceec:  12 80 00 09  bne  0xa009cf10
a009cef0:  80 8c a0 ff  btst  0xff, %l2
a009cef4:  c2 13 20 1a  lduh  [ %o4 + 0x1a ], %g1
a009cef8:  9b 32 20 11  srl  %o0, 0x11, %o5
a009cefc:  82 18 40 0d  xor  %g1, %o5, %g1
a009cf00:  80 a0 00 01  cmp  %g0, %g1
a009cf04:  82 60 20 00  subx  %g0, 0, %g1
a009cf08:  a4 08 40 12  and  %g1, %l2, %l2
a009cf0c:  80 8c a0 ff  btst  0xff, %l2
a009cf10:  32 80 00 13  bne,a   0xa009cf5c
a009cf14:  25 2a 01 f5  sethi  %hi(0xa807d400), %l2
a009cf18:  9a 0d 20 ff  and  %l4, 0xff, %o5
a009cf1c:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a009cf20:  9a 5b 61 90  smul  %o5, 0x190, %o5
a009cf24:  92 05 20 41  add  %l4, 0x41, %o1
a009cf28:  82 10 63 e0  or  %g1, 0x3e0, %g1
a009cf2c:  9a 03 40 01  add  %o5, %g1, %o5
a009cf30:  93 2a 60 18  sll  %o1, 0x18, %o1
a009cf34:  11 28 01 a9  sethi  %hi(0xa006a400), %o0
a009cf38:  ee 33 60 1e  sth  %l7, [ %o5 + 0x1e ]
a009cf3c:  ec 33 60 1a  sth  %l6, [ %o5 + 0x1a ]
a009cf40:  90 12 23 b0  or  %o0, 0x3b0, %o0
a009cf44:  7f ff 58 40  call  0xa0073044
a009cf48:  93 3a 60 18  sra  %o1, 0x18, %o1
a009cf4c:  80 8c a0 ff  btst  0xff, %l2
a009cf50:  02 80 00 e8  be  0xa009d2f0
a009cf54:  b0 10 20 00  clr  %i0
a009cf58:  25 2a 01 f5  sethi  %hi(0xa807d400), %l2
a009cf5c:  a0 0d 20 ff  and  %l4, 0xff, %l0
a009cf60:  9a 14 a3 e0  or  %l2, 0x3e0, %o5
a009cf64:  82 5c 21 90  smul  %l0, 0x190, %g1
a009cf68:  82 00 40 0d  add  %g1, %o5, %g1
a009cf6c:  9b 2d a0 10  sll  %l6, 0x10, %o5
a009cf70:  9b 33 60 10  srl  %o5, 0x10, %o5
a009cf74:  c2 10 60 1a  lduh  [ %g1 + 0x1a ], %g1
a009cf78:  82 20 40 0d  sub  %g1, %o5, %g1
a009cf7c:  9b 38 60 1f  sra  %g1, 0x1f, %o5
a009cf80:  82 1b 40 01  xor  %o5, %g1, %g1
a009cf84:  94 20 40 0d  sub  %g1, %o5, %o2
a009cf88:  80 a2 a0 05  cmp  %o2, 5
a009cf8c:  04 80 00 0e  ble  0xa009cfc4
a009cf90:  9a 14 a3 e0  or  %l2, 0x3e0, %o5
a009cf94:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009cf98:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a009cf9c:  80 88 60 04  btst  4, %g1
a009cfa0:  02 80 00 0a  be  0xa009cfc8
a009cfa4:  82 5c 21 90  smul  %l0, 0x190, %g1
a009cfa8:  92 05 20 41  add  %l4, 0x41, %o1
a009cfac:  93 2a 60 18  sll  %o1, 0x18, %o1
a009cfb0:  11 28 01 a9  sethi  %hi(0xa006a400), %o0
a009cfb4:  90 12 23 e0  or  %o0, 0x3e0, %o0	! 0xa006a7e0
a009cfb8:  7f ff 58 23  call  0xa0073044
a009cfbc:  93 3a 60 18  sra  %o1, 0x18, %o1
a009cfc0:  9a 14 a3 e0  or  %l2, 0x3e0, %o5
a009cfc4:  82 5c 21 90  smul  %l0, 0x190, %g1
a009cfc8:  82 00 40 0d  add  %g1, %o5, %g1
a009cfcc:  9b 2d 60 10  sll  %l5, 0x10, %o5
a009cfd0:  9b 33 60 10  srl  %o5, 0x10, %o5
a009cfd4:  c2 10 60 1c  lduh  [ %g1 + 0x1c ], %g1
a009cfd8:  82 20 40 0d  sub  %g1, %o5, %g1
a009cfdc:  9b 38 60 1f  sra  %g1, 0x1f, %o5
a009cfe0:  82 1b 40 01  xor  %o5, %g1, %g1
a009cfe4:  94 20 40 0d  sub  %g1, %o5, %o2
a009cfe8:  80 a2 a0 05  cmp  %o2, 5
a009cfec:  04 80 00 0e  ble  0xa009d024
a009cff0:  9a 14 a3 e0  or  %l2, 0x3e0, %o5
a009cff4:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009cff8:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a009cffc:  80 88 60 04  btst  4, %g1
a009d000:  02 80 00 0a  be  0xa009d028
a009d004:  82 5c 21 90  smul  %l0, 0x190, %g1
a009d008:  92 05 20 41  add  %l4, 0x41, %o1
a009d00c:  93 2a 60 18  sll  %o1, 0x18, %o1
a009d010:  11 28 01 aa  sethi  %hi(0xa006a800), %o0
a009d014:  90 12 20 08  or  %o0, 8, %o0	! 0xa006a808
a009d018:  7f ff 58 0b  call  0xa0073044
a009d01c:  93 3a 60 18  sra  %o1, 0x18, %o1
a009d020:  9a 14 a3 e0  or  %l2, 0x3e0, %o5
a009d024:  82 5c 21 90  smul  %l0, 0x190, %g1
a009d028:  82 00 40 0d  add  %g1, %o5, %g1
a009d02c:  9b 2d e0 10  sll  %l7, 0x10, %o5
a009d030:  9b 33 60 10  srl  %o5, 0x10, %o5
a009d034:  c2 10 60 1e  lduh  [ %g1 + 0x1e ], %g1
a009d038:  82 20 40 0d  sub  %g1, %o5, %g1
a009d03c:  9b 38 60 1f  sra  %g1, 0x1f, %o5
a009d040:  82 1b 40 01  xor  %o5, %g1, %g1
a009d044:  94 20 40 0d  sub  %g1, %o5, %o2
a009d048:  80 a2 a0 01  cmp  %o2, 1
a009d04c:  04 80 00 0e  ble  0xa009d084
a009d050:  9a 14 a3 e0  or  %l2, 0x3e0, %o5
a009d054:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009d058:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a009d05c:  80 88 60 04  btst  4, %g1
a009d060:  02 80 00 0a  be  0xa009d088
a009d064:  82 5c 21 90  smul  %l0, 0x190, %g1
a009d068:  92 05 20 41  add  %l4, 0x41, %o1
a009d06c:  93 2a 60 18  sll  %o1, 0x18, %o1
a009d070:  11 28 01 aa  sethi  %hi(0xa006a800), %o0
a009d074:  90 12 20 30  or  %o0, 0x30, %o0	! 0xa006a830
a009d078:  7f ff 57 f3  call  0xa0073044
a009d07c:  93 3a 60 18  sra  %o1, 0x18, %o1
a009d080:  9a 14 a3 e0  or  %l2, 0x3e0, %o5
a009d084:  82 5c 21 90  smul  %l0, 0x190, %g1
a009d088:  82 00 40 0d  add  %g1, %o5, %g1
a009d08c:  9b 2f 60 10  sll  %i5, 0x10, %o5
a009d090:  9b 33 60 10  srl  %o5, 0x10, %o5
a009d094:  c2 10 60 20  lduh  [ %g1 + 0x20 ], %g1
a009d098:  82 20 40 0d  sub  %g1, %o5, %g1
a009d09c:  9b 38 60 1f  sra  %g1, 0x1f, %o5
a009d0a0:  82 1b 40 01  xor  %o5, %g1, %g1
a009d0a4:  94 20 40 0d  sub  %g1, %o5, %o2
a009d0a8:  80 a2 a0 01  cmp  %o2, 1
a009d0ac:  04 80 00 0e  ble  0xa009d0e4
a009d0b0:  82 5c 21 90  smul  %l0, 0x190, %g1
a009d0b4:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009d0b8:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a009d0bc:  80 88 60 04  btst  4, %g1
a009d0c0:  02 80 00 09  be  0xa009d0e4
a009d0c4:  82 5c 21 90  smul  %l0, 0x190, %g1
a009d0c8:  92 05 20 41  add  %l4, 0x41, %o1
a009d0cc:  93 2a 60 18  sll  %o1, 0x18, %o1
a009d0d0:  11 28 01 aa  sethi  %hi(0xa006a800), %o0
a009d0d4:  90 12 20 58  or  %o0, 0x58, %o0	! 0xa006a858
a009d0d8:  7f ff 57 db  call  0xa0073044
a009d0dc:  93 3a 60 18  sra  %o1, 0x18, %o1
a009d0e0:  82 5c 21 90  smul  %l0, 0x190, %g1
a009d0e4:  9a 14 a3 e0  or  %l2, 0x3e0, %o5
a009d0e8:  a2 00 40 0d  add  %g1, %o5, %l1
a009d0ec:  7f ff eb 79  call  0xa0097ed0
a009d0f0:  90 10 00 10  mov  %l0, %o0
a009d0f4:  90 0a 20 ff  and  %o0, 0xff, %o0
a009d0f8:  c2 0c 60 18  ldub  [ %l1 + 0x18 ], %g1
a009d0fc:  80 a0 40 08  cmp  %g1, %o0
a009d100:  02 80 00 10  be  0xa009d140
a009d104:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009d108:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a009d10c:  80 88 60 04  btst  4, %g1
a009d110:  02 80 00 0d  be  0xa009d144
a009d114:  82 04 00 10  add  %l0, %l0, %g1
a009d118:  7f ff eb 6e  call  0xa0097ed0
a009d11c:  90 10 00 10  mov  %l0, %o0
a009d120:  92 05 20 41  add  %l4, 0x41, %o1
a009d124:  96 0a 20 ff  and  %o0, 0xff, %o3
a009d128:  93 2a 60 18  sll  %o1, 0x18, %o1
a009d12c:  11 28 01 aa  sethi  %hi(0xa006a800), %o0
a009d130:  90 12 20 80  or  %o0, 0x80, %o0	! 0xa006a880
a009d134:  93 3a 60 18  sra  %o1, 0x18, %o1
a009d138:  7f ff 57 c3  call  0xa0073044
a009d13c:  d4 0c 60 18  ldub  [ %l1 + 0x18 ], %o2
a009d140:  82 04 00 10  add  %l0, %l0, %g1
a009d144:  82 00 40 10  add  %g1, %l0, %g1
a009d148:  23 2a 01 f5  sethi  %hi(0xa807d400), %l1
a009d14c:  83 28 60 03  sll  %g1, 3, %g1
a009d150:  9a 14 62 50  or  %l1, 0x250, %o5
a009d154:  82 00 40 0d  add  %g1, %o5, %g1
a009d158:  c2 08 60 0a  ldub  [ %g1 + 0xa ], %g1
a009d15c:  80 a0 60 01  cmp  %g1, 1
a009d160:  12 80 00 0e  bne  0xa009d198
a009d164:  82 04 00 10  add  %l0, %l0, %g1
a009d168:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009d16c:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a009d170:  80 88 60 04  btst  4, %g1
a009d174:  02 80 00 09  be  0xa009d198
a009d178:  82 04 00 10  add  %l0, %l0, %g1
a009d17c:  92 05 20 41  add  %l4, 0x41, %o1
a009d180:  93 2a 60 18  sll  %o1, 0x18, %o1
a009d184:  11 28 01 aa  sethi  %hi(0xa006a800), %o0
a009d188:  90 12 20 b0  or  %o0, 0xb0, %o0	! 0xa006a8b0
a009d18c:  7f ff 57 ae  call  0xa0073044
a009d190:  93 3a 60 18  sra  %o1, 0x18, %o1
a009d194:  82 04 00 10  add  %l0, %l0, %g1
a009d198:  82 00 40 10  add  %g1, %l0, %g1
a009d19c:  9a 14 62 50  or  %l1, 0x250, %o5
a009d1a0:  83 28 60 03  sll  %g1, 3, %g1
a009d1a4:  82 00 40 0d  add  %g1, %o5, %g1
a009d1a8:  c2 08 60 14  ldub  [ %g1 + 0x14 ], %g1
a009d1ac:  80 a0 60 00  cmp  %g1, 0
a009d1b0:  12 80 00 11  bne  0xa009d1f4
a009d1b4:  82 14 a3 e0  or  %l2, 0x3e0, %g1
a009d1b8:  92 05 20 41  add  %l4, 0x41, %o1
a009d1bc:  93 2a 60 18  sll  %o1, 0x18, %o1
a009d1c0:  11 28 01 aa  sethi  %hi(0xa006a800), %o0
a009d1c4:  90 12 20 d8  or  %o0, 0xd8, %o0	! 0xa006a8d8
a009d1c8:  7f ff 57 9f  call  0xa0073044
a009d1cc:  93 3a 60 18  sra  %o1, 0x18, %o1
a009d1d0:  9a 0f 20 ff  and  %i4, 0xff, %o5
a009d1d4:  82 03 40 0d  add  %o5, %o5, %g1
a009d1d8:  82 00 40 0d  add  %g1, %o5, %g1
a009d1dc:  1b 2a 01 f3  sethi  %hi(0xa807cc00), %o5
a009d1e0:  83 28 60 03  sll  %g1, 3, %g1
a009d1e4:  9a 13 60 64  or  %o5, 0x64, %o5
a009d1e8:  82 00 40 0d  add  %g1, %o5, %g1
a009d1ec:  c0 28 60 01  clrb  [ %g1 + 1 ]
a009d1f0:  82 14 a3 e0  or  %l2, 0x3e0, %g1
a009d1f4:  9a 5c 21 90  smul  %l0, 0x190, %o5
a009d1f8:  98 03 40 01  add  %o5, %g1, %o4
a009d1fc:  c2 0b 21 8a  ldub  [ %o4 + 0x18a ], %g1
a009d200:  80 a0 60 01  cmp  %g1, 1
a009d204:  12 80 00 15  bne  0xa009d258
a009d208:  01 00 00 00  nop
a009d20c:  82 0f 20 ff  and  %i4, 0xff, %g1
a009d210:  9a 00 40 01  add  %g1, %g1, %o5
a009d214:  9a 03 40 01  add  %o5, %g1, %o5
a009d218:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a009d21c:  82 10 60 64  or  %g1, 0x64, %g1	! 0xa807cc64
a009d220:  9b 2b 60 03  sll  %o5, 3, %o5
a009d224:  9a 03 40 01  add  %o5, %g1, %o5
a009d228:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009d22c:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a009d230:  c0 2b 21 8a  clrb  [ %o4 + 0x18a ]
a009d234:  80 88 60 04  btst  4, %g1
a009d238:  02 80 00 08  be  0xa009d258
a009d23c:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a009d240:  92 05 20 41  add  %l4, 0x41, %o1
a009d244:  93 2a 60 18  sll  %o1, 0x18, %o1
a009d248:  11 28 01 aa  sethi  %hi(0xa006a800), %o0
a009d24c:  90 12 20 f8  or  %o0, 0xf8, %o0	! 0xa006a8f8
a009d250:  7f ff 57 7d  call  0xa0073044
a009d254:  93 3a 60 18  sra  %o1, 0x18, %o1
a009d258:  7f ff fd 89  call  0xa009c87c
a009d25c:  90 10 00 10  mov  %l0, %o0
a009d260:  82 14 a3 e0  or  %l2, 0x3e0, %g1
a009d264:  9a 5c 21 90  smul  %l0, 0x190, %o5
a009d268:  9a 03 40 01  add  %o5, %g1, %o5
a009d26c:  c2 0b 60 02  ldub  [ %o5 + 2 ], %g1
a009d270:  80 a0 60 00  cmp  %g1, 0
a009d274:  02 80 00 14  be  0xa009d2c4
a009d278:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009d27c:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a009d280:  80 88 60 04  btst  4, %g1
a009d284:  02 80 00 09  be  0xa009d2a8
a009d288:  90 10 00 10  mov  %l0, %o0
a009d28c:  92 05 20 41  add  %l4, 0x41, %o1
a009d290:  93 2a 60 18  sll  %o1, 0x18, %o1
a009d294:  11 28 01 aa  sethi  %hi(0xa006a800), %o0
a009d298:  90 12 21 30  or  %o0, 0x130, %o0	! 0xa006a930
a009d29c:  7f ff 57 6a  call  0xa0073044
a009d2a0:  93 3a 60 18  sra  %o1, 0x18, %o1
a009d2a4:  90 10 00 10  mov  %l0, %o0
a009d2a8:  40 00 0e 1a  call  0xa00a0b10
a009d2ac:  92 10 20 00  clr  %o1
a009d2b0:  90 10 00 10  mov  %l0, %o0
a009d2b4:  7f ff e4 24  call  0xa0096344
a009d2b8:  92 10 20 00  clr  %o1
a009d2bc:  10 80 00 0d  b  0xa009d2f0
a009d2c0:  b0 10 20 01  mov  1, %i0
a009d2c4:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1
a009d2c8:  80 88 60 04  btst  4, %g1
a009d2cc:  02 80 00 09  be  0xa009d2f0
a009d2d0:  b0 10 20 01  mov  1, %i0
a009d2d4:  92 05 20 41  add  %l4, 0x41, %o1
a009d2d8:  93 2a 60 18  sll  %o1, 0x18, %o1
a009d2dc:  11 28 01 aa  sethi  %hi(0xa006a800), %o0
a009d2e0:  90 12 21 70  or  %o0, 0x170, %o0	! 0xa006a970
a009d2e4:  7f ff 57 58  call  0xa0073044
a009d2e8:  93 3a 60 18  sra  %o1, 0x18, %o1
a009d2ec:  b0 10 20 01  mov  1, %i0
a009d2f0:  81 c7 e0 08  ret
a009d2f4:  81 e8 00 00  restore
