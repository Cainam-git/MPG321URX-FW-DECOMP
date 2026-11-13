# leon2m FUN_a010ae8c 0xa010ae8c-0xa010af18 (140 bytes)
a010ae8c:  9d e3 bf 90  save  %sp, -112, %sp
a010ae90:  95 2e 20 04  sll  %i0, 4, %o2
a010ae94:  b0 12 a0 04  or  %o2, 4, %i0
a010ae98:  b5 2e a0 10  sll  %i2, 0x10, %i2
a010ae9c:  93 2e 60 10  sll  %i1, 0x10, %o1
a010aea0:  b3 32 60 10  srl  %o1, 0x10, %i1
a010aea4:  a1 36 a0 10  srl  %i2, 0x10, %l0
a010aea8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a010aeac:  90 10 00 18  mov  %i0, %o0
a010aeb0:  92 10 00 19  mov  %i1, %o1
a010aeb4:  94 10 00 10  mov  %l0, %o2
a010aeb8:  7f ff 9f f8  call  0xa00f2e98
a010aebc:  96 10 00 1b  mov  %i3, %o3
a010aec0:  11 33 c0 3a  sethi  %hi(0xcf00e800), %o0
a010aec4:  82 12 22 c0  or  %o0, 0x2c0, %g1	! 0xcf00eac0
a010aec8:  b5 36 a0 11  srl  %i2, 0x11, %i2
a010aecc:  da 00 40 00  ld  [ %g1 ], %o5
a010aed0:  80 8b 60 80  btst  0x80, %o5
a010aed4:  02 80 00 0e  be  0xa010af0c
a010aed8:  b2 06 40 1a  add  %i1, %i2, %i1
a010aedc:  b4 04 00 1b  add  %l0, %i3, %i2
a010aee0:  90 10 00 18  mov  %i0, %o0
a010aee4:  92 10 21 00  mov  0x100, %o1
a010aee8:  94 10 20 02  mov  2, %o2
a010aeec:  80 a6 61 00  cmp  %i1, 0x100
a010aef0:  12 80 00 07  bne  0xa010af0c
a010aef4:  96 07 bf f0  add  %fp, -16, %o3
a010aef8:  d8 0e bf ff  ldub  [ %i2 + -1 ], %o4
a010aefc:  de 0e bf fe  ldub  [ %i2 + -2 ], %o7
a010af00:  de 2f bf f0  stb  %o7, [ %fp + -16 ]
a010af04:  7f ff 9f e5  call  0xa00f2e98
a010af08:  d8 2f bf f1  stb  %o4, [ %fp + -15 ]
a010af0c:  01 00 00 00  nop
a010af10:  81 c7 e0 08  ret
a010af14:  81 e8 00 00  restore
