# leon2s FUN_a006122c 0xa006122c-0xa0061280 (84 bytes)
a006122c:  03 30 03 00  sethi  %hi(0xc00c0000), %g1
a0061230:  96 10 60 14  or  %g1, 0x14, %o3	! 0xc00c0014
a0061234:  c2 02 c0 00  ld  [ %o3 ], %g1
a0061238:  80 88 60 20  btst  0x20, %g1
a006123c:  12 80 00 0c  bne  0xa006126c
a0061240:  98 10 20 00  clr  %o4
a0061244:  03 00 03 ff  sethi  %hi(0xffc00), %g1
a0061248:  9a 10 63 fe  or  %g1, 0x3fe, %o5	! 0xffffe
a006124c:  98 03 20 01  inc  %o4
a0061250:  80 a3 00 0d  cmp  %o4, %o5
a0061254:  38 80 00 07  bgu,a   0xa0061270
a0061258:  9a 0a 20 ff  and  %o0, 0xff, %o5
a006125c:  c2 02 c0 00  ld  [ %o3 ], %g1
a0061260:  80 88 60 20  btst  0x20, %g1
a0061264:  22 bf ff fb  be,a   0xa0061250
a0061268:  98 03 20 01  inc  %o4
a006126c:  9a 0a 20 ff  and  %o0, 0xff, %o5
a0061270:  03 30 03 00  sethi  %hi(0xc00c0000), %g1
a0061274:  da 20 40 00  st  %o5, [ %g1 ]
a0061278:  81 c3 e0 08  retl
a006127c:  01 00 00 00  nop
