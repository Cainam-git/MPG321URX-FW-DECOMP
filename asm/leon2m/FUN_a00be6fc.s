# leon2m FUN_a00be6fc 0xa00be6fc-0xa00be744 (72 bytes)
a00be6fc:  9d e3 bf 98  save  %sp, -104, %sp
a00be700:  15 2a 00 b5  sethi  %hi(0xa802d400), %o2
a00be704:  d0 0a a0 7b  ldub  [ %o2 + 0x7b ], %o0	! 0xa802d47b
a00be708:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00be70c:  9a 12 60 78  or  %o1, 0x78, %o5	! 0xa802d078
a00be710:  98 02 20 2f  add  %o0, 0x2f, %o4
a00be714:  82 10 20 30  mov  0x30, %g1
a00be718:  d8 2b 60 09  stb  %o4, [ %o5 + 9 ]
a00be71c:  c2 2b 60 08  stb  %g1, [ %o5 + 8 ]
a00be720:  c2 2b 60 07  stb  %g1, [ %o5 + 7 ]
a00be724:  7f ff f1 46  call  0xa00bac3c
a00be728:  90 10 20 7f  mov  0x7f, %o0
a00be72c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00be730:  7f ff f0 88  call  0xa00ba950
a00be734:  90 10 00 18  mov  %i0, %o0
a00be738:  7f ff f1 2b  call  0xa00babe4
a00be73c:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00be740:  01 00 00 00  nop
