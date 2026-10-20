# leon2m FUN_a00abd00 0xa00abd00-0xa00abdc8 (200 bytes)
a00abd00:  9d e3 bf 98  save  %sp, -104, %sp
a00abd04:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00abd08:  a0 12 a2 90  or  %o2, 0x290, %l0	! 0xa802d290
a00abd0c:  da 0c 20 13  ldub  [ %l0 + 0x13 ], %o5
a00abd10:  9a 03 7f ff  add  %o5, -1, %o5
a00abd14:  82 0b 60 ff  and  %o5, 0xff, %g1
a00abd18:  90 10 20 2c  mov  0x2c, %o0
a00abd1c:  92 10 20 08  mov  8, %o1
a00abd20:  96 10 20 07  mov  7, %o3
a00abd24:  98 10 20 01  mov  1, %o4
a00abd28:  80 a0 60 64  cmp  %g1, 0x64
a00abd2c:  08 80 00 04  bleu  0xa00abd3c
a00abd30:  94 10 00 01  mov  %g1, %o2
a00abd34:  10 80 00 1f  b  0xa00abdb0
a00abd38:  c0 2c 20 13  clrb  [ %l0 + 0x13 ]
a00abd3c:  7f ff fe 2d  call  0xa00ab5f0
a00abd40:  da 2c 20 13  stb  %o5, [ %l0 + 0x13 ]
a00abd44:  90 10 20 28  mov  0x28, %o0
a00abd48:  92 10 20 08  mov  8, %o1
a00abd4c:  94 10 20 03  mov  3, %o2
a00abd50:  96 10 27 42  mov  0x742, %o3
a00abd54:  40 02 6b 4b  call  0xa0146a80
a00abd58:  98 10 20 00  clr  %o4
a00abd5c:  90 10 20 2b  mov  0x2b, %o0
a00abd60:  92 10 20 08  mov  8, %o1
a00abd64:  94 10 20 01  mov  1, %o2
a00abd68:  96 10 27 42  mov  0x742, %o3
a00abd6c:  40 02 6b 45  call  0xa0146a80
a00abd70:  98 10 20 00  clr  %o4
a00abd74:  94 10 20 01  mov  1, %o2
a00abd78:  96 10 27 42  mov  0x742, %o3
a00abd7c:  98 10 20 00  clr  %o4
a00abd80:  90 10 20 32  mov  0x32, %o0
a00abd84:  40 02 6b 3f  call  0xa0146a80
a00abd88:  92 10 20 08  mov  8, %o1
a00abd8c:  90 10 20 e8  mov  0xe8, %o0
a00abd90:  40 02 6b 70  call  0xa0146b50
a00abd94:  92 10 20 00  clr  %o1
a00abd98:  d4 0c 20 13  ldub  [ %l0 + 0x13 ], %o2
a00abd9c:  90 10 20 29  mov  0x29, %o0
a00abda0:  40 00 2c 4a  call  0xa00b6ec8
a00abda4:  92 10 20 08  mov  8, %o1
a00abda8:  40 00 a2 21  call  0xa00d462c
a00abdac:  01 00 00 00  nop
a00abdb0:  11 2a 00 ac  sethi  %hi(0xa802b000), %o0
a00abdb4:  d6 0a 20 8e  ldub  [ %o0 + 0x8e ], %o3	! 0xa802b08e
a00abdb8:  92 12 e0 02  or  %o3, 2, %o1
a00abdbc:  d2 2a 20 8e  stb  %o1, [ %o0 + 0x8e ]
a00abdc0:  81 c7 e0 08  ret
a00abdc4:  81 e8 00 00  restore
