# leon2m FUN_a0110fb4 0xa0110fb4-0xa0111028 (116 bytes)
a0110fb4:  9d e3 bf 98  save  %sp, -104, %sp
a0110fb8:  17 00 06 8b  sethi  %hi(0x1a2c00), %o3
a0110fbc:  7f ff 38 6d  call  0xa00df170
a0110fc0:  90 12 e3 00  or  %o3, 0x300, %o0	! 0x1a2f00
a0110fc4:  15 33 c0 47  sethi  %hi(0xcf011c00), %o2
a0110fc8:  92 12 a3 80  or  %o2, 0x380, %o1	! 0xcf011f80
a0110fcc:  9a 10 20 81  mov  0x81, %o5
a0110fd0:  da 22 40 00  st  %o5, [ %o1 ]
a0110fd4:  67 fd f5 26  call  0x4008e46c
a0110fd8:  90 10 20 14  mov  0x14, %o0
a0110fdc:  a4 10 00 08  mov  %o0, %l2
a0110fe0:  11 2d c2 00  sethi  %hi(0xb7080000), %o0
a0110fe4:  90 12 21 60  or  %o0, 0x160, %o0	! 0xb7080160
a0110fe8:  67 fd ec 9d  call  0x4008c25c
a0110fec:  93 2c a0 05  sll  %l2, 5, %o1
a0110ff0:  03 00 06 6b  sethi  %hi(0x19ac00), %g1
a0110ff4:  a2 10 63 00  or  %g1, 0x300, %l1	! 0x19af00
a0110ff8:  a0 10 20 00  clr  %l0
a0110ffc:  90 10 00 11  mov  %l1, %o0
a0111000:  92 04 00 12  add  %l0, %l2, %o1
a0111004:  94 10 20 01  mov  1, %o2
a0111008:  40 00 0b ab  call  0xa0113eb4
a011100c:  96 10 20 01  mov  1, %o3
a0111010:  a0 04 20 01  inc  %l0
a0111014:  80 a4 24 00  cmp  %l0, 0x400
a0111018:  0a bf ff f9  bcs  0xa0110ffc
a011101c:  a2 04 60 20  add  %l1, 0x20, %l1
a0111020:  81 c7 e0 08  ret
a0111024:  81 e8 00 00  restore
