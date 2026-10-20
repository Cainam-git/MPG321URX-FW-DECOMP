# leon2m FUN_a00a4348 0xa00a4348-0xa00a439c (84 bytes)
a00a4348:  9d e3 bf 98  save  %sp, -104, %sp
a00a434c:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00a4350:  98 12 22 90  or  %o0, 0x290, %o4	! 0xa802d290
a00a4354:  da 0b 20 0a  ldub  [ %o4 + 0xa ], %o5
a00a4358:  9a 03 7f ff  add  %o5, -1, %o5
a00a435c:  82 0b 60 ff  and  %o5, 0xff, %g1
a00a4360:  80 a0 60 64  cmp  %g1, 0x64
a00a4364:  08 80 00 04  bleu  0xa00a4374
a00a4368:  90 10 20 01  mov  1, %o0
a00a436c:  10 80 00 06  b  0xa00a4384
a00a4370:  c0 2b 20 0a  clrb  [ %o4 + 0xa ]
a00a4374:  40 00 4a eb  call  0xa00b6f20
a00a4378:  da 2b 20 0a  stb  %o5, [ %o4 + 0xa ]
a00a437c:  40 00 ce 99  call  0xa00d7de0
a00a4380:  01 00 00 00  nop
a00a4384:  13 2a 00 ac  sethi  %hi(0xa802b000), %o1
a00a4388:  d6 0a 60 8e  ldub  [ %o1 + 0x8e ], %o3	! 0xa802b08e
a00a438c:  94 12 e0 02  or  %o3, 2, %o2
a00a4390:  d4 2a 60 8e  stb  %o2, [ %o1 + 0x8e ]
a00a4394:  81 c7 e0 08  ret
a00a4398:  81 e8 00 00  restore
