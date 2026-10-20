# leon2m FUN_a00bf6b0 0xa00bf6b0-0xa00bf7dc (300 bytes)
a00bf6b0:  9d e3 bf 98  save  %sp, -104, %sp
a00bf6b4:  35 2a 00 b4  sethi  %hi(0xa802d000), %i2
a00bf6b8:  a0 16 a0 78  or  %i2, 0x78, %l0	! 0xa802d078
a00bf6bc:  96 10 20 30  mov  0x30, %o3
a00bf6c0:  d6 2c 20 08  stb  %o3, [ %l0 + 8 ]
a00bf6c4:  40 00 61 a1  call  0xa00d7d48
a00bf6c8:  d6 2c 20 07  stb  %o3, [ %l0 + 7 ]
a00bf6cc:  80 a0 00 08  cmp  %g0, %o0
a00bf6d0:  94 10 20 31  mov  0x31, %o2
a00bf6d4:  92 42 bf ff  addx  %o2, -1, %o1
a00bf6d8:  d2 2c 20 09  stb  %o1, [ %l0 + 9 ]
a00bf6dc:  92 10 20 00  clr  %o1
a00bf6e0:  40 02 53 d7  call  0xa015463c
a00bf6e4:  90 10 20 3f  mov  0x3f, %o0
a00bf6e8:  d0 2e a0 78  stb  %o0, [ %i2 + 0x78 ]
a00bf6ec:  90 10 20 62  mov  0x62, %o0
a00bf6f0:  d0 2c 20 01  stb  %o0, [ %l0 + 1 ]
a00bf6f4:  92 10 20 02  mov  2, %o1
a00bf6f8:  40 02 53 d1  call  0xa015463c
a00bf6fc:  90 10 20 3f  mov  0x3f, %o0
a00bf700:  d0 2c 20 02  stb  %o0, [ %l0 + 2 ]
a00bf704:  92 10 20 03  mov  3, %o1
a00bf708:  40 02 53 cd  call  0xa015463c
a00bf70c:  90 10 20 3f  mov  0x3f, %o0
a00bf710:  d0 2c 20 03  stb  %o0, [ %l0 + 3 ]
a00bf714:  92 10 20 04  mov  4, %o1
a00bf718:  40 02 53 c9  call  0xa015463c
a00bf71c:  90 10 20 3f  mov  0x3f, %o0
a00bf720:  d0 2c 20 04  stb  %o0, [ %l0 + 4 ]
a00bf724:  92 10 20 05  mov  5, %o1
a00bf728:  40 02 53 c5  call  0xa015463c
a00bf72c:  90 10 20 3f  mov  0x3f, %o0
a00bf730:  d0 2c 20 05  stb  %o0, [ %l0 + 5 ]
a00bf734:  92 10 20 06  mov  6, %o1
a00bf738:  40 02 53 c1  call  0xa015463c
a00bf73c:  90 10 20 3f  mov  0x3f, %o0
a00bf740:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00bf744:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bf748:  82 10 20 0d  mov  0xd, %g1
a00bf74c:  9a 13 20 40  or  %o4, 0x40, %o5
a00bf750:  c2 2c 20 0a  stb  %g1, [ %l0 + 0xa ]
a00bf754:  80 a6 20 02  cmp  %i0, 2
a00bf758:  02 80 00 12  be  0xa00bf7a0
a00bf75c:  d0 2c 20 06  stb  %o0, [ %l0 + 6 ]
a00bf760:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00bf764:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00bf768:  96 12 a0 98  or  %o2, 0x98, %o3
a00bf76c:  80 a6 20 03  cmp  %i0, 3
a00bf770:  02 80 00 10  be  0xa00bf7b0
a00bf774:  9a 13 20 d0  or  %o4, 0xd0, %o5
a00bf778:  33 2a 00 ac  sethi  %hi(0xa802b000), %i1
a00bf77c:  c0 2e 60 9c  clrb  [ %i1 + 0x9c ]	! 0xa802b09c
a00bf780:  c0 2b 20 d0  clrb  [ %o4 + 0xd0 ]
a00bf784:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00bf788:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00bf78c:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00bf790:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00bf794:  b4 16 a0 78  or  %i2, 0x78, %i2
a00bf798:  40 02 24 14  call  0xa01487e8
a00bf79c:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bf7a0:  1f 2a 00 ac  sethi  %hi(0xa802b000), %o7
a00bf7a4:  c0 2b e0 9a  clrb  [ %o7 + 0x9a ]	! 0xa802b09a
a00bf7a8:  10 bf ff f7  b  0xa00bf784
a00bf7ac:  c0 2b 20 40  clrb  [ %o4 + 0x40 ]
a00bf7b0:  19 2a 00 ac  sethi  %hi(0xa802b000), %o4
a00bf7b4:  c0 2b 20 98  clrb  [ %o4 + 0x98 ]	! 0xa802b098
a00bf7b8:  c0 2a a0 98  clrb  [ %o2 + 0x98 ]
a00bf7bc:  c0 2a e0 19  clrb  [ %o3 + 0x19 ]
a00bf7c0:  c0 2a e0 01  clrb  [ %o3 + 1 ]
a00bf7c4:  c0 2a e0 07  clrb  [ %o3 + 7 ]
a00bf7c8:  c0 2a e0 0a  clrb  [ %o3 + 0xa ]
a00bf7cc:  b4 16 a0 78  or  %i2, 0x78, %i2
a00bf7d0:  40 02 24 06  call  0xa01487e8
a00bf7d4:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bf7d8:  01 00 00 00  nop
