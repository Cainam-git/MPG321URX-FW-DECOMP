# leon2m FUN_a00aaf48 0xa00aaf48-0xa00ab080 (312 bytes)
a00aaf48:  9d e3 bf 98  save  %sp, -104, %sp
a00aaf4c:  90 10 21 11  mov  0x111, %o0
a00aaf50:  40 02 6f 00  call  0xa0146b50
a00aaf54:  92 10 20 00  clr  %o1
a00aaf58:  90 10 20 00  clr  %o0
a00aaf5c:  40 02 6f 04  call  0xa0146b6c
a00aaf60:  92 10 20 00  clr  %o1
a00aaf64:  2b 2a 00 ac  sethi  %hi(0xa802b000), %l5
a00aaf68:  ec 0d 60 8f  ldub  [ %l5 + 0x8f ], %l6	! 0xa802b08f
a00aaf6c:  82 10 20 0e  mov  0xe, %g1
a00aaf70:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00aaf74:  c2 2d 60 8f  stb  %g1, [ %l5 + 0x8f ]
a00aaf78:  a8 13 62 90  or  %o5, 0x290, %l4
a00aaf7c:  a4 10 20 00  clr  %l2
a00aaf80:  a0 10 20 00  clr  %l0
a00aaf84:  10 80 00 19  b  0xa00aafe8
a00aaf88:  27 00 06 44  sethi  %hi(0x191000), %l3
a00aaf8c:  95 2c 20 03  sll  %l0, 3, %o2
a00aaf90:  82 22 80 10  sub  %o2, %l0, %g1
a00aaf94:  9b 28 60 02  sll  %g1, 2, %o5
a00aaf98:  98 03 40 10  add  %o5, %l0, %o4
a00aaf9c:  de 0d 20 08  ldub  [ %l4 + 8 ], %o7
a00aafa0:  96 03 00 0f  add  %o4, %o7, %o3
a00aafa4:  93 2a e0 10  sll  %o3, 0x10, %o1
a00aafa8:  93 32 60 10  srl  %o1, 0x10, %o1
a00aafac:  7f ff e2 26  call  0xa00a3844
a00aafb0:  90 14 e0 b0  or  %l3, 0xb0, %o0
a00aafb4:  98 10 00 08  mov  %o0, %o4
a00aafb8:  90 04 60 06  add  %l1, 6, %o0
a00aafbc:  95 2a 20 10  sll  %o0, 0x10, %o2
a00aafc0:  95 32 a0 10  srl  %o2, 0x10, %o2
a00aafc4:  90 10 20 00  clr  %o0
a00aafc8:  92 10 20 2a  mov  0x2a, %o1
a00aafcc:  96 10 20 01  mov  1, %o3
a00aafd0:  7f ff e0 75  call  0xa00a31a4
a00aafd4:  9a 10 20 00  clr  %o5
a00aafd8:  a0 0c a0 ff  and  %l2, 0xff, %l0
a00aafdc:  80 a4 20 07  cmp  %l0, 7
a00aafe0:  3a 80 00 10  bcc,a   0xa00ab020
a00aafe4:  da 0d 21 a4  ldub  [ %l4 + 0x1a4 ], %o5
a00aafe8:  7f ff ff 52  call  0xa00aad30
a00aafec:  90 10 00 10  mov  %l0, %o0
a00aaff0:  80 8a 20 ff  btst  0xff, %o0
a00aaff4:  a4 04 a0 01  inc  %l2
a00aaff8:  a2 04 00 10  add  %l0, %l0, %l1
a00aaffc:  94 10 20 0a  mov  0xa, %o2
a00ab000:  96 10 22 96  mov  0x296, %o3
a00ab004:  98 10 20 00  clr  %o4
a00ab008:  12 bf ff e1  bne  0xa00aaf8c
a00ab00c:  90 10 20 2a  mov  0x2a, %o0
a00ab010:  40 02 6e 9c  call  0xa0146a80
a00ab014:  92 04 60 06  add  %l1, 6, %o1
a00ab018:  10 bf ff de  b  0xa00aaf90
a00ab01c:  95 2c 20 03  sll  %l0, 3, %o2
a00ab020:  a0 03 40 0d  add  %o5, %o5, %l0
a00ab024:  80 a3 60 06  cmp  %o5, 6
a00ab028:  08 80 00 04  bleu  0xa00ab038
a00ab02c:  82 04 20 06  add  %l0, 6, %g1
a00ab030:  a2 03 40 0d  add  %o5, %o5, %l1
a00ab034:  82 04 7f f8  add  %l1, -8, %g1
a00ab038:  a4 08 60 ff  and  %g1, 0xff, %l2
a00ab03c:  90 10 20 00  clr  %o0
a00ab040:  92 10 20 28  mov  0x28, %o1
a00ab044:  94 10 00 12  mov  %l2, %o2
a00ab048:  96 10 20 01  mov  1, %o3
a00ab04c:  98 10 20 0f  mov  0xf, %o4
a00ab050:  40 02 6e b4  call  0xa0146b20
a00ab054:  9a 10 20 00  clr  %o5
a00ab058:  94 10 00 12  mov  %l2, %o2
a00ab05c:  90 10 20 00  clr  %o0
a00ab060:  92 10 20 29  mov  0x29, %o1
a00ab064:  96 10 20 01  mov  1, %o3
a00ab068:  98 10 20 10  mov  0x10, %o4
a00ab06c:  40 02 6e ad  call  0xa0146b20
a00ab070:  9a 10 20 00  clr  %o5
a00ab074:  ec 2d 60 8f  stb  %l6, [ %l5 + 0x8f ]
a00ab078:  81 c7 e0 08  ret
a00ab07c:  81 e8 00 00  restore
