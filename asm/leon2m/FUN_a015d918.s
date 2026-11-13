# leon2m FUN_a015d918 0xa015d918-0xa015d994 (124 bytes)
a015d918:  9d e3 bf 90  save  %sp, -112, %sp
a015d91c:  90 10 00 18  mov  %i0, %o0
a015d920:  7f ff ff 78  call  0xa015d700
a015d924:  92 07 bf f4  add  %fp, -12, %o1
a015d928:  a0 10 00 08  mov  %o0, %l0
a015d92c:  a2 10 00 09  mov  %o1, %l1
a015d930:  90 10 00 19  mov  %i1, %o0
a015d934:  7f ff ff 73  call  0xa015d700
a015d938:  92 07 bf f0  add  %fp, -16, %o1
a015d93c:  da 06 60 10  ld  [ %i1 + 0x10 ], %o5
a015d940:  d8 06 20 10  ld  [ %i0 + 0x10 ], %o4
a015d944:  98 23 00 0d  sub  %o4, %o5, %o4
a015d948:  da 07 bf f0  ld  [ %fp + -16 ], %o5
a015d94c:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a015d950:  82 20 40 0d  sub  %g1, %o5, %g1
a015d954:  99 2b 20 05  sll  %o4, 5, %o4
a015d958:  82 00 40 0c  add  %g1, %o4, %g1
a015d95c:  94 10 00 08  mov  %o0, %o2
a015d960:  96 10 00 09  mov  %o1, %o3
a015d964:  80 a0 60 00  cmp  %g1, 0
a015d968:  04 80 00 04  ble  0xa015d978
a015d96c:  9b 28 60 14  sll  %g1, 0x14, %o5
a015d970:  10 80 00 03  b  0xa015d97c
a015d974:  a0 03 40 10  add  %o5, %l0, %l0
a015d978:  94 22 80 0d  sub  %o2, %o5, %o2
a015d97c:  90 10 00 10  mov  %l0, %o0
a015d980:  7f ff e2 cc  call  0xa01564b0
a015d984:  92 10 00 11  mov  %l1, %o1
a015d988:  b0 10 00 08  mov  %o0, %i0
a015d98c:  81 c7 e0 08  ret
a015d990:  93 e8 00 09  restore  %g0, %o1, %o1
