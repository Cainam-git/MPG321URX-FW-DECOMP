# leon2m FUN_a002f984 0xa002f984-0xa002fa34 (176 bytes)
a002f984:  9d e3 bf 98  save  %sp, -104, %sp
a002f988:  b0 0e 20 ff  and  %i0, 0xff, %i0
a002f98c:  80 a6 20 01  cmp  %i0, 1
a002f990:  02 80 00 0e  be  0xa002f9c8
a002f994:  13 2a 00 b3  sethi  %hi(0xa802cc00), %o1
a002f998:  58 01 37 1f  call  0x7d614
a002f99c:  90 10 20 10  mov  0x10, %o0
a002f9a0:  80 8a 20 ff  btst  0xff, %o0
a002f9a4:  12 80 00 10  bne  0xa002f9e4
a002f9a8:  80 a6 20 01  cmp  %i0, 1
a002f9ac:  04 80 00 16  ble  0xa002fa04
a002f9b0:  80 a6 20 00  cmp  %i0, 0
a002f9b4:  80 a6 20 05  cmp  %i0, 5
a002f9b8:  12 80 00 1d  bne  0xa002fa2c
a002f9bc:  15 2a 00 b3  sethi  %hi(0xa802cc00), %o2
a002f9c0:  10 80 00 18  b  0xa002fa20
a002f9c4:  c2 02 a0 30  ld  [ %o2 + 0x30 ], %g1	! 0xa802cc30
a002f9c8:  c2 02 60 20  ld  [ %o1 + 0x20 ], %g1
a002f9cc:  80 a0 60 00  cmp  %g1, 0
a002f9d0:  02 80 00 17  be  0xa002fa2c
a002f9d4:  01 00 00 00  nop
a002f9d8:  9f c0 40 00  call  %g1
a002f9dc:  01 00 00 00  nop
a002f9e0:  30 80 00 13  b,a   0xa002fa2c
a002f9e4:  11 00 06 9d  sethi  %hi(0x1a7400), %o0
a002f9e8:  90 12 20 b0  or  %o0, 0xb0, %o0	! 0x1a74b0
a002f9ec:  58 01 3d e1  call  0x7f170
a002f9f0:  92 10 00 18  mov  %i0, %o1
a002f9f4:  80 a6 20 01  cmp  %i0, 1
a002f9f8:  14 bf ff f0  bg  0xa002f9b8
a002f9fc:  80 a6 20 05  cmp  %i0, 5
a002fa00:  80 a6 20 00  cmp  %i0, 0
a002fa04:  12 80 00 0a  bne  0xa002fa2c
a002fa08:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a002fa0c:  c2 00 60 1c  ld  [ %g1 + 0x1c ], %g1	! 0xa802cc1c
a002fa10:  80 a0 60 00  cmp  %g1, 0
a002fa14:  02 80 00 06  be  0xa002fa2c
a002fa18:  01 00 00 00  nop
a002fa1c:  30 bf ff ef  b,a   0xa002f9d8
a002fa20:  80 a0 60 00  cmp  %g1, 0
a002fa24:  12 bf ff ed  bne  0xa002f9d8
a002fa28:  01 00 00 00  nop
a002fa2c:  81 c7 e0 08  ret
a002fa30:  81 e8 00 00  restore
