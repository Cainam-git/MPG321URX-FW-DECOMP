# leon2m FUN_a00bc95c 0xa00bc95c-0xa00bcaa8 (332 bytes)
a00bc95c:  9d e3 bf 98  save  %sp, -104, %sp
a00bc960:  13 2a 00 b5  sethi  %hi(0xa802d400), %o1
a00bc964:  03 0a aa aa  sethi  %hi(0x2aaaa800), %g1
a00bc968:  d0 0a 60 12  ldub  [ %o1 + 0x12 ], %o0
a00bc96c:  96 02 20 05  add  %o0, 5, %o3
a00bc970:  a0 10 62 ab  or  %g1, 0x2ab, %l0
a00bc974:  80 5a c0 10  smul  %o3, %l0, %g0
a00bc978:  b5 40 00 00  rd  %y, %i2
a00bc97c:  b2 06 80 1a  add  %i2, %i2, %i1
a00bc980:  9e 06 40 1a  add  %i1, %i2, %o7
a00bc984:  9a 03 c0 0f  add  %o7, %o7, %o5
a00bc988:  35 2a 00 b4  sethi  %hi(0xa802d000), %i2
a00bc98c:  a0 16 a0 78  or  %i2, 0x78, %l0	! 0xa802d078
a00bc990:  94 22 c0 0d  sub  %o3, %o5, %o2
a00bc994:  92 10 20 30  mov  0x30, %o1
a00bc998:  98 02 a0 30  add  %o2, 0x30, %o4
a00bc99c:  d2 2c 20 08  stb  %o1, [ %l0 + 8 ]
a00bc9a0:  d2 2c 20 07  stb  %o1, [ %l0 + 7 ]
a00bc9a4:  d8 2c 20 09  stb  %o4, [ %l0 + 9 ]
a00bc9a8:  92 10 20 00  clr  %o1
a00bc9ac:  40 02 5f 24  call  0xa015463c
a00bc9b0:  90 10 20 13  mov  0x13, %o0
a00bc9b4:  d0 2e a0 78  stb  %o0, [ %i2 + 0x78 ]
a00bc9b8:  90 10 20 62  mov  0x62, %o0
a00bc9bc:  d0 2c 20 01  stb  %o0, [ %l0 + 1 ]
a00bc9c0:  92 10 20 02  mov  2, %o1
a00bc9c4:  40 02 5f 1e  call  0xa015463c
a00bc9c8:  90 10 20 13  mov  0x13, %o0
a00bc9cc:  d0 2c 20 02  stb  %o0, [ %l0 + 2 ]
a00bc9d0:  92 10 20 03  mov  3, %o1
a00bc9d4:  40 02 5f 1a  call  0xa015463c
a00bc9d8:  90 10 20 13  mov  0x13, %o0
a00bc9dc:  d0 2c 20 03  stb  %o0, [ %l0 + 3 ]
a00bc9e0:  92 10 20 04  mov  4, %o1
a00bc9e4:  40 02 5f 16  call  0xa015463c
a00bc9e8:  90 10 20 13  mov  0x13, %o0
a00bc9ec:  d0 2c 20 04  stb  %o0, [ %l0 + 4 ]
a00bc9f0:  92 10 20 05  mov  5, %o1
a00bc9f4:  40 02 5f 12  call  0xa015463c
a00bc9f8:  90 10 20 13  mov  0x13, %o0
a00bc9fc:  d0 2c 20 05  stb  %o0, [ %l0 + 5 ]
a00bca00:  92 10 20 06  mov  6, %o1
a00bca04:  40 02 5f 0e  call  0xa015463c
a00bca08:  90 10 20 13  mov  0x13, %o0
a00bca0c:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00bca10:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bca14:  82 10 20 0d  mov  0xd, %g1
a00bca18:  9a 13 20 40  or  %o4, 0x40, %o5
a00bca1c:  c2 2c 20 0a  stb  %g1, [ %l0 + 0xa ]
a00bca20:  80 a6 20 02  cmp  %i0, 2
a00bca24:  02 80 00 12  be  0xa00bca6c
a00bca28:  d0 2c 20 06  stb  %o0, [ %l0 + 6 ]
a00bca2c:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00bca30:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00bca34:  96 12 a0 98  or  %o2, 0x98, %o3
a00bca38:  80 a6 20 03  cmp  %i0, 3
a00bca3c:  02 80 00 10  be  0xa00bca7c
a00bca40:  9a 13 20 d0  or  %o4, 0xd0, %o5
a00bca44:  17 2a 00 ac  sethi  %hi(0xa802b000), %o3
a00bca48:  c0 2a e0 9c  clrb  [ %o3 + 0x9c ]	! 0xa802b09c
a00bca4c:  c0 2b 20 d0  clrb  [ %o4 + 0xd0 ]
a00bca50:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00bca54:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00bca58:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00bca5c:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00bca60:  b4 16 a0 78  or  %i2, 0x78, %i2
a00bca64:  40 02 2f 61  call  0xa01487e8
a00bca68:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bca6c:  15 2a 00 ac  sethi  %hi(0xa802b000), %o2
a00bca70:  c0 2a a0 9a  clrb  [ %o2 + 0x9a ]	! 0xa802b09a
a00bca74:  10 bf ff f7  b  0xa00bca50
a00bca78:  c0 2b 20 40  clrb  [ %o4 + 0x40 ]
a00bca7c:  19 2a 00 ac  sethi  %hi(0xa802b000), %o4
a00bca80:  c0 2b 20 98  clrb  [ %o4 + 0x98 ]	! 0xa802b098
a00bca84:  c0 2a a0 98  clrb  [ %o2 + 0x98 ]
a00bca88:  c0 2a e0 19  clrb  [ %o3 + 0x19 ]
a00bca8c:  c0 2a e0 01  clrb  [ %o3 + 1 ]
a00bca90:  c0 2a e0 07  clrb  [ %o3 + 7 ]
a00bca94:  c0 2a e0 0a  clrb  [ %o3 + 0xa ]
a00bca98:  b4 16 a0 78  or  %i2, 0x78, %i2
a00bca9c:  40 02 2f 53  call  0xa01487e8
a00bcaa0:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bcaa4:  01 00 00 00  nop
