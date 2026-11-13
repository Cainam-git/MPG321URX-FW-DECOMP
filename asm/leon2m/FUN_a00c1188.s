# leon2m FUN_a00c1188 0xa00c1188-0xa00c122c (164 bytes)
a00c1188:  9d e3 bf 98  save  %sp, -104, %sp
a00c118c:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00c1190:  80 a4 20 02  cmp  %l0, 2
a00c1194:  02 80 00 19  be  0xa00c11f8
a00c1198:  80 a4 20 03  cmp  %l0, 3
a00c119c:  02 80 00 1f  be  0xa00c1218
a00c11a0:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c11a4:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00c11a8:  96 08 60 ff  and  %g1, 0xff, %o3
a00c11ac:  94 02 ff d0  add  %o3, -48, %o2
a00c11b0:  82 0a a0 ff  and  %o2, 0xff, %g1
a00c11b4:  80 a0 60 01  cmp  %g1, 1
a00c11b8:  18 80 00 1b  bgu  0xa00c1224
a00c11bc:  b0 10 20 ff  mov  0xff, %i0
a00c11c0:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c11c4:  80 a0 60 01  cmp  %g1, 1
a00c11c8:  02 80 00 0f  be  0xa00c1204
a00c11cc:  98 13 62 90  or  %o5, 0x290, %o4
a00c11d0:  7f ff dd bf  call  0xa00b88cc
a00c11d4:  b0 10 20 00  clr  %i0
a00c11d8:  7f ff e6 25  call  0xa00baa6c
a00c11dc:  90 10 00 10  mov  %l0, %o0
a00c11e0:  7f ff e5 dc  call  0xa00ba950
a00c11e4:  90 10 00 10  mov  %l0, %o0
a00c11e8:  90 10 00 10  mov  %l0, %o0
a00c11ec:  7f ff e6 65  call  0xa00bab80
a00c11f0:  92 10 20 06  mov  6, %o1
a00c11f4:  30 80 00 0c  b,a   0xa00c1224
a00c11f8:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c11fc:  10 bf ff eb  b  0xa00c11a8
a00c1200:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00c1204:  b0 10 24 02  mov  0x402, %i0
a00c1208:  9e 10 27 50  mov  0x750, %o7
a00c120c:  f0 33 21 ae  sth  %i0, [ %o4 + 0x1ae ]
a00c1210:  10 bf ff f0  b  0xa00c11d0
a00c1214:  de 33 21 ac  sth  %o7, [ %o4 + 0x1ac ]
a00c1218:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c121c:  10 bf ff e3  b  0xa00c11a8
a00c1220:  c2 0a 20 a1  ldub  [ %o0 + 0xa1 ], %g1	! 0xa802d0a1
a00c1224:  81 c7 e0 08  ret
a00c1228:  81 e8 00 00  restore
