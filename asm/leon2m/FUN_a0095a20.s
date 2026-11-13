# leon2m FUN_a0095a20 0xa0095a20-0xa0095acc (172 bytes)
a0095a20:  9d e3 bf 98  save  %sp, -104, %sp
a0095a24:  40 00 4c 99  call  0xa00a8c88
a0095a28:  01 00 00 00  nop
a0095a2c:  90 10 20 03  mov  3, %o0	! 0x3
a0095a30:  92 10 20 00  clr  %o1
a0095a34:  40 02 c4 83  call  0xa0146c40
a0095a38:  94 10 20 00  clr  %o2
a0095a3c:  94 10 20 00  clr  %o2
a0095a40:  90 10 20 04  mov  4, %o0
a0095a44:  40 02 c4 7f  call  0xa0146c40
a0095a48:  92 10 20 00  clr  %o1
a0095a4c:  40 00 4a 1e  call  0xa00a82c4
a0095a50:  01 00 00 00  nop
a0095a54:  1f 2a 00 97  sethi  %hi(0xa8025c00), %o7
a0095a58:  96 10 20 3f  mov  0x3f, %o3
a0095a5c:  13 2a 00 ab  sethi  %hi(0xa802ac00), %o1
a0095a60:  d8 0b e0 56  ldub  [ %o7 + 0x56 ], %o4
a0095a64:  15 2a 00 b5  sethi  %hi(0xa802d400), %o2
a0095a68:  d6 22 63 ec  st  %o3, [ %o1 + 0x3ec ]
a0095a6c:  d8 2a a0 20  stb  %o4, [ %o2 + 0x20 ]
a0095a70:  90 10 20 00  clr  %o0
a0095a74:  40 00 4e f7  call  0xa00a9650
a0095a78:  92 10 20 01  mov  1, %o1
a0095a7c:  90 10 20 02  mov  2, %o0
a0095a80:  40 00 4e 7a  call  0xa00a9468
a0095a84:  92 10 20 05  mov  5, %o1
a0095a88:  90 10 20 00  clr  %o0
a0095a8c:  40 00 4e 77  call  0xa00a9468
a0095a90:  92 10 20 00  clr  %o1
a0095a94:  90 10 20 01  mov  1, %o0
a0095a98:  40 00 4e 74  call  0xa00a9468
a0095a9c:  92 10 20 02  mov  2, %o1
a0095aa0:  90 10 20 00  clr  %o0
a0095aa4:  40 00 76 8c  call  0xa00b34d4
a0095aa8:  92 10 20 01  mov  1, %o1
a0095aac:  40 00 76 68  call  0xa00b344c
a0095ab0:  90 10 20 07  mov  7, %o0
a0095ab4:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a0095ab8:  d0 0b 60 8e  ldub  [ %o5 + 0x8e ], %o0	! 0xa802b08e
a0095abc:  82 12 20 02  or  %o0, 2, %g1
a0095ac0:  c2 2b 60 8e  stb  %g1, [ %o5 + 0x8e ]
a0095ac4:  81 c7 e0 08  ret
a0095ac8:  81 e8 00 00  restore
