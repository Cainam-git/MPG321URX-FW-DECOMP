# leon2s FUN_a00d3704 0xa00d3704-0xa00d378c (136 bytes)
a00d3704:  9d e3 bf 98  save  %sp, -104, %sp
a00d3708:  80 a6 60 01  cmp  %i1, 1
a00d370c:  12 80 00 11  bne  0xa00d3750
a00d3710:  33 2a 01 e1  sethi  %hi(0xa8078400), %i1
a00d3714:  d2 06 61 e0  ld  [ %i1 + 0x1e0 ], %o1	! 0xa80785e0
a00d3718:  80 a2 40 18  cmp  %o1, %i0
a00d371c:  18 80 00 05  bgu  0xa00d3730
a00d3720:  a0 10 00 19  mov  %i1, %l0
a00d3724:  80 a2 40 18  cmp  %o1, %i0
a00d3728:  3a 80 00 07  bcc,a   0xa00d3744
a00d372c:  c2 04 21 e0  ld  [ %l0 + 0x1e0 ], %g1
a00d3730:  91 2e 20 08  sll  %i0, 8, %o0
a00d3734:  7f ff ff ec  call  0xa00d36e4
a00d3738:  94 10 20 28  mov  0x28, %o2
a00d373c:  d0 26 61 e0  st  %o0, [ %i1 + 0x1e0 ]
a00d3740:  c2 04 21 e0  ld  [ %l0 + 0x1e0 ], %g1
a00d3744:  82 00 60 80  add  %g1, 0x80, %g1
a00d3748:  10 80 00 04  b  0xa00d3758
a00d374c:  b1 30 60 08  srl  %g1, 8, %i0
a00d3750:  83 2e 20 08  sll  %i0, 8, %g1
a00d3754:  c2 26 61 e0  st  %g1, [ %i1 + 0x1e0 ]
a00d3758:  80 a6 25 14  cmp  %i0, 0x514
a00d375c:  18 80 00 07  bgu  0xa00d3778
a00d3760:  82 10 25 14  mov  0x514, %g1
a00d3764:  03 2a 01 e0  sethi  %hi(0xa8078000), %g1
a00d3768:  c2 10 63 dc  lduh  [ %g1 + 0x3dc ], %g1	! 0xa80783dc
a00d376c:  80 a6 00 01  cmp  %i0, %g1
a00d3770:  3a 80 00 02  bcc,a   0xa00d3778
a00d3774:  82 10 00 18  mov  %i0, %g1
a00d3778:  b1 28 60 10  sll  %g1, 0x10, %i0
a00d377c:  b1 36 20 10  srl  %i0, 0x10, %i0
a00d3780:  7f ff fa fe  call  0xa00d2378
a00d3784:  81 e8 00 00  restore
a00d3788:  01 00 00 00  nop
