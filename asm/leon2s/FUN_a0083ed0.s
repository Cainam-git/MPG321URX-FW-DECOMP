# leon2s FUN_a0083ed0 0xa0083ed0-0xa0083f04 (52 bytes)
a0083ed0:  9d e3 bf 98  save  %sp, -104, %sp
a0083ed4:  7f ff ff fc  call  0xa0083ec4
a0083ed8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0083edc:  90 0a 20 ff  and  %o0, 0xff, %o0
a0083ee0:  80 a2 20 01  cmp  %o0, 1
a0083ee4:  12 80 00 04  bne  0xa0083ef4
a0083ee8:  80 a0 00 18  cmp  %g0, %i0
a0083eec:  10 80 00 03  b  0xa0083ef8
a0083ef0:  82 40 20 00  addx  %g0, 0, %g1
a0083ef4:  82 60 3f ff  subx  %g0, -1, %g1
a0083ef8:  b0 08 60 01  and  %g1, 1, %i0
a0083efc:  81 c7 e0 08  ret
a0083f00:  81 e8 00 00  restore
