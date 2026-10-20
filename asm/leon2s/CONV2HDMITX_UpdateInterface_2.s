# leon2s CONV2HDMITX_UpdateInterface_2 0xa00ad38c-0xa00ad3e0 (84 bytes)  [FUN_a00ad3d8 = unreachable ret/restore tail, merged]
a00ad38c:  9d e3 bf 98  save  %sp, -104, %sp
a00ad390:  b4 0e 20 ff  and  %i0, 0xff, %i2
a00ad394:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00ad398:  82 10 60 18  or  %g1, 0x18, %g1	! 0xa807dc18
a00ad39c:  9a 5e a1 2c  smul  %i2, 0x12c, %o5
a00ad3a0:  9a 03 40 01  add  %o5, %g1, %o5
a00ad3a4:  94 16 7f 80  or  %i1, -128, %o2
a00ad3a8:  c2 0b 61 1e  ldub  [ %o5 + 0x11e ], %g1
a00ad3ac:  90 10 00 1a  mov  %i2, %o0
a00ad3b0:  92 10 22 1d  mov  0x21d, %o1
a00ad3b4:  94 0a a0 ff  and  %o2, 0xff, %o2
a00ad3b8:  80 a0 60 00  cmp  %g1, 0
a00ad3bc:  02 80 00 06  be  0xa00ad3d4
a00ad3c0:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00ad3c4:  7f ff e6 0f  call  0xa00a6c00
a00ad3c8:  31 28 01 b1  sethi  %hi(0xa006c400), %i0
a00ad3cc:  7f ff 17 1e  call  0xa0073044
a00ad3d0:  91 ee 20 e8  restore  %i0, 0xe8, %o0
a00ad3d4:  01 00 00 00  nop
a00ad3d8:  81 c7 e0 08  ret
a00ad3dc:  81 e8 00 00  restore
