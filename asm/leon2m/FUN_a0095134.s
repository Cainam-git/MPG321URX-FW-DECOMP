# leon2m FUN_a0095134 0xa0095134-0xa00951a8 (116 bytes)
a0095134:  9d e3 bf 98  save  %sp, -104, %sp
a0095138:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a009513c:  a0 12 62 90  or  %o1, 0x290, %l0	! 0xa802d290
a0095140:  23 2a 00 97  sethi  %hi(0xa8025c00), %l1
a0095144:  d0 0c 20 20  ldub  [ %l0 + 0x20 ], %o0
a0095148:  d8 0c 60 55  ldub  [ %l1 + 0x55 ], %o4
a009514c:  80 a2 00 0c  cmp  %o0, %o4
a0095150:  9a 10 20 0f  mov  0xf, %o5
a0095154:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a0095158:  da 28 60 8f  stb  %o5, [ %g1 + 0x8f ]	! 0xa802b08f
a009515c:  d8 2c 20 20  stb  %o4, [ %l0 + 0x20 ]
a0095160:  02 80 00 04  be  0xa0095170
a0095164:  90 10 20 01  mov  1, %o0
a0095168:  40 01 01 f4  call  0xa00d5938
a009516c:  01 00 00 00  nop
a0095170:  40 00 4e c6  call  0xa00a8c88
a0095174:  01 00 00 00  nop
a0095178:  40 00 4d 5c  call  0xa00a86e8
a009517c:  01 00 00 00  nop
a0095180:  9e 10 20 7a  mov  0x7a, %o7	! 0x7a
a0095184:  17 2a 00 ab  sethi  %hi(0xa802ac00), %o3
a0095188:  de 22 e3 ec  st  %o7, [ %o3 + 0x3ec ]	! 0xa802afec
a009518c:  90 10 20 00  clr  %o0
a0095190:  40 00 51 30  call  0xa00a9650
a0095194:  92 10 20 01  mov  1, %o1
a0095198:  d4 0c 21 a4  ldub  [ %l0 + 0x1a4 ], %o2
a009519c:  d4 2c 60 55  stb  %o2, [ %l1 + 0x55 ]
a00951a0:  81 c7 e0 08  ret
a00951a4:  81 e8 00 00  restore
