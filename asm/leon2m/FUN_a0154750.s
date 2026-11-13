# leon2m FUN_a0154750 0xa0154750-0xa01547b4 (100 bytes)
a0154750:  9d e3 bf 98  save  %sp, -104, %sp
a0154754:  82 10 00 18  mov  %i0, %g1
a0154758:  ba 10 00 19  mov  %i1, %i5
a015475c:  c2 37 a0 44  sth  %g1, [ %fp + 0x44 ]
a0154760:  fa 37 a0 48  sth  %i5, [ %fp + 0x48 ]
a0154764:  03 00 06 a0  sethi  %hi(0x1a8000), %g1
a0154768:  b8 10 61 cf  or  %g1, 0x1cf, %i4	! 0x1a81cf
a015476c:  c2 17 a0 48  lduh  [ %fp + 0x48 ], %g1
a0154770:  83 28 60 10  sll  %g1, 0x10, %g1
a0154774:  b7 30 60 10  srl  %g1, 0x10, %i3
a0154778:  c2 17 a0 44  lduh  [ %fp + 0x44 ], %g1
a015477c:  83 28 60 10  sll  %g1, 0x10, %g1
a0154780:  bb 30 60 10  srl  %g1, 0x10, %i5
a0154784:  82 10 00 1d  mov  %i5, %g1
a0154788:  83 28 60 02  sll  %g1, 2, %g1
a015478c:  82 00 40 1d  add  %g1, %i5, %g1
a0154790:  83 28 60 02  sll  %g1, 2, %g1
a0154794:  82 00 40 1d  add  %g1, %i5, %g1
a0154798:  82 00 40 01  add  %g1, %g1, %g1
a015479c:  82 00 40 1c  add  %g1, %i4, %g1
a01547a0:  c2 08 40 1b  ldub  [ %g1 + %i3 ], %g1
a01547a4:  82 08 60 ff  and  %g1, 0xff, %g1
a01547a8:  b0 10 00 01  mov  %g1, %i0
a01547ac:  81 c7 e0 08  ret
a01547b0:  81 e8 00 00  restore
