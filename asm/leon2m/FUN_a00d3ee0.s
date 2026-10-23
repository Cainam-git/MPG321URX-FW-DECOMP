# leon2m FUN_a00d3ee0 0xa00d3ee0-0xa00d3f80 (160 bytes)
a00d3ee0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d3ee4:  9b 2a 20 03  sll  %o0, 3, %o5
a00d3ee8:  98 03 40 08  add  %o5, %o0, %o4
a00d3eec:  03 3f ff f6  sethi  %hi(0xffffd800), %g1
a00d3ef0:  9b 2b 20 04  sll  %o4, 4, %o5
a00d3ef4:  82 10 60 af  or  %g1, 0xaf, %g1
a00d3ef8:  9a 03 40 01  add  %o5, %g1, %o5
a00d3efc:  03 22 22 22  sethi  %hi(0x88888800), %g1
a00d3f00:  82 10 60 89  or  %g1, 0x89, %g1	! 0x88888889
a00d3f04:  80 53 40 01  umul  %o5, %g1, %g0
a00d3f08:  9b 40 00 00  rd  %y, %o5
a00d3f0c:  98 5a 22 f1  smul  %o0, 0x2f1, %o4
a00d3f10:  98 03 20 23  add  %o4, 0x23, %o4
a00d3f14:  03 3a 83 a8  sethi  %hi(0xea0ea000), %g1
a00d3f18:  99 33 20 01  srl  %o4, 1, %o4
a00d3f1c:  82 10 60 eb  or  %g1, 0xeb, %g1
a00d3f20:  80 53 00 01  umul  %o4, %g1, %g0
a00d3f24:  99 40 00 00  rd  %y, %o4
a00d3f28:  9b 33 60 04  srl  %o5, 4, %o5
a00d3f2c:  80 a2 20 45  cmp  %o0, 0x45
a00d3f30:  9a 03 63 6f  add  %o5, 0x36f, %o5
a00d3f34:  18 80 00 03  bgu  0xa00d3f40
a00d3f38:  99 33 20 05  srl  %o4, 5, %o4
a00d3f3c:  9a 03 20 7e  add  %o4, 0x7e, %o5
a00d3f40:  9b 2b 60 10  sll  %o5, 0x10, %o5
a00d3f44:  91 33 60 10  srl  %o5, 0x10, %o0
a00d3f48:  9a 5a 20 64  smul  %o0, 0x64, %o5
a00d3f4c:  19 3f ff f3  sethi  %hi(0xffffcc00), %o4
a00d3f50:  82 13 22 c8  or  %o4, 0x2c8, %g1	! 0xffffcec8
a00d3f54:  11 24 87 d9  sethi  %hi(0x921f6400), %o0
a00d3f58:  9a 03 40 01  add  %o5, %g1, %o5
a00d3f5c:  98 12 20 bf  or  %o0, 0xbf, %o4
a00d3f60:  80 5b 40 0c  smul  %o5, %o4, %g0
a00d3f64:  83 40 00 00  rd  %y, %g1
a00d3f68:  90 00 40 0d  add  %g1, %o5, %o0
a00d3f6c:  83 3a 20 09  sra  %o0, 9, %g1
a00d3f70:  99 3b 60 1f  sra  %o5, 0x1f, %o4
a00d3f74:  90 20 40 0c  sub  %g1, %o4, %o0
a00d3f78:  81 c3 e0 08  retl
a00d3f7c:  90 0a 20 ff  and  %o0, 0xff, %o0
