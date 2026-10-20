# leon2m FUN_a009a554 0xa009a554-0xa009a5ac (88 bytes)
a009a554:  9d e3 bf 98  save  %sp, -104, %sp
a009a558:  19 2a 00 b5  sethi  %hi(0xa802d400), %o4
a009a55c:  40 00 3b 98  call  0xa00a93bc
a009a560:  d0 0b 20 71  ldub  [ %o4 + 0x71 ], %o0	! 0xa802d471
a009a564:  90 10 20 34  mov  0x34, %o0
a009a568:  40 00 53 b9  call  0xa00af44c
a009a56c:  92 10 20 03  mov  3, %o1
a009a570:  96 10 20 be  mov  0xbe, %o3
a009a574:  15 2a 00 ab  sethi  %hi(0xa802ac00), %o2
a009a578:  90 10 20 03  mov  3, %o0
a009a57c:  d6 22 a3 ec  st  %o3, [ %o2 + 0x3ec ]
a009a580:  40 00 3c 34  call  0xa00a9650
a009a584:  92 10 20 01  mov  1, %o1
a009a588:  13 2a 00 97  sethi  %hi(0xa8025c00), %o1
a009a58c:  40 01 01 65  call  0xa00dab20
a009a590:  c0 2a 60 55  clrb  [ %o1 + 0x55 ]	! 0xa8025c55
a009a594:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a009a598:  d0 0b 60 8e  ldub  [ %o5 + 0x8e ], %o0	! 0xa802b08e
a009a59c:  82 12 20 02  or  %o0, 2, %g1
a009a5a0:  c2 2b 60 8e  stb  %g1, [ %o5 + 0x8e ]
a009a5a4:  81 c7 e0 08  ret
a009a5a8:  81 e8 00 00  restore
