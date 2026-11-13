# leon2s FUN_a00aea64 0xa00aea64-0xa00aeadc (120 bytes)
a00aea64:  9d e3 bf 98  save  %sp, -104, %sp
a00aea68:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00aea6c:  7f ff f8 15  call  0xa00acac0
a00aea70:  90 10 00 18  mov  %i0, %o0
a00aea74:  a2 10 00 08  mov  %o0, %l1
a00aea78:  90 10 00 18  mov  %i0, %o0
a00aea7c:  7f ff e0 4f  call  0xa00a6bb8
a00aea80:  92 10 24 81  mov  0x481, %o1
a00aea84:  7f ff 7b 5f  call  0xa008d800
a00aea88:  a0 0a 20 ff  and  %o0, 0xff, %l0
a00aea8c:  a1 34 20 04  srl  %l0, 4, %l0
a00aea90:  a3 2c 60 10  sll  %l1, 0x10, %l1
a00aea94:  a0 0c 20 ff  and  %l0, 0xff, %l0
a00aea98:  a3 34 60 10  srl  %l1, 0x10, %l1
a00aea9c:  90 0a 20 ff  and  %o0, 0xff, %o0
a00aeaa0:  a0 1c 20 04  xor  %l0, 4, %l0
a00aeaa4:  a2 1c 6d 70  xor  %l1, 0xd70, %l1
a00aeaa8:  80 a2 20 83  cmp  %o0, 0x83
a00aeaac:  08 80 00 09  bleu  0xa00aead0
a00aeab0:  b0 10 20 01  mov  1, %i0
a00aeab4:  80 a0 00 10  cmp  %g0, %l0
a00aeab8:  9a 60 3f ff  subx  %g0, -1, %o5
a00aeabc:  80 a0 00 11  cmp  %g0, %l1
a00aeac0:  82 60 3f ff  subx  %g0, -1, %g1
a00aeac4:  80 8b 40 01  btst  %o5, %g1
a00aeac8:  12 80 00 03  bne  0xa00aead4
a00aeacc:  01 00 00 00  nop
a00aead0:  b0 10 20 00  clr  %i0	! 0x0
a00aead4:  81 c7 e0 08  ret
a00aead8:  81 e8 00 00  restore
