# leon2s FUN_a00ccd20 0xa00ccd20-0xa00ccdb4 (148 bytes)
a00ccd20:  9d e3 bf 98  save  %sp, -104, %sp
a00ccd24:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00ccd28:  7f ff ff 6b  call  0xa00ccad4
a00ccd2c:  90 10 00 18  mov  %i0, %o0
a00ccd30:  82 06 00 18  add  %i0, %i0, %g1
a00ccd34:  82 00 40 18  add  %g1, %i0, %g1
a00ccd38:  a1 28 60 03  sll  %g1, 3, %l0
a00ccd3c:  1b 2a 01 e2  sethi  %hi(0xa8078800), %o5
a00ccd40:  03 3f ff 3f  sethi  %hi(0xfffcfc00), %g1
a00ccd44:  a4 13 63 b0  or  %o5, 0x3b0, %l2
a00ccd48:  a6 10 63 ff  or  %g1, 0x3ff, %l3
a00ccd4c:  c2 04 80 10  ld  [ %l2 + %l0 ], %g1
a00ccd50:  1b 00 00 40  sethi  %hi(0x10000), %o5
a00ccd54:  82 08 40 13  and  %g1, %l3, %g1
a00ccd58:  82 10 40 0d  or  %g1, %o5, %g1
a00ccd5c:  c2 24 80 10  st  %g1, [ %l2 + %l0 ]
a00ccd60:  7f ff f2 43  call  0xa00c966c
a00ccd64:  90 10 00 18  mov  %i0, %o0
a00ccd68:  a2 0a 20 ff  and  %o0, 0xff, %l1
a00ccd6c:  92 10 20 00  clr  %o1
a00ccd70:  80 a4 60 00  cmp  %l1, 0
a00ccd74:  12 80 00 05  bne  0xa00ccd88
a00ccd78:  90 10 00 18  mov  %i0, %o0
a00ccd7c:  c2 04 80 10  ld  [ %l2 + %l0 ], %g1
a00ccd80:  10 80 00 09  b  0xa00ccda4
a00ccd84:  1b 00 00 c0  sethi  %hi(0x30000), %o5
a00ccd88:  7f ff ef 25  call  0xa00c8a1c
a00ccd8c:  01 00 00 00  nop
a00ccd90:  80 a4 60 22  cmp  %l1, 0x22
a00ccd94:  12 80 00 06  bne  0xa00ccdac
a00ccd98:  1b 00 00 80  sethi  %hi(0x20000), %o5
a00ccd9c:  c2 04 80 10  ld  [ %l2 + %l0 ], %g1
a00ccda0:  82 08 40 13  and  %g1, %l3, %g1
a00ccda4:  82 10 40 0d  or  %g1, %o5, %g1
a00ccda8:  c2 24 80 10  st  %g1, [ %l2 + %l0 ]
a00ccdac:  81 c7 e0 08  ret
a00ccdb0:  81 e8 00 00  restore
