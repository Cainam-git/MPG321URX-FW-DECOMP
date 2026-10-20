# leon2m FUN_a00ad86c 0xa00ad86c-0xa00ad970 (260 bytes)  [FUN_a00ad968 = unreachable ret/restore tail, merged]
a00ad86c:  9d e3 bf 80  save  %sp, -128, %sp
a00ad870:  82 0e 20 03  and  %i0, 3, %g1
a00ad874:  b0 00 40 01  add  %g1, %g1, %i0
a00ad878:  a0 0e 60 ff  and  %i1, 0xff, %l0
a00ad87c:  b0 06 20 04  add  %i0, 4, %i0
a00ad880:  92 10 20 00  clr  %o1
a00ad884:  94 10 20 00  clr  %o2
a00ad888:  b4 0e 20 ff  and  %i0, 0xff, %i2
a00ad88c:  80 a4 20 00  cmp  %l0, 0
a00ad890:  90 10 20 03  mov  3, %o0
a00ad894:  12 80 00 04  bne  0xa00ad8a4
a00ad898:  b2 10 20 04  mov  4, %i1
a00ad89c:  90 10 20 04  mov  4, %o0
a00ad8a0:  b2 10 20 0c  mov  0xc, %i1
a00ad8a4:  b6 0a 20 ff  and  %o0, 0xff, %i3
a00ad8a8:  40 02 64 e6  call  0xa0146c40
a00ad8ac:  90 10 00 1b  mov  %i3, %o0
a00ad8b0:  9a 0e 60 0c  and  %i1, 0xc, %o5
a00ad8b4:  90 10 00 1b  mov  %i3, %o0
a00ad8b8:  92 10 20 00  clr  %o1
a00ad8bc:  94 10 20 00  clr  %o2
a00ad8c0:  96 10 20 00  clr  %o3
a00ad8c4:  98 10 20 00  clr  %o4
a00ad8c8:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00ad8cc:  c0 23 a0 60  clr  [ %sp + 0x60 ]
a00ad8d0:  c0 23 a0 64  clr  [ %sp + 0x64 ]
a00ad8d4:  c0 23 a0 68  clr  [ %sp + 0x68 ]
a00ad8d8:  40 02 63 69  call  0xa014667c
a00ad8dc:  c0 23 a0 6c  clr  [ %sp + 0x6c ]
a00ad8e0:  93 2e a0 03  sll  %i2, 3, %o1
a00ad8e4:  90 02 40 1a  add  %o1, %i2, %o0
a00ad8e8:  95 2a 20 02  sll  %o0, 2, %o2
a00ad8ec:  98 02 a0 51  add  %o2, 0x51, %o4
a00ad8f0:  90 10 00 1b  mov  %i3, %o0
a00ad8f4:  92 10 20 48  mov  0x48, %o1
a00ad8f8:  94 02 a0 1a  add  %o2, 0x1a, %o2
a00ad8fc:  96 10 21 c7  mov  0x1c7, %o3
a00ad900:  80 a4 20 00  cmp  %l0, 0
a00ad904:  12 80 00 0c  bne  0xa00ad934
a00ad908:  9a 10 20 00  clr  %o5
a00ad90c:  b4 0e 20 ff  and  %i0, 0xff, %i2
a00ad910:  99 2e a0 03  sll  %i2, 3, %o4
a00ad914:  96 03 00 1a  add  %o4, %i2, %o3
a00ad918:  9f 2a e0 02  sll  %o3, 2, %o7
a00ad91c:  98 03 e0 55  add  %o7, 0x55, %o4
a00ad920:  96 10 21 c7  mov  0x1c7, %o3
a00ad924:  9a 10 20 00  clr  %o5
a00ad928:  90 10 00 1b  mov  %i3, %o0
a00ad92c:  92 10 20 48  mov  0x48, %o1
a00ad930:  94 03 e0 16  add  %o7, 0x16, %o2
a00ad934:  40 02 63 cf  call  0xa0146870
a00ad938:  b0 10 20 02  mov  2, %i0
a00ad93c:  90 10 00 1b  mov  %i3, %o0
a00ad940:  92 10 20 01  mov  1, %o1
a00ad944:  40 02 64 bf  call  0xa0146c40
a00ad948:  94 10 20 00  clr  %o2
a00ad94c:  b6 10 00 10  mov  %l0, %i3
a00ad950:  80 a4 20 00  cmp  %l0, 0
a00ad954:  02 80 00 04  be  0xa00ad964
a00ad958:  b2 10 20 03  mov  3, %i1
a00ad95c:  7f ff ff 12  call  0xa00ad5a4
a00ad960:  81 e8 00 00  restore
a00ad964:  01 00 00 00  nop
a00ad968:  81 c7 e0 08  ret
a00ad96c:  81 e8 00 00  restore
