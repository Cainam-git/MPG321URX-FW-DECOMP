# leon2m FUN_a00dedc8 0xa00dedc8-0xa00dee6c (164 bytes)
a00dedc8:  9d e3 bf 98  save  %sp, -104, %sp
a00dedcc:  15 24 68 ac  sethi  %hi(0x91a2b000), %o2
a00dedd0:  92 12 a3 c5  or  %o2, 0x3c5, %o1	! 0x91a2b3c5
a00dedd4:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00dedd8:  80 56 00 09  umul  %i0, %o1, %g0
a00deddc:  91 40 00 00  rd  %y, %o0
a00dede0:  9a 10 60 ec  or  %g1, 0xec, %o5
a00dede4:  21 30 02 c0  sethi  %hi(0xc00b0000), %l0
a00dede8:  b1 32 20 14  srl  %o0, 0x14, %i0
a00dedec:  c0 2b 60 80  clrb  [ %o5 + 0x80 ]
a00dedf0:  c0 2b 60 81  clrb  [ %o5 + 0x81 ]
a00dedf4:  90 14 20 0c  or  %l0, 0xc, %o0
a00dedf8:  67 fe b5 19  call  0x4008c25c
a00dedfc:  92 10 20 80  mov  0x80, %o1
a00dee00:  92 10 00 18  mov  %i0, %o1
a00dee04:  67 fe b5 16  call  0x4008c25c
a00dee08:  90 10 00 10  mov  %l0, %o0
a00dee0c:  90 14 20 04  or  %l0, 4, %o0
a00dee10:  67 fe b5 13  call  0x4008c25c
a00dee14:  92 10 20 00  clr  %o1
a00dee18:  90 14 20 0c  or  %l0, 0xc, %o0
a00dee1c:  67 fe b5 10  call  0x4008c25c
a00dee20:  92 10 20 00  clr  %o1
a00dee24:  90 14 20 0c  or  %l0, 0xc, %o0
a00dee28:  67 fe b5 0d  call  0x4008c25c
a00dee2c:  92 10 20 03  mov  3, %o1
a00dee30:  90 14 20 08  or  %l0, 8, %o0
a00dee34:  67 fe b5 0a  call  0x4008c25c
a00dee38:  92 10 20 06  mov  6, %o1
a00dee3c:  90 14 20 08  or  %l0, 8, %o0
a00dee40:  67 fe b5 07  call  0x4008c25c
a00dee44:  92 10 20 00  clr  %o1
a00dee48:  90 14 20 04  or  %l0, 4, %o0
a00dee4c:  92 10 20 01  mov  1, %o1
a00dee50:  67 fe b5 03  call  0x4008c25c
a00dee54:  35 28 00 b8  sethi  %hi(0xa002e000), %i2
a00dee58:  b4 16 a2 38  or  %i2, 0x238, %i2	! 0xa002e238
a00dee5c:  b0 10 20 04  mov  4, %i0
a00dee60:  67 fe ae 88  call  0x4008a880
a00dee64:  93 e8 20 20  restore  %g0, 0x20, %o1
a00dee68:  01 00 00 00  nop
