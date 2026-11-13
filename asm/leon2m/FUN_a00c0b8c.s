# leon2m FUN_a00c0b8c 0xa00c0b8c-0xa00c0be4 (88 bytes)
a00c0b8c:  90 0a 20 ff  and  %o0, 0xff, %o0
a00c0b90:  80 a2 20 02  cmp  %o0, 2
a00c0b94:  02 80 00 0c  be  0xa00c0bc4
a00c0b98:  80 a2 20 03  cmp  %o0, 3
a00c0b9c:  02 80 00 0d  be  0xa00c0bd0
a00c0ba0:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c0ba4:  c2 0b 60 d9  ldub  [ %o5 + 0xd9 ], %g1	! 0xa802d0d9
a00c0ba8:  90 00 7f d0  add  %g1, -48, %o0
a00c0bac:  82 0a 20 ff  and  %o0, 0xff, %g1
a00c0bb0:  80 a0 60 64  cmp  %g1, 0x64
a00c0bb4:  18 80 00 0a  bgu  0xa00c0bdc
a00c0bb8:  90 10 20 ff  mov  0xff, %o0
a00c0bbc:  10 80 00 08  b  0xa00c0bdc
a00c0bc0:  90 10 00 01  mov  %g1, %o0
a00c0bc4:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c0bc8:  10 bf ff f8  b  0xa00c0ba8
a00c0bcc:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00c0bd0:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c0bd4:  10 bf ff f5  b  0xa00c0ba8
a00c0bd8:  c2 0a 20 a1  ldub  [ %o0 + 0xa1 ], %g1	! 0xa802d0a1
a00c0bdc:  81 c3 e0 08  retl
a00c0be0:  01 00 00 00  nop
