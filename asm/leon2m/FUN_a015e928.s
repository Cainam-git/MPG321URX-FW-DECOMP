# leon2m FUN_a015e928 0xa015e928-0xa015e970 (72 bytes)
a015e928:  17 2a 00 ab  sethi  %hi(0xa802ac00), %o3
a015e92c:  d8 02 e3 34  ld  [ %o3 + 0x334 ], %o4	! 0xa802af34
a015e930:  9a 10 00 0c  mov  %o4, %o5
a015e934:  c2 03 60 04  ld  [ %o5 + 4 ], %g1
a015e938:  80 88 60 04  btst  4, %g1
a015e93c:  02 bf ff fe  be  0xa015e934
a015e940:  82 0a 20 ff  and  %o0, 0xff, %g1
a015e944:  c2 23 00 00  st  %g1, [ %o4 ]
a015e948:  80 a2 20 0a  cmp  %o0, 0xa
a015e94c:  12 80 00 07  bne  0xa015e968
a015e950:  da 02 e3 34  ld  [ %o3 + 0x334 ], %o5
a015e954:  c2 03 60 04  ld  [ %o5 + 4 ], %g1
a015e958:  80 88 60 04  btst  4, %g1
a015e95c:  02 bf ff fe  be  0xa015e954
a015e960:  82 10 20 0d  mov  0xd, %g1
a015e964:  c2 23 40 00  st  %g1, [ %o5 ]
a015e968:  81 c3 e0 08  retl
a015e96c:  01 00 00 00  nop
