# leon2m FUN_a00aa01c 0xa00aa01c-0xa00aa0e8 (204 bytes)
a00aa01c:  9d e3 bf 90  save  %sp, -112, %sp
a00aa020:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00aa024:  82 06 00 18  add  %i0, %i0, %g1
a00aa028:  80 a6 20 04  cmp  %i0, 4
a00aa02c:  02 80 00 05  be  0xa00aa040
a00aa030:  96 00 60 06  add  %g1, 6, %o3
a00aa034:  b0 10 20 00  clr  %i0
a00aa038:  40 00 25 27  call  0xa00b34d4
a00aa03c:  93 e8 20 04  restore  %g0, 4, %o1
a00aa040:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00aa044:  da 02 22 90  ld  [ %o0 + 0x290 ], %o5	! 0xa802d290
a00aa048:  80 8b 62 00  btst  0x200, %o5
a00aa04c:  12 80 00 03  bne  0xa00aa058
a00aa050:  9a 10 20 01  mov  1, %o5
a00aa054:  9a 10 20 00  clr  %o5
a00aa058:  92 0e 60 ff  and  %i1, 0xff, %o1
a00aa05c:  80 a2 60 01  cmp  %o1, 1
a00aa060:  02 80 00 1c  be  0xa00aa0d0
a00aa064:  b0 0b 60 ff  and  %o5, 0xff, %i0
a00aa068:  80 a0 00 18  cmp  %g0, %i0
a00aa06c:  82 40 3f ff  addx  %g0, -1, %g1
a00aa070:  b2 08 7e 00  and  %g1, -512, %i1
a00aa074:  82 06 67 92  add  %i1, 0x792, %g1
a00aa078:  9f 28 60 10  sll  %g1, 0x10, %o7
a00aa07c:  95 33 e0 10  srl  %o7, 0x10, %o2
a00aa080:  98 1a a7 42  xor  %o2, 0x742, %o4
a00aa084:  80 a0 00 0c  cmp  %g0, %o4
a00aa088:  90 60 3f ff  subx  %g0, -1, %o0
a00aa08c:  92 1a a7 92  xor  %o2, 0x792, %o1
a00aa090:  80 a0 00 09  cmp  %g0, %o1
a00aa094:  9a 60 3f ff  subx  %g0, -1, %o5
a00aa098:  80 92 00 0d  orcc  %o0, %o5, %g0
a00aa09c:  12 80 00 03  bne  0xa00aa0a8
a00aa0a0:  82 10 20 37  mov  0x37, %g1
a00aa0a4:  82 10 20 34  mov  0x34, %g1
a00aa0a8:  98 0a e0 fe  and  %o3, 0xfe, %o4
a00aa0ac:  c2 23 a0 5c  st  %g1, [ %sp + 0x5c ]
a00aa0b0:  90 10 20 01  mov  1, %o0
a00aa0b4:  92 10 20 01  mov  1, %o1
a00aa0b8:  96 10 20 22  mov  0x22, %o3
a00aa0bc:  40 00 24 8a  call  0xa00b32e4
a00aa0c0:  9a 10 20 03  mov  3, %o5
a00aa0c4:  b0 10 20 00  clr  %i0
a00aa0c8:  40 00 25 03  call  0xa00b34d4
a00aa0cc:  93 e8 20 02  restore  %g0, 2, %o1
a00aa0d0:  9e 0b 60 ff  and  %o5, 0xff, %o7
a00aa0d4:  80 a0 00 0f  cmp  %g0, %o7
a00aa0d8:  98 40 3f ff  addx  %g0, -1, %o4
a00aa0dc:  94 0b 3e 00  and  %o4, -512, %o2
a00aa0e0:  10 bf ff e6  b  0xa00aa078
a00aa0e4:  82 02 a7 42  add  %o2, 0x742, %g1
