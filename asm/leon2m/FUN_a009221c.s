# leon2m FUN_a009221c 0xa009221c-0xa00922f0 (212 bytes)
a009221c:  9d e3 bf 98  save  %sp, -104, %sp
a0092220:  33 2a 00 ab  sethi  %hi(0xa802ac00), %i1
a0092224:  d8 06 63 ec  ld  [ %i1 + 0x3ec ], %o4	! 0xa802afec
a0092228:  96 03 3f fe  add  %o4, -2, %o3
a009222c:  90 0a e0 ff  and  %o3, 0xff, %o0
a0092230:  40 00 87 c5  call  0xa00b4144
a0092234:  92 10 20 02  mov  2, %o1
a0092238:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a009223c:  40 02 c8 f0  call  0xa01445fc
a0092240:  d0 0a a2 ae  ldub  [ %o2 + 0x2ae ], %o0	! 0xa802d2ae
a0092244:  92 0a 20 ff  and  %o0, 0xff, %o1
a0092248:  90 02 60 1e  add  %o1, 0x1e, %o0
a009224c:  03 19 99 99  sethi  %hi(0x66666400), %g1
a0092250:  d0 26 63 ec  st  %o0, [ %i1 + 0x3ec ]
a0092254:  b0 10 62 67  or  %g1, 0x267, %i0
a0092258:  10 80 00 0d  b  0xa009228c
a009225c:  a0 10 00 19  mov  %i1, %l0
a0092260:  94 03 7f e3  add  %o5, -29, %o2
a0092264:  80 5a 80 18  smul  %o2, %i0, %g0
a0092268:  93 40 00 00  rd  %y, %o1
a009226c:  83 3a 60 01  sra  %o1, 1, %g1
a0092270:  91 3a a0 1f  sra  %o2, 0x1f, %o0
a0092274:  98 20 40 08  sub  %g1, %o0, %o4
a0092278:  9f 2b 20 02  sll  %o4, 2, %o7
a009227c:  96 03 c0 0c  add  %o7, %o4, %o3
a0092280:  92 22 80 0b  sub  %o2, %o3, %o1
a0092284:  90 02 60 1e  add  %o1, 0x1e, %o0
a0092288:  d0 26 63 ec  st  %o0, [ %i1 + 0x3ec ]
a009228c:  c2 06 63 ec  ld  [ %i1 + 0x3ec ], %g1
a0092290:  9e 00 7f e2  add  %g1, -30, %o7
a0092294:  90 0b e0 ff  and  %o7, 0xff, %o0
a0092298:  40 00 60 a2  call  0xa00aa520
a009229c:  01 00 00 00  nop
a00922a0:  9a 0a 20 ff  and  %o0, 0xff, %o5
a00922a4:  80 a3 60 01  cmp  %o5, 1
a00922a8:  12 bf ff ee  bne  0xa0092260
a00922ac:  da 16 63 ee  lduh  [ %i1 + 0x3ee ], %o5
a00922b0:  f0 04 23 ec  ld  [ %l0 + 0x3ec ], %i0
a00922b4:  a0 06 3f e2  add  %i0, -30, %l0
a00922b8:  90 0c 20 ff  and  %l0, 0xff, %o0
a00922bc:  40 00 5b 54  call  0xa00a900c
a00922c0:  92 10 20 01  mov  1, %o1
a00922c4:  90 10 20 06  mov  6, %o0
a00922c8:  92 10 20 00  clr  %o1
a00922cc:  40 02 d2 5d  call  0xa0146c40
a00922d0:  94 10 20 00  clr  %o2
a00922d4:  90 10 20 01  mov  1, %o0
a00922d8:  40 00 5c 64  call  0xa00a9468
a00922dc:  92 10 20 03  mov  3, %o1
a00922e0:  b0 10 20 00  clr  %i0
a00922e4:  40 00 84 7c  call  0xa00b34d4
a00922e8:  93 e8 20 04  restore  %g0, 4, %o1
a00922ec:  01 00 00 00  nop
