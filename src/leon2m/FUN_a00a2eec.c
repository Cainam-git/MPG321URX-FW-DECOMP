/* leon2m FUN_a00a2eec @ 0xa00a2eec-0xa00a3024 (78 words), flags -mcpu=v8 -O3 -g. Called from FUN_a00a31a4.
 * Selects a table-lookup routine by the byte sel and returns its result for the index n (passed as 16 bits):
 * sel 0xf1..0xfe call FUN_a00a2cc4, FUN_a00a2d24, FUN_a00a2d54, FUN_a00a2db4, FUN_a00a2e14, FUN_a00a2c64,
 * FUN_a00a2e44, FUN_a00a2c34, FUN_a00a288c, FUN_a00a285c, FUN_a00a2de4, FUN_a00a2d84, FUN_a00a2c94, FUN_a00a2cf4;
 * sel 0xf0 and every other value call FUN_a00a2c04. A switch with a jump table (0x42e74, 15 entries).
 * The case order in the source decides the registers of the inlined argument truncations (the register-renaming
 * pass visits the case blocks in source order); the block layout is the same for every order.
 */
extern unsigned int FUN_a00a2c04(unsigned short n);
extern unsigned int FUN_a00a2cf4(unsigned short n);
extern unsigned int FUN_a00a2c94(unsigned short n);
extern unsigned int FUN_a00a2d84(unsigned short n);
extern unsigned int FUN_a00a2de4(unsigned short n);
extern unsigned int FUN_a00a285c(unsigned short n);
extern unsigned int FUN_a00a288c(unsigned short n);
extern unsigned int FUN_a00a2c34(unsigned short n);
extern unsigned int FUN_a00a2e44(unsigned short n);
extern unsigned int FUN_a00a2c64(unsigned short n);
extern unsigned int FUN_a00a2e14(unsigned short n);
extern unsigned int FUN_a00a2db4(unsigned short n);
extern unsigned int FUN_a00a2d54(unsigned short n);
extern unsigned int FUN_a00a2d24(unsigned short n);
extern unsigned int FUN_a00a2cc4(unsigned short n);

unsigned int FUN_a00a2eec(unsigned char sel, unsigned short n)
{
    unsigned int r;

    switch (sel) {
    case 0xf0: r = FUN_a00a2c04(n); break;
    case 0xf1: r = FUN_a00a2cc4(n); break;
    case 0xf4: r = FUN_a00a2db4(n); break;
    case 0xf3: r = FUN_a00a2d54(n); break;
    case 0xf5: r = FUN_a00a2e14(n); break;
    case 0xf6: r = FUN_a00a2c64(n); break;
    case 0xf7: r = FUN_a00a2e44(n); break;
    case 0xf8: r = FUN_a00a2c34(n); break;
    case 0xf9: r = FUN_a00a288c(n); break;
    case 0xfa: r = FUN_a00a285c(n); break;
    case 0xf2: r = FUN_a00a2d24(n); break;
    case 0xfb: r = FUN_a00a2de4(n); break;
    case 0xfc: r = FUN_a00a2d84(n); break;
    case 0xfd: r = FUN_a00a2c94(n); break;
    case 0xfe: r = FUN_a00a2cf4(n); break;
    default: r = FUN_a00a2c04(n); break;
    }
    return r;
}
