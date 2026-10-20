# leon2m FUN_a0097f48 0xa0097f48-0xa009811c (468 bytes)
a0097f48:  9d e3 bf 98  save  %sp, -104, %sp
a0097f4c:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a0097f50:  da 04 63 ec  ld  [ %l1 + 0x3ec ], %o5	! 0xa802afec
a0097f54:  21 2a 00 97  sethi  %hi(0xa8025c00), %l0
a0097f58:  82 03 7f 81  add  %o5, -127, %g1
a0097f5c:  d0 0c 20 54  ldub  [ %l0 + 0x54 ], %o0
a0097f60:  80 a0 40 08  cmp  %g1, %o0
a0097f64:  02 80 00 0a  be  0xa0097f8c
a0097f68:  80 a3 60 7f  cmp  %o5, 0x7f
a0097f6c:  40 00 45 14  call  0xa00a93bc
a0097f70:  01 00 00 00  nop
a0097f74:  90 10 20 01  mov  1, %o0	! 0x1
a0097f78:  d2 0c 20 54  ldub  [ %l0 + 0x54 ], %o1
a0097f7c:  40 00 40 70  call  0xa00a813c
a0097f80:  94 10 20 00  clr  %o2
a0097f84:  da 04 63 ec  ld  [ %l1 + 0x3ec ], %o5
a0097f88:  80 a3 60 7f  cmp  %o5, 0x7f
a0097f8c:  02 80 00 41  be  0xa0098090
a0097f90:  80 a3 60 80  cmp  %o5, 0x80
a0097f94:  02 80 00 4a  be  0xa00980bc
a0097f98:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a0097f9c:  d8 0c 20 54  ldub  [ %l0 + 0x54 ], %o4
a0097fa0:  96 14 a2 90  or  %l2, 0x290, %o3
a0097fa4:  da 0a e0 2f  ldub  [ %o3 + 0x2f ], %o5
a0097fa8:  9e 0b 20 ff  and  %o4, 0xff, %o7
a0097fac:  80 a3 40 0f  cmp  %o5, %o7
a0097fb0:  02 80 00 19  be  0xa0098014
a0097fb4:  d0 04 63 ec  ld  [ %l1 + 0x3ec ], %o0
a0097fb8:  d8 2a e0 2f  stb  %o4, [ %o3 + 0x2f ]
a0097fbc:  40 01 04 90  call  0xa00d91fc
a0097fc0:  90 10 20 00  clr  %o0
a0097fc4:  11 2a 00 b3  sethi  %hi(0xa802cc00), %o0
a0097fc8:  98 12 23 f4  or  %o0, 0x3f4, %o4	! 0xa802cff4
a0097fcc:  da 13 20 04  lduh  [ %o4 + 4 ], %o5
a0097fd0:  03 3f ff e0  sethi  %hi(0xffff8000), %g1
a0097fd4:  a0 0b 40 01  and  %o5, %g1, %l0
a0097fd8:  97 2c 20 10  sll  %l0, 0x10, %o3
a0097fdc:  80 a2 e0 00  cmp  %o3, 0
a0097fe0:  12 80 00 48  bne  0xa0098100
a0097fe4:  92 13 64 00  or  %o5, 0x400, %o1
a0097fe8:  40 00 74 26  call  0xa00b5080
a0097fec:  c0 24 63 ec  clr  [ %l1 + 0x3ec ]
a0097ff0:  90 10 20 00  clr  %o0
a0097ff4:  40 02 c0 9d  call  0xa0148268
a0097ff8:  92 10 20 01  mov  1, %o1
a0097ffc:  90 10 20 01  mov  1, %o0
a0098000:  40 02 c0 9a  call  0xa0148268
a0098004:  92 10 20 01  mov  1, %o1
a0098008:  40 01 08 93  call  0xa00da254
a009800c:  01 00 00 00  nop
a0098010:  d0 04 63 ec  ld  [ %l1 + 0x3ec ], %o0
a0098014:  80 a2 20 00  cmp  %o0, 0
a0098018:  02 80 00 3f  be  0xa0098114
a009801c:  94 02 3f 81  add  %o0, -127, %o2
a0098020:  40 00 44 e7  call  0xa00a93bc
a0098024:  90 0a a0 ff  and  %o2, 0xff, %o0
a0098028:  a0 14 a2 90  or  %l2, 0x290, %l0
a009802c:  94 10 20 01  mov  1, %o2
a0098030:  90 10 20 01  mov  1, %o0
a0098034:  40 00 40 42  call  0xa00a813c
a0098038:  d2 0c 20 2f  ldub  [ %l0 + 0x2f ], %o1
a009803c:  d0 0c 20 2f  ldub  [ %l0 + 0x2f ], %o0
a0098040:  40 00 45 84  call  0xa00a9650
a0098044:  92 10 20 00  clr  %o1
a0098048:  90 10 20 01  mov  1, %o0
a009804c:  40 00 45 07  call  0xa00a9468
a0098050:  92 10 20 02  mov  2, %o1
a0098054:  a4 10 20 25  mov  0x25, %l2
a0098058:  e4 24 63 ec  st  %l2, [ %l1 + 0x3ec ]
a009805c:  90 10 20 02  mov  2, %o0
a0098060:  40 00 43 eb  call  0xa00a900c
a0098064:  92 10 20 01  mov  1, %o1
a0098068:  90 10 20 01  mov  1, %o0
a009806c:  40 00 44 ff  call  0xa00a9468
a0098070:  92 10 20 02  mov  2, %o1
a0098074:  90 10 20 00  clr  %o0
a0098078:  40 00 6d 17  call  0xa00b34d4
a009807c:  92 10 20 01  mov  1, %o1
a0098080:  a2 10 20 05  mov  5, %l1
a0098084:  19 2a 00 ac  sethi  %hi(0xa802b000), %o4
a0098088:  10 80 00 23  b  0xa0098114
a009808c:  e2 2b 20 8f  stb  %l1, [ %o4 + 0x8f ]	! 0xa802b08f
a0098090:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a0098094:  9a 14 a2 90  or  %l2, 0x290, %o5	! 0xa802d290
a0098098:  d0 0b 60 2f  ldub  [ %o5 + 0x2f ], %o0
a009809c:  80 a2 20 00  cmp  %o0, 0
a00980a0:  22 bf ff dd  be,a   0xa0098014
a00980a4:  d0 04 63 ec  ld  [ %l1 + 0x3ec ], %o0
a00980a8:  c0 2b 60 2f  clrb  [ %o5 + 0x2f ]
a00980ac:  40 01 04 54  call  0xa00d91fc
a00980b0:  90 10 20 00  clr  %o0
a00980b4:  10 bf ff d0  b  0xa0097ff4
a00980b8:  90 10 20 00  clr  %o0
a00980bc:  9a 14 a2 90  or  %l2, 0x290, %o5
a00980c0:  d2 0b 60 2f  ldub  [ %o5 + 0x2f ], %o1
a00980c4:  80 a2 60 01  cmp  %o1, 1
a00980c8:  02 bf ff d2  be  0xa0098010
a00980cc:  94 10 20 01  mov  1, %o2
a00980d0:  d4 2b 60 2f  stb  %o2, [ %o5 + 0x2f ]
a00980d4:  40 01 04 4a  call  0xa00d91fc
a00980d8:  90 10 20 00  clr  %o0
a00980dc:  11 2a 00 b3  sethi  %hi(0xa802cc00), %o0
a00980e0:  98 12 23 f4  or  %o0, 0x3f4, %o4	! 0xa802cff4
a00980e4:  da 13 20 04  lduh  [ %o4 + 4 ], %o5
a00980e8:  03 3f ff e0  sethi  %hi(0xffff8000), %g1
a00980ec:  a0 0b 40 01  and  %o5, %g1, %l0
a00980f0:  97 2c 20 10  sll  %l0, 0x10, %o3
a00980f4:  80 a2 e0 00  cmp  %o3, 0
a00980f8:  02 bf ff bc  be  0xa0097fe8
a00980fc:  92 13 64 00  or  %o5, 0x400, %o1
a0098100:  d2 33 20 04  sth  %o1, [ %o4 + 4 ]
a0098104:  90 10 20 04  mov  4, %o0
a0098108:  7f ff a1 e9  call  0xa00808ac
a009810c:  92 10 20 00  clr  %o1
a0098110:  30 bf ff b6  b,a   0xa0097fe8
a0098114:  81 c7 e0 08  ret
a0098118:  81 e8 00 00  restore
