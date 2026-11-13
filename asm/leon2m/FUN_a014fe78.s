# leon2m FUN_a014fe78 0xa014fe78-0xa0150120 (680 bytes)
a014fe78:  9d e3 bf 98  save  %sp, -104, %sp
a014fe7c:  03 2a 00 a9  sethi  %hi(0xa802a400), %g1
a014fe80:  7f ff 3a 17  call  0xa011e6dc
a014fe84:  d0 08 60 9a  ldub  [ %g1 + 0x9a ], %o0	! 0xa802a49a
a014fe88:  b0 0e 20 ff  and  %i0, 0xff, %i0
a014fe8c:  80 a6 20 01  cmp  %i0, 1
a014fe90:  02 80 00 55  be  0xa014ffe4
a014fe94:  17 00 06 9c  sethi  %hi(0x1a7000), %o3
a014fe98:  7f fe 3c b6  call  0xa00df170
a014fe9c:  90 12 e3 50  or  %o3, 0x350, %o0	! 0x1a7350
a014fea0:  21 2a 00 b3  sethi  %hi(0xa802cc00), %l0
a014fea4:  da 0c 20 87  ldub  [ %l0 + 0x87 ], %o5	! 0xa802cc87
a014fea8:  13 2a 00 a9  sethi  %hi(0xa802a400), %o1
a014feac:  80 8b 60 01  btst  1, %o5
a014feb0:  12 80 00 18  bne  0xa014ff10
a014feb4:  f0 12 60 b2  lduh  [ %o1 + 0xb2 ], %i0
a014feb8:  80 8b 60 02  btst  2, %o5
a014febc:  32 80 00 1e  bne,a   0xa014ff34
a014fec0:  9b 2e 20 10  sll  %i0, 0x10, %o5
a014fec4:  80 8b 60 04  btst  4, %o5
a014fec8:  12 80 00 23  bne  0xa014ff54
a014fecc:  9f 2e 20 10  sll  %i0, 0x10, %o7
a014fed0:  80 8b 60 08  btst  8, %o5
a014fed4:  12 80 00 28  bne  0xa014ff74
a014fed8:  83 2e 20 10  sll  %i0, 0x10, %g1
a014fedc:  80 8b 60 10  btst  0x10, %o5
a014fee0:  32 80 00 2d  bne,a   0xa014ff94
a014fee4:  91 2e 20 10  sll  %i0, 0x10, %o0
a014fee8:  80 8b 60 20  btst  0x20, %o5
a014feec:  12 80 00 32  bne  0xa014ffb4
a014fef0:  95 2e 20 10  sll  %i0, 0x10, %o2
a014fef4:  80 8b 60 40  btst  0x40, %o5
a014fef8:  32 80 00 37  bne,a   0xa014ffd4
a014fefc:  a1 2e 20 10  sll  %i0, 0x10, %l0
a014ff00:  7f ff ff 3c  call  0xa014fbf0
a014ff04:  90 10 20 00  clr  %o0
a014ff08:  7f ff ff 8b  call  0xa014fd34
a014ff0c:  91 e8 20 00  restore  %g0, 0, %o0
a014ff10:  99 2e 20 10  sll  %i0, 0x10, %o4
a014ff14:  93 33 20 10  srl  %o4, 0x10, %o1
a014ff18:  7f ff 37 a1  call  0xa011dd9c
a014ff1c:  90 10 20 10  mov  0x10, %o0
a014ff20:  da 0c 20 87  ldub  [ %l0 + 0x87 ], %o5
a014ff24:  80 8b 60 02  btst  2, %o5
a014ff28:  02 bf ff e8  be  0xa014fec8
a014ff2c:  80 8b 60 04  btst  4, %o5
a014ff30:  9b 2e 20 10  sll  %i0, 0x10, %o5
a014ff34:  93 33 60 10  srl  %o5, 0x10, %o1
a014ff38:  7f ff 37 99  call  0xa011dd9c
a014ff3c:  90 10 20 11  mov  0x11, %o0
a014ff40:  da 0c 20 87  ldub  [ %l0 + 0x87 ], %o5
a014ff44:  80 8b 60 04  btst  4, %o5
a014ff48:  02 bf ff e3  be  0xa014fed4
a014ff4c:  80 8b 60 08  btst  8, %o5
a014ff50:  9f 2e 20 10  sll  %i0, 0x10, %o7
a014ff54:  93 33 e0 10  srl  %o7, 0x10, %o1
a014ff58:  7f ff 37 91  call  0xa011dd9c
a014ff5c:  90 10 20 12  mov  0x12, %o0
a014ff60:  da 0c 20 87  ldub  [ %l0 + 0x87 ], %o5
a014ff64:  80 8b 60 08  btst  8, %o5
a014ff68:  02 bf ff de  be  0xa014fee0
a014ff6c:  80 8b 60 10  btst  0x10, %o5
a014ff70:  83 2e 20 10  sll  %i0, 0x10, %g1
a014ff74:  93 30 60 10  srl  %g1, 0x10, %o1
a014ff78:  7f ff 37 89  call  0xa011dd9c
a014ff7c:  90 10 20 13  mov  0x13, %o0
a014ff80:  da 0c 20 87  ldub  [ %l0 + 0x87 ], %o5
a014ff84:  80 8b 60 10  btst  0x10, %o5
a014ff88:  02 bf ff d9  be  0xa014feec
a014ff8c:  80 8b 60 20  btst  0x20, %o5
a014ff90:  91 2e 20 10  sll  %i0, 0x10, %o0
a014ff94:  93 32 20 10  srl  %o0, 0x10, %o1
a014ff98:  7f ff 37 81  call  0xa011dd9c
a014ff9c:  90 10 20 14  mov  0x14, %o0
a014ffa0:  da 0c 20 87  ldub  [ %l0 + 0x87 ], %o5
a014ffa4:  80 8b 60 20  btst  0x20, %o5
a014ffa8:  02 bf ff d4  be  0xa014fef8
a014ffac:  80 8b 60 40  btst  0x40, %o5
a014ffb0:  95 2e 20 10  sll  %i0, 0x10, %o2
a014ffb4:  93 32 a0 10  srl  %o2, 0x10, %o1
a014ffb8:  7f ff 37 79  call  0xa011dd9c
a014ffbc:  90 10 20 15  mov  0x15, %o0
a014ffc0:  da 0c 20 87  ldub  [ %l0 + 0x87 ], %o5
a014ffc4:  80 8b 60 40  btst  0x40, %o5
a014ffc8:  02 bf ff ce  be  0xa014ff00
a014ffcc:  01 00 00 00  nop
a014ffd0:  a1 2e 20 10  sll  %i0, 0x10, %l0
a014ffd4:  93 34 20 10  srl  %l0, 0x10, %o1
a014ffd8:  7f ff 37 71  call  0xa011dd9c
a014ffdc:  90 10 20 16  mov  0x16, %o0
a014ffe0:  30 bf ff c8  b,a   0xa014ff00
a014ffe4:  15 00 06 9c  sethi  %hi(0x1a7000), %o2
a014ffe8:  7f fe 3c 62  call  0xa00df170
a014ffec:  90 12 a3 68  or  %o2, 0x368, %o0	! 0x1a7368
a014fff0:  13 2a 00 a9  sethi  %hi(0xa802a400), %o1
a014fff4:  d4 12 60 9c  lduh  [ %o1 + 0x9c ], %o2	! 0xa802a49c
a014fff8:  90 10 20 10  mov  0x10, %o0
a014fffc:  92 10 20 ff  mov  0xff, %o1
a0150000:  7f ff 35 d2  call  0xa011d748
a0150004:  96 10 20 00  clr  %o3
a0150008:  31 2a 00 b3  sethi  %hi(0xa802cc00), %i0
a015000c:  da 0e 20 87  ldub  [ %i0 + 0x87 ], %o5	! 0xa802cc87
a0150010:  11 2a 00 a9  sethi  %hi(0xa802a400), %o0
a0150014:  80 8b 60 01  btst  1, %o5
a0150018:  12 80 00 1e  bne  0xa0150090
a015001c:  e0 12 20 b2  lduh  [ %o0 + 0xb2 ], %l0
a0150020:  80 8b 60 02  btst  2, %o5
a0150024:  12 80 00 35  bne  0xa01500f8
a0150028:  99 2c 20 10  sll  %l0, 0x10, %o4
a015002c:  80 8b 60 04  btst  4, %o5
a0150030:  32 80 00 2d  bne,a   0xa01500e4
a0150034:  9b 2c 20 10  sll  %l0, 0x10, %o5
a0150038:  80 8b 60 08  btst  8, %o5
a015003c:  12 80 00 25  bne  0xa01500d0
a0150040:  9f 2c 20 10  sll  %l0, 0x10, %o7
a0150044:  80 8b 60 10  btst  0x10, %o5
a0150048:  12 80 00 1d  bne  0xa01500bc
a015004c:  83 2c 20 10  sll  %l0, 0x10, %g1
a0150050:  80 8b 60 20  btst  0x20, %o5
a0150054:  12 80 00 15  bne  0xa01500a8
a0150058:  91 2c 20 10  sll  %l0, 0x10, %o0
a015005c:  80 8b 60 40  btst  0x40, %o5
a0150060:  32 80 00 2b  bne,a   0xa015010c
a0150064:  b1 2c 20 10  sll  %l0, 0x10, %i0
a0150068:  15 2a 00 a9  sethi  %hi(0xa802a400), %o2
a015006c:  d2 12 a0 b0  lduh  [ %o2 + 0xb0 ], %o1	! 0xa802a4b0
a0150070:  7f ff 37 4b  call  0xa011dd9c
a0150074:  90 10 20 18  mov  0x18, %o0
a0150078:  7f ff fe de  call  0xa014fbf0
a015007c:  90 10 20 01  mov  1, %o0
a0150080:  21 2a 00 b3  sethi  %hi(0xa802cc00), %l0
a0150084:  f0 0c 20 84  ldub  [ %l0 + 0x84 ], %i0	! 0xa802cc84
a0150088:  7f ff ff 2b  call  0xa014fd34
a015008c:  81 e8 00 00  restore
a0150090:  97 2c 20 10  sll  %l0, 0x10, %o3
a0150094:  93 32 e0 10  srl  %o3, 0x10, %o1
a0150098:  7f ff 37 41  call  0xa011dd9c
a015009c:  90 10 20 10  mov  0x10, %o0
a01500a0:  10 bf ff e0  b  0xa0150020
a01500a4:  da 0e 20 87  ldub  [ %i0 + 0x87 ], %o5
a01500a8:  93 32 20 10  srl  %o0, 0x10, %o1
a01500ac:  7f ff 37 3c  call  0xa011dd9c
a01500b0:  90 10 20 15  mov  0x15, %o0
a01500b4:  10 bf ff ea  b  0xa015005c
a01500b8:  da 0e 20 87  ldub  [ %i0 + 0x87 ], %o5
a01500bc:  93 30 60 10  srl  %g1, 0x10, %o1
a01500c0:  7f ff 37 37  call  0xa011dd9c
a01500c4:  90 10 20 14  mov  0x14, %o0
a01500c8:  10 bf ff e2  b  0xa0150050
a01500cc:  da 0e 20 87  ldub  [ %i0 + 0x87 ], %o5
a01500d0:  93 33 e0 10  srl  %o7, 0x10, %o1
a01500d4:  7f ff 37 32  call  0xa011dd9c
a01500d8:  90 10 20 13  mov  0x13, %o0
a01500dc:  10 bf ff da  b  0xa0150044
a01500e0:  da 0e 20 87  ldub  [ %i0 + 0x87 ], %o5
a01500e4:  93 33 60 10  srl  %o5, 0x10, %o1
a01500e8:  7f ff 37 2d  call  0xa011dd9c
a01500ec:  90 10 20 12  mov  0x12, %o0
a01500f0:  10 bf ff d2  b  0xa0150038
a01500f4:  da 0e 20 87  ldub  [ %i0 + 0x87 ], %o5
a01500f8:  93 33 20 10  srl  %o4, 0x10, %o1
a01500fc:  7f ff 37 28  call  0xa011dd9c
a0150100:  90 10 20 11  mov  0x11, %o0
a0150104:  10 bf ff ca  b  0xa015002c
a0150108:  da 0e 20 87  ldub  [ %i0 + 0x87 ], %o5
a015010c:  93 36 20 10  srl  %i0, 0x10, %o1
a0150110:  7f ff 37 23  call  0xa011dd9c
a0150114:  90 10 20 16  mov  0x16, %o0
a0150118:  10 bf ff d5  b  0xa015006c
a015011c:  15 2a 00 a9  sethi  %hi(0xa802a400), %o2
