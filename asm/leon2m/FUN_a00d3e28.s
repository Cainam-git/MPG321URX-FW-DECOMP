# leon2m FUN_a00d3e28 0xa00d3e28-0xa00d3ee0 (184 bytes)
a00d3e28:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d3e2c:  17 2a 00 b5  sethi  %hi(0xa802d400), %o3
a00d3e30:  80 a2 20 45  cmp  %o0, 0x45
a00d3e34:  08 80 00 0f  bleu  0xa00d3e70
a00d3e38:  98 02 3f ba  add  %o0, -70, %o4
a00d3e3c:  c2 12 e0 6a  lduh  [ %o3 + 0x6a ], %g1
a00d3e40:  9a 10 23 ff  mov  0x3ff, %o5
a00d3e44:  90 23 40 01  sub  %o5, %g1, %o0
a00d3e48:  9a 5b 00 08  smul  %o4, %o0, %o5
a00d3e4c:  11 22 22 22  sethi  %hi(0x88888800), %o0
a00d3e50:  98 03 60 0f  add  %o5, 0xf, %o4
a00d3e54:  82 12 20 89  or  %o0, 0x89, %g1
a00d3e58:  80 53 00 01  umul  %o4, %g1, %g0
a00d3e5c:  91 40 00 00  rd  %y, %o0
a00d3e60:  9b 32 20 04  srl  %o0, 4, %o5
a00d3e64:  c2 12 e0 6a  lduh  [ %o3 + 0x6a ], %g1
a00d3e68:  10 80 00 0e  b  0xa00d3ea0
a00d3e6c:  9a 03 40 01  add  %o5, %g1, %o5
a00d3e70:  1b 2a 00 b5  sethi  %hi(0xa802d400), %o5
a00d3e74:  d6 13 60 6a  lduh  [ %o5 + 0x6a ], %o3	! 0xa802d46a
a00d3e78:  82 02 ff 82  add  %o3, -126, %g1
a00d3e7c:  98 5a 00 01  smul  %o0, %g1, %o4
a00d3e80:  9a 03 20 23  add  %o4, 0x23, %o5
a00d3e84:  17 3a 83 a8  sethi  %hi(0xea0ea000), %o3
a00d3e88:  91 33 60 01  srl  %o5, 1, %o0
a00d3e8c:  82 12 e0 eb  or  %o3, 0xeb, %g1
a00d3e90:  80 52 00 01  umul  %o0, %g1, %g0
a00d3e94:  99 40 00 00  rd  %y, %o4
a00d3e98:  97 33 20 05  srl  %o4, 5, %o3
a00d3e9c:  9a 02 e0 7e  add  %o3, 0x7e, %o5
a00d3ea0:  91 2b 60 10  sll  %o5, 0x10, %o0
a00d3ea4:  83 32 20 10  srl  %o0, 0x10, %g1
a00d3ea8:  17 3f ff f3  sethi  %hi(0xffffcc00), %o3
a00d3eac:  9a 58 60 64  smul  %g1, 0x64, %o5
a00d3eb0:  98 12 e2 c8  or  %o3, 0x2c8, %o4
a00d3eb4:  11 24 87 d9  sethi  %hi(0x921f6400), %o0
a00d3eb8:  96 03 40 0c  add  %o5, %o4, %o3
a00d3ebc:  82 12 20 bf  or  %o0, 0xbf, %g1
a00d3ec0:  80 5a c0 01  smul  %o3, %g1, %g0
a00d3ec4:  99 40 00 00  rd  %y, %o4
a00d3ec8:  90 03 00 0b  add  %o4, %o3, %o0
a00d3ecc:  99 3a 20 09  sra  %o0, 9, %o4
a00d3ed0:  83 3a e0 1f  sra  %o3, 0x1f, %g1
a00d3ed4:  90 23 00 01  sub  %o4, %g1, %o0
a00d3ed8:  81 c3 e0 08  retl
a00d3edc:  90 0a 20 ff  and  %o0, 0xff, %o0
