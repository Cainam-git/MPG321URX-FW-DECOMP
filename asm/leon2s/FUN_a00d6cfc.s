# leon2s FUN_a00d6cfc 0xa00d6cfc-0xa00d6dac (176 bytes)
a00d6cfc:  03 3f ff e0  sethi  %hi(0xffff8000), %g1
a00d6d00:  96 10 60 ff  or  %g1, 0xff, %o3	! 0xffff80ff
a00d6d04:  c2 0a 40 00  ldub  [ %o1 ], %g1
a00d6d08:  83 30 60 04  srl  %g1, 4, %g1
a00d6d0c:  82 00 7f ff  add  %g1, -1, %g1
a00d6d10:  9b 30 60 1f  srl  %g1, 0x1f, %o5
a00d6d14:  9a 00 40 0d  add  %g1, %o5, %o5
a00d6d18:  9b 3b 60 01  sra  %o5, 1, %o5
a00d6d1c:  80 88 60 01  btst  1, %g1
a00d6d20:  02 80 00 03  be  0xa00d6d2c
a00d6d24:  98 10 00 0d  mov  %o5, %o4
a00d6d28:  98 03 60 01  add  %o5, 1, %o4
a00d6d2c:  98 0b 20 ff  and  %o4, 0xff, %o4
a00d6d30:  98 02 40 0c  add  %o1, %o4, %o4
a00d6d34:  da 0b 20 03  ldub  [ %o4 + 3 ], %o5
a00d6d38:  c2 12 00 00  lduh  [ %o0 ], %g1
a00d6d3c:  9a 0b 60 7f  and  %o5, 0x7f, %o5
a00d6d40:  9b 2b 60 08  sll  %o5, 8, %o5
a00d6d44:  82 08 40 0b  and  %g1, %o3, %g1
a00d6d48:  82 10 40 0d  or  %g1, %o5, %g1
a00d6d4c:  c2 32 00 00  sth  %g1, [ %o0 ]
a00d6d50:  da 0b 20 04  ldub  [ %o4 + 4 ], %o5
a00d6d54:  9a 0b 60 f0  and  %o5, 0xf0, %o5
a00d6d58:  82 08 7f 0f  and  %g1, -241, %g1
a00d6d5c:  82 10 40 0d  or  %g1, %o5, %g1
a00d6d60:  c2 32 00 00  sth  %g1, [ %o0 ]
a00d6d64:  da 0b 20 04  ldub  [ %o4 + 4 ], %o5
a00d6d68:  9a 0b 60 0f  and  %o5, 0xf, %o5
a00d6d6c:  82 08 7f f0  and  %g1, -16, %g1
a00d6d70:  82 10 40 0d  or  %g1, %o5, %g1
a00d6d74:  c2 32 00 00  sth  %g1, [ %o0 ]
a00d6d78:  da 0b 20 05  ldub  [ %o4 + 5 ], %o5
a00d6d7c:  c2 12 20 02  lduh  [ %o0 + 2 ], %g1
a00d6d80:  9a 0b 60 7f  and  %o5, 0x7f, %o5
a00d6d84:  9b 2b 60 08  sll  %o5, 8, %o5
a00d6d88:  82 08 40 0b  and  %g1, %o3, %g1
a00d6d8c:  82 10 40 0d  or  %g1, %o5, %g1
a00d6d90:  c2 32 20 02  sth  %g1, [ %o0 + 2 ]
a00d6d94:  c2 0b 20 06  ldub  [ %o4 + 6 ], %g1
a00d6d98:  da 0b 20 07  ldub  [ %o4 + 7 ], %o5
a00d6d9c:  83 28 60 08  sll  %g1, 8, %g1
a00d6da0:  82 10 40 0d  or  %g1, %o5, %g1
a00d6da4:  81 c3 e0 08  retl
a00d6da8:  c2 32 20 04  sth  %g1, [ %o0 + 4 ]
