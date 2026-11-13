# leon2m FUN_a009a020 0xa009a020-0xa009a078 (88 bytes)
a009a020:  9d e3 bf 98  save  %sp, -104, %sp
a009a024:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a009a028:  a0 12 e2 90  or  %o3, 0x290, %l0	! 0xa802d290
a009a02c:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a009a030:  d4 04 63 ec  ld  [ %l1 + 0x3ec ], %o2	! 0xa802afec
a009a034:  da 0c 21 ee  ldub  [ %l0 + 0x1ee ], %o5
a009a038:  13 2a 00 97  sethi  %hi(0xa8025c00), %o1
a009a03c:  90 02 bf cc  add  %o2, -52, %o0
a009a040:  da 2a 60 56  stb  %o5, [ %o1 + 0x56 ]
a009a044:  90 0a 20 ff  and  %o0, 0xff, %o0
a009a048:  40 00 3b f1  call  0xa00a900c
a009a04c:  92 10 20 02  mov  2, %o1
a009a050:  d0 0c 21 ee  ldub  [ %l0 + 0x1ee ], %o0
a009a054:  82 02 20 c3  add  %o0, 0xc3, %g1
a009a058:  c2 24 63 ec  st  %g1, [ %l1 + 0x3ec ]
a009a05c:  40 00 3d 7d  call  0xa00a9650
a009a060:  92 10 20 01  mov  1, %o1
a009a064:  f2 0c 21 ee  ldub  [ %l0 + 0x1ee ], %i1
a009a068:  b0 10 20 01  mov  1, %i0
a009a06c:  40 00 38 34  call  0xa00a813c
a009a070:  95 e8 20 00  restore  %g0, 0, %o2
a009a074:  01 00 00 00  nop
