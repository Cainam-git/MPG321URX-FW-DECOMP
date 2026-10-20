# leon2m FUN_a01341dc 0xa01341dc-0xa01342d0 (244 bytes)
a01341dc:  9d e3 bf 98  save  %sp, -104, %sp
a01341e0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a01341e4:  b6 10 00 19  mov  %i1, %i3
a01341e8:  80 a6 20 11  cmp  %i0, 0x11
a01341ec:  18 80 00 08  bgu  0xa013420c
a01341f0:  a0 10 00 1a  mov  %i2, %l0
a01341f4:  11 00 03 4a  sethi  %hi(0xd2800), %o0
a01341f8:  83 2e 20 02  sll  %i0, 2, %g1
a01341fc:  9a 12 23 2c  or  %o0, 0x32c, %o5
a0134200:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a0134204:  81 c3 00 00  jmp  %o4
a0134208:  01 00 00 00  nop
a013420c:  7f fe a5 02  call  0xa00dd614
a0134210:  90 10 20 20  mov  0x20, %o0	! 0x20
a0134214:  80 8a 20 ff  btst  0xff, %o0
a0134218:  12 80 00 2a  bne  0xa01342c0
a013421c:  b4 10 20 00  clr  %i2
a0134220:  7f fe a7 41  call  0xa00ddf24
a0134224:  90 10 00 18  mov  %i0, %o0
a0134228:  b2 10 00 08  mov  %o0, %i1
a013422c:  7f fe a4 fa  call  0xa00dd614
a0134230:  90 10 20 20  mov  0x20, %o0
a0134234:  80 8a 20 ff  btst  0xff, %o0
a0134238:  b5 36 a0 02  srl  %i2, 2, %i2
a013423c:  12 80 00 17  bne  0xa0134298
a0134240:  b8 0c 20 ff  and  %l0, 0xff, %i4
a0134244:  92 16 40 1b  or  %i1, %i3, %o1
a0134248:  94 0a 60 ff  and  %o1, 0xff, %o2
a013424c:  96 10 00 1c  mov  %i4, %o3
a0134250:  90 10 20 19  mov  0x19, %o0
a0134254:  92 10 20 00  clr  %o1
a0134258:  67 fd 6c 67  call  0x4008f3f4
a013425c:  98 10 20 01  mov  1, %o4
a0134260:  b0 2e 40 1b  andn  %i1, %i3, %i0
a0134264:  94 0e 20 ff  and  %i0, 0xff, %o2
a0134268:  96 10 00 1c  mov  %i4, %o3
a013426c:  b7 36 a0 08  srl  %i2, 8, %i3
a0134270:  90 10 20 1a  mov  0x1a, %o0
a0134274:  92 10 20 00  clr  %o1
a0134278:  67 fd 6c 5f  call  0x4008f3f4
a013427c:  98 10 20 01  mov  1, %o4
a0134280:  b4 0e a0 1f  and  %i2, 0x1f, %i2
a0134284:  b6 0e e0 f3  and  %i3, 0xf3, %i3
a0134288:  b0 10 20 18  mov  0x18, %i0
a013428c:  b2 10 20 00  clr  %i1
a0134290:  67 fd 6c 59  call  0x4008f3f4
a0134294:  99 e8 20 01  restore  %g0, 1, %o4
a0134298:  21 00 06 95  sethi  %hi(0x1a5400), %l0
a013429c:  90 14 20 40  or  %l0, 0x40, %o0	! 0x1a5440
a01342a0:  92 10 00 18  mov  %i0, %o1
a01342a4:  94 0e e0 ff  and  %i3, 0xff, %o2
a01342a8:  96 10 00 1c  mov  %i4, %o3
a01342ac:  98 10 00 1a  mov  %i2, %o4
a01342b0:  7f fe ab b0  call  0xa00df170
a01342b4:  9a 0e 60 ff  and  %i1, 0xff, %o5
a01342b8:  10 bf ff e4  b  0xa0134248
a01342bc:  92 16 40 1b  or  %i1, %i3, %o1
a01342c0:  11 00 06 95  sethi  %hi(0x1a5400), %o0
a01342c4:  7f fe ab ab  call  0xa00df170
a01342c8:  90 12 20 70  or  %o0, 0x70, %o0	! 0x1a5470
a01342cc:  30 bf ff d5  b,a   0xa0134220
