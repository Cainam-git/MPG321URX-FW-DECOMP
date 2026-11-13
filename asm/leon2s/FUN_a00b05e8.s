# leon2s FUN_a00b05e8 0xa00b05e8-0xa00b06e0 (248 bytes)  [FUN_a00b06d8 = unreachable ret/restore tail, merged]
a00b05e8:  9d e3 bf 98  save  %sp, -104, %sp
a00b05ec:  21 2a 01 e4  sethi  %hi(0xa8079000), %l0
a00b05f0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00b05f4:  82 14 23 18  or  %l0, 0x318, %g1
a00b05f8:  c2 08 40 18  ldub  [ %g1 + %i0 ], %g1
a00b05fc:  82 18 60 01  xor  %g1, 1, %g1
a00b0600:  80 a0 00 01  cmp  %g0, %g1
a00b0604:  9a 40 20 00  addx  %g0, 0, %o5
a00b0608:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00b060c:  80 a0 00 19  cmp  %g0, %i1
a00b0610:  82 40 20 00  addx  %g0, 0, %g1
a00b0614:  80 93 40 01  orcc  %o5, %g1, %g0
a00b0618:  02 80 00 2f  be  0xa00b06d4
a00b061c:  90 10 00 18  mov  %i0, %o0
a00b0620:  7f ff ff c8  call  0xa00b0540
a00b0624:  01 00 00 00  nop
a00b0628:  7f ff f7 5e  call  0xa00ae3a0
a00b062c:  90 10 00 18  mov  %i0, %o0
a00b0630:  90 10 00 18  mov  %i0, %o0
a00b0634:  92 10 20 01  mov  1, %o1
a00b0638:  7f ff 4e 33  call  0xa0083f04
a00b063c:  94 10 20 01  mov  1, %o2
a00b0640:  80 a6 60 00  cmp  %i1, 0
a00b0644:  02 80 00 04  be  0xa00b0654
a00b0648:  90 10 00 18  mov  %i0, %o0
a00b064c:  7f ff 51 ae  call  0xa0084d04
a00b0650:  01 00 00 00  nop
a00b0654:  7f ff 4e 59  call  0xa0083fb8
a00b0658:  90 10 00 18  mov  %i0, %o0
a00b065c:  7f ff 74 69  call  0xa008d800
a00b0660:  01 00 00 00  nop
a00b0664:  82 0a 20 ff  and  %o0, 0xff, %g1
a00b0668:  92 10 22 1d  mov  0x21d, %o1
a00b066c:  94 10 20 84  mov  0x84, %o2
a00b0670:  80 a0 60 80  cmp  %g1, 0x80
a00b0674:  08 80 00 0f  bleu  0xa00b06b0
a00b0678:  90 10 00 18  mov  %i0, %o0
a00b067c:  7f ff d9 61  call  0xa00a6c00
a00b0680:  01 00 00 00  nop
a00b0684:  90 10 00 18  mov  %i0, %o0
a00b0688:  92 10 20 c0  mov  0xc0, %o1
a00b068c:  94 10 20 80  mov  0x80, %o2
a00b0690:  7f ff d9 82  call  0xa00a6c98
a00b0694:  96 10 20 00  clr  %o3
a00b0698:  90 10 00 18  mov  %i0, %o0
a00b069c:  92 10 20 da  mov  0xda, %o1
a00b06a0:  94 10 20 10  mov  0x10, %o2
a00b06a4:  7f ff d9 7d  call  0xa00a6c98
a00b06a8:  96 10 20 01  mov  1, %o3
a00b06ac:  30 80 00 03  b,a   0xa00b06b8
a00b06b0:  7f ff 50 87  call  0xa00848cc
a00b06b4:  90 10 00 18  mov  %i0, %o0
a00b06b8:  7f ff ed 1e  call  0xa00abb30
a00b06bc:  90 10 00 18  mov  %i0, %o0
a00b06c0:  9a 14 23 18  or  %l0, 0x318, %o5
a00b06c4:  82 10 20 01  mov  1, %g1
a00b06c8:  c2 2b 40 18  stb  %g1, [ %o5 + %i0 ]
a00b06cc:  7f ff ff 93  call  0xa00b0518
a00b06d0:  81 e8 00 00  restore
a00b06d4:  01 00 00 00  nop
a00b06d8:  81 c7 e0 08  ret
a00b06dc:  81 e8 00 00  restore
