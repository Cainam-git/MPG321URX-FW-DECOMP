# leon2s FUN_a00aec2c 0xa00aec2c-0xa00aec50 (36 bytes)
a00aec2c:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00aec30:  c2 00 60 04  ld  [ %g1 + 4 ], %g1	! 0xa807dc04
a00aec34:  c2 00 60 b4  ld  [ %g1 + 0xb4 ], %g1
a00aec38:  80 88 60 04  btst  4, %g1
a00aec3c:  02 80 00 03  be  0xa00aec48
a00aec40:  90 10 20 00  clr  %o0
a00aec44:  90 10 20 01  mov  1, %o0
a00aec48:  81 c3 e0 08  retl
a00aec4c:  90 0a 20 01  and  %o0, 1, %o0
