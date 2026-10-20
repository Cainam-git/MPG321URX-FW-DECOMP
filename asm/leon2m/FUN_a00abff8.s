# leon2m FUN_a00abff8 0xa00abff8-0xa00ac0c4 (204 bytes)
a00abff8:  9d e3 bf 98  save  %sp, -104, %sp
a00abffc:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00ac000:  a0 12 a2 90  or  %o2, 0x290, %l0	! 0xa802d290
a00ac004:  da 0c 20 12  ldub  [ %l0 + 0x12 ], %o5
a00ac008:  9a 03 60 01  inc  %o5
a00ac00c:  82 0b 60 ff  and  %o5, 0xff, %g1
a00ac010:  90 10 20 2c  mov  0x2c, %o0
a00ac014:  92 10 20 06  mov  6, %o1
a00ac018:  96 10 20 07  mov  7, %o3
a00ac01c:  98 10 20 01  mov  1, %o4
a00ac020:  80 a0 60 64  cmp  %g1, 0x64
a00ac024:  08 80 00 05  bleu  0xa00ac038
a00ac028:  94 10 00 01  mov  %g1, %o2
a00ac02c:  90 10 20 64  mov  0x64, %o0
a00ac030:  10 80 00 1f  b  0xa00ac0ac
a00ac034:  d0 2c 20 12  stb  %o0, [ %l0 + 0x12 ]
a00ac038:  7f ff fd 6e  call  0xa00ab5f0
a00ac03c:  da 2c 20 12  stb  %o5, [ %l0 + 0x12 ]
a00ac040:  90 10 20 28  mov  0x28, %o0
a00ac044:  92 10 20 06  mov  6, %o1
a00ac048:  94 10 20 03  mov  3, %o2
a00ac04c:  96 10 27 42  mov  0x742, %o3
a00ac050:  40 02 6a 8c  call  0xa0146a80
a00ac054:  98 10 20 00  clr  %o4
a00ac058:  90 10 20 2b  mov  0x2b, %o0
a00ac05c:  92 10 20 06  mov  6, %o1
a00ac060:  94 10 20 01  mov  1, %o2
a00ac064:  96 10 27 42  mov  0x742, %o3
a00ac068:  40 02 6a 86  call  0xa0146a80
a00ac06c:  98 10 20 00  clr  %o4
a00ac070:  94 10 20 01  mov  1, %o2
a00ac074:  96 10 27 42  mov  0x742, %o3
a00ac078:  98 10 20 00  clr  %o4
a00ac07c:  90 10 20 32  mov  0x32, %o0
a00ac080:  40 02 6a 80  call  0xa0146a80
a00ac084:  92 10 20 06  mov  6, %o1
a00ac088:  90 10 20 e6  mov  0xe6, %o0
a00ac08c:  40 02 6a b1  call  0xa0146b50
a00ac090:  92 10 20 00  clr  %o1
a00ac094:  d4 0c 20 12  ldub  [ %l0 + 0x12 ], %o2
a00ac098:  90 10 20 29  mov  0x29, %o0
a00ac09c:  40 00 2b 8b  call  0xa00b6ec8
a00ac0a0:  92 10 20 06  mov  6, %o1
a00ac0a4:  40 00 a1 55  call  0xa00d45f8
a00ac0a8:  01 00 00 00  nop
a00ac0ac:  13 2a 00 ac  sethi  %hi(0xa802b000), %o1
a00ac0b0:  d8 0a 60 8e  ldub  [ %o1 + 0x8e ], %o4	! 0xa802b08e
a00ac0b4:  96 13 20 02  or  %o4, 2, %o3
a00ac0b8:  d6 2a 60 8e  stb  %o3, [ %o1 + 0x8e ]
a00ac0bc:  81 c7 e0 08  ret
a00ac0c0:  81 e8 00 00  restore
