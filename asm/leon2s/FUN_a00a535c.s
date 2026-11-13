# leon2s FUN_a00a535c 0xa00a535c-0xa00a53b0 (84 bytes)
a00a535c:  9d e3 bf 98  save  %sp, -104, %sp
a00a5360:  b1 2e 20 10  sll  %i0, 0x10, %i0
a00a5364:  b1 36 20 10  srl  %i0, 0x10, %i0
a00a5368:  b3 2e 60 10  sll  %i1, 0x10, %i1
a00a536c:  b4 5e 80 18  smul  %i2, %i0, %i2
a00a5370:  b3 36 60 10  srl  %i1, 0x10, %i1
a00a5374:  81 80 00 00  mov  %g0, %y
a00a5378:  01 00 00 00  nop
a00a537c:  01 00 00 00  nop
a00a5380:  01 00 00 00  nop
a00a5384:  b4 76 80 19  udiv  %i2, %i1, %i2
a00a5388:  b4 5e a0 64  smul  %i2, 0x64, %i2
a00a538c:  11 28 01 b0  sethi  %hi(0xa006c000), %o0
a00a5390:  92 10 00 1a  mov  %i2, %o1
a00a5394:  7f ff 37 2c  call  0xa0073044
a00a5398:  90 12 20 70  or  %o0, 0x70, %o0
a00a539c:  90 10 20 00  clr  %o0
a00a53a0:  7f ff ff 6a  call  0xa00a5148
a00a53a4:  92 10 00 1a  mov  %i2, %o1
a00a53a8:  81 c7 e0 08  ret
a00a53ac:  91 e8 00 1a  restore  %g0, %i2, %o0
