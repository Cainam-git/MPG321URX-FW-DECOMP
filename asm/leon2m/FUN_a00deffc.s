# leon2m FUN_a00deffc 0xa00deffc-0xa00df074 (120 bytes)
a00deffc:  9d e3 bf 98  save  %sp, -104, %sp
a00df000:  03 00 06 63  sethi  %hi(0x198c00), %g1
a00df004:  1b 00 03 ff  sethi  %hi(0xffc00), %o5
a00df008:  ac 10 63 a0  or  %g1, 0x3a0, %l6
a00df00c:  a8 13 63 fe  or  %o5, 0x3fe, %l4
a00df010:  aa 10 20 00  clr  %l5
a00df014:  25 30 02 c0  sethi  %hi(0xc00b0000), %l2
a00df018:  a6 10 20 1c  mov  0x1c, %l3
a00df01c:  93 36 00 13  srl  %i0, %l3, %o1
a00df020:  90 0a 60 0f  and  %o1, 0xf, %o0
a00df024:  e2 0d 80 08  ldub  [ %l6 + %o0 ], %l1
a00df028:  a0 10 20 00  clr  %l0
a00df02c:  67 fe b4 89  call  0x4008c250
a00df030:  90 14 a0 14  or  %l2, 0x14, %o0
a00df034:  80 8a 20 20  btst  0x20, %o0
a00df038:  12 80 00 05  bne  0xa00df04c
a00df03c:  a0 04 20 01  inc  %l0
a00df040:  80 a4 00 14  cmp  %l0, %l4
a00df044:  08 bf ff fa  bleu  0xa00df02c
a00df048:  01 00 00 00  nop
a00df04c:  95 2c 60 18  sll  %l1, 0x18, %o2
a00df050:  93 3a a0 18  sra  %o2, 0x18, %o1
a00df054:  67 fe b4 82  call  0x4008c25c
a00df058:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a00df05c:  aa 05 60 01  inc  %l5
a00df060:  80 a5 60 07  cmp  %l5, 7
a00df064:  04 bf ff ee  ble  0xa00df01c
a00df068:  a6 04 ff fc  add  %l3, -4, %l3
a00df06c:  81 c7 e0 08  ret
a00df070:  81 e8 00 00  restore
