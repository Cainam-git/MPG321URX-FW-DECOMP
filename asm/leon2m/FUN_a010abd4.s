# leon2m FUN_a010abd4 0xa010abd4-0xa010ac68 (148 bytes)
a010abd4:  9d e3 bf 98  save  %sp, -104, %sp
a010abd8:  67 fe 0a 6c  call  0x4008d588
a010abdc:  01 00 00 00  nop
a010abe0:  9a 0e 20 ff  and  %i0, 0xff, %o5
a010abe4:  03 33 c0 47  sethi  %hi(0xcf011c00), %g1
a010abe8:  a3 2a 20 10  sll  %o0, 0x10, %l1
a010abec:  a4 10 63 f4  or  %g1, 0x3f4, %l2
a010abf0:  a0 03 60 04  add  %o5, 4, %l0
a010abf4:  67 fe 0a 68  call  0x4008d594
a010abf8:  91 34 60 10  srl  %l1, 0x10, %o0
a010abfc:  97 2a 20 10  sll  %o0, 0x10, %o3
a010ac00:  95 32 e0 10  srl  %o3, 0x10, %o2
a010ac04:  80 a2 a0 31  cmp  %o2, 0x31
a010ac08:  18 80 00 07  bgu  0xa010ac24
a010ac0c:  98 0e 20 ff  and  %i0, 0xff, %o4
a010ac10:  d2 04 80 00  ld  [ %l2 ], %o1
a010ac14:  91 32 40 10  srl  %o1, %l0, %o0
a010ac18:  80 8a 20 01  btst  1, %o0
a010ac1c:  12 bf ff f6  bne  0xa010abf4
a010ac20:  01 00 00 00  nop
a010ac24:  1f 33 c0 47  sethi  %hi(0xcf011c00), %o7
a010ac28:  a0 13 e3 f4  or  %o7, 0x3f4, %l0	! 0xcf011ff4
a010ac2c:  b0 03 20 04  add  %o4, 4, %i0
a010ac30:  67 fe 0a 59  call  0x4008d594
a010ac34:  91 34 60 10  srl  %l1, 0x10, %o0
a010ac38:  91 2a 20 10  sll  %o0, 0x10, %o0
a010ac3c:  83 32 20 10  srl  %o0, 0x10, %g1
a010ac40:  80 a0 60 63  cmp  %g1, 0x63
a010ac44:  18 80 00 07  bgu  0xa010ac60
a010ac48:  01 00 00 00  nop
a010ac4c:  da 04 00 00  ld  [ %l0 ], %o5
a010ac50:  a5 33 40 18  srl  %o5, %i0, %l2
a010ac54:  80 8c a0 01  btst  1, %l2
a010ac58:  02 bf ff f6  be  0xa010ac30
a010ac5c:  01 00 00 00  nop
a010ac60:  81 c7 e0 08  ret
a010ac64:  81 e8 00 00  restore
