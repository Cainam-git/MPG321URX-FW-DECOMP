# leon2m FUN_a0147d0c 0xa0147d0c-0xa0147d70 (100 bytes)
a0147d0c:  9d e3 bf 98  save  %sp, -104, %sp
a0147d10:  9e 0e 60 ff  and  %i1, 0xff, %o7
a0147d14:  b2 03 c0 18  add  %o7, %i0, %i1
a0147d18:  7f ff 6f cd  call  0xa0123c4c
a0147d1c:  d0 0e 7f f8  ldub  [ %i1 + -8 ], %o0
a0147d20:  9a 0a 20 ff  and  %o0, 0xff, %o5
a0147d24:  b1 2b 60 0c  sll  %o5, 0xc, %i0
a0147d28:  7f ff 6f c9  call  0xa0123c4c
a0147d2c:  d0 0e 7f f9  ldub  [ %i1 + -7 ], %o0
a0147d30:  98 0a 20 ff  and  %o0, 0xff, %o4
a0147d34:  97 2b 20 08  sll  %o4, 8, %o3
a0147d38:  b0 16 00 0b  or  %i0, %o3, %i0
a0147d3c:  7f ff 6f c4  call  0xa0123c4c
a0147d40:  d0 0e 7f fa  ldub  [ %i1 + -6 ], %o0
a0147d44:  94 0a 20 ff  and  %o0, 0xff, %o2
a0147d48:  93 2a a0 04  sll  %o2, 4, %o1
a0147d4c:  b0 16 00 09  or  %i0, %o1, %i0
a0147d50:  7f ff 6f bf  call  0xa0123c4c
a0147d54:  d0 0e 7f fb  ldub  [ %i1 + -5 ], %o0
a0147d58:  90 0a 20 ff  and  %o0, 0xff, %o0
a0147d5c:  82 16 00 08  or  %i0, %o0, %g1
a0147d60:  b1 28 60 10  sll  %g1, 0x10, %i0
a0147d64:  b1 36 20 10  srl  %i0, 0x10, %i0
a0147d68:  81 c7 e0 08  ret
a0147d6c:  81 e8 00 00  restore
