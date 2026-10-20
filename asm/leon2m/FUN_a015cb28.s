# leon2m FUN_a015cb28 0xa015cb28-0xa015cc54 (300 bytes)
a015cb28:  96 10 00 09  mov  %o1, %o3
a015cb2c:  80 a2 40 08  cmp  %o1, %o0
a015cb30:  9a 10 00 08  mov  %o0, %o5
a015cb34:  1a 80 00 13  bcc  0xa015cb80
a015cb38:  98 10 00 0a  mov  %o2, %o4
a015cb3c:  82 02 40 0a  add  %o1, %o2, %g1
a015cb40:  80 a0 40 08  cmp  %g1, %o0
a015cb44:  08 80 00 10  bleu  0xa015cb84
a015cb48:  80 a2 a0 0f  cmp  %o2, 0xf
a015cb4c:  98 02 bf ff  add  %o2, -1, %o4
a015cb50:  9a 02 00 0a  add  %o0, %o2, %o5
a015cb54:  80 a3 3f ff  cmp  %o4, -1
a015cb58:  02 80 00 3d  be  0xa015cc4c
a015cb5c:  92 10 00 01  mov  %g1, %o1
a015cb60:  92 02 7f ff  add  %o1, -1, %o1
a015cb64:  9a 03 7f ff  add  %o5, -1, %o5
a015cb68:  98 03 3f ff  add  %o4, -1, %o4
a015cb6c:  c2 0a 40 00  ldub  [ %o1 ], %g1
a015cb70:  80 a3 3f ff  cmp  %o4, -1
a015cb74:  12 bf ff fb  bne  0xa015cb60
a015cb78:  c2 2b 40 00  stb  %g1, [ %o5 ]
a015cb7c:  30 80 00 34  b,a   0xa015cc4c
a015cb80:  80 a2 a0 0f  cmp  %o2, 0xf
a015cb84:  18 80 00 0e  bgu  0xa015cbbc
a015cb88:  82 12 c0 08  or  %o3, %o0, %g1
a015cb8c:  98 03 3f ff  add  %o4, -1, %o4
a015cb90:  80 a3 3f ff  cmp  %o4, -1
a015cb94:  02 80 00 2e  be  0xa015cc4c
a015cb98:  01 00 00 00  nop
a015cb9c:  c2 0a 40 00  ldub  [ %o1 ], %g1
a015cba0:  c2 2b 40 00  stb  %g1, [ %o5 ]
a015cba4:  98 03 3f ff  add  %o4, -1, %o4
a015cba8:  92 02 60 01  inc  %o1
a015cbac:  80 a3 3f ff  cmp  %o4, -1
a015cbb0:  12 bf ff fb  bne  0xa015cb9c
a015cbb4:  9a 03 60 01  inc  %o5
a015cbb8:  30 80 00 25  b,a   0xa015cc4c
a015cbbc:  80 88 60 03  btst  3, %g1
a015cbc0:  32 bf ff f4  bne,a   0xa015cb90
a015cbc4:  98 03 3f ff  add  %o4, -1, %o4
a015cbc8:  92 10 00 0b  mov  %o3, %o1
a015cbcc:  9a 10 00 08  mov  %o0, %o5
a015cbd0:  c2 02 40 00  ld  [ %o1 ], %g1
a015cbd4:  c2 23 40 00  st  %g1, [ %o5 ]
a015cbd8:  92 02 60 04  add  %o1, 4, %o1
a015cbdc:  c2 02 40 00  ld  [ %o1 ], %g1
a015cbe0:  9a 03 60 04  add  %o5, 4, %o5
a015cbe4:  c2 23 40 00  st  %g1, [ %o5 ]
a015cbe8:  92 02 60 04  add  %o1, 4, %o1
a015cbec:  c2 02 40 00  ld  [ %o1 ], %g1
a015cbf0:  9a 03 60 04  add  %o5, 4, %o5
a015cbf4:  c2 23 40 00  st  %g1, [ %o5 ]
a015cbf8:  92 02 60 04  add  %o1, 4, %o1
a015cbfc:  9a 03 60 04  add  %o5, 4, %o5
a015cc00:  c2 02 40 00  ld  [ %o1 ], %g1
a015cc04:  c2 23 40 00  st  %g1, [ %o5 ]
a015cc08:  98 03 3f f0  add  %o4, -16, %o4
a015cc0c:  92 02 60 04  add  %o1, 4, %o1
a015cc10:  80 a3 20 0f  cmp  %o4, 0xf
a015cc14:  18 bf ff ef  bgu  0xa015cbd0
a015cc18:  9a 03 60 04  add  %o5, 4, %o5
a015cc1c:  80 a3 20 03  cmp  %o4, 3
a015cc20:  28 bf ff dc  bleu,a   0xa015cb90
a015cc24:  98 03 3f ff  add  %o4, -1, %o4
a015cc28:  c2 02 40 00  ld  [ %o1 ], %g1
a015cc2c:  c2 23 40 00  st  %g1, [ %o5 ]
a015cc30:  98 03 3f fc  add  %o4, -4, %o4
a015cc34:  92 02 60 04  add  %o1, 4, %o1
a015cc38:  80 a3 20 03  cmp  %o4, 3
a015cc3c:  18 bf ff fb  bgu  0xa015cc28
a015cc40:  9a 03 60 04  add  %o5, 4, %o5
a015cc44:  10 bf ff d3  b  0xa015cb90
a015cc48:  98 03 3f ff  add  %o4, -1, %o4
a015cc4c:  81 c3 e0 08  retl
a015cc50:  01 00 00 00  nop
