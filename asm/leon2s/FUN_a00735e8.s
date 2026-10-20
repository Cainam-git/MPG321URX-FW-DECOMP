# leon2s FUN_a00735e8 0xa00735e8-0xa0073638 (80 bytes)
a00735e8:  9d e3 bf 98  save  %sp, -104, %sp
a00735ec:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00735f0:  7f ff ff cc  call  0xa0073520
a00735f4:  90 10 00 18  mov  %i0, %o0
a00735f8:  82 1e 20 02  xor  %i0, 2, %g1
a00735fc:  80 8a 20 ff  btst  0xff, %o0
a0073600:  02 80 00 0c  be  0xa0073630
a0073604:  b0 10 20 00  clr  %i0
a0073608:  80 a0 00 01  cmp  %g0, %g1
a007360c:  9a 40 20 00  addx  %g0, 0, %o5
a0073610:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a0073614:  82 10 63 00  or  %g1, 0x300, %g1	! 0xa807db00
a0073618:  9a 5b 60 34  smul  %o5, 0x34, %o5
a007361c:  9a 03 40 01  add  %o5, %g1, %o5
a0073620:  c2 03 60 18  ld  [ %o5 + 0x18 ], %g1
a0073624:  c2 00 60 90  ld  [ %g1 + 0x90 ], %g1
a0073628:  83 30 60 18  srl  %g1, 0x18, %g1
a007362c:  b0 08 60 0f  and  %g1, 0xf, %i0
a0073630:  81 c7 e0 08  ret
a0073634:  81 e8 00 00  restore
