# leon2m FUN_a011cf88 0xa011cf88-0xa011d0a8 (288 bytes)
a011cf88:  9c 03 bf 90  add  %sp, -112, %sp
a011cf8c:  9a 10 20 00  clr  %o5
a011cf90:  17 33 c0 45  sethi  %hi(0xcf011400), %o3
a011cf94:  98 10 20 00  clr  %o4
a011cf98:  d8 3b a0 60  std  %o4, [ %sp + 0x60 ]
a011cf9c:  82 12 e0 44  or  %o3, 0x44, %g1
a011cfa0:  da 00 40 00  ld  [ %g1 ], %o5
a011cfa4:  80 a3 60 16  cmp  %o5, 0x16
a011cfa8:  02 80 00 16  be  0xa011d000
a011cfac:  90 10 3f 84  mov  -124, %o0
a011cfb0:  19 33 c0 45  sethi  %hi(0xcf011400), %o4
a011cfb4:  82 13 20 44  or  %o4, 0x44, %g1	! 0xcf011444
a011cfb8:  d6 00 40 00  ld  [ %g1 ], %o3
a011cfbc:  80 a2 e0 1e  cmp  %o3, 0x1e
a011cfc0:  02 80 00 27  be  0xa011d05c
a011cfc4:  9a 13 20 40  or  %o4, 0x40, %o5
a011cfc8:  19 33 c0 45  sethi  %hi(0xcf011400), %o4
a011cfcc:  96 13 20 44  or  %o4, 0x44, %o3	! 0xcf011444
a011cfd0:  d4 02 c0 00  ld  [ %o3 ], %o2
a011cfd4:  80 a2 a0 1f  cmp  %o2, 0x1f
a011cfd8:  02 80 00 27  be  0xa011d074
a011cfdc:  82 13 20 40  or  %o4, 0x40, %g1
a011cfe0:  19 33 c0 45  sethi  %hi(0xcf011400), %o4
a011cfe4:  94 13 20 44  or  %o4, 0x44, %o2	! 0xcf011444
a011cfe8:  da 02 80 00  ld  [ %o2 ], %o5
a011cfec:  80 a3 60 17  cmp  %o5, 0x17
a011cff0:  32 80 00 2c  bne,a   0xa011d0a0
a011cff4:  90 0a 20 ff  and  %o0, 0xff, %o0
a011cff8:  10 80 00 25  b  0xa011d08c
a011cffc:  82 13 20 40  or  %o4, 0x40, %g1
a011d000:  98 12 e0 40  or  %o3, 0x40, %o4
a011d004:  d4 03 00 00  ld  [ %o4 ], %o2
a011d008:  80 a2 a0 01  cmp  %o2, 1
a011d00c:  12 bf ff ea  bne  0xa011cfb4
a011d010:  19 33 c0 45  sethi  %hi(0xcf011400), %o4
a011d014:  11 27 c6 c1  sethi  %hi(0x9f1b0400), %o0
a011d018:  94 12 22 00  or  %o0, 0x200, %o2	! 0x9f1b0600
a011d01c:  96 03 a0 60  add  %sp, 0x60, %o3
a011d020:  98 10 20 00  clr  %o4
a011d024:  9a 10 20 00  clr  %o5
a011d028:  c2 0b 40 0a  ldub  [ %o5 + %o2 ], %g1
a011d02c:  c2 2b 40 0b  stb  %g1, [ %o5 + %o3 ]
a011d030:  98 03 20 01  inc  %o4
a011d034:  9a 0b 20 ff  and  %o4, 0xff, %o5
a011d038:  80 a3 60 08  cmp  %o5, 8
a011d03c:  2a bf ff fc  bcs,a   0xa011d02c
a011d040:  c2 0b 40 0a  ldub  [ %o5 + %o2 ], %g1
a011d044:  d4 0b a0 66  ldub  [ %sp + 0x66 ], %o2
a011d048:  9a 1a a0 01  xor  %o2, 1, %o5
a011d04c:  80 a0 00 0d  cmp  %g0, %o5
a011d050:  96 10 3f 81  mov  -127, %o3
a011d054:  10 80 00 12  b  0xa011d09c
a011d058:  90 62 e0 00  subx  %o3, 0, %o0
a011d05c:  d8 03 40 00  ld  [ %o5 ], %o4
a011d060:  80 a3 20 01  cmp  %o4, 1
a011d064:  32 bf ff da  bne,a   0xa011cfcc
a011d068:  19 33 c0 45  sethi  %hi(0xcf011400), %o4
a011d06c:  10 80 00 0c  b  0xa011d09c
a011d070:  90 10 3f 82  mov  -126, %o0
a011d074:  d8 00 40 00  ld  [ %g1 ], %o4
a011d078:  80 a3 20 01  cmp  %o4, 1
a011d07c:  32 bf ff da  bne,a   0xa011cfe4
a011d080:  19 33 c0 45  sethi  %hi(0xcf011400), %o4
a011d084:  10 80 00 06  b  0xa011d09c
a011d088:  90 10 3f 83  mov  -125, %o0
a011d08c:  d6 00 40 00  ld  [ %g1 ], %o3
a011d090:  80 a2 e0 01  cmp  %o3, 1
a011d094:  22 80 00 02  be,a   0xa011d09c
a011d098:  90 10 3f 84  mov  -124, %o0
a011d09c:  90 0a 20 ff  and  %o0, 0xff, %o0
a011d0a0:  81 c3 e0 08  retl
a011d0a4:  9c 23 bf 90  sub  %sp, -112, %sp
