# leon2s FUN_a00c8b18 0xa00c8b18-0xa00c8c64 (332 bytes)
a00c8b18:  9d e3 bf 90  save  %sp, -112, %sp
a00c8b1c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c8b20:  92 07 bf f0  add  %fp, -16, %o1
a00c8b24:  7f ff ff 0f  call  0xa00c8760
a00c8b28:  90 10 00 18  mov  %i0, %o0
a00c8b2c:  82 06 00 18  add  %i0, %i0, %g1
a00c8b30:  82 00 40 18  add  %g1, %i0, %g1
a00c8b34:  1b 2a 01 e2  sethi  %hi(0xa8078800), %o5
a00c8b38:  80 8a 20 ff  btst  0xff, %o0
a00c8b3c:  96 13 63 b0  or  %o5, 0x3b0, %o3
a00c8b40:  99 28 60 03  sll  %g1, 3, %o4
a00c8b44:  92 10 20 00  clr  %o1
a00c8b48:  94 10 20 0f  mov  0xf, %o2
a00c8b4c:  02 80 00 05  be  0xa00c8b60
a00c8b50:  90 10 00 18  mov  %i0, %o0
a00c8b54:  c2 02 c0 0c  ld  [ %o3 + %o4 ], %g1
a00c8b58:  10 80 00 3f  b  0xa00c8c54
a00c8b5c:  1b 00 00 c0  sethi  %hi(0x30000), %o5
a00c8b60:  40 3b bd 1e  call  0xa0fb7fd8
a00c8b64:  01 00 00 00  nop
a00c8b68:  80 8a 20 02  btst  2, %o0
a00c8b6c:  11 27 c7 08  sethi  %hi(0x9f1c2000), %o0
a00c8b70:  12 80 00 04  bne  0xa00c8b80
a00c8b74:  90 12 20 30  or  %o0, 0x30, %o0	! 0x9f1c2030
a00c8b78:  40 3a e9 33  call  0xa0f83044
a00c8b7c:  01 00 00 00  nop
a00c8b80:  92 10 20 00  clr  %o1	! 0x0
a00c8b84:  94 10 20 22  mov  0x22, %o2
a00c8b88:  40 3b bd 14  call  0xa0fb7fd8
a00c8b8c:  90 10 00 18  mov  %i0, %o0
a00c8b90:  9a 0a 20 ff  and  %o0, 0xff, %o5
a00c8b94:  c2 0f bf f0  ldub  [ %fp + -16 ], %g1
a00c8b98:  92 10 20 00  clr  %o1
a00c8b9c:  94 10 20 23  mov  0x23, %o2
a00c8ba0:  80 a3 40 01  cmp  %o5, %g1
a00c8ba4:  12 80 00 0a  bne  0xa00c8bcc
a00c8ba8:  90 10 00 18  mov  %i0, %o0
a00c8bac:  40 3b bd 0b  call  0xa0fb7fd8
a00c8bb0:  01 00 00 00  nop
a00c8bb4:  82 0a 20 ff  and  %o0, 0xff, %g1
a00c8bb8:  11 27 c7 08  sethi  %hi(0x9f1c2000), %o0
a00c8bbc:  da 0f bf f1  ldub  [ %fp + -15 ], %o5
a00c8bc0:  80 a0 40 0d  cmp  %g1, %o5
a00c8bc4:  02 80 00 17  be  0xa00c8c20
a00c8bc8:  90 12 20 40  or  %o0, 0x40, %o0
a00c8bcc:  11 27 c7 08  sethi  %hi(0x9f1c2000), %o0
a00c8bd0:  40 3a e9 1d  call  0xa0f83044
a00c8bd4:  90 12 20 68  or  %o0, 0x68, %o0	! 0x9f1c2068
a00c8bd8:  98 06 00 18  add  %i0, %i0, %o4
a00c8bdc:  98 03 00 18  add  %o4, %i0, %o4
a00c8be0:  17 2a 01 e2  sethi  %hi(0xa8078800), %o3
a00c8be4:  96 12 e3 b0  or  %o3, 0x3b0, %o3	! 0xa8078bb0
a00c8be8:  99 2b 20 03  sll  %o4, 3, %o4
a00c8bec:  d4 02 c0 0c  ld  [ %o3 + %o4 ], %o2
a00c8bf0:  83 32 a0 18  srl  %o2, 0x18, %g1
a00c8bf4:  82 08 60 0f  and  %g1, 0xf, %g1
a00c8bf8:  82 00 7f ff  add  %g1, -1, %g1
a00c8bfc:  82 08 60 0f  and  %g1, 0xf, %g1
a00c8c00:  1b 03 c0 00  sethi  %hi(0xf000000), %o5
a00c8c04:  83 28 60 18  sll  %g1, 0x18, %g1
a00c8c08:  9a 2a 80 0d  andn  %o2, %o5, %o5
a00c8c0c:  9a 13 40 01  or  %o5, %g1, %o5
a00c8c10:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00c8c14:  9a 13 40 01  or  %o5, %g1, %o5
a00c8c18:  10 80 00 11  b  0xa00c8c5c
a00c8c1c:  da 22 c0 0c  st  %o5, [ %o3 + %o4 ]
a00c8c20:  40 3a e9 09  call  0xa0f83044
a00c8c24:  01 00 00 00  nop
a00c8c28:  98 06 00 18  add  %i0, %i0, %o4
a00c8c2c:  98 03 00 18  add  %o4, %i0, %o4
a00c8c30:  17 2a 01 e2  sethi  %hi(0xa8078800), %o3
a00c8c34:  96 12 e3 b0  or  %o3, 0x3b0, %o3	! 0xa8078bb0
a00c8c38:  99 2b 20 03  sll  %o4, 3, %o4
a00c8c3c:  c2 02 c0 0c  ld  [ %o3 + %o4 ], %g1
a00c8c40:  1b 00 20 00  sethi  %hi(0x800000), %o5
a00c8c44:  9a 28 40 0d  andn  %g1, %o5, %o5
a00c8c48:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00c8c4c:  82 2b 40 01  andn  %o5, %g1, %g1
a00c8c50:  1b 00 00 40  sethi  %hi(0x10000), %o5
a00c8c54:  82 10 40 0d  or  %g1, %o5, %g1
a00c8c58:  c2 22 c0 0c  st  %g1, [ %o3 + %o4 ]
a00c8c5c:  81 c7 e0 08  ret
a00c8c60:  81 e8 00 00  restore
