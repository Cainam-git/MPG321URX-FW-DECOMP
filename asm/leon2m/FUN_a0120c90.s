# leon2m FUN_a0120c90 0xa0120c90-0xa0120de4 (340 bytes)
a0120c90:  9d e3 bf 98  save  %sp, -104, %sp
a0120c94:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0120c98:  92 10 20 12  mov  0x12, %o1
a0120c9c:  7f ff 45 55  call  0xa00f21f0
a0120ca0:  90 10 00 18  mov  %i0, %o0
a0120ca4:  15 00 00 07  sethi  %hi(0x1c00), %o2
a0120ca8:  a0 12 a3 ff  or  %o2, 0x3ff, %l0	! 0x1fff
a0120cac:  a2 0a 00 10  and  %o0, %l0, %l1
a0120cb0:  98 04 7f 6d  add  %l1, -147, %o4
a0120cb4:  97 2b 20 10  sll  %o4, 0x10, %o3
a0120cb8:  83 32 e0 10  srl  %o3, 0x10, %g1
a0120cbc:  9a 12 a2 ad  or  %o2, 0x2ad, %o5
a0120cc0:  80 a0 40 0d  cmp  %g1, %o5
a0120cc4:  92 10 20 14  mov  0x14, %o1
a0120cc8:  90 10 00 18  mov  %i0, %o0
a0120ccc:  18 80 00 44  bgu  0xa0120ddc
a0120cd0:  82 10 20 00  clr  %g1
a0120cd4:  7f ff 45 47  call  0xa00f21f0
a0120cd8:  01 00 00 00  nop
a0120cdc:  a0 0c 00 08  and  %l0, %o0, %l0
a0120ce0:  90 04 3b fd  add  %l0, -1027, %o0
a0120ce4:  95 2a 20 10  sll  %o0, 0x10, %o2
a0120ce8:  03 00 00 11  sethi  %hi(0x4400), %g1
a0120cec:  9e 10 61 3b  or  %g1, 0x13b, %o7	! 0x453b
a0120cf0:  9b 32 a0 10  srl  %o2, 0x10, %o5
a0120cf4:  90 10 00 18  mov  %i0, %o0
a0120cf8:  92 10 20 04  mov  4, %o1
a0120cfc:  80 a3 40 0f  cmp  %o5, %o7
a0120d00:  18 80 00 37  bgu  0xa0120ddc
a0120d04:  82 10 20 00  clr  %g1
a0120d08:  7f ff 43 62  call  0xa00f1a90
a0120d0c:  01 00 00 00  nop
a0120d10:  80 8a 20 02  btst  2, %o0
a0120d14:  92 10 20 54  mov  0x54, %o1
a0120d18:  02 80 00 26  be  0xa0120db0
a0120d1c:  90 10 00 18  mov  %i0, %o0
a0120d20:  7f ff 43 5c  call  0xa00f1a90
a0120d24:  01 00 00 00  nop
a0120d28:  82 06 00 18  add  %i0, %i0, %g1
a0120d2c:  9a 00 40 18  add  %g1, %i0, %o5
a0120d30:  1f 2a 00 9e  sethi  %hi(0xa8027800), %o7
a0120d34:  97 2b 60 02  sll  %o5, 2, %o3
a0120d38:  98 13 e2 ac  or  %o7, 0x2ac, %o4
a0120d3c:  92 0a 20 ff  and  %o0, 0xff, %o1
a0120d40:  80 a2 60 20  cmp  %o1, 0x20
a0120d44:  12 80 00 1b  bne  0xa0120db0
a0120d48:  82 02 c0 0c  add  %o3, %o4, %g1
a0120d4c:  f0 00 60 04  ld  [ %g1 + 4 ], %i0
a0120d50:  80 a6 20 01  cmp  %i0, 1
a0120d54:  02 80 00 1e  be  0xa0120dcc
a0120d58:  90 10 00 10  mov  %l0, %o0
a0120d5c:  40 00 d3 b9  call  0xa0155c40
a0120d60:  90 10 00 10  mov  %l0, %o0
a0120d64:  15 00 06 8b  sethi  %hi(0x1a2c00), %o2
a0120d68:  d2 02 a3 dc  ld  [ %o2 + 0x3dc ], %o1	! 0x1a2fdc
a0120d6c:  40 00 d2 b1  call  0xa0155830
a0120d70:  01 00 00 00  nop
a0120d74:  b0 10 00 08  mov  %o0, %i0
a0120d78:  40 00 d3 b2  call  0xa0155c40
a0120d7c:  90 10 00 11  mov  %l1, %o0
a0120d80:  92 10 00 08  mov  %o0, %o1
a0120d84:  40 00 d3 25  call  0xa0155a18
a0120d88:  90 10 00 18  mov  %i0, %o0
a0120d8c:  40 00 d4 01  call  0xa0155d90
a0120d90:  23 00 06 69  sethi  %hi(0x19a400), %l1
a0120d94:  40 00 d4 c6  call  0xa01560ac
a0120d98:  d4 1c 62 38  ldd  [ %l1 + 0x238 ], %o2	! 0x19a638
a0120d9c:  40 00 d0 f1  call  0xa0155160
a0120da0:  01 00 00 00  nop
a0120da4:  91 2a 20 10  sll  %o0, 0x10, %o0
a0120da8:  10 80 00 0d  b  0xa0120ddc
a0120dac:  83 32 20 10  srl  %o0, 0x10, %g1
a0120db0:  90 10 00 18  mov  %i0, %o0
a0120db4:  7f ff 45 0f  call  0xa00f21f0
a0120db8:  92 10 20 26  mov  0x26, %o1
a0120dbc:  90 02 20 01  inc  %o0
a0120dc0:  91 2a 20 10  sll  %o0, 0x10, %o0
a0120dc4:  10 80 00 06  b  0xa0120ddc
a0120dc8:  83 32 20 10  srl  %o0, 0x10, %g1
a0120dcc:  40 00 d3 9d  call  0xa0155c40
a0120dd0:  21 00 06 8b  sethi  %hi(0x1a2c00), %l0
a0120dd4:  10 bf ff e6  b  0xa0120d6c
a0120dd8:  d2 04 23 d8  ld  [ %l0 + 0x3d8 ], %o1	! 0x1a2fd8
a0120ddc:  81 c7 e0 08  ret
a0120de0:  91 e8 00 01  restore  %g0, %g1, %o0
