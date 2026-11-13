# leon2m FUN_a00ef048 0xa00ef048-0xa00ef1b0 (360 bytes)
a00ef048:  9d e3 bf 98  save  %sp, -104, %sp
a00ef04c:  82 0e 20 ff  and  %i0, 0xff, %g1
a00ef050:  1f 2a 00 9a  sethi  %hi(0xa8026800), %o7
a00ef054:  f0 2b e2 79  stb  %i0, [ %o7 + 0x279 ]	! 0xa8026a79
a00ef058:  80 a0 60 07  cmp  %g1, 7
a00ef05c:  18 80 00 10  bgu  0xa00ef09c
a00ef060:  37 2a 00 9a  sethi  %hi(0xa8026800), %i3
a00ef064:  31 00 02 3b  sethi  %hi(0x8ec00), %i0
a00ef068:  83 28 60 02  sll  %g1, 2, %g1
a00ef06c:  ba 16 23 5c  or  %i0, 0x35c, %i5
a00ef070:  f8 07 40 01  ld  [ %i5 + %g1 ], %i4
a00ef074:  81 c7 00 00  jmp  %i4
a00ef078:  01 00 00 00  nop 
a00ef07c:  37 33 c0 51  sethi  %hi(0xcf014400), %i3
a00ef080:  82 16 e3 50  or  %i3, 0x350, %g1	! 0xcf014750
a00ef084:  f4 00 40 00  ld  [ %g1 ], %i2
a00ef088:  ba 0e bf fe  and  %i2, -2, %i5
a00ef08c:  37 2a 00 9a  sethi  %hi(0xa8026800), %i3
a00ef090:  fa 20 40 00  st  %i5, [ %g1 ]
a00ef094:  b8 10 20 02  mov  2, %i4
a00ef098:  f8 2e e2 78  stb  %i4, [ %i3 + 0x278 ]
a00ef09c:  f8 0e e2 78  ldub  [ %i3 + 0x278 ], %i4
a00ef0a0:  80 a7 20 08  cmp  %i4, 8
a00ef0a4:  02 80 00 12  be  0xa00ef0ec
a00ef0a8:  80 a7 20 03  cmp  %i4, 3
a00ef0ac:  18 80 00 0c  bgu  0xa00ef0dc
a00ef0b0:  f0 0b e2 79  ldub  [ %o7 + 0x279 ], %i0
a00ef0b4:  33 00 06 67  sethi  %hi(0x199c00), %i1
a00ef0b8:  b0 07 00 1c  add  %i4, %i4, %i0
a00ef0bc:  82 16 63 fc  or  %i1, 0x3fc, %g1
a00ef0c0:  fa 10 40 18  lduh  [ %g1 + %i0 ], %i5
a00ef0c4:  b5 2f 60 02  sll  %i5, 2, %i2
a00ef0c8:  37 33 c0 00  sethi  %hi(0xcf000000), %i3
a00ef0cc:  b2 16 80 1b  or  %i2, %i3, %i1
a00ef0d0:  b8 10 20 16  mov  0x16, %i4
a00ef0d4:  f8 26 40 00  st  %i4, [ %i1 ]
a00ef0d8:  f0 0b e2 79  ldub  [ %o7 + 0x279 ], %i0
a00ef0dc:  b2 10 20 88  mov  0x88, %i1
a00ef0e0:  b4 10 20 20  mov  0x20, %i2
a00ef0e4:  40 00 0c 92  call  0xa00f232c
a00ef0e8:  97 e8 20 00  restore  %g0, 0, %o3
a00ef0ec:  37 00 06 67  sethi  %hi(0x199c00), %i3
a00ef0f0:  b2 16 e3 fc  or  %i3, 0x3fc, %i1	! 0x199ffc
a00ef0f4:  b8 10 20 00  clr  %i4
a00ef0f8:  ba 10 20 00  clr  %i5
a00ef0fc:  35 33 c0 00  sethi  %hi(0xcf000000), %i2
a00ef100:  b6 10 20 16  mov  0x16, %i3
a00ef104:  82 07 40 1d  add  %i5, %i5, %g1
a00ef108:  f0 16 40 01  lduh  [ %i1 + %g1 ], %i0
a00ef10c:  bb 2e 20 02  sll  %i0, 2, %i5
a00ef110:  82 17 40 1a  or  %i5, %i2, %g1
a00ef114:  b8 07 20 01  inc  %i4
a00ef118:  ba 0f 20 ff  and  %i4, 0xff, %i5
a00ef11c:  f6 20 40 00  st  %i3, [ %g1 ]
a00ef120:  80 a7 60 03  cmp  %i5, 3
a00ef124:  08 bf ff f9  bleu  0xa00ef108
a00ef128:  82 07 40 1d  add  %i5, %i5, %g1
a00ef12c:  f0 0b e2 79  ldub  [ %o7 + 0x279 ], %i0
a00ef130:  b2 10 20 88  mov  0x88, %i1
a00ef134:  b4 10 20 20  mov  0x20, %i2
a00ef138:  40 00 0c 7d  call  0xa00f232c
a00ef13c:  97 e8 20 00  restore  %g0, 0, %o3
a00ef140:  35 33 c0 51  sethi  %hi(0xcf014400), %i2
a00ef144:  82 16 a3 50  or  %i2, 0x350, %g1	! 0xcf014750
a00ef148:  f2 00 40 00  ld  [ %g1 ], %i1
a00ef14c:  ba 16 60 04  or  %i1, 4, %i5
a00ef150:  37 2a 00 9a  sethi  %hi(0xa8026800), %i3
a00ef154:  fa 20 40 00  st  %i5, [ %g1 ]
a00ef158:  b8 10 20 03  mov  3, %i4
a00ef15c:  10 bf ff d0  b  0xa00ef09c
a00ef160:  f8 2e e2 78  stb  %i4, [ %i3 + 0x278 ]
a00ef164:  37 2a 00 9a  sethi  %hi(0xa8026800), %i3
a00ef168:  10 bf ff cd  b  0xa00ef09c
a00ef16c:  c0 2e e2 78  clrb  [ %i3 + 0x278 ]	! 0xa8026a78
a00ef170:  37 2a 00 9a  sethi  %hi(0xa8026800), %i3
a00ef174:  b2 10 20 01  mov  1, %i1
a00ef178:  10 bf ff c9  b  0xa00ef09c
a00ef17c:  f2 2e e2 78  stb  %i1, [ %i3 + 0x278 ]
a00ef180:  31 33 c0 51  sethi  %hi(0xcf014400), %i0
a00ef184:  82 16 23 50  or  %i0, 0x350, %g1	! 0xcf014750
a00ef188:  fa 00 40 00  ld  [ %g1 ], %i5
a00ef18c:  10 bf ff f1  b  0xa00ef150
a00ef190:  ba 0f 7f fb  and  %i5, -5, %i5
a00ef194:  10 bf ff c2  b  0xa00ef09c
a00ef198:  37 2a 00 9a  sethi  %hi(0xa8026800), %i3
a00ef19c:  03 33 c0 51  sethi  %hi(0xcf014400), %g1
a00ef1a0:  82 10 63 50  or  %g1, 0x350, %g1	! 0xcf014750
a00ef1a4:  f8 00 40 00  ld  [ %g1 ], %i4
a00ef1a8:  10 bf ff b9  b  0xa00ef08c
a00ef1ac:  ba 17 20 01  or  %i4, 1, %i5
