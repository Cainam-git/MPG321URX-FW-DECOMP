# leon2m FUN_a010ef64 0xa010ef64-0xa010f064 (256 bytes)
a010ef64:  96 0a 20 ff  and  %o0, 0xff, %o3
a010ef68:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a010ef6c:  80 a2 e0 01  cmp  %o3, 1
a010ef70:  02 80 00 06  be  0xa010ef88
a010ef74:  9a 10 63 c4  or  %g1, 0x3c4, %o5
a010ef78:  15 2a 00 b5  sethi  %hi(0xa802d400), %o2
a010ef7c:  80 a2 e0 02  cmp  %o3, 2
a010ef80:  02 80 00 34  be  0xa010f050
a010ef84:  9a 12 a3 44  or  %o2, 0x344, %o5
a010ef88:  d4 0b 60 3e  ldub  [ %o5 + 0x3e ], %o2
a010ef8c:  82 0a bf fe  and  %o2, -2, %g1
a010ef90:  80 a2 e0 02  cmp  %o3, 2
a010ef94:  08 80 00 03  bleu  0xa010efa0
a010ef98:  c2 2b 60 3e  stb  %g1, [ %o5 + 0x3e ]
a010ef9c:  90 10 20 00  clr  %o0
a010efa0:  98 0a 20 ff  and  %o0, 0xff, %o4
a010efa4:  1b 00 06 6b  sethi  %hi(0x19ac00), %o5
a010efa8:  94 13 62 d8  or  %o5, 0x2d8, %o2	! 0x19aed8
a010efac:  83 2b 20 02  sll  %o4, 2, %g1
a010efb0:  d0 02 80 01  ld  [ %o2 + %g1 ], %o0
a010efb4:  d8 02 20 04  ld  [ %o0 + 4 ], %o4
a010efb8:  1b 00 00 10  sethi  %hi(0x4000), %o5
a010efbc:  80 a2 e0 02  cmp  %o3, 2
a010efc0:  08 80 00 13  bleu  0xa010f00c
a010efc4:  90 2b 00 0d  andn  %o4, %o5, %o0
a010efc8:  98 10 20 00  clr  %o4
a010efcc:  83 2b 20 02  sll  %o4, 2, %g1
a010efd0:  da 02 80 01  ld  [ %o2 + %g1 ], %o5
a010efd4:  98 03 20 01  inc  %o4
a010efd8:  d0 23 60 04  st  %o0, [ %o5 + 4 ]
a010efdc:  80 a3 20 02  cmp  %o4, 2
a010efe0:  28 bf ff fc  bleu,a   0xa010efd0
a010efe4:  83 2b 20 02  sll  %o4, 2, %g1
a010efe8:  80 a2 e0 02  cmp  %o3, 2
a010efec:  18 80 00 0f  bgu  0xa010f028
a010eff0:  15 00 06 6b  sethi  %hi(0x19ac00), %o2
a010eff4:  1b 00 06 6b  sethi  %hi(0x19ac00), %o5
a010eff8:  99 2a e0 02  sll  %o3, 2, %o4
a010effc:  94 13 62 cc  or  %o5, 0x2cc, %o2
a010f000:  d6 02 80 0c  ld  [ %o2 + %o4 ], %o3
a010f004:  d0 22 e0 04  st  %o0, [ %o3 + 4 ]
a010f008:  30 80 00 15  b,a   0xa010f05c
a010f00c:  9b 2a e0 02  sll  %o3, 2, %o5
a010f010:  d8 02 80 0d  ld  [ %o2 + %o5 ], %o4
a010f014:  d0 23 20 04  st  %o0, [ %o4 + 4 ]
a010f018:  80 a2 e0 02  cmp  %o3, 2
a010f01c:  08 bf ff f7  bleu  0xa010eff8
a010f020:  1b 00 06 6b  sethi  %hi(0x19ac00), %o5
a010f024:  15 00 06 6b  sethi  %hi(0x19ac00), %o2
a010f028:  96 12 a2 cc  or  %o2, 0x2cc, %o3	! 0x19aecc
a010f02c:  98 10 20 00  clr  %o4
a010f030:  83 2b 20 02  sll  %o4, 2, %g1
a010f034:  da 02 c0 01  ld  [ %o3 + %g1 ], %o5
a010f038:  98 03 20 01  inc  %o4
a010f03c:  d0 23 60 04  st  %o0, [ %o5 + 4 ]
a010f040:  80 a3 20 02  cmp  %o4, 2
a010f044:  08 bf ff fc  bleu  0xa010f034
a010f048:  83 2b 20 02  sll  %o4, 2, %g1
a010f04c:  30 80 00 04  b,a   0xa010f05c
a010f050:  19 2a 00 b5  sethi  %hi(0xa802d400), %o4
a010f054:  10 bf ff cd  b  0xa010ef88
a010f058:  9a 13 23 84  or  %o4, 0x384, %o5	! 0xa802d784
a010f05c:  81 c3 e0 08  retl
a010f060:  01 00 00 00  nop
