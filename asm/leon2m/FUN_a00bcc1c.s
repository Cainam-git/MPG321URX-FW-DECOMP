# leon2m FUN_a00bcc1c 0xa00bcc1c-0xa00bcc64 (72 bytes)
a00bcc1c:  9d e3 bf 98  save  %sp, -104, %sp
a00bcc20:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00bcc24:  d0 0a a3 ce  ldub  [ %o2 + 0x3ce ], %o0	! 0xa802d3ce
a00bcc28:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00bcc2c:  9a 12 60 78  or  %o1, 0x78, %o5	! 0xa802d078
a00bcc30:  98 02 20 30  add  %o0, 0x30, %o4
a00bcc34:  82 10 20 30  mov  0x30, %g1
a00bcc38:  d8 2b 60 09  stb  %o4, [ %o5 + 9 ]
a00bcc3c:  c2 2b 60 08  stb  %g1, [ %o5 + 8 ]
a00bcc40:  c2 2b 60 07  stb  %g1, [ %o5 + 7 ]
a00bcc44:  7f ff f7 fe  call  0xa00bac3c
a00bcc48:  90 10 20 19  mov  0x19, %o0
a00bcc4c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bcc50:  7f ff f7 40  call  0xa00ba950
a00bcc54:  90 10 00 18  mov  %i0, %o0
a00bcc58:  7f ff f7 e3  call  0xa00babe4
a00bcc5c:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bcc60:  01 00 00 00  nop
