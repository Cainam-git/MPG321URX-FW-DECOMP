# leon2s FUN_a00acc54 0xa00acc54-0xa00aceec (664 bytes)
a00acc54:  9d e3 bf 98  save  %sp, -104, %sp
a00acc58:  a2 0e 20 ff  and  %i0, 0xff, %l1
a00acc5c:  92 10 20 82  mov  0x82, %o1
a00acc60:  7f ff e7 d6  call  0xa00a6bb8
a00acc64:  90 10 00 11  mov  %l1, %o0
a00acc68:  a0 0a 20 ff  and  %o0, 0xff, %l0
a00acc6c:  92 10 20 83  mov  0x83, %o1
a00acc70:  7f ff e7 d2  call  0xa00a6bb8
a00acc74:  90 10 00 11  mov  %l1, %o0
a00acc78:  90 0a 20 ff  and  %o0, 0xff, %o0
a00acc7c:  a1 2c 20 08  sll  %l0, 8, %l0
a00acc80:  a0 14 00 08  or  %l0, %o0, %l0
a00acc84:  92 10 20 84  mov  0x84, %o1
a00acc88:  7f ff e7 cc  call  0xa00a6bb8
a00acc8c:  90 10 00 11  mov  %l1, %o0
a00acc90:  90 0a 20 ff  and  %o0, 0xff, %o0
a00acc94:  a1 2c 20 08  sll  %l0, 8, %l0
a00acc98:  a0 14 00 08  or  %l0, %o0, %l0
a00acc9c:  92 10 20 85  mov  0x85, %o1
a00acca0:  7f ff e7 c6  call  0xa00a6bb8
a00acca4:  90 10 00 11  mov  %l1, %o0
a00acca8:  a4 10 00 18  mov  %i0, %l2
a00accac:  b0 0a 20 ff  and  %o0, 0xff, %i0
a00accb0:  92 10 20 86  mov  0x86, %o1
a00accb4:  7f ff e7 c1  call  0xa00a6bb8
a00accb8:  90 10 00 11  mov  %l1, %o0
a00accbc:  90 0a 20 ff  and  %o0, 0xff, %o0
a00accc0:  b1 2e 20 08  sll  %i0, 8, %i0
a00accc4:  b0 16 00 08  or  %i0, %o0, %i0
a00accc8:  92 10 20 87  mov  0x87, %o1
a00acccc:  7f ff e7 bb  call  0xa00a6bb8
a00accd0:  90 10 00 11  mov  %l1, %o0
a00accd4:  90 0a 20 ff  and  %o0, 0xff, %o0
a00accd8:  b1 2e 20 08  sll  %i0, 8, %i0
a00accdc:  b0 16 00 08  or  %i0, %o0, %i0
a00acce0:  90 10 00 11  mov  %l1, %o0
a00acce4:  7f ff e7 b5  call  0xa00a6bb8
a00acce8:  92 10 20 03  mov  3, %o1
a00accec:  80 8a 20 20  btst  0x20, %o0
a00accf0:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00accf4:  02 80 00 05  be  0xa00acd08
a00accf8:  99 2c 60 02  sll  %l1, 2, %o4
a00accfc:  82 10 63 20  or  %g1, 0x320, %g1
a00acd00:  10 80 00 4a  b  0xa00ace28
a00acd04:  e0 20 40 0c  st  %l0, [ %g1 + %o4 ]
a00acd08:  96 10 00 01  mov  %g1, %o3
a00acd0c:  82 10 63 20  or  %g1, 0x320, %g1
a00acd10:  da 00 40 0c  ld  [ %g1 + %o4 ], %o5
a00acd14:  80 a4 00 0d  cmp  %l0, %o5
a00acd18:  28 80 00 0c  bleu,a   0xa00acd48
a00acd1c:  9a 12 e3 20  or  %o3, 0x320, %o5
a00acd20:  82 0c 20 fc  and  %l0, 0xfc, %g1
a00acd24:  80 a0 60 fc  cmp  %g1, 0xfc
a00acd28:  32 80 00 08  bne,a   0xa00acd48
a00acd2c:  9a 12 e3 20  or  %o3, 0x320, %o5
a00acd30:  82 24 00 0d  sub  %l0, %o5, %g1
a00acd34:  82 00 7f 07  add  %g1, -249, %g1
a00acd38:  80 a0 60 0a  cmp  %g1, 0xa
a00acd3c:  08 80 00 34  bleu  0xa00ace0c
a00acd40:  9a 0c a0 ff  and  %l2, 0xff, %o5
a00acd44:  9a 12 e3 20  or  %o3, 0x320, %o5
a00acd48:  83 2c 60 02  sll  %l1, 2, %g1
a00acd4c:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a00acd50:  80 a4 00 01  cmp  %l0, %g1
a00acd54:  1a 80 00 0b  bcc  0xa00acd80
a00acd58:  9a 12 e3 20  or  %o3, 0x320, %o5
a00acd5c:  80 8c 20 fc  btst  0xfc, %l0
a00acd60:  32 80 00 09  bne,a   0xa00acd84
a00acd64:  83 2c 60 02  sll  %l1, 2, %g1
a00acd68:  82 20 40 10  sub  %g1, %l0, %g1
a00acd6c:  82 00 7f 07  add  %g1, -249, %g1
a00acd70:  80 a0 60 0a  cmp  %g1, 0xa
a00acd74:  08 80 00 26  bleu  0xa00ace0c
a00acd78:  9a 0c a0 ff  and  %l2, 0xff, %o5
a00acd7c:  9a 12 e3 20  or  %o3, 0x320, %o5
a00acd80:  83 2c 60 02  sll  %l1, 2, %g1
a00acd84:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a00acd88:  80 a4 00 0c  cmp  %l0, %o4
a00acd8c:  08 80 00 10  bleu  0xa00acdcc
a00acd90:  9a 12 e3 20  or  %o3, 0x320, %o5
a00acd94:  1b 00 00 3f  sethi  %hi(0xfc00), %o5
a00acd98:  82 0c 00 0d  and  %l0, %o5, %g1
a00acd9c:  80 a0 40 0d  cmp  %g1, %o5
a00acda0:  12 80 00 0a  bne  0xa00acdc8
a00acda4:  9a 12 e3 20  or  %o3, 0x320, %o5
a00acda8:  03 3f ff c1  sethi  %hi(0xffff0400), %g1
a00acdac:  9a 24 00 0c  sub  %l0, %o4, %o5
a00acdb0:  82 10 63 ff  or  %g1, 0x3ff, %g1
a00acdb4:  9a 03 40 01  add  %o5, %g1, %o5
a00acdb8:  80 a3 6b fe  cmp  %o5, 0xbfe
a00acdbc:  08 80 00 14  bleu  0xa00ace0c
a00acdc0:  9a 0c a0 ff  and  %l2, 0xff, %o5
a00acdc4:  9a 12 e3 20  or  %o3, 0x320, %o5
a00acdc8:  83 2c 60 02  sll  %l1, 2, %g1
a00acdcc:  da 03 40 01  ld  [ %o5 + %g1 ], %o5
a00acdd0:  80 a4 00 0d  cmp  %l0, %o5
a00acdd4:  3a 80 00 13  bcc,a   0xa00ace20
a00acdd8:  9a 12 e3 20  or  %o3, 0x320, %o5
a00acddc:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a00acde0:  80 8c 00 01  btst  %l0, %g1
a00acde4:  32 80 00 0f  bne,a   0xa00ace20
a00acde8:  9a 12 e3 20  or  %o3, 0x320, %o5
a00acdec:  03 3f ff c1  sethi  %hi(0xffff0400), %g1
a00acdf0:  9a 23 40 10  sub  %o5, %l0, %o5
a00acdf4:  82 10 63 ff  or  %g1, 0x3ff, %g1
a00acdf8:  9a 03 40 01  add  %o5, %g1, %o5
a00acdfc:  80 a3 6b fe  cmp  %o5, 0xbfe
a00ace00:  18 80 00 08  bgu  0xa00ace20
a00ace04:  9a 12 e3 20  or  %o3, 0x320, %o5
a00ace08:  9a 0c a0 ff  and  %l2, 0xff, %o5
a00ace0c:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00ace10:  9b 2b 60 02  sll  %o5, 2, %o5
a00ace14:  82 10 63 20  or  %g1, 0x320, %g1
a00ace18:  10 80 00 04  b  0xa00ace28
a00ace1c:  e0 00 40 0d  ld  [ %g1 + %o5 ], %l0
a00ace20:  83 2c 60 02  sll  %l1, 2, %g1
a00ace24:  e0 23 40 01  st  %l0, [ %o5 + %g1 ]
a00ace28:  80 a6 20 00  cmp  %i0, 0
a00ace2c:  22 80 00 02  be,a   0xa00ace34
a00ace30:  b0 10 20 01  mov  1, %i0
a00ace34:  a2 0c a0 ff  and  %l2, 0xff, %l1
a00ace38:  90 10 00 11  mov  %l1, %o0
a00ace3c:  7f ff e7 5f  call  0xa00a6bb8
a00ace40:  92 10 20 80  mov  0x80, %o1
a00ace44:  90 0a 20 03  and  %o0, 3, %o0
a00ace48:  80 a2 20 01  cmp  %o0, 1
a00ace4c:  02 80 00 0b  be  0xa00ace78
a00ace50:  82 5c 21 0e  smul  %l0, 0x10e, %g1
a00ace54:  80 a2 20 01  cmp  %o0, 1
a00ace58:  04 80 00 07  ble  0xa00ace74
a00ace5c:  80 a2 20 02  cmp  %o0, 2
a00ace60:  02 80 00 06  be  0xa00ace78
a00ace64:  82 5c 22 1c  smul  %l0, 0x21c, %g1
a00ace68:  80 a2 20 03  cmp  %o0, 3
a00ace6c:  02 80 00 03  be  0xa00ace78
a00ace70:  82 5c 23 2a  smul  %l0, 0x32a, %g1
a00ace74:  82 5c 20 a2  smul  %l0, 0xa2, %g1
a00ace78:  81 80 00 00  mov  %g0, %y
a00ace7c:  01 00 00 00  nop
a00ace80:  01 00 00 00  nop
a00ace84:  01 00 00 00  nop
a00ace88:  b0 70 40 18  udiv  %g1, %i0, %i0
a00ace8c:  90 10 00 11  mov  %l1, %o0
a00ace90:  7f ff e7 4a  call  0xa00a6bb8
a00ace94:  92 10 20 d7  mov  0xd7, %o1
a00ace98:  80 8a 20 10  btst  0x10, %o0
a00ace9c:  02 80 00 04  be  0xa00aceac
a00acea0:  90 10 00 11  mov  %l1, %o0
a00acea4:  10 80 00 0e  b  0xa00acedc
a00acea8:  b1 2e 20 03  sll  %i0, 3, %i0
a00aceac:  7f ff e7 43  call  0xa00a6bb8
a00aceb0:  92 10 20 d7  mov  0xd7, %o1
a00aceb4:  80 8a 20 04  btst  4, %o0
a00aceb8:  02 80 00 04  be  0xa00acec8
a00acebc:  90 10 00 11  mov  %l1, %o0
a00acec0:  10 80 00 07  b  0xa00acedc
a00acec4:  b1 2e 20 02  sll  %i0, 2, %i0
a00acec8:  7f ff e7 3c  call  0xa00a6bb8
a00acecc:  92 10 20 d5  mov  0xd5, %o1
a00aced0:  80 8a 20 20  btst  0x20, %o0
a00aced4:  32 80 00 02  bne,a   0xa00acedc
a00aced8:  b0 06 00 18  add  %i0, %i0, %i0
a00acedc:  b1 2e 20 10  sll  %i0, 0x10, %i0
a00acee0:  b1 36 20 10  srl  %i0, 0x10, %i0
a00acee4:  81 c7 e0 08  ret
a00acee8:  81 e8 00 00  restore
