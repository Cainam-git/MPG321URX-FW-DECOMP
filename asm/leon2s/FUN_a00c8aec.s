# leon2s FUN_a00c8aec 0xa00c8aec-0xa00c8b18 (44 bytes)
a00c8aec:  90 0a 20 ff  and  %o0, 0xff, %o0
a00c8af0:  98 02 00 08  add  %o0, %o0, %o4
a00c8af4:  98 03 00 08  add  %o4, %o0, %o4
a00c8af8:  17 2a 01 e2  sethi  %hi(0xa8078800), %o3
a00c8afc:  96 12 e3 b0  or  %o3, 0x3b0, %o3	! 0xa8078bb0
a00c8b00:  99 2b 20 03  sll  %o4, 3, %o4
a00c8b04:  c2 02 c0 0c  ld  [ %o3 + %o4 ], %g1
a00c8b08:  1b 00 00 c0  sethi  %hi(0x30000), %o5
a00c8b0c:  82 10 40 0d  or  %g1, %o5, %g1
a00c8b10:  81 c3 e0 08  retl
a00c8b14:  c2 22 c0 0c  st  %g1, [ %o3 + %o4 ]
