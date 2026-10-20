# leon2m FUN_a0109844 0xa0109844-0xa01099fc (440 bytes)
a0109844:  9d e3 bf 98  save  %sp, -104, %sp
a0109848:  11 33 c0 47  sethi  %hi(0xcf011c00), %o0
a010984c:  82 12 21 8c  or  %o0, 0x18c, %g1	! 0xcf011d8c
a0109850:  da 00 40 00  ld  [ %g1 ], %o5
a0109854:  b2 0b 60 ff  and  %o5, 0xff, %i1
a0109858:  80 8e 60 01  btst  1, %i1
a010985c:  22 80 00 33  be,a   0xa0109928
a0109860:  90 12 23 64  or  %o0, 0x364, %o0
a0109864:  7f ff a6 05  call  0xa00f3078
a0109868:  90 12 21 e0  or  %o0, 0x1e0, %o0
a010986c:  95 2a 20 10  sll  %o0, 0x10, %o2
a0109870:  93 32 a0 11  srl  %o2, 0x11, %o1
a0109874:  80 8e 60 02  btst  2, %i1
a0109878:  02 80 00 21  be  0xa01098fc
a010987c:  83 2a 60 10  sll  %o1, 0x10, %g1
a0109880:  95 2a 20 10  sll  %o0, 0x10, %o2
a0109884:  83 32 a0 10  srl  %o2, 0x10, %g1
a0109888:  93 28 60 02  sll  %g1, 2, %o1
a010988c:  9a 02 40 01  add  %o1, %g1, %o5
a0109890:  31 15 55 55  sethi  %hi(0x55555400), %i0
a0109894:  9e 16 21 56  or  %i0, 0x156, %o7	! 0x55555556
a0109898:  96 03 40 0d  add  %o5, %o5, %o3
a010989c:  80 5a c0 0f  smul  %o3, %o7, %g0
a01098a0:  97 40 00 00  rd  %y, %o3
a01098a4:  99 2a e0 10  sll  %o3, 0x10, %o4
a01098a8:  11 33 33 33  sethi  %hi(0xcccccc00), %o0
a01098ac:  9f 33 20 10  srl  %o4, 0x10, %o7
a01098b0:  94 12 20 cd  or  %o0, 0xcd, %o2
a01098b4:  80 53 c0 0a  umul  %o7, %o2, %g0
a01098b8:  93 40 00 00  rd  %y, %o1
a01098bc:  95 32 60 03  srl  %o1, 3, %o2
a01098c0:  83 2a a0 02  sll  %o2, 2, %g1
a01098c4:  9a 00 40 0a  add  %g1, %o2, %o5
a01098c8:  b0 03 40 0d  add  %o5, %o5, %i0
a01098cc:  90 23 c0 18  sub  %o7, %i0, %o0
a01098d0:  99 2a 20 10  sll  %o0, 0x10, %o4
a01098d4:  80 a3 20 00  cmp  %o4, 0
a01098d8:  12 80 00 45  bne  0xa01099ec
a01098dc:  82 10 00 0b  mov  %o3, %g1
a01098e0:  80 88 60 1f  btst  0x1f, %g1
a01098e4:  02 80 00 06  be  0xa01098fc
a01098e8:  83 28 60 10  sll  %g1, 0x10, %g1
a01098ec:  97 30 60 15  srl  %g1, 0x15, %o3
a01098f0:  99 2a e0 05  sll  %o3, 5, %o4
a01098f4:  90 03 20 20  add  %o4, 0x20, %o0
a01098f8:  83 2a 20 10  sll  %o0, 0x10, %g1
a01098fc:  1f 33 c0 47  sethi  %hi(0xcf011c00), %o7
a0109900:  90 13 e3 64  or  %o7, 0x364, %o0	! 0xcf011f64
a0109904:  7f ff a5 e2  call  0xa00f308c
a0109908:  93 30 60 10  srl  %g1, 0x10, %o1
a010990c:  80 8e 60 04  btst  4, %i1
a0109910:  12 80 00 0c  bne  0xa0109940
a0109914:  13 33 c0 47  sethi  %hi(0xcf011c00), %o1
a0109918:  19 33 c0 47  sethi  %hi(0xcf011c00), %o4
a010991c:  b0 13 23 6c  or  %o4, 0x36c, %i0	! 0xcf011f6c
a0109920:  7f ff a5 db  call  0xa00f308c
a0109924:  93 e8 20 00  restore  %g0, 0, %o1
a0109928:  7f ff a5 d9  call  0xa00f308c
a010992c:  92 10 20 00  clr  %o1
a0109930:  80 8e 60 04  btst  4, %i1
a0109934:  02 bf ff fa  be  0xa010991c
a0109938:  19 33 c0 47  sethi  %hi(0xcf011c00), %o4
a010993c:  13 33 c0 47  sethi  %hi(0xcf011c00), %o1
a0109940:  7f ff a5 ce  call  0xa00f3078
a0109944:  90 12 62 00  or  %o1, 0x200, %o0	! 0xcf011e00
a0109948:  9b 2a 20 10  sll  %o0, 0x10, %o5
a010994c:  b1 33 60 11  srl  %o5, 0x11, %i0
a0109950:  80 8e 60 08  btst  8, %i1
a0109954:  02 80 00 21  be  0xa01099d8
a0109958:  83 2e 20 10  sll  %i0, 0x10, %g1
a010995c:  93 2a 20 10  sll  %o0, 0x10, %o1
a0109960:  9b 32 60 10  srl  %o1, 0x10, %o5
a0109964:  b1 2b 60 02  sll  %o5, 2, %i0
a0109968:  9e 06 00 0d  add  %i0, %o5, %o7
a010996c:  33 15 55 55  sethi  %hi(0x55555400), %i1
a0109970:  96 03 c0 0f  add  %o7, %o7, %o3
a0109974:  98 16 61 56  or  %i1, 0x156, %o4
a0109978:  80 5a c0 0c  smul  %o3, %o4, %g0
a010997c:  b3 40 00 00  rd  %y, %i1
a0109980:  91 2e 60 10  sll  %i1, 0x10, %o0
a0109984:  03 33 33 33  sethi  %hi(0xcccccc00), %g1
a0109988:  94 10 60 cd  or  %g1, 0xcd, %o2	! 0xcccccccd
a010998c:  99 32 20 10  srl  %o0, 0x10, %o4
a0109990:  80 53 00 0a  umul  %o4, %o2, %g0
a0109994:  93 40 00 00  rd  %y, %o1
a0109998:  95 32 60 03  srl  %o1, 3, %o2
a010999c:  9b 2a a0 02  sll  %o2, 2, %o5
a01099a0:  b0 03 40 0a  add  %o5, %o2, %i0
a01099a4:  9e 06 00 18  add  %i0, %i0, %o7
a01099a8:  90 23 00 0f  sub  %o4, %o7, %o0
a01099ac:  83 2a 20 10  sll  %o0, 0x10, %g1
a01099b0:  80 a0 60 00  cmp  %g1, 0
a01099b4:  12 80 00 10  bne  0xa01099f4
a01099b8:  82 10 00 19  mov  %i1, %g1
a01099bc:  80 88 60 1f  btst  0x1f, %g1
a01099c0:  02 80 00 06  be  0xa01099d8
a01099c4:  83 28 60 10  sll  %g1, 0x10, %g1
a01099c8:  91 30 60 15  srl  %g1, 0x15, %o0
a01099cc:  83 2a 20 05  sll  %o0, 5, %g1
a01099d0:  94 00 60 20  add  %g1, 0x20, %o2
a01099d4:  83 2a a0 10  sll  %o2, 0x10, %g1
a01099d8:  17 33 c0 47  sethi  %hi(0xcf011c00), %o3
a01099dc:  b0 12 e3 6c  or  %o3, 0x36c, %i0	! 0xcf011f6c
a01099e0:  b3 30 60 10  srl  %g1, 0x10, %i1
a01099e4:  7f ff a5 aa  call  0xa00f308c
a01099e8:  81 e8 00 00  restore
a01099ec:  10 bf ff bd  b  0xa01098e0
a01099f0:  82 02 a0 01  add  %o2, 1, %g1
a01099f4:  10 bf ff f2  b  0xa01099bc
a01099f8:  82 02 a0 01  add  %o2, 1, %g1
