# leon2m FUN_a012a700 0xa012a700-0xa012a774 (116 bytes)
a012a700:  9d e3 bf 98  save  %sp, -104, %sp
a012a704:  97 2e 20 10  sll  %i0, 0x10, %o3
a012a708:  91 32 e0 10  srl  %o3, 0x10, %o0
a012a70c:  95 2a 20 03  sll  %o0, 3, %o2
a012a710:  92 22 80 08  sub  %o2, %o0, %o1
a012a714:  83 2a 60 07  sll  %o1, 7, %g1
a012a718:  1b 00 10 04  sethi  %hi(0x401000), %o5
a012a71c:  9e 00 40 08  add  %g1, %o0, %o7
a012a720:  b0 13 60 05  or  %o5, 5, %i0
a012a724:  80 53 c0 18  umul  %o7, %i0, %g0
a012a728:  95 40 00 00  rd  %y, %o2
a012a72c:  98 23 c0 0a  sub  %o7, %o2, %o4
a012a730:  97 33 20 01  srl  %o4, 1, %o3
a012a734:  92 02 80 0b  add  %o2, %o3, %o1
a012a738:  91 32 60 09  srl  %o1, 9, %o0
a012a73c:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a012a740:  9a 02 20 7e  add  %o0, 0x7e, %o5
a012a744:  c2 00 60 50  ld  [ %g1 + 0x50 ], %g1
a012a748:  da 37 a0 44  sth  %o5, [ %fp + 0x44 ]
a012a74c:  80 a0 60 00  cmp  %g1, 0
a012a750:  02 80 00 04  be  0xa012a760
a012a754:  90 07 a0 44  add  %fp, 0x44, %o0
a012a758:  9f c0 40 00  call  %g1
a012a75c:  01 00 00 00  nop
a012a760:  40 00 64 29  call  0xa0143804
a012a764:  d0 17 a0 44  lduh  [ %fp + 0x44 ], %o0
a012a768:  01 00 00 00  nop
a012a76c:  81 c7 e0 08  ret
a012a770:  81 e8 00 00  restore
