# leon2m FUN_a00adc98 0xa00adc98-0xa00addac (276 bytes)
a00adc98:  9d e3 bf 90  save  %sp, -112, %sp
a00adc9c:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00adca0:  92 14 62 90  or  %l1, 0x290, %o1	! 0xa802d290
a00adca4:  d0 0a 61 7c  ldub  [ %o1 + 0x17c ], %o0
a00adca8:  82 02 00 08  add  %o0, %o0, %g1
a00adcac:  a0 00 60 04  add  %g1, 4, %l0
a00adcb0:  90 10 20 00  clr  %o0
a00adcb4:  92 10 20 00  clr  %o1
a00adcb8:  94 10 20 00  clr  %o2
a00adcbc:  40 00 18 85  call  0xa00b3ed0
a00adcc0:  96 10 20 00  clr  %o3
a00adcc4:  a0 0c 20 ff  and  %l0, 0xff, %l0
a00adcc8:  90 10 20 00  clr  %o0
a00adccc:  92 10 20 00  clr  %o1
a00adcd0:  94 10 27 92  mov  0x792, %o2
a00adcd4:  96 10 20 03  mov  3, %o3
a00adcd8:  98 10 20 0a  mov  0xa, %o4
a00adcdc:  80 a4 20 0a  cmp  %l0, 0xa
a00adce0:  02 80 00 0a  be  0xa00add08
a00adce4:  9a 10 20 02  mov  2, %o5
a00adce8:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00adcec:  90 10 20 00  clr  %o0
a00adcf0:  92 10 20 00  clr  %o1
a00adcf4:  94 10 27 92  mov  0x792, %o2
a00adcf8:  96 10 20 03  mov  3, %o3
a00adcfc:  98 10 00 10  mov  %l0, %o4
a00add00:  10 80 00 0d  b  0xa00add34
a00add04:  9a 10 20 03  mov  3, %o5
a00add08:  40 00 15 77  call  0xa00b32e4
a00add0c:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00add10:  96 10 20 11  mov  0x11, %o3
a00add14:  d6 23 a0 5c  st  %o3, [ %sp + 0x5c ]
a00add18:  15 00 00 0c  sethi  %hi(0x3000), %o2
a00add1c:  94 12 a0 92  or  %o2, 0x92, %o2	! 0x3092
a00add20:  90 10 20 01  mov  1, %o0
a00add24:  92 10 20 00  clr  %o1
a00add28:  96 10 20 03  mov  3, %o3
a00add2c:  98 10 20 0c  mov  0xc, %o4
a00add30:  9a 10 20 01  mov  1, %o5
a00add34:  40 00 15 6c  call  0xa00b32e4
a00add38:  01 00 00 00  nop
a00add3c:  98 10 00 10  mov  %l0, %o4
a00add40:  90 10 20 00  clr  %o0
a00add44:  92 10 20 00  clr  %o1
a00add48:  94 10 27 92  mov  0x792, %o2
a00add4c:  96 10 20 12  mov  0x12, %o3
a00add50:  9a 10 20 03  mov  3, %o5
a00add54:  40 00 15 64  call  0xa00b32e4
a00add58:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00add5c:  a0 14 62 90  or  %l1, 0x290, %l0
a00add60:  d8 0c 21 7c  ldub  [ %l0 + 0x17c ], %o4
a00add64:  1b 15 55 55  sethi  %hi(0x55555400), %o5
a00add68:  90 03 20 01  add  %o4, 1, %o0
a00add6c:  96 13 61 56  or  %o5, 0x156, %o3
a00add70:  80 5a 00 0b  smul  %o0, %o3, %g0
a00add74:  95 40 00 00  rd  %y, %o2
a00add78:  92 02 80 0a  add  %o2, %o2, %o1
a00add7c:  82 02 40 0a  add  %o1, %o2, %g1
a00add80:  a2 22 00 01  sub  %o0, %g1, %l1
a00add84:  e2 2c 21 7c  stb  %l1, [ %l0 + 0x17c ]
a00add88:  90 0c 60 ff  and  %l1, 0xff, %o0
a00add8c:  7f ff fe b8  call  0xa00ad86c
a00add90:  92 10 20 01  mov  1, %o1
a00add94:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00add98:  de 0b 60 8e  ldub  [ %o5 + 0x8e ], %o7	! 0xa802b08e
a00add9c:  98 13 e0 02  or  %o7, 2, %o4
a00adda0:  d8 2b 60 8e  stb  %o4, [ %o5 + 0x8e ]
a00adda4:  81 c7 e0 08  ret
a00adda8:  81 e8 00 00  restore
