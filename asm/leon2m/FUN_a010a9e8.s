# leon2m FUN_a010a9e8 0xa010a9e8-0xa010aae8 (256 bytes)
a010a9e8:  9d e3 bf 98  save  %sp, -104, %sp
a010a9ec:  31 33 c0 46  sethi  %hi(0xcf011800), %i0
a010a9f0:  82 16 22 80  or  %i0, 0x280, %g1	! 0xcf011a80
a010a9f4:  da 00 40 00  ld  [ %g1 ], %o5
a010a9f8:  80 8b 60 80  btst  0x80, %o5
a010a9fc:  22 80 00 2c  be,a   0xa010aaac
a010aa00:  31 33 c0 47  sethi  %hi(0xcf011c00), %i0
a010aa04:  7f ff a1 9d  call  0xa00f3078
a010aa08:  90 16 22 e0  or  %i0, 0x2e0, %o0	! 0xcf011ee0
a010aa0c:  a0 10 00 08  mov  %o0, %l0
a010aa10:  7f ff a1 9a  call  0xa00f3078
a010aa14:  90 16 22 e8  or  %i0, 0x2e8, %o0
a010aa18:  a0 04 00 08  add  %l0, %o0, %l0
a010aa1c:  7f ff a1 97  call  0xa00f3078
a010aa20:  90 16 22 f0  or  %i0, 0x2f0, %o0
a010aa24:  a0 04 00 08  add  %l0, %o0, %l0
a010aa28:  7f ff a1 94  call  0xa00f3078
a010aa2c:  90 16 22 f8  or  %i0, 0x2f8, %o0
a010aa30:  40 00 49 56  call  0xa011cf88
a010aa34:  a0 04 00 08  add  %l0, %o0, %l0
a010aa38:  90 0a 20 ff  and  %o0, 0xff, %o0
a010aa3c:  80 a2 20 82  cmp  %o0, 0x82
a010aa40:  18 80 00 1f  bgu  0xa010aabc
a010aa44:  b0 10 00 10  mov  %l0, %i0
a010aa48:  40 00 49 50  call  0xa011cf88
a010aa4c:  01 00 00 00  nop
a010aa50:  98 0a 20 ff  and  %o0, 0xff, %o4
a010aa54:  80 a3 20 83  cmp  %o4, 0x83
a010aa58:  08 80 00 07  bleu  0xa010aa74
a010aa5c:  03 33 c0 47  sethi  %hi(0xcf011c00), %g1
a010aa60:  9a 10 62 40  or  %g1, 0x240, %o5	! 0xcf011e40
a010aa64:  de 03 40 00  ld  [ %o5 ], %o7
a010aa68:  80 8b e0 04  btst  4, %o7
a010aa6c:  32 80 00 02  bne,a   0xa010aa74
a010aa70:  b1 2e 20 02  sll  %i0, 2, %i0
a010aa74:  40 00 49 45  call  0xa011cf88
a010aa78:  01 00 00 00  nop
a010aa7c:  90 0a 20 ff  and  %o0, 0xff, %o0
a010aa80:  80 a2 20 83  cmp  %o0, 0x83
a010aa84:  08 80 00 16  bleu  0xa010aadc
a010aa88:  97 2e 20 10  sll  %i0, 0x10, %o3
a010aa8c:  15 33 c0 47  sethi  %hi(0xcf011c00), %o2
a010aa90:  92 12 a2 40  or  %o2, 0x240, %o1	! 0xcf011e40
a010aa94:  e0 02 40 00  ld  [ %o1 ], %l0
a010aa98:  80 8c 20 02  btst  2, %l0
a010aa9c:  32 80 00 0f  bne,a   0xa010aad8
a010aaa0:  b1 2e 20 03  sll  %i0, 3, %i0
a010aaa4:  10 80 00 0f  b  0xa010aae0
a010aaa8:  b1 32 e0 10  srl  %o3, 0x10, %i0
a010aaac:  7f ff a1 73  call  0xa00f3078
a010aab0:  90 16 20 38  or  %i0, 0x38, %o0
a010aab4:  10 80 00 09  b  0xa010aad8
a010aab8:  b0 10 00 08  mov  %o0, %i0
a010aabc:  17 33 c0 47  sethi  %hi(0xcf011c00), %o3
a010aac0:  94 12 e2 40  or  %o3, 0x240, %o2	! 0xcf011e40
a010aac4:  d2 02 80 00  ld  [ %o2 ], %o1
a010aac8:  80 8a 60 08  btst  8, %o1
a010aacc:  32 bf ff df  bne,a   0xa010aa48
a010aad0:  b0 04 00 10  add  %l0, %l0, %i0
a010aad4:  30 bf ff dd  b,a   0xa010aa48
a010aad8:  97 2e 20 10  sll  %i0, 0x10, %o3
a010aadc:  b1 32 e0 10  srl  %o3, 0x10, %i0
a010aae0:  81 c7 e0 08  ret
a010aae4:  81 e8 00 00  restore
