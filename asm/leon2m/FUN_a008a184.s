# leon2m FUN_a008a184 0xa008a184-0xa008a210 (140 bytes)
a008a184:  92 0a 20 ff  and  %o0, 0xff, %o1
a008a188:  94 1a 60 3f  xor  %o1, 0x3f, %o2
a008a18c:  80 a0 00 0a  cmp  %g0, %o2
a008a190:  98 60 3f ff  subx  %g0, -1, %o4
a008a194:  82 1a 60 4f  xor  %o1, 0x4f, %g1
a008a198:  80 a0 00 01  cmp  %g0, %g1
a008a19c:  9a 60 3f ff  subx  %g0, -1, %o5
a008a1a0:  96 1a 60 84  xor  %o1, 0x84, %o3
a008a1a4:  80 93 00 0d  orcc  %o4, %o5, %g0
a008a1a8:  12 80 00 18  bne  0xa008a208
a008a1ac:  94 1a 60 c7  xor  %o1, 0xc7, %o2
a008a1b0:  80 a0 00 0b  cmp  %g0, %o3
a008a1b4:  9a 60 3f ff  subx  %g0, -1, %o5
a008a1b8:  80 a0 00 0a  cmp  %g0, %o2
a008a1bc:  96 60 3f ff  subx  %g0, -1, %o3
a008a1c0:  80 93 40 0b  orcc  %o5, %o3, %g0
a008a1c4:  12 80 00 11  bne  0xa008a208
a008a1c8:  13 2a 00 ab  sethi  %hi(0xa802ac00), %o1
a008a1cc:  d8 0a 63 a1  ldub  [ %o1 + 0x3a1 ], %o4	! 0xa802afa1
a008a1d0:  9a 0b 20 ff  and  %o4, 0xff, %o5
a008a1d4:  96 03 20 01  add  %o4, 1, %o3
a008a1d8:  80 a3 60 0a  cmp  %o5, 0xa
a008a1dc:  02 80 00 0b  be  0xa008a208
a008a1e0:  98 0a e0 ff  and  %o3, 0xff, %o4
a008a1e4:  15 2a 00 ab  sethi  %hi(0xa802ac00), %o2
a008a1e8:  82 12 a3 a8  or  %o2, 0x3a8, %g1	! 0xa802afa8
a008a1ec:  80 a3 20 0a  cmp  %o4, 0xa
a008a1f0:  08 80 00 05  bleu  0xa008a204
a008a1f4:  d0 28 40 0d  stb  %o0, [ %g1 + %o5 ]
a008a1f8:  90 10 20 0a  mov  0xa, %o0
a008a1fc:  10 80 00 03  b  0xa008a208
a008a200:  d0 2a 63 a1  stb  %o0, [ %o1 + 0x3a1 ]
a008a204:  d6 2a 63 a1  stb  %o3, [ %o1 + 0x3a1 ]
a008a208:  81 c3 e0 08  retl
a008a20c:  01 00 00 00  nop
