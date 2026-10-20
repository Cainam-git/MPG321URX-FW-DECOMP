# leon2m FUN_a013c040 0xa013c040-0xa013c144 (260 bytes)
a013c040:  9d e3 bf 10  save  %sp, -240, %sp
a013c044:  b0 0e 20 ff  and  %i0, 0xff, %i0
a013c048:  40 00 03 41  call  0xa013cd4c
a013c04c:  90 10 00 18  mov  %i0, %o0
a013c050:  80 a6 20 00  cmp  %i0, 0
a013c054:  a2 07 bf 78  add  %fp, -136, %l1
a013c058:  a0 10 00 08  mov  %o0, %l0
a013c05c:  12 80 00 38  bne  0xa013c13c
a013c060:  b0 10 00 19  mov  %i1, %i0
a013c064:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a013c068:  d8 00 63 d0  ld  [ %g1 + 0x3d0 ], %o4	! 0xa802e3d0
a013c06c:  1b 00 80 00  sethi  %hi(0x2000000), %o5
a013c070:  80 8b 00 0d  btst  %o4, %o5
a013c074:  02 80 00 07  be  0xa013c090
a013c078:  92 04 20 06  add  %l0, 6, %o1
a013c07c:  d2 04 20 70  ld  [ %l0 + 0x70 ], %o1
a013c080:  80 a2 60 00  cmp  %o1, 0
a013c084:  06 80 00 18  bl  0xa013c0e4
a013c088:  90 10 20 00  clr  %o0
a013c08c:  92 04 20 06  add  %l0, 6, %o1
a013c090:  94 10 20 3c  mov  0x3c, %o2
a013c094:  40 00 02 1f  call  0xa013c910
a013c098:  90 10 00 11  mov  %l1, %o0
a013c09c:  91 2e a0 10  sll  %i2, 0x10, %o0
a013c0a0:  9f 2e 20 10  sll  %i0, 0x10, %o7
a013c0a4:  97 32 20 10  srl  %o0, 0x10, %o3
a013c0a8:  92 10 00 11  mov  %l1, %o1
a013c0ac:  95 33 e0 10  srl  %o7, 0x10, %o2
a013c0b0:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a013c0b4:  90 10 20 00  clr  %o0
a013c0b8:  98 10 20 00  clr  %o4
a013c0bc:  7f ff 31 90  call  0xa01086fc
a013c0c0:  9a 10 20 00  clr  %o5
a013c0c4:  f0 04 20 68  ld  [ %l0 + 0x68 ], %i0
a013c0c8:  35 00 10 00  sethi  %hi(0x400000), %i2
a013c0cc:  b2 2e 00 1a  andn  %i0, %i2, %i1
a013c0d0:  25 00 08 00  sethi  %hi(0x200000), %l2
a013c0d4:  a2 2e 40 12  andn  %i1, %l2, %l1
a013c0d8:  7f fe f5 ea  call  0xa00f9880
a013c0dc:  e2 24 20 68  st  %l1, [ %l0 + 0x68 ]
a013c0e0:  30 80 00 17  b,a   0xa013c13c
a013c0e4:  7f ff 94 5d  call  0xa0121258
a013c0e8:  01 00 00 00  nop
a013c0ec:  96 0a 20 ff  and  %o0, 0xff, %o3
a013c0f0:  a4 07 bf b8  add  %fp, -72, %l2
a013c0f4:  92 04 20 06  add  %l0, 6, %o1
a013c0f8:  94 10 20 3c  mov  0x3c, %o2
a013c0fc:  80 a2 e0 01  cmp  %o3, 1
a013c100:  12 bf ff e5  bne  0xa013c094
a013c104:  90 10 00 12  mov  %l2, %o0
a013c108:  40 00 02 02  call  0xa013c910
a013c10c:  01 00 00 00  nop
a013c110:  d6 14 20 18  lduh  [ %l0 + 0x18 ], %o3
a013c114:  95 2e 60 10  sll  %i1, 0x10, %o2
a013c118:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a013c11c:  92 10 00 12  mov  %l2, %o1
a013c120:  95 32 a0 10  srl  %o2, 0x10, %o2
a013c124:  90 10 20 00  clr  %o0
a013c128:  98 10 20 01  mov  1, %o4
a013c12c:  7f ff 31 74  call  0xa01086fc
a013c130:  9a 10 20 00  clr  %o5
a013c134:  10 bf ff e4  b  0xa013c0c4
a013c138:  c0 2c 20 68  clrb  [ %l0 + 0x68 ]
a013c13c:  81 c7 e0 08  ret
a013c140:  81 e8 00 00  restore
