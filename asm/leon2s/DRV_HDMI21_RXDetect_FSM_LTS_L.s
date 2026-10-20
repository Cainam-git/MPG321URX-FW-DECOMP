# leon2s DRV_HDMI21_RXDetect_FSM_LTS_L 0xa009bba8-0xa009bef0 (840 bytes)
a009bba8:  9d e3 bf 98  save  %sp, -104, %sp
a009bbac:  96 0e 20 ff  and  %i0, 0xff, %o3
a009bbb0:  80 a2 e0 00  cmp  %o3, 0
a009bbb4:  02 80 00 05  be  0xa009bbc8
a009bbb8:  aa 10 20 02  mov  2, %l5
a009bbbc:  80 a2 e0 01  cmp  %o3, 1
a009bbc0:  12 80 00 ca  bne  0xa009bee8
a009bbc4:  aa 10 20 03  mov  3, %l5
a009bbc8:  25 2a 01 f5  sethi  %hi(0xa807d400), %l2
a009bbcc:  82 14 a2 80  or  %l2, 0x280, %g1	! 0xa807d680
a009bbd0:  9a 5a e0 b0  smul  %o3, 0xb0, %o5
a009bbd4:  9a 03 40 01  add  %o5, %g1, %o5
a009bbd8:  23 2a 01 f5  sethi  %hi(0xa807d400), %l1
a009bbdc:  83 2a e0 02  sll  %o3, 2, %g1
a009bbe0:  98 14 62 48  or  %l1, 0x248, %o4
a009bbe4:  d8 03 00 01  ld  [ %o4 + %g1 ], %o4
a009bbe8:  c2 03 60 30  ld  [ %o5 + 0x30 ], %g1
a009bbec:  80 a3 00 01  cmp  %o4, %g1
a009bbf0:  02 80 00 57  be  0xa009bd4c
a009bbf4:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a009bbf8:  9a 5a e0 34  smul  %o3, 0x34, %o5
a009bbfc:  82 10 63 00  or  %g1, 0x300, %g1
a009bc00:  98 03 40 01  add  %o5, %g1, %o4
a009bc04:  03 3c 3f ff  sethi  %hi(0xf0fffc00), %g1
a009bc08:  92 10 63 ff  or  %g1, 0x3ff, %o1	! 0xf0ffffff
a009bc0c:  03 03 ff ff  sethi  %hi(0xffffc00), %g1
a009bc10:  94 10 63 ff  or  %g1, 0x3ff, %o2	! 0xfffffff
a009bc14:  96 10 20 00  clr  %o3
a009bc18:  82 0a e0 ff  and  %o3, 0xff, %g1
a009bc1c:  80 a0 60 00  cmp  %g1, 0
a009bc20:  12 80 00 06  bne  0xa009bc38
a009bc24:  80 a0 60 01  cmp  %g1, 1
a009bc28:  da 03 20 18  ld  [ %o4 + 0x18 ], %o5
a009bc2c:  c2 03 60 a0  ld  [ %o5 + 0xa0 ], %g1
a009bc30:  10 80 00 07  b  0xa009bc4c
a009bc34:  82 08 40 09  and  %g1, %o1, %g1
a009bc38:  12 80 00 08  bne  0xa009bc58
a009bc3c:  80 a0 60 02  cmp  %g1, 2
a009bc40:  da 03 20 18  ld  [ %o4 + 0x18 ], %o5
a009bc44:  c2 03 60 a0  ld  [ %o5 + 0xa0 ], %g1
a009bc48:  82 08 40 0a  and  %g1, %o2, %g1
a009bc4c:  c2 23 60 a0  st  %g1, [ %o5 + 0xa0 ]
a009bc50:  10 80 00 0f  b  0xa009bc8c
a009bc54:  96 02 e0 01  inc  %o3
a009bc58:  12 80 00 06  bne  0xa009bc70
a009bc5c:  80 a0 60 03  cmp  %g1, 3
a009bc60:  da 03 20 18  ld  [ %o4 + 0x18 ], %o5
a009bc64:  c2 03 60 a4  ld  [ %o5 + 0xa4 ], %g1
a009bc68:  10 80 00 07  b  0xa009bc84
a009bc6c:  82 08 7f f0  and  %g1, -16, %g1
a009bc70:  32 80 00 07  bne,a   0xa009bc8c
a009bc74:  96 02 e0 01  inc  %o3
a009bc78:  da 03 20 18  ld  [ %o4 + 0x18 ], %o5
a009bc7c:  c2 03 60 a4  ld  [ %o5 + 0xa4 ], %g1
a009bc80:  82 08 7f 0f  and  %g1, -241, %g1
a009bc84:  c2 23 60 a4  st  %g1, [ %o5 + 0xa4 ]
a009bc88:  96 02 e0 01  inc  %o3
a009bc8c:  82 0a e0 ff  and  %o3, 0xff, %g1
a009bc90:  80 a0 60 03  cmp  %g1, 3
a009bc94:  08 bf ff e3  bleu  0xa009bc20
a009bc98:  80 a0 60 00  cmp  %g1, 0
a009bc9c:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009bca0:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a009bca4:  80 88 68 00  btst  0x800, %g1
a009bca8:  02 80 00 08  be  0xa009bcc8
a009bcac:  a0 0e 20 ff  and  %i0, 0xff, %l0
a009bcb0:  11 28 01 9e  sethi  %hi(0xa0067800), %o0
a009bcb4:  13 28 02 d0  sethi  %hi(0xa00b4000), %o1
a009bcb8:  90 12 20 68  or  %o0, 0x68, %o0
a009bcbc:  7f ff 5c e2  call  0xa0073044
a009bcc0:  92 12 63 f8  or  %o1, 0x3f8, %o1
a009bcc4:  a0 0e 20 ff  and  %i0, 0xff, %l0
a009bcc8:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a009bccc:  82 10 63 00  or  %g1, 0x300, %g1	! 0xa807db00
a009bcd0:  98 5c 20 34  smul  %l0, 0x34, %o4
a009bcd4:  98 03 00 01  add  %o4, %g1, %o4
a009bcd8:  96 14 a2 80  or  %l2, 0x280, %o3
a009bcdc:  9a 5c 20 b0  smul  %l0, 0xb0, %o5
a009bce0:  9a 03 40 0b  add  %o5, %o3, %o5
a009bce4:  94 14 62 48  or  %l1, 0x248, %o2
a009bce8:  83 2c 20 02  sll  %l0, 2, %g1
a009bcec:  d6 02 80 01  ld  [ %o2 + %g1 ], %o3
a009bcf0:  d2 03 20 18  ld  [ %o4 + 0x18 ], %o1
a009bcf4:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a009bcf8:  98 04 00 10  add  %l0, %l0, %o4
a009bcfc:  82 10 60 54  or  %g1, 0x54, %g1
a009bd00:  c0 30 40 0c  clrh  [ %g1 + %o4 ]
a009bd04:  d6 23 60 30  st  %o3, [ %o5 + 0x30 ]
a009bd08:  c0 2b 60 02  clrb  [ %o5 + 2 ]
a009bd0c:  92 02 60 a0  add  %o1, 0xa0, %o1
a009bd10:  40 00 2d a7  call  0xa00a73ac
a009bd14:  90 10 20 16  mov  0x16, %o0
a009bd18:  7f ff fe 37  call  0xa009b5f4
a009bd1c:  90 10 00 10  mov  %l0, %o0
a009bd20:  23 00 00 0d  sethi  %hi(0x3400), %l1
a009bd24:  90 10 20 00  clr  %o0
a009bd28:  92 10 20 00  clr  %o1
a009bd2c:  94 10 00 10  mov  %l0, %o2
a009bd30:  40 00 2d bd  call  0xa00a7424
a009bd34:  96 14 62 00  or  %l1, 0x200, %o3
a009bd38:  94 10 00 10  mov  %l0, %o2
a009bd3c:  96 14 62 00  or  %l1, 0x200, %o3
a009bd40:  90 10 20 00  clr  %o0
a009bd44:  40 00 2d b8  call  0xa00a7424
a009bd48:  92 10 20 01  mov  1, %o1
a009bd4c:  29 2a 01 f6  sethi  %hi(0xa807d800), %l4
a009bd50:  a0 0e 20 ff  and  %i0, 0xff, %l0
a009bd54:  82 5c 20 34  smul  %l0, 0x34, %g1
a009bd58:  9a 15 23 00  or  %l4, 0x300, %o5
a009bd5c:  a2 00 40 0d  add  %g1, %o5, %l1
a009bd60:  d2 04 60 18  ld  [ %l1 + 0x18 ], %o1
a009bd64:  c2 02 60 90  ld  [ %o1 + 0x90 ], %g1
a009bd68:  83 30 60 18  srl  %g1, 0x18, %g1
a009bd6c:  80 88 60 0f  btst  0xf, %g1
a009bd70:  02 80 00 0c  be  0xa009bda0
a009bd74:  27 2a 01 f5  sethi  %hi(0xa807d400), %l3
a009bd78:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a009bd7c:  82 10 62 48  or  %g1, 0x248, %g1	! 0xa807d648
a009bd80:  99 2c 20 02  sll  %l0, 2, %o4
a009bd84:  9a 10 20 03  mov  3, %o5
a009bd88:  da 20 40 0c  st  %o5, [ %g1 + %o4 ]
a009bd8c:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a009bd90:  96 04 00 10  add  %l0, %l0, %o3
a009bd94:  82 10 60 54  or  %g1, 0x54, %g1
a009bd98:  10 80 00 54  b  0xa009bee8
a009bd9c:  c0 30 40 0b  clrh  [ %g1 + %o3 ]
a009bda0:  82 14 e3 e0  or  %l3, 0x3e0, %g1
a009bda4:  9a 5c 21 90  smul  %l0, 0x190, %o5
a009bda8:  9a 03 40 01  add  %o5, %g1, %o5
a009bdac:  c2 0b 60 01  ldub  [ %o5 + 1 ], %g1
a009bdb0:  80 a0 60 01  cmp  %g1, 1
a009bdb4:  12 80 00 06  bne  0xa009bdcc
a009bdb8:  25 2a 01 e4  sethi  %hi(0xa8079000), %l2
a009bdbc:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a009bdc0:  9a 04 00 10  add  %l0, %l0, %o5
a009bdc4:  82 10 60 54  or  %g1, 0x54, %g1
a009bdc8:  c0 30 40 0d  clrh  [ %g1 + %o5 ]
a009bdcc:  98 14 a0 54  or  %l2, 0x54, %o4
a009bdd0:  9a 04 00 10  add  %l0, %l0, %o5
a009bdd4:  c2 13 00 0d  lduh  [ %o4 + %o5 ], %g1
a009bdd8:  80 a0 62 bc  cmp  %g1, 0x2bc
a009bddc:  08 80 00 11  bleu  0xa009be20
a009bde0:  80 a0 60 64  cmp  %g1, 0x64
a009bde4:  c0 33 00 0d  clrh  [ %o4 + %o5 ]
a009bde8:  7f ff f3 5e  call  0xa0098b60
a009bdec:  90 10 00 10  mov  %l0, %o0
a009bdf0:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009bdf4:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a009bdf8:  80 88 68 00  btst  0x800, %g1
a009bdfc:  22 80 00 36  be,a   0xa009bed4
a009be00:  82 0e 20 ff  and  %i0, 0xff, %g1
a009be04:  11 28 01 a9  sethi  %hi(0xa006a400), %o0
a009be08:  92 10 00 10  mov  %l0, %o1
a009be0c:  94 10 20 01  mov  1, %o2
a009be10:  7f ff 5c 8d  call  0xa0073044
a009be14:  90 12 21 d8  or  %o0, 0x1d8, %o0
a009be18:  10 80 00 2f  b  0xa009bed4
a009be1c:  82 0e 20 ff  and  %i0, 0xff, %g1
a009be20:  08 80 00 0d  bleu  0xa009be54
a009be24:  9a 0d 60 ff  and  %l5, 0xff, %o5
a009be28:  92 02 60 90  add  %o1, 0x90, %o1
a009be2c:  40 00 2d 77  call  0xa00a7408
a009be30:  90 10 20 11  mov  0x11, %o0
a009be34:  80 a2 20 00  cmp  %o0, 0
a009be38:  02 80 00 07  be  0xa009be54
a009be3c:  9a 0d 60 ff  and  %l5, 0xff, %o5
a009be40:  d2 04 60 18  ld  [ %l1 + 0x18 ], %o1
a009be44:  92 02 60 90  add  %o1, 0x90, %o1
a009be48:  40 00 2d 63  call  0xa00a73d4
a009be4c:  90 10 20 11  mov  0x11, %o0
a009be50:  9a 0d 60 ff  and  %l5, 0xff, %o5
a009be54:  82 03 40 0d  add  %o5, %o5, %g1
a009be58:  82 00 40 0d  add  %g1, %o5, %g1
a009be5c:  1b 2a 01 f3  sethi  %hi(0xa807cc00), %o5
a009be60:  83 28 60 03  sll  %g1, 3, %g1
a009be64:  9a 13 60 64  or  %o5, 0x64, %o5
a009be68:  82 00 40 0d  add  %g1, %o5, %g1
a009be6c:  c2 08 60 06  ldub  [ %g1 + 6 ], %g1
a009be70:  80 a0 60 00  cmp  %g1, 0
a009be74:  02 80 00 18  be  0xa009bed4
a009be78:  82 0e 20 ff  and  %i0, 0xff, %g1
a009be7c:  82 15 23 00  or  %l4, 0x300, %g1
a009be80:  9a 5c 20 34  smul  %l0, 0x34, %o5
a009be84:  d2 00 40 0d  ld  [ %g1 + %o5 ], %o1
a009be88:  92 02 60 04  add  %o1, 4, %o1
a009be8c:  40 00 2d 5f  call  0xa00a7408
a009be90:  90 10 20 11  mov  0x11, %o0
a009be94:  80 a2 20 00  cmp  %o0, 0
a009be98:  02 80 00 0f  be  0xa009bed4
a009be9c:  82 0e 20 ff  and  %i0, 0xff, %g1
a009bea0:  82 14 e3 e0  or  %l3, 0x3e0, %g1
a009bea4:  9a 5c 21 90  smul  %l0, 0x190, %o5
a009bea8:  9a 03 40 01  add  %o5, %g1, %o5
a009beac:  c2 0b 60 01  ldub  [ %o5 + 1 ], %g1
a009beb0:  80 a0 60 00  cmp  %g1, 0
a009beb4:  12 80 00 08  bne  0xa009bed4
a009beb8:  82 0e 20 ff  and  %i0, 0xff, %g1
a009bebc:  98 14 a0 54  or  %l2, 0x54, %o4
a009bec0:  9a 04 00 10  add  %l0, %l0, %o5
a009bec4:  c2 13 00 0d  lduh  [ %o4 + %o5 ], %g1
a009bec8:  82 00 60 01  inc  %g1
a009becc:  c2 33 00 0d  sth  %g1, [ %o4 + %o5 ]
a009bed0:  82 0e 20 ff  and  %i0, 0xff, %g1
a009bed4:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a009bed8:  83 28 60 02  sll  %g1, 2, %g1
a009bedc:  98 10 20 07  mov  7, %o4
a009bee0:  9a 13 62 48  or  %o5, 0x248, %o5
a009bee4:  d8 23 40 01  st  %o4, [ %o5 + %g1 ]
a009bee8:  81 c7 e0 08  ret
a009beec:  91 e8 20 00  restore  %g0, 0, %o0
