# leon2m FUN_a015cef8 0xa015cef8-0xa015cf78 (128 bytes)
a015cef8:  03 3f ff c0  sethi  %hi(0xffff0000), %g1
a015cefc:  80 8a 00 01  btst  %o0, %g1
a015cf00:  12 80 00 04  bne  0xa015cf10
a015cf04:  9a 10 20 00  clr  %o5
a015cf08:  91 2a 20 10  sll  %o0, 0x10, %o0
a015cf0c:  9a 10 20 10  mov  0x10, %o5
a015cf10:  03 3f c0 00  sethi  %hi(0xff000000), %g1
a015cf14:  80 8a 00 01  btst  %o0, %g1
a015cf18:  12 80 00 04  bne  0xa015cf28
a015cf1c:  03 3c 00 00  sethi  %hi(0xf0000000), %g1
a015cf20:  9a 03 60 08  add  %o5, 8, %o5
a015cf24:  91 2a 20 08  sll  %o0, 8, %o0
a015cf28:  80 8a 00 01  btst  %o0, %g1
a015cf2c:  12 80 00 04  bne  0xa015cf3c
a015cf30:  03 30 00 00  sethi  %hi(0xc0000000), %g1
a015cf34:  9a 03 60 04  add  %o5, 4, %o5
a015cf38:  91 2a 20 04  sll  %o0, 4, %o0
a015cf3c:  80 8a 00 01  btst  %o0, %g1
a015cf40:  12 80 00 05  bne  0xa015cf54
a015cf44:  80 a2 20 00  cmp  %o0, 0
a015cf48:  9a 03 60 02  add  %o5, 2, %o5
a015cf4c:  91 2a 20 02  sll  %o0, 2, %o0
a015cf50:  80 a2 20 00  cmp  %o0, 0
a015cf54:  06 80 00 06  bl  0xa015cf6c
a015cf58:  03 10 00 00  sethi  %hi(0x40000000), %g1
a015cf5c:  80 8a 00 01  btst  %o0, %g1
a015cf60:  9a 03 60 01  inc  %o5
a015cf64:  02 80 00 03  be  0xa015cf70
a015cf68:  90 10 20 20  mov  0x20, %o0
a015cf6c:  90 10 00 0d  mov  %o5, %o0
a015cf70:  81 c3 e0 08  retl
a015cf74:  01 00 00 00  nop
