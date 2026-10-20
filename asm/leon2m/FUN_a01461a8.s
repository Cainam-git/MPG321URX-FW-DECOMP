# leon2m FUN_a01461a8 0xa01461a8-0xa01461dc (52 bytes)
a01461a8:  9d e3 bf 90  save  %sp, -112, %sp
a01461ac:  d8 06 20 04  ld  [ %i0 + 4 ], %o4
a01461b0:  c2 16 00 00  lduh  [ %i0 ], %g1
a01461b4:  da 16 20 02  lduh  [ %i0 + 2 ], %o5
a01461b8:  c2 37 bf f0  sth  %g1, [ %fp + -16 ]
a01461bc:  da 37 bf f2  sth  %o5, [ %fp + -14 ]
a01461c0:  d8 27 bf f4  st  %o4, [ %fp + -12 ]
a01461c4:  92 0e 60 ff  and  %i1, 0xff, %o1
a01461c8:  7f ff 54 ca  call  0xa011b4f0
a01461cc:  90 07 bf f0  add  %fp, -16, %o0
a01461d0:  01 00 00 00  nop
a01461d4:  81 c7 e0 08  ret
a01461d8:  81 e8 00 00  restore
