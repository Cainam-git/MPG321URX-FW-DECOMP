# leon2m FUN_a00e285c 0xa00e285c-0xa00e29a4 (328 bytes)
a00e285c:  9d e3 bf 98  save  %sp, -104, %sp
a00e2860:  80 a6 60 09  cmp  %i1, 9
a00e2864:  18 80 00 38  bgu  0xa00e2944
a00e2868:  82 10 00 19  mov  %i1, %g1
a00e286c:  80 a6 a0 09  cmp  %i2, 9
a00e2870:  18 80 00 2e  bgu  0xa00e2928
a00e2874:  b2 10 00 1a  mov  %i2, %i1
a00e2878:  13 2a 00 98  sethi  %hi(0xa8026000), %o1
a00e287c:  15 2a 00 98  sethi  %hi(0xa8026000), %o2
a00e2880:  17 2a 00 98  sethi  %hi(0xa8026000), %o3
a00e2884:  b5 28 60 02  sll  %g1, 2, %i2
a00e2888:  98 10 00 1d  mov  %i5, %o4
a00e288c:  90 10 00 18  mov  %i0, %o0
a00e2890:  92 12 60 b0  or  %o1, 0xb0, %o1
a00e2894:  94 12 a0 88  or  %o2, 0x88, %o2
a00e2898:  80 a0 7f ff  cmp  %g1, -1
a00e289c:  02 80 00 30  be  0xa00e295c
a00e28a0:  96 12 e0 60  or  %o3, 0x60, %o3
a00e28a4:  1b 2a 00 98  sethi  %hi(0xa8026000), %o5
a00e28a8:  17 2a 00 98  sethi  %hi(0xa8026000), %o3
a00e28ac:  3b 2a 00 98  sethi  %hi(0xa8026000), %i5
a00e28b0:  82 12 e0 88  or  %o3, 0x88, %g1
a00e28b4:  b2 13 60 b0  or  %o5, 0xb0, %i1
a00e28b8:  a2 17 60 60  or  %i5, 0x60, %l1
a00e28bc:  d4 00 40 1a  ld  [ %g1 + %i2 ], %o2
a00e28c0:  d2 06 40 1a  ld  [ %i1 + %i2 ], %o1
a00e28c4:  7f ff f7 ac  call  0xa00e0774
a00e28c8:  d6 04 40 1a  ld  [ %l1 + %i2 ], %o3
a00e28cc:  13 2a 00 98  sethi  %hi(0xa8026000), %o1
a00e28d0:  15 2a 00 98  sethi  %hi(0xa8026000), %o2
a00e28d4:  19 2a 00 97  sethi  %hi(0xa8025c00), %o4
a00e28d8:  b2 13 23 e8  or  %o4, 0x3e8, %i1	! 0xa8025fe8
a00e28dc:  9e 12 60 38  or  %o1, 0x38, %o7
a00e28e0:  9a 12 a0 10  or  %o2, 0x10, %o5
a00e28e4:  d6 06 40 1a  ld  [ %i1 + %i2 ], %o3
a00e28e8:  90 10 00 18  mov  %i0, %o0
a00e28ec:  d2 03 c0 1a  ld  [ %o7 + %i2 ], %o1
a00e28f0:  d4 03 40 1a  ld  [ %o5 + %i2 ], %o2
a00e28f4:  7f ff f7 a0  call  0xa00e0774
a00e28f8:  98 10 00 1b  mov  %i3, %o4
a00e28fc:  17 2a 00 ad  sethi  %hi(0xa802b400), %o3
a00e2900:  3b 2a 00 97  sethi  %hi(0xa8025c00), %i5
a00e2904:  82 12 e1 a8  or  %o3, 0x1a8, %g1
a00e2908:  a2 17 63 c0  or  %i5, 0x3c0, %l1
a00e290c:  21 2a 00 97  sethi  %hi(0xa8025c00), %l0
a00e2910:  f6 00 40 1a  ld  [ %g1 + %i2 ], %i3
a00e2914:  f2 04 40 1a  ld  [ %l1 + %i2 ], %i1
a00e2918:  90 14 23 98  or  %l0, 0x398, %o0
a00e291c:  f4 02 00 1a  ld  [ %o0 + %i2 ], %i2
a00e2920:  7f ff f7 95  call  0xa00e0774
a00e2924:  81 e8 00 00  restore
a00e2928:  7f ff f3 b9  call  0xa00df80c
a00e292c:  01 00 00 00  nop
a00e2930:  7f ff f8 a4  call  0xa00e0bc0
a00e2934:  01 00 00 00  nop
a00e2938:  03 00 06 65  sethi  %hi(0x199400), %g1
a00e293c:  7f ff f2 0d  call  0xa00df170
a00e2940:  91 e8 63 68  restore  %g1, 0x368, %o0
a00e2944:  7f ff f3 b2  call  0xa00df80c
a00e2948:  31 00 06 65  sethi  %hi(0x199400), %i0
a00e294c:  7f ff f8 9d  call  0xa00e0bc0
a00e2950:  b0 16 23 88  or  %i0, 0x388, %i0	! 0x199788
a00e2954:  7f ff f2 07  call  0xa00df170
a00e2958:  81 e8 00 00  restore
a00e295c:  7f ff f7 86  call  0xa00e0774
a00e2960:  33 2a 00 97  sethi  %hi(0xa8025c00), %i1
a00e2964:  19 2a 00 97  sethi  %hi(0xa8025c00), %o4
a00e2968:  96 13 23 e8  or  %o4, 0x3e8, %o3	! 0xa8025fe8
a00e296c:  1f 2a 00 98  sethi  %hi(0xa8026000), %o7
a00e2970:  1b 2a 00 98  sethi  %hi(0xa8026000), %o5
a00e2974:  98 10 00 1b  mov  %i3, %o4
a00e2978:  90 10 00 18  mov  %i0, %o0
a00e297c:  92 13 e0 38  or  %o7, 0x38, %o1
a00e2980:  94 13 60 10  or  %o5, 0x10, %o2
a00e2984:  35 2a 00 97  sethi  %hi(0xa8025c00), %i2
a00e2988:  7f ff f7 7b  call  0xa00e0774
a00e298c:  37 2a 00 ad  sethi  %hi(0xa802b400), %i3
a00e2990:  b2 16 63 c0  or  %i1, 0x3c0, %i1
a00e2994:  b4 16 a3 98  or  %i2, 0x398, %i2
a00e2998:  7f ff f7 77  call  0xa00e0774
a00e299c:  97 ee e1 a8  restore  %i3, 0x1a8, %o3
a00e29a0:  01 00 00 00  nop
