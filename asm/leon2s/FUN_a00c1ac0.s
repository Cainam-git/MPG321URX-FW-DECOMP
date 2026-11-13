# leon2s FUN_a00c1ac0 0xa00c1ac0-0xa00c1c18 (344 bytes)
a00c1ac0:  9d e3 bf 98  save  %sp, -104, %sp
a00c1ac4:  a4 10 20 00  clr  %l2
a00c1ac8:  a0 0c a0 ff  and  %l2, 0xff, %l0
a00c1acc:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a00c1ad0:  83 2c 20 04  sll  %l0, 4, %g1
a00c1ad4:  9a 13 61 c8  or  %o5, 0x1c8, %o5
a00c1ad8:  a2 00 40 0d  add  %g1, %o5, %l1
a00c1adc:  c2 0c 60 0d  ldub  [ %l1 + 0xd ], %g1
a00c1ae0:  82 00 7f fb  add  %g1, -5, %g1
a00c1ae4:  82 08 60 ff  and  %g1, 0xff, %g1
a00c1ae8:  a4 04 a0 01  inc  %l2
a00c1aec:  92 10 23 18  mov  0x318, %o1
a00c1af0:  80 a0 60 01  cmp  %g1, 1
a00c1af4:  18 80 00 12  bgu  0xa00c1b3c
a00c1af8:  90 10 00 10  mov  %l0, %o0
a00c1afc:  40 3b d2 a0  call  0xa0fb657c
a00c1b00:  01 00 00 00  nop
a00c1b04:  80 8a 20 20  btst  0x20, %o0
a00c1b08:  92 10 23 18  mov  0x318, %o1
a00c1b0c:  94 10 20 60  mov  0x60, %o2
a00c1b10:  02 80 00 0b  be  0xa00c1b3c
a00c1b14:  90 10 00 10  mov  %l0, %o0
a00c1b18:  40 3b d2 ab  call  0xa0fb65c4
a00c1b1c:  01 00 00 00  nop
a00c1b20:  90 10 00 10  mov  %l0, %o0
a00c1b24:  92 10 23 08  mov  0x308, %o1
a00c1b28:  94 10 20 10  mov  0x10, %o2
a00c1b2c:  40 3b d3 23  call  0xa0fb67b8
a00c1b30:  96 10 20 01  mov  1, %o3
a00c1b34:  82 10 20 07  mov  7, %g1
a00c1b38:  c2 2c 60 0d  stb  %g1, [ %l1 + 0xd ]
a00c1b3c:  82 0c a0 ff  and  %l2, 0xff, %g1
a00c1b40:  80 a0 60 01  cmp  %g1, 1
a00c1b44:  08 bf ff e2  bleu  0xa00c1acc
a00c1b48:  a0 0c a0 ff  and  %l2, 0xff, %l0
a00c1b4c:  a4 10 20 00  clr  %l2
a00c1b50:  a0 0c a0 ff  and  %l2, 0xff, %l0
a00c1b54:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a00c1b58:  83 2c 20 04  sll  %l0, 4, %g1
a00c1b5c:  9a 13 61 e8  or  %o5, 0x1e8, %o5
a00c1b60:  a2 00 40 0d  add  %g1, %o5, %l1
a00c1b64:  c2 0c 60 0d  ldub  [ %l1 + 0xd ], %g1
a00c1b68:  82 00 7f fb  add  %g1, -5, %g1
a00c1b6c:  82 08 60 ff  and  %g1, 0xff, %g1
a00c1b70:  a4 04 a0 01  inc  %l2
a00c1b74:  92 10 20 a8  mov  0xa8, %o1
a00c1b78:  80 a0 60 01  cmp  %g1, 1
a00c1b7c:  18 80 00 21  bgu  0xa00c1c00
a00c1b80:  90 10 00 10  mov  %l0, %o0
a00c1b84:  40 3b d3 8c  call  0xa0fb69b4
a00c1b88:  01 00 00 00  nop
a00c1b8c:  80 8a 20 40  btst  0x40, %o0
a00c1b90:  92 10 20 a8  mov  0xa8, %o1
a00c1b94:  94 10 20 60  mov  0x60, %o2
a00c1b98:  02 80 00 1a  be  0xa00c1c00
a00c1b9c:  90 10 00 10  mov  %l0, %o0
a00c1ba0:  40 3b d3 97  call  0xa0fb69fc
a00c1ba4:  01 00 00 00  nop
a00c1ba8:  90 10 00 10  mov  %l0, %o0
a00c1bac:  92 10 20 a6  mov  0xa6, %o1
a00c1bb0:  40 3b d3 93  call  0xa0fb69fc
a00c1bb4:  94 10 20 09  mov  9, %o2
a00c1bb8:  90 10 00 10  mov  %l0, %o0
a00c1bbc:  92 10 20 a4  mov  0xa4, %o1
a00c1bc0:  40 3b d3 8f  call  0xa0fb69fc
a00c1bc4:  94 10 20 00  clr  %o2
a00c1bc8:  90 10 00 10  mov  %l0, %o0
a00c1bcc:  92 10 20 a5  mov  0xa5, %o1
a00c1bd0:  40 3b d3 8b  call  0xa0fb69fc
a00c1bd4:  94 10 20 00  clr  %o2
a00c1bd8:  90 10 00 10  mov  %l0, %o0
a00c1bdc:  92 10 20 a7  mov  0xa7, %o1
a00c1be0:  40 3b d3 87  call  0xa0fb69fc
a00c1be4:  94 10 20 10  mov  0x10, %o2
a00c1be8:  90 10 00 10  mov  %l0, %o0
a00c1bec:  92 10 20 a4  mov  0xa4, %o1
a00c1bf0:  40 3b d3 83  call  0xa0fb69fc
a00c1bf4:  94 10 20 20  mov  0x20, %o2
a00c1bf8:  82 10 20 07  mov  7, %g1
a00c1bfc:  c2 2c 60 0d  stb  %g1, [ %l1 + 0xd ]
a00c1c00:  82 0c a0 ff  and  %l2, 0xff, %g1
a00c1c04:  80 a0 60 01  cmp  %g1, 1
a00c1c08:  08 bf ff d3  bleu  0xa00c1b54
a00c1c0c:  a0 0c a0 ff  and  %l2, 0xff, %l0
a00c1c10:  81 c7 e0 08  ret
a00c1c14:  81 e8 00 00  restore
