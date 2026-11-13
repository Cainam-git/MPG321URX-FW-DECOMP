# leon2m FUN_a00aad30 0xa00aad30-0xa00aaf48 (536 bytes)
a00aad30:  9d e3 bf 98  save  %sp, -104, %sp
a00aad34:  23 2a 00 ac  sethi  %hi(0xa802b000), %l1
a00aad38:  c2 0c 60 8f  ldub  [ %l1 + 0x8f ], %g1	! 0xa802b08f
a00aad3c:  80 a0 60 0c  cmp  %g1, 0xc
a00aad40:  02 80 00 44  be  0xa00aae50
a00aad44:  a4 10 00 18  mov  %i0, %l2
a00aad48:  d4 0c 60 8f  ldub  [ %l1 + 0x8f ], %o2
a00aad4c:  80 a2 a0 0e  cmp  %o2, 0xe
a00aad50:  02 80 00 18  be  0xa00aadb0
a00aad54:  82 0c a0 ff  and  %l2, 0xff, %g1
a00aad58:  f0 0c 60 8f  ldub  [ %l1 + 0x8f ], %i0
a00aad5c:  80 a6 20 0f  cmp  %i0, 0xf
a00aad60:  02 80 00 24  be  0xa00aadf0
a00aad64:  82 04 bf fd  add  %l2, -3, %g1
a00aad68:  d4 0c 60 8f  ldub  [ %l1 + 0x8f ], %o2
a00aad6c:  80 a2 a0 10  cmp  %o2, 0x10
a00aad70:  02 80 00 04  be  0xa00aad80
a00aad74:  9a 04 bf fb  add  %l2, -5, %o5
a00aad78:  10 80 00 72  b  0xa00aaf40
a00aad7c:  b0 10 20 01  mov  1, %i0
a00aad80:  a2 0b 60 ff  and  %o5, 0xff, %l1
a00aad84:  80 a4 60 01  cmp  %l1, 1
a00aad88:  38 80 00 6e  bgu,a   0xa00aaf40
a00aad8c:  b0 10 20 01  mov  1, %i0
a00aad90:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00aad94:  98 16 22 90  or  %i0, 0x290, %o4	! 0xa802d290
a00aad98:  e4 0b 20 20  ldub  [ %o4 + 0x20 ], %l2
a00aad9c:  d6 0b 20 1e  ldub  [ %o4 + 0x1e ], %o3
a00aada0:  80 a2 c0 12  cmp  %o3, %l2
a00aada4:  12 bf ff f5  bne  0xa00aad78
a00aada8:  b0 10 20 00  clr  %i0
a00aadac:  30 80 00 65  b,a   0xa00aaf40
a00aadb0:  80 a0 60 04  cmp  %g1, 4
a00aadb4:  02 80 00 3d  be  0xa00aaea8
a00aadb8:  80 a0 60 03  cmp  %g1, 3
a00aadbc:  02 80 00 19  be  0xa00aae20
a00aadc0:  80 a0 60 05  cmp  %g1, 5
a00aadc4:  02 80 00 5a  be  0xa00aaf2c
a00aadc8:  80 a0 60 06  cmp  %g1, 6
a00aadcc:  12 bf ff e4  bne  0xa00aad5c
a00aadd0:  f0 0c 60 8f  ldub  [ %l1 + 0x8f ], %i0
a00aadd4:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00aadd8:  d6 0b 22 af  ldub  [ %o4 + 0x2af ], %o3	! 0xa802d2af
a00aaddc:  80 a2 e0 00  cmp  %o3, 0
a00aade0:  12 80 00 58  bne  0xa00aaf40
a00aade4:  b0 10 20 00  clr  %i0
a00aade8:  10 bf ff dd  b  0xa00aad5c
a00aadec:  f0 0c 60 8f  ldub  [ %l1 + 0x8f ], %i0
a00aadf0:  9e 08 60 ff  and  %g1, 0xff, %o7
a00aadf4:  80 a3 e0 01  cmp  %o7, 1
a00aadf8:  18 bf ff dd  bgu  0xa00aad6c
a00aadfc:  d4 0c 60 8f  ldub  [ %l1 + 0x8f ], %o2
a00aae00:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00aae04:  90 12 62 90  or  %o1, 0x290, %o0	! 0xa802d290
a00aae08:  e0 0a 20 20  ldub  [ %o0 + 0x20 ], %l0
a00aae0c:  e6 0a 20 1e  ldub  [ %o0 + 0x1e ], %l3
a00aae10:  80 a4 c0 10  cmp  %l3, %l0
a00aae14:  12 bf ff d6  bne  0xa00aad6c
a00aae18:  b0 10 20 00  clr  %i0
a00aae1c:  30 80 00 49  b,a   0xa00aaf40
a00aae20:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00aae24:  82 12 22 90  or  %o0, 0x290, %g1	! 0xa802d290
a00aae28:  e6 08 60 1f  ldub  [ %g1 + 0x1f ], %l3
a00aae2c:  80 a4 e0 00  cmp  %l3, 0
a00aae30:  12 80 00 44  bne  0xa00aaf40
a00aae34:  b0 10 20 00  clr  %i0
a00aae38:  d2 00 61 f4  ld  [ %g1 + 0x1f4 ], %o1
a00aae3c:  80 a2 60 00  cmp  %o1, 0
a00aae40:  06 80 00 40  bl  0xa00aaf40
a00aae44:  01 00 00 00  nop
a00aae48:  10 bf ff c5  b  0xa00aad5c
a00aae4c:  f0 0c 60 8f  ldub  [ %l1 + 0x8f ], %i0
a00aae50:  90 10 20 04  mov  4, %o0
a00aae54:  40 00 2f 4d  call  0xa00b6b88
a00aae58:  92 10 20 00  clr  %o1
a00aae5c:  90 0a 20 ff  and  %o0, 0xff, %o0
a00aae60:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00aae64:  80 a2 00 10  cmp  %o0, %l0
a00aae68:  18 bf ff b9  bgu  0xa00aad4c
a00aae6c:  d4 0c 60 8f  ldub  [ %l1 + 0x8f ], %o2
a00aae70:  92 10 20 00  clr  %o1
a00aae74:  40 00 2f 45  call  0xa00b6b88
a00aae78:  90 10 20 06  mov  6, %o0
a00aae7c:  92 0a 20 ff  and  %o0, 0xff, %o1
a00aae80:  80 a2 40 10  cmp  %o1, %l0
a00aae84:  0a bf ff b2  bcs  0xa00aad4c
a00aae88:  d4 0c 60 8f  ldub  [ %l1 + 0x8f ], %o2
a00aae8c:  40 00 b3 af  call  0xa00d7d48
a00aae90:  b0 10 20 00  clr  %i0
a00aae94:  80 a2 20 00  cmp  %o0, 0
a00aae98:  12 80 00 2a  bne  0xa00aaf40
a00aae9c:  d4 0c 60 8f  ldub  [ %l1 + 0x8f ], %o2
a00aaea0:  10 bf ff ac  b  0xa00aad50
a00aaea4:  80 a2 a0 0e  cmp  %o2, 0xe
a00aaea8:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00aaeac:  a6 12 e2 90  or  %o3, 0x290, %l3	! 0xa802d290
a00aaeb0:  da 0c e0 1f  ldub  [ %l3 + 0x1f ], %o5
a00aaeb4:  80 a3 60 00  cmp  %o5, 0
a00aaeb8:  12 80 00 22  bne  0xa00aaf40
a00aaebc:  b0 10 20 00  clr  %i0
a00aaec0:  92 10 20 07  mov  7, %o1
a00aaec4:  40 02 69 e7  call  0xa0145660
a00aaec8:  90 10 20 00  clr  %o0
a00aaecc:  b0 10 00 08  mov  %o0, %i0
a00aaed0:  40 02 75 2b  call  0xa014837c
a00aaed4:  90 10 20 00  clr  %o0
a00aaed8:  a1 2e 20 10  sll  %i0, 0x10, %l0
a00aaedc:  99 2a 20 10  sll  %o0, 0x10, %o4
a00aaee0:  80 a3 00 10  cmp  %o4, %l0
a00aaee4:  12 bf ff 9e  bne  0xa00aad5c
a00aaee8:  f0 0c 60 8f  ldub  [ %l1 + 0x8f ], %i0
a00aaeec:  92 10 20 08  mov  8, %o1
a00aaef0:  40 02 69 dc  call  0xa0145660
a00aaef4:  90 10 20 00  clr  %o0
a00aaef8:  a0 10 00 08  mov  %o0, %l0
a00aaefc:  40 02 75 20  call  0xa014837c
a00aaf00:  90 10 20 01  mov  1, %o0
a00aaf04:  9f 2c 20 10  sll  %l0, 0x10, %o7
a00aaf08:  83 2a 20 10  sll  %o0, 0x10, %g1
a00aaf0c:  80 a0 40 0f  cmp  %g1, %o7
a00aaf10:  38 bf ff 93  bgu,a   0xa00aad5c
a00aaf14:  f0 0c 60 8f  ldub  [ %l1 + 0x8f ], %i0
a00aaf18:  e4 0c e1 a4  ldub  [ %l3 + 0x1a4 ], %l2
a00aaf1c:  a2 1c a0 03  xor  %l2, 3, %l1
a00aaf20:  80 a0 00 11  cmp  %g0, %l1
a00aaf24:  10 80 00 07  b  0xa00aaf40
a00aaf28:  b0 60 3f ff  subx  %g0, -1, %i0
a00aaf2c:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00aaf30:  d4 0b 62 af  ldub  [ %o5 + 0x2af ], %o2	! 0xa802d2af
a00aaf34:  80 a2 a0 00  cmp  %o2, 0
a00aaf38:  02 bf ff 88  be  0xa00aad58
a00aaf3c:  b0 10 20 00  clr  %i0
a00aaf40:  81 c7 e0 08  ret
a00aaf44:  81 e8 00 00  restore
