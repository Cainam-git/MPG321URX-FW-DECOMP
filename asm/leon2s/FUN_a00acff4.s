# leon2s FUN_a00acff4 0xa00acff4-0xa00ad054 (96 bytes)
a00acff4:  9d e3 bf 98  save  %sp, -104, %sp
a00acff8:  21 33 c0 4c  sethi  %hi(0xcf013000), %l0
a00acffc:  a0 14 22 c0  or  %l0, 0x2c0, %l0	! 0xcf0132c0
a00ad000:  c2 04 00 00  ld  [ %l0 ], %g1
a00ad004:  82 10 60 02  or  %g1, 2, %g1
a00ad008:  c2 24 00 00  st  %g1, [ %l0 ]
a00ad00c:  40 00 11 e2  call  0xa00b1794
a00ad010:  90 10 20 01  mov  1, %o0
a00ad014:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00ad018:  98 10 60 18  or  %g1, 0x18, %o4	! 0xa807dc18
a00ad01c:  c2 04 00 00  ld  [ %l0 ], %g1
a00ad020:  da 0b 21 1f  ldub  [ %o4 + 0x11f ], %o5
a00ad024:  82 08 7f fd  and  %g1, -3, %g1
a00ad028:  c2 24 00 00  st  %g1, [ %l0 ]
a00ad02c:  80 a3 60 01  cmp  %o5, 1
a00ad030:  02 80 00 06  be  0xa00ad048
a00ad034:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00ad038:  c2 0b 22 4b  ldub  [ %o4 + 0x24b ], %g1
a00ad03c:  80 a0 60 01  cmp  %g1, 1
a00ad040:  12 80 00 03  bne  0xa00ad04c
a00ad044:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00ad048:  c0 28 63 16  clrb  [ %g1 + 0x316 ]	! 0xa8079316
a00ad04c:  81 c7 e0 08  ret
a00ad050:  81 e8 00 00  restore
