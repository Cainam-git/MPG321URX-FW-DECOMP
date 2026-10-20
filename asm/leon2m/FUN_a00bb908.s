# leon2m FUN_a00bb908 0xa00bb908-0xa00bbabc (436 bytes)
a00bb908:  9d e3 bf 98  save  %sp, -104, %sp
a00bb90c:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00bb910:  a6 10 60 40  or  %g1, 0x40, %l3	! 0xa802d040
a00bb914:  a4 10 20 00  clr  %l2
a00bb918:  b0 10 20 00  clr  %i0
a00bb91c:  a2 10 20 02  mov  2, %l1
a00bb920:  a0 10 20 02  mov  2, %l0
a00bb924:  92 10 00 10  mov  %l0, %o1
a00bb928:  40 02 63 59  call  0xa015468c
a00bb92c:  90 10 00 18  mov  %i0, %o0
a00bb930:  94 0a 20 ff  and  %o0, 0xff, %o2
a00bb934:  a2 04 60 01  inc  %l1
a00bb938:  92 10 00 10  mov  %l0, %o1
a00bb93c:  80 a2 a0 ff  cmp  %o2, 0xff
a00bb940:  02 80 00 09  be  0xa00bb964
a00bb944:  90 10 00 18  mov  %i0, %o0
a00bb948:  40 02 63 51  call  0xa015468c
a00bb94c:  01 00 00 00  nop
a00bb950:  90 0a 20 ff  and  %o0, 0xff, %o0
a00bb954:  d2 0c c0 10  ldub  [ %l3 + %l0 ], %o1
a00bb958:  80 a2 00 09  cmp  %o0, %o1
a00bb95c:  12 80 00 07  bne  0xa00bb978
a00bb960:  80 a4 20 0a  cmp  %l0, 0xa
a00bb964:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00bb968:  80 a4 20 09  cmp  %l0, 9
a00bb96c:  08 bf ff ef  bleu  0xa00bb928
a00bb970:  92 10 00 10  mov  %l0, %o1
a00bb974:  80 a4 20 0a  cmp  %l0, 0xa
a00bb978:  02 80 00 4a  be  0xa00bbaa0
a00bb97c:  a4 04 a0 01  inc  %l2
a00bb980:  b0 0c a0 ff  and  %l2, 0xff, %i0
a00bb984:  80 a6 20 8c  cmp  %i0, 0x8c
a00bb988:  08 bf ff e6  bleu  0xa00bb920
a00bb98c:  a2 10 20 02  mov  2, %l1
a00bb990:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00bb994:  a6 12 e0 40  or  %o3, 0x40, %l3	! 0xa802d040
a00bb998:  a4 10 20 00  clr  %l2
a00bb99c:  b0 10 20 00  clr  %i0
a00bb9a0:  a0 10 20 02  mov  2, %l0
a00bb9a4:  92 10 00 10  mov  %l0, %o1
a00bb9a8:  40 02 63 51  call  0xa01546ec
a00bb9ac:  90 10 00 18  mov  %i0, %o0
a00bb9b0:  98 0a 20 ff  and  %o0, 0xff, %o4
a00bb9b4:  a2 04 60 01  inc  %l1
a00bb9b8:  92 10 00 10  mov  %l0, %o1
a00bb9bc:  80 a3 20 ff  cmp  %o4, 0xff
a00bb9c0:  02 80 00 09  be  0xa00bb9e4
a00bb9c4:  90 10 00 18  mov  %i0, %o0
a00bb9c8:  40 02 63 49  call  0xa01546ec
a00bb9cc:  01 00 00 00  nop
a00bb9d0:  9e 0a 20 ff  and  %o0, 0xff, %o7
a00bb9d4:  da 0c c0 10  ldub  [ %l3 + %l0 ], %o5
a00bb9d8:  80 a3 c0 0d  cmp  %o7, %o5
a00bb9dc:  12 80 00 07  bne  0xa00bb9f8
a00bb9e0:  80 a4 20 19  cmp  %l0, 0x19
a00bb9e4:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00bb9e8:  80 a4 20 18  cmp  %l0, 0x18
a00bb9ec:  08 bf ff ef  bleu  0xa00bb9a8
a00bb9f0:  92 10 00 10  mov  %l0, %o1
a00bb9f4:  80 a4 20 19  cmp  %l0, 0x19
a00bb9f8:  02 80 00 2c  be  0xa00bbaa8
a00bb9fc:  a0 04 bf 8d  add  %l2, -115, %l0
a00bba00:  a4 04 a0 01  inc  %l2
a00bba04:  b0 0c a0 ff  and  %l2, 0xff, %i0
a00bba08:  80 a6 20 0c  cmp  %i0, 0xc
a00bba0c:  08 bf ff e5  bleu  0xa00bb9a0
a00bba10:  a2 10 20 02  mov  2, %l1
a00bba14:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00bba18:  a6 14 60 40  or  %l1, 0x40, %l3	! 0xa802d040
a00bba1c:  a4 10 20 00  clr  %l2
a00bba20:  b0 10 20 00  clr  %i0
a00bba24:  a2 10 20 02  mov  2, %l1
a00bba28:  a0 10 20 02  mov  2, %l0
a00bba2c:  92 10 00 10  mov  %l0, %o1
a00bba30:  40 02 63 48  call  0xa0154750
a00bba34:  90 10 00 18  mov  %i0, %o0
a00bba38:  82 0a 20 ff  and  %o0, 0xff, %g1
a00bba3c:  a2 04 60 01  inc  %l1
a00bba40:  92 10 00 10  mov  %l0, %o1
a00bba44:  80 a0 60 ff  cmp  %g1, 0xff
a00bba48:  02 80 00 09  be  0xa00bba6c
a00bba4c:  90 10 00 18  mov  %i0, %o0
a00bba50:  40 02 63 40  call  0xa0154750
a00bba54:  01 00 00 00  nop
a00bba58:  92 0a 20 ff  and  %o0, 0xff, %o1
a00bba5c:  d4 0c c0 10  ldub  [ %l3 + %l0 ], %o2
a00bba60:  80 a2 40 0a  cmp  %o1, %o2
a00bba64:  12 80 00 07  bne  0xa00bba80
a00bba68:  80 a4 20 06  cmp  %l0, 6
a00bba6c:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00bba70:  80 a4 20 05  cmp  %l0, 5
a00bba74:  08 bf ff ef  bleu  0xa00bba30
a00bba78:  92 10 00 10  mov  %l0, %o1
a00bba7c:  80 a4 20 06  cmp  %l0, 6
a00bba80:  02 80 00 0c  be  0xa00bbab0
a00bba84:  a4 04 a0 01  inc  %l2
a00bba88:  b0 0c a0 ff  and  %l2, 0xff, %i0
a00bba8c:  80 a6 20 00  cmp  %i0, 0
a00bba90:  22 bf ff e6  be,a   0xa00bba28
a00bba94:  a2 10 20 02  mov  2, %l1
a00bba98:  10 80 00 07  b  0xa00bbab4
a00bba9c:  90 10 20 ff  mov  0xff, %o0
a00bbaa0:  10 80 00 05  b  0xa00bbab4
a00bbaa4:  90 10 00 18  mov  %i0, %o0
a00bbaa8:  10 80 00 03  b  0xa00bbab4
a00bbaac:  90 0c 20 ff  and  %l0, 0xff, %o0
a00bbab0:  90 10 20 99  mov  0x99, %o0
a00bbab4:  81 c7 e0 08  ret
a00bbab8:  91 e8 00 08  restore  %g0, %o0, %o0
