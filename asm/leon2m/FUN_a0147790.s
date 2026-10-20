# leon2m FUN_a0147790 0xa0147790-0xa0147814 (56 bytes)
a0147790:  9d e3 bf 98  save  %sp, -104, %sp
a0147794:  7f fe d2 e8  call  0xa00fc334
a0147798:  01 00 00 00  nop
a014779c:  80 a2 20 07  cmp  %o0, 7
a01477a0:  18 80 00 1b  bgu  0xa014780c
a01477a4:  b0 10 20 00  clr  %i0
a01477a8:  83 2a 20 02  sll  %o0, 2, %g1
a01477ac:  11 00 03 8c  sethi  %hi(0xe3000), %o0
a01477b0:  9a 12 23 d8  or  %o0, 0x3d8, %o5	! 0xe33d8
a01477b4:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a01477b8:  81 c3 00 00  jmp  %o4
a01477bc:  01 00 00 00  nop
a01477c0:  7f fe d4 a0  call  0xa00fca40
a01477c4:  b0 10 20 05  mov  5, %i0	! 0x5
a01477c8:  92 0a 20 ff  and  %o0, 0xff, %o1
a01477cc:  80 a2 60 40  cmp  %o1, 0x40
a01477d0:  02 80 00 0f  be  0xa014780c
a01477d4:  01 00 00 00  nop
a01477d8:  10 80 00 0d  b  0xa014780c
a01477dc:  b0 10 20 00  clr  %i0	! 0x0
a01477e0:  10 80 00 0b  b  0xa014780c
a01477e4:  b0 10 20 07  mov  7, %i0
a01477e8:  10 80 00 09  b  0xa014780c
a01477ec:  b0 10 20 01  mov  1, %i0
a01477f0:  10 80 00 07  b  0xa014780c
a01477f4:  b0 10 20 02  mov  2, %i0
a01477f8:  10 80 00 05  b  0xa014780c
a01477fc:  b0 10 20 03  mov  3, %i0
a0147800:  10 80 00 03  b  0xa014780c
a0147804:  b0 10 20 04  mov  4, %i0
a0147808:  b0 10 20 06  mov  6, %i0
a014780c:  81 c7 e0 08  ret
a0147810:  81 e8 00 00  restore
