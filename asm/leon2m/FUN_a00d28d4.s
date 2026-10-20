# leon2m FUN_a00d28d4 0xa00d28d4-0xa00d2974 (160 bytes)
a00d28d4:  9d e3 bf 98  save  %sp, -104, %sp
a00d28d8:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00d28dc:  da 0e 20 07  ldub  [ %i0 + 7 ], %o5
a00d28e0:  a2 14 22 90  or  %l0, 0x290, %l1
a00d28e4:  25 00 00 10  sethi  %hi(0x4000), %l2
a00d28e8:  90 10 20 30  mov  0x30, %o0
a00d28ec:  92 10 00 11  mov  %l1, %o1
a00d28f0:  94 10 20 00  clr  %o2
a00d28f4:  96 10 21 fc  mov  0x1fc, %o3
a00d28f8:  80 a3 60 01  cmp  %o5, 1
a00d28fc:  12 80 00 1c  bne  0xa00d296c
a00d2900:  b0 10 20 e4  mov  0xe4, %i0
a00d2904:  c2 04 22 90  ld  [ %l0 + 0x290 ], %g1
a00d2908:  b0 10 40 12  or  %g1, %l2, %i0
a00d290c:  f0 24 22 90  st  %i0, [ %l0 + 0x290 ]
a00d2910:  da 2c 61 d5  stb  %o5, [ %l1 + 0x1d5 ]
a00d2914:  1f 00 00 15  sethi  %hi(0x5400), %o7
a00d2918:  98 13 e1 aa  or  %o7, 0x1aa, %o4	! 0x55aa
a00d291c:  9a 10 20 55  mov  0x55, %o5
a00d2920:  d8 34 61 f6  sth  %o4, [ %l1 + 0x1f6 ]
a00d2924:  40 01 e1 6b  call  0xa014aed0
a00d2928:  da 2c 61 d6  stb  %o5, [ %l1 + 0x1d6 ]
a00d292c:  c2 04 22 90  ld  [ %l0 + 0x290 ], %g1
a00d2930:  80 88 40 12  btst  %g1, %l2
a00d2934:  02 80 00 0e  be  0xa00d296c
a00d2938:  b0 10 20 e4  mov  0xe4, %i0
a00d293c:  d0 0c 61 d5  ldub  [ %l1 + 0x1d5 ], %o0
a00d2940:  80 a2 20 01  cmp  %o0, 1
a00d2944:  02 80 00 04  be  0xa00d2954
a00d2948:  b0 10 20 e0  mov  0xe0, %i0
a00d294c:  10 80 00 08  b  0xa00d296c
a00d2950:  b0 10 20 e4  mov  0xe4, %i0
a00d2954:  17 00 00 15  sethi  %hi(0x5400), %o3
a00d2958:  d4 14 61 f6  lduh  [ %l1 + 0x1f6 ], %o2
a00d295c:  92 12 e1 aa  or  %o3, 0x1aa, %o1
a00d2960:  80 a2 80 09  cmp  %o2, %o1
a00d2964:  32 80 00 02  bne,a   0xa00d296c
a00d2968:  b0 10 20 e4  mov  0xe4, %i0
a00d296c:  81 c7 e0 08  ret
a00d2970:  81 e8 00 00  restore
