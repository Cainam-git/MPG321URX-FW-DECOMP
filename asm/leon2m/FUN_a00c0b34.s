# leon2m FUN_a00c0b34 0xa00c0b34-0xa00c0b8c (88 bytes)
a00c0b34:  90 0a 20 ff  and  %o0, 0xff, %o0
a00c0b38:  80 a2 20 02  cmp  %o0, 2
a00c0b3c:  02 80 00 0c  be  0xa00c0b6c
a00c0b40:  80 a2 20 03  cmp  %o0, 3
a00c0b44:  02 80 00 0d  be  0xa00c0b78
a00c0b48:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c0b4c:  c2 0b 60 d8  ldub  [ %o5 + 0xd8 ], %g1	! 0xa802d0d8
a00c0b50:  90 00 7f d0  add  %g1, -48, %o0
a00c0b54:  82 0a 20 ff  and  %o0, 0xff, %g1
a00c0b58:  80 a0 60 64  cmp  %g1, 0x64
a00c0b5c:  18 80 00 0a  bgu  0xa00c0b84
a00c0b60:  90 10 20 ff  mov  0xff, %o0
a00c0b64:  10 80 00 08  b  0xa00c0b84
a00c0b68:  90 10 00 01  mov  %g1, %o0
a00c0b6c:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c0b70:  10 bf ff f8  b  0xa00c0b50
a00c0b74:  c2 08 60 48  ldub  [ %g1 + 0x48 ], %g1	! 0xa802d048
a00c0b78:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c0b7c:  10 bf ff f5  b  0xa00c0b50
a00c0b80:  c2 0a 20 a0  ldub  [ %o0 + 0xa0 ], %g1	! 0xa802d0a0
a00c0b84:  81 c3 e0 08  retl
a00c0b88:  01 00 00 00  nop
