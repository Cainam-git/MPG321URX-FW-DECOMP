# leon2m FUN_a014e8ec 0xa014e8ec-0xa014e960 (116 bytes)
a014e8ec:  9d e3 bf 98  save  %sp, -104, %sp
a014e8f0:  03 33 c0 3b  sethi  %hi(0xcf00ec00), %g1
a014e8f4:  b6 10 63 80  or  %g1, 0x380, %i3	! 0xcf00ef80
a014e8f8:  9e 10 63 84  or  %g1, 0x384, %o7
a014e8fc:  9a 10 63 88  or  %g1, 0x388, %o5
a014e900:  98 10 63 8c  or  %g1, 0x38c, %o4
a014e904:  96 10 63 90  or  %g1, 0x390, %o3
a014e908:  b8 0e 60 ff  and  %i1, 0xff, %i4
a014e90c:  82 0e a0 ff  and  %i2, 0xff, %g1
a014e910:  b3 2e 60 10  sll  %i1, 0x10, %i1
a014e914:  b5 2e a0 10  sll  %i2, 0x10, %i2
a014e918:  ba 10 00 1b  mov  %i3, %i5
a014e91c:  80 8e 20 ff  btst  0xff, %i0
a014e920:  b3 36 60 18  srl  %i1, 0x18, %i1
a014e924:  02 80 00 0a  be  0xa014e94c
a014e928:  b5 36 a0 18  srl  %i2, 0x18, %i2
a014e92c:  f8 23 c0 00  st  %i4, [ %o7 ]
a014e930:  f2 23 40 00  st  %i1, [ %o5 ]
a014e934:  c2 23 00 00  st  %g1, [ %o4 ]
a014e938:  f4 22 c0 00  st  %i2, [ %o3 ]
a014e93c:  f8 06 c0 00  ld  [ %i3 ], %i4
a014e940:  b0 17 20 03  or  %i4, 3, %i0
a014e944:  f0 26 c0 00  st  %i0, [ %i3 ]
a014e948:  30 80 00 04  b,a   0xa014e958
a014e94c:  f4 06 c0 00  ld  [ %i3 ], %i2
a014e950:  b6 0e bf fd  and  %i2, -3, %i3
a014e954:  f6 27 40 00  st  %i3, [ %i5 ]
a014e958:  81 c7 e0 08  ret
a014e95c:  81 e8 00 00  restore
