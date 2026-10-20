# leon2m FUN_a00d430c 0xa00d430c-0xa00d43b4 (168 bytes)
a00d430c:  9d e3 bf 98  save  %sp, -104, %sp
a00d4310:  40 01 c0 41  call  0xa0144414
a00d4314:  a2 10 00 18  mov  %i0, %l1
a00d4318:  a4 0a 20 ff  and  %o0, 0xff, %l2
a00d431c:  82 0c 60 ff  and  %l1, 0xff, %g1
a00d4320:  92 10 20 0d  mov  0xd, %o1
a00d4324:  90 10 00 12  mov  %l2, %o0
a00d4328:  b0 10 00 12  mov  %l2, %i0
a00d432c:  b2 10 20 0b  mov  0xb, %i1
a00d4330:  80 a0 60 64  cmp  %g1, 0x64
a00d4334:  08 80 00 03  bleu  0xa00d4340
a00d4338:  b6 10 20 01  mov  1, %i3
a00d433c:  a2 10 20 64  mov  0x64, %l1
a00d4340:  96 10 20 64  mov  0x64, %o3
a00d4344:  40 01 c4 c7  call  0xa0145660
a00d4348:  a0 22 c0 11  sub  %o3, %l1, %l0
a00d434c:  95 2a 20 10  sll  %o0, 0x10, %o2
a00d4350:  a3 32 a0 10  srl  %o2, 0x10, %l1
a00d4354:  92 10 20 0e  mov  0xe, %o1
a00d4358:  40 01 c4 c2  call  0xa0145660
a00d435c:  90 10 00 12  mov  %l2, %o0
a00d4360:  93 2a 20 10  sll  %o0, 0x10, %o1
a00d4364:  83 32 60 10  srl  %o1, 0x10, %g1
a00d4368:  b4 0c 20 ff  and  %l0, 0xff, %i2
a00d436c:  9e 24 40 01  sub  %l1, %g1, %o7
a00d4370:  1b 14 7a e1  sethi  %hi(0x51eb8400), %o5
a00d4374:  94 5e 80 0f  smul  %i2, %o7, %o2
a00d4378:  98 13 61 1f  or  %o5, 0x11f, %o4
a00d437c:  80 5a 80 0c  smul  %o2, %o4, %g0
a00d4380:  97 40 00 00  rd  %y, %o3
a00d4384:  91 3a e0 05  sra  %o3, 5, %o0
a00d4388:  a1 3a a0 1f  sra  %o2, 0x1f, %l0
a00d438c:  a2 22 00 10  sub  %o0, %l0, %l1
a00d4390:  92 10 20 0e  mov  0xe, %o1
a00d4394:  40 01 c4 b3  call  0xa0145660
a00d4398:  90 10 00 12  mov  %l2, %o0
a00d439c:  92 04 40 08  add  %l1, %o0, %o1
a00d43a0:  b5 2a 60 10  sll  %o1, 0x10, %i2
a00d43a4:  b5 36 a0 10  srl  %i2, 0x10, %i2
a00d43a8:  40 01 c5 18  call  0xa0145808
a00d43ac:  81 e8 00 00  restore
a00d43b0:  01 00 00 00  nop
