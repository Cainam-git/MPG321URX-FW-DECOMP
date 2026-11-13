# leon2m FUN_a00be744 0xa00be744-0xa00be78c (72 bytes)
a00be744:  9d e3 bf 98  save  %sp, -104, %sp
a00be748:  15 2a 00 b5  sethi  %hi(0xa802d400), %o2
a00be74c:  d0 0a a0 7c  ldub  [ %o2 + 0x7c ], %o0	! 0xa802d47c
a00be750:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00be754:  9a 12 60 78  or  %o1, 0x78, %o5	! 0xa802d078
a00be758:  98 02 20 30  add  %o0, 0x30, %o4
a00be75c:  82 10 20 30  mov  0x30, %g1
a00be760:  d8 2b 60 09  stb  %o4, [ %o5 + 9 ]
a00be764:  c2 2b 60 08  stb  %g1, [ %o5 + 8 ]
a00be768:  c2 2b 60 07  stb  %g1, [ %o5 + 7 ]
a00be76c:  7f ff f1 34  call  0xa00bac3c
a00be770:  90 10 20 80  mov  0x80, %o0
a00be774:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00be778:  7f ff f0 76  call  0xa00ba950
a00be77c:  90 10 00 18  mov  %i0, %o0
a00be780:  7f ff f1 19  call  0xa00babe4
a00be784:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00be788:  01 00 00 00  nop
