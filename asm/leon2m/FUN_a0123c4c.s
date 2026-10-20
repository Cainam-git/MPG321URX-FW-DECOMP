# leon2m FUN_a0123c4c 0xa0123c4c-0xa0123c80 (52 bytes)
a0123c4c:  82 02 3f d0  add  %o0, -48, %g1
a0123c50:  9a 02 3f bf  add  %o0, -65, %o5
a0123c54:  82 08 60 ff  and  %g1, 0xff, %g1
a0123c58:  9a 0b 60 ff  and  %o5, 0xff, %o5
a0123c5c:  80 a0 60 09  cmp  %g1, 9
a0123c60:  08 80 00 06  bleu  0xa0123c78
a0123c64:  90 02 3f c9  add  %o0, -55, %o0
a0123c68:  80 a3 60 05  cmp  %o5, 5
a0123c6c:  08 80 00 03  bleu  0xa0123c78
a0123c70:  82 0a 20 ff  and  %o0, 0xff, %g1
a0123c74:  82 10 20 aa  mov  0xaa, %g1
a0123c78:  81 c3 e0 08  retl
a0123c7c:  90 10 00 01  mov  %g1, %o0
