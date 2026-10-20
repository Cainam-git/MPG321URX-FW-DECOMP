# leon2m FUN_a009af8c 0xa009af8c-0xa009b070 (228 bytes)
a009af8c:  9d e3 bf 98  save  %sp, -104, %sp
a009af90:  35 2a 00 ab  sethi  %hi(0xa802ac00), %i2
a009af94:  d2 06 a3 ec  ld  [ %i2 + 0x3ec ], %o1	! 0xa802afec
a009af98:  90 02 60 33  add  %o1, 0x33, %o0
a009af9c:  40 00 39 08  call  0xa00a93bc
a009afa0:  90 0a 20 ff  and  %o0, 0xff, %o0
a009afa4:  03 15 55 55  sethi  %hi(0x55555400), %g1
a009afa8:  b2 10 61 56  or  %g1, 0x156, %i1	! 0x55555556
a009afac:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009afb0:  9e 02 3f 35  add  %o0, -203, %o7
a009afb4:  95 3b e0 1f  sra  %o7, 0x1f, %o2
a009afb8:  80 5b c0 19  smul  %o7, %i1, %g0
a009afbc:  93 40 00 00  rd  %y, %o1
a009afc0:  82 22 40 0a  sub  %o1, %o2, %g1
a009afc4:  b0 00 40 01  add  %g1, %g1, %i0
a009afc8:  98 06 00 01  add  %i0, %g1, %o4
a009afcc:  96 23 c0 0c  sub  %o7, %o4, %o3
a009afd0:  9a 02 e0 cd  add  %o3, 0xcd, %o5
a009afd4:  da 26 a3 ec  st  %o5, [ %i2 + 0x3ec ]
a009afd8:  40 00 3f 56  call  0xa00aad30
a009afdc:  90 0a e0 ff  and  %o3, 0xff, %o0
a009afe0:  94 0a 20 ff  and  %o0, 0xff, %o2
a009afe4:  80 a2 a0 01  cmp  %o2, 1
a009afe8:  12 bf ff f2  bne  0xa009afb0
a009afec:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009aff0:  d2 06 a3 ec  ld  [ %i2 + 0x3ec ], %o1
a009aff4:  94 10 3f cf  mov  -49, %o2
a009aff8:  96 02 60 33  add  %o1, 0x33, %o3
a009affc:  82 22 80 09  sub  %o2, %o1, %g1
a009b000:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a009b004:  90 0a e0 ff  and  %o3, 0xff, %o0
a009b008:  c2 2e 22 c1  stb  %g1, [ %i0 + 0x2c1 ]
a009b00c:  40 00 39 91  call  0xa00a9650
a009b010:  92 10 20 01  mov  1, %o1
a009b014:  40 00 f2 c3  call  0xa00d7b20
a009b018:  01 00 00 00  nop
a009b01c:  19 2a 00 97  sethi  %hi(0xa8025c00), %o4
a009b020:  de 06 a3 ec  ld  [ %i2 + 0x3ec ], %o7
a009b024:  d6 0b 20 55  ldub  [ %o4 + 0x55 ], %o3
a009b028:  9a 10 20 cf  mov  0xcf, %o5
a009b02c:  b4 23 40 0f  sub  %o5, %o7, %i2
a009b030:  b2 0a e0 ff  and  %o3, 0xff, %i1
a009b034:  80 a6 80 19  cmp  %i2, %i1
a009b038:  02 80 00 07  be  0xa009b054
a009b03c:  9a 10 20 02  mov  2, %o5
a009b040:  b4 23 40 0b  sub  %o5, %o3, %i2
a009b044:  b2 0e a0 ff  and  %i2, 0xff, %i1
a009b048:  b0 10 20 01  mov  1, %i0
a009b04c:  40 00 34 3c  call  0xa00a813c
a009b050:  95 e8 20 01  restore  %g0, 1, %o2
a009b054:  b2 10 20 02  mov  2, %i1
a009b058:  90 26 40 0b  sub  %i1, %o3, %o0
a009b05c:  b2 0a 20 ff  and  %o0, 0xff, %i1
a009b060:  b0 10 20 01  mov  1, %i0
a009b064:  40 00 34 36  call  0xa00a813c
a009b068:  95 e8 20 00  restore  %g0, 0, %o2
a009b06c:  01 00 00 00  nop
