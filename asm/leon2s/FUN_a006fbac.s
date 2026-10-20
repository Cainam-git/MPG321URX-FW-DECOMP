# leon2s FUN_a006fbac 0xa006fbac-0xa006fc54 (168 bytes)
a006fbac:  92 0a 60 ff  and  %o1, 0xff, %o1
a006fbb0:  9b 2a 60 02  sll  %o1, 2, %o5
a006fbb4:  9a 03 40 09  add  %o5, %o1, %o5
a006fbb8:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a006fbbc:  90 0a 20 ff  and  %o0, 0xff, %o0
a006fbc0:  82 10 60 24  or  %g1, 0x24, %g1
a006fbc4:  9b 2b 60 02  sll  %o5, 2, %o5
a006fbc8:  9a 03 40 01  add  %o5, %g1, %o5
a006fbcc:  d0 22 80 00  st  %o0, [ %o2 ]
a006fbd0:  c2 0b 60 0d  ldub  [ %o5 + 0xd ], %g1
a006fbd4:  83 28 60 08  sll  %g1, 8, %g1
a006fbd8:  90 12 00 01  or  %o0, %g1, %o0
a006fbdc:  d0 22 80 00  st  %o0, [ %o2 ]
a006fbe0:  c2 0b 60 0e  ldub  [ %o5 + 0xe ], %g1
a006fbe4:  83 28 60 10  sll  %g1, 0x10, %g1
a006fbe8:  90 12 00 01  or  %o0, %g1, %o0
a006fbec:  d0 22 80 00  st  %o0, [ %o2 ]
a006fbf0:  d2 0b 60 0c  ldub  [ %o5 + 0xc ], %o1
a006fbf4:  d2 22 a0 04  st  %o1, [ %o2 + 4 ]
a006fbf8:  c2 0b 60 12  ldub  [ %o5 + 0x12 ], %g1
a006fbfc:  82 08 60 1f  and  %g1, 0x1f, %g1
a006fc00:  83 28 60 08  sll  %g1, 8, %g1
a006fc04:  d8 13 60 02  lduh  [ %o5 + 2 ], %o4
a006fc08:  92 12 40 01  or  %o1, %g1, %o1
a006fc0c:  d0 13 60 0a  lduh  [ %o5 + 0xa ], %o0
a006fc10:  d6 13 60 06  lduh  [ %o5 + 6 ], %o3
a006fc14:  c2 13 60 04  lduh  [ %o5 + 4 ], %g1
a006fc18:  99 2b 20 10  sll  %o4, 0x10, %o4
a006fc1c:  91 2a 20 10  sll  %o0, 0x10, %o0
a006fc20:  92 12 40 0c  or  %o1, %o4, %o1
a006fc24:  97 2a e0 10  sll  %o3, 0x10, %o3
a006fc28:  da 13 60 08  lduh  [ %o5 + 8 ], %o5
a006fc2c:  9a 13 40 08  or  %o5, %o0, %o5
a006fc30:  82 10 40 0b  or  %g1, %o3, %g1
a006fc34:  d2 22 a0 04  st  %o1, [ %o2 + 4 ]
a006fc38:  c2 22 a0 08  st  %g1, [ %o2 + 8 ]
a006fc3c:  da 22 a0 0c  st  %o5, [ %o2 + 0xc ]
a006fc40:  90 10 00 0a  mov  %o2, %o0
a006fc44:  92 10 20 04  mov  4, %o1
a006fc48:  82 13 c0 00  mov  %o7, %g1
a006fc4c:  7f ff ff bc  call  0xa006fb3c
a006fc50:  9e 10 40 00  mov  %g1, %o7
