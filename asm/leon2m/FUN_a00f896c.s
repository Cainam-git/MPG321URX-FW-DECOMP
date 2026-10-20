# leon2m FUN_a00f896c 0xa00f896c-0xa00f8a98 (300 bytes)
a00f896c:  9d e3 bf 98  save  %sp, -104, %sp
a00f8970:  9b 2e 60 10  sll  %i1, 0x10, %o5
a00f8974:  83 33 60 13  srl  %o5, 0x13, %g1
a00f8978:  80 8e 60 07  btst  7, %i1
a00f897c:  12 80 00 03  bne  0xa00f8988
a00f8980:  b2 00 60 01  add  %g1, 1, %i1
a00f8984:  b2 10 00 01  mov  %g1, %i1
a00f8988:  91 2e a0 10  sll  %i2, 0x10, %o0
a00f898c:  83 32 20 13  srl  %o0, 0x13, %g1
a00f8990:  80 8e a0 07  btst  7, %i2
a00f8994:  12 80 00 03  bne  0xa00f89a0
a00f8998:  b4 00 60 01  add  %g1, 1, %i2
a00f899c:  b4 10 00 01  mov  %g1, %i2
a00f89a0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00f89a4:  40 00 13 9f  call  0xa00fd820
a00f89a8:  90 10 00 18  mov  %i0, %o0
a00f89ac:  90 0a 20 ff  and  %o0, 0xff, %o0
a00f89b0:  80 a2 20 b1  cmp  %o0, 0xb1
a00f89b4:  22 80 00 36  be,a   0xa00f8a8c
a00f89b8:  90 10 00 18  mov  %i0, %o0
a00f89bc:  94 1a 20 31  xor  %o0, 0x31, %o2
a00f89c0:  80 a0 00 0a  cmp  %g0, %o2
a00f89c4:  98 60 3f ff  subx  %g0, -1, %o4
a00f89c8:  92 1a 20 41  xor  %o0, 0x41, %o1
a00f89cc:  80 a0 00 09  cmp  %g0, %o1
a00f89d0:  82 60 3f ff  subx  %g0, -1, %g1
a00f89d4:  80 93 00 01  orcc  %o4, %g1, %g0
a00f89d8:  12 80 00 0a  bne  0xa00f8a00
a00f89dc:  82 1a 20 51  xor  %o0, 0x51, %g1
a00f89e0:  80 a0 00 01  cmp  %g0, %g1
a00f89e4:  9e 60 3f ff  subx  %g0, -1, %o7
a00f89e8:  9a 1a 20 61  xor  %o0, 0x61, %o5
a00f89ec:  80 a0 00 0d  cmp  %g0, %o5
a00f89f0:  96 60 3f ff  subx  %g0, -1, %o3
a00f89f4:  80 93 c0 0b  orcc  %o7, %o3, %g0
a00f89f8:  22 80 00 19  be,a   0xa00f8a5c
a00f89fc:  94 1a 20 71  xor  %o0, 0x71, %o2
a00f8a00:  90 10 00 18  mov  %i0, %o0
a00f8a04:  92 10 20 00  clr  %o1
a00f8a08:  94 10 20 01  mov  1, %o2
a00f8a0c:  7f ff e5 11  call  0xa00f1e50
a00f8a10:  01 00 00 00  nop
a00f8a14:  9f 2e 60 10  sll  %i1, 0x10, %o7
a00f8a18:  95 33 e0 10  srl  %o7, 0x10, %o2
a00f8a1c:  90 10 00 18  mov  %i0, %o0
a00f8a20:  7f ff e5 2e  call  0xa00f1ed8
a00f8a24:  92 10 20 10  mov  0x10, %o1
a00f8a28:  91 2e a0 10  sll  %i2, 0x10, %o0
a00f8a2c:  95 32 20 10  srl  %o0, 0x10, %o2
a00f8a30:  90 10 00 18  mov  %i0, %o0
a00f8a34:  7f ff e5 29  call  0xa00f1ed8
a00f8a38:  92 10 20 12  mov  0x12, %o1
a00f8a3c:  b3 2e e0 10  sll  %i3, 0x10, %i1
a00f8a40:  95 36 60 10  srl  %i1, 0x10, %o2
a00f8a44:  90 10 00 18  mov  %i0, %o0
a00f8a48:  7f ff e5 24  call  0xa00f1ed8
a00f8a4c:  92 10 20 14  mov  0x14, %o1
a00f8a50:  b2 10 20 16  mov  0x16, %i1
a00f8a54:  7f ff e4 ff  call  0xa00f1e50
a00f8a58:  95 e8 20 4a  restore  %g0, 0x4a, %o2
a00f8a5c:  80 a0 00 0a  cmp  %g0, %o2
a00f8a60:  92 1a 20 81  xor  %o0, 0x81, %o1
a00f8a64:  98 60 3f ff  subx  %g0, -1, %o4
a00f8a68:  80 a0 00 09  cmp  %g0, %o1
a00f8a6c:  96 60 3f ff  subx  %g0, -1, %o3
a00f8a70:  90 10 00 18  mov  %i0, %o0
a00f8a74:  92 10 20 00  clr  %o1
a00f8a78:  80 93 00 0b  orcc  %o4, %o3, %g0
a00f8a7c:  12 bf ff e4  bne  0xa00f8a0c
a00f8a80:  94 10 20 02  mov  2, %o2
a00f8a84:  10 bf ff e2  b  0xa00f8a0c
a00f8a88:  94 10 20 01  mov  1, %o2
a00f8a8c:  92 10 20 00  clr  %o1
a00f8a90:  10 bf ff df  b  0xa00f8a0c
a00f8a94:  94 10 20 00  clr  %o2
