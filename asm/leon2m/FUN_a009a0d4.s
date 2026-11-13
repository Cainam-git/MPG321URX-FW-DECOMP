# leon2m FUN_a009a0d4 0xa009a0d4-0xa009a198 (196 bytes)
a009a0d4:  9d e3 bf 98  save  %sp, -104, %sp
a009a0d8:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a009a0dc:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a009a0e0:  c2 04 63 ec  ld  [ %l1 + 0x3ec ], %g1
a009a0e4:  80 a0 60 c3  cmp  %g1, 0xc3
a009a0e8:  02 80 00 07  be  0xa009a104
a009a0ec:  9a 14 a2 90  or  %l2, 0x290, %o5
a009a0f0:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a009a0f4:  9a 14 a2 90  or  %l2, 0x290, %o5	! 0xa802d290
a009a0f8:  90 10 20 01  mov  1, %o0
a009a0fc:  10 80 00 03  b  0xa009a108
a009a100:  d0 2b 61 ee  stb  %o0, [ %o5 + 0x1ee ]
a009a104:  c0 2b 61 ee  clrb  [ %o5 + 0x1ee ]
a009a108:  21 2a 00 97  sethi  %hi(0xa8025c00), %l0
a009a10c:  da 0c 20 56  ldub  [ %l0 + 0x56 ], %o5	! 0xa8025c56
a009a110:  82 03 60 3d  add  %o5, 0x3d, %g1
a009a114:  40 00 3c aa  call  0xa00a93bc
a009a118:  90 08 60 ff  and  %g1, 0xff, %o0
a009a11c:  d2 0c 20 56  ldub  [ %l0 + 0x56 ], %o1
a009a120:  94 10 20 00  clr  %o2
a009a124:  a0 14 a2 90  or  %l2, 0x290, %l0
a009a128:  40 00 38 05  call  0xa00a813c
a009a12c:  90 10 20 01  mov  1, %o0
a009a130:  a4 10 20 36  mov  0x36, %l2
a009a134:  d0 0c 21 ee  ldub  [ %l0 + 0x1ee ], %o0
a009a138:  92 10 20 00  clr  %o1
a009a13c:  40 00 3d 45  call  0xa00a9650
a009a140:  e4 24 63 ec  st  %l2, [ %l1 + 0x3ec ]
a009a144:  94 10 20 01  mov  1, %o2
a009a148:  d2 0c 21 ee  ldub  [ %l0 + 0x1ee ], %o1
a009a14c:  40 00 37 fc  call  0xa00a813c
a009a150:  90 10 20 01  mov  1, %o0
a009a154:  de 04 63 ec  ld  [ %l1 + 0x3ec ], %o7
a009a158:  98 03 ff cc  add  %o7, -52, %o4
a009a15c:  90 0b 20 ff  and  %o4, 0xff, %o0
a009a160:  40 00 3b ab  call  0xa00a900c
a009a164:  92 10 20 01  mov  1, %o1
a009a168:  90 10 20 01  mov  1, %o0
a009a16c:  40 00 3c bf  call  0xa00a9468
a009a170:  92 10 20 02  mov  2, %o1
a009a174:  92 10 20 01  mov  1, %o1
a009a178:  40 00 64 d7  call  0xa00b34d4
a009a17c:  90 10 20 00  clr  %o0
a009a180:  13 2a 00 ac  sethi  %hi(0xa802b000), %o1
a009a184:  d6 0a 60 8e  ldub  [ %o1 + 0x8e ], %o3	! 0xa802b08e
a009a188:  94 12 e0 02  or  %o3, 2, %o2
a009a18c:  d4 2a 60 8e  stb  %o2, [ %o1 + 0x8e ]
a009a190:  81 c7 e0 08  ret
a009a194:  81 e8 00 00  restore
