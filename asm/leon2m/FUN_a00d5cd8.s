# leon2m FUN_a00d5cd8 0xa00d5cd8-0xa00d5d8c (180 bytes)
a00d5cd8:  9d e3 bf 98  save  %sp, -104, %sp
a00d5cdc:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00d5ce0:  b2 16 22 90  or  %i0, 0x290, %i1	! 0xa802d290
a00d5ce4:  c2 0e 60 1f  ldub  [ %i1 + 0x1f ], %g1
a00d5ce8:  80 a0 60 00  cmp  %g1, 0
a00d5cec:  32 80 00 0c  bne,a   0xa00d5d1c
a00d5cf0:  d4 06 60 ac  ld  [ %i1 + 0xac ], %o2
a00d5cf4:  da 06 60 ac  ld  [ %i1 + 0xac ], %o5
a00d5cf8:  13 00 00 80  sethi  %hi(0x20000), %o1
a00d5cfc:  80 8b 40 09  btst  %o5, %o1
a00d5d00:  12 80 00 10  bne  0xa00d5d40
a00d5d04:  90 10 20 00  clr  %o0
a00d5d08:  c0 2e 60 3e  clrb  [ %i1 + 0x3e ]
a00d5d0c:  9e 16 22 90  or  %i0, 0x290, %o7
a00d5d10:  f0 0b e0 3e  ldub  [ %o7 + 0x3e ], %i0
a00d5d14:  40 01 c6 e7  call  0xa01478b0
a00d5d18:  93 e8 20 07  restore  %g0, 7, %o1
a00d5d1c:  11 00 00 80  sethi  %hi(0x20000), %o0
a00d5d20:  80 8a 80 08  btst  %o2, %o0
a00d5d24:  22 bf ff fa  be,a   0xa00d5d0c
a00d5d28:  c0 2e 60 3e  clrb  [ %i1 + 0x3e ]
a00d5d2c:  d8 06 60 a8  ld  [ %i1 + 0xa8 ], %o4
a00d5d30:  17 00 00 10  sethi  %hi(0x4000), %o3
a00d5d34:  80 8b 00 0b  btst  %o4, %o3
a00d5d38:  02 80 00 0d  be  0xa00d5d6c
a00d5d3c:  90 10 20 01  mov  1, %o0
a00d5d40:  40 01 b9 d3  call  0xa014448c
a00d5d44:  01 00 00 00  nop
a00d5d48:  40 01 ba 2d  call  0xa01445fc
a00d5d4c:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d5d50:  40 01 ba 4f  call  0xa014468c
a00d5d54:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d5d58:  d0 2e 60 3e  stb  %o0, [ %i1 + 0x3e ]
a00d5d5c:  9e 16 22 90  or  %i0, 0x290, %o7
a00d5d60:  f0 0b e0 3e  ldub  [ %o7 + 0x3e ], %i0
a00d5d64:  40 01 c6 d3  call  0xa01478b0
a00d5d68:  93 e8 20 07  restore  %g0, 7, %o1
a00d5d6c:  40 01 b9 c8  call  0xa014448c
a00d5d70:  90 10 20 00  clr  %o0
a00d5d74:  40 01 ba 22  call  0xa01445fc
a00d5d78:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d5d7c:  40 01 ba 44  call  0xa014468c
a00d5d80:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d5d84:  10 bf ff f6  b  0xa00d5d5c
a00d5d88:  d0 2e 60 3e  stb  %o0, [ %i1 + 0x3e ]
