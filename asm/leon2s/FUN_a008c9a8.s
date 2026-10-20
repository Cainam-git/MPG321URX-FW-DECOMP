# leon2s FUN_a008c9a8 0xa008c9a8-0xa008cba0 (504 bytes)
a008c9a8:  9d e3 bf 98  save  %sp, -104, %sp
a008c9ac:  b0 0e 20 ff  and  %i0, 0xff, %i0
a008c9b0:  b6 0e e0 ff  and  %i3, 0xff, %i3
a008c9b4:  90 10 00 18  mov  %i0, %o0
a008c9b8:  7f ff f9 32  call  0xa008ae80
a008c9bc:  92 10 00 1b  mov  %i3, %o1
a008c9c0:  b4 0e a0 ff  and  %i2, 0xff, %i2
a008c9c4:  90 10 00 18  mov  %i0, %o0
a008c9c8:  7f ff f8 78  call  0xa008aba8
a008c9cc:  92 10 00 1a  mov  %i2, %o1
a008c9d0:  90 10 00 18  mov  %i0, %o0
a008c9d4:  7f ff fd 02  call  0xa008bddc
a008c9d8:  92 10 00 1a  mov  %i2, %o1
a008c9dc:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a008c9e0:  c0 28 63 30  clrb  [ %g1 + 0x330 ]	! 0xa8078b30
a008c9e4:  90 10 00 18  mov  %i0, %o0
a008c9e8:  7f ff fe fc  call  0xa008c5d8
a008c9ec:  92 10 00 1a  mov  %i2, %o1
a008c9f0:  80 a6 20 08  cmp  %i0, 8
a008c9f4:  12 80 00 09  bne  0xa008ca18
a008c9f8:  80 a6 20 0a  cmp  %i0, 0xa
a008c9fc:  90 10 20 00  clr  %o0
a008ca00:  92 10 20 05  mov  5, %o1
a008ca04:  94 10 20 02  mov  2, %o2
a008ca08:  40 00 67 6c  call  0xa00a67b8
a008ca0c:  96 10 20 01  mov  1, %o3
a008ca10:  10 80 00 0a  b  0xa008ca38
a008ca14:  90 10 20 00  clr  %o0
a008ca18:  12 80 00 0e  bne  0xa008ca50
a008ca1c:  80 a6 20 0c  cmp  %i0, 0xc
a008ca20:  90 10 20 01  mov  1, %o0
a008ca24:  92 10 20 05  mov  5, %o1
a008ca28:  94 10 20 02  mov  2, %o2
a008ca2c:  40 00 67 63  call  0xa00a67b8
a008ca30:  96 10 20 01  mov  1, %o3
a008ca34:  90 10 20 01  mov  1, %o0
a008ca38:  92 10 20 05  mov  5, %o1
a008ca3c:  94 10 20 02  mov  2, %o2
a008ca40:  40 00 67 5e  call  0xa00a67b8
a008ca44:  96 10 20 00  clr  %o3
a008ca48:  10 80 00 1c  b  0xa008cab8
a008ca4c:  90 0e 60 ff  and  %i1, 0xff, %o0
a008ca50:  12 80 00 0b  bne  0xa008ca7c
a008ca54:  80 a6 20 0e  cmp  %i0, 0xe
a008ca58:  21 2a 01 f6  sethi  %hi(0xa807d800), %l0
a008ca5c:  d2 04 23 00  ld  [ %l0 + 0x300 ], %o1	! 0xa807db00
a008ca60:  92 02 60 04  add  %o1, 4, %o1
a008ca64:  40 00 6a 52  call  0xa00a73ac
a008ca68:  90 10 20 0a  mov  0xa, %o0
a008ca6c:  40 00 92 e8  call  0xa00b160c
a008ca70:  90 10 20 01  mov  1, %o0
a008ca74:  10 80 00 0d  b  0xa008caa8
a008ca78:  d2 04 23 00  ld  [ %l0 + 0x300 ], %o1
a008ca7c:  12 80 00 0f  bne  0xa008cab8
a008ca80:  90 0e 60 ff  and  %i1, 0xff, %o0
a008ca84:  21 2a 01 f6  sethi  %hi(0xa807d800), %l0
a008ca88:  a0 14 23 00  or  %l0, 0x300, %l0	! 0xa807db00
a008ca8c:  d2 04 20 34  ld  [ %l0 + 0x34 ], %o1
a008ca90:  92 02 60 04  add  %o1, 4, %o1
a008ca94:  40 00 6a 46  call  0xa00a73ac
a008ca98:  90 10 20 0a  mov  0xa, %o0
a008ca9c:  40 00 92 dc  call  0xa00b160c
a008caa0:  90 10 20 01  mov  1, %o0
a008caa4:  d2 04 20 34  ld  [ %l0 + 0x34 ], %o1
a008caa8:  92 02 60 04  add  %o1, 4, %o1
a008caac:  40 00 6a 4a  call  0xa00a73d4
a008cab0:  90 10 20 0a  mov  0xa, %o0
a008cab4:  90 0e 60 ff  and  %i1, 0xff, %o0
a008cab8:  94 10 00 1b  mov  %i3, %o2
a008cabc:  7f ff fa 1c  call  0xa008b32c
a008cac0:  92 10 00 18  mov  %i0, %o1
a008cac4:  80 a6 20 0c  cmp  %i0, 0xc
a008cac8:  12 80 00 08  bne  0xa008cae8
a008cacc:  80 a6 20 0e  cmp  %i0, 0xe
a008cad0:  40 00 57 b8  call  0xa00a29b0
a008cad4:  90 10 20 00  clr  %o0
a008cad8:  94 0a 20 ff  and  %o0, 0xff, %o2
a008cadc:  92 10 00 1a  mov  %i2, %o1
a008cae0:  10 80 00 09  b  0xa008cb04
a008cae4:  90 10 20 0c  mov  0xc, %o0
a008cae8:  12 80 00 0a  bne  0xa008cb10
a008caec:  80 a6 20 04  cmp  %i0, 4
a008caf0:  40 00 57 b0  call  0xa00a29b0
a008caf4:  90 10 20 01  mov  1, %o0
a008caf8:  94 0a 20 ff  and  %o0, 0xff, %o2
a008cafc:  92 10 00 1a  mov  %i2, %o1
a008cb00:  90 10 20 0e  mov  0xe, %o0
a008cb04:  7f ff f5 83  call  0xa008a110
a008cb08:  01 00 00 00  nop
a008cb0c:  30 80 00 24  b,a   0xa008cb9c
a008cb10:  12 80 00 07  bne  0xa008cb2c
a008cb14:  80 a6 20 06  cmp  %i0, 6
a008cb18:  92 10 00 1a  mov  %i2, %o1
a008cb1c:  90 10 20 04  mov  4, %o0
a008cb20:  7f ff f5 a5  call  0xa008a1b4
a008cb24:  94 10 20 01  mov  1, %o2
a008cb28:  30 80 00 0a  b,a   0xa008cb50
a008cb2c:  12 80 00 07  bne  0xa008cb48
a008cb30:  80 a6 20 04  cmp  %i0, 4
a008cb34:  92 10 00 1a  mov  %i2, %o1
a008cb38:  90 10 20 06  mov  6, %o0
a008cb3c:  7f ff f5 9e  call  0xa008a1b4
a008cb40:  94 10 20 01  mov  1, %o2
a008cb44:  30 80 00 0e  b,a   0xa008cb7c
a008cb48:  12 80 00 0b  bne  0xa008cb74
a008cb4c:  80 a6 20 06  cmp  %i0, 6
a008cb50:  7f ff f5 12  call  0xa0089f98
a008cb54:  90 10 20 04  mov  4, %o0
a008cb58:  91 2a 20 10  sll  %o0, 0x10, %o0
a008cb5c:  80 a2 20 00  cmp  %o0, 0
a008cb60:  02 80 00 0f  be  0xa008cb9c
a008cb64:  01 00 00 00  nop
a008cb68:  7f ff f8 ac  call  0xa008ae18
a008cb6c:  90 10 20 00  clr  %o0	! 0x0
a008cb70:  30 80 00 0b  b,a   0xa008cb9c
a008cb74:  12 80 00 0a  bne  0xa008cb9c
a008cb78:  01 00 00 00  nop
a008cb7c:  7f ff f5 07  call  0xa0089f98
a008cb80:  90 10 20 06  mov  6, %o0	! 0x6
a008cb84:  91 2a 20 10  sll  %o0, 0x10, %o0
a008cb88:  80 a2 20 00  cmp  %o0, 0
a008cb8c:  02 80 00 04  be  0xa008cb9c
a008cb90:  01 00 00 00  nop
a008cb94:  7f ff f8 a1  call  0xa008ae18
a008cb98:  91 e8 20 01  restore  %g0, 1, %o0
a008cb9c:  01 00 00 00  nop
