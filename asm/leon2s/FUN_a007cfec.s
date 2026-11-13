# leon2s FUN_a007cfec 0xa007cfec-0xa007d054 (104 bytes)
a007cfec:  9d e3 bf 98  save  %sp, -104, %sp
a007cff0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a007cff4:  7f ff d9 4b  call  0xa0073520
a007cff8:  90 10 00 18  mov  %i0, %o0
a007cffc:  80 8a 20 ff  btst  0xff, %o0
a007d000:  82 1e 20 02  xor  %i0, 2, %g1
a007d004:  92 10 22 f6  mov  0x2f6, %o1
a007d008:  02 80 00 0e  be  0xa007d040
a007d00c:  90 10 20 10  mov  0x10, %o0
a007d010:  80 a0 00 01  cmp  %g0, %g1
a007d014:  82 40 20 00  addx  %g0, 0, %g1
a007d018:  1b 2a 01 f6  sethi  %hi(0xa807d800), %o5
a007d01c:  9a 13 63 00  or  %o5, 0x300, %o5	! 0xa807db00
a007d020:  82 58 60 34  smul  %g1, 0x34, %g1
a007d024:  82 00 40 0d  add  %g1, %o5, %g1
a007d028:  d2 00 60 0c  ld  [ %g1 + 0xc ], %o1
a007d02c:  40 00 a8 f7  call  0xa00a7408
a007d030:  92 02 60 74  add  %o1, 0x74, %o1
a007d034:  80 a0 00 08  cmp  %g0, %o0
a007d038:  10 80 00 05  b  0xa007d04c
a007d03c:  b0 40 20 00  addx  %g0, 0, %i0
a007d040:  40 00 a5 4f  call  0xa00a657c
a007d044:  90 10 00 18  mov  %i0, %o0
a007d048:  b0 0a 20 01  and  %o0, 1, %i0
a007d04c:  81 c7 e0 08  ret
a007d050:  81 e8 00 00  restore
