# leon2s FUN_a009f66c 0xa009f66c-0xa009f738 (204 bytes)
a009f66c:  9d e3 bf 98  save  %sp, -104, %sp
a009f670:  b0 0e 20 ff  and  %i0, 0xff, %i0
a009f674:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a009f678:  82 10 63 00  or  %g1, 0x300, %g1	! 0xa807db00
a009f67c:  b0 5e 20 34  smul  %i0, 0x34, %i0
a009f680:  b0 06 00 01  add  %i0, %g1, %i0
a009f684:  d2 06 20 0c  ld  [ %i0 + 0xc ], %o1
a009f688:  92 02 60 7c  add  %o1, 0x7c, %o1
a009f68c:  40 00 1f 52  call  0xa00a73d4
a009f690:  90 10 20 0b  mov  0xb, %o0
a009f694:  d2 06 20 0c  ld  [ %i0 + 0xc ], %o1
a009f698:  92 02 60 60  add  %o1, 0x60, %o1
a009f69c:  40 00 1f 4e  call  0xa00a73d4
a009f6a0:  90 10 20 00  clr  %o0
a009f6a4:  d2 06 20 0c  ld  [ %i0 + 0xc ], %o1
a009f6a8:  92 02 60 60  add  %o1, 0x60, %o1
a009f6ac:  40 00 1f 4a  call  0xa00a73d4
a009f6b0:  90 10 20 01  mov  1, %o0
a009f6b4:  d2 06 20 0c  ld  [ %i0 + 0xc ], %o1
a009f6b8:  da 02 60 5c  ld  [ %o1 + 0x5c ], %o5
a009f6bc:  03 3f c0 00  sethi  %hi(0xff000000), %g1
a009f6c0:  82 2b 40 01  andn  %o5, %g1, %g1
a009f6c4:  c2 22 60 5c  st  %g1, [ %o1 + 0x5c ]
a009f6c8:  92 02 60 60  add  %o1, 0x60, %o1
a009f6cc:  40 00 1f 42  call  0xa00a73d4
a009f6d0:  90 10 20 08  mov  8, %o0
a009f6d4:  d2 06 20 0c  ld  [ %i0 + 0xc ], %o1
a009f6d8:  92 02 60 60  add  %o1, 0x60, %o1
a009f6dc:  40 00 1f 3e  call  0xa00a73d4
a009f6e0:  90 10 20 09  mov  9, %o0
a009f6e4:  d2 06 20 18  ld  [ %i0 + 0x18 ], %o1
a009f6e8:  92 02 60 90  add  %o1, 0x90, %o1
a009f6ec:  40 00 1f 3a  call  0xa00a73d4
a009f6f0:  90 10 20 11  mov  0x11, %o0
a009f6f4:  d2 06 20 18  ld  [ %i0 + 0x18 ], %o1
a009f6f8:  92 02 60 80  add  %o1, 0x80, %o1
a009f6fc:  40 00 1f 36  call  0xa00a73d4
a009f700:  90 10 20 06  mov  6, %o0
a009f704:  7f ff b8 3f  call  0xa008d800
a009f708:  01 00 00 00  nop
a009f70c:  90 0a 20 ff  and  %o0, 0xff, %o0
a009f710:  80 a2 20 82  cmp  %o0, 0x82
a009f714:  08 80 00 07  bleu  0xa009f730
a009f718:  03 3f ff c0  sethi  %hi(0xffff0000), %g1
a009f71c:  d8 06 20 18  ld  [ %i0 + 0x18 ], %o4
a009f720:  da 03 20 b0  ld  [ %o4 + 0xb0 ], %o5
a009f724:  82 10 60 ff  or  %g1, 0xff, %g1
a009f728:  9a 0b 40 01  and  %o5, %g1, %o5
a009f72c:  da 23 20 b0  st  %o5, [ %o4 + 0xb0 ]
a009f730:  81 c7 e0 08  ret
a009f734:  81 e8 00 00  restore
