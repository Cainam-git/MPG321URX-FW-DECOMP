# leon2s FUN_a0089f98 0xa0089f98-0xa0089ff4 (92 bytes)
a0089f98:  9d e3 bf 98  save  %sp, -104, %sp
a0089f9c:  a4 10 00 18  mov  %i0, %l2
a0089fa0:  b0 10 20 00  clr  %i0
a0089fa4:  a2 10 20 00  clr  %l1
a0089fa8:  a0 0c 60 ff  and  %l1, 0xff, %l0
a0089fac:  7f ff ff f6  call  0xa0089f84
a0089fb0:  90 10 00 10  mov  %l0, %o0
a0089fb4:  82 10 20 01  mov  1, %g1
a0089fb8:  9b 28 40 10  sll  %g1, %l0, %o5
a0089fbc:  a2 04 60 01  inc  %l1
a0089fc0:  90 0a 20 ff  and  %o0, 0xff, %o0
a0089fc4:  82 0c a0 ff  and  %l2, 0xff, %g1
a0089fc8:  80 a2 00 01  cmp  %o0, %g1
a0089fcc:  12 80 00 03  bne  0xa0089fd8
a0089fd0:  98 0c 60 ff  and  %l1, 0xff, %o4
a0089fd4:  b0 13 40 18  or  %o5, %i0, %i0
a0089fd8:  80 a3 20 08  cmp  %o4, 8
a0089fdc:  08 bf ff f4  bleu  0xa0089fac
a0089fe0:  a0 0c 60 ff  and  %l1, 0xff, %l0
a0089fe4:  b1 2e 20 10  sll  %i0, 0x10, %i0
a0089fe8:  b1 36 20 10  srl  %i0, 0x10, %i0
a0089fec:  81 c7 e0 08  ret
a0089ff0:  81 e8 00 00  restore
