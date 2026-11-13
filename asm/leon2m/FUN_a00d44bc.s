# leon2m FUN_a00d44bc 0xa00d44bc-0xa00d4558 (156 bytes)
a00d44bc:  9d e3 bf 98  save  %sp, -104, %sp
a00d44c0:  40 01 bf d5  call  0xa0144414
a00d44c4:  b4 0e 20 ff  and  %i0, 0xff, %i2
a00d44c8:  a2 0a 20 ff  and  %o0, 0xff, %l1
a00d44cc:  92 10 20 12  mov  0x12, %o1
a00d44d0:  90 10 00 11  mov  %l1, %o0
a00d44d4:  b0 10 00 11  mov  %l1, %i0
a00d44d8:  b2 10 20 0f  mov  0xf, %i1
a00d44dc:  80 a6 a0 64  cmp  %i2, 0x64
a00d44e0:  08 80 00 03  bleu  0xa00d44ec
a00d44e4:  b6 10 20 01  mov  1, %i3
a00d44e8:  b4 10 20 64  mov  0x64, %i2
a00d44ec:  40 01 c4 5d  call  0xa0145660
a00d44f0:  01 00 00 00  nop
a00d44f4:  93 2a 20 10  sll  %o0, 0x10, %o1
a00d44f8:  a1 32 60 10  srl  %o1, 0x10, %l0
a00d44fc:  92 10 20 13  mov  0x13, %o1
a00d4500:  40 01 c4 58  call  0xa0145660
a00d4504:  90 10 00 11  mov  %l1, %o0
a00d4508:  83 2a 20 10  sll  %o0, 0x10, %g1
a00d450c:  9f 30 60 10  srl  %g1, 0x10, %o7
a00d4510:  9a 24 00 0f  sub  %l0, %o7, %o5
a00d4514:  19 14 7a e1  sethi  %hi(0x51eb8400), %o4
a00d4518:  92 5e 80 0d  smul  %i2, %o5, %o1
a00d451c:  96 13 21 1f  or  %o4, 0x11f, %o3
a00d4520:  80 5a 40 0b  smul  %o1, %o3, %g0
a00d4524:  95 40 00 00  rd  %y, %o2
a00d4528:  91 3a a0 05  sra  %o2, 5, %o0
a00d452c:  a1 3a 60 1f  sra  %o1, 0x1f, %l0
a00d4530:  b4 22 00 10  sub  %o0, %l0, %i2
a00d4534:  90 10 00 11  mov  %l1, %o0
a00d4538:  40 01 c4 4a  call  0xa0145660
a00d453c:  92 10 20 13  mov  0x13, %o1
a00d4540:  82 06 80 08  add  %i2, %o0, %g1
a00d4544:  b5 28 60 10  sll  %g1, 0x10, %i2
a00d4548:  b5 36 a0 10  srl  %i2, 0x10, %i2
a00d454c:  40 01 c4 af  call  0xa0145808
a00d4550:  81 e8 00 00  restore
a00d4554:  01 00 00 00  nop
