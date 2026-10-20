# leon2s FUN_a007d140 0xa007d140-0xa007d21c (220 bytes)
a007d140:  9d e3 bf 98  save  %sp, -104, %sp
a007d144:  a4 0e 20 ff  and  %i0, 0xff, %l2
a007d148:  7f ff ff c3  call  0xa007d054
a007d14c:  90 10 00 12  mov  %l2, %o0
a007d150:  80 8a 20 ff  btst  0xff, %o0
a007d154:  22 80 00 30  be,a   0xa007d214
a007d158:  b0 10 20 01  mov  1, %i0
a007d15c:  a6 10 20 00  clr  %l3
a007d160:  21 00 00 07  sethi  %hi(0x1c00), %l0
a007d164:  92 14 22 98  or  %l0, 0x298, %o1	! 0x1e98
a007d168:  40 00 a8 6b  call  0xa00a7314
a007d16c:  90 10 00 12  mov  %l2, %o0
a007d170:  a3 32 20 18  srl  %o0, 0x18, %l1
a007d174:  92 14 22 9c  or  %l0, 0x29c, %o1
a007d178:  40 00 a8 67  call  0xa00a7314
a007d17c:  90 10 00 12  mov  %l2, %o0
a007d180:  a8 10 00 08  mov  %o0, %l4
a007d184:  90 10 00 12  mov  %l2, %o0
a007d188:  40 00 a8 63  call  0xa00a7314
a007d18c:  92 14 22 9c  or  %l0, 0x29c, %o1
a007d190:  82 0d 20 ff  and  %l4, 0xff, %g1
a007d194:  a6 04 e0 01  inc  %l3
a007d198:  94 0c 60 ff  and  %l1, 0xff, %o2
a007d19c:  96 08 60 f0  and  %g1, 0xf0, %o3
a007d1a0:  91 32 20 08  srl  %o0, 8, %o0
a007d1a4:  98 0c e0 ff  and  %l3, 0xff, %o4
a007d1a8:  82 08 60 0f  and  %g1, 0xf, %g1
a007d1ac:  80 a2 a0 18  cmp  %o2, 0x18
a007d1b0:  12 80 00 09  bne  0xa007d1d4
a007d1b4:  9a 0a 20 f0  and  %o0, 0xf0, %o5
a007d1b8:  80 a0 60 01  cmp  %g1, 1
a007d1bc:  14 80 00 06  bg  0xa007d1d4
a007d1c0:  80 a2 e0 1f  cmp  %o3, 0x1f
a007d1c4:  14 80 00 04  bg  0xa007d1d4
a007d1c8:  80 a3 60 1f  cmp  %o5, 0x1f
a007d1cc:  04 80 00 0f  ble  0xa007d208
a007d1d0:  80 a3 20 02  cmp  %o4, 2
a007d1d4:  98 0a 20 ff  and  %o0, 0xff, %o4
a007d1d8:  92 06 20 41  add  %i0, 0x41, %o1
a007d1dc:  93 2a 60 18  sll  %o1, 0x18, %o1
a007d1e0:  11 28 01 9e  sethi  %hi(0xa0067800), %o0
a007d1e4:  93 3a 60 18  sra  %o1, 0x18, %o1
a007d1e8:  96 0d 20 ff  and  %l4, 0xff, %o3
a007d1ec:  7f ff d7 96  call  0xa0073044
a007d1f0:  90 12 23 58  or  %o0, 0x358, %o0
a007d1f4:  11 28 01 9e  sethi  %hi(0xa0067800), %o0
a007d1f8:  7f ff d8 b3  call  0xa00734c4
a007d1fc:  90 12 23 90  or  %o0, 0x390, %o0	! 0xa0067b90
a007d200:  10 80 00 05  b  0xa007d214
a007d204:  b0 10 20 00  clr  %i0
a007d208:  08 bf ff d7  bleu  0xa007d164
a007d20c:  21 00 00 07  sethi  %hi(0x1c00), %l0
a007d210:  b0 10 20 01  mov  1, %i0
a007d214:  81 c7 e0 08  ret
a007d218:  81 e8 00 00  restore
