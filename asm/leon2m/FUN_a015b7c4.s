# leon2m FUN_a015b7c4 0xa015b7c4-0xa015b8c0 (252 bytes)
a015b7c4:  9d e3 bf 98  save  %sp, -104, %sp
a015b7c8:  40 00 05 23  call  0xa015cc54
a015b7cc:  90 10 00 18  mov  %i0, %o0
a015b7d0:  03 2a 00 aa  sethi  %hi(0xa802a800), %g1
a015b7d4:  a2 10 62 b8  or  %g1, 0x2b8, %l1	! 0xa802aab8
a015b7d8:  da 04 60 08  ld  [ %l1 + 8 ], %o5
a015b7dc:  c2 03 60 04  ld  [ %o5 + 4 ], %g1
a015b7e0:  a0 08 7f fc  and  %g1, -4, %l0
a015b7e4:  b2 24 00 19  sub  %l0, %i1, %i1
a015b7e8:  b2 06 6f ef  add  %i1, 0xfef, %i1
a015b7ec:  b2 0e 70 00  and  %i1, -4096, %i1
a015b7f0:  b2 06 70 00  add  %i1, -4096, %i1
a015b7f4:  92 10 20 00  clr  %o1
a015b7f8:  80 a6 6f ff  cmp  %i1, 0xfff
a015b7fc:  04 80 00 0a  ble  0xa015b824
a015b800:  90 10 00 18  mov  %i0, %o0
a015b804:  40 00 09 c2  call  0xa015df0c
a015b808:  01 00 00 00  nop
a015b80c:  c2 04 60 08  ld  [ %l1 + 8 ], %g1
a015b810:  82 00 40 10  add  %g1, %l0, %g1
a015b814:  80 a0 40 08  cmp  %g1, %o0
a015b818:  92 20 00 19  neg  %i1, %o1
a015b81c:  02 80 00 05  be  0xa015b830
a015b820:  90 10 00 18  mov  %i0, %o0
a015b824:  40 00 05 12  call  0xa015cc6c
a015b828:  b0 10 20 00  clr  %i0
a015b82c:  30 80 00 23  b,a   0xa015b8b8
a015b830:  40 00 09 b7  call  0xa015df0c
a015b834:  90 10 00 18  mov  %i0, %o0
a015b838:  82 24 00 19  sub  %l0, %i1, %g1
a015b83c:  80 a2 3f ff  cmp  %o0, -1
a015b840:  82 10 60 01  or  %g1, 1, %g1
a015b844:  92 10 20 00  clr  %o1
a015b848:  19 2a 00 b3  sethi  %hi(0xa802cc00), %o4
a015b84c:  02 80 00 0b  be  0xa015b878
a015b850:  90 10 00 18  mov  %i0, %o0
a015b854:  da 04 60 08  ld  [ %l1 + 8 ], %o5
a015b858:  c2 23 60 04  st  %g1, [ %o5 + 4 ]
a015b85c:  c2 03 23 a0  ld  [ %o4 + 0x3a0 ], %g1
a015b860:  82 20 40 19  sub  %g1, %i1, %g1
a015b864:  90 10 00 18  mov  %i0, %o0
a015b868:  40 00 05 01  call  0xa015cc6c
a015b86c:  c2 23 23 a0  st  %g1, [ %o4 + 0x3a0 ]
a015b870:  10 80 00 12  b  0xa015b8b8
a015b874:  b0 10 20 01  mov  1, %i0
a015b878:  40 00 09 a5  call  0xa015df0c
a015b87c:  01 00 00 00  nop
a015b880:  98 10 00 08  mov  %o0, %o4
a015b884:  d6 04 60 08  ld  [ %l1 + 8 ], %o3
a015b888:  a0 23 00 0b  sub  %o4, %o3, %l0
a015b88c:  90 10 00 18  mov  %i0, %o0
a015b890:  80 a4 20 0f  cmp  %l0, 0xf
a015b894:  04 bf ff e4  ble  0xa015b824
a015b898:  b2 14 20 01  or  %l0, 1, %i1
a015b89c:  03 2a 00 aa  sethi  %hi(0xa802a800), %g1
a015b8a0:  da 00 62 b0  ld  [ %g1 + 0x2b0 ], %o5	! 0xa802aab0
a015b8a4:  9a 23 00 0d  sub  %o4, %o5, %o5
a015b8a8:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a015b8ac:  da 20 63 a0  st  %o5, [ %g1 + 0x3a0 ]	! 0xa802cfa0
a015b8b0:  10 bf ff dd  b  0xa015b824
a015b8b4:  f2 22 e0 04  st  %i1, [ %o3 + 4 ]
a015b8b8:  81 c7 e0 08  ret
a015b8bc:  81 e8 00 00  restore
