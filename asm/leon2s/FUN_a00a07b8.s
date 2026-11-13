# leon2s FUN_a00a07b8 0xa00a07b8-0xa00a0910 (344 bytes)
a00a07b8:  80 a2 60 3f  cmp  %o1, 0x3f
a00a07bc:  18 80 00 53  bgu  0xa00a0908
a00a07c0:  03 28 02 d2  sethi  %hi(0xa00b4800), %g1
a00a07c4:  82 10 62 00  or  %g1, 0x200, %g1	! 0xa00b4a00
a00a07c8:  97 2a 60 03  sll  %o1, 3, %o3
a00a07cc:  98 02 c0 01  add  %o3, %g1, %o4
a00a07d0:  da 0b 20 04  ldub  [ %o4 + 4 ], %o5
a00a07d4:  d2 02 c0 01  ld  [ %o3 + %g1 ], %o1
a00a07d8:  9b 2b 60 03  sll  %o5, 3, %o5
a00a07dc:  c2 0b 20 06  ldub  [ %o4 + 6 ], %g1
a00a07e0:  80 a2 60 07  cmp  %o1, 7
a00a07e4:  18 80 00 49  bgu  0xa00a0908
a00a07e8:  98 03 40 01  add  %o5, %g1, %o4
a00a07ec:  1b 28 02 81  sethi  %hi(0xa00a0400), %o5
a00a07f0:  9a 13 63 98  or  %o5, 0x398, %o5	! 0xa00a0798
a00a07f4:  83 2a 60 02  sll  %o1, 2, %g1
a00a07f8:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a00a07fc:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a0800:  96 0b 20 ff  and  %o4, 0xff, %o3
a00a0804:  81 c0 40 00  jmp  %g1
a00a0808:  1b 2a 01 f6  sethi  %hi(0xa807d800), %o5
a00a080c:  9a 13 63 00  or  %o5, 0x300, %o5	! 0xa807db00
a00a0810:  82 5a 20 34  smul  %o0, 0x34, %g1
a00a0814:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a00a0818:  da 03 20 70  ld  [ %o4 + 0x70 ], %o5
a00a081c:  82 10 20 01  mov  1, %g1
a00a0820:  83 28 40 0b  sll  %g1, %o3, %g1
a00a0824:  9a 0b 60 ff  and  %o5, 0xff, %o5
a00a0828:  9a 13 40 01  or  %o5, %g1, %o5
a00a082c:  da 23 20 70  st  %o5, [ %o4 + 0x70 ]
a00a0830:  30 80 00 36  b,a   0xa00a0908
a00a0834:  9a 13 63 00  or  %o5, 0x300, %o5
a00a0838:  82 5a 20 34  smul  %o0, 0x34, %g1
a00a083c:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a00a0840:  da 03 20 74  ld  [ %o4 + 0x74 ], %o5
a00a0844:  82 10 20 01  mov  1, %g1
a00a0848:  83 28 40 0b  sll  %g1, %o3, %g1
a00a084c:  9a 0b 7f 00  and  %o5, -256, %o5
a00a0850:  9a 13 40 01  or  %o5, %g1, %o5
a00a0854:  da 23 20 74  st  %o5, [ %o4 + 0x74 ]
a00a0858:  30 80 00 2c  b,a   0xa00a0908
a00a085c:  9a 13 63 00  or  %o5, 0x300, %o5
a00a0860:  82 5a 20 34  smul  %o0, 0x34, %g1
a00a0864:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a00a0868:  c2 03 20 78  ld  [ %o4 + 0x78 ], %g1
a00a086c:  1b 3f c0 00  sethi  %hi(0xff000000), %o5
a00a0870:  9a 28 40 0d  andn  %g1, %o5, %o5
a00a0874:  82 10 20 01  mov  1, %g1
a00a0878:  83 28 40 0b  sll  %g1, %o3, %g1
a00a087c:  9a 13 40 01  or  %o5, %g1, %o5
a00a0880:  da 23 20 78  st  %o5, [ %o4 + 0x78 ]
a00a0884:  30 80 00 21  b,a   0xa00a0908
a00a0888:  9a 13 63 00  or  %o5, 0x300, %o5
a00a088c:  82 5a 20 34  smul  %o0, 0x34, %g1
a00a0890:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a00a0894:  da 03 20 7c  ld  [ %o4 + 0x7c ], %o5
a00a0898:  82 10 20 01  mov  1, %g1
a00a089c:  83 28 40 0b  sll  %g1, %o3, %g1
a00a08a0:  9a 0b 7f 00  and  %o5, -256, %o5
a00a08a4:  9a 13 40 01  or  %o5, %g1, %o5
a00a08a8:  da 23 20 7c  st  %o5, [ %o4 + 0x7c ]
a00a08ac:  30 80 00 17  b,a   0xa00a0908
a00a08b0:  9a 13 63 00  or  %o5, 0x300, %o5
a00a08b4:  82 5a 20 34  smul  %o0, 0x34, %g1
a00a08b8:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a00a08bc:  c2 03 20 80  ld  [ %o4 + 0x80 ], %g1
a00a08c0:  1b 3f c0 00  sethi  %hi(0xff000000), %o5
a00a08c4:  9a 28 40 0d  andn  %g1, %o5, %o5
a00a08c8:  82 10 20 01  mov  1, %g1
a00a08cc:  83 28 40 0b  sll  %g1, %o3, %g1
a00a08d0:  9a 13 40 01  or  %o5, %g1, %o5
a00a08d4:  da 23 20 80  st  %o5, [ %o4 + 0x80 ]
a00a08d8:  30 80 00 0c  b,a   0xa00a0908
a00a08dc:  9a 13 63 00  or  %o5, 0x300, %o5
a00a08e0:  82 5a 20 34  smul  %o0, 0x34, %g1
a00a08e4:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a00a08e8:  03 3f c0 3f  sethi  %hi(0xff00fc00), %g1
a00a08ec:  da 03 20 90  ld  [ %o4 + 0x90 ], %o5
a00a08f0:  82 10 63 00  or  %g1, 0x300, %g1
a00a08f4:  9a 0b 40 01  and  %o5, %g1, %o5
a00a08f8:  82 10 20 01  mov  1, %g1
a00a08fc:  83 28 40 0b  sll  %g1, %o3, %g1
a00a0900:  9a 13 40 01  or  %o5, %g1, %o5
a00a0904:  da 23 20 90  st  %o5, [ %o4 + 0x90 ]
a00a0908:  81 c3 e0 08  retl
a00a090c:  01 00 00 00  nop
