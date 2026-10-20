# leon2m FUN_a013b5a0 0xa013b5a0-0xa013b5fc (92 bytes)
a013b5a0:  9d e3 bf 80  save  %sp, -128, %sp
a013b5a4:  1b 2a 00 a9  sethi  %hi(0xa802a400), %o5
a013b5a8:  13 2a 00 b2  sethi  %hi(0xa802c800), %o1
a013b5ac:  98 13 60 68  or  %o5, 0x68, %o4
a013b5b0:  d6 0b 60 68  ldub  [ %o5 + 0x68 ], %o3
a013b5b4:  d0 0a 63 bc  ldub  [ %o1 + 0x3bc ], %o0
a013b5b8:  c2 0b 20 02  ldub  [ %o4 + 2 ], %g1
a013b5bc:  93 32 20 01  srl  %o0, 1, %o1
a013b5c0:  9e 0e 20 ff  and  %i0, 0xff, %o7
a013b5c4:  d6 2b 60 68  stb  %o3, [ %o5 + 0x68 ]
a013b5c8:  d6 37 bf e6  sth  %o3, [ %fp + -26 ]
a013b5cc:  c2 2b 20 02  stb  %g1, [ %o4 + 2 ]
a013b5d0:  de 37 bf ee  sth  %o7, [ %fp + -18 ]
a013b5d4:  c2 37 bf f6  sth  %g1, [ %fp + -10 ]
a013b5d8:  f0 2b 20 01  stb  %i0, [ %o4 + 1 ]
a013b5dc:  90 0a 20 01  and  %o0, 1, %o0
a013b5e0:  92 0a 60 01  and  %o1, 1, %o1
a013b5e4:  94 07 bf e0  add  %fp, -32, %o2
a013b5e8:  7f fe ee 7f  call  0xa00f6fe4
a013b5ec:  96 10 20 70  mov  0x70, %o3
a013b5f0:  01 00 00 00  nop
a013b5f4:  81 c7 e0 08  ret
a013b5f8:  81 e8 00 00  restore
