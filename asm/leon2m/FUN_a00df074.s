# leon2m FUN_a00df074 0xa00df074-0xa00df0f4 (128 bytes)
a00df074:  9d e3 bf 98  save  %sp, -104, %sp
a00df078:  b1 2e 20 10  sll  %i0, 0x10, %i0
a00df07c:  03 00 06 63  sethi  %hi(0x198c00), %g1
a00df080:  1b 00 03 ff  sethi  %hi(0xffc00), %o5
a00df084:  ac 10 63 a0  or  %g1, 0x3a0, %l6
a00df088:  aa 13 63 fe  or  %o5, 0x3fe, %l5
a00df08c:  b1 36 20 10  srl  %i0, 0x10, %i0
a00df090:  a8 10 20 00  clr  %l4
a00df094:  25 30 02 c0  sethi  %hi(0xc00b0000), %l2
a00df098:  a6 10 20 0c  mov  0xc, %l3
a00df09c:  93 3e 00 13  sra  %i0, %l3, %o1
a00df0a0:  90 0a 60 0f  and  %o1, 0xf, %o0
a00df0a4:  e2 0d 80 08  ldub  [ %l6 + %o0 ], %l1
a00df0a8:  a0 10 20 00  clr  %l0
a00df0ac:  67 fe b4 69  call  0x4008c250
a00df0b0:  90 14 a0 14  or  %l2, 0x14, %o0
a00df0b4:  80 8a 20 20  btst  0x20, %o0
a00df0b8:  12 80 00 05  bne  0xa00df0cc
a00df0bc:  a0 04 20 01  inc  %l0
a00df0c0:  80 a4 00 15  cmp  %l0, %l5
a00df0c4:  08 bf ff fa  bleu  0xa00df0ac
a00df0c8:  01 00 00 00  nop
a00df0cc:  95 2c 60 18  sll  %l1, 0x18, %o2
a00df0d0:  93 3a a0 18  sra  %o2, 0x18, %o1
a00df0d4:  67 fe b4 62  call  0x4008c25c
a00df0d8:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a00df0dc:  a8 05 20 01  inc  %l4
a00df0e0:  80 a5 20 03  cmp  %l4, 3
a00df0e4:  04 bf ff ee  ble  0xa00df09c
a00df0e8:  a6 04 ff fc  add  %l3, -4, %l3
a00df0ec:  81 c7 e0 08  ret
a00df0f0:  81 e8 00 00  restore
