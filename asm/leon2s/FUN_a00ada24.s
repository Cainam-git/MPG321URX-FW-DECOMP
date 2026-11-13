# leon2s FUN_a00ada24 0xa00ada24-0xa00add0c (744 bytes)
a00ada24:  9d e3 bf 98  save  %sp, -104, %sp
a00ada28:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00ada2c:  90 10 00 10  mov  %l0, %o0
a00ada30:  7f ff e5 52  call  0xa00a6f78
a00ada34:  92 10 20 05  mov  5, %o1
a00ada38:  80 8a 20 04  btst  4, %o0
a00ada3c:  02 80 00 60  be  0xa00adbbc
a00ada40:  92 10 20 8d  mov  0x8d, %o1
a00ada44:  90 10 00 10  mov  %l0, %o0
a00ada48:  7f ff e4 5c  call  0xa00a6bb8
a00ada4c:  92 10 20 8e  mov  0x8e, %o1
a00ada50:  80 8a 20 40  btst  0x40, %o0
a00ada54:  22 80 00 5a  be,a   0xa00adbbc
a00ada58:  92 10 20 8d  mov  0x8d, %o1
a00ada5c:  94 10 20 80  mov  0x80, %o2
a00ada60:  96 10 20 00  clr  %o3
a00ada64:  90 10 00 10  mov  %l0, %o0
a00ada68:  7f ff e4 8c  call  0xa00a6c98
a00ada6c:  92 10 20 be  mov  0xbe, %o1
a00ada70:  92 10 20 bd  mov  0xbd, %o1
a00ada74:  7f ff e4 51  call  0xa00a6bb8
a00ada78:  90 10 00 10  mov  %l0, %o0
a00ada7c:  a2 10 00 08  mov  %o0, %l1
a00ada80:  94 10 20 80  mov  0x80, %o2
a00ada84:  96 10 20 01  mov  1, %o3
a00ada88:  90 10 00 10  mov  %l0, %o0
a00ada8c:  7f ff e4 83  call  0xa00a6c98
a00ada90:  92 10 20 be  mov  0xbe, %o1
a00ada94:  92 10 20 bd  mov  0xbd, %o1
a00ada98:  7f ff e4 48  call  0xa00a6bb8
a00ada9c:  90 10 00 10  mov  %l0, %o0
a00adaa0:  b2 10 00 08  mov  %o0, %i1
a00adaa4:  90 10 00 10  mov  %l0, %o0
a00adaa8:  92 10 20 be  mov  0xbe, %o1
a00adaac:  94 10 20 80  mov  0x80, %o2
a00adab0:  7f ff e4 7a  call  0xa00a6c98
a00adab4:  96 10 20 00  clr  %o3
a00adab8:  82 0c 60 ff  and  %l1, 0xff, %g1
a00adabc:  82 00 7f fa  add  %g1, -6, %g1
a00adac0:  80 a0 60 31  cmp  %g1, 0x31
a00adac4:  38 80 00 2f  bgu,a   0xa00adb80
a00adac8:  b0 10 20 01  mov  1, %i0
a00adacc:  1b 28 02 b6  sethi  %hi(0xa00ad800), %o5
a00adad0:  83 28 60 02  sll  %g1, 2, %g1
a00adad4:  9a 13 61 5c  or  %o5, 0x15c, %o5
a00adad8:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a00adadc:  81 c0 40 00  jmp  %g1
a00adae0:  01 00 00 00  nop
a00adae4:  10 80 00 27  b  0xa00adb80
a00adae8:  b0 10 20 1b  mov  0x1b, %i0	! 0x1b
a00adaec:  10 80 00 25  b  0xa00adb80
a00adaf0:  b0 10 20 03  mov  3, %i0
a00adaf4:  10 80 00 23  b  0xa00adb80
a00adaf8:  b0 10 20 09  mov  9, %i0
a00adafc:  10 80 00 21  b  0xa00adb80
a00adb00:  b0 10 20 15  mov  0x15, %i0
a00adb04:  10 80 00 1f  b  0xa00adb80
a00adb08:  b0 10 20 0f  mov  0xf, %i0
a00adb0c:  10 80 00 1d  b  0xa00adb80
a00adb10:  b0 10 20 1d  mov  0x1d, %i0
a00adb14:  10 80 00 1b  b  0xa00adb80
a00adb18:  b0 10 20 23  mov  0x23, %i0
a00adb1c:  10 80 00 19  b  0xa00adb80
a00adb20:  b0 10 20 05  mov  5, %i0
a00adb24:  10 80 00 17  b  0xa00adb80
a00adb28:  b0 10 20 0b  mov  0xb, %i0
a00adb2c:  10 80 00 15  b  0xa00adb80
a00adb30:  b0 10 20 17  mov  0x17, %i0
a00adb34:  10 80 00 13  b  0xa00adb80
a00adb38:  b0 10 20 11  mov  0x11, %i0
a00adb3c:  10 80 00 11  b  0xa00adb80
a00adb40:  b0 10 20 1f  mov  0x1f, %i0
a00adb44:  10 80 00 0f  b  0xa00adb80
a00adb48:  b0 10 20 25  mov  0x25, %i0
a00adb4c:  10 80 00 0d  b  0xa00adb80
a00adb50:  b0 10 20 07  mov  7, %i0
a00adb54:  10 80 00 0b  b  0xa00adb80
a00adb58:  b0 10 20 0d  mov  0xd, %i0
a00adb5c:  10 80 00 09  b  0xa00adb80
a00adb60:  b0 10 20 19  mov  0x19, %i0
a00adb64:  10 80 00 07  b  0xa00adb80
a00adb68:  b0 10 20 13  mov  0x13, %i0
a00adb6c:  10 80 00 05  b  0xa00adb80
a00adb70:  b0 10 20 21  mov  0x21, %i0
a00adb74:  10 80 00 03  b  0xa00adb80
a00adb78:  b0 10 20 27  mov  0x27, %i0
a00adb7c:  b0 10 20 01  mov  1, %i0
a00adb80:  82 04 7f e0  add  %l1, -32, %g1
a00adb84:  82 08 60 ff  and  %g1, 0xff, %g1
a00adb88:  80 a0 60 07  cmp  %g1, 7
a00adb8c:  18 80 00 08  bgu  0xa00adbac
a00adb90:  80 8e 60 80  btst  0x80, %i1
a00adb94:  7f ff ff 0d  call  0xa00ad7c8
a00adb98:  90 10 00 10  mov  %l0, %o0
a00adb9c:  80 8a 20 ff  btst  0xff, %o0
a00adba0:  32 80 00 02  bne,a   0xa00adba8
a00adba4:  b0 06 3f fe  add  %i0, -2, %i0
a00adba8:  80 8e 60 80  btst  0x80, %i1
a00adbac:  32 80 00 55  bne,a   0xa00add00
a00adbb0:  b0 06 3f ff  add  %i0, -1, %i0
a00adbb4:  10 80 00 54  b  0xa00add04
a00adbb8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00adbbc:  7f ff e3 ff  call  0xa00a6bb8
a00adbc0:  90 10 00 10  mov  %l0, %o0
a00adbc4:  a2 0a 20 1e  and  %o0, 0x1e, %l1
a00adbc8:  90 10 00 10  mov  %l0, %o0
a00adbcc:  7f ff e3 fb  call  0xa00a6bb8
a00adbd0:  92 10 20 8e  mov  0x8e, %o1
a00adbd4:  80 8a 20 80  btst  0x80, %o0
a00adbd8:  12 80 00 4a  bne  0xa00add00
a00adbdc:  b0 10 20 01  mov  1, %i0
a00adbe0:  82 0c 60 ff  and  %l1, 0xff, %g1
a00adbe4:  82 00 7f fe  add  %g1, -2, %g1
a00adbe8:  80 a0 60 1a  cmp  %g1, 0x1a
a00adbec:  18 80 00 34  bgu  0xa00adcbc
a00adbf0:  1b 28 02 b6  sethi  %hi(0xa00ad800), %o5
a00adbf4:  83 28 60 02  sll  %g1, 2, %g1
a00adbf8:  9a 13 60 f0  or  %o5, 0xf0, %o5
a00adbfc:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a00adc00:  81 c0 40 00  jmp  %g1
a00adc04:  01 00 00 00  nop
a00adc08:  7f ff fe f0  call  0xa00ad7c8
a00adc0c:  90 10 00 10  mov  %l0, %o0
a00adc10:  90 0a 20 ff  and  %o0, 0xff, %o0
a00adc14:  80 a0 00 08  cmp  %g0, %o0
a00adc18:  82 40 3f ff  addx  %g0, -1, %g1
a00adc1c:  b0 08 60 02  and  %g1, 2, %i0
a00adc20:  10 80 00 38  b  0xa00add00
a00adc24:  b0 06 20 02  add  %i0, 2, %i0
a00adc28:  7f ff fe e8  call  0xa00ad7c8
a00adc2c:  90 10 00 10  mov  %l0, %o0
a00adc30:  90 0a 20 ff  and  %o0, 0xff, %o0
a00adc34:  80 a0 00 08  cmp  %g0, %o0
a00adc38:  82 40 3f ff  addx  %g0, -1, %g1
a00adc3c:  b0 08 60 02  and  %g1, 2, %i0
a00adc40:  10 80 00 30  b  0xa00add00
a00adc44:  b0 06 20 08  add  %i0, 8, %i0
a00adc48:  10 80 00 2e  b  0xa00add00
a00adc4c:  b0 10 20 02  mov  2, %i0
a00adc50:  10 80 00 2c  b  0xa00add00
a00adc54:  b0 10 20 08  mov  8, %i0
a00adc58:  10 80 00 2a  b  0xa00add00
a00adc5c:  b0 10 20 10  mov  0x10, %i0
a00adc60:  10 80 00 28  b  0xa00add00
a00adc64:  b0 10 20 16  mov  0x16, %i0
a00adc68:  10 80 00 26  b  0xa00add00
a00adc6c:  b0 10 20 0e  mov  0xe, %i0
a00adc70:  10 80 00 24  b  0xa00add00
a00adc74:  b0 10 20 14  mov  0x14, %i0
a00adc78:  7f ff fe 9d  call  0xa00ad6ec
a00adc7c:  90 10 00 10  mov  %l0, %o0
a00adc80:  80 8a 20 ff  btst  0xff, %o0
a00adc84:  02 80 00 1f  be  0xa00add00
a00adc88:  b0 10 20 00  clr  %i0
a00adc8c:  80 8e 60 ff  btst  0xff, %i1
a00adc90:  02 80 00 1c  be  0xa00add00
a00adc94:  1b 2a 01 f7  sethi  %hi(0xa807dc00), %o5
a00adc98:  82 5c 21 2c  smul  %l0, 0x12c, %g1
a00adc9c:  9a 13 60 18  or  %o5, 0x18, %o5
a00adca0:  82 00 40 0d  add  %g1, %o5, %g1
a00adca4:  c2 08 61 1f  ldub  [ %g1 + 0x11f ], %g1
a00adca8:  80 a0 60 00  cmp  %g1, 0
a00adcac:  12 80 00 15  bne  0xa00add00
a00adcb0:  b0 10 20 08  mov  8, %i0
a00adcb4:  10 80 00 13  b  0xa00add00
a00adcb8:  b0 10 20 00  clr  %i0
a00adcbc:  7f ff fe 8c  call  0xa00ad6ec
a00adcc0:  90 10 00 10  mov  %l0, %o0
a00adcc4:  80 8a 20 ff  btst  0xff, %o0
a00adcc8:  02 80 00 0e  be  0xa00add00
a00adccc:  b0 10 20 01  mov  1, %i0
a00adcd0:  80 8e 60 ff  btst  0xff, %i1
a00adcd4:  02 80 00 0c  be  0xa00add04
a00adcd8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00adcdc:  1b 2a 01 f7  sethi  %hi(0xa807dc00), %o5
a00adce0:  82 5c 21 2c  smul  %l0, 0x12c, %g1
a00adce4:  9a 13 60 18  or  %o5, 0x18, %o5
a00adce8:  82 00 40 0d  add  %g1, %o5, %g1
a00adcec:  c2 08 61 1f  ldub  [ %g1 + 0x11f ], %g1
a00adcf0:  80 a0 60 00  cmp  %g1, 0
a00adcf4:  12 80 00 03  bne  0xa00add00
a00adcf8:  b0 10 20 08  mov  8, %i0
a00adcfc:  b0 10 20 01  mov  1, %i0
a00add00:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00add04:  81 c7 e0 08  ret
a00add08:  81 e8 00 00  restore
