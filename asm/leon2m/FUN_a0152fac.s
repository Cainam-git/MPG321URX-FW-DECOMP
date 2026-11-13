# leon2m FUN_a0152fac 0xa0152fac-0xa0153018 (108 bytes)
a0152fac:  9d e3 bf 98  save  %sp, -104, %sp
a0152fb0:  7f ff 1a 6f  call  0xa011996c
a0152fb4:  90 10 20 00  clr  %o0
a0152fb8:  80 8a 20 ff  btst  0xff, %o0
a0152fbc:  23 2a 00 a9  sethi  %hi(0xa802a400), %l1
a0152fc0:  90 10 20 01  mov  1, %o0
a0152fc4:  02 80 00 0b  be  0xa0152ff0
a0152fc8:  a0 10 20 00  clr  %l0
a0152fcc:  a0 10 3f ff  mov  -1, %l0
a0152fd0:  c2 04 60 bc  ld  [ %l1 + 0xbc ], %g1
a0152fd4:  80 a4 00 01  cmp  %l0, %g1
a0152fd8:  02 80 00 0d  be  0xa015300c
a0152fdc:  90 10 00 10  mov  %l0, %o0
a0152fe0:  7f ff 9d d2  call  0xa013a728
a0152fe4:  01 00 00 00  nop
a0152fe8:  10 80 00 0a  b  0xa0153010
a0152fec:  e0 24 60 bc  st  %l0, [ %l1 + 0xbc ]
a0152ff0:  7f ff 1a 5f  call  0xa011996c
a0152ff4:  01 00 00 00  nop
a0152ff8:  80 8a 20 ff  btst  0xff, %o0
a0152ffc:  02 bf ff f6  be  0xa0152fd4
a0153000:  c2 04 60 bc  ld  [ %l1 + 0xbc ], %g1
a0153004:  10 bf ff f4  b  0xa0152fd4
a0153008:  a0 10 3f ff  mov  -1, %l0
a015300c:  e0 24 60 bc  st  %l0, [ %l1 + 0xbc ]
a0153010:  81 c7 e0 08  ret
a0153014:  81 e8 00 00  restore
