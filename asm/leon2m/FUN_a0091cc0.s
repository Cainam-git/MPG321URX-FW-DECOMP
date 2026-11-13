# leon2m FUN_a0091cc0 0xa0091cc0-0xa0091d74 (180 bytes)  [FUN_a0091d6c = unreachable ret/restore tail, merged]
a0091cc0:  9d e3 bf 98  save  %sp, -104, %sp
a0091cc4:  33 2a 00 ab  sethi  %hi(0xa802ac00), %i1
a0091cc8:  d2 06 63 ec  ld  [ %i1 + 0x3ec ], %o1	! 0xa802afec
a0091ccc:  90 02 7f fe  add  %o1, -2, %o0
a0091cd0:  90 0a 20 ff  and  %o0, 0xff, %o0
a0091cd4:  40 00 89 1c  call  0xa00b4144
a0091cd8:  92 10 20 02  mov  2, %o1
a0091cdc:  82 10 20 15  mov  0x15, %g1
a0091ce0:  1b 15 55 55  sethi  %hi(0x55555400), %o5
a0091ce4:  c2 26 63 ec  st  %g1, [ %i1 + 0x3ec ]
a0091ce8:  b0 13 61 56  or  %o5, 0x156, %i0
a0091cec:  10 80 00 0c  b  0xa0091d1c
a0091cf0:  a0 10 00 19  mov  %i1, %l0
a0091cf4:  90 03 ff ec  add  %o7, -20, %o0
a0091cf8:  80 5a 00 18  smul  %o0, %i0, %g0
a0091cfc:  99 40 00 00  rd  %y, %o4
a0091d00:  97 3a 20 1f  sra  %o0, 0x1f, %o3
a0091d04:  94 23 00 0b  sub  %o4, %o3, %o2
a0091d08:  92 02 80 0a  add  %o2, %o2, %o1
a0091d0c:  82 02 40 0a  add  %o1, %o2, %g1
a0091d10:  9a 22 00 01  sub  %o0, %g1, %o5
a0091d14:  9e 03 60 15  add  %o5, 0x15, %o7
a0091d18:  de 26 63 ec  st  %o7, [ %i1 + 0x3ec ]
a0091d1c:  d8 06 63 ec  ld  [ %i1 + 0x3ec ], %o4
a0091d20:  96 03 3f eb  add  %o4, -21, %o3
a0091d24:  40 00 61 ff  call  0xa00aa520
a0091d28:  90 0a e0 ff  and  %o3, 0xff, %o0
a0091d2c:  94 0a 20 ff  and  %o0, 0xff, %o2
a0091d30:  80 a2 a0 01  cmp  %o2, 1
a0091d34:  12 bf ff f0  bne  0xa0091cf4
a0091d38:  de 16 63 ee  lduh  [ %i1 + 0x3ee ], %o7
a0091d3c:  da 04 23 ec  ld  [ %l0 + 0x3ec ], %o5
a0091d40:  b2 03 7f eb  add  %o5, -21, %i1
a0091d44:  90 0e 60 ff  and  %i1, 0xff, %o0
a0091d48:  40 00 5c b1  call  0xa00a900c
a0091d4c:  92 10 20 01  mov  1, %o1
a0091d50:  f0 04 23 ec  ld  [ %l0 + 0x3ec ], %i0
a0091d54:  80 a6 20 16  cmp  %i0, 0x16
a0091d58:  12 80 00 04  bne  0xa0091d68
a0091d5c:  b0 10 20 01  mov  1, %i0
a0091d60:  40 00 61 3e  call  0xa00aa258
a0091d64:  93 e8 20 00  restore  %g0, 0, %o1
a0091d68:  01 00 00 00  nop
a0091d6c:  81 c7 e0 08  ret
a0091d70:  81 e8 00 00  restore
