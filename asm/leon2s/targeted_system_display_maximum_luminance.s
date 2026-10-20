# leon2s targeted_system_display_maximum_luminance 0xa0061adc-0xa0061d60 (644 bytes)
a0061adc:  9d e3 bf 90  save  %sp, -112, %sp
a0061ae0:  21 34 00 4f  sethi  %hi(0xd0013c00), %l0
a0061ae4:  7f ff fe 91  call  0xa0061528
a0061ae8:  90 14 23 f0  or  %l0, 0x3f0, %o0	! 0xd0013ff0
a0061aec:  80 a2 20 01  cmp  %o0, 1
a0061af0:  12 80 00 99  bne  0xa0061d54
a0061af4:  90 14 23 f0  or  %l0, 0x3f0, %o0
a0061af8:  92 10 20 00  clr  %o1
a0061afc:  7f ff fe 8e  call  0xa0061534
a0061b00:  c0 27 bf f4  clr  [ %fp + -12 ]
a0061b04:  23 2a 01 e2  sethi  %hi(0xa8078800), %l1
a0061b08:  a0 14 62 a0  or  %l1, 0x2a0, %l0	! 0xa8078aa0
a0061b0c:  11 28 01 96  sethi  %hi(0xa0065800), %o0
a0061b10:  d2 14 20 88  lduh  [ %l0 + 0x88 ], %o1
a0061b14:  40 00 45 4c  call  0xa0073044
a0061b18:  90 12 21 60  or  %o0, 0x160, %o0
a0061b1c:  11 28 01 96  sethi  %hi(0xa0065800), %o0
a0061b20:  d2 0c 20 58  ldub  [ %l0 + 0x58 ], %o1
a0061b24:  40 00 45 48  call  0xa0073044
a0061b28:  90 12 21 a0  or  %o0, 0x1a0, %o0
a0061b2c:  11 28 01 96  sethi  %hi(0xa0065800), %o0
a0061b30:  d2 14 20 02  lduh  [ %l0 + 2 ], %o1
a0061b34:  40 00 45 44  call  0xa0073044
a0061b38:  90 12 21 d0  or  %o0, 0x1d0, %o0
a0061b3c:  11 28 01 96  sethi  %hi(0xa0065800), %o0
a0061b40:  d2 14 20 04  lduh  [ %l0 + 4 ], %o1
a0061b44:  40 00 45 40  call  0xa0073044
a0061b48:  90 12 21 f0  or  %o0, 0x1f0, %o0
a0061b4c:  03 2a 01 d9  sethi  %hi(0xa8076400), %g1
a0061b50:  11 28 01 96  sethi  %hi(0xa0065800), %o0
a0061b54:  d2 00 62 80  ld  [ %g1 + 0x280 ], %o1
a0061b58:  40 00 45 3b  call  0xa0073044
a0061b5c:  90 12 22 10  or  %o0, 0x210, %o0
a0061b60:  03 2a 01 d9  sethi  %hi(0xa8076400), %g1
a0061b64:  11 28 01 96  sethi  %hi(0xa0065800), %o0
a0061b68:  d2 00 62 7c  ld  [ %g1 + 0x27c ], %o1
a0061b6c:  40 00 45 36  call  0xa0073044
a0061b70:  90 12 22 30  or  %o0, 0x230, %o0
a0061b74:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a0061b78:  11 28 01 96  sethi  %hi(0xa0065800), %o0
a0061b7c:  d2 00 62 90  ld  [ %g1 + 0x290 ], %o1
a0061b80:  40 00 45 31  call  0xa0073044
a0061b84:  90 12 22 58  or  %o0, 0x258, %o0
a0061b88:  11 28 01 96  sethi  %hi(0xa0065800), %o0
a0061b8c:  d2 0c 20 01  ldub  [ %l0 + 1 ], %o1
a0061b90:  90 12 22 88  or  %o0, 0x288, %o0
a0061b94:  40 00 45 2c  call  0xa0073044
a0061b98:  a0 10 20 00  clr  %l0
a0061b9c:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a0061ba0:  da 00 61 74  ld  [ %g1 + 0x174 ], %o5	! 0xa807cd74
a0061ba4:  92 04 22 75  add  %l0, 0x275, %o1
a0061ba8:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a0061bac:  93 2a 60 10  sll  %o1, 0x10, %o1
a0061bb0:  d0 08 62 38  ldub  [ %g1 + 0x238 ], %o0
a0061bb4:  9f c3 40 00  call  %o5
a0061bb8:  93 32 60 10  srl  %o1, 0x10, %o1
a0061bbc:  94 0a 20 ff  and  %o0, 0xff, %o2
a0061bc0:  11 28 01 96  sethi  %hi(0xa0065800), %o0
a0061bc4:  92 10 00 10  mov  %l0, %o1
a0061bc8:  95 2a a0 02  sll  %o2, 2, %o2
a0061bcc:  40 00 45 1e  call  0xa0073044
a0061bd0:  90 12 22 c0  or  %o0, 0x2c0, %o0
a0061bd4:  9a 04 00 10  add  %l0, %l0, %o5
a0061bd8:  82 14 62 a0  or  %l1, 0x2a0, %g1
a0061bdc:  9a 03 40 01  add  %o5, %g1, %o5
a0061be0:  11 28 01 96  sethi  %hi(0xa0065800), %o0
a0061be4:  92 10 00 10  mov  %l0, %o1
a0061be8:  90 12 22 f8  or  %o0, 0x2f8, %o0
a0061bec:  40 00 45 16  call  0xa0073044
a0061bf0:  d4 13 60 5a  lduh  [ %o5 + 0x5a ], %o2
a0061bf4:  a0 04 20 01  inc  %l0
a0061bf8:  80 a4 20 08  cmp  %l0, 8
a0061bfc:  08 bf ff e9  bleu  0xa0061ba0
a0061c00:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a0061c04:  21 34 00 4f  sethi  %hi(0xd0013c00), %l0
a0061c08:  7f ff fe 48  call  0xa0061528
a0061c0c:  90 14 23 60  or  %l0, 0x360, %o0	! 0xd0013f60
a0061c10:  d0 27 bf f4  st  %o0, [ %fp + -12 ]
a0061c14:  90 07 bf f4  add  %fp, -12, %o0
a0061c18:  92 10 20 00  clr  %o1
a0061c1c:  94 10 20 00  clr  %o2
a0061c20:  7f ff ff 93  call  0xa0061a6c
a0061c24:  96 10 20 01  mov  1, %o3
a0061c28:  90 07 bf f4  add  %fp, -12, %o0
a0061c2c:  92 10 20 14  mov  0x14, %o1
a0061c30:  94 10 20 14  mov  0x14, %o2
a0061c34:  7f ff ff 8e  call  0xa0061a6c
a0061c38:  96 10 20 01  mov  1, %o3
a0061c3c:  90 07 bf f4  add  %fp, -12, %o0
a0061c40:  92 10 20 10  mov  0x10, %o1
a0061c44:  94 10 20 08  mov  8, %o2
a0061c48:  7f ff ff 89  call  0xa0061a6c
a0061c4c:  96 10 20 00  clr  %o3
a0061c50:  90 14 23 60  or  %l0, 0x360, %o0
a0061c54:  7f ff fe 38  call  0xa0061534
a0061c58:  d2 07 bf f4  ld  [ %fp + -12 ], %o1
a0061c5c:  a0 10 20 00  clr  %l0
a0061c60:  90 07 bf f4  add  %fp, -12, %o0
a0061c64:  92 10 20 00  clr  %o1
a0061c68:  94 10 20 00  clr  %o2
a0061c6c:  7f ff ff 80  call  0xa0061a6c
a0061c70:  96 10 20 01  mov  1, %o3
a0061c74:  96 10 00 10  mov  %l0, %o3
a0061c78:  94 10 20 08  mov  8, %o2
a0061c7c:  90 07 bf f4  add  %fp, -12, %o0
a0061c80:  7f ff ff 7b  call  0xa0061a6c
a0061c84:  92 10 20 10  mov  0x10, %o1
a0061c88:  23 34 00 4f  sethi  %hi(0xd0013c00), %l1
a0061c8c:  d2 07 bf f4  ld  [ %fp + -12 ], %o1
a0061c90:  7f ff fe 29  call  0xa0061534
a0061c94:  90 14 63 60  or  %l1, 0x360, %o0
a0061c98:  40 01 3e bf  call  0xa00b1794
a0061c9c:  90 10 20 05  mov  5, %o0
a0061ca0:  d2 07 bf f4  ld  [ %fp + -12 ], %o1
a0061ca4:  7f ff fe 24  call  0xa0061534
a0061ca8:  90 14 63 60  or  %l1, 0x360, %o0
a0061cac:  40 01 3e ba  call  0xa00b1794
a0061cb0:  90 10 20 05  mov  5, %o0
a0061cb4:  d2 07 bf f4  ld  [ %fp + -12 ], %o1
a0061cb8:  7f ff fe 1f  call  0xa0061534
a0061cbc:  90 14 63 60  or  %l1, 0x360, %o0
a0061cc0:  40 01 3e b5  call  0xa00b1794
a0061cc4:  90 10 20 0a  mov  0xa, %o0
a0061cc8:  7f ff fe 18  call  0xa0061528
a0061ccc:  90 14 63 64  or  %l1, 0x364, %o0
a0061cd0:  94 10 00 08  mov  %o0, %o2
a0061cd4:  11 28 01 96  sethi  %hi(0xa0065800), %o0
a0061cd8:  92 10 00 10  mov  %l0, %o1
a0061cdc:  40 00 44 da  call  0xa0073044
a0061ce0:  90 12 23 28  or  %o0, 0x328, %o0
a0061ce4:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a0061ce8:  9b 2c 20 02  sll  %l0, 2, %o5
a0061cec:  82 10 62 78  or  %g1, 0x278, %g1
a0061cf0:  11 28 01 96  sethi  %hi(0xa0065800), %o0
a0061cf4:  92 10 00 10  mov  %l0, %o1
a0061cf8:  d4 00 40 0d  ld  [ %g1 + %o5 ], %o2
a0061cfc:  40 00 44 d2  call  0xa0073044
a0061d00:  90 12 23 48  or  %o0, 0x348, %o0
a0061d04:  a0 04 20 10  add  %l0, 0x10, %l0
a0061d08:  80 a4 21 00  cmp  %l0, 0x100
a0061d0c:  08 bf ff d6  bleu  0xa0061c64
a0061d10:  90 07 bf f4  add  %fp, -12, %o0
a0061d14:  7f ff fe 05  call  0xa0061528
a0061d18:  90 14 63 60  or  %l1, 0x360, %o0
a0061d1c:  d0 27 bf f4  st  %o0, [ %fp + -12 ]
a0061d20:  90 07 bf f4  add  %fp, -12, %o0
a0061d24:  92 10 20 00  clr  %o1
a0061d28:  94 10 20 00  clr  %o2
a0061d2c:  7f ff ff 50  call  0xa0061a6c
a0061d30:  96 10 20 00  clr  %o3
a0061d34:  90 07 bf f4  add  %fp, -12, %o0
a0061d38:  92 10 20 14  mov  0x14, %o1
a0061d3c:  94 10 20 14  mov  0x14, %o2
a0061d40:  7f ff ff 4b  call  0xa0061a6c
a0061d44:  96 10 20 00  clr  %o3
a0061d48:  90 14 63 60  or  %l1, 0x360, %o0
a0061d4c:  7f ff fd fa  call  0xa0061534
a0061d50:  d2 07 bf f4  ld  [ %fp + -12 ], %o1
a0061d54:  01 00 00 00  nop
a0061d58:  81 c7 e0 08  ret
a0061d5c:  81 e8 00 00  restore
