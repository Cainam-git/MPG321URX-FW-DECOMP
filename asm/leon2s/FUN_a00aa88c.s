# leon2s FUN_a00aa88c 0xa00aa88c-0xa00aa904 (120 bytes)
a00aa88c:  90 0a 20 ff  and  %o0, 0xff, %o0
a00aa890:  80 a2 20 04  cmp  %o0, 4
a00aa894:  18 80 00 19  bgu  0xa00aa8f8
a00aa898:  1b 28 02 aa  sethi  %hi(0xa00aa800), %o5
a00aa89c:  83 2a 20 02  sll  %o0, 2, %g1
a00aa8a0:  9a 13 60 78  or  %o5, 0x78, %o5
a00aa8a4:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a00aa8a8:  81 c0 40 00  jmp  %g1
a00aa8ac:  96 0a 60 ff  and  %o1, 0xff, %o3
a00aa8b0:  90 10 20 01  mov  1, %o0
a00aa8b4:  10 80 00 07  b  0xa00aa8d0
a00aa8b8:  92 10 20 67  mov  0x67, %o1
a00aa8bc:  90 10 20 01  mov  1, %o0
a00aa8c0:  10 80 00 0a  b  0xa00aa8e8
a00aa8c4:  92 10 20 67  mov  0x67, %o1
a00aa8c8:  90 10 20 01  mov  1, %o0
a00aa8cc:  92 10 20 8a  mov  0x8a, %o1
a00aa8d0:  10 80 00 07  b  0xa00aa8ec
a00aa8d4:  94 10 20 0f  mov  0xf, %o2
a00aa8d8:  90 10 20 01  mov  1, %o0
a00aa8dc:  10 80 00 03  b  0xa00aa8e8
a00aa8e0:  92 10 20 8a  mov  0x8a, %o1
a00aa8e4:  92 10 20 49  mov  0x49, %o1
a00aa8e8:  94 10 20 f0  mov  0xf0, %o2
a00aa8ec:  82 13 c0 00  mov  %o7, %g1
a00aa8f0:  7f ff f5 05  call  0xa00a7d04
a00aa8f4:  9e 10 40 00  mov  %g1, %o7
a00aa8f8:  01 00 00 00  nop
a00aa8fc:  81 c3 e0 08  retl
a00aa900:  01 00 00 00  nop
