# leon2m FUN_a009ccc0 0xa009ccc0-0xa009cd74 (180 bytes)
a009ccc0:  9d e3 bf 98  save  %sp, -104, %sp
a009ccc4:  35 2a 00 ab  sethi  %hi(0xa802ac00), %i2
a009ccc8:  d2 06 a3 ec  ld  [ %i2 + 0x3ec ], %o1	! 0xa802afec
a009cccc:  90 02 7f 81  add  %o1, -127, %o0
a009ccd0:  40 00 31 bb  call  0xa00a93bc
a009ccd4:  90 0a 20 ff  and  %o0, 0xff, %o0
a009ccd8:  03 24 92 49  sethi  %hi(0x92492400), %g1
a009ccdc:  b2 10 60 93  or  %g1, 0x93, %i1	! 0x92492493
a009cce0:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009cce4:  9e 02 3f 82  add  %o0, -126, %o7
a009cce8:  80 5b c0 19  smul  %o7, %i1, %g0
a009ccec:  99 40 00 00  rd  %y, %o4
a009ccf0:  96 03 00 0f  add  %o4, %o7, %o3
a009ccf4:  93 3a e0 02  sra  %o3, 2, %o1
a009ccf8:  95 3b e0 1f  sra  %o7, 0x1f, %o2
a009ccfc:  82 22 40 0a  sub  %o1, %o2, %g1
a009cd00:  b1 28 60 03  sll  %g1, 3, %i0
a009cd04:  9a 26 00 01  sub  %i0, %g1, %o5
a009cd08:  96 23 c0 0d  sub  %o7, %o5, %o3
a009cd0c:  98 02 e0 7f  add  %o3, 0x7f, %o4
a009cd10:  d8 26 a3 ec  st  %o4, [ %i2 + 0x3ec ]
a009cd14:  40 00 38 07  call  0xa00aad30
a009cd18:  90 0a e0 ff  and  %o3, 0xff, %o0
a009cd1c:  94 0a 20 ff  and  %o0, 0xff, %o2
a009cd20:  80 a2 a0 01  cmp  %o2, 1
a009cd24:  12 bf ff f0  bne  0xa009cce4
a009cd28:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009cd2c:  f0 06 a3 ec  ld  [ %i2 + 0x3ec ], %i0
a009cd30:  9a 06 3f 81  add  %i0, -127, %o5
a009cd34:  90 0b 60 ff  and  %o5, 0xff, %o0
a009cd38:  40 00 32 46  call  0xa00a9650
a009cd3c:  92 10 20 01  mov  1, %o1
a009cd40:  f2 06 a3 ec  ld  [ %i2 + 0x3ec ], %i1
a009cd44:  9e 06 7f 81  add  %i1, -127, %o7
a009cd48:  35 2a 00 97  sethi  %hi(0xa8025c00), %i2
a009cd4c:  f2 0e a0 54  ldub  [ %i2 + 0x54 ], %i1	! 0xa8025c54
a009cd50:  b0 10 20 01  mov  1, %i0
a009cd54:  80 a3 c0 19  cmp  %o7, %i1
a009cd58:  02 80 00 04  be  0xa009cd68
a009cd5c:  b4 10 20 00  clr  %i2
a009cd60:  b0 10 20 01  mov  1, %i0
a009cd64:  b4 10 20 01  mov  1, %i2
a009cd68:  40 00 2c f5  call  0xa00a813c
a009cd6c:  81 e8 00 00  restore
a009cd70:  01 00 00 00  nop
