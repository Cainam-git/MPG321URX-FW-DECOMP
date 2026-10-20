# leon2m FUN_a009cfd4 0xa009cfd4-0xa009d234 (608 bytes)
a009cfd4:  9d e3 bf 98  save  %sp, -104, %sp
a009cfd8:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a009cfdc:  d0 04 63 ec  ld  [ %l1 + 0x3ec ], %o0	! 0xa802afec
a009cfe0:  1b 09 24 92  sethi  %hi(0x24924800), %o5
a009cfe4:  92 02 3f 7a  add  %o0, -134, %o1
a009cfe8:  82 13 61 25  or  %o5, 0x125, %g1
a009cfec:  80 52 40 01  umul  %o1, %g1, %g0
a009cff0:  9f 40 00 00  rd  %y, %o7
a009cff4:  a4 22 40 0f  sub  %o1, %o7, %l2
a009cff8:  a1 34 a0 01  srl  %l2, 1, %l0
a009cffc:  98 03 c0 10  add  %o7, %l0, %o4
a009d000:  97 33 20 02  srl  %o4, 2, %o3
a009d004:  95 2a e0 03  sll  %o3, 3, %o2
a009d008:  9a 22 80 0b  sub  %o2, %o3, %o5
a009d00c:  90 22 40 0d  sub  %o1, %o5, %o0
a009d010:  40 00 30 eb  call  0xa00a93bc
a009d014:  90 0a 20 ff  and  %o0, 0xff, %o0
a009d018:  03 0a aa aa  sethi  %hi(0x2aaaa800), %g1
a009d01c:  a0 10 62 ab  or  %g1, 0x2ab, %l0	! 0x2aaaaaab
a009d020:  a4 10 20 00  clr  %l2
a009d024:  d0 14 63 ee  lduh  [ %l1 + 0x3ee ], %o0
a009d028:  9e 02 3f 7b  add  %o0, -133, %o7
a009d02c:  80 5b c0 10  smul  %o7, %l0, %g0
a009d030:  99 40 00 00  rd  %y, %o4
a009d034:  95 3b 20 01  sra  %o4, 1, %o2
a009d038:  97 3b e0 1f  sra  %o7, 0x1f, %o3
a009d03c:  9a 22 80 0b  sub  %o2, %o3, %o5
a009d040:  92 03 40 0d  add  %o5, %o5, %o1
a009d044:  82 02 40 0d  add  %o1, %o5, %g1
a009d048:  99 28 60 02  sll  %g1, 2, %o4
a009d04c:  94 23 c0 0c  sub  %o7, %o4, %o2
a009d050:  96 02 a0 86  add  %o2, 0x86, %o3
a009d054:  d6 24 63 ec  st  %o3, [ %l1 + 0x3ec ]
a009d058:  40 00 37 36  call  0xa00aad30
a009d05c:  90 0a a0 ff  and  %o2, 0xff, %o0
a009d060:  92 0a 20 ff  and  %o0, 0xff, %o1
a009d064:  80 a2 60 01  cmp  %o1, 1
a009d068:  32 bf ff f0  bne,a   0xa009d028
a009d06c:  d0 14 63 ee  lduh  [ %l1 + 0x3ee ], %o0
a009d070:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a009d074:  9a 14 22 90  or  %l0, 0x290, %o5	! 0xa802d290
a009d078:  d6 04 63 ec  ld  [ %l1 + 0x3ec ], %o3
a009d07c:  d2 0b 61 a3  ldub  [ %o5 + 0x1a3 ], %o1
a009d080:  9e 02 40 0d  add  %o1, %o5, %o7
a009d084:  82 02 e0 7a  add  %o3, 0x7a, %g1
a009d088:  80 a2 e0 8d  cmp  %o3, 0x8d
a009d08c:  02 80 00 57  be  0xa009d1e8
a009d090:  c2 2b e1 8a  stb  %g1, [ %o7 + 0x18a ]
a009d094:  80 a2 e0 86  cmp  %o3, 0x86
a009d098:  02 80 00 5b  be  0xa009d204
a009d09c:  01 00 00 00  nop
a009d0a0:  80 8c a0 ff  btst  0xff, %l2
a009d0a4:  12 80 00 31  bne  0xa009d168
a009d0a8:  25 2a 00 97  sethi  %hi(0xa8025c00), %l2
a009d0ac:  d0 04 63 ec  ld  [ %l1 + 0x3ec ], %o0
a009d0b0:  21 09 24 92  sethi  %hi(0x24924800), %l0
a009d0b4:  94 02 3f 7a  add  %o0, -134, %o2
a009d0b8:  a0 14 21 25  or  %l0, 0x125, %l0
a009d0bc:  80 52 80 10  umul  %o2, %l0, %g0
a009d0c0:  83 40 00 00  rd  %y, %g1
a009d0c4:  9e 22 80 01  sub  %o2, %g1, %o7
a009d0c8:  97 33 e0 01  srl  %o7, 1, %o3
a009d0cc:  98 00 40 0b  add  %g1, %o3, %o4
a009d0d0:  9b 33 20 02  srl  %o4, 2, %o5
a009d0d4:  93 2b 60 03  sll  %o5, 3, %o1
a009d0d8:  9e 22 40 0d  sub  %o1, %o5, %o7
a009d0dc:  96 22 80 0f  sub  %o2, %o7, %o3
a009d0e0:  90 0a e0 ff  and  %o3, 0xff, %o0
a009d0e4:  40 00 31 5b  call  0xa00a9650
a009d0e8:  92 10 20 01  mov  1, %o1
a009d0ec:  d4 0c a0 56  ldub  [ %l2 + 0x56 ], %o2
a009d0f0:  e4 04 63 ec  ld  [ %l1 + 0x3ec ], %l2
a009d0f4:  80 52 80 10  umul  %o2, %l0, %g0
a009d0f8:  99 40 00 00  rd  %y, %o4
a009d0fc:  96 04 bf 7a  add  %l2, -134, %o3
a009d100:  a2 22 80 0c  sub  %o2, %o4, %l1
a009d104:  80 52 c0 10  umul  %o3, %l0, %g0
a009d108:  a1 40 00 00  rd  %y, %l0
a009d10c:  83 34 60 01  srl  %l1, 1, %g1
a009d110:  90 22 c0 10  sub  %o3, %l0, %o0
a009d114:  92 03 00 01  add  %o4, %g1, %o1
a009d118:  9b 32 20 01  srl  %o0, 1, %o5
a009d11c:  9e 04 00 0d  add  %l0, %o5, %o7
a009d120:  99 32 60 02  srl  %o1, 2, %o4
a009d124:  a3 33 e0 02  srl  %o7, 2, %l1
a009d128:  a4 0b 20 ff  and  %o4, 0xff, %l2
a009d12c:  80 a4 80 11  cmp  %l2, %l1
a009d130:  02 80 00 04  be  0xa009d140
a009d134:  80 a2 c0 0a  cmp  %o3, %o2
a009d138:  40 00 6d e0  call  0xa00b88b8
a009d13c:  81 e8 00 00  restore
a009d140:  02 80 00 35  be  0xa009d214
a009d144:  97 2b 20 03  sll  %o4, 3, %o3
a009d148:  82 22 c0 0c  sub  %o3, %o4, %g1
a009d14c:  9a 22 80 01  sub  %o2, %g1, %o5
a009d150:  92 0b 60 ff  and  %o5, 0xff, %o1
a009d154:  90 10 20 01  mov  1, %o0
a009d158:  40 00 2b f9  call  0xa00a813c
a009d15c:  94 10 20 01  mov  1, %o2
a009d160:  40 00 6d d6  call  0xa00b88b8
a009d164:  81 e8 00 00  restore
a009d168:  82 14 22 90  or  %l0, 0x290, %g1
a009d16c:  da 08 61 a3  ldub  [ %g1 + 0x1a3 ], %o5
a009d170:  15 09 24 92  sethi  %hi(0x24924800), %o2
a009d174:  92 03 40 01  add  %o5, %g1, %o1
a009d178:  9e 12 a1 25  or  %o2, 0x125, %o7
a009d17c:  d6 0a 61 8a  ldub  [ %o1 + 0x18a ], %o3
a009d180:  d4 0c a0 56  ldub  [ %l2 + 0x56 ], %o2
a009d184:  80 52 80 0f  umul  %o2, %o7, %g0
a009d188:  93 40 00 00  rd  %y, %o1
a009d18c:  80 52 c0 0f  umul  %o3, %o7, %g0
a009d190:  83 40 00 00  rd  %y, %g1
a009d194:  98 22 c0 01  sub  %o3, %g1, %o4
a009d198:  90 22 80 09  sub  %o2, %o1, %o0
a009d19c:  a1 33 20 01  srl  %o4, 1, %l0
a009d1a0:  9b 32 20 01  srl  %o0, 1, %o5
a009d1a4:  9e 00 40 10  add  %g1, %l0, %o7
a009d1a8:  96 02 40 0d  add  %o1, %o5, %o3
a009d1ac:  91 33 e0 02  srl  %o7, 2, %o0
a009d1b0:  97 32 e0 02  srl  %o3, 2, %o3
a009d1b4:  98 0a 20 ff  and  %o0, 0xff, %o4
a009d1b8:  a0 0a e0 ff  and  %o3, 0xff, %l0
a009d1bc:  80 a3 00 10  cmp  %o4, %l0
a009d1c0:  32 bf ff bc  bne,a   0xa009d0b0
a009d1c4:  d0 04 63 ec  ld  [ %l1 + 0x3ec ], %o0
a009d1c8:  99 2a e0 03  sll  %o3, 3, %o4
a009d1cc:  90 23 00 0b  sub  %o4, %o3, %o0
a009d1d0:  a0 22 80 08  sub  %o2, %o0, %l0
a009d1d4:  90 0c 20 ff  and  %l0, 0xff, %o0
a009d1d8:  40 00 31 1e  call  0xa00a9650
a009d1dc:  92 10 20 00  clr  %o1
a009d1e0:  10 bf ff b4  b  0xa009d0b0
a009d1e4:  d0 04 63 ec  ld  [ %l1 + 0x3ec ], %o0
a009d1e8:  40 00 2e a8  call  0xa00a8c88
a009d1ec:  01 00 00 00  nop
a009d1f0:  90 10 20 01  mov  1, %o0	! 0x1
a009d1f4:  40 00 6a 66  call  0xa00b7b8c
a009d1f8:  a4 10 20 01  mov  1, %l2
a009d1fc:  10 bf ff aa  b  0xa009d0a4
a009d200:  80 8c a0 ff  btst  0xff, %l2
a009d204:  40 00 2e a1  call  0xa00a8c88
a009d208:  01 00 00 00  nop
a009d20c:  10 bf ff fa  b  0xa009d1f4
a009d210:  90 10 20 00  clr  %o0	! 0x0
a009d214:  93 2b 20 03  sll  %o4, 3, %o1
a009d218:  a4 22 40 0c  sub  %o1, %o4, %l2
a009d21c:  a2 22 80 12  sub  %o2, %l2, %l1
a009d220:  92 0c 60 ff  and  %l1, 0xff, %o1
a009d224:  90 10 20 01  mov  1, %o0
a009d228:  40 00 2b c5  call  0xa00a813c
a009d22c:  94 10 20 00  clr  %o2
a009d230:  30 bf ff cc  b,a   0xa009d160
