# leon2s FUN_a009c4a4 0xa009c4a4-0xa009c558 (180 bytes)
a009c4a4:  9d e3 bf 98  save  %sp, -104, %sp
a009c4a8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a009c4ac:  7f ff ff e2  call  0xa009c434
a009c4b0:  90 10 00 18  mov  %i0, %o0
a009c4b4:  80 8a 20 ff  btst  0xff, %o0
a009c4b8:  b0 5e 20 34  smul  %i0, 0x34, %i0
a009c4bc:  02 80 00 08  be  0xa009c4dc
a009c4c0:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a009c4c4:  82 10 63 00  or  %g1, 0x300, %g1	! 0xa807db00
a009c4c8:  82 06 00 01  add  %i0, %g1, %g1
a009c4cc:  c2 00 60 04  ld  [ %g1 + 4 ], %g1
a009c4d0:  c2 00 40 00  ld  [ %g1 ], %g1
a009c4d4:  10 80 00 07  b  0xa009c4f0
a009c4d8:  83 30 60 10  srl  %g1, 0x10, %g1
a009c4dc:  82 10 63 00  or  %g1, 0x300, %g1
a009c4e0:  82 06 00 01  add  %i0, %g1, %g1
a009c4e4:  c2 00 60 04  ld  [ %g1 + 4 ], %g1
a009c4e8:  c2 00 40 00  ld  [ %g1 ], %g1
a009c4ec:  83 30 60 18  srl  %g1, 0x18, %g1
a009c4f0:  82 08 60 0f  and  %g1, 0xf, %g1
a009c4f4:  80 a0 60 0e  cmp  %g1, 0xe
a009c4f8:  18 80 00 15  bgu  0xa009c54c
a009c4fc:  b0 10 20 02  mov  2, %i0
a009c500:  1b 28 02 71  sethi  %hi(0xa009c400), %o5
a009c504:  83 28 60 02  sll  %g1, 2, %g1
a009c508:  9a 13 60 68  or  %o5, 0x68, %o5
a009c50c:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a009c510:  81 c0 40 00  jmp  %g1
a009c514:  01 00 00 00  nop
a009c518:  10 80 00 0d  b  0xa009c54c
a009c51c:  b0 10 20 00  clr  %i0	! 0x0
a009c520:  10 80 00 0b  b  0xa009c54c
a009c524:  b0 10 20 08  mov  8, %i0
a009c528:  10 80 00 09  b  0xa009c54c
a009c52c:  b0 10 20 0c  mov  0xc, %i0
a009c530:  10 80 00 07  b  0xa009c54c
a009c534:  b0 10 20 0a  mov  0xa, %i0
a009c538:  10 80 00 05  b  0xa009c54c
a009c53c:  b0 10 20 0e  mov  0xe, %i0
a009c540:  10 80 00 03  b  0xa009c54c
a009c544:  b0 10 20 03  mov  3, %i0
a009c548:  b0 10 20 02  mov  2, %i0
a009c54c:  b0 0e 20 0f  and  %i0, 0xf, %i0
a009c550:  81 c7 e0 08  ret
a009c554:  81 e8 00 00  restore
