# leon2s FUN_a0078fe8 0xa0078fe8-0xa0079054 (108 bytes)
a0078fe8:  9d e3 bf 98  save  %sp, -104, %sp
a0078fec:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0078ff0:  15 00 00 07  sethi  %hi(0x1c00), %o2
a0078ff4:  94 12 a0 04  or  %o2, 4, %o2	! 0x1c04
a0078ff8:  92 10 00 18  mov  %i0, %o1
a0078ffc:  40 00 b9 1b  call  0xa00a7468
a0079000:  90 10 20 1c  mov  0x1c, %o0
a0079004:  80 a2 20 00  cmp  %o0, 0
a0079008:  02 80 00 10  be  0xa0079048
a007900c:  90 10 00 18  mov  %i0, %o0
a0079010:  7f ff ef d4  call  0xa0074f60
a0079014:  01 00 00 00  nop
a0079018:  83 2a 20 10  sll  %o0, 0x10, %g1
a007901c:  83 30 60 10  srl  %g1, 0x10, %g1
a0079020:  80 a0 60 0a  cmp  %g1, 0xa
a0079024:  08 80 00 09  bleu  0xa0079048
a0079028:  90 10 00 18  mov  %i0, %o0
a007902c:  7f ff ef cd  call  0xa0074f60
a0079030:  b0 10 20 01  mov  1, %i0
a0079034:  91 2a 20 10  sll  %o0, 0x10, %o0
a0079038:  91 32 20 10  srl  %o0, 0x10, %o0
a007903c:  80 a2 22 57  cmp  %o0, 0x257
a0079040:  08 80 00 03  bleu  0xa007904c
a0079044:  01 00 00 00  nop
a0079048:  b0 10 20 00  clr  %i0	! 0x0
a007904c:  81 c7 e0 08  ret
a0079050:  81 e8 00 00  restore
