# leon2m FUN_a00d8064 0xa00d8064-0xa00d80b0 (76 bytes)
a00d8064:  82 0a 20 ff  and  %o0, 0xff, %g1
a00d8068:  80 a0 60 00  cmp  %g1, 0
a00d806c:  02 80 00 0b  be  0xa00d8098
a00d8070:  90 10 20 00  clr  %o0
a00d8074:  80 a0 60 01  cmp  %g1, 1
a00d8078:  02 80 00 08  be  0xa00d8098
a00d807c:  90 10 20 01  mov  1, %o0
a00d8080:  80 a0 60 02  cmp  %g1, 2
a00d8084:  02 80 00 05  be  0xa00d8098
a00d8088:  90 10 20 02  mov  2, %o0
a00d808c:  80 a0 60 03  cmp  %g1, 3
a00d8090:  12 80 00 05  bne  0xa00d80a4
a00d8094:  90 10 20 03  mov  3, %o0
a00d8098:  82 13 c0 00  mov  %o7, %g1
a00d809c:  40 01 cf 1c  call  0xa014bd0c
a00d80a0:  9e 10 40 00  mov  %g1, %o7
a00d80a4:  01 00 00 00  nop
a00d80a8:  81 c3 e0 08  retl
a00d80ac:  01 00 00 00  nop
