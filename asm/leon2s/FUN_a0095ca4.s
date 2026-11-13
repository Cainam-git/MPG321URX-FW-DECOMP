# leon2s FUN_a0095ca4 0xa0095ca4-0xa0095d34 (144 bytes)
a0095ca4:  9d e3 bf 98  save  %sp, -104, %sp
a0095ca8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0095cac:  03 27 c6 c0  sethi  %hi(0x9f1b0000), %g1
a0095cb0:  82 10 62 00  or  %g1, 0x200, %g1	! 0x9f1b0200
a0095cb4:  9b 2e 20 09  sll  %i0, 9, %o5
a0095cb8:  a0 03 40 01  add  %o5, %g1, %l0
a0095cbc:  92 10 00 10  mov  %l0, %o1
a0095cc0:  90 10 00 18  mov  %i0, %o0
a0095cc4:  94 10 20 80  mov  0x80, %o2
a0095cc8:  7f ff f0 3b  call  0xa0091db4
a0095ccc:  96 10 20 00  clr  %o3
a0095cd0:  c2 0c 20 7f  ldub  [ %l0 + 0x7f ], %g1
a0095cd4:  80 a0 60 03  cmp  %g1, 3
a0095cd8:  08 80 00 03  bleu  0xa0095ce4
a0095cdc:  a0 04 20 80  add  %l0, 0x80, %l0
a0095ce0:  82 10 20 03  mov  3, %g1
a0095ce4:  a2 08 60 ff  and  %g1, 0xff, %l1
a0095ce8:  80 a4 60 00  cmp  %l1, 0
a0095cec:  02 80 00 10  be  0xa0095d2c
a0095cf0:  01 00 00 00  nop
a0095cf4:  02 80 00 0e  be  0xa0095d2c
a0095cf8:  a4 10 20 00  clr  %l2	! 0x0
a0095cfc:  96 0c a0 ff  and  %l2, 0xff, %o3
a0095d00:  97 2a e0 07  sll  %o3, 7, %o3
a0095d04:  92 10 00 10  mov  %l0, %o1
a0095d08:  96 02 e0 80  add  %o3, 0x80, %o3
a0095d0c:  90 10 00 18  mov  %i0, %o0
a0095d10:  7f ff f0 29  call  0xa0091db4
a0095d14:  94 10 20 80  mov  0x80, %o2
a0095d18:  a4 04 a0 01  inc  %l2
a0095d1c:  82 0c a0 ff  and  %l2, 0xff, %g1
a0095d20:  80 a0 40 11  cmp  %g1, %l1
a0095d24:  0a bf ff f6  bcs  0xa0095cfc
a0095d28:  a0 04 20 80  add  %l0, 0x80, %l0
a0095d2c:  81 c7 e0 08  ret
a0095d30:  81 e8 00 00  restore
