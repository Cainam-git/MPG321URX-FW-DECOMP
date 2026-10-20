# leon2m FUN_a0139968 0xa0139968-0xa0139a30 (200 bytes)
a0139968:  9d e3 bf 90  save  %sp, -112, %sp
a013996c:  25 2a 00 b2  sethi  %hi(0xa802c800), %l2
a0139970:  da 0c a3 99  ldub  [ %l2 + 0x399 ], %o5	! 0xa802cb99
a0139974:  82 0e 20 ff  and  %i0, 0xff, %g1
a0139978:  80 a3 40 01  cmp  %o5, %g1
a013997c:  02 80 00 2a  be  0xa0139a24
a0139980:  92 10 3f ff  mov  -1, %o1
a0139984:  d2 27 bf f4  st  %o1, [ %fp + -12 ]
a0139988:  90 10 20 02  mov  2, %o0
a013998c:  92 10 20 20  mov  0x20, %o1
a0139990:  94 07 bf f4  add  %fp, -12, %o2
a0139994:  67 fd 4a cf  call  0x4008c4d0
a0139998:  96 10 20 01  mov  1, %o3
a013999c:  d0 07 bf f4  ld  [ %fp + -12 ], %o0
a01399a0:  80 a2 20 00  cmp  %o0, 0
a01399a4:  a2 0e 20 ff  and  %i0, 0xff, %l1
a01399a8:  02 80 00 10  be  0xa01399e8
a01399ac:  a0 10 20 64  mov  0x64, %l0
a01399b0:  67 fd 4d fc  call  0x4008d1a0
a01399b4:  90 10 20 01  mov  1, %o0
a01399b8:  90 10 20 02  mov  2, %o0
a01399bc:  92 10 20 20  mov  0x20, %o1
a01399c0:  94 07 bf f4  add  %fp, -12, %o2
a01399c4:  67 fd 4a c3  call  0x4008c4d0
a01399c8:  96 10 20 01  mov  1, %o3
a01399cc:  a0 04 3f ff  add  %l0, -1, %l0
a01399d0:  80 a4 20 00  cmp  %l0, 0
a01399d4:  02 80 00 10  be  0xa0139a14
a01399d8:  d4 07 bf f4  ld  [ %fp + -12 ], %o2
a01399dc:  80 a2 a0 00  cmp  %o2, 0
a01399e0:  12 bf ff f4  bne  0xa01399b0
a01399e4:  01 00 00 00  nop
a01399e8:  9e 0c 60 ff  and  %l1, 0xff, %o7
a01399ec:  21 08 00 00  sethi  %hi(0x20000000), %l0
a01399f0:  98 13 c0 10  or  %o7, %l0, %o4
a01399f4:  d8 27 bf f4  st  %o4, [ %fp + -12 ]
a01399f8:  90 10 20 02  mov  2, %o0
a01399fc:  92 10 20 20  mov  0x20, %o1
a0139a00:  94 07 bf f4  add  %fp, -12, %o2
a0139a04:  67 fd 4a fd  call  0x4008c5f8
a0139a08:  96 10 20 01  mov  1, %o3
a0139a0c:  10 80 00 07  b  0xa0139a28
a0139a10:  f0 2c a3 99  stb  %i0, [ %l2 + 0x399 ]
a0139a14:  d6 07 bf f4  ld  [ %fp + -12 ], %o3
a0139a18:  80 a2 e0 00  cmp  %o3, 0
a0139a1c:  02 bf ff f4  be  0xa01399ec
a0139a20:  9e 0c 60 ff  and  %l1, 0xff, %o7
a0139a24:  f0 2c a3 99  stb  %i0, [ %l2 + 0x399 ]
a0139a28:  81 c7 e0 08  ret
a0139a2c:  81 e8 00 00  restore
