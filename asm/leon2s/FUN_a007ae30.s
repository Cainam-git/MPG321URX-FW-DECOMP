# leon2s FUN_a007ae30 0xa007ae30-0xa007ae94 (100 bytes)  [FUN_a007ae8c = unreachable ret/restore tail, merged]
a007ae30:  9d e3 bf 98  save  %sp, -104, %sp
a007ae34:  b2 0e 60 ff  and  %i1, 0xff, %i1
a007ae38:  b2 1e 60 01  xor  %i1, 1, %i1
a007ae3c:  80 a0 00 19  cmp  %g0, %i1
a007ae40:  a0 60 3f ff  subx  %g0, -1, %l0
a007ae44:  b4 0e 20 ff  and  %i0, 0xff, %i2
a007ae48:  17 00 00 07  sethi  %hi(0x1c00), %o3
a007ae4c:  96 12 e0 04  or  %o3, 4, %o3	! 0x1c04
a007ae50:  92 10 20 07  mov  7, %o1
a007ae54:  94 10 00 1a  mov  %i2, %o2
a007ae58:  40 00 b1 73  call  0xa00a7424
a007ae5c:  90 10 00 10  mov  %l0, %o0
a007ae60:  7f ff e1 b0  call  0xa0073520
a007ae64:  90 10 00 1a  mov  %i2, %o0
a007ae68:  37 00 00 0b  sethi  %hi(0x2c00), %i3
a007ae6c:  b0 10 00 10  mov  %l0, %i0
a007ae70:  b6 16 e0 04  or  %i3, 4, %i3
a007ae74:  80 8a 20 ff  btst  0xff, %o0
a007ae78:  02 80 00 04  be  0xa007ae88
a007ae7c:  b2 10 20 07  mov  7, %i1
a007ae80:  40 00 b1 69  call  0xa00a7424
a007ae84:  81 e8 00 00  restore
a007ae88:  01 00 00 00  nop
a007ae8c:  81 c7 e0 08  ret
a007ae90:  81 e8 00 00  restore
