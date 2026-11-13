# leon2m FUN_a00957e8 0xa00957e8-0xa009584c (100 bytes)
a00957e8:  9d e3 bf 98  save  %sp, -104, %sp
a00957ec:  40 00 4d 27  call  0xa00a8c88
a00957f0:  b0 10 20 00  clr  %i0
a00957f4:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00957f8:  a0 12 62 90  or  %o1, 0x290, %l0	! 0xa802d290
a00957fc:  d6 0c 21 7b  ldub  [ %l0 + 0x17b ], %o3
a0095800:  90 0a e0 ff  and  %o3, 0xff, %o0
a0095804:  82 02 20 ed  add  %o0, 0xed, %g1
a0095808:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a009580c:  19 2a 00 97  sethi  %hi(0xa8025c00), %o4
a0095810:  c2 23 63 ec  st  %g1, [ %o5 + 0x3ec ]
a0095814:  40 00 78 ad  call  0xa00b3ac8
a0095818:  d6 2b 20 55  stb  %o3, [ %o4 + 0x55 ]
a009581c:  d0 0c 21 7b  ldub  [ %l0 + 0x17b ], %o0
a0095820:  40 00 4f 8c  call  0xa00a9650
a0095824:  92 10 20 00  clr  %o1
a0095828:  d0 0c 21 7b  ldub  [ %l0 + 0x17b ], %o0
a009582c:  40 00 4f 89  call  0xa00a9650
a0095830:  92 10 20 01  mov  1, %o1
a0095834:  90 10 20 01  mov  1, %o0
a0095838:  40 00 4f 0c  call  0xa00a9468
a009583c:  92 10 20 03  mov  3, %o1
a0095840:  40 00 77 25  call  0xa00b34d4
a0095844:  93 e8 20 04  restore  %g0, 4, %o1
a0095848:  01 00 00 00  nop
