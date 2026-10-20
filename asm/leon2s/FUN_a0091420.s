# leon2s FUN_a0091420 0xa0091420-0xa00914c4 (164 bytes)
a0091420:  9d e3 bf 98  save  %sp, -104, %sp
a0091424:  80 8e 20 ff  btst  0xff, %i0
a0091428:  b0 0e 60 ff  and  %i1, 0xff, %i0
a009142c:  27 2a 01 e3  sethi  %hi(0xa8078c00), %l3
a0091430:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a0091434:  a5 2e 20 02  sll  %i0, 2, %l2
a0091438:  9a 14 e0 18  or  %l3, 0x18, %o5
a009143c:  02 80 00 06  be  0xa0091454
a0091440:  a8 10 60 0c  or  %g1, 0xc, %l4
a0091444:  40 00 83 08  call  0xa00b2064
a0091448:  c0 2b 40 18  clrb  [ %o5 + %i0 ]
a009144c:  10 80 00 18  b  0xa00914ac
a0091450:  d0 25 00 12  st  %o0, [ %l4 + %l2 ]
a0091454:  40 00 83 04  call  0xa00b2064
a0091458:  01 00 00 00  nop
a009145c:  c2 05 00 12  ld  [ %l4 + %l2 ], %g1
a0091460:  90 22 00 01  sub  %o0, %g1, %o0
a0091464:  80 a2 20 28  cmp  %o0, 0x28
a0091468:  08 80 00 12  bleu  0xa00914b0
a009146c:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a0091470:  40 00 82 fd  call  0xa00b2064
a0091474:  01 00 00 00  nop
a0091478:  d0 25 00 12  st  %o0, [ %l4 + %l2 ]
a009147c:  7f ff ff c3  call  0xa0091388
a0091480:  90 10 00 18  mov  %i0, %o0
a0091484:  90 02 3e d3  add  %o0, -301, %o0
a0091488:  91 2a 20 10  sll  %o0, 0x10, %o0
a009148c:  91 32 20 10  srl  %o0, 0x10, %o0
a0091490:  80 a2 26 5c  cmp  %o0, 0x65c
a0091494:  18 80 00 05  bgu  0xa00914a8
a0091498:  9a 14 e0 18  or  %l3, 0x18, %o5
a009149c:  82 10 20 01  mov  1, %g1
a00914a0:  10 80 00 03  b  0xa00914ac
a00914a4:  c2 2b 40 18  stb  %g1, [ %o5 + %i0 ]
a00914a8:  c0 2b 40 18  clrb  [ %o5 + %i0 ]
a00914ac:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00914b0:  9a 0e 60 ff  and  %i1, 0xff, %o5
a00914b4:  82 10 60 18  or  %g1, 0x18, %g1
a00914b8:  f0 08 40 0d  ldub  [ %g1 + %o5 ], %i0
a00914bc:  81 c7 e0 08  ret
a00914c0:  81 e8 00 00  restore
