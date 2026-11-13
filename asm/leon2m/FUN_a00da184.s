# leon2m FUN_a00da184 0xa00da184-0xa00da254 (208 bytes)
a00da184:  9d e3 bf 98  save  %sp, -104, %sp
a00da188:  90 10 20 02  mov  2, %o0
a00da18c:  7f ff fe 1b  call  0xa00d99f8
a00da190:  92 10 20 01  mov  1, %o1
a00da194:  94 10 23 e8  mov  0x3e8, %o2
a00da198:  92 10 20 01  mov  1, %o1
a00da19c:  40 01 c1 ce  call  0xa014a8d4
a00da1a0:  90 10 20 04  mov  4, %o0
a00da1a4:  40 01 a8 ba  call  0xa014448c
a00da1a8:  90 10 20 00  clr  %o0
a00da1ac:  40 01 a9 14  call  0xa01445fc
a00da1b0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00da1b4:  b0 10 20 0d  mov  0xd, %i0
a00da1b8:  80 8a 20 ff  btst  0xff, %o0
a00da1bc:  02 80 00 0c  be  0xa00da1ec
a00da1c0:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00da1c4:  11 2a 00 b3  sethi  %hi(0xa802cc00), %o0
a00da1c8:  9a 14 22 90  or  %l0, 0x290, %o5
a00da1cc:  96 12 23 f4  or  %o0, 0x3f4, %o3
a00da1d0:  d8 03 60 ac  ld  [ %o5 + 0xac ], %o4
a00da1d4:  03 00 04 00  sethi  %hi(0x100000), %g1
a00da1d8:  13 00 00 04  sethi  %hi(0x1000), %o1
a00da1dc:  80 8b 00 01  btst  %o4, %g1
a00da1e0:  92 12 63 88  or  %o1, 0x388, %o1
a00da1e4:  12 80 00 17  bne  0xa00da240
a00da1e8:  90 10 20 14  mov  0x14, %o0
a00da1ec:  7f fe bf 60  call  0xa0089f6c
a00da1f0:  a0 14 22 90  or  %l0, 0x290, %l0
a00da1f4:  90 10 20 00  clr  %o0
a00da1f8:  40 01 b8 1c  call  0xa0148268
a00da1fc:  92 10 20 01  mov  1, %o1
a00da200:  90 10 20 01  mov  1, %o0
a00da204:  40 01 b8 19  call  0xa0148268
a00da208:  92 10 20 01  mov  1, %o1
a00da20c:  90 10 20 0f  mov  0xf, %o0
a00da210:  40 01 de 25  call  0xa0151aa4
a00da214:  92 10 20 01  mov  1, %o1
a00da218:  c2 04 20 a8  ld  [ %l0 + 0xa8 ], %g1
a00da21c:  93 30 60 07  srl  %g1, 7, %o1
a00da220:  92 0a 60 01  and  %o1, 1, %o1
a00da224:  40 01 c1 51  call  0xa014a768
a00da228:  90 10 20 0c  mov  0xc, %o0
a00da22c:  d6 04 20 a8  ld  [ %l0 + 0xa8 ], %o3
a00da230:  b3 32 e0 07  srl  %o3, 7, %i1
a00da234:  b2 0e 60 01  and  %i1, 1, %i1
a00da238:  40 01 c1 4c  call  0xa014a768
a00da23c:  81 e8 00 00  restore
a00da240:  de 12 e0 0a  lduh  [ %o3 + 0xa ], %o7
a00da244:  94 13 e0 40  or  %o7, 0x40, %o2
a00da248:  7f fe b1 da  call  0xa00869b0
a00da24c:  d4 32 e0 0a  sth  %o2, [ %o3 + 0xa ]
a00da250:  30 bf ff e7  b,a   0xa00da1ec
