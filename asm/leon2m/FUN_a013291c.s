# leon2m FUN_a013291c 0xa013291c-0xa0132964 (72 bytes)
a013291c:  9d e3 bf 98  save  %sp, -104, %sp
a0132920:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0132924:  91 2e 20 04  sll  %i0, 4, %o0
a0132928:  82 22 00 18  sub  %o0, %i0, %g1
a013292c:  9b 28 60 03  sll  %g1, 3, %o5
a0132930:  80 a6 20 03  cmp  %i0, 3
a0132934:  18 80 00 07  bgu  0xa0132950
a0132938:  90 10 3f ff  mov  -1, %o0
a013293c:  17 2a 00 b7  sethi  %hi(0xa802dc00), %o3
a0132940:  94 12 e3 30  or  %o3, 0x330, %o2	! 0xa802df30
a0132944:  d2 02 80 0d  ld  [ %o2 + %o5 ], %o1
a0132948:  9b 32 60 0c  srl  %o1, 0xc, %o5
a013294c:  90 0b 60 0f  and  %o5, 0xf, %o0
a0132950:  40 00 41 a5  call  0xa0142fe4
a0132954:  90 0a 20 ff  and  %o0, 0xff, %o0
a0132958:  b0 0a 20 ff  and  %o0, 0xff, %i0
a013295c:  81 c7 e0 08  ret
a0132960:  81 e8 00 00  restore
