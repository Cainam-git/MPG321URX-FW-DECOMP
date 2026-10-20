# leon2s FUN_a00abbc4 0xa00abbc4-0xa00abe20 (604 bytes)  [FUN_a00abe18 = unreachable ret/restore tail, merged]
a00abbc4:  9d e3 bf 98  save  %sp, -104, %sp
a00abbc8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00abbcc:  90 10 00 18  mov  %i0, %o0
a00abbd0:  92 10 23 b0  mov  0x3b0, %o1
a00abbd4:  7f ff ec 0b  call  0xa00a6c00
a00abbd8:  94 10 20 14  mov  0x14, %o2
a00abbdc:  35 2a 01 f7  sethi  %hi(0xa807dc00), %i2
a00abbe0:  9a 16 a0 18  or  %i2, 0x18, %o5	! 0xa807dc18
a00abbe4:  82 5e 21 2c  smul  %i0, 0x12c, %g1
a00abbe8:  82 00 40 0d  add  %g1, %o5, %g1
a00abbec:  c2 08 61 10  ldub  [ %g1 + 0x110 ], %g1
a00abbf0:  90 10 00 18  mov  %i0, %o0
a00abbf4:  92 10 23 b1  mov  0x3b1, %o1
a00abbf8:  80 a0 60 03  cmp  %g1, 3
a00abbfc:  02 80 00 0f  be  0xa00abc38
a00abc00:  94 10 20 1e  mov  0x1e, %o2
a00abc04:  90 10 00 18  mov  %i0, %o0
a00abc08:  92 10 23 b1  mov  0x3b1, %o1
a00abc0c:  80 a0 60 02  cmp  %g1, 2
a00abc10:  02 80 00 0a  be  0xa00abc38
a00abc14:  94 10 20 14  mov  0x14, %o2
a00abc18:  90 10 00 18  mov  %i0, %o0
a00abc1c:  92 10 23 b1  mov  0x3b1, %o1
a00abc20:  80 a0 60 01  cmp  %g1, 1
a00abc24:  02 80 00 05  be  0xa00abc38
a00abc28:  94 10 20 0a  mov  0xa, %o2
a00abc2c:  90 10 00 18  mov  %i0, %o0
a00abc30:  92 10 23 b1  mov  0x3b1, %o1
a00abc34:  94 10 20 06  mov  6, %o2
a00abc38:  7f ff eb f2  call  0xa00a6c00
a00abc3c:  01 00 00 00  nop
a00abc40:  9a 16 a0 18  or  %i2, 0x18, %o5
a00abc44:  82 5e 21 2c  smul  %i0, 0x12c, %g1
a00abc48:  82 00 40 0d  add  %g1, %o5, %g1
a00abc4c:  c2 08 61 11  ldub  [ %g1 + 0x111 ], %g1
a00abc50:  90 10 00 18  mov  %i0, %o0
a00abc54:  92 10 23 b2  mov  0x3b2, %o1
a00abc58:  80 a0 60 02  cmp  %g1, 2
a00abc5c:  02 80 00 0a  be  0xa00abc84
a00abc60:  94 10 20 c4  mov  0xc4, %o2
a00abc64:  90 10 00 18  mov  %i0, %o0
a00abc68:  92 10 23 b2  mov  0x3b2, %o1
a00abc6c:  80 a0 60 01  cmp  %g1, 1
a00abc70:  02 80 00 05  be  0xa00abc84
a00abc74:  94 10 20 c2  mov  0xc2, %o2
a00abc78:  90 10 00 18  mov  %i0, %o0
a00abc7c:  92 10 23 b2  mov  0x3b2, %o1
a00abc80:  94 10 20 c1  mov  0xc1, %o2
a00abc84:  7f ff eb df  call  0xa00a6c00
a00abc88:  01 00 00 00  nop
a00abc8c:  82 16 a0 18  or  %i2, 0x18, %g1
a00abc90:  9a 5e 21 2c  smul  %i0, 0x12c, %o5
a00abc94:  9a 03 40 01  add  %o5, %g1, %o5
a00abc98:  c2 0b 61 10  ldub  [ %o5 + 0x110 ], %g1
a00abc9c:  90 10 00 18  mov  %i0, %o0
a00abca0:  92 10 23 b3  mov  0x3b3, %o1
a00abca4:  80 a0 60 03  cmp  %g1, 3
a00abca8:  02 80 00 05  be  0xa00abcbc
a00abcac:  94 10 20 81  mov  0x81, %o2
a00abcb0:  90 10 00 18  mov  %i0, %o0
a00abcb4:  92 10 23 b3  mov  0x3b3, %o1
a00abcb8:  94 10 20 01  mov  1, %o2
a00abcbc:  7f ff eb d1  call  0xa00a6c00
a00abcc0:  01 00 00 00  nop
a00abcc4:  90 10 00 18  mov  %i0, %o0
a00abcc8:  92 10 23 b4  mov  0x3b4, %o1
a00abccc:  7f ff eb cd  call  0xa00a6c00
a00abcd0:  94 10 20 01  mov  1, %o2
a00abcd4:  90 10 00 18  mov  %i0, %o0
a00abcd8:  92 10 23 b6  mov  0x3b6, %o1
a00abcdc:  7f ff eb c9  call  0xa00a6c00
a00abce0:  94 10 20 01  mov  1, %o2
a00abce4:  90 10 00 18  mov  %i0, %o0
a00abce8:  92 10 23 ba  mov  0x3ba, %o1
a00abcec:  94 10 20 04  mov  4, %o2
a00abcf0:  7f ff eb ea  call  0xa00a6c98
a00abcf4:  96 10 20 01  mov  1, %o3
a00abcf8:  90 10 00 18  mov  %i0, %o0
a00abcfc:  92 10 23 bd  mov  0x3bd, %o1
a00abd00:  7f ff eb c0  call  0xa00a6c00
a00abd04:  94 10 20 00  clr  %o2
a00abd08:  80 a6 20 00  cmp  %i0, 0
a00abd0c:  12 80 00 20  bne  0xa00abd8c
a00abd10:  1b 2a 01 f7  sethi  %hi(0xa807dc00), %o5
a00abd14:  82 16 a0 18  or  %i2, 0x18, %g1
a00abd18:  c2 08 61 12  ldub  [ %g1 + 0x112 ], %g1
a00abd1c:  80 a0 60 00  cmp  %g1, 0
a00abd20:  02 80 00 1c  be  0xa00abd90
a00abd24:  82 5e 21 2c  smul  %i0, 0x12c, %g1
a00abd28:  90 10 20 00  clr  %o0
a00abd2c:  92 10 23 b5  mov  0x3b5, %o1
a00abd30:  7f ff eb b4  call  0xa00a6c00
a00abd34:  94 10 20 01  mov  1, %o2
a00abd38:  90 10 20 00  clr  %o0
a00abd3c:  92 10 23 b7  mov  0x3b7, %o1
a00abd40:  7f ff eb b0  call  0xa00a6c00
a00abd44:  94 10 20 81  mov  0x81, %o2
a00abd48:  90 10 20 00  clr  %o0
a00abd4c:  92 10 23 b8  mov  0x3b8, %o1
a00abd50:  7f ff eb ac  call  0xa00a6c00
a00abd54:  94 10 20 00  clr  %o2
a00abd58:  90 10 20 00  clr  %o0
a00abd5c:  92 10 23 b9  mov  0x3b9, %o1
a00abd60:  7f ff eb a8  call  0xa00a6c00
a00abd64:  94 10 20 00  clr  %o2
a00abd68:  90 10 20 00  clr  %o0
a00abd6c:  92 10 23 ba  mov  0x3ba, %o1
a00abd70:  7f ff eb a4  call  0xa00a6c00
a00abd74:  94 10 20 04  mov  4, %o2
a00abd78:  90 10 20 00  clr  %o0
a00abd7c:  92 10 23 bb  mov  0x3bb, %o1
a00abd80:  7f ff eb a0  call  0xa00a6c00
a00abd84:  94 10 20 00  clr  %o2
a00abd88:  1b 2a 01 f7  sethi  %hi(0xa807dc00), %o5
a00abd8c:  82 5e 21 2c  smul  %i0, 0x12c, %g1
a00abd90:  9a 13 60 18  or  %o5, 0x18, %o5
a00abd94:  b4 00 40 0d  add  %g1, %o5, %i2
a00abd98:  c2 0e a1 15  ldub  [ %i2 + 0x115 ], %g1
a00abd9c:  80 a0 60 00  cmp  %g1, 0
a00abda0:  22 80 00 08  be,a   0xa00abdc0
a00abda4:  c2 0e a1 23  ldub  [ %i2 + 0x123 ], %g1
a00abda8:  90 10 00 18  mov  %i0, %o0
a00abdac:  92 10 23 b7  mov  0x3b7, %o1
a00abdb0:  94 10 20 40  mov  0x40, %o2
a00abdb4:  7f ff eb b9  call  0xa00a6c98
a00abdb8:  96 10 20 01  mov  1, %o3
a00abdbc:  c2 0e a1 23  ldub  [ %i2 + 0x123 ], %g1
a00abdc0:  80 a0 60 00  cmp  %g1, 0
a00abdc4:  22 80 00 0f  be,a   0xa00abe00
a00abdc8:  c2 0e a1 24  ldub  [ %i2 + 0x124 ], %g1
a00abdcc:  90 10 00 18  mov  %i0, %o0
a00abdd0:  92 10 23 c0  mov  0x3c0, %o1
a00abdd4:  7f ff eb 8b  call  0xa00a6c00
a00abdd8:  94 10 20 f0  mov  0xf0, %o2
a00abddc:  90 10 00 18  mov  %i0, %o0
a00abde0:  92 10 23 c2  mov  0x3c2, %o1
a00abde4:  7f ff eb 87  call  0xa00a6c00
a00abde8:  94 10 20 10  mov  0x10, %o2
a00abdec:  90 10 00 18  mov  %i0, %o0
a00abdf0:  92 10 23 c3  mov  0x3c3, %o1
a00abdf4:  7f ff eb 83  call  0xa00a6c00
a00abdf8:  94 10 20 10  mov  0x10, %o2
a00abdfc:  c2 0e a1 24  ldub  [ %i2 + 0x124 ], %g1
a00abe00:  80 a0 60 00  cmp  %g1, 0
a00abe04:  02 80 00 04  be  0xa00abe14
a00abe08:  b2 10 23 c4  mov  0x3c4, %i1
a00abe0c:  7f ff eb 7d  call  0xa00a6c00
a00abe10:  95 e8 20 01  restore  %g0, 1, %o2
a00abe14:  01 00 00 00  nop
a00abe18:  81 c7 e0 08  ret
a00abe1c:  81 e8 00 00  restore
