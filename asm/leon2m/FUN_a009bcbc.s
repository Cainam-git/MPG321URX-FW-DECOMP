# leon2m FUN_a009bcbc 0xa009bcbc-0xa009bdcc (272 bytes)
a009bcbc:  9d e3 bf 98  save  %sp, -104, %sp
a009bcc0:  33 2a 00 ab  sethi  %hi(0xa802ac00), %i1
a009bcc4:  d2 06 63 ec  ld  [ %i1 + 0x3ec ], %o1	! 0xa802afec
a009bcc8:  90 02 60 28  add  %o1, 0x28, %o0
a009bccc:  40 00 35 bc  call  0xa00a93bc
a009bcd0:  90 0a 20 ff  and  %o0, 0xff, %o0
a009bcd4:  03 19 99 99  sethi  %hi(0x66666400), %g1
a009bcd8:  b0 10 62 67  or  %g1, 0x267, %i0	! 0x66666667
a009bcdc:  d0 16 63 ee  lduh  [ %i1 + 0x3ee ], %o0
a009bce0:  9e 02 3f 2c  add  %o0, -212, %o7
a009bce4:  80 5b c0 18  smul  %o7, %i0, %g0
a009bce8:  9b 40 00 00  rd  %y, %o5
a009bcec:  95 3b 60 01  sra  %o5, 1, %o2
a009bcf0:  97 3b e0 1f  sra  %o7, 0x1f, %o3
a009bcf4:  92 22 80 0b  sub  %o2, %o3, %o1
a009bcf8:  83 2a 60 02  sll  %o1, 2, %g1
a009bcfc:  98 00 40 09  add  %g1, %o1, %o4
a009bd00:  96 23 c0 0c  sub  %o7, %o4, %o3
a009bd04:  9a 02 e0 d8  add  %o3, 0xd8, %o5
a009bd08:  da 26 63 ec  st  %o5, [ %i1 + 0x3ec ]
a009bd0c:  40 00 3c 09  call  0xa00aad30
a009bd10:  90 0a e0 ff  and  %o3, 0xff, %o0
a009bd14:  94 0a 20 ff  and  %o0, 0xff, %o2
a009bd18:  80 a2 a0 01  cmp  %o2, 1
a009bd1c:  32 bf ff f1  bne,a   0xa009bce0
a009bd20:  d0 16 63 ee  lduh  [ %i1 + 0x3ee ], %o0
a009bd24:  d8 06 63 ec  ld  [ %i1 + 0x3ec ], %o4
a009bd28:  90 03 20 28  add  %o4, 0x28, %o0
a009bd2c:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a009bd30:  92 13 e2 90  or  %o7, 0x290, %o1	! 0xa802d290
a009bd34:  90 0a 20 ff  and  %o0, 0xff, %o0
a009bd38:  da 02 60 30  ld  [ %o1 + 0x30 ], %o5
a009bd3c:  b0 0a 20 0f  and  %o0, 0xf, %i0
a009bd40:  83 2e 20 04  sll  %i0, 4, %g1
a009bd44:  96 0b 7f 0f  and  %o5, -241, %o3
a009bd48:  94 12 c0 01  or  %o3, %g1, %o2
a009bd4c:  d4 22 60 30  st  %o2, [ %o1 + 0x30 ]
a009bd50:  40 00 36 40  call  0xa00a9650
a009bd54:  92 10 20 01  mov  1, %o1
a009bd58:  40 00 ef 46  call  0xa00d7a70
a009bd5c:  90 10 20 01  mov  1, %o0
a009bd60:  d8 06 63 ec  ld  [ %i1 + 0x3ec ], %o4
a009bd64:  1f 2a 00 97  sethi  %hi(0xa8025c00), %o7
a009bd68:  b0 03 3f 28  add  %o4, -216, %i0
a009bd6c:  d2 0b e0 55  ldub  [ %o7 + 0x55 ], %o1
a009bd70:  90 10 20 01  mov  1, %o0
a009bd74:  80 a6 00 09  cmp  %i0, %o1
a009bd78:  02 80 00 04  be  0xa009bd88
a009bd7c:  94 10 20 00  clr  %o2
a009bd80:  90 10 20 01  mov  1, %o0
a009bd84:  94 10 20 01  mov  1, %o2
a009bd88:  40 00 30 ed  call  0xa00a813c
a009bd8c:  01 00 00 00  nop
a009bd90:  d2 06 63 ec  ld  [ %i1 + 0x3ec ], %o1
a009bd94:  80 a2 60 dc  cmp  %o1, 0xdc
a009bd98:  02 80 00 07  be  0xa009bdb4
a009bd9c:  90 10 20 01  mov  1, %o0
a009bda0:  40 00 35 b2  call  0xa00a9468
a009bda4:  92 10 20 03  mov  3, %o1
a009bda8:  b0 10 20 00  clr  %i0
a009bdac:  40 00 5d ca  call  0xa00b34d4
a009bdb0:  93 e8 20 04  restore  %g0, 4, %o1
a009bdb4:  40 00 35 ad  call  0xa00a9468
a009bdb8:  92 10 20 02  mov  2, %o1
a009bdbc:  b0 10 20 00  clr  %i0
a009bdc0:  40 00 5d c5  call  0xa00b34d4
a009bdc4:  93 e8 20 01  restore  %g0, 1, %o1
a009bdc8:  01 00 00 00  nop
