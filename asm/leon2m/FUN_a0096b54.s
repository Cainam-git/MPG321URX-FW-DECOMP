# leon2m FUN_a0096b54 0xa0096b54-0xa0096bd8 (132 bytes)
a0096b54:  9d e3 bf 98  save  %sp, -104, %sp
a0096b58:  21 2a 00 b3  sethi  %hi(0xa802cc00), %l0
a0096b5c:  9e 14 23 f4  or  %l0, 0x3f4, %o7	! 0xa802cff4
a0096b60:  13 2a 00 ac  sethi  %hi(0xa802b000), %o1
a0096b64:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a0096b68:  d8 0a 60 8e  ldub  [ %o1 + 0x8e ], %o4
a0096b6c:  d4 13 e0 04  lduh  [ %o7 + 4 ], %o2
a0096b70:  17 3f ff e0  sethi  %hi(0xffff8000), %o3
a0096b74:  c2 04 23 ec  ld  [ %l0 + 0x3ec ], %g1
a0096b78:  90 0a 80 0b  and  %o2, %o3, %o0
a0096b7c:  9a 00 7f 90  add  %g1, -112, %o5
a0096b80:  98 13 20 02  or  %o4, 2, %o4
a0096b84:  97 2a 20 10  sll  %o0, 0x10, %o3
a0096b88:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a0096b8c:  d8 2a 60 8e  stb  %o4, [ %o1 + 0x8e ]
a0096b90:  94 12 a4 00  or  %o2, 0x400, %o2
a0096b94:  da 28 60 34  stb  %o5, [ %g1 + 0x34 ]
a0096b98:  80 a2 e0 00  cmp  %o3, 0
a0096b9c:  90 10 20 04  mov  4, %o0
a0096ba0:  12 80 00 06  bne  0xa0096bb8
a0096ba4:  92 10 20 00  clr  %o1
a0096ba8:  40 00 79 36  call  0xa00b5080
a0096bac:  c0 24 23 ec  clr  [ %l0 + 0x3ec ]
a0096bb0:  7f ff ff 2a  call  0xa0096858
a0096bb4:  81 e8 00 00  restore
a0096bb8:  d4 33 e0 04  sth  %o2, [ %o7 + 4 ]
a0096bbc:  7f ff a7 3c  call  0xa00808ac
a0096bc0:  01 00 00 00  nop
a0096bc4:  40 00 79 2f  call  0xa00b5080
a0096bc8:  c0 24 23 ec  clr  [ %l0 + 0x3ec ]
a0096bcc:  7f ff ff 23  call  0xa0096858
a0096bd0:  81 e8 00 00  restore
a0096bd4:  01 00 00 00  nop
