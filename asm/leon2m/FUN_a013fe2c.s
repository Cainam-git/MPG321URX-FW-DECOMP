# leon2m FUN_a013fe2c 0xa013fe2c-0xa013ffb0 (388 bytes)  [FUN_a013ffa8 = unreachable ret/restore tail, merged]
a013fe2c:  9d e3 bf 98  save  %sp, -104, %sp
a013fe30:  b0 0e 20 ff  and  %i0, 0xff, %i0
a013fe34:  7f ff f3 c6  call  0xa013cd4c
a013fe38:  90 10 00 18  mov  %i0, %o0
a013fe3c:  a4 10 00 08  mov  %o0, %l2
a013fe40:  40 00 0c 13  call  0xa0142e8c
a013fe44:  90 10 00 18  mov  %i0, %o0
a013fe48:  90 0a 20 ff  and  %o0, 0xff, %o0
a013fe4c:  80 a2 20 05  cmp  %o0, 5
a013fe50:  02 80 00 55  be  0xa013ffa4
a013fe54:  94 10 20 00  clr  %o2
a013fe58:  9b 2e 60 10  sll  %i1, 0x10, %o5
a013fe5c:  33 00 06 96  sethi  %hi(0x1a5800), %i1
a013fe60:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a013fe64:  90 10 63 ff  or  %g1, 0x3ff, %o0	! 0xffff
a013fe68:  9b 33 60 10  srl  %o5, 0x10, %o5
a013fe6c:  10 80 00 06  b  0xa013fe84
a013fe70:  92 16 62 16  or  %i1, 0x216, %o1
a013fe74:  e2 13 20 22  lduh  [ %o4 + 0x22 ], %l1
a013fe78:  80 a4 40 0d  cmp  %l1, %o5
a013fe7c:  02 80 00 0c  be  0xa013feac
a013fe80:  80 a2 e0 ff  cmp  %o3, 0xff
a013fe84:  96 0a a0 ff  and  %o2, 0xff, %o3
a013fe88:  a1 2a e0 03  sll  %o3, 3, %l0
a013fe8c:  98 04 00 0b  add  %l0, %o3, %o4
a013fe90:  a1 2b 20 02  sll  %o4, 2, %l0
a013fe94:  98 04 00 09  add  %l0, %o1, %o4
a013fe98:  de 13 20 02  lduh  [ %o4 + 2 ], %o7
a013fe9c:  80 a3 c0 08  cmp  %o7, %o0
a013fea0:  12 bf ff f5  bne  0xa013fe74
a013fea4:  94 02 a0 01  inc  %o2
a013fea8:  30 80 00 3f  b,a   0xa013ffa4
a013feac:  02 80 00 3e  be  0xa013ffa4
a013feb0:  01 00 00 00  nop
a013feb4:  7f ff f3 a6  call  0xa013cd4c
a013feb8:  90 10 00 18  mov  %i0, %o0
a013febc:  96 16 62 16  or  %i1, 0x216, %o3
a013fec0:  98 04 00 0b  add  %l0, %o3, %o4
a013fec4:  e2 13 20 0e  lduh  [ %o4 + 0xe ], %l1
a013fec8:  e2 32 20 12  sth  %l1, [ %o0 + 0x12 ]
a013fecc:  de 13 20 10  lduh  [ %o4 + 0x10 ], %o7
a013fed0:  de 32 20 14  sth  %o7, [ %o0 + 0x14 ]
a013fed4:  de 13 20 12  lduh  [ %o4 + 0x12 ], %o7
a013fed8:  de 32 20 16  sth  %o7, [ %o0 + 0x16 ]
a013fedc:  f2 13 20 14  lduh  [ %o4 + 0x14 ], %i1
a013fee0:  f2 32 20 18  sth  %i1, [ %o0 + 0x18 ]
a013fee4:  f2 13 20 0a  lduh  [ %o4 + 0xa ], %i1
a013fee8:  f2 32 20 0e  sth  %i1, [ %o0 + 0xe ]
a013feec:  e2 13 20 1a  lduh  [ %o4 + 0x1a ], %l1
a013fef0:  e2 32 20 1e  sth  %l1, [ %o0 + 0x1e ]
a013fef4:  f0 13 20 1c  lduh  [ %o4 + 0x1c ], %i0
a013fef8:  f0 32 20 20  sth  %i0, [ %o0 + 0x20 ]
a013fefc:  d4 13 20 16  lduh  [ %o4 + 0x16 ], %o2
a013ff00:  d4 32 20 1a  sth  %o2, [ %o0 + 0x1a ]
a013ff04:  d2 13 20 18  lduh  [ %o4 + 0x18 ], %o1
a013ff08:  d2 32 20 1c  sth  %o1, [ %o0 + 0x1c ]
a013ff0c:  d4 13 20 0a  lduh  [ %o4 + 0xa ], %o2
a013ff10:  d4 32 20 28  sth  %o2, [ %o0 + 0x28 ]
a013ff14:  d2 13 20 16  lduh  [ %o4 + 0x16 ], %o1
a013ff18:  d2 32 20 2a  sth  %o1, [ %o0 + 0x2a ]
a013ff1c:  c2 13 20 18  lduh  [ %o4 + 0x18 ], %g1
a013ff20:  9a 10 20 20  mov  0x20, %o5
a013ff24:  c2 32 20 2c  sth  %g1, [ %o0 + 0x2c ]
a013ff28:  da 2a 20 26  stb  %o5, [ %o0 + 0x26 ]
a013ff2c:  c0 2a 20 3a  clrb  [ %o0 + 0x3a ]
a013ff30:  f0 13 20 22  lduh  [ %o4 + 0x22 ], %i0
a013ff34:  f0 32 20 3c  sth  %i0, [ %o0 + 0x3c ]
a013ff38:  c2 0a c0 10  ldub  [ %o3 + %l0 ], %g1
a013ff3c:  80 a0 60 00  cmp  %g1, 0
a013ff40:  02 80 00 12  be  0xa013ff88
a013ff44:  b0 04 a0 06  add  %l2, 6, %i0
a013ff48:  82 08 60 ff  and  %g1, 0xff, %g1
a013ff4c:  9a 5b c0 01  smul  %o7, %g1, %o5
a013ff50:  da 32 20 16  sth  %o5, [ %o0 + 0x16 ]
a013ff54:  d8 0a c0 10  ldub  [ %o3 + %l0 ], %o4
a013ff58:  9e 5e 40 0c  smul  %i1, %o4, %o7
a013ff5c:  de 32 20 0e  sth  %o7, [ %o0 + 0xe ]
a013ff60:  f2 0a c0 10  ldub  [ %o3 + %l0 ], %i1
a013ff64:  b0 5c 40 19  smul  %l1, %i1, %i0
a013ff68:  f0 32 20 1e  sth  %i0, [ %o0 + 0x1e ]
a013ff6c:  c2 0a c0 10  ldub  [ %o3 + %l0 ], %g1
a013ff70:  9a 5a 80 01  smul  %o2, %g1, %o5
a013ff74:  da 32 20 28  sth  %o5, [ %o0 + 0x28 ]
a013ff78:  d8 0a c0 10  ldub  [ %o3 + %l0 ], %o4
a013ff7c:  96 5a 40 0c  smul  %o1, %o4, %o3
a013ff80:  d6 32 20 2a  sth  %o3, [ %o0 + 0x2a ]
a013ff84:  b0 04 a0 06  add  %l2, 6, %i0
a013ff88:  40 00 50 99  call  0xa01541ec
a013ff8c:  90 10 00 18  mov  %i0, %o0
a013ff90:  80 8a 20 ff  btst  0xff, %o0
a013ff94:  12 80 00 04  bne  0xa013ffa4
a013ff98:  01 00 00 00  nop
a013ff9c:  40 00 50 ca  call  0xa01542c4
a013ffa0:  81 e8 00 00  restore
a013ffa4:  01 00 00 00  nop
a013ffa8:  81 c7 e0 08  ret
a013ffac:  81 e8 00 00  restore
