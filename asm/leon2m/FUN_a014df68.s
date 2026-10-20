# leon2m FUN_a014df68 0xa014df68-0xa014e010 (168 bytes)
a014df68:  9d e3 bf 98  save  %sp, -104, %sp
a014df6c:  7f ff 5c 8b  call  0xa0125198
a014df70:  90 0e 20 ff  and  %i0, 0xff, %o0
a014df74:  7f ff d0 a9  call  0xa0142218
a014df78:  90 0a 20 ff  and  %o0, 0xff, %o0
a014df7c:  7f ff d0 92  call  0xa01421c4
a014df80:  90 0a 20 ff  and  %o0, 0xff, %o0
a014df84:  21 2a 00 b8  sethi  %hi(0xa802e000), %l0
a014df88:  da 04 23 d0  ld  [ %l0 + 0x3d0 ], %o5	! 0xa802e3d0
a014df8c:  94 0e 60 01  and  %i1, 1, %o2
a014df90:  17 00 04 00  sethi  %hi(0x100000), %o3
a014df94:  92 2b 40 0b  andn  %o5, %o3, %o1
a014df98:  b3 2a a0 14  sll  %o2, 0x14, %i1
a014df9c:  82 12 40 19  or  %o1, %i1, %g1
a014dfa0:  9a 0a 20 ff  and  %o0, 0xff, %o5
a014dfa4:  b2 10 20 00  clr  %i1
a014dfa8:  90 10 20 10  mov  0x10, %o0
a014dfac:  92 10 20 01  mov  1, %o1
a014dfb0:  80 a3 60 71  cmp  %o5, 0x71
a014dfb4:  02 80 00 11  be  0xa014dff8
a014dfb8:  c2 24 23 d0  st  %g1, [ %l0 + 0x3d0 ]
a014dfbc:  80 a3 60 81  cmp  %o5, 0x81
a014dfc0:  02 80 00 0b  be  0xa014dfec
a014dfc4:  b2 10 3f ff  mov  -1, %i1
a014dfc8:  90 0e 60 ff  and  %i1, 0xff, %o0
a014dfcc:  80 a2 20 ff  cmp  %o0, 0xff
a014dfd0:  02 80 00 0e  be  0xa014e008
a014dfd4:  b0 10 00 08  mov  %o0, %i0
a014dfd8:  de 04 23 d0  ld  [ %l0 + 0x3d0 ], %o7
a014dfdc:  99 33 e0 14  srl  %o7, 0x14, %o4
a014dfe0:  b2 0b 20 01  and  %o4, 1, %i1
a014dfe4:  7f ff 76 31  call  0xa012b8a8
a014dfe8:  81 e8 00 00  restore
a014dfec:  b2 10 20 01  mov  1, %i1
a014dff0:  90 10 20 20  mov  0x20, %o0
a014dff4:  92 10 20 01  mov  1, %o1
a014dff8:  40 00 0e ab  call  0xa0151aa4
a014dffc:  01 00 00 00  nop
a014e000:  10 bf ff f3  b  0xa014dfcc
a014e004:  90 0e 60 ff  and  %i1, 0xff, %o0
a014e008:  81 c7 e0 08  ret
a014e00c:  81 e8 00 00  restore
