# leon2s FUN_a00cf9e8 0xa00cf9e8-0xa00cfab8 (208 bytes)
a00cf9e8:  9d e3 bf 90  save  %sp, -112, %sp
a00cf9ec:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00cf9f0:  c0 2f bf f7  clrb  [ %fp + -9 ]
a00cf9f4:  90 10 00 18  mov  %i0, %o0
a00cf9f8:  92 10 20 90  mov  0x90, %o1
a00cf9fc:  94 10 22 01  mov  0x201, %o2
a00cfa00:  40 3b 1a 67  call  0xa0f9639c
a00cfa04:  96 07 bf f7  add  %fp, -9, %o3
a00cfa08:  c2 0f bf f7  ldub  [ %fp + -9 ], %g1
a00cfa0c:  80 88 60 04  btst  4, %g1
a00cfa10:  02 80 00 27  be  0xa00cfaac
a00cfa14:  a0 10 20 00  clr  %l0
a00cfa18:  92 10 20 80  mov  0x80, %o1
a00cfa1c:  94 10 22 01  mov  0x201, %o2
a00cfa20:  96 10 20 04  mov  4, %o3
a00cfa24:  40 3b 1a 4f  call  0xa0f96360
a00cfa28:  90 10 00 18  mov  %i0, %o0
a00cfa2c:  15 00 01 a0  sethi  %hi(0x68000), %o2
a00cfa30:  90 10 00 18  mov  %i0, %o0
a00cfa34:  94 12 a0 29  or  %o2, 0x29, %o2
a00cfa38:  92 10 20 90  mov  0x90, %o1
a00cfa3c:  40 3b 1a 58  call  0xa0f9639c
a00cfa40:  96 07 bf f6  add  %fp, -10, %o3
a00cfa44:  80 8a 20 ff  btst  0xff, %o0
a00cfa48:  12 80 00 0a  bne  0xa00cfa70
a00cfa4c:  15 00 01 a5  sethi  %hi(0x69400), %o2
a00cfa50:  c2 0f bf f6  ldub  [ %fp + -10 ], %g1
a00cfa54:  80 88 60 04  btst  4, %g1
a00cfa58:  32 80 00 02  bne,a   0xa00cfa60
a00cfa5c:  a0 10 20 01  mov  1, %l0
a00cfa60:  80 88 60 08  btst  8, %g1
a00cfa64:  32 80 00 02  bne,a   0xa00cfa6c
a00cfa68:  a0 10 20 01  mov  1, %l0
a00cfa6c:  15 00 01 a5  sethi  %hi(0x69400), %o2
a00cfa70:  90 10 00 18  mov  %i0, %o0
a00cfa74:  94 12 a0 93  or  %o2, 0x93, %o2
a00cfa78:  92 10 20 90  mov  0x90, %o1
a00cfa7c:  40 3b 1a 48  call  0xa0f9639c
a00cfa80:  96 07 bf f6  add  %fp, -10, %o3
a00cfa84:  80 8a 20 ff  btst  0xff, %o0
a00cfa88:  32 80 00 0a  bne,a   0xa00cfab0
a00cfa8c:  b0 0c 20 01  and  %l0, 1, %i0
a00cfa90:  c2 0f bf f6  ldub  [ %fp + -10 ], %g1
a00cfa94:  80 88 60 08  btst  8, %g1
a00cfa98:  32 80 00 02  bne,a   0xa00cfaa0
a00cfa9c:  a0 10 20 01  mov  1, %l0
a00cfaa0:  80 88 60 10  btst  0x10, %g1
a00cfaa4:  32 80 00 02  bne,a   0xa00cfaac
a00cfaa8:  a0 10 20 01  mov  1, %l0
a00cfaac:  b0 0c 20 01  and  %l0, 1, %i0
a00cfab0:  81 c7 e0 08  ret
a00cfab4:  81 e8 00 00  restore
