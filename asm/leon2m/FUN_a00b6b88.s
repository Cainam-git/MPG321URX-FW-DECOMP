# leon2m FUN_a00b6b88 0xa00b6b88-0xa00b6bec (100 bytes)
a00b6b88:  9a 10 00 08  mov  %o0, %o5
a00b6b8c:  92 0a 60 ff  and  %o1, 0xff, %o1
a00b6b90:  98 0a 20 ff  and  %o0, 0xff, %o4
a00b6b94:  80 a2 60 01  cmp  %o1, 1
a00b6b98:  02 80 00 0b  be  0xa00b6bc4
a00b6b9c:  90 10 20 07  mov  7, %o0
a00b6ba0:  80 a3 20 07  cmp  %o4, 7
a00b6ba4:  02 80 00 10  be  0xa00b6be4
a00b6ba8:  90 10 20 00  clr  %o0
a00b6bac:  80 a3 20 06  cmp  %o4, 6
a00b6bb0:  18 80 00 0d  bgu  0xa00b6be4
a00b6bb4:  90 10 00 0c  mov  %o4, %o0
a00b6bb8:  98 03 60 01  add  %o5, 1, %o4
a00b6bbc:  10 80 00 0a  b  0xa00b6be4
a00b6bc0:  90 0b 20 ff  and  %o4, 0xff, %o0
a00b6bc4:  82 03 7f ff  add  %o5, -1, %g1
a00b6bc8:  80 a3 20 00  cmp  %o4, 0
a00b6bcc:  02 80 00 06  be  0xa00b6be4
a00b6bd0:  82 08 60 ff  and  %g1, 0xff, %g1
a00b6bd4:  80 a0 60 06  cmp  %g1, 6
a00b6bd8:  08 80 00 03  bleu  0xa00b6be4
a00b6bdc:  90 10 00 01  mov  %g1, %o0
a00b6be0:  90 10 00 0c  mov  %o4, %o0
a00b6be4:  81 c3 e0 08  retl
a00b6be8:  01 00 00 00  nop
