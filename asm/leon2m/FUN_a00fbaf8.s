# leon2m FUN_a00fbaf8 0xa00fbaf8-0xa00fbc80 (392 bytes)
a00fbaf8:  9d e3 bf 90  save  %sp, -112, %sp
a00fbafc:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00fbb00:  c0 27 bf f0  clr  [ %fp + -16 ]
a00fbb04:  80 a6 20 01  cmp  %i0, 1
a00fbb08:  18 80 00 03  bgu  0xa00fbb14
a00fbb0c:  9a 10 20 01  mov  1, %o5
a00fbb10:  9a 10 20 00  clr  %o5
a00fbb14:  80 a6 60 04  cmp  %i1, 4
a00fbb18:  18 80 00 03  bgu  0xa00fbb24
a00fbb1c:  82 10 20 01  mov  1, %g1
a00fbb20:  82 10 20 00  clr  %g1
a00fbb24:  80 93 40 01  orcc  %o5, %g1, %g0
a00fbb28:  02 80 00 05  be  0xa00fbb3c
a00fbb2c:  25 2a 00 ad  sethi  %hi(0xa802b400), %l2
a00fbb30:  c0 27 bf f4  clr  [ %fp + -12 ]
a00fbb34:  10 80 00 51  b  0xa00fbc78
a00fbb38:  b0 10 20 00  clr  %i0
a00fbb3c:  19 2a 00 9a  sethi  %hi(0xa8026800), %o4
a00fbb40:  f2 2c a3 fc  stb  %i1, [ %l2 + 0x3fc ]
a00fbb44:  80 a6 60 01  cmp  %i1, 1
a00fbb48:  9a 13 22 8a  or  %o4, 0x28a, %o5
a00fbb4c:  18 80 00 2e  bgu  0xa00fbc04
a00fbb50:  82 10 21 00  mov  0x100, %g1
a00fbb54:  c2 33 40 00  sth  %g1, [ %o5 ]
a00fbb58:  15 2a 00 ad  sethi  %hi(0xa802b400), %o2
a00fbb5c:  d2 12 a3 fa  lduh  [ %o2 + 0x3fa ], %o1	! 0xa802b7fa
a00fbb60:  d8 13 22 8a  lduh  [ %o4 + 0x28a ], %o4
a00fbb64:  90 5a 40 0c  smul  %o1, %o4, %o0
a00fbb68:  83 3a 20 08  sra  %o0, 8, %g1
a00fbb6c:  9a 10 23 e8  mov  0x3e8, %o5
a00fbb70:  80 a0 63 e8  cmp  %g1, 0x3e8
a00fbb74:  c2 27 bf f4  st  %g1, [ %fp + -12 ]
a00fbb78:  08 80 00 03  bleu  0xa00fbb84
a00fbb7c:  9a 23 40 01  sub  %o5, %g1, %o5
a00fbb80:  9a 10 20 00  clr  %o5
a00fbb84:  17 2a 00 9a  sethi  %hi(0xa8026800), %o3
a00fbb88:  da 32 e2 88  sth  %o5, [ %o3 + 0x288 ]	! 0xa8026a88
a00fbb8c:  23 2a 00 b5  sethi  %hi(0xa802d400), %l1
a00fbb90:  21 2a 00 b5  sethi  %hi(0xa802d400), %l0
a00fbb94:  da 27 bf f4  st  %o5, [ %fp + -12 ]
a00fbb98:  90 10 20 08  mov  8, %o0
a00fbb9c:  92 07 bf f4  add  %fp, -12, %o1
a00fbba0:  d4 14 62 7a  lduh  [ %l1 + 0x27a ], %o2
a00fbba4:  7f ff fe 24  call  0xa00fb434
a00fbba8:  d6 14 22 78  lduh  [ %l0 + 0x278 ], %o3
a00fbbac:  80 a6 60 04  cmp  %i1, 4
a00fbbb0:  02 80 00 17  be  0xa00fbc0c
a00fbbb4:  80 a6 20 00  cmp  %i0, 0
a00fbbb8:  d6 0c a3 fc  ldub  [ %l2 + 0x3fc ], %o3
a00fbbbc:  80 a0 00 0b  cmp  %g0, %o3
a00fbbc0:  19 34 01 00  sethi  %hi(0xd0040000), %o4
a00fbbc4:  a0 40 20 00  addx  %g0, 0, %l0
a00fbbc8:  c2 03 00 00  ld  [ %o4 ], %g1
a00fbbcc:  93 2c 20 1f  sll  %l0, 0x1f, %o1
a00fbbd0:  11 20 00 00  sethi  %hi(0x80000000), %o0
a00fbbd4:  9a 0a 40 08  and  %o1, %o0, %o5
a00fbbd8:  b2 28 40 08  andn  %g1, %o0, %i1
a00fbbdc:  b0 16 40 0d  or  %i1, %o5, %i0
a00fbbe0:  f0 23 00 00  st  %i0, [ %o4 ]
a00fbbe4:  a0 13 20 d8  or  %o4, 0xd8, %l0
a00fbbe8:  de 04 00 00  ld  [ %l0 ], %o7
a00fbbec:  a4 0b ff f0  and  %o7, -16, %l2
a00fbbf0:  94 0a e0 0f  and  %o3, 0xf, %o2
a00fbbf4:  a2 14 80 0a  or  %l2, %o2, %l1
a00fbbf8:  e2 24 00 00  st  %l1, [ %l0 ]
a00fbbfc:  10 80 00 1f  b  0xa00fbc78
a00fbc00:  b0 10 20 01  mov  1, %i0
a00fbc04:  10 bf ff d4  b  0xa00fbb54
a00fbc08:  82 10 20 80  mov  0x80, %g1
a00fbc0c:  12 bf ff ec  bne  0xa00fbbbc
a00fbc10:  d6 0c a3 fc  ldub  [ %l2 + 0x3fc ], %o3
a00fbc14:  1f 2a 00 9a  sethi  %hi(0xa8026800), %o7
a00fbc18:  da 13 e2 86  lduh  [ %o7 + 0x286 ], %o5	! 0xa8026a86
a00fbc1c:  80 a3 6b b7  cmp  %o5, 0xbb7
a00fbc20:  18 80 00 0d  bgu  0xa00fbc54
a00fbc24:  da 27 bf f4  st  %o5, [ %fp + -12 ]
a00fbc28:  80 a3 61 f3  cmp  %o5, 0x1f3
a00fbc2c:  18 80 00 0d  bgu  0xa00fbc60
a00fbc30:  13 3f ff e6  sethi  %hi(0xffff9800), %o1
a00fbc34:  c0 27 bf f0  clr  [ %fp + -16 ]
a00fbc38:  d4 14 62 7a  lduh  [ %l1 + 0x27a ], %o2
a00fbc3c:  d6 14 22 78  lduh  [ %l0 + 0x278 ], %o3
a00fbc40:  92 07 bf f0  add  %fp, -16, %o1
a00fbc44:  7f ff fd fc  call  0xa00fb434
a00fbc48:  90 10 20 0b  mov  0xb, %o0
a00fbc4c:  10 bf ff dc  b  0xa00fbbbc
a00fbc50:  d6 0c a3 fc  ldub  [ %l2 + 0x3fc ], %o3
a00fbc54:  b0 10 20 80  mov  0x80, %i0
a00fbc58:  10 bf ff f8  b  0xa00fbc38
a00fbc5c:  f0 27 bf f0  st  %i0, [ %fp + -16 ]
a00fbc60:  90 5b 60 34  smul  %o5, 0x34, %o0
a00fbc64:  82 12 62 70  or  %o1, 0x270, %g1
a00fbc68:  9a 02 00 01  add  %o0, %g1, %o5
a00fbc6c:  b3 33 60 0a  srl  %o5, 0xa, %i1
a00fbc70:  10 bf ff f2  b  0xa00fbc38
a00fbc74:  f2 27 bf f0  st  %i1, [ %fp + -16 ]
a00fbc78:  81 c7 e0 08  ret
a00fbc7c:  81 e8 00 00  restore
