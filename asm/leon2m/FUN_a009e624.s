# leon2m FUN_a009e624 0xa009e624-0xa009e65c (56 bytes)
a009e624:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a009e628:  82 10 62 90  or  %g1, 0x290, %g1	! 0xa802d290
a009e62c:  da 08 61 df  ldub  [ %g1 + 0x1df ], %o5
a009e630:  98 03 60 01  add  %o5, 1, %o4
a009e634:  80 a3 60 05  cmp  %o5, 5
a009e638:  18 80 00 06  bgu  0xa009e650
a009e63c:  90 10 20 01  mov  1, %o0
a009e640:  d8 28 61 df  stb  %o4, [ %g1 + 0x1df ]
a009e644:  82 13 c0 00  mov  %o7, %g1
a009e648:  40 00 65 b3  call  0xa00b7d14
a009e64c:  9e 10 40 00  mov  %g1, %o7
a009e650:  01 00 00 00  nop
a009e654:  81 c3 e0 08  retl
a009e658:  01 00 00 00  nop
