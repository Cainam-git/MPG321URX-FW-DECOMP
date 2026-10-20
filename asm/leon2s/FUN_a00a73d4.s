# leon2s FUN_a00a73d4 0xa00a73d4-0xa00a7408 (52 bytes)
a00a73d4:  9c 03 bf 90  add  %sp, -112, %sp
a00a73d8:  9a 0a 20 1f  and  %o0, 0x1f, %o5
a00a73dc:  82 10 20 01  mov  1, %g1
a00a73e0:  83 28 40 0d  sll  %g1, %o5, %g1
a00a73e4:  c2 23 a0 64  st  %g1, [ %sp + 0x64 ]
a00a73e8:  91 32 20 05  srl  %o0, 5, %o0
a00a73ec:  c2 03 a0 64  ld  [ %sp + 0x64 ], %g1
a00a73f0:  91 2a 20 02  sll  %o0, 2, %o0
a00a73f4:  da 02 40 08  ld  [ %o1 + %o0 ], %o5
a00a73f8:  82 2b 40 01  andn  %o5, %g1, %g1
a00a73fc:  c2 22 40 08  st  %g1, [ %o1 + %o0 ]
a00a7400:  81 c3 e0 08  retl
a00a7404:  9c 23 bf 90  sub  %sp, -112, %sp
