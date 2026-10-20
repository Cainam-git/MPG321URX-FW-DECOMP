# leon2m FUN_a01410a4 0xa01410a4-0xa014110c (104 bytes)
a01410a4:  9d e3 bf 78  save  %sp, -136, %sp
a01410a8:  c2 07 bf e8  ld  [ %fp + -24 ], %g1
a01410ac:  13 20 00 00  sethi  %hi(0x80000000), %o1
a01410b0:  90 28 40 09  andn  %g1, %o1, %o0
a01410b4:  1b 08 00 00  sethi  %hi(0x20000000), %o5
a01410b8:  9e 2a 00 0d  andn  %o0, %o5, %o7
a01410bc:  19 10 00 00  sethi  %hi(0x40000000), %o4
a01410c0:  13 00 06 8d  sethi  %hi(0x1a3400), %o1
a01410c4:  03 00 06 8d  sethi  %hi(0x1a3400), %g1
a01410c8:  96 2b c0 0c  andn  %o7, %o4, %o3
a01410cc:  94 10 20 02  mov  2, %o2
a01410d0:  90 12 62 68  or  %o1, 0x268, %o0
a01410d4:  9a 10 62 48  or  %g1, 0x248, %o5
a01410d8:  d0 27 bf f0  st  %o0, [ %fp + -16 ]
a01410dc:  d6 27 bf e8  st  %o3, [ %fp + -24 ]
a01410e0:  d4 27 bf ec  st  %o2, [ %fp + -20 ]
a01410e4:  da 27 bf f4  st  %o5, [ %fp + -12 ]
a01410e8:  d4 1f bf e8  ldd  [ %fp + -24 ], %o2
a01410ec:  d8 1f bf f0  ldd  [ %fp + -16 ], %o4
a01410f0:  d4 3f bf d8  std  %o2, [ %fp + -40 ]
a01410f4:  d8 3f bf e0  std  %o4, [ %fp + -32 ]
a01410f8:  7f ff 5f 43  call  0xa0118e04
a01410fc:  90 07 bf d8  add  %fp, -40, %o0
a0141100:  01 00 00 00  nop
a0141104:  81 c7 e0 08  ret
a0141108:  81 e8 00 00  restore
