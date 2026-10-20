# leon2m FUN_a0096598 0xa0096598-0xa0096610 (120 bytes)
a0096598:  9d e3 bf 98  save  %sp, -104, %sp
a009659c:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a00965a0:  d6 04 63 ec  ld  [ %l1 + 0x3ec ], %o3	! 0xa802afec
a00965a4:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00965a8:  19 2a 00 97  sethi  %hi(0xa8025c00), %o4
a00965ac:  a0 13 e2 90  or  %o7, 0x290, %l0
a00965b0:  d4 0b 20 56  ldub  [ %o4 + 0x56 ], %o2
a00965b4:  92 02 ff 94  add  %o3, -108, %o1
a00965b8:  d4 2c 20 11  stb  %o2, [ %l0 + 0x11 ]
a00965bc:  40 00 4b 80  call  0xa00a93bc
a00965c0:  90 0a 60 ff  and  %o1, 0xff, %o0
a00965c4:  d0 0c 20 11  ldub  [ %l0 + 0x11 ], %o0
a00965c8:  40 00 4c 22  call  0xa00a9650
a00965cc:  92 10 20 00  clr  %o1
a00965d0:  d2 0c 20 11  ldub  [ %l0 + 0x11 ], %o1
a00965d4:  90 10 20 01  mov  1, %o0
a00965d8:  40 00 46 d9  call  0xa00a813c
a00965dc:  94 10 20 01  mov  1, %o2
a00965e0:  40 01 0c 61  call  0xa00d9764
a00965e4:  01 00 00 00  nop
a00965e8:  90 10 20 1b  mov  0x1b, %o0	! 0x1b
a00965ec:  d0 24 63 ec  st  %o0, [ %l1 + 0x3ec ]
a00965f0:  90 10 20 03  mov  3, %o0
a00965f4:  40 00 4a 86  call  0xa00a900c
a00965f8:  92 10 20 01  mov  1, %o1
a00965fc:  9a 10 20 03  mov  3, %o5
a0096600:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a0096604:  da 28 60 8f  stb  %o5, [ %g1 + 0x8f ]	! 0xa802b08f
a0096608:  81 c7 e0 08  ret
a009660c:  81 e8 00 00  restore
