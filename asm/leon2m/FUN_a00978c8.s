# leon2m FUN_a00978c8 0xa00978c8-0xa0097988 (192 bytes)
a00978c8:  9d e3 bf 98  save  %sp, -104, %sp
a00978cc:  25 2a 00 97  sethi  %hi(0xa8025c00), %l2
a00978d0:  40 00 45 86  call  0xa00a8ee8
a00978d4:  d0 0c a0 56  ldub  [ %l2 + 0x56 ], %o0	! 0xa8025c56
a00978d8:  90 10 20 00  clr  %o0
a00978dc:  d2 0c a0 56  ldub  [ %l2 + 0x56 ], %o1
a00978e0:  40 00 42 17  call  0xa00a813c
a00978e4:  94 10 20 00  clr  %o2
a00978e8:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00978ec:  a2 12 e2 90  or  %o3, 0x290, %l1	! 0xa802d290
a00978f0:  94 10 20 00  clr  %o2
a00978f4:  90 10 20 00  clr  %o0
a00978f8:  40 00 42 11  call  0xa00a813c
a00978fc:  d2 0c 60 1f  ldub  [ %l1 + 0x1f ], %o1
a0097900:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a0097904:  d4 04 23 ec  ld  [ %l0 + 0x3ec ], %o2	! 0xa802afec
a0097908:  92 02 bf dd  add  %o2, -35, %o1
a009790c:  90 0a 60 ff  and  %o1, 0xff, %o0
a0097910:  40 00 45 bf  call  0xa00a900c
a0097914:  92 10 20 02  mov  2, %o1
a0097918:  7f ff fe fc  call  0xa0097508
a009791c:  01 00 00 00  nop
a0097920:  7f ff ff 76  call  0xa00976f8
a0097924:  01 00 00 00  nop
a0097928:  90 10 20 7a  mov  0x7a, %o0	! 0x7a
a009792c:  d0 24 23 ec  st  %o0, [ %l0 + 0x3ec ]
a0097930:  90 10 20 00  clr  %o0
a0097934:  40 00 47 47  call  0xa00a9650
a0097938:  92 10 20 03  mov  3, %o1
a009793c:  d6 0c 60 1f  ldub  [ %l1 + 0x1f ], %o3
a0097940:  9a 0a e0 ff  and  %o3, 0xff, %o5
a0097944:  c2 0c a0 56  ldub  [ %l2 + 0x56 ], %g1
a0097948:  80 a3 40 01  cmp  %o5, %g1
a009794c:  22 80 00 06  be,a   0xa0097964
a0097950:  c2 0c 61 a4  ldub  [ %l1 + 0x1a4 ], %g1
a0097954:  40 00 55 68  call  0xa00acef4
a0097958:  01 00 00 00  nop
a009795c:  d6 0c 60 1f  ldub  [ %l1 + 0x1f ], %o3
a0097960:  c2 0c 61 a4  ldub  [ %l1 + 0x1a4 ], %g1
a0097964:  23 2a 00 97  sethi  %hi(0xa8025c00), %l1
a0097968:  9e 10 20 0f  mov  0xf, %o7
a009796c:  19 2a 00 ac  sethi  %hi(0xa802b000), %o4
a0097970:  d6 2c a0 56  stb  %o3, [ %l2 + 0x56 ]
a0097974:  c2 2c 60 55  stb  %g1, [ %l1 + 0x55 ]
a0097978:  de 2b 20 8f  stb  %o7, [ %o4 + 0x8f ]
a009797c:  40 00 f4 07  call  0xa00d4998
a0097980:  81 e8 00 00  restore
a0097984:  01 00 00 00  nop
