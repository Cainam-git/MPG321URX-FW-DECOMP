# leon2s FUN_a00a621c 0xa00a621c-0xa00a6260 (68 bytes)
a00a621c:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a6220:  80 a2 20 51  cmp  %o0, 0x51
a00a6224:  12 80 00 05  bne  0xa00a6238
a00a6228:  9a 10 20 00  clr  %o5
a00a622c:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a00a6230:  10 80 00 06  b  0xa00a6248
a00a6234:  c2 08 63 e1  ldub  [ %g1 + 0x3e1 ], %g1	! 0xa807d7e1
a00a6238:  80 a2 20 61  cmp  %o0, 0x61
a00a623c:  12 80 00 07  bne  0xa00a6258
a00a6240:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a00a6244:  c2 08 61 71  ldub  [ %g1 + 0x171 ], %g1	! 0xa807d971
a00a6248:  80 a0 60 00  cmp  %g1, 0
a00a624c:  12 80 00 03  bne  0xa00a6258
a00a6250:  01 00 00 00  nop
a00a6254:  9a 10 20 01  mov  1, %o5	! 0x1
a00a6258:  81 c3 e0 08  retl
a00a625c:  90 0b 60 01  and  %o5, 1, %o0
