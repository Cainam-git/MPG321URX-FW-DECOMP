# leon2m FUN_a0082dc4 0xa0082dc4-0xa0082ec4 (256 bytes)
a0082dc4:  9d e3 bf 98  save  %sp, -104, %sp
a0082dc8:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a0082dcc:  92 14 a2 90  or  %l2, 0x290, %o1	! 0xa802d290
a0082dd0:  da 0a 60 39  ldub  [ %o1 + 0x39 ], %o5
a0082dd4:  96 03 7f ff  add  %o5, -1, %o3
a0082dd8:  de 0a 60 37  ldub  [ %o1 + 0x37 ], %o7
a0082ddc:  9b 3a e0 1f  sra  %o3, 0x1f, %o5
a0082de0:  81 83 60 00  mov  %o5, %y
a0082de4:  01 00 00 00  nop
a0082de8:  01 00 00 00  nop
a0082dec:  01 00 00 00  nop
a0082df0:  94 7a c0 0f  sdiv  %o3, %o7, %o2
a0082df4:  e4 0a 60 38  ldub  [ %o1 + 0x38 ], %l2
a0082df8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0082dfc:  a2 02 a0 01  add  %o2, 1, %l1
a0082e00:  92 10 20 08  mov  8, %o1
a0082e04:  40 03 0a 17  call  0xa0145660
a0082e08:  90 10 00 18  mov  %i0, %o0
a0082e0c:  a0 10 00 08  mov  %o0, %l0
a0082e10:  90 10 00 18  mov  %i0, %o0
a0082e14:  40 03 0a 13  call  0xa0145660
a0082e18:  92 10 20 0f  mov  0xf, %o1
a0082e1c:  b0 10 00 08  mov  %o0, %i0
a0082e20:  a2 0c 60 ff  and  %l1, 0xff, %l1
a0082e24:  11 00 03 fb  sethi  %hi(0xfec00), %o0
a0082e28:  94 10 00 11  mov  %l1, %o2
a0082e2c:  92 10 00 12  mov  %l2, %o1
a0082e30:  40 01 70 d0  call  0xa00df170
a0082e34:  90 12 22 b8  or  %o0, 0x2b8, %o0
a0082e38:  83 2c 20 10  sll  %l0, 0x10, %g1
a0082e3c:  95 30 60 10  srl  %g1, 0x10, %o2
a0082e40:  83 3a a0 1f  sra  %o2, 0x1f, %g1
a0082e44:  81 80 60 00  mov  %g1, %y
a0082e48:  01 00 00 00  nop
a0082e4c:  01 00 00 00  nop
a0082e50:  01 00 00 00  nop
a0082e54:  98 7a 80 12  sdiv  %o2, %l2, %o4
a0082e58:  99 33 20 01  srl  %o4, 1, %o4
a0082e5c:  9e 03 00 0c  add  %o4, %o4, %o7
a0082e60:  96 5b c0 12  smul  %o7, %l2, %o3
a0082e64:  92 22 80 0b  sub  %o2, %o3, %o1
a0082e68:  9b 3a 60 1f  sra  %o1, 0x1f, %o5
a0082e6c:  a0 1b 40 09  xor  %o5, %o1, %l0
a0082e70:  9a 24 00 0d  sub  %l0, %o5, %o5
a0082e74:  90 0b 60 ff  and  %o5, 0xff, %o0
a0082e78:  83 32 20 01  srl  %o0, 1, %g1
a0082e7c:  94 04 7f ff  add  %l1, -1, %o2
a0082e80:  98 03 00 0c  add  %o4, %o4, %o4
a0082e84:  80 a4 40 01  cmp  %l1, %g1
a0082e88:  96 10 00 0c  mov  %o4, %o3
a0082e8c:  18 80 00 04  bgu  0xa0082e9c
a0082e90:  a2 04 40 11  add  %l1, %l1, %l1
a0082e94:  96 03 20 02  add  %o4, 2, %o3
a0082e98:  9a 04 7f fe  add  %l1, -2, %o5
a0082e9c:  93 2a e0 10  sll  %o3, 0x10, %o1
a0082ea0:  a3 32 60 10  srl  %o1, 0x10, %l1
a0082ea4:  a0 5c 40 0a  smul  %l1, %o2, %l0
a0082ea8:  90 0b 60 ff  and  %o5, 0xff, %o0
a0082eac:  82 04 00 08  add  %l0, %o0, %g1
a0082eb0:  98 00 40 18  add  %g1, %i0, %o4
a0082eb4:  d8 36 80 00  sth  %o4, [ %i2 ]
a0082eb8:  d6 36 40 00  sth  %o3, [ %i1 ]
a0082ebc:  81 c7 e0 08  ret
a0082ec0:  81 e8 00 00  restore
