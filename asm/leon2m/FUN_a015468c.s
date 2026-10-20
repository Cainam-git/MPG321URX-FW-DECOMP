# leon2m FUN_a015468c 0xa015468c-0xa01546ec (96 bytes)
a015468c:  9d e3 bf 98  save  %sp, -104, %sp
a0154690:  82 10 00 18  mov  %i0, %g1
a0154694:  ba 10 00 19  mov  %i1, %i5
a0154698:  c2 37 a0 44  sth  %g1, [ %fp + 0x44 ]
a015469c:  fa 37 a0 48  sth  %i5, [ %fp + 0x48 ]
a01546a0:  03 00 06 9e  sethi  %hi(0x1a7800), %g1
a01546a4:  b6 10 62 6e  or  %g1, 0x26e, %i3	! 0x1a7a6e
a01546a8:  c2 17 a0 48  lduh  [ %fp + 0x48 ], %g1
a01546ac:  83 28 60 10  sll  %g1, 0x10, %g1
a01546b0:  b9 30 60 10  srl  %g1, 0x10, %i4
a01546b4:  c2 17 a0 44  lduh  [ %fp + 0x44 ], %g1
a01546b8:  83 28 60 10  sll  %g1, 0x10, %g1
a01546bc:  bb 30 60 10  srl  %g1, 0x10, %i5
a01546c0:  82 10 00 1d  mov  %i5, %g1
a01546c4:  82 00 40 01  add  %g1, %g1, %g1
a01546c8:  82 00 40 1d  add  %g1, %i5, %g1
a01546cc:  83 28 60 02  sll  %g1, 2, %g1
a01546d0:  82 20 40 1d  sub  %g1, %i5, %g1
a01546d4:  82 00 40 1b  add  %g1, %i3, %g1
a01546d8:  c2 08 40 1c  ldub  [ %g1 + %i4 ], %g1
a01546dc:  82 08 60 ff  and  %g1, 0xff, %g1
a01546e0:  b0 10 00 01  mov  %g1, %i0
a01546e4:  81 c7 e0 08  ret
a01546e8:  81 e8 00 00  restore
