# leon2s FUN_a00ab4a8 0xa00ab4a8-0xa00ab4f8 (80 bytes)
a00ab4a8:  9d e3 bf 98  save  %sp, -104, %sp
a00ab4ac:  21 33 c0 4c  sethi  %hi(0xcf013000), %l0
a00ab4b0:  98 14 22 80  or  %l0, 0x280, %o4	! 0xcf013280
a00ab4b4:  9a 10 20 01  mov  1, %o5
a00ab4b8:  c2 03 00 00  ld  [ %o4 ], %g1
a00ab4bc:  9b 2b 40 18  sll  %o5, %i0, %o5
a00ab4c0:  82 10 40 0d  or  %g1, %o5, %g1
a00ab4c4:  9a 14 22 90  or  %l0, 0x290, %o5
a00ab4c8:  c2 23 00 00  st  %g1, [ %o4 ]
a00ab4cc:  c2 03 40 00  ld  [ %o5 ], %g1
a00ab4d0:  82 08 7f f6  and  %g1, -10, %g1
a00ab4d4:  c2 23 40 00  st  %g1, [ %o5 ]
a00ab4d8:  40 00 18 af  call  0xa00b1794
a00ab4dc:  90 10 20 01  mov  1, %o0
a00ab4e0:  a0 14 22 84  or  %l0, 0x284, %l0
a00ab4e4:  c2 04 00 00  ld  [ %l0 ], %g1
a00ab4e8:  82 10 60 01  or  %g1, 1, %g1
a00ab4ec:  c2 24 00 00  st  %g1, [ %l0 ]
a00ab4f0:  81 c7 e0 08  ret
a00ab4f4:  81 e8 00 00  restore
