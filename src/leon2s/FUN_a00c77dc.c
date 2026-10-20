/* BYTE-EXACT: leon2s FUN_a00c77dc @ 0xa00c77dc-0xa00c79c8 (123 words),
 * flags -mcpu=v8 -Os -g. jf 100.00 match=True, rawcmp_l2s 0/123.
 * Code facts: (u8 p), void. Byte DAT_a807cdb8[0] = 0; base = &DAT_a807cdb8 (kept in %l1). Through
 * func_0xa0fb7ee0(p, reg, val) (write) / func_0xa0fb7fa0(p, reg) (read): reg 0xc = 0x18, 0x10; 32 writes of
 * ROM table DAT_9f1c1ea8[i] to reg 0xd; reg 0xa = 0x42; wait while bit 1 of reg 0xa is SET, at most 255
 * polls (u8 counter from 0xff, --cnt == 0 ends it); reg 0xc = 0x28, 0x20; base[0x21 + i] = read(0xd) ^
 * DAT_9f1c1e48[i] for i = 0..0x5e. Second round: reg 0xc = 0x18, 0x10; write base[0x21 .. 0x7f] to reg 0xd;
 * reg 0xa = 0x44; wait while bit 2 is set; reg 0xc = 0x28, 0x20; base[1 + i] = read(0xd) ^ DAT_9f1c1ea8[i],
 * i = 0..0x1f.
 * Required forms: base pointer for the record; the last 2 words (fw 'mov %i0,%o0; clr %l0' before the 2nd call) come
 * from 'i = 0' at the DECLARATION (an 'i = 0' just before the 2nd call gives 'clr %l0' first). No aids.
 */
extern unsigned char DAT_a807cdb8[];
extern const unsigned char DAT_9f1c1ea8[];
extern const unsigned char DAT_9f1c1e48[];
extern void func_0xa0fb7ee0(unsigned int, unsigned int, unsigned int);
extern unsigned int func_0xa0fb7fa0(unsigned int, unsigned int);

void FUN_a00c77dc(unsigned char p)
{
    unsigned char i = 0;
    unsigned char cnt;
    unsigned char *base;

    base = DAT_a807cdb8;
    DAT_a807cdb8[0] = 0;
    func_0xa0fb7ee0(p, 0xc, 0x18);
    func_0xa0fb7ee0(p, 0xc, 0x10);
    do {
        func_0xa0fb7ee0(p, 0xd, DAT_9f1c1ea8[i]);
        i++;
    } while (i < 0x20);
    func_0xa0fb7ee0(p, 0xa, 0x42);
    cnt = 0xff;
    while (func_0xa0fb7fa0(p, 0xa) & 2) {
        if (--cnt == 0)
            break;
    }
    func_0xa0fb7ee0(p, 0xc, 0x28);
    func_0xa0fb7ee0(p, 0xc, 0x20);
    for (i = 0; i < 0x5f; i++)
        base[0x21 + i] = func_0xa0fb7fa0(p, 0xd) ^ DAT_9f1c1e48[i];

    func_0xa0fb7ee0(p, 0xc, 0x18);
    func_0xa0fb7ee0(p, 0xc, 0x10);
    for (i = 0; i < 0x5f; i++)
        func_0xa0fb7ee0(p, 0xd, base[0x21 + i]);
    func_0xa0fb7ee0(p, 0xa, 0x44);
    cnt = 0xff;
    while (func_0xa0fb7fa0(p, 0xa) & 4) {
        if (--cnt == 0)
            break;
    }
    func_0xa0fb7ee0(p, 0xc, 0x28);
    func_0xa0fb7ee0(p, 0xc, 0x20);
    for (i = 0; i < 0x20; i++)
        base[1 + i] = func_0xa0fb7fa0(p, 0xd) ^ DAT_9f1c1ea8[i];
}
