# leon2m FUN_a00be140 0xa00be140-0xa00be1c0 (128 bytes)
a00be140:  9d e3 bf 98  save  %sp, -104, %sp
a00be144:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00be148:  96 12 22 90  or  %o0, 0x290, %o3	! 0xa802d290
a00be14c:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00be150:  9a 13 60 78  or  %o5, 0x78, %o5	! 0xa802d078
a00be154:  98 10 20 30  mov  0x30, %o4
a00be158:  c2 0a e0 1f  ldub  [ %o3 + 0x1f ], %g1
a00be15c:  80 a0 60 00  cmp  %g1, 0
a00be160:  d8 2b 60 07  stb  %o4, [ %o5 + 7 ]
a00be164:  12 80 00 0e  bne  0xa00be19c
a00be168:  d8 2b 60 08  stb  %o4, [ %o5 + 8 ]
a00be16c:  d8 02 e0 ac  ld  [ %o3 + 0xac ], %o4
a00be170:  97 33 20 14  srl  %o4, 0x14, %o3
a00be174:  94 0a e0 01  and  %o3, 1, %o2
a00be178:  92 02 a0 30  add  %o2, 0x30, %o1
a00be17c:  d2 2b 60 09  stb  %o1, [ %o5 + 9 ]
a00be180:  7f ff f2 af  call  0xa00bac3c
a00be184:  90 10 20 4c  mov  0x4c, %o0
a00be188:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00be18c:  7f ff f1 f1  call  0xa00ba950
a00be190:  90 10 00 18  mov  %i0, %o0
a00be194:  7f ff f2 94  call  0xa00babe4
a00be198:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00be19c:  d8 2b 60 09  stb  %o4, [ %o5 + 9 ]
a00be1a0:  7f ff f2 a7  call  0xa00bac3c
a00be1a4:  90 10 20 4c  mov  0x4c, %o0
a00be1a8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00be1ac:  7f ff f1 e9  call  0xa00ba950
a00be1b0:  90 10 00 18  mov  %i0, %o0
a00be1b4:  7f ff f2 8c  call  0xa00babe4
a00be1b8:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00be1bc:  01 00 00 00  nop
