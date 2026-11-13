# leon2s FUN_a0086030 0xa0086030-0xa0086154 (292 bytes)
a0086030:  9d e3 bf 98  save  %sp, -104, %sp
a0086034:  a0 0e 20 ff  and  %i0, 0xff, %l0
a0086038:  90 10 00 10  mov  %l0, %o0
a008603c:  92 10 20 31  mov  0x31, %o1
a0086040:  40 00 86 2f  call  0xa00a78fc
a0086044:  94 10 20 71  mov  0x71, %o2
a0086048:  95 36 a0 10  srl  %i2, 0x10, %o2
a008604c:  82 0e 60 f0  and  %i1, 0xf0, %g1
a0086050:  94 0a a0 0f  and  %o2, 0xf, %o2
a0086054:  94 10 40 0a  or  %g1, %o2, %o2
a0086058:  90 10 00 10  mov  %l0, %o0
a008605c:  40 00 86 28  call  0xa00a78fc
a0086060:  92 10 20 30  mov  0x30, %o1
a0086064:  95 36 a0 08  srl  %i2, 8, %o2
a0086068:  94 0a a0 ff  and  %o2, 0xff, %o2
a008606c:  90 10 00 10  mov  %l0, %o0
a0086070:  40 00 86 23  call  0xa00a78fc
a0086074:  92 10 20 30  mov  0x30, %o1
a0086078:  94 0e a0 ff  and  %i2, 0xff, %o2
a008607c:  90 10 00 10  mov  %l0, %o0
a0086080:  40 00 86 1f  call  0xa00a78fc
a0086084:  92 10 20 30  mov  0x30, %o1
a0086088:  b2 0e 60 ff  and  %i1, 0xff, %i1
a008608c:  82 1e 60 80  xor  %i1, 0x80, %g1
a0086090:  80 a0 00 01  cmp  %g0, %g1
a0086094:  9a 60 3f ff  subx  %g0, -1, %o5
a0086098:  82 1e 60 40  xor  %i1, 0x40, %g1
a008609c:  80 a0 00 01  cmp  %g0, %g1
a00860a0:  82 60 3f ff  subx  %g0, -1, %g1
a00860a4:  80 93 40 01  orcc  %o5, %g1, %g0
a00860a8:  12 80 00 05  bne  0xa00860bc
a00860ac:  b4 10 00 1b  mov  %i3, %i2
a00860b0:  80 a6 60 00  cmp  %i1, 0
a00860b4:  12 80 00 17  bne  0xa0086110
a00860b8:  94 0e e0 ff  and  %i3, 0xff, %o2
a00860bc:  90 10 00 10  mov  %l0, %o0
a00860c0:  92 10 20 30  mov  0x30, %o1
a00860c4:  40 00 86 0e  call  0xa00a78fc
a00860c8:  94 0e a0 ff  and  %i2, 0xff, %o2
a00860cc:  80 8e e0 80  btst  0x80, %i3
a00860d0:  12 80 00 0e  bne  0xa0086108
a00860d4:  b6 10 20 00  clr  %i3
a00860d8:  82 0e e0 ff  and  %i3, 0xff, %g1
a00860dc:  d4 0f 00 01  ldub  [ %i4 + %g1 ], %o2
a00860e0:  90 10 00 10  mov  %l0, %o0
a00860e4:  40 00 86 06  call  0xa00a78fc
a00860e8:  92 10 20 30  mov  0x30, %o1
a00860ec:  b6 06 e0 01  inc  %i3
a00860f0:  83 2e a0 18  sll  %i2, 0x18, %g1
a00860f4:  83 38 60 18  sra  %g1, 0x18, %g1
a00860f8:  9a 0e e0 ff  and  %i3, 0xff, %o5
a00860fc:  80 a3 40 01  cmp  %o5, %g1
a0086100:  04 bf ff f7  ble  0xa00860dc
a0086104:  82 0e e0 ff  and  %i3, 0xff, %g1
a0086108:  10 80 00 0c  b  0xa0086138
a008610c:  90 0e 20 ff  and  %i0, 0xff, %o0
a0086110:  90 10 00 10  mov  %l0, %o0
a0086114:  40 00 85 fa  call  0xa00a78fc
a0086118:  92 10 20 30  mov  0x30, %o1
a008611c:  83 2e e0 18  sll  %i3, 0x18, %g1
a0086120:  90 10 00 10  mov  %l0, %o0
a0086124:  92 10 20 31  mov  0x31, %o1
a0086128:  80 a0 60 00  cmp  %g1, 0
a008612c:  02 80 00 05  be  0xa0086140
a0086130:  94 10 20 03  mov  3, %o2
a0086134:  90 10 00 10  mov  %l0, %o0
a0086138:  92 10 20 31  mov  0x31, %o1
a008613c:  94 10 20 0b  mov  0xb, %o2
a0086140:  40 00 85 ef  call  0xa00a78fc
a0086144:  b0 10 20 01  mov  1, %i0
a0086148:  40 00 ad 93  call  0xa00b1794
a008614c:  81 e8 00 00  restore
a0086150:  01 00 00 00  nop
