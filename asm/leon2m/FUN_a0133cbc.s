# leon2m FUN_a0133cbc 0xa0133cbc-0xa0133cf4 (56 bytes)
a0133cbc:  9d e3 bf 90  save  %sp, -112, %sp
a0133cc0:  90 10 20 00  clr  %o0
a0133cc4:  92 10 20 0c  mov  0xc, %o1
a0133cc8:  c0 27 bf f4  clr  [ %fp + -12 ]
a0133ccc:  94 07 bf f4  add  %fp, -12, %o2
a0133cd0:  67 fd 62 00  call  0x4008c4d0
a0133cd4:  96 10 20 01  mov  1, %o3
a0133cd8:  92 10 00 18  mov  %i0, %o1
a0133cdc:  83 2a 60 03  sll  %o1, 3, %g1
a0133ce0:  d0 07 bf f4  ld  [ %fp + -12 ], %o0
a0133ce4:  b1 32 00 01  srl  %o0, %g1, %i0
a0133ce8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0133cec:  81 c7 e0 08  ret
a0133cf0:  81 e8 00 00  restore
