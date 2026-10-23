# leon2m FUN_a00f11f4 0xa00f11f4-0xa00f1298 (164 bytes)
a00f11f4:  90 0a 20 ff  and  %o0, 0xff, %o0
a00f11f8:  80 a2 20 04  cmp  %o0, 4
a00f11fc:  02 80 00 10  be  0xa00f123c
a00f1200:  80 a2 20 03  cmp  %o0, 3
a00f1204:  18 80 00 23  bgu  0xa00f1290
a00f1208:  99 2a 60 10  sll  %o1, 0x10, %o4
a00f120c:  1b 2a 00 9a  sethi  %hi(0xa8026800), %o5
a00f1210:  92 13 62 7e  or  %o5, 0x27e, %o1	! 0xa8026a7e
a00f1214:  96 02 00 08  add  %o0, %o0, %o3
a00f1218:  d0 12 40 0b  lduh  [ %o1 + %o3 ], %o0
a00f121c:  83 33 20 10  srl  %o4, 0x10, %g1
a00f1220:  9a 02 00 01  add  %o0, %g1, %o5
a00f1224:  93 2b 60 02  sll  %o5, 2, %o1
a00f1228:  17 33 c0 00  sethi  %hi(0xcf000000), %o3
a00f122c:  90 12 40 0b  or  %o1, %o3, %o0
a00f1230:  98 0a a0 ff  and  %o2, 0xff, %o4
a00f1234:  d8 22 00 00  st  %o4, [ %o0 ]
a00f1238:  30 80 00 16  b,a   0xa00f1290
a00f123c:  9b 2a 60 10  sll  %o1, 0x10, %o5
a00f1240:  03 2a 00 9a  sethi  %hi(0xa8026800), %g1
a00f1244:  93 33 60 10  srl  %o5, 0x10, %o1
a00f1248:  98 10 62 7e  or  %g1, 0x27e, %o4
a00f124c:  94 0a a0 ff  and  %o2, 0xff, %o2
a00f1250:  90 10 20 00  clr  %o0
a00f1254:  96 10 20 00  clr  %o3
a00f1258:  1b 33 c0 00  sethi  %hi(0xcf000000), %o5
a00f125c:  82 02 c0 0b  add  %o3, %o3, %g1
a00f1260:  90 02 20 01  inc  %o0
a00f1264:  80 a2 e0 03  cmp  %o3, 3
a00f1268:  02 80 00 07  be  0xa00f1284
a00f126c:  96 0a 20 ff  and  %o0, 0xff, %o3
a00f1270:  c2 13 00 01  lduh  [ %o4 + %g1 ], %g1
a00f1274:  82 00 40 09  add  %g1, %o1, %g1
a00f1278:  83 28 60 02  sll  %g1, 2, %g1
a00f127c:  82 10 40 0d  or  %g1, %o5, %g1
a00f1280:  d4 20 40 00  st  %o2, [ %g1 ]
a00f1284:  80 a2 e0 03  cmp  %o3, 3
a00f1288:  08 bf ff f6  bleu  0xa00f1260
a00f128c:  82 02 c0 0b  add  %o3, %o3, %g1
a00f1290:  81 c3 e0 08  retl
a00f1294:  01 00 00 00  nop
