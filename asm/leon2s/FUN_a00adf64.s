# leon2s FUN_a00adf64 0xa00adf64-0xa00adf84 (32 bytes)
a00adf64:  90 0a 20 ff  and  %o0, 0xff, %o0
a00adf68:  91 2a 20 02  sll  %o0, 2, %o0
a00adf6c:  92 02 40 08  add  %o1, %o0, %o1
a00adf70:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00adf74:  d0 08 62 70  ldub  [ %g1 + 0x270 ], %o0	! 0xa807de70
a00adf78:  91 3a 00 09  sra  %o0, %o1, %o0
a00adf7c:  81 c3 e0 08  retl
a00adf80:  90 0a 20 01  and  %o0, 1, %o0
