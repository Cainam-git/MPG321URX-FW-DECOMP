# leon2m FUN_a015e8b0 0xa015e8b0-0xa015e928 (120 bytes)
a015e8b0:  9d e3 bf 98  save  %sp, -104, %sp
a015e8b4:  a0 10 20 00  clr  %l0
a015e8b8:  80 a4 00 1a  cmp  %l0, %i2
a015e8bc:  06 80 00 0a  bl  0xa015e8e4
a015e8c0:  b0 10 00 1a  mov  %i2, %i0
a015e8c4:  30 80 00 17  b,a   0xa015e920
a015e8c8:  91 28 60 18  sll  %g1, 0x18, %o0
a015e8cc:  40 00 00 17  call  0xa015e928
a015e8d0:  91 3a 20 18  sra  %o0, 0x18, %o0
a015e8d4:  a0 04 20 01  inc  %l0
a015e8d8:  80 a4 00 18  cmp  %l0, %i0
a015e8dc:  16 80 00 11  bge  0xa015e920
a015e8e0:  01 00 00 00  nop
a015e8e4:  c2 4e 40 10  ldsb  [ %i1 + %l0 ], %g1
a015e8e8:  80 a0 60 0a  cmp  %g1, 0xa
a015e8ec:  90 10 20 0d  mov  0xd, %o0
a015e8f0:  12 bf ff f6  bne  0xa015e8c8
a015e8f4:  c2 0e 40 10  ldub  [ %i1 + %l0 ], %g1
a015e8f8:  40 00 00 0c  call  0xa015e928
a015e8fc:  01 00 00 00  nop
a015e900:  c2 0e 40 10  ldub  [ %i1 + %l0 ], %g1
a015e904:  91 28 60 18  sll  %g1, 0x18, %o0
a015e908:  40 00 00 08  call  0xa015e928
a015e90c:  91 3a 20 18  sra  %o0, 0x18, %o0
a015e910:  a0 04 20 01  inc  %l0
a015e914:  80 a4 00 18  cmp  %l0, %i0
a015e918:  26 bf ff f4  bl,a   0xa015e8e8
a015e91c:  c2 4e 40 10  ldsb  [ %i1 + %l0 ], %g1
a015e920:  81 c7 e0 08  ret
a015e924:  81 e8 00 00  restore
