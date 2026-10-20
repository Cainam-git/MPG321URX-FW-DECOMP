# leon2m FUN_a0083b60 0xa0083b60-0xa0083be0 (128 bytes)
a0083b60:  9d e3 bf 98  save  %sp, -104, %sp
a0083b64:  40 03 13 41  call  0xa0148868
a0083b68:  01 00 00 00  nop
a0083b6c:  a0 0a 20 ff  and  %o0, 0xff, %l0
a0083b70:  11 00 03 fb  sethi  %hi(0xfec00), %o0
a0083b74:  92 10 00 10  mov  %l0, %o1
a0083b78:  40 01 6d 7e  call  0xa00df170
a0083b7c:  90 12 22 f8  or  %o0, 0x2f8, %o0
a0083b80:  82 1c 20 04  xor  %l0, 4, %g1
a0083b84:  80 a4 20 03  cmp  %l0, 3
a0083b88:  02 80 00 0c  be  0xa0083bb8
a0083b8c:  a0 10 20 01  mov  1, %l0
a0083b90:  80 a0 00 01  cmp  %g0, %g1
a0083b94:  92 40 20 00  addx  %g0, 0, %o1
a0083b98:  a0 10 00 09  mov  %o1, %l0
a0083b9c:  80 8c 20 ff  btst  0xff, %l0
a0083ba0:  02 80 00 0e  be  0xa0083bd8
a0083ba4:  01 00 00 00  nop
a0083ba8:  40 02 83 e6  call  0xa0124b40
a0083bac:  01 00 00 00  nop
a0083bb0:  40 02 83 ae  call  0xa0124a68
a0083bb4:  81 e8 00 00  restore
a0083bb8:  40 03 13 9b  call  0xa0148a24
a0083bbc:  01 00 00 00  nop
a0083bc0:  82 0a 20 ff  and  %o0, 0xff, %g1
a0083bc4:  80 a0 60 01  cmp  %g1, 1
a0083bc8:  22 bf ff f5  be,a   0xa0083b9c
a0083bcc:  a0 10 20 00  clr  %l0
a0083bd0:  10 bf ff f4  b  0xa0083ba0
a0083bd4:  80 8c 20 ff  btst  0xff, %l0
a0083bd8:  81 c7 e0 08  ret
a0083bdc:  81 e8 00 00  restore
