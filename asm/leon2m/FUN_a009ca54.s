# leon2m FUN_a009ca54 0xa009ca54-0xa009cb0c (184 bytes)
a009ca54:  9d e3 bf 98  save  %sp, -104, %sp
a009ca58:  35 2a 00 ab  sethi  %hi(0xa802ac00), %i2
a009ca5c:  d2 06 a3 ec  ld  [ %i2 + 0x3ec ], %o1	! 0xa802afec
a009ca60:  90 02 7f 90  add  %o1, -112, %o0
a009ca64:  40 00 32 56  call  0xa00a93bc
a009ca68:  90 0a 20 ff  and  %o0, 0xff, %o0
a009ca6c:  03 24 92 49  sethi  %hi(0x92492400), %g1
a009ca70:  b2 10 60 93  or  %g1, 0x93, %i1	! 0x92492493
a009ca74:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009ca78:  9e 02 3f 91  add  %o0, -111, %o7
a009ca7c:  80 5b c0 19  smul  %o7, %i1, %g0
a009ca80:  99 40 00 00  rd  %y, %o4
a009ca84:  96 03 00 0f  add  %o4, %o7, %o3
a009ca88:  93 3a e0 02  sra  %o3, 2, %o1
a009ca8c:  95 3b e0 1f  sra  %o7, 0x1f, %o2
a009ca90:  82 22 40 0a  sub  %o1, %o2, %g1
a009ca94:  b1 28 60 03  sll  %g1, 3, %i0
a009ca98:  9a 26 00 01  sub  %i0, %g1, %o5
a009ca9c:  96 23 c0 0d  sub  %o7, %o5, %o3
a009caa0:  98 02 e0 70  add  %o3, 0x70, %o4
a009caa4:  d8 26 a3 ec  st  %o4, [ %i2 + 0x3ec ]
a009caa8:  40 00 38 a2  call  0xa00aad30
a009caac:  90 0a e0 ff  and  %o3, 0xff, %o0
a009cab0:  94 0a 20 ff  and  %o0, 0xff, %o2
a009cab4:  80 a2 a0 01  cmp  %o2, 1
a009cab8:  12 bf ff f0  bne  0xa009ca78
a009cabc:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009cac0:  f0 06 a3 ec  ld  [ %i2 + 0x3ec ], %i0
a009cac4:  9a 06 3f 90  add  %i0, -112, %o5
a009cac8:  90 0b 60 ff  and  %o5, 0xff, %o0
a009cacc:  40 00 32 e1  call  0xa00a9650
a009cad0:  92 10 20 01  mov  1, %o1
a009cad4:  40 00 41 08  call  0xa00acef4
a009cad8:  b0 10 20 01  mov  1, %i0
a009cadc:  f2 06 a3 ec  ld  [ %i2 + 0x3ec ], %i1
a009cae0:  9e 06 7f 90  add  %i1, -112, %o7
a009cae4:  35 2a 00 97  sethi  %hi(0xa8025c00), %i2
a009cae8:  f2 0e a0 56  ldub  [ %i2 + 0x56 ], %i1	! 0xa8025c56
a009caec:  80 a3 c0 19  cmp  %o7, %i1
a009caf0:  02 80 00 04  be  0xa009cb00
a009caf4:  b4 10 20 00  clr  %i2
a009caf8:  b0 10 20 01  mov  1, %i0
a009cafc:  b4 10 20 01  mov  1, %i2
a009cb00:  40 00 2d 8f  call  0xa00a813c
a009cb04:  81 e8 00 00  restore
a009cb08:  01 00 00 00  nop
