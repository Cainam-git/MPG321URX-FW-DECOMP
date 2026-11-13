# leon2m FUN_a002be7c 0xa002be7c-0xa002c11c (672 bytes)
a002be7c:  9d e3 bf 98  save  %sp, -104, %sp
a002be80:  25 2a 00 b6  sethi  %hi(0xa802d800), %l2
a002be84:  a0 14 a1 92  or  %l2, 0x192, %l0	! 0xa802d992
a002be88:  d2 14 20 08  lduh  [ %l0 + 8 ], %o1
a002be8c:  15 3f ff f0  sethi  %hi(0xffffc000), %o2
a002be90:  90 0a 40 0a  and  %o1, %o2, %o0
a002be94:  83 2a 20 10  sll  %o0, 0x10, %g1
a002be98:  1b 20 00 00  sethi  %hi(0x80000000), %o5
a002be9c:  80 a0 40 0d  cmp  %g1, %o5
a002bea0:  12 80 00 9c  bne  0xa002c110
a002bea4:  a8 10 20 00  clr  %l4
a002bea8:  7f ff fa 9a  call  0xa002a910
a002beac:  a2 10 00 10  mov  %l0, %l1
a002beb0:  d2 0c 20 03  ldub  [ %l0 + 3 ], %o1
a002beb4:  94 10 20 00  clr  %o2
a002beb8:  40 00 02 6d  call  0xa002c86c
a002bebc:  d0 0c 20 02  ldub  [ %l0 + 2 ], %o0
a002bec0:  d8 14 20 04  lduh  [ %l0 + 4 ], %o4
a002bec4:  97 2b 20 11  sll  %o4, 0x11, %o3
a002bec8:  40 00 04 dd  call  0xa002d23c
a002becc:  91 32 e0 10  srl  %o3, 0x10, %o0
a002bed0:  d2 0c 20 01  ldub  [ %l0 + 1 ], %o1
a002bed4:  d0 0c a1 92  ldub  [ %l2 + 0x192 ], %o0
a002bed8:  40 00 02 65  call  0xa002c86c
a002bedc:  94 10 20 01  mov  1, %o2
a002bee0:  d2 0c 20 01  ldub  [ %l0 + 1 ], %o1
a002bee4:  d0 0c a1 92  ldub  [ %l2 + 0x192 ], %o0
a002bee8:  40 00 03 12  call  0xa002cb30
a002beec:  94 10 20 01  mov  1, %o2
a002bef0:  a0 10 3f ff  mov  -1, %l0
a002bef4:  10 80 00 07  b  0xa002bf10
a002bef8:  a6 10 00 12  mov  %l2, %l3
a002befc:  80 a3 60 00  cmp  %o5, 0
a002bf00:  02 80 00 0d  be  0xa002bf34
a002bf04:  d0 0c e1 92  ldub  [ %l3 + 0x192 ], %o0
a002bf08:  01 00 00 00  nop
a002bf0c:  01 00 00 00  nop
a002bf10:  d0 0c a1 92  ldub  [ %l2 + 0x192 ], %o0
a002bf14:  40 00 03 89  call  0xa002cd38
a002bf18:  d2 0c 60 01  ldub  [ %l1 + 1 ], %o1
a002bf1c:  9e 04 3f ff  add  %l0, -1, %o7
a002bf20:  9b 2b e0 10  sll  %o7, 0x10, %o5
a002bf24:  80 8a 20 ff  btst  0xff, %o0
a002bf28:  02 bf ff f5  be  0xa002befc
a002bf2c:  a0 10 00 0f  mov  %o7, %l0
a002bf30:  d0 0c e1 92  ldub  [ %l3 + 0x192 ], %o0
a002bf34:  d2 0c 60 01  ldub  [ %l1 + 1 ], %o1
a002bf38:  40 00 02 fe  call  0xa002cb30
a002bf3c:  94 10 20 00  clr  %o2
a002bf40:  d2 14 60 04  lduh  [ %l1 + 4 ], %o1
a002bf44:  91 2a 60 11  sll  %o1, 0x11, %o0
a002bf48:  40 00 04 bd  call  0xa002d23c
a002bf4c:  91 32 20 10  srl  %o0, 0x10, %o0
a002bf50:  d2 0c 60 03  ldub  [ %l1 + 3 ], %o1
a002bf54:  94 10 20 01  mov  1, %o2
a002bf58:  40 00 02 45  call  0xa002c86c
a002bf5c:  d0 0c 60 02  ldub  [ %l1 + 2 ], %o0
a002bf60:  c2 14 60 04  lduh  [ %l1 + 4 ], %g1
a002bf64:  9b 28 60 11  sll  %g1, 0x11, %o5
a002bf68:  40 00 04 b5  call  0xa002d23c
a002bf6c:  91 33 60 10  srl  %o5, 0x10, %o0
a002bf70:  7f ff fa 68  call  0xa002a910
a002bf74:  a0 14 a1 92  or  %l2, 0x192, %l0
a002bf78:  7f ff fa e3  call  0xa002ab04
a002bf7c:  90 0e 20 ff  and  %i0, 0xff, %o0
a002bf80:  a8 0a 20 ff  and  %o0, 0xff, %l4
a002bf84:  80 a0 00 14  cmp  %g0, %l4
a002bf88:  b0 60 3f ff  subx  %g0, -1, %i0
a002bf8c:  d2 0c 20 03  ldub  [ %l0 + 3 ], %o1
a002bf90:  94 10 20 00  clr  %o2
a002bf94:  40 00 02 36  call  0xa002c86c
a002bf98:  d0 0c 20 02  ldub  [ %l0 + 2 ], %o0
a002bf9c:  e6 14 20 04  lduh  [ %l0 + 4 ], %l3
a002bfa0:  a3 2c e0 11  sll  %l3, 0x11, %l1
a002bfa4:  40 00 04 a6  call  0xa002d23c
a002bfa8:  91 34 60 10  srl  %l1, 0x10, %o0
a002bfac:  d2 0c 20 01  ldub  [ %l0 + 1 ], %o1
a002bfb0:  d0 0c a1 92  ldub  [ %l2 + 0x192 ], %o0
a002bfb4:  40 00 02 2e  call  0xa002c86c
a002bfb8:  94 10 20 01  mov  1, %o2
a002bfbc:  d2 0c 20 01  ldub  [ %l0 + 1 ], %o1
a002bfc0:  d0 0c a1 92  ldub  [ %l2 + 0x192 ], %o0
a002bfc4:  94 10 20 01  mov  1, %o2
a002bfc8:  a2 10 00 10  mov  %l0, %l1
a002bfcc:  40 00 02 d9  call  0xa002cb30
a002bfd0:  a8 10 00 18  mov  %i0, %l4
a002bfd4:  a0 10 3f ff  mov  -1, %l0
a002bfd8:  10 80 00 07  b  0xa002bff4
a002bfdc:  27 2a 00 b6  sethi  %hi(0xa802d800), %l3
a002bfe0:  80 a3 60 00  cmp  %o5, 0
a002bfe4:  22 80 00 0d  be,a   0xa002c018
a002bfe8:  d2 0c 60 01  ldub  [ %l1 + 1 ], %o1
a002bfec:  01 00 00 00  nop
a002bff0:  01 00 00 00  nop
a002bff4:  d0 0c a1 92  ldub  [ %l2 + 0x192 ], %o0
a002bff8:  40 00 03 50  call  0xa002cd38
a002bffc:  d2 0c 60 01  ldub  [ %l1 + 1 ], %o1
a002c000:  94 04 3f ff  add  %l0, -1, %o2
a002c004:  9b 2a a0 10  sll  %o2, 0x10, %o5
a002c008:  80 8a 20 ff  btst  0xff, %o0
a002c00c:  02 bf ff f5  be  0xa002bfe0
a002c010:  a0 10 00 0a  mov  %o2, %l0
a002c014:  d2 0c 60 01  ldub  [ %l1 + 1 ], %o1
a002c018:  94 10 20 00  clr  %o2
a002c01c:  40 00 02 c5  call  0xa002cb30
a002c020:  d0 0c e1 92  ldub  [ %l3 + 0x192 ], %o0
a002c024:  da 14 60 04  lduh  [ %l1 + 4 ], %o5
a002c028:  b1 2b 60 11  sll  %o5, 0x11, %i0
a002c02c:  40 00 04 84  call  0xa002d23c
a002c030:  91 36 20 10  srl  %i0, 0x10, %o0
a002c034:  d2 0c 60 03  ldub  [ %l1 + 3 ], %o1
a002c038:  94 10 20 01  mov  1, %o2
a002c03c:  40 00 02 0c  call  0xa002c86c
a002c040:  d0 0c 60 02  ldub  [ %l1 + 2 ], %o0
a002c044:  e0 14 60 04  lduh  [ %l1 + 4 ], %l0
a002c048:  9f 2c 20 11  sll  %l0, 0x11, %o7
a002c04c:  91 33 e0 10  srl  %o7, 0x10, %o0
a002c050:  40 00 04 7b  call  0xa002d23c
a002c054:  a0 10 3f ff  mov  -1, %l0
a002c058:  7f ff fa 2e  call  0xa002a910
a002c05c:  01 00 00 00  nop
a002c060:  d2 0c 60 03  ldub  [ %l1 + 3 ], %o1
a002c064:  94 10 20 00  clr  %o2
a002c068:  40 00 02 01  call  0xa002c86c
a002c06c:  d0 0c 60 02  ldub  [ %l1 + 2 ], %o0
a002c070:  d8 14 60 04  lduh  [ %l1 + 4 ], %o4
a002c074:  97 2b 20 11  sll  %o4, 0x11, %o3
a002c078:  40 00 04 71  call  0xa002d23c
a002c07c:  91 32 e0 10  srl  %o3, 0x10, %o0
a002c080:  d0 0c e1 92  ldub  [ %l3 + 0x192 ], %o0
a002c084:  d2 0c 60 01  ldub  [ %l1 + 1 ], %o1
a002c088:  40 00 01 f9  call  0xa002c86c
a002c08c:  94 10 20 01  mov  1, %o2
a002c090:  d0 0c e1 92  ldub  [ %l3 + 0x192 ], %o0
a002c094:  d2 0c 60 01  ldub  [ %l1 + 1 ], %o1
a002c098:  94 10 20 01  mov  1, %o2
a002c09c:  40 00 02 a5  call  0xa002cb30
a002c0a0:  27 2a 00 b6  sethi  %hi(0xa802d800), %l3
a002c0a4:  10 80 00 07  b  0xa002c0c0
a002c0a8:  a2 14 e1 92  or  %l3, 0x192, %l1	! 0xa802d992
a002c0ac:  80 a3 60 00  cmp  %o5, 0
a002c0b0:  02 80 00 0d  be  0xa002c0e4
a002c0b4:  d0 0c e1 92  ldub  [ %l3 + 0x192 ], %o0
a002c0b8:  01 00 00 00  nop
a002c0bc:  01 00 00 00  nop
a002c0c0:  d0 0c a1 92  ldub  [ %l2 + 0x192 ], %o0
a002c0c4:  40 00 03 1d  call  0xa002cd38
a002c0c8:  d2 0c 60 01  ldub  [ %l1 + 1 ], %o1
a002c0cc:  82 04 3f ff  add  %l0, -1, %g1
a002c0d0:  9b 28 60 10  sll  %g1, 0x10, %o5
a002c0d4:  80 8a 20 ff  btst  0xff, %o0
a002c0d8:  02 bf ff f5  be  0xa002c0ac
a002c0dc:  a0 10 00 01  mov  %g1, %l0
a002c0e0:  d0 0c e1 92  ldub  [ %l3 + 0x192 ], %o0
a002c0e4:  d2 0c 60 01  ldub  [ %l1 + 1 ], %o1
a002c0e8:  40 00 02 92  call  0xa002cb30
a002c0ec:  94 10 20 00  clr  %o2
a002c0f0:  e6 14 60 04  lduh  [ %l1 + 4 ], %l3
a002c0f4:  a5 2c e0 11  sll  %l3, 0x11, %l2
a002c0f8:  40 00 04 51  call  0xa002d23c
a002c0fc:  91 34 a0 10  srl  %l2, 0x10, %o0
a002c100:  d2 0c 60 03  ldub  [ %l1 + 3 ], %o1
a002c104:  d0 0c 60 02  ldub  [ %l1 + 2 ], %o0
a002c108:  40 00 01 d9  call  0xa002c86c
a002c10c:  94 10 20 01  mov  1, %o2
a002c110:  b0 0d 20 01  and  %l4, 1, %i0
a002c114:  81 c7 e0 08  ret
a002c118:  81 e8 00 00  restore
