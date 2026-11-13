# leon2s FUN_a00b0138 0xa00b0138-0xa00b0248 (272 bytes)
a00b0138:  9d e3 bf 90  save  %sp, -112, %sp
a00b013c:  13 28 02 d3  sethi  %hi(0xa00b4c00), %o1
a00b0140:  92 12 62 04  or  %o1, 0x204, %o1	! 0xa00b4e04
a00b0144:  94 10 20 08  mov  8, %o2
a00b0148:  40 00 05 24  call  0xa00b15d8
a00b014c:  90 07 bf f0  add  %fp, -16, %o0
a00b0150:  a2 0e 20 ff  and  %i0, 0xff, %l1
a00b0154:  7f ff f2 5b  call  0xa00acac0
a00b0158:  90 10 00 11  mov  %l1, %o0
a00b015c:  a0 10 00 08  mov  %o0, %l0
a00b0160:  7f ff f2 68  call  0xa00acb00
a00b0164:  90 10 00 11  mov  %l1, %o0
a00b0168:  a1 2c 20 10  sll  %l0, 0x10, %l0
a00b016c:  91 2a 20 10  sll  %o0, 0x10, %o0
a00b0170:  a1 34 20 10  srl  %l0, 0x10, %l0
a00b0174:  91 32 20 10  srl  %o0, 0x10, %o0
a00b0178:  a4 10 20 00  clr  %l2
a00b017c:  94 10 20 00  clr  %o2
a00b0180:  98 10 20 00  clr  %o4
a00b0184:  92 07 bf f8  add  %fp, -8, %o1
a00b0188:  82 0b 20 ff  and  %o4, 0xff, %g1
a00b018c:  83 28 60 02  sll  %g1, 2, %g1
a00b0190:  9a 00 40 09  add  %g1, %o1, %o5
a00b0194:  98 03 20 01  inc  %o4
a00b0198:  c2 13 7f f8  lduh  [ %o5 + -8 ], %g1
a00b019c:  80 a4 00 01  cmp  %l0, %g1
a00b01a0:  12 80 00 06  bne  0xa00b01b8
a00b01a4:  96 0b 20 ff  and  %o4, 0xff, %o3
a00b01a8:  c2 13 7f fa  lduh  [ %o5 + -6 ], %g1
a00b01ac:  80 a2 00 01  cmp  %o0, %g1
a00b01b0:  22 80 00 05  be,a   0xa00b01c4
a00b01b4:  94 10 20 01  mov  1, %o2
a00b01b8:  80 a2 e0 01  cmp  %o3, 1
a00b01bc:  08 bf ff f4  bleu  0xa00b018c
a00b01c0:  82 0b 20 ff  and  %o4, 0xff, %g1
a00b01c4:  82 0a a0 ff  and  %o2, 0xff, %g1
a00b01c8:  80 a0 60 01  cmp  %g1, 1
a00b01cc:  12 80 00 0d  bne  0xa00b0200
a00b01d0:  80 a0 60 00  cmp  %g1, 0
a00b01d4:  90 10 00 11  mov  %l1, %o0
a00b01d8:  7f ff da 78  call  0xa00a6bb8
a00b01dc:  92 10 20 46  mov  0x46, %o1
a00b01e0:  80 8a 20 04  btst  4, %o0
a00b01e4:  02 80 00 17  be  0xa00b0240
a00b01e8:  b0 0c a0 01  and  %l2, 1, %i0
a00b01ec:  90 10 00 11  mov  %l1, %o0
a00b01f0:  92 10 20 46  mov  0x46, %o1
a00b01f4:  94 10 20 04  mov  4, %o2
a00b01f8:  10 80 00 0f  b  0xa00b0234
a00b01fc:  96 10 20 00  clr  %o3
a00b0200:  32 80 00 10  bne,a   0xa00b0240
a00b0204:  b0 0c a0 01  and  %l2, 1, %i0
a00b0208:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00b020c:  90 10 00 18  mov  %i0, %o0
a00b0210:  7f ff da 6a  call  0xa00a6bb8
a00b0214:  92 10 20 46  mov  0x46, %o1
a00b0218:  80 8a 20 04  btst  4, %o0
a00b021c:  32 80 00 09  bne,a   0xa00b0240
a00b0220:  b0 0c a0 01  and  %l2, 1, %i0
a00b0224:  90 10 00 18  mov  %i0, %o0
a00b0228:  92 10 20 46  mov  0x46, %o1
a00b022c:  94 10 20 04  mov  4, %o2
a00b0230:  96 10 20 01  mov  1, %o3
a00b0234:  7f ff da 99  call  0xa00a6c98
a00b0238:  a4 10 20 01  mov  1, %l2
a00b023c:  b0 0c a0 01  and  %l2, 1, %i0
a00b0240:  81 c7 e0 08  ret
a00b0244:  81 e8 00 00  restore
