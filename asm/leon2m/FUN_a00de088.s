# leon2m FUN_a00de088 0xa00de088-0xa00de1fc (44 bytes)
a00de088:  82 0a 20 ff  and  %o0, 0xff, %g1
a00de08c:  80 a0 60 11  cmp  %g1, 0x11
a00de090:  18 80 00 59  bgu  0xa00de1f4
a00de094:  11 00 01 f7  sethi  %hi(0x7dc00), %o0
a00de098:  83 28 60 02  sll  %g1, 2, %g1
a00de09c:  9a 12 20 e0  or  %o0, 0xe0, %o5
a00de0a0:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a00de0a4:  81 c3 00 00  jmp  %o4
a00de0a8:  01 00 00 00  nop
a00de0ac:  9a 0a 60 ff  and  %o1, 0xff, %o5
a00de0b0:  13 33 c0 f0  sethi  %hi(0xcf03c000), %o1
a00de0b4:  82 12 60 14  or  %o1, 0x14, %g1	! 0xcf03c014
a00de0b8:  da 20 40 00  st  %o5, [ %g1 ]
a00de0bc:  30 80 00 4e  b,a   0xa00de1f4
a00de0c0:  03 33 c0 f3  sethi  %hi(0xcf03cc00), %g1
a00de0c4:  9a 0a 60 ff  and  %o1, 0xff, %o5
a00de0c8:  82 10 60 4c  or  %g1, 0x4c, %g1
a00de0cc:  da 20 40 00  st  %o5, [ %g1 ]
a00de0d0:  30 80 00 49  b,a   0xa00de1f4
a00de0d4:  9a 0a 60 ff  and  %o1, 0xff, %o5
a00de0d8:  13 33 c0 f3  sethi  %hi(0xcf03cc00), %o1
a00de0dc:  82 12 60 48  or  %o1, 0x48, %g1	! 0xcf03cc48
a00de0e0:  da 20 40 00  st  %o5, [ %g1 ]
a00de0e4:  30 80 00 44  b,a   0xa00de1f4
a00de0e8:  03 33 c0 f3  sethi  %hi(0xcf03cc00), %g1
a00de0ec:  9a 0a 60 ff  and  %o1, 0xff, %o5
a00de0f0:  82 10 60 44  or  %g1, 0x44, %g1
a00de0f4:  da 20 40 00  st  %o5, [ %g1 ]
a00de0f8:  30 80 00 3f  b,a   0xa00de1f4
a00de0fc:  11 33 c0 f3  sethi  %hi(0xcf03cc00), %o0
a00de100:  9a 0a 60 ff  and  %o1, 0xff, %o5
a00de104:  82 12 20 40  or  %o0, 0x40, %g1
a00de108:  da 20 40 00  st  %o5, [ %g1 ]
a00de10c:  30 80 00 3a  b,a   0xa00de1f4
a00de110:  03 33 c0 f1  sethi  %hi(0xcf03c400), %g1
a00de114:  9a 0a 60 ff  and  %o1, 0xff, %o5
a00de118:  82 10 60 7c  or  %g1, 0x7c, %g1
a00de11c:  da 20 40 00  st  %o5, [ %g1 ]
a00de120:  30 80 00 35  b,a   0xa00de1f4
a00de124:  19 33 c0 f1  sethi  %hi(0xcf03c400), %o4
a00de128:  9a 0a 60 ff  and  %o1, 0xff, %o5
a00de12c:  82 13 20 74  or  %o4, 0x74, %g1
a00de130:  da 20 40 00  st  %o5, [ %g1 ]
a00de134:  30 80 00 30  b,a   0xa00de1f4
a00de138:  9a 0a 60 ff  and  %o1, 0xff, %o5
a00de13c:  13 33 c0 f1  sethi  %hi(0xcf03c400), %o1
a00de140:  82 12 60 6c  or  %o1, 0x6c, %g1	! 0xcf03c46c
a00de144:  da 20 40 00  st  %o5, [ %g1 ]
a00de148:  30 80 00 2b  b,a   0xa00de1f4
a00de14c:  11 33 c0 f1  sethi  %hi(0xcf03c400), %o0
a00de150:  9a 0a 60 ff  and  %o1, 0xff, %o5
a00de154:  82 12 20 64  or  %o0, 0x64, %g1
a00de158:  da 20 40 00  st  %o5, [ %g1 ]
a00de15c:  30 80 00 26  b,a   0xa00de1f4
a00de160:  03 33 c0 f1  sethi  %hi(0xcf03c400), %g1
a00de164:  9a 0a 60 ff  and  %o1, 0xff, %o5
a00de168:  82 10 60 5c  or  %g1, 0x5c, %g1
a00de16c:  da 20 40 00  st  %o5, [ %g1 ]
a00de170:  30 80 00 21  b,a   0xa00de1f4
a00de174:  19 33 c0 f1  sethi  %hi(0xcf03c400), %o4
a00de178:  9a 0a 60 ff  and  %o1, 0xff, %o5
a00de17c:  82 13 20 54  or  %o4, 0x54, %g1
a00de180:  da 20 40 00  st  %o5, [ %g1 ]
a00de184:  30 80 00 1c  b,a   0xa00de1f4
a00de188:  03 33 c0 f0  sethi  %hi(0xcf03c000), %g1
a00de18c:  9a 0a 60 ff  and  %o1, 0xff, %o5
a00de190:  10 bf ff cf  b  0xa00de0cc
a00de194:  82 10 60 4c  or  %g1, 0x4c, %g1
a00de198:  03 33 c0 f0  sethi  %hi(0xcf03c000), %g1
a00de19c:  9a 0a 60 ff  and  %o1, 0xff, %o5
a00de1a0:  10 bf ff d5  b  0xa00de0f4
a00de1a4:  82 10 60 44  or  %g1, 0x44, %g1
a00de1a8:  9a 0a 60 ff  and  %o1, 0xff, %o5
a00de1ac:  13 33 c0 f0  sethi  %hi(0xcf03c000), %o1
a00de1b0:  82 12 60 24  or  %o1, 0x24, %g1	! 0xcf03c024
a00de1b4:  da 20 40 00  st  %o5, [ %g1 ]
a00de1b8:  30 80 00 0f  b,a   0xa00de1f4
a00de1bc:  11 33 c0 f0  sethi  %hi(0xcf03c000), %o0
a00de1c0:  9a 0a 60 ff  and  %o1, 0xff, %o5
a00de1c4:  82 12 20 20  or  %o0, 0x20, %g1
a00de1c8:  da 20 40 00  st  %o5, [ %g1 ]
a00de1cc:  30 80 00 0a  b,a   0xa00de1f4
a00de1d0:  03 33 c0 f0  sethi  %hi(0xcf03c000), %g1
a00de1d4:  9a 0a 60 ff  and  %o1, 0xff, %o5
a00de1d8:  82 10 60 1c  or  %g1, 0x1c, %g1
a00de1dc:  da 20 40 00  st  %o5, [ %g1 ]
a00de1e0:  30 80 00 05  b,a   0xa00de1f4
a00de1e4:  19 33 c0 f0  sethi  %hi(0xcf03c000), %o4
a00de1e8:  9a 0a 60 ff  and  %o1, 0xff, %o5
a00de1ec:  82 13 20 18  or  %o4, 0x18, %g1
a00de1f0:  da 20 40 00  st  %o5, [ %g1 ]
a00de1f4:  81 c3 e0 08  retl
a00de1f8:  01 00 00 00  nop
