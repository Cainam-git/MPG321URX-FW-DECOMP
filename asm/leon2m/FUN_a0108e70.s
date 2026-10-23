# leon2m FUN_a0108e70 0xa0108e70-0xa0108eec (124 bytes)
a0108e70:  90 0a 20 ff  and  %o0, 0xff, %o0
a0108e74:  80 a2 20 01  cmp  %o0, 1
a0108e78:  02 80 00 0a  be  0xa0108ea0
a0108e7c:  03 33 c0 46  sethi  %hi(0xcf011800), %g1
a0108e80:  04 80 00 15  ble  0xa0108ed4
a0108e84:  80 a2 20 02  cmp  %o0, 2
a0108e88:  02 80 00 10  be  0xa0108ec8
a0108e8c:  80 a2 20 03  cmp  %o0, 3
a0108e90:  12 80 00 15  bne  0xa0108ee4
a0108e94:  1b 33 c0 46  sethi  %hi(0xcf011800), %o5
a0108e98:  10 80 00 03  b  0xa0108ea4
a0108e9c:  98 13 62 ac  or  %o5, 0x2ac, %o4	! 0xcf011aac
a0108ea0:  98 10 62 a4  or  %g1, 0x2a4, %o4
a0108ea4:  d0 03 00 00  ld  [ %o4 ], %o0
a0108ea8:  82 0a 3f cf  and  %o0, -49, %g1
a0108eac:  c2 23 00 00  st  %g1, [ %o4 ]
a0108eb0:  9a 0a 60 03  and  %o1, 3, %o5
a0108eb4:  c2 03 00 00  ld  [ %o4 ], %g1
a0108eb8:  91 2b 60 04  sll  %o5, 4, %o0
a0108ebc:  92 10 40 08  or  %g1, %o0, %o1
a0108ec0:  d2 23 00 00  st  %o1, [ %o4 ]
a0108ec4:  30 80 00 08  b,a   0xa0108ee4
a0108ec8:  11 33 c0 46  sethi  %hi(0xcf011800), %o0
a0108ecc:  10 bf ff f6  b  0xa0108ea4
a0108ed0:  98 12 22 a8  or  %o0, 0x2a8, %o4	! 0xcf011aa8
a0108ed4:  19 33 c0 46  sethi  %hi(0xcf011800), %o4
a0108ed8:  80 a2 20 00  cmp  %o0, 0
a0108edc:  02 bf ff f2  be  0xa0108ea4
a0108ee0:  98 13 22 a0  or  %o4, 0x2a0, %o4
a0108ee4:  81 c3 e0 08  retl
a0108ee8:  01 00 00 00  nop
