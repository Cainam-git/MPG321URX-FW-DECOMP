# leon2m FUN_a00f8a98 0xa00f8a98-0xa00f8cc4 (556 bytes)
a00f8a98:  9d e3 bf 98  save  %sp, -104, %sp
a00f8a9c:  9b 2e 60 10  sll  %i1, 0x10, %o5
a00f8aa0:  83 33 60 12  srl  %o5, 0x12, %g1
a00f8aa4:  80 8e 60 03  btst  3, %i1
a00f8aa8:  b2 00 60 01  add  %g1, 1, %i1
a00f8aac:  12 80 00 03  bne  0xa00f8ab8
a00f8ab0:  a0 10 20 00  clr  %l0
a00f8ab4:  b2 10 00 01  mov  %g1, %i1
a00f8ab8:  91 2e a0 10  sll  %i2, 0x10, %o0
a00f8abc:  83 32 20 12  srl  %o0, 0x12, %g1
a00f8ac0:  80 8e a0 03  btst  3, %i2
a00f8ac4:  12 80 00 03  bne  0xa00f8ad0
a00f8ac8:  b4 00 60 01  add  %g1, 1, %i2
a00f8acc:  b4 10 00 01  mov  %g1, %i2
a00f8ad0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00f8ad4:  40 00 13 53  call  0xa00fd820
a00f8ad8:  90 10 00 18  mov  %i0, %o0
a00f8adc:  90 0a 20 ff  and  %o0, 0xff, %o0
a00f8ae0:  80 a2 20 b1  cmp  %o0, 0xb1
a00f8ae4:  22 80 00 75  be,a   0xa00f8cb8
a00f8ae8:  90 10 00 18  mov  %i0, %o0
a00f8aec:  94 1a 20 31  xor  %o0, 0x31, %o2
a00f8af0:  80 a0 00 0a  cmp  %g0, %o2
a00f8af4:  98 60 3f ff  subx  %g0, -1, %o4
a00f8af8:  92 1a 20 41  xor  %o0, 0x41, %o1
a00f8afc:  80 a0 00 09  cmp  %g0, %o1
a00f8b00:  82 60 3f ff  subx  %g0, -1, %g1
a00f8b04:  80 93 00 01  orcc  %o4, %g1, %g0
a00f8b08:  12 80 00 0a  bne  0xa00f8b30
a00f8b0c:  82 1a 20 51  xor  %o0, 0x51, %g1
a00f8b10:  80 a0 00 01  cmp  %g0, %g1
a00f8b14:  9e 60 3f ff  subx  %g0, -1, %o7
a00f8b18:  9a 1a 20 61  xor  %o0, 0x61, %o5
a00f8b1c:  80 a0 00 0d  cmp  %g0, %o5
a00f8b20:  96 60 3f ff  subx  %g0, -1, %o3
a00f8b24:  80 93 c0 0b  orcc  %o7, %o3, %g0
a00f8b28:  02 80 00 55  be  0xa00f8c7c
a00f8b2c:  94 1a 20 71  xor  %o0, 0x71, %o2
a00f8b30:  90 10 00 18  mov  %i0, %o0
a00f8b34:  92 10 20 00  clr  %o1
a00f8b38:  94 10 20 01  mov  1, %o2
a00f8b3c:  7f ff e4 c5  call  0xa00f1e50
a00f8b40:  01 00 00 00  nop
a00f8b44:  9f 2e 60 10  sll  %i1, 0x10, %o7
a00f8b48:  95 33 e0 10  srl  %o7, 0x10, %o2
a00f8b4c:  90 10 00 18  mov  %i0, %o0
a00f8b50:  7f ff e4 e2  call  0xa00f1ed8
a00f8b54:  92 10 20 10  mov  0x10, %o1
a00f8b58:  91 2e a0 10  sll  %i2, 0x10, %o0
a00f8b5c:  95 32 20 10  srl  %o0, 0x10, %o2
a00f8b60:  90 10 00 18  mov  %i0, %o0
a00f8b64:  7f ff e4 dd  call  0xa00f1ed8
a00f8b68:  92 10 20 12  mov  0x12, %o1
a00f8b6c:  b3 2e e0 10  sll  %i3, 0x10, %i1
a00f8b70:  95 36 60 10  srl  %i1, 0x10, %o2
a00f8b74:  90 10 00 18  mov  %i0, %o0
a00f8b78:  7f ff e4 d8  call  0xa00f1ed8
a00f8b7c:  92 10 20 14  mov  0x14, %o1
a00f8b80:  b2 10 20 16  mov  0x16, %i1
a00f8b84:  80 a6 20 01  cmp  %i0, 1
a00f8b88:  02 80 00 15  be  0xa00f8bdc
a00f8b8c:  b4 10 20 42  mov  0x42, %i2
a00f8b90:  7f ff e4 b0  call  0xa00f1e50
a00f8b94:  81 e8 00 00  restore
a00f8b98:  7f ff e4 9d  call  0xa00f1e0c
a00f8b9c:  35 00 06 68  sethi  %hi(0x19a000), %i2
a00f8ba0:  94 0a 20 03  and  %o0, 3, %o2
a00f8ba4:  90 16 a3 e0  or  %i2, 0x3e0, %o0
a00f8ba8:  7f ff 99 72  call  0xa00df170
a00f8bac:  92 0c 20 ff  and  %l0, 0xff, %o1
a00f8bb0:  90 10 00 18  mov  %i0, %o0
a00f8bb4:  7f ff e4 96  call  0xa00f1e0c
a00f8bb8:  92 10 20 4a  mov  0x4a, %o1
a00f8bbc:  b6 04 20 01  add  %l0, 1, %i3
a00f8bc0:  9a 0e e0 ff  and  %i3, 0xff, %o5
a00f8bc4:  80 8a 20 03  btst  3, %o0
a00f8bc8:  02 80 00 39  be  0xa00f8cac
a00f8bcc:  a0 10 00 1b  mov  %i3, %l0
a00f8bd0:  80 a3 60 09  cmp  %o5, 9
a00f8bd4:  18 80 00 37  bgu  0xa00f8cb0
a00f8bd8:  b2 10 20 49  mov  0x49, %i1
a00f8bdc:  67 fe 50 bf  call  0x4008ced8
a00f8be0:  01 00 00 00  nop
a00f8be4:  90 10 00 18  mov  %i0, %o0
a00f8be8:  92 10 20 48  mov  0x48, %o1
a00f8bec:  7f ff e4 99  call  0xa00f1e50
a00f8bf0:  94 10 20 01  mov  1, %o2
a00f8bf4:  92 10 20 16  mov  0x16, %o1
a00f8bf8:  94 10 20 4a  mov  0x4a, %o2
a00f8bfc:  7f ff e4 95  call  0xa00f1e50
a00f8c00:  90 10 00 18  mov  %i0, %o0
a00f8c04:  67 fe 51 67  call  0x4008d1a0
a00f8c08:  90 10 20 01  mov  1, %o0
a00f8c0c:  90 10 00 18  mov  %i0, %o0
a00f8c10:  92 10 20 16  mov  0x16, %o1
a00f8c14:  7f ff e4 8f  call  0xa00f1e50
a00f8c18:  94 10 20 42  mov  0x42, %o2
a00f8c1c:  90 10 00 18  mov  %i0, %o0
a00f8c20:  92 10 20 48  mov  0x48, %o1
a00f8c24:  7f ff e4 8b  call  0xa00f1e50
a00f8c28:  94 10 20 00  clr  %o2
a00f8c2c:  92 10 20 49  mov  0x49, %o1
a00f8c30:  94 10 20 c3  mov  0xc3, %o2
a00f8c34:  7f ff e4 87  call  0xa00f1e50
a00f8c38:  90 10 00 18  mov  %i0, %o0
a00f8c3c:  67 fe 51 59  call  0x4008d1a0
a00f8c40:  90 10 20 32  mov  0x32, %o0
a00f8c44:  94 10 20 01  mov  1, %o2
a00f8c48:  92 10 20 49  mov  0x49, %o1
a00f8c4c:  7f ff e4 81  call  0xa00f1e50
a00f8c50:  90 10 00 18  mov  %i0, %o0
a00f8c54:  67 fe 51 53  call  0x4008d1a0
a00f8c58:  90 10 20 05  mov  5, %o0
a00f8c5c:  92 10 20 4a  mov  0x4a, %o1
a00f8c60:  7f ff e4 6b  call  0xa00f1e0c
a00f8c64:  90 10 00 18  mov  %i0, %o0
a00f8c68:  80 8a 20 03  btst  3, %o0
a00f8c6c:  92 10 20 4a  mov  0x4a, %o1
a00f8c70:  02 bf ff d0  be  0xa00f8bb0
a00f8c74:  90 10 00 18  mov  %i0, %o0
a00f8c78:  30 bf ff c8  b,a   0xa00f8b98
a00f8c7c:  80 a0 00 0a  cmp  %g0, %o2
a00f8c80:  92 1a 20 81  xor  %o0, 0x81, %o1
a00f8c84:  98 60 3f ff  subx  %g0, -1, %o4
a00f8c88:  80 a0 00 09  cmp  %g0, %o1
a00f8c8c:  96 60 3f ff  subx  %g0, -1, %o3
a00f8c90:  90 10 00 18  mov  %i0, %o0
a00f8c94:  92 10 20 00  clr  %o1
a00f8c98:  80 93 00 0b  orcc  %o4, %o3, %g0
a00f8c9c:  12 bf ff a8  bne  0xa00f8b3c
a00f8ca0:  94 10 20 02  mov  2, %o2
a00f8ca4:  10 bf ff a6  b  0xa00f8b3c
a00f8ca8:  94 10 20 01  mov  1, %o2
a00f8cac:  b2 10 20 49  mov  0x49, %i1
a00f8cb0:  7f ff e4 68  call  0xa00f1e50
a00f8cb4:  95 e8 20 03  restore  %g0, 3, %o2
a00f8cb8:  92 10 20 00  clr  %o1
a00f8cbc:  10 bf ff a0  b  0xa00f8b3c
a00f8cc0:  94 10 20 00  clr  %o2
