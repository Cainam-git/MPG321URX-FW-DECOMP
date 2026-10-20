# leon2m FUN_a00d472c 0xa00d472c-0xa00d477c (80 bytes)
a00d472c:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00d4730:  9a 12 22 90  or  %o0, 0x290, %o5	! 0xa802d290
a00d4734:  d2 0b 60 0d  ldub  [ %o5 + 0xd ], %o1
a00d4738:  c2 0b 60 0e  ldub  [ %o5 + 0xe ], %g1
a00d473c:  91 2a 60 10  sll  %o1, 0x10, %o0
a00d4740:  99 32 20 10  srl  %o0, 0x10, %o4
a00d4744:  83 28 60 10  sll  %g1, 0x10, %g1
a00d4748:  94 10 20 00  clr  %o2
a00d474c:  80 a3 20 64  cmp  %o4, 0x64
a00d4750:  08 80 00 03  bleu  0xa00d475c
a00d4754:  9b 30 60 10  srl  %g1, 0x10, %o5
a00d4758:  11 00 19 00  sethi  %hi(0x640000), %o0
a00d475c:  80 a3 60 64  cmp  %o5, 0x64
a00d4760:  08 80 00 03  bleu  0xa00d476c
a00d4764:  91 32 20 10  srl  %o0, 0x10, %o0
a00d4768:  03 00 19 00  sethi  %hi(0x640000), %g1
a00d476c:  93 30 60 10  srl  %g1, 0x10, %o1
a00d4770:  82 13 c0 00  mov  %o7, %g1
a00d4774:  40 01 c7 69  call  0xa0146518
a00d4778:  9e 10 40 00  mov  %g1, %o7
