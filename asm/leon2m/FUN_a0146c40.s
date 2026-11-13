# leon2m FUN_a0146c40 0xa0146c40-0xa0146dc0 (384 bytes)
a0146c40:  9d e3 bf 98  save  %sp, -104, %sp
a0146c44:  82 0e 20 ff  and  %i0, 0xff, %g1
a0146c48:  80 a0 60 07  cmp  %g1, 7
a0146c4c:  38 80 00 08  bgu,a   0xa0146c6c
a0146c50:  80 8e 60 ff  btst  0xff, %i1
a0146c54:  11 00 03 8c  sethi  %hi(0xe3000), %o0
a0146c58:  83 28 60 02  sll  %g1, 2, %g1
a0146c5c:  9a 12 23 60  or  %o0, 0x360, %o5
a0146c60:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a0146c64:  81 c3 00 00  jmp  %o4
a0146c68:  01 00 00 00  nop
a0146c6c:  02 80 00 1a  be  0xa0146cd4
a0146c70:  b2 0e a0 ff  and  %i2, 0xff, %i1
a0146c74:  90 10 20 00  clr  %o0
a0146c78:  7f ff 4d 4e  call  0xa011a1b0
a0146c7c:  92 10 00 19  mov  %i1, %o1
a0146c80:  90 10 20 01  mov  1, %o0
a0146c84:  7f ff 4d 4b  call  0xa011a1b0
a0146c88:  92 10 00 19  mov  %i1, %o1
a0146c8c:  90 10 20 02  mov  2, %o0
a0146c90:  7f ff 4d 48  call  0xa011a1b0
a0146c94:  92 10 00 19  mov  %i1, %o1
a0146c98:  90 10 20 03  mov  3, %o0
a0146c9c:  7f ff 4d 45  call  0xa011a1b0
a0146ca0:  92 10 00 19  mov  %i1, %o1
a0146ca4:  90 10 20 04  mov  4, %o0
a0146ca8:  7f ff 4d 42  call  0xa011a1b0
a0146cac:  92 10 00 19  mov  %i1, %o1
a0146cb0:  90 10 20 05  mov  5, %o0
a0146cb4:  7f ff 4d 3f  call  0xa011a1b0
a0146cb8:  92 10 00 19  mov  %i1, %o1
a0146cbc:  90 10 20 06  mov  6, %o0
a0146cc0:  7f ff 4d 3c  call  0xa011a1b0
a0146cc4:  92 10 00 19  mov  %i1, %o1
a0146cc8:  b0 10 20 07  mov  7, %i0
a0146ccc:  7f ff 4d 39  call  0xa011a1b0
a0146cd0:  81 e8 00 00  restore
a0146cd4:  7f ff 4d a9  call  0xa011a378
a0146cd8:  91 e8 20 08  restore  %g0, 8, %o0
a0146cdc:  80 8e 60 ff  btst  0xff, %i1
a0146ce0:  02 80 00 35  be  0xa0146db4
a0146ce4:  b2 0e a0 ff  and  %i2, 0xff, %i1
a0146ce8:  7f ff 4d 32  call  0xa011a1b0
a0146cec:  91 e8 20 03  restore  %g0, 3, %o0
a0146cf0:  80 8e 60 ff  btst  0xff, %i1
a0146cf4:  02 80 00 2e  be  0xa0146dac
a0146cf8:  b2 0e a0 ff  and  %i2, 0xff, %i1
a0146cfc:  7f ff 4d 2d  call  0xa011a1b0
a0146d00:  91 e8 20 04  restore  %g0, 4, %o0
a0146d04:  80 8e 60 ff  btst  0xff, %i1
a0146d08:  02 80 00 27  be  0xa0146da4
a0146d0c:  b2 0e a0 ff  and  %i2, 0xff, %i1
a0146d10:  7f ff 4d 28  call  0xa011a1b0
a0146d14:  91 e8 20 05  restore  %g0, 5, %o0
a0146d18:  80 8e 60 ff  btst  0xff, %i1
a0146d1c:  02 80 00 20  be  0xa0146d9c
a0146d20:  b2 0e a0 ff  and  %i2, 0xff, %i1
a0146d24:  7f ff 4d 23  call  0xa011a1b0
a0146d28:  91 e8 20 06  restore  %g0, 6, %o0
a0146d2c:  80 8e 60 ff  btst  0xff, %i1
a0146d30:  02 80 00 19  be  0xa0146d94
a0146d34:  b2 0e a0 ff  and  %i2, 0xff, %i1
a0146d38:  7f ff 4d 1e  call  0xa011a1b0
a0146d3c:  91 e8 20 01  restore  %g0, 1, %o0
a0146d40:  80 8e 60 ff  btst  0xff, %i1
a0146d44:  02 80 00 12  be  0xa0146d8c
a0146d48:  b2 0e a0 ff  and  %i2, 0xff, %i1
a0146d4c:  7f ff 4d 19  call  0xa011a1b0
a0146d50:  91 e8 20 02  restore  %g0, 2, %o0
a0146d54:  80 8e 60 ff  btst  0xff, %i1
a0146d58:  02 80 00 0b  be  0xa0146d84
a0146d5c:  b2 0e a0 ff  and  %i2, 0xff, %i1
a0146d60:  7f ff 4d 14  call  0xa011a1b0
a0146d64:  91 e8 20 00  restore  %g0, 0, %o0
a0146d68:  80 8e 60 ff  btst  0xff, %i1
a0146d6c:  02 80 00 04  be  0xa0146d7c
a0146d70:  b2 0e a0 ff  and  %i2, 0xff, %i1
a0146d74:  10 bf ff d6  b  0xa0146ccc
a0146d78:  b0 10 20 07  mov  7, %i0
a0146d7c:  7f ff 4d 7f  call  0xa011a378
a0146d80:  91 e8 20 07  restore  %g0, 7, %o0
a0146d84:  7f ff 4d 7d  call  0xa011a378
a0146d88:  91 e8 20 00  restore  %g0, 0, %o0
a0146d8c:  7f ff 4d 7b  call  0xa011a378
a0146d90:  91 e8 20 02  restore  %g0, 2, %o0
a0146d94:  7f ff 4d 79  call  0xa011a378
a0146d98:  91 e8 20 01  restore  %g0, 1, %o0
a0146d9c:  7f ff 4d 77  call  0xa011a378
a0146da0:  91 e8 20 06  restore  %g0, 6, %o0
a0146da4:  7f ff 4d 75  call  0xa011a378
a0146da8:  91 e8 20 05  restore  %g0, 5, %o0
a0146dac:  7f ff 4d 73  call  0xa011a378
a0146db0:  91 e8 20 04  restore  %g0, 4, %o0
a0146db4:  7f ff 4d 71  call  0xa011a378
a0146db8:  91 e8 20 03  restore  %g0, 3, %o0
a0146dbc:  01 00 00 00  nop
