# leon2s FUN_a00d3efc 0xa00d3efc-0xa00d3f30 (52 bytes)
a00d3efc:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00d3f00:  c2 08 60 38  ldub  [ %g1 + 0x38 ], %g1	! 0xa8078c38
a00d3f04:  80 a0 60 03  cmp  %g1, 3
a00d3f08:  08 80 00 04  bleu  0xa00d3f18
a00d3f0c:  90 10 20 00  clr  %o0
a00d3f10:  10 80 00 06  b  0xa00d3f28
a00d3f14:  90 10 20 02  mov  2, %o0
a00d3f18:  80 a0 60 00  cmp  %g1, 0
a00d3f1c:  02 80 00 03  be  0xa00d3f28
a00d3f20:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a00d3f24:  d0 08 61 4f  ldub  [ %g1 + 0x14f ], %o0	! 0xa807d54f
a00d3f28:  81 c3 e0 08  retl
a00d3f2c:  90 0a 20 ff  and  %o0, 0xff, %o0
