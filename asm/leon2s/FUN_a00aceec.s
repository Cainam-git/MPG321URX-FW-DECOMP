# leon2s FUN_a00aceec 0xa00aceec-0xa00acff4 (264 bytes)
a00aceec:  9d e3 bf 98  save  %sp, -104, %sp
a00acef0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00acef4:  92 10 20 63  mov  0x63, %o1
a00acef8:  7f ff e8 04  call  0xa00a6f08
a00acefc:  90 10 00 18  mov  %i0, %o0
a00acf00:  a2 10 00 08  mov  %o0, %l1
a00acf04:  92 10 20 68  mov  0x68, %o1
a00acf08:  7f ff e7 2c  call  0xa00a6bb8
a00acf0c:  90 10 00 18  mov  %i0, %o0
a00acf10:  a0 0a 20 ff  and  %o0, 0xff, %l0
a00acf14:  92 10 20 67  mov  0x67, %o1
a00acf18:  7f ff e7 28  call  0xa00a6bb8
a00acf1c:  90 10 00 18  mov  %i0, %o0
a00acf20:  90 0a 20 ff  and  %o0, 0xff, %o0
a00acf24:  a1 2c 20 08  sll  %l0, 8, %l0
a00acf28:  a0 14 00 08  or  %l0, %o0, %l0
a00acf2c:  90 10 00 18  mov  %i0, %o0
a00acf30:  7f ff e7 22  call  0xa00a6bb8
a00acf34:  92 10 20 66  mov  0x66, %o1
a00acf38:  80 a0 00 11  cmp  %g0, %l1
a00acf3c:  a1 2c 20 08  sll  %l0, 8, %l0
a00acf40:  90 0a 20 ff  and  %o0, 0xff, %o0
a00acf44:  9a 60 3f ff  subx  %g0, -1, %o5
a00acf48:  a0 14 00 08  or  %l0, %o0, %l0
a00acf4c:  80 a0 00 10  cmp  %g0, %l0
a00acf50:  82 60 3f ff  subx  %g0, -1, %g1
a00acf54:  80 93 40 01  orcc  %o5, %g1, %g0
a00acf58:  a4 10 20 00  clr  %l2
a00acf5c:  12 80 00 24  bne  0xa00acfec
a00acf60:  82 10 20 00  clr  %g1
a00acf64:  90 10 00 18  mov  %i0, %o0
a00acf68:  7f ff e7 14  call  0xa00a6bb8
a00acf6c:  92 10 20 80  mov  0x80, %o1
a00acf70:  90 0a 20 03  and  %o0, 3, %o0
a00acf74:  80 a2 20 01  cmp  %o0, 1
a00acf78:  02 80 00 12  be  0xa00acfc0
a00acf7c:  9a 5c 61 0e  smul  %l1, 0x10e, %o5
a00acf80:  14 80 00 07  bg  0xa00acf9c
a00acf84:  80 a2 20 02  cmp  %o0, 2
a00acf88:  80 a2 20 00  cmp  %o0, 0
a00acf8c:  02 80 00 0d  be  0xa00acfc0
a00acf90:  9a 5c 60 a2  smul  %l1, 0xa2, %o5
a00acf94:  10 80 00 15  b  0xa00acfe8
a00acf98:  83 2c a0 10  sll  %l2, 0x10, %g1
a00acf9c:  02 80 00 06  be  0xa00acfb4
a00acfa0:  80 a2 20 03  cmp  %o0, 3
a00acfa4:  02 80 00 06  be  0xa00acfbc
a00acfa8:  83 2c a0 10  sll  %l2, 0x10, %g1
a00acfac:  10 80 00 10  b  0xa00acfec
a00acfb0:  83 30 60 10  srl  %g1, 0x10, %g1
a00acfb4:  10 80 00 03  b  0xa00acfc0
a00acfb8:  9a 5c 62 1c  smul  %l1, 0x21c, %o5
a00acfbc:  9a 5c 63 2a  smul  %l1, 0x32a, %o5
a00acfc0:  03 00 00 09  sethi  %hi(0x2400), %g1
a00acfc4:  81 80 00 00  mov  %g0, %y
a00acfc8:  01 00 00 00  nop
a00acfcc:  01 00 00 00  nop
a00acfd0:  01 00 00 00  nop
a00acfd4:  9a 73 40 10  udiv  %o5, %l0, %o5
a00acfd8:  82 10 63 10  or  %g1, 0x310, %g1
a00acfdc:  9a 5b 40 01  smul  %o5, %g1, %o5
a00acfe0:  a5 33 60 09  srl  %o5, 9, %l2
a00acfe4:  83 2c a0 10  sll  %l2, 0x10, %g1
a00acfe8:  83 30 60 10  srl  %g1, 0x10, %g1
a00acfec:  81 c7 e0 08  ret
a00acff0:  91 e8 00 01  restore  %g0, %g1, %o0
