# leon2s FUN_a00c7fec 0xa00c7fec-0xa00c8048 (92 bytes)
a00c7fec:  9d e3 bf 98  save  %sp, -104, %sp
a00c7ff0:  b4 0e a0 ff  and  %i2, 0xff, %i2
a00c7ff4:  80 a6 a0 00  cmp  %i2, 0
a00c7ff8:  02 80 00 11  be  0xa00c803c
a00c7ffc:  a0 10 20 00  clr  %l0
a00c8000:  95 2e e0 10  sll  %i3, 0x10, %o2
a00c8004:  95 32 a0 10  srl  %o2, 0x10, %o2
a00c8008:  90 0e 20 ff  and  %i0, 0xff, %o0
a00c800c:  40 3b bf f3  call  0xa0fb7fd8
a00c8010:  92 10 20 00  clr  %o1
a00c8014:  96 04 20 01  add  %l0, 1, %o3
a00c8018:  83 2c 20 10  sll  %l0, 0x10, %g1
a00c801c:  9b 2a e0 10  sll  %o3, 0x10, %o5
a00c8020:  83 30 60 10  srl  %g1, 0x10, %g1
a00c8024:  9b 33 60 10  srl  %o5, 0x10, %o5
a00c8028:  98 0e a0 ff  and  %i2, 0xff, %o4
a00c802c:  d0 2e 40 01  stb  %o0, [ %i1 + %g1 ]
a00c8030:  80 a3 40 0c  cmp  %o5, %o4
a00c8034:  0a bf ff f3  bcs  0xa00c8000
a00c8038:  a0 10 00 0b  mov  %o3, %l0
a00c803c:  40 3b e5 d6  call  0xa0fc1794
a00c8040:  91 e8 20 01  restore  %g0, 1, %o0
a00c8044:  01 00 00 00  nop
