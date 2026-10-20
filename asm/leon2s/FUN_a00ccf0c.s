# leon2s FUN_a00ccf0c 0xa00ccf0c-0xa00ccfa8 (156 bytes)
a00ccf0c:  9d e3 bf 98  save  %sp, -104, %sp
a00ccf10:  7f ff fe ca  call  0xa00cca38
a00ccf14:  90 10 20 00  clr  %o0
a00ccf18:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00ccf1c:  82 06 00 18  add  %i0, %i0, %g1
a00ccf20:  82 00 40 18  add  %g1, %i0, %g1
a00ccf24:  b1 28 60 03  sll  %g1, 3, %i0
a00ccf28:  1b 2a 01 e2  sethi  %hi(0xa8078800), %o5
a00ccf2c:  03 3f ff 3f  sethi  %hi(0xfffcfc00), %g1
a00ccf30:  a0 13 63 b0  or  %o5, 0x3b0, %l0
a00ccf34:  a2 10 63 ff  or  %g1, 0x3ff, %l1
a00ccf38:  c2 04 00 18  ld  [ %l0 + %i0 ], %g1
a00ccf3c:  1b 00 00 40  sethi  %hi(0x10000), %o5
a00ccf40:  82 08 40 11  and  %g1, %l1, %g1
a00ccf44:  82 10 40 0d  or  %g1, %o5, %g1
a00ccf48:  25 2a 01 f3  sethi  %hi(0xa807cc00), %l2
a00ccf4c:  15 00 01 a4  sethi  %hi(0x69000), %o2
a00ccf50:  c2 24 00 18  st  %g1, [ %l0 + %i0 ]
a00ccf54:  94 12 a2 1d  or  %o2, 0x21d, %o2
a00ccf58:  92 10 20 90  mov  0x90, %o1
a00ccf5c:  96 10 20 00  clr  %o3
a00ccf60:  98 14 a2 50  or  %l2, 0x250, %o4
a00ccf64:  40 3b 25 27  call  0xa0f96400
a00ccf68:  90 10 20 00  clr  %o0
a00ccf6c:  80 8a 20 ff  btst  0xff, %o0
a00ccf70:  32 80 00 05  bne,a   0xa00ccf84
a00ccf74:  c2 0c a2 50  ldub  [ %l2 + 0x250 ], %g1
a00ccf78:  c2 04 00 18  ld  [ %l0 + %i0 ], %g1
a00ccf7c:  10 80 00 08  b  0xa00ccf9c
a00ccf80:  82 08 40 11  and  %g1, %l1, %g1
a00ccf84:  80 a0 60 02  cmp  %g1, 2
a00ccf88:  12 80 00 06  bne  0xa00ccfa0
a00ccf8c:  1b 00 00 80  sethi  %hi(0x20000), %o5
a00ccf90:  c2 04 00 18  ld  [ %l0 + %i0 ], %g1
a00ccf94:  82 08 40 11  and  %g1, %l1, %g1
a00ccf98:  82 10 40 0d  or  %g1, %o5, %g1
a00ccf9c:  c2 24 00 18  st  %g1, [ %l0 + %i0 ]
a00ccfa0:  81 c7 e0 08  ret
a00ccfa4:  81 e8 00 00  restore
