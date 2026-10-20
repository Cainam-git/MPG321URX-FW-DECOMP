# leon2s FUN_a00caf78 0xa00caf78-0xa00cb1d4 (604 bytes)
a00caf78:  9d e3 bf 98  save  %sp, -104, %sp
a00caf7c:  a2 0e 20 ff  and  %i0, 0xff, %l1
a00caf80:  82 04 40 11  add  %l1, %l1, %g1
a00caf84:  82 00 40 11  add  %g1, %l1, %g1
a00caf88:  2b 2a 01 e2  sethi  %hi(0xa8078800), %l5
a00caf8c:  83 28 60 03  sll  %g1, 3, %g1
a00caf90:  9a 15 63 b0  or  %l5, 0x3b0, %o5
a00caf94:  c2 13 40 01  lduh  [ %o5 + %g1 ], %g1
a00caf98:  82 08 60 03  and  %g1, 3, %g1
a00caf9c:  80 a0 60 01  cmp  %g1, 1
a00cafa0:  a8 10 20 01  mov  1, %l4
a00cafa4:  12 80 00 0b  bne  0xa00cafd0
a00cafa8:  a6 10 20 32  mov  0x32, %l3
a00cafac:  7f ff fd ca  call  0xa00ca6d4
a00cafb0:  90 10 00 11  mov  %l1, %o0
a00cafb4:  10 80 00 07  b  0xa00cafd0
a00cafb8:  a8 10 00 08  mov  %o0, %l4
a00cafbc:  40 3b d9 f6  call  0xa0fc1794
a00cafc0:  01 00 00 00  nop
a00cafc4:  80 8c e0 ff  btst  0xff, %l3
a00cafc8:  22 80 00 1f  be,a   0xa00cb044
a00cafcc:  c2 04 80 10  ld  [ %l2 + %l0 ], %g1
a00cafd0:  82 04 40 11  add  %l1, %l1, %g1
a00cafd4:  9a 0d 20 ff  and  %l4, 0xff, %o5
a00cafd8:  82 00 40 11  add  %g1, %l1, %g1
a00cafdc:  80 a0 00 0d  cmp  %g0, %o5
a00cafe0:  a1 28 60 03  sll  %g1, 3, %l0
a00cafe4:  82 0c e0 ff  and  %l3, 0xff, %g1
a00cafe8:  9a 40 20 00  addx  %g0, 0, %o5
a00cafec:  80 a0 00 01  cmp  %g0, %g1
a00caff0:  82 40 20 00  addx  %g0, 0, %g1
a00caff4:  a4 15 63 b0  or  %l5, 0x3b0, %l2
a00caff8:  90 10 20 0a  mov  0xa, %o0
a00caffc:  80 8b 40 01  btst  %o5, %g1
a00cb000:  02 80 00 07  be  0xa00cb01c
a00cb004:  a6 04 ff ff  add  %l3, -1, %l3
a00cb008:  c2 14 80 10  lduh  [ %l2 + %l0 ], %g1
a00cb00c:  82 08 60 03  and  %g1, 3, %g1
a00cb010:  80 a0 60 01  cmp  %g1, 1
a00cb014:  02 bf ff ea  be  0xa00cafbc
a00cb018:  01 00 00 00  nop
a00cb01c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00cb020:  21 2a 01 f4  sethi  %hi(0xa807d000), %l0
a00cb024:  90 10 00 18  mov  %i0, %o0
a00cb028:  7f ff f9 dc  call  0xa00c9798
a00cb02c:  92 14 22 50  or  %l0, 0x250, %o1
a00cb030:  80 8a 20 ff  btst  0xff, %o0
a00cb034:  02 80 00 08  be  0xa00cb054
a00cb038:  82 14 22 50  or  %l0, 0x250, %g1
a00cb03c:  10 80 00 2b  b  0xa00cb0e8
a00cb040:  9a 06 00 18  add  %i0, %i0, %o5
a00cb044:  1b 00 00 c0  sethi  %hi(0x30000), %o5
a00cb048:  82 10 40 0d  or  %g1, %o5, %g1
a00cb04c:  10 bf ff f4  b  0xa00cb01c
a00cb050:  c2 24 80 10  st  %g1, [ %l2 + %l0 ]
a00cb054:  d8 08 60 01  ldub  [ %g1 + 1 ], %o4
a00cb058:  82 0b 20 03  and  %o4, 3, %g1
a00cb05c:  83 28 60 08  sll  %g1, 8, %g1
a00cb060:  da 0c 22 50  ldub  [ %l0 + 0x250 ], %o5
a00cb064:  80 8b 20 0c  btst  0xc, %o4
a00cb068:  12 80 00 1f  bne  0xa00cb0e4
a00cb06c:  82 00 40 0d  add  %g1, %o5, %g1
a00cb070:  83 28 60 10  sll  %g1, 0x10, %g1
a00cb074:  80 a0 60 00  cmp  %g1, 0
a00cb078:  12 80 00 0b  bne  0xa00cb0a4
a00cb07c:  98 06 00 18  add  %i0, %i0, %o4
a00cb080:  98 03 00 18  add  %o4, %i0, %o4
a00cb084:  17 2a 01 e2  sethi  %hi(0xa8078800), %o3
a00cb088:  96 12 e3 b0  or  %o3, 0x3b0, %o3	! 0xa8078bb0
a00cb08c:  99 2b 20 03  sll  %o4, 3, %o4
a00cb090:  c2 02 c0 0c  ld  [ %o3 + %o4 ], %g1
a00cb094:  1b 00 00 c0  sethi  %hi(0x30000), %o5
a00cb098:  82 10 40 0d  or  %g1, %o5, %g1
a00cb09c:  10 80 00 4c  b  0xa00cb1cc
a00cb0a0:  c2 22 c0 0c  st  %g1, [ %o3 + %o4 ]
a00cb0a4:  90 10 00 18  mov  %i0, %o0
a00cb0a8:  92 10 20 74  mov  0x74, %o1
a00cb0ac:  94 10 20 80  mov  0x80, %o2
a00cb0b0:  7f ff f3 e6  call  0xa00c8048
a00cb0b4:  96 10 20 21  mov  0x21, %o3
a00cb0b8:  80 8a 20 ff  btst  0xff, %o0
a00cb0bc:  12 80 00 0b  bne  0xa00cb0e8
a00cb0c0:  9a 06 00 18  add  %i0, %i0, %o5
a00cb0c4:  21 2a 01 f3  sethi  %hi(0xa807cc00), %l0
a00cb0c8:  90 10 00 18  mov  %i0, %o0
a00cb0cc:  92 14 22 50  or  %l0, 0x250, %o1
a00cb0d0:  7f ff f4 4a  call  0xa00c81f8
a00cb0d4:  94 10 20 21  mov  0x21, %o2
a00cb0d8:  80 8a 20 ff  btst  0xff, %o0
a00cb0dc:  02 80 00 17  be  0xa00cb138
a00cb0e0:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00cb0e4:  9a 06 00 18  add  %i0, %i0, %o5
a00cb0e8:  9a 03 40 18  add  %o5, %i0, %o5
a00cb0ec:  19 2a 01 e2  sethi  %hi(0xa8078800), %o4
a00cb0f0:  98 13 23 b0  or  %o4, 0x3b0, %o4	! 0xa8078bb0
a00cb0f4:  9b 2b 60 03  sll  %o5, 3, %o5
a00cb0f8:  d6 03 00 0d  ld  [ %o4 + %o5 ], %o3
a00cb0fc:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00cb100:  82 2a c0 01  andn  %o3, %g1, %g1
a00cb104:  10 80 00 32  b  0xa00cb1cc
a00cb108:  c2 23 00 0d  st  %g1, [ %o4 + %o5 ]
a00cb10c:  9a 06 00 18  add  %i0, %i0, %o5
a00cb110:  9a 03 40 18  add  %o5, %i0, %o5
a00cb114:  96 12 23 b0  or  %o0, 0x3b0, %o3
a00cb118:  9b 2b 60 03  sll  %o5, 3, %o5
a00cb11c:  d8 02 c0 0d  ld  [ %o3 + %o5 ], %o4
a00cb120:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00cb124:  82 2b 00 01  andn  %o4, %g1, %g1
a00cb128:  c2 22 c0 0d  st  %g1, [ %o3 + %o5 ]
a00cb12c:  7f ff f2 27  call  0xa00c79c8
a00cb130:  90 10 00 18  mov  %i0, %o0
a00cb134:  30 80 00 26  b,a   0xa00cb1cc
a00cb138:  94 10 61 88  or  %g1, 0x188, %o2
a00cb13c:  92 14 22 50  or  %l0, 0x250, %o1
a00cb140:  96 10 20 00  clr  %o3
a00cb144:  98 0a e0 ff  and  %o3, 0xff, %o4
a00cb148:  82 03 00 09  add  %o4, %o1, %g1
a00cb14c:  96 02 e0 01  inc  %o3
a00cb150:  c2 08 60 01  ldub  [ %g1 + 1 ], %g1
a00cb154:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00cb158:  80 a3 60 1f  cmp  %o5, 0x1f
a00cb15c:  08 bf ff fa  bleu  0xa00cb144
a00cb160:  c2 2a 80 0c  stb  %g1, [ %o2 + %o4 ]
a00cb164:  98 06 00 18  add  %i0, %i0, %o4
a00cb168:  98 03 00 18  add  %o4, %i0, %o4
a00cb16c:  11 2a 01 e2  sethi  %hi(0xa8078800), %o0
a00cb170:  96 12 23 b0  or  %o0, 0x3b0, %o3	! 0xa8078bb0
a00cb174:  99 2b 20 03  sll  %o4, 3, %o4
a00cb178:  da 02 c0 0c  ld  [ %o3 + %o4 ], %o5
a00cb17c:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00cb180:  82 2b 40 01  andn  %o5, %g1, %g1
a00cb184:  1b 00 00 40  sethi  %hi(0x10000), %o5
a00cb188:  82 10 40 0d  or  %g1, %o5, %g1
a00cb18c:  c2 22 c0 0c  st  %g1, [ %o3 + %o4 ]
a00cb190:  03 2a 01 f4  sethi  %hi(0xa807d000), %g1
a00cb194:  92 10 60 88  or  %g1, 0x88, %o1	! 0xa807d088
a00cb198:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00cb19c:  94 10 61 88  or  %g1, 0x188, %o2	! 0xa807cd88
a00cb1a0:  96 10 20 00  clr  %o3
a00cb1a4:  82 0a e0 ff  and  %o3, 0xff, %g1
a00cb1a8:  da 0a 80 01  ldub  [ %o2 + %g1 ], %o5
a00cb1ac:  96 02 e0 01  inc  %o3
a00cb1b0:  c2 0a 40 01  ldub  [ %o1 + %g1 ], %g1
a00cb1b4:  80 a0 40 0d  cmp  %g1, %o5
a00cb1b8:  12 bf ff d5  bne  0xa00cb10c
a00cb1bc:  98 0a e0 ff  and  %o3, 0xff, %o4
a00cb1c0:  80 a3 20 1f  cmp  %o4, 0x1f
a00cb1c4:  08 bf ff f9  bleu  0xa00cb1a8
a00cb1c8:  82 0a e0 ff  and  %o3, 0xff, %g1
a00cb1cc:  81 c7 e0 08  ret
a00cb1d0:  81 e8 00 00  restore
