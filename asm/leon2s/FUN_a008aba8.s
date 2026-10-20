# leon2s FUN_a008aba8 0xa008aba8-0xa008ae18 (624 bytes)
a008aba8:  90 0a 20 ff  and  %o0, 0xff, %o0
a008abac:  82 02 3f ff  add  %o0, -1, %g1
a008abb0:  80 a0 60 12  cmp  %g1, 0x12
a008abb4:  18 80 00 97  bgu  0xa008ae10
a008abb8:  1b 28 02 2a  sethi  %hi(0xa008a800), %o5
a008abbc:  83 28 60 02  sll  %g1, 2, %g1
a008abc0:  9a 13 63 5c  or  %o5, 0x35c, %o5
a008abc4:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a008abc8:  81 c0 40 00  jmp  %g1
a008abcc:  01 00 00 00  nop
a008abd0:  19 33 c0 51  sethi  %hi(0xcf014400), %o4
a008abd4:  98 13 23 70  or  %o4, 0x370, %o4	! 0xcf014770
a008abd8:  82 10 20 01  mov  1, %g1
a008abdc:  da 03 00 00  ld  [ %o4 ], %o5
a008abe0:  83 28 40 09  sll  %g1, %o1, %g1
a008abe4:  82 2b 40 01  andn  %o5, %g1, %g1
a008abe8:  c2 23 00 00  st  %g1, [ %o4 ]
a008abec:  19 33 c0 44  sethi  %hi(0xcf011000), %o4
a008abf0:  10 80 00 15  b  0xa008ac44
a008abf4:  98 13 21 cc  or  %o4, 0x1cc, %o4	! 0xcf0111cc
a008abf8:  19 33 c0 51  sethi  %hi(0xcf014400), %o4
a008abfc:  98 13 23 70  or  %o4, 0x370, %o4	! 0xcf014770
a008ac00:  82 10 20 01  mov  1, %g1
a008ac04:  da 03 00 00  ld  [ %o4 ], %o5
a008ac08:  83 28 40 09  sll  %g1, %o1, %g1
a008ac0c:  82 2b 40 01  andn  %o5, %g1, %g1
a008ac10:  c2 23 00 00  st  %g1, [ %o4 ]
a008ac14:  19 33 c0 44  sethi  %hi(0xcf011000), %o4
a008ac18:  10 80 00 1a  b  0xa008ac80
a008ac1c:  98 13 21 cc  or  %o4, 0x1cc, %o4	! 0xcf0111cc
a008ac20:  19 33 c0 51  sethi  %hi(0xcf014400), %o4
a008ac24:  98 13 23 70  or  %o4, 0x370, %o4	! 0xcf014770
a008ac28:  82 10 20 01  mov  1, %g1
a008ac2c:  da 03 00 00  ld  [ %o4 ], %o5
a008ac30:  83 28 40 09  sll  %g1, %o1, %g1
a008ac34:  82 2b 40 01  andn  %o5, %g1, %g1
a008ac38:  c2 23 00 00  st  %g1, [ %o4 ]
a008ac3c:  19 33 c0 44  sethi  %hi(0xcf011000), %o4
a008ac40:  98 13 21 d0  or  %o4, 0x1d0, %o4	! 0xcf0111d0
a008ac44:  c2 03 00 00  ld  [ %o4 ], %g1
a008ac48:  82 08 60 3f  and  %g1, 0x3f, %g1
a008ac4c:  9b 2a 60 06  sll  %o1, 6, %o5
a008ac50:  82 10 40 0d  or  %g1, %o5, %g1
a008ac54:  10 80 00 10  b  0xa008ac94
a008ac58:  82 10 60 20  or  %g1, 0x20, %g1
a008ac5c:  19 33 c0 51  sethi  %hi(0xcf014400), %o4
a008ac60:  98 13 23 70  or  %o4, 0x370, %o4	! 0xcf014770
a008ac64:  82 10 20 01  mov  1, %g1
a008ac68:  da 03 00 00  ld  [ %o4 ], %o5
a008ac6c:  83 28 40 09  sll  %g1, %o1, %g1
a008ac70:  82 2b 40 01  andn  %o5, %g1, %g1
a008ac74:  c2 23 00 00  st  %g1, [ %o4 ]
a008ac78:  19 33 c0 44  sethi  %hi(0xcf011000), %o4
a008ac7c:  98 13 21 d0  or  %o4, 0x1d0, %o4	! 0xcf0111d0
a008ac80:  c2 03 00 00  ld  [ %o4 ], %g1
a008ac84:  82 08 7f f3  and  %g1, -13, %g1
a008ac88:  9b 2a 60 02  sll  %o1, 2, %o5
a008ac8c:  82 10 40 0d  or  %g1, %o5, %g1
a008ac90:  82 10 60 02  or  %g1, 2, %g1
a008ac94:  82 08 60 ff  and  %g1, 0xff, %g1
a008ac98:  c2 23 00 00  st  %g1, [ %o4 ]
a008ac9c:  30 80 00 5d  b,a   0xa008ae10
a008aca0:  19 33 c0 51  sethi  %hi(0xcf014400), %o4
a008aca4:  98 13 23 70  or  %o4, 0x370, %o4	! 0xcf014770
a008aca8:  82 10 20 01  mov  1, %g1
a008acac:  da 03 00 00  ld  [ %o4 ], %o5
a008acb0:  83 28 40 09  sll  %g1, %o1, %g1
a008acb4:  82 2b 40 01  andn  %o5, %g1, %g1
a008acb8:  1b 33 c0 44  sethi  %hi(0xcf011000), %o5
a008acbc:  c2 23 00 00  st  %g1, [ %o4 ]
a008acc0:  9a 13 61 c4  or  %o5, 0x1c4, %o5
a008acc4:  c2 03 40 00  ld  [ %o5 ], %g1
a008acc8:  82 08 60 3f  and  %g1, 0x3f, %g1
a008accc:  10 80 00 50  b  0xa008ae0c
a008acd0:  82 10 60 20  or  %g1, 0x20, %g1
a008acd4:  19 33 c0 51  sethi  %hi(0xcf014400), %o4
a008acd8:  98 13 23 70  or  %o4, 0x370, %o4	! 0xcf014770
a008acdc:  82 10 20 01  mov  1, %g1
a008ace0:  da 03 00 00  ld  [ %o4 ], %o5
a008ace4:  83 28 40 09  sll  %g1, %o1, %g1
a008ace8:  82 2b 40 01  andn  %o5, %g1, %g1
a008acec:  1b 33 c0 44  sethi  %hi(0xcf011000), %o5
a008acf0:  c2 23 00 00  st  %g1, [ %o4 ]
a008acf4:  9a 13 61 c4  or  %o5, 0x1c4, %o5
a008acf8:  c2 03 40 00  ld  [ %o5 ], %g1
a008acfc:  82 10 60 06  or  %g1, 6, %g1
a008ad00:  10 80 00 43  b  0xa008ae0c
a008ad04:  82 08 60 f7  and  %g1, 0xf7, %g1
a008ad08:  19 33 c0 51  sethi  %hi(0xcf014400), %o4
a008ad0c:  98 13 23 70  or  %o4, 0x370, %o4	! 0xcf014770
a008ad10:  82 10 20 01  mov  1, %g1
a008ad14:  da 03 00 00  ld  [ %o4 ], %o5
a008ad18:  83 28 40 09  sll  %g1, %o1, %g1
a008ad1c:  82 2b 40 01  andn  %o5, %g1, %g1
a008ad20:  1b 33 c0 44  sethi  %hi(0xcf011000), %o5
a008ad24:  c2 23 00 00  st  %g1, [ %o4 ]
a008ad28:  9a 13 61 c8  or  %o5, 0x1c8, %o5
a008ad2c:  c2 03 40 00  ld  [ %o5 ], %g1
a008ad30:  82 08 60 3f  and  %g1, 0x3f, %g1
a008ad34:  10 80 00 36  b  0xa008ae0c
a008ad38:  82 10 60 a0  or  %g1, 0xa0, %g1
a008ad3c:  19 33 c0 51  sethi  %hi(0xcf014400), %o4
a008ad40:  98 13 23 70  or  %o4, 0x370, %o4	! 0xcf014770
a008ad44:  82 10 20 01  mov  1, %g1
a008ad48:  da 03 00 00  ld  [ %o4 ], %o5
a008ad4c:  83 28 40 09  sll  %g1, %o1, %g1
a008ad50:  82 2b 40 01  andn  %o5, %g1, %g1
a008ad54:  1b 33 c0 44  sethi  %hi(0xcf011000), %o5
a008ad58:  c2 23 00 00  st  %g1, [ %o4 ]
a008ad5c:  9a 13 61 c8  or  %o5, 0x1c8, %o5
a008ad60:  c2 03 40 00  ld  [ %o5 ], %g1
a008ad64:  82 10 60 0e  or  %g1, 0xe, %g1
a008ad68:  10 80 00 29  b  0xa008ae0c
a008ad6c:  82 08 60 ff  and  %g1, 0xff, %g1
a008ad70:  19 33 c0 51  sethi  %hi(0xcf014400), %o4
a008ad74:  98 13 23 70  or  %o4, 0x370, %o4	! 0xcf014770
a008ad78:  96 0a 60 ff  and  %o1, 0xff, %o3
a008ad7c:  82 10 20 01  mov  1, %g1
a008ad80:  da 03 00 00  ld  [ %o4 ], %o5
a008ad84:  83 28 40 0b  sll  %g1, %o3, %g1
a008ad88:  82 2b 40 01  andn  %o5, %g1, %g1
a008ad8c:  1b 33 c0 44  sethi  %hi(0xcf011000), %o5
a008ad90:  c2 23 00 00  st  %g1, [ %o4 ]
a008ad94:  9a 13 61 c0  or  %o5, 0x1c0, %o5
a008ad98:  c2 03 40 00  ld  [ %o5 ], %g1
a008ad9c:  82 08 60 1f  and  %g1, 0x1f, %g1
a008ada0:  82 10 60 20  or  %g1, 0x20, %g1
a008ada4:  97 2a e0 06  sll  %o3, 6, %o3
a008ada8:  10 80 00 19  b  0xa008ae0c
a008adac:  82 10 40 0b  or  %g1, %o3, %g1
a008adb0:  03 33 c0 44  sethi  %hi(0xcf011000), %g1
a008adb4:  82 10 61 c0  or  %g1, 0x1c0, %g1	! 0xcf0111c0
a008adb8:  da 00 40 00  ld  [ %g1 ], %o5
a008adbc:  9a 13 60 10  or  %o5, 0x10, %o5
a008adc0:  98 0a 60 ff  and  %o1, 0xff, %o4
a008adc4:  9a 0b 60 f3  and  %o5, 0xf3, %o5
a008adc8:  99 2b 20 02  sll  %o4, 2, %o4
a008adcc:  9a 13 40 0c  or  %o5, %o4, %o5
a008add0:  da 20 40 00  st  %o5, [ %g1 ]
a008add4:  30 80 00 0f  b,a   0xa008ae10
a008add8:  1b 33 c0 51  sethi  %hi(0xcf014400), %o5
a008addc:  9a 13 63 70  or  %o5, 0x370, %o5	! 0xcf014770
a008ade0:  c2 03 40 00  ld  [ %o5 ], %g1
a008ade4:  98 0a 60 ff  and  %o1, 0xff, %o4
a008ade8:  82 10 40 0c  or  %g1, %o4, %g1
a008adec:  c2 23 40 00  st  %g1, [ %o5 ]
a008adf0:  1b 33 c0 44  sethi  %hi(0xcf011000), %o5
a008adf4:  9a 13 61 d4  or  %o5, 0x1d4, %o5	! 0xcf0111d4
a008adf8:  c2 03 40 00  ld  [ %o5 ], %g1
a008adfc:  82 08 60 1f  and  %g1, 0x1f, %g1
a008ae00:  82 10 60 20  or  %g1, 0x20, %g1
a008ae04:  99 2b 20 06  sll  %o4, 6, %o4
a008ae08:  82 10 40 0c  or  %g1, %o4, %g1
a008ae0c:  c2 23 40 00  st  %g1, [ %o5 ]
a008ae10:  81 c3 e0 08  retl
a008ae14:  01 00 00 00  nop
