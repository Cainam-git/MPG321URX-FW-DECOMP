# leon2m FUN_a0148ef4 0xa0148ef4-0xa0148f4c (88 bytes)
a0148ef4:  9d e3 bf 98  save  %sp, -104, %sp
a0148ef8:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a0148efc:  da 03 23 d0  ld  [ %o4 + 0x3d0 ], %o5	! 0xa802e3d0
a0148f00:  15 00 80 00  sethi  %hi(0x2000000), %o2
a0148f04:  92 0e 20 01  and  %i0, 1, %o1
a0148f08:  90 2b 40 0a  andn  %o5, %o2, %o0
a0148f0c:  b1 2a 60 19  sll  %o1, 0x19, %i0
a0148f10:  82 12 00 18  or  %o0, %i0, %g1
a0148f14:  c2 23 23 d0  st  %g1, [ %o4 + 0x3d0 ]
a0148f18:  90 10 20 00  clr  %o0
a0148f1c:  7f ff 98 b4  call  0xa012f1ec
a0148f20:  92 10 20 01  mov  1, %o1
a0148f24:  90 10 20 01  mov  1, %o0
a0148f28:  7f ff 98 b1  call  0xa012f1ec
a0148f2c:  92 10 20 01  mov  1, %o1
a0148f30:  90 10 20 02  mov  2, %o0
a0148f34:  7f ff 98 ae  call  0xa012f1ec
a0148f38:  92 10 20 01  mov  1, %o1
a0148f3c:  b0 10 20 03  mov  3, %i0
a0148f40:  7f ff 98 ab  call  0xa012f1ec
a0148f44:  93 e8 20 01  restore  %g0, 1, %o1
a0148f48:  01 00 00 00  nop
