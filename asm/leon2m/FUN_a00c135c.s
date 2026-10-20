# leon2m FUN_a00c135c 0xa00c135c-0xa00c1400 (164 bytes)
a00c135c:  9d e3 bf 98  save  %sp, -104, %sp
a00c1360:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00c1364:  80 a4 20 02  cmp  %l0, 2
a00c1368:  02 80 00 1e  be  0xa00c13e0
a00c136c:  80 a4 20 03  cmp  %l0, 3
a00c1370:  02 80 00 1f  be  0xa00c13ec
a00c1374:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c1378:  da 0a 60 d9  ldub  [ %o1 + 0xd9 ], %o5	! 0xa802d0d9
a00c137c:  9e 0b 60 ff  and  %o5, 0xff, %o7
a00c1380:  98 03 ff d0  add  %o7, -48, %o4
a00c1384:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00c1388:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00c138c:  96 16 22 90  or  %i0, 0x290, %o3	! 0xa802d290
a00c1390:  94 0b 60 01  and  %o5, 1, %o2
a00c1394:  99 2a a0 0f  sll  %o2, 0xf, %o4
a00c1398:  80 a3 60 01  cmp  %o5, 1
a00c139c:  18 80 00 17  bgu  0xa00c13f8
a00c13a0:  b0 10 20 ff  mov  0xff, %i0
a00c13a4:  da 02 e0 a8  ld  [ %o3 + 0xa8 ], %o5
a00c13a8:  13 00 00 20  sethi  %hi(0x8000), %o1
a00c13ac:  90 2b 40 09  andn  %o5, %o1, %o0
a00c13b0:  82 12 00 0c  or  %o0, %o4, %g1
a00c13b4:  7f ff dd 46  call  0xa00b88cc
a00c13b8:  c2 22 e0 a8  st  %g1, [ %o3 + 0xa8 ]
a00c13bc:  7f ff e5 ac  call  0xa00baa6c
a00c13c0:  90 10 00 10  mov  %l0, %o0
a00c13c4:  7f ff e5 63  call  0xa00ba950
a00c13c8:  90 10 00 10  mov  %l0, %o0
a00c13cc:  90 10 00 10  mov  %l0, %o0
a00c13d0:  7f ff e5 ec  call  0xa00bab80
a00c13d4:  92 10 20 06  mov  6, %o1
a00c13d8:  10 80 00 08  b  0xa00c13f8
a00c13dc:  b0 10 20 00  clr  %i0
a00c13e0:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c13e4:  10 bf ff e6  b  0xa00c137c
a00c13e8:  da 08 60 49  ldub  [ %g1 + 0x49 ], %o5	! 0xa802d049
a00c13ec:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c13f0:  10 bf ff e3  b  0xa00c137c
a00c13f4:  da 0a 20 a1  ldub  [ %o0 + 0xa1 ], %o5	! 0xa802d0a1
a00c13f8:  81 c7 e0 08  ret
a00c13fc:  81 e8 00 00  restore
