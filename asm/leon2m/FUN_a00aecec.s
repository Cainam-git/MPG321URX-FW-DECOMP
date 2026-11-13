# leon2m FUN_a00aecec 0xa00aecec-0xa00aee44 (344 bytes)
a00aecec:  9d e3 bf 90  save  %sp, -112, %sp
a00aecf0:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00aecf4:  94 14 62 90  or  %l1, 0x290, %o2	! 0xa802d290
a00aecf8:  d2 0a a1 90  ldub  [ %o2 + 0x190 ], %o1
a00aecfc:  90 0a 60 03  and  %o1, 3, %o0
a00aed00:  82 02 00 08  add  %o0, %o0, %g1
a00aed04:  a0 00 60 04  add  %g1, 4, %l0
a00aed08:  90 10 20 00  clr  %o0
a00aed0c:  92 10 20 00  clr  %o1
a00aed10:  94 10 20 00  clr  %o2
a00aed14:  40 00 14 6f  call  0xa00b3ed0
a00aed18:  96 10 20 00  clr  %o3
a00aed1c:  a0 0c 20 ff  and  %l0, 0xff, %l0
a00aed20:  90 10 20 00  clr  %o0
a00aed24:  92 10 20 00  clr  %o1
a00aed28:  94 10 27 92  mov  0x792, %o2
a00aed2c:  96 10 20 03  mov  3, %o3
a00aed30:  98 10 20 0a  mov  0xa, %o4
a00aed34:  80 a4 20 0a  cmp  %l0, 0xa
a00aed38:  02 80 00 2d  be  0xa00aedec
a00aed3c:  9a 10 20 02  mov  2, %o5
a00aed40:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00aed44:  90 10 20 00  clr  %o0
a00aed48:  92 10 20 00  clr  %o1
a00aed4c:  94 10 27 92  mov  0x792, %o2
a00aed50:  96 10 20 03  mov  3, %o3
a00aed54:  98 10 00 10  mov  %l0, %o4
a00aed58:  9a 10 20 03  mov  3, %o5
a00aed5c:  40 00 11 62  call  0xa00b32e4
a00aed60:  01 00 00 00  nop
a00aed64:  98 10 00 10  mov  %l0, %o4
a00aed68:  90 10 20 00  clr  %o0
a00aed6c:  92 10 20 00  clr  %o1
a00aed70:  94 10 27 92  mov  0x792, %o2
a00aed74:  96 10 20 12  mov  0x12, %o3
a00aed78:  9a 10 20 03  mov  3, %o5
a00aed7c:  40 00 11 5a  call  0xa00b32e4
a00aed80:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00aed84:  a0 14 62 90  or  %l1, 0x290, %l0
a00aed88:  d8 0c 21 90  ldub  [ %l0 + 0x190 ], %o4
a00aed8c:  13 24 92 49  sethi  %hi(0x92492400), %o1
a00aed90:  94 03 20 06  add  %o4, 6, %o2
a00aed94:  90 12 60 93  or  %o1, 0x93, %o0
a00aed98:  80 5a 80 08  smul  %o2, %o0, %g0
a00aed9c:  83 40 00 00  rd  %y, %g1
a00aeda0:  a2 00 40 0a  add  %g1, %o2, %l1
a00aeda4:  9b 3c 60 02  sra  %l1, 2, %o5
a00aeda8:  9f 2b 60 03  sll  %o5, 3, %o7
a00aedac:  96 23 c0 0d  sub  %o7, %o5, %o3
a00aedb0:  9e 22 80 0b  sub  %o2, %o3, %o7
a00aedb4:  90 0b e0 ff  and  %o7, 0xff, %o0
a00aedb8:  92 1a 20 06  xor  %o0, 6, %o1
a00aedbc:  80 a0 00 09  cmp  %g0, %o1
a00aedc0:  a2 60 3f ff  subx  %g0, -1, %l1
a00aedc4:  82 1a 20 03  xor  %o0, 3, %g1
a00aedc8:  80 a0 00 01  cmp  %g0, %g1
a00aedcc:  9a 60 3f ff  subx  %g0, -1, %o5
a00aedd0:  80 94 40 0d  orcc  %l1, %o5, %g0
a00aedd4:  02 80 00 12  be  0xa00aee1c
a00aedd8:  de 2c 21 90  stb  %o7, [ %l0 + 0x190 ]
a00aeddc:  7f ff fb 46  call  0xa00adaf4
a00aede0:  01 00 00 00  nop
a00aede4:  10 80 00 0f  b  0xa00aee20
a00aede8:  de 0c 21 90  ldub  [ %l0 + 0x190 ], %o7
a00aedec:  40 00 11 3e  call  0xa00b32e4
a00aedf0:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00aedf4:  98 10 20 11  mov  0x11, %o4
a00aedf8:  17 00 00 0c  sethi  %hi(0x3000), %o3
a00aedfc:  d8 23 a0 5c  st  %o4, [ %sp + 0x5c ]
a00aee00:  94 12 e0 92  or  %o3, 0x92, %o2
a00aee04:  90 10 20 01  mov  1, %o0
a00aee08:  92 10 20 00  clr  %o1
a00aee0c:  96 10 20 03  mov  3, %o3
a00aee10:  98 10 20 0c  mov  0xc, %o4
a00aee14:  10 bf ff d2  b  0xa00aed5c
a00aee18:  9a 10 20 01  mov  1, %o5
a00aee1c:  de 0c 21 90  ldub  [ %l0 + 0x190 ], %o7
a00aee20:  90 0b e0 03  and  %o7, 3, %o0
a00aee24:  7f ff fa 92  call  0xa00ad86c
a00aee28:  92 10 20 01  mov  1, %o1
a00aee2c:  21 2a 00 ac  sethi  %hi(0xa802b000), %l0
a00aee30:  d6 0c 20 8e  ldub  [ %l0 + 0x8e ], %o3	! 0xa802b08e
a00aee34:  94 12 e0 02  or  %o3, 2, %o2
a00aee38:  d4 2c 20 8e  stb  %o2, [ %l0 + 0x8e ]
a00aee3c:  81 c7 e0 08  ret
a00aee40:  81 e8 00 00  restore
