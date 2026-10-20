# leon2m FUN_a00fde94 0xa00fde94-0xa00fdf44 (176 bytes)
a00fde94:  9d e3 bf 98  save  %sp, -104, %sp
a00fde98:  a2 0e 20 ff  and  %i0, 0xff, %l1
a00fde9c:  80 a4 60 07  cmp  %l1, 7
a00fdea0:  18 80 00 04  bgu  0xa00fdeb0
a00fdea4:  82 10 20 00  clr  %g1
a00fdea8:  97 2e 20 04  sll  %i0, 4, %o3
a00fdeac:  82 12 c0 18  or  %o3, %i0, %g1
a00fdeb0:  31 33 c0 80  sethi  %hi(0xcf020000), %i0
a00fdeb4:  a0 16 21 0c  or  %i0, 0x10c, %l0	! 0xcf02010c
a00fdeb8:  9e 08 60 ff  and  %g1, 0xff, %o7
a00fdebc:  d8 04 00 00  ld  [ %l0 ], %o4
a00fdec0:  80 a3 00 0f  cmp  %o4, %o7
a00fdec4:  12 80 00 1e  bne  0xa00fdf3c
a00fdec8:  a0 10 20 00  clr  %l0
a00fdecc:  10 80 00 07  b  0xa00fdee8
a00fded0:  b0 10 20 00  clr  %i0
a00fded4:  a0 04 20 01  inc  %l0
a00fded8:  b0 0c 20 ff  and  %l0, 0xff, %i0
a00fdedc:  80 a6 20 07  cmp  %i0, 7
a00fdee0:  18 80 00 17  bgu  0xa00fdf3c
a00fdee4:  01 00 00 00  nop
a00fdee8:  90 10 00 18  mov  %i0, %o0
a00fdeec:  80 a6 00 11  cmp  %i0, %l1
a00fdef0:  02 bf ff f9  be  0xa00fded4
a00fdef4:  92 10 20 04  mov  4, %o1
a00fdef8:  7f ff ce e6  call  0xa00f1a90
a00fdefc:  01 00 00 00  nop
a00fdf00:  80 8a 20 03  btst  3, %o0
a00fdf04:  92 10 20 03  mov  3, %o1
a00fdf08:  12 bf ff f3  bne  0xa00fded4
a00fdf0c:  90 10 00 18  mov  %i0, %o0
a00fdf10:  7f ff ce e0  call  0xa00f1a90
a00fdf14:  01 00 00 00  nop
a00fdf18:  80 8a 20 20  btst  0x20, %o0
a00fdf1c:  32 bf ff ef  bne,a   0xa00fded8
a00fdf20:  a0 04 20 01  inc  %l0
a00fdf24:  95 2c 20 04  sll  %l0, 4, %o2
a00fdf28:  92 12 80 10  or  %o2, %l0, %o1
a00fdf2c:  11 33 c0 80  sethi  %hi(0xcf020000), %o0
a00fdf30:  9a 0a 60 ff  and  %o1, 0xff, %o5
a00fdf34:  82 12 21 0c  or  %o0, 0x10c, %g1
a00fdf38:  da 20 40 00  st  %o5, [ %g1 ]
a00fdf3c:  81 c7 e0 08  ret
a00fdf40:  81 e8 00 00  restore
