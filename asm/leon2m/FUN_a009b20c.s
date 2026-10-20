# leon2m FUN_a009b20c 0xa009b20c-0xa009b2c4 (184 bytes)
a009b20c:  9d e3 bf 98  save  %sp, -104, %sp
a009b210:  35 2a 00 ab  sethi  %hi(0xa802ac00), %i2
a009b214:  d2 06 a3 ec  ld  [ %i2 + 0x3ec ], %o1	! 0xa802afec
a009b218:  90 02 60 23  add  %o1, 0x23, %o0
a009b21c:  40 00 38 68  call  0xa00a93bc
a009b220:  90 0a 20 ff  and  %o0, 0xff, %o0
a009b224:  03 19 99 99  sethi  %hi(0x66666400), %g1
a009b228:  b2 10 62 67  or  %g1, 0x267, %i1	! 0x66666667
a009b22c:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009b230:  9e 02 3f 24  add  %o0, -220, %o7
a009b234:  80 5b c0 19  smul  %o7, %i1, %g0
a009b238:  97 40 00 00  rd  %y, %o3
a009b23c:  93 3a e0 01  sra  %o3, 1, %o1
a009b240:  95 3b e0 1f  sra  %o7, 0x1f, %o2
a009b244:  82 22 40 0a  sub  %o1, %o2, %g1
a009b248:  b1 28 60 02  sll  %g1, 2, %i0
a009b24c:  98 06 00 01  add  %i0, %g1, %o4
a009b250:  96 23 c0 0c  sub  %o7, %o4, %o3
a009b254:  9a 02 e0 dd  add  %o3, 0xdd, %o5
a009b258:  da 26 a3 ec  st  %o5, [ %i2 + 0x3ec ]
a009b25c:  40 00 3e b5  call  0xa00aad30
a009b260:  90 0a e0 ff  and  %o3, 0xff, %o0
a009b264:  94 0a 20 ff  and  %o0, 0xff, %o2
a009b268:  80 a2 a0 01  cmp  %o2, 1
a009b26c:  12 bf ff f1  bne  0xa009b230
a009b270:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009b274:  f0 06 a3 ec  ld  [ %i2 + 0x3ec ], %i0
a009b278:  9a 06 20 23  add  %i0, 0x23, %o5
a009b27c:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a009b280:  da 2b 23 ce  stb  %o5, [ %o4 + 0x3ce ]	! 0xa802d3ce
a009b284:  90 0b 60 ff  and  %o5, 0xff, %o0
a009b288:  40 00 38 f2  call  0xa00a9650
a009b28c:  92 10 20 01  mov  1, %o1
a009b290:  f2 06 a3 ec  ld  [ %i2 + 0x3ec ], %i1
a009b294:  9e 06 7f 23  add  %i1, -221, %o7
a009b298:  35 2a 00 97  sethi  %hi(0xa8025c00), %i2
a009b29c:  f2 0e a0 55  ldub  [ %i2 + 0x55 ], %i1	! 0xa8025c55
a009b2a0:  b0 10 20 01  mov  1, %i0
a009b2a4:  80 a3 c0 19  cmp  %o7, %i1
a009b2a8:  02 80 00 04  be  0xa009b2b8
a009b2ac:  b4 10 20 00  clr  %i2
a009b2b0:  b0 10 20 01  mov  1, %i0
a009b2b4:  b4 10 20 01  mov  1, %i2
a009b2b8:  40 00 33 a1  call  0xa00a813c
a009b2bc:  81 e8 00 00  restore
a009b2c0:  01 00 00 00  nop
