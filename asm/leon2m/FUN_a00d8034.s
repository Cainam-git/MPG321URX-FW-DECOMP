# leon2m FUN_a00d8034 0xa00d8034-0xa00d8064 (48 bytes)
a00d8034:  9d e3 bf 98  save  %sp, -104, %sp
a00d8038:  40 01 b1 15  call  0xa014448c
a00d803c:  90 10 20 00  clr  %o0
a00d8040:  82 02 3f f5  add  %o0, -11, %g1
a00d8044:  90 08 60 ff  and  %g1, 0xff, %o0
a00d8048:  80 a2 20 04  cmp  %o0, 4
a00d804c:  18 80 00 03  bgu  0xa00d8058
a00d8050:  b0 10 20 00  clr  %i0
a00d8054:  b0 10 20 01  mov  1, %i0
a00d8058:  b0 0e 20 01  and  %i0, 1, %i0
a00d805c:  81 c7 e0 08  ret
a00d8060:  81 e8 00 00  restore
