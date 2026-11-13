# leon2m FUN_a0090f30 0xa0090f30-0xa0090f94 (100 bytes)
a0090f30:  9d e3 bf 98  save  %sp, -104, %sp
a0090f34:  b0 10 20 01  mov  1, %i0
a0090f38:  a2 10 20 00  clr  %l1
a0090f3c:  10 80 00 05  b  0xa0090f50
a0090f40:  a0 10 20 00  clr  %l0
a0090f44:  80 a4 20 03  cmp  %l0, 3
a0090f48:  38 80 00 11  bgu,a   0xa0090f8c
a0090f4c:  b0 0e 20 01  and  %i0, 1, %i0
a0090f50:  7f ff bc f4  call  0xa0080320
a0090f54:  90 10 00 10  mov  %l0, %o0
a0090f58:  80 8a 20 ff  btst  0xff, %o0
a0090f5c:  a2 04 60 01  inc  %l1
a0090f60:  90 10 00 10  mov  %l0, %o0
a0090f64:  02 bf ff f8  be  0xa0090f44
a0090f68:  a0 0c 60 ff  and  %l1, 0xff, %l0
a0090f6c:  40 02 cb 2a  call  0xa0143c14
a0090f70:  01 00 00 00  nop
a0090f74:  90 0a 20 ff  and  %o0, 0xff, %o0
a0090f78:  80 a2 20 04  cmp  %o0, 4
a0090f7c:  02 bf ff f3  be  0xa0090f48
a0090f80:  80 a4 20 03  cmp  %l0, 3
a0090f84:  b0 10 20 00  clr  %i0
a0090f88:  b0 0e 20 01  and  %i0, 1, %i0
a0090f8c:  81 c7 e0 08  ret
a0090f90:  81 e8 00 00  restore
