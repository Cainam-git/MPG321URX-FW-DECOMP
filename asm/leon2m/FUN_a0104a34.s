# leon2m FUN_a0104a34 0xa0104a34-0xa0104b2c (248 bytes)
a0104a34:  9d e3 bf 98  save  %sp, -104, %sp
a0104a38:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0104a3c:  92 10 20 04  mov  4, %o1
a0104a40:  7f ff b4 14  call  0xa00f1a90
a0104a44:  90 10 00 18  mov  %i0, %o0
a0104a48:  82 0a 20 0f  and  %o0, 0xf, %g1
a0104a4c:  92 10 20 03  mov  3, %o1
a0104a50:  80 a0 60 01  cmp  %g1, 1
a0104a54:  04 80 00 1d  ble  0xa0104ac8
a0104a58:  90 10 00 18  mov  %i0, %o0
a0104a5c:  83 2e a0 10  sll  %i2, 0x10, %g1
a0104a60:  93 30 60 10  srl  %g1, 0x10, %o1
a0104a64:  94 10 20 01  mov  1, %o2
a0104a68:  40 00 72 05  call  0xa012127c
a0104a6c:  90 10 00 18  mov  %i0, %o0
a0104a70:  35 33 c0 45  sethi  %hi(0xcf011400), %i2
a0104a74:  9a 16 a2 58  or  %i2, 0x258, %o5	! 0xcf011658
a0104a78:  de 03 40 00  ld  [ %o5 ], %o7
a0104a7c:  98 13 e0 80  or  %o7, 0x80, %o4
a0104a80:  d8 23 40 00  st  %o4, [ %o5 ]
a0104a84:  7f ff d2 14  call  0xa00f92d4
a0104a88:  90 10 00 18  mov  %i0, %o0
a0104a8c:  80 8a 20 ff  btst  0xff, %o0
a0104a90:  92 10 20 01  mov  1, %o1
a0104a94:  02 80 00 08  be  0xa0104ab4
a0104a98:  90 10 00 18  mov  %i0, %o0
a0104a9c:  7f ff b5 40  call  0xa00f1f9c
a0104aa0:  01 00 00 00  nop
a0104aa4:  92 12 20 0f  or  %o0, 0xf, %o1
a0104aa8:  90 10 00 18  mov  %i0, %o0
a0104aac:  10 80 00 19  b  0xa0104b10
a0104ab0:  94 0a 60 ff  and  %o1, 0xff, %o2
a0104ab4:  7f ff b5 3a  call  0xa00f1f9c
a0104ab8:  90 10 00 18  mov  %i0, %o0
a0104abc:  94 0a 20 f0  and  %o0, 0xf0, %o2
a0104ac0:  10 80 00 14  b  0xa0104b10
a0104ac4:  90 10 00 18  mov  %i0, %o0
a0104ac8:  7f ff b3 f2  call  0xa00f1a90
a0104acc:  01 00 00 00  nop
a0104ad0:  80 8a 20 20  btst  0x20, %o0
a0104ad4:  92 10 20 54  mov  0x54, %o1
a0104ad8:  12 bf ff e1  bne  0xa0104a5c
a0104adc:  90 10 00 18  mov  %i0, %o0
a0104ae0:  7f ff b3 ec  call  0xa00f1a90
a0104ae4:  01 00 00 00  nop
a0104ae8:  13 33 c0 4a  sethi  %hi(0xcf012800), %o1
a0104aec:  90 0a 20 03  and  %o0, 3, %o0
a0104af0:  80 a2 20 01  cmp  %o0, 1
a0104af4:  12 bf ff da  bne  0xa0104a5c
a0104af8:  9a 12 60 04  or  %o1, 4, %o5
a0104afc:  d6 03 40 00  ld  [ %o5 ], %o3
a0104b00:  94 12 e0 40  or  %o3, 0x40, %o2
a0104b04:  d4 23 40 00  st  %o2, [ %o5 ]
a0104b08:  10 bf ff d6  b  0xa0104a60
a0104b0c:  83 2e a0 10  sll  %i2, 0x10, %g1
a0104b10:  7f ff b5 34  call  0xa00f1fe0
a0104b14:  92 10 20 01  mov  1, %o1
a0104b18:  11 33 c0 44  sethi  %hi(0xcf011000), %o0
a0104b1c:  b0 12 23 6c  or  %o0, 0x36c, %i0	! 0xcf01136c
a0104b20:  c0 26 00 00  clr  [ %i0 ]
a0104b24:  81 c7 e0 08  ret
a0104b28:  81 e8 00 00  restore
