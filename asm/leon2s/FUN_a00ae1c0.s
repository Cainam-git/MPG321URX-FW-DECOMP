# leon2s FUN_a00ae1c0 0xa00ae1c0-0xa00ae238 (120 bytes)
a00ae1c0:  9d e3 bf 98  save  %sp, -104, %sp
a00ae1c4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00ae1c8:  92 10 20 00  clr  %o1
a00ae1cc:  7f ff e2 7b  call  0xa00a6bb8
a00ae1d0:  90 10 00 18  mov  %i0, %o0
a00ae1d4:  b4 10 00 08  mov  %o0, %i2
a00ae1d8:  90 10 00 18  mov  %i0, %o0
a00ae1dc:  92 10 20 00  clr  %o1
a00ae1e0:  94 10 20 20  mov  0x20, %o2
a00ae1e4:  7f ff e2 ad  call  0xa00a6c98
a00ae1e8:  96 10 20 00  clr  %o3
a00ae1ec:  90 10 00 18  mov  %i0, %o0
a00ae1f0:  92 10 20 30  mov  0x30, %o1
a00ae1f4:  94 10 20 40  mov  0x40, %o2
a00ae1f8:  7f ff e2 a8  call  0xa00a6c98
a00ae1fc:  96 10 20 01  mov  1, %o3
a00ae200:  03 00 00 22  sethi  %hi(0x8800), %g1
a00ae204:  98 10 60 b7  or  %g1, 0xb7, %o4	! 0x88b7
a00ae208:  9a 10 20 00  clr  %o5
a00ae20c:  01 00 00 00  nop
a00ae210:  9a 03 60 01  inc  %o5
a00ae214:  83 2b 60 10  sll  %o5, 0x10, %g1
a00ae218:  83 30 60 10  srl  %g1, 0x10, %g1
a00ae21c:  80 a0 40 0c  cmp  %g1, %o4
a00ae220:  08 bf ff fb  bleu  0xa00ae20c
a00ae224:  01 00 00 00  nop
a00ae228:  b4 0e a0 ff  and  %i2, 0xff, %i2
a00ae22c:  7f ff e2 75  call  0xa00a6c00
a00ae230:  93 e8 20 00  restore  %g0, 0, %o1
a00ae234:  01 00 00 00  nop
