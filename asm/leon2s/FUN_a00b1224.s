# leon2s FUN_a00b1224 0xa00b1224-0xa00b12c4 (160 bytes)  [FUN_a00b12bc = unreachable ret/restore tail, merged]
a00b1224:  9d e3 bf 98  save  %sp, -104, %sp
a00b1228:  82 0e 60 ff  and  %i1, 0xff, %g1
a00b122c:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00b1230:  92 10 20 55  mov  0x55, %o1
a00b1234:  94 10 20 40  mov  0x40, %o2
a00b1238:  96 10 20 01  mov  1, %o3
a00b123c:  b2 10 20 55  mov  0x55, %i1
a00b1240:  b4 10 20 10  mov  0x10, %i2
a00b1244:  b6 10 20 01  mov  1, %i3
a00b1248:  80 a0 60 01  cmp  %g1, 1
a00b124c:  02 80 00 17  be  0xa00b12a8
a00b1250:  90 10 00 10  mov  %l0, %o0
a00b1254:  80 a0 60 01  cmp  %g1, 1
a00b1258:  14 80 00 08  bg  0xa00b1278
a00b125c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00b1260:  b0 10 00 10  mov  %l0, %i0
a00b1264:  96 10 20 00  clr  %o3
a00b1268:  80 a0 60 00  cmp  %g1, 0
a00b126c:  02 80 00 0c  be  0xa00b129c
a00b1270:  b6 10 20 00  clr  %i3
a00b1274:  30 80 00 11  b,a   0xa00b12b8
a00b1278:  90 10 00 18  mov  %i0, %o0
a00b127c:  92 10 20 55  mov  0x55, %o1
a00b1280:  94 10 20 40  mov  0x40, %o2
a00b1284:  96 10 20 01  mov  1, %o3
a00b1288:  b2 10 20 55  mov  0x55, %i1
a00b128c:  b4 10 20 10  mov  0x10, %i2
a00b1290:  80 a0 60 02  cmp  %g1, 2
a00b1294:  12 80 00 09  bne  0xa00b12b8
a00b1298:  b6 10 20 00  clr  %i3
a00b129c:  7f ff d6 7f  call  0xa00a6c98
a00b12a0:  01 00 00 00  nop
a00b12a4:  30 80 00 03  b,a   0xa00b12b0
a00b12a8:  7f ff d6 7c  call  0xa00a6c98
a00b12ac:  b0 10 00 10  mov  %l0, %i0
a00b12b0:  7f ff d6 7a  call  0xa00a6c98
a00b12b4:  81 e8 00 00  restore
a00b12b8:  01 00 00 00  nop
a00b12bc:  81 c7 e0 08  ret
a00b12c0:  81 e8 00 00  restore
