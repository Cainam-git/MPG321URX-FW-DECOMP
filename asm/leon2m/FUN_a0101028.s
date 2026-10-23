# leon2m FUN_a0101028 0xa0101028-0xa01010f4 (204 bytes)
a0101028:  98 02 3f f4  add  %o0, -12, %o4
a010102c:  96 0b 20 ff  and  %o4, 0xff, %o3
a0101030:  80 a2 e0 02  cmp  %o3, 2
a0101034:  90 0a 20 ff  and  %o0, 0xff, %o0
a0101038:  92 60 20 00  subx  %g0, 0, %o1
a010103c:  94 1a 20 06  xor  %o0, 6, %o2
a0101040:  80 a0 00 0a  cmp  %g0, %o2
a0101044:  9a 0a 60 01  and  %o1, 1, %o5
a0101048:  82 60 3f ff  subx  %g0, -1, %g1
a010104c:  98 1a 20 07  xor  %o0, 7, %o4
a0101050:  80 93 40 01  orcc  %o5, %g1, %g0
a0101054:  12 80 00 0a  bne  0xa010107c
a0101058:  96 1a 20 12  xor  %o0, 0x12, %o3
a010105c:  80 a0 00 0c  cmp  %g0, %o4
a0101060:  9a 60 3f ff  subx  %g0, -1, %o5
a0101064:  80 a0 00 0b  cmp  %g0, %o3
a0101068:  82 60 3f ff  subx  %g0, -1, %g1
a010106c:  94 1a 20 13  xor  %o0, 0x13, %o2
a0101070:  80 93 40 01  orcc  %o5, %g1, %g0
a0101074:  02 80 00 04  be  0xa0101084
a0101078:  98 1a 20 18  xor  %o0, 0x18, %o4
a010107c:  10 80 00 1c  b  0xa01010ec
a0101080:  98 10 20 01  mov  1, %o4
a0101084:  80 a0 00 0a  cmp  %g0, %o2
a0101088:  82 60 3f ff  subx  %g0, -1, %g1
a010108c:  80 a0 00 0c  cmp  %g0, %o4
a0101090:  92 60 3f ff  subx  %g0, -1, %o1
a0101094:  96 1a 20 19  xor  %o0, 0x19, %o3
a0101098:  80 90 40 09  orcc  %g1, %o1, %g0
a010109c:  12 bf ff f8  bne  0xa010107c
a01010a0:  94 1a 20 20  xor  %o0, 0x20, %o2
a01010a4:  80 a0 00 0b  cmp  %g0, %o3
a01010a8:  96 60 3f ff  subx  %g0, -1, %o3
a01010ac:  80 a0 00 0a  cmp  %g0, %o2
a01010b0:  94 60 3f ff  subx  %g0, -1, %o2
a01010b4:  92 1a 20 21  xor  %o0, 0x21, %o1
a01010b8:  80 92 c0 0a  orcc  %o3, %o2, %g0
a01010bc:  12 bf ff f0  bne  0xa010107c
a01010c0:  98 1a 20 26  xor  %o0, 0x26, %o4
a01010c4:  80 a0 00 09  cmp  %g0, %o1
a01010c8:  9a 60 3f ff  subx  %g0, -1, %o5
a01010cc:  80 a0 00 0c  cmp  %g0, %o4
a01010d0:  92 60 3f ff  subx  %g0, -1, %o1
a01010d4:  80 93 40 09  orcc  %o5, %o1, %g0
a01010d8:  12 bf ff e9  bne  0xa010107c
a01010dc:  98 10 20 00  clr  %o4
a01010e0:  80 a2 20 27  cmp  %o0, 0x27
a01010e4:  22 80 00 02  be,a   0xa01010ec
a01010e8:  98 10 20 01  mov  1, %o4
a01010ec:  81 c3 e0 08  retl
a01010f0:  90 10 00 0c  mov  %o4, %o0
