# leon2m FUN_a011bd60 0xa011bd60-0xa011bed8 (376 bytes)
a011bd60:  9d e3 bf 98  save  %sp, -104, %sp
a011bd64:  9e 0f 20 ff  and  %i4, 0xff, %o7
a011bd68:  3b 2a 00 b2  sethi  %hi(0xa802c800), %i5
a011bd6c:  82 17 61 ca  or  %i5, 0x1ca, %g1	! 0xa802c9ca
a011bd70:  b8 03 c0 0f  add  %o7, %o7, %i4
a011bd74:  fa 10 40 1c  lduh  [ %g1 + %i4 ], %i5
a011bd78:  b2 5e 40 1d  smul  %i1, %i5, %i1
a011bd7c:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a011bd80:  b0 06 00 19  add  %i0, %i1, %i0
a011bd84:  ba 10 20 70  mov  0x70, %i5
a011bd88:  80 a3 e0 00  cmp  %o7, 0
a011bd8c:  02 80 00 05  be  0xa011bda0
a011bd90:  82 10 63 80  or  %g1, 0x380, %g1
a011bd94:  33 33 c0 45  sethi  %hi(0xcf011400), %i1
a011bd98:  ba 10 20 70  mov  0x70, %i5
a011bd9c:  82 16 63 94  or  %i1, 0x394, %g1
a011bda0:  fa 20 40 00  st  %i5, [ %g1 ]
a011bda4:  82 10 20 9f  mov  0x9f, %g1
a011bda8:  01 00 00 00  nop
a011bdac:  82 80 7f ff  addcc  %g1, -1, %g1
a011bdb0:  1c bf ff fe  bpos  0xa011bda8
a011bdb4:  80 a3 e0 00  cmp  %o7, 0
a011bdb8:  b1 2e 20 10  sll  %i0, 0x10, %i0
a011bdbc:  12 80 00 34  bne  0xa011be8c
a011bdc0:  bb 36 20 10  srl  %i0, 0x10, %i5
a011bdc4:  33 33 c0 45  sethi  %hi(0xcf011400), %i1
a011bdc8:  b8 16 63 84  or  %i1, 0x384, %i4	! 0xcf011784
a011bdcc:  ba 0f 60 ff  and  %i5, 0xff, %i5
a011bdd0:  fa 27 00 00  st  %i5, [ %i4 ]
a011bdd4:  83 36 20 18  srl  %i0, 0x18, %g1
a011bdd8:  b8 16 63 88  or  %i1, 0x388, %i4
a011bddc:  c2 27 00 00  st  %g1, [ %i4 ]
a011bde0:  03 33 c0 2f  sethi  %hi(0xcf00bc00), %g1
a011bde4:  b0 10 63 cc  or  %g1, 0x3cc, %i0	! 0xcf00bfcc
a011bde8:  c0 26 00 00  clr  [ %i0 ]
a011bdec:  82 10 20 9f  mov  0x9f, %g1
a011bdf0:  01 00 00 00  nop
a011bdf4:  82 80 7f ff  addcc  %g1, -1, %g1
a011bdf8:  1c bf ff fe  bpos  0xa011bdf0
a011bdfc:  01 00 00 00  nop
a011be00:  b4 0e a0 ff  and  %i2, 0xff, %i2
a011be04:  80 a6 a0 00  cmp  %i2, 0
a011be08:  02 80 00 32  be  0xa011bed0
a011be0c:  b8 10 20 00  clr  %i4
a011be10:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a011be14:  b0 10 63 a0  or  %g1, 0x3a0, %i0	! 0xcf0117a0
a011be18:  b2 10 63 8c  or  %g1, 0x38c, %i1
a011be1c:  80 a3 e0 00  cmp  %o7, 0
a011be20:  12 80 00 24  bne  0xa011beb0
a011be24:  fa 16 c0 00  lduh  [ %i3 ], %i5
a011be28:  82 0f 60 ff  and  %i5, 0xff, %g1
a011be2c:  c2 26 40 00  st  %g1, [ %i1 ]
a011be30:  82 10 20 9f  mov  0x9f, %g1
a011be34:  01 00 00 00  nop
a011be38:  82 80 7f ff  addcc  %g1, -1, %g1
a011be3c:  1c bf ff fe  bpos  0xa011be34
a011be40:  80 a3 e0 00  cmp  %o7, 0
a011be44:  83 2f 60 10  sll  %i5, 0x10, %g1
a011be48:  12 80 00 1e  bne  0xa011bec0
a011be4c:  83 30 60 18  srl  %g1, 0x18, %g1
a011be50:  ba 08 60 ff  and  %g1, 0xff, %i5
a011be54:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a011be58:  82 10 63 8c  or  %g1, 0x38c, %g1	! 0xcf01178c
a011be5c:  fa 20 40 00  st  %i5, [ %g1 ]
a011be60:  82 10 20 9f  mov  0x9f, %g1
a011be64:  01 00 00 00  nop
a011be68:  82 80 7f ff  addcc  %g1, -1, %g1
a011be6c:  1c bf ff fe  bpos  0xa011be64
a011be70:  01 00 00 00  nop
a011be74:  b8 07 20 01  inc  %i4
a011be78:  ba 0f 20 ff  and  %i4, 0xff, %i5
a011be7c:  80 a7 40 1a  cmp  %i5, %i2
a011be80:  0a bf ff e7  bcs  0xa011be1c
a011be84:  b6 06 e0 02  add  %i3, 2, %i3
a011be88:  30 80 00 12  b,a   0xa011bed0
a011be8c:  39 33 c0 45  sethi  %hi(0xcf011400), %i4
a011be90:  82 17 23 98  or  %i4, 0x398, %g1	! 0xcf011798
a011be94:  ba 0f 60 ff  and  %i5, 0xff, %i5
a011be98:  fa 20 40 00  st  %i5, [ %g1 ]
a011be9c:  82 17 23 9c  or  %i4, 0x39c, %g1
a011bea0:  b3 36 20 18  srl  %i0, 0x18, %i1
a011bea4:  f2 20 40 00  st  %i1, [ %g1 ]
a011bea8:  10 bf ff cf  b  0xa011bde4
a011beac:  03 33 c0 30  sethi  %hi(0xcf00c000), %g1
a011beb0:  82 0f 60 ff  and  %i5, 0xff, %g1
a011beb4:  c2 26 00 00  st  %g1, [ %i0 ]
a011beb8:  10 bf ff df  b  0xa011be34
a011bebc:  82 10 20 9f  mov  0x9f, %g1
a011bec0:  ba 08 60 ff  and  %g1, 0xff, %i5
a011bec4:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a011bec8:  10 bf ff e5  b  0xa011be5c
a011becc:  82 10 63 a0  or  %g1, 0x3a0, %g1	! 0xcf0117a0
a011bed0:  81 c7 e0 08  ret
a011bed4:  81 e8 00 00  restore
