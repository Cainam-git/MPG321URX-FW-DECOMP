# leon2m FUN_a0095610 0xa0095610-0xa00956a0 (144 bytes)
a0095610:  9d e3 bf 98  save  %sp, -104, %sp
a0095614:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a0095618:  1b 2a 00 97  sethi  %hi(0xa8025c00), %o5
a009561c:  96 12 22 90  or  %o0, 0x290, %o3
a0095620:  da 0b 60 55  ldub  [ %o5 + 0x55 ], %o5
a0095624:  d8 0a e0 4c  ldub  [ %o3 + 0x4c ], %o4
a0095628:  82 0b 60 ff  and  %o5, 0xff, %g1
a009562c:  33 2a 00 97  sethi  %hi(0xa8025c00), %i1
a0095630:  b0 10 20 01  mov  1, %i0
a0095634:  b4 10 20 01  mov  1, %i2
a0095638:  80 a3 00 01  cmp  %o4, %g1
a009563c:  02 80 00 04  be  0xa009564c
a0095640:  90 10 20 01  mov  1, %o0
a0095644:  40 01 02 1a  call  0xa00d5eac
a0095648:  da 2a e0 4c  stb  %o5, [ %o3 + 0x4c ]
a009564c:  40 00 4d 8f  call  0xa00a8c88
a0095650:  01 00 00 00  nop
a0095654:  40 00 89 24  call  0xa00b7ae4
a0095658:  01 00 00 00  nop
a009565c:  c2 0e 60 56  ldub  [ %i1 + 0x56 ], %g1
a0095660:  94 00 60 02  add  %g1, 2, %o2
a0095664:  9e 10 20 45  mov  0x45, %o7
a0095668:  17 2a 00 ab  sethi  %hi(0xa802ac00), %o3
a009566c:  90 0a a0 ff  and  %o2, 0xff, %o0
a0095670:  de 22 e3 ec  st  %o7, [ %o3 + 0x3ec ]
a0095674:  40 00 4f f7  call  0xa00a9650
a0095678:  92 10 20 02  mov  2, %o1
a009567c:  92 10 20 01  mov  1, %o1
a0095680:  40 00 4f f4  call  0xa00a9650
a0095684:  90 10 20 01  mov  1, %o0
a0095688:  d2 0e 60 56  ldub  [ %i1 + 0x56 ], %o1
a009568c:  b2 02 60 02  add  %o1, 2, %i1
a0095690:  b2 0e 60 ff  and  %i1, 0xff, %i1
a0095694:  40 00 4a aa  call  0xa00a813c
a0095698:  81 e8 00 00  restore
a009569c:  01 00 00 00  nop
