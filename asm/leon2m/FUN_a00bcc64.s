# leon2m FUN_a00bcc64 0xa00bcc64-0xa00bccac (72 bytes)
a00bcc64:  9d e3 bf 98  save  %sp, -104, %sp
a00bcc68:  15 2a 00 b5  sethi  %hi(0xa802d400), %o2
a00bcc6c:  d0 0a a0 30  ldub  [ %o2 + 0x30 ], %o0	! 0xa802d430
a00bcc70:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00bcc74:  9a 12 60 78  or  %o1, 0x78, %o5	! 0xa802d078
a00bcc78:  98 02 20 30  add  %o0, 0x30, %o4
a00bcc7c:  82 10 20 30  mov  0x30, %g1
a00bcc80:  d8 2b 60 09  stb  %o4, [ %o5 + 9 ]
a00bcc84:  c2 2b 60 08  stb  %g1, [ %o5 + 8 ]
a00bcc88:  c2 2b 60 07  stb  %g1, [ %o5 + 7 ]
a00bcc8c:  7f ff f7 ec  call  0xa00bac3c
a00bcc90:  90 10 20 1a  mov  0x1a, %o0
a00bcc94:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bcc98:  7f ff f7 2e  call  0xa00ba950
a00bcc9c:  90 10 00 18  mov  %i0, %o0
a00bcca0:  7f ff f7 d1  call  0xa00babe4
a00bcca4:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bcca8:  01 00 00 00  nop
