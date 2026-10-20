# leon2m FUN_a013b4e8 0xa013b4e8-0xa013b544 (92 bytes)
a013b4e8:  9d e3 bf 80  save  %sp, -128, %sp
a013b4ec:  1f 2a 00 b2  sethi  %hi(0xa802c800), %o7
a013b4f0:  d0 0b e3 bc  ldub  [ %o7 + 0x3bc ], %o0	! 0xa802cbbc
a013b4f4:  1b 2a 00 a9  sethi  %hi(0xa802a400), %o5
a013b4f8:  96 0e 60 ff  and  %i1, 0xff, %o3
a013b4fc:  94 0e a0 ff  and  %i2, 0xff, %o2
a013b500:  82 13 60 68  or  %o5, 0x68, %g1
a013b504:  93 32 20 01  srl  %o0, 1, %o1
a013b508:  98 0e 20 ff  and  %i0, 0xff, %o4
a013b50c:  d6 37 bf ee  sth  %o3, [ %fp + -18 ]
a013b510:  d4 37 bf f6  sth  %o2, [ %fp + -10 ]
a013b514:  f0 2b 60 68  stb  %i0, [ %o5 + 0x68 ]
a013b518:  f4 28 60 02  stb  %i2, [ %g1 + 2 ]
a013b51c:  d8 37 bf e6  sth  %o4, [ %fp + -26 ]
a013b520:  f2 28 60 01  stb  %i1, [ %g1 + 1 ]
a013b524:  90 0a 20 01  and  %o0, 1, %o0
a013b528:  92 0a 60 01  and  %o1, 1, %o1
a013b52c:  94 07 bf e0  add  %fp, -32, %o2
a013b530:  7f fe ee ad  call  0xa00f6fe4
a013b534:  96 10 20 70  mov  0x70, %o3
a013b538:  01 00 00 00  nop
a013b53c:  81 c7 e0 08  ret
a013b540:  81 e8 00 00  restore
