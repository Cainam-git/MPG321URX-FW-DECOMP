# leon2s FUN_a00a2320 0xa00a2320-0xa00a2370 (80 bytes)
a00a2320:  9a 0a 20 ff  and  %o0, 0xff, %o5
a00a2324:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a00a2328:  92 0a 60 ff  and  %o1, 0xff, %o1
a00a232c:  96 5b 60 34  smul  %o5, 0x34, %o3
a00a2330:  98 10 63 00  or  %g1, 0x300, %o4
a00a2334:  80 a2 60 01  cmp  %o1, 1
a00a2338:  90 10 20 15  mov  0x15, %o0
a00a233c:  12 80 00 07  bne  0xa00a2358
a00a2340:  96 02 c0 0c  add  %o3, %o4, %o3
a00a2344:  d2 02 e0 04  ld  [ %o3 + 4 ], %o1
a00a2348:  92 02 60 24  add  %o1, 0x24, %o1
a00a234c:  82 13 c0 00  mov  %o7, %g1
a00a2350:  40 00 14 17  call  0xa00a73ac
a00a2354:  9e 10 40 00  mov  %g1, %o7
a00a2358:  d2 02 e0 04  ld  [ %o3 + 4 ], %o1
a00a235c:  92 02 60 24  add  %o1, 0x24, %o1
a00a2360:  90 10 20 15  mov  0x15, %o0
a00a2364:  82 13 c0 00  mov  %o7, %g1
a00a2368:  40 00 14 1b  call  0xa00a73d4
a00a236c:  9e 10 40 00  mov  %g1, %o7
