# leon2m FUN_a0147ae8 0xa0147ae8-0xa0147b28 (64 bytes)
a0147ae8:  9d e3 bf 90  save  %sp, -112, %sp
a0147aec:  c2 17 a0 5e  lduh  [ %fp + 0x5e ], %g1
a0147af0:  95 2e a0 10  sll  %i2, 0x10, %o2
a0147af4:  97 2e e0 10  sll  %i3, 0x10, %o3
a0147af8:  90 0e 20 ff  and  %i0, 0xff, %o0
a0147afc:  c2 23 a0 5c  st  %g1, [ %sp + 0x5c ]
a0147b00:  92 0e 60 ff  and  %i1, 0xff, %o1
a0147b04:  95 32 a0 10  srl  %o2, 0x10, %o2
a0147b08:  97 32 e0 10  srl  %o3, 0x10, %o3
a0147b0c:  98 0f 20 ff  and  %i4, 0xff, %o4
a0147b10:  7f ff 76 f0  call  0xa01256d0
a0147b14:  9a 10 00 1d  mov  %i5, %o5
a0147b18:  91 2a 20 10  sll  %o0, 0x10, %o0
a0147b1c:  b1 32 20 10  srl  %o0, 0x10, %i0
a0147b20:  81 c7 e0 08  ret
a0147b24:  81 e8 00 00  restore
