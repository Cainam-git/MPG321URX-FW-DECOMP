# leon2s FUN_a00ab6e0 0xa00ab6e0-0xa00ab884 (420 bytes)  [FUN_a00ab87c = unreachable ret/restore tail, merged]
a00ab6e0:  9d e3 bf 98  save  %sp, -104, %sp
a00ab6e4:  83 2e 60 10  sll  %i1, 0x10, %g1
a00ab6e8:  99 30 60 10  srl  %g1, 0x10, %o4
a00ab6ec:  80 a3 20 00  cmp  %o4, 0
a00ab6f0:  02 80 00 62  be  0xa00ab878
a00ab6f4:  17 2a 01 e4  sethi  %hi(0xa8079000), %o3
a00ab6f8:  c2 12 e3 1a  lduh  [ %o3 + 0x31a ], %g1	! 0xa807931a
a00ab6fc:  82 18 40 0c  xor  %g1, %o4, %g1
a00ab700:  80 a0 00 01  cmp  %g0, %g1
a00ab704:  9a 60 3f ff  subx  %g0, -1, %o5
a00ab708:  82 0e a0 ff  and  %i2, 0xff, %g1
a00ab70c:  80 a0 00 01  cmp  %g0, %g1
a00ab710:  82 60 3f ff  subx  %g0, -1, %g1
a00ab714:  80 8b 40 01  btst  %o5, %g1
a00ab718:  12 80 00 58  bne  0xa00ab878
a00ab71c:  03 00 00 2e  sethi  %hi(0xb800), %g1
a00ab720:  82 10 63 80  or  %g1, 0x380, %g1	! 0xbb80
a00ab724:  9b 38 60 1f  sra  %g1, 0x1f, %o5
a00ab728:  81 83 60 00  mov  %o5, %y
a00ab72c:  01 00 00 00  nop
a00ab730:  01 00 00 00  nop
a00ab734:  01 00 00 00  nop
a00ab738:  82 78 40 0c  sdiv  %g1, %o4, %g1
a00ab73c:  99 30 60 01  srl  %g1, 1, %o4
a00ab740:  f2 32 e3 1a  sth  %i1, [ %o3 + 0x31a ]
a00ab744:  80 a3 20 ff  cmp  %o4, 0xff
a00ab748:  18 80 00 03  bgu  0xa00ab754
a00ab74c:  94 10 20 ff  mov  0xff, %o2
a00ab750:  94 10 00 0c  mov  %o4, %o2
a00ab754:  9a 20 40 0a  sub  %g1, %o2, %o5
a00ab758:  83 2b 60 10  sll  %o5, 0x10, %g1
a00ab75c:  b3 30 60 11  srl  %g1, 0x11, %i1
a00ab760:  a0 0a a0 ff  and  %o2, 0xff, %l0
a00ab764:  80 a6 60 ff  cmp  %i1, 0xff
a00ab768:  a2 10 00 0d  mov  %o5, %l1
a00ab76c:  b4 0e 20 ff  and  %i0, 0xff, %i2
a00ab770:  08 80 00 12  bleu  0xa00ab7b8
a00ab774:  95 2a a0 10  sll  %o2, 0x10, %o2
a00ab778:  90 10 00 1a  mov  %i2, %o0
a00ab77c:  92 10 20 26  mov  0x26, %o1
a00ab780:  7f ff ed 20  call  0xa00a6c00
a00ab784:  94 10 20 80  mov  0x80, %o2
a00ab788:  90 10 00 1a  mov  %i2, %o0
a00ab78c:  92 10 20 27  mov  0x27, %o1
a00ab790:  7f ff ed 1c  call  0xa00a6c00
a00ab794:  94 10 20 ff  mov  0xff, %o2
a00ab798:  90 10 00 1a  mov  %i2, %o0
a00ab79c:  92 10 20 28  mov  0x28, %o1
a00ab7a0:  7f ff ed 18  call  0xa00a6c00
a00ab7a4:  94 10 20 ff  mov  0xff, %o2
a00ab7a8:  90 10 00 1a  mov  %i2, %o0
a00ab7ac:  92 10 20 29  mov  0x29, %o1
a00ab7b0:  10 80 00 16  b  0xa00ab808
a00ab7b4:  94 10 20 f0  mov  0xf0, %o2
a00ab7b8:  95 32 a0 11  srl  %o2, 0x11, %o2
a00ab7bc:  94 0a a0 ff  and  %o2, 0xff, %o2
a00ab7c0:  90 10 00 1a  mov  %i2, %o0
a00ab7c4:  7f ff ed 0f  call  0xa00a6c00
a00ab7c8:  92 10 20 26  mov  0x26, %o1
a00ab7cc:  90 10 00 1a  mov  %i2, %o0
a00ab7d0:  94 10 00 10  mov  %l0, %o2
a00ab7d4:  7f ff ed 0b  call  0xa00a6c00
a00ab7d8:  92 10 20 27  mov  0x27, %o1
a00ab7dc:  94 0e 60 ff  and  %i1, 0xff, %o2
a00ab7e0:  90 10 00 1a  mov  %i2, %o0
a00ab7e4:  7f ff ed 07  call  0xa00a6c00
a00ab7e8:  92 10 20 28  mov  0x28, %o1
a00ab7ec:  92 10 20 28  mov  0x28, %o1
a00ab7f0:  7f ff ec f2  call  0xa00a6bb8
a00ab7f4:  90 10 00 1a  mov  %i2, %o0
a00ab7f8:  94 24 40 08  sub  %l1, %o0, %o2
a00ab7fc:  90 10 00 1a  mov  %i2, %o0
a00ab800:  94 0a a0 ff  and  %o2, 0xff, %o2
a00ab804:  92 10 20 29  mov  0x29, %o1
a00ab808:  7f ff ec fe  call  0xa00a6c00
a00ab80c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00ab810:  90 10 00 18  mov  %i0, %o0
a00ab814:  92 10 20 2a  mov  0x2a, %o1
a00ab818:  7f ff ec fa  call  0xa00a6c00
a00ab81c:  94 10 20 36  mov  0x36, %o2
a00ab820:  90 10 00 18  mov  %i0, %o0
a00ab824:  92 10 20 2e  mov  0x2e, %o1
a00ab828:  94 10 20 31  mov  0x31, %o2
a00ab82c:  7f ff ed 1b  call  0xa00a6c98
a00ab830:  96 10 20 01  mov  1, %o3
a00ab834:  1b 2a 01 f7  sethi  %hi(0xa807dc00), %o5
a00ab838:  82 5e 21 2c  smul  %i0, 0x12c, %g1
a00ab83c:  9a 13 60 18  or  %o5, 0x18, %o5
a00ab840:  82 00 40 0d  add  %g1, %o5, %g1
a00ab844:  c2 08 61 1f  ldub  [ %g1 + 0x11f ], %g1
a00ab848:  90 10 00 18  mov  %i0, %o0
a00ab84c:  92 10 20 2b  mov  0x2b, %o1
a00ab850:  80 a0 60 01  cmp  %g1, 1
a00ab854:  02 80 00 05  be  0xa00ab868
a00ab858:  94 10 20 cc  mov  0xcc, %o2
a00ab85c:  90 10 00 18  mov  %i0, %o0
a00ab860:  92 10 20 2b  mov  0x2b, %o1
a00ab864:  94 10 20 d9  mov  0xd9, %o2
a00ab868:  7f ff ec e6  call  0xa00a6c00
a00ab86c:  b2 10 20 2c  mov  0x2c, %i1
a00ab870:  7f ff ec e4  call  0xa00a6c00
a00ab874:  95 e8 20 0f  restore  %g0, 0xf, %o2
a00ab878:  01 00 00 00  nop
a00ab87c:  81 c7 e0 08  ret
a00ab880:  81 e8 00 00  restore
