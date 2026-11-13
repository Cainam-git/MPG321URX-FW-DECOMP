# leon2m FUN_a00abdc8 0xa00abdc8-0xa00abe94 (204 bytes)
a00abdc8:  9d e3 bf 98  save  %sp, -104, %sp
a00abdcc:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00abdd0:  a0 12 a2 90  or  %o2, 0x290, %l0	! 0xa802d290
a00abdd4:  da 0c 20 13  ldub  [ %l0 + 0x13 ], %o5
a00abdd8:  9a 03 60 01  inc  %o5
a00abddc:  82 0b 60 ff  and  %o5, 0xff, %g1
a00abde0:  90 10 20 2c  mov  0x2c, %o0
a00abde4:  92 10 20 08  mov  8, %o1
a00abde8:  96 10 20 07  mov  7, %o3
a00abdec:  98 10 20 01  mov  1, %o4
a00abdf0:  80 a0 60 64  cmp  %g1, 0x64
a00abdf4:  08 80 00 05  bleu  0xa00abe08
a00abdf8:  94 10 00 01  mov  %g1, %o2
a00abdfc:  90 10 20 64  mov  0x64, %o0
a00abe00:  10 80 00 1f  b  0xa00abe7c
a00abe04:  d0 2c 20 13  stb  %o0, [ %l0 + 0x13 ]
a00abe08:  7f ff fd fa  call  0xa00ab5f0
a00abe0c:  da 2c 20 13  stb  %o5, [ %l0 + 0x13 ]
a00abe10:  90 10 20 28  mov  0x28, %o0
a00abe14:  92 10 20 08  mov  8, %o1
a00abe18:  94 10 20 03  mov  3, %o2
a00abe1c:  96 10 27 42  mov  0x742, %o3
a00abe20:  40 02 6b 18  call  0xa0146a80
a00abe24:  98 10 20 00  clr  %o4
a00abe28:  90 10 20 2b  mov  0x2b, %o0
a00abe2c:  92 10 20 08  mov  8, %o1
a00abe30:  94 10 20 01  mov  1, %o2
a00abe34:  96 10 27 42  mov  0x742, %o3
a00abe38:  40 02 6b 12  call  0xa0146a80
a00abe3c:  98 10 20 00  clr  %o4
a00abe40:  94 10 20 01  mov  1, %o2
a00abe44:  96 10 27 42  mov  0x742, %o3
a00abe48:  98 10 20 00  clr  %o4
a00abe4c:  90 10 20 32  mov  0x32, %o0
a00abe50:  40 02 6b 0c  call  0xa0146a80
a00abe54:  92 10 20 08  mov  8, %o1
a00abe58:  90 10 20 e8  mov  0xe8, %o0
a00abe5c:  40 02 6b 3d  call  0xa0146b50
a00abe60:  92 10 20 00  clr  %o1
a00abe64:  d4 0c 20 13  ldub  [ %l0 + 0x13 ], %o2
a00abe68:  90 10 20 29  mov  0x29, %o0
a00abe6c:  40 00 2c 17  call  0xa00b6ec8
a00abe70:  92 10 20 08  mov  8, %o1
a00abe74:  40 00 a1 ee  call  0xa00d462c
a00abe78:  01 00 00 00  nop
a00abe7c:  13 2a 00 ac  sethi  %hi(0xa802b000), %o1
a00abe80:  d8 0a 60 8e  ldub  [ %o1 + 0x8e ], %o4	! 0xa802b08e
a00abe84:  96 13 20 02  or  %o4, 2, %o3
a00abe88:  d6 2a 60 8e  stb  %o3, [ %o1 + 0x8e ]
a00abe8c:  81 c7 e0 08  ret
a00abe90:  81 e8 00 00  restore
