# leon2m FUN_a00f3134 0xa00f3134-0xa00f31bc (136 bytes)
a00f3134:  82 0a 60 ff  and  %o1, 0xff, %g1
a00f3138:  c2 22 00 00  st  %g1, [ %o0 ]
a00f313c:  9b 32 60 08  srl  %o1, 8, %o5
a00f3140:  83 32 60 10  srl  %o1, 0x10, %g1
a00f3144:  9a 0b 60 ff  and  %o5, 0xff, %o5
a00f3148:  da 22 20 04  st  %o5, [ %o0 + 4 ]
a00f314c:  82 08 60 ff  and  %g1, 0xff, %g1
a00f3150:  c2 22 20 08  st  %g1, [ %o0 + 8 ]
a00f3154:  93 32 60 18  srl  %o1, 0x18, %o1
a00f3158:  d2 22 20 0c  st  %o1, [ %o0 + 0xc ]
a00f315c:  81 c3 e0 08  retl
a00f3160:  01 00 00 00  nop
a00f3164:  c2 02 00 00  ld  [ %o0 ], %g1
a00f3168:  98 10 00 08  mov  %o0, %o4
a00f316c:  da 02 20 04  ld  [ %o0 + 4 ], %o5
a00f3170:  91 2b 60 08  sll  %o5, 8, %o0
a00f3174:  da 03 20 08  ld  [ %o4 + 8 ], %o5
a00f3178:  90 12 00 01  or  %o0, %g1, %o0
a00f317c:  9b 2b 60 10  sll  %o5, 0x10, %o5
a00f3180:  c2 03 20 0c  ld  [ %o4 + 0xc ], %g1
a00f3184:  90 12 00 0d  or  %o0, %o5, %o0
a00f3188:  83 28 60 18  sll  %g1, 0x18, %g1
a00f318c:  81 c3 e0 08  retl
a00f3190:  90 12 00 01  or  %o0, %g1, %o0
a00f3194:  1b 33 c0 80  sethi  %hi(0xcf020000), %o5
a00f3198:  98 13 60 d4  or  %o5, 0xd4, %o4	! 0xcf0200d4
a00f319c:  82 10 20 e0  mov  0xe0, %g1
a00f31a0:  c2 23 00 00  st  %g1, [ %o4 ]
a00f31a4:  9a 13 61 14  or  %o5, 0x114, %o5
a00f31a8:  d8 03 40 00  ld  [ %o5 ], %o4
a00f31ac:  82 13 20 e0  or  %o4, 0xe0, %g1
a00f31b0:  c2 23 40 00  st  %g1, [ %o5 ]
a00f31b4:  81 c3 e0 08  retl
a00f31b8:  01 00 00 00  nop
