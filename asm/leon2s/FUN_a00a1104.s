# leon2s FUN_a00a1104 0xa00a1104-0xa00a1150 (76 bytes)
a00a1104:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a00a1108:  82 10 63 e0  or  %g1, 0x3e0, %g1	! 0xa807d7e0
a00a110c:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a1110:  9a 00 61 62  add  %g1, 0x162, %o5
a00a1114:  92 5a 21 90  smul  %o0, 0x190, %o1
a00a1118:  82 02 40 01  add  %o1, %g1, %g1
a00a111c:  92 02 40 0d  add  %o1, %o5, %o1
a00a1120:  9a 10 20 01  mov  1, %o5
a00a1124:  d8 08 61 83  ldub  [ %g1 + 0x183 ], %o4
a00a1128:  da 28 61 82  stb  %o5, [ %g1 + 0x182 ]
a00a112c:  80 a3 20 00  cmp  %o4, 0
a00a1130:  12 80 00 05  bne  0xa00a1144
a00a1134:  da 28 61 81  stb  %o5, [ %g1 + 0x181 ]
a00a1138:  82 13 c0 00  mov  %o7, %g1
a00a113c:  7f ff fc 4b  call  0xa00a0268
a00a1140:  9e 10 40 00  mov  %g1, %o7
a00a1144:  01 00 00 00  nop
a00a1148:  81 c3 e0 08  retl
a00a114c:  01 00 00 00  nop
