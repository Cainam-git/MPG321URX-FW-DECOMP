# leon2m FUN_a0133fbc 0xa0133fbc-0xa0134068 (172 bytes)  [FUN_a0134060 = unreachable ret/restore tail, merged]
a0133fbc:  9d e3 bf 98  save  %sp, -104, %sp
a0133fc0:  7f fe a5 95  call  0xa00dd614
a0133fc4:  90 10 20 20  mov  0x20, %o0
a0133fc8:  80 8a 20 ff  btst  0xff, %o0
a0133fcc:  a2 10 00 18  mov  %i0, %l1
a0133fd0:  a0 10 00 19  mov  %i1, %l0
a0133fd4:  11 00 06 94  sethi  %hi(0x1a5000), %o0
a0133fd8:  b0 10 20 0e  mov  0xe, %i0
a0133fdc:  b6 10 20 00  clr  %i3
a0133fe0:  b8 10 20 01  mov  1, %i4
a0133fe4:  b4 0e a0 ff  and  %i2, 0xff, %i2
a0133fe8:  90 12 23 f8  or  %o0, 0x3f8, %o0
a0133fec:  b2 0c 60 ff  and  %l1, 0xff, %i1
a0133ff0:  a4 10 20 00  clr  %l2
a0133ff4:  12 80 00 14  bne  0xa0134044
a0133ff8:  a6 10 20 00  clr  %l3
a0133ffc:  83 2c 20 10  sll  %l0, 0x10, %g1
a0134000:  a1 30 60 10  srl  %g1, 0x10, %l0
a0134004:  90 10 20 01  mov  1, %o0
a0134008:  92 10 00 19  mov  %i1, %o1
a013400c:  94 10 20 a0  mov  0xa0, %o2
a0134010:  80 a4 20 80  cmp  %l0, 0x80
a0134014:  08 80 00 03  bleu  0xa0134020
a0134018:  98 10 20 01  mov  1, %o4
a013401c:  a4 10 20 01  mov  1, %l2
a0134020:  67 fd 6c f5  call  0x4008f3f4
a0134024:  96 0c a0 01  and  %l2, 1, %o3
a0134028:  80 a4 21 00  cmp  %l0, 0x100
a013402c:  38 80 00 02  bgu,a   0xa0134034
a0134030:  a6 10 20 01  mov  1, %l3
a0134034:  80 8c e0 ff  btst  0xff, %l3
a0134038:  02 80 00 09  be  0xa013405c
a013403c:  01 00 00 00  nop
a0134040:  30 80 00 05  b,a   0xa0134054
a0134044:  7f fe ac 4b  call  0xa00df170
a0134048:  92 10 00 19  mov  %i1, %o1
a013404c:  10 bf ff ed  b  0xa0134000
a0134050:  83 2c 20 10  sll  %l0, 0x10, %g1
a0134054:  67 fd 6c e8  call  0x4008f3f4
a0134058:  81 e8 00 00  restore
a013405c:  01 00 00 00  nop
a0134060:  81 c7 e0 08  ret
a0134064:  81 e8 00 00  restore
