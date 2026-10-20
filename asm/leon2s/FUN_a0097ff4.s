# leon2s FUN_a0097ff4 0xa0097ff4-0xa0098048 (84 bytes)
a0097ff4:  9d e3 bf 98  save  %sp, -104, %sp
a0097ff8:  a0 0e 20 ff  and  %i0, 0xff, %l0
a0097ffc:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a0098000:  82 10 63 00  or  %g1, 0x300, %g1	! 0xa807db00
a0098004:  a0 5c 20 34  smul  %l0, 0x34, %l0
a0098008:  a0 04 00 01  add  %l0, %g1, %l0
a009800c:  d2 04 20 04  ld  [ %l0 + 4 ], %o1
a0098010:  92 02 60 34  add  %o1, 0x34, %o1
a0098014:  40 00 3c e6  call  0xa00a73ac
a0098018:  90 10 20 1b  mov  0x1b, %o0
a009801c:  b2 0e 60 ff  and  %i1, 0xff, %i1
a0098020:  80 a6 60 01  cmp  %i1, 1
a0098024:  c2 04 20 04  ld  [ %l0 + 4 ], %g1
a0098028:  b0 10 20 18  mov  0x18, %i0
a009802c:  12 80 00 04  bne  0xa009803c
a0098030:  b2 00 60 34  add  %g1, 0x34, %i1
a0098034:  40 00 3c de  call  0xa00a73ac
a0098038:  81 e8 00 00  restore
a009803c:  40 00 3c e6  call  0xa00a73d4
a0098040:  91 e8 20 18  restore  %g0, 0x18, %o0
a0098044:  01 00 00 00  nop
