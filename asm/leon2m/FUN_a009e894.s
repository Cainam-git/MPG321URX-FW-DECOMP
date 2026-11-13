# leon2m FUN_a009e894 0xa009e894-0xa009e91c (136 bytes)
a009e894:  9d e3 bf 98  save  %sp, -104, %sp
a009e898:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a009e89c:  c2 04 23 ec  ld  [ %l0 + 0x3ec ], %g1	! 0xa802afec
a009e8a0:  80 a0 60 1c  cmp  %g1, 0x1c
a009e8a4:  02 80 00 09  be  0xa009e8c8
a009e8a8:  90 10 21 0f  mov  0x10f, %o0
a009e8ac:  d0 24 23 ec  st  %o0, [ %l0 + 0x3ec ]
a009e8b0:  d2 04 23 ec  ld  [ %l0 + 0x3ec ], %o1
a009e8b4:  80 a2 60 1c  cmp  %o1, 0x1c
a009e8b8:  90 10 20 01  mov  1, %o0
a009e8bc:  12 80 00 0c  bne  0xa009e8ec
a009e8c0:  92 10 20 00  clr  %o1
a009e8c4:  30 80 00 08  b,a   0xa009e8e4
a009e8c8:  40 00 e5 20  call  0xa00d7d48
a009e8cc:  01 00 00 00  nop
a009e8d0:  80 a2 20 00  cmp  %o0, 0
a009e8d4:  22 bf ff f8  be,a   0xa009e8b4
a009e8d8:  d2 04 23 ec  ld  [ %l0 + 0x3ec ], %o1
a009e8dc:  10 bf ff f4  b  0xa009e8ac
a009e8e0:  90 10 21 0f  mov  0x10f, %o0
a009e8e4:  40 02 a1 37  call  0xa0146dc0
a009e8e8:  01 00 00 00  nop
a009e8ec:  40 00 66 e8  call  0xa00b848c
a009e8f0:  01 00 00 00  nop
a009e8f4:  67 ff bb 25  call  0x4008d588
a009e8f8:  01 00 00 00  nop
a009e8fc:  15 2a 00 b3  sethi  %hi(0xa802cc00), %o2
a009e900:  d6 12 a3 f4  lduh  [ %o2 + 0x3f4 ], %o3	! 0xa802cff4
a009e904:  9a 12 e1 00  or  %o3, 0x100, %o5
a009e908:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a009e90c:  d0 33 20 3c  sth  %o0, [ %o4 + 0x3c ]	! 0xa802d03c
a009e910:  da 32 a3 f4  sth  %o5, [ %o2 + 0x3f4 ]
a009e914:  81 c7 e0 08  ret
a009e918:  81 e8 00 00  restore
