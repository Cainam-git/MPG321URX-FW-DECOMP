# leon2m FUN_a00addac 0xa00addac-0xa00adec0 (276 bytes)
a00addac:  9d e3 bf 90  save  %sp, -112, %sp
a00addb0:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00addb4:  92 14 62 90  or  %l1, 0x290, %o1	! 0xa802d290
a00addb8:  d0 0a 61 7c  ldub  [ %o1 + 0x17c ], %o0
a00addbc:  82 02 00 08  add  %o0, %o0, %g1
a00addc0:  a0 00 60 04  add  %g1, 4, %l0
a00addc4:  90 10 20 00  clr  %o0
a00addc8:  92 10 20 00  clr  %o1
a00addcc:  94 10 20 00  clr  %o2
a00addd0:  40 00 18 40  call  0xa00b3ed0
a00addd4:  96 10 20 00  clr  %o3
a00addd8:  a0 0c 20 ff  and  %l0, 0xff, %l0
a00adddc:  90 10 20 00  clr  %o0
a00adde0:  92 10 20 00  clr  %o1
a00adde4:  94 10 27 92  mov  0x792, %o2
a00adde8:  96 10 20 03  mov  3, %o3
a00addec:  98 10 20 0a  mov  0xa, %o4
a00addf0:  80 a4 20 0a  cmp  %l0, 0xa
a00addf4:  02 80 00 0a  be  0xa00ade1c
a00addf8:  9a 10 20 02  mov  2, %o5
a00addfc:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00ade00:  90 10 20 00  clr  %o0
a00ade04:  92 10 20 00  clr  %o1
a00ade08:  94 10 27 92  mov  0x792, %o2
a00ade0c:  96 10 20 03  mov  3, %o3
a00ade10:  98 10 00 10  mov  %l0, %o4
a00ade14:  10 80 00 0d  b  0xa00ade48
a00ade18:  9a 10 20 03  mov  3, %o5
a00ade1c:  40 00 15 32  call  0xa00b32e4
a00ade20:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00ade24:  96 10 20 11  mov  0x11, %o3
a00ade28:  d6 23 a0 5c  st  %o3, [ %sp + 0x5c ]
a00ade2c:  15 00 00 0c  sethi  %hi(0x3000), %o2
a00ade30:  94 12 a0 92  or  %o2, 0x92, %o2	! 0x3092
a00ade34:  90 10 20 01  mov  1, %o0
a00ade38:  92 10 20 00  clr  %o1
a00ade3c:  96 10 20 03  mov  3, %o3
a00ade40:  98 10 20 0c  mov  0xc, %o4
a00ade44:  9a 10 20 01  mov  1, %o5
a00ade48:  40 00 15 27  call  0xa00b32e4
a00ade4c:  01 00 00 00  nop
a00ade50:  98 10 00 10  mov  %l0, %o4
a00ade54:  90 10 20 00  clr  %o0
a00ade58:  92 10 20 00  clr  %o1
a00ade5c:  94 10 27 92  mov  0x792, %o2
a00ade60:  96 10 20 12  mov  0x12, %o3
a00ade64:  9a 10 20 03  mov  3, %o5
a00ade68:  40 00 15 1f  call  0xa00b32e4
a00ade6c:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00ade70:  a0 14 62 90  or  %l1, 0x290, %l0
a00ade74:  d8 0c 21 7c  ldub  [ %l0 + 0x17c ], %o4
a00ade78:  1b 15 55 55  sethi  %hi(0x55555400), %o5
a00ade7c:  90 03 20 02  add  %o4, 2, %o0
a00ade80:  96 13 61 56  or  %o5, 0x156, %o3
a00ade84:  80 5a 00 0b  smul  %o0, %o3, %g0
a00ade88:  95 40 00 00  rd  %y, %o2
a00ade8c:  92 02 80 0a  add  %o2, %o2, %o1
a00ade90:  82 02 40 0a  add  %o1, %o2, %g1
a00ade94:  a2 22 00 01  sub  %o0, %g1, %l1
a00ade98:  e2 2c 21 7c  stb  %l1, [ %l0 + 0x17c ]
a00ade9c:  90 0c 60 ff  and  %l1, 0xff, %o0
a00adea0:  7f ff fe 73  call  0xa00ad86c
a00adea4:  92 10 20 01  mov  1, %o1
a00adea8:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00adeac:  de 0b 60 8e  ldub  [ %o5 + 0x8e ], %o7	! 0xa802b08e
a00adeb0:  98 13 e0 02  or  %o7, 2, %o4
a00adeb4:  d8 2b 60 8e  stb  %o4, [ %o5 + 0x8e ]
a00adeb8:  81 c7 e0 08  ret
a00adebc:  81 e8 00 00  restore
