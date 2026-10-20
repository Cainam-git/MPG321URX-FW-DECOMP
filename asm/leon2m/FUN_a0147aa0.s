# leon2m FUN_a0147aa0 0xa0147aa0-0xa0147ae8 (72 bytes)
a0147aa0:  9d e3 bf 90  save  %sp, -112, %sp
a0147aa4:  da 0f a0 63  ldub  [ %fp + 0x63 ], %o5
a0147aa8:  c2 17 a0 5e  lduh  [ %fp + 0x5e ], %g1
a0147aac:  da 23 a0 60  st  %o5, [ %sp + 0x60 ]
a0147ab0:  95 2e a0 10  sll  %i2, 0x10, %o2
a0147ab4:  97 2e e0 10  sll  %i3, 0x10, %o3
a0147ab8:  90 0e 20 ff  and  %i0, 0xff, %o0
a0147abc:  c2 23 a0 5c  st  %g1, [ %sp + 0x5c ]
a0147ac0:  92 0e 60 ff  and  %i1, 0xff, %o1
a0147ac4:  95 32 a0 10  srl  %o2, 0x10, %o2
a0147ac8:  97 32 e0 10  srl  %o3, 0x10, %o3
a0147acc:  98 0f 20 ff  and  %i4, 0xff, %o4
a0147ad0:  7f ff 76 dd  call  0xa0125644
a0147ad4:  9a 10 00 1d  mov  %i5, %o5
a0147ad8:  91 2a 20 10  sll  %o0, 0x10, %o0
a0147adc:  b1 32 20 10  srl  %o0, 0x10, %i0
a0147ae0:  81 c7 e0 08  ret
a0147ae4:  81 e8 00 00  restore
