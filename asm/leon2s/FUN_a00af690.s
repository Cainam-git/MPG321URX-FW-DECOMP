# leon2s FUN_a00af690 0xa00af690-0xa00af764 (212 bytes)
a00af690:  9d e3 bf 98  save  %sp, -104, %sp
a00af694:  c2 0e 00 00  ldub  [ %i0 ], %g1
a00af698:  a0 0e 60 ff  and  %i1, 0xff, %l0
a00af69c:  92 10 22 29  mov  0x229, %o1
a00af6a0:  80 a0 60 05  cmp  %g1, 5
a00af6a4:  12 80 00 07  bne  0xa00af6c0
a00af6a8:  90 10 00 10  mov  %l0, %o0
a00af6ac:  7f ff dd 43  call  0xa00a6bb8
a00af6b0:  b1 2c 20 02  sll  %l0, 2, %i0
a00af6b4:  80 8a 20 01  btst  1, %o0
a00af6b8:  12 80 00 0c  bne  0xa00af6e8
a00af6bc:  01 00 00 00  nop
a00af6c0:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00af6c4:  82 10 63 38  or  %g1, 0x338, %g1	! 0xa8079338
a00af6c8:  a0 0e 60 ff  and  %i1, 0xff, %l0
a00af6cc:  40 00 0a 66  call  0xa00b2064
a00af6d0:  c0 28 40 10  clrb  [ %g1 + %l0 ]
a00af6d4:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00af6d8:  a1 2c 20 02  sll  %l0, 2, %l0
a00af6dc:  82 10 63 2c  or  %g1, 0x32c, %g1
a00af6e0:  10 80 00 1b  b  0xa00af74c
a00af6e4:  d0 20 40 10  st  %o0, [ %g1 + %l0 ]
a00af6e8:  40 00 0a 5f  call  0xa00b2064
a00af6ec:  01 00 00 00  nop
a00af6f0:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00af6f4:  a2 10 63 2c  or  %g1, 0x32c, %l1	! 0xa807932c
a00af6f8:  c2 04 40 18  ld  [ %l1 + %i0 ], %g1
a00af6fc:  90 22 00 01  sub  %o0, %g1, %o0
a00af700:  80 a2 20 28  cmp  %o0, 0x28
a00af704:  08 80 00 13  bleu  0xa00af750
a00af708:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00af70c:  40 00 0a 56  call  0xa00b2064
a00af710:  01 00 00 00  nop
a00af714:  d0 24 40 18  st  %o0, [ %l1 + %i0 ]
a00af718:  7f ff f5 f5  call  0xa00aceec
a00af71c:  90 10 00 10  mov  %l0, %o0
a00af720:  90 02 3e d3  add  %o0, -301, %o0
a00af724:  91 2a 20 10  sll  %o0, 0x10, %o0
a00af728:  91 32 20 10  srl  %o0, 0x10, %o0
a00af72c:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00af730:  80 a2 26 5c  cmp  %o0, 0x65c
a00af734:  18 80 00 05  bgu  0xa00af748
a00af738:  9a 10 63 38  or  %g1, 0x338, %o5
a00af73c:  82 10 20 01  mov  1, %g1
a00af740:  10 80 00 03  b  0xa00af74c
a00af744:  c2 2b 40 10  stb  %g1, [ %o5 + %l0 ]
a00af748:  c0 2b 40 10  clrb  [ %o5 + %l0 ]
a00af74c:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00af750:  9a 0e 60 ff  and  %i1, 0xff, %o5
a00af754:  82 10 63 38  or  %g1, 0x338, %g1
a00af758:  f0 08 40 0d  ldub  [ %g1 + %o5 ], %i0
a00af75c:  81 c7 e0 08  ret
a00af760:  81 e8 00 00  restore
