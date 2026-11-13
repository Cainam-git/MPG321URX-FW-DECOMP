# leon2m FUN_a0109b70 0xa0109b70-0xa0109bbc (76 bytes)
a0109b70:  9d e3 bf 98  save  %sp, -104, %sp
a0109b74:  b1 2e 20 10  sll  %i0, 0x10, %i0
a0109b78:  21 33 c0 47  sethi  %hi(0xcf011c00), %l0
a0109b7c:  a3 36 20 10  srl  %i0, 0x10, %l1
a0109b80:  90 14 21 08  or  %l0, 0x108, %o0
a0109b84:  7f ff a5 42  call  0xa00f308c
a0109b88:  92 10 00 11  mov  %l1, %o1
a0109b8c:  90 14 21 00  or  %l0, 0x100, %o0
a0109b90:  7f ff a5 3f  call  0xa00f308c
a0109b94:  92 10 20 00  clr  %o1
a0109b98:  82 14 22 c4  or  %l0, 0x2c4, %g1
a0109b9c:  a2 0c 60 ff  and  %l1, 0xff, %l1
a0109ba0:  91 36 20 18  srl  %i0, 0x18, %o0
a0109ba4:  e2 20 40 00  st  %l1, [ %g1 ]
a0109ba8:  a0 14 22 c0  or  %l0, 0x2c0, %l0
a0109bac:  b0 12 20 80  or  %o0, 0x80, %i0
a0109bb0:  f0 24 00 00  st  %i0, [ %l0 ]
a0109bb4:  81 c7 e0 08  ret
a0109bb8:  81 e8 00 00  restore
