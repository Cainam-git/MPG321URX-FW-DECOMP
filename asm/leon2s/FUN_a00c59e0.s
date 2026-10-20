# leon2s FUN_a00c59e0 0xa00c59e0-0xa00c5ae4 (260 bytes)
a00c59e0:  9d e3 bf 98  save  %sp, -104, %sp
a00c59e4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c59e8:  90 10 00 18  mov  %i0, %o0
a00c59ec:  40 3b c9 2b  call  0xa0fb7e98
a00c59f0:  92 10 20 71  mov  0x71, %o1
a00c59f4:  90 0a 20 03  and  %o0, 3, %o0
a00c59f8:  80 a2 20 03  cmp  %o0, 3
a00c59fc:  12 80 00 38  bne  0xa00c5adc
a00c5a00:  90 10 00 18  mov  %i0, %o0
a00c5a04:  40 3b c9 25  call  0xa0fb7e98
a00c5a08:  92 10 20 2e  mov  0x2e, %o1
a00c5a0c:  80 8a 20 40  btst  0x40, %o0
a00c5a10:  12 80 00 04  bne  0xa00c5a20
a00c5a14:  b2 10 20 71  mov  0x71, %i1
a00c5a18:  40 3b c8 ee  call  0xa0fb7dd0
a00c5a1c:  95 e8 20 03  restore  %g0, 3, %o2
a00c5a20:  90 10 00 18  mov  %i0, %o0
a00c5a24:  92 10 20 71  mov  0x71, %o1
a00c5a28:  40 3b c8 ea  call  0xa0fb7dd0
a00c5a2c:  94 10 20 03  mov  3, %o2
a00c5a30:  90 10 00 18  mov  %i0, %o0
a00c5a34:  92 10 20 37  mov  0x37, %o1
a00c5a38:  94 10 20 04  mov  4, %o2
a00c5a3c:  40 3b c8 f6  call  0xa0fb7e14
a00c5a40:  96 10 20 00  clr  %o3
a00c5a44:  90 10 00 18  mov  %i0, %o0
a00c5a48:  92 10 20 88  mov  0x88, %o1
a00c5a4c:  94 10 20 40  mov  0x40, %o2
a00c5a50:  40 3b c8 f1  call  0xa0fb7e14
a00c5a54:  96 10 20 01  mov  1, %o3
a00c5a58:  90 10 00 18  mov  %i0, %o0
a00c5a5c:  92 10 20 37  mov  0x37, %o1
a00c5a60:  94 10 20 01  mov  1, %o2
a00c5a64:  40 3b c8 ec  call  0xa0fb7e14
a00c5a68:  96 10 20 01  mov  1, %o3
a00c5a6c:  90 10 00 18  mov  %i0, %o0
a00c5a70:  40 3b c9 0a  call  0xa0fb7e98
a00c5a74:  92 10 20 37  mov  0x37, %o1
a00c5a78:  80 8a 20 01  btst  1, %o0
a00c5a7c:  02 bf ff fd  be  0xa00c5a70
a00c5a80:  90 10 00 18  mov  %i0, %o0
a00c5a84:  92 10 20 88  mov  0x88, %o1
a00c5a88:  94 10 20 40  mov  0x40, %o2
a00c5a8c:  40 3b c8 e2  call  0xa0fb7e14
a00c5a90:  96 10 20 00  clr  %o3
a00c5a94:  90 10 00 18  mov  %i0, %o0
a00c5a98:  40 3b c9 00  call  0xa0fb7e98
a00c5a9c:  92 10 20 71  mov  0x71, %o1
a00c5aa0:  90 0a 20 03  and  %o0, 3, %o0
a00c5aa4:  80 a2 20 03  cmp  %o0, 3
a00c5aa8:  02 80 00 0d  be  0xa00c5adc
a00c5aac:  96 10 20 01  mov  1, %o3
a00c5ab0:  90 10 00 18  mov  %i0, %o0
a00c5ab4:  92 10 20 2e  mov  0x2e, %o1
a00c5ab8:  40 3b c8 d7  call  0xa0fb7e14
a00c5abc:  94 10 20 28  mov  0x28, %o2
a00c5ac0:  19 2a 01 f5  sethi  %hi(0xa807d400), %o4
a00c5ac4:  98 13 21 c8  or  %o4, 0x1c8, %o4	! 0xa807d5c8
a00c5ac8:  97 2e 20 04  sll  %i0, 4, %o3
a00c5acc:  c2 03 00 0b  ld  [ %o4 + %o3 ], %g1
a00c5ad0:  1b 00 20 00  sethi  %hi(0x800000), %o5
a00c5ad4:  82 10 40 0d  or  %g1, %o5, %g1
a00c5ad8:  c2 23 00 0b  st  %g1, [ %o4 + %o3 ]
a00c5adc:  81 c7 e0 08  ret
a00c5ae0:  81 e8 00 00  restore
