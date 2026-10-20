# leon2m FUN_a00dd43c 0xa00dd43c-0xa00dd540 (260 bytes)  [FUN_a00dd538 = unreachable ret/restore tail, merged]
a00dd43c:  9d e3 bf 98  save  %sp, -104, %sp
a00dd440:  80 a6 20 00  cmp  %i0, 0
a00dd444:  02 80 00 3c  be  0xa00dd534
a00dd448:  80 a6 60 00  cmp  %i1, 0
a00dd44c:  02 80 00 0f  be  0xa00dd488
a00dd450:  a4 0e 3f fc  and  %i0, -4, %l2
a00dd454:  83 2e 60 02  sll  %i1, 2, %g1
a00dd458:  b2 00 40 12  add  %g1, %l2, %i1
a00dd45c:  9a 06 60 1f  add  %i1, 0x1f, %o5
a00dd460:  29 00 03 fb  sethi  %hi(0xfec00), %l4
a00dd464:  aa 0b 7f e0  and  %o5, -32, %l5
a00dd468:  90 15 23 90  or  %l4, 0x390, %o0
a00dd46c:  40 00 06 b5  call  0xa00def40
a00dd470:  b0 0e 3f e0  and  %i0, -32, %i0
a00dd474:  80 a6 00 15  cmp  %i0, %l5
a00dd478:  0a 80 00 10  bcs  0xa00dd4b8
a00dd47c:  a2 10 00 18  mov  %i0, %l1
a00dd480:  40 00 06 b0  call  0xa00def40
a00dd484:  91 ed 23 90  restore  %l4, 0x390, %o0
a00dd488:  b2 10 20 20  mov  0x20, %i1
a00dd48c:  83 2e 60 02  sll  %i1, 2, %g1
a00dd490:  b2 00 40 12  add  %g1, %l2, %i1
a00dd494:  9a 06 60 1f  add  %i1, 0x1f, %o5
a00dd498:  29 00 03 fb  sethi  %hi(0xfec00), %l4
a00dd49c:  aa 0b 7f e0  and  %o5, -32, %l5
a00dd4a0:  90 15 23 90  or  %l4, 0x390, %o0
a00dd4a4:  40 00 06 a7  call  0xa00def40
a00dd4a8:  b0 0e 3f e0  and  %i0, -32, %i0
a00dd4ac:  80 a6 00 15  cmp  %i0, %l5
a00dd4b0:  1a bf ff f4  bcc  0xa00dd480
a00dd4b4:  a2 10 00 18  mov  %i0, %l1
a00dd4b8:  2f 00 06 62  sethi  %hi(0x198800), %l7
a00dd4bc:  27 00 06 62  sethi  %hi(0x198800), %l3
a00dd4c0:  2d 00 06 62  sethi  %hi(0x198800), %l6
a00dd4c4:  40 00 06 ce  call  0xa00deffc
a00dd4c8:  90 10 00 11  mov  %l1, %o0
a00dd4cc:  40 00 06 9d  call  0xa00def40
a00dd4d0:  90 15 e3 60  or  %l7, 0x360, %o0
a00dd4d4:  a0 10 20 03  mov  3, %l0
a00dd4d8:  80 a6 00 12  cmp  %i0, %l2
a00dd4dc:  94 40 20 00  addx  %g0, 0, %o2
a00dd4e0:  80 a6 00 19  cmp  %i0, %i1
a00dd4e4:  92 60 3f ff  subx  %g0, -1, %o1
a00dd4e8:  80 92 80 09  orcc  %o2, %o1, %g0
a00dd4ec:  12 80 00 05  bne  0xa00dd500
a00dd4f0:  90 14 e3 a8  or  %l3, 0x3a8, %o0
a00dd4f4:  40 00 06 c2  call  0xa00deffc
a00dd4f8:  d0 06 00 00  ld  [ %i0 ], %o0
a00dd4fc:  90 15 a3 b0  or  %l6, 0x3b0, %o0
a00dd500:  40 00 06 90  call  0xa00def40
a00dd504:  b0 06 20 04  add  %i0, 4, %i0
a00dd508:  a0 84 3f ff  addcc  %l0, -1, %l0
a00dd50c:  1c bf ff f4  bpos  0xa00dd4dc
a00dd510:  80 a6 00 12  cmp  %i0, %l2
a00dd514:  40 00 06 8b  call  0xa00def40
a00dd518:  90 15 23 90  or  %l4, 0x390, %o0
a00dd51c:  a2 04 60 10  add  %l1, 0x10, %l1
a00dd520:  80 a4 40 15  cmp  %l1, %l5
a00dd524:  0a bf ff e8  bcs  0xa00dd4c4
a00dd528:  01 00 00 00  nop
a00dd52c:  40 00 06 85  call  0xa00def40
a00dd530:  91 ed 23 90  restore  %l4, 0x390, %o0
a00dd534:  01 00 00 00  nop
a00dd538:  81 c7 e0 08  ret
a00dd53c:  81 e8 00 00  restore
