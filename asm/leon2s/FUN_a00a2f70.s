# leon2s FUN_a00a2f70 0xa00a2f70-0xa00a2fd0 (96 bytes)
a00a2f70:  98 0a 20 ff  and  %o0, 0xff, %o4
a00a2f74:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a00a2f78:  80 8a a0 ff  btst  0xff, %o2
a00a2f7c:  96 5b 20 34  smul  %o4, 0x34, %o3
a00a2f80:  9a 10 63 00  or  %g1, 0x300, %o5
a00a2f84:  90 10 20 07  mov  7, %o0
a00a2f88:  94 0a 60 ff  and  %o1, 0xff, %o2
a00a2f8c:  02 80 00 0b  be  0xa00a2fb8
a00a2f90:  96 02 c0 0d  add  %o3, %o5, %o3
a00a2f94:  d2 02 e0 30  ld  [ %o3 + 0x30 ], %o1
a00a2f98:  c2 02 60 08  ld  [ %o1 + 8 ], %g1
a00a2f9c:  82 08 7f c0  and  %g1, -64, %g1
a00a2fa0:  82 10 40 0a  or  %g1, %o2, %g1
a00a2fa4:  c2 22 60 08  st  %g1, [ %o1 + 8 ]
a00a2fa8:  92 02 60 08  add  %o1, 8, %o1
a00a2fac:  82 13 c0 00  mov  %o7, %g1
a00a2fb0:  40 00 10 ff  call  0xa00a73ac
a00a2fb4:  9e 10 40 00  mov  %g1, %o7
a00a2fb8:  d2 02 e0 30  ld  [ %o3 + 0x30 ], %o1
a00a2fbc:  92 02 60 08  add  %o1, 8, %o1
a00a2fc0:  90 10 20 07  mov  7, %o0
a00a2fc4:  82 13 c0 00  mov  %o7, %g1
a00a2fc8:  40 00 11 03  call  0xa00a73d4
a00a2fcc:  9e 10 40 00  mov  %g1, %o7
