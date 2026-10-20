# leon2m FUN_a00dffd8 0xa00dffd8-0xa00e0040 (104 bytes)  [FUN_a00e0038 = unreachable ret/restore tail, merged]
a00dffd8:  9d e3 bf 98  save  %sp, -104, %sp
a00dffdc:  7f ff fe 46  call  0xa00df8f4
a00dffe0:  90 10 00 18  mov  %i0, %o0
a00dffe4:  80 a0 00 18  cmp  %g0, %i0
a00dffe8:  82 60 3f ff  subx  %g0, -1, %g1
a00dffec:  9a 1e 20 02  xor  %i0, 2, %o5
a00dfff0:  80 a0 00 0d  cmp  %g0, %o5
a00dfff4:  a0 10 00 18  mov  %i0, %l0
a00dfff8:  98 60 3f ff  subx  %g0, -1, %o4
a00dfffc:  80 90 40 0c  orcc  %g1, %o4, %g0
a00e0000:  9a 10 00 19  mov  %i1, %o5
a00e0004:  b0 10 00 19  mov  %i1, %i0
a00e0008:  82 10 00 1a  mov  %i2, %g1
a00e000c:  b2 10 00 1a  mov  %i2, %i1
a00e0010:  12 80 00 07  bne  0xa00e002c
a00e0014:  b4 10 20 01  mov  1, %i2
a00e0018:  b0 10 00 0d  mov  %o5, %i0
a00e001c:  b2 10 00 01  mov  %g1, %i1
a00e0020:  80 a4 20 01  cmp  %l0, 1
a00e0024:  12 80 00 04  bne  0xa00e0034
a00e0028:  b4 10 20 02  mov  2, %i2
a00e002c:  7f ff fd 87  call  0xa00df648
a00e0030:  81 e8 00 00  restore
a00e0034:  01 00 00 00  nop
a00e0038:  81 c7 e0 08  ret
a00e003c:  81 e8 00 00  restore
