# leon2m FUN_a009cd74 0xa009cd74-0xa009cfd4 (608 bytes)
a009cd74:  9d e3 bf 98  save  %sp, -104, %sp
a009cd78:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a009cd7c:  d0 04 63 ec  ld  [ %l1 + 0x3ec ], %o0	! 0xa802afec
a009cd80:  1b 09 24 92  sethi  %hi(0x24924800), %o5
a009cd84:  92 02 3f 7a  add  %o0, -134, %o1
a009cd88:  82 13 61 25  or  %o5, 0x125, %g1
a009cd8c:  80 52 40 01  umul  %o1, %g1, %g0
a009cd90:  9f 40 00 00  rd  %y, %o7
a009cd94:  a4 22 40 0f  sub  %o1, %o7, %l2
a009cd98:  a1 34 a0 01  srl  %l2, 1, %l0
a009cd9c:  98 03 c0 10  add  %o7, %l0, %o4
a009cda0:  97 33 20 02  srl  %o4, 2, %o3
a009cda4:  95 2a e0 03  sll  %o3, 3, %o2
a009cda8:  9a 22 80 0b  sub  %o2, %o3, %o5
a009cdac:  90 22 40 0d  sub  %o1, %o5, %o0
a009cdb0:  40 00 31 83  call  0xa00a93bc
a009cdb4:  90 0a 20 ff  and  %o0, 0xff, %o0
a009cdb8:  03 0a aa aa  sethi  %hi(0x2aaaa800), %g1
a009cdbc:  a0 10 62 ab  or  %g1, 0x2ab, %l0	! 0x2aaaaaab
a009cdc0:  a4 10 20 00  clr  %l2
a009cdc4:  d0 14 63 ee  lduh  [ %l1 + 0x3ee ], %o0
a009cdc8:  9e 02 3f 85  add  %o0, -123, %o7
a009cdcc:  80 5b c0 10  smul  %o7, %l0, %g0
a009cdd0:  99 40 00 00  rd  %y, %o4
a009cdd4:  95 3b 20 01  sra  %o4, 1, %o2
a009cdd8:  97 3b e0 1f  sra  %o7, 0x1f, %o3
a009cddc:  9a 22 80 0b  sub  %o2, %o3, %o5
a009cde0:  92 03 40 0d  add  %o5, %o5, %o1
a009cde4:  82 02 40 0d  add  %o1, %o5, %g1
a009cde8:  99 28 60 02  sll  %g1, 2, %o4
a009cdec:  94 23 c0 0c  sub  %o7, %o4, %o2
a009cdf0:  96 02 a0 86  add  %o2, 0x86, %o3
a009cdf4:  d6 24 63 ec  st  %o3, [ %l1 + 0x3ec ]
a009cdf8:  40 00 37 ce  call  0xa00aad30
a009cdfc:  90 0a a0 ff  and  %o2, 0xff, %o0
a009ce00:  92 0a 20 ff  and  %o0, 0xff, %o1
a009ce04:  80 a2 60 01  cmp  %o1, 1
a009ce08:  32 bf ff f0  bne,a   0xa009cdc8
a009ce0c:  d0 14 63 ee  lduh  [ %l1 + 0x3ee ], %o0
a009ce10:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a009ce14:  9a 14 22 90  or  %l0, 0x290, %o5	! 0xa802d290
a009ce18:  d6 04 63 ec  ld  [ %l1 + 0x3ec ], %o3
a009ce1c:  d2 0b 61 a3  ldub  [ %o5 + 0x1a3 ], %o1
a009ce20:  9e 02 40 0d  add  %o1, %o5, %o7
a009ce24:  82 02 e0 7a  add  %o3, 0x7a, %g1
a009ce28:  80 a2 e0 8c  cmp  %o3, 0x8c
a009ce2c:  02 80 00 57  be  0xa009cf88
a009ce30:  c2 2b e1 8a  stb  %g1, [ %o7 + 0x18a ]
a009ce34:  80 a2 e0 91  cmp  %o3, 0x91
a009ce38:  02 80 00 5b  be  0xa009cfa4
a009ce3c:  01 00 00 00  nop
a009ce40:  80 8c a0 ff  btst  0xff, %l2
a009ce44:  12 80 00 31  bne  0xa009cf08
a009ce48:  25 2a 00 97  sethi  %hi(0xa8025c00), %l2
a009ce4c:  d0 04 63 ec  ld  [ %l1 + 0x3ec ], %o0
a009ce50:  21 09 24 92  sethi  %hi(0x24924800), %l0
a009ce54:  94 02 3f 7a  add  %o0, -134, %o2
a009ce58:  a0 14 21 25  or  %l0, 0x125, %l0
a009ce5c:  80 52 80 10  umul  %o2, %l0, %g0
a009ce60:  83 40 00 00  rd  %y, %g1
a009ce64:  9e 22 80 01  sub  %o2, %g1, %o7
a009ce68:  97 33 e0 01  srl  %o7, 1, %o3
a009ce6c:  98 00 40 0b  add  %g1, %o3, %o4
a009ce70:  9b 33 20 02  srl  %o4, 2, %o5
a009ce74:  93 2b 60 03  sll  %o5, 3, %o1
a009ce78:  9e 22 40 0d  sub  %o1, %o5, %o7
a009ce7c:  96 22 80 0f  sub  %o2, %o7, %o3
a009ce80:  90 0a e0 ff  and  %o3, 0xff, %o0
a009ce84:  40 00 31 f3  call  0xa00a9650
a009ce88:  92 10 20 01  mov  1, %o1
a009ce8c:  d4 0c a0 56  ldub  [ %l2 + 0x56 ], %o2
a009ce90:  e4 04 63 ec  ld  [ %l1 + 0x3ec ], %l2
a009ce94:  80 52 80 10  umul  %o2, %l0, %g0
a009ce98:  99 40 00 00  rd  %y, %o4
a009ce9c:  96 04 bf 7a  add  %l2, -134, %o3
a009cea0:  a2 22 80 0c  sub  %o2, %o4, %l1
a009cea4:  80 52 c0 10  umul  %o3, %l0, %g0
a009cea8:  a1 40 00 00  rd  %y, %l0
a009ceac:  83 34 60 01  srl  %l1, 1, %g1
a009ceb0:  90 22 c0 10  sub  %o3, %l0, %o0
a009ceb4:  92 03 00 01  add  %o4, %g1, %o1
a009ceb8:  9b 32 20 01  srl  %o0, 1, %o5
a009cebc:  9e 04 00 0d  add  %l0, %o5, %o7
a009cec0:  99 32 60 02  srl  %o1, 2, %o4
a009cec4:  a3 33 e0 02  srl  %o7, 2, %l1
a009cec8:  a4 0b 20 ff  and  %o4, 0xff, %l2
a009cecc:  80 a4 80 11  cmp  %l2, %l1
a009ced0:  02 80 00 04  be  0xa009cee0
a009ced4:  80 a2 c0 0a  cmp  %o3, %o2
a009ced8:  40 00 6e 78  call  0xa00b88b8
a009cedc:  81 e8 00 00  restore
a009cee0:  02 80 00 35  be  0xa009cfb4
a009cee4:  97 2b 20 03  sll  %o4, 3, %o3
a009cee8:  82 22 c0 0c  sub  %o3, %o4, %g1
a009ceec:  9a 22 80 01  sub  %o2, %g1, %o5
a009cef0:  92 0b 60 ff  and  %o5, 0xff, %o1
a009cef4:  90 10 20 01  mov  1, %o0
a009cef8:  40 00 2c 91  call  0xa00a813c
a009cefc:  94 10 20 01  mov  1, %o2
a009cf00:  40 00 6e 6e  call  0xa00b88b8
a009cf04:  81 e8 00 00  restore
a009cf08:  82 14 22 90  or  %l0, 0x290, %g1
a009cf0c:  da 08 61 a3  ldub  [ %g1 + 0x1a3 ], %o5
a009cf10:  15 09 24 92  sethi  %hi(0x24924800), %o2
a009cf14:  92 03 40 01  add  %o5, %g1, %o1
a009cf18:  9e 12 a1 25  or  %o2, 0x125, %o7
a009cf1c:  d6 0a 61 8a  ldub  [ %o1 + 0x18a ], %o3
a009cf20:  d4 0c a0 56  ldub  [ %l2 + 0x56 ], %o2
a009cf24:  80 52 80 0f  umul  %o2, %o7, %g0
a009cf28:  93 40 00 00  rd  %y, %o1
a009cf2c:  80 52 c0 0f  umul  %o3, %o7, %g0
a009cf30:  83 40 00 00  rd  %y, %g1
a009cf34:  98 22 c0 01  sub  %o3, %g1, %o4
a009cf38:  90 22 80 09  sub  %o2, %o1, %o0
a009cf3c:  a1 33 20 01  srl  %o4, 1, %l0
a009cf40:  9b 32 20 01  srl  %o0, 1, %o5
a009cf44:  9e 00 40 10  add  %g1, %l0, %o7
a009cf48:  96 02 40 0d  add  %o1, %o5, %o3
a009cf4c:  91 33 e0 02  srl  %o7, 2, %o0
a009cf50:  97 32 e0 02  srl  %o3, 2, %o3
a009cf54:  98 0a 20 ff  and  %o0, 0xff, %o4
a009cf58:  a0 0a e0 ff  and  %o3, 0xff, %l0
a009cf5c:  80 a3 00 10  cmp  %o4, %l0
a009cf60:  32 bf ff bc  bne,a   0xa009ce50
a009cf64:  d0 04 63 ec  ld  [ %l1 + 0x3ec ], %o0
a009cf68:  99 2a e0 03  sll  %o3, 3, %o4
a009cf6c:  90 23 00 0b  sub  %o4, %o3, %o0
a009cf70:  a0 22 80 08  sub  %o2, %o0, %l0
a009cf74:  90 0c 20 ff  and  %l0, 0xff, %o0
a009cf78:  40 00 31 b6  call  0xa00a9650
a009cf7c:  92 10 20 00  clr  %o1
a009cf80:  10 bf ff b4  b  0xa009ce50
a009cf84:  d0 04 63 ec  ld  [ %l1 + 0x3ec ], %o0
a009cf88:  40 00 2f 40  call  0xa00a8c88
a009cf8c:  01 00 00 00  nop
a009cf90:  90 10 20 00  clr  %o0	! 0x0
a009cf94:  40 00 6a fe  call  0xa00b7b8c
a009cf98:  a4 10 20 01  mov  1, %l2
a009cf9c:  10 bf ff aa  b  0xa009ce44
a009cfa0:  80 8c a0 ff  btst  0xff, %l2
a009cfa4:  40 00 2f 39  call  0xa00a8c88
a009cfa8:  01 00 00 00  nop
a009cfac:  10 bf ff fa  b  0xa009cf94
a009cfb0:  90 10 20 01  mov  1, %o0	! 0x1
a009cfb4:  93 2b 20 03  sll  %o4, 3, %o1
a009cfb8:  a4 22 40 0c  sub  %o1, %o4, %l2
a009cfbc:  a2 22 80 12  sub  %o2, %l2, %l1
a009cfc0:  92 0c 60 ff  and  %l1, 0xff, %o1
a009cfc4:  90 10 20 01  mov  1, %o0
a009cfc8:  40 00 2c 5d  call  0xa00a813c
a009cfcc:  94 10 20 00  clr  %o2
a009cfd0:  30 bf ff cc  b,a   0xa009cf00
