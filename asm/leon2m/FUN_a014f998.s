# leon2m FUN_a014f998 0xa014f998-0xa014fa84 (236 bytes)
a014f998:  9d e3 bf 98  save  %sp, -104, %sp
a014f99c:  33 2a 00 b3  sethi  %hi(0xa802cc00), %i1
a014f9a0:  c2 0e 60 87  ldub  [ %i1 + 0x87 ], %g1	! 0xa802cc87
a014f9a4:  80 88 60 01  btst  1, %g1
a014f9a8:  12 80 00 30  bne  0xa014fa68
a014f9ac:  93 2e 20 10  sll  %i0, 0x10, %o1
a014f9b0:  80 88 60 02  btst  2, %g1
a014f9b4:  32 80 00 28  bne,a   0xa014fa54
a014f9b8:  83 2e 20 10  sll  %i0, 0x10, %g1
a014f9bc:  80 88 60 04  btst  4, %g1
a014f9c0:  12 80 00 20  bne  0xa014fa40
a014f9c4:  91 2e 20 10  sll  %i0, 0x10, %o0
a014f9c8:  80 88 60 08  btst  8, %g1
a014f9cc:  12 80 00 18  bne  0xa014fa2c
a014f9d0:  95 2e 20 10  sll  %i0, 0x10, %o2
a014f9d4:  80 88 60 10  btst  0x10, %g1
a014f9d8:  12 80 00 10  bne  0xa014fa18
a014f9dc:  97 2e 20 10  sll  %i0, 0x10, %o3
a014f9e0:  80 88 60 20  btst  0x20, %g1
a014f9e4:  12 80 00 08  bne  0xa014fa04
a014f9e8:  99 2e 20 10  sll  %i0, 0x10, %o4
a014f9ec:  80 88 60 40  btst  0x40, %g1
a014f9f0:  02 80 00 23  be  0xa014fa7c
a014f9f4:  b3 2e 20 10  sll  %i0, 0x10, %i1
a014f9f8:  b3 36 60 10  srl  %i1, 0x10, %i1
a014f9fc:  7f ff 38 e8  call  0xa011dd9c
a014fa00:  91 e8 20 16  restore  %g0, 0x16, %o0
a014fa04:  93 33 20 10  srl  %o4, 0x10, %o1
a014fa08:  7f ff 38 e5  call  0xa011dd9c
a014fa0c:  90 10 20 15  mov  0x15, %o0
a014fa10:  10 bf ff f7  b  0xa014f9ec
a014fa14:  c2 0e 60 87  ldub  [ %i1 + 0x87 ], %g1
a014fa18:  93 32 e0 10  srl  %o3, 0x10, %o1
a014fa1c:  7f ff 38 e0  call  0xa011dd9c
a014fa20:  90 10 20 14  mov  0x14, %o0
a014fa24:  10 bf ff ef  b  0xa014f9e0
a014fa28:  c2 0e 60 87  ldub  [ %i1 + 0x87 ], %g1
a014fa2c:  93 32 a0 10  srl  %o2, 0x10, %o1
a014fa30:  7f ff 38 db  call  0xa011dd9c
a014fa34:  90 10 20 13  mov  0x13, %o0
a014fa38:  10 bf ff e7  b  0xa014f9d4
a014fa3c:  c2 0e 60 87  ldub  [ %i1 + 0x87 ], %g1
a014fa40:  93 32 20 10  srl  %o0, 0x10, %o1
a014fa44:  7f ff 38 d6  call  0xa011dd9c
a014fa48:  90 10 20 12  mov  0x12, %o0
a014fa4c:  10 bf ff df  b  0xa014f9c8
a014fa50:  c2 0e 60 87  ldub  [ %i1 + 0x87 ], %g1
a014fa54:  93 30 60 10  srl  %g1, 0x10, %o1
a014fa58:  7f ff 38 d1  call  0xa011dd9c
a014fa5c:  90 10 20 11  mov  0x11, %o0
a014fa60:  10 bf ff d7  b  0xa014f9bc
a014fa64:  c2 0e 60 87  ldub  [ %i1 + 0x87 ], %g1
a014fa68:  93 32 60 10  srl  %o1, 0x10, %o1
a014fa6c:  7f ff 38 cc  call  0xa011dd9c
a014fa70:  90 10 20 10  mov  0x10, %o0
a014fa74:  10 bf ff cf  b  0xa014f9b0
a014fa78:  c2 0e 60 87  ldub  [ %i1 + 0x87 ], %g1
a014fa7c:  81 c7 e0 08  ret
a014fa80:  81 e8 00 00  restore
