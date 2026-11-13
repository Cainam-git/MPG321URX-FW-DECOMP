# leon2s FUN_a00dc0a8 0xa00dc0a8-0xa00dc214 (364 bytes)
a00dc0a8:  9d e3 bf 98  save  %sp, -104, %sp
a00dc0ac:  21 2a 01 e2  sethi  %hi(0xa8078800), %l0
a00dc0b0:  11 27 c7 33  sethi  %hi(0x9f1ccc00), %o0
a00dc0b4:  90 12 20 30  or  %o0, 0x30, %o0	! 0x9f1ccc30
a00dc0b8:  40 3a 9b e3  call  0xa0f83044
a00dc0bc:  d2 0c 20 32  ldub  [ %l0 + 0x32 ], %o1
a00dc0c0:  23 2a 01 e2  sethi  %hi(0xa8078800), %l1
a00dc0c4:  c2 0c 60 40  ldub  [ %l1 + 0x40 ], %g1	! 0xa8078840
a00dc0c8:  80 a0 60 01  cmp  %g1, 1
a00dc0cc:  32 80 00 50  bne,a   0xa00dc20c
a00dc0d0:  c0 2c 60 40  clrb  [ %l1 + 0x40 ]
a00dc0d4:  da 0c 20 32  ldub  [ %l0 + 0x32 ], %o5
a00dc0d8:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00dc0dc:  98 03 40 0d  add  %o5, %o5, %o4
a00dc0e0:  82 10 60 0a  or  %g1, 0xa, %g1
a00dc0e4:  c0 30 40 0c  clrh  [ %g1 + %o4 ]
a00dc0e8:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00dc0ec:  82 10 60 00  mov  %g1, %g1	! 0xa8078800
a00dc0f0:  c0 28 40 0d  clrb  [ %g1 + %o5 ]
a00dc0f4:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00dc0f8:  82 10 60 30  or  %g1, 0x30, %g1	! 0xa8078830
a00dc0fc:  c0 28 40 0d  clrb  [ %g1 + %o5 ]
a00dc100:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00dc104:  82 10 60 28  or  %g1, 0x28, %g1	! 0xa8078828
a00dc108:  c0 28 40 0d  clrb  [ %g1 + %o5 ]
a00dc10c:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00dc110:  82 10 60 0e  or  %g1, 0xe, %g1	! 0xa807880e
a00dc114:  c0 30 40 0c  clrh  [ %g1 + %o4 ]
a00dc118:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00dc11c:  82 10 60 08  or  %g1, 8, %g1	! 0xa8078808
a00dc120:  c0 28 40 0d  clrb  [ %g1 + %o5 ]
a00dc124:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00dc128:  c0 28 63 ff  clrb  [ %g1 + 0x3ff ]	! 0xa80787ff
a00dc12c:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00dc130:  c0 28 63 fe  clrb  [ %g1 + 0x3fe ]	! 0xa80787fe
a00dc134:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00dc138:  c0 28 63 fd  clrb  [ %g1 + 0x3fd ]	! 0xa80787fd
a00dc13c:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00dc140:  c0 28 63 fc  clrb  [ %g1 + 0x3fc ]	! 0xa80787fc
a00dc144:  03 2a 01 e7  sethi  %hi(0xa8079c00), %g1
a00dc148:  96 10 60 3d  or  %g1, 0x3d, %o3	! 0xa8079c3d
a00dc14c:  98 10 20 00  clr  %o4
a00dc150:  82 0b 20 ff  and  %o4, 0xff, %g1
a00dc154:  82 00 40 01  add  %g1, %g1, %g1
a00dc158:  c0 2a c0 01  clrb  [ %o3 + %g1 ]
a00dc15c:  98 03 20 01  inc  %o4
a00dc160:  82 00 40 0b  add  %g1, %o3, %g1
a00dc164:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00dc168:  80 a3 60 03  cmp  %o5, 3
a00dc16c:  08 bf ff f9  bleu  0xa00dc150
a00dc170:  c0 28 60 01  clrb  [ %g1 + 1 ]
a00dc174:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00dc178:  da 0c 20 32  ldub  [ %l0 + 0x32 ], %o5
a00dc17c:  82 10 60 50  or  %g1, 0x50, %g1
a00dc180:  c0 28 40 0d  clrb  [ %g1 + %o5 ]
a00dc184:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00dc188:  82 10 60 48  or  %g1, 0x48, %g1	! 0xa8078848
a00dc18c:  c0 28 40 0d  clrb  [ %g1 + %o5 ]
a00dc190:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a00dc194:  99 2b 60 02  sll  %o5, 2, %o4
a00dc198:  82 10 60 a4  or  %g1, 0xa4, %g1
a00dc19c:  da 00 40 0c  ld  [ %g1 + %o4 ], %o5
a00dc1a0:  c2 03 6c cc  ld  [ %o5 + 0xccc ], %g1
a00dc1a4:  82 08 7f cf  and  %g1, -49, %g1
a00dc1a8:  c2 23 6c cc  st  %g1, [ %o5 + 0xccc ]
a00dc1ac:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a00dc1b0:  d8 0c 20 32  ldub  [ %l0 + 0x32 ], %o4
a00dc1b4:  9a 10 20 01  mov  1, %o5
a00dc1b8:  82 10 60 b0  or  %g1, 0xb0, %g1
a00dc1bc:  da 28 40 0c  stb  %o5, [ %g1 + %o4 ]
a00dc1c0:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00dc1c4:  c0 30 63 fa  clrh  [ %g1 + 0x3fa ]	! 0xa80787fa
a00dc1c8:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00dc1cc:  c0 30 63 f8  clrh  [ %g1 + 0x3f8 ]	! 0xa80787f8
a00dc1d0:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00dc1d4:  82 10 60 38  or  %g1, 0x38, %g1	! 0xa8078838
a00dc1d8:  c0 28 40 0c  clrb  [ %g1 + %o4 ]
a00dc1dc:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00dc1e0:  40 3a e9 31  call  0xa0f966a4
a00dc1e4:  c0 28 60 47  clrb  [ %g1 + 0x47 ]	! 0xa8078847
a00dc1e8:  80 8a 20 ff  btst  0xff, %o0
a00dc1ec:  02 80 00 05  be  0xa00dc200
a00dc1f0:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00dc1f4:  7f ff f6 21  call  0xa00d9a78
a00dc1f8:  01 00 00 00  nop
a00dc1fc:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00dc200:  7f ff e8 d8  call  0xa00d6560
a00dc204:  d0 08 60 32  ldub  [ %g1 + 0x32 ], %o0	! 0xa8078832
a00dc208:  c0 2c 60 40  clrb  [ %l1 + 0x40 ]
a00dc20c:  81 c7 e0 08  ret
a00dc210:  81 e8 00 00  restore
