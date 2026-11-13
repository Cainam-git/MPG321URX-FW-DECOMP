# leon2m FUN_a010ac68 0xa010ac68-0xa010ace4 (124 bytes)
a010ac68:  9d e3 bf 98  save  %sp, -104, %sp
a010ac6c:  67 fe 0a 47  call  0x4008d588
a010ac70:  01 00 00 00  nop
a010ac74:  03 33 c0 47  sethi  %hi(0xcf011c00), %g1
a010ac78:  a1 2a 20 10  sll  %o0, 0x10, %l0
a010ac7c:  a2 10 63 f4  or  %g1, 0x3f4, %l1
a010ac80:  67 fe 0a 45  call  0x4008d594
a010ac84:  91 34 20 10  srl  %l0, 0x10, %o0
a010ac88:  95 2a 20 10  sll  %o0, 0x10, %o2
a010ac8c:  93 32 a0 10  srl  %o2, 0x10, %o1
a010ac90:  80 a2 60 31  cmp  %o1, 0x31
a010ac94:  18 80 00 06  bgu  0xa010acac
a010ac98:  17 33 c0 47  sethi  %hi(0xcf011c00), %o3
a010ac9c:  d0 04 40 00  ld  [ %l1 ], %o0
a010aca0:  80 8a 20 01  btst  1, %o0
a010aca4:  12 bf ff f7  bne  0xa010ac80
a010aca8:  01 00 00 00  nop
a010acac:  a2 12 e3 f4  or  %o3, 0x3f4, %l1
a010acb0:  67 fe 0a 39  call  0x4008d594
a010acb4:  91 34 20 10  srl  %l0, 0x10, %o0
a010acb8:  9f 2a 20 10  sll  %o0, 0x10, %o7
a010acbc:  9b 33 e0 10  srl  %o7, 0x10, %o5
a010acc0:  80 a3 60 63  cmp  %o5, 0x63
a010acc4:  18 80 00 06  bgu  0xa010acdc
a010acc8:  01 00 00 00  nop
a010accc:  d8 04 40 00  ld  [ %l1 ], %o4
a010acd0:  80 8b 20 01  btst  1, %o4
a010acd4:  02 bf ff f7  be  0xa010acb0
a010acd8:  01 00 00 00  nop
a010acdc:  81 c7 e0 08  ret
a010ace0:  81 e8 00 00  restore
