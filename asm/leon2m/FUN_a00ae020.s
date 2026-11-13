# leon2m FUN_a00ae020 0xa00ae020-0xa00ae174 (340 bytes)
a00ae020:  9d e3 bf 90  save  %sp, -112, %sp
a00ae024:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00ae028:  94 14 62 90  or  %l1, 0x290, %o2	! 0xa802d290
a00ae02c:  d2 0a a1 5b  ldub  [ %o2 + 0x15b ], %o1
a00ae030:  90 0a 60 03  and  %o1, 3, %o0
a00ae034:  82 02 00 08  add  %o0, %o0, %g1
a00ae038:  a0 00 60 04  add  %g1, 4, %l0
a00ae03c:  90 10 20 00  clr  %o0
a00ae040:  92 10 20 00  clr  %o1
a00ae044:  94 10 20 00  clr  %o2
a00ae048:  40 00 17 a2  call  0xa00b3ed0
a00ae04c:  96 10 20 00  clr  %o3
a00ae050:  a0 0c 20 ff  and  %l0, 0xff, %l0
a00ae054:  90 10 20 00  clr  %o0
a00ae058:  92 10 20 00  clr  %o1
a00ae05c:  94 10 27 92  mov  0x792, %o2
a00ae060:  96 10 20 03  mov  3, %o3
a00ae064:  98 10 20 0a  mov  0xa, %o4
a00ae068:  80 a4 20 0a  cmp  %l0, 0xa
a00ae06c:  02 80 00 29  be  0xa00ae110
a00ae070:  9a 10 20 02  mov  2, %o5
a00ae074:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00ae078:  90 10 20 00  clr  %o0
a00ae07c:  92 10 20 00  clr  %o1
a00ae080:  94 10 27 92  mov  0x792, %o2
a00ae084:  96 10 20 03  mov  3, %o3
a00ae088:  98 10 00 10  mov  %l0, %o4
a00ae08c:  9a 10 20 03  mov  3, %o5
a00ae090:  40 00 14 95  call  0xa00b32e4
a00ae094:  01 00 00 00  nop
a00ae098:  98 10 00 10  mov  %l0, %o4
a00ae09c:  94 10 27 92  mov  0x792, %o2
a00ae0a0:  96 10 20 12  mov  0x12, %o3
a00ae0a4:  9a 10 20 03  mov  3, %o5
a00ae0a8:  90 10 20 00  clr  %o0
a00ae0ac:  92 10 20 00  clr  %o1
a00ae0b0:  40 00 14 8d  call  0xa00b32e4
a00ae0b4:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00ae0b8:  a0 14 62 90  or  %l1, 0x290, %l0
a00ae0bc:  e2 0c 21 5b  ldub  [ %l0 + 0x15b ], %l1
a00ae0c0:  1f 19 99 99  sethi  %hi(0x66666400), %o7
a00ae0c4:  90 04 60 04  add  %l1, 4, %o0
a00ae0c8:  9a 13 e2 67  or  %o7, 0x267, %o5
a00ae0cc:  80 5a 00 0d  smul  %o0, %o5, %g0
a00ae0d0:  99 40 00 00  rd  %y, %o4
a00ae0d4:  97 3b 20 01  sra  %o4, 1, %o3
a00ae0d8:  95 2a e0 02  sll  %o3, 2, %o2
a00ae0dc:  92 02 80 0b  add  %o2, %o3, %o1
a00ae0e0:  9e 22 00 09  sub  %o0, %o1, %o7
a00ae0e4:  82 03 ff fd  add  %o7, -3, %g1
a00ae0e8:  a2 08 60 ff  and  %g1, 0xff, %l1
a00ae0ec:  9a 0b e0 ff  and  %o7, 0xff, %o5
a00ae0f0:  80 a4 60 01  cmp  %l1, 1
a00ae0f4:  de 2c 21 5b  stb  %o7, [ %l0 + 0x15b ]
a00ae0f8:  18 80 00 12  bgu  0xa00ae140
a00ae0fc:  91 33 60 02  srl  %o5, 2, %o0
a00ae100:  7f ff fe 1c  call  0xa00ad970
a00ae104:  01 00 00 00  nop
a00ae108:  10 80 00 0f  b  0xa00ae144
a00ae10c:  d2 0c 21 5b  ldub  [ %l0 + 0x15b ], %o1
a00ae110:  40 00 14 75  call  0xa00b32e4
a00ae114:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00ae118:  98 10 20 11  mov  0x11, %o4
a00ae11c:  17 00 00 0c  sethi  %hi(0x3000), %o3
a00ae120:  d8 23 a0 5c  st  %o4, [ %sp + 0x5c ]
a00ae124:  94 12 e0 92  or  %o3, 0x92, %o2
a00ae128:  90 10 20 01  mov  1, %o0
a00ae12c:  92 10 20 00  clr  %o1
a00ae130:  96 10 20 03  mov  3, %o3
a00ae134:  98 10 20 0c  mov  0xc, %o4
a00ae138:  10 bf ff d6  b  0xa00ae090
a00ae13c:  9a 10 20 01  mov  1, %o5
a00ae140:  d2 0c 21 5b  ldub  [ %l0 + 0x15b ], %o1
a00ae144:  90 0a 60 03  and  %o1, 3, %o0
a00ae148:  7f ff fd c9  call  0xa00ad86c
a00ae14c:  92 10 20 01  mov  1, %o1
a00ae150:  40 00 ab f4  call  0xa00d9120
a00ae154:  21 2a 00 ac  sethi  %hi(0xa802b000), %l0
a00ae158:  40 00 9a 10  call  0xa00d4998
a00ae15c:  01 00 00 00  nop
a00ae160:  d0 0c 20 8e  ldub  [ %l0 + 0x8e ], %o0
a00ae164:  82 12 20 02  or  %o0, 2, %g1
a00ae168:  c2 2c 20 8e  stb  %g1, [ %l0 + 0x8e ]
a00ae16c:  81 c7 e0 08  ret
a00ae170:  81 e8 00 00  restore
