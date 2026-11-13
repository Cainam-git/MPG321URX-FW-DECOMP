# leon2m FUN_a015b4f8 0xa015b4f8-0xa015b558 (96 bytes)
a015b4f8:  9d e3 bf 98  save  %sp, -104, %sp
a015b4fc:  a0 06 40 19  add  %i1, %i1, %l0
a015b500:  a0 04 00 19  add  %l0, %i1, %l0
a015b504:  83 2c 20 04  sll  %l0, 4, %g1
a015b508:  a0 04 00 01  add  %l0, %g1, %l0
a015b50c:  a1 2c 20 02  sll  %l0, 2, %l0
a015b510:  90 10 00 18  mov  %i0, %o0
a015b514:  40 00 03 92  call  0xa015c35c
a015b518:  92 04 20 0c  add  %l0, 0xc, %o1
a015b51c:  a2 10 00 08  mov  %o0, %l1
a015b520:  82 02 20 0c  add  %o0, 0xc, %g1
a015b524:  90 10 00 01  mov  %g1, %o0
a015b528:  94 10 00 10  mov  %l0, %o2
a015b52c:  92 10 20 00  clr  %o1
a015b530:  80 a4 60 00  cmp  %l1, 0
a015b534:  02 80 00 07  be  0xa015b550
a015b538:  b0 10 20 00  clr  %i0
a015b53c:  f2 24 60 04  st  %i1, [ %l1 + 4 ]
a015b540:  c0 24 40 00  clr  [ %l1 ]
a015b544:  7f ff f0 69  call  0xa01576e8
a015b548:  c2 24 60 08  st  %g1, [ %l1 + 8 ]
a015b54c:  b0 10 00 11  mov  %l1, %i0
a015b550:  81 c7 e0 08  ret
a015b554:  81 e8 00 00  restore
