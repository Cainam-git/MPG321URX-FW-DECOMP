# leon2m FUN_a0120b38 0xa0120b38-0xa0120bf4 (188 bytes)
a0120b38:  9d e3 bf 98  save  %sp, -104, %sp
a0120b3c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0120b40:  90 10 00 18  mov  %i0, %o0
a0120b44:  7f ff 45 ab  call  0xa00f21f0
a0120b48:  92 10 20 14  mov  0x14, %o1
a0120b4c:  98 06 00 18  add  %i0, %i0, %o4
a0120b50:  82 03 00 18  add  %o4, %i0, %g1
a0120b54:  9e 02 3b fd  add  %o0, -1027, %o7
a0120b58:  9b 28 60 02  sll  %g1, 2, %o5
a0120b5c:  95 2b e0 10  sll  %o7, 0x10, %o2
a0120b60:  13 00 00 11  sethi  %hi(0x4400), %o1
a0120b64:  17 2a 00 9e  sethi  %hi(0xa8027800), %o3
a0120b68:  82 12 61 3b  or  %o1, 0x13b, %g1
a0120b6c:  99 32 a0 10  srl  %o2, 0x10, %o4
a0120b70:  b0 12 e2 ac  or  %o3, 0x2ac, %i0
a0120b74:  80 a3 00 01  cmp  %o4, %g1
a0120b78:  96 03 40 18  add  %o5, %i0, %o3
a0120b7c:  18 80 00 1a  bgu  0xa0120be4
a0120b80:  82 10 3f ff  mov  -1, %g1
a0120b84:  95 2a 20 10  sll  %o0, 0x10, %o2
a0120b88:  d2 02 e0 04  ld  [ %o3 + 4 ], %o1
a0120b8c:  80 a2 60 01  cmp  %o1, 1
a0120b90:  02 80 00 0c  be  0xa0120bc0
a0120b94:  99 32 a0 10  srl  %o2, 0x10, %o4
a0120b98:  13 01 c9 c3  sethi  %hi(0x7270c00), %o1
a0120b9c:  b0 12 62 00  or  %o1, 0x200, %i0	! 0x7270e00
a0120ba0:  81 80 00 00  mov  %g0, %y
a0120ba4:  01 00 00 00  nop
a0120ba8:  01 00 00 00  nop
a0120bac:  01 00 00 00  nop
a0120bb0:  98 76 00 0c  udiv  %i0, %o4, %o4
a0120bb4:  82 03 20 80  add  %o4, 0x80, %g1
a0120bb8:  10 80 00 0b  b  0xa0120be4
a0120bbc:  83 30 60 08  srl  %g1, 8, %g1
a0120bc0:  17 01 c9 c3  sethi  %hi(0x7270c00), %o3
a0120bc4:  9a 12 e2 00  or  %o3, 0x200, %o5	! 0x7270e00
a0120bc8:  81 80 00 00  mov  %g0, %y
a0120bcc:  01 00 00 00  nop
a0120bd0:  01 00 00 00  nop
a0120bd4:  01 00 00 00  nop
a0120bd8:  9e 73 40 0c  udiv  %o5, %o4, %o7
a0120bdc:  90 03 e0 10  add  %o7, 0x10, %o0
a0120be0:  83 32 20 05  srl  %o0, 5, %g1
a0120be4:  95 28 60 10  sll  %g1, 0x10, %o2
a0120be8:  b1 32 a0 10  srl  %o2, 0x10, %i0
a0120bec:  81 c7 e0 08  ret
a0120bf0:  81 e8 00 00  restore
