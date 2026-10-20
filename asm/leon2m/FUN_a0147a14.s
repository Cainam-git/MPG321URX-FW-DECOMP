# leon2m FUN_a0147a14 0xa0147a14-0xa0147a7c (104 bytes)
a0147a14:  90 0a 20 ff  and  %o0, 0xff, %o0
a0147a18:  83 2a 20 0a  sll  %o0, 0xa, %g1
a0147a1c:  9a 20 40 08  sub  %g1, %o0, %o5
a0147a20:  13 14 7a e1  sethi  %hi(0x51eb8400), %o1
a0147a24:  82 12 61 1f  or  %o1, 0x11f, %g1	! 0x51eb851f
a0147a28:  90 03 60 32  add  %o5, 0x32, %o0
a0147a2c:  80 52 00 01  umul  %o0, %g1, %g0
a0147a30:  9b 40 00 00  rd  %y, %o5
a0147a34:  93 2b 60 0b  sll  %o5, 0xb, %o1
a0147a38:  9b 32 60 10  srl  %o1, 0x10, %o5
a0147a3c:  11 00 00 14  sethi  %hi(0x5000), %o0
a0147a40:  82 12 21 b2  or  %o0, 0x1b2, %g1	! 0x51b2
a0147a44:  13 20 08 02  sethi  %hi(0x80200800), %o1
a0147a48:  90 12 60 03  or  %o1, 3, %o0	! 0x80200803
a0147a4c:  9a 5b 40 01  smul  %o5, %g1, %o5
a0147a50:  80 5b 40 08  smul  %o5, %o0, %g0
a0147a54:  83 40 00 00  rd  %y, %g1
a0147a58:  92 00 40 0d  add  %g1, %o5, %o1
a0147a5c:  91 3a 60 09  sra  %o1, 9, %o0
a0147a60:  82 02 20 01  add  %o0, 1, %g1
a0147a64:  93 28 60 10  sll  %g1, 0x10, %o1
a0147a68:  93 32 60 10  srl  %o1, 0x10, %o1
a0147a6c:  90 10 20 00  clr  %o0
a0147a70:  82 13 c0 00  mov  %o7, %g1
a0147a74:  7f ff c3 0e  call  0xa01386ac
a0147a78:  9e 10 40 00  mov  %g1, %o7
