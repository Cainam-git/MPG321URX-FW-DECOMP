/* FUN_a00c7770 (leon2s, 0xa00c7770-0xa00c77dc, 27 words). Flags -mcpu=v8 -Os -g. jf 100.00 match=True, rawcmp_l2s 0 mismatches.
 Code facts: u8 idx, u16 reg. idx > 2: print func_0xa0f83044(s_9f1c1f78, s_9f1c1f00, idx, reg), return 0. Else returns the low byte of the
 hardware register at 0xcf000000 | ((DAT_9f1c1ec8[idx] + reg) << 2) (volatile: real 0xcf... register).
 Fixes vs draft: 0x9f1c1f78/0x9f1c1f00/0x9f1c1ec8 are SYMBOL addresses (own sethi each; the table is an extern u32 array, which gives the fw
 [base + idx*4] order); the print is variadic. Aids: none.
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
