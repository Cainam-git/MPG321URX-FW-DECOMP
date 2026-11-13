# leon2s FUN_a00a1a80 0xa00a1a80-0xa00a1b08 (136 bytes)
a00a1a80:  9d e3 bf 98  save  %sp, -104, %sp
a00a1a84:  a2 10 20 00  clr  %l1
a00a1a88:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00a1a8c:  25 2a 01 f5  sethi  %hi(0xa807d400), %l2
a00a1a90:  82 14 a3 e0  or  %l2, 0x3e0, %g1	! 0xa807d7e0
a00a1a94:  9a 5c 21 90  smul  %l0, 0x190, %o5
a00a1a98:  98 03 40 01  add  %o5, %g1, %o4
a00a1a9c:  c2 0b 20 03  ldub  [ %o4 + 3 ], %g1
a00a1aa0:  80 a0 60 00  cmp  %g1, 0
a00a1aa4:  22 80 00 12  be,a   0xa00a1aec
a00a1aa8:  c0 2b 20 02  clrb  [ %o4 + 2 ]
a00a1aac:  da 0b 20 01  ldub  [ %o4 + 1 ], %o5
a00a1ab0:  82 10 20 01  mov  1, %g1
a00a1ab4:  90 10 00 10  mov  %l0, %o0
a00a1ab8:  80 a3 60 01  cmp  %o5, 1
a00a1abc:  12 80 00 06  bne  0xa00a1ad4
a00a1ac0:  c2 2b 20 02  stb  %g1, [ %o4 + 2 ]
a00a1ac4:  7f ff f3 c2  call  0xa009e9cc
a00a1ac8:  01 00 00 00  nop
a00a1acc:  10 80 00 05  b  0xa00a1ae0
a00a1ad0:  9a 14 a3 e0  or  %l2, 0x3e0, %o5
a00a1ad4:  7f ff f3 ca  call  0xa009e9fc
a00a1ad8:  90 10 00 10  mov  %l0, %o0
a00a1adc:  9a 14 a3 e0  or  %l2, 0x3e0, %o5
a00a1ae0:  82 5c 21 90  smul  %l0, 0x190, %g1
a00a1ae4:  82 00 40 0d  add  %g1, %o5, %g1
a00a1ae8:  c0 28 60 01  clrb  [ %g1 + 1 ]
a00a1aec:  a2 04 60 01  inc  %l1
a00a1af0:  82 0c 60 ff  and  %l1, 0xff, %g1
a00a1af4:  80 a0 60 01  cmp  %g1, 1
a00a1af8:  08 bf ff e5  bleu  0xa00a1a8c
a00a1afc:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00a1b00:  81 c7 e0 08  ret
a00a1b04:  81 e8 00 00  restore
