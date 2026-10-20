/* leon2s FUN_a009f66c @ 0xa009f66c  MATCH (-mcpu=v8 -Os -g)
 * For the 0x34-byte record of port at 0xa807db00: calls FUN_a00a73d4(0xB, base + 0x1F), FUN_a00a73d4(0, base +
 * 0x18) and FUN_a00a73d4(1, base + 0x18), clears the top byte of base[0x17], calls FUN_a00a73d4 with 8 and 9 on
 * base + 0x18, 0x11 on cfg + 0x24 and 6 on cfg + 0x20 (word indexes), and when the low byte of FUN_a008d800() is
 * above 0x82 clears bits 8..15 of cfg[0x2C] (sethi / or 0xff builds the mask 0xFFFF00FF).
 */
extern unsigned char DAT_a807db00;
extern int FUN_a00a73d4(int, void *);
extern int FUN_a008d800(void);

struct port_regs {
    unsigned char pad0[0x0c];
    unsigned int *base;
    unsigned char pad1[0x08];
    unsigned int *cfg;
    unsigned char pad2[0x1c];
};

void FUN_a009f66c(unsigned char port)
{
    struct port_regs *pr;
    unsigned int v;

    pr = (struct port_regs *)((unsigned char *)&DAT_a807db00 + port * 0x34);
    FUN_a00a73d4(0xb, pr->base + 0x1f);
    FUN_a00a73d4(0, pr->base + 0x18);
    FUN_a00a73d4(1, pr->base + 0x18);
    v = pr->base[0x17];
    pr->base[0x17] = v & 0x00ffffff;
    FUN_a00a73d4(8, pr->base + 0x18);
    FUN_a00a73d4(9, pr->base + 0x18);
    FUN_a00a73d4(0x11, pr->cfg + 0x24);
    FUN_a00a73d4(6, pr->cfg + 0x20);
    if ((unsigned char)FUN_a008d800() > 0x82) {
        pr->cfg[0x2c] &= 0xffff00ff;
    }
}
