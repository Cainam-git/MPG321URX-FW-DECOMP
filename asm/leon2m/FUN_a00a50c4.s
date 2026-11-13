# leon2m FUN_a00a50c4 0xa00a50c4-0xa00a5218 (340 bytes)
a00a50c4:  9d e3 bf 98  save  %sp, -104, %sp
a00a50c8:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00a50cc:  a0 10 62 90  or  %g1, 0x290, %l0	! 0xa802d290
a00a50d0:  da 0c 20 4a  ldub  [ %l0 + 0x4a ], %o5
a00a50d4:  80 a3 60 01  cmp  %o5, 1
a00a50d8:  12 80 00 4b  bne  0xa00a5204
a00a50dc:  23 2a 00 ac  sethi  %hi(0xa802b000), %l1
a00a50e0:  c0 2c 20 4a  clrb  [ %l0 + 0x4a ]
a00a50e4:  40 00 c3 72  call  0xa00d5eac
a00a50e8:  90 10 20 00  clr  %o0
a00a50ec:  e0 0c 20 4a  ldub  [ %l0 + 0x4a ], %l0
a00a50f0:  90 10 20 05  mov  5, %o0
a00a50f4:  92 10 20 08  mov  8, %o1
a00a50f8:  94 10 20 04  mov  4, %o2
a00a50fc:  96 10 27 92  mov  0x792, %o3
a00a5100:  40 02 86 60  call  0xa0146a80
a00a5104:  98 10 20 00  clr  %o4
a00a5108:  a2 94 20 00  orcc  %l0, 0, %l1
a00a510c:  02 80 00 22  be  0xa00a5194
a00a5110:  a0 10 20 00  clr  %l0
a00a5114:  96 0c 20 ff  and  %l0, 0xff, %o3
a00a5118:  94 02 e0 09  add  %o3, 9, %o2
a00a511c:  93 2a a0 10  sll  %o2, 0x10, %o1
a00a5120:  98 04 20 1e  add  %l0, 0x1e, %o4
a00a5124:  90 10 20 00  clr  %o0
a00a5128:  93 32 60 10  srl  %o1, 0x10, %o1
a00a512c:  98 0b 20 ff  and  %o4, 0xff, %o4
a00a5130:  94 10 20 08  mov  8, %o2
a00a5134:  96 10 20 01  mov  1, %o3
a00a5138:  40 02 86 7a  call  0xa0146b20
a00a513c:  9a 10 20 00  clr  %o5
a00a5140:  a0 04 20 01  inc  %l0
a00a5144:  90 0c 20 ff  and  %l0, 0xff, %o0
a00a5148:  80 a2 20 03  cmp  %o0, 3
a00a514c:  08 bf ff f3  bleu  0xa00a5118
a00a5150:  96 0c 20 ff  and  %l0, 0xff, %o3
a00a5154:  80 a4 60 00  cmp  %l1, 0
a00a5158:  12 80 00 21  bne  0xa00a51dc
a00a515c:  90 10 20 03  mov  3, %o0
a00a5160:  92 10 20 08  mov  8, %o1
a00a5164:  94 10 20 05  mov  5, %o2
a00a5168:  96 10 27 92  mov  0x792, %o3
a00a516c:  40 02 86 45  call  0xa0146a80
a00a5170:  98 10 20 00  clr  %o4
a00a5174:  90 10 20 0e  mov  0xe, %o0
a00a5178:  92 10 20 08  mov  8, %o1
a00a517c:  94 10 20 05  mov  5, %o2
a00a5180:  96 10 29 92  mov  0x992, %o3
a00a5184:  40 02 86 3f  call  0xa0146a80
a00a5188:  98 10 20 00  clr  %o4
a00a518c:  10 80 00 1e  b  0xa00a5204
a00a5190:  23 2a 00 ac  sethi  %hi(0xa802b000), %l1
a00a5194:  98 0c 20 ff  and  %l0, 0xff, %o4
a00a5198:  90 03 20 09  add  %o4, 9, %o0
a00a519c:  9a 04 20 22  add  %l0, 0x22, %o5
a00a51a0:  83 2a 20 10  sll  %o0, 0x10, %g1
a00a51a4:  98 0b 60 ff  and  %o5, 0xff, %o4
a00a51a8:  93 30 60 10  srl  %g1, 0x10, %o1
a00a51ac:  90 10 20 00  clr  %o0
a00a51b0:  94 10 20 08  mov  8, %o2
a00a51b4:  96 10 20 01  mov  1, %o3
a00a51b8:  40 02 86 5a  call  0xa0146b20
a00a51bc:  9a 10 20 00  clr  %o5
a00a51c0:  a0 04 20 01  inc  %l0
a00a51c4:  9e 0c 20 ff  and  %l0, 0xff, %o7
a00a51c8:  80 a3 e0 03  cmp  %o7, 3
a00a51cc:  08 bf ff f3  bleu  0xa00a5198
a00a51d0:  98 0c 20 ff  and  %l0, 0xff, %o4
a00a51d4:  10 bf ff e1  b  0xa00a5158
a00a51d8:  80 a4 60 00  cmp  %l1, 0
a00a51dc:  92 10 20 08  mov  8, %o1
a00a51e0:  94 10 20 05  mov  5, %o2
a00a51e4:  96 10 29 92  mov  0x992, %o3
a00a51e8:  40 02 86 26  call  0xa0146a80
a00a51ec:  98 10 20 00  clr  %o4
a00a51f0:  90 10 20 0e  mov  0xe, %o0
a00a51f4:  92 10 20 08  mov  8, %o1
a00a51f8:  94 10 20 05  mov  5, %o2
a00a51fc:  10 bf ff e2  b  0xa00a5184
a00a5200:  96 10 27 92  mov  0x792, %o3
a00a5204:  d4 0c 60 8e  ldub  [ %l1 + 0x8e ], %o2
a00a5208:  92 12 a0 02  or  %o2, 2, %o1
a00a520c:  d2 2c 60 8e  stb  %o1, [ %l1 + 0x8e ]
a00a5210:  81 c7 e0 08  ret
a00a5214:  81 e8 00 00  restore
