# leon2m FUN_a00d41b4 0xa00d41b4-0xa00d4250 (156 bytes)
a00d41b4:  9d e3 bf 98  save  %sp, -104, %sp
a00d41b8:  40 01 c0 97  call  0xa0144414
a00d41bc:  b4 0e 20 ff  and  %i0, 0xff, %i2
a00d41c0:  a2 0a 20 ff  and  %o0, 0xff, %l1
a00d41c4:  92 10 20 05  mov  5, %o1
a00d41c8:  90 10 00 11  mov  %l1, %o0
a00d41cc:  b0 10 00 11  mov  %l1, %i0
a00d41d0:  b2 10 20 04  mov  4, %i1
a00d41d4:  80 a6 a0 64  cmp  %i2, 0x64
a00d41d8:  08 80 00 03  bleu  0xa00d41e4
a00d41dc:  b6 10 20 01  mov  1, %i3
a00d41e0:  b4 10 20 64  mov  0x64, %i2
a00d41e4:  40 01 c5 1f  call  0xa0145660
a00d41e8:  01 00 00 00  nop
a00d41ec:  93 2a 20 10  sll  %o0, 0x10, %o1
a00d41f0:  a1 32 60 10  srl  %o1, 0x10, %l0
a00d41f4:  92 10 20 06  mov  6, %o1
a00d41f8:  40 01 c5 1a  call  0xa0145660
a00d41fc:  90 10 00 11  mov  %l1, %o0
a00d4200:  83 2a 20 10  sll  %o0, 0x10, %g1
a00d4204:  9f 30 60 10  srl  %g1, 0x10, %o7
a00d4208:  9a 24 00 0f  sub  %l0, %o7, %o5
a00d420c:  19 14 7a e1  sethi  %hi(0x51eb8400), %o4
a00d4210:  92 5e 80 0d  smul  %i2, %o5, %o1
a00d4214:  96 13 21 1f  or  %o4, 0x11f, %o3
a00d4218:  80 5a 40 0b  smul  %o1, %o3, %g0
a00d421c:  95 40 00 00  rd  %y, %o2
a00d4220:  91 3a a0 05  sra  %o2, 5, %o0
a00d4224:  a1 3a 60 1f  sra  %o1, 0x1f, %l0
a00d4228:  b4 22 00 10  sub  %o0, %l0, %i2
a00d422c:  90 10 00 11  mov  %l1, %o0
a00d4230:  40 01 c5 0c  call  0xa0145660
a00d4234:  92 10 20 06  mov  6, %o1
a00d4238:  82 06 80 08  add  %i2, %o0, %g1
a00d423c:  b5 28 60 10  sll  %g1, 0x10, %i2
a00d4240:  b5 36 a0 10  srl  %i2, 0x10, %i2
a00d4244:  40 01 c5 71  call  0xa0145808
a00d4248:  81 e8 00 00  restore
a00d424c:  01 00 00 00  nop
