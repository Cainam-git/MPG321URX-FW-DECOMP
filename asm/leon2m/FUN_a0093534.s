# leon2m FUN_a0093534 0xa0093534-0xa00935e8 (180 bytes)
a0093534:  9d e3 bf 98  save  %sp, -104, %sp
a0093538:  21 2a 00 97  sethi  %hi(0xa8025c00), %l0
a009353c:  de 0c 20 56  ldub  [ %l0 + 0x56 ], %o7	! 0xa8025c56
a0093540:  98 03 e0 01  add  %o7, 1, %o4
a0093544:  40 00 57 9e  call  0xa00a93bc
a0093548:  90 0b 20 ff  and  %o4, 0xff, %o0
a009354c:  d6 0c 20 56  ldub  [ %l0 + 0x56 ], %o3
a0093550:  a2 02 e0 01  add  %o3, 1, %l1
a0093554:  92 0c 60 ff  and  %l1, 0xff, %o1
a0093558:  94 10 20 00  clr  %o2
a009355c:  40 00 52 f8  call  0xa00a813c
a0093560:  90 10 20 01  mov  1, %o0
a0093564:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a0093568:  d4 04 63 ec  ld  [ %l1 + 0x3ec ], %o2	! 0xa802afec
a009356c:  92 02 bf ad  add  %o2, -83, %o1
a0093570:  90 0a 60 ff  and  %o1, 0xff, %o0
a0093574:  40 00 58 37  call  0xa00a9650
a0093578:  92 10 20 00  clr  %o1
a009357c:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a0093580:  a0 12 22 90  or  %o0, 0x290, %l0	! 0xa802d290
a0093584:  c2 04 20 a8  ld  [ %l0 + 0xa8 ], %g1
a0093588:  9b 30 60 0c  srl  %g1, 0xc, %o5
a009358c:  9e 0b 60 01  and  %o5, 1, %o7
a0093590:  92 03 e0 01  add  %o7, 1, %o1
a0093594:  90 10 20 01  mov  1, %o0
a0093598:  40 00 52 e9  call  0xa00a813c
a009359c:  94 10 20 00  clr  %o2
a00935a0:  d8 04 20 a8  ld  [ %l0 + 0xa8 ], %o4
a00935a4:  97 33 20 0c  srl  %o4, 0xc, %o3
a00935a8:  94 0a e0 01  and  %o3, 1, %o2
a00935ac:  92 02 a0 01  add  %o2, 1, %o1
a00935b0:  90 10 20 01  mov  1, %o0
a00935b4:  40 00 52 e2  call  0xa00a813c
a00935b8:  94 10 20 01  mov  1, %o2
a00935bc:  92 10 20 11  mov  0x11, %o1
a00935c0:  d2 24 63 ec  st  %o1, [ %l1 + 0x3ec ]
a00935c4:  90 10 20 03  mov  3, %o0
a00935c8:  40 00 56 91  call  0xa00a900c
a00935cc:  92 10 20 01  mov  1, %o1
a00935d0:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00935d4:  d0 0b 60 8e  ldub  [ %o5 + 0x8e ], %o0	! 0xa802b08e
a00935d8:  82 12 20 02  or  %o0, 2, %g1
a00935dc:  c2 2b 60 8e  stb  %g1, [ %o5 + 0x8e ]
a00935e0:  81 c7 e0 08  ret
a00935e4:  81 e8 00 00  restore
