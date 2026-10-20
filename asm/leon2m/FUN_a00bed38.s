# leon2m FUN_a00bed38 0xa00bed38-0xa00bee64 (300 bytes)
a00bed38:  9d e3 bf 98  save  %sp, -104, %sp
a00bed3c:  35 2a 00 b4  sethi  %hi(0xa802d000), %i2
a00bed40:  a0 16 a0 78  or  %i2, 0x78, %l0	! 0xa802d078
a00bed44:  9a 10 20 30  mov  0x30, %o5
a00bed48:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00bed4c:  da 2c 20 08  stb  %o5, [ %l0 + 8 ]
a00bed50:  da 2c 20 07  stb  %o5, [ %l0 + 7 ]
a00bed54:  40 02 16 2a  call  0xa01445fc
a00bed58:  d0 0a a2 ae  ldub  [ %o2 + 0x2ae ], %o0
a00bed5c:  92 02 20 30  add  %o0, 0x30, %o1
a00bed60:  d2 2c 20 09  stb  %o1, [ %l0 + 9 ]
a00bed64:  92 10 20 00  clr  %o1
a00bed68:  40 02 56 35  call  0xa015463c
a00bed6c:  90 10 20 35  mov  0x35, %o0
a00bed70:  d0 2e a0 78  stb  %o0, [ %i2 + 0x78 ]
a00bed74:  90 10 20 62  mov  0x62, %o0
a00bed78:  d0 2c 20 01  stb  %o0, [ %l0 + 1 ]
a00bed7c:  92 10 20 02  mov  2, %o1
a00bed80:  40 02 56 2f  call  0xa015463c
a00bed84:  90 10 20 35  mov  0x35, %o0
a00bed88:  d0 2c 20 02  stb  %o0, [ %l0 + 2 ]
a00bed8c:  92 10 20 03  mov  3, %o1
a00bed90:  40 02 56 2b  call  0xa015463c
a00bed94:  90 10 20 35  mov  0x35, %o0
a00bed98:  d0 2c 20 03  stb  %o0, [ %l0 + 3 ]
a00bed9c:  92 10 20 04  mov  4, %o1
a00beda0:  40 02 56 27  call  0xa015463c
a00beda4:  90 10 20 35  mov  0x35, %o0
a00beda8:  d0 2c 20 04  stb  %o0, [ %l0 + 4 ]
a00bedac:  92 10 20 05  mov  5, %o1
a00bedb0:  40 02 56 23  call  0xa015463c
a00bedb4:  90 10 20 35  mov  0x35, %o0
a00bedb8:  d0 2c 20 05  stb  %o0, [ %l0 + 5 ]
a00bedbc:  92 10 20 06  mov  6, %o1
a00bedc0:  40 02 56 1f  call  0xa015463c
a00bedc4:  90 10 20 35  mov  0x35, %o0
a00bedc8:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00bedcc:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bedd0:  82 10 20 0d  mov  0xd, %g1
a00bedd4:  9a 13 20 40  or  %o4, 0x40, %o5
a00bedd8:  c2 2c 20 0a  stb  %g1, [ %l0 + 0xa ]
a00beddc:  80 a6 20 02  cmp  %i0, 2
a00bede0:  02 80 00 12  be  0xa00bee28
a00bede4:  d0 2c 20 06  stb  %o0, [ %l0 + 6 ]
a00bede8:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00bedec:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00bedf0:  96 12 a0 98  or  %o2, 0x98, %o3
a00bedf4:  80 a6 20 03  cmp  %i0, 3
a00bedf8:  02 80 00 10  be  0xa00bee38
a00bedfc:  9a 13 20 d0  or  %o4, 0xd0, %o5
a00bee00:  1f 2a 00 ac  sethi  %hi(0xa802b000), %o7
a00bee04:  c0 2b e0 9c  clrb  [ %o7 + 0x9c ]	! 0xa802b09c
a00bee08:  c0 2b 20 d0  clrb  [ %o4 + 0xd0 ]
a00bee0c:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00bee10:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00bee14:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00bee18:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00bee1c:  b4 16 a0 78  or  %i2, 0x78, %i2
a00bee20:  40 02 26 72  call  0xa01487e8
a00bee24:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bee28:  17 2a 00 ac  sethi  %hi(0xa802b000), %o3
a00bee2c:  c0 2a e0 9a  clrb  [ %o3 + 0x9a ]	! 0xa802b09a
a00bee30:  10 bf ff f7  b  0xa00bee0c
a00bee34:  c0 2b 20 40  clrb  [ %o4 + 0x40 ]
a00bee38:  19 2a 00 ac  sethi  %hi(0xa802b000), %o4
a00bee3c:  c0 2b 20 98  clrb  [ %o4 + 0x98 ]	! 0xa802b098
a00bee40:  c0 2a a0 98  clrb  [ %o2 + 0x98 ]
a00bee44:  c0 2a e0 19  clrb  [ %o3 + 0x19 ]
a00bee48:  c0 2a e0 01  clrb  [ %o3 + 1 ]
a00bee4c:  c0 2a e0 07  clrb  [ %o3 + 7 ]
a00bee50:  c0 2a e0 0a  clrb  [ %o3 + 0xa ]
a00bee54:  b4 16 a0 78  or  %i2, 0x78, %i2
a00bee58:  40 02 26 64  call  0xa01487e8
a00bee5c:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bee60:  01 00 00 00  nop
