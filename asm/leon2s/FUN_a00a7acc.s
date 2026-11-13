# leon2s FUN_a00a7acc 0xa00a7acc-0xa00a7b64 (152 bytes)
a00a7acc:  82 10 00 09  mov  %o1, %g1
a00a7ad0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a7ad4:  83 28 60 10  sll  %g1, 0x10, %g1
a00a7ad8:  96 02 00 08  add  %o0, %o0, %o3
a00a7adc:  80 a2 20 04  cmp  %o0, 4
a00a7ae0:  9a 10 20 00  clr  %o5
a00a7ae4:  18 80 00 1e  bgu  0xa00a7b5c
a00a7ae8:  99 30 60 10  srl  %g1, 0x10, %o4
a00a7aec:  83 2a 60 10  sll  %o1, 0x10, %g1
a00a7af0:  80 a2 20 00  cmp  %o0, 0
a00a7af4:  02 80 00 11  be  0xa00a7b38
a00a7af8:  93 30 60 10  srl  %g1, 0x10, %o1
a00a7afc:  82 02 3f ff  add  %o0, -1, %g1
a00a7b00:  80 a2 60 5f  cmp  %o1, 0x5f
a00a7b04:  18 80 00 0d  bgu  0xa00a7b38
a00a7b08:  91 28 60 06  sll  %g1, 6, %o0
a00a7b0c:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00a7b10:  82 10 61 70  or  %g1, 0x170, %g1	! 0xa00b4d70
a00a7b14:  da 10 40 0b  lduh  [ %g1 + %o3 ], %o5
a00a7b18:  9a 03 60 60  add  %o5, 0x60, %o5
a00a7b1c:  03 33 c0 00  sethi  %hi(0xcf000000), %g1
a00a7b20:  9b 2b 60 02  sll  %o5, 2, %o5
a00a7b24:  9a 13 40 01  or  %o5, %g1, %o5
a00a7b28:  c2 03 40 00  ld  [ %o5 ], %g1
a00a7b2c:  82 08 60 3f  and  %g1, 0x3f, %g1
a00a7b30:  82 10 40 08  or  %g1, %o0, %g1
a00a7b34:  c2 23 40 00  st  %g1, [ %o5 ]
a00a7b38:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00a7b3c:  82 10 61 70  or  %g1, 0x170, %g1	! 0xa00b4d70
a00a7b40:  c2 10 40 0b  lduh  [ %g1 + %o3 ], %g1
a00a7b44:  82 00 40 0c  add  %g1, %o4, %g1
a00a7b48:  1b 33 c0 00  sethi  %hi(0xcf000000), %o5
a00a7b4c:  83 28 60 02  sll  %g1, 2, %g1
a00a7b50:  82 10 40 0d  or  %g1, %o5, %g1
a00a7b54:  c2 00 40 00  ld  [ %g1 ], %g1
a00a7b58:  9a 08 60 ff  and  %g1, 0xff, %o5
a00a7b5c:  81 c3 e0 08  retl
a00a7b60:  90 10 00 0d  mov  %o5, %o0
