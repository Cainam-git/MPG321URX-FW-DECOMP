# leon2s FUN_a006fb3c 0xa006fb3c-0xa006fbac (112 bytes)
a006fb3c:  da 02 00 00  ld  [ %o0 ], %o5
a006fb40:  03 3f c0 00  sethi  %hi(0xff000000), %g1
a006fb44:  82 2b 40 01  andn  %o5, %g1, %g1
a006fb48:  92 0a 60 ff  and  %o1, 0xff, %o1
a006fb4c:  c2 22 00 00  st  %g1, [ %o0 ]
a006fb50:  80 a2 60 00  cmp  %o1, 0
a006fb54:  98 10 20 00  clr  %o4
a006fb58:  02 80 00 10  be  0xa006fb98
a006fb5c:  96 10 20 00  clr  %o3
a006fb60:  82 0a e0 ff  and  %o3, 0xff, %g1
a006fb64:  83 28 60 02  sll  %g1, 2, %g1
a006fb68:  da 02 00 01  ld  [ %o0 + %g1 ], %o5
a006fb6c:  83 33 60 08  srl  %o5, 8, %g1
a006fb70:  98 1b 40 0c  xor  %o5, %o4, %o4
a006fb74:  98 1b 00 01  xor  %o4, %g1, %o4
a006fb78:  83 33 60 10  srl  %o5, 0x10, %g1
a006fb7c:  98 1b 00 01  xor  %o4, %g1, %o4
a006fb80:  96 02 e0 01  inc  %o3
a006fb84:  9b 33 60 18  srl  %o5, 0x18, %o5
a006fb88:  82 0a e0 ff  and  %o3, 0xff, %g1
a006fb8c:  80 a0 40 09  cmp  %g1, %o1
a006fb90:  0a bf ff f5  bcs  0xa006fb64
a006fb94:  98 1b 00 0d  xor  %o4, %o5, %o4
a006fb98:  c2 02 00 00  ld  [ %o0 ], %g1
a006fb9c:  9b 2b 20 18  sll  %o4, 0x18, %o5
a006fba0:  82 10 40 0d  or  %g1, %o5, %g1
a006fba4:  81 c3 e0 08  retl
a006fba8:  c2 22 00 00  st  %g1, [ %o0 ]
