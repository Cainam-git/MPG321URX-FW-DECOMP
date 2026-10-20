# leon2m FUN_a00d8bd8 0xa00d8bd8-0xa00d8c1c (68 bytes)
a00d8bd8:  9d e3 bf 98  save  %sp, -104, %sp
a00d8bdc:  92 10 20 01  mov  1, %o1
a00d8be0:  40 01 b2 a0  call  0xa0145660
a00d8be4:  90 10 20 00  clr  %o0
a00d8be8:  99 2a 20 10  sll  %o0, 0x10, %o4
a00d8bec:  17 33 33 33  sethi  %hi(0xcccccc00), %o3
a00d8bf0:  95 33 20 10  srl  %o4, 0x10, %o2
a00d8bf4:  82 12 e0 cd  or  %o3, 0xcd, %g1
a00d8bf8:  80 52 80 01  umul  %o2, %g1, %g0
a00d8bfc:  93 40 00 00  rd  %y, %o1
a00d8c00:  91 2a 60 0d  sll  %o1, 0xd, %o0
a00d8c04:  7f fe ba 15  call  0xa0087458
a00d8c08:  91 32 20 10  srl  %o0, 0x10, %o0
a00d8c0c:  80 a0 00 08  cmp  %g0, %o0
a00d8c10:  b0 40 20 00  addx  %g0, 0, %i0
a00d8c14:  81 c7 e0 08  ret
a00d8c18:  81 e8 00 00  restore
