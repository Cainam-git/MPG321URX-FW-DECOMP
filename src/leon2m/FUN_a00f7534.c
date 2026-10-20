/* leon2m FUN_a00f7534 @ 0xa00f7534 (-mcpu=v8 -O3 -g)
 * Writes (0xCF00EE80 & 0xF9) | (DAT_a802b7b4 << 1) to 0xCF00EE80, (0xCF00EEC0 & 0xF3) | 0xA8 to 0xCF00EEC0 and sets
 * bits 0x50 of 0xCF00EEC4. Then writes the n 16-bit entries of the table t (p, or DAT_0019a334 when p is null;
 * layout { u8 n; u16 v[n]; } with v at offset 2) one after another to 0xCF00EEC8, sets bit 7 of 0xCF00EEC4, calls
 * the ROM routine func_0x4008e2a4() and clears bit 7 again. No direct callers found.
 * Source form: the table is selected with if (p == 0) / else (other forms keep one register base for all addresses).
 */
#define R(a) (*(volatile unsigned int *)(a))

struct coef {
    unsigned char n;
    unsigned short v[1];
};

extern unsigned char DAT_a802b7b4;
extern struct coef DAT_0019a334;
extern void func_0x4008e2a4(void);

void FUN_a00f7534(struct coef *p)
{
    unsigned char i;
    struct coef *t;

    R(0xcf00ee80) = (R(0xcf00ee80) & 0xf9) | (DAT_a802b7b4 << 1);
    R(0xcf00eec0) = (R(0xcf00eec0) & 0xf3) | 0xa8;
    R(0xcf00eec4) |= 0x50;
    if (p == 0)
        t = &DAT_0019a334;
    else
        t = p;
    for (i = 0; i < t->n; i++)
        R(0xcf00eec8) = t->v[i];
    R(0xcf00eec4) |= 0x80;
    func_0x4008e2a4();
    R(0xcf00eec4) &= ~0x80;
}
