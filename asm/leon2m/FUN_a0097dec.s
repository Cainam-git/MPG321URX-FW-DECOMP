# leon2m FUN_a0097dec 0xa0097dec-0xa0097f48 (348 bytes)
a0097dec:  9d e3 bf 98  save  %sp, -104, %sp
a0097df0:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a0097df4:  da 04 63 ec  ld  [ %l1 + 0x3ec ], %o5	! 0xa802afec
a0097df8:  21 2a 00 97  sethi  %hi(0xa8025c00), %l0
a0097dfc:  82 03 7f 81  add  %o5, -127, %g1
a0097e00:  d0 0c 20 54  ldub  [ %l0 + 0x54 ], %o0
a0097e04:  80 a0 40 08  cmp  %g1, %o0
a0097e08:  02 80 00 0a  be  0xa0097e30
a0097e0c:  80 a3 60 7f  cmp  %o5, 0x7f
a0097e10:  40 00 45 6b  call  0xa00a93bc
a0097e14:  01 00 00 00  nop
a0097e18:  90 10 20 01  mov  1, %o0	! 0x1
a0097e1c:  d2 0c 20 54  ldub  [ %l0 + 0x54 ], %o1
a0097e20:  40 00 40 c7  call  0xa00a813c
a0097e24:  94 10 20 00  clr  %o2
a0097e28:  da 04 63 ec  ld  [ %l1 + 0x3ec ], %o5
a0097e2c:  80 a3 60 7f  cmp  %o5, 0x7f
a0097e30:  02 80 00 18  be  0xa0097e90
a0097e34:  80 a3 60 80  cmp  %o5, 0x80
a0097e38:  02 80 00 1e  be  0xa0097eb0
a0097e3c:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a0097e40:  d8 0c 20 54  ldub  [ %l0 + 0x54 ], %o4
a0097e44:  96 14 a2 90  or  %l2, 0x290, %o3
a0097e48:  da 0a e0 2f  ldub  [ %o3 + 0x2f ], %o5
a0097e4c:  9e 0b 20 ff  and  %o4, 0xff, %o7
a0097e50:  80 a3 40 0f  cmp  %o5, %o7
a0097e54:  22 80 00 1f  be,a   0xa0097ed0
a0097e58:  d0 04 63 ec  ld  [ %l1 + 0x3ec ], %o0
a0097e5c:  d8 2a e0 2f  stb  %o4, [ %o3 + 0x2f ]
a0097e60:  40 01 04 e7  call  0xa00d91fc
a0097e64:  90 10 20 00  clr  %o0
a0097e68:  90 10 20 00  clr  %o0
a0097e6c:  40 02 c0 ff  call  0xa0148268
a0097e70:  92 10 20 01  mov  1, %o1
a0097e74:  90 10 20 01  mov  1, %o0
a0097e78:  40 02 c0 fc  call  0xa0148268
a0097e7c:  92 10 20 01  mov  1, %o1
a0097e80:  40 01 08 f5  call  0xa00da254
a0097e84:  01 00 00 00  nop
a0097e88:  10 80 00 12  b  0xa0097ed0
a0097e8c:  d0 04 63 ec  ld  [ %l1 + 0x3ec ], %o0
a0097e90:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a0097e94:  9a 14 a2 90  or  %l2, 0x290, %o5	! 0xa802d290
a0097e98:  d0 0b 60 2f  ldub  [ %o5 + 0x2f ], %o0
a0097e9c:  80 a2 20 00  cmp  %o0, 0
a0097ea0:  22 80 00 0c  be,a   0xa0097ed0
a0097ea4:  d0 04 63 ec  ld  [ %l1 + 0x3ec ], %o0
a0097ea8:  10 bf ff ee  b  0xa0097e60
a0097eac:  c0 2b 60 2f  clrb  [ %o5 + 0x2f ]
a0097eb0:  9a 14 a2 90  or  %l2, 0x290, %o5
a0097eb4:  d2 0b 60 2f  ldub  [ %o5 + 0x2f ], %o1
a0097eb8:  80 a2 60 01  cmp  %o1, 1
a0097ebc:  02 80 00 04  be  0xa0097ecc
a0097ec0:  94 10 20 01  mov  1, %o2
a0097ec4:  10 bf ff e7  b  0xa0097e60
a0097ec8:  d4 2b 60 2f  stb  %o2, [ %o5 + 0x2f ]
a0097ecc:  d0 04 63 ec  ld  [ %l1 + 0x3ec ], %o0
a0097ed0:  82 02 3f 81  add  %o0, -127, %g1
a0097ed4:  40 00 45 3a  call  0xa00a93bc
a0097ed8:  90 08 60 ff  and  %g1, 0xff, %o0
a0097edc:  a0 14 a2 90  or  %l2, 0x290, %l0
a0097ee0:  94 10 20 01  mov  1, %o2
a0097ee4:  d2 0c 20 2f  ldub  [ %l0 + 0x2f ], %o1
a0097ee8:  40 00 40 95  call  0xa00a813c
a0097eec:  90 10 20 01  mov  1, %o0
a0097ef0:  d0 0c 20 2f  ldub  [ %l0 + 0x2f ], %o0
a0097ef4:  40 00 45 d7  call  0xa00a9650
a0097ef8:  92 10 20 00  clr  %o1
a0097efc:  90 10 20 01  mov  1, %o0
a0097f00:  40 00 45 5a  call  0xa00a9468
a0097f04:  92 10 20 02  mov  2, %o1
a0097f08:  a0 10 20 25  mov  0x25, %l0
a0097f0c:  90 10 20 02  mov  2, %o0
a0097f10:  92 10 20 01  mov  1, %o1
a0097f14:  40 00 44 3e  call  0xa00a900c
a0097f18:  e0 24 63 ec  st  %l0, [ %l1 + 0x3ec ]
a0097f1c:  90 10 20 01  mov  1, %o0
a0097f20:  40 00 45 52  call  0xa00a9468
a0097f24:  92 10 20 02  mov  2, %o1
a0097f28:  90 10 20 00  clr  %o0
a0097f2c:  40 00 6d 6a  call  0xa00b34d4
a0097f30:  92 10 20 01  mov  1, %o1
a0097f34:  98 10 20 05  mov  5, %o4
a0097f38:  17 2a 00 ac  sethi  %hi(0xa802b000), %o3
a0097f3c:  d8 2a e0 8f  stb  %o4, [ %o3 + 0x8f ]	! 0xa802b08f
a0097f40:  81 c7 e0 08  ret
a0097f44:  81 e8 00 00  restore
