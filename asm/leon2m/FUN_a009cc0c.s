# leon2m FUN_a009cc0c 0xa009cc0c-0xa009ccc0 (180 bytes)
a009cc0c:  9d e3 bf 98  save  %sp, -104, %sp
a009cc10:  35 2a 00 ab  sethi  %hi(0xa802ac00), %i2
a009cc14:  d2 06 a3 ec  ld  [ %i2 + 0x3ec ], %o1	! 0xa802afec
a009cc18:  90 02 7f 81  add  %o1, -127, %o0
a009cc1c:  40 00 31 e8  call  0xa00a93bc
a009cc20:  90 0a 20 ff  and  %o0, 0xff, %o0
a009cc24:  03 24 92 49  sethi  %hi(0x92492400), %g1
a009cc28:  b2 10 60 93  or  %g1, 0x93, %i1	! 0x92492493
a009cc2c:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009cc30:  9e 02 3f 87  add  %o0, -121, %o7
a009cc34:  80 5b c0 19  smul  %o7, %i1, %g0
a009cc38:  99 40 00 00  rd  %y, %o4
a009cc3c:  96 03 00 0f  add  %o4, %o7, %o3
a009cc40:  93 3a e0 02  sra  %o3, 2, %o1
a009cc44:  95 3b e0 1f  sra  %o7, 0x1f, %o2
a009cc48:  82 22 40 0a  sub  %o1, %o2, %g1
a009cc4c:  b1 28 60 03  sll  %g1, 3, %i0
a009cc50:  9a 26 00 01  sub  %i0, %g1, %o5
a009cc54:  96 23 c0 0d  sub  %o7, %o5, %o3
a009cc58:  98 02 e0 7f  add  %o3, 0x7f, %o4
a009cc5c:  d8 26 a3 ec  st  %o4, [ %i2 + 0x3ec ]
a009cc60:  40 00 38 34  call  0xa00aad30
a009cc64:  90 0a e0 ff  and  %o3, 0xff, %o0
a009cc68:  94 0a 20 ff  and  %o0, 0xff, %o2
a009cc6c:  80 a2 a0 01  cmp  %o2, 1
a009cc70:  12 bf ff f0  bne  0xa009cc30
a009cc74:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009cc78:  f0 06 a3 ec  ld  [ %i2 + 0x3ec ], %i0
a009cc7c:  9a 06 3f 81  add  %i0, -127, %o5
a009cc80:  90 0b 60 ff  and  %o5, 0xff, %o0
a009cc84:  40 00 32 73  call  0xa00a9650
a009cc88:  92 10 20 01  mov  1, %o1
a009cc8c:  f2 06 a3 ec  ld  [ %i2 + 0x3ec ], %i1
a009cc90:  9e 06 7f 81  add  %i1, -127, %o7
a009cc94:  35 2a 00 97  sethi  %hi(0xa8025c00), %i2
a009cc98:  f2 0e a0 54  ldub  [ %i2 + 0x54 ], %i1	! 0xa8025c54
a009cc9c:  b0 10 20 01  mov  1, %i0
a009cca0:  80 a3 c0 19  cmp  %o7, %i1
a009cca4:  02 80 00 04  be  0xa009ccb4
a009cca8:  b4 10 20 00  clr  %i2
a009ccac:  b0 10 20 01  mov  1, %i0
a009ccb0:  b4 10 20 01  mov  1, %i2
a009ccb4:  40 00 2d 22  call  0xa00a813c
a009ccb8:  81 e8 00 00  restore
a009ccbc:  01 00 00 00  nop
