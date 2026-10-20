# leon2m FUN_a0105790 0xa0105790-0xa0105910 (384 bytes)
a0105790:  9d e3 bf 98  save  %sp, -104, %sp
a0105794:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0105798:  90 10 00 18  mov  %i0, %o0
a010579c:  7f ff b2 ae  call  0xa00f2254
a01057a0:  92 10 20 88  mov  0x88, %o1
a01057a4:  80 8a 20 01  btst  1, %o0
a01057a8:  02 80 00 58  be  0xa0105908
a01057ac:  90 10 00 18  mov  %i0, %o0
a01057b0:  f4 16 a0 08  lduh  [ %i2 + 8 ], %i2
a01057b4:  7f ff b3 91  call  0xa00f25f8
a01057b8:  92 10 20 5e  mov  0x5e, %o1
a01057bc:  a4 10 00 08  mov  %o0, %l2
a01057c0:  80 a6 20 03  cmp  %i0, 3
a01057c4:  a0 10 20 00  clr  %l0
a01057c8:  08 80 00 3a  bleu  0xa01058b0
a01057cc:  9a 10 20 00  clr  %o5
a01057d0:  99 2e a0 10  sll  %i2, 0x10, %o4
a01057d4:  95 33 20 10  srl  %o4, 0x10, %o2
a01057d8:  92 0c 20 ff  and  %l0, 0xff, %o1
a01057dc:  90 5a 40 0a  smul  %o1, %o2, %o0
a01057e0:  9b 2b 60 03  sll  %o5, 3, %o5
a01057e4:  82 02 00 0d  add  %o0, %o5, %g1
a01057e8:  17 00 03 d0  sethi  %hi(0xf4000), %o3
a01057ec:  a2 10 00 01  mov  %g1, %l1
a01057f0:  d0 1e e0 18  ldd  [ %i3 + 0x18 ], %o0
a01057f4:  94 10 20 00  clr  %o2
a01057f8:  40 01 3e 84  call  0xa0155208
a01057fc:  96 12 e2 40  or  %o3, 0x240, %o3
a0105800:  96 54 40 09  umul  %l1, %o1, %o3
a0105804:  95 40 00 00  rd  %y, %o2
a0105808:  b6 5c 40 08  smul  %l1, %o0, %i3
a010580c:  a0 10 20 00  clr  %l0
a0105810:  a0 5a 40 10  smul  %o1, %l0, %l0
a0105814:  b4 06 c0 0a  add  %i3, %o2, %i2
a0105818:  a3 2e 60 10  sll  %i1, 0x10, %l1
a010581c:  9e 06 80 10  add  %i2, %l0, %o7
a0105820:  99 34 60 10  srl  %l1, 0x10, %o4
a0105824:  92 10 00 0b  mov  %o3, %o1
a0105828:  90 10 00 0f  mov  %o7, %o0
a010582c:  94 10 20 00  clr  %o2
a0105830:  40 01 3e 76  call  0xa0155208
a0105834:  96 10 00 0c  mov  %o4, %o3
a0105838:  80 a6 20 01  cmp  %i0, 1
a010583c:  02 80 00 25  be  0xa01058d0
a0105840:  b7 2c a0 10  sll  %l2, 0x10, %i3
a0105844:  b5 36 e0 10  srl  %i3, 0x10, %i2
a0105848:  81 80 00 00  mov  %g0, %y
a010584c:  01 00 00 00  nop
a0105850:  01 00 00 00  nop
a0105854:  01 00 00 00  nop
a0105858:  9e 72 40 1a  udiv  %o1, %i2, %o7
a010585c:  82 03 e0 01  add  %o7, 1, %g1
a0105860:  80 a6 20 00  cmp  %i0, 0
a0105864:  12 80 00 22  bne  0xa01058ec
a0105868:  90 10 00 01  mov  %g1, %o0
a010586c:  91 28 60 10  sll  %g1, 0x10, %o0
a0105870:  a1 32 20 10  srl  %o0, 0x10, %l0
a0105874:  80 a4 20 02  cmp  %l0, 2
a0105878:  28 80 00 02  bleu,a   0xa0105880
a010587c:  11 00 00 c0  sethi  %hi(0x30000), %o0
a0105880:  a5 32 20 10  srl  %o0, 0x10, %l2
a0105884:  90 10 00 18  mov  %i0, %o0
a0105888:  92 10 20 62  mov  0x62, %o1
a010588c:  7f ff b2 ff  call  0xa00f2488
a0105890:  94 10 00 12  mov  %l2, %o2
a0105894:  90 10 00 18  mov  %i0, %o0
a0105898:  94 10 00 12  mov  %l2, %o2
a010589c:  7f ff b2 fb  call  0xa00f2488
a01058a0:  92 10 20 6f  mov  0x6f, %o1
a01058a4:  b2 10 20 be  mov  0xbe, %i1
a01058a8:  7f ff b2 f8  call  0xa00f2488
a01058ac:  95 e8 20 01  restore  %g0, 1, %o2
a01058b0:  15 2a 00 b5  sethi  %hi(0xa802d400), %o2
a01058b4:  90 12 a2 80  or  %o2, 0x280, %o0	! 0xa802d680
a01058b8:  92 06 00 18  add  %i0, %i0, %o1
a01058bc:  9a 02 40 08  add  %o1, %o0, %o5
a01058c0:  82 06 00 08  add  %i0, %o0, %g1
a01058c4:  e0 08 60 15  ldub  [ %g1 + 0x15 ], %l0
a01058c8:  10 bf ff c2  b  0xa01057d0
a01058cc:  da 13 60 1a  lduh  [ %o5 + 0x1a ], %o5
a01058d0:  b3 2c a0 10  sll  %l2, 0x10, %i1
a01058d4:  a5 36 60 10  srl  %i1, 0x10, %l2
a01058d8:  81 80 00 00  mov  %g0, %y
a01058dc:  01 00 00 00  nop
a01058e0:  01 00 00 00  nop
a01058e4:  01 00 00 00  nop
a01058e8:  90 72 40 12  udiv  %o1, %l2, %o0
a01058ec:  91 2a 20 10  sll  %o0, 0x10, %o0
a01058f0:  a3 32 20 10  srl  %o0, 0x10, %l1
a01058f4:  80 a4 60 01  cmp  %l1, 1
a01058f8:  28 bf ff e2  bleu,a   0xa0105880
a01058fc:  11 00 00 80  sethi  %hi(0x20000), %o0
a0105900:  10 bf ff e1  b  0xa0105884
a0105904:  a5 32 20 10  srl  %o0, 0x10, %l2
a0105908:  81 c7 e0 08  ret
a010590c:  81 e8 00 00  restore
