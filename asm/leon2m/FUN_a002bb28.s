# leon2m FUN_a002bb28 0xa002bb28-0xa002be7c (852 bytes)
a002bb28:  9d e3 bf 98  save  %sp, -104, %sp
a002bb2c:  d6 16 00 00  lduh  [ %i0 ], %o3
a002bb30:  23 2a 00 b6  sethi  %hi(0xa802d800), %l1
a002bb34:  d6 34 61 92  sth  %o3, [ %l1 + 0x192 ]	! 0xa802d992
a002bb38:  98 14 61 92  or  %l1, 0x192, %o4
a002bb3c:  d4 16 20 02  lduh  [ %i0 + 2 ], %o2
a002bb40:  d4 33 20 02  sth  %o2, [ %o4 + 2 ]
a002bb44:  d2 16 20 04  lduh  [ %i0 + 4 ], %o1
a002bb48:  d2 33 20 04  sth  %o1, [ %o4 + 4 ]
a002bb4c:  d0 16 20 06  lduh  [ %i0 + 6 ], %o0
a002bb50:  d0 33 20 06  sth  %o0, [ %o4 + 6 ]
a002bb54:  c2 16 20 08  lduh  [ %i0 + 8 ], %g1
a002bb58:  da 0b 20 07  ldub  [ %o4 + 7 ], %o5
a002bb5c:  c2 33 20 08  sth  %g1, [ %o4 + 8 ]
a002bb60:  80 a3 60 01  cmp  %o5, 1
a002bb64:  b0 10 00 19  mov  %i1, %i0
a002bb68:  02 80 00 0e  be  0xa002bba0
a002bb6c:  a6 10 20 00  clr  %l3
a002bb70:  a0 14 61 92  or  %l1, 0x192, %l0
a002bb74:  d0 14 20 08  lduh  [ %l0 + 8 ], %o0
a002bb78:  13 3f ff f0  sethi  %hi(0xffffc000), %o1
a002bb7c:  f2 0b 20 06  ldub  [ %o4 + 6 ], %i1
a002bb80:  82 0a 00 09  and  %o0, %o1, %g1
a002bb84:  9b 28 60 10  sll  %g1, 0x10, %o5
a002bb88:  19 20 00 00  sethi  %hi(0x80000000), %o4
a002bb8c:  80 a3 40 0c  cmp  %o5, %o4
a002bb90:  02 80 00 11  be  0xa002bbd4
a002bb94:  9b 2c e0 10  sll  %l3, 0x10, %o5
a002bb98:  10 80 00 b7  b  0xa002be74
a002bb9c:  b1 33 60 10  srl  %o5, 0x10, %i0
a002bba0:  a5 36 60 07  srl  %i1, 7, %l2
a002bba4:  a0 0c a0 0e  and  %l2, 0xe, %l0
a002bba8:  de 0b 20 06  ldub  [ %o4 + 6 ], %o7
a002bbac:  b2 14 00 0f  or  %l0, %o7, %i1
a002bbb0:  a0 14 61 92  or  %l1, 0x192, %l0
a002bbb4:  d0 14 20 08  lduh  [ %l0 + 8 ], %o0
a002bbb8:  13 3f ff f0  sethi  %hi(0xffffc000), %o1
a002bbbc:  82 0a 00 09  and  %o0, %o1, %g1
a002bbc0:  9b 28 60 10  sll  %g1, 0x10, %o5
a002bbc4:  19 20 00 00  sethi  %hi(0x80000000), %o4
a002bbc8:  80 a3 40 0c  cmp  %o5, %o4
a002bbcc:  12 bf ff f3  bne  0xa002bb98
a002bbd0:  9b 2c e0 10  sll  %l3, 0x10, %o5
a002bbd4:  7f ff fb 4f  call  0xa002a910
a002bbd8:  a4 10 00 10  mov  %l0, %l2
a002bbdc:  b2 0e 60 ff  and  %i1, 0xff, %i1
a002bbe0:  a0 10 20 00  clr  %l0
a002bbe4:  7f ff fb c8  call  0xa002ab04
a002bbe8:  90 10 00 19  mov  %i1, %o0
a002bbec:  80 8a 20 ff  btst  0xff, %o0
a002bbf0:  22 80 00 0d  be,a   0xa002bc24
a002bbf4:  a5 2c 20 10  sll  %l0, 0x10, %l2
a002bbf8:  da 14 a0 04  lduh  [ %l2 + 4 ], %o5
a002bbfc:  99 2b 60 11  sll  %o5, 0x11, %o4
a002bc00:  40 00 05 8f  call  0xa002d23c
a002bc04:  91 33 20 10  srl  %o4, 0x10, %o0
a002bc08:  94 04 20 01  add  %l0, 1, %o2
a002bc0c:  9f 2a a0 10  sll  %o2, 0x10, %o7
a002bc10:  97 33 e0 10  srl  %o7, 0x10, %o3
a002bc14:  80 a2 e0 09  cmp  %o3, 9
a002bc18:  08 bf ff f3  bleu  0xa002bbe4
a002bc1c:  a0 10 00 0a  mov  %o2, %l0
a002bc20:  a5 2c 20 10  sll  %l0, 0x10, %l2
a002bc24:  b3 34 a0 10  srl  %l2, 0x10, %i1
a002bc28:  80 a6 60 0a  cmp  %i1, 0xa
a002bc2c:  02 80 00 64  be  0xa002bdbc
a002bc30:  90 14 61 92  or  %l1, 0x192, %o0
a002bc34:  e0 0a 20 07  ldub  [ %o0 + 7 ], %l0
a002bc38:  80 a4 20 01  cmp  %l0, 1
a002bc3c:  02 80 00 04  be  0xa002bc4c
a002bc40:  93 2e 20 10  sll  %i0, 0x10, %o1
a002bc44:  7f ff fb b0  call  0xa002ab04
a002bc48:  91 32 60 18  srl  %o1, 0x18, %o0
a002bc4c:  7f ff fb ae  call  0xa002ab04
a002bc50:  90 0e 20 ff  and  %i0, 0xff, %o0
a002bc54:  7f ff fb 2f  call  0xa002a910
a002bc58:  a0 10 20 00  clr  %l0
a002bc5c:  15 2a 00 b6  sethi  %hi(0xa802d800), %o2
a002bc60:  b2 12 a1 92  or  %o2, 0x192, %i1	! 0xa802d992
a002bc64:  d6 0e 60 06  ldub  [ %i1 + 6 ], %o3
a002bc68:  7f ff fb a7  call  0xa002ab04
a002bc6c:  90 12 e0 01  or  %o3, 1, %o0
a002bc70:  80 8a 20 ff  btst  0xff, %o0
a002bc74:  22 80 00 0d  be,a   0xa002bca8
a002bc78:  b3 2e a0 10  sll  %i2, 0x10, %i1
a002bc7c:  f0 16 60 04  lduh  [ %i1 + 4 ], %i0
a002bc80:  a5 2e 20 11  sll  %i0, 0x11, %l2
a002bc84:  40 00 05 6e  call  0xa002d23c
a002bc88:  91 34 a0 10  srl  %l2, 0x10, %o0
a002bc8c:  9e 04 20 01  add  %l0, 1, %o7
a002bc90:  9b 2b e0 10  sll  %o7, 0x10, %o5
a002bc94:  99 33 60 10  srl  %o5, 0x10, %o4
a002bc98:  80 a3 20 09  cmp  %o4, 9
a002bc9c:  08 bf ff f2  bleu  0xa002bc64
a002bca0:  a0 10 00 0f  mov  %o7, %l0
a002bca4:  b3 2e a0 10  sll  %i2, 0x10, %i1
a002bca8:  83 36 60 10  srl  %i1, 0x10, %g1
a002bcac:  80 a0 60 00  cmp  %g1, 0
a002bcb0:  02 80 00 14  be  0xa002bd00
a002bcb4:  b2 10 20 00  clr  %i1
a002bcb8:  b4 10 00 01  mov  %g1, %i2
a002bcbc:  93 2e 60 10  sll  %i1, 0x10, %o1
a002bcc0:  a1 32 60 10  srl  %o1, 0x10, %l0
a002bcc4:  82 00 7f ff  add  %g1, -1, %g1
a002bcc8:  80 a4 00 01  cmp  %l0, %g1
a002bccc:  02 80 00 03  be  0xa002bcd8
a002bcd0:  90 10 20 01  mov  1, %o0
a002bcd4:  90 10 20 00  clr  %o0
a002bcd8:  7f ff fc 5d  call  0xa002ae4c
a002bcdc:  a6 04 e0 01  inc  %l3
a002bce0:  d0 2c 00 1b  stb  %o0, [ %l0 + %i3 ]
a002bce4:  a0 06 60 01  add  %i1, 1, %l0
a002bce8:  95 2c 20 10  sll  %l0, 0x10, %o2
a002bcec:  91 32 a0 10  srl  %o2, 0x10, %o0
a002bcf0:  80 a2 00 1a  cmp  %o0, %i2
a002bcf4:  b2 10 00 10  mov  %l0, %i1
a002bcf8:  0a bf ff f1  bcs  0xa002bcbc
a002bcfc:  82 10 00 1a  mov  %i2, %g1
a002bd00:  a0 14 61 92  or  %l1, 0x192, %l0
a002bd04:  d2 0c 20 03  ldub  [ %l0 + 3 ], %o1
a002bd08:  94 10 20 00  clr  %o2
a002bd0c:  40 00 02 d8  call  0xa002c86c
a002bd10:  d0 0c 20 02  ldub  [ %l0 + 2 ], %o0
a002bd14:  f6 14 20 04  lduh  [ %l0 + 4 ], %i3
a002bd18:  b5 2e e0 11  sll  %i3, 0x11, %i2
a002bd1c:  40 00 05 48  call  0xa002d23c
a002bd20:  91 36 a0 10  srl  %i2, 0x10, %o0
a002bd24:  d0 0c 61 92  ldub  [ %l1 + 0x192 ], %o0
a002bd28:  d2 0c 20 01  ldub  [ %l0 + 1 ], %o1
a002bd2c:  40 00 02 d0  call  0xa002c86c
a002bd30:  94 10 20 01  mov  1, %o2
a002bd34:  d0 0c 61 92  ldub  [ %l1 + 0x192 ], %o0
a002bd38:  d2 0c 20 01  ldub  [ %l0 + 1 ], %o1
a002bd3c:  40 00 03 7d  call  0xa002cb30
a002bd40:  94 10 20 01  mov  1, %o2
a002bd44:  10 80 00 07  b  0xa002bd60
a002bd48:  b6 10 3f ff  mov  -1, %i3
a002bd4c:  80 a3 60 00  cmp  %o5, 0
a002bd50:  02 80 00 0d  be  0xa002bd84
a002bd54:  19 2a 00 b6  sethi  %hi(0xa802d800), %o4
a002bd58:  01 00 00 00  nop
a002bd5c:  01 00 00 00  nop
a002bd60:  d0 0c 61 92  ldub  [ %l1 + 0x192 ], %o0
a002bd64:  40 00 03 f5  call  0xa002cd38
a002bd68:  d2 0c 20 01  ldub  [ %l0 + 1 ], %o1
a002bd6c:  96 06 ff ff  add  %i3, -1, %o3
a002bd70:  9b 2a e0 10  sll  %o3, 0x10, %o5
a002bd74:  80 8a 20 ff  btst  0xff, %o0
a002bd78:  02 bf ff f5  be  0xa002bd4c
a002bd7c:  b6 10 00 0b  mov  %o3, %i3
a002bd80:  19 2a 00 b6  sethi  %hi(0xa802d800), %o4
a002bd84:  d0 0b 21 92  ldub  [ %o4 + 0x192 ], %o0	! 0xa802d992
a002bd88:  d2 0c 20 01  ldub  [ %l0 + 1 ], %o1
a002bd8c:  40 00 03 69  call  0xa002cb30
a002bd90:  94 10 20 00  clr  %o2
a002bd94:  de 14 20 04  lduh  [ %l0 + 4 ], %o7
a002bd98:  a3 2b e0 11  sll  %o7, 0x11, %l1
a002bd9c:  40 00 05 28  call  0xa002d23c
a002bda0:  91 34 60 10  srl  %l1, 0x10, %o0
a002bda4:  d2 0c 20 03  ldub  [ %l0 + 3 ], %o1
a002bda8:  d0 0c 20 02  ldub  [ %l0 + 2 ], %o0
a002bdac:  40 00 02 b0  call  0xa002c86c
a002bdb0:  94 10 20 01  mov  1, %o2
a002bdb4:  10 bf ff 79  b  0xa002bb98
a002bdb8:  9b 2c e0 10  sll  %l3, 0x10, %o5
a002bdbc:  a0 14 61 92  or  %l1, 0x192, %l0
a002bdc0:  d2 0c 20 03  ldub  [ %l0 + 3 ], %o1
a002bdc4:  94 10 20 00  clr  %o2
a002bdc8:  40 00 02 a9  call  0xa002c86c
a002bdcc:  d0 0c 20 02  ldub  [ %l0 + 2 ], %o0
a002bdd0:  f0 14 20 04  lduh  [ %l0 + 4 ], %i0
a002bdd4:  a7 2e 20 11  sll  %i0, 0x11, %l3
a002bdd8:  40 00 05 19  call  0xa002d23c
a002bddc:  91 34 e0 10  srl  %l3, 0x10, %o0
a002bde0:  d0 0c 61 92  ldub  [ %l1 + 0x192 ], %o0
a002bde4:  d2 0c 20 01  ldub  [ %l0 + 1 ], %o1
a002bde8:  40 00 02 a1  call  0xa002c86c
a002bdec:  94 10 20 01  mov  1, %o2
a002bdf0:  d0 0c 61 92  ldub  [ %l1 + 0x192 ], %o0
a002bdf4:  d2 0c 20 01  ldub  [ %l0 + 1 ], %o1
a002bdf8:  40 00 03 4e  call  0xa002cb30
a002bdfc:  94 10 20 01  mov  1, %o2
a002be00:  10 80 00 07  b  0xa002be1c
a002be04:  a4 10 3f ff  mov  -1, %l2
a002be08:  80 a3 60 00  cmp  %o5, 0
a002be0c:  02 80 00 0d  be  0xa002be40
a002be10:  03 2a 00 b6  sethi  %hi(0xa802d800), %g1
a002be14:  01 00 00 00  nop
a002be18:  01 00 00 00  nop
a002be1c:  d0 0c 61 92  ldub  [ %l1 + 0x192 ], %o0
a002be20:  40 00 03 c6  call  0xa002cd38
a002be24:  d2 0c 20 01  ldub  [ %l0 + 1 ], %o1
a002be28:  b4 04 bf ff  add  %l2, -1, %i2
a002be2c:  9b 2e a0 10  sll  %i2, 0x10, %o5
a002be30:  80 8a 20 ff  btst  0xff, %o0
a002be34:  02 bf ff f5  be  0xa002be08
a002be38:  a4 10 00 1a  mov  %i2, %l2
a002be3c:  03 2a 00 b6  sethi  %hi(0xa802d800), %g1
a002be40:  d0 08 61 92  ldub  [ %g1 + 0x192 ], %o0	! 0xa802d992
a002be44:  d2 0c 20 01  ldub  [ %l0 + 1 ], %o1
a002be48:  40 00 03 3a  call  0xa002cb30
a002be4c:  94 10 20 00  clr  %o2
a002be50:  f6 14 20 04  lduh  [ %l0 + 4 ], %i3
a002be54:  a3 2e e0 11  sll  %i3, 0x11, %l1
a002be58:  40 00 04 f9  call  0xa002d23c
a002be5c:  91 34 60 10  srl  %l1, 0x10, %o0
a002be60:  d2 0c 20 03  ldub  [ %l0 + 3 ], %o1
a002be64:  d0 0c 20 02  ldub  [ %l0 + 2 ], %o0
a002be68:  40 00 02 81  call  0xa002c86c
a002be6c:  94 10 20 01  mov  1, %o2
a002be70:  b0 10 20 00  clr  %i0
a002be74:  81 c7 e0 08  ret
a002be78:  81 e8 00 00  restore
