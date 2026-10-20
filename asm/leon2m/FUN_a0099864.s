# leon2m FUN_a0099864 0xa0099864-0xa0099970 (268 bytes)
a0099864:  9d e3 bf 98  save  %sp, -104, %sp
a0099868:  7f ff ff 7c  call  0xa0099658
a009986c:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a0099870:  c2 04 63 ec  ld  [ %l1 + 0x3ec ], %g1	! 0xa802afec
a0099874:  80 a0 60 45  cmp  %g1, 0x45
a0099878:  08 80 00 16  bleu  0xa00998d0
a009987c:  21 2a 00 97  sethi  %hi(0xa8025c00), %l0
a0099880:  40 00 f9 32  call  0xa00d7d48
a0099884:  01 00 00 00  nop
a0099888:  80 a2 20 00  cmp  %o0, 0
a009988c:  92 10 20 13  mov  0x13, %o1
a0099890:  94 10 20 0c  mov  0xc, %o2
a0099894:  96 10 22 92  mov  0x292, %o3
a0099898:  98 10 20 00  clr  %o4
a009989c:  02 80 00 06  be  0xa00998b4
a00998a0:  90 10 20 09  mov  9, %o0
a00998a4:  40 02 b4 77  call  0xa0146a80
a00998a8:  01 00 00 00  nop
a00998ac:  10 80 00 0a  b  0xa00998d4
a00998b0:  de 0c 20 56  ldub  [ %l0 + 0x56 ], %o7
a00998b4:  96 10 27 92  mov  0x792, %o3
a00998b8:  98 10 20 00  clr  %o4
a00998bc:  92 10 20 13  mov  0x13, %o1
a00998c0:  94 10 20 0c  mov  0xc, %o2
a00998c4:  40 02 b4 6f  call  0xa0146a80
a00998c8:  90 10 20 09  mov  9, %o0
a00998cc:  21 2a 00 97  sethi  %hi(0xa8025c00), %l0
a00998d0:  de 0c 20 56  ldub  [ %l0 + 0x56 ], %o7	! 0xa8025c56
a00998d4:  98 03 e0 02  add  %o7, 2, %o4
a00998d8:  40 00 3e b9  call  0xa00a93bc
a00998dc:  90 0b 20 ff  and  %o4, 0xff, %o0
a00998e0:  d6 0c 20 56  ldub  [ %l0 + 0x56 ], %o3
a00998e4:  94 02 e0 02  add  %o3, 2, %o2
a00998e8:  92 0a a0 ff  and  %o2, 0xff, %o1
a00998ec:  94 10 20 00  clr  %o2
a00998f0:  40 00 3a 13  call  0xa00a813c
a00998f4:  90 10 20 01  mov  1, %o0
a00998f8:  d2 04 63 ec  ld  [ %l1 + 0x3ec ], %o1
a00998fc:  90 02 7f bc  add  %o1, -68, %o0
a0099900:  90 0a 20 ff  and  %o0, 0xff, %o0
a0099904:  40 00 3f 53  call  0xa00a9650
a0099908:  92 10 20 00  clr  %o1
a009990c:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a0099910:  a0 13 62 90  or  %o5, 0x290, %l0	! 0xa802d290
a0099914:  c2 0c 20 4a  ldub  [ %l0 + 0x4a ], %g1
a0099918:  9e 00 60 02  add  %g1, 2, %o7
a009991c:  92 0b e0 ff  and  %o7, 0xff, %o1
a0099920:  90 10 20 01  mov  1, %o0
a0099924:  40 00 3a 06  call  0xa00a813c
a0099928:  94 10 20 00  clr  %o2
a009992c:  d8 0c 20 4a  ldub  [ %l0 + 0x4a ], %o4
a0099930:  96 03 20 02  add  %o4, 2, %o3
a0099934:  92 0a e0 ff  and  %o3, 0xff, %o1
a0099938:  90 10 20 01  mov  1, %o0
a009993c:  40 00 3a 00  call  0xa00a813c
a0099940:  94 10 20 01  mov  1, %o2
a0099944:  94 10 20 0d  mov  0xd, %o2
a0099948:  90 10 20 02  mov  2, %o0
a009994c:  92 10 20 01  mov  1, %o1
a0099950:  40 00 3d af  call  0xa00a900c
a0099954:  d4 24 63 ec  st  %o2, [ %l1 + 0x3ec ]
a0099958:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a009995c:  d2 0b 60 8e  ldub  [ %o5 + 0x8e ], %o1	! 0xa802b08e
a0099960:  90 12 60 02  or  %o1, 2, %o0
a0099964:  d0 2b 60 8e  stb  %o0, [ %o5 + 0x8e ]
a0099968:  81 c7 e0 08  ret
a009996c:  81 e8 00 00  restore
