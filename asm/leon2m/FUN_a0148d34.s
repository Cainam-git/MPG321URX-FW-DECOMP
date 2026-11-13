# leon2m FUN_a0148d34 0xa0148d34-0xa0148d98 (100 bytes)
a0148d34:  9a 10 00 09  mov  %o1, %o5
a0148d38:  82 0a 20 ff  and  %o0, 0xff, %g1
a0148d3c:  93 2a 60 10  sll  %o1, 0x10, %o1
a0148d40:  90 10 20 07  mov  7, %o0
a0148d44:  80 a0 60 01  cmp  %g1, 1
a0148d48:  02 80 00 0e  be  0xa0148d80
a0148d4c:  93 32 60 10  srl  %o1, 0x10, %o1
a0148d50:  80 a0 60 01  cmp  %g1, 1
a0148d54:  04 80 00 06  ble  0xa0148d6c
a0148d58:  80 a0 60 02  cmp  %g1, 2
a0148d5c:  12 80 00 0c  bne  0xa0148d8c
a0148d60:  83 2b 60 10  sll  %o5, 0x10, %g1
a0148d64:  10 80 00 07  b  0xa0148d80
a0148d68:  93 30 60 10  srl  %g1, 0x10, %o1
a0148d6c:  80 a0 60 00  cmp  %g1, 0
a0148d70:  12 80 00 07  bne  0xa0148d8c
a0148d74:  83 2b 60 10  sll  %o5, 0x10, %g1
a0148d78:  93 30 60 10  srl  %g1, 0x10, %o1
a0148d7c:  90 10 20 07  mov  7, %o0
a0148d80:  82 13 c0 00  mov  %o7, %g1
a0148d84:  7f ff 54 06  call  0xa011dd9c
a0148d88:  9e 10 40 00  mov  %g1, %o7
a0148d8c:  01 00 00 00  nop
a0148d90:  81 c3 e0 08  retl
a0148d94:  01 00 00 00  nop
