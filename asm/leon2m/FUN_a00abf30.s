# leon2m FUN_a00abf30 0xa00abf30-0xa00abff8 (200 bytes)
a00abf30:  9d e3 bf 98  save  %sp, -104, %sp
a00abf34:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00abf38:  a0 12 a2 90  or  %o2, 0x290, %l0	! 0xa802d290
a00abf3c:  da 0c 20 12  ldub  [ %l0 + 0x12 ], %o5
a00abf40:  9a 03 7f ff  add  %o5, -1, %o5
a00abf44:  82 0b 60 ff  and  %o5, 0xff, %g1
a00abf48:  90 10 20 2c  mov  0x2c, %o0
a00abf4c:  92 10 20 06  mov  6, %o1
a00abf50:  96 10 20 07  mov  7, %o3
a00abf54:  98 10 20 01  mov  1, %o4
a00abf58:  80 a0 60 64  cmp  %g1, 0x64
a00abf5c:  08 80 00 04  bleu  0xa00abf6c
a00abf60:  94 10 00 01  mov  %g1, %o2
a00abf64:  10 80 00 1f  b  0xa00abfe0
a00abf68:  c0 2c 20 12  clrb  [ %l0 + 0x12 ]
a00abf6c:  7f ff fd a1  call  0xa00ab5f0
a00abf70:  da 2c 20 12  stb  %o5, [ %l0 + 0x12 ]
a00abf74:  90 10 20 28  mov  0x28, %o0
a00abf78:  92 10 20 06  mov  6, %o1
a00abf7c:  94 10 20 03  mov  3, %o2
a00abf80:  96 10 27 42  mov  0x742, %o3
a00abf84:  40 02 6a bf  call  0xa0146a80
a00abf88:  98 10 20 00  clr  %o4
a00abf8c:  90 10 20 2b  mov  0x2b, %o0
a00abf90:  92 10 20 06  mov  6, %o1
a00abf94:  94 10 20 01  mov  1, %o2
a00abf98:  96 10 27 42  mov  0x742, %o3
a00abf9c:  40 02 6a b9  call  0xa0146a80
a00abfa0:  98 10 20 00  clr  %o4
a00abfa4:  94 10 20 01  mov  1, %o2
a00abfa8:  96 10 27 42  mov  0x742, %o3
a00abfac:  98 10 20 00  clr  %o4
a00abfb0:  90 10 20 32  mov  0x32, %o0
a00abfb4:  40 02 6a b3  call  0xa0146a80
a00abfb8:  92 10 20 06  mov  6, %o1
a00abfbc:  90 10 20 e6  mov  0xe6, %o0
a00abfc0:  40 02 6a e4  call  0xa0146b50
a00abfc4:  92 10 20 00  clr  %o1
a00abfc8:  d4 0c 20 12  ldub  [ %l0 + 0x12 ], %o2
a00abfcc:  90 10 20 29  mov  0x29, %o0
a00abfd0:  40 00 2b be  call  0xa00b6ec8
a00abfd4:  92 10 20 06  mov  6, %o1
a00abfd8:  40 00 a1 88  call  0xa00d45f8
a00abfdc:  01 00 00 00  nop
a00abfe0:  11 2a 00 ac  sethi  %hi(0xa802b000), %o0
a00abfe4:  d6 0a 20 8e  ldub  [ %o0 + 0x8e ], %o3	! 0xa802b08e
a00abfe8:  92 12 e0 02  or  %o3, 2, %o1
a00abfec:  d2 2a 20 8e  stb  %o1, [ %o0 + 0x8e ]
a00abff0:  81 c7 e0 08  ret
a00abff4:  81 e8 00 00  restore
