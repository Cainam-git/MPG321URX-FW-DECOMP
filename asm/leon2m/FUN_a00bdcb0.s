# leon2m FUN_a00bdcb0 0xa00bdcb0-0xa00bdcf8 (72 bytes)
a00bdcb0:  9d e3 bf 98  save  %sp, -104, %sp
a00bdcb4:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00bdcb8:  d0 0a a2 bf  ldub  [ %o2 + 0x2bf ], %o0	! 0xa802d2bf
a00bdcbc:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00bdcc0:  9a 12 60 78  or  %o1, 0x78, %o5	! 0xa802d078
a00bdcc4:  98 02 20 30  add  %o0, 0x30, %o4
a00bdcc8:  82 10 20 30  mov  0x30, %g1
a00bdccc:  d8 2b 60 09  stb  %o4, [ %o5 + 9 ]
a00bdcd0:  c2 2b 60 08  stb  %g1, [ %o5 + 8 ]
a00bdcd4:  c2 2b 60 07  stb  %g1, [ %o5 + 7 ]
a00bdcd8:  7f ff f3 d9  call  0xa00bac3c
a00bdcdc:  90 10 20 68  mov  0x68, %o0
a00bdce0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bdce4:  7f ff f3 1b  call  0xa00ba950
a00bdce8:  90 10 00 18  mov  %i0, %o0
a00bdcec:  7f ff f3 be  call  0xa00babe4
a00bdcf0:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bdcf4:  01 00 00 00  nop
