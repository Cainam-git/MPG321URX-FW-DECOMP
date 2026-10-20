# leon2m FUN_a00fe184 0xa00fe184-0xa00fe1dc (88 bytes)
a00fe184:  9d e3 bf 98  save  %sp, -104, %sp
a00fe188:  40 00 7b 80  call  0xa011cf88
a00fe18c:  01 00 00 00  nop
a00fe190:  90 0a 20 ff  and  %o0, 0xff, %o0
a00fe194:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a00fe198:  80 a2 20 81  cmp  %o0, 0x81
a00fe19c:  18 80 00 04  bgu  0xa00fe1ac
a00fe1a0:  82 10 62 e0  or  %g1, 0x2e0, %g1
a00fe1a4:  13 33 c0 45  sethi  %hi(0xcf011400), %o1
a00fe1a8:  82 12 62 d4  or  %o1, 0x2d4, %g1	! 0xcf0116d4
a00fe1ac:  da 00 40 00  ld  [ %g1 ], %o5
a00fe1b0:  94 0b 60 50  and  %o5, 0x50, %o2
a00fe1b4:  9a 1a a0 10  xor  %o2, 0x10, %o5
a00fe1b8:  80 a2 a0 40  cmp  %o2, 0x40
a00fe1bc:  02 80 00 05  be  0xa00fe1d0
a00fe1c0:  82 10 20 03  mov  3, %g1
a00fe1c4:  80 a0 00 0d  cmp  %g0, %o5
a00fe1c8:  98 10 20 02  mov  2, %o4
a00fe1cc:  82 63 20 00  subx  %o4, 0, %g1
a00fe1d0:  b0 08 60 ff  and  %g1, 0xff, %i0
a00fe1d4:  81 c7 e0 08  ret
a00fe1d8:  81 e8 00 00  restore
