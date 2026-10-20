# leon2s FUN_a0092890 0xa0092890-0xa0092944 (180 bytes)
a0092890:  9d e3 bf 98  save  %sp, -104, %sp
a0092894:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0092898:  9b 2e 20 03  sll  %i0, 3, %o5
a009289c:  9a 23 40 18  sub  %o5, %i0, %o5
a00928a0:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a00928a4:  80 8e 60 ff  btst  0xff, %i1
a00928a8:  9b 2b 60 02  sll  %o5, 2, %o5
a00928ac:  82 10 61 80  or  %g1, 0x180, %g1
a00928b0:  92 10 20 03  mov  3, %o1
a00928b4:  94 10 20 01  mov  1, %o2
a00928b8:  96 10 20 01  mov  1, %o3
a00928bc:  98 10 20 01  mov  1, %o4
a00928c0:  b4 10 20 00  clr  %i2
a00928c4:  b2 10 20 01  mov  1, %i1
a00928c8:  a0 03 40 01  add  %o5, %g1, %l0
a00928cc:  02 80 00 17  be  0xa0092928
a00928d0:  90 10 00 18  mov  %i0, %o0
a00928d4:  40 00 55 e0  call  0xa00a8054
a00928d8:  d6 0c 20 19  ldub  [ %l0 + 0x19 ], %o3
a00928dc:  d6 14 20 18  lduh  [ %l0 + 0x18 ], %o3
a00928e0:  90 10 00 18  mov  %i0, %o0
a00928e4:  97 32 e0 08  srl  %o3, 8, %o3
a00928e8:  92 10 20 03  mov  3, %o1
a00928ec:  40 00 55 da  call  0xa00a8054
a00928f0:  94 10 20 02  mov  2, %o2
a00928f4:  90 10 00 18  mov  %i0, %o0
a00928f8:  92 10 20 03  mov  3, %o1
a00928fc:  94 10 20 bd  mov  0xbd, %o2
a0092900:  96 10 20 01  mov  1, %o3
a0092904:  40 00 55 f2  call  0xa00a80cc
a0092908:  98 10 20 01  mov  1, %o4
a009290c:  90 10 00 18  mov  %i0, %o0
a0092910:  92 10 20 03  mov  3, %o1
a0092914:  94 10 20 be  mov  0xbe, %o2
a0092918:  96 10 20 01  mov  1, %o3
a009291c:  40 00 55 ec  call  0xa00a80cc
a0092920:  98 10 20 00  clr  %o4
a0092924:  30 80 00 05  b,a   0xa0092938
a0092928:  40 00 55 e9  call  0xa00a80cc
a009292c:  94 10 20 be  mov  0xbe, %o2
a0092930:  b2 10 20 00  clr  %i1
a0092934:  b4 10 20 00  clr  %i2
a0092938:  7f ff ff 9a  call  0xa00927a0
a009293c:  81 e8 00 00  restore
a0092940:  01 00 00 00  nop
