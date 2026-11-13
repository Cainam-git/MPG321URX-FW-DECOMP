# leon2m FUN_a00ab0e0 0xa00ab0e0-0xa00ab2a8 (456 bytes)
a00ab0e0:  9d e3 bf 90  save  %sp, -112, %sp
a00ab0e4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00ab0e8:  80 a6 20 02  cmp  %i0, 2
a00ab0ec:  02 80 00 51  be  0xa00ab230
a00ab0f0:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00ab0f4:  7f ff de 82  call  0xa00a2afc
a00ab0f8:  aa 10 20 2d  mov  0x2d, %l5
a00ab0fc:  90 10 21 2b  mov  0x12b, %o0
a00ab100:  40 02 6e 94  call  0xa0146b50
a00ab104:  92 10 20 00  clr  %o1
a00ab108:  90 10 20 02  mov  2, %o0
a00ab10c:  40 02 6e 98  call  0xa0146b6c
a00ab110:  92 10 20 00  clr  %o1
a00ab114:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00ab118:  19 00 06 3e  sethi  %hi(0x18f800), %o4
a00ab11c:  d2 0b e2 98  ldub  [ %o7 + 0x298 ], %o1
a00ab120:  7f ff e1 c9  call  0xa00a3844
a00ab124:  90 13 21 84  or  %o4, 0x184, %o0
a00ab128:  98 10 00 08  mov  %o0, %o4
a00ab12c:  90 10 20 00  clr  %o0
a00ab130:  92 10 20 2a  mov  0x2a, %o1
a00ab134:  94 10 20 06  mov  6, %o2
a00ab138:  96 10 20 08  mov  8, %o3
a00ab13c:  7f ff e0 1a  call  0xa00a31a4
a00ab140:  9a 10 20 00  clr  %o5
a00ab144:  a8 10 20 07  mov  7, %l4
a00ab148:  a4 10 20 00  clr  %l2
a00ab14c:  a2 10 20 00  clr  %l1
a00ab150:  80 a4 60 0c  cmp  %l1, 0xc
a00ab154:  a0 10 00 12  mov  %l2, %l0
a00ab158:  18 80 00 52  bgu  0xa00ab2a0
a00ab15c:  82 10 00 11  mov  %l1, %g1
a00ab160:  80 a0 00 11  cmp  %g0, %l1
a00ab164:  a6 60 3f ff  subx  %g0, -1, %l3
a00ab168:  80 a6 20 02  cmp  %i0, 2
a00ab16c:  02 80 00 17  be  0xa00ab1c8
a00ab170:  80 a0 60 06  cmp  %g1, 6
a00ab174:  96 0c 20 ff  and  %l0, 0xff, %o3
a00ab178:  94 22 c0 11  sub  %o3, %l1, %o2
a00ab17c:  9a 02 80 0a  add  %o2, %o2, %o5
a00ab180:  82 03 60 11  add  %o5, 0x11, %g1
a00ab184:  90 24 00 12  sub  %l0, %l2, %o0
a00ab188:  a6 02 00 14  add  %o0, %l4, %l3
a00ab18c:  b0 08 60 ff  and  %g1, 0xff, %i0
a00ab190:  92 10 20 01  mov  1, %o1
a00ab194:  f0 23 a0 5c  st  %i0, [ %sp + 0x5c ]
a00ab198:  98 0c e0 ff  and  %l3, 0xff, %o4
a00ab19c:  90 10 20 01  mov  1, %o0
a00ab1a0:  94 10 27 96  mov  0x796, %o2
a00ab1a4:  96 0d 60 ff  and  %l5, 0xff, %o3
a00ab1a8:  40 00 20 4f  call  0xa00b32e4
a00ab1ac:  9a 10 20 02  mov  2, %o5
a00ab1b0:  a0 04 20 01  inc  %l0
a00ab1b4:  92 0c 20 ff  and  %l0, 0xff, %o1
a00ab1b8:  80 a2 60 0c  cmp  %o1, 0xc
a00ab1bc:  08 bf ff ef  bleu  0xa00ab178
a00ab1c0:  96 0c 20 ff  and  %l0, 0xff, %o3
a00ab1c4:  30 80 00 37  b,a   0xa00ab2a0
a00ab1c8:  18 80 00 03  bgu  0xa00ab1d4
a00ab1cc:  9e 10 20 01  mov  1, %o7
a00ab1d0:  9e 10 20 00  clr  %o7
a00ab1d4:  9a 0c 20 ff  and  %l0, 0xff, %o5
a00ab1d8:  90 23 40 11  sub  %o5, %l1, %o0
a00ab1dc:  82 02 00 08  add  %o0, %o0, %g1
a00ab1e0:  92 00 60 11  add  %g1, 0x11, %o1
a00ab1e4:  b0 24 00 12  sub  %l0, %l2, %i0
a00ab1e8:  98 06 00 14  add  %i0, %l4, %o4
a00ab1ec:  82 0a 60 ff  and  %o1, 0xff, %g1
a00ab1f0:  98 0b 20 ff  and  %o4, 0xff, %o4
a00ab1f4:  90 10 20 01  mov  1, %o0
a00ab1f8:  92 10 20 01  mov  1, %o1
a00ab1fc:  94 10 27 96  mov  0x796, %o2
a00ab200:  96 0d 60 ff  and  %l5, 0xff, %o3
a00ab204:  9a 10 20 02  mov  2, %o5
a00ab208:  80 8c c0 0f  btst  %l3, %o7
a00ab20c:  12 80 00 25  bne  0xa00ab2a0
a00ab210:  a0 04 20 01  inc  %l0
a00ab214:  40 00 20 34  call  0xa00b32e4
a00ab218:  c2 23 a0 5c  st  %g1, [ %sp + 0x5c ]
a00ab21c:  82 0c 20 ff  and  %l0, 0xff, %g1
a00ab220:  80 a0 60 0c  cmp  %g1, 0xc
a00ab224:  08 bf ff e9  bleu  0xa00ab1c8
a00ab228:  80 a0 60 06  cmp  %g1, 6
a00ab22c:  30 80 00 1d  b,a   0xa00ab2a0
a00ab230:  9a 13 22 90  or  %o4, 0x290, %o5
a00ab234:  d0 0b 61 90  ldub  [ %o5 + 0x190 ], %o0
a00ab238:  83 32 20 02  srl  %o0, 2, %g1
a00ab23c:  80 a0 60 00  cmp  %g1, 0
a00ab240:  aa 10 20 0a  mov  0xa, %l5
a00ab244:  a8 10 20 05  mov  5, %l4
a00ab248:  12 80 00 04  bne  0xa00ab258
a00ab24c:  a4 10 20 07  mov  7, %l2
a00ab250:  a4 10 20 00  clr  %l2
a00ab254:  a8 10 20 08  mov  8, %l4
a00ab258:  a2 0c a0 ff  and  %l2, 0xff, %l1
a00ab25c:  80 a4 60 00  cmp  %l1, 0
a00ab260:  32 bf ff bd  bne,a   0xa00ab154
a00ab264:  80 a4 60 0c  cmp  %l1, 0xc
a00ab268:  96 13 22 90  or  %o4, 0x290, %o3
a00ab26c:  15 00 06 3e  sethi  %hi(0x18f800), %o2
a00ab270:  d2 0a e0 08  ldub  [ %o3 + 8 ], %o1
a00ab274:  7f ff e1 74  call  0xa00a3844
a00ab278:  90 12 a1 84  or  %o2, 0x184, %o0
a00ab27c:  98 10 00 08  mov  %o0, %o4
a00ab280:  90 10 20 00  clr  %o0
a00ab284:  92 10 20 08  mov  8, %o1
a00ab288:  94 10 20 06  mov  6, %o2
a00ab28c:  96 10 20 0d  mov  0xd, %o3
a00ab290:  7f ff df c5  call  0xa00a31a4
a00ab294:  9a 10 20 00  clr  %o5
a00ab298:  10 bf ff af  b  0xa00ab154
a00ab29c:  80 a4 60 0c  cmp  %l1, 0xc
a00ab2a0:  81 c7 e0 08  ret
a00ab2a4:  81 e8 00 00  restore
