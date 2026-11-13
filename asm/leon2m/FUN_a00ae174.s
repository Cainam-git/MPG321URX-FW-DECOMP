# leon2m FUN_a00ae174 0xa00ae174-0xa00ae288 (276 bytes)
a00ae174:  9d e3 bf 90  save  %sp, -112, %sp
a00ae178:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00ae17c:  92 14 62 90  or  %l1, 0x290, %o1	! 0xa802d290
a00ae180:  d0 0a 61 a3  ldub  [ %o1 + 0x1a3 ], %o0
a00ae184:  82 02 00 08  add  %o0, %o0, %g1
a00ae188:  a0 00 60 04  add  %g1, 4, %l0
a00ae18c:  90 10 20 00  clr  %o0
a00ae190:  92 10 20 00  clr  %o1
a00ae194:  94 10 20 00  clr  %o2
a00ae198:  40 00 17 4e  call  0xa00b3ed0
a00ae19c:  96 10 20 00  clr  %o3
a00ae1a0:  a0 0c 20 ff  and  %l0, 0xff, %l0
a00ae1a4:  90 10 20 00  clr  %o0
a00ae1a8:  92 10 20 00  clr  %o1
a00ae1ac:  94 10 27 92  mov  0x792, %o2
a00ae1b0:  96 10 20 03  mov  3, %o3
a00ae1b4:  98 10 20 0a  mov  0xa, %o4
a00ae1b8:  80 a4 20 0a  cmp  %l0, 0xa
a00ae1bc:  02 80 00 0a  be  0xa00ae1e4
a00ae1c0:  9a 10 20 02  mov  2, %o5
a00ae1c4:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00ae1c8:  90 10 20 00  clr  %o0
a00ae1cc:  92 10 20 00  clr  %o1
a00ae1d0:  94 10 27 92  mov  0x792, %o2
a00ae1d4:  96 10 20 03  mov  3, %o3
a00ae1d8:  98 10 00 10  mov  %l0, %o4
a00ae1dc:  10 80 00 0d  b  0xa00ae210
a00ae1e0:  9a 10 20 03  mov  3, %o5
a00ae1e4:  40 00 14 40  call  0xa00b32e4
a00ae1e8:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00ae1ec:  96 10 20 11  mov  0x11, %o3
a00ae1f0:  d6 23 a0 5c  st  %o3, [ %sp + 0x5c ]
a00ae1f4:  15 00 00 0c  sethi  %hi(0x3000), %o2
a00ae1f8:  94 12 a0 92  or  %o2, 0x92, %o2	! 0x3092
a00ae1fc:  90 10 20 01  mov  1, %o0
a00ae200:  92 10 20 00  clr  %o1
a00ae204:  96 10 20 03  mov  3, %o3
a00ae208:  98 10 20 0c  mov  0xc, %o4
a00ae20c:  9a 10 20 01  mov  1, %o5
a00ae210:  40 00 14 35  call  0xa00b32e4
a00ae214:  01 00 00 00  nop
a00ae218:  98 10 00 10  mov  %l0, %o4
a00ae21c:  90 10 20 00  clr  %o0
a00ae220:  92 10 20 00  clr  %o1
a00ae224:  94 10 27 92  mov  0x792, %o2
a00ae228:  96 10 20 12  mov  0x12, %o3
a00ae22c:  9a 10 20 03  mov  3, %o5
a00ae230:  40 00 14 2d  call  0xa00b32e4
a00ae234:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00ae238:  a0 14 62 90  or  %l1, 0x290, %l0
a00ae23c:  d8 0c 21 a3  ldub  [ %l0 + 0x1a3 ], %o4
a00ae240:  1b 15 55 55  sethi  %hi(0x55555400), %o5
a00ae244:  90 03 20 01  add  %o4, 1, %o0
a00ae248:  96 13 61 56  or  %o5, 0x156, %o3
a00ae24c:  80 5a 00 0b  smul  %o0, %o3, %g0
a00ae250:  95 40 00 00  rd  %y, %o2
a00ae254:  92 02 80 0a  add  %o2, %o2, %o1
a00ae258:  82 02 40 0a  add  %o1, %o2, %g1
a00ae25c:  a2 22 00 01  sub  %o0, %g1, %l1
a00ae260:  e2 2c 21 a3  stb  %l1, [ %l0 + 0x1a3 ]
a00ae264:  90 0c 60 ff  and  %l1, 0xff, %o0
a00ae268:  7f ff fd 81  call  0xa00ad86c
a00ae26c:  92 10 20 01  mov  1, %o1
a00ae270:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00ae274:  de 0b 60 8e  ldub  [ %o5 + 0x8e ], %o7	! 0xa802b08e
a00ae278:  98 13 e0 02  or  %o7, 2, %o4
a00ae27c:  d8 2b 60 8e  stb  %o4, [ %o5 + 0x8e ]
a00ae280:  81 c7 e0 08  ret
a00ae284:  81 e8 00 00  restore
