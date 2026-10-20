# leon2s FUN_a00aa7cc 0xa00aa7cc-0xa00aa878 (172 bytes)
a00aa7cc:  9d e3 bf 98  save  %sp, -104, %sp
a00aa7d0:  90 0e 20 ff  and  %i0, 0xff, %o0
a00aa7d4:  80 a2 20 00  cmp  %o0, 0
a00aa7d8:  12 80 00 0f  bne  0xa00aa814
a00aa7dc:  b0 10 20 07  mov  7, %i0
a00aa7e0:  7f ff f4 bb  call  0xa00a7acc
a00aa7e4:  92 10 20 0a  mov  0xa, %o1
a00aa7e8:  90 0a 20 ff  and  %o0, 0xff, %o0
a00aa7ec:  80 a2 20 11  cmp  %o0, 0x11
a00aa7f0:  02 80 00 0f  be  0xa00aa82c
a00aa7f4:  80 a2 20 22  cmp  %o0, 0x22
a00aa7f8:  02 80 00 11  be  0xa00aa83c
a00aa7fc:  80 a2 20 66  cmp  %o0, 0x66
a00aa800:  02 80 00 13  be  0xa00aa84c
a00aa804:  80 a2 20 44  cmp  %o0, 0x44
a00aa808:  02 80 00 15  be  0xa00aa85c
a00aa80c:  80 a2 20 33  cmp  %o0, 0x33
a00aa810:  30 80 00 15  b,a   0xa00aa864
a00aa814:  7f ff f4 ae  call  0xa00a7acc
a00aa818:  92 10 20 63  mov  0x63, %o1
a00aa81c:  90 0a 20 70  and  %o0, 0x70, %o0
a00aa820:  80 a2 20 10  cmp  %o0, 0x10
a00aa824:  12 80 00 04  bne  0xa00aa834
a00aa828:  80 a2 20 20  cmp  %o0, 0x20
a00aa82c:  10 80 00 10  b  0xa00aa86c
a00aa830:  b0 10 20 00  clr  %i0
a00aa834:  12 80 00 04  bne  0xa00aa844
a00aa838:  80 a2 20 60  cmp  %o0, 0x60
a00aa83c:  10 80 00 0c  b  0xa00aa86c
a00aa840:  b0 10 20 01  mov  1, %i0
a00aa844:  12 80 00 04  bne  0xa00aa854
a00aa848:  80 a2 20 40  cmp  %o0, 0x40
a00aa84c:  10 80 00 08  b  0xa00aa86c
a00aa850:  b0 10 20 02  mov  2, %i0
a00aa854:  12 80 00 04  bne  0xa00aa864
a00aa858:  80 a2 20 30  cmp  %o0, 0x30
a00aa85c:  10 80 00 04  b  0xa00aa86c
a00aa860:  b0 10 20 04  mov  4, %i0
a00aa864:  22 80 00 02  be,a   0xa00aa86c
a00aa868:  b0 10 20 05  mov  5, %i0
a00aa86c:  b0 0e 20 07  and  %i0, 7, %i0
a00aa870:  81 c7 e0 08  ret
a00aa874:  81 e8 00 00  restore
