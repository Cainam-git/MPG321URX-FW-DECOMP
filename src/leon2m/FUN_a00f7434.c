/* leon2m FUN_a00f7434 @ 0xa00f7434-0xa00f7534, flags -mcpu=v8 -O3 -g. Callers: FUN_a012a2f0, FUN_a01474b0.
 * Writes (0xcf00ee80 & 0xf9) | (DAT_a802b7b4 << 1) to 0xcf00ee80, clears bit 5 of 0xcf00eec0 and writes
 * v = (0xcf00eec4 & 0x0f) | 0x50 (an unsigned char) to 0xcf00eec4. The data block t is p, or DAT_0019a378 when p
 * is null (layout { u8 n; u16 v[]; } with v at offset 2). For i = 0..n (inclusive, do-while) it writes the low
 * byte, then the high byte of v[i] to 0xcf00eec8, each write followed by a call of the 32-nop loop FUN_a00f2e74.
 * Then it writes v | 0x90 to 0xcf00eec4, calls func_0x4008e2a4, sets bit (DAT_a802b7b4 + 4) of 0xcf00ee80
 * (result masked to 8 bits) and clears bit 7 of 0xcf00eec4. Same frame as src/leon2m/FUN_a00f7534.c.
 */
#define R(a) (*(volatile unsigned int *)(a))

struct coef {
    unsigned char n;
    unsigned short v[1];
};

extern unsigned char DAT_a802b7b4;
extern struct coef DAT_0019a378;
extern void FUN_a00f2e74(void);
extern void func_0x4008e2a4(void);

void FUN_a00f7434(struct coef *p)
{
    unsigned char i;
    unsigned char v;
    struct coef *t;

    R(0xcf00ee80) = (R(0xcf00ee80) & 0xf9) | (DAT_a802b7b4 << 1);
    R(0xcf00eec0) &= ~0x20;
    v = (R(0xcf00eec4) & 0xf) | 0x50;
    R(0xcf00eec4) = v;
    if (p == 0)
        t = &DAT_0019a378;
    else
        t = p;
    i = 0;
    do {
        R(0xcf00eec8) = t->v[i] & 0xff;
        FUN_a00f2e74();
        R(0xcf00eec8) = t->v[i] >> 8;
        i++;
        FUN_a00f2e74();
    } while (i <= t->n);
    R(0xcf00eec4) = v | 0x90;
    func_0x4008e2a4();
    R(0xcf00ee80) = (R(0xcf00ee80) | (1 << (DAT_a802b7b4 + 4))) & 0xff;
    R(0xcf00eec4) &= ~0x80;
}
