# leon2m FUN_a013129c 0xa013129c-0xa01312d4 (56 bytes)
a013129c:  9d e3 bf 98  save  %sp, -104, %sp
a01312a0:  7f ff fc 66  call  0xa0130438
a01312a4:  a2 10 20 00  clr  %l1
a01312a8:  a0 0c 60 ff  and  %l1, 0xff, %l0
a01312ac:  40 00 30 f6  call  0xa013d684
a01312b0:  90 10 00 10  mov  %l0, %o0
a01312b4:  40 00 31 99  call  0xa013d918
a01312b8:  90 10 00 10  mov  %l0, %o0
a01312bc:  a2 04 60 01  inc  %l1
a01312c0:  80 a4 60 03  cmp  %l1, 3
a01312c4:  04 bf ff fa  ble  0xa01312ac
a01312c8:  a0 0c 60 ff  and  %l1, 0xff, %l0
a01312cc:  81 c7 e0 08  ret
a01312d0:  81 e8 00 00  restore
