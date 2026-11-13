# leon2m FUN_a013faa0 0xa013faa0-0xa013fbe8 (328 bytes)
a013faa0:  9d e3 bf 98  save  %sp, -104, %sp
a013faa4:  7f ff f4 aa  call  0xa013cd4c
a013faa8:  90 0e 20 ff  and  %i0, 0xff, %o0
a013faac:  13 00 06 96  sethi  %hi(0x1a5800), %o1
a013fab0:  98 12 62 16  or  %o1, 0x216, %o4	! 0x1a5a16
a013fab4:  1b 00 00 3f  sethi  %hi(0xfc00), %o5
a013fab8:  9a 13 63 ff  or  %o5, 0x3ff, %o5	! 0xffff
a013fabc:  c2 13 20 02  lduh  [ %o4 + 2 ], %g1
a013fac0:  80 a0 40 0d  cmp  %g1, %o5
a013fac4:  b0 10 20 00  clr  %i0
a013fac8:  02 80 00 18  be  0xa013fb28
a013facc:  96 10 20 00  clr  %o3
a013fad0:  92 10 00 0c  mov  %o4, %o1
a013fad4:  9e 10 00 0d  mov  %o5, %o7
a013fad8:  98 10 20 00  clr  %o4
a013fadc:  d4 12 20 3c  lduh  [ %o0 + 0x3c ], %o2
a013fae0:  9b 2b 20 03  sll  %o4, 3, %o5
a013fae4:  82 03 40 0c  add  %o5, %o4, %g1
a013fae8:  9b 28 60 02  sll  %g1, 2, %o5
a013faec:  82 03 40 09  add  %o5, %o1, %g1
a013faf0:  d8 10 60 22  lduh  [ %g1 + 0x22 ], %o4
a013faf4:  80 a2 80 0c  cmp  %o2, %o4
a013faf8:  22 80 00 0c  be,a   0xa013fb28
a013fafc:  b0 10 20 01  mov  1, %i0
a013fb00:  96 02 e0 01  inc  %o3
a013fb04:  98 0a e0 ff  and  %o3, 0xff, %o4
a013fb08:  9b 2b 20 03  sll  %o4, 3, %o5
a013fb0c:  82 03 40 0c  add  %o5, %o4, %g1
a013fb10:  9b 28 60 02  sll  %g1, 2, %o5
a013fb14:  82 03 40 09  add  %o5, %o1, %g1
a013fb18:  da 10 60 02  lduh  [ %g1 + 2 ], %o5
a013fb1c:  80 a3 40 0f  cmp  %o5, %o7
a013fb20:  12 bf ff f1  bne  0xa013fae4
a013fb24:  9b 2b 20 03  sll  %o4, 3, %o5
a013fb28:  80 8e 20 ff  btst  0xff, %i0
a013fb2c:  02 80 00 2d  be  0xa013fbe0
a013fb30:  b0 10 20 ff  mov  0xff, %i0
a013fb34:  d4 12 20 3c  lduh  [ %o0 + 0x3c ], %o2
a013fb38:  11 00 00 3f  sethi  %hi(0xfc00), %o0
a013fb3c:  1f 00 06 96  sethi  %hi(0x1a5800), %o7
a013fb40:  98 12 23 ff  or  %o0, 0x3ff, %o4
a013fb44:  96 02 e0 01  inc  %o3
a013fb48:  92 13 e2 16  or  %o7, 0x216, %o1
a013fb4c:  10 80 00 0f  b  0xa013fb88
a013fb50:  91 2a a0 10  sll  %o2, 0x10, %o0
a013fb54:  83 2e 20 03  sll  %i0, 3, %g1
a013fb58:  9a 00 40 18  add  %g1, %i0, %o5
a013fb5c:  9f 2b 60 02  sll  %o5, 2, %o7
a013fb60:  82 03 c0 09  add  %o7, %o1, %g1
a013fb64:  da 10 60 22  lduh  [ %g1 + 0x22 ], %o5
a013fb68:  9f 2b 60 10  sll  %o5, 0x10, %o7
a013fb6c:  83 33 e0 18  srl  %o7, 0x18, %g1
a013fb70:  80 a3 c0 08  cmp  %o7, %o0
a013fb74:  02 80 00 1a  be  0xa013fbdc
a013fb78:  96 02 e0 01  inc  %o3
a013fb7c:  80 a2 80 01  cmp  %o2, %g1
a013fb80:  02 80 00 18  be  0xa013fbe0
a013fb84:  01 00 00 00  nop
a013fb88:  b0 0a e0 ff  and  %o3, 0xff, %i0
a013fb8c:  9b 2e 20 03  sll  %i0, 3, %o5
a013fb90:  9e 03 40 18  add  %o5, %i0, %o7
a013fb94:  95 2b e0 02  sll  %o7, 2, %o2
a013fb98:  82 02 80 09  add  %o2, %o1, %g1
a013fb9c:  da 10 60 02  lduh  [ %g1 + 2 ], %o5
a013fba0:  80 a3 40 0c  cmp  %o5, %o4
a013fba4:  12 bf ff ec  bne  0xa013fb54
a013fba8:  95 32 20 18  srl  %o0, 0x18, %o2
a013fbac:  b0 10 20 00  clr  %i0
a013fbb0:  83 2e 20 03  sll  %i0, 3, %g1
a013fbb4:  9a 00 40 18  add  %g1, %i0, %o5
a013fbb8:  9f 2b 60 02  sll  %o5, 2, %o7
a013fbbc:  82 03 c0 09  add  %o7, %o1, %g1
a013fbc0:  da 10 60 22  lduh  [ %g1 + 0x22 ], %o5
a013fbc4:  9f 2b 60 10  sll  %o5, 0x10, %o7
a013fbc8:  96 10 20 00  clr  %o3
a013fbcc:  83 33 e0 18  srl  %o7, 0x18, %g1
a013fbd0:  80 a3 c0 08  cmp  %o7, %o0
a013fbd4:  12 bf ff ea  bne  0xa013fb7c
a013fbd8:  96 02 e0 01  inc  %o3
a013fbdc:  b0 10 20 ff  mov  0xff, %i0
a013fbe0:  81 c7 e0 08  ret
a013fbe4:  81 e8 00 00  restore
