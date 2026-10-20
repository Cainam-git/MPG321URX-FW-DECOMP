# leon2m FUN_a002a5e4 0xa002a5e4-0xa002a614 (48 bytes)
a002a5e4:  9d e3 bf 98  save  %sp, -104, %sp
a002a5e8:  21 27 c0 80  sethi  %hi(0x9f020000), %l0
a002a5ec:  40 00 07 19  call  0xa002c250
a002a5f0:  90 14 20 64  or  %l0, 0x64, %o0	! 0x9f020064
a002a5f4:  92 0e 60 ff  and  %i1, 0xff, %o1
a002a5f8:  83 2a 40 18  sll  %o1, %i0, %g1
a002a5fc:  b3 28 60 10  sll  %g1, 0x10, %i1
a002a600:  b2 16 40 08  or  %i1, %o0, %i1
a002a604:  b0 14 20 64  or  %l0, 0x64, %i0
a002a608:  40 00 07 15  call  0xa002c25c
a002a60c:  81 e8 00 00  restore
a002a610:  01 00 00 00  nop
