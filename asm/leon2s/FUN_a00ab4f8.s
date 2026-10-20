# leon2s FUN_a00ab4f8 0xa00ab4f8-0xa00ab548 (80 bytes)
a00ab4f8:  9d e3 bf 98  save  %sp, -104, %sp
a00ab4fc:  21 33 c0 4c  sethi  %hi(0xcf013000), %l0
a00ab500:  98 14 22 80  or  %l0, 0x280, %o4	! 0xcf013280
a00ab504:  9a 10 20 01  mov  1, %o5
a00ab508:  c2 03 00 00  ld  [ %o4 ], %g1
a00ab50c:  9b 2b 40 18  sll  %o5, %i0, %o5
a00ab510:  82 10 40 0d  or  %g1, %o5, %g1
a00ab514:  9a 14 22 90  or  %l0, 0x290, %o5
a00ab518:  c2 23 00 00  st  %g1, [ %o4 ]
a00ab51c:  c2 03 40 00  ld  [ %o5 ], %g1
a00ab520:  82 10 60 09  or  %g1, 9, %g1
a00ab524:  c2 23 40 00  st  %g1, [ %o5 ]
a00ab528:  40 00 18 9b  call  0xa00b1794
a00ab52c:  90 10 20 01  mov  1, %o0
a00ab530:  a0 14 22 84  or  %l0, 0x284, %l0
a00ab534:  c2 04 00 00  ld  [ %l0 ], %g1
a00ab538:  82 08 7f fe  and  %g1, -2, %g1
a00ab53c:  c2 24 00 00  st  %g1, [ %l0 ]
a00ab540:  81 c7 e0 08  ret
a00ab544:  81 e8 00 00  restore
