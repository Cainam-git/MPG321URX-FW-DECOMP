# leon2m FUN_a0093f90 0xa0093f90-0xa0094108 (376 bytes)
a0093f90:  9d e3 bf 98  save  %sp, -104, %sp
a0093f94:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a0093f98:  67 ff e5 7f  call  0x4008d594
a0093f9c:  d0 14 a0 34  lduh  [ %l2 + 0x34 ], %o0	! 0xa802d034
a0093fa0:  83 2a 20 10  sll  %o0, 0x10, %g1
a0093fa4:  91 30 60 10  srl  %g1, 0x10, %o0
a0093fa8:  80 a2 20 64  cmp  %o0, 0x64
a0093fac:  a8 10 00 12  mov  %l2, %l4
a0093fb0:  27 2a 00 b3  sethi  %hi(0xa802cc00), %l3
a0093fb4:  18 80 00 47  bgu  0xa00940d0
a0093fb8:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a0093fbc:  40 02 cd da  call  0xa0147724
a0093fc0:  a0 14 e3 f4  or  %l3, 0x3f4, %l0
a0093fc4:  d6 0c 20 08  ldub  [ %l0 + 8 ], %o3
a0093fc8:  95 32 e0 04  srl  %o3, 4, %o2
a0093fcc:  80 a2 a0 03  cmp  %o2, 3
a0093fd0:  02 80 00 06  be  0xa0093fe8
a0093fd4:  d0 35 20 34  sth  %o0, [ %l4 + 0x34 ]
a0093fd8:  98 10 20 38  mov  0x38, %o4
a0093fdc:  40 02 cd d2  call  0xa0147724
a0093fe0:  d8 2c 20 08  stb  %o4, [ %l0 + 8 ]
a0093fe4:  d0 34 60 3a  sth  %o0, [ %l1 + 0x3a ]
a0093fe8:  67 ff e5 6b  call  0x4008d594
a0093fec:  d0 14 60 3a  lduh  [ %l1 + 0x3a ], %o0
a0093ff0:  91 2a 20 10  sll  %o0, 0x10, %o0
a0093ff4:  9f 32 20 10  srl  %o0, 0x10, %o7
a0093ff8:  80 a3 e7 d0  cmp  %o7, 0x7d0
a0093ffc:  18 80 00 2c  bgu  0xa00940ac
a0094000:  01 00 00 00  nop
a0094004:  67 ff e5 64  call  0x4008d594
a0094008:  d0 14 60 3a  lduh  [ %l1 + 0x3a ], %o0
a009400c:  95 2a 20 10  sll  %o0, 0x10, %o2
a0094010:  13 00 00 04  sethi  %hi(0x1000), %o1
a0094014:  a3 32 a0 10  srl  %o2, 0x10, %l1
a0094018:  a0 12 63 88  or  %o1, 0x388, %l0
a009401c:  80 a4 40 10  cmp  %l1, %l0
a0094020:  18 80 00 18  bgu  0xa0094080
a0094024:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a0094028:  96 12 22 90  or  %o0, 0x290, %o3	! 0xa802d290
a009402c:  c2 0a e0 31  ldub  [ %o3 + 0x31 ], %g1
a0094030:  80 a0 60 00  cmp  %g1, 0
a0094034:  22 80 00 08  be,a   0xa0094054
a0094038:  82 14 e3 f4  or  %l3, 0x3f4, %g1
a009403c:  80 a0 60 01  cmp  %g1, 1
a0094040:  02 80 00 04  be  0xa0094050
a0094044:  80 a0 60 02  cmp  %g1, 2
a0094048:  12 80 00 28  bne  0xa00940e8
a009404c:  01 00 00 00  nop
a0094050:  82 14 e3 f4  or  %l3, 0x3f4, %g1
a0094054:  da 08 60 08  ldub  [ %g1 + 8 ], %o5
a0094058:  a6 0b 60 0f  and  %o5, 0xf, %l3
a009405c:  e8 12 e0 56  lduh  [ %o3 + 0x56 ], %l4
a0094060:  80 a4 c0 14  cmp  %l3, %l4
a0094064:  08 80 00 04  bleu  0xa0094074
a0094068:  82 0c e0 ff  and  %l3, 0xff, %g1
a009406c:  10 80 00 1f  b  0xa00940e8
a0094070:  c0 32 e0 56  clrh  [ %o3 + 0x56 ]
a0094074:  a0 25 00 01  sub  %l4, %g1, %l0
a0094078:  10 80 00 1c  b  0xa00940e8
a009407c:  e0 32 e0 56  sth  %l0, [ %o3 + 0x56 ]
a0094080:  67 ff e5 45  call  0x4008d594
a0094084:  d0 14 a0 34  lduh  [ %l2 + 0x34 ], %o0
a0094088:  97 2a 20 10  sll  %o0, 0x10, %o3
a009408c:  a5 32 e0 10  srl  %o3, 0x10, %l2
a0094090:  80 a4 a0 63  cmp  %l2, 0x63
a0094094:  18 bf ff e5  bgu  0xa0094028
a0094098:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a009409c:  98 14 e3 f4  or  %l3, 0x3f4, %o4
a00940a0:  9e 10 20 38  mov  0x38, %o7
a00940a4:  10 bf ff e1  b  0xa0094028
a00940a8:  de 2b 20 08  stb  %o7, [ %o4 + 8 ]
a00940ac:  67 ff e5 3a  call  0x4008d594
a00940b0:  d0 15 20 34  lduh  [ %l4 + 0x34 ], %o0
a00940b4:  83 2a 20 10  sll  %o0, 0x10, %g1
a00940b8:  a9 30 60 10  srl  %g1, 0x10, %l4
a00940bc:  80 a5 20 63  cmp  %l4, 0x63
a00940c0:  18 bf ff d1  bgu  0xa0094004
a00940c4:  9a 10 20 38  mov  0x38, %o5
a00940c8:  10 bf ff cf  b  0xa0094004
a00940cc:  da 2c 20 08  stb  %o5, [ %l0 + 8 ]
a00940d0:  9a 14 e3 f4  or  %l3, 0x3f4, %o5
a00940d4:  92 10 20 38  mov  0x38, %o1
a00940d8:  40 02 cd 93  call  0xa0147724
a00940dc:  d2 2b 60 08  stb  %o1, [ %o5 + 8 ]
a00940e0:  10 bf ff b7  b  0xa0093fbc
a00940e4:  d0 34 60 3a  sth  %o0, [ %l1 + 0x3a ]
a00940e8:  40 01 0e 62  call  0xa00d7a70
a00940ec:  90 10 20 00  clr  %o0
a00940f0:  23 2a 00 ac  sethi  %hi(0xa802b000), %l1
a00940f4:  d4 0c 60 8e  ldub  [ %l1 + 0x8e ], %o2	! 0xa802b08e
a00940f8:  92 12 a0 02  or  %o2, 2, %o1
a00940fc:  d2 2c 60 8e  stb  %o1, [ %l1 + 0x8e ]
a0094100:  81 c7 e0 08  ret
a0094104:  81 e8 00 00  restore
