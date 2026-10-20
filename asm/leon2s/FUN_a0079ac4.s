# leon2s FUN_a0079ac4 0xa0079ac4-0xa0079b84 (192 bytes)
a0079ac4:  9d e3 bf 98  save  %sp, -104, %sp
a0079ac8:  b2 0e 60 ff  and  %i1, 0xff, %i1
a0079acc:  a2 06 40 19  add  %i1, %i1, %l1
a0079ad0:  80 a6 60 03  cmp  %i1, 3
a0079ad4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0079ad8:  90 10 00 18  mov  %i0, %o0
a0079adc:  b2 10 20 00  clr  %i1
a0079ae0:  98 10 20 00  clr  %o4
a0079ae4:  18 80 00 11  bgu  0xa0079b28
a0079ae8:  a4 10 20 00  clr  %l2
a0079aec:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a0079af0:  82 10 62 f4  or  %g1, 0x2f4, %g1	! 0xa00b3af4
a0079af4:  d2 10 40 11  lduh  [ %g1 + %l1 ], %o1
a0079af8:  40 00 b6 07  call  0xa00a7314
a0079afc:  21 00 00 07  sethi  %hi(0x1c00), %l0
a0079b00:  a0 14 23 00  or  %l0, 0x300, %l0	! 0x1f00
a0079b04:  90 0a 00 10  and  %o0, %l0, %o0
a0079b08:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a0079b0c:  82 10 62 ec  or  %g1, 0x2ec, %g1	! 0xa00b3aec
a0079b10:  b3 32 20 08  srl  %o0, 8, %i1
a0079b14:  d2 10 40 11  lduh  [ %g1 + %l1 ], %o1
a0079b18:  40 00 b5 ff  call  0xa00a7314
a0079b1c:  90 10 00 18  mov  %i0, %o0
a0079b20:  90 0a 00 10  and  %o0, %l0, %o0
a0079b24:  99 32 20 08  srl  %o0, 8, %o4
a0079b28:  98 1b 20 10  xor  %o4, 0x10, %o4
a0079b2c:  96 1e 60 10  xor  %i1, 0x10, %o3
a0079b30:  9a 0a e0 ff  and  %o3, 0xff, %o5
a0079b34:  82 0b 20 ff  and  %o4, 0xff, %g1
a0079b38:  b4 0e a0 ff  and  %i2, 0xff, %i2
a0079b3c:  80 a3 40 01  cmp  %o5, %g1
a0079b40:  18 80 00 03  bgu  0xa0079b4c
a0079b44:  90 10 00 0c  mov  %o4, %o0
a0079b48:  90 10 00 0b  mov  %o3, %o0
a0079b4c:  80 a6 a0 06  cmp  %i2, 6
a0079b50:  12 80 00 07  bne  0xa0079b6c
a0079b54:  90 0a 20 ff  and  %o0, 0xff, %o0
a0079b58:  80 a2 20 17  cmp  %o0, 0x17
a0079b5c:  82 60 20 00  subx  %g0, 0, %g1
a0079b60:  82 08 60 04  and  %g1, 4, %g1
a0079b64:  10 80 00 05  b  0xa0079b78
a0079b68:  a4 00 60 04  add  %g1, 4, %l2
a0079b6c:  80 a6 a0 05  cmp  %i2, 5
a0079b70:  22 80 00 02  be,a   0xa0079b78
a0079b74:  a4 10 20 02  mov  2, %l2
a0079b78:  b0 0c a0 0e  and  %l2, 0xe, %i0
a0079b7c:  81 c7 e0 08  ret
a0079b80:  81 e8 00 00  restore
