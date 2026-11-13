# leon2s FUN_a00aeb6c 0xa00aeb6c-0xa00aec10 (164 bytes)  [FUN_a00aec08 = its unreachable ret/restore tail, merged]
a00aeb6c:  9d e3 bf 98  save  %sp, -104, %sp
a00aeb70:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00aeb74:  7f ff ff da  call  0xa00aeadc
a00aeb78:  90 10 00 18  mov  %i0, %o0
a00aeb7c:  80 8a 20 ff  btst  0xff, %o0
a00aeb80:  12 80 00 07  bne  0xa00aeb9c
a00aeb84:  90 10 00 18  mov  %i0, %o0
a00aeb88:  7f ff ff e7  call  0xa00aeb24
a00aeb8c:  01 00 00 00  nop
a00aeb90:  80 8a 20 ff  btst  0xff, %o0
a00aeb94:  02 80 00 1c  be  0xa00aec04
a00aeb98:  01 00 00 00  nop
a00aeb9c:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00aeba0:  9a 10 20 01  mov  1, %o5
a00aeba4:  82 10 63 10  or  %g1, 0x310, %g1
a00aeba8:  da 28 40 18  stb  %o5, [ %g1 + %i0 ]
a00aebac:  90 10 00 18  mov  %i0, %o0
a00aebb0:  92 10 20 30  mov  0x30, %o1
a00aebb4:  94 10 20 80  mov  0x80, %o2
a00aebb8:  7f ff e0 38  call  0xa00a6c98
a00aebbc:  96 10 20 01  mov  1, %o3
a00aebc0:  90 10 00 18  mov  %i0, %o0
a00aebc4:  92 10 24 63  mov  0x463, %o1
a00aebc8:  94 10 20 01  mov  1, %o2
a00aebcc:  7f ff e0 33  call  0xa00a6c98
a00aebd0:  96 10 20 01  mov  1, %o3
a00aebd4:  90 10 00 18  mov  %i0, %o0
a00aebd8:  92 10 24 63  mov  0x463, %o1
a00aebdc:  94 10 20 02  mov  2, %o2
a00aebe0:  7f ff e0 2e  call  0xa00a6c98
a00aebe4:  96 10 20 01  mov  1, %o3
a00aebe8:  90 10 00 18  mov  %i0, %o0
a00aebec:  92 10 20 30  mov  0x30, %o1
a00aebf0:  94 10 20 80  mov  0x80, %o2
a00aebf4:  7f ff e0 29  call  0xa00a6c98
a00aebf8:  96 10 20 00  clr  %o3
a00aebfc:  7f ff fd 71  call  0xa00ae1c0
a00aec00:  81 e8 00 00  restore
a00aec04:  01 00 00 00  nop
a00aec08:  81 c7 e0 08  ret
a00aec0c:  81 e8 00 00  restore
