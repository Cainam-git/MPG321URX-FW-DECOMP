# leon2s FUN_a00a7168 0xa00a7168-0xa00a71b4 (76 bytes)
a00a7168:  82 0a 20 ff  and  %o0, 0xff, %g1
a00a716c:  80 a0 60 04  cmp  %g1, 4
a00a7170:  82 60 20 00  subx  %g0, 0, %g1
a00a7174:  90 0a 00 01  and  %o0, %g1, %o0
a00a7178:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a717c:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00a7180:  90 02 00 08  add  %o0, %o0, %o0
a00a7184:  93 2a 60 10  sll  %o1, 0x10, %o1
a00a7188:  82 10 61 88  or  %g1, 0x188, %g1
a00a718c:  c2 10 40 08  lduh  [ %g1 + %o0 ], %g1
a00a7190:  93 32 60 10  srl  %o1, 0x10, %o1
a00a7194:  82 00 40 09  add  %g1, %o1, %g1
a00a7198:  83 28 60 02  sll  %g1, 2, %g1
a00a719c:  1b 33 c0 00  sethi  %hi(0xcf000000), %o5
a00a71a0:  82 10 40 0d  or  %g1, %o5, %g1
a00a71a4:  94 0a a0 ff  and  %o2, 0xff, %o2
a00a71a8:  d4 20 40 00  st  %o2, [ %g1 ]
a00a71ac:  81 c3 e0 08  retl
a00a71b0:  01 00 00 00  nop
