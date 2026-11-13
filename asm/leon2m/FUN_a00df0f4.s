# leon2m FUN_a00df0f4 0xa00df0f4-0xa00df170 (124 bytes)
a00df0f4:  9d e3 bf 98  save  %sp, -104, %sp
a00df0f8:  03 00 06 63  sethi  %hi(0x198c00), %g1
a00df0fc:  1b 00 03 ff  sethi  %hi(0xffc00), %o5
a00df100:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00df104:  ac 10 63 a0  or  %g1, 0x3a0, %l6
a00df108:  aa 13 63 fe  or  %o5, 0x3fe, %l5
a00df10c:  a8 10 20 00  clr  %l4
a00df110:  27 30 02 c0  sethi  %hi(0xc00b0000), %l3
a00df114:  a4 10 20 04  mov  4, %l2
a00df118:  93 3e 00 12  sra  %i0, %l2, %o1
a00df11c:  90 0a 60 0f  and  %o1, 0xf, %o0
a00df120:  e2 0d 80 08  ldub  [ %l6 + %o0 ], %l1
a00df124:  a0 10 20 00  clr  %l0
a00df128:  67 fe b4 4a  call  0x4008c250
a00df12c:  90 14 e0 14  or  %l3, 0x14, %o0
a00df130:  80 8a 20 20  btst  0x20, %o0
a00df134:  12 80 00 05  bne  0xa00df148
a00df138:  a0 04 20 01  inc  %l0
a00df13c:  80 a4 00 15  cmp  %l0, %l5
a00df140:  08 bf ff fa  bleu  0xa00df128
a00df144:  01 00 00 00  nop
a00df148:  95 2c 60 18  sll  %l1, 0x18, %o2
a00df14c:  93 3a a0 18  sra  %o2, 0x18, %o1
a00df150:  67 fe b4 43  call  0x4008c25c
a00df154:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a00df158:  a8 05 20 01  inc  %l4
a00df15c:  80 a5 20 01  cmp  %l4, 1
a00df160:  04 bf ff ee  ble  0xa00df118
a00df164:  a4 04 bf fc  add  %l2, -4, %l2
a00df168:  81 c7 e0 08  ret
a00df16c:  81 e8 00 00  restore
