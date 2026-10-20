# leon2m FUN_a012af40 0xa012af40-0xa012b078 (312 bytes)
a012af40:  9d e3 bf 80  save  %sp, -128, %sp
a012af44:  1b 2a 00 b8  sethi  %hi(0xa802e000), %o5
a012af48:  90 13 61 a0  or  %o5, 0x1a0, %o0	! 0xa802e1a0
a012af4c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a012af50:  97 2e 20 02  sll  %i0, 2, %o3
a012af54:  93 2e 20 03  sll  %i0, 3, %o1
a012af58:  98 10 20 03  mov  3, %o4
a012af5c:  de 0a 20 2c  ldub  [ %o0 + 0x2c ], %o7
a012af60:  a1 3b c0 0b  sra  %o7, %o3, %l0
a012af64:  a5 2b 00 09  sll  %o4, %o1, %l2
a012af68:  98 0c 20 0f  and  %l0, 0xf, %o4
a012af6c:  94 03 00 0c  add  %o4, %o4, %o2
a012af70:  a2 0e 60 ff  and  %i1, 0xff, %l1
a012af74:  a6 10 20 0f  mov  0xf, %l3
a012af78:  a1 2c 80 0a  sll  %l2, %o2, %l0
a012af7c:  83 2c 40 09  sll  %l1, %o1, %g1
a012af80:  9a 0e 60 ff  and  %i1, 0xff, %o5
a012af84:  9f 2c c0 0b  sll  %l3, %o3, %o7
a012af88:  95 28 40 0a  sll  %g1, %o2, %o2
a012af8c:  80 a3 20 02  cmp  %o4, 2
a012af90:  18 80 00 15  bgu  0xa012afe4
a012af94:  9b 2b 40 0b  sll  %o5, %o3, %o5
a012af98:  e6 02 20 2c  ld  [ %o0 + 0x2c ], %l3
a012af9c:  d8 02 20 30  ld  [ %o0 + 0x30 ], %o4
a012afa0:  a4 0c e0 ff  and  %l3, 0xff, %l2
a012afa4:  93 2c a0 08  sll  %l2, 8, %o1
a012afa8:  97 33 20 18  srl  %o4, 0x18, %o3
a012afac:  a2 12 c0 09  or  %o3, %o1, %l1
a012afb0:  82 2c 40 10  andn  %l1, %l0, %g1
a012afb4:  9a 10 40 0a  or  %g1, %o2, %o5
a012afb8:  a1 2b 60 10  sll  %o5, 0x10, %l0
a012afbc:  1f 3f c0 00  sethi  %hi(0xff000000), %o7
a012afc0:  a2 2b 00 0f  andn  %o4, %o7, %l1
a012afc4:  92 0c ff 00  and  %l3, -256, %o1
a012afc8:  97 2c 20 08  sll  %l0, 8, %o3
a012afcc:  a5 34 20 18  srl  %l0, 0x18, %l2
a012afd0:  94 12 40 12  or  %o1, %l2, %o2
a012afd4:  82 14 40 0b  or  %l1, %o3, %g1
a012afd8:  c2 22 20 30  st  %g1, [ %o0 + 0x30 ]
a012afdc:  10 80 00 06  b  0xa012aff4
a012afe0:  d4 22 20 2c  st  %o2, [ %o0 + 0x2c ]
a012afe4:  e6 0a 20 31  ldub  [ %o0 + 0x31 ], %l3
a012afe8:  a0 2c c0 0f  andn  %l3, %o7, %l0
a012afec:  94 14 00 0d  or  %l0, %o5, %o2
a012aff0:  d4 2a 20 31  stb  %o2, [ %o0 + 0x31 ]
a012aff4:  23 2a 00 b6  sethi  %hi(0xa802d800), %l1
a012aff8:  a4 14 60 ae  or  %l1, 0xae, %l2	! 0xa802d8ae
a012affc:  a6 5e 20 16  smul  %i0, 0x16, %l3
a012b000:  f2 2c 80 13  stb  %i1, [ %l2 + %l3 ]
a012b004:  d6 14 80 13  lduh  [ %l2 + %l3 ], %o3
a012b008:  82 04 c0 12  add  %l3, %l2, %g1
a012b00c:  d2 10 60 08  lduh  [ %g1 + 8 ], %o1
a012b010:  d0 10 60 0a  lduh  [ %g1 + 0xa ], %o0
a012b014:  f2 10 60 14  lduh  [ %g1 + 0x14 ], %i1
a012b018:  d4 10 60 02  lduh  [ %g1 + 2 ], %o2
a012b01c:  da 10 60 04  lduh  [ %g1 + 4 ], %o5
a012b020:  d8 10 60 06  lduh  [ %g1 + 6 ], %o4
a012b024:  de 10 60 0c  lduh  [ %g1 + 0xc ], %o7
a012b028:  e0 10 60 0e  lduh  [ %g1 + 0xe ], %l0
a012b02c:  e2 10 60 10  lduh  [ %g1 + 0x10 ], %l1
a012b030:  e4 10 60 12  lduh  [ %g1 + 0x12 ], %l2
a012b034:  d2 37 bf e8  sth  %o1, [ %fp + -24 ]
a012b038:  d0 37 bf ea  sth  %o0, [ %fp + -22 ]
a012b03c:  d6 37 bf e0  sth  %o3, [ %fp + -32 ]
a012b040:  d4 37 bf e2  sth  %o2, [ %fp + -30 ]
a012b044:  da 37 bf e4  sth  %o5, [ %fp + -28 ]
a012b048:  d8 37 bf e6  sth  %o4, [ %fp + -26 ]
a012b04c:  de 37 bf ec  sth  %o7, [ %fp + -20 ]
a012b050:  e0 37 bf ee  sth  %l0, [ %fp + -18 ]
a012b054:  e2 37 bf f0  sth  %l1, [ %fp + -16 ]
a012b058:  e4 37 bf f2  sth  %l2, [ %fp + -14 ]
a012b05c:  f2 37 bf f4  sth  %i1, [ %fp + -12 ]
a012b060:  90 10 00 18  mov  %i0, %o0
a012b064:  40 00 32 81  call  0xa0137a68
a012b068:  92 07 bf e0  add  %fp, -32, %o1
a012b06c:  01 00 00 00  nop
a012b070:  81 c7 e0 08  ret
a012b074:  81 e8 00 00  restore
