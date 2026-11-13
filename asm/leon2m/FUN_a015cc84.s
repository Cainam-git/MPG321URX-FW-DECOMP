# leon2m FUN_a015cc84 0xa015cc84-0xa015cd28 (164 bytes)
a015cc84:  9d e3 bf 98  save  %sp, -104, %sp
a015cc88:  d6 06 20 4c  ld  [ %i0 + 0x4c ], %o3
a015cc8c:  92 10 20 04  mov  4, %o1
a015cc90:  94 10 20 10  mov  0x10, %o2
a015cc94:  80 a2 e0 00  cmp  %o3, 0
a015cc98:  02 80 00 12  be  0xa015cce0
a015cc9c:  90 10 00 18  mov  %i0, %o0
a015cca0:  82 10 20 01  mov  1, %g1
a015cca4:  a1 28 40 19  sll  %g1, %i1, %l0
a015cca8:  99 2e 60 02  sll  %i1, 2, %o4
a015ccac:  95 2c 20 02  sll  %l0, 2, %o2
a015ccb0:  da 02 c0 0c  ld  [ %o3 + %o4 ], %o5
a015ccb4:  90 10 00 18  mov  %i0, %o0
a015ccb8:  94 02 a0 14  add  %o2, 0x14, %o2
a015ccbc:  80 a3 60 00  cmp  %o5, 0
a015ccc0:  02 80 00 10  be  0xa015cd00
a015ccc4:  92 10 20 01  mov  1, %o1
a015ccc8:  c2 03 40 00  ld  [ %o5 ], %g1
a015cccc:  c2 22 c0 0c  st  %g1, [ %o3 + %o4 ]
a015ccd0:  c0 23 60 10  clr  [ %o5 + 0x10 ]
a015ccd4:  c0 23 60 0c  clr  [ %o5 + 0xc ]
a015ccd8:  10 80 00 12  b  0xa015cd20
a015ccdc:  82 10 00 0d  mov  %o5, %g1
a015cce0:  40 00 05 25  call  0xa015e174
a015cce4:  01 00 00 00  nop
a015cce8:  96 10 00 08  mov  %o0, %o3
a015ccec:  d0 26 20 4c  st  %o0, [ %i0 + 0x4c ]
a015ccf0:  80 a2 20 00  cmp  %o0, 0
a015ccf4:  12 bf ff eb  bne  0xa015cca0
a015ccf8:  82 10 20 00  clr  %g1
a015ccfc:  30 80 00 09  b,a   0xa015cd20
a015cd00:  40 00 05 1d  call  0xa015e174
a015cd04:  01 00 00 00  nop
a015cd08:  9a 92 20 00  orcc  %o0, 0, %o5
a015cd0c:  02 80 00 05  be  0xa015cd20
a015cd10:  82 10 20 00  clr  %g1
a015cd14:  f2 23 60 04  st  %i1, [ %o5 + 4 ]
a015cd18:  10 bf ff ee  b  0xa015ccd0
a015cd1c:  e0 23 60 08  st  %l0, [ %o5 + 8 ]
a015cd20:  81 c7 e0 08  ret
a015cd24:  91 e8 00 01  restore  %g0, %g1, %o0
