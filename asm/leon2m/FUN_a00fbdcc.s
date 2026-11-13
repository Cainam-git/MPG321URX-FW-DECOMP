# leon2m FUN_a00fbdcc 0xa00fbdcc-0xa00fbf54 (392 bytes)
a00fbdcc:  9d e3 bf 80  save  %sp, -128, %sp
a00fbdd0:  80 a6 60 02  cmp  %i1, 2
a00fbdd4:  02 80 00 3a  be  0xa00fbebc
a00fbdd8:  90 10 20 00  clr  %o0
a00fbddc:  80 a6 60 02  cmp  %i1, 2
a00fbde0:  08 80 00 09  bleu  0xa00fbe04
a00fbde4:  80 a6 60 01  cmp  %i1, 1
a00fbde8:  80 a6 60 03  cmp  %i1, 3
a00fbdec:  02 80 00 4e  be  0xa00fbf24
a00fbdf0:  80 a6 60 04  cmp  %i1, 4
a00fbdf4:  32 80 00 56  bne,a   0xa00fbf4c
a00fbdf8:  b0 0a 20 ff  and  %o0, 0xff, %i0
a00fbdfc:  10 80 00 50  b  0xa00fbf3c
a00fbe00:  90 0e 20 ff  and  %i0, 0xff, %o0
a00fbe04:  12 80 00 52  bne  0xa00fbf4c
a00fbe08:  b0 0a 20 ff  and  %o0, 0xff, %i0
a00fbe0c:  9a 10 20 80  mov  0x80, %o5
a00fbe10:  82 10 21 00  mov  0x100, %g1
a00fbe14:  da 27 bf e4  st  %o5, [ %fp + -28 ]
a00fbe18:  c2 27 bf e0  st  %g1, [ %fp + -32 ]
a00fbe1c:  da 27 bf e8  st  %o5, [ %fp + -24 ]
a00fbe20:  f2 27 bf f0  st  %i1, [ %fp + -16 ]
a00fbe24:  c0 27 bf f4  clr  [ %fp + -12 ]
a00fbe28:  7f ff f6 f6  call  0xa00f9a00
a00fbe2c:  c0 27 bf ec  clr  [ %fp + -20 ]
a00fbe30:  21 2a 00 b5  sethi  %hi(0xa802d400), %l0
a00fbe34:  7f ff f7 62  call  0xa00f9bbc
a00fbe38:  23 2a 00 b5  sethi  %hi(0xa802d400), %l1
a00fbe3c:  92 07 bf f4  add  %fp, -12, %o1
a00fbe40:  d4 14 22 7a  lduh  [ %l0 + 0x27a ], %o2
a00fbe44:  d6 14 62 78  lduh  [ %l1 + 0x278 ], %o3
a00fbe48:  7f ff fd 7b  call  0xa00fb434
a00fbe4c:  90 10 20 0c  mov  0xc, %o0
a00fbe50:  92 07 bf f0  add  %fp, -16, %o1
a00fbe54:  d4 14 22 7a  lduh  [ %l0 + 0x27a ], %o2
a00fbe58:  d6 14 62 78  lduh  [ %l1 + 0x278 ], %o3
a00fbe5c:  7f ff fd 76  call  0xa00fb434
a00fbe60:  90 10 20 0d  mov  0xd, %o0
a00fbe64:  92 07 bf ec  add  %fp, -20, %o1
a00fbe68:  d4 14 22 7a  lduh  [ %l0 + 0x27a ], %o2
a00fbe6c:  d6 14 62 78  lduh  [ %l1 + 0x278 ], %o3
a00fbe70:  7f ff fd 71  call  0xa00fb434
a00fbe74:  90 10 20 0e  mov  0xe, %o0
a00fbe78:  92 07 bf e8  add  %fp, -24, %o1
a00fbe7c:  d4 14 22 7a  lduh  [ %l0 + 0x27a ], %o2
a00fbe80:  d6 14 62 78  lduh  [ %l1 + 0x278 ], %o3
a00fbe84:  7f ff fd 6c  call  0xa00fb434
a00fbe88:  90 10 20 0f  mov  0xf, %o0
a00fbe8c:  92 07 bf e4  add  %fp, -28, %o1
a00fbe90:  d4 14 22 7a  lduh  [ %l0 + 0x27a ], %o2
a00fbe94:  d6 14 62 78  lduh  [ %l1 + 0x278 ], %o3
a00fbe98:  7f ff fd 67  call  0xa00fb434
a00fbe9c:  90 10 20 10  mov  0x10, %o0
a00fbea0:  d4 14 22 7a  lduh  [ %l0 + 0x27a ], %o2
a00fbea4:  d6 14 62 78  lduh  [ %l1 + 0x278 ], %o3
a00fbea8:  90 10 20 11  mov  0x11, %o0
a00fbeac:  7f ff fd 62  call  0xa00fb434
a00fbeb0:  92 07 bf e0  add  %fp, -32, %o1
a00fbeb4:  10 80 00 25  b  0xa00fbf48
a00fbeb8:  90 10 20 01  mov  1, %o0
a00fbebc:  13 2a 00 ad  sethi  %hi(0xa802b400), %o1
a00fbec0:  d0 0a 63 ef  ldub  [ %o1 + 0x3ef ], %o0	! 0xa802b7ef
a00fbec4:  80 a2 20 00  cmp  %o0, 0
a00fbec8:  02 80 00 0c  be  0xa00fbef8
a00fbecc:  15 2a 00 ad  sethi  %hi(0xa802b400), %o2
a00fbed0:  17 34 01 00  sethi  %hi(0xd0040000), %o3
a00fbed4:  f0 02 c0 00  ld  [ %o3 ], %i0
a00fbed8:  33 20 00 00  sethi  %hi(0x80000000), %i1
a00fbedc:  9f 36 20 1f  srl  %i0, 0x1f, %o7
a00fbee0:  15 2a 00 ad  sethi  %hi(0xa802b400), %o2
a00fbee4:  98 2e 00 19  andn  %i0, %i1, %o4
a00fbee8:  de 2a a3 e8  stb  %o7, [ %o2 + 0x3e8 ]
a00fbeec:  d8 22 c0 00  st  %o4, [ %o3 ]
a00fbef0:  10 80 00 16  b  0xa00fbf48
a00fbef4:  90 10 20 01  mov  1, %o0
a00fbef8:  d8 0a a3 e8  ldub  [ %o2 + 0x3e8 ], %o4
a00fbefc:  23 34 01 00  sethi  %hi(0xd0040000), %l1
a00fbf00:  11 20 00 00  sethi  %hi(0x80000000), %o0
a00fbf04:  d2 04 40 00  ld  [ %l1 ], %o1
a00fbf08:  97 2b 20 1f  sll  %o4, 0x1f, %o3
a00fbf0c:  9a 0a c0 08  and  %o3, %o0, %o5
a00fbf10:  82 2a 40 08  andn  %o1, %o0, %g1
a00fbf14:  a0 10 40 0d  or  %g1, %o5, %l0
a00fbf18:  e0 24 40 00  st  %l0, [ %l1 ]
a00fbf1c:  10 80 00 0b  b  0xa00fbf48
a00fbf20:  90 10 20 01  mov  1, %o0
a00fbf24:  1f 2a 00 ad  sethi  %hi(0xa802b400), %o7
a00fbf28:  d2 13 e3 ec  lduh  [ %o7 + 0x3ec ], %o1	! 0xa802b7ec
a00fbf2c:  7f ff fe f3  call  0xa00fbaf8
a00fbf30:  90 0e 20 ff  and  %i0, 0xff, %o0
a00fbf34:  10 80 00 06  b  0xa00fbf4c
a00fbf38:  b0 0a 20 ff  and  %o0, 0xff, %i0
a00fbf3c:  31 2a 00 ad  sethi  %hi(0xa802b400), %i0
a00fbf40:  7f ff ff 50  call  0xa00fbc80
a00fbf44:  d2 0e 23 eb  ldub  [ %i0 + 0x3eb ], %o1	! 0xa802b7eb
a00fbf48:  b0 0a 20 ff  and  %o0, 0xff, %i0
a00fbf4c:  81 c7 e0 08  ret
a00fbf50:  81 e8 00 00  restore
