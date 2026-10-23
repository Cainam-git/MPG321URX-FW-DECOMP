# leon2m FUN_a01011c0 0xa01011c0-0xa010128c (204 bytes)
a01011c0:  98 02 3f f8  add  %o0, -8, %o4
a01011c4:  96 0b 20 ff  and  %o4, 0xff, %o3
a01011c8:  80 a2 e0 02  cmp  %o3, 2
a01011cc:  90 0a 20 ff  and  %o0, 0xff, %o0
a01011d0:  92 60 20 00  subx  %g0, 0, %o1
a01011d4:  94 1a 20 02  xor  %o0, 2, %o2
a01011d8:  80 a0 00 0a  cmp  %g0, %o2
a01011dc:  9a 0a 60 01  and  %o1, 1, %o5
a01011e0:  82 60 3f ff  subx  %g0, -1, %g1
a01011e4:  98 1a 20 03  xor  %o0, 3, %o4
a01011e8:  80 93 40 01  orcc  %o5, %g1, %g0
a01011ec:  12 80 00 0a  bne  0xa0101214
a01011f0:  96 1a 20 0e  xor  %o0, 0xe, %o3
a01011f4:  80 a0 00 0c  cmp  %g0, %o4
a01011f8:  9a 60 3f ff  subx  %g0, -1, %o5
a01011fc:  80 a0 00 0b  cmp  %g0, %o3
a0101200:  82 60 3f ff  subx  %g0, -1, %g1
a0101204:  94 1a 20 0f  xor  %o0, 0xf, %o2
a0101208:  80 93 40 01  orcc  %o5, %g1, %g0
a010120c:  02 80 00 04  be  0xa010121c
a0101210:  98 1a 20 14  xor  %o0, 0x14, %o4
a0101214:  10 80 00 1c  b  0xa0101284
a0101218:  98 10 20 01  mov  1, %o4
a010121c:  80 a0 00 0a  cmp  %g0, %o2
a0101220:  82 60 3f ff  subx  %g0, -1, %g1
a0101224:  80 a0 00 0c  cmp  %g0, %o4
a0101228:  92 60 3f ff  subx  %g0, -1, %o1
a010122c:  96 1a 20 15  xor  %o0, 0x15, %o3
a0101230:  80 90 40 09  orcc  %g1, %o1, %g0
a0101234:  12 bf ff f8  bne  0xa0101214
a0101238:  94 1a 20 1c  xor  %o0, 0x1c, %o2
a010123c:  80 a0 00 0b  cmp  %g0, %o3
a0101240:  96 60 3f ff  subx  %g0, -1, %o3
a0101244:  80 a0 00 0a  cmp  %g0, %o2
a0101248:  94 60 3f ff  subx  %g0, -1, %o2
a010124c:  92 1a 20 1d  xor  %o0, 0x1d, %o1
a0101250:  80 92 c0 0a  orcc  %o3, %o2, %g0
a0101254:  12 bf ff f0  bne  0xa0101214
a0101258:  98 1a 20 22  xor  %o0, 0x22, %o4
a010125c:  80 a0 00 09  cmp  %g0, %o1
a0101260:  9a 60 3f ff  subx  %g0, -1, %o5
a0101264:  80 a0 00 0c  cmp  %g0, %o4
a0101268:  92 60 3f ff  subx  %g0, -1, %o1
a010126c:  80 93 40 09  orcc  %o5, %o1, %g0
a0101270:  12 bf ff e9  bne  0xa0101214
a0101274:  98 10 20 00  clr  %o4
a0101278:  80 a2 20 23  cmp  %o0, 0x23
a010127c:  22 80 00 02  be,a   0xa0101284
a0101280:  98 10 20 01  mov  1, %o4
a0101284:  81 c3 e0 08  retl
a0101288:  90 10 00 0c  mov  %o4, %o0
