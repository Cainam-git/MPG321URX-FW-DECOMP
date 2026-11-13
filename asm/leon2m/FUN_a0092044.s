# leon2m FUN_a0092044 0xa0092044-0xa00920f4 (176 bytes)
a0092044:  9d e3 bf 98  save  %sp, -104, %sp
a0092048:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a009204c:  c2 04 63 ec  ld  [ %l1 + 0x3ec ], %g1	! 0xa802afec
a0092050:  90 00 7f e8  add  %g1, -24, %o0
a0092054:  40 00 5b a5  call  0xa00a8ee8
a0092058:  90 0a 20 ff  and  %o0, 0xff, %o0
a009205c:  40 00 61 31  call  0xa00aa520
a0092060:  90 10 20 00  clr  %o0
a0092064:  80 8a 20 ff  btst  0xff, %o0
a0092068:  b0 10 20 03  mov  3, %i0
a009206c:  b2 10 20 01  mov  1, %i1
a0092070:  90 10 20 01  mov  1, %o0
a0092074:  02 80 00 0d  be  0xa00920a8
a0092078:  82 10 20 00  clr  %g1
a009207c:  a0 08 60 ff  and  %g1, 0xff, %l0
a0092080:  90 10 20 18  mov  0x18, %o0
a0092084:  40 00 74 f2  call  0xa00af44c
a0092088:  92 10 00 10  mov  %l0, %o1
a009208c:  90 10 00 10  mov  %l0, %o0
a0092090:  40 00 5b df  call  0xa00a900c
a0092094:  92 10 20 00  clr  %o1
a0092098:  98 10 20 05  mov  5, %o4
a009209c:  d8 24 63 ec  st  %o4, [ %l1 + 0x3ec ]
a00920a0:  40 00 88 29  call  0xa00b4144
a00920a4:  81 e8 00 00  restore
a00920a8:  40 00 61 1e  call  0xa00aa520
a00920ac:  01 00 00 00  nop
a00920b0:  96 0a 20 ff  and  %o0, 0xff, %o3
a00920b4:  94 1a e0 01  xor  %o3, 1, %o2
a00920b8:  80 a0 00 0a  cmp  %g0, %o2
a00920bc:  92 40 20 00  addx  %g0, 0, %o1
a00920c0:  82 02 60 01  add  %o1, 1, %g1
a00920c4:  a0 08 60 ff  and  %g1, 0xff, %l0
a00920c8:  90 10 20 18  mov  0x18, %o0
a00920cc:  40 00 74 e0  call  0xa00af44c
a00920d0:  92 10 00 10  mov  %l0, %o1
a00920d4:  90 10 00 10  mov  %l0, %o0
a00920d8:  40 00 5b cd  call  0xa00a900c
a00920dc:  92 10 20 00  clr  %o1
a00920e0:  98 10 20 05  mov  5, %o4
a00920e4:  d8 24 63 ec  st  %o4, [ %l1 + 0x3ec ]
a00920e8:  40 00 88 17  call  0xa00b4144
a00920ec:  81 e8 00 00  restore
a00920f0:  01 00 00 00  nop
