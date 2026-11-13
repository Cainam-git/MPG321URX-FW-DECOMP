# leon2m FUN_a00d8b38 0xa00d8b38-0xa00d8bd8 (160 bytes)
a00d8b38:  9d e3 bf 98  save  %sp, -104, %sp
a00d8b3c:  92 10 20 02  mov  2, %o1
a00d8b40:  40 01 b2 c8  call  0xa0145660
a00d8b44:  90 10 20 00  clr  %o0
a00d8b48:  93 2a 20 10  sll  %o0, 0x10, %o1
a00d8b4c:  83 32 60 10  srl  %o1, 0x10, %g1
a00d8b50:  31 19 99 99  sethi  %hi(0x66666400), %i0
a00d8b54:  9a 16 22 67  or  %i0, 0x267, %o5	! 0x66666667
a00d8b58:  9e 00 60 05  add  %g1, 5, %o7
a00d8b5c:  80 5b c0 0d  smul  %o7, %o5, %g0
a00d8b60:  99 40 00 00  rd  %y, %o4
a00d8b64:  9b 3b 20 02  sra  %o4, 2, %o5
a00d8b68:  96 02 3b 4d  add  %o0, -1203, %o3
a00d8b6c:  94 03 7f 71  add  %o5, -143, %o2
a00d8b70:  93 2a e0 10  sll  %o3, 0x10, %o1
a00d8b74:  83 2a a0 10  sll  %o2, 0x10, %g1
a00d8b78:  91 32 60 10  srl  %o1, 0x10, %o0
a00d8b7c:  99 30 60 10  srl  %g1, 0x10, %o4
a00d8b80:  80 a2 20 04  cmp  %o0, 4
a00d8b84:  08 80 00 13  bleu  0xa00d8bd0
a00d8b88:  b0 10 20 78  mov  0x78, %i0
a00d8b8c:  94 03 7f 4d  add  %o5, -179, %o2
a00d8b90:  91 2a a0 10  sll  %o2, 0x10, %o0
a00d8b94:  97 32 20 10  srl  %o0, 0x10, %o3
a00d8b98:  80 a3 20 02  cmp  %o4, 2
a00d8b9c:  08 80 00 0d  bleu  0xa00d8bd0
a00d8ba0:  b0 10 20 90  mov  0x90, %i0
a00d8ba4:  9e 03 7f 11  add  %o5, -239, %o7
a00d8ba8:  99 2b e0 10  sll  %o7, 0x10, %o4
a00d8bac:  83 33 20 10  srl  %o4, 0x10, %g1
a00d8bb0:  80 a2 e0 02  cmp  %o3, 2
a00d8bb4:  08 80 00 07  bleu  0xa00d8bd0
a00d8bb8:  b0 10 20 b4  mov  0xb4, %i0
a00d8bbc:  80 a0 60 02  cmp  %g1, 2
a00d8bc0:  08 80 00 04  bleu  0xa00d8bd0
a00d8bc4:  b0 10 20 f0  mov  0xf0, %i0
a00d8bc8:  97 2b 60 10  sll  %o5, 0x10, %o3
a00d8bcc:  b1 32 e0 10  srl  %o3, 0x10, %i0
a00d8bd0:  81 c7 e0 08  ret
a00d8bd4:  81 e8 00 00  restore
