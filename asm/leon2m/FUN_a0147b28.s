# leon2m FUN_a0147b28 0xa0147b28-0xa0147b70 (72 bytes)
a0147b28:  9d e3 bf 90  save  %sp, -112, %sp
a0147b2c:  da 0f a0 63  ldub  [ %fp + 0x63 ], %o5
a0147b30:  c2 17 a0 5e  lduh  [ %fp + 0x5e ], %g1
a0147b34:  da 23 a0 60  st  %o5, [ %sp + 0x60 ]
a0147b38:  95 2e a0 10  sll  %i2, 0x10, %o2
a0147b3c:  97 2e e0 10  sll  %i3, 0x10, %o3
a0147b40:  90 0e 20 ff  and  %i0, 0xff, %o0
a0147b44:  c2 23 a0 5c  st  %g1, [ %sp + 0x5c ]
a0147b48:  92 10 00 19  mov  %i1, %o1
a0147b4c:  95 32 a0 10  srl  %o2, 0x10, %o2
a0147b50:  97 32 e0 10  srl  %o3, 0x10, %o3
a0147b54:  98 0f 20 ff  and  %i4, 0xff, %o4
a0147b58:  7f ff 76 ff  call  0xa0125754
a0147b5c:  9a 10 00 1d  mov  %i5, %o5
a0147b60:  91 2a 20 10  sll  %o0, 0x10, %o0
a0147b64:  b1 32 20 10  srl  %o0, 0x10, %i0
a0147b68:  81 c7 e0 08  ret
a0147b6c:  81 e8 00 00  restore
