# leon2m FUN_a01394a8 0xa01394a8-0xa0139558 (176 bytes)
a01394a8:  9d e3 bf 90  save  %sp, -112, %sp
a01394ac:  90 10 3f ff  mov  -1, %o0
a01394b0:  d0 27 bf f4  st  %o0, [ %fp + -12 ]
a01394b4:  90 10 20 02  mov  2, %o0
a01394b8:  92 10 20 20  mov  0x20, %o1
a01394bc:  94 07 bf f4  add  %fp, -12, %o2
a01394c0:  67 fd 4c 04  call  0x4008c4d0
a01394c4:  96 10 20 01  mov  1, %o3
a01394c8:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a01394cc:  80 a0 60 00  cmp  %g1, 0
a01394d0:  b0 0e 20 01  and  %i0, 1, %i0
a01394d4:  02 80 00 10  be  0xa0139514
a01394d8:  a0 10 20 64  mov  0x64, %l0
a01394dc:  67 fd 4f 31  call  0x4008d1a0
a01394e0:  90 10 20 01  mov  1, %o0
a01394e4:  90 10 20 02  mov  2, %o0
a01394e8:  92 10 20 20  mov  0x20, %o1
a01394ec:  94 07 bf f4  add  %fp, -12, %o2
a01394f0:  67 fd 4b f8  call  0x4008c4d0
a01394f4:  96 10 20 01  mov  1, %o3
a01394f8:  a0 04 3f ff  add  %l0, -1, %l0
a01394fc:  80 a4 20 00  cmp  %l0, 0
a0139500:  02 80 00 10  be  0xa0139540
a0139504:  d2 07 bf f4  ld  [ %fp + -12 ], %o1
a0139508:  80 a2 60 00  cmp  %o1, 0
a013950c:  12 bf ff f4  bne  0xa01394dc
a0139510:  01 00 00 00  nop
a0139514:  80 a0 00 18  cmp  %g0, %i0
a0139518:  98 40 20 00  addx  %g0, 0, %o4
a013951c:  1b 0e 00 00  sethi  %hi(0x38000000), %o5
a0139520:  96 13 00 0d  or  %o4, %o5, %o3
a0139524:  d6 27 bf f4  st  %o3, [ %fp + -12 ]
a0139528:  90 10 20 02  mov  2, %o0
a013952c:  92 10 20 20  mov  0x20, %o1
a0139530:  94 07 bf f4  add  %fp, -12, %o2
a0139534:  67 fd 4c 31  call  0x4008c5f8
a0139538:  96 10 20 01  mov  1, %o3
a013953c:  30 80 00 05  b,a   0xa0139550
a0139540:  d4 07 bf f4  ld  [ %fp + -12 ], %o2
a0139544:  80 a2 a0 00  cmp  %o2, 0
a0139548:  02 bf ff f4  be  0xa0139518
a013954c:  80 a0 00 18  cmp  %g0, %i0
a0139550:  81 c7 e0 08  ret
a0139554:  81 e8 00 00  restore
