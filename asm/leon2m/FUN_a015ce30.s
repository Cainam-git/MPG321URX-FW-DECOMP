# leon2m FUN_a015ce30 0xa015ce30-0xa015cef8 (200 bytes)
a015ce30:  9d e3 bf 98  save  %sp, -104, %sp
a015ce34:  92 10 20 09  mov  9, %o1
a015ce38:  7f ff e7 0f  call  0xa0156a74
a015ce3c:  90 06 e0 08  add  %i3, 8, %o0
a015ce40:  80 a2 20 01  cmp  %o0, 1
a015ce44:  92 10 20 00  clr  %o1
a015ce48:  04 80 00 06  ble  0xa015ce60
a015ce4c:  82 10 20 01  mov  1, %g1
a015ce50:  82 00 40 01  add  %g1, %g1, %g1
a015ce54:  80 a2 00 01  cmp  %o0, %g1
a015ce58:  14 bf ff fe  bg  0xa015ce50
a015ce5c:  92 02 60 01  inc  %o1
a015ce60:  7f ff ff 89  call  0xa015cc84
a015ce64:  90 10 00 18  mov  %i0, %o0
a015ce68:  f8 22 20 14  st  %i4, [ %o0 + 0x14 ]
a015ce6c:  82 10 20 01  mov  1, %g1
a015ce70:  c2 22 20 10  st  %g1, [ %o0 + 0x10 ]
a015ce74:  80 a6 a0 09  cmp  %i2, 9
a015ce78:  04 80 00 11  ble  0xa015cebc
a015ce7c:  b8 10 20 09  mov  9, %i4
a015ce80:  b2 06 60 09  add  %i1, 9, %i1
a015ce84:  d6 4e 40 00  ldsb  [ %i1 ], %o3
a015ce88:  92 10 00 08  mov  %o0, %o1
a015ce8c:  96 02 ff d0  add  %o3, -48, %o3
a015ce90:  90 10 00 18  mov  %i0, %o0
a015ce94:  7f ff ff b0  call  0xa015cd54
a015ce98:  94 10 20 0a  mov  0xa, %o2
a015ce9c:  b8 07 20 01  inc  %i4
a015cea0:  80 a7 00 1a  cmp  %i4, %i2
a015cea4:  06 bf ff f8  bl  0xa015ce84
a015cea8:  b2 06 60 01  inc  %i1
a015ceac:  80 a7 00 1b  cmp  %i4, %i3
a015ceb0:  06 80 00 06  bl  0xa015cec8
a015ceb4:  b2 06 60 01  inc  %i1
a015ceb8:  30 80 00 0e  b,a   0xa015cef0
a015cebc:  80 a7 00 1b  cmp  %i4, %i3
a015cec0:  16 80 00 0c  bge  0xa015cef0
a015cec4:  b2 06 60 0a  add  %i1, 0xa, %i1
a015cec8:  b8 26 c0 1c  sub  %i3, %i4, %i4
a015cecc:  d6 4e 40 00  ldsb  [ %i1 ], %o3
a015ced0:  92 10 00 08  mov  %o0, %o1
a015ced4:  96 02 ff d0  add  %o3, -48, %o3
a015ced8:  90 10 00 18  mov  %i0, %o0
a015cedc:  7f ff ff 9e  call  0xa015cd54
a015cee0:  94 10 20 0a  mov  0xa, %o2
a015cee4:  b8 87 3f ff  addcc  %i4, -1, %i4
a015cee8:  12 bf ff f9  bne  0xa015cecc
a015ceec:  b2 06 60 01  inc  %i1
a015cef0:  81 c7 e0 08  ret
a015cef4:  91 e8 00 08  restore  %g0, %o0, %o0
