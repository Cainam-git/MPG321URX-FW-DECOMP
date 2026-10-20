# leon2s FUN_a0062b64 0xa0062b64-0xa0062b94 (48 bytes)
a0062b64:  9d e3 bf 98  save  %sp, -104, %sp
a0062b68:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a0062b6c:  e2 10 62 a4  lduh  [ %g1 + 0x2a4 ], %l1	! 0xa8078aa4
a0062b70:  90 10 00 18  mov  %i0, %o0
a0062b74:  7f ff ff b0  call  0xa0062a34
a0062b78:  21 00 00 04  sethi  %hi(0x1000), %l0
a0062b7c:  a0 24 00 11  sub  %l0, %l1, %l0
a0062b80:  91 32 20 02  srl  %o0, 2, %o0
a0062b84:  a3 2c 60 12  sll  %l1, 0x12, %l1
a0062b88:  a0 5c 00 08  smul  %l0, %o0, %l0
a0062b8c:  81 c7 e0 08  ret
a0062b90:  91 ec 40 10  restore  %l1, %l0, %o0
