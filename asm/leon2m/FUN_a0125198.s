# leon2m FUN_a0125198 0xa0125198-0xa0125230 (152 bytes)
a0125198:  03 00 06 90  sethi  %hi(0x1a4000), %g1
a012519c:  90 0a 20 ff  and  %o0, 0xff, %o0
a01251a0:  94 10 62 a8  or  %g1, 0x2a8, %o2
a01251a4:  92 10 3f ff  mov  -1, %o1
a01251a8:  96 10 20 00  clr  %o3
a01251ac:  98 10 20 00  clr  %o4
a01251b0:  82 5b 20 16  smul  %o4, 0x16, %g1
a01251b4:  da 0a 80 01  ldub  [ %o2 + %g1 ], %o5
a01251b8:  80 a3 40 08  cmp  %o5, %o0
a01251bc:  02 80 00 12  be  0xa0125204
a01251c0:  80 a3 20 07  cmp  %o4, 7
a01251c4:  96 02 e0 01  inc  %o3
a01251c8:  98 0a e0 ff  and  %o3, 0xff, %o4
a01251cc:  80 a3 20 07  cmp  %o4, 7
a01251d0:  28 bf ff f9  bleu,a   0xa01251b4
a01251d4:  82 5b 20 16  smul  %o4, 0x16, %g1
a01251d8:  80 a2 20 13  cmp  %o0, 0x13
a01251dc:  22 80 00 13  be,a   0xa0125228
a01251e0:  92 10 3f fd  mov  -3, %o1
a01251e4:  80 a2 20 13  cmp  %o0, 0x13
a01251e8:  14 80 00 0e  bg  0xa0125220
a01251ec:  80 a2 20 14  cmp  %o0, 0x14
a01251f0:  80 a2 20 12  cmp  %o0, 0x12
a01251f4:  12 80 00 0d  bne  0xa0125228
a01251f8:  01 00 00 00  nop
a01251fc:  10 80 00 0b  b  0xa0125228
a0125200:  92 10 3f fc  mov  -4, %o1	! 0xfffffffc
a0125204:  08 80 00 09  bleu  0xa0125228
a0125208:  92 10 00 0b  mov  %o3, %o1
a012520c:  80 a2 20 13  cmp  %o0, 0x13
a0125210:  12 bf ff f6  bne  0xa01251e8
a0125214:  01 00 00 00  nop
a0125218:  10 80 00 04  b  0xa0125228
a012521c:  92 10 3f fd  mov  -3, %o1	! 0xfffffffd
a0125220:  22 80 00 02  be,a   0xa0125228
a0125224:  92 10 3f fe  mov  -2, %o1
a0125228:  81 c3 e0 08  retl
a012522c:  90 0a 60 ff  and  %o1, 0xff, %o0
