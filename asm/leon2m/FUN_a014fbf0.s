# leon2m FUN_a014fbf0 0xa014fbf0-0xa014fd34 (324 bytes)  [FUN_a014fd2c = unreachable ret/restore tail, merged]
a014fbf0:  9d e3 bf 98  save  %sp, -104, %sp
a014fbf4:  33 2a 00 b3  sethi  %hi(0xa802cc00), %i1
a014fbf8:  c2 0e 60 86  ldub  [ %i1 + 0x86 ], %g1	! 0xa802cc86
a014fbfc:  80 88 60 01  btst  1, %g1
a014fc00:  12 80 00 17  bne  0xa014fc5c
a014fc04:  80 88 60 02  btst  2, %g1
a014fc08:  12 80 00 1d  bne  0xa014fc7c
a014fc0c:  90 10 20 11  mov  0x11, %o0
a014fc10:  80 88 60 04  btst  4, %g1
a014fc14:  12 80 00 21  bne  0xa014fc98
a014fc18:  90 10 20 12  mov  0x12, %o0
a014fc1c:  80 88 60 08  btst  8, %g1
a014fc20:  12 80 00 25  bne  0xa014fcb4
a014fc24:  90 10 20 13  mov  0x13, %o0
a014fc28:  80 88 60 10  btst  0x10, %g1
a014fc2c:  12 80 00 29  bne  0xa014fcd0
a014fc30:  90 10 20 14  mov  0x14, %o0
a014fc34:  80 88 60 20  btst  0x20, %g1
a014fc38:  12 80 00 2d  bne  0xa014fcec
a014fc3c:  90 10 20 15  mov  0x15, %o0
a014fc40:  80 88 60 40  btst  0x40, %g1
a014fc44:  12 80 00 31  bne  0xa014fd08
a014fc48:  90 10 20 16  mov  0x16, %o0
a014fc4c:  80 88 60 80  btst  0x80, %g1
a014fc50:  02 80 00 36  be  0xa014fd28
a014fc54:  b2 0e 20 ff  and  %i0, 0xff, %i1
a014fc58:  30 80 00 32  b,a   0xa014fd20
a014fc5c:  90 10 20 10  mov  0x10, %o0
a014fc60:  7f ff 3a cd  call  0xa011e794
a014fc64:  92 0e 20 ff  and  %i0, 0xff, %o1
a014fc68:  c2 0e 60 86  ldub  [ %i1 + 0x86 ], %g1
a014fc6c:  80 88 60 02  btst  2, %g1
a014fc70:  02 bf ff e9  be  0xa014fc14
a014fc74:  80 88 60 04  btst  4, %g1
a014fc78:  90 10 20 11  mov  0x11, %o0
a014fc7c:  7f ff 3a c6  call  0xa011e794
a014fc80:  92 0e 20 ff  and  %i0, 0xff, %o1
a014fc84:  c2 0e 60 86  ldub  [ %i1 + 0x86 ], %g1
a014fc88:  80 88 60 04  btst  4, %g1
a014fc8c:  02 bf ff e5  be  0xa014fc20
a014fc90:  80 88 60 08  btst  8, %g1
a014fc94:  90 10 20 12  mov  0x12, %o0
a014fc98:  7f ff 3a bf  call  0xa011e794
a014fc9c:  92 0e 20 ff  and  %i0, 0xff, %o1
a014fca0:  c2 0e 60 86  ldub  [ %i1 + 0x86 ], %g1
a014fca4:  80 88 60 08  btst  8, %g1
a014fca8:  02 bf ff e1  be  0xa014fc2c
a014fcac:  80 88 60 10  btst  0x10, %g1
a014fcb0:  90 10 20 13  mov  0x13, %o0
a014fcb4:  7f ff 3a b8  call  0xa011e794
a014fcb8:  92 0e 20 ff  and  %i0, 0xff, %o1
a014fcbc:  c2 0e 60 86  ldub  [ %i1 + 0x86 ], %g1
a014fcc0:  80 88 60 10  btst  0x10, %g1
a014fcc4:  02 bf ff dd  be  0xa014fc38
a014fcc8:  80 88 60 20  btst  0x20, %g1
a014fccc:  90 10 20 14  mov  0x14, %o0
a014fcd0:  7f ff 3a b1  call  0xa011e794
a014fcd4:  92 0e 20 ff  and  %i0, 0xff, %o1
a014fcd8:  c2 0e 60 86  ldub  [ %i1 + 0x86 ], %g1
a014fcdc:  80 88 60 20  btst  0x20, %g1
a014fce0:  02 bf ff d9  be  0xa014fc44
a014fce4:  80 88 60 40  btst  0x40, %g1
a014fce8:  90 10 20 15  mov  0x15, %o0
a014fcec:  7f ff 3a aa  call  0xa011e794
a014fcf0:  92 0e 20 ff  and  %i0, 0xff, %o1
a014fcf4:  c2 0e 60 86  ldub  [ %i1 + 0x86 ], %g1
a014fcf8:  80 88 60 40  btst  0x40, %g1
a014fcfc:  02 bf ff d5  be  0xa014fc50
a014fd00:  80 88 60 80  btst  0x80, %g1
a014fd04:  90 10 20 16  mov  0x16, %o0
a014fd08:  7f ff 3a a3  call  0xa011e794
a014fd0c:  92 0e 20 ff  and  %i0, 0xff, %o1
a014fd10:  c2 0e 60 86  ldub  [ %i1 + 0x86 ], %g1
a014fd14:  80 88 60 80  btst  0x80, %g1
a014fd18:  02 80 00 04  be  0xa014fd28
a014fd1c:  b2 0e 20 ff  and  %i0, 0xff, %i1
a014fd20:  7f ff 3a 9d  call  0xa011e794
a014fd24:  91 e8 20 17  restore  %g0, 0x17, %o0
a014fd28:  01 00 00 00  nop
a014fd2c:  81 c7 e0 08  ret
a014fd30:  81 e8 00 00  restore
