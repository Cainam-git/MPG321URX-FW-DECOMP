# leon2m FUN_a0092908 0xa0092908-0xa0092998 (144 bytes)
a0092908:  9d e3 bf 98  save  %sp, -104, %sp
a009290c:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a0092910:  d2 04 23 ec  ld  [ %l0 + 0x3ec ], %o1	! 0xa802afec
a0092914:  90 02 7f fe  add  %o1, -2, %o0
a0092918:  90 0a 20 ff  and  %o0, 0xff, %o0
a009291c:  40 00 86 0a  call  0xa00b4144
a0092920:  92 10 20 02  mov  2, %o1
a0092924:  82 10 20 26  mov  0x26, %g1
a0092928:  c2 24 23 ec  st  %g1, [ %l0 + 0x3ec ]
a009292c:  10 80 00 0a  b  0xa0092954
a0092930:  a2 10 00 10  mov  %l0, %l1
a0092934:  90 03 3f db  add  %o4, -37, %o0
a0092938:  97 3a 20 1f  sra  %o0, 0x1f, %o3
a009293c:  95 32 e0 1e  srl  %o3, 0x1e, %o2
a0092940:  92 02 00 0a  add  %o0, %o2, %o1
a0092944:  82 0a 7f fc  and  %o1, -4, %g1
a0092948:  9e 22 00 01  sub  %o0, %g1, %o7
a009294c:  9a 03 e0 26  add  %o7, 0x26, %o5
a0092950:  da 24 23 ec  st  %o5, [ %l0 + 0x3ec ]
a0092954:  d8 04 23 ec  ld  [ %l0 + 0x3ec ], %o4
a0092958:  96 03 3f da  add  %o4, -38, %o3
a009295c:  40 00 5e f1  call  0xa00aa520
a0092960:  90 0a e0 ff  and  %o3, 0xff, %o0
a0092964:  94 0a 20 ff  and  %o0, 0xff, %o2
a0092968:  80 a2 a0 01  cmp  %o2, 1
a009296c:  12 bf ff f2  bne  0xa0092934
a0092970:  d8 14 23 ee  lduh  [ %l0 + 0x3ee ], %o4
a0092974:  da 04 63 ec  ld  [ %l1 + 0x3ec ], %o5
a0092978:  a2 03 7f da  add  %o5, -38, %l1
a009297c:  90 0c 60 ff  and  %l1, 0xff, %o0
a0092980:  40 00 59 a3  call  0xa00a900c
a0092984:  92 10 20 01  mov  1, %o1
a0092988:  21 2a 00 b5  sethi  %hi(0xa802d400), %l0
a009298c:  c0 2c 20 33  clrb  [ %l0 + 0x33 ]	! 0xa802d433
a0092990:  81 c7 e0 08  ret
a0092994:  81 e8 00 00  restore
