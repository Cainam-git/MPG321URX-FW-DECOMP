# leon2s FUN_a00da030 0xa00da030-0xa00da288 (600 bytes)
a00da030:  9d e3 bf 68  save  %sp, -152, %sp
a00da034:  25 2a 01 e2  sethi  %hi(0xa8078800), %l2
a00da038:  d6 0c a0 32  ldub  [ %l2 + 0x32 ], %o3	! 0xa8078832
a00da03c:  27 2a 01 e2  sethi  %hi(0xa8078800), %l3
a00da040:  82 02 c0 0b  add  %o3, %o3, %g1
a00da044:  9a 14 e0 0a  or  %l3, 0xa, %o5
a00da048:  d0 13 40 01  lduh  [ %o5 + %g1 ], %o0
a00da04c:  03 2a 01 e7  sethi  %hi(0xa8079c00), %g1
a00da050:  99 2a e0 09  sll  %o3, 9, %o4
a00da054:  82 10 63 98  or  %g1, 0x398, %g1
a00da058:  92 03 00 01  add  %o4, %g1, %o1
a00da05c:  94 10 20 00  clr  %o2
a00da060:  9e 07 bf f8  add  %fp, -8, %o7
a00da064:  9a 0a a0 ff  and  %o2, 0xff, %o5
a00da068:  82 02 00 0d  add  %o0, %o5, %g1
a00da06c:  82 08 61 ff  and  %g1, 0x1ff, %g1
a00da070:  d8 0a 40 01  ldub  [ %o1 + %g1 ], %o4
a00da074:  94 02 a0 01  inc  %o2
a00da078:  9a 03 c0 0d  add  %o7, %o5, %o5
a00da07c:  82 0a a0 ff  and  %o2, 0xff, %g1
a00da080:  80 a0 60 2f  cmp  %g1, 0x2f
a00da084:  08 bf ff f8  bleu  0xa00da064
a00da088:  d8 2b 7f d0  stb  %o4, [ %o5 + -48 ]
a00da08c:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00da090:  82 10 60 00  mov  %g1, %g1	! 0xa8078800
a00da094:  d4 08 40 0b  ldub  [ %g1 + %o3 ], %o2
a00da098:  82 02 80 0a  add  %o2, %o2, %g1
a00da09c:  82 00 40 0a  add  %g1, %o2, %g1
a00da0a0:  83 28 60 02  sll  %g1, 2, %g1
a00da0a4:  82 20 40 0a  sub  %g1, %o2, %g1
a00da0a8:  9a 5a e0 b0  smul  %o3, 0xb0, %o5
a00da0ac:  9a 03 40 01  add  %o5, %g1, %o5
a00da0b0:  03 2a 01 e8  sethi  %hi(0xa807a000), %g1
a00da0b4:  82 10 63 98  or  %g1, 0x398, %g1	! 0xa807a398
a00da0b8:  da 0b 40 01  ldub  [ %o5 + %g1 ], %o5
a00da0bc:  9b 33 60 04  srl  %o5, 4, %o5
a00da0c0:  9a 03 7f ff  add  %o5, -1, %o5
a00da0c4:  99 33 60 1f  srl  %o5, 0x1f, %o4
a00da0c8:  03 2a 01 e7  sethi  %hi(0xa8079c00), %g1
a00da0cc:  97 2a e0 04  sll  %o3, 4, %o3
a00da0d0:  98 03 40 0c  add  %o5, %o4, %o4
a00da0d4:  82 10 60 62  or  %g1, 0x62, %g1
a00da0d8:  96 02 c0 01  add  %o3, %g1, %o3
a00da0dc:  99 3b 20 01  sra  %o4, 1, %o4
a00da0e0:  d6 0a c0 0a  ldub  [ %o3 + %o2 ], %o3
a00da0e4:  80 8b 60 01  btst  1, %o5
a00da0e8:  02 80 00 03  be  0xa00da0f4
a00da0ec:  a0 10 00 0c  mov  %o4, %l0
a00da0f0:  a0 03 20 01  add  %o4, 1, %l0
a00da0f4:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00da0f8:  d8 08 60 68  ldub  [ %g1 + 0x68 ], %o4	! 0xa8078868
a00da0fc:  9a 0e 20 ff  and  %i0, 0xff, %o5
a00da100:  82 0b 20 ff  and  %o4, 0xff, %g1
a00da104:  80 a3 40 01  cmp  %o5, %g1
a00da108:  18 80 00 03  bgu  0xa00da114
a00da10c:  a2 10 00 0c  mov  %o4, %l1
a00da110:  a2 10 00 18  mov  %i0, %l1
a00da114:  82 0a e0 ff  and  %o3, 0xff, %g1
a00da118:  80 a0 60 00  cmp  %g1, 0
a00da11c:  12 80 00 2a  bne  0xa00da1c4
a00da120:  b0 0c 60 ff  and  %l1, 0xff, %i0
a00da124:  80 a0 40 18  cmp  %g1, %i0
a00da128:  1a 80 00 14  bcc  0xa00da178
a00da12c:  94 10 20 00  clr  %o2
a00da130:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a00da134:  92 10 60 9c  or  %g1, 0x9c, %o1	! 0xa807609c
a00da138:  96 0c 20 ff  and  %l0, 0xff, %o3
a00da13c:  98 0a a0 ff  and  %o2, 0xff, %o4
a00da140:  c2 0c a0 32  ldub  [ %l2 + 0x32 ], %g1
a00da144:  9a 02 c0 0c  add  %o3, %o4, %o5
a00da148:  83 28 60 02  sll  %g1, 2, %g1
a00da14c:  c2 02 40 01  ld  [ %o1 + %g1 ], %g1
a00da150:  9b 2b 60 02  sll  %o5, 2, %o5
a00da154:  98 03 c0 0c  add  %o7, %o4, %o4
a00da158:  9a 03 40 01  add  %o5, %g1, %o5
a00da15c:  c2 0b 3f d0  ldub  [ %o4 + -48 ], %g1
a00da160:  94 02 a0 01  inc  %o2
a00da164:  98 0a a0 ff  and  %o2, 0xff, %o4
a00da168:  c2 23 60 0c  st  %g1, [ %o5 + 0xc ]
a00da16c:  80 a3 00 18  cmp  %o4, %i0
a00da170:  0a bf ff f4  bcs  0xa00da140
a00da174:  98 0a a0 ff  and  %o2, 0xff, %o4
a00da178:  90 07 bf c8  add  %fp, -56, %o0
a00da17c:  92 10 00 18  mov  %i0, %o1
a00da180:  94 10 20 00  clr  %o2
a00da184:  7f ff fe 01  call  0xa00d9988
a00da188:  96 10 20 30  mov  0x30, %o3
a00da18c:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00da190:  d8 08 60 32  ldub  [ %g1 + 0x32 ], %o4	! 0xa8078832
a00da194:  9a 0c 20 ff  and  %l0, 0xff, %o5
a00da198:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a00da19c:  9a 03 40 18  add  %o5, %i0, %o5
a00da1a0:  99 2b 20 02  sll  %o4, 2, %o4
a00da1a4:  82 10 60 9c  or  %g1, 0x9c, %g1
a00da1a8:  c2 00 40 0c  ld  [ %g1 + %o4 ], %g1
a00da1ac:  9b 2b 60 02  sll  %o5, 2, %o5
a00da1b0:  9a 03 40 01  add  %o5, %g1, %o5
a00da1b4:  90 0a 20 ff  and  %o0, 0xff, %o0
a00da1b8:  d0 23 60 0c  st  %o0, [ %o5 + 0xc ]
a00da1bc:  10 80 00 29  b  0xa00da260
a00da1c0:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00da1c4:  80 a6 20 00  cmp  %i0, 0
a00da1c8:  02 80 00 14  be  0xa00da218
a00da1cc:  94 10 20 00  clr  %o2
a00da1d0:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a00da1d4:  92 10 60 9c  or  %g1, 0x9c, %o1	! 0xa807609c
a00da1d8:  96 0c 20 ff  and  %l0, 0xff, %o3
a00da1dc:  98 0a a0 ff  and  %o2, 0xff, %o4
a00da1e0:  c2 0c a0 32  ldub  [ %l2 + 0x32 ], %g1
a00da1e4:  9a 02 c0 0c  add  %o3, %o4, %o5
a00da1e8:  83 28 60 02  sll  %g1, 2, %g1
a00da1ec:  c2 02 40 01  ld  [ %o1 + %g1 ], %g1
a00da1f0:  9b 2b 60 02  sll  %o5, 2, %o5
a00da1f4:  98 03 c0 0c  add  %o7, %o4, %o4
a00da1f8:  9a 03 40 01  add  %o5, %g1, %o5
a00da1fc:  c2 0b 3f d0  ldub  [ %o4 + -48 ], %g1
a00da200:  94 02 a0 01  inc  %o2
a00da204:  98 0a a0 ff  and  %o2, 0xff, %o4
a00da208:  c2 23 60 cc  st  %g1, [ %o5 + 0xcc ]
a00da20c:  80 a3 00 18  cmp  %o4, %i0
a00da210:  0a bf ff f4  bcs  0xa00da1e0
a00da214:  98 0a a0 ff  and  %o2, 0xff, %o4
a00da218:  90 07 bf c8  add  %fp, -56, %o0
a00da21c:  92 10 00 18  mov  %i0, %o1
a00da220:  94 10 20 00  clr  %o2
a00da224:  7f ff fd d9  call  0xa00d9988
a00da228:  96 10 20 30  mov  0x30, %o3
a00da22c:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00da230:  d8 08 60 32  ldub  [ %g1 + 0x32 ], %o4	! 0xa8078832
a00da234:  9a 0c 20 ff  and  %l0, 0xff, %o5
a00da238:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a00da23c:  9a 03 40 18  add  %o5, %i0, %o5
a00da240:  99 2b 20 02  sll  %o4, 2, %o4
a00da244:  82 10 60 9c  or  %g1, 0x9c, %g1
a00da248:  c2 00 40 0c  ld  [ %g1 + %o4 ], %g1
a00da24c:  9b 2b 60 02  sll  %o5, 2, %o5
a00da250:  9a 03 40 01  add  %o5, %g1, %o5
a00da254:  90 0a 20 ff  and  %o0, 0xff, %o0
a00da258:  d0 23 60 cc  st  %o0, [ %o5 + 0xcc ]
a00da25c:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00da260:  da 08 60 32  ldub  [ %g1 + 0x32 ], %o5	! 0xa8078832
a00da264:  96 14 e0 0a  or  %l3, 0xa, %o3
a00da268:  9a 03 40 0d  add  %o5, %o5, %o5
a00da26c:  c2 12 c0 0d  lduh  [ %o3 + %o5 ], %g1
a00da270:  98 0c 60 ff  and  %l1, 0xff, %o4
a00da274:  82 00 40 0c  add  %g1, %o4, %g1
a00da278:  82 08 61 ff  and  %g1, 0x1ff, %g1
a00da27c:  c2 32 c0 0d  sth  %g1, [ %o3 + %o5 ]
a00da280:  81 c7 e0 08  ret
a00da284:  81 e8 00 00  restore
