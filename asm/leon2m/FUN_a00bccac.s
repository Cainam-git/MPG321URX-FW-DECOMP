# leon2m FUN_a00bccac 0xa00bccac-0xa00bccf4 (72 bytes)
a00bccac:  9d e3 bf 98  save  %sp, -104, %sp
a00bccb0:  15 2a 00 b3  sethi  %hi(0xa802cc00), %o2
a00bccb4:  d0 0a a3 fd  ldub  [ %o2 + 0x3fd ], %o0	! 0xa802cffd
a00bccb8:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00bccbc:  9a 12 60 78  or  %o1, 0x78, %o5	! 0xa802d078
a00bccc0:  98 02 20 30  add  %o0, 0x30, %o4
a00bccc4:  82 10 20 30  mov  0x30, %g1
a00bccc8:  d8 2b 60 09  stb  %o4, [ %o5 + 9 ]
a00bcccc:  c2 2b 60 08  stb  %g1, [ %o5 + 8 ]
a00bccd0:  c2 2b 60 07  stb  %g1, [ %o5 + 7 ]
a00bccd4:  7f ff f7 da  call  0xa00bac3c
a00bccd8:  90 10 20 1b  mov  0x1b, %o0
a00bccdc:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bcce0:  7f ff f7 1c  call  0xa00ba950
a00bcce4:  90 10 00 18  mov  %i0, %o0
a00bcce8:  7f ff f7 bf  call  0xa00babe4
a00bccec:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bccf0:  01 00 00 00  nop
