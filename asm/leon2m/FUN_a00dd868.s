# leon2m FUN_a00dd868 0xa00dd868-0xa00dd8ac (68 bytes)
a00dd868:  da 0a 00 00  ldub  [ %o0 ], %o5
a00dd86c:  c2 0a 40 00  ldub  [ %o1 ], %g1
a00dd870:  99 2b 60 18  sll  %o5, 0x18, %o4
a00dd874:  97 28 60 18  sll  %g1, 0x18, %o3
a00dd878:  9b 3b 20 18  sra  %o4, 0x18, %o5
a00dd87c:  83 3a e0 18  sra  %o3, 0x18, %g1
a00dd880:  96 23 40 01  sub  %o5, %g1, %o3
a00dd884:  80 a0 00 0b  cmp  %g0, %o3
a00dd888:  98 60 3f ff  subx  %g0, -1, %o4
a00dd88c:  80 a0 00 0d  cmp  %g0, %o5
a00dd890:  82 40 20 00  addx  %g0, 0, %g1
a00dd894:  80 8b 00 01  btst  %o4, %g1
a00dd898:  90 02 20 01  inc  %o0
a00dd89c:  12 bf ff f3  bne  0xa00dd868
a00dd8a0:  92 02 60 01  inc  %o1
a00dd8a4:  81 c3 e0 08  retl
a00dd8a8:  90 10 00 0b  mov  %o3, %o0
