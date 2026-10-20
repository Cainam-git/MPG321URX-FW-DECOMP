# leon2m FUN_a013b544 0xa013b544-0xa013b5a0 (92 bytes)
a013b544:  9d e3 bf 80  save  %sp, -128, %sp
a013b548:  1b 2a 00 a9  sethi  %hi(0xa802a400), %o5
a013b54c:  13 2a 00 b2  sethi  %hi(0xa802c800), %o1
a013b550:  98 13 60 68  or  %o5, 0x68, %o4
a013b554:  d6 0b 60 68  ldub  [ %o5 + 0x68 ], %o3
a013b558:  d0 0a 63 bc  ldub  [ %o1 + 0x3bc ], %o0
a013b55c:  e0 0b 20 01  ldub  [ %o4 + 1 ], %l0
a013b560:  93 32 20 01  srl  %o0, 1, %o1
a013b564:  9e 0e 20 ff  and  %i0, 0xff, %o7
a013b568:  d6 2b 60 68  stb  %o3, [ %o5 + 0x68 ]
a013b56c:  d6 37 bf e6  sth  %o3, [ %fp + -26 ]
a013b570:  f0 2b 20 02  stb  %i0, [ %o4 + 2 ]
a013b574:  e0 37 bf ee  sth  %l0, [ %fp + -18 ]
a013b578:  de 37 bf f6  sth  %o7, [ %fp + -10 ]
a013b57c:  e0 2b 20 01  stb  %l0, [ %o4 + 1 ]
a013b580:  90 0a 20 01  and  %o0, 1, %o0
a013b584:  92 0a 60 01  and  %o1, 1, %o1
a013b588:  94 07 bf e0  add  %fp, -32, %o2
a013b58c:  7f fe ee 96  call  0xa00f6fe4
a013b590:  96 10 20 70  mov  0x70, %o3
a013b594:  01 00 00 00  nop
a013b598:  81 c7 e0 08  ret
a013b59c:  81 e8 00 00  restore
