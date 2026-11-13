# leon2s FUN_a00ad828 0xa00ad828-0xa00ad8f0 (200 bytes)
a00ad828:  82 02 3f f4  add  %o0, -12, %g1
a00ad82c:  82 08 60 ff  and  %g1, 0xff, %g1
a00ad830:  80 a0 60 02  cmp  %g1, 2
a00ad834:  90 0a 20 ff  and  %o0, 0xff, %o0
a00ad838:  9a 60 20 00  subx  %g0, 0, %o5
a00ad83c:  82 1a 20 06  xor  %o0, 6, %g1
a00ad840:  80 a0 00 01  cmp  %g0, %g1
a00ad844:  9a 0b 60 01  and  %o5, 1, %o5
a00ad848:  82 60 3f ff  subx  %g0, -1, %g1
a00ad84c:  96 1a 20 07  xor  %o0, 7, %o3
a00ad850:  80 93 40 01  orcc  %o5, %g1, %g0
a00ad854:  12 80 00 24  bne  0xa00ad8e4
a00ad858:  94 1a 20 12  xor  %o0, 0x12, %o2
a00ad85c:  80 a0 00 0b  cmp  %g0, %o3
a00ad860:  9a 60 3f ff  subx  %g0, -1, %o5
a00ad864:  80 a0 00 0a  cmp  %g0, %o2
a00ad868:  82 60 3f ff  subx  %g0, -1, %g1
a00ad86c:  98 1a 20 13  xor  %o0, 0x13, %o4
a00ad870:  80 93 40 01  orcc  %o5, %g1, %g0
a00ad874:  12 80 00 1c  bne  0xa00ad8e4
a00ad878:  96 1a 20 18  xor  %o0, 0x18, %o3
a00ad87c:  80 a0 00 0c  cmp  %g0, %o4
a00ad880:  9a 60 3f ff  subx  %g0, -1, %o5
a00ad884:  80 a0 00 0b  cmp  %g0, %o3
a00ad888:  82 60 3f ff  subx  %g0, -1, %g1
a00ad88c:  94 1a 20 19  xor  %o0, 0x19, %o2
a00ad890:  80 93 40 01  orcc  %o5, %g1, %g0
a00ad894:  12 80 00 14  bne  0xa00ad8e4
a00ad898:  92 1a 20 20  xor  %o0, 0x20, %o1
a00ad89c:  80 a0 00 0a  cmp  %g0, %o2
a00ad8a0:  9a 60 3f ff  subx  %g0, -1, %o5
a00ad8a4:  80 a0 00 09  cmp  %g0, %o1
a00ad8a8:  82 60 3f ff  subx  %g0, -1, %g1
a00ad8ac:  96 1a 20 21  xor  %o0, 0x21, %o3
a00ad8b0:  80 93 40 01  orcc  %o5, %g1, %g0
a00ad8b4:  12 80 00 0c  bne  0xa00ad8e4
a00ad8b8:  98 1a 20 26  xor  %o0, 0x26, %o4
a00ad8bc:  80 a0 00 0b  cmp  %g0, %o3
a00ad8c0:  9a 60 3f ff  subx  %g0, -1, %o5
a00ad8c4:  80 a0 00 0c  cmp  %g0, %o4
a00ad8c8:  82 60 3f ff  subx  %g0, -1, %g1
a00ad8cc:  80 93 40 01  orcc  %o5, %g1, %g0
a00ad8d0:  12 80 00 05  bne  0xa00ad8e4
a00ad8d4:  98 10 20 00  clr  %o4
a00ad8d8:  80 a2 20 27  cmp  %o0, 0x27
a00ad8dc:  12 80 00 03  bne  0xa00ad8e8
a00ad8e0:  01 00 00 00  nop
a00ad8e4:  98 10 20 01  mov  1, %o4	! 0x1
a00ad8e8:  81 c3 e0 08  retl
a00ad8ec:  90 10 00 0c  mov  %o4, %o0
