# leon2m FUN_a01010f4 0xa01010f4-0xa01011c0 (204 bytes)
a01010f4:  98 02 3f f6  add  %o0, -10, %o4
a01010f8:  96 0b 20 ff  and  %o4, 0xff, %o3
a01010fc:  80 a2 e0 02  cmp  %o3, 2
a0101100:  90 0a 20 ff  and  %o0, 0xff, %o0
a0101104:  92 60 20 00  subx  %g0, 0, %o1
a0101108:  94 1a 20 04  xor  %o0, 4, %o2
a010110c:  80 a0 00 0a  cmp  %g0, %o2
a0101110:  9a 0a 60 01  and  %o1, 1, %o5
a0101114:  82 60 3f ff  subx  %g0, -1, %g1
a0101118:  98 1a 20 05  xor  %o0, 5, %o4
a010111c:  80 93 40 01  orcc  %o5, %g1, %g0
a0101120:  12 80 00 0a  bne  0xa0101148
a0101124:  96 1a 20 10  xor  %o0, 0x10, %o3
a0101128:  80 a0 00 0c  cmp  %g0, %o4
a010112c:  9a 60 3f ff  subx  %g0, -1, %o5
a0101130:  80 a0 00 0b  cmp  %g0, %o3
a0101134:  82 60 3f ff  subx  %g0, -1, %g1
a0101138:  94 1a 20 11  xor  %o0, 0x11, %o2
a010113c:  80 93 40 01  orcc  %o5, %g1, %g0
a0101140:  02 80 00 04  be  0xa0101150
a0101144:  98 1a 20 16  xor  %o0, 0x16, %o4
a0101148:  10 80 00 1c  b  0xa01011b8
a010114c:  98 10 20 01  mov  1, %o4
a0101150:  80 a0 00 0a  cmp  %g0, %o2
a0101154:  82 60 3f ff  subx  %g0, -1, %g1
a0101158:  80 a0 00 0c  cmp  %g0, %o4
a010115c:  92 60 3f ff  subx  %g0, -1, %o1
a0101160:  96 1a 20 17  xor  %o0, 0x17, %o3
a0101164:  80 90 40 09  orcc  %g1, %o1, %g0
a0101168:  12 bf ff f8  bne  0xa0101148
a010116c:  94 1a 20 1e  xor  %o0, 0x1e, %o2
a0101170:  80 a0 00 0b  cmp  %g0, %o3
a0101174:  96 60 3f ff  subx  %g0, -1, %o3
a0101178:  80 a0 00 0a  cmp  %g0, %o2
a010117c:  94 60 3f ff  subx  %g0, -1, %o2
a0101180:  92 1a 20 1f  xor  %o0, 0x1f, %o1
a0101184:  80 92 c0 0a  orcc  %o3, %o2, %g0
a0101188:  12 bf ff f0  bne  0xa0101148
a010118c:  98 1a 20 24  xor  %o0, 0x24, %o4
a0101190:  80 a0 00 09  cmp  %g0, %o1
a0101194:  9a 60 3f ff  subx  %g0, -1, %o5
a0101198:  80 a0 00 0c  cmp  %g0, %o4
a010119c:  92 60 3f ff  subx  %g0, -1, %o1
a01011a0:  80 93 40 09  orcc  %o5, %o1, %g0
a01011a4:  12 bf ff e9  bne  0xa0101148
a01011a8:  98 10 20 00  clr  %o4
a01011ac:  80 a2 20 25  cmp  %o0, 0x25
a01011b0:  22 80 00 02  be,a   0xa01011b8
a01011b4:  98 10 20 01  mov  1, %o4
a01011b8:  81 c3 e0 08  retl
a01011bc:  90 10 00 0c  mov  %o4, %o0
