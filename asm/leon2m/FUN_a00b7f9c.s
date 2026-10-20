# leon2m FUN_a00b7f9c 0xa00b7f9c-0xa00b81a4 (468 bytes)
a00b7f9c:  9d e3 bf 98  save  %sp, -104, %sp
a00b7fa0:  90 10 20 00  clr  %o0
a00b7fa4:  40 02 3b 87  call  0xa0146dc0
a00b7fa8:  92 10 20 00  clr  %o1
a00b7fac:  94 10 20 00  clr  %o2
a00b7fb0:  90 10 20 08  mov  8, %o0
a00b7fb4:  40 02 3b 23  call  0xa0146c40
a00b7fb8:  92 10 20 00  clr  %o1
a00b7fbc:  92 10 20 24  mov  0x24, %o1
a00b7fc0:  33 2a 00 ac  sethi  %hi(0xa802b000), %i1
a00b7fc4:  d2 2e 60 8f  stb  %o1, [ %i1 + 0x8f ]	! 0xa802b08f
a00b7fc8:  90 10 20 00  clr  %o0
a00b7fcc:  40 02 3b 7d  call  0xa0146dc0
a00b7fd0:  92 10 20 01  mov  1, %o1
a00b7fd4:  25 2a 00 b3  sethi  %hi(0xa802cc00), %l2
a00b7fd8:  98 14 a3 f4  or  %l2, 0x3f4, %o4	! 0xa802cff4
a00b7fdc:  da 13 20 3e  lduh  [ %o4 + 0x3e ], %o5
a00b7fe0:  11 3f ff e0  sethi  %hi(0xffff8000), %o0
a00b7fe4:  82 2b 40 08  andn  %o5, %o0, %g1
a00b7fe8:  67 ff 58 af  call  0x4008e2a4
a00b7fec:  c2 33 20 3e  sth  %g1, [ %o4 + 0x3e ]
a00b7ff0:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00b7ff4:  80 a4 20 11  cmp  %l0, 0x11
a00b7ff8:  02 80 00 4a  be  0xa00b8120
a00b7ffc:  01 00 00 00  nop
a00b8000:  7f ff f4 36  call  0xa00b50d8
a00b8004:  90 10 20 03  mov  3, %o0	! 0x3
a00b8008:  90 10 20 00  clr  %o0
a00b800c:  40 02 3b 6d  call  0xa0146dc0
a00b8010:  92 10 20 00  clr  %o1
a00b8014:  90 10 20 08  mov  8, %o0
a00b8018:  92 10 20 00  clr  %o1
a00b801c:  40 02 3b 09  call  0xa0146c40
a00b8020:  94 10 20 00  clr  %o2
a00b8024:  96 10 20 00  clr  %o3
a00b8028:  98 10 20 00  clr  %o4
a00b802c:  90 10 20 00  clr  %o0
a00b8030:  92 10 20 00  clr  %o1
a00b8034:  40 02 39 85  call  0xa0146648
a00b8038:  94 10 20 00  clr  %o2
a00b803c:  90 10 20 0e  mov  0xe, %o0
a00b8040:  92 10 20 05  mov  5, %o1
a00b8044:  40 02 38 3e  call  0xa014613c
a00b8048:  94 10 20 00  clr  %o2
a00b804c:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00b8050:  9e 14 62 90  or  %l1, 0x290, %o7	! 0xa802d290
a00b8054:  d2 0b e0 0e  ldub  [ %o7 + 0xe ], %o1
a00b8058:  d0 0b e0 0d  ldub  [ %o7 + 0xd ], %o0
a00b805c:  40 02 39 2f  call  0xa0146518
a00b8060:  94 10 20 00  clr  %o2
a00b8064:  92 10 20 00  clr  %o1
a00b8068:  40 02 3a 92  call  0xa0146ab0
a00b806c:  90 10 27 92  mov  0x792, %o0
a00b8070:  40 02 38 26  call  0xa0146108
a00b8074:  90 10 20 00  clr  %o0
a00b8078:  90 10 20 00  clr  %o0
a00b807c:  7f ff b5 a6  call  0xa00a5714
a00b8080:  92 10 20 00  clr  %o1
a00b8084:  90 10 20 32  mov  0x32, %o0
a00b8088:  92 10 20 32  mov  0x32, %o1
a00b808c:  40 02 39 23  call  0xa0146518
a00b8090:  94 10 20 00  clr  %o2
a00b8094:  90 10 20 64  mov  0x64, %o0
a00b8098:  40 02 3a ae  call  0xa0146b50
a00b809c:  92 10 20 00  clr  %o1
a00b80a0:  90 10 20 02  mov  2, %o0
a00b80a4:  40 02 3a b2  call  0xa0146b6c
a00b80a8:  92 10 20 00  clr  %o1
a00b80ac:  90 10 27 92  mov  0x792, %o0
a00b80b0:  40 02 3a 80  call  0xa0146ab0
a00b80b4:  92 10 20 00  clr  %o1
a00b80b8:  82 04 3f ef  add  %l0, -17, %g1
a00b80bc:  80 a0 60 0d  cmp  %g1, 0xd
a00b80c0:  18 80 00 15  bgu  0xa00b8114
a00b80c4:  f0 2e 60 8f  stb  %i0, [ %i1 + 0x8f ]
a00b80c8:  33 00 01 4c  sethi  %hi(0x53000), %i1
a00b80cc:  a1 28 60 02  sll  %g1, 2, %l0
a00b80d0:  b0 16 62 ac  or  %i1, 0x2ac, %i0
a00b80d4:  d4 06 00 10  ld  [ %i0 + %l0 ], %o2
a00b80d8:  81 c2 80 00  jmp  %o2
a00b80dc:  01 00 00 00  nop
a00b80e0:  82 14 62 90  or  %l1, 0x290, %g1
a00b80e4:  19 00 06 4b  sethi  %hi(0x192c00), %o4
a00b80e8:  d2 08 60 08  ldub  [ %g1 + 8 ], %o1
a00b80ec:  90 13 21 8c  or  %o4, 0x18c, %o0
a00b80f0:  7f ff ad d5  call  0xa00a3844
a00b80f4:  01 00 00 00  nop
a00b80f8:  98 10 00 08  mov  %o0, %o4
a00b80fc:  90 10 20 01  mov  1, %o0
a00b8100:  92 10 20 01  mov  1, %o1
a00b8104:  94 10 20 02  mov  2, %o2
a00b8108:  96 10 20 0c  mov  0xc, %o3
a00b810c:  7f ff ac 26  call  0xa00a31a4
a00b8110:  9a 10 20 00  clr  %o5
a00b8114:  b0 10 20 01  mov  1, %i0
a00b8118:  40 02 3b 2a  call  0xa0146dc0
a00b811c:  93 e8 20 00  restore  %g0, 0, %o1
a00b8120:  7f ff f3 ee  call  0xa00b50d8
a00b8124:  90 10 20 04  mov  4, %o0
a00b8128:  90 10 20 00  clr  %o0
a00b812c:  40 02 3b 25  call  0xa0146dc0
a00b8130:  92 10 20 00  clr  %o1
a00b8134:  90 10 20 08  mov  8, %o0
a00b8138:  92 10 20 00  clr  %o1
a00b813c:  40 02 3a c1  call  0xa0146c40
a00b8140:  94 10 20 00  clr  %o2
a00b8144:  98 10 20 00  clr  %o4
a00b8148:  96 10 20 00  clr  %o3
a00b814c:  90 10 20 00  clr  %o0
a00b8150:  92 10 20 00  clr  %o1
a00b8154:  40 02 39 3d  call  0xa0146648
a00b8158:  94 10 20 00  clr  %o2
a00b815c:  90 10 20 08  mov  8, %o0
a00b8160:  92 10 20 03  mov  3, %o1
a00b8164:  40 02 37 f6  call  0xa014613c
a00b8168:  94 10 20 00  clr  %o2
a00b816c:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00b8170:  96 14 62 90  or  %l1, 0x290, %o3	! 0xa802d290
a00b8174:  d2 0a e0 0e  ldub  [ %o3 + 0xe ], %o1
a00b8178:  d0 0a e0 0d  ldub  [ %o3 + 0xd ], %o0
a00b817c:  40 02 38 e7  call  0xa0146518
a00b8180:  94 10 20 00  clr  %o2
a00b8184:  92 10 20 00  clr  %o1
a00b8188:  40 02 3a 4a  call  0xa0146ab0
a00b818c:  90 10 27 92  mov  0x792, %o0
a00b8190:  40 02 37 de  call  0xa0146108
a00b8194:  90 10 20 00  clr  %o0
a00b8198:  90 10 20 63  mov  0x63, %o0
a00b819c:  10 bf ff bc  b  0xa00b808c
a00b81a0:  92 10 20 62  mov  0x62, %o1
