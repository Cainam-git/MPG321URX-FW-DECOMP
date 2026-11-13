# leon2s FUN_a008ff08 0xa008ff08-0xa008ff58 (80 bytes)
a008ff08:  9d e3 bf 98  save  %sp, -104, %sp
a008ff0c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a008ff10:  92 10 21 46  mov  0x146, %o1
a008ff14:  40 00 59 9a  call  0xa00a657c
a008ff18:  90 10 00 18  mov  %i0, %o0
a008ff1c:  82 0a 20 70  and  %o0, 0x70, %g1
a008ff20:  90 10 00 18  mov  %i0, %o0
a008ff24:  92 10 21 46  mov  0x146, %o1
a008ff28:  80 a0 60 50  cmp  %g1, 0x50
a008ff2c:  02 80 00 09  be  0xa008ff50
a008ff30:  b0 10 20 01  mov  1, %i0
a008ff34:  40 00 59 92  call  0xa00a657c
a008ff38:  01 00 00 00  nop
a008ff3c:  90 0a 20 70  and  %o0, 0x70, %o0
a008ff40:  90 1a 20 60  xor  %o0, 0x60, %o0
a008ff44:  80 a0 00 08  cmp  %g0, %o0
a008ff48:  82 60 3f ff  subx  %g0, -1, %g1
a008ff4c:  b0 00 40 01  add  %g1, %g1, %i0
a008ff50:  81 c7 e0 08  ret
a008ff54:  81 e8 00 00  restore
