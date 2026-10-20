# leon2m FUN_a00aeb98 0xa00aeb98-0xa00aecec (340 bytes)
a00aeb98:  9d e3 bf 90  save  %sp, -112, %sp
a00aeb9c:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00aeba0:  94 14 62 90  or  %l1, 0x290, %o2	! 0xa802d290
a00aeba4:  d2 0a a1 90  ldub  [ %o2 + 0x190 ], %o1
a00aeba8:  90 0a 60 03  and  %o1, 3, %o0
a00aebac:  82 02 00 08  add  %o0, %o0, %g1
a00aebb0:  a0 00 60 04  add  %g1, 4, %l0
a00aebb4:  90 10 20 00  clr  %o0
a00aebb8:  92 10 20 00  clr  %o1
a00aebbc:  94 10 20 00  clr  %o2
a00aebc0:  40 00 14 c4  call  0xa00b3ed0
a00aebc4:  96 10 20 00  clr  %o3
a00aebc8:  a0 0c 20 ff  and  %l0, 0xff, %l0
a00aebcc:  90 10 20 00  clr  %o0
a00aebd0:  92 10 20 00  clr  %o1
a00aebd4:  94 10 27 92  mov  0x792, %o2
a00aebd8:  96 10 20 03  mov  3, %o3
a00aebdc:  98 10 20 0a  mov  0xa, %o4
a00aebe0:  80 a4 20 0a  cmp  %l0, 0xa
a00aebe4:  02 80 00 2c  be  0xa00aec94
a00aebe8:  9a 10 20 02  mov  2, %o5
a00aebec:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00aebf0:  90 10 20 00  clr  %o0
a00aebf4:  92 10 20 00  clr  %o1
a00aebf8:  94 10 27 92  mov  0x792, %o2
a00aebfc:  96 10 20 03  mov  3, %o3
a00aec00:  98 10 00 10  mov  %l0, %o4
a00aec04:  9a 10 20 03  mov  3, %o5
a00aec08:  40 00 11 b7  call  0xa00b32e4
a00aec0c:  01 00 00 00  nop
a00aec10:  98 10 00 10  mov  %l0, %o4
a00aec14:  90 10 20 00  clr  %o0
a00aec18:  92 10 20 00  clr  %o1
a00aec1c:  94 10 27 92  mov  0x792, %o2
a00aec20:  96 10 20 12  mov  0x12, %o3
a00aec24:  9a 10 20 03  mov  3, %o5
a00aec28:  40 00 11 af  call  0xa00b32e4
a00aec2c:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00aec30:  a0 14 62 90  or  %l1, 0x290, %l0
a00aec34:  d8 0c 21 90  ldub  [ %l0 + 0x190 ], %o4
a00aec38:  03 24 92 49  sethi  %hi(0x92492400), %g1
a00aec3c:  92 03 20 01  add  %o4, 1, %o1
a00aec40:  90 10 60 93  or  %g1, 0x93, %o0
a00aec44:  80 5a 40 08  smul  %o1, %o0, %g0
a00aec48:  9b 40 00 00  rd  %y, %o5
a00aec4c:  a2 03 40 09  add  %o5, %o1, %l1
a00aec50:  9f 3c 60 02  sra  %l1, 2, %o7
a00aec54:  97 2b e0 03  sll  %o7, 3, %o3
a00aec58:  94 22 c0 0f  sub  %o3, %o7, %o2
a00aec5c:  9e 22 40 0a  sub  %o1, %o2, %o7
a00aec60:  90 0b e0 ff  and  %o7, 0xff, %o0
a00aec64:  82 1a 20 04  xor  %o0, 4, %g1
a00aec68:  80 a0 00 01  cmp  %g0, %g1
a00aec6c:  9a 60 3f ff  subx  %g0, -1, %o5
a00aec70:  80 a0 00 08  cmp  %g0, %o0
a00aec74:  a2 60 3f ff  subx  %g0, -1, %l1
a00aec78:  80 93 40 11  orcc  %o5, %l1, %g0
a00aec7c:  02 80 00 12  be  0xa00aecc4
a00aec80:  de 2c 21 90  stb  %o7, [ %l0 + 0x190 ]
a00aec84:  7f ff fb 9c  call  0xa00adaf4
a00aec88:  01 00 00 00  nop
a00aec8c:  10 80 00 0f  b  0xa00aecc8
a00aec90:  d6 0c 21 90  ldub  [ %l0 + 0x190 ], %o3
a00aec94:  40 00 11 94  call  0xa00b32e4
a00aec98:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00aec9c:  98 10 20 11  mov  0x11, %o4
a00aeca0:  17 00 00 0c  sethi  %hi(0x3000), %o3
a00aeca4:  d8 23 a0 5c  st  %o4, [ %sp + 0x5c ]
a00aeca8:  94 12 e0 92  or  %o3, 0x92, %o2
a00aecac:  90 10 20 01  mov  1, %o0
a00aecb0:  92 10 20 00  clr  %o1
a00aecb4:  96 10 20 03  mov  3, %o3
a00aecb8:  98 10 20 0c  mov  0xc, %o4
a00aecbc:  10 bf ff d3  b  0xa00aec08
a00aecc0:  9a 10 20 01  mov  1, %o5
a00aecc4:  d6 0c 21 90  ldub  [ %l0 + 0x190 ], %o3
a00aecc8:  92 10 20 01  mov  1, %o1
a00aeccc:  7f ff fa e8  call  0xa00ad86c
a00aecd0:  90 0a e0 03  and  %o3, 3, %o0
a00aecd4:  21 2a 00 ac  sethi  %hi(0xa802b000), %l0
a00aecd8:  d4 0c 20 8e  ldub  [ %l0 + 0x8e ], %o2	! 0xa802b08e
a00aecdc:  92 12 a0 02  or  %o2, 2, %o1
a00aece0:  d2 2c 20 8e  stb  %o1, [ %l0 + 0x8e ]
a00aece4:  81 c7 e0 08  ret
a00aece8:  81 e8 00 00  restore
