# leon2m FUN_a0142ea8 0xa0142ea8-0xa0142ed0 (40 bytes)
a0142ea8:  9d e3 bf 98  save  %sp, -104, %sp
a0142eac:  94 0e 20 ff  and  %i0, 0xff, %o2
a0142eb0:  13 2a 00 b8  sethi  %hi(0xa802e000), %o1
a0142eb4:  90 5a a0 2a  smul  %o2, 0x2a, %o0
a0142eb8:  82 12 62 24  or  %o1, 0x224, %g1
a0142ebc:  67 fd 29 b3  call  0x4008d588
a0142ec0:  b0 02 00 01  add  %o0, %g1, %i0
a0142ec4:  d0 36 20 12  sth  %o0, [ %i0 + 0x12 ]
a0142ec8:  81 c7 e0 08  ret
a0142ecc:  81 e8 00 00  restore
