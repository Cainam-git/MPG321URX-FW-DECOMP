# leon2m FUN_a0100468 0xa0100468-0xa01004cc (100 bytes)
a0100468:  82 02 60 1f  add  %o1, 0x1f, %g1
a010046c:  92 08 60 ff  and  %g1, 0xff, %o1
a0100470:  80 a2 60 01  cmp  %o1, 1
a0100474:  9a 10 00 0a  mov  %o2, %o5
a0100478:  18 80 00 12  bgu  0xa01004c0
a010047c:  82 10 00 08  mov  %o0, %g1
a0100480:  90 0a 20 ff  and  %o0, 0xff, %o0
a0100484:  92 10 20 ab  mov  0xab, %o1
a0100488:  94 10 20 04  mov  4, %o2
a010048c:  80 8b 60 ff  btst  0xff, %o5
a0100490:  02 80 00 05  be  0xa01004a4
a0100494:  96 10 20 01  mov  1, %o3
a0100498:  82 13 c0 00  mov  %o7, %g1
a010049c:  7f ff c5 b0  call  0xa00f1b5c
a01004a0:  9e 10 40 00  mov  %g1, %o7
a01004a4:  90 08 60 ff  and  %g1, 0xff, %o0
a01004a8:  92 10 20 ab  mov  0xab, %o1
a01004ac:  94 10 20 04  mov  4, %o2
a01004b0:  96 10 20 00  clr  %o3
a01004b4:  82 13 c0 00  mov  %o7, %g1
a01004b8:  7f ff c5 a9  call  0xa00f1b5c
a01004bc:  9e 10 40 00  mov  %g1, %o7
a01004c0:  01 00 00 00  nop
a01004c4:  81 c3 e0 08  retl
a01004c8:  01 00 00 00  nop
