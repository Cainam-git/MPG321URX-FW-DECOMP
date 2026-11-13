# leon2m FUN_a012be4c 0xa012be4c-0xa012c004 (92 bytes)
a012be4c:  9d e3 bf 90  save  %sp, -112, %sp
a012be50:  90 0e 60 ff  and  %i1, 0xff, %o0
a012be54:  82 02 3f dc  add  %o0, -36, %g1
a012be58:  80 a0 60 37  cmp  %g1, 0x37
a012be5c:  18 80 00 19  bgu  0xa012bec0
a012be60:  c0 27 bf f0  clr  [ %fp + -16 ]
a012be64:  13 00 03 2e  sethi  %hi(0xcb800), %o1
a012be68:  83 28 60 02  sll  %g1, 2, %g1
a012be6c:  9a 12 60 c0  or  %o1, 0xc0, %o5
a012be70:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a012be74:  81 c3 00 00  jmp  %o4
a012be78:  01 00 00 00  nop
a012be7c:  82 0e 20 ff  and  %i0, 0xff, %g1
a012be80:  b3 28 60 03  sll  %g1, 3, %i1
a012be84:  19 2a 00 b6  sethi  %hi(0xa802d800), %o4
a012be88:  9e 06 40 01  add  %i1, %g1, %o7
a012be8c:  94 13 20 dc  or  %o4, 0xdc, %o2
a012be90:  97 2b e0 02  sll  %o7, 2, %o3
a012be94:  d8 02 80 0b  ld  [ %o2 + %o3 ], %o4
a012be98:  9b 33 20 1f  srl  %o4, 0x1f, %o5
a012be9c:  92 0e a0 01  and  %i2, 1, %o1
a012bea0:  80 a3 40 09  cmp  %o5, %o1
a012bea4:  02 80 00 07  be  0xa012bec0
a012bea8:  1f 20 00 00  sethi  %hi(0x80000000), %o7
a012beac:  92 2b 00 0f  andn  %o4, %o7, %o1
a012beb0:  9b 2e a0 1f  sll  %i2, 0x1f, %o5
a012beb4:  b6 12 40 0d  or  %o1, %o5, %i3
a012beb8:  f6 22 80 0b  st  %i3, [ %o2 + %o3 ]
a012bebc:  b6 10 20 01  mov  1, %i3
a012bec0:  80 8e e0 ff  btst  0xff, %i3
a012bec4:  02 80 00 4e  be  0xa012bffc
a012bec8:  92 10 20 04  mov  4, %o1
a012becc:  f0 2f bf f0  stb  %i0, [ %fp + -16 ]
a012bed0:  f4 2f bf f1  stb  %i2, [ %fp + -15 ]
a012bed4:  94 07 bf f0  add  %fp, -16, %o2
a012bed8:  40 00 2c 81  call  0xa01370dc
a012bedc:  96 10 20 00  clr  %o3
a012bee0:  30 80 00 47  b,a   0xa012bffc
a012bee4:  9a 0e 20 ff  and  %i0, 0xff, %o5
a012bee8:  93 2b 60 03  sll  %o5, 3, %o1
a012beec:  98 02 40 0d  add  %o1, %o5, %o4
a012bef0:  17 2a 00 b6  sethi  %hi(0xa802d800), %o3
a012bef4:  96 12 e0 dc  or  %o3, 0xdc, %o3	! 0xa802d8dc
a012bef8:  99 2b 20 02  sll  %o4, 2, %o4
a012befc:  d4 02 c0 0c  ld  [ %o3 + %o4 ], %o2
a012bf00:  b2 0e a0 01  and  %i2, 1, %i1
a012bf04:  03 00 80 00  sethi  %hi(0x2000000), %g1
a012bf08:  82 2a 80 01  andn  %o2, %g1, %g1
a012bf0c:  9b 2e 60 19  sll  %i1, 0x19, %o5
a012bf10:  9e 10 40 0d  or  %g1, %o5, %o7
a012bf14:  10 bf ff eb  b  0xa012bec0
a012bf18:  de 22 c0 0c  st  %o7, [ %o3 + %o4 ]
a012bf1c:  96 0e 20 ff  and  %i0, 0xff, %o3
a012bf20:  95 2a e0 03  sll  %o3, 3, %o2
a012bf24:  b2 02 80 0b  add  %o2, %o3, %i1
a012bf28:  03 2a 00 b6  sethi  %hi(0xa802d800), %g1
a012bf2c:  96 10 60 dc  or  %g1, 0xdc, %o3	! 0xa802d8dc
a012bf30:  99 2e 60 02  sll  %i1, 2, %o4
a012bf34:  de 02 c0 0c  ld  [ %o3 + %o4 ], %o7
a012bf38:  9a 0e a0 01  and  %i2, 1, %o5
a012bf3c:  13 08 00 00  sethi  %hi(0x20000000), %o1
a012bf40:  82 2b c0 09  andn  %o7, %o1, %g1
a012bf44:  9b 2b 60 1d  sll  %o5, 0x1d, %o5
a012bf48:  9e 10 40 0d  or  %g1, %o5, %o7
a012bf4c:  10 bf ff dd  b  0xa012bec0
a012bf50:  de 22 c0 0c  st  %o7, [ %o3 + %o4 ]
a012bf54:  82 0e 20 ff  and  %i0, 0xff, %g1
a012bf58:  9b 28 60 03  sll  %g1, 3, %o5
a012bf5c:  98 03 40 01  add  %o5, %g1, %o4
a012bf60:  17 2a 00 b6  sethi  %hi(0xa802d800), %o3
a012bf64:  96 12 e0 dc  or  %o3, 0xdc, %o3	! 0xa802d8dc
a012bf68:  99 2b 20 02  sll  %o4, 2, %o4
a012bf6c:  d4 02 c0 0c  ld  [ %o3 + %o4 ], %o2
a012bf70:  9e 0e a0 01  and  %i2, 1, %o7
a012bf74:  33 02 00 00  sethi  %hi(0x8000000), %i1
a012bf78:  82 2a 80 19  andn  %o2, %i1, %g1
a012bf7c:  9b 2b e0 1b  sll  %o7, 0x1b, %o5
a012bf80:  9e 10 40 0d  or  %g1, %o5, %o7
a012bf84:  10 bf ff cf  b  0xa012bec0
a012bf88:  de 22 c0 0c  st  %o7, [ %o3 + %o4 ]
a012bf8c:  9a 0e 20 ff  and  %i0, 0xff, %o5
a012bf90:  99 2b 60 03  sll  %o5, 3, %o4
a012bf94:  94 03 00 0d  add  %o4, %o5, %o2
a012bf98:  17 2a 00 b6  sethi  %hi(0xa802d800), %o3
a012bf9c:  96 12 e0 dc  or  %o3, 0xdc, %o3	! 0xa802d8dc
a012bfa0:  99 2a a0 02  sll  %o2, 2, %o4
a012bfa4:  f2 02 c0 0c  ld  [ %o3 + %o4 ], %i1
a012bfa8:  1f 04 00 00  sethi  %hi(0x10000000), %o7
a012bfac:  92 0e a0 01  and  %i2, 1, %o1
a012bfb0:  82 2e 40 0f  andn  %i1, %o7, %g1
a012bfb4:  9b 2a 60 1c  sll  %o1, 0x1c, %o5
a012bfb8:  9e 10 40 0d  or  %g1, %o5, %o7
a012bfbc:  10 bf ff c1  b  0xa012bec0
a012bfc0:  de 22 c0 0c  st  %o7, [ %o3 + %o4 ]
a012bfc4:  98 0e 20 ff  and  %i0, 0xff, %o4
a012bfc8:  97 2b 20 03  sll  %o4, 3, %o3
a012bfcc:  b2 02 c0 0c  add  %o3, %o4, %i1
a012bfd0:  15 2a 00 b6  sethi  %hi(0xa802d800), %o2
a012bfd4:  96 12 a0 dc  or  %o2, 0xdc, %o3	! 0xa802d8dc
a012bfd8:  99 2e 60 02  sll  %i1, 2, %o4
a012bfdc:  de 02 c0 0c  ld  [ %o3 + %o4 ], %o7
a012bfe0:  92 0e a0 01  and  %i2, 1, %o1
a012bfe4:  03 10 00 00  sethi  %hi(0x40000000), %g1
a012bfe8:  82 2b c0 01  andn  %o7, %g1, %g1
a012bfec:  9b 2a 60 1e  sll  %o1, 0x1e, %o5
a012bff0:  9e 10 40 0d  or  %g1, %o5, %o7
a012bff4:  10 bf ff b3  b  0xa012bec0
a012bff8:  de 22 c0 0c  st  %o7, [ %o3 + %o4 ]
a012bffc:  81 c7 e0 08  ret
a012c000:  81 e8 00 00  restore
