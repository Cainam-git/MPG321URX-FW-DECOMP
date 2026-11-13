# leon2m FUN_a0095b58 0xa0095b58-0xa0095bcc (116 bytes)
a0095b58:  9d e3 bf 98  save  %sp, -104, %sp
a0095b5c:  21 2a 00 97  sethi  %hi(0xa8025c00), %l0
a0095b60:  40 00 4e 17  call  0xa00a93bc
a0095b64:  d0 0c 20 56  ldub  [ %l0 + 0x56 ], %o0	! 0xa8025c56
a0095b68:  d2 0c 20 56  ldub  [ %l0 + 0x56 ], %o1
a0095b6c:  94 10 20 00  clr  %o2
a0095b70:  40 00 49 73  call  0xa00a813c
a0095b74:  90 10 20 01  mov  1, %o0
a0095b78:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a0095b7c:  d4 04 23 ec  ld  [ %l0 + 0x3ec ], %o2	! 0xa802afec
a0095b80:  92 02 bf b2  add  %o2, -78, %o1
a0095b84:  90 0a 60 ff  and  %o1, 0xff, %o0
a0095b88:  40 00 4e b2  call  0xa00a9650
a0095b8c:  92 10 20 00  clr  %o1
a0095b90:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a0095b94:  d2 0a 23 eb  ldub  [ %o0 + 0x3eb ], %o1	! 0xa802d3eb
a0095b98:  94 10 20 01  mov  1, %o2
a0095b9c:  40 00 49 68  call  0xa00a813c
a0095ba0:  90 10 20 01  mov  1, %o0
a0095ba4:  82 10 20 0f  mov  0xf, %g1
a0095ba8:  c2 24 23 ec  st  %g1, [ %l0 + 0x3ec ]
a0095bac:  90 10 20 01  mov  1, %o0
a0095bb0:  40 00 4d 17  call  0xa00a900c
a0095bb4:  92 10 20 01  mov  1, %o1
a0095bb8:  40 00 5c cf  call  0xa00acef4
a0095bbc:  01 00 00 00  nop
a0095bc0:  40 00 fb 76  call  0xa00d4998
a0095bc4:  81 e8 00 00  restore
a0095bc8:  01 00 00 00  nop
