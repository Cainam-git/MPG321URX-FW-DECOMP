# leon2m FUN_a002a880 0xa002a880-0xa002a910 (144 bytes)
a002a880:  9d e3 bf 98  save  %sp, -104, %sp
a002a884:  b3 2e 60 10  sll  %i1, 0x10, %i1
a002a888:  9e 10 00 18  mov  %i0, %o7
a002a88c:  9a 10 00 1a  mov  %i2, %o5
a002a890:  b3 36 60 10  srl  %i1, 0x10, %i1
a002a894:  b8 10 20 00  clr  %i4
a002a898:  83 3e 40 1c  sra  %i1, %i4, %g1
a002a89c:  ba 07 20 01  add  %i4, 1, %i5
a002a8a0:  80 88 60 01  btst  1, %g1
a002a8a4:  b5 2f 60 10  sll  %i5, 0x10, %i2
a002a8a8:  83 2f 20 10  sll  %i4, 0x10, %g1
a002a8ac:  b7 36 a0 10  srl  %i2, 0x10, %i3
a002a8b0:  12 80 00 06  bne  0xa002a8c8
a002a8b4:  b8 10 00 1d  mov  %i5, %i4
a002a8b8:  80 a6 e0 0f  cmp  %i3, 0xf
a002a8bc:  08 bf ff f8  bleu  0xa002a89c
a002a8c0:  83 3e 40 1c  sra  %i1, %i4, %g1
a002a8c4:  82 10 00 1a  mov  %i2, %g1
a002a8c8:  b1 30 60 10  srl  %g1, 0x10, %i0
a002a8cc:  80 a6 20 10  cmp  %i0, 0x10
a002a8d0:  02 80 00 0e  be  0xa002a908
a002a8d4:  80 a3 e0 0e  cmp  %o7, 0xe
a002a8d8:  18 80 00 0c  bgu  0xa002a908
a002a8dc:  39 00 06 64  sethi  %hi(0x199000), %i4
a002a8e0:  b6 17 22 78  or  %i4, 0x278, %i3	! 0x199278
a002a8e4:  f4 0e c0 0f  ldub  [ %i3 + %o7 ], %i2
a002a8e8:  80 a6 80 18  cmp  %i2, %i0
a002a8ec:  08 80 00 07  bleu  0xa002a908
a002a8f0:  b5 2b e0 04  sll  %o7, 4, %i2
a002a8f4:  ba 06 80 18  add  %i2, %i0, %i5
a002a8f8:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a002a8fc:  b1 2f 60 02  sll  %i5, 2, %i0
a002a900:  b2 10 61 70  or  %g1, 0x170, %i1
a002a904:  da 26 40 18  st  %o5, [ %i1 + %i0 ]
a002a908:  81 c7 e0 08  ret
a002a90c:  81 e8 00 00  restore
