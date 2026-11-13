# leon2s FUN_a007af04 0xa007af04-0xa007af6c (104 bytes)
a007af04:  9d e3 bf 98  save  %sp, -104, %sp
a007af08:  b0 0e 20 ff  and  %i0, 0xff, %i0
a007af0c:  7f ff e1 85  call  0xa0073520
a007af10:  90 10 00 18  mov  %i0, %o0
a007af14:  80 8a 20 ff  btst  0xff, %o0
a007af18:  82 1e 20 02  xor  %i0, 2, %g1
a007af1c:  92 10 22 e1  mov  0x2e1, %o1
a007af20:  02 80 00 0e  be  0xa007af58
a007af24:  90 10 20 08  mov  8, %o0
a007af28:  80 a0 00 01  cmp  %g0, %g1
a007af2c:  82 40 20 00  addx  %g0, 0, %g1
a007af30:  1b 2a 01 f6  sethi  %hi(0xa807d800), %o5
a007af34:  9a 13 63 00  or  %o5, 0x300, %o5	! 0xa807db00
a007af38:  82 58 60 34  smul  %g1, 0x34, %g1
a007af3c:  82 00 40 0d  add  %g1, %o5, %g1
a007af40:  d2 00 60 0c  ld  [ %g1 + 0xc ], %o1
a007af44:  40 00 b1 31  call  0xa00a7408
a007af48:  92 02 60 60  add  %o1, 0x60, %o1
a007af4c:  80 a0 00 08  cmp  %g0, %o0
a007af50:  10 80 00 05  b  0xa007af64
a007af54:  b0 40 20 00  addx  %g0, 0, %i0
a007af58:  40 00 ad 89  call  0xa00a657c
a007af5c:  90 10 00 18  mov  %i0, %o0
a007af60:  b0 0a 20 01  and  %o0, 1, %i0
a007af64:  81 c7 e0 08  ret
a007af68:  81 e8 00 00  restore
