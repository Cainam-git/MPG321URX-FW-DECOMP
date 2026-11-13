# leon2m FUN_a009e9a8 0xa009e9a8-0xa009ea08 (96 bytes)
a009e9a8:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a009e9ac:  9a 12 e2 90  or  %o3, 0x290, %o5	! 0xa802d290
a009e9b0:  d8 13 61 f6  lduh  [ %o5 + 0x1f6 ], %o4
a009e9b4:  03 00 00 15  sethi  %hi(0x5400), %g1
a009e9b8:  9a 10 61 aa  or  %g1, 0x1aa, %o5	! 0x55aa
a009e9bc:  80 a3 00 0d  cmp  %o4, %o5
a009e9c0:  02 80 00 0f  be  0xa009e9fc
a009e9c4:  d8 02 e2 90  ld  [ %o3 + 0x290 ], %o4
a009e9c8:  17 00 00 10  sethi  %hi(0x4000), %o3
a009e9cc:  80 8b 00 0b  btst  %o4, %o3
a009e9d0:  12 80 00 0b  bne  0xa009e9fc
a009e9d4:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a009e9d8:  da 10 63 f8  lduh  [ %g1 + 0x3f8 ], %o5	! 0xa802cff8
a009e9dc:  80 8b 64 00  btst  0x400, %o5
a009e9e0:  12 80 00 07  bne  0xa009e9fc
a009e9e4:  98 10 21 0e  mov  0x10e, %o4
a009e9e8:  17 2a 00 ab  sethi  %hi(0xa802ac00), %o3
a009e9ec:  d8 22 e3 ec  st  %o4, [ %o3 + 0x3ec ]	! 0xa802afec
a009e9f0:  82 13 c0 00  mov  %o7, %g1
a009e9f4:  40 00 67 60  call  0xa00b8774
a009e9f8:  9e 10 40 00  mov  %g1, %o7
a009e9fc:  01 00 00 00  nop
a009ea00:  81 c3 e0 08  retl
a009ea04:  01 00 00 00  nop
