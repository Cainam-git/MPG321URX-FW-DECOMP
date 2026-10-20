# leon2m FUN_a00cae64 0xa00cae64-0xa00caf0c (168 bytes)
a00cae64:  9d e3 bf 98  save  %sp, -104, %sp
a00cae68:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00cae6c:  80 a4 20 02  cmp  %l0, 2
a00cae70:  02 80 00 1f  be  0xa00caeec
a00cae74:  80 a4 20 03  cmp  %l0, 3
a00cae78:  02 80 00 20  be  0xa00caef8
a00cae7c:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00cae80:  da 0a 60 d9  ldub  [ %o1 + 0xd9 ], %o5	! 0xa802d0d9
a00cae84:  9e 0b 60 ff  and  %o5, 0xff, %o7
a00cae88:  98 03 ff d0  add  %o7, -48, %o4
a00cae8c:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00cae90:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00cae94:  96 16 22 90  or  %i0, 0x290, %o3	! 0xa802d290
a00cae98:  94 0b 60 01  and  %o5, 1, %o2
a00cae9c:  99 2a a0 0f  sll  %o2, 0xf, %o4
a00caea0:  80 a3 60 01  cmp  %o5, 1
a00caea4:  18 80 00 18  bgu  0xa00caf04
a00caea8:  b0 10 20 ff  mov  0xff, %i0
a00caeac:  da 02 e1 dc  ld  [ %o3 + 0x1dc ], %o5
a00caeb0:  13 00 00 20  sethi  %hi(0x8000), %o1
a00caeb4:  90 2b 40 09  andn  %o5, %o1, %o0
a00caeb8:  82 12 00 0c  or  %o0, %o4, %g1
a00caebc:  40 00 3f 19  call  0xa00dab20
a00caec0:  c2 22 e1 dc  st  %g1, [ %o3 + 0x1dc ]
a00caec4:  7f ff b6 82  call  0xa00b88cc
a00caec8:  b0 10 20 00  clr  %i0
a00caecc:  7f ff be e8  call  0xa00baa6c
a00caed0:  90 10 00 10  mov  %l0, %o0
a00caed4:  7f ff be 9f  call  0xa00ba950
a00caed8:  90 10 00 10  mov  %l0, %o0
a00caedc:  90 10 00 10  mov  %l0, %o0
a00caee0:  7f ff bf 28  call  0xa00bab80
a00caee4:  92 10 20 06  mov  6, %o1
a00caee8:  30 80 00 07  b,a   0xa00caf04
a00caeec:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00caef0:  10 bf ff e5  b  0xa00cae84
a00caef4:  da 08 60 49  ldub  [ %g1 + 0x49 ], %o5	! 0xa802d049
a00caef8:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00caefc:  10 bf ff e2  b  0xa00cae84
a00caf00:  da 0a 20 a1  ldub  [ %o0 + 0xa1 ], %o5	! 0xa802d0a1
a00caf04:  81 c7 e0 08  ret
a00caf08:  81 e8 00 00  restore
