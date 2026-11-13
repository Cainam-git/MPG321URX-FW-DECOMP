# leon2s FUN_a00d904c 0xa00d904c-0xa00d90dc (144 bytes)
a00d904c:  9d e3 bf 88  save  %sp, -120, %sp
a00d9050:  90 07 bf f0  add  %fp, -16, %o0
a00d9054:  92 10 20 00  clr  %o1
a00d9058:  94 10 20 01  mov  1, %o2
a00d905c:  96 10 20 1c  mov  0x1c, %o3
a00d9060:  c0 37 bf f0  clrh  [ %fp + -16 ]
a00d9064:  7f ff f8 d4  call  0xa00d73b4
a00d9068:  c0 37 bf e8  clrh  [ %fp + -24 ]
a00d906c:  c2 07 bf e8  ld  [ %fp + -24 ], %g1
a00d9070:  19 1f c0 00  sethi  %hi(0x7f000000), %o4
a00d9074:  98 28 40 0c  andn  %g1, %o4, %o4
a00d9078:  03 09 40 00  sethi  %hi(0x25000000), %g1
a00d907c:  98 13 00 01  or  %o4, %g1, %o4
a00d9080:  da 07 bf f0  ld  [ %fp + -16 ], %o5
a00d9084:  03 00 3c 00  sethi  %hi(0xf00000), %g1
a00d9088:  9a 0b 40 01  and  %o5, %g1, %o5
a00d908c:  82 2b 00 01  andn  %o4, %g1, %g1
a00d9090:  82 10 40 0d  or  %g1, %o5, %g1
a00d9094:  c2 27 bf e8  st  %g1, [ %fp + -24 ]
a00d9098:  90 07 bf e8  add  %fp, -24, %o0
a00d909c:  92 10 20 02  mov  2, %o1
a00d90a0:  94 10 20 01  mov  1, %o2
a00d90a4:  96 10 20 0c  mov  0xc, %o3
a00d90a8:  7f ff fa 1d  call  0xa00d791c
a00d90ac:  98 10 20 02  mov  2, %o4
a00d90b0:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00d90b4:  da 08 60 32  ldub  [ %g1 + 0x32 ], %o5	! 0xa8078832
a00d90b8:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a00d90bc:  82 10 60 a4  or  %g1, 0xa4, %g1	! 0xa80760a4
a00d90c0:  9b 2b 60 02  sll  %o5, 2, %o5
a00d90c4:  da 00 40 0d  ld  [ %g1 + %o5 ], %o5
a00d90c8:  c2 03 40 00  ld  [ %o5 ], %g1
a00d90cc:  82 10 60 20  or  %g1, 0x20, %g1
a00d90d0:  c2 23 40 00  st  %g1, [ %o5 ]
a00d90d4:  81 c7 e0 08  ret
a00d90d8:  81 e8 00 00  restore
