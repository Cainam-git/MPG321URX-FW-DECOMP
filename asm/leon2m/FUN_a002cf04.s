# leon2m FUN_a002cf04 0xa002cf04-0xa002cf78 (116 bytes)
a002cf04:  9d e3 bf 98  save  %sp, -104, %sp
a002cf08:  58 02 40 20  call  0xbcf88
a002cf0c:  01 00 00 00  nop
a002cf10:  90 0a 20 ff  and  %o0, 0xff, %o0
a002cf14:  80 a2 20 e0  cmp  %o0, 0xe0
a002cf18:  12 80 00 16  bne  0xa002cf70
a002cf1c:  03 33 c0 f2  sethi  %hi(0xcf03c800), %g1
a002cf20:  9a 10 60 44  or  %g1, 0x44, %o5	! 0xcf03c844
a002cf24:  98 10 20 01  mov  1, %o4
a002cf28:  d2 03 40 00  ld  [ %o5 ], %o1
a002cf2c:  80 a2 60 02  cmp  %o1, 2
a002cf30:  32 80 00 02  bne,a   0xa002cf38
a002cf34:  d8 23 40 00  st  %o4, [ %o5 ]
a002cf38:  d4 03 40 00  ld  [ %o5 ], %o2
a002cf3c:  80 a2 a0 01  cmp  %o2, 1
a002cf40:  12 bf ff fa  bne  0xa002cf28
a002cf44:  17 33 c0 f2  sethi  %hi(0xcf03c800), %o3
a002cf48:  9a 12 e0 48  or  %o3, 0x48, %o5	! 0xcf03c848
a002cf4c:  98 10 20 01  mov  1, %o4
a002cf50:  de 03 40 00  ld  [ %o5 ], %o7
a002cf54:  80 a3 e0 02  cmp  %o7, 2
a002cf58:  32 80 00 02  bne,a   0xa002cf60
a002cf5c:  d8 23 40 00  st  %o4, [ %o5 ]
a002cf60:  d0 03 40 00  ld  [ %o5 ], %o0
a002cf64:  80 a2 20 01  cmp  %o0, 1
a002cf68:  12 bf ff fa  bne  0xa002cf50
a002cf6c:  01 00 00 00  nop
a002cf70:  81 c7 e0 08  ret
a002cf74:  81 e8 00 00  restore
