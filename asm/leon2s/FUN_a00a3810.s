# leon2s FUN_a00a3810 0xa00a3810-0xa00a3a10 (512 bytes)
a00a3810:  9d e3 bf 98  save  %sp, -104, %sp
a00a3814:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00a3818:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a381c:  27 2a 01 f6  sethi  %hi(0xa807d800), %l3
a00a3820:  a1 2e 20 02  sll  %i0, 2, %l0
a00a3824:  a4 10 63 3c  or  %g1, 0x33c, %l2
a00a3828:  a2 14 e3 6c  or  %l3, 0x36c, %l1
a00a382c:  da 04 40 10  ld  [ %l1 + %l0 ], %o5
a00a3830:  c2 04 80 10  ld  [ %l2 + %l0 ], %g1
a00a3834:  80 a3 40 01  cmp  %o5, %g1
a00a3838:  02 80 00 09  be  0xa00a385c
a00a383c:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a3840:  11 28 01 ae  sethi  %hi(0xa006b800), %o0
a00a3844:  90 12 23 08  or  %o0, 0x308, %o0	! 0xa006bb08
a00a3848:  7f ff 3d ff  call  0xa0073044
a00a384c:  92 10 00 18  mov  %i0, %o1
a00a3850:  c2 04 40 10  ld  [ %l1 + %l0 ], %g1
a00a3854:  c2 24 80 10  st  %g1, [ %l2 + %l0 ]
a00a3858:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a385c:  a4 10 61 d0  or  %g1, 0x1d0, %l2	! 0xa80791d0
a00a3860:  92 10 20 01  mov  1, %o1
a00a3864:  7f ff b9 40  call  0xa0091d64
a00a3868:  90 10 00 18  mov  %i0, %o0
a00a386c:  d0 2c 80 18  stb  %o0, [ %l2 + %i0 ]
a00a3870:  7f ff b8 3c  call  0xa0091960
a00a3874:  90 10 00 18  mov  %i0, %o0
a00a3878:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a387c:  80 a2 20 01  cmp  %o0, 1
a00a3880:  12 80 00 54  bne  0xa00a39d0
a00a3884:  82 10 20 06  mov  6, %g1
a00a3888:  1b 2a 01 e4  sethi  %hi(0xa8079000), %o5
a00a388c:  c2 0b 61 b2  ldub  [ %o5 + 0x1b2 ], %g1	! 0xa80791b2
a00a3890:  80 a0 60 00  cmp  %g1, 0
a00a3894:  02 80 00 16  be  0xa00a38ec
a00a3898:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a389c:  82 10 61 d8  or  %g1, 0x1d8, %g1	! 0xa80791d8
a00a38a0:  c2 08 40 18  ldub  [ %g1 + %i0 ], %g1
a00a38a4:  80 a0 60 00  cmp  %g1, 0
a00a38a8:  02 80 00 0d  be  0xa00a38dc
a00a38ac:  c2 0b 61 b2  ldub  [ %o5 + 0x1b2 ], %g1
a00a38b0:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a38b4:  82 10 61 e0  or  %g1, 0x1e0, %g1	! 0xa80791e0
a00a38b8:  c2 08 40 18  ldub  [ %g1 + %i0 ], %g1
a00a38bc:  80 a0 60 01  cmp  %g1, 1
a00a38c0:  12 80 00 07  bne  0xa00a38dc
a00a38c4:  c2 0b 61 b2  ldub  [ %o5 + 0x1b2 ], %g1
a00a38c8:  c2 0c 80 18  ldub  [ %l2 + %i0 ], %g1
a00a38cc:  80 a0 60 00  cmp  %g1, 0
a00a38d0:  12 80 00 07  bne  0xa00a38ec
a00a38d4:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a38d8:  c2 0b 61 b2  ldub  [ %o5 + 0x1b2 ], %g1
a00a38dc:  80 a0 60 00  cmp  %g1, 0
a00a38e0:  12 80 00 36  bne  0xa00a39b8
a00a38e4:  98 14 e3 6c  or  %l3, 0x36c, %o4
a00a38e8:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a38ec:  82 10 61 d8  or  %g1, 0x1d8, %g1	! 0xa80791d8
a00a38f0:  d4 08 40 18  ldub  [ %g1 + %i0 ], %o2
a00a38f4:  96 0a a0 ff  and  %o2, 0xff, %o3
a00a38f8:  80 a2 e0 06  cmp  %o3, 6
a00a38fc:  18 80 00 0e  bgu  0xa00a3934
a00a3900:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a3904:  9b 2e 20 03  sll  %i0, 3, %o5
a00a3908:  9a 23 40 18  sub  %o5, %i0, %o5
a00a390c:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a00a3910:  82 10 61 80  or  %g1, 0x180, %g1	! 0xa807d580
a00a3914:  9b 2b 60 02  sll  %o5, 2, %o5
a00a3918:  9a 03 40 01  add  %o5, %g1, %o5
a00a391c:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a3920:  99 2e 20 02  sll  %i0, 2, %o4
a00a3924:  82 10 61 fc  or  %g1, 0x1fc, %g1
a00a3928:  d6 20 40 0c  st  %o3, [ %g1 + %o4 ]
a00a392c:  d4 2b 60 12  stb  %o2, [ %o5 + 0x12 ]
a00a3930:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a3934:  c2 08 61 b2  ldub  [ %g1 + 0x1b2 ], %g1	! 0xa80791b2
a00a3938:  80 a0 60 00  cmp  %g1, 0
a00a393c:  12 80 00 12  bne  0xa00a3984
a00a3940:  21 2a 01 e4  sethi  %hi(0xa8079000), %l0
a00a3944:  80 a2 e0 00  cmp  %o3, 0
a00a3948:  12 80 00 10  bne  0xa00a3988
a00a394c:  a3 2e 20 02  sll  %i0, 2, %l1
a00a3950:  9b 2e 20 03  sll  %i0, 3, %o5
a00a3954:  9a 23 40 18  sub  %o5, %i0, %o5
a00a3958:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a00a395c:  82 10 61 80  or  %g1, 0x180, %g1	! 0xa807d580
a00a3960:  9b 2b 60 02  sll  %o5, 2, %o5
a00a3964:  9a 03 40 01  add  %o5, %g1, %o5
a00a3968:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a396c:  96 10 20 05  mov  5, %o3
a00a3970:  99 2e 20 02  sll  %i0, 2, %o4
a00a3974:  82 10 61 fc  or  %g1, 0x1fc, %g1
a00a3978:  d6 20 40 0c  st  %o3, [ %g1 + %o4 ]
a00a397c:  d6 2b 60 12  stb  %o3, [ %o5 + 0x12 ]
a00a3980:  21 2a 01 e4  sethi  %hi(0xa8079000), %l0
a00a3984:  a3 2e 20 02  sll  %i0, 2, %l1
a00a3988:  a0 14 21 fc  or  %l0, 0x1fc, %l0
a00a398c:  d2 04 00 11  ld  [ %l0 + %l1 ], %o1
a00a3990:  90 10 00 18  mov  %i0, %o0
a00a3994:  7f ff b7 e1  call  0xa0091918
a00a3998:  92 0a 60 ff  and  %o1, 0xff, %o1
a00a399c:  d0 04 00 11  ld  [ %l0 + %l1 ], %o0
a00a39a0:  7f ff c5 84  call  0xa0094fb0
a00a39a4:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a39a8:  9a 14 e3 6c  or  %l3, 0x36c, %o5
a00a39ac:  82 10 20 02  mov  2, %g1
a00a39b0:  10 80 00 16  b  0xa00a3a08
a00a39b4:  c2 23 40 11  st  %g1, [ %o5 + %l1 ]
a00a39b8:  9b 2e 20 02  sll  %i0, 2, %o5
a00a39bc:  82 10 20 06  mov  6, %g1
a00a39c0:  c2 23 00 0d  st  %g1, [ %o4 + %o5 ]
a00a39c4:  7f ff b7 f1  call  0xa0091988
a00a39c8:  90 10 00 18  mov  %i0, %o0
a00a39cc:  30 80 00 02  b,a   0xa00a39d4
a00a39d0:  c2 24 40 10  st  %g1, [ %l1 + %l0 ]
a00a39d4:  7f ff b8 68  call  0xa0091b74
a00a39d8:  90 10 00 18  mov  %i0, %o0
a00a39dc:  9b 2e 20 03  sll  %i0, 3, %o5
a00a39e0:  9a 23 40 18  sub  %o5, %i0, %o5
a00a39e4:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a00a39e8:  82 10 61 80  or  %g1, 0x180, %g1	! 0xa807d580
a00a39ec:  9b 2b 60 02  sll  %o5, 2, %o5
a00a39f0:  9a 03 40 01  add  %o5, %g1, %o5
a00a39f4:  c2 03 60 14  ld  [ %o5 + 0x14 ], %g1
a00a39f8:  82 08 77 ff  and  %g1, -2049, %g1
a00a39fc:  19 00 00 04  sethi  %hi(0x1000), %o4
a00a3a00:  82 10 40 0c  or  %g1, %o4, %g1
a00a3a04:  c2 23 60 14  st  %g1, [ %o5 + 0x14 ]
a00a3a08:  81 c7 e0 08  ret
a00a3a0c:  91 e8 20 00  restore  %g0, 0, %o0
