# leon2m FUN_a00e0788 0xa00e0788-0xa00e0888 (256 bytes)
a00e0788:  9d e3 bf 98  save  %sp, -104, %sp
a00e078c:  25 2a 00 ad  sethi  %hi(0xa802b400), %l2
a00e0790:  c2 04 a1 50  ld  [ %l2 + 0x150 ], %g1	! 0xa802b550
a00e0794:  80 a0 60 00  cmp  %g1, 0
a00e0798:  12 80 00 22  bne  0xa00e0820
a00e079c:  11 00 06 65  sethi  %hi(0x199400), %o0
a00e07a0:  a2 10 20 00  clr  %l1
a00e07a4:  10 80 00 08  b  0xa00e07c4
a00e07a8:  a6 10 00 12  mov  %l2, %l3
a00e07ac:  80 a4 00 1b  cmp  %l0, %i3
a00e07b0:  02 80 00 18  be  0xa00e0810
a00e07b4:  d6 04 e1 50  ld  [ %l3 + 0x150 ], %o3
a00e07b8:  80 a4 60 09  cmp  %l1, 9
a00e07bc:  14 80 00 20  bg  0xa00e083c
a00e07c0:  da 04 a1 50  ld  [ %l2 + 0x150 ], %o5
a00e07c4:  7f ff fd f8  call  0xa00dffa4
a00e07c8:  90 10 20 02  mov  2, %o0
a00e07cc:  92 10 00 19  mov  %i1, %o1
a00e07d0:  7f ff fe c7  call  0xa00e02ec
a00e07d4:  90 10 00 18  mov  %i0, %o0
a00e07d8:  a0 0a 00 1a  and  %o0, %i2, %l0
a00e07dc:  13 00 06 65  sethi  %hi(0x199400), %o1
a00e07e0:  d4 04 a1 50  ld  [ %l2 + 0x150 ], %o2
a00e07e4:  90 12 61 08  or  %o1, 0x108, %o0
a00e07e8:  a2 04 60 01  inc  %l1
a00e07ec:  80 a2 a0 00  cmp  %o2, 0
a00e07f0:  02 bf ff ef  be  0xa00e07ac
a00e07f4:  92 10 00 10  mov  %l0, %o1
a00e07f8:  7f ff fa 5e  call  0xa00df170
a00e07fc:  01 00 00 00  nop
a00e0800:  80 a4 00 1b  cmp  %l0, %i3
a00e0804:  12 bf ff ee  bne  0xa00e07bc
a00e0808:  80 a4 60 09  cmp  %l1, 9
a00e080c:  d6 04 e1 50  ld  [ %l3 + 0x150 ], %o3
a00e0810:  80 a2 e0 00  cmp  %o3, 0
a00e0814:  12 80 00 16  bne  0xa00e086c
a00e0818:  b0 10 20 01  mov  1, %i0
a00e081c:  30 80 00 19  b,a   0xa00e0880
a00e0820:  92 10 00 19  mov  %i1, %o1
a00e0824:  94 10 00 1a  mov  %i2, %o2
a00e0828:  96 10 00 1b  mov  %i3, %o3
a00e082c:  7f ff fa 51  call  0xa00df170
a00e0830:  90 12 20 e0  or  %o0, 0xe0, %o0
a00e0834:  10 bf ff dc  b  0xa00e07a4
a00e0838:  a2 10 20 00  clr  %l1
a00e083c:  80 a3 60 00  cmp  %o5, 0
a00e0840:  12 80 00 04  bne  0xa00e0850
a00e0844:  1f 00 06 65  sethi  %hi(0x199400), %o7
a00e0848:  10 80 00 0e  b  0xa00e0880
a00e084c:  b0 10 20 00  clr  %i0
a00e0850:  90 13 e1 28  or  %o7, 0x128, %o0
a00e0854:  92 10 00 19  mov  %i1, %o1
a00e0858:  94 10 00 1b  mov  %i3, %o2
a00e085c:  7f ff fa 45  call  0xa00df170
a00e0860:  96 10 00 10  mov  %l0, %o3
a00e0864:  10 80 00 07  b  0xa00e0880
a00e0868:  b0 10 20 00  clr  %i0
a00e086c:  19 00 06 65  sethi  %hi(0x199400), %o4
a00e0870:  90 13 21 50  or  %o4, 0x150, %o0	! 0x199550
a00e0874:  7f ff fa 3f  call  0xa00df170
a00e0878:  92 10 00 19  mov  %i1, %o1
a00e087c:  b0 10 20 01  mov  1, %i0
a00e0880:  81 c7 e0 08  ret
a00e0884:  81 e8 00 00  restore
