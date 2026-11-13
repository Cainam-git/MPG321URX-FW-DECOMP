# leon2m FUN_a01546ec 0xa01546ec-0xa0154750 (100 bytes)
a01546ec:  9d e3 bf 98  save  %sp, -104, %sp
a01546f0:  82 10 00 18  mov  %i0, %g1
a01546f4:  ba 10 00 19  mov  %i1, %i5
a01546f8:  c2 37 a0 44  sth  %g1, [ %fp + 0x44 ]
a01546fc:  fa 37 a0 48  sth  %i5, [ %fp + 0x48 ]
a0154700:  03 00 06 a0  sethi  %hi(0x1a8000), %g1
a0154704:  b8 10 60 7d  or  %g1, 0x7d, %i4	! 0x1a807d
a0154708:  c2 17 a0 48  lduh  [ %fp + 0x48 ], %g1
a015470c:  83 28 60 10  sll  %g1, 0x10, %g1
a0154710:  b7 30 60 10  srl  %g1, 0x10, %i3
a0154714:  c2 17 a0 44  lduh  [ %fp + 0x44 ], %g1
a0154718:  83 28 60 10  sll  %g1, 0x10, %g1
a015471c:  bb 30 60 10  srl  %g1, 0x10, %i5
a0154720:  82 10 00 1d  mov  %i5, %g1
a0154724:  82 00 40 01  add  %g1, %g1, %g1
a0154728:  82 00 40 1d  add  %g1, %i5, %g1
a015472c:  83 28 60 02  sll  %g1, 2, %g1
a0154730:  82 00 40 1d  add  %g1, %i5, %g1
a0154734:  82 00 40 01  add  %g1, %g1, %g1
a0154738:  82 00 40 1c  add  %g1, %i4, %g1
a015473c:  c2 08 40 1b  ldub  [ %g1 + %i3 ], %g1
a0154740:  82 08 60 ff  and  %g1, 0xff, %g1
a0154744:  b0 10 00 01  mov  %g1, %i0
a0154748:  81 c7 e0 08  ret
a015474c:  81 e8 00 00  restore
