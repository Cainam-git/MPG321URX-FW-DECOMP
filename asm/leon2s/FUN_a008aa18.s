# leon2s FUN_a008aa18 0xa008aa18-0xa008aab0 (152 bytes)
a008aa18:  9d e3 bf 98  save  %sp, -104, %sp
a008aa1c:  7f ff ff d6  call  0xa008a974
a008aa20:  90 10 20 44  mov  0x44, %o0
a008aa24:  7f ff fd 58  call  0xa0089f84
a008aa28:  90 10 20 00  clr  %o0
a008aa2c:  82 0a 20 ff  and  %o0, 0xff, %g1
a008aa30:  9a 10 00 18  mov  %i0, %o5
a008aa34:  11 00 00 20  sethi  %hi(0x8000), %o0
a008aa38:  b0 10 20 01  mov  1, %i0
a008aa3c:  80 a0 60 04  cmp  %g1, 4
a008aa40:  02 80 00 09  be  0xa008aa64
a008aa44:  b2 10 00 0d  mov  %o5, %i1
a008aa48:  80 a0 60 05  cmp  %g1, 5
a008aa4c:  02 80 00 06  be  0xa008aa64
a008aa50:  80 a0 60 06  cmp  %g1, 6
a008aa54:  02 80 00 04  be  0xa008aa64
a008aa58:  80 a0 60 07  cmp  %g1, 7
a008aa5c:  12 80 00 0a  bne  0xa008aa84
a008aa60:  9b 2b 60 10  sll  %o5, 0x10, %o5
a008aa64:  7f ff ff b0  call  0xa008a924
a008aa68:  b3 2e 60 10  sll  %i1, 0x10, %i1
a008aa6c:  b3 36 60 10  srl  %i1, 0x10, %i1
a008aa70:  90 10 20 00  clr  %o0
a008aa74:  7f ff ff de  call  0xa008a9ec
a008aa78:  92 10 00 19  mov  %i1, %o1
a008aa7c:  7f ff ff dc  call  0xa008a9ec
a008aa80:  81 e8 00 00  restore
a008aa84:  80 a0 60 01  cmp  %g1, 1
a008aa88:  12 80 00 06  bne  0xa008aaa0
a008aa8c:  b1 33 60 18  srl  %o5, 0x18, %i0
a008aa90:  7f ff ff a5  call  0xa008a924
a008aa94:  01 00 00 00  nop
a008aa98:  7f ff ff b1  call  0xa008a95c
a008aa9c:  81 e8 00 00  restore
a008aaa0:  b1 33 60 10  srl  %o5, 0x10, %i0
a008aaa4:  7f ff ff a0  call  0xa008a924
a008aaa8:  81 e8 00 00  restore
a008aaac:  01 00 00 00  nop
