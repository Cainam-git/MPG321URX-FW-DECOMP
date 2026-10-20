# leon2m FUN_a0093b04 0xa0093b04-0xa0093b74 (112 bytes)
a0093b04:  9d e3 bf 98  save  %sp, -104, %sp
a0093b08:  21 2a 00 97  sethi  %hi(0xa8025c00), %l0
a0093b0c:  40 00 56 2c  call  0xa00a93bc
a0093b10:  d0 0c 20 55  ldub  [ %l0 + 0x55 ], %o0	! 0xa8025c55
a0093b14:  94 10 20 00  clr  %o2
a0093b18:  90 10 20 01  mov  1, %o0
a0093b1c:  40 00 51 88  call  0xa00a813c
a0093b20:  d2 0c 20 55  ldub  [ %l0 + 0x55 ], %o1
a0093b24:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a0093b28:  d2 02 a2 c0  ld  [ %o2 + 0x2c0 ], %o1	! 0xa802d2c0
a0093b2c:  91 32 60 04  srl  %o1, 4, %o0
a0093b30:  90 0a 20 0f  and  %o0, 0xf, %o0
a0093b34:  d0 2c 20 55  stb  %o0, [ %l0 + 0x55 ]
a0093b38:  40 00 56 c6  call  0xa00a9650
a0093b3c:  92 10 20 01  mov  1, %o1
a0093b40:  90 10 20 01  mov  1, %o0
a0093b44:  40 00 56 49  call  0xa00a9468
a0093b48:  92 10 20 02  mov  2, %o1
a0093b4c:  90 10 20 00  clr  %o0
a0093b50:  40 00 7e 61  call  0xa00b34d4
a0093b54:  92 10 20 01  mov  1, %o1
a0093b58:  9a 10 21 07  mov  0x107, %o5
a0093b5c:  03 2a 00 ab  sethi  %hi(0xa802ac00), %g1
a0093b60:  da 20 63 ec  st  %o5, [ %g1 + 0x3ec ]	! 0xa802afec
a0093b64:  b0 10 20 00  clr  %i0
a0093b68:  40 02 cc 96  call  0xa0146dc0
a0093b6c:  93 e8 20 00  restore  %g0, 0, %o1
a0093b70:  01 00 00 00  nop
