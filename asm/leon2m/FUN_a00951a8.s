# leon2m FUN_a00951a8 0xa00951a8-0xa009530c (356 bytes)
a00951a8:  9d e3 bf 98  save  %sp, -104, %sp
a00951ac:  2b 2a 00 b4  sethi  %hi(0xa802d000), %l5
a00951b0:  a2 15 62 90  or  %l5, 0x290, %l1	! 0xa802d290
a00951b4:  29 2a 00 ab  sethi  %hi(0xa802ac00), %l4
a00951b8:  c2 0c 61 a3  ldub  [ %l1 + 0x1a3 ], %g1
a00951bc:  27 2a 00 97  sethi  %hi(0xa8025c00), %l3
a00951c0:  a4 10 00 14  mov  %l4, %l2
a00951c4:  80 a0 60 00  cmp  %g1, 0
a00951c8:  12 80 00 13  bne  0xa0095214
a00951cc:  e0 0c 60 20  ldub  [ %l1 + 0x20 ], %l0
a00951d0:  d6 05 23 ec  ld  [ %l4 + 0x3ec ], %o3
a00951d4:  94 02 e0 2c  add  %o3, 0x2c, %o2
a00951d8:  40 02 bc f1  call  0xa014459c
a00951dc:  90 0a a0 ff  and  %o2, 0xff, %o0
a00951e0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00951e4:  d2 0c 60 1e  ldub  [ %l1 + 0x1e ], %o1
a00951e8:  80 a2 40 08  cmp  %o1, %o0
a00951ec:  02 80 00 2b  be  0xa0095298
a00951f0:  a0 10 00 13  mov  %l3, %l0
a00951f4:  da 05 23 ec  ld  [ %l4 + 0x3ec ], %o5
a00951f8:  98 03 60 2c  add  %o5, 0x2c, %o4
a00951fc:  40 02 bc e8  call  0xa014459c
a0095200:  90 0b 20 ff  and  %o4, 0xff, %o0
a0095204:  40 00 8d 80  call  0xa00b8804
a0095208:  d0 2c 60 1e  stb  %o0, [ %l1 + 0x1e ]
a009520c:  10 80 00 39  b  0xa00952f0
a0095210:  1f 2a 00 ac  sethi  %hi(0xa802b000), %o7
a0095214:  d2 05 23 ec  ld  [ %l4 + 0x3ec ], %o1
a0095218:  90 02 60 2c  add  %o1, 0x2c, %o0
a009521c:  40 02 bc e0  call  0xa014459c
a0095220:  90 0a 20 ff  and  %o0, 0xff, %o0
a0095224:  82 0a 20 ff  and  %o0, 0xff, %g1
a0095228:  a4 0c 20 ff  and  %l0, 0xff, %l2
a009522c:  d0 2c 60 20  stb  %o0, [ %l1 + 0x20 ]
a0095230:  80 a0 40 12  cmp  %g1, %l2
a0095234:  02 80 00 04  be  0xa0095244
a0095238:  90 10 20 01  mov  1, %o0
a009523c:  40 01 01 bf  call  0xa00d5938
a0095240:  01 00 00 00  nop
a0095244:  96 10 20 10  mov  0x10, %o3	! 0x10
a0095248:  15 2a 00 ac  sethi  %hi(0xa802b000), %o2
a009524c:  40 00 4e 8f  call  0xa00a8c88
a0095250:  d6 2a a0 8f  stb  %o3, [ %o2 + 0x8f ]	! 0xa802b08f
a0095254:  40 00 52 1a  call  0xa00a9abc
a0095258:  a0 10 20 83  mov  0x83, %l0
a009525c:  d0 0c e0 54  ldub  [ %l3 + 0x54 ], %o0
a0095260:  40 00 50 fc  call  0xa00a9650
a0095264:  92 10 20 02  mov  2, %o1
a0095268:  d2 0c e0 54  ldub  [ %l3 + 0x54 ], %o1
a009526c:  90 10 20 01  mov  1, %o0
a0095270:  40 00 4b b3  call  0xa00a813c
a0095274:  94 10 20 01  mov  1, %o2
a0095278:  90 10 20 04  mov  4, %o0
a009527c:  40 00 50 f5  call  0xa00a9650
a0095280:  92 10 20 03  mov  3, %o1
a0095284:  d8 0c 61 a4  ldub  [ %l1 + 0x1a4 ], %o4
a0095288:  23 2a 00 97  sethi  %hi(0xa8025c00), %l1
a009528c:  e0 25 23 ec  st  %l0, [ %l4 + 0x3ec ]
a0095290:  10 80 00 17  b  0xa00952ec
a0095294:  d8 2c 60 55  stb  %o4, [ %l1 + 0x55 ]
a0095298:  a8 10 20 10  mov  0x10, %l4
a009529c:  27 2a 00 ac  sethi  %hi(0xa802b000), %l3
a00952a0:  40 00 4e 7a  call  0xa00a8c88
a00952a4:  e8 2c e0 8f  stb  %l4, [ %l3 + 0x8f ]	! 0xa802b08f
a00952a8:  40 00 52 05  call  0xa00a9abc
a00952ac:  01 00 00 00  nop
a00952b0:  d0 0c 20 54  ldub  [ %l0 + 0x54 ], %o0
a00952b4:  40 00 50 e7  call  0xa00a9650
a00952b8:  92 10 20 02  mov  2, %o1
a00952bc:  d2 0c 20 54  ldub  [ %l0 + 0x54 ], %o1
a00952c0:  90 10 20 01  mov  1, %o0
a00952c4:  40 00 4b 9e  call  0xa00a813c
a00952c8:  94 10 20 01  mov  1, %o2
a00952cc:  90 10 20 03  mov  3, %o0
a00952d0:  40 00 50 e0  call  0xa00a9650
a00952d4:  92 10 20 03  mov  3, %o1
a00952d8:  d8 0c 61 a4  ldub  [ %l1 + 0x1a4 ], %o4
a00952dc:  9e 10 20 82  mov  0x82, %o7
a00952e0:  23 2a 00 97  sethi  %hi(0xa8025c00), %l1
a00952e4:  de 24 a3 ec  st  %o7, [ %l2 + 0x3ec ]
a00952e8:  d8 2c 60 55  stb  %o4, [ %l1 + 0x55 ]
a00952ec:  1f 2a 00 ac  sethi  %hi(0xa802b000), %o7
a00952f0:  da 0b e0 8e  ldub  [ %o7 + 0x8e ], %o5	! 0xa802b08e
a00952f4:  98 15 62 90  or  %l5, 0x290, %o4
a00952f8:  aa 13 60 02  or  %o5, 2, %l5
a00952fc:  ea 2b e0 8e  stb  %l5, [ %o7 + 0x8e ]
a0095300:  c0 2b 21 a3  clrb  [ %o4 + 0x1a3 ]
a0095304:  81 c7 e0 08  ret
a0095308:  81 e8 00 00  restore
