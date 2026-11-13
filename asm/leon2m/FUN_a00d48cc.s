# leon2m FUN_a00d48cc 0xa00d48cc-0xa00d4910 (68 bytes)
a00d48cc:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00d48d0:  d0 03 22 90  ld  [ %o4 + 0x290 ], %o0	! 0xa802d290
a00d48d4:  83 32 20 0b  srl  %o0, 0xb, %g1
a00d48d8:  82 08 60 01  and  %g1, 1, %g1
a00d48dc:  80 a0 60 01  cmp  %g1, 1
a00d48e0:  08 80 00 03  bleu  0xa00d48ec
a00d48e4:  9a 0a 37 ff  and  %o0, -2049, %o5
a00d48e8:  82 10 20 01  mov  1, %g1
a00d48ec:  91 28 60 0b  sll  %g1, 0xb, %o0
a00d48f0:  82 13 40 08  or  %o5, %o0, %g1
a00d48f4:  9b 30 60 0b  srl  %g1, 0xb, %o5
a00d48f8:  c2 23 22 90  st  %g1, [ %o4 + 0x290 ]
a00d48fc:  90 0b 60 01  and  %o5, 1, %o0
a00d4900:  82 13 c0 00  mov  %o7, %g1
a00d4904:  40 01 cc 3a  call  0xa01479ec
a00d4908:  9e 10 40 00  mov  %g1, %o7
a00d490c:  01 00 00 00  nop
