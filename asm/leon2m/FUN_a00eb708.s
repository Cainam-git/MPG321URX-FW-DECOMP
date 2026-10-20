# leon2m FUN_a00eb708 0xa00eb708-0xa00eba64 (860 bytes)
a00eb708:  9d e3 bf 98  save  %sp, -104, %sp
a00eb70c:  80 a6 7f ff  cmp  %i1, -1
a00eb710:  02 80 00 a2  be  0xa00eb998
a00eb714:  03 2a 00 9a  sethi  %hi(0xa8026800), %g1
a00eb718:  a1 2e 60 02  sll  %i1, 2, %l0
a00eb71c:  96 10 61 18  or  %g1, 0x118, %o3
a00eb720:  39 2a 00 9a  sethi  %hi(0xa8026800), %i4
a00eb724:  19 2a 00 9a  sethi  %hi(0xa8026800), %o4
a00eb728:  9a 13 20 f8  or  %o4, 0xf8, %o5	! 0xa80268f8
a00eb72c:  9e 17 21 08  or  %i4, 0x108, %o7
a00eb730:  37 2a 00 b5  sethi  %hi(0xa802d400), %i3
a00eb734:  d2 02 c0 10  ld  [ %o3 + %l0 ], %o1
a00eb738:  d6 03 40 10  ld  [ %o5 + %l0 ], %o3
a00eb73c:  d4 03 c0 10  ld  [ %o7 + %l0 ], %o2
a00eb740:  90 10 00 18  mov  %i0, %o0
a00eb744:  7f ff d4 0c  call  0xa00e0774
a00eb748:  d8 06 e2 6c  ld  [ %i3 + 0x26c ], %o4
a00eb74c:  13 2a 00 9a  sethi  %hi(0xa8026800), %o1
a00eb750:  90 12 60 e8  or  %o1, 0xe8, %o0	! 0xa80268e8
a00eb754:  15 2a 00 9a  sethi  %hi(0xa8026800), %o2
a00eb758:  17 2a 00 9a  sethi  %hi(0xa8026800), %o3
a00eb75c:  d2 02 00 10  ld  [ %o0 + %l0 ], %o1
a00eb760:  82 12 a0 d8  or  %o2, 0xd8, %g1
a00eb764:  de 06 e2 6c  ld  [ %i3 + 0x26c ], %o7
a00eb768:  b8 12 e0 c8  or  %o3, 0xc8, %i4
a00eb76c:  d4 00 40 10  ld  [ %g1 + %l0 ], %o2
a00eb770:  d6 07 00 10  ld  [ %i4 + %l0 ], %o3
a00eb774:  98 03 c0 1a  add  %o7, %i2, %o4
a00eb778:  7f ff d3 ff  call  0xa00e0774
a00eb77c:  90 10 00 18  mov  %i0, %o0
a00eb780:  13 2a 00 9a  sethi  %hi(0xa8026800), %o1
a00eb784:  15 2a 00 9a  sethi  %hi(0xa8026800), %o2
a00eb788:  1b 2a 00 9a  sethi  %hi(0xa8026800), %o5
a00eb78c:  d8 06 e2 6c  ld  [ %i3 + 0x26c ], %o4
a00eb790:  90 13 60 98  or  %o5, 0x98, %o0
a00eb794:  82 12 60 b8  or  %o1, 0xb8, %g1
a00eb798:  b8 12 a0 a8  or  %o2, 0xa8, %i4
a00eb79c:  98 03 00 1a  add  %o4, %i2, %o4
a00eb7a0:  d6 02 00 10  ld  [ %o0 + %l0 ], %o3
a00eb7a4:  d2 00 40 10  ld  [ %g1 + %l0 ], %o1
a00eb7a8:  d4 07 00 10  ld  [ %i4 + %l0 ], %o2
a00eb7ac:  98 03 3f fc  add  %o4, -4, %o4
a00eb7b0:  7f ff d3 f1  call  0xa00e0774
a00eb7b4:  90 10 00 18  mov  %i0, %o0
a00eb7b8:  80 a6 a0 08  cmp  %i2, 8
a00eb7bc:  04 80 00 43  ble  0xa00eb8c8
a00eb7c0:  80 a6 7f ff  cmp  %i1, -1
a00eb7c4:  02 80 00 92  be  0xa00eba0c
a00eb7c8:  1f 2a 00 9a  sethi  %hi(0xa8026800), %o7
a00eb7cc:  15 2a 00 9a  sethi  %hi(0xa8026800), %o2
a00eb7d0:  b7 2e 60 02  sll  %i1, 2, %i3
a00eb7d4:  98 13 e1 28  or  %o7, 0x128, %o4
a00eb7d8:  13 2a 00 9a  sethi  %hi(0xa8026800), %o1
a00eb7dc:  90 12 a1 38  or  %o2, 0x138, %o0
a00eb7e0:  d6 03 00 1b  ld  [ %o4 + %i3 ], %o3
a00eb7e4:  9a 12 61 48  or  %o1, 0x148, %o5
a00eb7e8:  d4 02 00 1b  ld  [ %o0 + %i3 ], %o2
a00eb7ec:  d2 03 40 1b  ld  [ %o5 + %i3 ], %o1
a00eb7f0:  90 10 00 18  mov  %i0, %o0
a00eb7f4:  7f ff d3 e0  call  0xa00e0774
a00eb7f8:  98 10 20 03  mov  3, %o4
a00eb7fc:  80 a6 7f ff  cmp  %i1, -1
a00eb800:  22 80 00 44  be,a   0xa00eb910
a00eb804:  11 2a 00 ad  sethi  %hi(0xa802b400), %o0
a00eb808:  1b 2a 00 99  sethi  %hi(0xa8026400), %o5
a00eb80c:  b9 2e 60 02  sll  %i1, 2, %i4
a00eb810:  94 13 63 68  or  %o5, 0x368, %o2
a00eb814:  11 2a 00 99  sethi  %hi(0xa8026400), %o0
a00eb818:  21 2a 00 ad  sethi  %hi(0xa802b400), %l0
a00eb81c:  d2 02 80 1c  ld  [ %o2 + %i4 ], %o1
a00eb820:  b6 12 23 58  or  %o0, 0x358, %i3
a00eb824:  b4 14 22 e8  or  %l0, 0x2e8, %i2
a00eb828:  d4 06 c0 1c  ld  [ %i3 + %i4 ], %o2
a00eb82c:  d6 06 80 1c  ld  [ %i2 + %i4 ], %o3
a00eb830:  90 10 00 18  mov  %i0, %o0
a00eb834:  7f ff d3 d0  call  0xa00e0774
a00eb838:  98 10 20 00  clr  %o4
a00eb83c:  1f 2a 00 ad  sethi  %hi(0xa802b400), %o7
a00eb840:  17 2a 00 99  sethi  %hi(0xa8026400), %o3
a00eb844:  98 13 e2 d8  or  %o7, 0x2d8, %o4
a00eb848:  b2 12 e3 08  or  %o3, 0x308, %i1
a00eb84c:  13 2a 00 99  sethi  %hi(0xa8026400), %o1
a00eb850:  82 12 63 18  or  %o1, 0x318, %g1	! 0xa8026718
a00eb854:  d6 03 00 1c  ld  [ %o4 + %i4 ], %o3
a00eb858:  d2 00 40 1c  ld  [ %g1 + %i4 ], %o1
a00eb85c:  d4 06 40 1c  ld  [ %i1 + %i4 ], %o2
a00eb860:  90 10 00 18  mov  %i0, %o0
a00eb864:  7f ff d3 c4  call  0xa00e0774
a00eb868:  98 10 20 00  clr  %o4
a00eb86c:  1b 2a 00 99  sethi  %hi(0xa8026400), %o5
a00eb870:  94 13 63 98  or  %o5, 0x398, %o2	! 0xa8026798
a00eb874:  11 2a 00 99  sethi  %hi(0xa8026400), %o0
a00eb878:  21 2a 00 99  sethi  %hi(0xa8026400), %l0
a00eb87c:  d2 02 80 1c  ld  [ %o2 + %i4 ], %o1
a00eb880:  b6 12 23 88  or  %o0, 0x388, %i3
a00eb884:  b4 14 23 78  or  %l0, 0x378, %i2
a00eb888:  d6 06 80 1c  ld  [ %i2 + %i4 ], %o3
a00eb88c:  d4 06 c0 1c  ld  [ %i3 + %i4 ], %o2
a00eb890:  98 10 20 00  clr  %o4
a00eb894:  7f ff d3 b8  call  0xa00e0774
a00eb898:  90 10 00 18  mov  %i0, %o0
a00eb89c:  33 2a 00 99  sethi  %hi(0xa8026400), %i1
a00eb8a0:  03 2a 00 99  sethi  %hi(0xa8026400), %g1
a00eb8a4:  19 2a 00 99  sethi  %hi(0xa8026400), %o4
a00eb8a8:  96 10 63 28  or  %g1, 0x328, %o3
a00eb8ac:  9e 16 63 48  or  %i1, 0x348, %o7
a00eb8b0:  92 13 23 38  or  %o4, 0x338, %o1
a00eb8b4:  f6 02 c0 1c  ld  [ %o3 + %i4 ], %i3
a00eb8b8:  f2 03 c0 1c  ld  [ %o7 + %i4 ], %i1
a00eb8bc:  f4 02 40 1c  ld  [ %o1 + %i4 ], %i2
a00eb8c0:  7f ff d3 ad  call  0xa00e0774
a00eb8c4:  99 e8 20 00  restore  %g0, 0, %o4
a00eb8c8:  02 80 00 5c  be  0xa00eba38
a00eb8cc:  37 2a 00 9a  sethi  %hi(0xa8026800), %i3
a00eb8d0:  13 2a 00 9a  sethi  %hi(0xa8026800), %o1
a00eb8d4:  15 2a 00 9a  sethi  %hi(0xa8026800), %o2
a00eb8d8:  b5 2e 60 02  sll  %i1, 2, %i2
a00eb8dc:  9a 12 61 28  or  %o1, 0x128, %o5
a00eb8e0:  90 12 a1 48  or  %o2, 0x148, %o0
a00eb8e4:  d2 02 00 1a  ld  [ %o0 + %i2 ], %o1
a00eb8e8:  a0 16 e1 38  or  %i3, 0x138, %l0
a00eb8ec:  d6 03 40 1a  ld  [ %o5 + %i2 ], %o3
a00eb8f0:  d4 04 00 1a  ld  [ %l0 + %i2 ], %o2
a00eb8f4:  90 10 00 18  mov  %i0, %o0
a00eb8f8:  7f ff d3 9f  call  0xa00e0774
a00eb8fc:  98 10 20 00  clr  %o4
a00eb900:  80 a6 7f ff  cmp  %i1, -1
a00eb904:  12 bf ff c2  bne  0xa00eb80c
a00eb908:  1b 2a 00 99  sethi  %hi(0xa8026400), %o5
a00eb90c:  11 2a 00 ad  sethi  %hi(0xa802b400), %o0
a00eb910:  1b 2a 00 99  sethi  %hi(0xa8026400), %o5
a00eb914:  96 12 22 e8  or  %o0, 0x2e8, %o3
a00eb918:  15 2a 00 99  sethi  %hi(0xa8026400), %o2
a00eb91c:  92 13 63 68  or  %o5, 0x368, %o1
a00eb920:  94 12 a3 58  or  %o2, 0x358, %o2
a00eb924:  90 10 00 18  mov  %i0, %o0
a00eb928:  7f ff d3 93  call  0xa00e0774
a00eb92c:  98 10 20 00  clr  %o4
a00eb930:  37 2a 00 99  sethi  %hi(0xa8026400), %i3
a00eb934:  35 2a 00 ad  sethi  %hi(0xa802b400), %i2
a00eb938:  21 2a 00 99  sethi  %hi(0xa8026400), %l0
a00eb93c:  92 16 e3 18  or  %i3, 0x318, %o1
a00eb940:  96 16 a2 d8  or  %i2, 0x2d8, %o3
a00eb944:  90 10 00 18  mov  %i0, %o0
a00eb948:  94 14 23 08  or  %l0, 0x308, %o2
a00eb94c:  7f ff d3 8a  call  0xa00e0774
a00eb950:  98 10 20 00  clr  %o4
a00eb954:  17 2a 00 99  sethi  %hi(0xa8026400), %o3
a00eb958:  03 2a 00 99  sethi  %hi(0xa8026400), %g1
a00eb95c:  94 12 e3 88  or  %o3, 0x388, %o2
a00eb960:  39 2a 00 99  sethi  %hi(0xa8026400), %i4
a00eb964:  96 17 23 78  or  %i4, 0x378, %o3	! 0xa8026778
a00eb968:  98 10 20 00  clr  %o4
a00eb96c:  90 10 00 18  mov  %i0, %o0
a00eb970:  7f ff d3 81  call  0xa00e0774
a00eb974:  92 10 63 98  or  %g1, 0x398, %o1
a00eb978:  33 2a 00 99  sethi  %hi(0xa8026400), %i1
a00eb97c:  1f 2a 00 99  sethi  %hi(0xa8026400), %o7
a00eb980:  19 2a 00 99  sethi  %hi(0xa8026400), %o4
a00eb984:  b2 16 63 48  or  %i1, 0x348, %i1
a00eb988:  b4 13 e3 38  or  %o7, 0x338, %i2
a00eb98c:  b6 13 23 28  or  %o4, 0x328, %i3
a00eb990:  7f ff d3 79  call  0xa00e0774
a00eb994:  99 e8 20 00  restore  %g0, 0, %o4
a00eb998:  17 2a 00 9a  sethi  %hi(0xa8026800), %o3
a00eb99c:  39 2a 00 b5  sethi  %hi(0xa802d400), %i4
a00eb9a0:  92 12 e1 18  or  %o3, 0x118, %o1
a00eb9a4:  37 2a 00 9a  sethi  %hi(0xa8026800), %i3
a00eb9a8:  21 2a 00 9a  sethi  %hi(0xa8026800), %l0
a00eb9ac:  94 16 e1 08  or  %i3, 0x108, %o2
a00eb9b0:  96 14 20 f8  or  %l0, 0xf8, %o3
a00eb9b4:  90 10 00 18  mov  %i0, %o0
a00eb9b8:  7f ff d3 6f  call  0xa00e0774
a00eb9bc:  d8 07 22 6c  ld  [ %i4 + 0x26c ], %o4
a00eb9c0:  11 2a 00 9a  sethi  %hi(0xa8026800), %o0
a00eb9c4:  96 12 20 c8  or  %o0, 0xc8, %o3	! 0xa80268c8
a00eb9c8:  c2 07 22 6c  ld  [ %i4 + 0x26c ], %g1
a00eb9cc:  1f 2a 00 9a  sethi  %hi(0xa8026800), %o7
a00eb9d0:  1b 2a 00 9a  sethi  %hi(0xa8026800), %o5
a00eb9d4:  92 13 e0 e8  or  %o7, 0xe8, %o1
a00eb9d8:  94 13 60 d8  or  %o5, 0xd8, %o2
a00eb9dc:  98 00 40 1a  add  %g1, %i2, %o4
a00eb9e0:  7f ff d3 65  call  0xa00e0774
a00eb9e4:  90 10 00 18  mov  %i0, %o0
a00eb9e8:  d8 07 22 6c  ld  [ %i4 + 0x26c ], %o4
a00eb9ec:  13 2a 00 9a  sethi  %hi(0xa8026800), %o1
a00eb9f0:  15 2a 00 9a  sethi  %hi(0xa8026800), %o2
a00eb9f4:  17 2a 00 9a  sethi  %hi(0xa8026800), %o3
a00eb9f8:  98 03 00 1a  add  %o4, %i2, %o4
a00eb9fc:  92 12 60 b8  or  %o1, 0xb8, %o1
a00eba00:  94 12 a0 a8  or  %o2, 0xa8, %o2
a00eba04:  10 bf ff 6a  b  0xa00eb7ac
a00eba08:  96 12 e0 98  or  %o3, 0x98, %o3
a00eba0c:  21 2a 00 9a  sethi  %hi(0xa8026800), %l0
a00eba10:  35 2a 00 9a  sethi  %hi(0xa8026800), %i2
a00eba14:  33 2a 00 9a  sethi  %hi(0xa8026800), %i1
a00eba18:  92 14 21 48  or  %l0, 0x148, %o1
a00eba1c:  94 16 a1 38  or  %i2, 0x138, %o2
a00eba20:  96 16 61 28  or  %i1, 0x128, %o3
a00eba24:  90 10 00 18  mov  %i0, %o0
a00eba28:  7f ff d3 53  call  0xa00e0774
a00eba2c:  98 10 20 03  mov  3, %o4
a00eba30:  10 bf ff b8  b  0xa00eb910
a00eba34:  11 2a 00 ad  sethi  %hi(0xa802b400), %o0
a00eba38:  17 2a 00 9a  sethi  %hi(0xa8026800), %o3
a00eba3c:  03 2a 00 9a  sethi  %hi(0xa8026800), %g1
a00eba40:  94 12 e1 38  or  %o3, 0x138, %o2
a00eba44:  39 2a 00 9a  sethi  %hi(0xa8026800), %i4
a00eba48:  92 10 61 48  or  %g1, 0x148, %o1
a00eba4c:  96 17 21 28  or  %i4, 0x128, %o3
a00eba50:  90 10 00 18  mov  %i0, %o0
a00eba54:  7f ff d3 48  call  0xa00e0774
a00eba58:  98 10 20 00  clr  %o4
a00eba5c:  10 bf ff ad  b  0xa00eb910
a00eba60:  11 2a 00 ad  sethi  %hi(0xa802b400), %o0
