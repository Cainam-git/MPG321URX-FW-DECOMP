# leon2m FUN_a0097814 0xa0097814-0xa00978c8 (180 bytes)  [FUN_a00978c0 = unreachable ret/restore tail, merged]
a0097814:  9d e3 bf 98  save  %sp, -104, %sp
a0097818:  23 2a 00 97  sethi  %hi(0xa8025c00), %l1
a009781c:  40 00 45 b3  call  0xa00a8ee8
a0097820:  d0 0c 60 56  ldub  [ %l1 + 0x56 ], %o0	! 0xa8025c56
a0097824:  94 10 20 00  clr  %o2
a0097828:  90 10 20 00  clr  %o0
a009782c:  40 00 42 44  call  0xa00a813c
a0097830:  d2 0c 60 56  ldub  [ %l1 + 0x56 ], %o1
a0097834:  25 2a 00 ab  sethi  %hi(0xa802ac00), %l2
a0097838:  d6 04 a3 ec  ld  [ %l2 + 0x3ec ], %o3	! 0xa802afec
a009783c:  94 02 ff dd  add  %o3, -35, %o2
a0097840:  90 0a a0 ff  and  %o2, 0xff, %o0
a0097844:  40 00 45 f2  call  0xa00a900c
a0097848:  92 10 20 00  clr  %o1
a009784c:  7f ff ff 2f  call  0xa0097508
a0097850:  01 00 00 00  nop
a0097854:  7f ff ff a9  call  0xa00976f8
a0097858:  01 00 00 00  nop
a009785c:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a0097860:  a0 12 62 90  or  %o1, 0x290, %l0	! 0xa802d290
a0097864:  94 10 20 01  mov  1, %o2
a0097868:  90 10 20 00  clr  %o0
a009786c:  40 00 42 34  call  0xa00a813c
a0097870:  d2 0c 20 1f  ldub  [ %l0 + 0x1f ], %o1
a0097874:  90 10 20 07  mov  7, %o0
a0097878:  d0 24 a3 ec  st  %o0, [ %l2 + 0x3ec ]
a009787c:  90 10 20 05  mov  5, %o0
a0097880:  40 00 72 31  call  0xa00b4144
a0097884:  92 10 20 01  mov  1, %o1
a0097888:  90 10 20 01  mov  1, %o0
a009788c:  40 00 46 f7  call  0xa00a9468
a0097890:  92 10 20 02  mov  2, %o1
a0097894:  90 10 20 00  clr  %o0
a0097898:  40 00 6f 0f  call  0xa00b34d4
a009789c:  92 10 20 01  mov  1, %o1
a00978a0:  da 0c 20 1f  ldub  [ %l0 + 0x1f ], %o5
a00978a4:  c2 0c 60 56  ldub  [ %l1 + 0x56 ], %g1
a00978a8:  80 a3 40 01  cmp  %o5, %g1
a00978ac:  02 80 00 04  be  0xa00978bc
a00978b0:  01 00 00 00  nop
a00978b4:  40 00 55 90  call  0xa00acef4
a00978b8:  81 e8 00 00  restore
a00978bc:  01 00 00 00  nop
a00978c0:  81 c7 e0 08  ret
a00978c4:  81 e8 00 00  restore
