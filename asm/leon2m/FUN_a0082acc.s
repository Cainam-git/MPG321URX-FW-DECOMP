# leon2m FUN_a0082acc 0xa0082acc-0xa0082b00 (52 bytes)
a0082acc:  9d e3 bf 98  save  %sp, -104, %sp
a0082ad0:  40 00 32 21  call  0xa008f354
a0082ad4:  01 00 00 00  nop
a0082ad8:  90 10 20 ff  mov  0xff, %o0	! 0xff
a0082adc:  40 00 30 e4  call  0xa008ee6c
a0082ae0:  92 10 20 00  clr  %o1
a0082ae4:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a0082ae8:  d0 0b 63 41  ldub  [ %o5 + 0x341 ], %o0	! 0xa802af41
a0082aec:  82 0a 3f fe  and  %o0, -2, %g1
a0082af0:  c2 2b 63 41  stb  %g1, [ %o5 + 0x341 ]
a0082af4:  40 03 04 ad  call  0xa0143da8
a0082af8:  81 e8 00 00  restore
a0082afc:  01 00 00 00  nop
