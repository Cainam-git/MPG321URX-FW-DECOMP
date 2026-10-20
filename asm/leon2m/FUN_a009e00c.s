# leon2m FUN_a009e00c 0xa009e00c-0xa009e0bc (176 bytes)
a009e00c:  9d e3 bf 98  save  %sp, -104, %sp
a009e010:  35 2a 00 ab  sethi  %hi(0xa802ac00), %i2
a009e014:  d2 06 a3 ec  ld  [ %i2 + 0x3ec ], %o1	! 0xa802afec
a009e018:  90 02 60 45  add  %o1, 0x45, %o0
a009e01c:  40 00 2c e8  call  0xa00a93bc
a009e020:  90 0a 20 ff  and  %o0, 0xff, %o0
a009e024:  03 19 99 99  sethi  %hi(0x66666400), %g1
a009e028:  b2 10 62 67  or  %g1, 0x267, %i1	! 0x66666667
a009e02c:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009e030:  9e 02 3f 46  add  %o0, -186, %o7
a009e034:  80 5b c0 19  smul  %o7, %i1, %g0
a009e038:  97 40 00 00  rd  %y, %o3
a009e03c:  93 3a e0 01  sra  %o3, 1, %o1
a009e040:  95 3b e0 1f  sra  %o7, 0x1f, %o2
a009e044:  82 22 40 0a  sub  %o1, %o2, %g1
a009e048:  b1 28 60 02  sll  %g1, 2, %i0
a009e04c:  98 06 00 01  add  %i0, %g1, %o4
a009e050:  96 23 c0 0c  sub  %o7, %o4, %o3
a009e054:  9a 02 e0 bb  add  %o3, 0xbb, %o5
a009e058:  da 26 a3 ec  st  %o5, [ %i2 + 0x3ec ]
a009e05c:  40 00 33 35  call  0xa00aad30
a009e060:  90 0a e0 ff  and  %o3, 0xff, %o0
a009e064:  94 0a 20 ff  and  %o0, 0xff, %o2
a009e068:  80 a2 a0 01  cmp  %o2, 1
a009e06c:  12 bf ff f1  bne  0xa009e030
a009e070:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009e074:  d8 06 a3 ec  ld  [ %i2 + 0x3ec ], %o4
a009e078:  9a 03 20 45  add  %o4, 0x45, %o5
a009e07c:  90 0b 60 ff  and  %o5, 0xff, %o0
a009e080:  40 00 2d 74  call  0xa00a9650
a009e084:  92 10 20 01  mov  1, %o1
a009e088:  f2 06 a3 ec  ld  [ %i2 + 0x3ec ], %i1
a009e08c:  9e 06 7f 45  add  %i1, -187, %o7
a009e090:  35 2a 00 97  sethi  %hi(0xa8025c00), %i2
a009e094:  f2 0e a0 56  ldub  [ %i2 + 0x56 ], %i1	! 0xa8025c56
a009e098:  b0 10 20 01  mov  1, %i0
a009e09c:  80 a3 c0 19  cmp  %o7, %i1
a009e0a0:  02 80 00 04  be  0xa009e0b0
a009e0a4:  b4 10 20 00  clr  %i2
a009e0a8:  b0 10 20 01  mov  1, %i0
a009e0ac:  b4 10 20 01  mov  1, %i2
a009e0b0:  40 00 28 23  call  0xa00a813c
a009e0b4:  81 e8 00 00  restore
a009e0b8:  01 00 00 00  nop
