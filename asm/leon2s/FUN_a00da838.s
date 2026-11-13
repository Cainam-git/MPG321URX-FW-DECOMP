# leon2s FUN_a00da838 0xa00da838-0xa00da960 (296 bytes)
a00da838:  9d e3 bf 98  save  %sp, -104, %sp
a00da83c:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00da840:  f4 08 63 fc  ldub  [ %g1 + 0x3fc ], %i2	! 0xa80787fc
a00da844:  b8 06 80 1a  add  %i2, %i2, %i4
a00da848:  b8 07 00 1a  add  %i4, %i2, %i4
a00da84c:  37 2a 01 e7  sethi  %hi(0xa8079c00), %i3
a00da850:  b9 2f 20 04  sll  %i4, 4, %i4
a00da854:  b6 16 e0 98  or  %i3, 0x98, %i3
a00da858:  fa 0f 00 1b  ldub  [ %i4 + %i3 ], %i5
a00da85c:  bb 37 60 04  srl  %i5, 4, %i5
a00da860:  ba 07 7f ff  add  %i5, -1, %i5
a00da864:  83 37 60 1f  srl  %i5, 0x1f, %g1
a00da868:  82 07 40 01  add  %i5, %g1, %g1
a00da86c:  b3 38 60 01  sra  %g1, 1, %i1
a00da870:  03 2a 01 e7  sethi  %hi(0xa8079c00), %g1
a00da874:  82 10 60 50  or  %g1, 0x50, %g1	! 0xa8079c50
a00da878:  f4 08 40 1a  ldub  [ %g1 + %i2 ], %i2
a00da87c:  80 8f 60 01  btst  1, %i5
a00da880:  b0 07 00 1b  add  %i4, %i3, %i0
a00da884:  02 80 00 03  be  0xa00da890
a00da888:  82 10 00 19  mov  %i1, %g1
a00da88c:  82 06 60 01  add  %i1, 1, %g1
a00da890:  b2 08 60 ff  and  %g1, 0xff, %i1
a00da894:  82 06 00 19  add  %i0, %i1, %g1
a00da898:  ba 0e a0 ff  and  %i2, 0xff, %i5
a00da89c:  c2 08 60 01  ldub  [ %g1 + 1 ], %g1
a00da8a0:  80 a7 60 00  cmp  %i5, 0
a00da8a4:  12 80 00 18  bne  0xa00da904
a00da8a8:  b4 08 60 3f  and  %g1, 0x3f, %i2
a00da8ac:  80 a7 40 1a  cmp  %i5, %i2
a00da8b0:  1a 80 00 2a  bcc  0xa00da958
a00da8b4:  b6 10 20 00  clr  %i3
a00da8b8:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a00da8bc:  9a 10 60 9c  or  %g1, 0x9c, %o5	! 0xa807609c
a00da8c0:  1f 2a 01 e2  sethi  %hi(0xa8078800), %o7
a00da8c4:  82 0e e0 ff  and  %i3, 0xff, %g1
a00da8c8:  fa 0b e0 32  ldub  [ %o7 + 0x32 ], %i5
a00da8cc:  82 06 40 01  add  %i1, %g1, %g1
a00da8d0:  b8 00 40 18  add  %g1, %i0, %i4
a00da8d4:  bb 2f 60 02  sll  %i5, 2, %i5
a00da8d8:  fa 03 40 1d  ld  [ %o5 + %i5 ], %i5
a00da8dc:  83 28 60 02  sll  %g1, 2, %g1
a00da8e0:  82 00 40 1d  add  %g1, %i5, %g1
a00da8e4:  fa 0f 20 03  ldub  [ %i4 + 3 ], %i5
a00da8e8:  b6 06 e0 01  inc  %i3
a00da8ec:  b8 0e e0 ff  and  %i3, 0xff, %i4
a00da8f0:  fa 20 60 0c  st  %i5, [ %g1 + 0xc ]
a00da8f4:  80 a7 00 1a  cmp  %i4, %i2
a00da8f8:  0a bf ff f4  bcs  0xa00da8c8
a00da8fc:  82 0e e0 ff  and  %i3, 0xff, %g1
a00da900:  30 80 00 16  b,a   0xa00da958
a00da904:  80 a6 a0 00  cmp  %i2, 0
a00da908:  02 80 00 14  be  0xa00da958
a00da90c:  b6 10 20 00  clr  %i3
a00da910:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a00da914:  9a 10 60 9c  or  %g1, 0x9c, %o5	! 0xa807609c
a00da918:  1f 2a 01 e2  sethi  %hi(0xa8078800), %o7
a00da91c:  82 0e e0 ff  and  %i3, 0xff, %g1
a00da920:  fa 0b e0 32  ldub  [ %o7 + 0x32 ], %i5
a00da924:  82 06 40 01  add  %i1, %g1, %g1
a00da928:  b8 00 40 18  add  %g1, %i0, %i4
a00da92c:  bb 2f 60 02  sll  %i5, 2, %i5
a00da930:  fa 03 40 1d  ld  [ %o5 + %i5 ], %i5
a00da934:  83 28 60 02  sll  %g1, 2, %g1
a00da938:  82 00 40 1d  add  %g1, %i5, %g1
a00da93c:  fa 0f 20 03  ldub  [ %i4 + 3 ], %i5
a00da940:  b6 06 e0 01  inc  %i3
a00da944:  b8 0e e0 ff  and  %i3, 0xff, %i4
a00da948:  fa 20 60 cc  st  %i5, [ %g1 + 0xcc ]
a00da94c:  80 a7 00 1a  cmp  %i4, %i2
a00da950:  0a bf ff f4  bcs  0xa00da920
a00da954:  82 0e e0 ff  and  %i3, 0xff, %g1
a00da958:  81 c7 e0 08  ret
a00da95c:  81 e8 00 00  restore
