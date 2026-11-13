# leon2m FUN_a01411c8 0xa01411c8-0xa01411f8 (48 bytes)
a01411c8:  9d e3 bf 98  save  %sp, -104, %sp
a01411cc:  7f ff 5f b4  call  0xa011909c
a01411d0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a01411d4:  96 0a 20 ff  and  %o0, 0xff, %o3
a01411d8:  95 2e 20 04  sll  %i0, 4, %o2
a01411dc:  92 02 80 0b  add  %o2, %o3, %o1
a01411e0:  11 00 06 8d  sethi  %hi(0x1a3400), %o0
a01411e4:  b0 02 40 09  add  %o1, %o1, %i0
a01411e8:  82 12 22 48  or  %o0, 0x248, %g1
a01411ec:  f0 08 40 18  ldub  [ %g1 + %i0 ], %i0
a01411f0:  81 c7 e0 08  ret
a01411f4:  81 e8 00 00  restore
