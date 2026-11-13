# leon2m FUN_a00964fc 0xa00964fc-0xa0096598 (156 bytes)
a00964fc:  9d e3 bf 98  save  %sp, -104, %sp
a0096500:  21 2a 00 97  sethi  %hi(0xa8025c00), %l0
a0096504:  40 00 4b ae  call  0xa00a93bc
a0096508:  d0 0c 20 56  ldub  [ %l0 + 0x56 ], %o0	! 0xa8025c56
a009650c:  94 10 20 00  clr  %o2
a0096510:  d2 0c 20 56  ldub  [ %l0 + 0x56 ], %o1
a0096514:  40 00 47 0a  call  0xa00a813c
a0096518:  90 10 20 01  mov  1, %o0
a009651c:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a0096520:  d0 04 23 ec  ld  [ %l0 + 0x3ec ], %o0	! 0xa802afec
a0096524:  98 02 3f 94  add  %o0, -108, %o4
a0096528:  90 0b 20 ff  and  %o4, 0xff, %o0
a009652c:  40 00 4c 49  call  0xa00a9650
a0096530:  92 10 20 00  clr  %o1
a0096534:  c2 04 23 ec  ld  [ %l0 + 0x3ec ], %g1
a0096538:  9a 00 7f 94  add  %g1, -108, %o5
a009653c:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a0096540:  40 01 0c 89  call  0xa00d9764
a0096544:  da 2a e2 a1  stb  %o5, [ %o3 + 0x2a1 ]	! 0xa802d2a1
a0096548:  de 04 23 ec  ld  [ %l0 + 0x3ec ], %o7
a009654c:  94 03 ff 94  add  %o7, -108, %o2
a0096550:  92 0a a0 ff  and  %o2, 0xff, %o1
a0096554:  90 10 20 01  mov  1, %o0
a0096558:  40 00 46 f9  call  0xa00a813c
a009655c:  94 10 20 01  mov  1, %o2
a0096560:  92 10 20 1b  mov  0x1b, %o1
a0096564:  d2 24 23 ec  st  %o1, [ %l0 + 0x3ec ]
a0096568:  90 10 20 03  mov  3, %o0
a009656c:  40 00 4a a8  call  0xa00a900c
a0096570:  92 10 20 01  mov  1, %o1
a0096574:  17 2a 00 ac  sethi  %hi(0xa802b000), %o3
a0096578:  d0 0a e0 8e  ldub  [ %o3 + 0x8e ], %o0	! 0xa802b08e
a009657c:  9a 12 20 02  or  %o0, 2, %o5
a0096580:  98 10 20 03  mov  3, %o4
a0096584:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a0096588:  d8 28 60 8f  stb  %o4, [ %g1 + 0x8f ]	! 0xa802b08f
a009658c:  da 2a e0 8e  stb  %o5, [ %o3 + 0x8e ]
a0096590:  81 c7 e0 08  ret
a0096594:  81 e8 00 00  restore
