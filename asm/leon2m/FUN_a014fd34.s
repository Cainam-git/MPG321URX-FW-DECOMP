# leon2m FUN_a014fd34 0xa014fd34-0xa014fe78 (324 bytes)  [FUN_a014fe70 = its unreachable ret/restore tail, merged]
a014fd34:  9d e3 bf 98  save  %sp, -104, %sp
a014fd38:  33 2a 00 b3  sethi  %hi(0xa802cc00), %i1
a014fd3c:  c2 0e 60 86  ldub  [ %i1 + 0x86 ], %g1	! 0xa802cc86
a014fd40:  80 88 60 01  btst  1, %g1
a014fd44:  12 80 00 17  bne  0xa014fda0
a014fd48:  80 88 60 02  btst  2, %g1
a014fd4c:  12 80 00 1d  bne  0xa014fdc0
a014fd50:  90 10 20 11  mov  0x11, %o0
a014fd54:  80 88 60 04  btst  4, %g1
a014fd58:  12 80 00 21  bne  0xa014fddc
a014fd5c:  90 10 20 12  mov  0x12, %o0
a014fd60:  80 88 60 08  btst  8, %g1
a014fd64:  12 80 00 25  bne  0xa014fdf8
a014fd68:  90 10 20 13  mov  0x13, %o0
a014fd6c:  80 88 60 10  btst  0x10, %g1
a014fd70:  12 80 00 29  bne  0xa014fe14
a014fd74:  90 10 20 14  mov  0x14, %o0
a014fd78:  80 88 60 20  btst  0x20, %g1
a014fd7c:  12 80 00 2d  bne  0xa014fe30
a014fd80:  90 10 20 15  mov  0x15, %o0
a014fd84:  80 88 60 40  btst  0x40, %g1
a014fd88:  12 80 00 31  bne  0xa014fe4c
a014fd8c:  90 10 20 16  mov  0x16, %o0
a014fd90:  80 88 60 80  btst  0x80, %g1
a014fd94:  02 80 00 36  be  0xa014fe6c
a014fd98:  b2 0e 20 ff  and  %i0, 0xff, %i1
a014fd9c:  30 80 00 32  b,a   0xa014fe64
a014fda0:  90 10 20 10  mov  0x10, %o0
a014fda4:  7f ff 3a d6  call  0xa011e8fc
a014fda8:  92 0e 20 ff  and  %i0, 0xff, %o1
a014fdac:  c2 0e 60 86  ldub  [ %i1 + 0x86 ], %g1
a014fdb0:  80 88 60 02  btst  2, %g1
a014fdb4:  02 bf ff e9  be  0xa014fd58
a014fdb8:  80 88 60 04  btst  4, %g1
a014fdbc:  90 10 20 11  mov  0x11, %o0
a014fdc0:  7f ff 3a cf  call  0xa011e8fc
a014fdc4:  92 0e 20 ff  and  %i0, 0xff, %o1
a014fdc8:  c2 0e 60 86  ldub  [ %i1 + 0x86 ], %g1
a014fdcc:  80 88 60 04  btst  4, %g1
a014fdd0:  02 bf ff e5  be  0xa014fd64
a014fdd4:  80 88 60 08  btst  8, %g1
a014fdd8:  90 10 20 12  mov  0x12, %o0
a014fddc:  7f ff 3a c8  call  0xa011e8fc
a014fde0:  92 0e 20 ff  and  %i0, 0xff, %o1
a014fde4:  c2 0e 60 86  ldub  [ %i1 + 0x86 ], %g1
a014fde8:  80 88 60 08  btst  8, %g1
a014fdec:  02 bf ff e1  be  0xa014fd70
a014fdf0:  80 88 60 10  btst  0x10, %g1
a014fdf4:  90 10 20 13  mov  0x13, %o0
a014fdf8:  7f ff 3a c1  call  0xa011e8fc
a014fdfc:  92 0e 20 ff  and  %i0, 0xff, %o1
a014fe00:  c2 0e 60 86  ldub  [ %i1 + 0x86 ], %g1
a014fe04:  80 88 60 10  btst  0x10, %g1
a014fe08:  02 bf ff dd  be  0xa014fd7c
a014fe0c:  80 88 60 20  btst  0x20, %g1
a014fe10:  90 10 20 14  mov  0x14, %o0
a014fe14:  7f ff 3a ba  call  0xa011e8fc
a014fe18:  92 0e 20 ff  and  %i0, 0xff, %o1
a014fe1c:  c2 0e 60 86  ldub  [ %i1 + 0x86 ], %g1
a014fe20:  80 88 60 20  btst  0x20, %g1
a014fe24:  02 bf ff d9  be  0xa014fd88
a014fe28:  80 88 60 40  btst  0x40, %g1
a014fe2c:  90 10 20 15  mov  0x15, %o0
a014fe30:  7f ff 3a b3  call  0xa011e8fc
a014fe34:  92 0e 20 ff  and  %i0, 0xff, %o1
a014fe38:  c2 0e 60 86  ldub  [ %i1 + 0x86 ], %g1
a014fe3c:  80 88 60 40  btst  0x40, %g1
a014fe40:  02 bf ff d5  be  0xa014fd94
a014fe44:  80 88 60 80  btst  0x80, %g1
a014fe48:  90 10 20 16  mov  0x16, %o0
a014fe4c:  7f ff 3a ac  call  0xa011e8fc
a014fe50:  92 0e 20 ff  and  %i0, 0xff, %o1
a014fe54:  c2 0e 60 86  ldub  [ %i1 + 0x86 ], %g1
a014fe58:  80 88 60 80  btst  0x80, %g1
a014fe5c:  02 80 00 04  be  0xa014fe6c
a014fe60:  b2 0e 20 ff  and  %i0, 0xff, %i1
a014fe64:  7f ff 3a a6  call  0xa011e8fc
a014fe68:  91 e8 20 17  restore  %g0, 0x17, %o0
a014fe6c:  01 00 00 00  nop
a014fe70:  81 c7 e0 08  ret
a014fe74:  81 e8 00 00  restore
