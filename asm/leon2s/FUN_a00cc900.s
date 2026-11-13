# leon2s FUN_a00cc900 0xa00cc900-0xa00cc974 (116 bytes)
a00cc900:  9d e3 bf 98  save  %sp, -104, %sp
a00cc904:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00cc908:  92 10 20 01  mov  1, %o1
a00cc90c:  7f ff f4 17  call  0xa00c9968
a00cc910:  90 10 00 18  mov  %i0, %o0
a00cc914:  7f ff f2 95  call  0xa00c9368
a00cc918:  90 10 00 18  mov  %i0, %o0
a00cc91c:  a0 10 00 08  mov  %o0, %l0
a00cc920:  7f ff f3 8c  call  0xa00c9750
a00cc924:  90 10 00 18  mov  %i0, %o0
a00cc928:  a0 0c 20 ff  and  %l0, 0xff, %l0
a00cc92c:  90 0a 20 ff  and  %o0, 0xff, %o0
a00cc930:  80 a4 00 08  cmp  %l0, %o0
a00cc934:  92 10 00 10  mov  %l0, %o1
a00cc938:  02 80 00 04  be  0xa00cc948
a00cc93c:  90 10 00 18  mov  %i0, %o0
a00cc940:  7f ff ff bd  call  0xa00cc834
a00cc944:  01 00 00 00  nop
a00cc948:  98 06 00 18  add  %i0, %i0, %o4
a00cc94c:  98 03 00 18  add  %o4, %i0, %o4
a00cc950:  17 2a 01 e2  sethi  %hi(0xa8078800), %o3
a00cc954:  96 12 e3 b0  or  %o3, 0x3b0, %o3	! 0xa8078bb0
a00cc958:  99 2b 20 03  sll  %o4, 3, %o4
a00cc95c:  c2 02 c0 0c  ld  [ %o3 + %o4 ], %g1
a00cc960:  1b 00 00 c0  sethi  %hi(0x30000), %o5
a00cc964:  82 10 40 0d  or  %g1, %o5, %g1
a00cc968:  c2 22 c0 0c  st  %g1, [ %o3 + %o4 ]
a00cc96c:  81 c7 e0 08  ret
a00cc970:  81 e8 00 00  restore
