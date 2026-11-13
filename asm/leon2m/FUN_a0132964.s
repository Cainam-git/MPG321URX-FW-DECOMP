# leon2m FUN_a0132964 0xa0132964-0xa0132a14 (176 bytes)
a0132964:  9d e3 bf 98  save  %sp, -104, %sp
a0132968:  7f ff 2b ae  call  0xa00fd820
a013296c:  90 0e 20 ff  and  %i0, 0xff, %o0
a0132970:  90 0a 20 ff  and  %o0, 0xff, %o0
a0132974:  80 a2 20 b1  cmp  %o0, 0xb1
a0132978:  b0 10 20 00  clr  %i0
a013297c:  02 80 00 1f  be  0xa01329f8
a0132980:  a0 10 3f ff  mov  -1, %l0
a0132984:  92 1a 20 31  xor  %o0, 0x31, %o1
a0132988:  80 a0 00 09  cmp  %g0, %o1
a013298c:  98 60 3f ff  subx  %g0, -1, %o4
a0132990:  82 1a 20 41  xor  %o0, 0x41, %g1
a0132994:  80 a0 00 01  cmp  %g0, %g1
a0132998:  9a 60 3f ff  subx  %g0, -1, %o5
a013299c:  80 93 00 0d  orcc  %o4, %o5, %g0
a01329a0:  12 80 00 0c  bne  0xa01329d0
a01329a4:  80 a2 20 51  cmp  %o0, 0x51
a01329a8:  9a 1a 20 51  xor  %o0, 0x51, %o5
a01329ac:  80 a0 00 0d  cmp  %g0, %o5
a01329b0:  96 60 3f ff  subx  %g0, -1, %o3
a01329b4:  9e 1a 20 61  xor  %o0, 0x61, %o7
a01329b8:  80 a0 00 0f  cmp  %g0, %o7
a01329bc:  94 60 3f ff  subx  %g0, -1, %o2
a01329c0:  80 92 c0 0a  orcc  %o3, %o2, %g0
a01329c4:  22 80 00 12  be,a   0xa0132a0c
a01329c8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a01329cc:  80 a2 20 51  cmp  %o0, 0x51
a01329d0:  02 80 00 08  be  0xa01329f0
a01329d4:  80 a2 20 61  cmp  %o0, 0x61
a01329d8:  22 80 00 02  be,a   0xa01329e0
a01329dc:  a0 10 20 01  mov  1, %l0
a01329e0:  40 00 3d c1  call  0xa01420e4
a01329e4:  90 0c 20 ff  and  %l0, 0xff, %o0
a01329e8:  10 80 00 08  b  0xa0132a08
a01329ec:  b0 10 00 08  mov  %o0, %i0
a01329f0:  10 bf ff fc  b  0xa01329e0
a01329f4:  a0 10 20 00  clr  %l0
a01329f8:  7f ff f4 8a  call  0xa012fc20
a01329fc:  01 00 00 00  nop
a0132a00:  10 bf ff e1  b  0xa0132984
a0132a04:  90 0a 20 ff  and  %o0, 0xff, %o0
a0132a08:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0132a0c:  81 c7 e0 08  ret
a0132a10:  81 e8 00 00  restore
