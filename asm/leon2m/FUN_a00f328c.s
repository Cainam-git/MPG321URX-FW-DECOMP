# leon2m FUN_a00f328c 0xa00f328c-0xa00f32d8 (76 bytes)
a00f328c:  1b 33 c0 80  sethi  %hi(0xcf020000), %o5
a00f3290:  98 13 60 d4  or  %o5, 0xd4, %o4	! 0xcf0200d4
a00f3294:  c0 23 00 00  clr  [ %o4 ]
a00f3298:  98 13 61 14  or  %o5, 0x114, %o4
a00f329c:  d6 03 00 00  ld  [ %o4 ], %o3
a00f32a0:  82 0a ff 1f  and  %o3, -225, %g1
a00f32a4:  c2 23 00 00  st  %g1, [ %o4 ]
a00f32a8:  98 13 60 cc  or  %o5, 0xcc, %o4
a00f32ac:  d6 03 00 00  ld  [ %o4 ], %o3
a00f32b0:  82 0a ff be  and  %o3, -66, %g1
a00f32b4:  c2 23 00 00  st  %g1, [ %o4 ]
a00f32b8:  98 13 61 34  or  %o5, 0x134, %o4
a00f32bc:  96 10 20 50  mov  0x50, %o3
a00f32c0:  d6 23 00 00  st  %o3, [ %o4 ]
a00f32c4:  9a 13 61 38  or  %o5, 0x138, %o5
a00f32c8:  82 10 20 22  mov  0x22, %g1
a00f32cc:  c2 23 40 00  st  %g1, [ %o5 ]
a00f32d0:  81 c3 e0 08  retl
a00f32d4:  01 00 00 00  nop
