# leon2m FUN_a00ad02c 0xa00ad02c-0xa00ad1c0 (404 bytes)  [FUN_a00ad1b8 = unreachable ret/restore tail, merged]
a00ad02c:  9d e3 bf 98  save  %sp, -104, %sp
a00ad030:  80 8e 60 ff  btst  0xff, %i1
a00ad034:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00ad038:  02 80 00 06  be  0xa00ad050
a00ad03c:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00ad040:  d0 0b 60 8d  ldub  [ %o5 + 0x8d ], %o0
a00ad044:  80 a2 00 10  cmp  %o0, %l0
a00ad048:  02 80 00 5b  be  0xa00ad1b4
a00ad04c:  01 00 00 00  nop
a00ad050:  67 ff 84 95  call  0x4008e2a4
a00ad054:  f0 2b 60 8d  stb  %i0, [ %o5 + 0x8d ]
a00ad058:  b0 10 20 05  mov  5, %i0
a00ad05c:  b2 10 20 05  mov  5, %i1
a00ad060:  94 10 00 19  mov  %i1, %o2
a00ad064:  90 10 20 00  clr  %o0
a00ad068:  92 10 20 13  mov  0x13, %o1
a00ad06c:  96 10 20 13  mov  0x13, %o3
a00ad070:  98 10 20 00  clr  %o4
a00ad074:  40 02 66 ab  call  0xa0146b20
a00ad078:  9a 10 20 00  clr  %o5
a00ad07c:  92 10 00 19  mov  %i1, %o1
a00ad080:  90 10 20 13  mov  0x13, %o0
a00ad084:  94 10 20 13  mov  0x13, %o2
a00ad088:  96 10 27 92  mov  0x792, %o3
a00ad08c:  98 10 20 00  clr  %o4
a00ad090:  40 02 66 7c  call  0xa0146a80
a00ad094:  b0 06 20 01  inc  %i0
a00ad098:  b2 0e 20 ff  and  %i0, 0xff, %i1
a00ad09c:  80 a6 60 14  cmp  %i1, 0x14
a00ad0a0:  08 bf ff f1  bleu  0xa00ad064
a00ad0a4:  94 10 00 19  mov  %i1, %o2
a00ad0a8:  96 10 20 02  mov  2, %o3
a00ad0ac:  98 10 20 00  clr  %o4
a00ad0b0:  9a 10 20 00  clr  %o5
a00ad0b4:  90 10 20 00  clr  %o0
a00ad0b8:  92 10 20 1c  mov  0x1c, %o1
a00ad0bc:  40 02 66 99  call  0xa0146b20
a00ad0c0:  94 10 20 15  mov  0x15, %o2
a00ad0c4:  94 10 20 00  clr  %o2
a00ad0c8:  90 10 20 05  mov  5, %o0
a00ad0cc:  40 02 66 dd  call  0xa0146c40
a00ad0d0:  92 10 20 00  clr  %o1
a00ad0d4:  90 10 20 92  mov  0x92, %o0
a00ad0d8:  40 02 66 9e  call  0xa0146b50
a00ad0dc:  92 10 20 00  clr  %o1
a00ad0e0:  90 10 20 00  clr  %o0
a00ad0e4:  40 02 66 a2  call  0xa0146b6c
a00ad0e8:  92 10 20 00  clr  %o1
a00ad0ec:  80 a4 20 00  cmp  %l0, 0
a00ad0f0:  12 80 00 31  bne  0xa00ad1b4
a00ad0f4:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00ad0f8:  a2 12 62 90  or  %o1, 0x290, %l1	! 0xa802d290
a00ad0fc:  10 80 00 1a  b  0xa00ad164
a00ad100:  b2 10 20 00  clr  %i1
a00ad104:  95 2e 60 03  sll  %i1, 3, %o2
a00ad108:  92 22 80 19  sub  %o2, %i1, %o1
a00ad10c:  83 2a 60 02  sll  %o1, 2, %g1
a00ad110:  90 00 40 19  add  %g1, %i1, %o0
a00ad114:  f2 0c 60 08  ldub  [ %l1 + 8 ], %i1
a00ad118:  9e 02 00 19  add  %o0, %i1, %o7
a00ad11c:  9b 2b e0 10  sll  %o7, 0x10, %o5
a00ad120:  19 00 06 23  sethi  %hi(0x188c00), %o4
a00ad124:  93 33 60 10  srl  %o5, 0x10, %o1
a00ad128:  7f ff d9 c7  call  0xa00a3844
a00ad12c:  90 13 21 a0  or  %o4, 0x1a0, %o0
a00ad130:  96 06 20 06  add  %i0, 6, %o3
a00ad134:  98 10 00 08  mov  %o0, %o4
a00ad138:  95 2a e0 10  sll  %o3, 0x10, %o2
a00ad13c:  95 32 a0 10  srl  %o2, 0x10, %o2
a00ad140:  90 10 20 00  clr  %o0
a00ad144:  92 10 20 14  mov  0x14, %o1
a00ad148:  96 10 20 01  mov  1, %o3
a00ad14c:  7f ff d8 16  call  0xa00a31a4
a00ad150:  9a 10 20 00  clr  %o5
a00ad154:  b2 0c 20 ff  and  %l0, 0xff, %i1
a00ad158:  80 a6 60 06  cmp  %i1, 6
a00ad15c:  18 80 00 10  bgu  0xa00ad19c
a00ad160:  01 00 00 00  nop
a00ad164:  7f ff f4 ef  call  0xa00aa520
a00ad168:  90 10 00 19  mov  %i1, %o0
a00ad16c:  80 8a 20 ff  btst  0xff, %o0
a00ad170:  a0 04 20 01  inc  %l0
a00ad174:  b0 06 40 19  add  %i1, %i1, %i0
a00ad178:  94 10 20 0d  mov  0xd, %o2
a00ad17c:  96 10 22 92  mov  0x292, %o3
a00ad180:  98 10 20 00  clr  %o4
a00ad184:  12 bf ff e0  bne  0xa00ad104
a00ad188:  90 10 20 14  mov  0x14, %o0
a00ad18c:  40 02 66 3d  call  0xa0146a80
a00ad190:  92 06 20 06  add  %i0, 6, %o1
a00ad194:  10 bf ff dd  b  0xa00ad108
a00ad198:  95 2e 60 03  sll  %i1, 3, %o2
a00ad19c:  40 00 25 fe  call  0xa00b6994
a00ad1a0:  01 00 00 00  nop
a00ad1a4:  40 00 26 0b  call  0xa00b69d0
a00ad1a8:  01 00 00 00  nop
a00ad1ac:  40 00 26 6f  call  0xa00b6b68
a00ad1b0:  81 e8 00 00  restore
a00ad1b4:  01 00 00 00  nop
a00ad1b8:  81 c7 e0 08  ret
a00ad1bc:  81 e8 00 00  restore
