# leon2s FUN_a00618d8 0xa00618d8-0xa0061a6c (404 bytes)
a00618d8:  9d e3 bf 98  save  %sp, -104, %sp
a00618dc:  19 2a 01 e4  sethi  %hi(0xa8079000), %o4
a00618e0:  96 10 20 01  mov  1, %o3
a00618e4:  da 03 23 a0  ld  [ %o4 + 0x3a0 ], %o5
a00618e8:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00618ec:  80 a3 60 00  cmp  %o5, 0
a00618f0:  02 80 00 05  be  0xa0061904
a00618f4:  d6 28 62 92  stb  %o3, [ %g1 + 0x292 ]
a00618f8:  c2 03 23 a0  ld  [ %o4 + 0x3a0 ], %g1
a00618fc:  82 00 7f ff  add  %g1, -1, %g1
a0061900:  c2 23 23 a0  st  %g1, [ %o4 + 0x3a0 ]
a0061904:  1b 2a 01 f7  sethi  %hi(0xa807dc00), %o5
a0061908:  c2 03 62 8c  ld  [ %o5 + 0x28c ], %g1	! 0xa807de8c
a006190c:  82 00 60 01  inc  %g1
a0061910:  80 a0 60 04  cmp  %g1, 4
a0061914:  08 80 00 05  bleu  0xa0061928
a0061918:  c2 23 62 8c  st  %g1, [ %o5 + 0x28c ]
a006191c:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a0061920:  d6 28 62 9c  stb  %o3, [ %g1 + 0x29c ]	! 0xa807de9c
a0061924:  c0 23 62 8c  clr  [ %o5 + 0x28c ]
a0061928:  1b 2a 01 f7  sethi  %hi(0xa807dc00), %o5
a006192c:  c2 03 62 a0  ld  [ %o5 + 0x2a0 ], %g1	! 0xa807dea0
a0061930:  82 00 60 01  inc  %g1
a0061934:  80 a0 60 31  cmp  %g1, 0x31
a0061938:  08 80 00 05  bleu  0xa006194c
a006193c:  c2 23 62 a0  st  %g1, [ %o5 + 0x2a0 ]
a0061940:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a0061944:  d6 28 62 90  stb  %o3, [ %g1 + 0x290 ]	! 0xa807de90
a0061948:  c0 23 62 a0  clr  [ %o5 + 0x2a0 ]
a006194c:  1b 2a 01 f7  sethi  %hi(0xa807dc00), %o5
a0061950:  c2 03 62 94  ld  [ %o5 + 0x294 ], %g1	! 0xa807de94
a0061954:  82 00 60 01  inc  %g1
a0061958:  80 a0 61 f3  cmp  %g1, 0x1f3
a006195c:  08 80 00 05  bleu  0xa0061970
a0061960:  c2 23 62 94  st  %g1, [ %o5 + 0x294 ]
a0061964:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a0061968:  d6 28 62 91  stb  %o3, [ %g1 + 0x291 ]	! 0xa807de91
a006196c:  c0 23 62 94  clr  [ %o5 + 0x294 ]
a0061970:  23 2a 01 e4  sethi  %hi(0xa8079000), %l1
a0061974:  98 14 63 a4  or  %l1, 0x3a4, %o4	! 0xa80793a4
a0061978:  da 03 20 04  ld  [ %o4 + 4 ], %o5
a006197c:  17 2a 01 f7  sethi  %hi(0xa807dc00), %o3
a0061980:  c2 02 e2 98  ld  [ %o3 + 0x298 ], %g1	! 0xa807de98
a0061984:  9a 03 60 01  inc  %o5
a0061988:  82 00 60 01  inc  %g1
a006198c:  da 23 20 04  st  %o5, [ %o4 + 4 ]
a0061990:  c2 22 e2 98  st  %g1, [ %o3 + 0x298 ]
a0061994:  98 03 20 14  add  %o4, 0x14, %o4
a0061998:  90 10 20 01  mov  1, %o0
a006199c:  94 10 20 00  clr  %o2
a00619a0:  92 10 20 0f  mov  0xf, %o1
a00619a4:  9a 02 80 0c  add  %o2, %o4, %o5
a00619a8:  c2 03 60 10  ld  [ %o5 + 0x10 ], %g1
a00619ac:  80 a0 60 00  cmp  %g1, 0
a00619b0:  22 80 00 17  be,a   0xa0061a0c
a00619b4:  92 82 7f ff  addcc  %o1, -1, %o1
a00619b8:  c2 0b 60 04  ldub  [ %o5 + 4 ], %g1
a00619bc:  80 a0 60 00  cmp  %g1, 0
a00619c0:  22 80 00 13  be,a   0xa0061a0c
a00619c4:  92 82 7f ff  addcc  %o1, -1, %o1
a00619c8:  d6 03 60 08  ld  [ %o5 + 8 ], %o3
a00619cc:  80 a2 e0 00  cmp  %o3, 0
a00619d0:  22 80 00 0f  be,a   0xa0061a0c
a00619d4:  92 82 7f ff  addcc  %o1, -1, %o1
a00619d8:  c2 03 60 0c  ld  [ %o5 + 0xc ], %g1
a00619dc:  82 00 7f ff  add  %g1, -1, %g1
a00619e0:  80 a0 60 00  cmp  %g1, 0
a00619e4:  12 80 00 09  bne  0xa0061a08
a00619e8:  c2 23 60 0c  st  %g1, [ %o5 + 0xc ]
a00619ec:  c2 02 80 0c  ld  [ %o2 + %o4 ], %g1
a00619f0:  80 a0 60 00  cmp  %g1, 0
a00619f4:  12 80 00 04  bne  0xa0061a04
a00619f8:  d0 2b 60 05  stb  %o0, [ %o5 + 5 ]
a00619fc:  10 80 00 03  b  0xa0061a08
a0061a00:  c0 2b 60 04  clrb  [ %o5 + 4 ]
a0061a04:  d6 23 60 0c  st  %o3, [ %o5 + 0xc ]
a0061a08:  92 82 7f ff  addcc  %o1, -1, %o1
a0061a0c:  1c bf ff e6  bpos  0xa00619a4
a0061a10:  94 02 a0 18  add  %o2, 0x18, %o2
a0061a14:  a0 10 20 00  clr  %l0
a0061a18:  82 0c 20 ff  and  %l0, 0xff, %g1
a0061a1c:  83 28 60 02  sll  %g1, 2, %g1
a0061a20:  9a 14 63 a4  or  %l1, 0x3a4, %o5
a0061a24:  82 00 40 0d  add  %g1, %o5, %g1
a0061a28:  c2 00 60 0c  ld  [ %g1 + 0xc ], %g1
a0061a2c:  a0 04 20 01  inc  %l0
a0061a30:  80 a0 60 00  cmp  %g1, 0
a0061a34:  02 80 00 04  be  0xa0061a44
a0061a38:  90 10 20 00  clr  %o0
a0061a3c:  9f c0 40 00  call  %g1
a0061a40:  01 00 00 00  nop
a0061a44:  82 0c 20 ff  and  %l0, 0xff, %g1
a0061a48:  80 a0 60 01  cmp  %g1, 1
a0061a4c:  08 bf ff f5  bleu  0xa0061a20
a0061a50:  83 28 60 02  sll  %g1, 2, %g1
a0061a54:  1b 2a 01 e4  sethi  %hi(0xa8079000), %o5
a0061a58:  c2 03 63 9c  ld  [ %o5 + 0x39c ], %g1	! 0xa807939c
a0061a5c:  82 00 60 01  inc  %g1
a0061a60:  c2 23 63 9c  st  %g1, [ %o5 + 0x39c ]
a0061a64:  81 c7 e0 08  ret
a0061a68:  81 e8 00 00  restore
