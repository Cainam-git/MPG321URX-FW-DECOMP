# leon2m FUN_a0105af8 0xa0105af8-0xa0105c0c (276 bytes)
a0105af8:  9d e3 bf 98  save  %sp, -104, %sp
a0105afc:  a4 0e 20 ff  and  %i0, 0xff, %l2
a0105b00:  40 00 6b c6  call  0xa0120a18
a0105b04:  90 10 00 12  mov  %l2, %o0
a0105b08:  99 2a 20 10  sll  %o0, 0x10, %o4
a0105b0c:  a7 33 20 10  srl  %o4, 0x10, %l3
a0105b10:  92 10 20 4c  mov  0x4c, %o1
a0105b14:  7f ff b2 b9  call  0xa00f25f8
a0105b18:  90 10 00 12  mov  %l2, %o0
a0105b1c:  97 2a 20 10  sll  %o0, 0x10, %o3
a0105b20:  95 32 e0 10  srl  %o3, 0x10, %o2
a0105b24:  11 04 18 93  sethi  %hi(0x10624c00), %o0
a0105b28:  92 5c c0 0a  smul  %l3, %o2, %o1
a0105b2c:  82 12 21 d3  or  %o0, 0x1d3, %g1
a0105b30:  e2 56 40 00  ldsh  [ %i1 ], %l1
a0105b34:  80 52 40 01  umul  %o1, %g1, %g0
a0105b38:  a1 40 00 00  rd  %y, %l0
a0105b3c:  40 01 40 41  call  0xa0155c40
a0105b40:  90 10 00 11  mov  %l1, %o0
a0105b44:  a6 10 00 19  mov  %i1, %l3
a0105b48:  a9 34 20 06  srl  %l0, 6, %l4
a0105b4c:  b0 10 00 12  mov  %l2, %i0
a0105b50:  a0 10 00 08  mov  %o0, %l0
a0105b54:  b2 10 20 91  mov  0x91, %i1
a0105b58:  b4 10 20 04  mov  4, %i2
a0105b5c:  80 a4 60 00  cmp  %l1, 0
a0105b60:  06 80 00 26  bl  0xa0105bf8
a0105b64:  b6 10 20 01  mov  1, %i3
a0105b68:  40 01 40 36  call  0xa0155c40
a0105b6c:  d0 14 e0 02  lduh  [ %l3 + 2 ], %o0
a0105b70:  92 10 00 08  mov  %o0, %o1
a0105b74:  40 01 3f 2f  call  0xa0155830
a0105b78:  90 10 00 10  mov  %l0, %o0
a0105b7c:  a6 10 00 08  mov  %o0, %l3
a0105b80:  40 00 6b ee  call  0xa0120b38
a0105b84:  90 10 00 12  mov  %l2, %o0
a0105b88:  93 2a 20 10  sll  %o0, 0x10, %o1
a0105b8c:  40 01 40 2d  call  0xa0155c40
a0105b90:  91 32 60 10  srl  %o1, 0x10, %o0
a0105b94:  92 10 00 08  mov  %o0, %o1
a0105b98:  40 01 3f 26  call  0xa0155830
a0105b9c:  90 10 00 13  mov  %l3, %o0
a0105ba0:  21 00 06 6a  sethi  %hi(0x19a800), %l0
a0105ba4:  e2 04 23 a0  ld  [ %l0 + 0x3a0 ], %l1	! 0x19aba0
a0105ba8:  40 01 3f 9c  call  0xa0155a18
a0105bac:  92 10 00 11  mov  %l1, %o1
a0105bb0:  40 01 3f 9a  call  0xa0155a18
a0105bb4:  92 10 00 11  mov  %l1, %o1
a0105bb8:  40 01 3d 81  call  0xa01551bc
a0105bbc:  01 00 00 00  nop
a0105bc0:  81 80 00 00  mov  %g0, %y
a0105bc4:  01 00 00 00  nop
a0105bc8:  01 00 00 00  nop
a0105bcc:  01 00 00 00  nop
a0105bd0:  9e 75 00 08  udiv  %l4, %o0, %o7
a0105bd4:  80 a3 e0 0e  cmp  %o7, 0xe
a0105bd8:  38 80 00 04  bgu,a   0xa0105be8
a0105bdc:  b0 10 00 12  mov  %l2, %i0
a0105be0:  7f ff b1 d3  call  0xa00f232c
a0105be4:  81 e8 00 00  restore
a0105be8:  b2 10 20 91  mov  0x91, %i1
a0105bec:  b4 10 20 04  mov  4, %i2
a0105bf0:  7f ff b1 cf  call  0xa00f232c
a0105bf4:  97 e8 20 00  restore  %g0, 0, %o3
a0105bf8:  1b 00 06 68  sethi  %hi(0x19a000), %o5
a0105bfc:  40 01 3e e4  call  0xa015578c
a0105c00:  d2 03 62 d0  ld  [ %o5 + 0x2d0 ], %o1	! 0x19a2d0
a0105c04:  10 bf ff d9  b  0xa0105b68
a0105c08:  a0 10 00 08  mov  %o0, %l0
