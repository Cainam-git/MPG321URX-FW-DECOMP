# leon2s DRV_HDMI_EQScan_FSM_PHY_DPHY 0xa007cea4-0xa007cfec (328 bytes)
a007cea4:  9d e3 bf 98  save  %sp, -104, %sp
a007cea8:  a0 0e 20 ff  and  %i0, 0xff, %l0
a007ceac:  82 04 00 10  add  %l0, %l0, %g1
a007ceb0:  82 00 40 10  add  %g1, %l0, %g1
a007ceb4:  1b 2a 01 f3  sethi  %hi(0xa807cc00), %o5
a007ceb8:  9a 13 60 64  or  %o5, 0x64, %o5	! 0xa807cc64
a007cebc:  83 28 60 03  sll  %g1, 3, %g1
a007cec0:  82 00 40 0d  add  %g1, %o5, %g1
a007cec4:  25 2a 01 e1  sethi  %hi(0xa8078400), %l2
a007cec8:  da 04 a2 34  ld  [ %l2 + 0x234 ], %o5	! 0xa8078634
a007cecc:  a6 10 00 18  mov  %i0, %l3
a007ced0:  80 8b 60 02  btst  2, %o5
a007ced4:  02 80 00 0a  be  0xa007cefc
a007ced8:  e2 10 60 08  lduh  [ %g1 + 8 ], %l1
a007cedc:  92 06 20 41  add  %i0, 0x41, %o1
a007cee0:  93 2a 60 18  sll  %o1, 0x18, %o1
a007cee4:  11 28 01 9e  sethi  %hi(0xa0067800), %o0
a007cee8:  15 28 02 cf  sethi  %hi(0xa00b3c00), %o2
a007ceec:  90 12 23 38  or  %o0, 0x338, %o0
a007cef0:  93 3a 60 18  sra  %o1, 0x18, %o1
a007cef4:  7f ff d8 54  call  0xa0073044
a007cef8:  94 12 a2 90  or  %o2, 0x290, %o2
a007cefc:  31 00 00 07  sethi  %hi(0x1c00), %i0
a007cf00:  90 10 20 01  mov  1, %o0
a007cf04:  92 10 20 07  mov  7, %o1
a007cf08:  94 10 00 10  mov  %l0, %o2
a007cf0c:  40 00 a9 46  call  0xa00a7424
a007cf10:  96 16 22 90  or  %i0, 0x290, %o3
a007cf14:  90 10 00 10  mov  %l0, %o0
a007cf18:  92 16 23 08  or  %i0, 0x308, %o1
a007cf1c:  94 10 3f f8  mov  -8, %o2
a007cf20:  40 00 a9 5a  call  0xa00a7488
a007cf24:  96 10 20 04  mov  4, %o3
a007cf28:  83 2c 60 10  sll  %l1, 0x10, %g1
a007cf2c:  83 30 60 10  srl  %g1, 0x10, %g1
a007cf30:  80 a0 60 63  cmp  %g1, 0x63
a007cf34:  08 80 00 10  bleu  0xa007cf74
a007cf38:  80 a0 60 9f  cmp  %g1, 0x9f
a007cf3c:  08 80 00 0e  bleu  0xa007cf74
a007cf40:  80 a0 61 2b  cmp  %g1, 0x12b
a007cf44:  18 80 00 05  bgu  0xa007cf58
a007cf48:  80 a0 62 58  cmp  %g1, 0x258
a007cf4c:  17 00 00 07  sethi  %hi(0x1c00), %o3
a007cf50:  10 80 00 0a  b  0xa007cf78
a007cf54:  96 12 e2 90  or  %o3, 0x290, %o3	! 0x1e90
a007cf58:  18 80 00 15  bgu  0xa007cfac
a007cf5c:  c2 04 a2 34  ld  [ %l2 + 0x234 ], %g1
a007cf60:  7f ff f8 d0  call  0xa007b2a0
a007cf64:  90 10 00 10  mov  %l0, %o0
a007cf68:  80 8a 20 ff  btst  0xff, %o0
a007cf6c:  22 bf ff f9  be,a   0xa007cf50
a007cf70:  17 00 00 07  sethi  %hi(0x1c00), %o3
a007cf74:  96 16 22 90  or  %i0, 0x290, %o3
a007cf78:  94 10 00 10  mov  %l0, %o2
a007cf7c:  90 10 20 00  clr  %o0
a007cf80:  40 00 a9 29  call  0xa00a7424
a007cf84:  92 10 20 02  mov  2, %o1
a007cf88:  13 00 00 04  sethi  %hi(0x1000), %o1
a007cf8c:  15 3f c0 3f  sethi  %hi(0xff00fc00), %o2
a007cf90:  90 10 00 10  mov  %l0, %o0
a007cf94:  92 12 61 9c  or  %o1, 0x19c, %o1
a007cf98:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a007cf9c:  40 00 a9 3b  call  0xa00a7488
a007cfa0:  96 10 20 00  clr  %o3
a007cfa4:  10 80 00 09  b  0xa007cfc8
a007cfa8:  82 0c e0 ff  and  %l3, 0xff, %g1
a007cfac:  80 88 60 02  btst  2, %g1
a007cfb0:  02 80 00 06  be  0xa007cfc8
a007cfb4:  82 0c e0 ff  and  %l3, 0xff, %g1
a007cfb8:  11 28 01 9e  sethi  %hi(0xa0067800), %o0
a007cfbc:  7f ff d9 42  call  0xa00734c4
a007cfc0:  90 12 22 98  or  %o0, 0x298, %o0	! 0xa0067a98
a007cfc4:  82 0c e0 ff  and  %l3, 0xff, %g1
a007cfc8:  9a 00 40 01  add  %g1, %g1, %o5
a007cfcc:  9a 03 40 01  add  %o5, %g1, %o5
a007cfd0:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a007cfd4:  9b 2b 60 02  sll  %o5, 2, %o5
a007cfd8:  98 10 20 03  mov  3, %o4
a007cfdc:  82 10 60 c4  or  %g1, 0xc4, %g1
a007cfe0:  d8 20 40 0d  st  %o4, [ %g1 + %o5 ]
a007cfe4:  81 c7 e0 08  ret
a007cfe8:  91 e8 20 00  restore  %g0, 0, %o0
