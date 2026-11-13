# leon2m FUN_a00c12b4 0xa00c12b4-0xa00c135c (168 bytes)
a00c12b4:  9d e3 bf 98  save  %sp, -104, %sp
a00c12b8:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00c12bc:  80 a4 20 02  cmp  %l0, 2
a00c12c0:  02 80 00 1f  be  0xa00c133c
a00c12c4:  80 a4 20 03  cmp  %l0, 3
a00c12c8:  02 80 00 20  be  0xa00c1348
a00c12cc:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c12d0:  da 0a 60 d9  ldub  [ %o1 + 0xd9 ], %o5	! 0xa802d0d9
a00c12d4:  9e 0b 60 ff  and  %o5, 0xff, %o7
a00c12d8:  98 03 ff d0  add  %o7, -48, %o4
a00c12dc:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00c12e0:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00c12e4:  96 16 22 90  or  %i0, 0x290, %o3	! 0xa802d290
a00c12e8:  94 0b 60 01  and  %o5, 1, %o2
a00c12ec:  99 2a a0 16  sll  %o2, 0x16, %o4
a00c12f0:  80 a3 60 01  cmp  %o5, 1
a00c12f4:  18 80 00 18  bgu  0xa00c1354
a00c12f8:  b0 10 20 ff  mov  0xff, %i0
a00c12fc:  da 02 e0 ac  ld  [ %o3 + 0xac ], %o5
a00c1300:  13 00 10 00  sethi  %hi(0x400000), %o1
a00c1304:  90 2b 40 09  andn  %o5, %o1, %o0
a00c1308:  82 12 00 0c  or  %o0, %o4, %g1
a00c130c:  7f ff 3f 33  call  0xa0090fd8
a00c1310:  c2 22 e0 ac  st  %g1, [ %o3 + 0xac ]
a00c1314:  7f ff dd 6e  call  0xa00b88cc
a00c1318:  b0 10 20 00  clr  %i0
a00c131c:  7f ff e5 d4  call  0xa00baa6c
a00c1320:  90 10 00 10  mov  %l0, %o0
a00c1324:  7f ff e5 8b  call  0xa00ba950
a00c1328:  90 10 00 10  mov  %l0, %o0
a00c132c:  90 10 00 10  mov  %l0, %o0
a00c1330:  7f ff e6 14  call  0xa00bab80
a00c1334:  92 10 20 06  mov  6, %o1
a00c1338:  30 80 00 07  b,a   0xa00c1354
a00c133c:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c1340:  10 bf ff e5  b  0xa00c12d4
a00c1344:  da 08 60 49  ldub  [ %g1 + 0x49 ], %o5	! 0xa802d049
a00c1348:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c134c:  10 bf ff e2  b  0xa00c12d4
a00c1350:  da 0a 20 a1  ldub  [ %o0 + 0xa1 ], %o5	! 0xa802d0a1
a00c1354:  81 c7 e0 08  ret
a00c1358:  81 e8 00 00  restore
