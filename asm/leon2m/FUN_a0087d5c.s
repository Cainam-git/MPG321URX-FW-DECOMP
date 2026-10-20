# leon2m FUN_a0087d5c 0xa0087d5c-0xa0087da8 (76 bytes)
a0087d5c:  9d e3 bf 98  save  %sp, -104, %sp
a0087d60:  96 0e 20 ff  and  %i0, 0xff, %o3
a0087d64:  80 a2 e0 04  cmp  %o3, 4
a0087d68:  9a 40 20 00  addx  %g0, 0, %o5
a0087d6c:  98 20 00 0d  neg  %o5, %o4
a0087d70:  b0 0a c0 0c  and  %o3, %o4, %i0
a0087d74:  95 2e 20 04  sll  %i0, 4, %o2
a0087d78:  92 02 80 18  add  %o2, %i0, %o1
a0087d7c:  11 00 03 fd  sethi  %hi(0xff400), %o0
a0087d80:  82 12 22 00  or  %o0, 0x200, %g1	! 0xff600
a0087d84:  b3 2a 60 02  sll  %o1, 2, %i1
a0087d88:  b2 06 40 01  add  %i1, %g1, %i1
a0087d8c:  90 10 20 01  mov  1, %o0
a0087d90:  40 02 fd c8  call  0xa01474b0
a0087d94:  92 10 00 19  mov  %i1, %o1
a0087d98:  40 02 fd c6  call  0xa01474b0
a0087d9c:  91 e8 20 00  restore  %g0, 0, %o0
a0087da0:  01 00 00 00  nop
a0087da4:  00 02 9d 3c  unimp  0x29d3c
