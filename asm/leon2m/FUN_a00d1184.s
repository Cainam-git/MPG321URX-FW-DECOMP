# leon2m FUN_a00d1184 0xa00d1184-0xa00d1220 (156 bytes)
a00d1184:  c2 0a 20 07  ldub  [ %o0 + 7 ], %g1
a00d1188:  80 a0 60 00  cmp  %g1, 0
a00d118c:  12 80 00 15  bne  0xa00d11e0
a00d1190:  80 a0 60 01  cmp  %g1, 1
a00d1194:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00d1198:  d0 03 62 90  ld  [ %o5 + 0x290 ], %o0	! 0xa802d290
a00d119c:  83 32 20 0e  srl  %o0, 0xe, %g1
a00d11a0:  82 08 60 01  and  %g1, 1, %g1
a00d11a4:  c2 2a 60 07  stb  %g1, [ %o1 + 7 ]
a00d11a8:  c2 0a 60 01  ldub  [ %o1 + 1 ], %g1
a00d11ac:  98 08 60 7f  and  %g1, 0x7f, %o4
a00d11b0:  94 83 20 02  addcc  %o4, 2, %o2
a00d11b4:  96 10 20 50  mov  0x50, %o3
a00d11b8:  02 80 00 18  be  0xa00d1218
a00d11bc:  98 10 20 00  clr  %o4
a00d11c0:  9a 10 20 00  clr  %o5
a00d11c4:  d0 0b 40 09  ldub  [ %o5 + %o1 ], %o0
a00d11c8:  98 03 20 01  inc  %o4
a00d11cc:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00d11d0:  80 a3 40 0a  cmp  %o5, %o2
a00d11d4:  0a bf ff fc  bcs  0xa00d11c4
a00d11d8:  96 1a c0 08  xor  %o3, %o0, %o3
a00d11dc:  30 80 00 0f  b,a   0xa00d1218
a00d11e0:  02 80 00 06  be  0xa00d11f8
a00d11e4:  80 a0 60 02  cmp  %g1, 2
a00d11e8:  02 80 00 08  be  0xa00d1208
a00d11ec:  82 10 3f e4  mov  -28, %g1
a00d11f0:  10 bf ff ee  b  0xa00d11a8
a00d11f4:  c2 2a 60 07  stb  %g1, [ %o1 + 7 ]
a00d11f8:  15 2a 00 b5  sethi  %hi(0xa802d400), %o2
a00d11fc:  da 0a a0 65  ldub  [ %o2 + 0x65 ], %o5	! 0xa802d465
a00d1200:  10 bf ff ea  b  0xa00d11a8
a00d1204:  da 2a 60 07  stb  %o5, [ %o1 + 7 ]
a00d1208:  17 2a 00 b5  sethi  %hi(0xa802d400), %o3
a00d120c:  da 0a e0 66  ldub  [ %o3 + 0x66 ], %o5	! 0xa802d466
a00d1210:  10 bf ff e6  b  0xa00d11a8
a00d1214:  da 2a 60 07  stb  %o5, [ %o1 + 7 ]
a00d1218:  81 c3 e0 08  retl
a00d121c:  d6 2a 60 08  stb  %o3, [ %o1 + 8 ]
