# leon2s FUN_a00d9e5c 0xa00d9e5c-0xa00d9edc (128 bytes)
a00d9e5c:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d9e60:  80 a2 20 02  cmp  %o0, 2
a00d9e64:  02 80 00 06  be  0xa00d9e7c
a00d9e68:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00d9e6c:  80 a2 20 04  cmp  %o0, 4
a00d9e70:  02 80 00 0e  be  0xa00d9ea8
a00d9e74:  82 10 20 00  clr  %g1
a00d9e78:  30 80 00 17  b,a   0xa00d9ed4
a00d9e7c:  d8 08 60 32  ldub  [ %g1 + 0x32 ], %o4
a00d9e80:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00d9e84:  82 10 60 00  mov  %g1, %g1	! 0xa8078800
a00d9e88:  da 08 40 0c  ldub  [ %g1 + %o4 ], %o5
a00d9e8c:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00d9e90:  82 10 60 08  or  %g1, 8, %g1	! 0xa8078808
a00d9e94:  c2 08 40 0c  ldub  [ %g1 + %o4 ], %g1
a00d9e98:  98 23 40 01  sub  %o5, %g1, %o4
a00d9e9c:  80 a3 40 01  cmp  %o5, %g1
a00d9ea0:  10 80 00 09  b  0xa00d9ec4
a00d9ea4:  82 20 40 0d  sub  %g1, %o5, %g1
a00d9ea8:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00d9eac:  da 08 63 fd  ldub  [ %g1 + 0x3fd ], %o5	! 0xa80787fd
a00d9eb0:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00d9eb4:  c2 08 63 fc  ldub  [ %g1 + 0x3fc ], %g1	! 0xa80787fc
a00d9eb8:  98 20 40 0d  sub  %g1, %o5, %o4
a00d9ebc:  80 a0 40 0d  cmp  %g1, %o5
a00d9ec0:  82 23 40 01  sub  %o5, %g1, %g1
a00d9ec4:  08 80 00 04  bleu  0xa00d9ed4
a00d9ec8:  01 00 00 00  nop
a00d9ecc:  82 10 20 10  mov  0x10, %g1	! 0x10
a00d9ed0:  82 20 40 0c  sub  %g1, %o4, %g1
a00d9ed4:  81 c3 e0 08  retl
a00d9ed8:  90 08 60 ff  and  %g1, 0xff, %o0
