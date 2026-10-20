# leon2s FUN_a00cfd38 0xa00cfd38-0xa00d00e0 (936 bytes)
a00cfd38:  9d e3 bf 88  save  %sp, -120, %sp
a00cfd3c:  7f ff ff 79  call  0xa00cfb20
a00cfd40:  90 10 20 0a  mov  0xa, %o0
a00cfd44:  80 a2 20 00  cmp  %o0, 0
a00cfd48:  17 2a 01 e2  sethi  %hi(0xa8078800), %o3
a00cfd4c:  02 80 00 12  be  0xa00cfd94
a00cfd50:  a2 0e 20 ff  and  %i0, 0xff, %l1
a00cfd54:  9a 04 40 11  add  %l1, %l1, %o5
a00cfd58:  9a 03 40 11  add  %o5, %l1, %o5
a00cfd5c:  96 12 e3 b0  or  %o3, 0x3b0, %o3
a00cfd60:  9b 2b 60 03  sll  %o5, 3, %o5
a00cfd64:  c2 02 c0 0d  ld  [ %o3 + %o5 ], %g1
a00cfd68:  10 80 00 d3  b  0xa00d00b4
a00cfd6c:  19 00 00 c0  sethi  %hi(0x30000), %o4
a00cfd70:  9a 04 40 11  add  %l1, %l1, %o5
a00cfd74:  9a 03 40 11  add  %o5, %l1, %o5
a00cfd78:  96 14 a3 b0  or  %l2, 0x3b0, %o3
a00cfd7c:  9b 2b 60 03  sll  %o5, 3, %o5
a00cfd80:  d8 02 c0 0d  ld  [ %o3 + %o5 ], %o4
a00cfd84:  03 08 00 00  sethi  %hi(0x20000000), %g1
a00cfd88:  82 2b 00 01  andn  %o4, %g1, %g1
a00cfd8c:  10 80 00 3c  b  0xa00cfe7c
a00cfd90:  c2 22 c0 0d  st  %g1, [ %o3 + %o5 ]
a00cfd94:  98 04 40 11  add  %l1, %l1, %o4
a00cfd98:  a4 10 00 0b  mov  %o3, %l2
a00cfd9c:  98 03 00 11  add  %o4, %l1, %o4
a00cfda0:  99 2b 20 03  sll  %o4, 3, %o4
a00cfda4:  96 12 e3 b0  or  %o3, 0x3b0, %o3
a00cfda8:  da 02 c0 0c  ld  [ %o3 + %o4 ], %o5
a00cfdac:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00cfdb0:  82 2b 40 01  andn  %o5, %g1, %g1
a00cfdb4:  1b 00 00 40  sethi  %hi(0x10000), %o5
a00cfdb8:  82 10 40 0d  or  %g1, %o5, %g1
a00cfdbc:  c2 22 c0 0c  st  %g1, [ %o3 + %o4 ]
a00cfdc0:  a8 07 bf e8  add  %fp, -24, %l4
a00cfdc4:  15 00 01 a4  sethi  %hi(0x69000), %o2
a00cfdc8:  94 12 a0 0b  or  %o2, 0xb, %o2	! 0x6900b
a00cfdcc:  92 10 20 90  mov  0x90, %o1
a00cfdd0:  96 10 20 04  mov  4, %o3
a00cfdd4:  40 3b 19 8b  call  0xa0f96400
a00cfdd8:  98 10 00 14  mov  %l4, %o4
a00cfddc:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00cfde0:  92 10 62 38  or  %g1, 0x238, %o1	! 0xa807ce38
a00cfde4:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00cfde8:  94 10 62 50  or  %g1, 0x250, %o2	! 0xa807ce50
a00cfdec:  a0 10 20 00  clr  %l0
a00cfdf0:  a6 07 bf f8  add  %fp, -8, %l3
a00cfdf4:  82 0c 20 ff  and  %l0, 0xff, %g1
a00cfdf8:  9a 04 c0 01  add  %l3, %g1, %o5
a00cfdfc:  d6 0b 7f f0  ldub  [ %o5 + -16 ], %o3
a00cfe00:  9a 00 40 0a  add  %g1, %o2, %o5
a00cfe04:  a0 04 20 01  inc  %l0
a00cfe08:  82 00 40 09  add  %g1, %o1, %g1
a00cfe0c:  98 0c 20 ff  and  %l0, 0xff, %o4
a00cfe10:  d6 2b 60 01  stb  %o3, [ %o5 + 1 ]
a00cfe14:  80 a3 20 04  cmp  %o4, 4
a00cfe18:  08 bf ff f7  bleu  0xa00cfdf4
a00cfe1c:  d6 28 60 0a  stb  %o3, [ %g1 + 0xa ]
a00cfe20:  9a 04 40 11  add  %l1, %l1, %o5
a00cfe24:  9a 03 40 11  add  %o5, %l1, %o5
a00cfe28:  9b 2b 60 03  sll  %o5, 3, %o5
a00cfe2c:  96 14 a3 b0  or  %l2, 0x3b0, %o3
a00cfe30:  c2 02 c0 0d  ld  [ %o3 + %o5 ], %g1
a00cfe34:  19 08 00 00  sethi  %hi(0x20000000), %o4
a00cfe38:  82 10 40 0c  or  %g1, %o4, %g1
a00cfe3c:  c2 22 c0 0d  st  %g1, [ %o3 + %o5 ]
a00cfe40:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00cfe44:  94 10 61 a8  or  %g1, 0x1a8, %o2	! 0xa807cda8
a00cfe48:  a0 10 20 00  clr  %l0
a00cfe4c:  82 0c 20 ff  and  %l0, 0xff, %g1
a00cfe50:  98 00 40 0a  add  %g1, %o2, %o4
a00cfe54:  82 04 c0 01  add  %l3, %g1, %g1
a00cfe58:  da 08 7f f0  ldub  [ %g1 + -16 ], %o5
a00cfe5c:  a0 04 20 01  inc  %l0
a00cfe60:  c2 0b 20 0a  ldub  [ %o4 + 0xa ], %g1
a00cfe64:  80 a3 40 01  cmp  %o5, %g1
a00cfe68:  12 bf ff c2  bne  0xa00cfd70
a00cfe6c:  96 0c 20 ff  and  %l0, 0xff, %o3
a00cfe70:  80 a2 e0 04  cmp  %o3, 4
a00cfe74:  08 bf ff f7  bleu  0xa00cfe50
a00cfe78:  82 0c 20 ff  and  %l0, 0xff, %g1
a00cfe7c:  03 00 01 a4  sethi  %hi(0x69000), %g1
a00cfe80:  a4 10 60 10  or  %g1, 0x10, %l2	! 0x69010
a00cfe84:  a2 10 20 00  clr  %l1
a00cfe88:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00cfe8c:  a1 2c 20 04  sll  %l0, 4, %l0
a00cfe90:  94 04 80 10  add  %l2, %l0, %o2
a00cfe94:  96 10 20 0f  mov  0xf, %o3
a00cfe98:  90 10 20 00  clr  %o0
a00cfe9c:  92 10 20 90  mov  0x90, %o1
a00cfea0:  40 3b 19 58  call  0xa0f96400
a00cfea4:  98 10 00 14  mov  %l4, %o4
a00cfea8:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00cfeac:  82 10 62 50  or  %g1, 0x250, %g1	! 0xa807ce50
a00cfeb0:  96 04 00 01  add  %l0, %g1, %o3
a00cfeb4:  a0 10 20 00  clr  %l0
a00cfeb8:  82 0c 20 ff  and  %l0, 0xff, %g1
a00cfebc:  9a 04 c0 01  add  %l3, %g1, %o5
a00cfec0:  d8 0b 7f f0  ldub  [ %o5 + -16 ], %o4
a00cfec4:  a0 04 20 01  inc  %l0
a00cfec8:  82 02 c0 01  add  %o3, %g1, %g1
a00cfecc:  9a 0c 20 ff  and  %l0, 0xff, %o5
a00cfed0:  80 a3 60 0f  cmp  %o5, 0xf
a00cfed4:  08 bf ff f9  bleu  0xa00cfeb8
a00cfed8:  d8 28 60 06  stb  %o4, [ %g1 + 6 ]
a00cfedc:  a2 04 60 01  inc  %l1
a00cfee0:  82 0c 60 ff  and  %l1, 0xff, %g1
a00cfee4:  80 a0 60 07  cmp  %g1, 7
a00cfee8:  08 bf ff e9  bleu  0xa00cfe8c
a00cfeec:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00cfef0:  15 00 01 a4  sethi  %hi(0x69000), %o2
a00cfef4:  94 12 a0 90  or  %o2, 0x90, %o2	! 0x69090
a00cfef8:  92 10 20 90  mov  0x90, %o1
a00cfefc:  90 10 20 00  clr  %o0
a00cff00:  96 10 20 04  mov  4, %o3
a00cff04:  40 3b 19 3f  call  0xa0f96400
a00cff08:  98 10 00 14  mov  %l4, %o4
a00cff0c:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00cff10:  92 10 62 48  or  %g1, 0x248, %o1	! 0xa807ce48
a00cff14:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00cff18:  94 10 62 50  or  %g1, 0x250, %o2	! 0xa807ce50
a00cff1c:  a0 10 20 00  clr  %l0
a00cff20:  82 0c 20 ff  and  %l0, 0xff, %g1
a00cff24:  9a 04 c0 01  add  %l3, %g1, %o5
a00cff28:  d6 0b 7f f0  ldub  [ %o5 + -16 ], %o3
a00cff2c:  a0 04 20 01  inc  %l0
a00cff30:  9a 00 40 0a  add  %g1, %o2, %o5
a00cff34:  98 0c 20 ff  and  %l0, 0xff, %o4
a00cff38:  d6 2b 60 86  stb  %o3, [ %o5 + 0x86 ]
a00cff3c:  80 a3 20 04  cmp  %o4, 4
a00cff40:  08 bf ff f8  bleu  0xa00cff20
a00cff44:  d6 2a 40 01  stb  %o3, [ %o1 + %g1 ]
a00cff48:  03 00 01 a4  sethi  %hi(0x69000), %g1
a00cff4c:  a4 10 60 95  or  %g1, 0x95, %l2	! 0x69095
a00cff50:  a2 10 20 00  clr  %l1
a00cff54:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00cff58:  a1 2c 20 04  sll  %l0, 4, %l0
a00cff5c:  92 10 20 90  mov  0x90, %o1
a00cff60:  94 04 80 10  add  %l2, %l0, %o2
a00cff64:  96 10 20 0f  mov  0xf, %o3
a00cff68:  90 10 20 00  clr  %o0
a00cff6c:  40 3b 19 25  call  0xa0f96400
a00cff70:  98 10 00 14  mov  %l4, %o4
a00cff74:  13 2a 01 f3  sethi  %hi(0xa807cc00), %o1
a00cff78:  82 12 63 08  or  %o1, 0x308, %g1	! 0xa807cf08
a00cff7c:  96 04 00 01  add  %l0, %g1, %o3
a00cff80:  a0 10 20 00  clr  %l0
a00cff84:  98 0c 20 ff  and  %l0, 0xff, %o4
a00cff88:  82 04 c0 0c  add  %l3, %o4, %g1
a00cff8c:  a0 04 20 01  inc  %l0
a00cff90:  c2 08 7f f0  ldub  [ %g1 + -16 ], %g1
a00cff94:  9a 0c 20 ff  and  %l0, 0xff, %o5
a00cff98:  80 a3 60 0f  cmp  %o5, 0xf
a00cff9c:  08 bf ff fa  bleu  0xa00cff84
a00cffa0:  c2 2a c0 0c  stb  %g1, [ %o3 + %o4 ]
a00cffa4:  a2 04 60 01  inc  %l1
a00cffa8:  82 0c 60 ff  and  %l1, 0xff, %g1
a00cffac:  80 a0 60 17  cmp  %g1, 0x17
a00cffb0:  08 bf ff ea  bleu  0xa00cff58
a00cffb4:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00cffb8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00cffbc:  82 06 00 18  add  %i0, %i0, %g1
a00cffc0:  82 00 40 18  add  %g1, %i0, %g1
a00cffc4:  23 2a 01 e2  sethi  %hi(0xa8078800), %l1
a00cffc8:  9b 28 60 03  sll  %g1, 3, %o5
a00cffcc:  98 14 63 b0  or  %l1, 0x3b0, %o4
a00cffd0:  c2 03 00 0d  ld  [ %o4 + %o5 ], %g1
a00cffd4:  83 30 60 13  srl  %g1, 0x13, %g1
a00cffd8:  80 88 60 01  btst  1, %g1
a00cffdc:  32 80 00 0d  bne,a   0xa00d0010
a00cffe0:  90 10 00 18  mov  %i0, %o0
a00cffe4:  82 03 40 0c  add  %o5, %o4, %g1
a00cffe8:  d0 08 60 09  ldub  [ %g1 + 9 ], %o0
a00cffec:  92 12 63 08  or  %o1, 0x308, %o1
a00cfff0:  94 10 20 00  clr  %o2
a00cfff4:  96 10 20 00  clr  %o3
a00cfff8:  7f ff e6 6b  call  0xa00c99a4
a00cfffc:  98 10 2c 00  mov  0xc00, %o4
a00d0000:  11 2a 01 f3  sethi  %hi(0xa807cc00), %o0
a00d0004:  7f ff e9 39  call  0xa00ca4e8
a00d0008:  90 12 22 51  or  %o0, 0x251, %o0	! 0xa807ce51
a00d000c:  90 10 00 18  mov  %i0, %o0
a00d0010:  92 10 20 03  mov  3, %o1
a00d0014:  7f ff e1 f5  call  0xa00c87e8
a00d0018:  15 00 00 20  sethi  %hi(0x8000), %o2
a00d001c:  15 00 01 a4  sethi  %hi(0x69000), %o2
a00d0020:  94 12 a2 15  or  %o2, 0x215, %o2	! 0x69215
a00d0024:  98 10 00 14  mov  %l4, %o4
a00d0028:  90 10 20 00  clr  %o0
a00d002c:  92 10 20 90  mov  0x90, %o1
a00d0030:  40 3b 18 f4  call  0xa0f96400
a00d0034:  96 10 20 0a  mov  0xa, %o3
a00d0038:  a0 10 20 00  clr  %l0
a00d003c:  82 0c 20 ff  and  %l0, 0xff, %g1
a00d0040:  82 04 c0 01  add  %l3, %g1, %g1
a00d0044:  d4 08 7f f0  ldub  [ %g1 + -16 ], %o2
a00d0048:  90 10 00 18  mov  %i0, %o0
a00d004c:  7f ff dd 82  call  0xa00c7654
a00d0050:  92 10 20 01  mov  1, %o1
a00d0054:  a0 04 20 01  inc  %l0
a00d0058:  82 0c 20 ff  and  %l0, 0xff, %g1
a00d005c:  80 a0 60 0a  cmp  %g1, 0xa
a00d0060:  08 bf ff f9  bleu  0xa00d0044
a00d0064:  82 04 c0 01  add  %l3, %g1, %g1
a00d0068:  c2 0f bf f0  ldub  [ %fp + -16 ], %g1
a00d006c:  80 a0 60 02  cmp  %g1, 2
a00d0070:  02 80 00 08  be  0xa00d0090
a00d0074:  9a 06 00 18  add  %i0, %i0, %o5
a00d0078:  9a 03 40 18  add  %o5, %i0, %o5
a00d007c:  96 14 63 b0  or  %l1, 0x3b0, %o3
a00d0080:  9b 2b 60 03  sll  %o5, 3, %o5
a00d0084:  d8 02 c0 0d  ld  [ %o3 + %o5 ], %o4
a00d0088:  10 80 00 12  b  0xa00d00d0
a00d008c:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00d0090:  c2 0f bf f2  ldub  [ %fp + -14 ], %g1
a00d0094:  80 a0 60 03  cmp  %g1, 3
a00d0098:  12 80 00 09  bne  0xa00d00bc
a00d009c:  01 00 00 00  nop
a00d00a0:  9a 03 40 18  add  %o5, %i0, %o5
a00d00a4:  96 14 63 b0  or  %l1, 0x3b0, %o3
a00d00a8:  9b 2b 60 03  sll  %o5, 3, %o5
a00d00ac:  c2 02 c0 0d  ld  [ %o3 + %o5 ], %g1
a00d00b0:  19 04 00 00  sethi  %hi(0x10000000), %o4
a00d00b4:  10 80 00 08  b  0xa00d00d4
a00d00b8:  82 10 40 0c  or  %g1, %o4, %g1
a00d00bc:  9a 03 40 18  add  %o5, %i0, %o5
a00d00c0:  96 14 63 b0  or  %l1, 0x3b0, %o3
a00d00c4:  9b 2b 60 03  sll  %o5, 3, %o5
a00d00c8:  d8 02 c0 0d  ld  [ %o3 + %o5 ], %o4
a00d00cc:  03 04 00 00  sethi  %hi(0x10000000), %g1
a00d00d0:  82 2b 00 01  andn  %o4, %g1, %g1
a00d00d4:  c2 22 c0 0d  st  %g1, [ %o3 + %o5 ]
a00d00d8:  81 c7 e0 08  ret
a00d00dc:  81 e8 00 00  restore
