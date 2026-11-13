# leon2m FUN_a00e0134 0xa00e0134-0xa00e021c (232 bytes)  [FUN_a00e0214 = unreachable ret/restore tail, merged]
a00e0134:  9d e3 bf 98  save  %sp, -104, %sp
a00e0138:  d4 07 a0 5c  ld  [ %fp + 0x5c ], %o2
a00e013c:  e0 07 a0 60  ld  [ %fp + 0x60 ], %l0
a00e0140:  9a 10 20 00  clr  %o5
a00e0144:  96 10 20 00  clr  %o3
a00e0148:  98 10 20 00  clr  %o4
a00e014c:  91 36 c0 0c  srl  %i3, %o4, %o0
a00e0150:  82 0a 20 01  and  %o0, 1, %g1
a00e0154:  9a 18 40 0d  xor  %g1, %o5, %o5
a00e0158:  98 03 20 01  inc  %o4
a00e015c:  96 02 c0 0d  add  %o3, %o5, %o3
a00e0160:  80 a3 20 1f  cmp  %o4, 0x1f
a00e0164:  04 bf ff fa  ble  0xa00e014c
a00e0168:  9a 10 00 01  mov  %g1, %o5
a00e016c:  92 02 ff ff  add  %o3, -1, %o1
a00e0170:  80 a2 60 01  cmp  %o1, 1
a00e0174:  08 80 00 08  bleu  0xa00e0194
a00e0178:  a2 0a 80 1b  and  %o2, %i3, %l1
a00e017c:  7f ff fd a4  call  0xa00df80c
a00e0180:  31 00 06 64  sethi  %hi(0x199000), %i0
a00e0184:  40 00 02 8f  call  0xa00e0bc0
a00e0188:  b0 16 23 80  or  %i0, 0x380, %i0	! 0x199380
a00e018c:  7f ff fb f9  call  0xa00df170
a00e0190:  81 e8 00 00  restore
a00e0194:  90 10 00 18  mov  %i0, %o0
a00e0198:  40 00 00 55  call  0xa00e02ec
a00e019c:  92 10 00 19  mov  %i1, %o1
a00e01a0:  b4 0e 80 1b  and  %i2, %i3, %i2
a00e01a4:  b8 0f 00 1b  and  %i4, %i3, %i4
a00e01a8:  80 a4 20 00  cmp  %l0, 0
a00e01ac:  12 80 00 0d  bne  0xa00e01e0
a00e01b0:  82 0a 00 1b  and  %o0, %i3, %g1
a00e01b4:  96 20 40 1a  sub  %g1, %i2, %o3
a00e01b8:  82 0a e0 ff  and  %o3, 0xff, %g1
a00e01bc:  80 a0 40 1c  cmp  %g1, %i4
a00e01c0:  0a 80 00 0e  bcs  0xa00e01f8
a00e01c4:  80 a7 60 00  cmp  %i5, 0
a00e01c8:  9e 0a 20 ff  and  %o0, 0xff, %o7
a00e01cc:  98 08 40 1b  and  %g1, %i3, %o4
a00e01d0:  b4 2b c0 1b  andn  %o7, %i3, %i2
a00e01d4:  b4 16 80 0c  or  %i2, %o4, %i2
a00e01d8:  40 00 00 76  call  0xa00e03b0
a00e01dc:  81 e8 00 00  restore
a00e01e0:  94 00 40 1a  add  %g1, %i2, %o2
a00e01e4:  82 0a a0 ff  and  %o2, 0xff, %g1
a00e01e8:  80 a0 40 1c  cmp  %g1, %i4
a00e01ec:  08 bf ff f8  bleu  0xa00e01cc
a00e01f0:  9e 0a 20 ff  and  %o0, 0xff, %o7
a00e01f4:  80 a7 60 00  cmp  %i5, 0
a00e01f8:  12 80 00 06  bne  0xa00e0210
a00e01fc:  b8 0a 20 ff  and  %o0, 0xff, %i4
a00e0200:  a0 2f 00 1b  andn  %i4, %i3, %l0
a00e0204:  b4 14 00 11  or  %l0, %l1, %i2
a00e0208:  40 00 00 6a  call  0xa00e03b0
a00e020c:  81 e8 00 00  restore
a00e0210:  01 00 00 00  nop
a00e0214:  81 c7 e0 08  ret
a00e0218:  81 e8 00 00  restore
