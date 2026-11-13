# leon2m FUN_a00bfcc4 0xa00bfcc4-0xa00c0adc (48 bytes)
a00bfcc4:  9d e3 bf 98  save  %sp, -104, %sp
a00bfcc8:  82 0e 60 ff  and  %i1, 0xff, %g1
a00bfccc:  80 a0 60 82  cmp  %g1, 0x82
a00bfcd0:  18 80 03 81  bgu  0xa00c0ad4
a00bfcd4:  11 00 01 69  sethi  %hi(0x5a400), %o0
a00bfcd8:  83 28 60 02  sll  %g1, 2, %g1
a00bfcdc:  9a 12 20 28  or  %o0, 0x28, %o5
a00bfce0:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a00bfce4:  81 c3 00 00  jmp  %o4
a00bfce8:  01 00 00 00  nop
a00bfcec:  17 2a 00 b5  sethi  %hi(0xa802d400), %o3
a00bfcf0:  d4 0a e0 7e  ldub  [ %o3 + 0x7e ], %o2	! 0xa802d47e
a00bfcf4:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00bfcf8:  92 13 e0 78  or  %o7, 0x78, %o1	! 0xa802d078
a00bfcfc:  b4 10 20 30  mov  0x30, %i2
a00bfd00:  82 02 a0 30  add  %o2, 0x30, %g1
a00bfd04:  c2 2a 60 09  stb  %g1, [ %o1 + 9 ]
a00bfd08:  f4 2a 60 08  stb  %i2, [ %o1 + 8 ]
a00bfd0c:  f4 2a 60 07  stb  %i2, [ %o1 + 7 ]
a00bfd10:  90 10 20 82  mov  0x82, %o0
a00bfd14:  7f ff eb ca  call  0xa00bac3c
a00bfd18:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bfd1c:  7f ff eb 0d  call  0xa00ba950
a00bfd20:  90 10 00 18  mov  %i0, %o0
a00bfd24:  7f ff eb b0  call  0xa00babe4
a00bfd28:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bfd2c:  11 2a 00 b5  sethi  %hi(0xa802d400), %o0
a00bfd30:  f2 0a 20 7d  ldub  [ %o0 + 0x7d ], %i1	! 0xa802d47d
a00bfd34:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00bfd38:  9e 13 60 78  or  %o5, 0x78, %o7	! 0xa802d078
a00bfd3c:  96 10 20 30  mov  0x30, %o3
a00bfd40:  98 06 60 2f  add  %i1, 0x2f, %o4
a00bfd44:  d8 2b e0 09  stb  %o4, [ %o7 + 9 ]
a00bfd48:  d6 2b e0 08  stb  %o3, [ %o7 + 8 ]
a00bfd4c:  d6 2b e0 07  stb  %o3, [ %o7 + 7 ]
a00bfd50:  10 bf ff f1  b  0xa00bfd14
a00bfd54:  90 10 20 81  mov  0x81, %o0
a00bfd58:  15 2a 00 b5  sethi  %hi(0xa802d400), %o2
a00bfd5c:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00bfd60:  b2 10 60 78  or  %g1, 0x78, %i1	! 0xa802d078
a00bfd64:  90 10 20 30  mov  0x30, %o0
a00bfd68:  f4 0a a0 7c  ldub  [ %o2 + 0x7c ], %i2
a00bfd6c:  92 06 a0 30  add  %i2, 0x30, %o1
a00bfd70:  d0 2e 60 08  stb  %o0, [ %i1 + 8 ]
a00bfd74:  d0 2e 60 07  stb  %o0, [ %i1 + 7 ]
a00bfd78:  d2 2e 60 09  stb  %o1, [ %i1 + 9 ]
a00bfd7c:  10 bf ff e6  b  0xa00bfd14
a00bfd80:  90 10 20 80  mov  0x80, %o0
a00bfd84:  17 2a 00 b5  sethi  %hi(0xa802d400), %o3
a00bfd88:  de 0a e0 7b  ldub  [ %o3 + 0x7b ], %o7	! 0xa802d47b
a00bfd8c:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00bfd90:  b4 13 60 78  or  %o5, 0x78, %i2	! 0xa802d078
a00bfd94:  94 10 20 30  mov  0x30, %o2
a00bfd98:  98 03 e0 2f  add  %o7, 0x2f, %o4
a00bfd9c:  d8 2e a0 09  stb  %o4, [ %i2 + 9 ]
a00bfda0:  d4 2e a0 08  stb  %o2, [ %i2 + 8 ]
a00bfda4:  d4 2e a0 07  stb  %o2, [ %i2 + 7 ]
a00bfda8:  10 bf ff db  b  0xa00bfd14
a00bfdac:  90 10 20 7f  mov  0x7f, %o0
a00bfdb0:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a00bfdb4:  d0 08 60 7a  ldub  [ %g1 + 0x7a ], %o0	! 0xa802d47a
a00bfdb8:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00bfdbc:  9e 12 60 78  or  %o1, 0x78, %o7	! 0xa802d078
a00bfdc0:  b2 02 20 30  add  %o0, 0x30, %i1
a00bfdc4:  96 10 20 30  mov  0x30, %o3
a00bfdc8:  f2 2b e0 09  stb  %i1, [ %o7 + 9 ]
a00bfdcc:  d6 2b e0 08  stb  %o3, [ %o7 + 8 ]
a00bfdd0:  d6 2b e0 07  stb  %o3, [ %o7 + 7 ]
a00bfdd4:  10 bf ff d0  b  0xa00bfd14
a00bfdd8:  90 10 20 7e  mov  0x7e, %o0
a00bfddc:  15 2a 00 b5  sethi  %hi(0xa802d400), %o2
a00bfde0:  f4 0a a0 79  ldub  [ %o2 + 0x79 ], %i2	! 0xa802d479
a00bfde4:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00bfde8:  92 13 60 78  or  %o5, 0x78, %o1	! 0xa802d078
a00bfdec:  82 10 20 30  mov  0x30, %g1
a00bfdf0:  98 06 a0 2f  add  %i2, 0x2f, %o4
a00bfdf4:  d8 2a 60 09  stb  %o4, [ %o1 + 9 ]
a00bfdf8:  c2 2a 60 08  stb  %g1, [ %o1 + 8 ]
a00bfdfc:  c2 2a 60 07  stb  %g1, [ %o1 + 7 ]
a00bfe00:  10 bf ff c5  b  0xa00bfd14
a00bfe04:  90 10 20 7d  mov  0x7d, %o0
a00bfe08:  11 2a 00 b5  sethi  %hi(0xa802d400), %o0
a00bfe0c:  d6 0a 20 78  ldub  [ %o0 + 0x78 ], %o3	! 0xa802d478
a00bfe10:  33 2a 00 b4  sethi  %hi(0xa802d000), %i1
a00bfe14:  b4 16 60 78  or  %i1, 0x78, %i2	! 0xa802d078
a00bfe18:  94 10 20 30  mov  0x30, %o2
a00bfe1c:  9e 02 e0 30  add  %o3, 0x30, %o7
a00bfe20:  de 2e a0 09  stb  %o7, [ %i2 + 9 ]
a00bfe24:  d4 2e a0 08  stb  %o2, [ %i2 + 8 ]
a00bfe28:  d4 2e a0 07  stb  %o2, [ %i2 + 7 ]
a00bfe2c:  10 bf ff ba  b  0xa00bfd14
a00bfe30:  90 10 20 7c  mov  0x7c, %o0
a00bfe34:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bfe38:  7f ff fa 79  call  0xa00be81c
a00bfe3c:  81 e8 00 00  restore
a00bfe40:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00bfe44:  98 13 60 78  or  %o5, 0x78, %o4	! 0xa802d078
a00bfe48:  92 10 20 30  mov  0x30, %o1
a00bfe4c:  d2 2b 20 09  stb  %o1, [ %o4 + 9 ]
a00bfe50:  d2 2b 20 07  stb  %o1, [ %o4 + 7 ]
a00bfe54:  d2 2b 20 08  stb  %o1, [ %o4 + 8 ]
a00bfe58:  10 bf ff af  b  0xa00bfd14
a00bfe5c:  90 10 20 77  mov  0x77, %o0
a00bfe60:  35 2a 00 b5  sethi  %hi(0xa802d400), %i2
a00bfe64:  d2 0e a0 6f  ldub  [ %i2 + 0x6f ], %o1	! 0xa802d46f
a00bfe68:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00bfe6c:  90 13 60 78  or  %o5, 0x78, %o0	! 0xa802d078
a00bfe70:  82 10 20 30  mov  0x30, %g1
a00bfe74:  98 02 60 30  add  %o1, 0x30, %o4
a00bfe78:  d8 2a 20 09  stb  %o4, [ %o0 + 9 ]
a00bfe7c:  c2 2a 20 08  stb  %g1, [ %o0 + 8 ]
a00bfe80:  c2 2a 20 07  stb  %g1, [ %o0 + 7 ]
a00bfe84:  10 bf ff a4  b  0xa00bfd14
a00bfe88:  90 10 20 76  mov  0x76, %o0
a00bfe8c:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a00bfe90:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00bfe94:  f2 08 60 71  ldub  [ %g1 + 0x71 ], %i1
a00bfe98:  94 12 20 78  or  %o0, 0x78, %o2
a00bfe9c:  9e 10 20 30  mov  0x30, %o7
a00bfea0:  96 06 60 30  add  %i1, 0x30, %o3
a00bfea4:  d6 2a a0 09  stb  %o3, [ %o2 + 9 ]
a00bfea8:  de 2a a0 08  stb  %o7, [ %o2 + 8 ]
a00bfeac:  de 2a a0 07  stb  %o7, [ %o2 + 7 ]
a00bfeb0:  10 bf ff 99  b  0xa00bfd14
a00bfeb4:  90 10 20 75  mov  0x75, %o0
a00bfeb8:  33 2a 00 b5  sethi  %hi(0xa802d400), %i1
a00bfebc:  de 0e 60 70  ldub  [ %i1 + 0x70 ], %o7	! 0xa802d470
a00bfec0:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00bfec4:  92 12 e0 78  or  %o3, 0x78, %o1	! 0xa802d078
a00bfec8:  b4 10 20 30  mov  0x30, %i2
a00bfecc:  94 03 e0 30  add  %o7, 0x30, %o2
a00bfed0:  d4 2a 60 09  stb  %o2, [ %o1 + 9 ]
a00bfed4:  f4 2a 60 08  stb  %i2, [ %o1 + 8 ]
a00bfed8:  f4 2a 60 07  stb  %i2, [ %o1 + 7 ]
a00bfedc:  10 bf ff 8e  b  0xa00bfd14
a00bfee0:  90 10 20 74  mov  0x74, %o0
a00bfee4:  1b 2a 00 b5  sethi  %hi(0xa802d400), %o5
a00bfee8:  d8 03 60 6c  ld  [ %o5 + 0x6c ], %o4	! 0xa802d46c
a00bfeec:  83 33 20 0f  srl  %o4, 0xf, %g1
a00bfef0:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00bfef4:  b2 08 60 01  and  %g1, 1, %i1
a00bfef8:  94 12 20 78  or  %o0, 0x78, %o2
a00bfefc:  9e 10 20 30  mov  0x30, %o7
a00bff00:  96 06 60 30  add  %i1, 0x30, %o3
a00bff04:  d6 2a a0 09  stb  %o3, [ %o2 + 9 ]
a00bff08:  de 2a a0 08  stb  %o7, [ %o2 + 8 ]
a00bff0c:  de 2a a0 07  stb  %o7, [ %o2 + 7 ]
a00bff10:  10 bf ff 81  b  0xa00bfd14
a00bff14:  90 10 20 73  mov  0x73, %o0
a00bff18:  35 2a 00 b5  sethi  %hi(0xa802d400), %i2
a00bff1c:  d2 06 a0 6c  ld  [ %i2 + 0x6c ], %o1	! 0xa802d46c
a00bff20:  9b 32 60 1e  srl  %o1, 0x1e, %o5
a00bff24:  90 0b 60 01  and  %o5, 1, %o0
a00bff28:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00bff2c:  96 13 20 78  or  %o4, 0x78, %o3	! 0xa802d078
a00bff30:  82 02 20 30  add  %o0, 0x30, %g1
a00bff34:  b2 10 20 30  mov  0x30, %i1
a00bff38:  c2 2a e0 09  stb  %g1, [ %o3 + 9 ]
a00bff3c:  f2 2a e0 08  stb  %i1, [ %o3 + 8 ]
a00bff40:  f2 2a e0 07  stb  %i1, [ %o3 + 7 ]
a00bff44:  10 bf ff 74  b  0xa00bfd14
a00bff48:  90 10 20 72  mov  0x72, %o0
a00bff4c:  1f 2a 00 b5  sethi  %hi(0xa802d400), %o7
a00bff50:  d4 03 e0 6c  ld  [ %o7 + 0x6c ], %o2	! 0xa802d46c
a00bff54:  93 32 a0 1f  srl  %o2, 0x1f, %o1
a00bff58:  35 2a 00 b4  sethi  %hi(0xa802d000), %i2
a00bff5c:  90 16 a0 78  or  %i2, 0x78, %o0	! 0xa802d078
a00bff60:  98 10 20 30  mov  0x30, %o4
a00bff64:  9a 02 60 30  add  %o1, 0x30, %o5
a00bff68:  da 2a 20 09  stb  %o5, [ %o0 + 9 ]
a00bff6c:  d8 2a 20 08  stb  %o4, [ %o0 + 8 ]
a00bff70:  d8 2a 20 07  stb  %o4, [ %o0 + 7 ]
a00bff74:  10 bf ff 68  b  0xa00bfd14
a00bff78:  90 10 20 71  mov  0x71, %o0
a00bff7c:  33 2a 00 b5  sethi  %hi(0xa802d400), %i1
a00bff80:  d6 0e 60 6d  ldub  [ %i1 + 0x6d ], %o3	! 0xa802d46d
a00bff84:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00bff88:  b4 10 60 78  or  %g1, 0x78, %i2	! 0xa802d078
a00bff8c:  94 10 20 30  mov  0x30, %o2
a00bff90:  9e 02 e0 30  add  %o3, 0x30, %o7
a00bff94:  de 2e a0 09  stb  %o7, [ %i2 + 9 ]
a00bff98:  d4 2e a0 08  stb  %o2, [ %i2 + 8 ]
a00bff9c:  d4 2e a0 07  stb  %o2, [ %i2 + 7 ]
a00bffa0:  10 bf ff 5d  b  0xa00bfd14
a00bffa4:  90 10 20 70  mov  0x70, %o0
a00bffa8:  13 2a 00 b5  sethi  %hi(0xa802d400), %o1
a00bffac:  d8 02 60 84  ld  [ %o1 + 0x84 ], %o4	! 0xa802d484
a00bffb0:  9b 33 20 1e  srl  %o4, 0x1e, %o5
a00bffb4:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00bffb8:  b2 0b 60 01  and  %o5, 1, %i1
a00bffbc:  9e 12 20 78  or  %o0, 0x78, %o7
a00bffc0:  96 10 20 30  mov  0x30, %o3
a00bffc4:  82 06 60 30  add  %i1, 0x30, %g1
a00bffc8:  c2 2b e0 09  stb  %g1, [ %o7 + 9 ]
a00bffcc:  d6 2b e0 08  stb  %o3, [ %o7 + 8 ]
a00bffd0:  d6 2b e0 07  stb  %o3, [ %o7 + 7 ]
a00bffd4:  10 bf ff 50  b  0xa00bfd14
a00bffd8:  90 10 20 6f  mov  0x6f, %o0
a00bffdc:  15 2a 00 b5  sethi  %hi(0xa802d400), %o2
a00bffe0:  f4 02 a0 84  ld  [ %o2 + 0x84 ], %i2	! 0xa802d484
a00bffe4:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00bffe8:  b2 12 60 78  or  %o1, 0x78, %i1	! 0xa802d078
a00bffec:  90 10 20 30  mov  0x30, %o0
a00bfff0:  99 36 a0 1f  srl  %i2, 0x1f, %o4
a00bfff4:  9a 03 20 30  add  %o4, 0x30, %o5
a00bfff8:  d0 2e 60 08  stb  %o0, [ %i1 + 8 ]
a00bfffc:  d0 2e 60 07  stb  %o0, [ %i1 + 7 ]
a00c0000:  da 2e 60 09  stb  %o5, [ %i1 + 9 ]
a00c0004:  10 bf ff 44  b  0xa00bfd14
a00c0008:  90 10 20 6e  mov  0x6e, %o0
a00c000c:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a00c0010:  d6 00 60 04  ld  [ %g1 + 4 ], %o3	! 0xa802d404
a00c0014:  9f 32 e0 0f  srl  %o3, 0xf, %o7
a00c0018:  b4 0b e0 01  and  %o7, 1, %i2
a00c001c:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c0020:  90 12 a0 78  or  %o2, 0x78, %o0	! 0xa802d078
a00c0024:  98 10 20 30  mov  0x30, %o4
a00c0028:  92 06 a0 30  add  %i2, 0x30, %o1
a00c002c:  d2 2a 20 09  stb  %o1, [ %o0 + 9 ]
a00c0030:  d8 2a 20 08  stb  %o4, [ %o0 + 8 ]
a00c0034:  d8 2a 20 07  stb  %o4, [ %o0 + 7 ]
a00c0038:  10 bf ff 37  b  0xa00bfd14
a00c003c:  90 10 20 6c  mov  0x6c, %o0
a00c0040:  1b 2a 00 b5  sethi  %hi(0xa802d400), %o5
a00c0044:  f2 03 60 7c  ld  [ %o5 + 0x7c ], %i1	! 0xa802d47c
a00c0048:  83 36 60 07  srl  %i1, 7, %g1
a00c004c:  9e 08 60 01  and  %g1, 1, %o7
a00c0050:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c0054:  92 12 e0 78  or  %o3, 0x78, %o1	! 0xa802d078
a00c0058:  b4 10 20 30  mov  0x30, %i2
a00c005c:  94 03 e0 30  add  %o7, 0x30, %o2
a00c0060:  d4 2a 60 09  stb  %o2, [ %o1 + 9 ]
a00c0064:  f4 2a 60 08  stb  %i2, [ %o1 + 8 ]
a00c0068:  f4 2a 60 07  stb  %i2, [ %o1 + 7 ]
a00c006c:  10 bf ff 2a  b  0xa00bfd14
a00c0070:  90 10 20 6b  mov  0x6b, %o0
a00c0074:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c0078:  d8 02 23 3c  ld  [ %o0 + 0x33c ], %o4	! 0xa802d33c
a00c007c:  b3 33 20 12  srl  %o4, 0x12, %i1
a00c0080:  96 0e 60 03  and  %i1, 3, %o3
a00c0084:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c0088:  94 13 60 78  or  %o5, 0x78, %o2	! 0xa802d078
a00c008c:  9e 10 20 30  mov  0x30, %o7
a00c0090:  82 02 e0 30  add  %o3, 0x30, %g1
a00c0094:  c2 2a a0 09  stb  %g1, [ %o2 + 9 ]
a00c0098:  de 2a a0 08  stb  %o7, [ %o2 + 8 ]
a00c009c:  de 2a a0 07  stb  %o7, [ %o2 + 7 ]
a00c00a0:  10 bf ff 1d  b  0xa00bfd14
a00c00a4:  90 10 20 6a  mov  0x6a, %o0
a00c00a8:  33 2a 00 b4  sethi  %hi(0xa802d000), %i1
a00c00ac:  d8 0e 62 bf  ldub  [ %i1 + 0x2bf ], %o4	! 0xa802d2bf
a00c00b0:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c00b4:  b4 13 e0 78  or  %o7, 0x78, %i2	! 0xa802d078
a00c00b8:  82 10 20 30  mov  0x30, %g1
a00c00bc:  96 03 20 30  add  %o4, 0x30, %o3
a00c00c0:  d6 2e a0 09  stb  %o3, [ %i2 + 9 ]
a00c00c4:  c2 2e a0 08  stb  %g1, [ %i2 + 8 ]
a00c00c8:  c2 2e a0 07  stb  %g1, [ %i2 + 7 ]
a00c00cc:  10 bf ff 12  b  0xa00bfd14
a00c00d0:  90 10 20 68  mov  0x68, %o0
a00c00d4:  1b 2a 00 b5  sethi  %hi(0xa802d400), %o5
a00c00d8:  de 0b 60 07  ldub  [ %o5 + 7 ], %o7	! 0xa802d407
a00c00dc:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c00e0:  92 10 60 78  or  %g1, 0x78, %o1	! 0xa802d078
a00c00e4:  b4 10 20 30  mov  0x30, %i2
a00c00e8:  94 03 e0 30  add  %o7, 0x30, %o2
a00c00ec:  d4 2a 60 09  stb  %o2, [ %o1 + 9 ]
a00c00f0:  f4 2a 60 08  stb  %i2, [ %o1 + 8 ]
a00c00f4:  f4 2a 60 07  stb  %i2, [ %o1 + 7 ]
a00c00f8:  10 bf ff 07  b  0xa00bfd14
a00c00fc:  90 10 20 66  mov  0x66, %o0
a00c0100:  35 2a 00 b5  sethi  %hi(0xa802d400), %i2
a00c0104:  d0 0e a0 0c  ldub  [ %i2 + 0xc ], %o0	! 0xa802d40c
a00c0108:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c010c:  96 12 60 78  or  %o1, 0x78, %o3	! 0xa802d078
a00c0110:  98 02 20 30  add  %o0, 0x30, %o4
a00c0114:  b2 10 20 30  mov  0x30, %i1
a00c0118:  d8 2a e0 09  stb  %o4, [ %o3 + 9 ]
a00c011c:  f2 2a e0 08  stb  %i1, [ %o3 + 8 ]
a00c0120:  f2 2a e0 07  stb  %i1, [ %o3 + 7 ]
a00c0124:  10 bf fe fc  b  0xa00bfd14
a00c0128:  90 10 20 65  mov  0x65, %o0
a00c012c:  33 2a 00 b4  sethi  %hi(0xa802d000), %i1
a00c0130:  d8 06 62 90  ld  [ %i1 + 0x290 ], %o4	! 0xa802d290
a00c0134:  9f 33 20 09  srl  %o4, 9, %o7
a00c0138:  96 0b e0 01  and  %o7, 1, %o3
a00c013c:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c0140:  92 13 60 78  or  %o5, 0x78, %o1	! 0xa802d078
a00c0144:  b4 10 20 30  mov  0x30, %i2
a00c0148:  82 02 e0 30  add  %o3, 0x30, %g1
a00c014c:  c2 2a 60 09  stb  %g1, [ %o1 + 9 ]
a00c0150:  f4 2a 60 08  stb  %i2, [ %o1 + 8 ]
a00c0154:  f4 2a 60 07  stb  %i2, [ %o1 + 7 ]
a00c0158:  10 bf fe ef  b  0xa00bfd14
a00c015c:  90 10 20 56  mov  0x56, %o0
a00c0160:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c0164:  96 13 e2 90  or  %o7, 0x290, %o3	! 0xa802d290
a00c0168:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c016c:  9a 13 60 78  or  %o5, 0x78, %o5	! 0xa802d078
a00c0170:  98 10 20 30  mov  0x30, %o4
a00c0174:  c2 0a e0 1f  ldub  [ %o3 + 0x1f ], %g1
a00c0178:  80 a0 60 00  cmp  %g1, 0
a00c017c:  d8 2b 60 07  stb  %o4, [ %o5 + 7 ]
a00c0180:  12 80 02 52  bne  0xa00c0ac8
a00c0184:  d8 2b 60 08  stb  %o4, [ %o5 + 8 ]
a00c0188:  d0 02 e0 ac  ld  [ %o3 + 0xac ], %o0
a00c018c:  99 32 20 14  srl  %o0, 0x14, %o4
a00c0190:  b2 0b 20 01  and  %o4, 1, %i1
a00c0194:  96 06 60 30  add  %i1, 0x30, %o3
a00c0198:  d6 2b 60 09  stb  %o3, [ %o5 + 9 ]
a00c019c:  10 bf fe de  b  0xa00bfd14
a00c01a0:  90 10 20 4c  mov  0x4c, %o0
a00c01a4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c01a8:  7f ff f0 2c  call  0xa00bc258
a00c01ac:  81 e8 00 00  restore
a00c01b0:  35 2a 00 b4  sethi  %hi(0xa802d000), %i2
a00c01b4:  b4 16 a0 78  or  %i2, 0x78, %i2	! 0xa802d078
a00c01b8:  96 10 20 30  mov  0x30, %o3
a00c01bc:  94 10 20 32  mov  0x32, %o2
a00c01c0:  92 10 20 31  mov  0x31, %o1
a00c01c4:  d6 2e a0 07  stb  %o3, [ %i2 + 7 ]
a00c01c8:  d4 2e a0 08  stb  %o2, [ %i2 + 8 ]
a00c01cc:  d2 2e a0 09  stb  %o1, [ %i2 + 9 ]
a00c01d0:  7f ff ea 9b  call  0xa00bac3c
a00c01d4:  90 10 20 4a  mov  0x4a, %o0
a00c01d8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c01dc:  7f ff e9 dd  call  0xa00ba950
a00c01e0:  90 10 00 18  mov  %i0, %o0
a00c01e4:  40 02 21 81  call  0xa01487e8
a00c01e8:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00c01ec:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c01f0:  7f ff fd 7b  call  0xa00bf7dc
a00c01f4:  81 e8 00 00  restore
a00c01f8:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c01fc:  f4 02 a3 3c  ld  [ %o2 + 0x33c ], %i2	! 0xa802d33c
a00c0200:  93 36 a0 16  srl  %i2, 0x16, %o1
a00c0204:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c0208:  98 0a 60 01  and  %o1, 1, %o4
a00c020c:  9a 12 20 78  or  %o0, 0x78, %o5
a00c0210:  9e 10 20 30  mov  0x30, %o7
a00c0214:  b2 03 20 30  add  %o4, 0x30, %i1
a00c0218:  f2 2b 60 09  stb  %i1, [ %o5 + 9 ]
a00c021c:  de 2b 60 08  stb  %o7, [ %o5 + 8 ]
a00c0220:  de 2b 60 07  stb  %o7, [ %o5 + 7 ]
a00c0224:  10 bf fe bc  b  0xa00bfd14
a00c0228:  90 10 20 46  mov  0x46, %o0
a00c022c:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c0230:  c2 02 e3 38  ld  [ %o3 + 0x338 ], %g1	! 0xa802d338
a00c0234:  95 30 60 0f  srl  %g1, 0xf, %o2
a00c0238:  92 0a a0 01  and  %o2, 1, %o1
a00c023c:  35 2a 00 b4  sethi  %hi(0xa802d000), %i2
a00c0240:  b2 16 a0 78  or  %i2, 0x78, %i1	! 0xa802d078
a00c0244:  90 02 60 30  add  %o1, 0x30, %o0
a00c0248:  98 10 20 30  mov  0x30, %o4
a00c024c:  d0 2e 60 09  stb  %o0, [ %i1 + 9 ]
a00c0250:  d8 2e 60 08  stb  %o4, [ %i1 + 8 ]
a00c0254:  d8 2e 60 07  stb  %o4, [ %i1 + 7 ]
a00c0258:  10 bf fe af  b  0xa00bfd14
a00c025c:  90 10 20 45  mov  0x45, %o0
a00c0260:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c0264:  7f ff f7 31  call  0xa00bdf28
a00c0268:  81 e8 00 00  restore
a00c026c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c0270:  7f ff fe 2e  call  0xa00bfb28
a00c0274:  81 e8 00 00  restore
a00c0278:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c027c:  90 13 60 78  or  %o5, 0x78, %o0	! 0xa802d078
a00c0280:  b4 10 20 30  mov  0x30, %i2
a00c0284:  92 10 20 31  mov  0x31, %o1
a00c0288:  96 10 20 0d  mov  0xd, %o3
a00c028c:  82 10 20 62  mov  0x62, %g1
a00c0290:  94 10 20 5c  mov  0x5c, %o2
a00c0294:  9e 10 20 35  mov  0x35, %o7
a00c0298:  d6 2a 20 0a  stb  %o3, [ %o0 + 0xa ]
a00c029c:  c2 2a 20 01  stb  %g1, [ %o0 + 1 ]
a00c02a0:  d4 2a 20 04  stb  %o2, [ %o0 + 4 ]
a00c02a4:  f4 2a 20 07  stb  %i2, [ %o0 + 7 ]
a00c02a8:  d2 2a 20 09  stb  %o1, [ %o0 + 9 ]
a00c02ac:  f4 2a 20 02  stb  %i2, [ %o0 + 2 ]
a00c02b0:  f4 2a 20 03  stb  %i2, [ %o0 + 3 ]
a00c02b4:  f4 2a 20 05  stb  %i2, [ %o0 + 5 ]
a00c02b8:  f4 2a 20 06  stb  %i2, [ %o0 + 6 ]
a00c02bc:  d2 2a 20 08  stb  %o1, [ %o0 + 8 ]
a00c02c0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c02c4:  de 2b 60 78  stb  %o7, [ %o5 + 0x78 ]
a00c02c8:  7f ff e9 a2  call  0xa00ba950
a00c02cc:  90 10 00 18  mov  %i0, %o0
a00c02d0:  7f ff ea 45  call  0xa00babe4
a00c02d4:  93 e8 20 26  restore  %g0, 0x26, %o1
a00c02d8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c02dc:  7f ff fc f5  call  0xa00bf6b0
a00c02e0:  81 e8 00 00  restore
a00c02e4:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c02e8:  f2 0a 22 dc  ldub  [ %o0 + 0x2dc ], %i1	! 0xa802d2dc
a00c02ec:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c02f0:  96 12 a0 78  or  %o2, 0x78, %o3	! 0xa802d078
a00c02f4:  9e 10 20 30  mov  0x30, %o7
a00c02f8:  98 06 60 30  add  %i1, 0x30, %o4
a00c02fc:  d8 2a e0 09  stb  %o4, [ %o3 + 9 ]
a00c0300:  de 2a e0 08  stb  %o7, [ %o3 + 8 ]
a00c0304:  de 2a e0 07  stb  %o7, [ %o3 + 7 ]
a00c0308:  10 bf fe 83  b  0xa00bfd14
a00c030c:  90 10 20 3e  mov  0x3e, %o0
a00c0310:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c0314:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c0318:  94 13 60 78  or  %o5, 0x78, %o2	! 0xa802d078
a00c031c:  90 10 20 30  mov  0x30, %o0
a00c0320:  f4 08 62 db  ldub  [ %g1 + 0x2db ], %i2
a00c0324:  92 06 a0 30  add  %i2, 0x30, %o1
a00c0328:  d0 2a a0 08  stb  %o0, [ %o2 + 8 ]
a00c032c:  d0 2a a0 07  stb  %o0, [ %o2 + 7 ]
a00c0330:  d2 2a a0 09  stb  %o1, [ %o2 + 9 ]
a00c0334:  10 bf fe 78  b  0xa00bfd14
a00c0338:  90 10 20 3d  mov  0x3d, %o0
a00c033c:  33 2a 00 b4  sethi  %hi(0xa802d000), %i1
a00c0340:  d8 0e 62 da  ldub  [ %i1 + 0x2da ], %o4	! 0xa802d2da
a00c0344:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c0348:  9a 13 e0 78  or  %o7, 0x78, %o5	! 0xa802d078
a00c034c:  82 10 20 30  mov  0x30, %g1
a00c0350:  96 03 20 30  add  %o4, 0x30, %o3
a00c0354:  d6 2b 60 09  stb  %o3, [ %o5 + 9 ]
a00c0358:  c2 2b 60 08  stb  %g1, [ %o5 + 8 ]
a00c035c:  c2 2b 60 07  stb  %g1, [ %o5 + 7 ]
a00c0360:  10 bf fe 6d  b  0xa00bfd14
a00c0364:  90 10 20 3c  mov  0x3c, %o0
a00c0368:  35 2a 00 b4  sethi  %hi(0xa802d000), %i2
a00c036c:  d0 0e a3 eb  ldub  [ %i2 + 0x3eb ], %o0	! 0xa802d3eb
a00c0370:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c0374:  9e 12 60 78  or  %o1, 0x78, %o7	! 0xa802d078
a00c0378:  94 02 20 30  add  %o0, 0x30, %o2
a00c037c:  b2 10 20 30  mov  0x30, %i1
a00c0380:  d4 2b e0 09  stb  %o2, [ %o7 + 9 ]
a00c0384:  f2 2b e0 08  stb  %i1, [ %o7 + 8 ]
a00c0388:  f2 2b e0 07  stb  %i1, [ %o7 + 7 ]
a00c038c:  10 bf fe 62  b  0xa00bfd14
a00c0390:  90 10 20 3b  mov  0x3b, %o0
a00c0394:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c0398:  d6 03 23 38  ld  [ %o4 + 0x338 ], %o3	! 0xa802d338
a00c039c:  83 32 e0 06  srl  %o3, 6, %g1
a00c03a0:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c03a4:  94 13 60 78  or  %o5, 0x78, %o2	! 0xa802d078
a00c03a8:  90 10 20 30  mov  0x30, %o0
a00c03ac:  b4 08 60 01  and  %g1, 1, %i2
a00c03b0:  92 06 a0 30  add  %i2, 0x30, %o1
a00c03b4:  d0 2a a0 08  stb  %o0, [ %o2 + 8 ]
a00c03b8:  d0 2a a0 07  stb  %o0, [ %o2 + 7 ]
a00c03bc:  d2 2a a0 09  stb  %o1, [ %o2 + 9 ]
a00c03c0:  10 bf fe 55  b  0xa00bfd14
a00c03c4:  90 10 20 3a  mov  0x3a, %o0
a00c03c8:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c03cc:  d2 03 62 c0  ld  [ %o5 + 0x2c0 ], %o1	! 0xa802d2c0
a00c03d0:  91 32 60 04  srl  %o1, 4, %o0
a00c03d4:  b2 0a 20 0f  and  %o0, 0xf, %i1
a00c03d8:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c03dc:  96 12 a0 78  or  %o2, 0x78, %o3	! 0xa802d078
a00c03e0:  98 10 20 30  mov  0x30, %o4
a00c03e4:  9e 06 60 30  add  %i1, 0x30, %o7
a00c03e8:  de 2a e0 09  stb  %o7, [ %o3 + 9 ]
a00c03ec:  d8 2a e0 08  stb  %o4, [ %o3 + 8 ]
a00c03f0:  d8 2a e0 07  stb  %o4, [ %o3 + 7 ]
a00c03f4:  10 bf fe 48  b  0xa00bfd14
a00c03f8:  90 10 20 39  mov  0x39, %o0
a00c03fc:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c0400:  f4 08 62 c1  ldub  [ %g1 + 0x2c1 ], %i2	! 0xa802d2c1
a00c0404:  9a 10 20 32  mov  0x32, %o5
a00c0408:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c040c:  b2 12 60 78  or  %o1, 0x78, %i1	! 0xa802d078
a00c0410:  90 23 40 1a  sub  %o5, %i2, %o0
a00c0414:  94 10 20 30  mov  0x30, %o2
a00c0418:  d0 2e 60 09  stb  %o0, [ %i1 + 9 ]
a00c041c:  d4 2e 60 08  stb  %o2, [ %i1 + 8 ]
a00c0420:  d4 2e 60 07  stb  %o2, [ %i1 + 7 ]
a00c0424:  10 bf fe 3c  b  0xa00bfd14
a00c0428:  90 10 20 38  mov  0x38, %o0
a00c042c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c0430:  7f ff f9 ac  call  0xa00beae0
a00c0434:  81 e8 00 00  restore
a00c0438:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c043c:  7f ff f9 f4  call  0xa00bec0c
a00c0440:  81 e8 00 00  restore
a00c0444:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c0448:  7f ff fa 3c  call  0xa00bed38
a00c044c:  81 e8 00 00  restore
a00c0450:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c0454:  7f ff fa 84  call  0xa00bee64
a00c0458:  81 e8 00 00  restore
a00c045c:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c0460:  d6 0b e2 af  ldub  [ %o7 + 0x2af ], %o3	! 0xa802d2af
a00c0464:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c0468:  9a 13 20 78  or  %o4, 0x78, %o5	! 0xa802d078
a00c046c:  82 10 20 30  mov  0x30, %g1
a00c0470:  b4 02 e0 30  add  %o3, 0x30, %i2
a00c0474:  f4 2b 60 09  stb  %i2, [ %o5 + 9 ]
a00c0478:  c2 2b 60 08  stb  %g1, [ %o5 + 8 ]
a00c047c:  c2 2b 60 07  stb  %g1, [ %o5 + 7 ]
a00c0480:  10 bf fe 25  b  0xa00bfd14
a00c0484:  90 10 20 33  mov  0x33, %o0
a00c0488:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c048c:  7f ff fc 2b  call  0xa00bf538
a00c0490:  81 e8 00 00  restore
a00c0494:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c0498:  7f ff fb d8  call  0xa00bf3f8
a00c049c:  81 e8 00 00  restore
a00c04a0:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c04a4:  9e 12 60 78  or  %o1, 0x78, %o7	! 0xa802d078
a00c04a8:  90 10 20 33  mov  0x33, %o0
a00c04ac:  d0 2b e0 09  stb  %o0, [ %o7 + 9 ]
a00c04b0:  94 10 20 56  mov  0x56, %o2
a00c04b4:  b2 10 20 32  mov  0x32, %i1
a00c04b8:  d4 2b e0 07  stb  %o2, [ %o7 + 7 ]
a00c04bc:  f2 2b e0 08  stb  %i1, [ %o7 + 8 ]
a00c04c0:  10 bf fe 15  b  0xa00bfd14
a00c04c4:  90 10 20 30  mov  0x30, %o0
a00c04c8:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c04cc:  82 13 20 78  or  %o4, 0x78, %g1	! 0xa802d078
a00c04d0:  b4 10 20 30  mov  0x30, %i2
a00c04d4:  96 10 3f 9f  mov  -97, %o3
a00c04d8:  d6 28 60 09  stb  %o3, [ %g1 + 9 ]
a00c04dc:  f4 28 60 08  stb  %i2, [ %g1 + 8 ]
a00c04e0:  f4 28 60 07  stb  %i2, [ %g1 + 7 ]
a00c04e4:  10 bf fe 0c  b  0xa00bfd14
a00c04e8:  90 10 20 2f  mov  0x2f, %o0
a00c04ec:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c04f0:  7f ff f5 3a  call  0xa00bd9d8
a00c04f4:  81 e8 00 00  restore
a00c04f8:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c04fc:  d2 03 63 3c  ld  [ %o5 + 0x33c ], %o1	! 0xa802d33c
a00c0500:  91 32 60 11  srl  %o1, 0x11, %o0
a00c0504:  b2 0a 20 01  and  %o0, 1, %i1
a00c0508:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c050c:  96 12 a0 78  or  %o2, 0x78, %o3	! 0xa802d078
a00c0510:  98 10 20 30  mov  0x30, %o4
a00c0514:  9e 06 60 30  add  %i1, 0x30, %o7
a00c0518:  de 2a e0 09  stb  %o7, [ %o3 + 9 ]
a00c051c:  d8 2a e0 08  stb  %o4, [ %o3 + 8 ]
a00c0520:  d8 2a e0 07  stb  %o4, [ %o3 + 7 ]
a00c0524:  10 bf fd fc  b  0xa00bfd14
a00c0528:  90 10 20 2d  mov  0x2d, %o0
a00c052c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c0530:  7f ff f4 8c  call  0xa00bd760
a00c0534:  81 e8 00 00  restore
a00c0538:  1b 2a 00 b5  sethi  %hi(0xa802d400), %o5
a00c053c:  c2 0b 60 1d  ldub  [ %o5 + 0x1d ], %g1	! 0xa802d41d
a00c0540:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c0544:  98 12 60 78  or  %o1, 0x78, %o4	! 0xa802d078
a00c0548:  9a 10 20 30  mov  0x30, %o5
a00c054c:  80 a0 60 09  cmp  %g1, 9
a00c0550:  08 80 01 59  bleu  0xa00c0ab4
a00c0554:  da 2b 20 07  stb  %o5, [ %o4 + 7 ]
a00c0558:  82 00 60 26  add  %g1, 0x26, %g1
a00c055c:  9a 10 20 31  mov  0x31, %o5
a00c0560:  c2 2b 20 09  stb  %g1, [ %o4 + 9 ]
a00c0564:  da 2b 20 08  stb  %o5, [ %o4 + 8 ]
a00c0568:  10 bf fd eb  b  0xa00bfd14
a00c056c:  90 10 20 2b  mov  0x2b, %o0
a00c0570:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c0574:  7f ff f4 0a  call  0xa00bd59c
a00c0578:  81 e8 00 00  restore
a00c057c:  33 2a 00 b4  sethi  %hi(0xa802d000), %i1
a00c0580:  1f 2a 00 b5  sethi  %hi(0xa802d400), %o7
a00c0584:  98 16 60 78  or  %i1, 0x78, %o4
a00c0588:  c2 0b e0 1b  ldub  [ %o7 + 0x1b ], %g1
a00c058c:  9a 10 20 30  mov  0x30, %o5
a00c0590:  80 a0 60 09  cmp  %g1, 9
a00c0594:  08 80 01 3e  bleu  0xa00c0a8c
a00c0598:  da 2b 20 07  stb  %o5, [ %o4 + 7 ]
a00c059c:  94 00 60 26  add  %g1, 0x26, %o2
a00c05a0:  9a 10 20 31  mov  0x31, %o5
a00c05a4:  d4 2b 20 09  stb  %o2, [ %o4 + 9 ]
a00c05a8:  da 2b 20 08  stb  %o5, [ %o4 + 8 ]
a00c05ac:  10 bf fd da  b  0xa00bfd14
a00c05b0:  90 10 20 29  mov  0x29, %o0
a00c05b4:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c05b8:  98 10 60 78  or  %g1, 0x78, %o4	! 0xa802d078
a00c05bc:  13 2a 00 b5  sethi  %hi(0xa802d400), %o1
a00c05c0:  c2 0a 60 1a  ldub  [ %o1 + 0x1a ], %g1	! 0xa802d41a
a00c05c4:  9a 10 20 30  mov  0x30, %o5
a00c05c8:  80 a0 60 09  cmp  %g1, 9
a00c05cc:  08 80 01 35  bleu  0xa00c0aa0
a00c05d0:  da 2b 20 07  stb  %o5, [ %o4 + 7 ]
a00c05d4:  b4 00 60 26  add  %g1, 0x26, %i2
a00c05d8:  9a 10 20 31  mov  0x31, %o5
a00c05dc:  f4 2b 20 09  stb  %i2, [ %o4 + 9 ]
a00c05e0:  da 2b 20 08  stb  %o5, [ %o4 + 8 ]
a00c05e4:  10 bf fd cc  b  0xa00bfd14
a00c05e8:  90 10 20 28  mov  0x28, %o0
a00c05ec:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c05f0:  7f ff f3 4e  call  0xa00bd328
a00c05f4:  81 e8 00 00  restore
a00c05f8:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c05fc:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c0600:  d4 0b 62 9f  ldub  [ %o5 + 0x29f ], %o2
a00c0604:  9e 12 20 78  or  %o0, 0x78, %o7
a00c0608:  b2 10 20 30  mov  0x30, %i1
a00c060c:  98 02 a0 30  add  %o2, 0x30, %o4
a00c0610:  d8 2b e0 09  stb  %o4, [ %o7 + 9 ]
a00c0614:  f2 2b e0 08  stb  %i1, [ %o7 + 8 ]
a00c0618:  f2 2b e0 07  stb  %i1, [ %o7 + 7 ]
a00c061c:  10 bf fd be  b  0xa00bfd14
a00c0620:  90 10 20 26  mov  0x26, %o0
a00c0624:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c0628:  f4 12 e2 c4  lduh  [ %o3 + 0x2c4 ], %i2	! 0xa802d2c4
a00c062c:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c0630:  94 10 60 78  or  %g1, 0x78, %o2	! 0xa802d078
a00c0634:  90 10 20 30  mov  0x30, %o0
a00c0638:  92 0e a0 0f  and  %i2, 0xf, %o1
a00c063c:  9a 02 60 30  add  %o1, 0x30, %o5
a00c0640:  d0 2a a0 08  stb  %o0, [ %o2 + 8 ]
a00c0644:  d0 2a a0 07  stb  %o0, [ %o2 + 7 ]
a00c0648:  da 2a a0 09  stb  %o5, [ %o2 + 9 ]
a00c064c:  10 bf fd b2  b  0xa00bfd14
a00c0650:  90 10 20 25  mov  0x25, %o0
a00c0654:  33 2a 00 b4  sethi  %hi(0xa802d000), %i1
a00c0658:  de 06 63 ac  ld  [ %i1 + 0x3ac ], %o7	! 0xa802d3ac
a00c065c:  99 33 e0 04  srl  %o7, 4, %o4
a00c0660:  b4 0b 20 01  and  %o4, 1, %i2
a00c0664:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c0668:  90 12 e0 78  or  %o3, 0x78, %o0	! 0xa802d078
a00c066c:  92 10 20 30  mov  0x30, %o1
a00c0670:  82 06 a0 30  add  %i2, 0x30, %g1
a00c0674:  c2 2a 20 09  stb  %g1, [ %o0 + 9 ]
a00c0678:  d2 2a 20 08  stb  %o1, [ %o0 + 8 ]
a00c067c:  d2 2a 20 07  stb  %o1, [ %o0 + 7 ]
a00c0680:  10 bf fd a5  b  0xa00bfd14
a00c0684:  90 10 20 24  mov  0x24, %o0
a00c0688:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c068c:  7f ff f2 79  call  0xa00bd070
a00c0690:  81 e8 00 00  restore
a00c0694:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c0698:  7f ff f2 0d  call  0xa00bcecc
a00c069c:  81 e8 00 00  restore
a00c06a0:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c06a4:  d4 03 63 38  ld  [ %o5 + 0x338 ], %o2	! 0xa802d338
a00c06a8:  b3 32 a0 0d  srl  %o2, 0xd, %i1
a00c06ac:  98 0e 60 01  and  %i1, 1, %o4
a00c06b0:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c06b4:  92 13 e0 78  or  %o7, 0x78, %o1	! 0xa802d078
a00c06b8:  b4 10 20 30  mov  0x30, %i2
a00c06bc:  96 03 20 30  add  %o4, 0x30, %o3
a00c06c0:  d6 2a 60 09  stb  %o3, [ %o1 + 9 ]
a00c06c4:  f4 2a 60 08  stb  %i2, [ %o1 + 8 ]
a00c06c8:  f4 2a 60 07  stb  %i2, [ %o1 + 7 ]
a00c06cc:  10 bf fd 92  b  0xa00bfd14
a00c06d0:  90 10 20 21  mov  0x21, %o0
a00c06d4:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c06d8:  c2 02 23 38  ld  [ %o0 + 0x338 ], %g1	! 0xa802d338
a00c06dc:  95 30 60 07  srl  %g1, 7, %o2
a00c06e0:  b2 0a a0 01  and  %o2, 1, %i1
a00c06e4:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c06e8:  96 13 60 78  or  %o5, 0x78, %o3	! 0xa802d078
a00c06ec:  98 10 20 30  mov  0x30, %o4
a00c06f0:  9e 06 60 30  add  %i1, 0x30, %o7
a00c06f4:  de 2a e0 09  stb  %o7, [ %o3 + 9 ]
a00c06f8:  d8 2a e0 08  stb  %o4, [ %o3 + 8 ]
a00c06fc:  d8 2a e0 07  stb  %o4, [ %o3 + 7 ]
a00c0700:  10 bf fd 85  b  0xa00bfd14
a00c0704:  90 10 20 20  mov  0x20, %o0
a00c0708:  35 2a 00 b5  sethi  %hi(0xa802d400), %i2
a00c070c:  d0 0e a0 0b  ldub  [ %i2 + 0xb ], %o0	! 0xa802d40b
a00c0710:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c0714:  b2 12 60 78  or  %o1, 0x78, %i1	! 0xa802d078
a00c0718:  82 02 20 30  add  %o0, 0x30, %g1
a00c071c:  94 10 20 30  mov  0x30, %o2
a00c0720:  c2 2e 60 09  stb  %g1, [ %i1 + 9 ]
a00c0724:  d4 2e 60 08  stb  %o2, [ %i1 + 8 ]
a00c0728:  d4 2e 60 07  stb  %o2, [ %i1 + 7 ]
a00c072c:  10 bf fd 7a  b  0xa00bfd14
a00c0730:  90 10 20 1f  mov  0x1f, %o0
a00c0734:  1f 2a 00 b5  sethi  %hi(0xa802d400), %o7
a00c0738:  d6 0b e0 20  ldub  [ %o7 + 0x20 ], %o3	! 0xa802d420
a00c073c:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c0740:  92 13 60 78  or  %o5, 0x78, %o1	! 0xa802d078
a00c0744:  b4 10 20 30  mov  0x30, %i2
a00c0748:  98 02 e0 30  add  %o3, 0x30, %o4
a00c074c:  d8 2a 60 09  stb  %o4, [ %o1 + 9 ]
a00c0750:  f4 2a 60 08  stb  %i2, [ %o1 + 8 ]
a00c0754:  f4 2a 60 07  stb  %i2, [ %o1 + 7 ]
a00c0758:  10 bf fd 6f  b  0xa00bfd14
a00c075c:  90 10 20 1e  mov  0x1e, %o0
a00c0760:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c0764:  d4 0a 23 cf  ldub  [ %o0 + 0x3cf ], %o2	! 0xa802d3cf
a00c0768:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c076c:  96 10 60 78  or  %g1, 0x78, %o3	! 0xa802d078
a00c0770:  9e 10 20 30  mov  0x30, %o7
a00c0774:  b2 02 a0 30  add  %o2, 0x30, %i1
a00c0778:  f2 2a e0 09  stb  %i1, [ %o3 + 9 ]
a00c077c:  de 2a e0 08  stb  %o7, [ %o3 + 8 ]
a00c0780:  de 2a e0 07  stb  %o7, [ %o3 + 7 ]
a00c0784:  10 bf fd 64  b  0xa00bfd14
a00c0788:  90 10 20 1d  mov  0x1d, %o0
a00c078c:  35 2a 00 b3  sethi  %hi(0xa802cc00), %i2
a00c0790:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c0794:  d2 0e a3 fd  ldub  [ %i2 + 0x3fd ], %o1
a00c0798:  9a 13 22 90  or  %o4, 0x290, %o5
a00c079c:  90 02 40 0d  add  %o1, %o5, %o0
a00c07a0:  f2 0a 21 9b  ldub  [ %o0 + 0x19b ], %i1
a00c07a4:  d4 0a 21 97  ldub  [ %o0 + 0x197 ], %o2
a00c07a8:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c07ac:  98 10 60 78  or  %g1, 0x78, %o4	! 0xa802d078
a00c07b0:  b4 02 a0 30  add  %o2, 0x30, %i2
a00c07b4:  9e 06 60 30  add  %i1, 0x30, %o7
a00c07b8:  96 10 20 30  mov  0x30, %o3
a00c07bc:  de 2b 20 09  stb  %o7, [ %o4 + 9 ]
a00c07c0:  d6 2b 20 07  stb  %o3, [ %o4 + 7 ]
a00c07c4:  f4 2b 20 08  stb  %i2, [ %o4 + 8 ]
a00c07c8:  10 bf fd 53  b  0xa00bfd14
a00c07cc:  90 10 20 1c  mov  0x1c, %o0
a00c07d0:  13 2a 00 b3  sethi  %hi(0xa802cc00), %o1
a00c07d4:  d0 0a 63 fd  ldub  [ %o1 + 0x3fd ], %o0	! 0xa802cffd
a00c07d8:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c07dc:  94 13 60 78  or  %o5, 0x78, %o2	! 0xa802d078
a00c07e0:  82 02 20 30  add  %o0, 0x30, %g1
a00c07e4:  b2 10 20 30  mov  0x30, %i1
a00c07e8:  c2 2a a0 09  stb  %g1, [ %o2 + 9 ]
a00c07ec:  f2 2a a0 08  stb  %i1, [ %o2 + 8 ]
a00c07f0:  f2 2a a0 07  stb  %i1, [ %o2 + 7 ]
a00c07f4:  10 bf fd 48  b  0xa00bfd14
a00c07f8:  90 10 20 1b  mov  0x1b, %o0
a00c07fc:  1f 2a 00 b5  sethi  %hi(0xa802d400), %o7
a00c0800:  d6 0b e0 30  ldub  [ %o7 + 0x30 ], %o3	! 0xa802d430
a00c0804:  35 2a 00 b4  sethi  %hi(0xa802d000), %i2
a00c0808:  9a 16 a0 78  or  %i2, 0x78, %o5	! 0xa802d078
a00c080c:  92 10 20 30  mov  0x30, %o1
a00c0810:  98 02 e0 30  add  %o3, 0x30, %o4
a00c0814:  d8 2b 60 09  stb  %o4, [ %o5 + 9 ]
a00c0818:  d2 2b 60 08  stb  %o1, [ %o5 + 8 ]
a00c081c:  d2 2b 60 07  stb  %o1, [ %o5 + 7 ]
a00c0820:  10 bf fd 3d  b  0xa00bfd14
a00c0824:  90 10 20 1a  mov  0x1a, %o0
a00c0828:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c082c:  f2 0a 23 ce  ldub  [ %o0 + 0x3ce ], %i1	! 0xa802d3ce
a00c0830:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c0834:  b4 10 60 78  or  %g1, 0x78, %i2	! 0xa802d078
a00c0838:  9e 10 20 30  mov  0x30, %o7
a00c083c:  94 06 60 30  add  %i1, 0x30, %o2
a00c0840:  d4 2e a0 09  stb  %o2, [ %i2 + 9 ]
a00c0844:  de 2e a0 08  stb  %o7, [ %i2 + 8 ]
a00c0848:  de 2e a0 07  stb  %o7, [ %i2 + 7 ]
a00c084c:  10 bf fd 32  b  0xa00bfd14
a00c0850:  90 10 20 19  mov  0x19, %o0
a00c0854:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c0858:  d2 02 e3 38  ld  [ %o3 + 0x338 ], %o1	! 0xa802d338
a00c085c:  9b 32 60 0c  srl  %o1, 0xc, %o5
a00c0860:  90 0b 60 01  and  %o5, 1, %o0
a00c0864:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c0868:  94 13 20 78  or  %o4, 0x78, %o2	! 0xa802d078
a00c086c:  82 02 20 30  add  %o0, 0x30, %g1
a00c0870:  b2 10 20 30  mov  0x30, %i1
a00c0874:  c2 2a a0 09  stb  %g1, [ %o2 + 9 ]
a00c0878:  f2 2a a0 08  stb  %i1, [ %o2 + 8 ]
a00c087c:  f2 2a a0 07  stb  %i1, [ %o2 + 7 ]
a00c0880:  10 bf fd 25  b  0xa00bfd14
a00c0884:  90 10 20 18  mov  0x18, %o0
a00c0888:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c088c:  f4 03 e3 ac  ld  [ %o7 + 0x3ac ], %i2	! 0xa802d3ac
a00c0890:  93 36 a0 1f  srl  %i2, 0x1f, %o1
a00c0894:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c0898:  90 12 e0 78  or  %o3, 0x78, %o0	! 0xa802d078
a00c089c:  98 10 20 30  mov  0x30, %o4
a00c08a0:  9a 02 60 30  add  %o1, 0x30, %o5
a00c08a4:  da 2a 20 09  stb  %o5, [ %o0 + 9 ]
a00c08a8:  d8 2a 20 08  stb  %o4, [ %o0 + 8 ]
a00c08ac:  d8 2a 20 07  stb  %o4, [ %o0 + 7 ]
a00c08b0:  10 bf fd 19  b  0xa00bfd14
a00c08b4:  90 10 20 17  mov  0x17, %o0
a00c08b8:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c08bc:  d4 00 63 40  ld  [ %g1 + 0x340 ], %o2	! 0xa802d340
a00c08c0:  33 2a 00 b4  sethi  %hi(0xa802d000), %i1
a00c08c4:  96 16 60 78  or  %i1, 0x78, %o3	! 0xa802d078
a00c08c8:  b4 10 20 30  mov  0x30, %i2
a00c08cc:  9e 02 a0 30  add  %o2, 0x30, %o7
a00c08d0:  de 2a e0 09  stb  %o7, [ %o3 + 9 ]
a00c08d4:  f4 2a e0 08  stb  %i2, [ %o3 + 8 ]
a00c08d8:  f4 2a e0 07  stb  %i2, [ %o3 + 7 ]
a00c08dc:  10 bf fd 0e  b  0xa00bfd14
a00c08e0:  90 10 20 16  mov  0x16, %o0
a00c08e4:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c08e8:  d0 0a 62 a9  ldub  [ %o1 + 0x2a9 ], %o0	! 0xa802d2a9
a00c08ec:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c08f0:  b2 13 60 78  or  %o5, 0x78, %i1	! 0xa802d078
a00c08f4:  98 02 20 30  add  %o0, 0x30, %o4
a00c08f8:  82 10 20 30  mov  0x30, %g1
a00c08fc:  d8 2e 60 09  stb  %o4, [ %i1 + 9 ]
a00c0900:  c2 2e 60 08  stb  %g1, [ %i1 + 8 ]
a00c0904:  c2 2e 60 07  stb  %g1, [ %i1 + 7 ]
a00c0908:  10 bf fd 03  b  0xa00bfd14
a00c090c:  90 10 20 15  mov  0x15, %o0
a00c0910:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c0914:  f4 0a a3 d0  ldub  [ %o2 + 0x3d0 ], %i2	! 0xa802d3d0
a00c0918:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c091c:  90 13 e0 78  or  %o7, 0x78, %o0	! 0xa802d078
a00c0920:  92 10 20 30  mov  0x30, %o1
a00c0924:  96 06 a0 30  add  %i2, 0x30, %o3
a00c0928:  d6 2a 20 09  stb  %o3, [ %o0 + 9 ]
a00c092c:  d2 2a 20 08  stb  %o1, [ %o0 + 8 ]
a00c0930:  d2 2a 20 07  stb  %o1, [ %o0 + 7 ]
a00c0934:  10 bf fc f8  b  0xa00bfd14
a00c0938:  90 10 20 14  mov  0x14, %o0
a00c093c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c0940:  7f ff f0 07  call  0xa00bc95c
a00c0944:  81 e8 00 00  restore
a00c0948:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c094c:  7f ff f9 91  call  0xa00bef90
a00c0950:  81 e8 00 00  restore
a00c0954:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c0958:  b2 10 60 78  or  %g1, 0x78, %i1	! 0xa802d078
a00c095c:  98 10 20 30  mov  0x30, %o4
a00c0960:  9a 10 20 31  mov  0x31, %o5
a00c0964:  da 2e 60 09  stb  %o5, [ %i1 + 9 ]
a00c0968:  d8 2e 60 08  stb  %o4, [ %i1 + 8 ]
a00c096c:  d8 2e 60 07  stb  %o4, [ %i1 + 7 ]
a00c0970:  7f ff e8 d5  call  0xa00bacc4
a00c0974:  90 10 20 0f  mov  0xf, %o0
a00c0978:  10 bf fc e9  b  0xa00bfd1c
a00c097c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c0980:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c0984:  f4 0a a2 98  ldub  [ %o2 + 0x298 ], %i2	! 0xa802d298
a00c0988:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c098c:  90 13 e0 78  or  %o7, 0x78, %o0	! 0xa802d078
a00c0990:  92 10 20 30  mov  0x30, %o1
a00c0994:  96 06 a0 30  add  %i2, 0x30, %o3
a00c0998:  d6 2a 20 09  stb  %o3, [ %o0 + 9 ]
a00c099c:  d2 2a 20 08  stb  %o1, [ %o0 + 8 ]
a00c09a0:  d2 2a 20 07  stb  %o1, [ %o0 + 7 ]
a00c09a4:  7f ff e8 c8  call  0xa00bacc4
a00c09a8:  90 10 20 0d  mov  0xd, %o0
a00c09ac:  10 bf fc dc  b  0xa00bfd1c
a00c09b0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c09b4:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c09b8:  82 13 62 90  or  %o5, 0x290, %g1	! 0xa802d290
a00c09bc:  de 08 60 14  ldub  [ %g1 + 0x14 ], %o7
a00c09c0:  f2 08 60 12  ldub  [ %g1 + 0x12 ], %i1
a00c09c4:  d4 08 60 13  ldub  [ %g1 + 0x13 ], %o2
a00c09c8:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c09cc:  90 13 20 78  or  %o4, 0x78, %o0	! 0xa802d078
a00c09d0:  96 06 60 30  add  %i1, 0x30, %o3
a00c09d4:  92 02 a0 30  add  %o2, 0x30, %o1
a00c09d8:  b4 03 e0 30  add  %o7, 0x30, %i2
a00c09dc:  f4 2a 20 09  stb  %i2, [ %o0 + 9 ]
a00c09e0:  d6 2a 20 07  stb  %o3, [ %o0 + 7 ]
a00c09e4:  d2 2a 20 08  stb  %o1, [ %o0 + 8 ]
a00c09e8:  7f ff e8 b7  call  0xa00bacc4
a00c09ec:  90 10 20 0a  mov  0xa, %o0
a00c09f0:  10 bf fc cb  b  0xa00bfd1c
a00c09f4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c09f8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c09fc:  7f ff ef 3d  call  0xa00bc6f0
a00c0a00:  81 e8 00 00  restore
a00c0a04:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c0a08:  7f ff ee db  call  0xa00bc574
a00c0a0c:  81 e8 00 00  restore
a00c0a10:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c0a14:  7f ff ee 79  call  0xa00bc3f8
a00c0a18:  81 e8 00 00  restore
a00c0a1c:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c0a20:  d8 0b 62 a1  ldub  [ %o5 + 0x2a1 ], %o4	! 0xa802d2a1
a00c0a24:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c0a28:  b4 10 60 78  or  %g1, 0x78, %i2	! 0xa802d078
a00c0a2c:  9e 10 20 30  mov  0x30, %o7
a00c0a30:  b2 03 20 30  add  %o4, 0x30, %i1
a00c0a34:  de 2e a0 08  stb  %o7, [ %i2 + 8 ]
a00c0a38:  f2 2e a0 09  stb  %i1, [ %i2 + 9 ]
a00c0a3c:  de 2e a0 07  stb  %o7, [ %i2 + 7 ]
a00c0a40:  7f ff e8 a1  call  0xa00bacc4
a00c0a44:  90 10 20 06  mov  6, %o0
a00c0a48:  10 bf fd e5  b  0xa00c01dc
a00c0a4c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c0a50:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c0a54:  7f ff ed 91  call  0xa00bc098
a00c0a58:  81 e8 00 00  restore
a00c0a5c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c0a60:  7f ff ed 2f  call  0xa00bbf1c
a00c0a64:  81 e8 00 00  restore
a00c0a68:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c0a6c:  7f ff ec cd  call  0xa00bbda0
a00c0a70:  81 e8 00 00  restore
a00c0a74:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c0a78:  7f ff f9 a6  call  0xa00bf110
a00c0a7c:  81 e8 00 00  restore
a00c0a80:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c0a84:  7f ff f7 c9  call  0xa00be9a8
a00c0a88:  81 e8 00 00  restore
a00c0a8c:  90 00 60 30  add  %g1, 0x30, %o0
a00c0a90:  d0 2b 20 09  stb  %o0, [ %o4 + 9 ]
a00c0a94:  da 2b 20 08  stb  %o5, [ %o4 + 8 ]
a00c0a98:  10 bf fc 9f  b  0xa00bfd14
a00c0a9c:  90 10 20 29  mov  0x29, %o0
a00c0aa0:  96 00 60 30  add  %g1, 0x30, %o3
a00c0aa4:  d6 2b 20 09  stb  %o3, [ %o4 + 9 ]
a00c0aa8:  da 2b 20 08  stb  %o5, [ %o4 + 8 ]
a00c0aac:  10 bf fc 9a  b  0xa00bfd14
a00c0ab0:  90 10 20 28  mov  0x28, %o0
a00c0ab4:  b4 00 60 30  add  %g1, 0x30, %i2
a00c0ab8:  f4 2b 20 09  stb  %i2, [ %o4 + 9 ]
a00c0abc:  da 2b 20 08  stb  %o5, [ %o4 + 8 ]
a00c0ac0:  10 bf fc 95  b  0xa00bfd14
a00c0ac4:  90 10 20 2b  mov  0x2b, %o0
a00c0ac8:  d8 2b 60 09  stb  %o4, [ %o5 + 9 ]
a00c0acc:  10 bf fc 92  b  0xa00bfd14
a00c0ad0:  90 10 20 4c  mov  0x4c, %o0
a00c0ad4:  81 c7 e0 08  ret
a00c0ad8:  81 e8 00 00  restore
