# leon2m FUN_a0083b14 0xa0083b14-0xa0083b60 (76 bytes)
a0083b14:  9d e3 bf 98  save  %sp, -104, %sp
a0083b18:  17 2a 00 b3  sethi  %hi(0xa802cc00), %o3
a0083b1c:  d2 12 e3 f4  lduh  [ %o3 + 0x3f4 ], %o1	! 0xa802cff4
a0083b20:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a0083b24:  9a 12 64 00  or  %o1, 0x400, %o5
a0083b28:  d8 08 62 af  ldub  [ %g1 + 0x2af ], %o4
a0083b2c:  90 10 20 00  clr  %o0
a0083b30:  b0 10 20 01  mov  1, %i0
a0083b34:  80 a3 20 00  cmp  %o4, 0
a0083b38:  12 80 00 07  bne  0xa0083b54
a0083b3c:  da 32 e3 f4  sth  %o5, [ %o3 + 0x3f4 ]
a0083b40:  40 03 02 53  call  0xa014448c
a0083b44:  01 00 00 00  nop
a0083b48:  b2 0a 20 ff  and  %o0, 0xff, %i1
a0083b4c:  40 03 17 8b  call  0xa0149978
a0083b50:  81 e8 00 00  restore
a0083b54:  01 00 00 00  nop
a0083b58:  81 c7 e0 08  ret
a0083b5c:  81 e8 00 00  restore
