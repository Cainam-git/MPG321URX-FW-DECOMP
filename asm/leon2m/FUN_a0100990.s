# leon2m FUN_a0100990 0xa0100990-0xa0100a40 (176 bytes)
a0100990:  90 0a 20 ff  and  %o0, 0xff, %o0
a0100994:  80 a2 20 04  cmp  %o0, 4
a0100998:  12 80 00 28  bne  0xa0100a38
a010099c:  90 10 20 28  mov  0x28, %o0
a01009a0:  03 2a 00 9e  sethi  %hi(0xa8027800), %g1
a01009a4:  d6 08 62 7c  ldub  [ %g1 + 0x27c ], %o3	! 0xa8027a7c
a01009a8:  90 0a e0 ff  and  %o3, 0xff, %o0
a01009ac:  80 a2 20 29  cmp  %o0, 0x29
a01009b0:  38 80 00 22  bgu,a   0xa0100a38
a01009b4:  90 0a 20 ff  and  %o0, 0xff, %o0
a01009b8:  19 00 02 81  sethi  %hi(0xa0400), %o4
a01009bc:  83 2a 20 02  sll  %o0, 2, %g1
a01009c0:  9a 13 21 84  or  %o4, 0x184, %o5
a01009c4:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a01009c8:  81 c3 00 00  jmp  %o4
a01009cc:  01 00 00 00  nop
a01009d0:  90 0a e0 ff  and  %o3, 0xff, %o0
a01009d4:  10 80 00 19  b  0xa0100a38
a01009d8:  90 0a 20 ff  and  %o0, 0xff, %o0
a01009dc:  90 10 20 1d  mov  0x1d, %o0
a01009e0:  10 80 00 16  b  0xa0100a38
a01009e4:  90 0a 20 ff  and  %o0, 0xff, %o0
a01009e8:  90 10 20 0f  mov  0xf, %o0
a01009ec:  10 80 00 13  b  0xa0100a38
a01009f0:  90 0a 20 ff  and  %o0, 0xff, %o0
a01009f4:  90 10 20 15  mov  0x15, %o0
a01009f8:  10 80 00 10  b  0xa0100a38
a01009fc:  90 0a 20 ff  and  %o0, 0xff, %o0
a0100a00:  90 10 20 09  mov  9, %o0
a0100a04:  10 80 00 0d  b  0xa0100a38
a0100a08:  90 0a 20 ff  and  %o0, 0xff, %o0
a0100a0c:  90 10 20 23  mov  0x23, %o0
a0100a10:  10 80 00 0a  b  0xa0100a38
a0100a14:  90 0a 20 ff  and  %o0, 0xff, %o0
a0100a18:  90 10 20 03  mov  3, %o0
a0100a1c:  10 80 00 07  b  0xa0100a38
a0100a20:  90 0a 20 ff  and  %o0, 0xff, %o0
a0100a24:  90 10 20 02  mov  2, %o0
a0100a28:  10 80 00 04  b  0xa0100a38
a0100a2c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0100a30:  90 10 20 22  mov  0x22, %o0
a0100a34:  90 0a 20 ff  and  %o0, 0xff, %o0
a0100a38:  81 c3 e0 08  retl
a0100a3c:  01 00 00 00  nop
