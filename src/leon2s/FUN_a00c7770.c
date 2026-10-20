/* FUN_a00c7770 (leon2s, 0xa00c7770-0xa00c77dc, 27 words). Flags -mcpu=v8 -Os -g.
 * u8 idx, u16 reg. idx > 2: prints func_0xa0f83044(s_9f1c1f78, s_9f1c1f00, idx, reg), returns 0. Else returns
 * the low byte of the hardware register at 0xcf000000 | ((DAT_9f1c1ec8[idx] + reg) << 2) (volatile: a 0xcf...
 * register).
 * 0x9f1c1f78/0x9f1c1f00/0x9f1c1ec8 are symbol addresses (own sethi each; the table is an extern u32 array,
 * which gives the firmware [base + idx*4] order); the print is variadic.
 */
extern unsigned int DAT_9f1c1ec8[];
extern char s_9f1c1f78[], s_9f1c1f00[];
extern int func_0xa0f83044(const char *, ...);

unsigned char FUN_a00c7770(unsigned char idx, unsigned short reg)
{
    if (idx > 2) {
        func_0xa0f83044(s_9f1c1f78, s_9f1c1f00, idx, reg);
        return 0;
    }
    return *(volatile unsigned int *)(((DAT_9f1c1ec8[idx] + reg) << 2) | 0xcf000000);
}
