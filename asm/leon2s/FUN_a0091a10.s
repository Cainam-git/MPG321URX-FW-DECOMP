# leon2s FUN_a0091a10 0xa0091a10-0xa0091a4c (60 bytes)
a0091a10:  90 0a 20 ff  and  %o0, 0xff, %o0
a0091a14:  83 2a 20 03  sll  %o0, 3, %g1
a0091a18:  82 20 40 08  sub  %g1, %o0, %g1
a0091a1c:  80 a2 20 01  cmp  %o0, 1
a0091a20:  9b 28 60 02  sll  %g1, 2, %o5
a0091a24:  18 80 00 08  bgu  0xa0091a44
a0091a28:  90 10 20 00  clr  %o0
a0091a2c:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a0091a30:  82 10 61 80  or  %g1, 0x180, %g1	! 0xa807d580
a0091a34:  c2 00 40 0d  ld  [ %g1 + %o5 ], %g1
a0091a38:  83 30 60 1f  srl  %g1, 0x1f, %g1
a0091a3c:  80 a0 00 01  cmp  %g0, %g1
a0091a40:  90 40 20 00  addx  %g0, 0, %o0
a0091a44:  81 c3 e0 08  retl
a0091a48:  01 00 00 00  nop
