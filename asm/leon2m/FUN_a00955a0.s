# leon2m FUN_a00955a0 0xa00955a0-0xa0095610 (112 bytes)
a00955a0:  9d e3 bf 98  save  %sp, -104, %sp
a00955a4:  40 00 4d b9  call  0xa00a8c88
a00955a8:  21 2a 00 97  sethi  %hi(0xa8025c00), %l0
a00955ac:  40 00 89 4e  call  0xa00b7ae4
a00955b0:  01 00 00 00  nop
a00955b4:  da 0c 20 56  ldub  [ %l0 + 0x56 ], %o5
a00955b8:  96 03 60 02  add  %o5, 2, %o3
a00955bc:  9e 10 20 45  mov  0x45, %o7
a00955c0:  19 2a 00 ab  sethi  %hi(0xa802ac00), %o4
a00955c4:  90 0a e0 ff  and  %o3, 0xff, %o0
a00955c8:  de 23 23 ec  st  %o7, [ %o4 + 0x3ec ]
a00955cc:  40 00 50 21  call  0xa00a9650
a00955d0:  92 10 20 02  mov  2, %o1
a00955d4:  90 10 20 01  mov  1, %o0
a00955d8:  40 00 50 1e  call  0xa00a9650
a00955dc:  92 10 20 01  mov  1, %o1
a00955e0:  d4 0c 20 56  ldub  [ %l0 + 0x56 ], %o2
a00955e4:  92 02 a0 02  add  %o2, 2, %o1
a00955e8:  90 10 20 01  mov  1, %o0
a00955ec:  92 0a 60 ff  and  %o1, 0xff, %o1
a00955f0:  40 00 4a d3  call  0xa00a813c
a00955f4:  94 10 20 01  mov  1, %o2
a00955f8:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00955fc:  d0 0b 60 8e  ldub  [ %o5 + 0x8e ], %o0	! 0xa802b08e
a0095600:  82 12 20 02  or  %o0, 2, %g1
a0095604:  c2 2b 60 8e  stb  %g1, [ %o5 + 0x8e ]
a0095608:  81 c7 e0 08  ret
a009560c:  81 e8 00 00  restore
