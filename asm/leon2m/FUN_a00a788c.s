# leon2m FUN_a00a788c 0xa00a788c-0xa00a7adc (592 bytes)
a00a788c:  9d e3 bf 90  save  %sp, -112, %sp
a00a7890:  96 0e 20 ff  and  %i0, 0xff, %o3
a00a7894:  90 1a e0 01  xor  %o3, 1, %o0
a00a7898:  80 a0 00 08  cmp  %g0, %o0
a00a789c:  98 60 3f ff  subx  %g0, -1, %o4
a00a78a0:  82 1a e0 07  xor  %o3, 7, %g1
a00a78a4:  80 a0 00 01  cmp  %g0, %g1
a00a78a8:  9a 60 3f ff  subx  %g0, -1, %o5
a00a78ac:  80 93 00 0d  orcc  %o4, %o5, %g0
a00a78b0:  12 80 00 0c  bne  0xa00a78e0
a00a78b4:  80 a2 e0 01  cmp  %o3, 1
a00a78b8:  a0 1a e0 08  xor  %o3, 8, %l0
a00a78bc:  80 a0 00 10  cmp  %g0, %l0
a00a78c0:  94 60 3f ff  subx  %g0, -1, %o2
a00a78c4:  9e 1a e0 0a  xor  %o3, 0xa, %o7
a00a78c8:  80 a0 00 0f  cmp  %g0, %o7
a00a78cc:  92 60 3f ff  subx  %g0, -1, %o1
a00a78d0:  80 92 80 09  orcc  %o2, %o1, %g0
a00a78d4:  02 80 00 26  be  0xa00a796c
a00a78d8:  94 06 3f fe  add  %i0, -2, %o2
a00a78dc:  80 a2 e0 01  cmp  %o3, 1
a00a78e0:  17 00 00 0e  sethi  %hi(0x3800), %o3
a00a78e4:  a4 12 e1 9a  or  %o3, 0x19a, %l2	! 0x399a
a00a78e8:  a0 10 20 07  mov  7, %l0
a00a78ec:  02 80 00 3f  be  0xa00a79e8
a00a78f0:  a2 10 20 0e  mov  0xe, %l1
a00a78f4:  b0 0c 20 ff  and  %l0, 0xff, %i0
a00a78f8:  90 10 00 18  mov  %i0, %o0
a00a78fc:  92 10 20 08  mov  8, %o1
a00a7900:  94 10 20 01  mov  1, %o2
a00a7904:  96 10 27 92  mov  0x792, %o3
a00a7908:  40 02 7c 5e  call  0xa0146a80
a00a790c:  98 10 20 00  clr  %o4
a00a7910:  a2 0c 60 ff  and  %l1, 0xff, %l1
a00a7914:  90 10 00 11  mov  %l1, %o0
a00a7918:  92 10 20 08  mov  8, %o1
a00a791c:  94 10 20 01  mov  1, %o2
a00a7920:  96 10 27 92  mov  0x792, %o3
a00a7924:  40 02 7c 57  call  0xa0146a80
a00a7928:  98 10 20 00  clr  %o4
a00a792c:  92 10 00 18  mov  %i0, %o1
a00a7930:  90 10 20 00  clr  %o0
a00a7934:  94 10 20 08  mov  8, %o2
a00a7938:  96 10 20 01  mov  1, %o3
a00a793c:  98 10 20 1a  mov  0x1a, %o4
a00a7940:  40 02 7c 78  call  0xa0146b20
a00a7944:  9a 10 20 00  clr  %o5
a00a7948:  92 10 00 11  mov  %l1, %o1
a00a794c:  90 10 20 00  clr  %o0
a00a7950:  94 10 20 08  mov  8, %o2
a00a7954:  96 10 20 01  mov  1, %o3
a00a7958:  98 10 20 1b  mov  0x1b, %o4
a00a795c:  40 02 7c 71  call  0xa0146b20
a00a7960:  9a 10 20 00  clr  %o5
a00a7964:  10 80 00 25  b  0xa00a79f8
a00a7968:  99 2c a0 10  sll  %l2, 0x10, %o4
a00a796c:  92 0a a0 ff  and  %o2, 0xff, %o1
a00a7970:  80 a2 60 03  cmp  %o1, 3
a00a7974:  90 60 20 00  subx  %g0, 0, %o0
a00a7978:  82 1a e0 09  xor  %o3, 9, %g1
a00a797c:  80 a0 00 01  cmp  %g0, %g1
a00a7980:  a4 60 3f ff  subx  %g0, -1, %l2
a00a7984:  98 0a 20 01  and  %o0, 1, %o4
a00a7988:  80 93 00 12  orcc  %o4, %l2, %g0
a00a798c:  1b 00 00 0f  sethi  %hi(0x3c00), %o5
a00a7990:  02 80 00 19  be  0xa00a79f4
a00a7994:  a4 13 62 9a  or  %o5, 0x29a, %l2	! 0x3e9a
a00a7998:  a0 10 20 16  mov  0x16, %l0
a00a799c:  e0 23 a0 5c  st  %l0, [ %sp + 0x5c ]
a00a79a0:  90 10 20 01  mov  1, %o0
a00a79a4:  92 10 20 01  mov  1, %o1
a00a79a8:  94 10 27 92  mov  0x792, %o2
a00a79ac:  96 10 20 0a  mov  0xa, %o3
a00a79b0:  98 10 20 03  mov  3, %o4
a00a79b4:  40 00 2e 4c  call  0xa00b32e4
a00a79b8:  9a 10 20 02  mov  2, %o5
a00a79bc:  9e 10 20 18  mov  0x18, %o7
a00a79c0:  de 23 a0 5c  st  %o7, [ %sp + 0x5c ]
a00a79c4:  90 10 20 01  mov  1, %o0
a00a79c8:  92 10 20 01  mov  1, %o1
a00a79cc:  94 10 27 92  mov  0x792, %o2
a00a79d0:  96 10 20 0a  mov  0xa, %o3
a00a79d4:  98 10 20 0d  mov  0xd, %o4
a00a79d8:  40 00 2e 43  call  0xa00b32e4
a00a79dc:  9a 10 20 02  mov  2, %o5
a00a79e0:  10 80 00 06  b  0xa00a79f8
a00a79e4:  99 2c a0 10  sll  %l2, 0x10, %o4
a00a79e8:  a0 10 20 03  mov  3, %l0
a00a79ec:  10 bf ff c2  b  0xa00a78f4
a00a79f0:  a2 10 20 12  mov  0x12, %l1
a00a79f4:  99 2c a0 10  sll  %l2, 0x10, %o4
a00a79f8:  a3 33 20 10  srl  %o4, 0x10, %l1
a00a79fc:  a0 10 20 75  mov  0x75, %l0
a00a7a00:  90 10 20 01  mov  1, %o0
a00a7a04:  92 10 20 00  clr  %o1
a00a7a08:  94 10 00 11  mov  %l1, %o2
a00a7a0c:  96 10 20 04  mov  4, %o3
a00a7a10:  98 10 20 0e  mov  0xe, %o4
a00a7a14:  9a 10 20 01  mov  1, %o5
a00a7a18:  40 00 2e 33  call  0xa00b32e4
a00a7a1c:  e0 23 a0 5c  st  %l0, [ %sp + 0x5c ]
a00a7a20:  31 00 00 12  sethi  %hi(0x4800), %i0
a00a7a24:  90 10 20 01  mov  1, %o0
a00a7a28:  92 10 20 00  clr  %o1
a00a7a2c:  94 16 20 9a  or  %i0, 0x9a, %o2
a00a7a30:  96 10 20 0d  mov  0xd, %o3
a00a7a34:  98 10 20 0e  mov  0xe, %o4
a00a7a38:  9a 10 20 01  mov  1, %o5
a00a7a3c:  40 00 2e 2a  call  0xa00b32e4
a00a7a40:  e0 23 a0 5c  st  %l0, [ %sp + 0x5c ]
a00a7a44:  a4 10 20 76  mov  0x76, %l2
a00a7a48:  90 10 20 01  mov  1, %o0
a00a7a4c:  92 10 20 01  mov  1, %o1
a00a7a50:  94 10 00 11  mov  %l1, %o2
a00a7a54:  96 10 20 03  mov  3, %o3
a00a7a58:  98 10 20 0f  mov  0xf, %o4
a00a7a5c:  9a 10 20 03  mov  3, %o5
a00a7a60:  40 00 2e 21  call  0xa00b32e4
a00a7a64:  e4 23 a0 5c  st  %l2, [ %sp + 0x5c ]
a00a7a68:  90 10 20 01  mov  1, %o0
a00a7a6c:  92 10 20 01  mov  1, %o1
a00a7a70:  94 16 20 9a  or  %i0, 0x9a, %o2
a00a7a74:  96 10 20 0c  mov  0xc, %o3
a00a7a78:  98 10 20 0f  mov  0xf, %o4
a00a7a7c:  9a 10 20 03  mov  3, %o5
a00a7a80:  40 00 2e 19  call  0xa00b32e4
a00a7a84:  e4 23 a0 5c  st  %l2, [ %sp + 0x5c ]
a00a7a88:  9a 10 20 79  mov  0x79, %o5
a00a7a8c:  da 23 a0 5c  st  %o5, [ %sp + 0x5c ]
a00a7a90:  94 10 00 11  mov  %l1, %o2
a00a7a94:  90 10 20 01  mov  1, %o0
a00a7a98:  92 10 20 00  clr  %o1
a00a7a9c:  96 10 20 04  mov  4, %o3
a00a7aa0:  98 10 20 10  mov  0x10, %o4
a00a7aa4:  40 00 2e 10  call  0xa00b32e4
a00a7aa8:  9a 10 20 01  mov  1, %o5
a00a7aac:  96 10 20 7a  mov  0x7a, %o3
a00a7ab0:  d6 23 a0 5c  st  %o3, [ %sp + 0x5c ]
a00a7ab4:  94 16 20 9a  or  %i0, 0x9a, %o2
a00a7ab8:  90 10 20 01  mov  1, %o0
a00a7abc:  92 10 20 00  clr  %o1
a00a7ac0:  96 10 20 0d  mov  0xd, %o3
a00a7ac4:  98 10 20 10  mov  0x10, %o4
a00a7ac8:  40 00 2e 07  call  0xa00b32e4
a00a7acc:  9a 10 20 01  mov  1, %o5
a00a7ad0:  01 00 00 00  nop
a00a7ad4:  81 c7 e0 08  ret
a00a7ad8:  81 e8 00 00  restore
