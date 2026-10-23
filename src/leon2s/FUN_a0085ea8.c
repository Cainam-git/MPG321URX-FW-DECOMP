/* FUN_a0085ea8 (leon2s 0xa0085ea8-0xa0086030, 392 bytes), flags -mcpu=v8 -Os -g.
 * Clears bits 6 and 7 of hardware register 0xcf0116bc (two writes), calls FUN_a00aa5e8(1, 0x1e, 0, 0) and
 * FUN_a00aa5e8(0, 0x1e, 0, 0), then FUN_a00aa88c(i, 0) for i = 0..4. For port 0 (unless FUN_a00aa7bc() is
 * non-zero) and for ports 1..4 (unless FUN_a00aa7c4(i) is non-zero) it calls FUN_a00aa3a4(i),
 * FUN_a00aa45c(i, bit 12 of word +0x20 of the 40-byte record ARR_a807a928[i]), FUN_a00aa49c(i, bits 13..14 of
 * that word), FUN_a0085b80(i), FUN_a0085dcc(i) and FUN_a0085b14(i). Finally clears bits 3 and 4 of 0xcf00f21c.
 * volatile only on the hardware registers.
 * Source form: port 0 written out before a loop over ports 1..4 (both for the FUN_a00aa88c calls and the
 * per-port sequence).
 */
struct R28 { unsigned char pad[0x20]; unsigned int w20; unsigned char rest[4]; };
extern struct R28 ARR_a807a928[];
#define R(a) (*(volatile unsigned int *)(a))
extern void FUN_a00aa5e8(unsigned int, unsigned int, unsigned int, unsigned int);
extern void FUN_a00aa88c(unsigned int, unsigned int);
extern unsigned char FUN_a00aa7bc(void);
extern unsigned char FUN_a00aa7c4(unsigned char);
extern void FUN_a00aa3a4(unsigned char);
extern void FUN_a00aa45c(unsigned char, unsigned char);
extern void FUN_a00aa49c(unsigned char, unsigned char);
extern void FUN_a0085b80(unsigned char);
extern void FUN_a0085dcc(unsigned char);
extern void FUN_a0085b14(unsigned char);

void FUN_a0085ea8(void)
{
    unsigned char i;

    R(0xcf0116bc) &= ~0x40;
    R(0xcf0116bc) &= ~0x80;
    FUN_a00aa5e8(1, 0x1e, 0, 0);
    FUN_a00aa5e8(0, 0x1e, 0, 0);
    FUN_a00aa88c(0, 0);
    for (i = 1; i <= 4; i++)
        FUN_a00aa88c(i, 0);
    if (!FUN_a00aa7bc()) {
        FUN_a00aa3a4(0);
        FUN_a00aa45c(0, (ARR_a807a928[0].w20 >> 12) & 1);
        FUN_a00aa49c(0, (ARR_a807a928[0].w20 >> 13) & 3);
        FUN_a0085b80(0);
        FUN_a0085dcc(0);
        FUN_a0085b14(0);
    }
    for (i = 1; i <= 4; i++) {
        if (FUN_a00aa7c4(i))
            continue;
        FUN_a00aa3a4(i);
        FUN_a00aa45c(i, (ARR_a807a928[i].w20 >> 12) & 1);
        FUN_a00aa49c(i, (ARR_a807a928[i].w20 >> 13) & 3);
        FUN_a0085b80(i);
        FUN_a0085dcc(i);
        FUN_a0085b14(i);
    }
    R(0xcf00f21c) &= ~0x18;
}
