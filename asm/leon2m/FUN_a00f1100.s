# leon2m FUN_a00f1100 0xa00f1100-0xa00f1150 (80 bytes)
a00f1100:  90 0a 20 ff  and  %o0, 0xff, %o0
a00f1104:  80 a2 20 02  cmp  %o0, 2
a00f1108:  02 80 00 0b  be  0xa00f1134
a00f110c:  82 10 20 00  clr  %g1
a00f1110:  80 a2 20 03  cmp  %o0, 3
a00f1114:  02 80 00 0b  be  0xa00f1140
a00f1118:  80 a2 20 06  cmp  %o0, 6
a00f111c:  02 80 00 06  be  0xa00f1134
a00f1120:  80 a2 20 07  cmp  %o0, 7
a00f1124:  12 80 00 09  bne  0xa00f1148
a00f1128:  01 00 00 00  nop
a00f112c:  10 80 00 06  b  0xa00f1144
a00f1130:  11 2a 00 ad  sethi  %hi(0xa802b400), %o0
a00f1134:  03 2a 00 ad  sethi  %hi(0xa802b400), %g1
a00f1138:  10 80 00 04  b  0xa00f1148
a00f113c:  c2 08 63 46  ldub  [ %g1 + 0x346 ], %g1	! 0xa802b746
a00f1140:  11 2a 00 ad  sethi  %hi(0xa802b400), %o0
a00f1144:  c2 0a 23 42  ldub  [ %o0 + 0x342 ], %g1	! 0xa802b742
a00f1148:  81 c3 e0 08  retl
a00f114c:  90 08 60 ff  and  %g1, 0xff, %o0
