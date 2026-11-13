# leon2m FUN_a00d5eac 0xa00d5eac-0xa00d5f3c (144 bytes)
a00d5eac:  9d e3 bf 98  save  %sp, -104, %sp
a00d5eb0:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00d5eb4:  82 10 62 90  or  %g1, 0x290, %g1	! 0xa802d290
a00d5eb8:  da 08 60 1f  ldub  [ %g1 + 0x1f ], %o5
a00d5ebc:  80 a3 60 00  cmp  %o5, 0
a00d5ec0:  12 80 00 1d  bne  0xa00d5f34
a00d5ec4:  a0 10 00 18  mov  %i0, %l0
a00d5ec8:  d4 08 60 4a  ldub  [ %g1 + 0x4a ], %o2
a00d5ecc:  90 10 20 01  mov  1, %o0
a00d5ed0:  80 a2 a0 00  cmp  %o2, 0
a00d5ed4:  12 80 00 11  bne  0xa00d5f18
a00d5ed8:  92 10 20 01  mov  1, %o1
a00d5edc:  90 10 20 01  mov  1, %o0
a00d5ee0:  40 01 dd 65  call  0xa014d474
a00d5ee4:  92 10 20 00  clr  %o1
a00d5ee8:  90 10 20 01  mov  1, %o0
a00d5eec:  40 01 df ab  call  0xa014dd98
a00d5ef0:  92 10 20 00  clr  %o1
a00d5ef4:  90 10 20 01  mov  1, %o0
a00d5ef8:  92 10 20 00  clr  %o1
a00d5efc:  80 8c 20 ff  btst  0xff, %l0
a00d5f00:  02 80 00 0d  be  0xa00d5f34
a00d5f04:  b0 10 20 01  mov  1, %i0
a00d5f08:  40 01 dd 5b  call  0xa014d474
a00d5f0c:  01 00 00 00  nop
a00d5f10:  40 01 d0 2a  call  0xa0149fb8
a00d5f14:  81 e8 00 00  restore
a00d5f18:  40 01 df a0  call  0xa014dd98
a00d5f1c:  01 00 00 00  nop
a00d5f20:  90 10 20 01  mov  1, %o0	! 0x1
a00d5f24:  40 01 dd 54  call  0xa014d474
a00d5f28:  92 10 20 01  mov  1, %o1
a00d5f2c:  10 bf ff f3  b  0xa00d5ef8
a00d5f30:  90 10 20 01  mov  1, %o0
a00d5f34:  81 c7 e0 08  ret
a00d5f38:  81 e8 00 00  restore
