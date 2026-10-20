# leon2m FUN_a00b0710 0xa00b0710-0xa00b0a90 (896 bytes)
a00b0710:  9d e3 bf 98  save  %sp, -104, %sp
a00b0714:  98 0e 20 ff  and  %i0, 0xff, %o4
a00b0718:  80 a3 20 01  cmp  %o4, 1
a00b071c:  92 10 20 00  clr  %o1
a00b0720:  b6 10 20 00  clr  %i3
a00b0724:  a0 10 20 00  clr  %l0
a00b0728:  a2 10 20 00  clr  %l1
a00b072c:  02 80 00 31  be  0xa00b07f0
a00b0730:  94 10 20 00  clr  %o2
a00b0734:  80 a3 20 01  cmp  %o4, 1
a00b0738:  04 80 00 4f  ble  0xa00b0874
a00b073c:  80 a3 20 02  cmp  %o4, 2
a00b0740:  02 80 00 3b  be  0xa00b082c
a00b0744:  80 a3 20 03  cmp  %o4, 3
a00b0748:  02 80 00 7b  be  0xa00b0934
a00b074c:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00b0750:  96 06 3f fe  add  %i0, -2, %o3
a00b0754:  90 0a e0 ff  and  %o3, 0xff, %o0
a00b0758:  80 a2 20 01  cmp  %o0, 1
a00b075c:  08 80 00 0f  bleu  0xa00b0798
a00b0760:  80 a3 20 03  cmp  %o4, 3
a00b0764:  80 8e 60 ff  btst  0xff, %i1
a00b0768:  02 80 00 27  be  0xa00b0804
a00b076c:  b4 0a a0 ff  and  %o2, 0xff, %i2
a00b0770:  92 0a 60 1f  and  %o1, 0x1f, %o1
a00b0774:  90 10 20 03  mov  3, %o0
a00b0778:  94 10 00 1a  mov  %i2, %o2
a00b077c:  96 10 20 01  mov  1, %o3
a00b0780:  7f ff f3 89  call  0xa00ad5a4
a00b0784:  b2 0e e0 1f  and  %i3, 0x1f, %i1
a00b0788:  b0 10 20 03  mov  3, %i0
a00b078c:  b6 10 20 00  clr  %i3
a00b0790:  7f ff f3 85  call  0xa00ad5a4
a00b0794:  81 e8 00 00  restore
a00b0798:  02 80 00 3e  be  0xa00b0890
a00b079c:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00b07a0:  80 a6 60 01  cmp  %i1, 1
a00b07a4:  02 80 00 70  be  0xa00b0964
a00b07a8:  b4 0a a0 ff  and  %o2, 0xff, %i2
a00b07ac:  80 a6 60 00  cmp  %i1, 0
a00b07b0:  12 80 00 24  bne  0xa00b0840
a00b07b4:  92 0a 60 1f  and  %o1, 0x1f, %o1
a00b07b8:  b4 0a a0 ff  and  %o2, 0xff, %i2
a00b07bc:  90 10 20 03  mov  3, %o0
a00b07c0:  94 10 00 1a  mov  %i2, %o2
a00b07c4:  7f ff f3 78  call  0xa00ad5a4
a00b07c8:  96 10 20 00  clr  %o3
a00b07cc:  92 0e e0 1f  and  %i3, 0x1f, %o1
a00b07d0:  90 10 20 03  mov  3, %o0
a00b07d4:  94 10 00 1a  mov  %i2, %o2
a00b07d8:  96 10 20 01  mov  1, %o3
a00b07dc:  7f ff f3 72  call  0xa00ad5a4
a00b07e0:  b2 0c 20 3f  and  %l0, 0x3f, %i1
a00b07e4:  b0 10 20 03  mov  3, %i0
a00b07e8:  10 bf ff ea  b  0xa00b0790
a00b07ec:  b6 10 20 00  clr  %i3
a00b07f0:  92 10 20 10  mov  0x10, %o1
a00b07f4:  b6 10 20 1c  mov  0x1c, %i3
a00b07f8:  a0 10 20 25  mov  0x25, %l0
a00b07fc:  10 bf ff d5  b  0xa00b0750
a00b0800:  94 10 20 16  mov  0x16, %o2
a00b0804:  92 0a 60 1f  and  %o1, 0x1f, %o1
a00b0808:  90 10 20 03  mov  3, %o0
a00b080c:  94 10 00 1a  mov  %i2, %o2
a00b0810:  96 10 20 00  clr  %o3
a00b0814:  7f ff f3 64  call  0xa00ad5a4
a00b0818:  b2 0e e0 1f  and  %i3, 0x1f, %i1
a00b081c:  b0 10 20 03  mov  3, %i0
a00b0820:  b6 10 20 01  mov  1, %i3
a00b0824:  7f ff f3 60  call  0xa00ad5a4
a00b0828:  81 e8 00 00  restore
a00b082c:  92 10 20 0a  mov  0xa, %o1
a00b0830:  b6 10 20 16  mov  0x16, %i3
a00b0834:  a0 10 20 23  mov  0x23, %l0
a00b0838:  10 bf ff c6  b  0xa00b0750
a00b083c:  94 10 20 16  mov  0x16, %o2
a00b0840:  90 10 20 03  mov  3, %o0
a00b0844:  94 10 00 1a  mov  %i2, %o2
a00b0848:  7f ff f3 57  call  0xa00ad5a4
a00b084c:  96 10 20 00  clr  %o3
a00b0850:  92 0e e0 1f  and  %i3, 0x1f, %o1
a00b0854:  90 10 20 03  mov  3, %o0
a00b0858:  94 10 00 1a  mov  %i2, %o2
a00b085c:  7f ff f3 52  call  0xa00ad5a4
a00b0860:  96 10 20 00  clr  %o3
a00b0864:  b2 0c 20 3f  and  %l0, 0x3f, %i1
a00b0868:  b0 10 20 03  mov  3, %i0
a00b086c:  10 bf ff ee  b  0xa00b0824
a00b0870:  b6 10 20 01  mov  1, %i3
a00b0874:  80 a3 20 00  cmp  %o4, 0
a00b0878:  12 bf ff b7  bne  0xa00b0754
a00b087c:  96 06 3f fe  add  %i0, -2, %o3
a00b0880:  92 10 20 09  mov  9, %o1
a00b0884:  b6 10 20 15  mov  0x15, %i3
a00b0888:  10 bf ff b2  b  0xa00b0750
a00b088c:  94 10 20 07  mov  7, %o2
a00b0890:  80 a6 60 00  cmp  %i1, 0
a00b0894:  02 80 00 3e  be  0xa00b098c
a00b0898:  80 a6 60 01  cmp  %i1, 1
a00b089c:  02 80 00 62  be  0xa00b0a24
a00b08a0:  80 a6 60 02  cmp  %i1, 2
a00b08a4:  02 80 00 45  be  0xa00b09b8
a00b08a8:  b4 0a a0 ff  and  %o2, 0xff, %i2
a00b08ac:  92 0a 60 1f  and  %o1, 0x1f, %o1
a00b08b0:  90 10 20 03  mov  3, %o0
a00b08b4:  94 10 00 1a  mov  %i2, %o2
a00b08b8:  96 10 20 00  clr  %o3
a00b08bc:  7f ff f3 3a  call  0xa00ad5a4
a00b08c0:  01 00 00 00  nop
a00b08c4:  13 2a 00 b5  sethi  %hi(0xa802d400), %o1
a00b08c8:  d6 0a 60 72  ldub  [ %o1 + 0x72 ], %o3	! 0xa802d472
a00b08cc:  80 a2 e0 02  cmp  %o3, 2
a00b08d0:  08 80 00 09  bleu  0xa00b08f4
a00b08d4:  92 0e e0 1f  and  %i3, 0x1f, %o1
a00b08d8:  7f ff 81 bd  call  0xa0090fcc
a00b08dc:  01 00 00 00  nop
a00b08e0:  99 2a 20 10  sll  %o0, 0x10, %o4
a00b08e4:  95 33 20 10  srl  %o4, 0x10, %o2
a00b08e8:  80 a2 a1 0a  cmp  %o2, 0x10a
a00b08ec:  02 80 00 07  be  0xa00b0908
a00b08f0:  92 0e e0 1f  and  %i3, 0x1f, %o1
a00b08f4:  90 10 20 03  mov  3, %o0
a00b08f8:  94 10 00 1a  mov  %i2, %o2
a00b08fc:  96 10 20 00  clr  %o3
a00b0900:  7f ff f3 29  call  0xa00ad5a4
a00b0904:  01 00 00 00  nop
a00b0908:  92 0c 20 3f  and  %l0, 0x3f, %o1
a00b090c:  90 10 20 03  mov  3, %o0
a00b0910:  94 10 00 1a  mov  %i2, %o2
a00b0914:  96 10 20 00  clr  %o3
a00b0918:  7f ff f3 23  call  0xa00ad5a4
a00b091c:  37 2a 00 b4  sethi  %hi(0xa802d000), %i3
a00b0920:  e0 0e e0 33  ldub  [ %i3 + 0x33 ], %l0	! 0xa802d033
a00b0924:  80 a4 20 01  cmp  %l0, 1
a00b0928:  12 80 00 58  bne  0xa00b0a88
a00b092c:  80 a6 60 03  cmp  %i1, 3
a00b0930:  30 80 00 1d  b,a   0xa00b09a4
a00b0934:  da 08 60 33  ldub  [ %g1 + 0x33 ], %o5
a00b0938:  80 a3 60 02  cmp  %o5, 2
a00b093c:  92 10 20 0a  mov  0xa, %o1
a00b0940:  b6 10 20 17  mov  0x17, %i3
a00b0944:  02 bf ff d1  be  0xa00b0888
a00b0948:  a0 10 20 24  mov  0x24, %l0
a00b094c:  92 10 20 04  mov  4, %o1
a00b0950:  b6 10 20 10  mov  0x10, %i3
a00b0954:  a0 10 20 1c  mov  0x1c, %l0
a00b0958:  a2 10 20 28  mov  0x28, %l1
a00b095c:  10 bf ff 7d  b  0xa00b0750
a00b0960:  94 10 20 07  mov  7, %o2
a00b0964:  92 0a 60 1f  and  %o1, 0x1f, %o1
a00b0968:  90 10 20 03  mov  3, %o0
a00b096c:  94 10 00 1a  mov  %i2, %o2
a00b0970:  7f ff f3 0d  call  0xa00ad5a4
a00b0974:  96 10 20 01  mov  1, %o3
a00b0978:  92 0e e0 1f  and  %i3, 0x1f, %o1
a00b097c:  90 10 20 03  mov  3, %o0
a00b0980:  94 10 00 1a  mov  %i2, %o2
a00b0984:  10 bf ff 96  b  0xa00b07dc
a00b0988:  96 10 20 00  clr  %o3
a00b098c:  b4 0a a0 ff  and  %o2, 0xff, %i2
a00b0990:  92 0a 60 1f  and  %o1, 0x1f, %o1
a00b0994:  90 10 20 03  mov  3, %o0
a00b0998:  94 10 00 1a  mov  %i2, %o2
a00b099c:  10 bf ff c8  b  0xa00b08bc
a00b09a0:  96 10 20 01  mov  1, %o3
a00b09a4:  02 80 00 36  be  0xa00b0a7c
a00b09a8:  b2 0c 60 28  and  %l1, 0x28, %i1
a00b09ac:  b0 10 20 03  mov  3, %i0
a00b09b0:  10 bf ff 78  b  0xa00b0790
a00b09b4:  b6 10 20 00  clr  %i3
a00b09b8:  92 0a 60 1f  and  %o1, 0x1f, %o1
a00b09bc:  90 10 20 03  mov  3, %o0
a00b09c0:  94 10 00 1a  mov  %i2, %o2
a00b09c4:  7f ff f2 f8  call  0xa00ad5a4
a00b09c8:  96 10 20 00  clr  %o3
a00b09cc:  1b 2a 00 b5  sethi  %hi(0xa802d400), %o5
a00b09d0:  f0 0b 60 72  ldub  [ %o5 + 0x72 ], %i0	! 0xa802d472
a00b09d4:  80 a6 20 02  cmp  %i0, 2
a00b09d8:  08 80 00 0a  bleu  0xa00b0a00
a00b09dc:  92 0e e0 1f  and  %i3, 0x1f, %o1
a00b09e0:  7f ff 81 7b  call  0xa0090fcc
a00b09e4:  01 00 00 00  nop
a00b09e8:  91 2a 20 10  sll  %o0, 0x10, %o0
a00b09ec:  83 32 20 10  srl  %o0, 0x10, %g1
a00b09f0:  80 a0 61 0a  cmp  %g1, 0x10a
a00b09f4:  22 80 00 08  be,a   0xa00b0a14
a00b09f8:  92 0c 20 3f  and  %l0, 0x3f, %o1
a00b09fc:  92 0e e0 1f  and  %i3, 0x1f, %o1
a00b0a00:  90 10 20 03  mov  3, %o0
a00b0a04:  94 10 00 1a  mov  %i2, %o2
a00b0a08:  7f ff f2 e7  call  0xa00ad5a4
a00b0a0c:  96 10 20 00  clr  %o3
a00b0a10:  92 0c 20 3f  and  %l0, 0x3f, %o1
a00b0a14:  90 10 20 03  mov  3, %o0
a00b0a18:  94 10 00 1a  mov  %i2, %o2
a00b0a1c:  10 bf ff bf  b  0xa00b0918
a00b0a20:  96 10 20 01  mov  1, %o3
a00b0a24:  b4 0a a0 ff  and  %o2, 0xff, %i2
a00b0a28:  92 0a 60 1f  and  %o1, 0x1f, %o1
a00b0a2c:  94 10 00 1a  mov  %i2, %o2
a00b0a30:  90 10 20 03  mov  3, %o0
a00b0a34:  7f ff f2 dc  call  0xa00ad5a4
a00b0a38:  96 10 20 00  clr  %o3
a00b0a3c:  15 2a 00 b5  sethi  %hi(0xa802d400), %o2
a00b0a40:  d2 0a a0 72  ldub  [ %o2 + 0x72 ], %o1	! 0xa802d472
a00b0a44:  80 a2 60 02  cmp  %o1, 2
a00b0a48:  08 80 00 09  bleu  0xa00b0a6c
a00b0a4c:  92 0e e0 1f  and  %i3, 0x1f, %o1
a00b0a50:  7f ff 81 5f  call  0xa0090fcc
a00b0a54:  01 00 00 00  nop
a00b0a58:  9f 2a 20 10  sll  %o0, 0x10, %o7
a00b0a5c:  99 33 e0 10  srl  %o7, 0x10, %o4
a00b0a60:  80 a3 21 0a  cmp  %o4, 0x10a
a00b0a64:  02 bf ff a9  be  0xa00b0908
a00b0a68:  92 0e e0 1f  and  %i3, 0x1f, %o1
a00b0a6c:  90 10 20 03  mov  3, %o0
a00b0a70:  94 10 00 1a  mov  %i2, %o2
a00b0a74:  10 bf ff a3  b  0xa00b0900
a00b0a78:  96 10 20 01  mov  1, %o3
a00b0a7c:  b0 10 20 03  mov  3, %i0
a00b0a80:  10 bf ff 69  b  0xa00b0824
a00b0a84:  b6 10 20 01  mov  1, %i3
a00b0a88:  81 c7 e0 08  ret
a00b0a8c:  81 e8 00 00  restore
