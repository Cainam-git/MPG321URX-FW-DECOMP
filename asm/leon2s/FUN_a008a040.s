# leon2s FUN_a008a040 0xa008a040-0xa008a110 (208 bytes)
a008a040:  90 0a 20 ff  and  %o0, 0xff, %o0
a008a044:  82 02 3f ff  add  %o0, -1, %g1
a008a048:  80 a0 60 12  cmp  %g1, 0x12
a008a04c:  38 80 00 2f  bgu,a   0xa008a108
a008a050:  82 10 3f ff  mov  -1, %g1
a008a054:  1b 28 02 27  sethi  %hi(0xa0089c00), %o5
a008a058:  83 28 60 02  sll  %g1, 2, %g1
a008a05c:  9a 13 63 f4  or  %o5, 0x3f4, %o5
a008a060:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a008a064:  81 c0 40 00  jmp  %g1
a008a068:  01 00 00 00  nop
a008a06c:  03 33 c0 44  sethi  %hi(0xcf011000), %g1
a008a070:  10 80 00 07  b  0xa008a08c
a008a074:  82 10 61 c0  or  %g1, 0x1c0, %g1	! 0xcf0111c0
a008a078:  03 33 c0 44  sethi  %hi(0xcf011000), %g1
a008a07c:  10 80 00 1e  b  0xa008a0f4
a008a080:  82 10 61 c0  or  %g1, 0x1c0, %g1	! 0xcf0111c0
a008a084:  03 33 c0 44  sethi  %hi(0xcf011000), %g1
a008a088:  82 10 61 d4  or  %g1, 0x1d4, %g1	! 0xcf0111d4
a008a08c:  c2 00 40 00  ld  [ %g1 ], %g1
a008a090:  10 80 00 1b  b  0xa008a0fc
a008a094:  83 30 60 06  srl  %g1, 6, %g1
a008a098:  03 33 c0 44  sethi  %hi(0xcf011000), %g1
a008a09c:  10 bf ff fc  b  0xa008a08c
a008a0a0:  82 10 61 c4  or  %g1, 0x1c4, %g1	! 0xcf0111c4
a008a0a4:  03 33 c0 44  sethi  %hi(0xcf011000), %g1
a008a0a8:  10 80 00 13  b  0xa008a0f4
a008a0ac:  82 10 61 c4  or  %g1, 0x1c4, %g1	! 0xcf0111c4
a008a0b0:  03 33 c0 44  sethi  %hi(0xcf011000), %g1
a008a0b4:  10 bf ff f6  b  0xa008a08c
a008a0b8:  82 10 61 c8  or  %g1, 0x1c8, %g1	! 0xcf0111c8
a008a0bc:  03 33 c0 44  sethi  %hi(0xcf011000), %g1
a008a0c0:  10 80 00 0d  b  0xa008a0f4
a008a0c4:  82 10 61 c8  or  %g1, 0x1c8, %g1	! 0xcf0111c8
a008a0c8:  03 33 c0 44  sethi  %hi(0xcf011000), %g1
a008a0cc:  10 bf ff f0  b  0xa008a08c
a008a0d0:  82 10 61 cc  or  %g1, 0x1cc, %g1	! 0xcf0111cc
a008a0d4:  03 33 c0 44  sethi  %hi(0xcf011000), %g1
a008a0d8:  10 80 00 07  b  0xa008a0f4
a008a0dc:  82 10 61 cc  or  %g1, 0x1cc, %g1	! 0xcf0111cc
a008a0e0:  03 33 c0 44  sethi  %hi(0xcf011000), %g1
a008a0e4:  10 bf ff ea  b  0xa008a08c
a008a0e8:  82 10 61 d0  or  %g1, 0x1d0, %g1	! 0xcf0111d0
a008a0ec:  03 33 c0 44  sethi  %hi(0xcf011000), %g1
a008a0f0:  82 10 61 d0  or  %g1, 0x1d0, %g1	! 0xcf0111d0
a008a0f4:  c2 00 40 00  ld  [ %g1 ], %g1
a008a0f8:  83 30 60 02  srl  %g1, 2, %g1
a008a0fc:  10 80 00 03  b  0xa008a108
a008a100:  82 08 60 03  and  %g1, 3, %g1
a008a104:  82 10 3f ff  mov  -1, %g1
a008a108:  81 c3 e0 08  retl
a008a10c:  90 08 60 ff  and  %g1, 0xff, %o0
