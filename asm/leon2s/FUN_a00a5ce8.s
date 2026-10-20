# leon2s FUN_a00a5ce8 0xa00a5ce8-0xa00a5d8c (164 bytes)
a00a5ce8:  9d e3 bf 90  save  %sp, -112, %sp
a00a5cec:  90 10 20 01  mov  1, %o0
a00a5cf0:  7f ff fc 75  call  0xa00a4ec4
a00a5cf4:  92 10 20 00  clr  %o1
a00a5cf8:  11 2a 01 f6  sethi  %hi(0xa807d800), %o0
a00a5cfc:  90 12 23 74  or  %o0, 0x374, %o0	! 0xa807db74
a00a5d00:  92 10 20 00  clr  %o1
a00a5d04:  40 00 2e 2a  call  0xa00b15ac
a00a5d08:  94 10 20 90  mov  0x90, %o2
a00a5d0c:  a4 10 20 00  clr  %l2
a00a5d10:  90 0c a0 ff  and  %l2, 0xff, %o0
a00a5d14:  a0 02 00 08  add  %o0, %o0, %l0
a00a5d18:  96 10 20 01  mov  1, %o3
a00a5d1c:  a0 04 00 08  add  %l0, %o0, %l0
a00a5d20:  23 2a 01 f7  sethi  %hi(0xa807dc00), %l1
a00a5d24:  d6 27 bf f4  st  %o3, [ %fp + -12 ]
a00a5d28:  a2 14 60 04  or  %l1, 4, %l1
a00a5d2c:  a1 2c 20 02  sll  %l0, 2, %l0
a00a5d30:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a00a5d34:  d8 04 40 10  ld  [ %l1 + %l0 ], %o4
a00a5d38:  da 03 20 b0  ld  [ %o4 + 0xb0 ], %o5
a00a5d3c:  82 2b 40 01  andn  %o5, %g1, %g1
a00a5d40:  c2 23 20 b0  st  %g1, [ %o4 + 0xb0 ]
a00a5d44:  d6 27 bf f4  st  %o3, [ %fp + -12 ]
a00a5d48:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a00a5d4c:  da 03 20 bc  ld  [ %o4 + 0xbc ], %o5
a00a5d50:  82 2b 40 01  andn  %o5, %g1, %g1
a00a5d54:  c2 23 20 bc  st  %g1, [ %o4 + 0xbc ]
a00a5d58:  7f ff ff d7  call  0xa00a5cb4
a00a5d5c:  01 00 00 00  nop
a00a5d60:  d8 04 40 10  ld  [ %l1 + %l0 ], %o4
a00a5d64:  c2 03 20 c0  ld  [ %o4 + 0xc0 ], %g1
a00a5d68:  1b 00 00 08  sethi  %hi(0x2000), %o5
a00a5d6c:  82 10 40 0d  or  %g1, %o5, %g1
a00a5d70:  a4 04 a0 01  inc  %l2
a00a5d74:  c2 23 20 c0  st  %g1, [ %o4 + 0xc0 ]
a00a5d78:  80 8c a0 ff  btst  0xff, %l2
a00a5d7c:  02 bf ff e6  be  0xa00a5d14
a00a5d80:  90 0c a0 ff  and  %l2, 0xff, %o0
a00a5d84:  81 c7 e0 08  ret
a00a5d88:  81 e8 00 00  restore
