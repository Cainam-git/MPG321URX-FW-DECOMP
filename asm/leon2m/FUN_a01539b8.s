# leon2m FUN_a01539b8 0xa01539b8-0xa0153a5c (164 bytes)
a01539b8:  9d e3 bf 88  save  %sp, -120, %sp
a01539bc:  a2 07 bf e8  add  %fp, -24, %l1
a01539c0:  13 00 06 9d  sethi  %hi(0x1a7400), %o1
a01539c4:  92 12 61 e6  or  %o1, 0x1e6, %o1	! 0x1a75e6
a01539c8:  90 10 00 11  mov  %l1, %o0
a01539cc:  7f ff a3 d1  call  0xa013c910
a01539d0:  94 10 20 10  mov  0x10, %o2
a01539d4:  a0 10 20 00  clr  %l0
a01539d8:  99 2c 20 10  sll  %l0, 0x10, %o4
a01539dc:  97 33 20 0c  srl  %o4, 0xc, %o3
a01539e0:  94 02 e3 00  add  %o3, 0x300, %o2
a01539e4:  91 2a a0 10  sll  %o2, 0x10, %o0
a01539e8:  93 32 20 10  srl  %o0, 0x10, %o1
a01539ec:  90 10 20 00  clr  %o0
a01539f0:  94 10 20 10  mov  0x10, %o2
a01539f4:  96 10 00 11  mov  %l1, %o3
a01539f8:  7f ff b5 1f  call  0xa0140e74
a01539fc:  98 10 20 00  clr  %o4
a0153a00:  9a 04 20 01  add  %l0, 1, %o5
a0153a04:  83 2b 60 10  sll  %o5, 0x10, %g1
a0153a08:  83 30 60 10  srl  %g1, 0x10, %g1
a0153a0c:  80 a0 60 14  cmp  %g1, 0x14
a0153a10:  0a bf ff f2  bcs  0xa01539d8
a0153a14:  a0 10 00 0d  mov  %o5, %l0
a0153a18:  93 28 60 04  sll  %g1, 4, %o1
a0153a1c:  9a 10 21 40  mov  0x140, %o5
a0153a20:  a0 23 40 09  sub  %o5, %o1, %l0
a0153a24:  9f 2c 20 10  sll  %l0, 0x10, %o7
a0153a28:  95 33 e0 10  srl  %o7, 0x10, %o2
a0153a2c:  80 a2 a0 00  cmp  %o2, 0
a0153a30:  02 80 00 08  be  0xa0153a50
a0153a34:  82 02 63 00  add  %o1, 0x300, %g1
a0153a38:  93 28 60 10  sll  %g1, 0x10, %o1
a0153a3c:  93 32 60 10  srl  %o1, 0x10, %o1
a0153a40:  96 10 00 11  mov  %l1, %o3
a0153a44:  90 10 20 00  clr  %o0
a0153a48:  7f ff b5 0b  call  0xa0140e74
a0153a4c:  98 10 20 00  clr  %o4
a0153a50:  01 00 00 00  nop
a0153a54:  81 c7 e0 08  ret
a0153a58:  81 e8 00 00  restore
