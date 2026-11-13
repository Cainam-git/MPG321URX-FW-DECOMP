# leon2s FUN_a006fc58 0xa006fc58-0xa006fca8 (80 bytes)
a006fc58:  9d e3 bf 90  save  %sp, -112, %sp
a006fc5c:  90 10 20 00  clr  %o0
a006fc60:  92 10 20 03  mov  3, %o1
a006fc64:  94 07 bf f4  add  %fp, -12, %o2
a006fc68:  7f ff ff 90  call  0xa006faa8
a006fc6c:  96 10 20 01  mov  1, %o3
a006fc70:  b0 0e 20 ff  and  %i0, 0xff, %i0
a006fc74:  1b 00 00 40  sethi  %hi(0x10000), %o5
a006fc78:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a006fc7c:  9b 2b 40 18  sll  %o5, %i0, %o5
a006fc80:  82 10 40 0d  or  %g1, %o5, %g1
a006fc84:  c2 27 bf f4  st  %g1, [ %fp + -12 ]
a006fc88:  90 10 20 00  clr  %o0
a006fc8c:  92 10 20 03  mov  3, %o1
a006fc90:  94 07 bf f4  add  %fp, -12, %o2
a006fc94:  7f ff ff 90  call  0xa006fad4
a006fc98:  96 10 20 01  mov  1, %o3
a006fc9c:  01 00 00 00  nop
a006fca0:  81 c7 e0 08  ret
a006fca4:  81 e8 00 00  restore
