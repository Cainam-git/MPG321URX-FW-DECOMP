# leon2m FUN_a011e8fc 0xa011e8fc-0xa011eadc (100 bytes)
a011e8fc:  92 0a 60 ff  and  %o1, 0xff, %o1
a011e900:  80 a2 60 01  cmp  %o1, 1
a011e904:  02 80 00 11  be  0xa011e948
a011e908:  98 0a 20 ff  and  %o0, 0xff, %o4
a011e90c:  82 03 3f f0  add  %o4, -16, %g1
a011e910:  80 a0 60 07  cmp  %g1, 7
a011e914:  18 80 00 70  bgu  0xa011ead4
a011e918:  19 00 02 f5  sethi  %hi(0xbd400), %o4
a011e91c:  93 28 60 02  sll  %g1, 2, %o1
a011e920:  9a 13 22 50  or  %o4, 0x250, %o5
a011e924:  d0 03 40 09  ld  [ %o5 + %o1 ], %o0
a011e928:  81 c2 00 00  jmp  %o0
a011e92c:  01 00 00 00  nop
a011e930:  19 33 c0 59  sethi  %hi(0xcf016400), %o4
a011e934:  9a 13 20 70  or  %o4, 0x70, %o5	! 0xcf016470
a011e938:  c2 03 40 00  ld  [ %o5 ], %g1
a011e93c:  82 10 60 01  or  %g1, 1, %g1
a011e940:  c2 23 40 00  st  %g1, [ %o5 ]
a011e944:  30 80 00 64  b,a   0xa011ead4
a011e948:  82 0a 20 ff  and  %o0, 0xff, %g1
a011e94c:  82 00 7f f0  add  %g1, -16, %g1
a011e950:  80 a0 60 07  cmp  %g1, 7
a011e954:  18 80 00 60  bgu  0xa011ead4
a011e958:  13 00 02 f5  sethi  %hi(0xbd400), %o1
a011e95c:  91 28 60 02  sll  %g1, 2, %o0
a011e960:  9a 12 62 30  or  %o1, 0x230, %o5
a011e964:  d8 03 40 08  ld  [ %o5 + %o0 ], %o4
a011e968:  81 c3 00 00  jmp  %o4
a011e96c:  01 00 00 00  nop
a011e970:  1b 33 c0 59  sethi  %hi(0xcf016400), %o5
a011e974:  9a 13 60 70  or  %o5, 0x70, %o5	! 0xcf016470
a011e978:  c2 03 40 00  ld  [ %o5 ], %g1
a011e97c:  82 08 7f 7f  and  %g1, -129, %g1
a011e980:  c2 23 40 00  st  %g1, [ %o5 ]
a011e984:  30 80 00 54  b,a   0xa011ead4
a011e988:  11 33 c0 59  sethi  %hi(0xcf016400), %o0
a011e98c:  9a 12 20 70  or  %o0, 0x70, %o5	! 0xcf016470
a011e990:  c2 03 40 00  ld  [ %o5 ], %g1
a011e994:  82 08 7f fe  and  %g1, -2, %g1
a011e998:  c2 23 40 00  st  %g1, [ %o5 ]
a011e99c:  30 80 00 4e  b,a   0xa011ead4
a011e9a0:  1b 33 c0 59  sethi  %hi(0xcf016400), %o5
a011e9a4:  9a 13 60 70  or  %o5, 0x70, %o5	! 0xcf016470
a011e9a8:  d2 03 40 00  ld  [ %o5 ], %o1
a011e9ac:  82 0a 7f fd  and  %o1, -3, %g1
a011e9b0:  c2 23 40 00  st  %g1, [ %o5 ]
a011e9b4:  30 80 00 48  b,a   0xa011ead4
a011e9b8:  03 33 c0 59  sethi  %hi(0xcf016400), %g1
a011e9bc:  9a 10 60 70  or  %g1, 0x70, %o5	! 0xcf016470
a011e9c0:  d8 03 40 00  ld  [ %o5 ], %o4
a011e9c4:  82 0b 3f fb  and  %o4, -5, %g1
a011e9c8:  c2 23 40 00  st  %g1, [ %o5 ]
a011e9cc:  30 80 00 42  b,a   0xa011ead4
a011e9d0:  13 33 c0 59  sethi  %hi(0xcf016400), %o1
a011e9d4:  9a 12 60 70  or  %o1, 0x70, %o5	! 0xcf016470
a011e9d8:  d0 03 40 00  ld  [ %o5 ], %o0
a011e9dc:  82 0a 3f f7  and  %o0, -9, %g1
a011e9e0:  c2 23 40 00  st  %g1, [ %o5 ]
a011e9e4:  30 80 00 3c  b,a   0xa011ead4
a011e9e8:  1b 33 c0 59  sethi  %hi(0xcf016400), %o5
a011e9ec:  9a 13 60 70  or  %o5, 0x70, %o5	! 0xcf016470
a011e9f0:  d8 03 40 00  ld  [ %o5 ], %o4
a011e9f4:  82 0b 3f ef  and  %o4, -17, %g1
a011e9f8:  c2 23 40 00  st  %g1, [ %o5 ]
a011e9fc:  30 80 00 36  b,a   0xa011ead4
a011ea00:  11 33 c0 59  sethi  %hi(0xcf016400), %o0
a011ea04:  9a 12 20 70  or  %o0, 0x70, %o5	! 0xcf016470
a011ea08:  c2 03 40 00  ld  [ %o5 ], %g1
a011ea0c:  82 08 7f df  and  %g1, -33, %g1
a011ea10:  c2 23 40 00  st  %g1, [ %o5 ]
a011ea14:  30 80 00 30  b,a   0xa011ead4
a011ea18:  19 33 c0 59  sethi  %hi(0xcf016400), %o4
a011ea1c:  9a 13 20 70  or  %o4, 0x70, %o5	! 0xcf016470
a011ea20:  d2 03 40 00  ld  [ %o5 ], %o1
a011ea24:  82 0a 7f bf  and  %o1, -65, %g1
a011ea28:  c2 23 40 00  st  %g1, [ %o5 ]
a011ea2c:  30 80 00 2a  b,a   0xa011ead4
a011ea30:  1b 33 c0 59  sethi  %hi(0xcf016400), %o5
a011ea34:  9a 13 60 70  or  %o5, 0x70, %o5	! 0xcf016470
a011ea38:  d2 03 40 00  ld  [ %o5 ], %o1
a011ea3c:  82 12 60 10  or  %o1, 0x10, %g1
a011ea40:  c2 23 40 00  st  %g1, [ %o5 ]
a011ea44:  30 80 00 24  b,a   0xa011ead4
a011ea48:  11 33 c0 59  sethi  %hi(0xcf016400), %o0
a011ea4c:  9a 12 20 70  or  %o0, 0x70, %o5	! 0xcf016470
a011ea50:  d8 03 40 00  ld  [ %o5 ], %o4
a011ea54:  82 13 20 08  or  %o4, 8, %g1
a011ea58:  c2 23 40 00  st  %g1, [ %o5 ]
a011ea5c:  30 80 00 1e  b,a   0xa011ead4
a011ea60:  03 33 c0 59  sethi  %hi(0xcf016400), %g1
a011ea64:  9a 10 60 70  or  %g1, 0x70, %o5	! 0xcf016470
a011ea68:  d2 03 40 00  ld  [ %o5 ], %o1
a011ea6c:  82 12 60 04  or  %o1, 4, %g1
a011ea70:  c2 23 40 00  st  %g1, [ %o5 ]
a011ea74:  30 80 00 18  b,a   0xa011ead4
a011ea78:  1b 33 c0 59  sethi  %hi(0xcf016400), %o5
a011ea7c:  9a 13 60 70  or  %o5, 0x70, %o5	! 0xcf016470
a011ea80:  d0 03 40 00  ld  [ %o5 ], %o0
a011ea84:  82 12 20 02  or  %o0, 2, %g1
a011ea88:  c2 23 40 00  st  %g1, [ %o5 ]
a011ea8c:  30 80 00 12  b,a   0xa011ead4
a011ea90:  13 33 c0 59  sethi  %hi(0xcf016400), %o1
a011ea94:  9a 12 60 70  or  %o1, 0x70, %o5	! 0xcf016470
a011ea98:  d0 03 40 00  ld  [ %o5 ], %o0
a011ea9c:  82 12 20 40  or  %o0, 0x40, %g1
a011eaa0:  c2 23 40 00  st  %g1, [ %o5 ]
a011eaa4:  30 80 00 0c  b,a   0xa011ead4
a011eaa8:  19 33 c0 59  sethi  %hi(0xcf016400), %o4
a011eaac:  9a 13 20 70  or  %o4, 0x70, %o5	! 0xcf016470
a011eab0:  c2 03 40 00  ld  [ %o5 ], %g1
a011eab4:  82 10 60 20  or  %g1, 0x20, %g1
a011eab8:  c2 23 40 00  st  %g1, [ %o5 ]
a011eabc:  30 80 00 06  b,a   0xa011ead4
a011eac0:  1b 33 c0 59  sethi  %hi(0xcf016400), %o5
a011eac4:  9a 13 60 70  or  %o5, 0x70, %o5	! 0xcf016470
a011eac8:  c2 03 40 00  ld  [ %o5 ], %g1
a011eacc:  82 10 60 80  or  %g1, 0x80, %g1
a011ead0:  c2 23 40 00  st  %g1, [ %o5 ]
a011ead4:  81 c3 e0 08  retl
a011ead8:  01 00 00 00  nop
