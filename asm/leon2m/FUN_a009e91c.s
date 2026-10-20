# leon2m FUN_a009e91c 0xa009e91c-0xa009e9a8 (140 bytes)  [FUN_a009e9a0 = unreachable ret/restore tail, merged]
a009e91c:  9d e3 bf 98  save  %sp, -104, %sp
a009e920:  40 02 94 bd  call  0xa0143c14
a009e924:  90 10 20 00  clr  %o0
a009e928:  90 0a 20 ff  and  %o0, 0xff, %o0
a009e92c:  80 a2 20 0a  cmp  %o0, 0xa
a009e930:  02 80 00 06  be  0xa009e948
a009e934:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a009e938:  da 00 62 90  ld  [ %g1 + 0x290 ], %o5	! 0xa802d290
a009e93c:  80 8b 62 00  btst  0x200, %o5
a009e940:  02 80 00 09  be  0xa009e964
a009e944:  15 2a 00 ab  sethi  %hi(0xa802ac00), %o2
a009e948:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a009e94c:  d6 03 21 a0  ld  [ %o4 + 0x1a0 ], %o3	! 0xa802e1a0
a009e950:  80 a2 e0 00  cmp  %o3, 0
a009e954:  16 80 00 12  bge  0xa009e99c
a009e958:  9a 10 21 0d  mov  0x10d, %o5
a009e95c:  10 80 00 0b  b  0xa009e988
a009e960:  11 2a 00 ab  sethi  %hi(0xa802ac00), %o0
a009e964:  d2 02 a3 ec  ld  [ %o2 + 0x3ec ], %o1
a009e968:  80 a2 60 fe  cmp  %o1, 0xfe
a009e96c:  02 80 00 0c  be  0xa009e99c
a009e970:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a009e974:  d6 03 21 a0  ld  [ %o4 + 0x1a0 ], %o3	! 0xa802e1a0
a009e978:  80 a2 e0 00  cmp  %o3, 0
a009e97c:  16 80 00 08  bge  0xa009e99c
a009e980:  9a 10 21 0d  mov  0x10d, %o5
a009e984:  11 2a 00 ab  sethi  %hi(0xa802ac00), %o0
a009e988:  1f 2a 00 b3  sethi  %hi(0xa802cc00), %o7
a009e98c:  da 22 23 ec  st  %o5, [ %o0 + 0x3ec ]
a009e990:  c0 2b e3 f5  clrb  [ %o7 + 0x3f5 ]
a009e994:  40 00 67 3a  call  0xa00b867c
a009e998:  81 e8 00 00  restore
a009e99c:  01 00 00 00  nop
a009e9a0:  81 c7 e0 08  ret
a009e9a4:  81 e8 00 00  restore
