# leon2m FUN_a00be78c 0xa00be78c-0xa00be7d4 (72 bytes)
a00be78c:  9d e3 bf 98  save  %sp, -104, %sp
a00be790:  15 2a 00 b5  sethi  %hi(0xa802d400), %o2
a00be794:  d0 0a a0 7d  ldub  [ %o2 + 0x7d ], %o0	! 0xa802d47d
a00be798:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00be79c:  9a 12 60 78  or  %o1, 0x78, %o5	! 0xa802d078
a00be7a0:  98 02 20 2f  add  %o0, 0x2f, %o4
a00be7a4:  82 10 20 30  mov  0x30, %g1
a00be7a8:  d8 2b 60 09  stb  %o4, [ %o5 + 9 ]
a00be7ac:  c2 2b 60 08  stb  %g1, [ %o5 + 8 ]
a00be7b0:  c2 2b 60 07  stb  %g1, [ %o5 + 7 ]
a00be7b4:  7f ff f1 22  call  0xa00bac3c
a00be7b8:  90 10 20 81  mov  0x81, %o0
a00be7bc:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00be7c0:  7f ff f0 64  call  0xa00ba950
a00be7c4:  90 10 00 18  mov  %i0, %o0
a00be7c8:  7f ff f1 07  call  0xa00babe4
a00be7cc:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00be7d0:  01 00 00 00  nop
