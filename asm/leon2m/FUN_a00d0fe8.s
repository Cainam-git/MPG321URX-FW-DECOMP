# leon2m FUN_a00d0fe8 0xa00d0fe8-0xa00d10b4 (204 bytes)
a00d0fe8:  96 10 3f 89  mov  -119, %o3
a00d0fec:  9a 10 3f e0  mov  -32, %o5
a00d0ff0:  d6 2a 20 01  stb  %o3, [ %o0 + 1 ]
a00d0ff4:  da 2a 20 07  stb  %o5, [ %o0 + 7 ]
a00d0ff8:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00d0ffc:  c2 08 62 a1  ldub  [ %g1 + 0x2a1 ], %g1	! 0xa802d2a1
a00d1000:  80 a0 60 02  cmp  %g1, 2
a00d1004:  02 80 00 18  be  0xa00d1064
a00d1008:  80 a0 60 01  cmp  %g1, 1
a00d100c:  02 80 00 1f  be  0xa00d1088
a00d1010:  80 a0 60 00  cmp  %g1, 0
a00d1014:  02 80 00 0c  be  0xa00d1044
a00d1018:  17 2a 00 b8  sethi  %hi(0xa802e000), %o3
a00d101c:  96 10 20 50  mov  0x50, %o3
a00d1020:  98 10 20 00  clr  %o4
a00d1024:  9a 10 20 00  clr  %o5
a00d1028:  c2 0b 40 08  ldub  [ %o5 + %o0 ], %g1
a00d102c:  98 03 20 01  inc  %o4
a00d1030:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00d1034:  80 a3 60 0b  cmp  %o5, 0xb
a00d1038:  0a bf ff fc  bcs  0xa00d1028
a00d103c:  96 1a c0 01  xor  %o3, %g1, %o3
a00d1040:  30 80 00 1b  b,a   0xa00d10ac
a00d1044:  82 12 e1 f0  or  %o3, 0x1f0, %g1
a00d1048:  da 08 60 12  ldub  [ %g1 + 0x12 ], %o5
a00d104c:  da 2a 20 08  stb  %o5, [ %o0 + 8 ]
a00d1050:  d8 08 60 13  ldub  [ %g1 + 0x13 ], %o4
a00d1054:  d8 2a 20 09  stb  %o4, [ %o0 + 9 ]
a00d1058:  da 08 60 14  ldub  [ %g1 + 0x14 ], %o5
a00d105c:  10 bf ff f0  b  0xa00d101c
a00d1060:  da 2a 20 0a  stb  %o5, [ %o0 + 0xa ]
a00d1064:  17 2a 00 b8  sethi  %hi(0xa802e000), %o3
a00d1068:  82 12 e1 f0  or  %o3, 0x1f0, %g1	! 0xa802e1f0
a00d106c:  da 08 60 06  ldub  [ %g1 + 6 ], %o5
a00d1070:  da 2a 20 08  stb  %o5, [ %o0 + 8 ]
a00d1074:  d8 08 60 07  ldub  [ %g1 + 7 ], %o4
a00d1078:  d8 2a 20 09  stb  %o4, [ %o0 + 9 ]
a00d107c:  da 08 60 08  ldub  [ %g1 + 8 ], %o5
a00d1080:  10 bf ff e7  b  0xa00d101c
a00d1084:  da 2a 20 0a  stb  %o5, [ %o0 + 0xa ]
a00d1088:  17 2a 00 b8  sethi  %hi(0xa802e000), %o3
a00d108c:  82 12 e1 f0  or  %o3, 0x1f0, %g1	! 0xa802e1f0
a00d1090:  da 08 60 09  ldub  [ %g1 + 9 ], %o5
a00d1094:  da 2a 20 08  stb  %o5, [ %o0 + 8 ]
a00d1098:  d8 08 60 0a  ldub  [ %g1 + 0xa ], %o4
a00d109c:  d8 2a 20 09  stb  %o4, [ %o0 + 9 ]
a00d10a0:  da 08 60 0b  ldub  [ %g1 + 0xb ], %o5
a00d10a4:  10 bf ff de  b  0xa00d101c
a00d10a8:  da 2a 20 0a  stb  %o5, [ %o0 + 0xa ]
a00d10ac:  81 c3 e0 08  retl
a00d10b0:  d6 2a 20 0b  stb  %o3, [ %o0 + 0xb ]
