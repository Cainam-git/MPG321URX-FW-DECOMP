# leon2s FUN_a00cbb50 0xa00cbb50-0xa00cc1d4 (1668 bytes)
a00cbb50:  9d e3 bf 98  save  %sp, -104, %sp
a00cbb54:  a4 0e 20 ff  and  %i0, 0xff, %l2
a00cbb58:  82 04 80 12  add  %l2, %l2, %g1
a00cbb5c:  82 00 40 12  add  %g1, %l2, %g1
a00cbb60:  a1 28 60 03  sll  %g1, 3, %l0
a00cbb64:  03 3f ff 3f  sethi  %hi(0xfffcfc00), %g1
a00cbb68:  2f 2a 01 e2  sethi  %hi(0xa8078800), %l7
a00cbb6c:  a2 15 e3 b0  or  %l7, 0x3b0, %l1	! 0xa8078bb0
a00cbb70:  aa 10 63 ff  or  %g1, 0x3ff, %l5
a00cbb74:  c2 04 40 10  ld  [ %l1 + %l0 ], %g1
a00cbb78:  1b 00 00 40  sethi  %hi(0x10000), %o5
a00cbb7c:  82 08 40 15  and  %g1, %l5, %g1
a00cbb80:  82 10 40 0d  or  %g1, %o5, %g1
a00cbb84:  c2 24 40 10  st  %g1, [ %l1 + %l0 ]
a00cbb88:  7f ff d3 9f  call  0xa00c0a04
a00cbb8c:  90 10 00 12  mov  %l2, %o0
a00cbb90:  80 8a 20 ff  btst  0xff, %o0
a00cbb94:  32 80 00 12  bne,a   0xa00cbbdc
a00cbb98:  c2 04 40 10  ld  [ %l1 + %l0 ], %g1
a00cbb9c:  2d 2a 01 f4  sethi  %hi(0xa807d000), %l6
a00cbba0:  90 10 00 12  mov  %l2, %o0
a00cbba4:  7f ff f6 fd  call  0xa00c9798
a00cbba8:  92 15 a2 50  or  %l6, 0x250, %o1
a00cbbac:  80 8a 20 ff  btst  0xff, %o0
a00cbbb0:  32 80 00 0b  bne,a   0xa00cbbdc
a00cbbb4:  c2 04 40 10  ld  [ %l1 + %l0 ], %g1
a00cbbb8:  82 15 a2 50  or  %l6, 0x250, %g1
a00cbbbc:  c2 08 60 01  ldub  [ %g1 + 1 ], %g1
a00cbbc0:  80 88 60 08  btst  8, %g1
a00cbbc4:  32 80 00 42  bne,a   0xa00cbccc
a00cbbc8:  c2 04 40 10  ld  [ %l1 + %l0 ], %g1
a00cbbcc:  80 88 60 04  btst  4, %g1
a00cbbd0:  12 80 00 06  bne  0xa00cbbe8
a00cbbd4:  d8 0d a2 50  ldub  [ %l6 + 0x250 ], %o4
a00cbbd8:  c2 04 40 10  ld  [ %l1 + %l0 ], %g1
a00cbbdc:  1b 00 00 c0  sethi  %hi(0x30000), %o5
a00cbbe0:  10 80 00 3c  b  0xa00cbcd0
a00cbbe4:  82 10 40 0d  or  %g1, %o5, %g1
a00cbbe8:  82 08 60 03  and  %g1, 3, %g1
a00cbbec:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00cbbf0:  83 28 60 08  sll  %g1, 8, %g1
a00cbbf4:  82 00 40 0d  add  %g1, %o5, %g1
a00cbbf8:  83 28 60 10  sll  %g1, 0x10, %g1
a00cbbfc:  a7 30 60 10  srl  %g1, 0x10, %l3
a00cbc00:  80 a4 e0 00  cmp  %l3, 0
a00cbc04:  96 10 00 0c  mov  %o4, %o3
a00cbc08:  12 80 00 07  bne  0xa00cbc24
a00cbc0c:  da 04 40 10  ld  [ %l1 + %l0 ], %o5
a00cbc10:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00cbc14:  82 13 40 01  or  %o5, %g1, %g1
a00cbc18:  c2 24 40 10  st  %g1, [ %l1 + %l0 ]
a00cbc1c:  40 3b d6 de  call  0xa0fc1794
a00cbc20:  91 e8 20 0a  restore  %g0, 0xa, %o0
a00cbc24:  03 00 20 00  sethi  %hi(0x800000), %g1
a00cbc28:  82 2b 40 01  andn  %o5, %g1, %g1
a00cbc2c:  c2 24 40 10  st  %g1, [ %l1 + %l0 ]
a00cbc30:  90 10 00 12  mov  %l2, %o0
a00cbc34:  92 10 20 74  mov  0x74, %o1
a00cbc38:  7f ff f1 04  call  0xa00c8048
a00cbc3c:  94 10 20 80  mov  0x80, %o2
a00cbc40:  80 8a 20 ff  btst  0xff, %o0
a00cbc44:  32 80 00 22  bne,a   0xa00cbccc
a00cbc48:  c2 04 40 10  ld  [ %l1 + %l0 ], %g1
a00cbc4c:  29 2a 01 f3  sethi  %hi(0xa807cc00), %l4
a00cbc50:  90 10 00 12  mov  %l2, %o0
a00cbc54:  92 15 22 50  or  %l4, 0x250, %o1
a00cbc58:  7f ff f1 68  call  0xa00c81f8
a00cbc5c:  d4 0d a2 50  ldub  [ %l6 + 0x250 ], %o2
a00cbc60:  80 8a 20 ff  btst  0xff, %o0
a00cbc64:  32 80 00 1a  bne,a   0xa00cbccc
a00cbc68:  c2 04 40 10  ld  [ %l1 + %l0 ], %g1
a00cbc6c:  80 a4 e0 05  cmp  %l3, 5
a00cbc70:  28 80 00 38  bleu,a   0xa00cbd50
a00cbc74:  25 2a 01 f3  sethi  %hi(0xa807cc00), %l2
a00cbc78:  82 04 00 11  add  %l0, %l1, %g1
a00cbc7c:  da 00 60 0c  ld  [ %g1 + 0xc ], %o5
a00cbc80:  03 00 3f ff  sethi  %hi(0xfffc00), %g1
a00cbc84:  82 10 63 ff  or  %g1, 0x3ff, %g1	! 0xffffff
a00cbc88:  80 a3 40 01  cmp  %o5, %g1
a00cbc8c:  12 80 00 13  bne  0xa00cbcd8
a00cbc90:  82 04 80 12  add  %l2, %l2, %g1
a00cbc94:  9a 15 22 50  or  %l4, 0x250, %o5
a00cbc98:  c2 0b 60 03  ldub  [ %o5 + 3 ], %g1
a00cbc9c:  80 a0 60 00  cmp  %g1, 0
a00cbca0:  12 80 00 0e  bne  0xa00cbcd8
a00cbca4:  82 04 80 12  add  %l2, %l2, %g1
a00cbca8:  c2 0b 60 04  ldub  [ %o5 + 4 ], %g1
a00cbcac:  80 a0 60 00  cmp  %g1, 0
a00cbcb0:  12 80 00 0a  bne  0xa00cbcd8
a00cbcb4:  82 04 80 12  add  %l2, %l2, %g1
a00cbcb8:  c2 0b 60 05  ldub  [ %o5 + 5 ], %g1
a00cbcbc:  80 a0 60 00  cmp  %g1, 0
a00cbcc0:  12 80 00 06  bne  0xa00cbcd8
a00cbcc4:  82 04 80 12  add  %l2, %l2, %g1
a00cbcc8:  c2 04 40 10  ld  [ %l1 + %l0 ], %g1
a00cbccc:  82 08 40 15  and  %g1, %l5, %g1
a00cbcd0:  10 80 01 3f  b  0xa00cc1cc
a00cbcd4:  c2 24 40 10  st  %g1, [ %l1 + %l0 ]
a00cbcd8:  82 00 40 12  add  %g1, %l2, %g1
a00cbcdc:  83 28 60 03  sll  %g1, 3, %g1
a00cbce0:  9a 15 e3 b0  or  %l7, 0x3b0, %o5
a00cbce4:  82 00 40 0d  add  %g1, %o5, %g1
a00cbce8:  c2 00 60 0c  ld  [ %g1 + 0xc ], %g1
a00cbcec:  80 a0 60 00  cmp  %g1, 0
a00cbcf0:  32 80 00 18  bne,a   0xa00cbd50
a00cbcf4:  25 2a 01 f3  sethi  %hi(0xa807cc00), %l2
a00cbcf8:  92 15 22 50  or  %l4, 0x250, %o1
a00cbcfc:  c2 0a 60 03  ldub  [ %o1 + 3 ], %g1
a00cbd00:  80 a0 60 00  cmp  %g1, 0
a00cbd04:  12 80 00 0b  bne  0xa00cbd30
a00cbd08:  9a 04 80 12  add  %l2, %l2, %o5
a00cbd0c:  c2 0a 60 04  ldub  [ %o1 + 4 ], %g1
a00cbd10:  80 a0 60 00  cmp  %g1, 0
a00cbd14:  12 80 00 08  bne  0xa00cbd34
a00cbd18:  9a 03 40 12  add  %o5, %l2, %o5
a00cbd1c:  c2 0a 60 05  ldub  [ %o1 + 5 ], %g1
a00cbd20:  80 a0 60 00  cmp  %g1, 0
a00cbd24:  22 80 00 0b  be,a   0xa00cbd50
a00cbd28:  25 2a 01 f3  sethi  %hi(0xa807cc00), %l2
a00cbd2c:  9a 04 80 12  add  %l2, %l2, %o5
a00cbd30:  9a 03 40 12  add  %o5, %l2, %o5
a00cbd34:  96 15 e3 b0  or  %l7, 0x3b0, %o3
a00cbd38:  9b 2b 60 03  sll  %o5, 3, %o5
a00cbd3c:  d8 02 c0 0d  ld  [ %o3 + %o5 ], %o4
a00cbd40:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00cbd44:  82 2b 00 01  andn  %o4, %g1, %g1
a00cbd48:  10 80 01 21  b  0xa00cc1cc
a00cbd4c:  c2 22 c0 0d  st  %g1, [ %o3 + %o5 ]
a00cbd50:  96 14 a2 50  or  %l2, 0x250, %o3
a00cbd54:  c2 0a e0 03  ldub  [ %o3 + 3 ], %g1
a00cbd58:  da 0a e0 04  ldub  [ %o3 + 4 ], %o5
a00cbd5c:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00cbd60:  9b 2b 60 08  sll  %o5, 8, %o5
a00cbd64:  83 28 60 10  sll  %g1, 0x10, %g1
a00cbd68:  82 10 40 0d  or  %g1, %o5, %g1
a00cbd6c:  98 04 00 10  add  %l0, %l0, %o4
a00cbd70:  da 0a e0 05  ldub  [ %o3 + 5 ], %o5
a00cbd74:  98 03 00 10  add  %o4, %l0, %o4
a00cbd78:  29 2a 01 e2  sethi  %hi(0xa8078800), %l4
a00cbd7c:  99 2b 20 03  sll  %o4, 3, %o4
a00cbd80:  96 15 23 b0  or  %l4, 0x3b0, %o3
a00cbd84:  82 10 40 0d  or  %g1, %o5, %g1
a00cbd88:  98 03 00 0b  add  %o4, %o3, %o4
a00cbd8c:  80 a0 60 00  cmp  %g1, 0
a00cbd90:  12 80 00 04  bne  0xa00cbda0
a00cbd94:  c2 23 20 0c  st  %g1, [ %o4 + 0xc ]
a00cbd98:  82 10 20 01  mov  1, %g1
a00cbd9c:  c2 23 20 0c  st  %g1, [ %o4 + 0xc ]
a00cbda0:  90 10 00 10  mov  %l0, %o0
a00cbda4:  92 10 20 05  mov  5, %o1
a00cbda8:  94 10 20 04  mov  4, %o2
a00cbdac:  7f ff ee 45  call  0xa00c76c0
a00cbdb0:  96 10 20 01  mov  1, %o3
a00cbdb4:  90 10 00 10  mov  %l0, %o0
a00cbdb8:  92 10 20 05  mov  5, %o1
a00cbdbc:  94 10 20 04  mov  4, %o2
a00cbdc0:  7f ff ee 40  call  0xa00c76c0
a00cbdc4:  96 10 20 00  clr  %o3
a00cbdc8:  90 10 00 10  mov  %l0, %o0
a00cbdcc:  92 10 20 0b  mov  0xb, %o1
a00cbdd0:  7f ff f2 86  call  0xa00c87e8
a00cbdd4:  15 00 00 20  sethi  %hi(0x8000), %o2
a00cbdd8:  a2 10 20 00  clr  %l1
a00cbddc:  82 0c 60 ff  and  %l1, 0xff, %g1
a00cbde0:  9a 14 a2 50  or  %l2, 0x250, %o5
a00cbde4:  82 00 40 0d  add  %g1, %o5, %g1
a00cbde8:  d4 08 60 01  ldub  [ %g1 + 1 ], %o2
a00cbdec:  90 10 00 10  mov  %l0, %o0
a00cbdf0:  7f ff ee 19  call  0xa00c7654
a00cbdf4:  92 10 20 01  mov  1, %o1
a00cbdf8:  a2 04 60 01  inc  %l1
a00cbdfc:  82 0c 60 ff  and  %l1, 0xff, %g1
a00cbe00:  80 a0 60 04  cmp  %g1, 4
a00cbe04:  08 bf ff f8  bleu  0xa00cbde4
a00cbe08:  9a 14 a2 50  or  %l2, 0x250, %o5
a00cbe0c:  c2 0d a2 50  ldub  [ %l6 + 0x250 ], %g1
a00cbe10:  82 00 7f ff  add  %g1, -1, %g1
a00cbe14:  80 a0 60 15  cmp  %g1, 0x15
a00cbe18:  04 80 00 10  ble  0xa00cbe58
a00cbe1c:  a2 10 20 15  mov  0x15, %l1
a00cbe20:  9a 14 a2 50  or  %l2, 0x250, %o5
a00cbe24:  82 0c 60 ff  and  %l1, 0xff, %g1
a00cbe28:  82 00 40 0d  add  %g1, %o5, %g1
a00cbe2c:  d4 08 60 01  ldub  [ %g1 + 1 ], %o2
a00cbe30:  90 10 00 10  mov  %l0, %o0
a00cbe34:  7f ff ee 08  call  0xa00c7654
a00cbe38:  92 10 20 01  mov  1, %o1
a00cbe3c:  a2 04 60 01  inc  %l1
a00cbe40:  c2 0d a2 50  ldub  [ %l6 + 0x250 ], %g1
a00cbe44:  82 00 7f ff  add  %g1, -1, %g1
a00cbe48:  9a 0c 60 ff  and  %l1, 0xff, %o5
a00cbe4c:  80 a3 40 01  cmp  %o5, %g1
a00cbe50:  06 bf ff f5  bl  0xa00cbe24
a00cbe54:  9a 14 a2 50  or  %l2, 0x250, %o5
a00cbe58:  27 2a 01 f3  sethi  %hi(0xa807cc00), %l3
a00cbe5c:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00cbe60:  94 10 61 88  or  %g1, 0x188, %o2	! 0xa807cd88
a00cbe64:  a2 10 20 00  clr  %l1
a00cbe68:  96 14 e2 50  or  %l3, 0x250, %o3
a00cbe6c:  98 0c 60 ff  and  %l1, 0xff, %o4
a00cbe70:  82 03 00 0b  add  %o4, %o3, %g1
a00cbe74:  a2 04 60 01  inc  %l1
a00cbe78:  c2 08 60 06  ldub  [ %g1 + 6 ], %g1
a00cbe7c:  9a 0c 60 ff  and  %l1, 0xff, %o5
a00cbe80:  80 a3 60 0f  cmp  %o5, 0xf
a00cbe84:  08 bf ff fa  bleu  0xa00cbe6c
a00cbe88:  c2 2a 80 0c  stb  %g1, [ %o2 + %o4 ]
a00cbe8c:  a2 10 20 00  clr  %l1
a00cbe90:  82 0c 60 ff  and  %l1, 0xff, %g1
a00cbe94:  9a 14 e2 50  or  %l3, 0x250, %o5
a00cbe98:  82 00 40 0d  add  %g1, %o5, %g1
a00cbe9c:  a4 0e 20 ff  and  %i0, 0xff, %l2
a00cbea0:  d4 08 60 01  ldub  [ %g1 + 1 ], %o2
a00cbea4:  90 10 00 12  mov  %l2, %o0
a00cbea8:  7f ff ed eb  call  0xa00c7654
a00cbeac:  92 10 20 01  mov  1, %o1
a00cbeb0:  a2 04 60 01  inc  %l1
a00cbeb4:  82 0c 60 ff  and  %l1, 0xff, %g1
a00cbeb8:  80 a0 60 04  cmp  %g1, 4
a00cbebc:  08 bf ff f7  bleu  0xa00cbe98
a00cbec0:  9a 14 e2 50  or  %l3, 0x250, %o5
a00cbec4:  90 10 00 12  mov  %l2, %o0
a00cbec8:  92 10 20 01  mov  1, %o1
a00cbecc:  7f ff ed e2  call  0xa00c7654
a00cbed0:  94 10 20 80  mov  0x80, %o2
a00cbed4:  90 10 00 12  mov  %l2, %o0
a00cbed8:  92 10 20 06  mov  6, %o1
a00cbedc:  7f ff ed de  call  0xa00c7654
a00cbee0:  94 10 20 e0  mov  0xe0, %o2
a00cbee4:  90 10 00 12  mov  %l2, %o0
a00cbee8:  7f ff ee 22  call  0xa00c7770
a00cbeec:  92 10 20 06  mov  6, %o1
a00cbef0:  80 8a 20 80  btst  0x80, %o0
a00cbef4:  12 bf ff fd  bne  0xa00cbee8
a00cbef8:  90 10 00 12  mov  %l2, %o0
a00cbefc:  92 10 20 14  mov  0x14, %o1
a00cbf00:  7f ff f2 3a  call  0xa00c87e8
a00cbf04:  15 00 00 20  sethi  %hi(0x8000), %o2
a00cbf08:  a2 10 20 00  clr  %l1
a00cbf0c:  90 10 00 12  mov  %l2, %o0
a00cbf10:  7f ff ee 18  call  0xa00c7770
a00cbf14:  92 10 20 01  mov  1, %o1
a00cbf18:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00cbf1c:  a2 04 60 01  inc  %l1
a00cbf20:  03 2a 01 f4  sethi  %hi(0xa807d000), %g1
a00cbf24:  9a 0c 60 ff  and  %l1, 0xff, %o5
a00cbf28:  82 10 60 88  or  %g1, 0x88, %g1
a00cbf2c:  80 a3 60 0f  cmp  %o5, 0xf
a00cbf30:  08 bf ff f7  bleu  0xa00cbf0c
a00cbf34:  d0 28 40 10  stb  %o0, [ %g1 + %l0 ]
a00cbf38:  92 14 e2 50  or  %l3, 0x250, %o1
a00cbf3c:  d0 0a 60 02  ldub  [ %o1 + 2 ], %o0
a00cbf40:  94 0a 20 ff  and  %o0, 0xff, %o2
a00cbf44:  80 8a a0 0c  btst  0xc, %o2
a00cbf48:  22 80 00 0d  be,a   0xa00cbf7c
a00cbf4c:  c2 0a 60 01  ldub  [ %o1 + 1 ], %g1
a00cbf50:  98 04 80 12  add  %l2, %l2, %o4
a00cbf54:  98 03 00 12  add  %o4, %l2, %o4
a00cbf58:  96 15 23 b0  or  %l4, 0x3b0, %o3
a00cbf5c:  99 2b 20 03  sll  %o4, 3, %o4
a00cbf60:  da 02 c0 0c  ld  [ %o3 + %o4 ], %o5
a00cbf64:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00cbf68:  82 2b 40 01  andn  %o5, %g1, %g1
a00cbf6c:  1b 00 00 80  sethi  %hi(0x20000), %o5
a00cbf70:  82 10 40 0d  or  %g1, %o5, %g1
a00cbf74:  c2 22 c0 0c  st  %g1, [ %o3 + %o4 ]
a00cbf78:  c2 0a 60 01  ldub  [ %o1 + 1 ], %g1
a00cbf7c:  80 88 60 01  btst  1, %g1
a00cbf80:  02 80 00 12  be  0xa00cbfc8
a00cbf84:  98 14 e2 50  or  %l3, 0x250, %o4
a00cbf88:  82 0a a0 f0  and  %o2, 0xf0, %g1
a00cbf8c:  80 a0 60 f0  cmp  %g1, 0xf0
a00cbf90:  32 80 00 0f  bne,a   0xa00cbfcc
a00cbf94:  da 0b 20 02  ldub  [ %o4 + 2 ], %o5
a00cbf98:  82 0e 20 ff  and  %i0, 0xff, %g1
a00cbf9c:  9a 00 40 01  add  %g1, %g1, %o5
a00cbfa0:  9a 03 40 01  add  %o5, %g1, %o5
a00cbfa4:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00cbfa8:  82 10 63 b0  or  %g1, 0x3b0, %g1	! 0xa8078bb0
a00cbfac:  9b 2b 60 03  sll  %o5, 3, %o5
a00cbfb0:  9a 03 40 01  add  %o5, %g1, %o5
a00cbfb4:  82 12 20 08  or  %o0, 8, %g1
a00cbfb8:  c2 2a 60 02  stb  %g1, [ %o1 + 2 ]
a00cbfbc:  82 10 20 01  mov  1, %g1
a00cbfc0:  10 80 00 0e  b  0xa00cbff8
a00cbfc4:  c2 2b 60 05  stb  %g1, [ %o5 + 5 ]
a00cbfc8:  da 0b 20 02  ldub  [ %o4 + 2 ], %o5
a00cbfcc:  82 0b 60 f0  and  %o5, 0xf0, %g1
a00cbfd0:  80 a0 60 f0  cmp  %g1, 0xf0
a00cbfd4:  12 80 00 08  bne  0xa00cbff4
a00cbfd8:  82 03 60 10  add  %o5, 0x10, %g1
a00cbfdc:  c2 0b 20 01  ldub  [ %o4 + 1 ], %g1
a00cbfe0:  9a 0b 60 0f  and  %o5, 0xf, %o5
a00cbfe4:  82 10 60 01  or  %g1, 1, %g1
a00cbfe8:  c2 2b 20 01  stb  %g1, [ %o4 + 1 ]
a00cbfec:  10 80 00 03  b  0xa00cbff8
a00cbff0:  da 2b 20 02  stb  %o5, [ %o4 + 2 ]
a00cbff4:  c2 2b 20 02  stb  %g1, [ %o4 + 2 ]
a00cbff8:  29 2a 01 f3  sethi  %hi(0xa807cc00), %l4
a00cbffc:  96 15 22 50  or  %l4, 0x250, %o3	! 0xa807ce50
a00cc000:  da 0a e0 01  ldub  [ %o3 + 1 ], %o5
a00cc004:  82 0b 60 0e  and  %o5, 0xe, %g1
a00cc008:  80 a0 60 07  cmp  %g1, 7
a00cc00c:  14 80 00 05  bg  0xa00cc020
a00cc010:  82 0e 20 ff  and  %i0, 0xff, %g1
a00cc014:  82 03 60 02  add  %o5, 2, %g1
a00cc018:  10 80 00 0d  b  0xa00cc04c
a00cc01c:  c2 2a e0 01  stb  %g1, [ %o3 + 1 ]
a00cc020:  9a 00 40 01  add  %g1, %g1, %o5
a00cc024:  9a 03 40 01  add  %o5, %g1, %o5
a00cc028:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00cc02c:  d8 0a e0 02  ldub  [ %o3 + 2 ], %o4
a00cc030:  82 10 63 b0  or  %g1, 0x3b0, %g1
a00cc034:  9b 2b 60 03  sll  %o5, 3, %o5
a00cc038:  9a 03 40 01  add  %o5, %g1, %o5
a00cc03c:  98 13 20 04  or  %o4, 4, %o4
a00cc040:  d8 2a e0 02  stb  %o4, [ %o3 + 2 ]
a00cc044:  82 10 20 01  mov  1, %g1
a00cc048:  c2 2b 60 06  stb  %g1, [ %o5 + 6 ]
a00cc04c:  82 0e 20 ff  and  %i0, 0xff, %g1
a00cc050:  9a 00 40 01  add  %g1, %g1, %o5
a00cc054:  98 15 22 50  or  %l4, 0x250, %o4
a00cc058:  9a 03 40 01  add  %o5, %g1, %o5
a00cc05c:  e2 0b 20 02  ldub  [ %o4 + 2 ], %l1
a00cc060:  a5 2b 60 03  sll  %o5, 3, %l2
a00cc064:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00cc068:  d6 0b 20 01  ldub  [ %o4 + 1 ], %o3
a00cc06c:  9a 0c 60 ff  and  %l1, 0xff, %o5
a00cc070:  a6 10 63 b0  or  %g1, 0x3b0, %l3
a00cc074:  82 04 80 13  add  %l2, %l3, %g1
a00cc078:  94 0a e0 01  and  %o3, 1, %o2
a00cc07c:  92 0b 60 08  and  %o5, 8, %o1
a00cc080:  90 0b 60 04  and  %o5, 4, %o0
a00cc084:  98 0b 60 02  and  %o5, 2, %o4
a00cc088:  de 08 60 05  ldub  [ %g1 + 5 ], %o7
a00cc08c:  e0 08 60 06  ldub  [ %g1 + 6 ], %l0
a00cc090:  9b 33 60 04  srl  %o5, 4, %o5
a00cc094:  95 2a a0 04  sll  %o2, 4, %o2
a00cc098:  96 0a e0 0e  and  %o3, 0xe, %o3
a00cc09c:  93 3a 60 03  sra  %o1, 3, %o1
a00cc0a0:  91 3a 20 02  sra  %o0, 2, %o0
a00cc0a4:  94 12 80 0d  or  %o2, %o5, %o2
a00cc0a8:  92 12 40 0f  or  %o1, %o7, %o1
a00cc0ac:  90 12 00 10  or  %o0, %l0, %o0
a00cc0b0:  97 3a e0 01  sra  %o3, 1, %o3
a00cc0b4:  a2 0c 60 01  and  %l1, 1, %l1
a00cc0b8:  99 3b 20 01  sra  %o4, 1, %o4
a00cc0bc:  d8 28 60 08  stb  %o4, [ %g1 + 8 ]
a00cc0c0:  d4 28 60 03  stb  %o2, [ %g1 + 3 ]
a00cc0c4:  d6 28 60 04  stb  %o3, [ %g1 + 4 ]
a00cc0c8:  d2 28 60 05  stb  %o1, [ %g1 + 5 ]
a00cc0cc:  d0 28 60 06  stb  %o0, [ %g1 + 6 ]
a00cc0d0:  e2 28 60 07  stb  %l1, [ %g1 + 7 ]
a00cc0d4:  da 04 c0 12  ld  [ %l3 + %l2 ], %o5
a00cc0d8:  83 33 60 10  srl  %o5, 0x10, %g1
a00cc0dc:  82 08 60 03  and  %g1, 3, %g1
a00cc0e0:  80 a0 60 02  cmp  %g1, 2
a00cc0e4:  02 80 00 1b  be  0xa00cc150
a00cc0e8:  19 3f ff 3f  sethi  %hi(0xfffcfc00), %o4
a00cc0ec:  98 13 23 ff  or  %o4, 0x3ff, %o4	! 0xfffcffff
a00cc0f0:  82 0b 40 0c  and  %o5, %o4, %g1
a00cc0f4:  1b 00 00 40  sethi  %hi(0x10000), %o5
a00cc0f8:  82 10 40 0d  or  %g1, %o5, %g1
a00cc0fc:  c2 24 c0 12  st  %g1, [ %l3 + %l2 ]
a00cc100:  03 2a 01 f4  sethi  %hi(0xa807d000), %g1
a00cc104:  9e 10 60 88  or  %g1, 0x88, %o7	! 0xa807d088
a00cc108:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00cc10c:  90 10 61 88  or  %g1, 0x188, %o0	! 0xa807cd88
a00cc110:  92 10 00 13  mov  %l3, %o1
a00cc114:  94 10 00 12  mov  %l2, %o2
a00cc118:  a2 10 20 00  clr  %l1
a00cc11c:  82 0c 60 ff  and  %l1, 0xff, %g1
a00cc120:  da 0a 00 01  ldub  [ %o0 + %g1 ], %o5
a00cc124:  a2 04 60 01  inc  %l1
a00cc128:  c2 0b c0 01  ldub  [ %o7 + %g1 ], %g1
a00cc12c:  80 a0 40 0d  cmp  %g1, %o5
a00cc130:  02 80 00 05  be  0xa00cc144
a00cc134:  96 0c 60 ff  and  %l1, 0xff, %o3
a00cc138:  c2 02 40 0a  ld  [ %o1 + %o2 ], %g1
a00cc13c:  82 08 40 0c  and  %g1, %o4, %g1
a00cc140:  c2 22 40 0a  st  %g1, [ %o1 + %o2 ]
a00cc144:  80 a2 e0 0f  cmp  %o3, 0xf
a00cc148:  08 bf ff f6  bleu  0xa00cc120
a00cc14c:  82 0c 60 ff  and  %l1, 0xff, %g1
a00cc150:  9a 15 22 50  or  %l4, 0x250, %o5
a00cc154:  c2 0b 60 01  ldub  [ %o5 + 1 ], %g1
a00cc158:  da 0b 60 02  ldub  [ %o5 + 2 ], %o5
a00cc15c:  82 08 60 01  and  %g1, 1, %g1
a00cc160:  9b 33 60 04  srl  %o5, 4, %o5
a00cc164:  83 28 60 04  sll  %g1, 4, %g1
a00cc168:  82 00 40 0d  add  %g1, %o5, %g1
a00cc16c:  95 28 60 02  sll  %g1, 2, %o2
a00cc170:  94 02 80 01  add  %o2, %g1, %o2
a00cc174:  03 00 00 10  sethi  %hi(0x4000), %g1
a00cc178:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00cc17c:  94 12 80 01  or  %o2, %g1, %o2
a00cc180:  90 10 00 18  mov  %i0, %o0
a00cc184:  7f ff f1 99  call  0xa00c87e8
a00cc188:  92 10 20 0b  mov  0xb, %o1
a00cc18c:  a2 10 20 00  clr  %l1
a00cc190:  9b 2e 20 02  sll  %i0, 2, %o5
a00cc194:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00cc198:  82 10 62 38  or  %g1, 0x238, %g1	! 0xa807ce38
a00cc19c:  9a 03 40 18  add  %o5, %i0, %o5
a00cc1a0:  9a 03 40 01  add  %o5, %g1, %o5
a00cc1a4:  82 0c 60 ff  and  %l1, 0xff, %g1
a00cc1a8:  d4 0b 40 01  ldub  [ %o5 + %g1 ], %o2
a00cc1ac:  90 10 00 18  mov  %i0, %o0
a00cc1b0:  7f ff ed 29  call  0xa00c7654
a00cc1b4:  92 10 20 01  mov  1, %o1
a00cc1b8:  a2 04 60 01  inc  %l1
a00cc1bc:  82 0c 60 ff  and  %l1, 0xff, %g1
a00cc1c0:  80 a0 60 04  cmp  %g1, 4
a00cc1c4:  08 bf ff f4  bleu  0xa00cc194
a00cc1c8:  9b 2e 20 02  sll  %i0, 2, %o5
a00cc1cc:  81 c7 e0 08  ret
a00cc1d0:  81 e8 00 00  restore
