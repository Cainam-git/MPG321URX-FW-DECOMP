# leon2m FUN_a00bcb38 0xa00bcb38-0xa00bcb80 (72 bytes)
a00bcb38:  9d e3 bf 98  save  %sp, -104, %sp
a00bcb3c:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00bcb40:  d0 02 a3 40  ld  [ %o2 + 0x340 ], %o0	! 0xa802d340
a00bcb44:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00bcb48:  9a 12 60 78  or  %o1, 0x78, %o5	! 0xa802d078
a00bcb4c:  98 02 20 30  add  %o0, 0x30, %o4
a00bcb50:  82 10 20 30  mov  0x30, %g1
a00bcb54:  d8 2b 60 09  stb  %o4, [ %o5 + 9 ]
a00bcb58:  c2 2b 60 08  stb  %g1, [ %o5 + 8 ]
a00bcb5c:  c2 2b 60 07  stb  %g1, [ %o5 + 7 ]
a00bcb60:  7f ff f8 37  call  0xa00bac3c
a00bcb64:  90 10 20 16  mov  0x16, %o0
a00bcb68:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bcb6c:  7f ff f7 79  call  0xa00ba950
a00bcb70:  90 10 00 18  mov  %i0, %o0
a00bcb74:  7f ff f8 1c  call  0xa00babe4
a00bcb78:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bcb7c:  01 00 00 00  nop
