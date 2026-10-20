# leon2m FUN_a0146870 0xa0146870-0xa01468d8 (104 bytes)
a0146870:  9d e3 bf 98  save  %sp, -104, %sp
a0146874:  82 0e 20 ff  and  %i0, 0xff, %g1
a0146878:  a0 10 00 1c  mov  %i4, %l0
a014687c:  80 a0 60 07  cmp  %g1, 7
a0146880:  18 80 00 0c  bgu  0xa01468b0
a0146884:  b8 0f 60 ff  and  %i5, 0xff, %i4
a0146888:  11 00 03 8c  sethi  %hi(0xe3000), %o0
a014688c:  83 28 60 02  sll  %g1, 2, %g1
a0146890:  9a 12 23 00  or  %o0, 0x300, %o5
a0146894:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a0146898:  81 c3 00 00  jmp  %o4
a014689c:  01 00 00 00  nop
a01468a0:  b8 0f 60 ff  and  %i5, 0xff, %i4
a01468a4:  90 10 20 07  mov  7, %o0
a01468a8:  67 fd 1f 8f  call  0x4008e6e4
a01468ac:  92 10 00 1c  mov  %i4, %o1
a01468b0:  b1 2e 60 10  sll  %i1, 0x10, %i0
a01468b4:  b3 2e a0 10  sll  %i2, 0x10, %i1
a01468b8:  b5 2e e0 10  sll  %i3, 0x10, %i2
a01468bc:  b7 2c 20 10  sll  %l0, 0x10, %i3
a01468c0:  b1 36 20 10  srl  %i0, 0x10, %i0
a01468c4:  b3 36 60 10  srl  %i1, 0x10, %i1
a01468c8:  b5 36 a0 10  srl  %i2, 0x10, %i2
a01468cc:  b7 36 e0 10  srl  %i3, 0x10, %i3
a01468d0:  67 fd 1f a5  call  0x4008e764
a01468d4:  81 e8 00 00  restore
