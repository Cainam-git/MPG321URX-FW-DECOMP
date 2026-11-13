# leon2s FUN_a006fedc 0xa006fedc-0xa006ffb4 (216 bytes)
a006fedc:  9d e3 bf 90  save  %sp, -112, %sp
a006fee0:  92 10 20 03  mov  3, %o1
a006fee4:  94 07 bf f4  add  %fp, -12, %o2
a006fee8:  96 10 20 01  mov  1, %o3
a006feec:  90 10 20 00  clr  %o0
a006fef0:  7f ff fe ee  call  0xa006faa8
a006fef4:  c0 27 bf f4  clr  [ %fp + -12 ]
a006fef8:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a006fefc:  d6 08 60 5c  ldub  [ %g1 + 0x5c ], %o3	! 0xa8078c5c
a006ff00:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a006ff04:  e0 08 63 f4  ldub  [ %g1 + 0x3f4 ], %l0	! 0xa80787f4
a006ff08:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a006ff0c:  d8 08 60 00  ldub  [ %g1 ], %o4
a006ff10:  96 02 c0 0b  add  %o3, %o3, %o3
a006ff14:  1b 2a 01 e3  sethi  %hi(0xa8078c00), %o5
a006ff18:  c2 0b 60 48  ldub  [ %o5 + 0x48 ], %g1	! 0xa8078c48
a006ff1c:  a0 14 00 0b  or  %l0, %o3, %l0
a006ff20:  99 2b 20 02  sll  %o4, 2, %o4
a006ff24:  a0 14 00 0c  or  %l0, %o4, %l0
a006ff28:  83 28 60 03  sll  %g1, 3, %g1
a006ff2c:  a0 14 00 01  or  %l0, %g1, %l0
a006ff30:  9a 13 60 48  or  %o5, 0x48, %o5
a006ff34:  da 0b 60 01  ldub  [ %o5 + 1 ], %o5
a006ff38:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a006ff3c:  d6 08 62 0a  ldub  [ %g1 + 0x20a ], %o3	! 0xa8078a0a
a006ff40:  9b 2b 60 04  sll  %o5, 4, %o5
a006ff44:  a0 14 00 0d  or  %l0, %o5, %l0
a006ff48:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a006ff4c:  da 08 60 dc  ldub  [ %g1 + 0xdc ], %o5	! 0xa80788dc
a006ff50:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a006ff54:  97 2a e0 05  sll  %o3, 5, %o3
a006ff58:  19 3f c0 00  sethi  %hi(0xff000000), %o4
a006ff5c:  98 28 40 0c  andn  %g1, %o4, %o4
a006ff60:  a0 14 00 0b  or  %l0, %o3, %l0
a006ff64:  9b 2b 60 06  sll  %o5, 6, %o5
a006ff68:  a0 14 00 0d  or  %l0, %o5, %l0
a006ff6c:  d8 27 bf f4  st  %o4, [ %fp + -12 ]
a006ff70:  40 00 63 cc  call  0xa0088ea0
a006ff74:  90 10 20 00  clr  %o0
a006ff78:  90 0a 20 ff  and  %o0, 0xff, %o0
a006ff7c:  91 2a 20 07  sll  %o0, 7, %o0
a006ff80:  a0 14 00 08  or  %l0, %o0, %l0
a006ff84:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a006ff88:  a1 2c 20 18  sll  %l0, 0x18, %l0
a006ff8c:  82 10 40 10  or  %g1, %l0, %g1
a006ff90:  c2 27 bf f4  st  %g1, [ %fp + -12 ]
a006ff94:  90 10 20 00  clr  %o0
a006ff98:  92 10 20 03  mov  3, %o1
a006ff9c:  94 07 bf f4  add  %fp, -12, %o2
a006ffa0:  7f ff fe cd  call  0xa006fad4
a006ffa4:  96 10 20 01  mov  1, %o3
a006ffa8:  01 00 00 00  nop
a006ffac:  81 c7 e0 08  ret
a006ffb0:  81 e8 00 00  restore
