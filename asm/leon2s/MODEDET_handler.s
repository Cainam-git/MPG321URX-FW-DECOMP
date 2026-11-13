# leon2s MODEDET_handler 0xa009c8b0-0xa009c9b4 (260 bytes)  [FUN_a009c9ac = unreachable ret/restore tail, merged]
a009c8b0:  9d e3 bf 98  save  %sp, -104, %sp
a009c8b4:  a0 10 00 18  mov  %i0, %l0
a009c8b8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a009c8bc:  80 a6 20 00  cmp  %i0, 0
a009c8c0:  02 80 00 05  be  0xa009c8d4
a009c8c4:  96 10 20 02  mov  2, %o3
a009c8c8:  80 a6 20 01  cmp  %i0, 1
a009c8cc:  12 80 00 37  bne  0xa009c9a8
a009c8d0:  96 10 20 03  mov  3, %o3
a009c8d4:  82 06 00 18  add  %i0, %i0, %g1
a009c8d8:  82 00 40 18  add  %g1, %i0, %g1
a009c8dc:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a009c8e0:  94 13 62 50  or  %o5, 0x250, %o2	! 0xa807d650
a009c8e4:  99 28 60 03  sll  %g1, 3, %o4
a009c8e8:  c2 02 80 0c  ld  [ %o2 + %o4 ], %g1
a009c8ec:  80 a0 60 00  cmp  %g1, 0
a009c8f0:  02 80 00 2e  be  0xa009c9a8
a009c8f4:  9a 0a e0 ff  and  %o3, 0xff, %o5
a009c8f8:  82 03 40 0d  add  %o5, %o5, %g1
a009c8fc:  82 00 40 0d  add  %g1, %o5, %g1
a009c900:  1b 2a 01 f3  sethi  %hi(0xa807cc00), %o5
a009c904:  83 28 60 03  sll  %g1, 3, %g1
a009c908:  9a 13 60 64  or  %o5, 0x64, %o5
a009c90c:  82 00 40 0d  add  %g1, %o5, %g1
a009c910:  c2 08 60 01  ldub  [ %g1 + 1 ], %g1
a009c914:  80 a0 60 01  cmp  %g1, 1
a009c918:  02 80 00 24  be  0xa009c9a8
a009c91c:  23 2a 01 e1  sethi  %hi(0xa8078400), %l1
a009c920:  c2 04 62 34  ld  [ %l1 + 0x234 ], %g1	! 0xa8078634
a009c924:  80 88 60 04  btst  4, %g1
a009c928:  02 80 00 08  be  0xa009c948
a009c92c:  c0 22 80 0c  clr  [ %o2 + %o4 ]
a009c930:  92 04 20 41  add  %l0, 0x41, %o1
a009c934:  93 2a 60 18  sll  %o1, 0x18, %o1
a009c938:  11 28 01 a9  sethi  %hi(0xa006a400), %o0
a009c93c:  90 12 23 00  or  %o0, 0x300, %o0	! 0xa006a700
a009c940:  7f ff 59 c1  call  0xa0073044
a009c944:  93 3a 60 18  sra  %o1, 0x18, %o1
a009c948:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a009c94c:  82 5e 21 90  smul  %i0, 0x190, %g1
a009c950:  9a 13 63 e0  or  %o5, 0x3e0, %o5
a009c954:  82 00 40 0d  add  %g1, %o5, %g1
a009c958:  c2 08 60 01  ldub  [ %g1 + 1 ], %g1
a009c95c:  80 a0 60 00  cmp  %g1, 0
a009c960:  02 80 00 10  be  0xa009c9a0
a009c964:  90 10 00 18  mov  %i0, %o0
a009c968:  40 00 10 6a  call  0xa00a0b10
a009c96c:  92 10 20 00  clr  %o1
a009c970:  90 10 00 18  mov  %i0, %o0
a009c974:  7f ff e6 74  call  0xa0096344
a009c978:  92 10 20 00  clr  %o1
a009c97c:  c2 04 62 34  ld  [ %l1 + 0x234 ], %g1
a009c980:  80 88 60 04  btst  4, %g1
a009c984:  02 80 00 07  be  0xa009c9a0
a009c988:  92 04 20 41  add  %l0, 0x41, %o1
a009c98c:  93 2a 60 18  sll  %o1, 0x18, %o1
a009c990:  11 28 01 a9  sethi  %hi(0xa006a400), %o0
a009c994:  90 12 23 38  or  %o0, 0x338, %o0	! 0xa006a738
a009c998:  7f ff 59 ab  call  0xa0073044
a009c99c:  93 3a 60 18  sra  %o1, 0x18, %o1
a009c9a0:  7f ff ff b7  call  0xa009c87c
a009c9a4:  81 e8 00 00  restore
a009c9a8:  01 00 00 00  nop
a009c9ac:  81 c7 e0 08  ret
a009c9b0:  81 e8 00 00  restore
