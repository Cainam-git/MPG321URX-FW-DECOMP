# leon2m FUN_a00d493c 0xa00d493c-0xa00d4970 (52 bytes)
a00d493c:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d4940:  80 a2 20 02  cmp  %o0, 2
a00d4944:  02 80 00 09  be  0xa00d4968
a00d4948:  82 10 20 01  mov  1, %g1
a00d494c:  80 a2 20 02  cmp  %o0, 2
a00d4950:  04 80 00 04  ble  0xa00d4960
a00d4954:  80 a2 20 01  cmp  %o0, 1
a00d4958:  10 80 00 04  b  0xa00d4968
a00d495c:  82 10 20 05  mov  5, %g1
a00d4960:  12 bf ff fe  bne  0xa00d4958
a00d4964:  82 10 20 00  clr  %g1
a00d4968:  81 c3 e0 08  retl
a00d496c:  90 08 60 05  and  %g1, 5, %o0
