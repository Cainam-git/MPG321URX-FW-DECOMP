# leon2m FUN_a0081e0c 0xa0081e0c-0xa0081ea8 (156 bytes)  [FUN_a0081ea0 = unreachable ret/restore tail, merged]
a0081e0c:  9d e3 bf 98  save  %sp, -104, %sp
a0081e10:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a0081e14:  d0 02 e2 90  ld  [ %o3 + 0x290 ], %o0	! 0xa802d290
a0081e18:  1b 00 00 14  sethi  %hi(0x5000), %o5
a0081e1c:  82 0a 00 0d  and  %o0, %o5, %g1
a0081e20:  19 00 00 04  sethi  %hi(0x1000), %o4
a0081e24:  80 a0 40 0c  cmp  %g1, %o4
a0081e28:  12 80 00 1d  bne  0xa0081e9c
a0081e2c:  96 12 e2 90  or  %o3, 0x290, %o3
a0081e30:  de 12 e1 f6  lduh  [ %o3 + 0x1f6 ], %o7
a0081e34:  13 00 03 fb  sethi  %hi(0xfec00), %o1
a0081e38:  17 00 00 15  sethi  %hi(0x5400), %o3
a0081e3c:  90 12 61 c8  or  %o1, 0x1c8, %o0
a0081e40:  94 12 e1 aa  or  %o3, 0x1aa, %o2
a0081e44:  92 10 20 01  mov  1, %o1
a0081e48:  b0 10 20 03  mov  3, %i0
a0081e4c:  80 a3 c0 0a  cmp  %o7, %o2
a0081e50:  02 80 00 13  be  0xa0081e9c
a0081e54:  b2 10 2b b8  mov  0xbb8, %i1
a0081e58:  40 01 74 c6  call  0xa00df170
a0081e5c:  01 00 00 00  nop
a0081e60:  40 00 34 3a  call  0xa008ef48
a0081e64:  01 00 00 00  nop
a0081e68:  90 10 20 ff  mov  0xff, %o0	! 0xff
a0081e6c:  40 00 34 00  call  0xa008ee6c
a0081e70:  92 10 20 01  mov  1, %o1
a0081e74:  90 10 20 40  mov  0x40, %o0
a0081e78:  40 00 33 fd  call  0xa008ee6c
a0081e7c:  92 10 20 00  clr  %o1
a0081e80:  19 2a 00 ab  sethi  %hi(0xa802ac00), %o4
a0081e84:  d0 0b 23 41  ldub  [ %o4 + 0x341 ], %o0	! 0xa802af41
a0081e88:  82 12 20 01  or  %o0, 1, %g1
a0081e8c:  40 03 07 c3  call  0xa0143d98
a0081e90:  c2 2b 23 41  stb  %g1, [ %o4 + 0x341 ]
a0081e94:  40 00 12 c7  call  0xa00869b0
a0081e98:  81 e8 00 00  restore
a0081e9c:  01 00 00 00  nop
a0081ea0:  81 c7 e0 08  ret
a0081ea4:  81 e8 00 00  restore
