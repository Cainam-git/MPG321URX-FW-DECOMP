# leon2m FUN_a009aa34 0xa009aa34-0xa009ab58 (292 bytes)
a009aa34:  9d e3 bf 98  save  %sp, -104, %sp
a009aa38:  35 2a 00 ab  sethi  %hi(0xa802ac00), %i2
a009aa3c:  d2 06 a3 ec  ld  [ %i2 + 0x3ec ], %o1	! 0xa802afec
a009aa40:  90 02 7f aa  add  %o1, -86, %o0
a009aa44:  40 00 3a 5e  call  0xa00a93bc
a009aa48:  90 0a 20 ff  and  %o0, 0xff, %o0
a009aa4c:  03 0a aa aa  sethi  %hi(0x2aaaa800), %g1
a009aa50:  b2 10 62 ab  or  %g1, 0x2ab, %i1	! 0x2aaaaaab
a009aa54:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009aa58:  9e 02 3f af  add  %o0, -81, %o7
a009aa5c:  80 5b c0 19  smul  %o7, %i1, %g0
a009aa60:  95 40 00 00  rd  %y, %o2
a009aa64:  97 3b e0 1f  sra  %o7, 0x1f, %o3
a009aa68:  92 22 80 0b  sub  %o2, %o3, %o1
a009aa6c:  82 02 40 09  add  %o1, %o1, %g1
a009aa70:  b0 00 40 09  add  %g1, %o1, %i0
a009aa74:  98 06 00 18  add  %i0, %i0, %o4
a009aa78:  96 23 c0 0c  sub  %o7, %o4, %o3
a009aa7c:  9a 02 e0 56  add  %o3, 0x56, %o5
a009aa80:  da 26 a3 ec  st  %o5, [ %i2 + 0x3ec ]
a009aa84:  40 00 40 ab  call  0xa00aad30
a009aa88:  90 0a e0 ff  and  %o3, 0xff, %o0
a009aa8c:  94 0a 20 ff  and  %o0, 0xff, %o2
a009aa90:  80 a2 a0 01  cmp  %o2, 1
a009aa94:  12 bf ff f1  bne  0xa009aa58
a009aa98:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009aa9c:  da 06 a3 ec  ld  [ %i2 + 0x3ec ], %o5
a009aaa0:  80 a3 60 56  cmp  %o5, 0x56
a009aaa4:  08 80 00 17  bleu  0xa009ab00
a009aaa8:  d6 06 a3 ec  ld  [ %i2 + 0x3ec ], %o3
a009aaac:  9a 03 7f a9  add  %o5, -87, %o5
a009aab0:  33 2a 00 b5  sethi  %hi(0xa802d400), %i1
a009aab4:  94 02 ff aa  add  %o3, -86, %o2
a009aab8:  da 2e 60 30  stb  %o5, [ %i1 + 0x30 ]
a009aabc:  92 10 20 01  mov  1, %o1
a009aac0:  40 00 3a e4  call  0xa00a9650
a009aac4:  90 0a a0 ff  and  %o2, 0xff, %o0
a009aac8:  33 2a 00 97  sethi  %hi(0xa8025c00), %i1
a009aacc:  f2 0e 60 56  ldub  [ %i1 + 0x56 ], %i1	! 0xa8025c56
a009aad0:  d2 06 a3 ec  ld  [ %i2 + 0x3ec ], %o1
a009aad4:  82 0e 60 ff  and  %i1, 0xff, %g1
a009aad8:  b0 02 7f aa  add  %o1, -86, %i0
a009aadc:  b4 00 60 01  add  %g1, 1, %i2
a009aae0:  80 a6 00 1a  cmp  %i0, %i2
a009aae4:  02 80 00 18  be  0xa009ab44
a009aae8:  90 06 60 01  add  %i1, 1, %o0
a009aaec:  b2 06 60 01  inc  %i1
a009aaf0:  b2 0e 60 ff  and  %i1, 0xff, %i1
a009aaf4:  b0 10 20 01  mov  1, %i0
a009aaf8:  40 00 35 91  call  0xa00a813c
a009aafc:  95 e8 20 01  restore  %g0, 1, %o2
a009ab00:  33 2a 00 97  sethi  %hi(0xa8025c00), %i1
a009ab04:  d8 0e 60 56  ldub  [ %i1 + 0x56 ], %o4	! 0xa8025c56
a009ab08:  1f 2a 00 b5  sethi  %hi(0xa802d400), %o7
a009ab0c:  94 02 ff aa  add  %o3, -86, %o2
a009ab10:  92 10 20 01  mov  1, %o1
a009ab14:  d8 2b e0 30  stb  %o4, [ %o7 + 0x30 ]
a009ab18:  40 00 3a ce  call  0xa00a9650
a009ab1c:  90 0a a0 ff  and  %o2, 0xff, %o0
a009ab20:  f2 0e 60 56  ldub  [ %i1 + 0x56 ], %i1
a009ab24:  d2 06 a3 ec  ld  [ %i2 + 0x3ec ], %o1
a009ab28:  82 0e 60 ff  and  %i1, 0xff, %g1
a009ab2c:  b0 02 7f aa  add  %o1, -86, %i0
a009ab30:  b4 00 60 01  add  %g1, 1, %i2
a009ab34:  80 a6 00 1a  cmp  %i0, %i2
a009ab38:  32 bf ff ee  bne,a   0xa009aaf0
a009ab3c:  b2 06 60 01  inc  %i1
a009ab40:  90 06 60 01  add  %i1, 1, %o0
a009ab44:  b2 0a 20 ff  and  %o0, 0xff, %i1
a009ab48:  b0 10 20 01  mov  1, %i0
a009ab4c:  40 00 35 7c  call  0xa00a813c
a009ab50:  95 e8 20 00  restore  %g0, 0, %o2
a009ab54:  01 00 00 00  nop
