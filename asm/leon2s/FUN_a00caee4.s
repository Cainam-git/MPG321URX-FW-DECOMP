# leon2s FUN_a00caee4 0xa00caee4-0xa00caf78 (148 bytes)
a00caee4:  9d e3 bf 98  save  %sp, -104, %sp
a00caee8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00caeec:  98 06 00 18  add  %i0, %i0, %o4
a00caef0:  98 03 00 18  add  %o4, %i0, %o4
a00caef4:  17 2a 01 e2  sethi  %hi(0xa8078800), %o3
a00caef8:  96 12 e3 b0  or  %o3, 0x3b0, %o3	! 0xa8078bb0
a00caefc:  99 2b 20 03  sll  %o4, 3, %o4
a00caf00:  da 02 c0 0c  ld  [ %o3 + %o4 ], %o5
a00caf04:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00caf08:  82 2b 40 01  andn  %o5, %g1, %g1
a00caf0c:  1b 00 00 40  sethi  %hi(0x10000), %o5
a00caf10:  82 10 40 0d  or  %g1, %o5, %g1
a00caf14:  c2 22 c0 0c  st  %g1, [ %o3 + %o4 ]
a00caf18:  82 10 20 05  mov  5, %g1
a00caf1c:  37 2a 01 f3  sethi  %hi(0xa807cc00), %i3
a00caf20:  c2 2e e2 50  stb  %g1, [ %i3 + 0x250 ]	! 0xa807ce50
a00caf24:  90 10 00 18  mov  %i0, %o0
a00caf28:  92 10 20 05  mov  5, %o1
a00caf2c:  7f ff f6 2f  call  0xa00c87e8
a00caf30:  15 00 00 20  sethi  %hi(0x8000), %o2
a00caf34:  b8 10 20 00  clr  %i4
a00caf38:  a0 0f 20 ff  and  %i4, 0xff, %l0
a00caf3c:  90 10 00 18  mov  %i0, %o0
a00caf40:  7f ff f2 0c  call  0xa00c7770
a00caf44:  92 10 20 01  mov  1, %o1
a00caf48:  b2 16 e2 50  or  %i3, 0x250, %i1
a00caf4c:  b8 07 20 01  inc  %i4
a00caf50:  a0 04 00 19  add  %l0, %i1, %l0
a00caf54:  82 0f 20 ff  and  %i4, 0xff, %g1
a00caf58:  80 a0 60 1f  cmp  %g1, 0x1f
a00caf5c:  08 bf ff f7  bleu  0xa00caf38
a00caf60:  d0 2c 20 01  stb  %o0, [ %l0 + 1 ]
a00caf64:  b4 10 20 74  mov  0x74, %i2
a00caf68:  b6 10 20 60  mov  0x60, %i3
a00caf6c:  7f ff f4 61  call  0xa00c80f0
a00caf70:  99 e8 20 21  restore  %g0, 0x21, %o4
a00caf74:  01 00 00 00  nop
