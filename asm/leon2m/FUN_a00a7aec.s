# leon2m FUN_a00a7aec 0xa00a7aec-0xa00a7c88 (364 bytes)
a00a7aec:  9d e3 bf 90  save  %sp, -112, %sp
a00a7af0:  80 8e 20 ff  btst  0xff, %i0
a00a7af4:  a6 10 20 00  clr  %l3
a00a7af8:  82 10 20 09  mov  9, %g1
a00a7afc:  12 80 00 04  bne  0xa00a7b0c
a00a7b00:  98 10 20 07  mov  7, %o4
a00a7b04:  82 10 20 07  mov  7, %g1
a00a7b08:  98 10 20 00  clr  %o4
a00a7b0c:  a8 08 60 ff  and  %g1, 0xff, %l4
a00a7b10:  82 0b 20 ff  and  %o4, 0xff, %g1
a00a7b14:  80 a0 40 14  cmp  %g1, %l4
a00a7b18:  1a 80 00 5a  bcc  0xa00a7c80
a00a7b1c:  a2 10 00 0c  mov  %o4, %l1
a00a7b20:  96 10 00 01  mov  %g1, %o3
a00a7b24:  80 a0 60 08  cmp  %g1, 8
a00a7b28:  18 80 00 0a  bgu  0xa00a7b50
a00a7b2c:  19 09 24 92  sethi  %hi(0x24924800), %o4
a00a7b30:  11 00 01 0e  sethi  %hi(0x43800), %o0
a00a7b34:  83 28 60 02  sll  %g1, 2, %g1
a00a7b38:  9a 12 20 54  or  %o0, 0x54, %o5
a00a7b3c:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a00a7b40:  81 c3 00 00  jmp  %o4
a00a7b44:  01 00 00 00  nop
a00a7b48:  a6 10 20 70  mov  0x70, %l3	! 0x70
a00a7b4c:  19 09 24 92  sethi  %hi(0x24924800), %o4
a00a7b50:  b0 13 21 25  or  %o4, 0x125, %i0	! 0x24924925
a00a7b54:  80 52 c0 18  umul  %o3, %i0, %g0
a00a7b58:  9f 40 00 00  rd  %y, %o7
a00a7b5c:  a4 22 c0 0f  sub  %o3, %o7, %l2
a00a7b60:  a1 34 a0 01  srl  %l2, 1, %l0
a00a7b64:  94 03 c0 10  add  %o7, %l0, %o2
a00a7b68:  9b 32 a0 02  srl  %o2, 2, %o5
a00a7b6c:  92 04 7f fa  add  %l1, -6, %o1
a00a7b70:  90 0a 60 ff  and  %o1, 0xff, %o0
a00a7b74:  83 2b 60 03  sll  %o5, 3, %g1
a00a7b78:  80 a2 20 02  cmp  %o0, 2
a00a7b7c:  98 20 40 0d  sub  %g1, %o5, %o4
a00a7b80:  b0 22 c0 0c  sub  %o3, %o4, %i0
a00a7b84:  a0 60 20 00  subx  %g0, 0, %l0
a00a7b88:  80 a0 00 0b  cmp  %g0, %o3
a00a7b8c:  a4 0e 20 ff  and  %i0, 0xff, %l2
a00a7b90:  b0 04 80 12  add  %l2, %l2, %i0
a00a7b94:  9e 0c 20 01  and  %l0, 1, %o7
a00a7b98:  96 60 3f ff  subx  %g0, -1, %o3
a00a7b9c:  80 93 c0 0b  orcc  %o7, %o3, %g0
a00a7ba0:  02 80 00 28  be  0xa00a7c40
a00a7ba4:  a4 06 20 06  add  %i0, 6, %l2
a00a7ba8:  94 06 20 05  add  %i0, 5, %o2
a00a7bac:  21 00 00 18  sethi  %hi(0x6000), %l0
a00a7bb0:  9e 0c e0 ff  and  %l3, 0xff, %o7
a00a7bb4:  98 0a a0 ff  and  %o2, 0xff, %o4
a00a7bb8:  de 23 a0 5c  st  %o7, [ %sp + 0x5c ]
a00a7bbc:  94 14 22 9a  or  %l0, 0x29a, %o2
a00a7bc0:  90 10 20 01  mov  1, %o0
a00a7bc4:  92 10 20 01  mov  1, %o1
a00a7bc8:  96 10 20 02  mov  2, %o3
a00a7bcc:  40 00 2d c6  call  0xa00b32e4
a00a7bd0:  9a 10 20 03  mov  3, %o5
a00a7bd4:  92 04 e0 03  add  %l3, 3, %o1
a00a7bd8:  90 0a 60 ff  and  %o1, 0xff, %o0
a00a7bdc:  d0 23 a0 5c  st  %o0, [ %sp + 0x5c ]
a00a7be0:  98 0c a0 fe  and  %l2, 0xfe, %o4
a00a7be4:  94 14 22 9a  or  %l0, 0x29a, %o2
a00a7be8:  96 10 20 02  mov  2, %o3
a00a7bec:  9a 10 20 03  mov  3, %o5
a00a7bf0:  90 10 20 01  mov  1, %o0
a00a7bf4:  40 00 2d bc  call  0xa00b32e4
a00a7bf8:  92 10 20 01  mov  1, %o1
a00a7bfc:  9a 04 e0 06  add  %l3, 6, %o5
a00a7c00:  96 06 20 07  add  %i0, 7, %o3
a00a7c04:  82 0b 60 ff  and  %o5, 0xff, %g1
a00a7c08:  c2 23 a0 5c  st  %g1, [ %sp + 0x5c ]
a00a7c0c:  94 14 22 9a  or  %l0, 0x29a, %o2
a00a7c10:  98 0a e0 ff  and  %o3, 0xff, %o4
a00a7c14:  96 10 20 02  mov  2, %o3
a00a7c18:  90 10 20 01  mov  1, %o0
a00a7c1c:  92 10 20 01  mov  1, %o1
a00a7c20:  40 00 2d b1  call  0xa00b32e4
a00a7c24:  9a 10 20 03  mov  3, %o5
a00a7c28:  a2 04 60 01  inc  %l1
a00a7c2c:  96 0c 60 ff  and  %l1, 0xff, %o3
a00a7c30:  80 a2 c0 14  cmp  %o3, %l4
a00a7c34:  0a bf ff bc  bcs  0xa00a7b24
a00a7c38:  82 10 00 0b  mov  %o3, %g1
a00a7c3c:  30 80 00 11  b,a   0xa00a7c80
a00a7c40:  98 0c e0 ff  and  %l3, 0xff, %o4
a00a7c44:  d8 23 a0 5c  st  %o4, [ %sp + 0x5c ]
a00a7c48:  31 00 00 19  sethi  %hi(0x6400), %i0
a00a7c4c:  94 16 21 9a  or  %i0, 0x19a, %o2	! 0x659a
a00a7c50:  10 bf ff f1  b  0xa00a7c14
a00a7c54:  98 0c a0 fe  and  %l2, 0xfe, %o4
a00a7c58:  10 bf ff bd  b  0xa00a7b4c
a00a7c5c:  a6 10 20 7c  mov  0x7c, %l3
a00a7c60:  10 bf ff bb  b  0xa00a7b4c
a00a7c64:  a6 10 20 64  mov  0x64, %l3
a00a7c68:  94 02 c0 0b  add  %o3, %o3, %o2
a00a7c6c:  92 02 80 0b  add  %o2, %o3, %o1
a00a7c70:  10 bf ff b7  b  0xa00a7b4c
a00a7c74:  a6 02 60 52  add  %o1, 0x52, %l3
a00a7c78:  10 bf ff b5  b  0xa00a7b4c
a00a7c7c:  a6 10 20 49  mov  0x49, %l3
a00a7c80:  81 c7 e0 08  ret
a00a7c84:  81 e8 00 00  restore
