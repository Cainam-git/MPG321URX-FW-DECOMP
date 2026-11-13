# leon2m FUN_a00b83e4 0xa00b83e4-0xa00b848c (168 bytes)
a00b83e4:  9d e3 bf 98  save  %sp, -104, %sp
a00b83e8:  40 02 2a a9  call  0xa0142e8c
a00b83ec:  90 10 20 00  clr  %o0
a00b83f0:  82 0a 20 ff  and  %o0, 0xff, %g1
a00b83f4:  80 a0 60 05  cmp  %g1, 5
a00b83f8:  02 80 00 10  be  0xa00b8438
a00b83fc:  90 10 20 15  mov  0x15, %o0
a00b8400:  7f ff fe e7  call  0xa00b7f9c
a00b8404:  01 00 00 00  nop
a00b8408:  40 02 3c c5  call  0xa014771c
a00b840c:  90 10 20 00  clr  %o0	! 0x0
a00b8410:  92 10 20 16  mov  0x16, %o1
a00b8414:  40 02 34 93  call  0xa0145660
a00b8418:  90 10 20 00  clr  %o0
a00b841c:  91 2a 20 10  sll  %o0, 0x10, %o0
a00b8420:  80 a2 20 00  cmp  %o0, 0
a00b8424:  02 80 00 05  be  0xa00b8438
a00b8428:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00b842c:  d4 0b 60 8e  ldub  [ %o5 + 0x8e ], %o2	! 0xa802b08e
a00b8430:  92 12 a0 01  or  %o2, 1, %o1
a00b8434:  d2 2b 60 8e  stb  %o1, [ %o5 + 0x8e ]
a00b8438:  90 10 20 00  clr  %o0
a00b843c:  40 02 3a 61  call  0xa0146dc0
a00b8440:  92 10 20 00  clr  %o1
a00b8444:  90 10 20 08  mov  8, %o0
a00b8448:  92 10 20 00  clr  %o1
a00b844c:  40 02 39 fd  call  0xa0146c40
a00b8450:  94 10 20 00  clr  %o2
a00b8454:  92 10 20 24  mov  0x24, %o1
a00b8458:  11 2a 00 ac  sethi  %hi(0xa802b000), %o0
a00b845c:  d2 2a 20 8f  stb  %o1, [ %o0 + 0x8f ]	! 0xa802b08f
a00b8460:  90 10 20 00  clr  %o0
a00b8464:  40 02 3a 57  call  0xa0146dc0
a00b8468:  92 10 20 01  mov  1, %o1
a00b846c:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a00b8470:  9a 10 63 f4  or  %g1, 0x3f4, %o5	! 0xa802cff4
a00b8474:  d8 13 60 3e  lduh  [ %o5 + 0x3e ], %o4
a00b8478:  1f 3f ff e0  sethi  %hi(0xffff8000), %o7
a00b847c:  96 2b 00 0f  andn  %o4, %o7, %o3
a00b8480:  d6 33 60 3e  sth  %o3, [ %o5 + 0x3e ]
a00b8484:  81 c7 e0 08  ret
a00b8488:  81 e8 00 00  restore
