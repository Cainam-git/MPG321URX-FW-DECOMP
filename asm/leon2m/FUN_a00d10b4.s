# leon2m FUN_a00d10b4 0xa00d10b4-0xa00d1110 (92 bytes)
a00d10b4:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00d10b8:  98 12 a2 74  or  %o2, 0x274, %o4	! 0xa802d274
a00d10bc:  da 0b 20 10  ldub  [ %o4 + 0x10 ], %o5
a00d10c0:  82 0b 60 01  and  %o5, 1, %g1
a00d10c4:  c2 2a 20 06  stb  %g1, [ %o0 + 6 ]
a00d10c8:  d6 0b 20 10  ldub  [ %o4 + 0x10 ], %o3
a00d10cc:  d4 0a 20 01  ldub  [ %o0 + 1 ], %o2
a00d10d0:  9a 0a e0 3e  and  %o3, 0x3e, %o5
a00d10d4:  82 0a a0 7f  and  %o2, 0x7f, %g1
a00d10d8:  da 2a 20 07  stb  %o5, [ %o0 + 7 ]
a00d10dc:  94 80 60 02  addcc  %g1, 2, %o2
a00d10e0:  96 10 20 50  mov  0x50, %o3
a00d10e4:  02 80 00 09  be  0xa00d1108
a00d10e8:  98 10 20 00  clr  %o4
a00d10ec:  9a 10 20 00  clr  %o5
a00d10f0:  c2 0b 40 08  ldub  [ %o5 + %o0 ], %g1
a00d10f4:  98 03 20 01  inc  %o4
a00d10f8:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00d10fc:  80 a3 40 0a  cmp  %o5, %o2
a00d1100:  0a bf ff fc  bcs  0xa00d10f0
a00d1104:  96 1a c0 01  xor  %o3, %g1, %o3
a00d1108:  81 c3 e0 08  retl
a00d110c:  d6 2a 20 08  stb  %o3, [ %o0 + 8 ]
