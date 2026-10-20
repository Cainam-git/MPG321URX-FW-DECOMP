# leon2m FUN_a0121bcc 0xa0121bcc-0xa0121c6c (160 bytes)
a0121bcc:  9d e3 bf 98  save  %sp, -104, %sp
a0121bd0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0121bd4:  80 a6 20 0a  cmp  %i0, 0xa
a0121bd8:  38 80 00 02  bgu,a   0xa0121be0
a0121bdc:  b0 10 20 0a  mov  0xa, %i0
a0121be0:  94 06 7f 38  add  %i1, -200, %o2
a0121be4:  93 2a a0 10  sll  %o2, 0x10, %o1
a0121be8:  91 2e 20 02  sll  %i0, 2, %o0
a0121bec:  83 32 60 10  srl  %o1, 0x10, %g1
a0121bf0:  9a 02 00 18  add  %o0, %i0, %o5
a0121bf4:  80 a0 6d 7a  cmp  %g1, 0xd7a
a0121bf8:  18 80 00 0d  bgu  0xa0121c2c
a0121bfc:  a1 2b 60 02  sll  %o5, 2, %l0
a0121c00:  a1 2e 60 10  sll  %i1, 0x10, %l0
a0121c04:  1b 00 00 09  sethi  %hi(0x2400), %o5
a0121c08:  b2 13 63 10  or  %o5, 0x310, %i1	! 0x2710
a0121c0c:  9f 34 20 10  srl  %l0, 0x10, %o7
a0121c10:  98 5e 00 19  smul  %i0, %i1, %o4
a0121c14:  81 80 00 00  mov  %g0, %y
a0121c18:  01 00 00 00  nop
a0121c1c:  01 00 00 00  nop
a0121c20:  01 00 00 00  nop
a0121c24:  96 73 00 0f  udiv  %o4, %o7, %o3
a0121c28:  a0 02 e0 01  add  %o3, 1, %l0
a0121c2c:  67 fd ae 57  call  0x4008d588
a0121c30:  01 00 00 00  nop
a0121c34:  83 2c 20 10  sll  %l0, 0x10, %g1
a0121c38:  b1 2a 20 10  sll  %o0, 0x10, %i0
a0121c3c:  10 80 00 03  b  0xa0121c48
a0121c40:  b3 30 60 10  srl  %g1, 0x10, %i1
a0121c44:  01 00 00 00  nop
a0121c48:  67 fd ae 53  call  0x4008d594
a0121c4c:  91 36 20 10  srl  %i0, 0x10, %o0
a0121c50:  93 2a 20 10  sll  %o0, 0x10, %o1
a0121c54:  91 32 60 10  srl  %o1, 0x10, %o0
a0121c58:  80 a2 00 19  cmp  %o0, %i1
a0121c5c:  0a bf ff fa  bcs  0xa0121c44
a0121c60:  01 00 00 00  nop
a0121c64:  81 c7 e0 08  ret
a0121c68:  81 e8 00 00  restore
