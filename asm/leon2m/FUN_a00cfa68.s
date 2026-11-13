# leon2m FUN_a00cfa68 0xa00cfa68-0xa00cfacc (100 bytes)
a00cfa68:  9d e3 bf 98  save  %sp, -104, %sp
a00cfa6c:  90 10 20 00  clr  %o0
a00cfa70:  a0 10 20 04  mov  4, %l0
a00cfa74:  82 10 20 04  mov  4, %g1
a00cfa78:  93 2a 20 10  sll  %o0, 0x10, %o1
a00cfa7c:  d0 08 40 18  ldub  [ %g1 + %i0 ], %o0
a00cfa80:  7f ff fb fc  call  0xa00cea70
a00cfa84:  93 32 60 10  srl  %o1, 0x10, %o1
a00cfa88:  a0 04 20 01  inc  %l0
a00cfa8c:  82 0c 20 ff  and  %l0, 0xff, %g1
a00cfa90:  80 a0 60 07  cmp  %g1, 7
a00cfa94:  08 bf ff fa  bleu  0xa00cfa7c
a00cfa98:  93 2a 20 10  sll  %o0, 0x10, %o1
a00cfa9c:  99 32 20 08  srl  %o0, 8, %o4
a00cfaa0:  d0 2e 60 04  stb  %o0, [ %i1 + 4 ]
a00cfaa4:  90 10 20 6e  mov  0x6e, %o0
a00cfaa8:  9a 10 3f 83  mov  -125, %o5
a00cfaac:  82 10 20 02  mov  2, %g1
a00cfab0:  d0 2e 40 00  stb  %o0, [ %i1 ]
a00cfab4:  da 2e 60 01  stb  %o5, [ %i1 + 1 ]
a00cfab8:  c2 2e 60 02  stb  %g1, [ %i1 + 2 ]
a00cfabc:  d8 2e 60 03  stb  %o4, [ %i1 + 3 ]
a00cfac0:  7f fe e9 28  call  0xa0089f60
a00cfac4:  91 e8 20 50  restore  %g0, 0x50, %o0
a00cfac8:  01 00 00 00  nop
