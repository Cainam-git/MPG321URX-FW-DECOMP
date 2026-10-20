/* leon2m FUN_a0124fd0 @ 0xa0124fd0-0xa01250a8 (54 words), flags -mcpu=v8 -O3 -g. BYTE-EXACT:
 * jf 100.00 match=True, rawcmp.py 0 mismatches / 54 words.
 * Code facts: FUN_a0133e7c(0x20, 0xa8); ROM func_0x4008c86c(7, 0x20, 0); four ROM func_0x4008cb30(a, b, 1) writes
 * with the byte pairs at ROM 0x1a4298..0x1a429f; FUN_a0133e7c(0x80, 0xa8); func_0x4008c86c(7, 0x10, 0); four more
 * with the pairs at 0x1a42a0..0x1a42a7 (the last a tail call). void.
 * Fix vs the autoc draft (77.78): the table base DAT_001a4288 is taken AFTER the first two calls (fw sethi|or into
 * %l1 at 0xa0124ff0; set at the top it is built before the first call, 96.30); symbol name, void. Aids: none.
 */
extern const unsigned char DAT_001a4288[];
extern void FUN_a0133e7c(unsigned char, unsigned char);
extern void func_0x4008c86c(unsigned char, unsigned char, unsigned char);
extern void func_0x4008cb30(unsigned char, unsigned char, unsigned char);

void FUN_a0124fd0(void)
{
    const unsigned char *base;
    const unsigned char *p;

    FUN_a0133e7c(0x20, 0xa8);
    func_0x4008c86c(7, 0x20, 0);
    base = DAT_001a4288;
    p = base + 0x10;
    func_0x4008cb30(p[0], p[1], 1);
    func_0x4008cb30(p[2], p[3], 1);
    p = base + 0x14;
    func_0x4008cb30(p[0], p[1], 1);
    func_0x4008cb30(p[2], p[3], 1);
    FUN_a0133e7c(0x80, 0xa8);
    func_0x4008c86c(7, 0x10, 0);
    p = base + 0x18;
    func_0x4008cb30(p[0], p[1], 1);
    func_0x4008cb30(p[2], p[3], 1);
    p = base + 0x1c;
    func_0x4008cb30(p[0], p[1], 1);
    func_0x4008cb30(p[2], p[3], 1);
}
