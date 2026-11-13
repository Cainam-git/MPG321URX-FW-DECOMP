# leon2m FUN_a00c122c 0xa00c122c-0xa00c12b4 (136 bytes)
a00c122c:  9d e3 bf 98  save  %sp, -104, %sp
a00c1230:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c1234:  80 a6 20 02  cmp  %i0, 2
a00c1238:  02 80 00 17  be  0xa00c1294
a00c123c:  80 a6 20 03  cmp  %i0, 3
a00c1240:  02 80 00 18  be  0xa00c12a0
a00c1244:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c1248:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00c124c:  94 08 60 ff  and  %g1, 0xff, %o2
a00c1250:  98 02 bf d0  add  %o2, -48, %o4
a00c1254:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00c1258:  80 a3 60 01  cmp  %o5, 1
a00c125c:  18 80 00 14  bgu  0xa00c12ac
a00c1260:  82 10 20 ff  mov  0xff, %g1
a00c1264:  17 2a 00 b5  sethi  %hi(0xa802d400), %o3
a00c1268:  7f ff dd 99  call  0xa00b88cc
a00c126c:  d8 2a e0 07  stb  %o4, [ %o3 + 7 ]	! 0xa802d407
a00c1270:  7f ff e5 ff  call  0xa00baa6c
a00c1274:  90 10 00 18  mov  %i0, %o0
a00c1278:  7f ff e5 b6  call  0xa00ba950
a00c127c:  90 10 00 18  mov  %i0, %o0
a00c1280:  90 10 00 18  mov  %i0, %o0
a00c1284:  7f ff e6 3f  call  0xa00bab80
a00c1288:  92 10 20 06  mov  6, %o1
a00c128c:  10 80 00 08  b  0xa00c12ac
a00c1290:  82 10 20 00  clr  %g1
a00c1294:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c1298:  10 bf ff ed  b  0xa00c124c
a00c129c:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00c12a0:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c12a4:  10 bf ff ea  b  0xa00c124c
a00c12a8:  c2 0a 20 a1  ldub  [ %o0 + 0xa1 ], %g1	! 0xa802d0a1
a00c12ac:  81 c7 e0 08  ret
a00c12b0:  91 e8 00 01  restore  %g0, %g1, %o0
