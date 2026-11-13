# leon2m FUN_a01396d8 0xa01396d8-0xa01397ec (276 bytes)
a01396d8:  9d e3 bf 90  save  %sp, -112, %sp
a01396dc:  90 10 20 02  mov  2, %o0
a01396e0:  c0 27 bf f4  clr  [ %fp + -12 ]
a01396e4:  92 10 20 34  mov  0x34, %o1
a01396e8:  94 07 bf f4  add  %fp, -12, %o2
a01396ec:  67 fd 4b 79  call  0x4008c4d0
a01396f0:  96 10 20 01  mov  1, %o3
a01396f4:  11 15 6a 80  sethi  %hi(0x55aa0000), %o0
a01396f8:  da 07 bf f4  ld  [ %fp + -12 ], %o5
a01396fc:  82 12 20 02  or  %o0, 2, %g1
a0139700:  80 a3 40 01  cmp  %o5, %g1
a0139704:  02 80 00 1f  be  0xa0139780
a0139708:  92 10 20 30  mov  0x30, %o1
a013970c:  03 15 6a 80  sethi  %hi(0x55aa0000), %g1
a0139710:  a0 10 60 02  or  %g1, 2, %l0	! 0x55aa0002
a0139714:  e0 27 bf f4  st  %l0, [ %fp + -12 ]
a0139718:  90 10 20 02  mov  2, %o0
a013971c:  92 10 20 30  mov  0x30, %o1
a0139720:  94 07 bf f4  add  %fp, -12, %o2
a0139724:  67 fd 4b b5  call  0x4008c5f8
a0139728:  96 10 20 01  mov  1, %o3
a013972c:  9e 10 20 01  mov  1, %o7
a0139730:  de 27 bf f4  st  %o7, [ %fp + -12 ]
a0139734:  a0 10 3f ff  mov  -1, %l0
a0139738:  90 10 20 02  mov  2, %o0
a013973c:  92 10 20 34  mov  0x34, %o1
a0139740:  94 07 bf f4  add  %fp, -12, %o2
a0139744:  67 fd 4b 63  call  0x4008c4d0
a0139748:  96 10 20 01  mov  1, %o3
a013974c:  90 04 3f ff  add  %l0, -1, %o0
a0139750:  a0 10 00 08  mov  %o0, %l0
a0139754:  01 00 00 00  nop
a0139758:  9b 2a 20 10  sll  %o0, 0x10, %o5
a013975c:  80 a3 60 00  cmp  %o5, 0
a0139760:  02 80 00 21  be  0xa01397e4
a0139764:  17 15 6a 80  sethi  %hi(0x55aa0000), %o3
a0139768:  d4 07 bf f4  ld  [ %fp + -12 ], %o2
a013976c:  92 12 e0 02  or  %o3, 2, %o1
a0139770:  80 a2 80 09  cmp  %o2, %o1
a0139774:  12 bf ff f2  bne  0xa013973c
a0139778:  90 10 20 02  mov  2, %o0
a013977c:  30 80 00 1a  b,a   0xa01397e4
a0139780:  c0 27 bf f4  clr  [ %fp + -12 ]
a0139784:  90 10 20 02  mov  2, %o0
a0139788:  94 07 bf f4  add  %fp, -12, %o2
a013978c:  67 fd 4b 9b  call  0x4008c5f8
a0139790:  96 10 20 01  mov  1, %o3
a0139794:  92 10 20 01  mov  1, %o1
a0139798:  d2 27 bf f4  st  %o1, [ %fp + -12 ]
a013979c:  a0 10 3f ff  mov  -1, %l0
a01397a0:  90 10 20 02  mov  2, %o0
a01397a4:  92 10 20 34  mov  0x34, %o1
a01397a8:  94 07 bf f4  add  %fp, -12, %o2
a01397ac:  67 fd 4b 49  call  0x4008c4d0
a01397b0:  96 10 20 01  mov  1, %o3
a01397b4:  96 04 3f ff  add  %l0, -1, %o3
a01397b8:  a0 10 00 0b  mov  %o3, %l0
a01397bc:  01 00 00 00  nop
a01397c0:  95 2a e0 10  sll  %o3, 0x10, %o2
a01397c4:  80 a2 a0 00  cmp  %o2, 0
a01397c8:  02 bf ff d1  be  0xa013970c
a01397cc:  d8 07 bf f4  ld  [ %fp + -12 ], %o4
a01397d0:  80 a3 20 00  cmp  %o4, 0
a01397d4:  12 bf ff f4  bne  0xa01397a4
a01397d8:  90 10 20 02  mov  2, %o0
a01397dc:  10 bf ff cd  b  0xa0139710
a01397e0:  03 15 6a 80  sethi  %hi(0x55aa0000), %g1
a01397e4:  81 c7 e0 08  ret
a01397e8:  81 e8 00 00  restore
