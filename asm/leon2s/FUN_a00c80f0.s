# leon2s FUN_a00c80f0 0xa00c80f0-0xa00c81f8 (264 bytes)
a00c80f0:  9d e3 bf 98  save  %sp, -104, %sp
a00c80f4:  a3 2f 20 10  sll  %i4, 0x10, %l1
a00c80f8:  a5 34 60 10  srl  %l1, 0x10, %l2
a00c80fc:  a6 10 00 18  mov  %i0, %l3
a00c8100:  80 a4 a0 00  cmp  %l2, 0
a00c8104:  02 80 00 3b  be  0xa00c81f0
a00c8108:  b0 10 20 01  mov  1, %i0
a00c810c:  a0 0c e0 ff  and  %l3, 0xff, %l0
a00c8110:  96 0e a0 ff  and  %i2, 0xff, %o3
a00c8114:  90 10 00 10  mov  %l0, %o0
a00c8118:  92 10 20 00  clr  %o1
a00c811c:  40 3b bf ce  call  0xa0fb8054
a00c8120:  94 10 20 ed  mov  0xed, %o2
a00c8124:  90 10 00 10  mov  %l0, %o0
a00c8128:  92 10 20 00  clr  %o1
a00c812c:  94 10 20 ee  mov  0xee, %o2
a00c8130:  40 3b bf c9  call  0xa0fb8054
a00c8134:  96 10 20 00  clr  %o3
a00c8138:  90 10 00 10  mov  %l0, %o0
a00c813c:  96 0e e0 ff  and  %i3, 0xff, %o3
a00c8140:  92 10 20 00  clr  %o1
a00c8144:  40 3b bf c4  call  0xa0fb8054
a00c8148:  94 10 20 ef  mov  0xef, %o2
a00c814c:  90 10 00 10  mov  %l0, %o0
a00c8150:  92 10 20 00  clr  %o1
a00c8154:  94 10 20 f0  mov  0xf0, %o2
a00c8158:  40 3b bf bf  call  0xa0fb8054
a00c815c:  96 0f 20 ff  and  %i4, 0xff, %o3
a00c8160:  97 34 60 18  srl  %l1, 0x18, %o3
a00c8164:  90 10 00 10  mov  %l0, %o0
a00c8168:  92 10 20 00  clr  %o1
a00c816c:  40 3b bf ba  call  0xa0fb8054
a00c8170:  94 10 20 f1  mov  0xf1, %o2
a00c8174:  90 10 00 10  mov  %l0, %o0
a00c8178:  92 10 20 00  clr  %o1
a00c817c:  94 10 20 f3  mov  0xf3, %o2
a00c8180:  40 3b bf b5  call  0xa0fb8054
a00c8184:  96 10 20 07  mov  7, %o3
a00c8188:  80 a4 a0 00  cmp  %l2, 0
a00c818c:  02 80 00 16  be  0xa00c81e4
a00c8190:  a2 10 20 00  clr  %l1
a00c8194:  a0 0c e0 ff  and  %l3, 0xff, %l0
a00c8198:  d6 0e 40 00  ldub  [ %i1 ], %o3
a00c819c:  90 10 00 10  mov  %l0, %o0
a00c81a0:  92 10 20 00  clr  %o1
a00c81a4:  40 3b bf ac  call  0xa0fb8054
a00c81a8:  94 10 20 f4  mov  0xf4, %o2
a00c81ac:  b2 06 60 01  inc  %i1
a00c81b0:  90 10 00 10  mov  %l0, %o0
a00c81b4:  92 10 20 00  clr  %o1
a00c81b8:  40 3b bf 88  call  0xa0fb7fd8
a00c81bc:  94 10 20 f2  mov  0xf2, %o2
a00c81c0:  80 8a 20 08  btst  8, %o0
a00c81c4:  12 bf ff fc  bne  0xa00c81b4
a00c81c8:  90 10 00 10  mov  %l0, %o0
a00c81cc:  98 04 60 01  add  %l1, 1, %o4
a00c81d0:  9b 2b 20 10  sll  %o4, 0x10, %o5
a00c81d4:  83 2f 20 10  sll  %i4, 0x10, %g1
a00c81d8:  80 a0 40 0d  cmp  %g1, %o5
a00c81dc:  18 bf ff ee  bgu  0xa00c8194
a00c81e0:  a2 10 00 0c  mov  %o4, %l1
a00c81e4:  40 3b e5 6c  call  0xa0fc1794
a00c81e8:  90 10 20 02  mov  2, %o0
a00c81ec:  b0 10 20 00  clr  %i0
a00c81f0:  81 c7 e0 08  ret
a00c81f4:  81 e8 00 00  restore
