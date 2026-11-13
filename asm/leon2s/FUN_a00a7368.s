# leon2s FUN_a00a7368 0xa00a7368-0xa00a73ac (68 bytes)
a00a7368:  03 00 00 3d  sethi  %hi(0xf400), %g1
a00a736c:  98 0a 20 ff  and  %o0, 0xff, %o4
a00a7370:  82 10 60 01  or  %g1, 1, %g1
a00a7374:  82 03 00 01  add  %o4, %g1, %g1
a00a7378:  96 0a 60 ff  and  %o1, 0xff, %o3
a00a737c:  83 28 60 02  sll  %g1, 2, %g1
a00a7380:  99 2b 20 08  sll  %o4, 8, %o4
a00a7384:  93 2a 60 10  sll  %o1, 0x10, %o1
a00a7388:  1b 33 c0 00  sethi  %hi(0xcf000000), %o5
a00a738c:  11 33 80 20  sethi  %hi(0xce008000), %o0
a00a7390:  82 10 40 0d  or  %g1, %o5, %g1
a00a7394:  98 03 00 0b  add  %o4, %o3, %o4
a00a7398:  93 32 60 18  srl  %o1, 0x18, %o1
a00a739c:  90 12 21 00  or  %o0, 0x100, %o0
a00a73a0:  d2 20 40 00  st  %o1, [ %g1 ]
a00a73a4:  81 c3 e0 08  retl
a00a73a8:  90 03 00 08  add  %o4, %o0, %o0
