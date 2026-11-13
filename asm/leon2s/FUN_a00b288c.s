# leon2s FUN_a00b288c 0xa00b288c-0xa00b28d0 (68 bytes)
a00b288c:  80 a2 20 00  cmp  %o0, 0
a00b2890:  9a 10 20 00  clr  %o5
a00b2894:  02 80 00 06  be  0xa00b28ac
a00b2898:  82 0a 20 ff  and  %o0, 0xff, %g1
a00b289c:  91 32 20 08  srl  %o0, 8, %o0
a00b28a0:  9a 03 40 01  add  %o5, %g1, %o5
a00b28a4:  10 bf ff fc  b  0xa00b2894
a00b28a8:  80 a2 20 00  cmp  %o0, 0
a00b28ac:  80 a2 60 00  cmp  %o1, 0
a00b28b0:  02 80 00 05  be  0xa00b28c4
a00b28b4:  82 0a 60 ff  and  %o1, 0xff, %g1
a00b28b8:  93 32 60 08  srl  %o1, 8, %o1
a00b28bc:  10 bf ff fc  b  0xa00b28ac
a00b28c0:  9a 03 40 01  add  %o5, %g1, %o5
a00b28c4:  90 0b 60 0f  and  %o5, 0xf, %o0
a00b28c8:  81 c3 e0 08  retl
a00b28cc:  90 02 20 30  add  %o0, 0x30, %o0
