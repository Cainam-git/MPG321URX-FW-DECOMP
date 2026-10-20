# leon2m FUN_a00a0780 0xa00a0780-0xa00a09f8 (632 bytes)
a00a0780:  9d e3 bf 98  save  %sp, -104, %sp
a00a0784:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00a0788:  a2 14 22 90  or  %l0, 0x290, %l1	! 0xa802d290
a00a078c:  19 00 00 15  sethi  %hi(0x5400), %o4
a00a0790:  da 14 61 f6  lduh  [ %l1 + 0x1f6 ], %o5
a00a0794:  82 13 21 aa  or  %o4, 0x1aa, %g1
a00a0798:  80 a3 40 01  cmp  %o5, %g1
a00a079c:  02 80 00 12  be  0xa00a07e4
a00a07a0:  1b 2a 00 b3  sethi  %hi(0xa802cc00), %o5
a00a07a4:  c2 13 63 f4  lduh  [ %o5 + 0x3f4 ], %g1	! 0xa802cff4
a00a07a8:  80 88 64 00  btst  0x400, %g1
a00a07ac:  12 80 00 91  bne  0xa00a09f0
a00a07b0:  98 13 63 f4  or  %o5, 0x3f4, %o4
a00a07b4:  d0 0c 61 a9  ldub  [ %l1 + 0x1a9 ], %o0
a00a07b8:  80 a2 20 01  cmp  %o0, 1
a00a07bc:  22 80 00 3a  be,a   0xa00a08a4
a00a07c0:  d2 0c 61 8c  ldub  [ %l1 + 0x18c ], %o1
a00a07c4:  40 02 71 aa  call  0xa013ce6c
a00a07c8:  90 10 20 00  clr  %o0
a00a07cc:  a2 0a 20 ff  and  %o0, 0xff, %l1
a00a07d0:  80 a4 60 0c  cmp  %l1, 0xc
a00a07d4:  12 80 00 87  bne  0xa00a09f0
a00a07d8:  9a 14 22 90  or  %l0, 0x290, %o5
a00a07dc:  10 80 00 16  b  0xa00a0834
a00a07e0:  c2 0b 61 8c  ldub  [ %o5 + 0x18c ], %g1
a00a07e4:  17 00 3f ff  sethi  %hi(0xfffc00), %o3
a00a07e8:  d2 04 61 d4  ld  [ %l1 + 0x1d4 ], %o1
a00a07ec:  94 12 e3 00  or  %o3, 0x300, %o2
a00a07f0:  90 0a 40 0a  and  %o1, %o2, %o0
a00a07f4:  98 13 21 00  or  %o4, 0x100, %o4
a00a07f8:  80 a2 00 0c  cmp  %o0, %o4
a00a07fc:  12 bf ff f2  bne  0xa00a07c4
a00a0800:  01 00 00 00  nop
a00a0804:  40 02 8f 66  call  0xa014459c
a00a0808:  90 10 20 02  mov  2, %o0	! 0x2
a00a080c:  40 00 e2 8b  call  0xa00d9238
a00a0810:  d0 2c 60 1e  stb  %o0, [ %l1 + 0x1e ]
a00a0814:  90 10 20 04  mov  4, %o0
a00a0818:  7f ff 80 25  call  0xa00808ac
a00a081c:  92 10 20 00  clr  %o1
a00a0820:  1f 2a 00 ac  sethi  %hi(0xa802b000), %o7
a00a0824:  e2 0b e0 8e  ldub  [ %o7 + 0x8e ], %l1	! 0xa802b08e
a00a0828:  a0 14 60 02  or  %l1, 2, %l0
a00a082c:  10 80 00 71  b  0xa00a09f0
a00a0830:  e0 2b e0 8e  stb  %l0, [ %o7 + 0x8e ]
a00a0834:  80 a0 60 00  cmp  %g1, 0
a00a0838:  02 80 00 6e  be  0xa00a09f0
a00a083c:  80 a0 60 01  cmp  %g1, 1
a00a0840:  22 80 00 39  be,a   0xa00a0924
a00a0844:  de 03 61 1c  ld  [ %o5 + 0x11c ], %o7
a00a0848:  a0 14 22 90  or  %l0, 0x290, %l0
a00a084c:  da 0c 21 8c  ldub  [ %l0 + 0x18c ], %o5
a00a0850:  80 a3 60 06  cmp  %o5, 6
a00a0854:  02 80 00 48  be  0xa00a0974
a00a0858:  01 00 00 00  nop
a00a085c:  82 0b 60 ff  and  %o5, 0xff, %g1
a00a0860:  80 a0 60 06  cmp  %g1, 6
a00a0864:  02 80 00 2a  be  0xa00a090c
a00a0868:  80 a0 60 09  cmp  %g1, 9
a00a086c:  02 80 00 56  be  0xa00a09c4
a00a0870:  01 00 00 00  nop
a00a0874:  92 0b 60 ff  and  %o5, 0xff, %o1
a00a0878:  80 a2 60 0a  cmp  %o1, 0xa
a00a087c:  02 80 00 4c  be  0xa00a09ac
a00a0880:  01 00 00 00  nop
a00a0884:  40 00 61 7e  call  0xa00b8e7c
a00a0888:  90 10 20 02  mov  2, %o0	! 0x2
a00a088c:  e2 0c 21 8c  ldub  [ %l0 + 0x18c ], %l1
a00a0890:  94 04 60 f9  add  %l1, 0xf9, %o2
a00a0894:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a00a0898:  d4 24 23 ec  st  %o2, [ %l0 + 0x3ec ]	! 0xa802afec
a00a089c:  40 00 0f 43  call  0xa00a45a8
a00a08a0:  81 e8 00 00  restore
a00a08a4:  80 a2 60 02  cmp  %o1, 2
a00a08a8:  12 bf ff c7  bne  0xa00a07c4
a00a08ac:  1b 3f ff e0  sethi  %hi(0xffff8000), %o5
a00a08b0:  d6 13 20 04  lduh  [ %o4 + 4 ], %o3
a00a08b4:  a0 0a c0 0d  and  %o3, %o5, %l0
a00a08b8:  95 2c 20 10  sll  %l0, 0x10, %o2
a00a08bc:  9e 10 20 05  mov  5, %o7
a00a08c0:  80 a2 a0 00  cmp  %o2, 0
a00a08c4:  12 80 00 33  bne  0xa00a0990
a00a08c8:  de 2b 20 0a  stb  %o7, [ %o4 + 0xa ]
a00a08cc:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a00a08d0:  40 00 51 ec  call  0xa00b5080
a00a08d4:  c0 24 23 ec  clr  [ %l0 + 0x3ec ]	! 0xa802afec
a00a08d8:  40 00 41 9c  call  0xa00b0f48
a00a08dc:  01 00 00 00  nop
a00a08e0:  17 2a 00 ac  sethi  %hi(0xa802b000), %o3
a00a08e4:  d4 0a e0 8e  ldub  [ %o3 + 0x8e ], %o2	! 0xa802b08e
a00a08e8:  90 12 a0 02  or  %o2, 2, %o0
a00a08ec:  92 10 21 16  mov  0x116, %o1
a00a08f0:  d2 24 23 ec  st  %o1, [ %l0 + 0x3ec ]
a00a08f4:  d0 2a e0 8e  stb  %o0, [ %o3 + 0x8e ]
a00a08f8:  67 ff b3 24  call  0x4008d588
a00a08fc:  c0 2c 61 aa  clrb  [ %l1 + 0x1aa ]
a00a0900:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00a0904:  10 80 00 3b  b  0xa00a09f0
a00a0908:  d0 33 20 3c  sth  %o0, [ %o4 + 0x3c ]	! 0xa802d03c
a00a090c:  d8 04 21 f4  ld  [ %l0 + 0x1f4 ], %o4
a00a0910:  80 a3 20 00  cmp  %o4, 0
a00a0914:  06 80 00 37  bl  0xa00a09f0
a00a0918:  92 0b 60 ff  and  %o5, 0xff, %o1
a00a091c:  10 bf ff d8  b  0xa00a087c
a00a0920:  80 a2 60 0a  cmp  %o1, 0xa
a00a0924:  80 a3 e0 00  cmp  %o7, 0
a00a0928:  06 80 00 32  bl  0xa00a09f0
a00a092c:  01 00 00 00  nop
a00a0930:  c2 03 60 b0  ld  [ %o5 + 0xb0 ], %g1
a00a0934:  80 a0 60 00  cmp  %g1, 0
a00a0938:  02 80 00 08  be  0xa00a0958
a00a093c:  01 00 00 00  nop
a00a0940:  40 00 e0 a6  call  0xa00d8bd8
a00a0944:  01 00 00 00  nop
a00a0948:  9a 0a 20 ff  and  %o0, 0xff, %o5
a00a094c:  80 a3 60 01  cmp  %o5, 1
a00a0950:  02 80 00 28  be  0xa00a09f0
a00a0954:  01 00 00 00  nop
a00a0958:  40 00 dc fc  call  0xa00d7d48
a00a095c:  01 00 00 00  nop
a00a0960:  80 a2 20 00  cmp  %o0, 0
a00a0964:  12 80 00 23  bne  0xa00a09f0
a00a0968:  a0 14 22 90  or  %l0, 0x290, %l0
a00a096c:  10 bf ff b9  b  0xa00a0850
a00a0970:  da 0c 21 8c  ldub  [ %l0 + 0x18c ], %o5
a00a0974:  40 00 dc f5  call  0xa00d7d48
a00a0978:  01 00 00 00  nop
a00a097c:  80 a2 20 00  cmp  %o0, 0
a00a0980:  12 80 00 1c  bne  0xa00a09f0
a00a0984:  01 00 00 00  nop
a00a0988:  10 bf ff b5  b  0xa00a085c
a00a098c:  da 0c 21 8c  ldub  [ %l0 + 0x18c ], %o5
a00a0990:  82 12 e4 00  or  %o3, 0x400, %g1
a00a0994:  c2 33 20 04  sth  %g1, [ %o4 + 4 ]
a00a0998:  90 10 20 04  mov  4, %o0
a00a099c:  7f ff 7f c4  call  0xa00808ac
a00a09a0:  92 10 20 00  clr  %o1
a00a09a4:  10 bf ff cb  b  0xa00a08d0
a00a09a8:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a00a09ac:  40 00 dc e7  call  0xa00d7d48
a00a09b0:  01 00 00 00  nop
a00a09b4:  80 a2 20 00  cmp  %o0, 0
a00a09b8:  02 bf ff b3  be  0xa00a0884
a00a09bc:  01 00 00 00  nop
a00a09c0:  30 80 00 0c  b,a   0xa00a09f0
a00a09c4:  40 00 dc e1  call  0xa00d7d48
a00a09c8:  01 00 00 00  nop
a00a09cc:  80 a2 20 00  cmp  %o0, 0
a00a09d0:  12 80 00 08  bne  0xa00a09f0
a00a09d4:  17 00 00 20  sethi  %hi(0x8000), %o3
a00a09d8:  d0 04 21 74  ld  [ %l0 + 0x174 ], %o0
a00a09dc:  80 8a 00 0b  btst  %o0, %o3
a00a09e0:  12 80 00 04  bne  0xa00a09f0
a00a09e4:  01 00 00 00  nop
a00a09e8:  10 bf ff a3  b  0xa00a0874
a00a09ec:  da 0c 21 8c  ldub  [ %l0 + 0x18c ], %o5
a00a09f0:  81 c7 e0 08  ret
a00a09f4:  81 e8 00 00  restore
