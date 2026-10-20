# leon2m FUN_a00ab080 0xa00ab080-0xa00ab0e0 (96 bytes)
a00ab080:  9d e3 bf 98  save  %sp, -104, %sp
a00ab084:  67 ff 8c 88  call  0x4008e2a4
a00ab088:  a2 10 20 05  mov  5, %l1
a00ab08c:  a0 10 20 05  mov  5, %l0
a00ab090:  92 10 00 10  mov  %l0, %o1
a00ab094:  90 10 20 01  mov  1, %o0
a00ab098:  94 10 20 11  mov  0x11, %o2
a00ab09c:  96 10 27 92  mov  0x792, %o3
a00ab0a0:  40 02 6e 78  call  0xa0146a80
a00ab0a4:  98 10 20 00  clr  %o4
a00ab0a8:  94 10 00 10  mov  %l0, %o2
a00ab0ac:  90 10 20 00  clr  %o0
a00ab0b0:  92 10 20 01  mov  1, %o1
a00ab0b4:  96 10 20 11  mov  0x11, %o3
a00ab0b8:  98 10 20 00  clr  %o4
a00ab0bc:  9a 10 20 00  clr  %o5
a00ab0c0:  40 02 6e 98  call  0xa0146b20
a00ab0c4:  a2 04 60 01  inc  %l1
a00ab0c8:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00ab0cc:  80 a4 20 15  cmp  %l0, 0x15
a00ab0d0:  08 bf ff f1  bleu  0xa00ab094
a00ab0d4:  92 10 00 10  mov  %l0, %o1
a00ab0d8:  81 c7 e0 08  ret
a00ab0dc:  81 e8 00 00  restore
