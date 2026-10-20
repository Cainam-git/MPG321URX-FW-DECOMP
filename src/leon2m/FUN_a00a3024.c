/* leon2m FUN_a00a3024 @ 0xa00a3024-0xa00a3198 (93 words).
 * Returns entry n of one of fifteen byte tables, chosen by the code c: a switch over 0xf0..0xfe (jump table at
 * 0x42eb0) calls the matching six-word table-lookup routine (FUN_a00a2c1c ... FUN_a00a2e5c, FUN_a00a2874,
 * FUN_a00a28a4) with n; every other code uses FUN_a00a2c1c, like code 0xf0. Called twice from FUN_a00a31a4.
 * The source order of the case labels decides the register names chosen by register renaming in each case
 * block; the order below reproduces the firmware's names (the code layout is the same for this order and for
 * ascending order).
 */
extern unsigned char FUN_a00a2c1c(unsigned short n);
extern unsigned char FUN_a00a2cdc(unsigned short n);
extern unsigned char FUN_a00a2d3c(unsigned short n);
extern unsigned char FUN_a00a2d6c(unsigned short n);
extern unsigned char FUN_a00a2dcc(unsigned short n);
extern unsigned char FUN_a00a2e2c(unsigned short n);
extern unsigned char FUN_a00a2c7c(unsigned short n);
extern unsigned char FUN_a00a2e5c(unsigned short n);
extern unsigned char FUN_a00a2c4c(unsigned short n);
extern unsigned char FUN_a00a28a4(unsigned short n);
extern unsigned char FUN_a00a2874(unsigned short n);
extern unsigned char FUN_a00a2dfc(unsigned short n);
extern unsigned char FUN_a00a2d9c(unsigned short n);
extern unsigned char FUN_a00a2cac(unsigned short n);
extern unsigned char FUN_a00a2d0c(unsigned short n);

unsigned char FUN_a00a3024(unsigned char c, unsigned short n)
{
    switch (c) {
    case 0xf0: return FUN_a00a2c1c(n);
    case 0xf1: return FUN_a00a2cdc(n);
    case 0xf4: return FUN_a00a2dcc(n);
    case 0xf3: return FUN_a00a2d6c(n);
    case 0xf5: return FUN_a00a2e2c(n);
    case 0xf6: return FUN_a00a2c7c(n);
    case 0xf7: return FUN_a00a2e5c(n);
    case 0xf8: return FUN_a00a2c4c(n);
    case 0xf9: return FUN_a00a28a4(n);
    case 0xfa: return FUN_a00a2874(n);
    case 0xf2: return FUN_a00a2d3c(n);
    case 0xfb: return FUN_a00a2dfc(n);
    case 0xfc: return FUN_a00a2d9c(n);
    case 0xfd: return FUN_a00a2cac(n);
    case 0xfe: return FUN_a00a2d0c(n);
    default:   return FUN_a00a2c1c(n);
    }
}
