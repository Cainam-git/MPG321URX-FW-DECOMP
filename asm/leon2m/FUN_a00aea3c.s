# leon2m FUN_a00aea3c 0xa00aea3c-0xa00aeb98 (348 bytes)
a00aea3c:  9d e3 bf 90  save  %sp, -112, %sp
a00aea40:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00aea44:  94 14 62 90  or  %l1, 0x290, %o2	! 0xa802d290
a00aea48:  40 02 56 ed  call  0xa01445fc
a00aea4c:  d0 0a a1 a3  ldub  [ %o2 + 0x1a3 ], %o0
a00aea50:  92 0a 20 ff  and  %o0, 0xff, %o1
a00aea54:  82 02 40 09  add  %o1, %o1, %g1
a00aea58:  a0 00 60 04  add  %g1, 4, %l0
a00aea5c:  90 10 20 00  clr  %o0
a00aea60:  92 10 20 00  clr  %o1
a00aea64:  94 10 20 00  clr  %o2
a00aea68:  40 00 15 1a  call  0xa00b3ed0
a00aea6c:  96 10 20 00  clr  %o3
a00aea70:  a0 0c 20 ff  and  %l0, 0xff, %l0
a00aea74:  90 10 20 00  clr  %o0
a00aea78:  92 10 20 00  clr  %o1
a00aea7c:  94 10 27 92  mov  0x792, %o2
a00aea80:  96 10 20 03  mov  3, %o3
a00aea84:  98 10 20 0a  mov  0xa, %o4
a00aea88:  80 a4 20 0a  cmp  %l0, 0xa
a00aea8c:  02 80 00 37  be  0xa00aeb68
a00aea90:  9a 10 20 02  mov  2, %o5
a00aea94:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00aea98:  90 10 20 00  clr  %o0
a00aea9c:  92 10 20 00  clr  %o1
a00aeaa0:  94 10 27 92  mov  0x792, %o2
a00aeaa4:  96 10 20 03  mov  3, %o3
a00aeaa8:  98 10 00 10  mov  %l0, %o4
a00aeaac:  9a 10 20 03  mov  3, %o5
a00aeab0:  40 00 12 0d  call  0xa00b32e4
a00aeab4:  b0 14 62 90  or  %l1, 0x290, %i0
a00aeab8:  98 10 00 10  mov  %l0, %o4
a00aeabc:  94 10 27 92  mov  0x792, %o2
a00aeac0:  96 10 20 12  mov  0x12, %o3
a00aeac4:  92 10 20 00  clr  %o1
a00aeac8:  9a 10 20 03  mov  3, %o5
a00aeacc:  90 10 20 00  clr  %o0
a00aead0:  40 00 12 05  call  0xa00b32e4
a00aead4:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00aead8:  40 02 56 c9  call  0xa01445fc
a00aeadc:  d0 0e 21 a3  ldub  [ %i0 + 0x1a3 ], %o0
a00aeae0:  9a 02 20 03  add  %o0, 3, %o5
a00aeae4:  40 02 56 ae  call  0xa014459c
a00aeae8:  90 0b 60 03  and  %o5, 3, %o0
a00aeaec:  d0 2e 21 a3  stb  %o0, [ %i0 + 0x1a3 ]
a00aeaf0:  40 02 56 c3  call  0xa01445fc
a00aeaf4:  90 0a 20 ff  and  %o0, 0xff, %o0
a00aeaf8:  90 0a 20 ff  and  %o0, 0xff, %o0
a00aeafc:  7f ff fb 5c  call  0xa00ad86c
a00aeb00:  92 10 20 01  mov  1, %o1
a00aeb04:  40 02 54 44  call  0xa0143c14
a00aeb08:  90 10 20 00  clr  %o0
a00aeb0c:  98 0a 20 ff  and  %o0, 0xff, %o4
a00aeb10:  80 a3 20 0a  cmp  %o4, 0xa
a00aeb14:  02 80 00 08  be  0xa00aeb34
a00aeb18:  b0 10 20 0a  mov  0xa, %i0
a00aeb1c:  e0 04 62 90  ld  [ %l1 + 0x290 ], %l0
a00aeb20:  1f 00 00 09  sethi  %hi(0x2400), %o7
a00aeb24:  80 8c 22 00  btst  0x200, %l0
a00aeb28:  92 13 e3 10  or  %o7, 0x310, %o1
a00aeb2c:  02 80 00 08  be  0xa00aeb4c
a00aeb30:  90 10 20 0b  mov  0xb, %o0
a00aeb34:  23 2a 00 ac  sethi  %hi(0xa802b000), %l1
a00aeb38:  d2 0c 60 8e  ldub  [ %l1 + 0x8e ], %o1	! 0xa802b08e
a00aeb3c:  82 12 60 02  or  %o1, 2, %g1
a00aeb40:  c2 2c 60 8e  stb  %g1, [ %l1 + 0x8e ]
a00aeb44:  7f ff 89 14  call  0xa0090f94
a00aeb48:  81 e8 00 00  restore
a00aeb4c:  7f ff 5f 99  call  0xa00869b0
a00aeb50:  23 2a 00 ac  sethi  %hi(0xa802b000), %l1
a00aeb54:  d2 0c 60 8e  ldub  [ %l1 + 0x8e ], %o1	! 0xa802b08e
a00aeb58:  82 12 60 02  or  %o1, 2, %g1
a00aeb5c:  c2 2c 60 8e  stb  %g1, [ %l1 + 0x8e ]
a00aeb60:  7f ff 89 0d  call  0xa0090f94
a00aeb64:  81 e8 00 00  restore
a00aeb68:  40 00 11 df  call  0xa00b32e4
a00aeb6c:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00aeb70:  96 10 20 11  mov  0x11, %o3
a00aeb74:  11 00 00 0c  sethi  %hi(0x3000), %o0
a00aeb78:  d6 23 a0 5c  st  %o3, [ %sp + 0x5c ]
a00aeb7c:  94 12 20 92  or  %o0, 0x92, %o2
a00aeb80:  90 10 20 01  mov  1, %o0
a00aeb84:  92 10 20 00  clr  %o1
a00aeb88:  96 10 20 03  mov  3, %o3
a00aeb8c:  98 10 20 0c  mov  0xc, %o4
a00aeb90:  10 bf ff c8  b  0xa00aeab0
a00aeb94:  9a 10 20 01  mov  1, %o5
