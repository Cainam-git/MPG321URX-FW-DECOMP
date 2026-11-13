# leon2m FUN_a00adec0 0xa00adec0-0xa00ae020 (352 bytes)
a00adec0:  9d e3 bf 90  save  %sp, -112, %sp
a00adec4:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00adec8:  94 14 62 90  or  %l1, 0x290, %o2	! 0xa802d290
a00adecc:  d2 0a a1 5b  ldub  [ %o2 + 0x15b ], %o1
a00aded0:  90 0a 60 03  and  %o1, 3, %o0
a00aded4:  82 02 00 08  add  %o0, %o0, %g1
a00aded8:  a0 00 60 04  add  %g1, 4, %l0
a00adedc:  90 10 20 00  clr  %o0
a00adee0:  92 10 20 00  clr  %o1
a00adee4:  94 10 20 00  clr  %o2
a00adee8:  40 00 17 fa  call  0xa00b3ed0
a00adeec:  96 10 20 00  clr  %o3
a00adef0:  a0 0c 20 ff  and  %l0, 0xff, %l0
a00adef4:  90 10 20 00  clr  %o0
a00adef8:  92 10 20 00  clr  %o1
a00adefc:  94 10 27 92  mov  0x792, %o2
a00adf00:  96 10 20 03  mov  3, %o3
a00adf04:  98 10 20 0a  mov  0xa, %o4
a00adf08:  80 a4 20 0a  cmp  %l0, 0xa
a00adf0c:  02 80 00 2c  be  0xa00adfbc
a00adf10:  9a 10 20 02  mov  2, %o5
a00adf14:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00adf18:  90 10 20 00  clr  %o0
a00adf1c:  92 10 20 00  clr  %o1
a00adf20:  94 10 27 92  mov  0x792, %o2
a00adf24:  96 10 20 03  mov  3, %o3
a00adf28:  98 10 00 10  mov  %l0, %o4
a00adf2c:  9a 10 20 03  mov  3, %o5
a00adf30:  40 00 14 ed  call  0xa00b32e4
a00adf34:  01 00 00 00  nop
a00adf38:  98 10 00 10  mov  %l0, %o4
a00adf3c:  94 10 27 92  mov  0x792, %o2
a00adf40:  96 10 20 12  mov  0x12, %o3
a00adf44:  9a 10 20 03  mov  3, %o5
a00adf48:  90 10 20 00  clr  %o0
a00adf4c:  92 10 20 00  clr  %o1
a00adf50:  40 00 14 e5  call  0xa00b32e4
a00adf54:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00adf58:  a0 14 62 90  or  %l1, 0x290, %l0
a00adf5c:  d8 0c 21 5b  ldub  [ %l0 + 0x15b ], %o4
a00adf60:  1b 19 99 99  sethi  %hi(0x66666400), %o5
a00adf64:  82 13 62 67  or  %o5, 0x267, %g1	! 0x66666667
a00adf68:  92 03 20 01  add  %o4, 1, %o1
a00adf6c:  80 5a 40 01  smul  %o1, %g1, %g0
a00adf70:  a3 40 00 00  rd  %y, %l1
a00adf74:  9f 3c 60 01  sra  %l1, 1, %o7
a00adf78:  97 2b e0 02  sll  %o7, 2, %o3
a00adf7c:  94 02 c0 0f  add  %o3, %o7, %o2
a00adf80:  a2 22 40 0a  sub  %o1, %o2, %l1
a00adf84:  9e 0c 60 ff  and  %l1, 0xff, %o7
a00adf88:  90 1b e0 04  xor  %o7, 4, %o0
a00adf8c:  80 a0 00 08  cmp  %g0, %o0
a00adf90:  9a 60 3f ff  subx  %g0, -1, %o5
a00adf94:  80 a0 00 0f  cmp  %g0, %o7
a00adf98:  82 60 3f ff  subx  %g0, -1, %g1
a00adf9c:  80 93 40 01  orcc  %o5, %g1, %g0
a00adfa0:  e2 2c 21 5b  stb  %l1, [ %l0 + 0x15b ]
a00adfa4:  02 80 00 12  be  0xa00adfec
a00adfa8:  91 33 e0 02  srl  %o7, 2, %o0
a00adfac:  7f ff fe 71  call  0xa00ad970
a00adfb0:  01 00 00 00  nop
a00adfb4:  10 80 00 0f  b  0xa00adff0
a00adfb8:  d4 0c 21 5b  ldub  [ %l0 + 0x15b ], %o2
a00adfbc:  40 00 14 ca  call  0xa00b32e4
a00adfc0:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00adfc4:  98 10 20 11  mov  0x11, %o4
a00adfc8:  17 00 00 0c  sethi  %hi(0x3000), %o3
a00adfcc:  d8 23 a0 5c  st  %o4, [ %sp + 0x5c ]
a00adfd0:  94 12 e0 92  or  %o3, 0x92, %o2
a00adfd4:  90 10 20 01  mov  1, %o0
a00adfd8:  92 10 20 00  clr  %o1
a00adfdc:  96 10 20 03  mov  3, %o3
a00adfe0:  98 10 20 0c  mov  0xc, %o4
a00adfe4:  10 bf ff d3  b  0xa00adf30
a00adfe8:  9a 10 20 01  mov  1, %o5
a00adfec:  d4 0c 21 5b  ldub  [ %l0 + 0x15b ], %o2
a00adff0:  90 0a a0 03  and  %o2, 3, %o0
a00adff4:  7f ff fe 1e  call  0xa00ad86c
a00adff8:  92 10 20 01  mov  1, %o1
a00adffc:  40 00 ac 49  call  0xa00d9120
a00ae000:  21 2a 00 ac  sethi  %hi(0xa802b000), %l0
a00ae004:  40 00 9a 65  call  0xa00d4998
a00ae008:  01 00 00 00  nop
a00ae00c:  d2 0c 20 8e  ldub  [ %l0 + 0x8e ], %o1
a00ae010:  90 12 60 02  or  %o1, 2, %o0
a00ae014:  d0 2c 20 8e  stb  %o0, [ %l0 + 0x8e ]
a00ae018:  81 c7 e0 08  ret
a00ae01c:  81 e8 00 00  restore
