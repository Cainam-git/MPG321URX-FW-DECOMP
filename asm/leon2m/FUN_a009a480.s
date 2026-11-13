# leon2m FUN_a009a480 0xa009a480-0xa009a500 (128 bytes)
a009a480:  9d e3 bf 98  save  %sp, -104, %sp
a009a484:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a009a488:  a0 14 22 90  or  %l0, 0x290, %l0	! 0xa802d290
a009a48c:  17 09 24 92  sethi  %hi(0x24924800), %o3
a009a490:  d4 0c 21 df  ldub  [ %l0 + 0x1df ], %o2
a009a494:  92 12 e1 25  or  %o3, 0x125, %o1
a009a498:  80 52 80 09  umul  %o2, %o1, %g0
a009a49c:  83 40 00 00  rd  %y, %g1
a009a4a0:  90 22 80 01  sub  %o2, %g1, %o0
a009a4a4:  9b 32 20 01  srl  %o0, 1, %o5
a009a4a8:  a2 00 40 0d  add  %g1, %o5, %l1
a009a4ac:  9f 34 60 02  srl  %l1, 2, %o7
a009a4b0:  99 2b e0 03  sll  %o7, 3, %o4
a009a4b4:  96 23 00 0f  sub  %o4, %o7, %o3
a009a4b8:  92 22 80 0b  sub  %o2, %o3, %o1
a009a4bc:  40 00 3b c0  call  0xa00a93bc
a009a4c0:  90 0a 60 ff  and  %o1, 0xff, %o0
a009a4c4:  23 2a 00 97  sethi  %hi(0xa8025c00), %l1
a009a4c8:  d0 0c 60 55  ldub  [ %l1 + 0x55 ], %o0	! 0xa8025c55
a009a4cc:  d0 2c 21 df  stb  %o0, [ %l0 + 0x1df ]
a009a4d0:  90 10 20 34  mov  0x34, %o0
a009a4d4:  40 00 53 de  call  0xa00af44c
a009a4d8:  92 10 20 03  mov  3, %o1
a009a4dc:  9a 10 20 bf  mov  0xbf, %o5
a009a4e0:  03 2a 00 ab  sethi  %hi(0xa802ac00), %g1
a009a4e4:  da 20 63 ec  st  %o5, [ %g1 + 0x3ec ]	! 0xa802afec
a009a4e8:  90 10 20 04  mov  4, %o0
a009a4ec:  40 00 3c 59  call  0xa00a9650
a009a4f0:  92 10 20 01  mov  1, %o1
a009a4f4:  c0 2c 60 55  clrb  [ %l1 + 0x55 ]
a009a4f8:  81 c7 e0 08  ret
a009a4fc:  81 e8 00 00  restore
