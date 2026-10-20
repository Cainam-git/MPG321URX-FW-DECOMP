# leon2m FUN_a00ed70c 0xa00ed70c-0xa00edc70 (1380 bytes)
a00ed70c:  9d e3 bf 70  save  %sp, -144, %sp
a00ed710:  98 10 20 00  clr  %o4
a00ed714:  9a 10 20 00  clr  %o5
a00ed718:  d8 3f bf e0  std  %o4, [ %fp + -32 ]
a00ed71c:  d8 3f bf e8  std  %o4, [ %fp + -24 ]
a00ed720:  d8 3f bf f0  std  %o4, [ %fp + -16 ]
a00ed724:  d8 3f bf d8  std  %o4, [ %fp + -40 ]
a00ed728:  92 10 21 49  mov  0x149, %o1
a00ed72c:  7f ff ca f0  call  0xa00e02ec
a00ed730:  90 10 00 18  mov  %i0, %o0
a00ed734:  d0 27 bf d4  st  %o0, [ %fp + -44 ]
a00ed738:  90 10 20 05  mov  5, %o0
a00ed73c:  92 10 00 18  mov  %i0, %o1
a00ed740:  7f ff ca 1d  call  0xa00dffb4
a00ed744:  94 10 00 1b  mov  %i3, %o2
a00ed748:  90 10 00 18  mov  %i0, %o0
a00ed74c:  92 10 00 19  mov  %i1, %o1
a00ed750:  7f ff c9 40  call  0xa00dfc50
a00ed754:  94 10 00 1a  mov  %i2, %o2
a00ed758:  f8 27 a0 54  st  %i4, [ %fp + 0x54 ]
a00ed75c:  80 a6 ff ff  cmp  %i3, -1
a00ed760:  02 80 00 ff  be  0xa00edb5c
a00ed764:  fa 27 a0 58  st  %i5, [ %fp + 0x58 ]
a00ed768:  23 2a 00 9a  sethi  %hi(0xa8026800), %l1
a00ed76c:  1f 2a 00 9a  sethi  %hi(0xa8026800), %o7
a00ed770:  11 2a 00 9a  sethi  %hi(0xa8026800), %o0
a00ed774:  99 2e e0 02  sll  %i3, 2, %o4
a00ed778:  a0 14 61 58  or  %l1, 0x158, %l0
a00ed77c:  9a 13 e1 78  or  %o7, 0x178, %o5
a00ed780:  82 12 21 68  or  %o0, 0x168, %g1
a00ed784:  d6 04 00 0c  ld  [ %l0 + %o4 ], %o3
a00ed788:  d2 03 40 0c  ld  [ %o5 + %o4 ], %o1
a00ed78c:  d4 00 40 0c  ld  [ %g1 + %o4 ], %o2
a00ed790:  98 10 20 01  mov  1, %o4
a00ed794:  7f ff cb f8  call  0xa00e0774
a00ed798:  90 10 00 18  mov  %i0, %o0
a00ed79c:  92 10 00 1b  mov  %i3, %o1
a00ed7a0:  94 10 20 06  mov  6, %o2
a00ed7a4:  7f ff ff 63  call  0xa00ed530
a00ed7a8:  90 10 00 18  mov  %i0, %o0
a00ed7ac:  98 10 20 01  mov  1, %o4
a00ed7b0:  90 10 00 18  mov  %i0, %o0
a00ed7b4:  92 10 22 81  mov  0x281, %o1
a00ed7b8:  94 10 20 80  mov  0x80, %o2
a00ed7bc:  7f ff cb ee  call  0xa00e0774
a00ed7c0:  96 10 20 07  mov  7, %o3
a00ed7c4:  90 10 00 18  mov  %i0, %o0
a00ed7c8:  92 10 21 49  mov  0x149, %o1
a00ed7cc:  94 10 20 ff  mov  0xff, %o2
a00ed7d0:  7f ff cb 82  call  0xa00e05d8
a00ed7d4:  96 10 20 ff  mov  0xff, %o3
a00ed7d8:  90 10 00 18  mov  %i0, %o0
a00ed7dc:  92 10 20 8e  mov  0x8e, %o1
a00ed7e0:  94 10 20 02  mov  2, %o2
a00ed7e4:  96 10 20 01  mov  1, %o3
a00ed7e8:  7f ff cb e3  call  0xa00e0774
a00ed7ec:  98 10 20 01  mov  1, %o4
a00ed7f0:  80 a6 a0 04  cmp  %i2, 4
a00ed7f4:  02 80 00 fd  be  0xa00edbe8
a00ed7f8:  80 a6 a0 03  cmp  %i2, 3
a00ed7fc:  02 80 01 10  be  0xa00edc3c
a00ed800:  01 00 00 00  nop
a00ed804:  7f ff d9 fc  call  0xa00e3ff4
a00ed808:  90 10 00 18  mov  %i0, %o0
a00ed80c:  96 12 20 80  or  %o0, 0x80, %o3
a00ed810:  b5 2e e0 02  sll  %i3, 2, %i2
a00ed814:  b8 07 bf f8  add  %fp, -8, %i4
a00ed818:  90 10 00 18  mov  %i0, %o0
a00ed81c:  92 10 20 06  mov  6, %o1
a00ed820:  94 10 20 01  mov  1, %o2
a00ed824:  a2 06 80 1c  add  %i2, %i4, %l1
a00ed828:  2b 2a 00 9a  sethi  %hi(0xa8026800), %l5
a00ed82c:  27 2a 00 9a  sethi  %hi(0xa8026800), %l3
a00ed830:  7f ff da 0f  call  0xa00e406c
a00ed834:  29 2a 00 ad  sethi  %hi(0xa802b400), %l4
a00ed838:  a4 10 20 00  clr  %l2
a00ed83c:  a0 10 20 00  clr  %l0
a00ed840:  ac 15 60 88  or  %l5, 0x88, %l6
a00ed844:  ae 14 e0 78  or  %l3, 0x78, %l7
a00ed848:  ba 15 23 18  or  %l4, 0x318, %i5
a00ed84c:  10 80 00 1a  b  0xa00ed8b4
a00ed850:  b2 10 00 11  mov  %l1, %i1
a00ed854:  02 80 00 a7  be  0xa00edaf0
a00ed858:  90 10 00 18  mov  %i0, %o0
a00ed85c:  d2 05 80 1a  ld  [ %l6 + %i2 ], %o1
a00ed860:  d4 05 c0 1a  ld  [ %l7 + %i2 ], %o2
a00ed864:  d6 07 40 1a  ld  [ %i5 + %i2 ], %o3
a00ed868:  7f ff cb bb  call  0xa00e0754
a00ed86c:  01 00 00 00  nop
a00ed870:  80 a2 20 00  cmp  %o0, 0
a00ed874:  12 80 00 05  bne  0xa00ed888
a00ed878:  9a 04 20 07  add  %l0, 7, %o5
a00ed87c:  d4 04 7f f0  ld  [ %l1 + -16 ], %o2
a00ed880:  96 02 a0 01  add  %o2, 1, %o3
a00ed884:  d6 24 7f f0  st  %o3, [ %l1 + -16 ]
a00ed888:  94 0b 60 ff  and  %o5, 0xff, %o2
a00ed88c:  90 10 00 18  mov  %i0, %o0
a00ed890:  7f ff ff 28  call  0xa00ed530
a00ed894:  92 10 00 1b  mov  %i3, %o1
a00ed898:  80 a4 a0 01  cmp  %l2, 1
a00ed89c:  22 80 00 30  be,a   0xa00ed95c
a00ed8a0:  f2 07 a0 60  ld  [ %fp + 0x60 ], %i1
a00ed8a4:  a0 04 20 01  inc  %l0
a00ed8a8:  80 a4 20 0f  cmp  %l0, 0xf
a00ed8ac:  34 80 00 95  bg,a   0xa00edb00
a00ed8b0:  a0 06 80 1c  add  %i2, %i4, %l0
a00ed8b4:  90 10 00 18  mov  %i0, %o0
a00ed8b8:  92 10 20 8e  mov  0x8e, %o1
a00ed8bc:  94 10 20 01  mov  1, %o2
a00ed8c0:  96 10 20 00  clr  %o3
a00ed8c4:  7f ff cb ac  call  0xa00e0774
a00ed8c8:  98 10 20 01  mov  1, %o4
a00ed8cc:  90 10 00 18  mov  %i0, %o0
a00ed8d0:  92 10 20 8e  mov  0x8e, %o1
a00ed8d4:  94 10 20 01  mov  1, %o2
a00ed8d8:  96 10 20 00  clr  %o3
a00ed8dc:  7f ff cb a6  call  0xa00e0774
a00ed8e0:  98 10 20 00  clr  %o4
a00ed8e4:  c2 04 7f f0  ld  [ %l1 + -16 ], %g1
a00ed8e8:  80 a0 60 00  cmp  %g1, 0
a00ed8ec:  02 bf ff da  be  0xa00ed854
a00ed8f0:  80 a6 ff ff  cmp  %i3, -1
a00ed8f4:  80 a0 60 01  cmp  %g1, 1
a00ed8f8:  12 bf ff e9  bne  0xa00ed89c
a00ed8fc:  80 a4 a0 01  cmp  %l2, 1
a00ed900:  80 a6 ff ff  cmp  %i3, -1
a00ed904:  02 80 00 92  be  0xa00edb4c
a00ed908:  90 10 00 18  mov  %i0, %o0
a00ed90c:  d2 05 80 1a  ld  [ %l6 + %i2 ], %o1
a00ed910:  d4 05 c0 1a  ld  [ %l7 + %i2 ], %o2
a00ed914:  d6 07 40 1a  ld  [ %i5 + %i2 ], %o3
a00ed918:  7f ff cb 8f  call  0xa00e0754
a00ed91c:  01 00 00 00  nop
a00ed920:  80 a2 20 00  cmp  %o0, 0
a00ed924:  02 bf ff d9  be  0xa00ed888
a00ed928:  9a 04 20 07  add  %l0, 7, %o5
a00ed92c:  c2 06 7f f0  ld  [ %i1 + -16 ], %g1
a00ed930:  98 00 60 01  add  %g1, 1, %o4
a00ed934:  d2 07 a0 54  ld  [ %fp + 0x54 ], %o1
a00ed938:  d8 26 7f f0  st  %o4, [ %i1 + -16 ]
a00ed93c:  80 a4 00 09  cmp  %l0, %o1
a00ed940:  04 bf ff d6  ble  0xa00ed898
a00ed944:  a4 04 a0 01  inc  %l2
a00ed948:  90 10 20 01  mov  1, %o0
a00ed94c:  80 a4 a0 01  cmp  %l2, 1
a00ed950:  12 bf ff d5  bne  0xa00ed8a4
a00ed954:  d0 26 7f e0  st  %o0, [ %i1 + -32 ]
a00ed958:  f2 07 a0 60  ld  [ %fp + 0x60 ], %i1
a00ed95c:  80 a6 60 00  cmp  %i1, 0
a00ed960:  25 2a 00 9a  sethi  %hi(0xa8026800), %l2
a00ed964:  23 2a 00 9a  sethi  %hi(0xa8026800), %l1
a00ed968:  02 80 00 1f  be  0xa00ed9e4
a00ed96c:  21 2a 00 9a  sethi  %hi(0xa8026800), %l0
a00ed970:  f8 07 a0 5c  ld  [ %fp + 0x5c ], %i4
a00ed974:  80 a7 20 00  cmp  %i4, 0
a00ed978:  02 80 00 05  be  0xa00ed98c
a00ed97c:  80 a6 ff ff  cmp  %i3, -1
a00ed980:  de 07 a0 60  ld  [ %fp + 0x60 ], %o7
a00ed984:  ba 20 00 0f  neg  %o7, %i5
a00ed988:  fa 27 a0 60  st  %i5, [ %fp + 0x60 ]
a00ed98c:  02 80 00 a5  be  0xa00edc20
a00ed990:  25 2a 00 9a  sethi  %hi(0xa8026800), %l2
a00ed994:  94 14 a1 18  or  %l2, 0x118, %o2	! 0xa8026918
a00ed998:  23 2a 00 9a  sethi  %hi(0xa8026800), %l1
a00ed99c:  96 14 61 08  or  %l1, 0x108, %o3	! 0xa8026908
a00ed9a0:  21 2a 00 9a  sethi  %hi(0xa8026800), %l0
a00ed9a4:  d2 02 80 1a  ld  [ %o2 + %i2 ], %o1
a00ed9a8:  a6 14 20 f8  or  %l0, 0xf8, %l3
a00ed9ac:  d4 02 c0 1a  ld  [ %o3 + %i2 ], %o2
a00ed9b0:  d6 04 c0 1a  ld  [ %l3 + %i2 ], %o3
a00ed9b4:  90 10 00 18  mov  %i0, %o0
a00ed9b8:  7f ff cb 67  call  0xa00e0754
a00ed9bc:  01 00 00 00  nop
a00ed9c0:  d8 07 a0 60  ld  [ %fp + 0x60 ], %o4
a00ed9c4:  92 02 00 0c  add  %o0, %o4, %o1
a00ed9c8:  94 0a 60 ff  and  %o1, 0xff, %o2
a00ed9cc:  90 10 00 18  mov  %i0, %o0
a00ed9d0:  7f ff fe d8  call  0xa00ed530
a00ed9d4:  92 10 00 1b  mov  %i3, %o1
a00ed9d8:  80 a2 20 00  cmp  %o0, 0
a00ed9dc:  12 80 00 a3  bne  0xa00edc68
a00ed9e0:  01 00 00 00  nop
a00ed9e4:  80 a6 ff ff  cmp  %i3, -1
a00ed9e8:  02 80 00 64  be  0xa00edb78
a00ed9ec:  a8 14 a1 18  or  %l2, 0x118, %l4
a00ed9f0:  98 14 20 f8  or  %l0, 0xf8, %o4
a00ed9f4:  b6 14 61 08  or  %l1, 0x108, %i3
a00ed9f8:  d6 03 00 1a  ld  [ %o4 + %i2 ], %o3
a00ed9fc:  d2 05 00 1a  ld  [ %l4 + %i2 ], %o1
a00eda00:  d4 06 c0 1a  ld  [ %i3 + %i2 ], %o2
a00eda04:  7f ff cb 54  call  0xa00e0754
a00eda08:  90 10 00 18  mov  %i0, %o0
a00eda0c:  1f 2a 00 9a  sethi  %hi(0xa8026800), %o7
a00eda10:  d2 07 a0 58  ld  [ %fp + 0x58 ], %o1
a00eda14:  15 2a 00 9a  sethi  %hi(0xa8026800), %o2
a00eda18:  17 2a 00 9a  sethi  %hi(0xa8026800), %o3
a00eda1c:  98 02 00 09  add  %o0, %o1, %o4
a00eda20:  b8 13 e0 c8  or  %o7, 0xc8, %i4
a00eda24:  a6 12 a0 e8  or  %o2, 0xe8, %l3
a00eda28:  ba 12 e0 d8  or  %o3, 0xd8, %i5
a00eda2c:  90 10 00 18  mov  %i0, %o0
a00eda30:  d2 04 c0 1a  ld  [ %l3 + %i2 ], %o1
a00eda34:  d4 07 40 1a  ld  [ %i5 + %i2 ], %o2
a00eda38:  7f ff cb 4f  call  0xa00e0774
a00eda3c:  d6 07 00 1a  ld  [ %i4 + %i2 ], %o3
a00eda40:  d2 04 c0 1a  ld  [ %l3 + %i2 ], %o1
a00eda44:  d4 07 40 1a  ld  [ %i5 + %i2 ], %o2
a00eda48:  d6 07 00 1a  ld  [ %i4 + %i2 ], %o3
a00eda4c:  7f ff cb 42  call  0xa00e0754
a00eda50:  90 10 00 18  mov  %i0, %o0
a00eda54:  98 02 3f fc  add  %o0, -4, %o4
a00eda58:  33 2a 00 9a  sethi  %hi(0xa8026800), %i1
a00eda5c:  2d 2a 00 9a  sethi  %hi(0xa8026800), %l6
a00eda60:  1b 2a 00 9a  sethi  %hi(0xa8026800), %o5
a00eda64:  ae 16 60 98  or  %i1, 0x98, %l7
a00eda68:  aa 15 a0 b8  or  %l6, 0xb8, %l5
a00eda6c:  90 13 60 a8  or  %o5, 0xa8, %o0
a00eda70:  d6 05 c0 1a  ld  [ %l7 + %i2 ], %o3
a00eda74:  d2 05 40 1a  ld  [ %l5 + %i2 ], %o1
a00eda78:  d4 02 00 1a  ld  [ %o0 + %i2 ], %o2
a00eda7c:  7f ff cb 3e  call  0xa00e0774
a00eda80:  90 10 00 18  mov  %i0, %o0
a00eda84:  90 10 00 18  mov  %i0, %o0
a00eda88:  7f ff d9 5b  call  0xa00e3ff4
a00eda8c:  21 00 03 ff  sethi  %hi(0xffc00), %l0
a00eda90:  b4 14 23 7f  or  %l0, 0x37f, %i2	! 0xfff7f
a00eda94:  96 0a 00 1a  and  %o0, %i2, %o3
a00eda98:  90 10 00 18  mov  %i0, %o0
a00eda9c:  92 10 20 06  mov  6, %o1
a00edaa0:  7f ff d9 73  call  0xa00e406c
a00edaa4:  94 10 20 01  mov  1, %o2
a00edaa8:  90 10 00 18  mov  %i0, %o0
a00edaac:  92 10 21 49  mov  0x149, %o1
a00edab0:  7f ff ca 40  call  0xa00e03b0
a00edab4:  94 10 20 00  clr  %o2
a00edab8:  92 10 20 8e  mov  0x8e, %o1
a00edabc:  94 10 20 02  mov  2, %o2
a00edac0:  96 10 20 01  mov  1, %o3
a00edac4:  98 10 20 00  clr  %o4
a00edac8:  7f ff cb 2b  call  0xa00e0774
a00edacc:  90 10 00 18  mov  %i0, %o0
a00edad0:  7f ff c9 70  call  0xa00e0090
a00edad4:  90 10 00 18  mov  %i0, %o0
a00edad8:  90 10 00 18  mov  %i0, %o0
a00edadc:  d4 07 bf d4  ld  [ %fp + -44 ], %o2
a00edae0:  7f ff ca 34  call  0xa00e03b0
a00edae4:  92 10 21 49  mov  0x149, %o1
a00edae8:  10 80 00 60  b  0xa00edc68
a00edaec:  90 10 20 00  clr  %o0
a00edaf0:  92 15 60 88  or  %l5, 0x88, %o1
a00edaf4:  94 14 e0 78  or  %l3, 0x78, %o2
a00edaf8:  10 bf ff 5c  b  0xa00ed868
a00edafc:  96 15 23 18  or  %l4, 0x318, %o3
a00edb00:  e8 04 3f f0  ld  [ %l0 + -16 ], %l4
a00edb04:  80 a5 20 01  cmp  %l4, 1
a00edb08:  34 bf ff 95  bg,a   0xa00ed95c
a00edb0c:  f2 07 a0 60  ld  [ %fp + 0x60 ], %i1
a00edb10:  92 10 00 1b  mov  %i3, %o1
a00edb14:  94 10 20 06  mov  6, %o2
a00edb18:  7f ff fe 86  call  0xa00ed530
a00edb1c:  90 10 00 18  mov  %i0, %o0
a00edb20:  ee 04 3f e0  ld  [ %l0 + -32 ], %l7
a00edb24:  ac 05 e0 01  add  %l7, 1, %l6
a00edb28:  7f ff cc 20  call  0xa00e0ba8
a00edb2c:  ec 24 3f e0  st  %l6, [ %l0 + -32 ]
a00edb30:  2b 00 06 67  sethi  %hi(0x199c00), %l5
a00edb34:  90 15 62 98  or  %l5, 0x298, %o0	! 0x199e98
a00edb38:  92 10 00 18  mov  %i0, %o1
a00edb3c:  7f ff c5 8d  call  0xa00df170
a00edb40:  94 10 00 1b  mov  %i3, %o2
a00edb44:  10 bf ff 86  b  0xa00ed95c
a00edb48:  f2 07 a0 60  ld  [ %fp + 0x60 ], %i1
a00edb4c:  92 15 60 88  or  %l5, 0x88, %o1
a00edb50:  94 14 e0 78  or  %l3, 0x78, %o2
a00edb54:  10 bf ff 71  b  0xa00ed918
a00edb58:  96 15 23 18  or  %l4, 0x318, %o3
a00edb5c:  13 2a 00 9a  sethi  %hi(0xa8026800), %o1
a00edb60:  15 2a 00 9a  sethi  %hi(0xa8026800), %o2
a00edb64:  17 2a 00 9a  sethi  %hi(0xa8026800), %o3
a00edb68:  92 12 61 78  or  %o1, 0x178, %o1
a00edb6c:  94 12 a1 68  or  %o2, 0x168, %o2
a00edb70:  10 bf ff 08  b  0xa00ed790
a00edb74:  96 12 e1 58  or  %o3, 0x158, %o3
a00edb78:  92 14 a1 18  or  %l2, 0x118, %o1
a00edb7c:  94 14 61 08  or  %l1, 0x108, %o2
a00edb80:  96 14 20 f8  or  %l0, 0xf8, %o3
a00edb84:  7f ff ca f4  call  0xa00e0754
a00edb88:  90 10 00 18  mov  %i0, %o0
a00edb8c:  c2 07 a0 58  ld  [ %fp + 0x58 ], %g1
a00edb90:  98 02 00 01  add  %o0, %g1, %o4
a00edb94:  29 2a 00 9a  sethi  %hi(0xa8026800), %l4
a00edb98:  23 2a 00 9a  sethi  %hi(0xa8026800), %l1
a00edb9c:  25 2a 00 9a  sethi  %hi(0xa8026800), %l2
a00edba0:  90 10 00 18  mov  %i0, %o0
a00edba4:  92 15 20 e8  or  %l4, 0xe8, %o1
a00edba8:  94 14 60 d8  or  %l1, 0xd8, %o2
a00edbac:  7f ff ca f2  call  0xa00e0774
a00edbb0:  96 14 a0 c8  or  %l2, 0xc8, %o3
a00edbb4:  92 15 20 e8  or  %l4, 0xe8, %o1
a00edbb8:  94 14 60 d8  or  %l1, 0xd8, %o2
a00edbbc:  96 14 a0 c8  or  %l2, 0xc8, %o3
a00edbc0:  7f ff ca e5  call  0xa00e0754
a00edbc4:  90 10 00 18  mov  %i0, %o0
a00edbc8:  21 2a 00 9a  sethi  %hi(0xa8026800), %l0
a00edbcc:  37 2a 00 9a  sethi  %hi(0xa8026800), %i3
a00edbd0:  35 2a 00 9a  sethi  %hi(0xa8026800), %i2
a00edbd4:  98 02 3f fc  add  %o0, -4, %o4
a00edbd8:  92 14 20 b8  or  %l0, 0xb8, %o1
a00edbdc:  94 16 e0 a8  or  %i3, 0xa8, %o2
a00edbe0:  10 bf ff a7  b  0xa00eda7c
a00edbe4:  96 16 a0 98  or  %i2, 0x98, %o3
a00edbe8:  7f ff d9 03  call  0xa00e3ff4
a00edbec:  90 10 00 18  mov  %i0, %o0
a00edbf0:  80 8a 20 01  btst  1, %o0
a00edbf4:  12 bf ff 04  bne  0xa00ed804
a00edbf8:  01 00 00 00  nop
a00edbfc:  7f ff c7 04  call  0xa00df80c
a00edc00:  25 00 06 67  sethi  %hi(0x199c00), %l2
a00edc04:  7f ff cb ef  call  0xa00e0bc0
a00edc08:  01 00 00 00  nop
a00edc0c:  90 14 a2 b0  or  %l2, 0x2b0, %o0
a00edc10:  7f ff c5 58  call  0xa00df170
a00edc14:  01 00 00 00  nop
a00edc18:  10 80 00 14  b  0xa00edc68
a00edc1c:  90 10 3f ff  mov  -1, %o0	! 0xffffffff
a00edc20:  23 2a 00 9a  sethi  %hi(0xa8026800), %l1
a00edc24:  21 2a 00 9a  sethi  %hi(0xa8026800), %l0
a00edc28:  90 10 00 18  mov  %i0, %o0
a00edc2c:  92 14 a1 18  or  %l2, 0x118, %o1
a00edc30:  94 14 61 08  or  %l1, 0x108, %o2
a00edc34:  10 bf ff 61  b  0xa00ed9b8
a00edc38:  96 14 20 f8  or  %l0, 0xf8, %o3
a00edc3c:  7f ff d8 ee  call  0xa00e3ff4
a00edc40:  90 10 00 18  mov  %i0, %o0
a00edc44:  80 8a 20 01  btst  1, %o0
a00edc48:  02 bf fe ef  be  0xa00ed804
a00edc4c:  01 00 00 00  nop
a00edc50:  7f ff c6 ef  call  0xa00df80c
a00edc54:  27 00 06 67  sethi  %hi(0x199c00), %l3
a00edc58:  7f ff cb da  call  0xa00e0bc0
a00edc5c:  01 00 00 00  nop
a00edc60:  10 bf ff ec  b  0xa00edc10
a00edc64:  90 14 e2 d0  or  %l3, 0x2d0, %o0
a00edc68:  81 c7 e0 08  ret
a00edc6c:  91 e8 00 08  restore  %g0, %o0, %o0
