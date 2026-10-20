# leon2m FUN_a00ae8e0 0xa00ae8e0-0xa00aea3c (348 bytes)
a00ae8e0:  9d e3 bf 90  save  %sp, -112, %sp
a00ae8e4:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00ae8e8:  94 14 62 90  or  %l1, 0x290, %o2	! 0xa802d290
a00ae8ec:  40 02 57 44  call  0xa01445fc
a00ae8f0:  d0 0a a1 a3  ldub  [ %o2 + 0x1a3 ], %o0
a00ae8f4:  92 0a 20 ff  and  %o0, 0xff, %o1
a00ae8f8:  82 02 40 09  add  %o1, %o1, %g1
a00ae8fc:  a0 00 60 04  add  %g1, 4, %l0
a00ae900:  90 10 20 00  clr  %o0
a00ae904:  92 10 20 00  clr  %o1
a00ae908:  94 10 20 00  clr  %o2
a00ae90c:  40 00 15 71  call  0xa00b3ed0
a00ae910:  96 10 20 00  clr  %o3
a00ae914:  a0 0c 20 ff  and  %l0, 0xff, %l0
a00ae918:  90 10 20 00  clr  %o0
a00ae91c:  92 10 20 00  clr  %o1
a00ae920:  94 10 27 92  mov  0x792, %o2
a00ae924:  96 10 20 03  mov  3, %o3
a00ae928:  98 10 20 0a  mov  0xa, %o4
a00ae92c:  80 a4 20 0a  cmp  %l0, 0xa
a00ae930:  02 80 00 37  be  0xa00aea0c
a00ae934:  9a 10 20 02  mov  2, %o5
a00ae938:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00ae93c:  90 10 20 00  clr  %o0
a00ae940:  92 10 20 00  clr  %o1
a00ae944:  94 10 27 92  mov  0x792, %o2
a00ae948:  96 10 20 03  mov  3, %o3
a00ae94c:  98 10 00 10  mov  %l0, %o4
a00ae950:  9a 10 20 03  mov  3, %o5
a00ae954:  40 00 12 64  call  0xa00b32e4
a00ae958:  b0 14 62 90  or  %l1, 0x290, %i0
a00ae95c:  98 10 00 10  mov  %l0, %o4
a00ae960:  94 10 27 92  mov  0x792, %o2
a00ae964:  96 10 20 12  mov  0x12, %o3
a00ae968:  92 10 20 00  clr  %o1
a00ae96c:  9a 10 20 03  mov  3, %o5
a00ae970:  90 10 20 00  clr  %o0
a00ae974:  40 00 12 5c  call  0xa00b32e4
a00ae978:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00ae97c:  40 02 57 20  call  0xa01445fc
a00ae980:  d0 0e 21 a3  ldub  [ %i0 + 0x1a3 ], %o0
a00ae984:  9a 02 20 01  add  %o0, 1, %o5
a00ae988:  40 02 57 05  call  0xa014459c
a00ae98c:  90 0b 60 03  and  %o5, 3, %o0
a00ae990:  d0 2e 21 a3  stb  %o0, [ %i0 + 0x1a3 ]
a00ae994:  40 02 57 1a  call  0xa01445fc
a00ae998:  90 0a 20 ff  and  %o0, 0xff, %o0
a00ae99c:  90 0a 20 ff  and  %o0, 0xff, %o0
a00ae9a0:  7f ff fb b3  call  0xa00ad86c
a00ae9a4:  92 10 20 01  mov  1, %o1
a00ae9a8:  40 02 54 9b  call  0xa0143c14
a00ae9ac:  90 10 20 00  clr  %o0
a00ae9b0:  98 0a 20 ff  and  %o0, 0xff, %o4
a00ae9b4:  80 a3 20 0a  cmp  %o4, 0xa
a00ae9b8:  02 80 00 08  be  0xa00ae9d8
a00ae9bc:  b0 10 20 0a  mov  0xa, %i0
a00ae9c0:  e0 04 62 90  ld  [ %l1 + 0x290 ], %l0
a00ae9c4:  1f 00 00 09  sethi  %hi(0x2400), %o7
a00ae9c8:  80 8c 22 00  btst  0x200, %l0
a00ae9cc:  92 13 e3 10  or  %o7, 0x310, %o1
a00ae9d0:  02 80 00 08  be  0xa00ae9f0
a00ae9d4:  90 10 20 0b  mov  0xb, %o0
a00ae9d8:  23 2a 00 ac  sethi  %hi(0xa802b000), %l1
a00ae9dc:  d2 0c 60 8e  ldub  [ %l1 + 0x8e ], %o1	! 0xa802b08e
a00ae9e0:  82 12 60 02  or  %o1, 2, %g1
a00ae9e4:  c2 2c 60 8e  stb  %g1, [ %l1 + 0x8e ]
a00ae9e8:  7f ff 89 6b  call  0xa0090f94
a00ae9ec:  81 e8 00 00  restore
a00ae9f0:  7f ff 5f f0  call  0xa00869b0
a00ae9f4:  23 2a 00 ac  sethi  %hi(0xa802b000), %l1
a00ae9f8:  d2 0c 60 8e  ldub  [ %l1 + 0x8e ], %o1	! 0xa802b08e
a00ae9fc:  82 12 60 02  or  %o1, 2, %g1
a00aea00:  c2 2c 60 8e  stb  %g1, [ %l1 + 0x8e ]
a00aea04:  7f ff 89 64  call  0xa0090f94
a00aea08:  81 e8 00 00  restore
a00aea0c:  40 00 12 36  call  0xa00b32e4
a00aea10:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00aea14:  96 10 20 11  mov  0x11, %o3
a00aea18:  11 00 00 0c  sethi  %hi(0x3000), %o0
a00aea1c:  d6 23 a0 5c  st  %o3, [ %sp + 0x5c ]
a00aea20:  94 12 20 92  or  %o0, 0x92, %o2
a00aea24:  90 10 20 01  mov  1, %o0
a00aea28:  92 10 20 00  clr  %o1
a00aea2c:  96 10 20 03  mov  3, %o3
a00aea30:  98 10 20 0c  mov  0xc, %o4
a00aea34:  10 bf ff c8  b  0xa00ae954
a00aea38:  9a 10 20 01  mov  1, %o5
