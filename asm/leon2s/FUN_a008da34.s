# leon2s FUN_a008da34 0xa008da34-0xa008da88 (84 bytes)
a008da34:  9d e3 bf 98  save  %sp, -104, %sp
a008da38:  b0 0e 20 ff  and  %i0, 0xff, %i0
a008da3c:  90 10 00 18  mov  %i0, %o0
a008da40:  92 10 20 01  mov  1, %o1
a008da44:  40 00 69 65  call  0xa00a7fd8
a008da48:  94 10 20 7f  mov  0x7f, %o2
a008da4c:  b2 0e 60 ff  and  %i1, 0xff, %i1
a008da50:  80 a6 60 01  cmp  %i1, 1
a008da54:  02 80 00 07  be  0xa008da70
a008da58:  90 0a 3f f3  and  %o0, -13, %o0
a008da5c:  80 a6 60 02  cmp  %i1, 2
a008da60:  22 80 00 05  be,a   0xa008da74
a008da64:  b6 12 20 0c  or  %o0, 0xc, %i3
a008da68:  10 80 00 03  b  0xa008da74
a008da6c:  b6 12 20 04  or  %o0, 4, %i3
a008da70:  b6 12 20 08  or  %o0, 8, %i3
a008da74:  b6 0e e0 ff  and  %i3, 0xff, %i3
a008da78:  b2 10 20 01  mov  1, %i1
a008da7c:  40 00 69 76  call  0xa00a8054
a008da80:  95 e8 20 7f  restore  %g0, 0x7f, %o2
a008da84:  01 00 00 00  nop
