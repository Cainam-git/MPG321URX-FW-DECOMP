# leon2m FUN_a00de7c4 0xa00de7c4-0xa00de970 (428 bytes)
a00de7c4:  9d e3 bf 98  save  %sp, -104, %sp
a00de7c8:  03 27 c0 80  sethi  %hi(0x9f020000), %g1
a00de7cc:  90 10 60 e0  or  %g1, 0xe0, %o0	! 0x9f0200e0
a00de7d0:  67 fe b6 a3  call  0x4008c25c
a00de7d4:  92 10 20 c0  mov  0xc0, %o1
a00de7d8:  01 00 00 00  nop
a00de7dc:  01 00 00 00  nop
a00de7e0:  01 00 00 00  nop
a00de7e4:  01 00 00 00  nop
a00de7e8:  01 00 00 00  nop
a00de7ec:  11 27 c0 00  sethi  %hi(0x9f000000), %o0
a00de7f0:  13 00 08 40  sethi  %hi(0x210000), %o1
a00de7f4:  90 12 20 14  or  %o0, 0x14, %o0
a00de7f8:  67 fe b6 99  call  0x4008c25c
a00de7fc:  92 12 60 03  or  %o1, 3, %o1
a00de800:  82 10 23 ff  mov  0x3ff, %g1
a00de804:  01 00 00 00  nop
a00de808:  82 80 7f ff  addcc  %g1, -1, %g1
a00de80c:  1c bf ff fe  bpos  0xa00de804
a00de810:  11 30 00 00  sethi  %hi(0xc0000000), %o0
a00de814:  67 fe b6 92  call  0x4008c25c
a00de818:  92 10 20 21  mov  0x21, %o1
a00de81c:  15 00 00 3e  sethi  %hi(0xf800), %o2
a00de820:  82 12 a1 ff  or  %o2, 0x1ff, %g1	! 0xf9ff
a00de824:  98 10 20 00  clr  %o4
a00de828:  9a 10 20 00  clr  %o5
a00de82c:  01 00 00 00  nop
a00de830:  01 00 00 00  nop
a00de834:  9a 03 60 01  inc  %o5
a00de838:  80 a3 40 01  cmp  %o5, %g1
a00de83c:  08 bf ff fc  bleu  0xa00de82c
a00de840:  01 00 00 00  nop
a00de844:  98 03 20 01  inc  %o4
a00de848:  80 a3 20 01  cmp  %o4, 1
a00de84c:  0a bf ff f7  bcs  0xa00de828
a00de850:  11 30 00 00  sethi  %hi(0xc0000000), %o0
a00de854:  67 fe b6 82  call  0x4008c25c
a00de858:  92 10 20 00  clr  %o1
a00de85c:  23 27 c0 80  sethi  %hi(0x9f020000), %l1
a00de860:  90 14 63 20  or  %l1, 0x320, %o0	! 0x9f020320
a00de864:  67 fe b6 7e  call  0x4008c25c
a00de868:  92 10 20 05  mov  5, %o1
a00de86c:  90 14 63 24  or  %l1, 0x324, %o0
a00de870:  67 fe b6 7b  call  0x4008c25c
a00de874:  13 2a 00 f9  sethi  %hi(0xa803e400), %o1
a00de878:  1b 28 00 b3  sethi  %hi(0xa002cc00), %o5
a00de87c:  94 13 62 a8  or  %o5, 0x2a8, %o2	! 0xa002cea8
a00de880:  92 10 20 10  mov  0x10, %o1
a00de884:  67 fe af ff  call  0x4008a880
a00de888:  90 10 20 01  mov  1, %o0
a00de88c:  19 01 6e 36  sethi  %hi(0x5b8d800), %o4
a00de890:  21 2a 00 97  sethi  %hi(0xa8025c00), %l0
a00de894:  90 10 00 0c  mov  %o4, %o0
a00de898:  40 00 01 4c  call  0xa00dedc8
a00de89c:  d8 24 20 74  st  %o4, [ %l0 + 0x74 ]
a00de8a0:  40 00 00 bf  call  0xa00deb9c
a00de8a4:  d0 04 20 74  ld  [ %l0 + 0x74 ], %o0
a00de8a8:  17 2a 00 90  sethi  %hi(0xa8024000), %o3
a00de8ac:  b2 12 e0 00  mov  %o3, %i1	! 0xa8024000
a00de8b0:  67 fe b6 68  call  0x4008c250
a00de8b4:  90 14 62 04  or  %l1, 0x204, %o0
a00de8b8:  a0 10 20 00  clr  %l0
a00de8bc:  98 10 20 00  clr  %o4
a00de8c0:  9a 10 20 00  clr  %o5
a00de8c4:  9f 32 00 0d  srl  %o0, %o5, %o7
a00de8c8:  98 03 20 01  inc  %o4
a00de8cc:  80 8b e0 01  btst  1, %o7
a00de8d0:  12 80 00 03  bne  0xa00de8dc
a00de8d4:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00de8d8:  a0 04 20 01  inc  %l0
a00de8dc:  80 a3 60 17  cmp  %o5, 0x17
a00de8e0:  08 bf ff fa  bleu  0xa00de8c8
a00de8e4:  9f 32 00 0d  srl  %o0, %o5, %o7
a00de8e8:  31 27 c0 80  sethi  %hi(0x9f020000), %i0
a00de8ec:  67 fe b6 59  call  0x4008c250
a00de8f0:  90 16 22 00  or  %i0, 0x200, %o0	! 0x9f020200
a00de8f4:  98 10 20 1b  mov  0x1b, %o4
a00de8f8:  9a 10 20 1b  mov  0x1b, %o5
a00de8fc:  93 32 00 0d  srl  %o0, %o5, %o1
a00de900:  98 03 3f ff  add  %o4, -1, %o4
a00de904:  80 8a 60 01  btst  1, %o1
a00de908:  02 80 00 03  be  0xa00de914
a00de90c:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00de910:  a0 04 20 01  inc  %l0
a00de914:  80 a3 60 03  cmp  %o5, 3
a00de918:  18 bf ff fa  bgu  0xa00de900
a00de91c:  93 32 00 0d  srl  %o0, %o5, %o1
a00de920:  82 0c 20 ff  and  %l0, 0xff, %g1
a00de924:  91 28 60 0c  sll  %g1, 0xc, %o0
a00de928:  15 2a 00 f0  sethi  %hi(0xa803c000), %o2
a00de92c:  92 22 80 08  sub  %o2, %o0, %o1
a00de930:  80 a2 40 19  cmp  %o1, %i1
a00de934:  02 80 00 07  be  0xa00de950
a00de938:  23 00 06 63  sethi  %hi(0x198c00), %l1
a00de93c:  90 14 62 70  or  %l1, 0x270, %o0	! 0x198e70
a00de940:  40 00 02 0c  call  0xa00df170
a00de944:  94 10 00 19  mov  %i1, %o2
a00de948:  10 80 00 00  b  0xa00de948
a00de94c:  01 00 00 00  nop
a00de950:  7f ff fb d7  call  0xa00dd8ac
a00de954:  33 00 06 63  sethi  %hi(0x198c00), %i1
a00de958:  67 fe ab c0  call  0x40089858
a00de95c:  b2 16 62 b8  or  %i1, 0x2b8, %i1	! 0x198eb8
a00de960:  17 00 06 63  sethi  %hi(0x198c00), %o3
a00de964:  40 00 02 03  call  0xa00df170
a00de968:  91 ea e3 18  restore  %o3, 0x318, %o0
a00de96c:  01 00 00 00  nop
