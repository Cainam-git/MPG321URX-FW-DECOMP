# leon2m FUN_a015d700 0xa015d700-0xa015d7f0 (240 bytes)
a015d700:  9d e3 bf 98  save  %sp, -104, %sp
a015d704:  c2 06 20 10  ld  [ %i0 + 0x10 ], %g1
a015d708:  83 28 60 02  sll  %g1, 2, %g1
a015d70c:  a4 06 20 14  add  %i0, 0x14, %l2
a015d710:  a0 00 40 12  add  %g1, %l2, %l0
a015d714:  a0 04 3f fc  add  %l0, -4, %l0
a015d718:  e2 04 00 00  ld  [ %l0 ], %l1
a015d71c:  7f ff fd f7  call  0xa015cef8
a015d720:  90 10 00 11  mov  %l1, %o0
a015d724:  82 10 20 20  mov  0x20, %g1
a015d728:  82 20 40 08  sub  %g1, %o0, %g1
a015d72c:  80 a2 20 0a  cmp  %o0, 0xa
a015d730:  04 80 00 1f  ble  0xa015d7ac
a015d734:  c2 26 40 00  st  %g1, [ %i1 ]
a015d738:  80 a4 00 12  cmp  %l0, %l2
a015d73c:  18 80 00 14  bgu  0xa015d78c
a015d740:  96 10 20 00  clr  %o3
a015d744:  90 82 3f f5  addcc  %o0, -11, %o0
a015d748:  02 80 00 16  be  0xa015d7a0
a015d74c:  03 0f fc 00  sethi  %hi(0x3ff00000), %g1
a015d750:  82 20 00 08  neg  %o0, %g1
a015d754:  9b 2c 40 08  sll  %l1, %o0, %o5
a015d758:  83 32 c0 01  srl  %o3, %g1, %g1
a015d75c:  9a 13 40 01  or  %o5, %g1, %o5
a015d760:  19 0f fc 00  sethi  %hi(0x3ff00000), %o4
a015d764:  b0 13 40 0c  or  %o5, %o4, %i0
a015d768:  80 a4 00 12  cmp  %l0, %l2
a015d76c:  08 80 00 03  bleu  0xa015d778
a015d770:  a2 10 20 00  clr  %l1
a015d774:  e2 04 3f fc  ld  [ %l0 + -4 ], %l1
a015d778:  82 20 00 08  neg  %o0, %g1
a015d77c:  83 34 40 01  srl  %l1, %g1, %g1
a015d780:  9b 2a c0 08  sll  %o3, %o0, %o5
a015d784:  10 80 00 19  b  0xa015d7e8
a015d788:  b2 13 40 01  or  %o5, %g1, %i1
a015d78c:  a0 04 3f fc  add  %l0, -4, %l0
a015d790:  90 82 3f f5  addcc  %o0, -11, %o0
a015d794:  12 bf ff ef  bne  0xa015d750
a015d798:  d6 04 00 00  ld  [ %l0 ], %o3
a015d79c:  03 0f fc 00  sethi  %hi(0x3ff00000), %g1
a015d7a0:  b0 14 40 01  or  %l1, %g1, %i0
a015d7a4:  10 80 00 11  b  0xa015d7e8
a015d7a8:  b2 10 00 0b  mov  %o3, %i1
a015d7ac:  82 10 20 0b  mov  0xb, %g1
a015d7b0:  82 20 40 08  sub  %g1, %o0, %g1
a015d7b4:  83 34 40 01  srl  %l1, %g1, %g1
a015d7b8:  1b 0f fc 00  sethi  %hi(0x3ff00000), %o5
a015d7bc:  b0 10 40 0d  or  %g1, %o5, %i0
a015d7c0:  80 a4 00 12  cmp  %l0, %l2
a015d7c4:  08 80 00 03  bleu  0xa015d7d0
a015d7c8:  98 10 20 00  clr  %o4
a015d7cc:  d8 04 3f fc  ld  [ %l0 + -4 ], %o4
a015d7d0:  9a 10 20 0b  mov  0xb, %o5
a015d7d4:  9a 23 40 08  sub  %o5, %o0, %o5
a015d7d8:  82 02 20 15  add  %o0, 0x15, %g1
a015d7dc:  83 2c 40 01  sll  %l1, %g1, %g1
a015d7e0:  9b 33 00 0d  srl  %o4, %o5, %o5
a015d7e4:  b2 13 40 01  or  %o5, %g1, %i1
a015d7e8:  81 c7 e0 08  ret
a015d7ec:  81 e8 00 00  restore
