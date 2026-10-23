# leon2m FUN_a009e65c 0xa009e65c-0xa009e694 (56 bytes)
a009e65c:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a009e660:  82 10 62 90  or  %g1, 0x290, %g1	! 0xa802d290
a009e664:  da 08 61 df  ldub  [ %g1 + 0x1df ], %o5
a009e668:  98 03 7f ff  add  %o5, -1, %o4
a009e66c:  80 a3 60 00  cmp  %o5, 0
a009e670:  02 80 00 06  be  0xa009e688
a009e674:  90 10 20 01  mov  1, %o0
a009e678:  d8 28 61 df  stb  %o4, [ %g1 + 0x1df ]
a009e67c:  82 13 c0 00  mov  %o7, %g1
a009e680:  40 00 65 a5  call  0xa00b7d14
a009e684:  9e 10 40 00  mov  %g1, %o7
a009e688:  01 00 00 00  nop
a009e68c:  81 c3 e0 08  retl
a009e690:  01 00 00 00  nop
