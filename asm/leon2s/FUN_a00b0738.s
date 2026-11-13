# leon2s FUN_a00b0738 0xa00b0738-0xa00b0e54 (1820 bytes)  [FUN_a00b0e4c = unreachable ret/restore tail, merged]
a00b0738:  9d e3 bf 98  save  %sp, -104, %sp
a00b073c:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00b0740:  7f ff 4d e4  call  0xa0083ed0
a00b0744:  90 10 00 10  mov  %l0, %o0
a00b0748:  35 2a 01 f7  sethi  %hi(0xa807dc00), %i2
a00b074c:  82 16 a0 18  or  %i2, 0x18, %g1	! 0xa807dc18
a00b0750:  9a 5c 21 2c  smul  %l0, 0x12c, %o5
a00b0754:  9a 03 40 01  add  %o5, %g1, %o5
a00b0758:  c2 0b 61 1f  ldub  [ %o5 + 0x11f ], %g1
a00b075c:  80 a0 60 01  cmp  %g1, 1
a00b0760:  12 80 00 0a  bne  0xa00b0788
a00b0764:  b6 10 00 08  mov  %o0, %i3
a00b0768:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00b076c:  82 10 63 10  or  %g1, 0x310, %g1	! 0xa8079310
a00b0770:  c2 08 40 10  ldub  [ %g1 + %l0 ], %g1
a00b0774:  80 a0 60 00  cmp  %g1, 0
a00b0778:  32 80 00 05  bne,a   0xa00b078c
a00b077c:  90 10 00 10  mov  %l0, %o0
a00b0780:  7f ff f8 fb  call  0xa00aeb6c
a00b0784:  90 10 00 10  mov  %l0, %o0
a00b0788:  90 10 00 10  mov  %l0, %o0
a00b078c:  7f ff d9 0b  call  0xa00a6bb8
a00b0790:  92 10 22 1e  mov  0x21e, %o1
a00b0794:  90 0a 20 c0  and  %o0, 0xc0, %o0
a00b0798:  80 a2 20 80  cmp  %o0, 0x80
a00b079c:  12 80 00 05  bne  0xa00b07b0
a00b07a0:  90 0e e0 ff  and  %i3, 0xff, %o0
a00b07a4:  92 10 24 99  mov  0x499, %o1
a00b07a8:  10 80 00 04  b  0xa00b07b8
a00b07ac:  94 10 20 01  mov  1, %o2
a00b07b0:  92 10 24 99  mov  0x499, %o1
a00b07b4:  94 10 20 00  clr  %o2
a00b07b8:  7f ff db 97  call  0xa00a7614
a00b07bc:  01 00 00 00  nop
a00b07c0:  82 16 a0 18  or  %i2, 0x18, %g1
a00b07c4:  9a 5c 21 2c  smul  %l0, 0x12c, %o5
a00b07c8:  9a 03 40 01  add  %o5, %g1, %o5
a00b07cc:  c2 0b 61 1f  ldub  [ %o5 + 0x11f ], %g1
a00b07d0:  80 a0 60 01  cmp  %g1, 1
a00b07d4:  12 80 00 0b  bne  0xa00b0800
a00b07d8:  90 10 00 10  mov  %l0, %o0
a00b07dc:  7f ff f3 a3  call  0xa00ad668
a00b07e0:  90 10 00 10  mov  %l0, %o0
a00b07e4:  80 8a 20 ff  btst  0xff, %o0
a00b07e8:  02 80 00 06  be  0xa00b0800
a00b07ec:  90 10 00 10  mov  %l0, %o0
a00b07f0:  7f ff f6 fd  call  0xa00ae3e4
a00b07f4:  90 10 00 10  mov  %l0, %o0
a00b07f8:  10 80 00 06  b  0xa00b0810
a00b07fc:  b6 0e 20 ff  and  %i0, 0xff, %i3
a00b0800:  92 10 20 d6  mov  0xd6, %o1
a00b0804:  7f ff d8 ff  call  0xa00a6c00
a00b0808:  94 10 20 86  mov  0x86, %o2
a00b080c:  b6 0e 20 ff  and  %i0, 0xff, %i3
a00b0810:  80 a6 e0 01  cmp  %i3, 1
a00b0814:  18 80 01 8d  bgu  0xa00b0e48
a00b0818:  82 16 a0 18  or  %i2, 0x18, %g1
a00b081c:  9a 5e e1 2c  smul  %i3, 0x12c, %o5
a00b0820:  9a 03 40 01  add  %o5, %g1, %o5
a00b0824:  c2 0b 61 28  ldub  [ %o5 + 0x128 ], %g1
a00b0828:  80 a0 60 00  cmp  %g1, 0
a00b082c:  22 80 00 03  be,a   0xa00b0838
a00b0830:  f4 0b 61 25  ldub  [ %o5 + 0x125 ], %i2
a00b0834:  f4 0b 61 29  ldub  [ %o5 + 0x129 ], %i2
a00b0838:  23 2a 01 e4  sethi  %hi(0xa8079000), %l1
a00b083c:  82 14 63 68  or  %l1, 0x368, %g1	! 0xa8079368
a00b0840:  c2 08 40 1b  ldub  [ %g1 + %i3 ], %g1
a00b0844:  a0 0e a0 ff  and  %i2, 0xff, %l0
a00b0848:  80 a0 40 10  cmp  %g1, %l0
a00b084c:  02 80 00 23  be  0xa00b08d8
a00b0850:  01 00 00 00  nop
a00b0854:  7f ff ff b4  call  0xa00b0724
a00b0858:  90 10 00 1b  mov  %i3, %o0
a00b085c:  80 a4 20 01  cmp  %l0, 1
a00b0860:  12 80 00 1a  bne  0xa00b08c8
a00b0864:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00b0868:  82 10 63 60  or  %g1, 0x360, %g1	! 0xa8079360
a00b086c:  40 00 05 fe  call  0xa00b2064
a00b0870:  e0 28 40 1b  stb  %l0, [ %g1 + %i3 ]
a00b0874:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00b0878:  a1 2e e0 02  sll  %i3, 2, %l0
a00b087c:  82 10 63 3c  or  %g1, 0x33c, %g1
a00b0880:  d0 20 40 10  st  %o0, [ %g1 + %l0 ]
a00b0884:  40 00 05 f8  call  0xa00b2064
a00b0888:  01 00 00 00  nop
a00b088c:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00b0890:  82 10 63 44  or  %g1, 0x344, %g1	! 0xa8079344
a00b0894:  d0 20 40 10  st  %o0, [ %g1 + %l0 ]
a00b0898:  40 00 05 f3  call  0xa00b2064
a00b089c:  01 00 00 00  nop
a00b08a0:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00b08a4:  82 10 63 4c  or  %g1, 0x34c, %g1	! 0xa807934c
a00b08a8:  d0 20 40 10  st  %o0, [ %g1 + %l0 ]
a00b08ac:  40 00 05 ee  call  0xa00b2064
a00b08b0:  01 00 00 00  nop
a00b08b4:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00b08b8:  82 10 63 54  or  %g1, 0x354, %g1	! 0xa8079354
a00b08bc:  d0 20 40 10  st  %o0, [ %g1 + %l0 ]
a00b08c0:  10 80 00 05  b  0xa00b08d4
a00b08c4:  82 14 63 68  or  %l1, 0x368, %g1
a00b08c8:  82 10 63 60  or  %g1, 0x360, %g1
a00b08cc:  c0 28 40 1b  clrb  [ %g1 + %i3 ]
a00b08d0:  82 14 63 68  or  %l1, 0x368, %g1
a00b08d4:  f4 28 40 1b  stb  %i2, [ %g1 + %i3 ]
a00b08d8:  40 00 05 e3  call  0xa00b2064
a00b08dc:  b6 0e 20 ff  and  %i0, 0xff, %i3
a00b08e0:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00b08e4:  9b 2e e0 02  sll  %i3, 2, %o5
a00b08e8:  82 10 63 3c  or  %g1, 0x33c, %g1
a00b08ec:  c2 00 40 0d  ld  [ %g1 + %o5 ], %g1
a00b08f0:  90 22 00 01  sub  %o0, %g1, %o0
a00b08f4:  03 00 00 04  sethi  %hi(0x1000), %g1
a00b08f8:  82 10 63 88  or  %g1, 0x388, %g1	! 0x1388
a00b08fc:  80 a2 00 01  cmp  %o0, %g1
a00b0900:  08 80 00 07  bleu  0xa00b091c
a00b0904:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00b0908:  9a 10 63 60  or  %g1, 0x360, %o5	! 0xa8079360
a00b090c:  c2 0b 40 1b  ldub  [ %o5 + %i3 ], %g1
a00b0910:  80 a0 60 01  cmp  %g1, 1
a00b0914:  22 80 00 02  be,a   0xa00b091c
a00b0918:  c0 2b 40 1b  clrb  [ %o5 + %i3 ]
a00b091c:  7f ff f3 22  call  0xa00ad5a4
a00b0920:  90 10 00 1b  mov  %i3, %o0
a00b0924:  90 0a 20 ff  and  %o0, 0xff, %o0
a00b0928:  80 a2 20 01  cmp  %o0, 1
a00b092c:  12 80 00 0d  bne  0xa00b0960
a00b0930:  23 2a 01 e4  sethi  %hi(0xa8079000), %l1
a00b0934:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00b0938:  82 10 63 60  or  %g1, 0x360, %g1	! 0xa8079360
a00b093c:  40 00 05 ca  call  0xa00b2064
a00b0940:  c0 28 40 1b  clrb  [ %g1 + %i3 ]
a00b0944:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00b0948:  9b 2e e0 02  sll  %i3, 2, %o5
a00b094c:  82 10 63 44  or  %g1, 0x344, %g1
a00b0950:  d0 20 40 0d  st  %o0, [ %g1 + %o5 ]
a00b0954:  7f ff f1 c3  call  0xa00ad060
a00b0958:  90 10 00 1b  mov  %i3, %o0
a00b095c:  23 2a 01 e4  sethi  %hi(0xa8079000), %l1
a00b0960:  82 14 63 60  or  %l1, 0x360, %g1	! 0xa8079360
a00b0964:  c2 08 40 1b  ldub  [ %g1 + %i3 ], %g1
a00b0968:  80 a0 60 01  cmp  %g1, 1
a00b096c:  12 80 00 59  bne  0xa00b0ad0
a00b0970:  90 10 00 1b  mov  %i3, %o0
a00b0974:  7f ff f2 42  call  0xa00ad27c
a00b0978:  90 10 00 1b  mov  %i3, %o0
a00b097c:  90 0a 20 ff  and  %o0, 0xff, %o0
a00b0980:  80 a2 20 01  cmp  %o0, 1
a00b0984:  12 80 00 12  bne  0xa00b09cc
a00b0988:  82 14 63 60  or  %l1, 0x360, %g1
a00b098c:  40 00 05 b6  call  0xa00b2064
a00b0990:  a1 2e e0 02  sll  %i3, 2, %l0
a00b0994:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00b0998:  82 10 63 4c  or  %g1, 0x34c, %g1	! 0xa807934c
a00b099c:  d0 20 40 10  st  %o0, [ %g1 + %l0 ]
a00b09a0:  7f ff f3 29  call  0xa00ad644
a00b09a4:  90 10 00 1b  mov  %i3, %o0
a00b09a8:  80 8a 20 ff  btst  0xff, %o0
a00b09ac:  12 80 00 08  bne  0xa00b09cc
a00b09b0:  82 14 63 60  or  %l1, 0x360, %g1
a00b09b4:  40 00 05 ac  call  0xa00b2064
a00b09b8:  01 00 00 00  nop
a00b09bc:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00b09c0:  82 10 63 54  or  %g1, 0x354, %g1	! 0xa8079354
a00b09c4:  d0 20 40 10  st  %o0, [ %g1 + %l0 ]
a00b09c8:  82 14 63 60  or  %l1, 0x360, %g1
a00b09cc:  c2 08 40 1b  ldub  [ %g1 + %i3 ], %g1
a00b09d0:  80 a0 60 01  cmp  %g1, 1
a00b09d4:  12 80 00 3f  bne  0xa00b0ad0
a00b09d8:  90 10 00 1b  mov  %i3, %o0
a00b09dc:  40 00 05 a2  call  0xa00b2064
a00b09e0:  a1 2e e0 02  sll  %i3, 2, %l0
a00b09e4:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00b09e8:  82 10 63 44  or  %g1, 0x344, %g1	! 0xa8079344
a00b09ec:  c2 00 40 10  ld  [ %g1 + %l0 ], %g1
a00b09f0:  90 22 00 01  sub  %o0, %g1, %o0
a00b09f4:  80 a2 25 dc  cmp  %o0, 0x5dc
a00b09f8:  08 80 00 36  bleu  0xa00b0ad0
a00b09fc:  90 10 00 1b  mov  %i3, %o0
a00b0a00:  40 00 05 99  call  0xa00b2064
a00b0a04:  01 00 00 00  nop
a00b0a08:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00b0a0c:  b2 10 63 4c  or  %g1, 0x34c, %i1	! 0xa807934c
a00b0a10:  c2 06 40 10  ld  [ %i1 + %l0 ], %g1
a00b0a14:  90 22 00 01  sub  %o0, %g1, %o0
a00b0a18:  80 a2 22 58  cmp  %o0, 0x258
a00b0a1c:  08 80 00 0e  bleu  0xa00b0a54
a00b0a20:  35 2a 01 e4  sethi  %hi(0xa8079000), %i2
a00b0a24:  92 10 20 01  mov  1, %o1
a00b0a28:  7f ff f2 59  call  0xa00ad38c
a00b0a2c:  90 10 00 1b  mov  %i3, %o0
a00b0a30:  40 00 05 8d  call  0xa00b2064
a00b0a34:  01 00 00 00  nop
a00b0a38:  d0 26 40 10  st  %o0, [ %i1 + %l0 ]
a00b0a3c:  40 00 05 8a  call  0xa00b2064
a00b0a40:  01 00 00 00  nop
a00b0a44:  82 16 a3 54  or  %i2, 0x354, %g1
a00b0a48:  d0 20 40 10  st  %o0, [ %g1 + %l0 ]
a00b0a4c:  10 80 00 21  b  0xa00b0ad0
a00b0a50:  90 10 00 1b  mov  %i3, %o0
a00b0a54:  40 00 05 84  call  0xa00b2064
a00b0a58:  b4 16 a3 54  or  %i2, 0x354, %i2
a00b0a5c:  c2 06 80 10  ld  [ %i2 + %l0 ], %g1
a00b0a60:  90 22 00 01  sub  %o0, %g1, %o0
a00b0a64:  80 a2 25 dc  cmp  %o0, 0x5dc
a00b0a68:  08 80 00 1a  bleu  0xa00b0ad0
a00b0a6c:  90 10 00 1b  mov  %i3, %o0
a00b0a70:  92 10 22 1d  mov  0x21d, %o1
a00b0a74:  7f ff d8 51  call  0xa00a6bb8
a00b0a78:  90 10 00 1b  mov  %i3, %o0
a00b0a7c:  90 0a 20 1f  and  %o0, 0x1f, %o0
a00b0a80:  80 a2 20 01  cmp  %o0, 1
a00b0a84:  02 80 00 0a  be  0xa00b0aac
a00b0a88:  92 10 20 02  mov  2, %o1
a00b0a8c:  90 10 00 1b  mov  %i3, %o0
a00b0a90:  7f ff d8 4a  call  0xa00a6bb8
a00b0a94:  92 10 22 1d  mov  0x21d, %o1
a00b0a98:  90 0a 20 1f  and  %o0, 0x1f, %o0
a00b0a9c:  80 a2 20 02  cmp  %o0, 2
a00b0aa0:  12 80 00 0c  bne  0xa00b0ad0
a00b0aa4:  90 10 00 1b  mov  %i3, %o0
a00b0aa8:  92 10 20 04  mov  4, %o1
a00b0aac:  7f ff f2 38  call  0xa00ad38c
a00b0ab0:  90 10 00 1b  mov  %i3, %o0
a00b0ab4:  40 00 05 6c  call  0xa00b2064
a00b0ab8:  01 00 00 00  nop
a00b0abc:  d0 26 40 10  st  %o0, [ %i1 + %l0 ]
a00b0ac0:  40 00 05 69  call  0xa00b2064
a00b0ac4:  01 00 00 00  nop
a00b0ac8:  d0 26 80 10  st  %o0, [ %i2 + %l0 ]
a00b0acc:  90 10 00 1b  mov  %i3, %o0
a00b0ad0:  92 10 22 56  mov  0x256, %o1
a00b0ad4:  7f ff d8 39  call  0xa00a6bb8
a00b0ad8:  25 2a 01 e4  sethi  %hi(0xa8079000), %l2
a00b0adc:  b4 14 a3 70  or  %l2, 0x370, %i2	! 0xa8079370
a00b0ae0:  9a 0a 20 ff  and  %o0, 0xff, %o5
a00b0ae4:  c2 0e 80 1b  ldub  [ %i2 + %i3 ], %g1
a00b0ae8:  82 18 40 0d  xor  %g1, %o5, %g1
a00b0aec:  80 a0 00 01  cmp  %g0, %g1
a00b0af0:  82 40 20 00  addx  %g0, 0, %g1
a00b0af4:  91 32 20 07  srl  %o0, 7, %o0
a00b0af8:  80 8a 00 01  btst  %o0, %g1
a00b0afc:  02 80 00 7c  be  0xa00b0cec
a00b0b00:  a2 10 20 00  clr  %l1
a00b0b04:  11 28 01 b1  sethi  %hi(0xa006c400), %o0
a00b0b08:  7f ff 0a 6f  call  0xa00734c4
a00b0b0c:  90 12 21 20  or  %o0, 0x120, %o0	! 0xa006c520
a00b0b10:  92 10 22 56  mov  0x256, %o1
a00b0b14:  7f ff d8 29  call  0xa00a6bb8
a00b0b18:  90 10 00 1b  mov  %i3, %o0
a00b0b1c:  d0 2e 80 1b  stb  %o0, [ %i2 + %i3 ]
a00b0b20:  7f ff 4c ec  call  0xa0083ed0
a00b0b24:  90 10 00 1b  mov  %i3, %o0
a00b0b28:  a0 10 00 08  mov  %o0, %l0
a00b0b2c:  b2 0a 20 ff  and  %o0, 0xff, %i1
a00b0b30:  90 10 00 19  mov  %i1, %o0
a00b0b34:  7f ff da 61  call  0xa00a74b8
a00b0b38:  92 10 20 ab  mov  0xab, %o1
a00b0b3c:  da 0e 80 1b  ldub  [ %i2 + %i3 ], %o5
a00b0b40:  80 a3 60 90  cmp  %o5, 0x90
a00b0b44:  02 80 00 0d  be  0xa00b0b78
a00b0b48:  82 0a 20 0c  and  %o0, 0xc, %g1
a00b0b4c:  14 80 00 06  bg  0xa00b0b64
a00b0b50:  80 a3 60 a0  cmp  %o5, 0xa0
a00b0b54:  80 a3 60 80  cmp  %o5, 0x80
a00b0b58:  22 80 00 0e  be,a   0xa00b0b90
a00b0b5c:  a2 0a 20 03  and  %o0, 3, %l1
a00b0b60:  30 80 00 0c  b,a   0xa00b0b90
a00b0b64:  02 80 00 07  be  0xa00b0b80
a00b0b68:  80 a3 60 b0  cmp  %o5, 0xb0
a00b0b6c:  02 80 00 08  be  0xa00b0b8c
a00b0b70:  82 0a 20 c0  and  %o0, 0xc0, %g1
a00b0b74:  30 80 00 07  b,a   0xa00b0b90
a00b0b78:  10 80 00 06  b  0xa00b0b90
a00b0b7c:  a3 30 60 02  srl  %g1, 2, %l1
a00b0b80:  82 0a 20 30  and  %o0, 0x30, %g1
a00b0b84:  10 80 00 03  b  0xa00b0b90
a00b0b88:  a3 30 60 04  srl  %g1, 4, %l1
a00b0b8c:  a3 30 60 06  srl  %g1, 6, %l1
a00b0b90:  7f ff 73 1c  call  0xa008d800
a00b0b94:  01 00 00 00  nop
a00b0b98:  90 0a 20 ff  and  %o0, 0xff, %o0
a00b0b9c:  80 a2 20 80  cmp  %o0, 0x80
a00b0ba0:  18 80 00 13  bgu  0xa00b0bec
a00b0ba4:  90 10 20 05  mov  5, %o0
a00b0ba8:  90 10 00 1b  mov  %i3, %o0
a00b0bac:  92 10 22 1d  mov  0x21d, %o1
a00b0bb0:  7f ff d8 14  call  0xa00a6c00
a00b0bb4:  94 10 20 84  mov  0x84, %o2
a00b0bb8:  90 10 00 1b  mov  %i3, %o0
a00b0bbc:  92 10 20 c0  mov  0xc0, %o1
a00b0bc0:  7f ff d8 10  call  0xa00a6c00
a00b0bc4:  94 10 20 00  clr  %o2
a00b0bc8:  90 10 00 19  mov  %i1, %o0
a00b0bcc:  92 10 24 03  mov  0x403, %o1
a00b0bd0:  7f ff da 91  call  0xa00a7614
a00b0bd4:  94 10 20 80  mov  0x80, %o2
a00b0bd8:  90 10 00 1b  mov  %i3, %o0
a00b0bdc:  92 10 20 c0  mov  0xc0, %o1
a00b0be0:  7f ff d8 08  call  0xa00a6c00
a00b0be4:  94 10 20 80  mov  0x80, %o2
a00b0be8:  90 10 20 05  mov  5, %o0
a00b0bec:  40 00 02 ea  call  0xa00b1794
a00b0bf0:  a0 0c 20 ff  and  %l0, 0xff, %l0
a00b0bf4:  90 10 00 10  mov  %l0, %o0
a00b0bf8:  92 10 24 7d  mov  0x47d, %o1
a00b0bfc:  7f ff da 86  call  0xa00a7614
a00b0c00:  94 10 20 00  clr  %o2
a00b0c04:  90 10 00 10  mov  %l0, %o0
a00b0c08:  92 10 25 25  mov  0x525, %o1
a00b0c0c:  7f ff da 82  call  0xa00a7614
a00b0c10:  94 10 20 00  clr  %o2
a00b0c14:  90 10 00 10  mov  %l0, %o0
a00b0c18:  92 10 26 25  mov  0x625, %o1
a00b0c1c:  7f ff da 7e  call  0xa00a7614
a00b0c20:  94 10 20 00  clr  %o2
a00b0c24:  90 10 00 10  mov  %l0, %o0
a00b0c28:  92 10 27 25  mov  0x725, %o1
a00b0c2c:  7f ff da 7a  call  0xa00a7614
a00b0c30:  94 10 20 00  clr  %o2
a00b0c34:  90 10 00 10  mov  %l0, %o0
a00b0c38:  92 10 28 25  mov  0x825, %o1
a00b0c3c:  7f ff da 76  call  0xa00a7614
a00b0c40:  94 10 20 00  clr  %o2
a00b0c44:  90 10 00 10  mov  %l0, %o0
a00b0c48:  92 10 24 69  mov  0x469, %o1
a00b0c4c:  7f ff da 72  call  0xa00a7614
a00b0c50:  94 10 20 2d  mov  0x2d, %o2
a00b0c54:  90 10 00 10  mov  %l0, %o0
a00b0c58:  92 10 20 03  mov  3, %o1
a00b0c5c:  7f ff da 6e  call  0xa00a7614
a00b0c60:  94 10 20 90  mov  0x90, %o2
a00b0c64:  90 10 00 10  mov  %l0, %o0
a00b0c68:  92 10 20 43  mov  0x43, %o1
a00b0c6c:  7f ff da 6a  call  0xa00a7614
a00b0c70:  94 10 20 f0  mov  0xf0, %o2
a00b0c74:  90 10 00 10  mov  %l0, %o0
a00b0c78:  92 10 24 71  mov  0x471, %o1
a00b0c7c:  7f ff da 66  call  0xa00a7614
a00b0c80:  94 10 20 f0  mov  0xf0, %o2
a00b0c84:  94 04 40 11  add  %l1, %l1, %o2
a00b0c88:  94 12 bf 80  or  %o2, -128, %o2
a00b0c8c:  94 0a a0 86  and  %o2, 0x86, %o2
a00b0c90:  90 10 00 10  mov  %l0, %o0
a00b0c94:  7f ff da 60  call  0xa00a7614
a00b0c98:  92 10 20 02  mov  2, %o1
a00b0c9c:  90 10 00 10  mov  %l0, %o0
a00b0ca0:  92 10 24 70  mov  0x470, %o1
a00b0ca4:  7f ff da 5c  call  0xa00a7614
a00b0ca8:  94 10 20 00  clr  %o2
a00b0cac:  90 10 00 10  mov  %l0, %o0
a00b0cb0:  92 10 25 10  mov  0x510, %o1
a00b0cb4:  7f ff da 58  call  0xa00a7614
a00b0cb8:  94 10 20 01  mov  1, %o2
a00b0cbc:  90 10 00 10  mov  %l0, %o0
a00b0cc0:  92 10 26 10  mov  0x610, %o1
a00b0cc4:  7f ff da 54  call  0xa00a7614
a00b0cc8:  94 10 20 01  mov  1, %o2
a00b0ccc:  90 10 00 10  mov  %l0, %o0
a00b0cd0:  92 10 27 10  mov  0x710, %o1
a00b0cd4:  7f ff da 50  call  0xa00a7614
a00b0cd8:  94 10 20 01  mov  1, %o2
a00b0cdc:  90 10 00 10  mov  %l0, %o0
a00b0ce0:  92 10 28 10  mov  0x810, %o1
a00b0ce4:  7f ff da 4c  call  0xa00a7614
a00b0ce8:  94 10 20 01  mov  1, %o2
a00b0cec:  9a 14 a3 70  or  %l2, 0x370, %o5
a00b0cf0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00b0cf4:  c2 4b 40 18  ldsb  [ %o5 + %i0 ], %g1
a00b0cf8:  80 a0 60 00  cmp  %g1, 0
a00b0cfc:  16 80 00 53  bge  0xa00b0e48
a00b0d00:  da 0b 40 18  ldub  [ %o5 + %i0 ], %o5
a00b0d04:  9a 0b 60 ff  and  %o5, 0xff, %o5
a00b0d08:  80 a3 60 90  cmp  %o5, 0x90
a00b0d0c:  02 80 00 10  be  0xa00b0d4c
a00b0d10:  92 10 22 b9  mov  0x2b9, %o1
a00b0d14:  14 80 00 06  bg  0xa00b0d2c
a00b0d18:  80 a3 60 a0  cmp  %o5, 0xa0
a00b0d1c:  80 a3 60 80  cmp  %o5, 0x80
a00b0d20:  02 80 00 08  be  0xa00b0d40
a00b0d24:  90 10 00 18  mov  %i0, %o0
a00b0d28:  30 80 00 48  b,a   0xa00b0e48
a00b0d2c:  02 80 00 1a  be  0xa00b0d94
a00b0d30:  80 a3 60 b0  cmp  %o5, 0xb0
a00b0d34:  02 80 00 2b  be  0xa00b0de0
a00b0d38:  92 10 22 bb  mov  0x2bb, %o1
a00b0d3c:  30 80 00 43  b,a   0xa00b0e48
a00b0d40:  7f ff d7 9e  call  0xa00a6bb8
a00b0d44:  92 10 22 b8  mov  0x2b8, %o1
a00b0d48:  30 80 00 40  b,a   0xa00b0e48
a00b0d4c:  7f ff d7 9b  call  0xa00a6bb8
a00b0d50:  90 10 00 18  mov  %i0, %o0
a00b0d54:  a0 10 00 08  mov  %o0, %l0
a00b0d58:  90 10 00 18  mov  %i0, %o0
a00b0d5c:  7f ff d7 97  call  0xa00a6bb8
a00b0d60:  92 10 22 b8  mov  0x2b8, %o1
a00b0d64:  a0 0c 20 ff  and  %l0, 0xff, %l0
a00b0d68:  90 0a 20 ff  and  %o0, 0xff, %o0
a00b0d6c:  80 a4 00 08  cmp  %l0, %o0
a00b0d70:  02 80 00 36  be  0xa00b0e48
a00b0d74:  90 10 00 18  mov  %i0, %o0
a00b0d78:  92 10 20 30  mov  0x30, %o1
a00b0d7c:  94 10 20 80  mov  0x80, %o2
a00b0d80:  7f ff d7 c6  call  0xa00a6c98
a00b0d84:  96 10 20 01  mov  1, %o3
a00b0d88:  90 10 00 18  mov  %i0, %o0
a00b0d8c:  10 80 00 26  b  0xa00b0e24
a00b0d90:  92 10 22 b9  mov  0x2b9, %o1
a00b0d94:  92 10 22 ba  mov  0x2ba, %o1
a00b0d98:  7f ff d7 88  call  0xa00a6bb8
a00b0d9c:  90 10 00 18  mov  %i0, %o0
a00b0da0:  a0 10 00 08  mov  %o0, %l0
a00b0da4:  90 10 00 18  mov  %i0, %o0
a00b0da8:  7f ff d7 84  call  0xa00a6bb8
a00b0dac:  92 10 22 b8  mov  0x2b8, %o1
a00b0db0:  a0 0c 20 ff  and  %l0, 0xff, %l0
a00b0db4:  90 0a 20 ff  and  %o0, 0xff, %o0
a00b0db8:  80 a4 00 08  cmp  %l0, %o0
a00b0dbc:  02 80 00 23  be  0xa00b0e48
a00b0dc0:  90 10 00 18  mov  %i0, %o0
a00b0dc4:  92 10 20 30  mov  0x30, %o1
a00b0dc8:  94 10 20 80  mov  0x80, %o2
a00b0dcc:  7f ff d7 b3  call  0xa00a6c98
a00b0dd0:  96 10 20 01  mov  1, %o3
a00b0dd4:  90 10 00 18  mov  %i0, %o0
a00b0dd8:  10 80 00 13  b  0xa00b0e24
a00b0ddc:  92 10 22 ba  mov  0x2ba, %o1
a00b0de0:  7f ff d7 76  call  0xa00a6bb8
a00b0de4:  90 10 00 18  mov  %i0, %o0
a00b0de8:  a0 10 00 08  mov  %o0, %l0
a00b0dec:  90 10 00 18  mov  %i0, %o0
a00b0df0:  7f ff d7 72  call  0xa00a6bb8
a00b0df4:  92 10 22 b8  mov  0x2b8, %o1
a00b0df8:  a0 0c 20 ff  and  %l0, 0xff, %l0
a00b0dfc:  90 0a 20 ff  and  %o0, 0xff, %o0
a00b0e00:  80 a4 00 08  cmp  %l0, %o0
a00b0e04:  02 80 00 11  be  0xa00b0e48
a00b0e08:  90 10 00 18  mov  %i0, %o0
a00b0e0c:  92 10 20 30  mov  0x30, %o1
a00b0e10:  94 10 20 80  mov  0x80, %o2
a00b0e14:  7f ff d7 a1  call  0xa00a6c98
a00b0e18:  96 10 20 01  mov  1, %o3
a00b0e1c:  90 10 00 18  mov  %i0, %o0
a00b0e20:  92 10 22 bb  mov  0x2bb, %o1
a00b0e24:  7f ff d7 65  call  0xa00a6bb8
a00b0e28:  b2 10 20 30  mov  0x30, %i1
a00b0e2c:  94 0a 20 ff  and  %o0, 0xff, %o2
a00b0e30:  90 10 00 18  mov  %i0, %o0
a00b0e34:  7f ff d7 73  call  0xa00a6c00
a00b0e38:  92 10 22 b8  mov  0x2b8, %o1
a00b0e3c:  b4 10 20 80  mov  0x80, %i2
a00b0e40:  7f ff d7 96  call  0xa00a6c98
a00b0e44:  97 e8 20 00  restore  %g0, 0, %o3
a00b0e48:  01 00 00 00  nop
a00b0e4c:  81 c7 e0 08  ret
a00b0e50:  81 e8 00 00  restore
