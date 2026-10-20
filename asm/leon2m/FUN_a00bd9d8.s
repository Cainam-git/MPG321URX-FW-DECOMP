# leon2m FUN_a00bd9d8 0xa00bd9d8-0xa00bdb48 (368 bytes)
a00bd9d8:  9d e3 bf 98  save  %sp, -104, %sp
a00bd9dc:  92 10 20 00  clr  %o1
a00bd9e0:  40 02 5b 17  call  0xa015463c
a00bd9e4:  90 10 20 2e  mov  0x2e, %o0
a00bd9e8:  35 2a 00 b4  sethi  %hi(0xa802d000), %i2
a00bd9ec:  d0 2e a0 78  stb  %o0, [ %i2 + 0x78 ]	! 0xa802d078
a00bd9f0:  b2 16 a0 78  or  %i2, 0x78, %i1
a00bd9f4:  90 10 20 62  mov  0x62, %o0
a00bd9f8:  d0 2e 60 01  stb  %o0, [ %i1 + 1 ]
a00bd9fc:  92 10 20 02  mov  2, %o1
a00bda00:  40 02 5b 0f  call  0xa015463c
a00bda04:  90 10 20 2e  mov  0x2e, %o0
a00bda08:  d0 2e 60 02  stb  %o0, [ %i1 + 2 ]
a00bda0c:  92 10 20 03  mov  3, %o1
a00bda10:  40 02 5b 0b  call  0xa015463c
a00bda14:  90 10 20 2e  mov  0x2e, %o0
a00bda18:  d0 2e 60 03  stb  %o0, [ %i1 + 3 ]
a00bda1c:  92 10 20 04  mov  4, %o1
a00bda20:  40 02 5b 07  call  0xa015463c
a00bda24:  90 10 20 2e  mov  0x2e, %o0
a00bda28:  d0 2e 60 04  stb  %o0, [ %i1 + 4 ]
a00bda2c:  92 10 20 05  mov  5, %o1
a00bda30:  40 02 5b 03  call  0xa015463c
a00bda34:  90 10 20 2e  mov  0x2e, %o0
a00bda38:  d0 2e 60 05  stb  %o0, [ %i1 + 5 ]
a00bda3c:  90 10 20 2e  mov  0x2e, %o0
a00bda40:  40 02 5a ff  call  0xa015463c
a00bda44:  92 10 20 06  mov  6, %o1
a00bda48:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00bda4c:  82 10 62 74  or  %g1, 0x274, %g1	! 0xa802d274
a00bda50:  da 08 60 02  ldub  [ %g1 + 2 ], %o5
a00bda54:  d0 2e 60 06  stb  %o0, [ %i1 + 6 ]
a00bda58:  80 a3 60 00  cmp  %o5, 0
a00bda5c:  08 80 00 0e  bleu  0xa00bda94
a00bda60:  94 10 20 00  clr  %o2
a00bda64:  9e 10 00 19  mov  %i1, %o7
a00bda68:  90 10 00 01  mov  %g1, %o0
a00bda6c:  92 10 00 0d  mov  %o5, %o1
a00bda70:  96 10 20 00  clr  %o3
a00bda74:  b2 02 c0 08  add  %o3, %o0, %i1
a00bda78:  98 02 c0 0f  add  %o3, %o7, %o4
a00bda7c:  94 02 a0 01  inc  %o2
a00bda80:  da 0e 60 03  ldub  [ %i1 + 3 ], %o5
a00bda84:  96 0a a0 ff  and  %o2, 0xff, %o3
a00bda88:  80 a2 40 0b  cmp  %o1, %o3
a00bda8c:  18 bf ff fa  bgu  0xa00bda74
a00bda90:  da 2b 20 07  stb  %o5, [ %o4 + 7 ]
a00bda94:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bda98:  92 16 a0 78  or  %i2, 0x78, %o1
a00bda9c:  94 10 20 0d  mov  0xd, %o2
a00bdaa0:  80 a6 20 02  cmp  %i0, 2
a00bdaa4:  02 80 00 10  be  0xa00bdae4
a00bdaa8:  d4 2a 60 14  stb  %o2, [ %o1 + 0x14 ]
a00bdaac:  80 a6 20 03  cmp  %i0, 3
a00bdab0:  02 80 00 19  be  0xa00bdb14
a00bdab4:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00bdab8:  33 2a 00 ac  sethi  %hi(0xa802b000), %i1
a00bdabc:  c0 2e 60 9c  clrb  [ %i1 + 0x9c ]	! 0xa802b09c
a00bdac0:  9a 13 20 d0  or  %o4, 0xd0, %o5
a00bdac4:  c0 2b 20 d0  clrb  [ %o4 + 0xd0 ]
a00bdac8:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00bdacc:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00bdad0:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00bdad4:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00bdad8:  b4 16 a0 78  or  %i2, 0x78, %i2
a00bdadc:  40 02 2b 43  call  0xa01487e8
a00bdae0:  93 e8 20 15  restore  %g0, 0x15, %o1
a00bdae4:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00bdae8:  1f 2a 00 ac  sethi  %hi(0xa802b000), %o7
a00bdaec:  9a 12 e0 40  or  %o3, 0x40, %o5
a00bdaf0:  c0 2b e0 9a  clrb  [ %o7 + 0x9a ]
a00bdaf4:  c0 2a e0 40  clrb  [ %o3 + 0x40 ]
a00bdaf8:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00bdafc:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00bdb00:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00bdb04:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00bdb08:  b4 16 a0 78  or  %i2, 0x78, %i2
a00bdb0c:  40 02 2b 37  call  0xa01487e8
a00bdb10:  93 e8 20 15  restore  %g0, 0x15, %o1
a00bdb14:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00bdb18:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00bdb1c:  9a 12 20 98  or  %o0, 0x98, %o5
a00bdb20:  c0 28 60 98  clrb  [ %g1 + 0x98 ]
a00bdb24:  c0 2a 20 98  clrb  [ %o0 + 0x98 ]
a00bdb28:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00bdb2c:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00bdb30:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00bdb34:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00bdb38:  b4 16 a0 78  or  %i2, 0x78, %i2
a00bdb3c:  40 02 2b 2b  call  0xa01487e8
a00bdb40:  93 e8 20 15  restore  %g0, 0x15, %o1
a00bdb44:  01 00 00 00  nop
