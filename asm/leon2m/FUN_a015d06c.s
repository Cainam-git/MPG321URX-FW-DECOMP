# leon2m FUN_a015d06c 0xa015d06c-0xa015d288 (540 bytes)
a015d06c:  9d e3 bf 88  save  %sp, -120, %sp
a015d070:  e2 06 60 10  ld  [ %i1 + 0x10 ], %l1
a015d074:  e0 06 a0 10  ld  [ %i2 + 0x10 ], %l0
a015d078:  80 a4 40 10  cmp  %l1, %l0
a015d07c:  16 80 00 07  bge  0xa015d098
a015d080:  90 10 00 18  mov  %i0, %o0
a015d084:  f2 27 bf f4  st  %i1, [ %fp + -12 ]
a015d088:  b2 10 00 1a  mov  %i2, %i1
a015d08c:  f4 07 bf f4  ld  [ %fp + -12 ], %i2
a015d090:  a2 10 00 10  mov  %l0, %l1
a015d094:  e0 06 a0 10  ld  [ %i2 + 0x10 ], %l0
a015d098:  b6 04 40 10  add  %l1, %l0, %i3
a015d09c:  c2 06 60 08  ld  [ %i1 + 8 ], %g1
a015d0a0:  80 a0 40 1b  cmp  %g1, %i3
a015d0a4:  16 80 00 03  bge  0xa015d0b0
a015d0a8:  d2 06 60 04  ld  [ %i1 + 4 ], %o1
a015d0ac:  92 02 60 01  inc  %o1
a015d0b0:  7f ff fe f5  call  0xa015cc84
a015d0b4:  01 00 00 00  nop
a015d0b8:  82 02 20 14  add  %o0, 0x14, %g1
a015d0bc:  9b 2e e0 02  sll  %i3, 2, %o5
a015d0c0:  b0 03 40 01  add  %o5, %g1, %i0
a015d0c4:  d0 27 bf f4  st  %o0, [ %fp + -12 ]
a015d0c8:  c2 27 bf e8  st  %g1, [ %fp + -24 ]
a015d0cc:  da 27 bf ec  st  %o5, [ %fp + -20 ]
a015d0d0:  80 a0 40 18  cmp  %g1, %i0
a015d0d4:  1a 80 00 07  bcc  0xa015d0f0
a015d0d8:  a6 10 00 01  mov  %g1, %l3
a015d0dc:  c0 24 c0 00  clr  [ %l3 ]
a015d0e0:  a6 04 e0 04  add  %l3, 4, %l3
a015d0e4:  80 a4 c0 18  cmp  %l3, %i0
a015d0e8:  2a bf ff fe  bcs,a   0xa015d0e0
a015d0ec:  c0 24 c0 00  clr  [ %l3 ]
a015d0f0:  b4 06 a0 14  add  %i2, 0x14, %i2
a015d0f4:  9b 2c 20 02  sll  %l0, 2, %o5
a015d0f8:  9a 03 40 1a  add  %o5, %i2, %o5
a015d0fc:  b0 06 60 14  add  %i1, 0x14, %i0
a015d100:  83 2c 60 02  sll  %l1, 2, %g1
a015d104:  da 27 bf f0  st  %o5, [ %fp + -16 ]
a015d108:  ba 00 40 18  add  %g1, %i0, %i5
a015d10c:  80 a6 80 0d  cmp  %i2, %o5
a015d110:  1a 80 00 4c  bcc  0xa015d240
a015d114:  f8 07 bf e8  ld  [ %fp + -24 ], %i4
a015d118:  1b 00 00 3f  sethi  %hi(0xfc00), %o5
a015d11c:  c2 06 80 00  ld  [ %i2 ], %g1
a015d120:  9a 13 63 ff  or  %o5, 0x3ff, %o5
a015d124:  ac 88 40 0d  andcc  %g1, %o5, %l6
a015d128:  22 80 00 20  be,a   0xa015d1a8
a015d12c:  ad 30 60 10  srl  %g1, 0x10, %l6
a015d130:  a6 10 00 18  mov  %i0, %l3
a015d134:  b2 10 00 1c  mov  %i4, %i1
a015d138:  a8 10 20 00  clr  %l4
a015d13c:  03 00 06 a1  sethi  %hi(0x1a8400), %g1
a015d140:  ea 00 62 50  ld  [ %g1 + 0x250 ], %l5	! 0x1a8650
a015d144:  e2 04 c0 00  ld  [ %l3 ], %l1
a015d148:  92 10 00 16  mov  %l6, %o1
a015d14c:  7f ff e9 2a  call  0xa01575f4
a015d150:  90 0c 40 15  and  %l1, %l5, %o0
a015d154:  e0 06 40 00  ld  [ %i1 ], %l0
a015d158:  82 0c 00 15  and  %l0, %l5, %g1
a015d15c:  90 02 00 01  add  %o0, %g1, %o0
a015d160:  a4 02 00 14  add  %o0, %l4, %l2
a015d164:  91 34 60 10  srl  %l1, 0x10, %o0
a015d168:  7f ff e9 23  call  0xa01575f4
a015d16c:  92 10 00 16  mov  %l6, %o1
a015d170:  a1 34 20 10  srl  %l0, 0x10, %l0
a015d174:  a9 34 a0 10  srl  %l2, 0x10, %l4
a015d178:  90 02 00 10  add  %o0, %l0, %o0
a015d17c:  a2 02 00 14  add  %o0, %l4, %l1
a015d180:  e2 36 40 00  sth  %l1, [ %i1 ]
a015d184:  e4 36 60 02  sth  %l2, [ %i1 + 2 ]
a015d188:  a6 04 e0 04  add  %l3, 4, %l3
a015d18c:  b2 06 60 04  add  %i1, 4, %i1
a015d190:  80 a4 c0 1d  cmp  %l3, %i5
a015d194:  0a bf ff ec  bcs  0xa015d144
a015d198:  a9 34 60 10  srl  %l1, 0x10, %l4
a015d19c:  e8 26 40 00  st  %l4, [ %i1 ]
a015d1a0:  c2 06 80 00  ld  [ %i2 ], %g1
a015d1a4:  ad 30 60 10  srl  %g1, 0x10, %l6
a015d1a8:  80 a5 a0 00  cmp  %l6, 0
a015d1ac:  22 80 00 21  be,a   0xa015d230
a015d1b0:  b4 06 a0 04  add  %i2, 4, %i2
a015d1b4:  e2 07 00 00  ld  [ %i4 ], %l1
a015d1b8:  b2 10 00 1c  mov  %i4, %i1
a015d1bc:  a6 10 00 18  mov  %i0, %l3
a015d1c0:  a8 10 20 00  clr  %l4
a015d1c4:  aa 10 00 11  mov  %l1, %l5
a015d1c8:  1b 00 06 a1  sethi  %hi(0x1a8400), %o5
a015d1cc:  ee 03 62 50  ld  [ %o5 + 0x250 ], %l7	! 0x1a8650
a015d1d0:  e0 04 c0 00  ld  [ %l3 ], %l0
a015d1d4:  92 10 00 16  mov  %l6, %o1
a015d1d8:  7f ff e9 07  call  0xa01575f4
a015d1dc:  90 0c 00 17  and  %l0, %l7, %o0
a015d1e0:  83 35 60 10  srl  %l5, 0x10, %g1
a015d1e4:  90 02 00 01  add  %o0, %g1, %o0
a015d1e8:  a4 02 00 14  add  %o0, %l4, %l2
a015d1ec:  e2 36 60 02  sth  %l1, [ %i1 + 2 ]
a015d1f0:  e4 36 40 00  sth  %l2, [ %i1 ]
a015d1f4:  91 34 20 10  srl  %l0, 0x10, %o0
a015d1f8:  7f ff e8 ff  call  0xa01575f4
a015d1fc:  92 10 00 16  mov  %l6, %o1
a015d200:  b2 06 60 04  add  %i1, 4, %i1
a015d204:  ea 06 40 00  ld  [ %i1 ], %l5
a015d208:  82 0d 40 17  and  %l5, %l7, %g1
a015d20c:  a9 34 a0 10  srl  %l2, 0x10, %l4
a015d210:  90 02 00 01  add  %o0, %g1, %o0
a015d214:  a2 02 00 14  add  %o0, %l4, %l1
a015d218:  a6 04 e0 04  add  %l3, 4, %l3
a015d21c:  80 a4 c0 1d  cmp  %l3, %i5
a015d220:  0a bf ff ec  bcs  0xa015d1d0
a015d224:  a9 34 60 10  srl  %l1, 0x10, %l4
a015d228:  e2 26 40 00  st  %l1, [ %i1 ]
a015d22c:  b4 06 a0 04  add  %i2, 4, %i2
a015d230:  c2 07 bf f0  ld  [ %fp + -16 ], %g1
a015d234:  80 a6 80 01  cmp  %i2, %g1
a015d238:  0a bf ff b8  bcs  0xa015d118
a015d23c:  b8 07 20 04  add  %i4, 4, %i4
a015d240:  da 07 bf ec  ld  [ %fp + -20 ], %o5
a015d244:  c2 07 bf e8  ld  [ %fp + -24 ], %g1
a015d248:  80 a6 e0 00  cmp  %i3, 0
a015d24c:  04 80 00 0b  ble  0xa015d278
a015d250:  b2 03 40 01  add  %o5, %g1, %i1
a015d254:  b2 06 7f fc  add  %i1, -4, %i1
a015d258:  c2 06 40 00  ld  [ %i1 ], %g1
a015d25c:  80 a0 60 00  cmp  %g1, 0
a015d260:  32 80 00 07  bne,a   0xa015d27c
a015d264:  da 07 bf f4  ld  [ %fp + -12 ], %o5
a015d268:  b6 06 ff ff  add  %i3, -1, %i3
a015d26c:  80 a6 e0 00  cmp  %i3, 0
a015d270:  14 bf ff fa  bg  0xa015d258
a015d274:  b2 06 7f fc  add  %i1, -4, %i1
a015d278:  da 07 bf f4  ld  [ %fp + -12 ], %o5
a015d27c:  f6 23 60 10  st  %i3, [ %o5 + 0x10 ]
a015d280:  81 c7 e0 08  ret
a015d284:  91 e8 00 0d  restore  %g0, %o5, %o0
