# leon2s FUN_a00a8054 0xa00a8054-0xa00a80cc (120 bytes)
a00a8054:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a8058:  82 02 00 08  add  %o0, %o0, %g1
a00a805c:  82 00 40 08  add  %g1, %o0, %g1
a00a8060:  82 00 40 01  add  %g1, %g1, %g1
a00a8064:  92 0a 60 ff  and  %o1, 0xff, %o1
a00a8068:  82 00 40 09  add  %g1, %o1, %g1
a00a806c:  95 2a a0 10  sll  %o2, 0x10, %o2
a00a8070:  98 00 40 01  add  %g1, %g1, %o4
a00a8074:  95 32 a0 10  srl  %o2, 0x10, %o2
a00a8078:  96 0a e0 ff  and  %o3, 0xff, %o3
a00a807c:  80 a2 20 01  cmp  %o0, 1
a00a8080:  9a 10 20 01  mov  1, %o5
a00a8084:  18 80 00 03  bgu  0xa00a8090
a00a8088:  82 10 20 01  mov  1, %g1
a00a808c:  9a 10 20 00  clr  %o5
a00a8090:  80 a2 60 05  cmp  %o1, 5
a00a8094:  28 80 00 02  bleu,a   0xa00a809c
a00a8098:  82 10 20 00  clr  %g1
a00a809c:  80 93 40 01  orcc  %o5, %g1, %g0
a00a80a0:  12 80 00 09  bne  0xa00a80c4
a00a80a4:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00a80a8:  82 10 61 44  or  %g1, 0x144, %g1	! 0xa00b4d44
a00a80ac:  c2 10 40 0c  lduh  [ %g1 + %o4 ], %g1
a00a80b0:  82 00 40 0a  add  %g1, %o2, %g1
a00a80b4:  83 28 60 02  sll  %g1, 2, %g1
a00a80b8:  1b 33 c0 00  sethi  %hi(0xcf000000), %o5
a00a80bc:  82 10 40 0d  or  %g1, %o5, %g1
a00a80c0:  d6 20 40 00  st  %o3, [ %g1 ]
a00a80c4:  81 c3 e0 08  retl
a00a80c8:  01 00 00 00  nop
