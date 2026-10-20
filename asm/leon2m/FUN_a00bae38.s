# leon2m FUN_a00bae38 0xa00bae38-0xa00baee8 (176 bytes)
a00bae38:  90 0a 20 ff  and  %o0, 0xff, %o0
a00bae3c:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00bae40:  80 a2 20 02  cmp  %o0, 2
a00bae44:  02 80 00 08  be  0xa00bae64
a00bae48:  82 10 60 40  or  %g1, 0x40, %g1
a00bae4c:  80 a2 20 03  cmp  %o0, 3
a00bae50:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00bae54:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00bae58:  9a 12 60 98  or  %o1, 0x98, %o5
a00bae5c:  02 80 00 1d  be  0xa00baed0
a00bae60:  82 12 20 d0  or  %o0, 0xd0, %g1
a00bae64:  d4 08 60 09  ldub  [ %g1 + 9 ], %o2
a00bae68:  d8 08 60 07  ldub  [ %g1 + 7 ], %o4
a00bae6c:  c2 08 60 08  ldub  [ %g1 + 8 ], %g1
a00bae70:  96 00 7f d0  add  %g1, -48, %o3
a00bae74:  98 03 3f d0  add  %o4, -48, %o4
a00bae78:  82 0b 20 ff  and  %o4, 0xff, %g1
a00bae7c:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00bae80:  80 a0 60 01  cmp  %g1, 1
a00bae84:  18 80 00 17  bgu  0xa00baee0
a00bae88:  90 10 20 ff  mov  0xff, %o0
a00bae8c:  94 02 bf d0  add  %o2, -48, %o2
a00bae90:  80 a3 60 09  cmp  %o5, 9
a00bae94:  18 80 00 13  bgu  0xa00baee0
a00bae98:  92 0a a0 ff  and  %o2, 0xff, %o1
a00bae9c:  82 10 00 0d  mov  %o5, %g1
a00baea0:  9b 2b 60 02  sll  %o5, 2, %o5
a00baea4:  96 03 40 01  add  %o5, %g1, %o3
a00baea8:  82 0b 20 ff  and  %o4, 0xff, %g1
a00baeac:  9a 02 c0 0b  add  %o3, %o3, %o5
a00baeb0:  98 58 60 64  smul  %g1, 0x64, %o4
a00baeb4:  82 03 00 0d  add  %o4, %o5, %g1
a00baeb8:  80 a2 60 09  cmp  %o1, 9
a00baebc:  18 80 00 09  bgu  0xa00baee0
a00baec0:  9a 0a a0 ff  and  %o2, 0xff, %o5
a00baec4:  94 00 40 0d  add  %g1, %o5, %o2
a00baec8:  10 80 00 06  b  0xa00baee0
a00baecc:  90 0a a0 ff  and  %o2, 0xff, %o0
a00baed0:  d4 0b 60 09  ldub  [ %o5 + 9 ], %o2
a00baed4:  d8 0b 60 07  ldub  [ %o5 + 7 ], %o4
a00baed8:  10 bf ff e6  b  0xa00bae70
a00baedc:  c2 0b 60 08  ldub  [ %o5 + 8 ], %g1
a00baee0:  81 c3 e0 08  retl
a00baee4:  01 00 00 00  nop
