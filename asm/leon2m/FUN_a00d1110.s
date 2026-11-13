# leon2m FUN_a00d1110 0xa00d1110-0xa00d1184 (116 bytes)
a00d1110:  94 10 3f 93  mov  -109, %o2
a00d1114:  d4 2a 20 01  stb  %o2, [ %o0 + 1 ]
a00d1118:  9a 10 3f e0  mov  -32, %o5
a00d111c:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00d1120:  da 2a 20 07  stb  %o5, [ %o0 + 7 ]
a00d1124:  94 10 62 74  or  %g1, 0x274, %o2
a00d1128:  96 10 20 00  clr  %o3
a00d112c:  82 02 00 0b  add  %o0, %o3, %g1
a00d1130:  9a 02 c0 0a  add  %o3, %o2, %o5
a00d1134:  d8 0b 60 03  ldub  [ %o5 + 3 ], %o4
a00d1138:  96 02 e0 01  inc  %o3
a00d113c:  80 a2 e0 0c  cmp  %o3, 0xc
a00d1140:  04 bf ff fb  ble  0xa00d112c
a00d1144:  d8 28 60 08  stb  %o4, [ %g1 + 8 ]
a00d1148:  d4 0a 20 01  ldub  [ %o0 + 1 ], %o2
a00d114c:  96 0a a0 7f  and  %o2, 0x7f, %o3
a00d1150:  94 82 e0 02  addcc  %o3, 2, %o2
a00d1154:  96 10 20 50  mov  0x50, %o3
a00d1158:  02 80 00 09  be  0xa00d117c
a00d115c:  98 10 20 00  clr  %o4
a00d1160:  9a 10 20 00  clr  %o5
a00d1164:  c2 0b 40 08  ldub  [ %o5 + %o0 ], %g1
a00d1168:  98 03 20 01  inc  %o4
a00d116c:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00d1170:  80 a3 40 0a  cmp  %o5, %o2
a00d1174:  0a bf ff fc  bcs  0xa00d1164
a00d1178:  96 1a c0 01  xor  %o3, %g1, %o3
a00d117c:  81 c3 e0 08  retl
a00d1180:  d6 2a 20 15  stb  %o3, [ %o0 + 0x15 ]
