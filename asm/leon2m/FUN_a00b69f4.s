# leon2m FUN_a00b69f4 0xa00b69f4-0xa00b6b68 (372 bytes)
a00b69f4:  9d e3 bf 98  save  %sp, -104, %sp
a00b69f8:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00b69fc:  a0 14 62 90  or  %l1, 0x290, %l0	! 0xa802d290
a00b6a00:  c2 04 20 a8  ld  [ %l0 + 0xa8 ], %g1
a00b6a04:  80 88 60 80  btst  0x80, %g1
a00b6a08:  22 80 00 1e  be,a   0xa00b6a80
a00b6a0c:  d0 0c 20 1f  ldub  [ %l0 + 0x1f ], %o0
a00b6a10:  82 08 7f 7f  and  %g1, -129, %g1
a00b6a14:  c2 24 20 a8  st  %g1, [ %l0 + 0xa8 ]
a00b6a18:  7f ff 69 70  call  0xa0090fd8
a00b6a1c:  a0 14 62 90  or  %l1, 0x290, %l0
a00b6a20:  40 01 b9 49  call  0xa0124f44
a00b6a24:  01 00 00 00  nop
a00b6a28:  40 00 89 f5  call  0xa00d91fc
a00b6a2c:  90 10 20 00  clr  %o0	! 0x0
a00b6a30:  d8 04 20 a8  ld  [ %l0 + 0xa8 ], %o4
a00b6a34:  97 33 20 07  srl  %o4, 7, %o3
a00b6a38:  92 0a e0 01  and  %o3, 1, %o1
a00b6a3c:  7f ff cd 3d  call  0xa00a9f30
a00b6a40:  90 10 20 05  mov  5, %o0
a00b6a44:  40 02 33 66  call  0xa01437dc
a00b6a48:  90 10 20 32  mov  0x32, %o0
a00b6a4c:  40 02 36 90  call  0xa014448c
a00b6a50:  90 10 20 00  clr  %o0
a00b6a54:  40 02 36 ea  call  0xa01445fc
a00b6a58:  90 0a 20 ff  and  %o0, 0xff, %o0
a00b6a5c:  80 8a 20 ff  btst  0xff, %o0
a00b6a60:  02 80 00 3a  be  0xa00b6b48
a00b6a64:  1f 00 04 00  sethi  %hi(0x100000), %o7
a00b6a68:  da 04 20 ac  ld  [ %l0 + 0xac ], %o5
a00b6a6c:  80 8b 40 0f  btst  %o5, %o7
a00b6a70:  02 80 00 36  be  0xa00b6b48
a00b6a74:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a00b6a78:  10 80 00 20  b  0xa00b6af8
a00b6a7c:  a2 10 63 f4  or  %g1, 0x3f4, %l1	! 0xa802cff4
a00b6a80:  80 a2 20 00  cmp  %o0, 0
a00b6a84:  12 80 00 14  bne  0xa00b6ad4
a00b6a88:  01 00 00 00  nop
a00b6a8c:  7f ff 33 56  call  0xa00837e4
a00b6a90:  01 00 00 00  nop
a00b6a94:  92 0a 20 ff  and  %o0, 0xff, %o1
a00b6a98:  80 a2 60 01  cmp  %o1, 1
a00b6a9c:  22 80 00 1f  be,a   0xa00b6b18
a00b6aa0:  c0 2c 21 a4  clrb  [ %l0 + 0x1a4 ]
a00b6aa4:  c0 2c 20 4a  clrb  [ %l0 + 0x4a ]
a00b6aa8:  40 00 7d 01  call  0xa00d5eac
a00b6aac:  90 10 20 00  clr  %o0
a00b6ab0:  d4 04 20 a8  ld  [ %l0 + 0xa8 ], %o2
a00b6ab4:  82 12 a0 80  or  %o2, 0x80, %g1
a00b6ab8:  1b 00 00 08  sethi  %hi(0x2000), %o5
a00b6abc:  80 88 40 0d  btst  %g1, %o5
a00b6ac0:  22 80 00 02  be,a   0xa00b6ac8
a00b6ac4:  82 10 40 0d  or  %g1, %o5, %g1
a00b6ac8:  40 00 77 b4  call  0xa00d4998
a00b6acc:  c2 24 20 a8  st  %g1, [ %l0 + 0xa8 ]
a00b6ad0:  30 bf ff d2  b,a   0xa00b6a18
a00b6ad4:  7f ff 69 41  call  0xa0090fd8
a00b6ad8:  c0 2c 20 1f  clrb  [ %l0 + 0x1f ]
a00b6adc:  40 01 b9 1a  call  0xa0124f44
a00b6ae0:  01 00 00 00  nop
a00b6ae4:  40 00 89 c6  call  0xa00d91fc
a00b6ae8:  90 10 20 00  clr  %o0	! 0x0
a00b6aec:  40 00 8d da  call  0xa00da254
a00b6af0:  01 00 00 00  nop
a00b6af4:  30 bf ff e6  b,a   0xa00b6a8c
a00b6af8:  d2 14 60 0a  lduh  [ %l1 + 0xa ], %o1
a00b6afc:  90 12 60 40  or  %o1, 0x40, %o0
a00b6b00:  d0 34 60 0a  sth  %o0, [ %l1 + 0xa ]
a00b6b04:  21 00 00 04  sethi  %hi(0x1000), %l0
a00b6b08:  92 14 23 88  or  %l0, 0x388, %o1	! 0x1388
a00b6b0c:  7f ff 3f a9  call  0xa00869b0
a00b6b10:  90 10 20 14  mov  0x14, %o0
a00b6b14:  30 80 00 0d  b,a   0xa00b6b48
a00b6b18:  90 10 20 00  clr  %o0
a00b6b1c:  40 02 45 d3  call  0xa0148268
a00b6b20:  92 10 20 01  mov  1, %o1
a00b6b24:  90 10 20 01  mov  1, %o0
a00b6b28:  40 02 45 d0  call  0xa0148268
a00b6b2c:  92 10 20 01  mov  1, %o1
a00b6b30:  40 00 8d c9  call  0xa00da254
a00b6b34:  01 00 00 00  nop
a00b6b38:  7f ff 31 6f  call  0xa00830f4
a00b6b3c:  90 10 20 00  clr  %o0	! 0x0
a00b6b40:  10 bf ff da  b  0xa00b6aa8
a00b6b44:  c0 2c 20 4a  clrb  [ %l0 + 0x4a ]
a00b6b48:  40 00 8d 8f  call  0xa00da184
a00b6b4c:  01 00 00 00  nop
a00b6b50:  15 2a 00 ac  sethi  %hi(0xa802b000), %o2
a00b6b54:  d8 0a a0 8e  ldub  [ %o2 + 0x8e ], %o4	! 0xa802b08e
a00b6b58:  96 13 20 02  or  %o4, 2, %o3
a00b6b5c:  d6 2a a0 8e  stb  %o3, [ %o2 + 0x8e ]
a00b6b60:  81 c7 e0 08  ret
a00b6b64:  81 e8 00 00  restore
