# leon2s FUN_a00abe20 0xa00abe20-0xa00abff0 (464 bytes)
a00abe20:  9d e3 bf 98  save  %sp, -104, %sp
a00abe24:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00abe28:  90 10 00 18  mov  %i0, %o0
a00abe2c:  92 10 20 30  mov  0x30, %o1
a00abe30:  94 10 20 80  mov  0x80, %o2
a00abe34:  7f ff eb 99  call  0xa00a6c98
a00abe38:  96 10 20 01  mov  1, %o3
a00abe3c:  37 2a 01 f7  sethi  %hi(0xa807dc00), %i3
a00abe40:  82 16 e0 18  or  %i3, 0x18, %g1	! 0xa807dc18
a00abe44:  9a 5e 21 2c  smul  %i0, 0x12c, %o5
a00abe48:  9a 03 40 01  add  %o5, %g1, %o5
a00abe4c:  c2 0b 61 17  ldub  [ %o5 + 0x117 ], %g1
a00abe50:  82 00 7f ff  add  %g1, -1, %g1
a00abe54:  82 08 60 ff  and  %g1, 0xff, %g1
a00abe58:  90 10 00 18  mov  %i0, %o0
a00abe5c:  92 10 22 00  mov  0x200, %o1
a00abe60:  80 a0 60 01  cmp  %g1, 1
a00abe64:  08 80 00 05  bleu  0xa00abe78
a00abe68:  94 10 20 12  mov  0x12, %o2
a00abe6c:  90 10 00 18  mov  %i0, %o0
a00abe70:  92 10 22 00  mov  0x200, %o1
a00abe74:  94 10 20 11  mov  0x11, %o2
a00abe78:  7f ff eb 62  call  0xa00a6c00
a00abe7c:  01 00 00 00  nop
a00abe80:  82 16 e0 18  or  %i3, 0x18, %g1
a00abe84:  9a 5e 21 2c  smul  %i0, 0x12c, %o5
a00abe88:  9a 03 40 01  add  %o5, %g1, %o5
a00abe8c:  da 0b 61 10  ldub  [ %o5 + 0x110 ], %o5
a00abe90:  82 03 7f fe  add  %o5, -2, %g1
a00abe94:  82 08 60 ff  and  %g1, 0xff, %g1
a00abe98:  90 10 00 18  mov  %i0, %o0
a00abe9c:  92 10 22 01  mov  0x201, %o1
a00abea0:  80 a0 60 01  cmp  %g1, 1
a00abea4:  08 80 00 0a  bleu  0xa00abecc
a00abea8:  94 10 20 14  mov  0x14, %o2
a00abeac:  90 10 00 18  mov  %i0, %o0
a00abeb0:  92 10 22 01  mov  0x201, %o1
a00abeb4:  80 a3 60 01  cmp  %o5, 1
a00abeb8:  02 80 00 05  be  0xa00abecc
a00abebc:  94 10 20 0a  mov  0xa, %o2
a00abec0:  90 10 00 18  mov  %i0, %o0
a00abec4:  92 10 22 01  mov  0x201, %o1
a00abec8:  94 10 20 06  mov  6, %o2
a00abecc:  7f ff eb 4d  call  0xa00a6c00
a00abed0:  01 00 00 00  nop
a00abed4:  9a 16 e0 18  or  %i3, 0x18, %o5
a00abed8:  82 5e 21 2c  smul  %i0, 0x12c, %g1
a00abedc:  82 00 40 0d  add  %g1, %o5, %g1
a00abee0:  c2 08 61 11  ldub  [ %g1 + 0x111 ], %g1
a00abee4:  90 10 00 18  mov  %i0, %o0
a00abee8:  92 10 22 02  mov  0x202, %o1
a00abeec:  80 a0 60 02  cmp  %g1, 2
a00abef0:  02 80 00 0a  be  0xa00abf18
a00abef4:  94 10 20 84  mov  0x84, %o2
a00abef8:  90 10 00 18  mov  %i0, %o0
a00abefc:  92 10 22 02  mov  0x202, %o1
a00abf00:  80 a0 60 01  cmp  %g1, 1
a00abf04:  02 80 00 05  be  0xa00abf18
a00abf08:  94 10 20 82  mov  0x82, %o2
a00abf0c:  90 10 00 18  mov  %i0, %o0
a00abf10:  92 10 22 02  mov  0x202, %o1
a00abf14:  94 10 20 81  mov  0x81, %o2
a00abf18:  7f ff eb 3a  call  0xa00a6c00
a00abf1c:  01 00 00 00  nop
a00abf20:  82 16 e0 18  or  %i3, 0x18, %g1
a00abf24:  9a 5e 21 2c  smul  %i0, 0x12c, %o5
a00abf28:  9a 03 40 01  add  %o5, %g1, %o5
a00abf2c:  c2 0b 61 17  ldub  [ %o5 + 0x117 ], %g1
a00abf30:  80 a0 60 00  cmp  %g1, 0
a00abf34:  12 80 00 06  bne  0xa00abf4c
a00abf38:  90 10 00 18  mov  %i0, %o0
a00abf3c:  92 10 22 02  mov  0x202, %o1
a00abf40:  94 10 20 40  mov  0x40, %o2
a00abf44:  10 80 00 05  b  0xa00abf58
a00abf48:  96 10 20 00  clr  %o3
a00abf4c:  92 10 22 02  mov  0x202, %o1
a00abf50:  94 10 20 40  mov  0x40, %o2
a00abf54:  96 10 20 01  mov  1, %o3
a00abf58:  7f ff eb 50  call  0xa00a6c98
a00abf5c:  01 00 00 00  nop
a00abf60:  82 16 e0 18  or  %i3, 0x18, %g1
a00abf64:  9a 5e 21 2c  smul  %i0, 0x12c, %o5
a00abf68:  9a 03 40 01  add  %o5, %g1, %o5
a00abf6c:  c2 0b 61 10  ldub  [ %o5 + 0x110 ], %g1
a00abf70:  90 10 00 18  mov  %i0, %o0
a00abf74:  92 10 22 03  mov  0x203, %o1
a00abf78:  80 a0 60 03  cmp  %g1, 3
a00abf7c:  02 80 00 05  be  0xa00abf90
a00abf80:  94 10 20 81  mov  0x81, %o2
a00abf84:  90 10 00 18  mov  %i0, %o0
a00abf88:  92 10 22 03  mov  0x203, %o1
a00abf8c:  94 10 20 01  mov  1, %o2
a00abf90:  7f ff eb 1c  call  0xa00a6c00
a00abf94:  01 00 00 00  nop
a00abf98:  82 16 e0 18  or  %i3, 0x18, %g1
a00abf9c:  9a 5e 21 2c  smul  %i0, 0x12c, %o5
a00abfa0:  9a 03 40 01  add  %o5, %g1, %o5
a00abfa4:  c2 0b 61 17  ldub  [ %o5 + 0x117 ], %g1
a00abfa8:  80 a0 60 02  cmp  %g1, 2
a00abfac:  12 80 00 09  bne  0xa00abfd0
a00abfb0:  90 10 00 18  mov  %i0, %o0
a00abfb4:  92 10 22 66  mov  0x266, %o1
a00abfb8:  7f ff eb 12  call  0xa00a6c00
a00abfbc:  94 10 20 83  mov  0x83, %o2
a00abfc0:  7f ff ff 01  call  0xa00abbc4
a00abfc4:  90 10 00 18  mov  %i0, %o0
a00abfc8:  10 80 00 06  b  0xa00abfe0
a00abfcc:  b2 10 20 30  mov  0x30, %i1
a00abfd0:  92 10 22 66  mov  0x266, %o1
a00abfd4:  7f ff eb 0b  call  0xa00a6c00
a00abfd8:  94 10 20 00  clr  %o2
a00abfdc:  b2 10 20 30  mov  0x30, %i1
a00abfe0:  b4 10 20 80  mov  0x80, %i2
a00abfe4:  7f ff eb 2d  call  0xa00a6c98
a00abfe8:  97 e8 20 00  restore  %g0, 0, %o3
a00abfec:  01 00 00 00  nop
