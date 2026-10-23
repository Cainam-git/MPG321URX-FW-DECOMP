# leon2m FUN_a010d068 0xa010d068-0xa010d244 (476 bytes)
a010d068:  80 8a 60 ff  btst  0xff, %o1
a010d06c:  12 80 00 27  bne  0xa010d108
a010d070:  96 0a 20 ff  and  %o0, 0xff, %o3
a010d074:  80 a2 e0 02  cmp  %o3, 2
a010d078:  18 80 00 49  bgu  0xa010d19c
a010d07c:  82 10 00 08  mov  %o0, %g1
a010d080:  98 08 60 ff  and  %g1, 0xff, %o4
a010d084:  1b 00 06 6b  sethi  %hi(0x19ac00), %o5
a010d088:  95 2b 20 02  sll  %o4, 2, %o2
a010d08c:  92 13 62 d8  or  %o5, 0x2d8, %o1
a010d090:  da 02 40 0a  ld  [ %o1 + %o2 ], %o5
a010d094:  d8 03 60 f4  ld  [ %o5 + 0xf4 ], %o4
a010d098:  03 00 40 00  sethi  %hi(0x1000000), %g1
a010d09c:  80 a2 e0 02  cmp  %o3, 2
a010d0a0:  08 80 00 4a  bleu  0xa010d1c8
a010d0a4:  94 2b 00 01  andn  %o4, %g1, %o2
a010d0a8:  96 10 00 09  mov  %o1, %o3
a010d0ac:  98 10 20 00  clr  %o4
a010d0b0:  83 2b 20 02  sll  %o4, 2, %g1
a010d0b4:  d2 02 c0 01  ld  [ %o3 + %g1 ], %o1
a010d0b8:  98 03 20 01  inc  %o4
a010d0bc:  d4 22 60 f4  st  %o2, [ %o1 + 0xf4 ]
a010d0c0:  80 a3 20 02  cmp  %o4, 2
a010d0c4:  08 bf ff fc  bleu  0xa010d0b4
a010d0c8:  83 2b 20 02  sll  %o4, 2, %g1
a010d0cc:  82 0a 20 ff  and  %o0, 0xff, %g1
a010d0d0:  80 a0 60 02  cmp  %g1, 2
a010d0d4:  08 80 00 45  bleu  0xa010d1e8
a010d0d8:  13 00 06 6b  sethi  %hi(0x19ac00), %o1
a010d0dc:  11 00 06 6b  sethi  %hi(0x19ac00), %o0
a010d0e0:  96 12 22 cc  or  %o0, 0x2cc, %o3	! 0x19aecc
a010d0e4:  98 10 20 00  clr  %o4
a010d0e8:  93 2b 20 02  sll  %o4, 2, %o1
a010d0ec:  da 02 c0 09  ld  [ %o3 + %o1 ], %o5
a010d0f0:  98 03 20 01  inc  %o4
a010d0f4:  d4 23 60 f4  st  %o2, [ %o5 + 0xf4 ]
a010d0f8:  80 a3 20 02  cmp  %o4, 2
a010d0fc:  08 bf ff fc  bleu  0xa010d0ec
a010d100:  93 2b 20 02  sll  %o4, 2, %o1
a010d104:  30 80 00 4e  b,a   0xa010d23c
a010d108:  80 a2 e0 02  cmp  %o3, 2
a010d10c:  18 80 00 3c  bgu  0xa010d1fc
a010d110:  82 10 00 08  mov  %o0, %g1
a010d114:  82 08 60 ff  and  %g1, 0xff, %g1
a010d118:  19 00 06 6b  sethi  %hi(0x19ac00), %o4
a010d11c:  92 13 22 d8  or  %o4, 0x2d8, %o1	! 0x19aed8
a010d120:  9b 28 60 02  sll  %g1, 2, %o5
a010d124:  d4 02 40 0d  ld  [ %o1 + %o5 ], %o2
a010d128:  d8 02 a0 f4  ld  [ %o2 + 0xf4 ], %o4
a010d12c:  03 00 40 00  sethi  %hi(0x1000000), %g1
a010d130:  80 a2 e0 02  cmp  %o3, 2
a010d134:  08 80 00 3d  bleu  0xa010d228
a010d138:  94 13 00 01  or  %o4, %g1, %o2
a010d13c:  96 10 00 09  mov  %o1, %o3
a010d140:  98 10 20 00  clr  %o4
a010d144:  9b 2b 20 02  sll  %o4, 2, %o5
a010d148:  d2 02 c0 0d  ld  [ %o3 + %o5 ], %o1
a010d14c:  98 03 20 01  inc  %o4
a010d150:  d4 22 60 f4  st  %o2, [ %o1 + 0xf4 ]
a010d154:  80 a3 20 02  cmp  %o4, 2
a010d158:  08 bf ff fc  bleu  0xa010d148
a010d15c:  9b 2b 20 02  sll  %o4, 2, %o5
a010d160:  82 0a 20 ff  and  %o0, 0xff, %g1
a010d164:  80 a0 60 02  cmp  %g1, 2
a010d168:  08 80 00 20  bleu  0xa010d1e8
a010d16c:  13 00 06 6b  sethi  %hi(0x19ac00), %o1
a010d170:  11 00 06 6b  sethi  %hi(0x19ac00), %o0
a010d174:  96 12 22 cc  or  %o0, 0x2cc, %o3	! 0x19aecc
a010d178:  98 10 20 00  clr  %o4
a010d17c:  9b 2b 20 02  sll  %o4, 2, %o5
a010d180:  d2 02 c0 0d  ld  [ %o3 + %o5 ], %o1
a010d184:  98 03 20 01  inc  %o4
a010d188:  d4 22 60 f4  st  %o2, [ %o1 + 0xf4 ]
a010d18c:  80 a3 20 02  cmp  %o4, 2
a010d190:  08 bf ff fc  bleu  0xa010d180
a010d194:  9b 2b 20 02  sll  %o4, 2, %o5
a010d198:  30 80 00 29  b,a   0xa010d23c
a010d19c:  82 10 20 00  clr  %g1
a010d1a0:  98 08 60 ff  and  %g1, 0xff, %o4
a010d1a4:  1b 00 06 6b  sethi  %hi(0x19ac00), %o5
a010d1a8:  95 2b 20 02  sll  %o4, 2, %o2
a010d1ac:  92 13 62 d8  or  %o5, 0x2d8, %o1
a010d1b0:  da 02 40 0a  ld  [ %o1 + %o2 ], %o5
a010d1b4:  d8 03 60 f4  ld  [ %o5 + 0xf4 ], %o4
a010d1b8:  03 00 40 00  sethi  %hi(0x1000000), %g1
a010d1bc:  80 a2 e0 02  cmp  %o3, 2
a010d1c0:  18 bf ff ba  bgu  0xa010d0a8
a010d1c4:  94 2b 00 01  andn  %o4, %g1, %o2
a010d1c8:  99 2a e0 02  sll  %o3, 2, %o4
a010d1cc:  d6 02 40 0c  ld  [ %o1 + %o4 ], %o3
a010d1d0:  82 0a 20 ff  and  %o0, 0xff, %g1
a010d1d4:  d4 22 e0 f4  st  %o2, [ %o3 + 0xf4 ]
a010d1d8:  80 a0 60 02  cmp  %g1, 2
a010d1dc:  18 bf ff c1  bgu  0xa010d0e0
a010d1e0:  11 00 06 6b  sethi  %hi(0x19ac00), %o0
a010d1e4:  13 00 06 6b  sethi  %hi(0x19ac00), %o1
a010d1e8:  97 28 60 02  sll  %g1, 2, %o3
a010d1ec:  90 12 62 cc  or  %o1, 0x2cc, %o0
a010d1f0:  d8 02 00 0b  ld  [ %o0 + %o3 ], %o4
a010d1f4:  d4 23 20 f4  st  %o2, [ %o4 + 0xf4 ]
a010d1f8:  30 80 00 11  b,a   0xa010d23c
a010d1fc:  82 10 20 00  clr  %g1
a010d200:  82 08 60 ff  and  %g1, 0xff, %g1
a010d204:  19 00 06 6b  sethi  %hi(0x19ac00), %o4
a010d208:  92 13 22 d8  or  %o4, 0x2d8, %o1	! 0x19aed8
a010d20c:  9b 28 60 02  sll  %g1, 2, %o5
a010d210:  d4 02 40 0d  ld  [ %o1 + %o5 ], %o2
a010d214:  d8 02 a0 f4  ld  [ %o2 + 0xf4 ], %o4
a010d218:  03 00 40 00  sethi  %hi(0x1000000), %g1
a010d21c:  80 a2 e0 02  cmp  %o3, 2
a010d220:  18 bf ff c7  bgu  0xa010d13c
a010d224:  94 13 00 01  or  %o4, %g1, %o2
a010d228:  83 2a e0 02  sll  %o3, 2, %g1
a010d22c:  d6 02 40 01  ld  [ %o1 + %g1 ], %o3
a010d230:  d4 22 e0 f4  st  %o2, [ %o3 + 0xf4 ]
a010d234:  10 bf ff cc  b  0xa010d164
a010d238:  82 0a 20 ff  and  %o0, 0xff, %g1
a010d23c:  81 c3 e0 08  retl
a010d240:  01 00 00 00  nop
